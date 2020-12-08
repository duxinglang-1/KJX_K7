/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  CnmgrSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is the main source file of Connection Management Service.
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

/************************************************************
 * Include
 ************************************************************/
#include "MMI_include.h"

#include "ProtocolEvents.h"

#include "Custom_events_notify.h"

#include "mmi2abm_struct.h"
#include "app2cbm_struct.h"

#include "abm_soc_enums.h"
#include "abm_api.h"

#include "l4c_common_enum.h"

#include "cbm_api.h"

#include "mmi_msg_struct.h"
#include "UcmSrvGprot.h"
#include "UCMGProt.h"
#include "nvram_struct.h"
#include "CbmSrvGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "cbm_consts.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
//#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "AlertScreen.h"
#include "gui_data_types.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "DtcntSrvGprot.h"
#include "GlobalConstants.h"
#include "CommonScreensResDef.h"
#include "stdio.h"

#include "CnmgrSrvGprot.h"
#include "CnmgrSrvIprot.h"
#include "CnmgrSrvMain.h"
#include "custom_cnmgr_config.h"

#include "NwUsabSrvGprot.h"
#include "TetheringSrvGprot.h"
#include "gpiosrvgprot.h"
#include "NetSetSrvGprot.h"

#include "mmi_rp_srv_cnmgr_def.h"

#ifdef __MMI_ENABLE_CNMGR_SRV__
/************************************************************
 * Global Variable
 ************************************************************/
static srv_cnmgr_context_struct g_cnmgr_srv_cntx;

static srv_cnmgr_bearer_context_struct g_cnmgr_srv_bearer_list[SRV_CNMGR_MAX_BEARER_NUM];

#ifdef __MMI_CBM_CONNECTION_MANAGER__
static srv_cnmgr_bearer_context_struct g_cnmgr_srv_backup_bearer_list[SRV_CNMGR_MAX_BACKUP_BEARER_NUM];
#ifdef __USB_TETHERING__
static srv_cnmgr_merged_bearer_data_struct g_cnmgr_srv_merged_bearer_list[SRV_CNMGR_MAX_BEARER_NUM];
#endif
#endif

#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
srv_cnmgr_history_connect_data_context_struct g_cnmgr_srv_history_data_cntx;
srv_cnmgr_history_connect_data_context_struct *const g_cnmgr_srv_history_data_cntx_ptr = &g_cnmgr_srv_history_data_cntx;
srv_cnmgr_runtime_connect_data_context_struct g_cnmgr_srv_runtime_data_cntx;
#define CNMGR_CTX(X) (g_cnmgr_srv_history_data_cntx_ptr->X)
#define CNMGR_TBL_PTR(_x_) (&CNMGR_CTX(history_connect_data[_x_]))
#define CNMGR_LOCAL_PTR(_x_) (&CNMGR_CTX(tcpip_active_temp_data[_x_]))
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
static U32 g_cnmgr_srv_req_id_counter = 0;
#endif


/************************************************************
 * Declaration
 ************************************************************/
cbm_sim_id_enum srv_cnmgr_convert_mmi_sim_id_to_cbm(mmi_sim_enum mmi_sim);
U8 srv_cnmgr_convert_mmi_sim_id_to_cnmgr(mmi_sim_enum mmi_sim);
srv_cnmgr_connect_type_enum srv_cnmgr_convert_abm_connect_type_to_cnmgr(kal_uint8 connect_type);
abm_connect_type_enum srv_cnmgr_convert_cnmgr_connect_type_to_abm(srv_cnmgr_connect_type_enum connect_type);
void srv_cnmgr_update_nvram(srv_cnmgr_nvram_data_enum data_type,
                                   cbm_sim_id_enum sim_id,
                                   void *data);
U8 srv_cnmgr_nvram_async_event_handler(void *msg);
void srv_cnmgr_start_timer(void);
void srv_cnmgr_timeout_handler(void);
void srv_cnmgr_check_and_stop_timer(void);
MMI_BOOL srv_cnmgr_is_no_valid_bearer(void);
U8 srv_cnmgr_check_active_bearer_type(void);
U8 srv_cnmgr_get_active_bearer_num(void);
void srv_cnmgr_add_node_to_bearer_list(srv_cnmgr_bearer_context_struct *node, MMI_BOOL backup_flag);
S32 srv_cnmgr_get_bearer_node_index(U32 profile_id, 
                                           srv_cnmgr_connect_type_enum connect_type, 
                                           U8 dialup_type);
void srv_cnmgr_add_or_update_bearer_list(mmi_abm_bearer_info_ind_struct *bearer_info,
                                                srv_cnmgr_bearer_type_enum bearer_type,
                                                srv_cnmgr_bearer_status_enum bearer_status,
                                                MMI_BOOL need_update,
                                                MMI_BOOL not_display);
void srv_cnmgr_remove_node_from_bearer_list(U32 profile_id, srv_cnmgr_connect_type_enum connect_type, U8 dialup_type);
void srv_cnmgr_change_last_session_bearer(U32 profile_id,
                                                 cbm_sim_id_enum sim_id,
                                                 srv_cnmgr_bearer_type_enum bearer_type,
                                                 srv_cnmgr_connect_type_enum connect_type,
                                                 srv_cnmgr_bearer_state_enum state);
void srv_cnmgr_change_last_local_bearer_session(U32 profile_id,
                                                       cbm_sim_id_enum sim_id,
                                                       srv_cnmgr_bearer_type_enum bearer_type,
                                                       srv_cnmgr_bearer_state_enum state);
void srv_cnmgr_change_last_dialup_bearer_session(U32 profile_id,
                                                        cbm_sim_id_enum sim_id,
                                                        srv_cnmgr_bearer_type_enum bearer_type,
                                                        srv_cnmgr_bearer_state_enum state);
void srv_cnmgr_change_transmit_data_time(U32 profile_id,
                                                cbm_sim_id_enum sim_id,
                                                srv_cnmgr_bearer_type_enum bearer_type,
                                                srv_cnmgr_connect_type_enum connect_type,
                                                srv_cnmgr_bearer_state_enum state,
                                                U64 recv_data_size,
                                                U64 send_data_size);
void srv_cnmgr_change_local_transmit_data_time(U32 profile_id,
                                                      cbm_sim_id_enum sim_id,
                                                      srv_cnmgr_bearer_type_enum bearer_type,
                                                      srv_cnmgr_bearer_state_enum state,
                                                      U64 recv_data_size,
                                                      U64 send_data_size);
void srv_cnmgr_change_dialup_transmit_data_time(U32 profile_id,
                                                       cbm_sim_id_enum sim_id,
                                                       srv_cnmgr_bearer_type_enum bearer_type,
                                                       srv_cnmgr_bearer_state_enum state,
                                                       U64 recv_data_size,
                                                       U64 send_data_size);
void srv_cnmgr_update_runtime_data(mmi_abm_get_bearer_info_cnf_struct *cnf_data);
U8 srv_cnmgr_bearer_info_ind_hdlr(void *msg);
srv_cnmgr_result_enum srv_cnmgr_get_bearer_info_req_handler(void);
U8 srv_cnmgr_get_bearer_info_cnf_handler(void *msg);
void srv_cnmgr_reply_connection_data(MMI_BOOL history_data);
void srv_cnmgr_connect_data_update_notify(void);
srv_cnmgr_result_enum srv_cnmgr_reset_local_profile(cbm_sim_id_enum sim_id,
                                                           srv_cnmgr_bearer_type_enum bearer_type,
                                                           srv_cnmgr_connect_data_enum data_type);
srv_cnmgr_result_enum srv_cnmgr_reset_dialup_data(cbm_sim_id_enum sim_id,
                                                         srv_cnmgr_bearer_type_enum bearer_type,
                                                         srv_cnmgr_connect_data_enum data_type);
MMI_BOOL srv_cnmgr_reset_counter_data(srv_cnmgr_connect_type_enum connect_type,
                                             cbm_sim_id_enum sim_id,
                                             srv_cnmgr_bearer_type_enum bearer_type,
                                             srv_cnmgr_connect_data_enum data_type);
U8 srv_cnmgr_reset_connection_data_cnf_handler(void *msg);
void srv_cnmgr_set_data_update_interval(MMI_BOOL reset, U32 interval);

#ifdef __MMI_CBM_CONNECTION_MANAGER__
srv_cnmgr_bearer_context_struct *srv_cnmgr_get_first_active_bearer_node(void);
void srv_cnmgr_move_bearer_node_to_bearer_list(void);
void srv_cnmgr_bearer_data_update_notify(void);
void srv_cnmgr_disconnect_bearer_req_handler(U32 profile_id, U8 sim_id, srv_cnmgr_connect_type_enum connect_type, U8 dialup_type);
void srv_cnmgr_disconnect_bearer_cnf_handler(void *msg);
void srv_cnmgr_disconnect_all_bearer_done(U8 result);
void srv_cnmgr_disconnect_bearer_done(U32 profile_id, U8 connect_type, U8 result);
#ifdef __USB_TETHERING__
void srv_cnmgr_add_node_to_merged_bearer_list(srv_cnmgr_bearer_context_struct *node);
void srv_cnmgr_remove_node_from_merged_bearer_list(U32 profile_id,
                                                          srv_cnmgr_connect_type_enum connect_type,
                                                          U8 dialup_type);
void srv_cnmgr_update_merged_bearer_status(U32 profile_id, 
                                                  srv_cnmgr_connect_type_enum connect_type, 
                                                  U8 dialup_type,
                                                  srv_cnmgr_bearer_status_enum bearer_status);
void srv_cnmgr_decide_merged_bearer_status(U8 idx);
void srv_cnmgr_update_merged_bearer_data(U32 profile_id, 
                                                srv_cnmgr_connect_type_enum connect_type, 
                                                U8 dialup_type,
                                                srv_cnmgr_bearer_detail_struct *old_data,
                                                srv_cnmgr_bearer_detail_struct *new_data);
#endif /* __USB_TETHERING__ */
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
void srv_cnmgr_set_scri_check_interval(srv_cnmgr_scri_check_timer_enum type);
MMI_BOOL srv_cnmgr_can_send_end_ps_data_session_req(MMI_BOOL *force_send_scri, MMI_BOOL call_prefer);
void srv_cnmgr_end_ps_data_session_req_handler(MMI_BOOL force_send_scri);
U8 srv_cnmgr_end_ps_data_session_rsp_handler(void *msg);
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
mmi_ret srv_cnmgr_get_pch_status_callback(mmi_event_struct *rsp);
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
void srv_cnmgr_notify_nwinfo(mmi_abm_get_bearer_info_cnf_struct* cnf);
void srv_cnmgr_post_nwinfo_evt(MMI_BOOL only_for_nwinfo);
#endif /* __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */

/************************************************************
 * Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_convert_mmi_sim_id_to_cbm
 * DESCRIPTION
 *  This API is used to convert MMI SIM id to CBM SIM id.
 * PARAMETERS
 *  mmi_sim         [IN]    MMI SIM id
 * RETURNS
 *  cbm_sim_id_enum
 *****************************************************************************/
cbm_sim_id_enum srv_cnmgr_convert_mmi_sim_id_to_cbm(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch (mmi_sim)
    {
        case MMI_SIM1:
            return CBM_SIM_ID_SIM1;

        case MMI_SIM2:
            return CBM_SIM_ID_SIM2;

        case MMI_SIM3:
            return CBM_SIM_ID_SIM3;

        case MMI_SIM4:
            return CBM_SIM_ID_SIM4;

        default:
            break;
    }

    return CBM_SIM_ID_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_convert_mmi_sim_id_to_cnmgr
 * DESCRIPTION
 *  This API is used to convert MMI SIM id to CNMGR SIM id.
 * PARAMETERS
 *  mmi_sim         [IN]    MMI SIM id
 * RETURNS
 *  srv_cnmgr_sim_id_enum
 *****************************************************************************/
U8 srv_cnmgr_convert_mmi_sim_id_to_cnmgr(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch (mmi_sim)
    {
        case MMI_SIM1:
            return SRV_CNMGR_SIM_ID_1;

        case MMI_SIM2:
            return SRV_CNMGR_SIM_ID_2;

        case MMI_SIM3:
            return SRV_CNMGR_SIM_ID_3;

        case MMI_SIM4:
            return SRV_CNMGR_SIM_ID_4;

        default:
            break;
    }

    return SRV_CNMGR_SIM_ID_1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_convert_abm_connect_type_to_cnmgr
 * DESCRIPTION
 *  This API is used to convert ABM connection type to CNMGR connection type.
 * PARAMETERS
 *  connect_type    [IN]    ABM connection type
 * RETURNS
 *  srv_cnmgr_connect_type_enum
 *****************************************************************************/
srv_cnmgr_connect_type_enum srv_cnmgr_convert_abm_connect_type_to_cnmgr(kal_uint8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (connect_type == ABM_CONNECT_TYPE_LOCAL)
    {
        return SRV_CNMGR_CONNECT_TYPE_LOCAL;
    }
    else if (connect_type == ABM_CONNECT_TYPE_DIALUP)
    {
        return SRV_CNMGR_CONNECT_TYPE_DIALUP;
    }

    return SRV_CNMGR_CONNECT_TYPE_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_convert_cnmgr_connect_type_to_abm
 * DESCRIPTION
 *  This API is used to convert CNMGR connection type to ABM connection type.
 * PARAMETERS
 *  connect_type    [IN]    CNMGR connection type
 * RETURNS
 *  abm_connect_type_enum
 *****************************************************************************/
abm_connect_type_enum srv_cnmgr_convert_cnmgr_connect_type_to_abm(srv_cnmgr_connect_type_enum connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL)
    {
        return ABM_CONNECT_TYPE_LOCAL;
    }
    else if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
    {
        return ABM_CONNECT_TYPE_DIALUP;
    }

    return ABM_CONNECT_TYPE_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_update_nvram
 * DESCRIPTION
 *  Update NVRAM data
 * PARAMETERS
 *  data_type       [IN]    NVRAM data type
 *  sim_id          [IN]    SIM id
 *  data            [IN]    Data which should be written to NVRAM
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_update_nvram(srv_cnmgr_nvram_data_enum data_type,
                                   cbm_sim_id_enum sim_id,
                                   void *data)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_type == SRV_CNMGR_NVRAM_DATA_LOCAL_CSD ||
        data_type == SRV_CNMGR_NVRAM_DATA_LOCAL_GPRS ||
        data_type == SRV_CNMGR_NVRAM_DATA_LOCAL_TOTAL ||
        data_type == SRV_CNMGR_NVRAM_DATA_DIALUP)
    {
        mmi_frm_write_async_record(NVRAM_EF_CNMGR_CONNECT_DATA_LID,
                                   data_type + (sim_id * 4),
                                   data,
                                   NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE);
        g_cnmgr_srv_cntx.nvram_count++;
    }
    else if (data_type == SRV_CNMGR_NVRAM_DATA_WIFI)
    {
        mmi_frm_write_async_record(NVRAM_EF_CNMGR_CONNECT_DATA_LID,
                                   1 + (SRV_CNMGR_SIM_TOTAL * 4),
                                   data,
                                   NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE);
        g_cnmgr_srv_cntx.nvram_count++;
    }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_nvram_async_event_handler
 * DESCRIPTION
 *  Handler of MSG_ID_NVRAM_WRITE_CNF
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  MMI_TRUE: event is handled
 *  MMI_FALSE: event is not handled
 *****************************************************************************/
U8 srv_cnmgr_nvram_async_event_handler(void *msg)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *nvram_write_cnf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_write_cnf = (nvram_write_cnf_struct*)msg;
    switch (nvram_write_cnf->file_idx) /* LID */
    {
        case NVRAM_EF_CNMGR_CONNECT_DATA_LID:
        {
            if (g_cnmgr_srv_cntx.nvram_count > 0)
            {
                g_cnmgr_srv_cntx.nvram_count--;
            }
            return MMI_TRUE;
        }

        default:
            return MMI_FALSE;
    }
#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

    return MMI_FALSE;
    
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_start_timer
 * DESCRIPTION
 *  Start timer
 *  When timer is expired, CNMGR may get bearer info again.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_cnmgr_srv_cntx.timer_start)
    {
        StartTimer(SRV_CNMGR_TIMER_ID, SRV_CNMGR_INTERNAL_TIMER_INTERVAL, srv_cnmgr_timeout_handler);
        g_cnmgr_srv_cntx.timer_start = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_timeout_handler
 * DESCRIPTION
 *  Timer timeout handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cnmgr_srv_cntx.timer_start = MMI_FALSE;

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            g_cnmgr_srv_bearer_list[i].connect_time++;
        }

#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
        if (g_cnmgr_srv_merged_bearer_list[i].count > 0 &&
            g_cnmgr_srv_merged_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            g_cnmgr_srv_merged_bearer_list[i].connect_time++;
        }
#endif
    }

    if (g_cnmgr_srv_cntx.get_bearer_info_wait_count > 0)
    {
        g_cnmgr_srv_cntx.get_bearer_info_wait_count--;
    }

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    if (g_cnmgr_srv_cntx.nvram_count == 0 &&
        g_cnmgr_srv_cntx.get_bearer_info_rsp_num == 0)
    {
        if(g_cnmgr_srv_cntx.get_bearer_info_wait_count == 0)
        {
            g_cnmgr_srv_cntx.send_for_nwinfo = MMI_FALSE;
        }
        else
        {
            g_cnmgr_srv_cntx.send_for_nwinfo = MMI_TRUE;
        }
        srv_cnmgr_get_bearer_info_req_handler();
    }
#else
    if (g_cnmgr_srv_cntx.nvram_count == 0 &&
        g_cnmgr_srv_cntx.get_bearer_info_wait_count == 0 &&
        g_cnmgr_srv_cntx.get_bearer_info_rsp_num == 0)
    {
        srv_cnmgr_get_bearer_info_req_handler();
    }
#endif /* __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */

    srv_cnmgr_start_timer();
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_check_and_stop_timer
 * DESCRIPTION
 *  Stop timer if no valid bearer in the list g_cnmgr_srv_bearer_list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_check_and_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    U32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cnmgr_is_no_valid_bearer())
    {
        g_cnmgr_srv_cntx.timer_start = MMI_FALSE;
        StopTimer(SRV_CNMGR_TIMER_ID);

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
        g_cnmgr_srv_cntx.scri_retry_num = 0;
        SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_IDLE);
#endif
    }
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    else
    {
        for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
        {
            if (g_cnmgr_srv_bearer_list[i].valid &&
                #ifndef __MMI_3G_SWITCH__
                g_cnmgr_srv_bearer_list[i].sim_id == CBM_SIM_ID_SIM1 &&
                #else
                g_cnmgr_srv_bearer_list[i].sim_id == g_cnmgr_srv_cntx.cur_3g_sim &&
                #endif
                (g_cnmgr_srv_bearer_list[i].bearer_type == SRV_CNMGR_BEARER_TYPE_GPRS ||
                 g_cnmgr_srv_bearer_list[i].bearer_type == SRV_CNMGR_BEARER_TYPE_CSD))
            {
                return;
            }
        }
        g_cnmgr_srv_cntx.scri_retry_num = 0;
        SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_IDLE);
    }
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_is_no_valid_bearer
 * DESCRIPTION
 *  Check whether there is valid bearer in the bearer list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: no active bearer
 *  MMI_FALSE: has active bearer
 *****************************************************************************/
MMI_BOOL srv_cnmgr_is_no_valid_bearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_check_active_bearer_type
 * DESCRIPTION
 *  This function is used to check whether normal data connection and dialup
 *  connection are activated.
 * PARAMETERS
 *  void
 * RETURNS
 *  Active bearer type
 *****************************************************************************/
U8 srv_cnmgr_check_active_bearer_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL &&
            g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            count++;
            break;
        }
    }

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP &&
            g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            count++;
            break;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_active_bearer_num
 * DESCRIPTION
 *  Get number of activated bearer
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of activated bearer
 *****************************************************************************/
U8 srv_cnmgr_get_active_bearer_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i< SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_BEARER_NODE_INFO,
                  i,
                  g_cnmgr_srv_bearer_list[i].profile_id,
                  g_cnmgr_srv_bearer_list[i].connect_type,
                  g_cnmgr_srv_bearer_list[i].valid,
                  g_cnmgr_srv_bearer_list[i].bearer_status);

        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_add_node_to_bearer_list
 * DESCRIPTION
 *  Add bearer node to g_cnmgr_srv_bearer_list if CNMGR is not disconnecting all connections now
 *  If CNMGR is disconnecting all connections, this bearer node will be added to backup list
 * PARAMETERS
 *  node            [IN]    Bearer node
 *  backup_flag     [IN]    Add to backup list or not
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_add_node_to_bearer_list(srv_cnmgr_bearer_context_struct *node, MMI_BOOL backup_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CBM_CONNECTION_MANAGER__
    if (backup_flag)
    {
        /* Check whether bearer list already has this bearer node */
        for (i = 0; i < SRV_CNMGR_MAX_BACKUP_BEARER_NUM; i++)
        {
            if (g_cnmgr_srv_backup_bearer_list[i].valid && 
                g_cnmgr_srv_backup_bearer_list[i].profile_id == node->profile_id &&
                g_cnmgr_srv_backup_bearer_list[i].connect_type == node->connect_type &&
                g_cnmgr_srv_backup_bearer_list[i].dialup_type == node->dialup_type)
            {
                memcpy(&g_cnmgr_srv_backup_bearer_list[i], node, sizeof(srv_cnmgr_bearer_context_struct));

                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_ADD_NODE_TO_BEARER_LIST,
                          backup_flag,
                          i,
                          node->profile_id,
                          node->connect_type,
                          node->dialup_type);
                return;
            }
        }

        for (i = 0; i < SRV_CNMGR_MAX_BACKUP_BEARER_NUM; i++)
        {
            if (!g_cnmgr_srv_backup_bearer_list[i].valid)
            {
                memcpy(&g_cnmgr_srv_backup_bearer_list[i], node, sizeof(srv_cnmgr_bearer_context_struct));
                g_cnmgr_srv_backup_bearer_list[i].valid = MMI_TRUE;

                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_ADD_NODE_TO_BEARER_LIST,
                          backup_flag,
                          i,
                          node->profile_id,
                          node->connect_type,
                          node->dialup_type);
                return;
            }
        }
    }
    else
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
    {
        /* Check whether bearer list already has this bearer node */
        for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
        {
            if (g_cnmgr_srv_bearer_list[i].valid && 
                g_cnmgr_srv_bearer_list[i].profile_id == node->profile_id &&
                g_cnmgr_srv_bearer_list[i].connect_type == node->connect_type &&
                g_cnmgr_srv_bearer_list[i].dialup_type == node->dialup_type)
            {
                memcpy(&g_cnmgr_srv_bearer_list[i], node, sizeof(srv_cnmgr_bearer_context_struct));

                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_ADD_NODE_TO_BEARER_LIST,
                          backup_flag,
                          i,
                          node->profile_id,
                          node->connect_type,
                          node->dialup_type);
                return;
            }
        }

        /* Add node to bearer list */
        for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
        {
            if (!g_cnmgr_srv_bearer_list[i].valid)
            {
                memcpy(&g_cnmgr_srv_bearer_list[i], node, sizeof(srv_cnmgr_bearer_context_struct));
                g_cnmgr_srv_bearer_list[i].valid = MMI_TRUE;
   
                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_ADD_NODE_TO_BEARER_LIST,
                          backup_flag,
                          i,
                          node->profile_id,
                          node->connect_type,
                          node->dialup_type);
                return;
            }
        }
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_ADD_NODE_TO_BEARER_LIST,
              backup_flag,
              -1,
              node->profile_id,
              node->connect_type,
              node->dialup_type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_bearer_node_index
 * DESCRIPTION
 *  Find the bearer node by given account id, connection type and dial-up type
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  connect_type    [IN]    Connection type
 *  dialup_type     [IN]    Dial-up type
 * RETURNS
 *  The index of bearer node in bearer list
 *****************************************************************************/
S32 srv_cnmgr_get_bearer_node_index(U32 profile_id, 
                                           srv_cnmgr_connect_type_enum connect_type, 
                                           U8 dialup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ori_acct_id = 0;
    S32 i;
    cbm_sim_id_enum sim;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ori_acct_id = cbm_get_original_account(profile_id);

    sim = cbm_get_sim_id(profile_id);

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid && 
            g_cnmgr_srv_bearer_list[i].profile_id == ori_acct_id &&
            g_cnmgr_srv_bearer_list[i].sim_id == sim &&
            g_cnmgr_srv_bearer_list[i].connect_type == connect_type &&
            g_cnmgr_srv_bearer_list[i].dialup_type == dialup_type)
        {
            return i;
        }
    }
    
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_add_or_update_bearer_list
 * DESCRIPTION
 *  Add bearer node into bearer list or update the the bearer list if bearer
 *  is already added into bearer list
 * PARAMETERS
 *  bearer_info     [IN]    Bearer info
 *  bearer_type     [IN]    Bearer type
 *  bearer_status   [IN]    Bearer status
 *  need_update     [IN]    Need update or not
 *  not_display     [IN]    Should not display in UI
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_add_or_update_bearer_list(mmi_abm_bearer_info_ind_struct *bearer_info,
                                                srv_cnmgr_bearer_type_enum bearer_type,
                                                srv_cnmgr_bearer_status_enum bearer_status,
                                                MMI_BOOL need_update,
                                                MMI_BOOL not_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_bearer_context_struct bearer_node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&bearer_node, 0, sizeof(srv_cnmgr_bearer_context_struct));

    bearer_node.profile_id = cbm_get_original_account(bearer_info->profile_id);
    bearer_node.sim_id = cbm_get_sim_id(bearer_info->profile_id);
    bearer_node.valid = MMI_TRUE;
    bearer_node.connect_type = srv_cnmgr_convert_abm_connect_type_to_cnmgr(bearer_info->connect_type);
    bearer_node.bearer_status = bearer_status;
    bearer_node.bearer_type = bearer_type;
    bearer_node.need_update = need_update;
    bearer_node.not_display = not_display;

    if (bearer_node.connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
    {
        bearer_node.dialup_type = bearer_info->dialup_info.bearer_type;
        bearer_node.sim_id = bearer_info->dialup_info.sim_id;
        if (bearer_node.dialup_type == CSD_BEARER_DIALUP)
        {
            bearer_node.profile_id = bearer_info->dialup_info.call_id;
        }
        else
        {
            bearer_node.profile_id = bearer_info->dialup_info.context_id;
        }
    }

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    bearer_node.detail.update_time = app_getcurrtime();
#endif

#ifdef __MMI_CBM_CONNECTION_MANAGER__
    if (g_cnmgr_srv_cntx.disc_all_flag)
    {
        g_cnmgr_srv_cntx.backup_list_flag = MMI_TRUE;
        srv_cnmgr_add_node_to_bearer_list(&bearer_node, MMI_TRUE);
    }
    else
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
    {
        srv_cnmgr_add_node_to_bearer_list(&bearer_node, MMI_FALSE);

#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
        if (not_display == MMI_FALSE)
        {
            srv_cnmgr_add_node_to_merged_bearer_list(&bearer_node);
        }
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_remove_node_from_bearer_list
 * DESCRIPTION
 *  Remove bearer node from bearer list
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  connect_type    [IN]    Connection type
 *  dialup_type     [IN]    Dial-up type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_remove_node_from_bearer_list(U32 profile_id, srv_cnmgr_connect_type_enum connect_type, U8 dialup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].profile_id  == profile_id &&
            g_cnmgr_srv_bearer_list[i].connect_type == connect_type &&
            g_cnmgr_srv_bearer_list[i].dialup_type == dialup_type)
        {
            memset(&g_cnmgr_srv_bearer_list[i], 0, sizeof(srv_cnmgr_bearer_context_struct));

#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
            srv_cnmgr_remove_node_from_merged_bearer_list(profile_id, connect_type, dialup_type);
#endif

            break;
        }
    }

    if (i < SRV_CNMGR_MAX_BEARER_NUM)
    {
        for (j = i; (j + 1) < SRV_CNMGR_MAX_BEARER_NUM; j++)
        {
            memcpy(&g_cnmgr_srv_bearer_list[j], &g_cnmgr_srv_bearer_list[j + 1], sizeof(srv_cnmgr_bearer_context_struct));
            memset(&g_cnmgr_srv_bearer_list[j + 1], 0, sizeof(srv_cnmgr_bearer_context_struct));

            if (!g_cnmgr_srv_bearer_list[j].valid)
            {
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_change_last_session_bearer
 * DESCRIPTION
 *  Record information for last bearer session
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  connect_type    [IN]    Connection type
 *  state           [IN]    Bearer state (ACTIVE or DEACTIVE)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_change_last_session_bearer(U32 profile_id,
                                                 cbm_sim_id_enum sim_id,
                                                 srv_cnmgr_bearer_type_enum bearer_type,
                                                 srv_cnmgr_connect_type_enum connect_type,
                                                 srv_cnmgr_bearer_state_enum state)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_CHANGE_LAST_SESSION_BEARER,
              profile_id,
              sim_id,
              bearer_type,
              connect_type,
              state);

    if (connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL)
    {
        srv_cnmgr_change_last_local_bearer_session(profile_id, sim_id, bearer_type, state);
    }
    else
    {
        srv_cnmgr_change_last_dialup_bearer_session(profile_id, sim_id, bearer_type, state);
    }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_change_last_local_bearer_session
 * DESCRIPTION
 *  Record information for last bearer session
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  state           [IN]    Bearer state (ACTIVE or DEACTIVE)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_change_last_local_bearer_session(U32 profile_id,
                                                       cbm_sim_id_enum sim_id,
                                                       srv_cnmgr_bearer_type_enum bearer_type,
                                                       srv_cnmgr_bearer_state_enum state)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state == SRV_CNMGR_BEARER_STATE_ACTIVE)
    {
        if (sim_id < CBM_SIM_ID_TOTAL && bearer_type != SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            for (i = 0; i < CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num; i++)
            {
                if (CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[i] == profile_id)
                {
                    return;
                }
            }

            CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num] = profile_id;
            CNMGR_TBL_PTR(sim_id)->last_session_profile_id = profile_id;

            switch (bearer_type)
            {
#ifdef __TCPIP_OVER_CSD__
                /* For CSD just 1 bearer when active */
                case SRV_CNMGR_BEARER_TYPE_CSD:
                {
                    CNMGR_TBL_PTR(sim_id)->csd_last_session_profile_id = profile_id;
                    break;
                }
#endif

                case SRV_CNMGR_BEARER_TYPE_GPRS:
                {
                    CNMGR_TBL_PTR(sim_id)->last_session_gprs_profile_id_order[CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num] = profile_id;
                    CNMGR_TBL_PTR(sim_id)->gprs_last_session_profile_id = profile_id;
                    break;
                }

                default:
                    break;
            }
        }

#ifdef __MMI_WLAN_FEATURES__
        if (bearer_type == SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            g_cnmgr_srv_history_data_cntx.wifi_last_session_profile_id = profile_id;
        }
#endif
    }
    else if (state == SRV_CNMGR_BEARER_STATE_DEACTIVE)
    {
        if (sim_id < CBM_SIM_ID_TOTAL && bearer_type != SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            for (i = 0; i < CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num; i++)
            {
                if (CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[i] == profile_id)
                {
                    CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[i] = 0;

                    if (i < (CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num - 1))
                    {
                        for (j = i; j < CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num - 1; j++)
                        {
                            CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[j] = CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[j + 1];
                        }
                        CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[j + 1] = 0;
                    }
                }
            }

            if ((CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num - 1) > 0)
            {
                CNMGR_TBL_PTR(sim_id)->last_session_profile_id = CNMGR_TBL_PTR(sim_id)->last_session_profile_id_order[CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num - 2];
            }
            else
            {
                CNMGR_TBL_PTR(sim_id)->last_session_profile_id = profile_id;
            }

            switch (bearer_type)
            {
#ifdef __TCPIP_OVER_CSD__
                /* Only one CSD bearer will be active */
                case SRV_CNMGR_BEARER_TYPE_CSD:
                {
                    CNMGR_TBL_PTR(sim_id)->csd_last_session_profile_id = profile_id;
                    break;
                }
#endif

                case SRV_CNMGR_BEARER_TYPE_GPRS:
                {
                    for (i = 0; i < CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num; i++)
                    {
                        if (CNMGR_TBL_PTR(sim_id)->last_session_gprs_profile_id_order[i] == profile_id)
                        {
                            CNMGR_TBL_PTR(sim_id)->last_session_gprs_profile_id_order[i] = 0;
                            if (i < (CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num - 1))
                            {
                                for (j = i; j < CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num - 1; j++)
                                {
                                    CNMGR_TBL_PTR(sim_id)->last_session_gprs_profile_id_order[j] = CNMGR_TBL_PTR(sim_id)->last_session_gprs_profile_id_order[j + 1];
                                }
                                CNMGR_TBL_PTR(sim_id)->last_session_gprs_profile_id_order[j + 1] = 0;
                            }
                        }
                    }

                    if ((CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num - 1) > 0)
                    {
                        CNMGR_TBL_PTR(sim_id)->gprs_last_session_profile_id = CNMGR_TBL_PTR(sim_id)->last_session_gprs_profile_id_order[CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num - 2];
                    }
                    else
                    {
                        CNMGR_TBL_PTR(sim_id)->gprs_last_session_profile_id = profile_id;
                    }

                    if (CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num > 0)
                    {
                        CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num--;
                    }
                    break;
                }
            }

            if (CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num > 0)
            {
                CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num--;
            }
        }

#ifdef __MMI_WLAN_FEATURES__
        if (bearer_type == SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            g_cnmgr_srv_history_data_cntx.wifi_last_session_profile_id = profile_id;
        }
#endif

        if (g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num)
        {
            g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num--;
        }
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_CHANGE_LAST_LOCAL_SESSION_BEARER,
              state,
              g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num,
              sim_id,
              CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num,
#ifdef __TCPIP_OVER_CSD__
              CNMGR_TBL_PTR(sim_id)->csd_last_session_profile_id,
#else
              0,
#endif
              CNMGR_TBL_PTR(sim_id)->gprs_last_session_profile_id,
#ifdef __MMI_WLAN_FEATURES__
              g_cnmgr_srv_history_data_cntx.wifi_last_session_profile_id,
#else
              0,
#endif
              CNMGR_TBL_PTR(sim_id)->last_session_profile_id);
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_change_last_dialup_bearer_session
 * DESCRIPTION
 *  Record information for last bearer session 
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  state           [IN]    Bearer state (ACTIVE or DEACTIVE)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_change_last_dialup_bearer_session(U32 profile_id,
                                                        cbm_sim_id_enum sim_id,
                                                        srv_cnmgr_bearer_type_enum bearer_type,
                                                        srv_cnmgr_bearer_state_enum state)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state == SRV_CNMGR_BEARER_STATE_ACTIVE)
    {
        if (sim_id < CBM_SIM_ID_TOTAL)
        {
            if (g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num >= SRV_CNMGR_MAX_DIALUP_NUM)
            {
                return;
            }

            for (i = 0; i < g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num; i++)
            {
                if (CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[i] == profile_id)
                {
                    return;
                }
            }

            CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[g_cnmgr_srv_history_data_cntx_ptr->dialup_active_bearer_num] = profile_id;

            g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num++;
        }
    }
    else if (state == SRV_CNMGR_BEARER_STATE_DEACTIVE)
    {
        if (sim_id < CBM_SIM_ID_TOTAL)
        {
            if ((g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num > SRV_CNMGR_MAX_DIALUP_NUM) ||
                (g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num <= 0))
            {
                return;
            }
            
            for (i = 0; i < g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num; i++)
            {
                if (CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[i] == profile_id)
                {
                    CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[i] = 0;

                    if (i < (g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num - 1))
                    {
                        for (j = i; j < g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num - 1; j++)
                        {
                            CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[j] = CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[j + 1];
                        }
                        CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[j + 1] = 0;
                    }
                }
            }

            if ((g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num - 1) > 0)
            {
                CNMGR_TBL_PTR(sim_id)->last_session_context_id = CNMGR_TBL_PTR(sim_id)->last_session_context_id_order[(g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num - 2)];
            }
            else
            {
                CNMGR_TBL_PTR(sim_id)->last_session_context_id = profile_id;
            }
        }

        if (g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num)
        {
            g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num--;
        }
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_CHANGE_LAST_DIALUP_SESSION_BEARER,
              state,
              g_cnmgr_srv_history_data_cntx.dialup_active_bearer_num,
              sim_id);
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_change_transmit_data_time
 * DESCRIPTION
 *  Update transmission data
 * PARAMETERS
 *  connect_type    [IN]    Connection type
 *  state           [IN]    Bearer state
 *  bearer_type     [IN]    Bearer type
 *  profile_id      [IN]    Profile id
 *  sim_id          [IN]    SIM id
 *  recv_data_size  [IN]    Received data size
 *  send_data_size  [IN]    Sent data size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_change_transmit_data_time(U32 profile_id,
                                                cbm_sim_id_enum sim_id,
                                                srv_cnmgr_bearer_type_enum bearer_type,
                                                srv_cnmgr_connect_type_enum connect_type,
                                                srv_cnmgr_bearer_state_enum state,
                                                U64 recv_data_size,
                                                U64 send_data_size)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_CHANGE_TRANSMIT_DATA_TIME,
              profile_id,
              sim_id,
              bearer_type,
              connect_type,
              state,
              (U32)recv_data_size,
              (U32)send_data_size);

    if (connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL)
    {
        srv_cnmgr_change_local_transmit_data_time(profile_id, sim_id, bearer_type, state, recv_data_size, send_data_size);
    }
    else
    {
        srv_cnmgr_change_dialup_transmit_data_time(profile_id, sim_id, bearer_type, state, recv_data_size, send_data_size);
    }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_change_local_transmit_data_time
 * DESCRIPTION
 *  Update transmission data
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  state           [IN]    Bearer state (ACTIVE or DEACTIVE)
 *  recv_data_size  [IN]    Received data size
 *  send_data_size  [IN]    Sent data size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_change_local_transmit_data_time(U32 profile_id,
                                                      cbm_sim_id_enum sim_id,
                                                      srv_cnmgr_bearer_type_enum bearer_type,
                                                      srv_cnmgr_bearer_state_enum state,
                                                      U64 recv_data_size,
                                                      U64 send_data_size)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 connect_time = 0;
    U32 i, j;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state == SRV_CNMGR_BEARER_STATE_ACTIVE)
    {
        for (i = 0; i < g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num; i++)
        {
            if (profile_id == CNMGR_LOCAL_PTR(i)->profile_id)
            {
                return;
            }
        }

        CNMGR_LOCAL_PTR(g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num)->profile_id = profile_id;
        CNMGR_LOCAL_PTR(g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num)->sim_id = sim_id;
        CNMGR_LOCAL_PTR(g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num)->bearer_type = bearer_type;

        if (sim_id < CBM_SIM_ID_TOTAL && bearer_type != SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num++;
             
            if (bearer_type == SRV_CNMGR_BEARER_TYPE_GPRS)
            {
                CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num++;
            }
        }
        
        g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num++;

        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_CHANGE_LOCAL_TRANSMIT_DATA_TIME_ACTIVE,
                  g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num,
                  sim_id,
                  CNMGR_TBL_PTR(sim_id)->tcpip_gprs_active_bearer_num,
                  CNMGR_TBL_PTR(sim_id)->tcpip_active_bearer_num);
    }
    else if (state == SRV_CNMGR_BEARER_STATE_DEACTIVE)
    {
        /* Clear temp data and find the active temp profile id */
        for (i = 0; i < g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num; i++)
        {
            if (profile_id == CNMGR_LOCAL_PTR(i)->profile_id)
            {
                break;
            }
        }

        if (i < g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num)
        {
            CNMGR_LOCAL_PTR(i)->profile_id = 0;
            CNMGR_LOCAL_PTR(i)->bearer_type = SRV_CNMGR_BEARER_TYPE_NONE;
            CNMGR_LOCAL_PTR(i)->sim_id = (cbm_sim_id_enum)0;
            if ((i + 1)< g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num)
            {
                for (j = i; (j + 1) < g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num; j++)
                {
                    CNMGR_LOCAL_PTR(j)->profile_id = CNMGR_LOCAL_PTR(j + 1)->profile_id;
                    CNMGR_LOCAL_PTR(j)->bearer_type = CNMGR_LOCAL_PTR(j + 1)->bearer_type;
                    CNMGR_LOCAL_PTR(j)->sim_id = CNMGR_LOCAL_PTR(j + 1)->sim_id;
                }

                CNMGR_LOCAL_PTR(j + 1)->profile_id = 0;
                CNMGR_LOCAL_PTR(j + 1)->bearer_type = SRV_CNMGR_BEARER_TYPE_NONE;
                CNMGR_LOCAL_PTR(j + 1)->sim_id = (cbm_sim_id_enum)0;
            }
        }

        if (sim_id < CBM_SIM_ID_TOTAL && bearer_type != SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            index = srv_cnmgr_get_bearer_node_index(profile_id, SRV_CNMGR_CONNECT_TYPE_LOCAL, 0);
            if (index >= 0)
            {
                /* Get bearer connection time */
                connect_time = g_cnmgr_srv_bearer_list[index].connect_time;
            }

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_CHANGE_LOCAL_TRANSMIT_DATA_TIME_DEACTIVE,
                      index,
                      (U32)connect_time);
#ifdef __TCPIP_OVER_CSD__
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_CSD,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_connect_duration);
#endif
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_GPRS,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_connect_duration);
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_SIM_PS,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_connect_duration);

            if (profile_id == CNMGR_TBL_PTR(sim_id)->last_session_profile_id)
            {
                CNMGR_TBL_PTR(sim_id)->local_total_data.last_recv_size = recv_data_size;
                CNMGR_TBL_PTR(sim_id)->local_total_data.last_sent_size = send_data_size;
                CNMGR_TBL_PTR(sim_id)->local_total_data.last_connect_duration = connect_time;
            }

            CNMGR_TBL_PTR(sim_id)->local_total_data.total_recv_size += recv_data_size;
            CNMGR_TBL_PTR(sim_id)->local_total_data.total_sent_size += send_data_size;
            CNMGR_TBL_PTR(sim_id)->local_total_data.total_connect_duration += connect_time;

            srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_TOTAL,
                                   sim_id,
                                   (void*)(&CNMGR_TBL_PTR(sim_id)->local_total_data));

            switch (bearer_type)
            {
#ifdef __TCPIP_OVER_CSD__
                case SRV_CNMGR_BEARER_TYPE_CSD:
                {
                    CNMGR_TBL_PTR(sim_id)->local_csd_data.last_recv_size = recv_data_size;
                    CNMGR_TBL_PTR(sim_id)->local_csd_data.last_sent_size = send_data_size;
                    CNMGR_TBL_PTR(sim_id)->local_csd_data.last_connect_duration = connect_time;
                    CNMGR_TBL_PTR(sim_id)->local_csd_data.total_recv_size += recv_data_size;
                    CNMGR_TBL_PTR(sim_id)->local_csd_data.total_sent_size += send_data_size;
                    CNMGR_TBL_PTR(sim_id)->local_csd_data.total_connect_duration += connect_time;

                    srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_CSD,
                                           sim_id,
                                           (void*)(&CNMGR_TBL_PTR(sim_id)->local_csd_data));
                    break;
                }
#endif /* __TCPIP_OVER_CSD__ */
                
                case SRV_CNMGR_BEARER_TYPE_GPRS:
                {
                    if (profile_id == CNMGR_TBL_PTR(sim_id)->gprs_last_session_profile_id)
                    {
                        CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_recv_size = recv_data_size;
                        CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_sent_size = send_data_size;
                        CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_connect_duration = connect_time;
                    }

                    CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_recv_size += recv_data_size;
                    CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_sent_size += send_data_size;
                    CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_connect_duration += connect_time;                    

                    srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_GPRS,
                                           sim_id,
                                           (void*)(&CNMGR_TBL_PTR(sim_id)->local_gprs_data));
                    break;
                }
            }

#ifdef __TCPIP_OVER_CSD__
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_CSD,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_connect_duration);
#endif /* __TCPIP_OVER_CSD__ */
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_GPRS,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_connect_duration);
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_SIM_PS,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_connect_duration);
        }

#ifdef __MMI_WLAN_FEATURES__
        if (bearer_type == SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_WIFI,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_sent_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_recv_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_connect_duration,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_sent_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_recv_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_connect_duration);

            g_cnmgr_srv_history_data_cntx.local_wifi_data.last_recv_size = recv_data_size;
            g_cnmgr_srv_history_data_cntx.local_wifi_data.last_sent_size = send_data_size;
            g_cnmgr_srv_history_data_cntx.local_wifi_data.last_connect_duration = connect_time;
            g_cnmgr_srv_history_data_cntx.local_wifi_data.total_recv_size += recv_data_size;
            g_cnmgr_srv_history_data_cntx.local_wifi_data.total_sent_size += send_data_size;
            g_cnmgr_srv_history_data_cntx.local_wifi_data.total_connect_duration += connect_time;

            srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_WIFI,
                                   CBM_SIM_ID_TOTAL,
                                   (void*)(&g_cnmgr_srv_history_data_cntx.local_wifi_data));

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_WIFI,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_sent_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_recv_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_connect_duration,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_sent_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_recv_size,
                      (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_connect_duration);
        }
#endif /* __WIFI_SUPPORT__ */
    }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_change_dialup_transmit_data_time
 * DESCRIPTION
 *  Update transmission data
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  state           [IN]    Bearer state (ACTIVE or DEACTIVE)
 *  recv_data_size  [IN]    Received data size
 *  send_data_size  [IN]    Sent data size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_change_dialup_transmit_data_time(U32 profile_id,
                                                       cbm_sim_id_enum sim_id,
                                                       srv_cnmgr_bearer_type_enum bearer_type,
                                                       srv_cnmgr_bearer_state_enum state,
                                                       U64 recv_data_size,
                                                       U64 send_data_size)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 connect_time = 0;
    S32 index;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state == SRV_CNMGR_BEARER_STATE_DEACTIVE)
    {
        if (sim_id < CBM_SIM_ID_TOTAL)
        {
            index = srv_cnmgr_get_bearer_node_index(profile_id, SRV_CNMGR_CONNECT_TYPE_DIALUP, bearer_type);
            if (index >= 0)
            {
                /* Get bearer connection time */
                connect_time = g_cnmgr_srv_bearer_list[index].connect_time;
            }

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_CHANGE_DIALUP_TRANSMIT_DATA_TIME_DEACTIVE,
                      index,
                      (U32)connect_time);
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_DIALUP_BEARER_DATA,
                      sim_id,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_connect_duration);
           
            if (profile_id == CNMGR_TBL_PTR(sim_id)->last_session_context_id)
            {
                CNMGR_TBL_PTR(sim_id)->dialup_data.last_recv_size = recv_data_size;
                CNMGR_TBL_PTR(sim_id)->dialup_data.last_sent_size = send_data_size;
                CNMGR_TBL_PTR(sim_id)->dialup_data.last_connect_duration = connect_time;
            }

            CNMGR_TBL_PTR(sim_id)->dialup_data.total_recv_size += recv_data_size;
            CNMGR_TBL_PTR(sim_id)->dialup_data.total_sent_size += send_data_size;
            CNMGR_TBL_PTR(sim_id)->dialup_data.total_connect_duration += connect_time;

            srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_DIALUP,
                                   sim_id,
                                   (void*)(&CNMGR_TBL_PTR(sim_id)->dialup_data));

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_DIALUP_BEARER_DATA,
                      sim_id,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_connect_duration);
        }
    }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_update_runtime_data
 * DESCRIPTION
 *  Calculate data size and write to NVRAM when receive MSG_ID_MMI_ABM_GET_BEARER_INFO_CNF
 * PARAMETERS
 *  cnf_data        [IN]    Connection data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_update_runtime_data(mmi_abm_get_bearer_info_cnf_struct *cnf_data)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    srv_cnmgr_connect_data_detail_struct temp_data;
    srv_cnmgr_connect_data_detail_struct temp_dialup_data[SRV_CNMGR_SIM_TOTAL];
    srv_cnmgr_connect_data_detail_struct temp_total_data[SRV_CNMGR_SIM_TOTAL];
    srv_cnmgr_connect_data_detail_struct temp_total_gprs_data[SRV_CNMGR_SIM_TOTAL];
    U32 i, j, ori_acct_id;
    S32 index;
    U8 app_id;
    MMI_BOOL is_always_ask;
    MMI_BOOL not_update = MMI_FALSE;
    cbm_sim_id_enum sim_id;
 
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (cnf_data == NULL)
    {
        return;
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_UPDATE_RUNTIME_DATA,
              0,
              cnf_data->connect_type,
              cnf_data->count);
    
    if (g_cnmgr_srv_cntx.nvram_count > 0)
    {
        not_update = MMI_TRUE;
    }

    memset(&temp_data, 0, sizeof(srv_cnmgr_connect_data_detail_struct));
    memset(temp_dialup_data, 0, sizeof(srv_cnmgr_connect_data_detail_struct) * SRV_CNMGR_SIM_TOTAL);
    memset(temp_total_data, 0, sizeof(srv_cnmgr_connect_data_detail_struct) * SRV_CNMGR_SIM_TOTAL);
    memset(temp_total_gprs_data, 0, sizeof(srv_cnmgr_connect_data_detail_struct) * SRV_CNMGR_SIM_TOTAL);

    if (cnf_data->connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL)
    {
        for (i = 0; i < CNMGR_CTX(tcpip_active_bearer_num); i++)
        {
            cbm_decode_data_account_id(CNMGR_LOCAL_PTR(i)->profile_id, &sim_id, &app_id, &is_always_ask, &ori_acct_id);
            for (j = 0; j < cnf_data->count; j++)
            {
                if (cnf_data->bearer_cnf_count[j].profile_id == ori_acct_id)
                {
                    sim_id = CNMGR_LOCAL_PTR(i)->sim_id;
                    if (sim_id < CBM_SIM_ID_TOTAL)
                    {
                        index = srv_cnmgr_get_bearer_node_index(cnf_data->bearer_cnf_count[j].profile_id,
                                                                srv_cnmgr_convert_abm_connect_type_to_cnmgr(cnf_data->connect_type),
                                                                0);

                        if (CNMGR_LOCAL_PTR(i)->bearer_type != SRV_CNMGR_BEARER_TYPE_WIFI)
                        {
                            temp_total_data[sim_id].total_recv_size += cnf_data->bearer_cnf_count[j].receive_data_size;
                            temp_total_data[sim_id].total_sent_size += cnf_data->bearer_cnf_count[j].send_data_size;
                            
                            if (index >= 0)
                            {
                                temp_total_data[sim_id].total_connect_duration += g_cnmgr_srv_bearer_list[index].connect_time;
                            }
                            
                            if (CNMGR_LOCAL_PTR(i)->profile_id == CNMGR_TBL_PTR(sim_id)->last_session_profile_id)
                            {
                            	temp_total_data[sim_id].last_recv_size = cnf_data->bearer_cnf_count[j].receive_data_size;
                            	temp_total_data[sim_id].last_sent_size = cnf_data->bearer_cnf_count[j].send_data_size;				
                                if (index >= 0)
                                {
                                    temp_total_data[sim_id].last_connect_duration = g_cnmgr_srv_bearer_list[index].connect_time;
                                }
                                else
                                {
                                    temp_total_data[sim_id].last_connect_duration = 0;
                                }
                            }
                        }

                        switch (CNMGR_LOCAL_PTR(i)->bearer_type)
                        {
#ifdef __TCPIP_OVER_CSD__
                            case SRV_CNMGR_BEARER_TYPE_CSD:
                            {
                                memcpy(&temp_data, &CNMGR_TBL_PTR(sim_id)->local_csd_data, sizeof(srv_cnmgr_connect_data_detail_struct));
                                temp_data.last_recv_size = cnf_data->bearer_cnf_count[j].receive_data_size;
                                temp_data.last_sent_size = cnf_data->bearer_cnf_count[j].send_data_size;
                                if (index >= 0)
                                {
                                    temp_data.last_connect_duration = g_cnmgr_srv_bearer_list[index].connect_time;
                                }
                                else
                                {
                                    temp_data.last_connect_duration = 0;
                                }
                                temp_data.total_recv_size += cnf_data->bearer_cnf_count[j].receive_data_size;
                                temp_data.total_sent_size += cnf_data->bearer_cnf_count[j].send_data_size;
                                if (index >= 0)
                                {
                                    temp_data.total_sent_size += g_cnmgr_srv_bearer_list[index].connect_time;
                                }

                                if (not_update == MMI_FALSE)
                                {
                                    srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_CSD, sim_id, (void*)(&temp_data));
                                }

                                memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id]),
                                       &temp_data,
                                       sizeof(srv_cnmgr_connect_data_detail_struct));

                                break;
                            }
#endif /* __TCPIP_OVER_CSD__ */

                            case SRV_CNMGR_BEARER_TYPE_GPRS:
                            {
                                temp_total_gprs_data[sim_id].total_recv_size += cnf_data->bearer_cnf_count[j].receive_data_size;
                                temp_total_gprs_data[sim_id].total_sent_size += cnf_data->bearer_cnf_count[j].send_data_size;
                                if (index >= 0)
                                {
                                    temp_total_gprs_data[sim_id].total_connect_duration += g_cnmgr_srv_bearer_list[index].connect_time;
                                }

                                if (CNMGR_LOCAL_PTR(i)->profile_id == CNMGR_TBL_PTR(sim_id)->gprs_last_session_profile_id)
                                {
                                	temp_total_gprs_data[sim_id].last_recv_size = cnf_data->bearer_cnf_count[j].receive_data_size;
                                	temp_total_gprs_data[sim_id].last_sent_size = cnf_data->bearer_cnf_count[j].send_data_size;
                                    if (index >= 0)
                                    {
                                        temp_total_gprs_data[sim_id].last_connect_duration = g_cnmgr_srv_bearer_list[index].connect_time;
                                    }
                                    else
                                    {
                                        temp_total_gprs_data[sim_id].last_connect_duration = 0;
                                    }
                                }

                                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                                          SRV_CNMGR_LOCAL_BEARER_DATA,
                                          sim_id,
                                          CNMGR_LOCAL_PTR(i)->bearer_type,
                                          (U32)temp_total_gprs_data[sim_id].last_sent_size,
                                          (U32)temp_total_gprs_data[sim_id].last_recv_size,
                                          (U32)temp_total_gprs_data[sim_id].last_connect_duration,
                                          (U32)temp_total_gprs_data[sim_id].total_sent_size,
                                          (U32)temp_total_gprs_data[sim_id].total_recv_size,
                                          (U32)temp_total_gprs_data[sim_id].total_connect_duration);

                                break;
                            }

#ifdef __MMI_WLAN_FEATURES__
                            case SRV_CNMGR_BEARER_TYPE_WIFI:
                            {
                                memcpy(&temp_data, &g_cnmgr_srv_history_data_cntx.local_wifi_data, sizeof(srv_cnmgr_connect_data_detail_struct));
                                temp_data.last_recv_size = cnf_data->bearer_cnf_count[j].receive_data_size;
                                temp_data.last_sent_size = cnf_data->bearer_cnf_count[j].send_data_size;
                                if (index >= 0)
                                {
                                    temp_data.last_connect_duration = g_cnmgr_srv_bearer_list[index].connect_time;
                                }
                                else
                                {
                                    temp_data.last_connect_duration = 0;
                                }
                                temp_data.total_recv_size += cnf_data->bearer_cnf_count[j].receive_data_size;
                                temp_data.total_sent_size += cnf_data->bearer_cnf_count[j].send_data_size;
                                if (index >= 0)
                                {
                                    temp_data.total_connect_duration += g_cnmgr_srv_bearer_list[index].connect_time;
                                }

                                if (not_update == MMI_FALSE)
                                {
                                    srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_WIFI, CBM_SIM_ID_TOTAL, (void*)(&temp_data));
                                }

                                memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_wifi_data), &temp_data, sizeof(srv_cnmgr_connect_data_detail_struct));

                                break;
			                }
#endif /* __WIFI_SUPPORT__ */

                            default:
                                break;
                        }
                    }
                }
            }
        }

        for (i = 0; i < SRV_CNMGR_SIM_TOTAL; i++)
        {
            memcpy(&temp_data, &CNMGR_TBL_PTR(i)->local_total_data, sizeof(srv_cnmgr_connect_data_detail_struct));

            if (CNMGR_CTX(tcpip_active_bearer_num) > 0)
            {
                if (temp_total_data[i].last_recv_size ||
                    temp_total_data[i].last_sent_size ||
                    temp_total_data[i].last_connect_duration)
                {
                    temp_data.last_recv_size = temp_total_data[i].last_recv_size;
                    temp_data.last_sent_size = temp_total_data[i].last_sent_size;
                    temp_data.last_connect_duration = temp_total_data[i].last_connect_duration;
                }
                temp_data.total_recv_size += temp_total_data[i].total_recv_size;
                temp_data.total_sent_size += temp_total_data[i].total_sent_size;
                temp_data.total_connect_duration += temp_total_data[i].total_connect_duration;

                if (not_update == MMI_FALSE)
                {
                    srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_TOTAL, (cbm_sim_id_enum)i, (void*)(&temp_data));
                }
            }

            memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_total_data[i]),
                   &temp_data,
                   sizeof(srv_cnmgr_connect_data_detail_struct));

            memcpy(&temp_data, &CNMGR_TBL_PTR(i)->local_gprs_data, sizeof(srv_cnmgr_connect_data_detail_struct));

            if (CNMGR_CTX(tcpip_active_bearer_num) > 0)
            {
                if (temp_total_gprs_data[i].last_recv_size ||
                    temp_total_gprs_data[i].last_sent_size ||
                    temp_total_gprs_data[i].last_connect_duration)
                {
                    temp_data.last_recv_size = temp_total_gprs_data[i].last_recv_size;
                    temp_data.last_sent_size = temp_total_gprs_data[i].last_sent_size;
                    temp_data.last_connect_duration = temp_total_gprs_data[i].last_connect_duration;
                }
                if (temp_total_gprs_data[i].total_recv_size ||
                    temp_total_gprs_data[i].total_sent_size ||
                    temp_total_gprs_data[i].total_connect_duration)
                {
                    temp_data.total_recv_size += temp_total_gprs_data[i].total_recv_size;
                    temp_data.total_sent_size += temp_total_gprs_data[i].total_sent_size;
                    temp_data.total_connect_duration += temp_total_gprs_data[i].total_connect_duration;
                }

                if (not_update == MMI_FALSE)
                {
                    srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_GPRS, (cbm_sim_id_enum)i, (void*)(&temp_data));
                }
            }

            memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_gprs_data[i]),
                   &temp_data,
                   sizeof(srv_cnmgr_connect_data_detail_struct));
        }
    }
    else if (cnf_data->connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
    {
        for (i = 0; i < SRV_CNMGR_SIM_TOTAL; i++)
        {
            memcpy(&(temp_dialup_data[i]), &CNMGR_TBL_PTR(i)->dialup_data, sizeof(srv_cnmgr_connect_data_detail_struct));
        }
        
        for (i = 0; i < cnf_data->count; i++)
        {
            index = srv_cnmgr_get_bearer_node_index(cnf_data->bearer_cnf_count[i].dialup_info.context_id,
                                                    srv_cnmgr_convert_abm_connect_type_to_cnmgr(cnf_data->connect_type),
                                                    cnf_data->bearer_cnf_count[i].dialup_info.bearer_type);
            sim_id = (cbm_sim_id_enum)cnf_data->bearer_cnf_count[i].dialup_info.sim_id;

            if (sim_id < CBM_SIM_ID_TOTAL && cnf_data->bearer_cnf_count[i].dialup_info.bearer_type == GPRS_BEARER_DIALUP)
            {    
                temp_dialup_data[sim_id].total_recv_size += cnf_data->bearer_cnf_count[i].receive_data_size;
                temp_dialup_data[sim_id].total_sent_size += cnf_data->bearer_cnf_count[i].send_data_size;
                if (index >= 0)
                {
                    temp_dialup_data[sim_id].total_connect_duration += g_cnmgr_srv_bearer_list[index].connect_time;
                }
                if (CNMGR_TBL_PTR(sim_id)->last_session_context_id == cnf_data->bearer_cnf_count[i].dialup_info.context_id)
                {
                    temp_dialup_data[sim_id].last_recv_size = cnf_data->bearer_cnf_count[i].receive_data_size;
                    temp_dialup_data[sim_id].last_sent_size = cnf_data->bearer_cnf_count[i].send_data_size;
                    if (index >= 0)
                    {
                        temp_dialup_data[sim_id].last_connect_duration = g_cnmgr_srv_bearer_list[index].connect_time;
                    }
                    else
                    {
                        temp_dialup_data[sim_id].last_connect_duration = 0;
                    }
                }
            }
        }

        if (not_update == MMI_FALSE)
        {
            srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_DIALUP, sim_id, (void*)(&temp_dialup_data[sim_id]));
        }

        for (i = 0; i < SRV_CNMGR_SIM_TOTAL; i++)
        {
            memcpy(&(g_cnmgr_srv_runtime_data_cntx.dialup_data[i]),
                   &temp_dialup_data[i],
                   sizeof(srv_cnmgr_connect_data_detail_struct));
        }
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_UPDATE_RUNTIME_DATA,
              1,
              cnf_data->connect_type,
              cnf_data->count);
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_bearer_info_ind_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_ABM_BEARER_INFO_IND
 *  Will add bearer node to g_cnmgr_srv_bearer_list if CNMGR needs to count the data
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_cnmgr_bearer_info_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 en_acct_id;
    S32 index;
    cbm_sim_id_enum sim_id;
    srv_cnmgr_bearer_type_enum bearer_type = SRV_CNMGR_BEARER_TYPE_TOTAL;
    mmi_abm_bearer_info_ind_struct *bearer_info;
    MMI_BOOL not_display = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_info = (mmi_abm_bearer_info_ind_struct *)msg;

    if (bearer_info->connect_type == ABM_CONNECT_TYPE_LOCAL)
    {
        switch (bearer_info->bearer_type)
        {
            case CBM_CSD:
            {
                bearer_type = SRV_CNMGR_BEARER_TYPE_CSD;
                break;
            }

            case CBM_GPRS:
            case CBM_EDGE:
            case CBM_UMTS:
            case CBM_PS:
            {
                bearer_type = SRV_CNMGR_BEARER_TYPE_GPRS;
                break;
            }

            case CBM_WIFI:
            {
                bearer_type = SRV_CNMGR_BEARER_TYPE_WIFI;
                break;
            }
                
            case CBM_WIFI_HS:
            case CBM_USB_TR:
                /* Ignore Wi-Fi hot spot and USB tethering messages */
                return MMI_FALSE;

            default:
               break;
        }
    }
    else if (bearer_info->connect_type == ABM_CONNECT_TYPE_DIALUP)
    {
        switch (bearer_info->dialup_info.bearer_type)
        {
            case GPRS_BEARER_DIALUP:
            {
                bearer_type = SRV_CNMGR_BEARER_TYPE_GPRS;
                break;
            }

            case CSD_BEARER_DIALUP:
            {
                bearer_type = SRV_CNMGR_BEARER_TYPE_CSD;
                break;
            }

            default:
               break;
        }
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_BEARER_INFO_IND, bearer_info->status, bearer_info->profile_id, bearer_info->connect_type);

    /*----------------------------------------------------------------*/
    /* For ACTIVATED indication                                       */
    /*----------------------------------------------------------------*/
    if (bearer_info->status == CBM_ACTIVATED)
    {
        if (bearer_info->connect_type == ABM_CONNECT_TYPE_LOCAL)
        {
            sim_id = cbm_get_sim_id(bearer_info->profile_id);

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
            if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_IDLE &&
                #ifndef __MMI_3G_SWITCH__
                sim_id == CBM_SIM_ID_SIM1 &&
                #else
                sim_id == g_cnmgr_srv_cntx.cur_3g_sim &&
                #endif
                (bearer_type == SRV_CNMGR_BEARER_TYPE_GPRS ||
                 bearer_type == SRV_CNMGR_BEARER_TYPE_CSD))
            {
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
            #endif
                SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_MONITORING);
            }
#endif

            srv_cnmgr_change_last_session_bearer(bearer_info->profile_id,
                                                 sim_id,
                                                 bearer_type,
                                                 SRV_CNMGR_CONNECT_TYPE_LOCAL,
                                                 SRV_CNMGR_BEARER_STATE_ACTIVE);
            srv_cnmgr_change_transmit_data_time(bearer_info->profile_id,
                                                sim_id,
                                                bearer_type,
                                                SRV_CNMGR_CONNECT_TYPE_LOCAL,
                                                SRV_CNMGR_BEARER_STATE_ACTIVE,
                                                0,
                                                0);

            if (cbm_get_original_account(bearer_info->profile_id) == CBM_DCD_ACCT_ID || 
                cbm_get_original_account(bearer_info->profile_id) == CBM_SAT_PS_ACCT_ID ||
                cbm_get_original_account(bearer_info->profile_id) == CBM_SAT_CSD_ACCT_ID)
            {
                not_display = MMI_TRUE;
            }
        }
        else if (bearer_info->connect_type == ABM_CONNECT_TYPE_DIALUP && 
                 bearer_info->dialup_info.bearer_type == GPRS_BEARER_DIALUP)
        {
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
            if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_IDLE &&
                #ifndef __MMI_3G_SWITCH__
                bearer_info->dialup_info.sim_id == CBM_SIM_ID_SIM1 &&
                #else
                bearer_info->dialup_info.sim_id == g_cnmgr_srv_cntx.cur_3g_sim &&
                #endif
                (bearer_type == SRV_CNMGR_BEARER_TYPE_GPRS ||
                 bearer_type == SRV_CNMGR_BEARER_TYPE_CSD))
            {
                /* Only need to send SCRI when SIM1 has transmitted data */
                SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_MONITORING);
            }
#endif

            if (bearer_info->dialup_info.sim_id < CBM_SIM_ID_TOTAL)
            {
                srv_cnmgr_change_last_session_bearer(bearer_info->dialup_info.context_id,
                                                     (cbm_sim_id_enum)bearer_info->dialup_info.sim_id,
                                                     bearer_type,
                                                     SRV_CNMGR_CONNECT_TYPE_DIALUP,
                                                     SRV_CNMGR_BEARER_STATE_ACTIVE);
                srv_cnmgr_change_transmit_data_time(bearer_info->dialup_info.context_id,
                                                    (cbm_sim_id_enum)bearer_info->dialup_info.sim_id,
                                                    bearer_type,
                                                    SRV_CNMGR_CONNECT_TYPE_DIALUP,
                                                    SRV_CNMGR_BEARER_STATE_ACTIVE,
                                                    0,
                                                    0);
            } 
        }

        srv_cnmgr_add_or_update_bearer_list(bearer_info, bearer_type, SRV_CNMGR_BEARER_STATUS_ACTIVE, MMI_TRUE, not_display);

        /* Start timer and notify application that active bearer list is updated */
        srv_cnmgr_start_timer();
    }
    /*----------------------------------------------------------------*/
    /* For DEACTIVATED indication                                     */
    /*----------------------------------------------------------------*/
    else if (bearer_info->status == CBM_DEACTIVATED)
    {
        if (bearer_info->connect_type == ABM_CONNECT_TYPE_DIALUP)
        {
            if (bearer_info->dialup_info.bearer_type == CSD_BEARER_DIALUP)
            {
                en_acct_id = cbm_encode_data_account_id(bearer_info->dialup_info.call_id, (cbm_sim_id_enum)bearer_info->dialup_info.sim_id, 0, KAL_FALSE);
                index = srv_cnmgr_get_bearer_node_index(en_acct_id,
                                                        srv_cnmgr_convert_abm_connect_type_to_cnmgr(bearer_info->connect_type),
                                                        bearer_info->dialup_info.bearer_type);
            }
            else
            {
                en_acct_id = cbm_encode_data_account_id(bearer_info->dialup_info.context_id, (cbm_sim_id_enum)bearer_info->dialup_info.sim_id, 0, KAL_FALSE);
                index = srv_cnmgr_get_bearer_node_index(en_acct_id,
                                                        srv_cnmgr_convert_abm_connect_type_to_cnmgr(bearer_info->connect_type),
                                                        bearer_info->dialup_info.bearer_type);

                if (index >=0 && bearer_info->dialup_info.sim_id < CBM_SIM_ID_TOTAL)
                {
                    srv_cnmgr_change_last_session_bearer(bearer_info->dialup_info.context_id,
                                                         (cbm_sim_id_enum)bearer_info->dialup_info.sim_id,
                                                         bearer_type,
                                                         SRV_CNMGR_CONNECT_TYPE_DIALUP,
                                                         SRV_CNMGR_BEARER_STATE_DEACTIVE);
                    srv_cnmgr_change_transmit_data_time(bearer_info->dialup_info.context_id,
                                                        (cbm_sim_id_enum)bearer_info->dialup_info.sim_id,
                                                        bearer_type,
                                                        SRV_CNMGR_CONNECT_TYPE_DIALUP,
                                                        SRV_CNMGR_BEARER_STATE_DEACTIVE,
                                                        bearer_info->recv_data_size,
                                                        bearer_info->send_data_size);
                }
            }
        }
        else
        {
            sim_id = cbm_get_sim_id(bearer_info->profile_id);
            index = srv_cnmgr_get_bearer_node_index(bearer_info->profile_id,
                                                    srv_cnmgr_convert_abm_connect_type_to_cnmgr(bearer_info->connect_type),
                                                    0);
            if (index >= 0 && g_cnmgr_srv_bearer_list[index].need_update == MMI_TRUE)
            {
                srv_cnmgr_change_last_session_bearer(bearer_info->profile_id,
                                                     sim_id,
                                                     bearer_type,
                                                     SRV_CNMGR_CONNECT_TYPE_LOCAL,
                                                     SRV_CNMGR_BEARER_STATE_DEACTIVE);
                srv_cnmgr_change_transmit_data_time(bearer_info->profile_id,
                                                    sim_id,
                                                    bearer_type,
                                                    SRV_CNMGR_CONNECT_TYPE_LOCAL,
                                                    SRV_CNMGR_BEARER_STATE_DEACTIVE,
                                                    bearer_info->recv_data_size,
                                                    bearer_info->send_data_size);
            }
        }

        if (index < 0)
        {
#ifdef __MMI_CBM_CONNECTION_MANAGER__
            if (g_cnmgr_srv_cntx.backup_list_flag && srv_cnmgr_is_no_valid_bearer())
            {
                g_cnmgr_srv_cntx.backup_list_flag = MMI_FALSE;
                srv_cnmgr_move_bearer_node_to_bearer_list();
            }
#endif

            srv_cnmgr_check_and_stop_timer();

#ifdef __USB_TETHERING__
            if (cbm_get_original_account(bearer_info->profile_id) == CBM_USB_TR_PS_ACCT_ID)
            {
                g_cnmgr_srv_cntx.user_tethering_acct = CBM_INVALID_NWK_ACCT_ID;
            }
#endif
            return MMI_FALSE;
        }

        srv_cnmgr_remove_node_from_bearer_list(g_cnmgr_srv_bearer_list[index].profile_id,
                                               g_cnmgr_srv_bearer_list[index].connect_type,
                                               g_cnmgr_srv_bearer_list[index].dialup_type);

#ifdef __MMI_CBM_CONNECTION_MANAGER__
        if (g_cnmgr_srv_cntx.backup_list_flag && srv_cnmgr_is_no_valid_bearer())
        {
            g_cnmgr_srv_cntx.backup_list_flag = MMI_FALSE;
            srv_cnmgr_move_bearer_node_to_bearer_list();
        }
#endif

        srv_cnmgr_check_and_stop_timer();

#ifdef __USB_TETHERING__
        if (cbm_get_original_account(bearer_info->profile_id) == CBM_USB_TR_PS_ACCT_ID)
        {
            g_cnmgr_srv_cntx.user_tethering_acct = CBM_INVALID_NWK_ACCT_ID;
        }
#endif
    }
    /*----------------------------------------------------------------*/
    /* For ACTIVATING and DEACTIVATING indication                     */
    /*----------------------------------------------------------------*/
    else if(bearer_info->status == CBM_ACTIVATING || 
            bearer_info->status == CBM_DEACTIVATING)
    {
#ifdef __USB_TETHERING__
        /*
         * USB tethering service reset account before CNMGR receive bearer deactivated indication,
         * so CNMGR can not get tethering account to remove bearer node from merged_bearer_list correctly.
         */
        if (bearer_info->status == CBM_ACTIVATING &&
            cbm_get_original_account(bearer_info->profile_id) == CBM_USB_TR_PS_ACCT_ID)
        {
            g_cnmgr_srv_cntx.user_tethering_acct = cbm_get_original_account(srv_tethering_usb_qurey_acct_id());
            MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_TETHERING_ACCOUNT, g_cnmgr_srv_cntx.user_tethering_acct);
        }
#endif

        if (cbm_get_original_account(bearer_info->profile_id) == CBM_DCD_ACCT_ID || 
            cbm_get_original_account(bearer_info->profile_id) == CBM_SAT_PS_ACCT_ID ||
            cbm_get_original_account(bearer_info->profile_id) == CBM_SAT_CSD_ACCT_ID)
        {
            /* Does not display these three connections */
            not_display = MMI_TRUE;
        }
        
        index = srv_cnmgr_get_bearer_node_index(bearer_info->profile_id,
                                                srv_cnmgr_convert_abm_connect_type_to_cnmgr(bearer_info->connect_type),
                                                bearer_info->dialup_info.bearer_type);

        if (index >= 0)
        {
            g_cnmgr_srv_bearer_list[index].bearer_status = ((bearer_info->status == CBM_ACTIVATING) ? SRV_CNMGR_BEARER_STATUS_ACTIVATING : SRV_CNMGR_BEARER_STATUS_DEACTIVATING);

            if (bearer_info->status == CBM_DEACTIVATING)
            {
                g_cnmgr_srv_bearer_list[index].detail.up_speed = 0;
                g_cnmgr_srv_bearer_list[index].detail.down_speed = 0;
            }

#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
            if (not_display == MMI_FALSE)
            {
                srv_cnmgr_update_merged_bearer_status(bearer_info->profile_id,
                                                      srv_cnmgr_convert_abm_connect_type_to_cnmgr(bearer_info->connect_type),
                                                      bearer_info->dialup_info.bearer_type,
                                                      g_cnmgr_srv_bearer_list[index].bearer_status);
            }
#endif
        }
        else
        {
            srv_cnmgr_add_or_update_bearer_list(bearer_info,
                                                bearer_type,
                                                ((bearer_info->status == CBM_ACTIVATING) ? SRV_CNMGR_BEARER_STATUS_ACTIVATING : SRV_CNMGR_BEARER_STATUS_DEACTIVATING),
                                                MMI_FALSE,
                                                not_display);
        }
    }

#ifdef __MMI_CBM_CONNECTION_MANAGER__
    srv_cnmgr_bearer_data_update_notify();
#endif

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_bearer_info_req_handler
 * DESCRIPTION
 *  Send MSG_ID_MMI_ABM_GET_BEARER_INFO_REQ to ABM to get bearer information
 *  One MSG_ID_MMI_ABM_GET_BEARER_INFO_REQ may receive two MSG_ID_MMI_ABM_GET_BEARER_INFO_CNF
 *  if GET_BEARER_INFO_REQ contains both LOCAL and DIALUP type
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_CNMGR_RESULT_SUCCESS
 *  SRV_CNMGR_RESULT_WAIT_FOR_RSP
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_get_bearer_info_req_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_get_bearer_info_req_struct *req = NULL;
    U32 i, bearer_num, req_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_GET_BEARER_INFO_REQ, g_cnmgr_srv_cntx.get_bearer_info_rsp_num);

    if (g_cnmgr_srv_cntx.get_bearer_info_rsp_num != 0)
    {
        /* Already send request to ABM */
        return SRV_CNMGR_RESULT_WAIT_FOR_RSP;
    }

    /* Count the number of BEARER_INFO_CNF messages CNMGR should wait and process */
    g_cnmgr_srv_cntx.get_bearer_info_rsp_num = srv_cnmgr_check_active_bearer_type();
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_GET_BEARER_INFO_REQ, g_cnmgr_srv_cntx.get_bearer_info_rsp_num);

    /* Get the number of active bearer */
    bearer_num = srv_cnmgr_get_active_bearer_num();

    if (bearer_num != 0)
    {
        for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
        {
            if (g_cnmgr_srv_bearer_list[i].valid &&
                g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
            {
                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_GET_BEARER_INFO_REQ_BEARER_NODE,
                          g_cnmgr_srv_bearer_list[i].profile_id,
                          g_cnmgr_srv_bearer_list[i].connect_type,
                          g_cnmgr_srv_bearer_list[i].dialup_type);

                if (g_cnmgr_srv_bearer_list[i].connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP &&
                    g_cnmgr_srv_bearer_list[i].dialup_type != GPRS_BEARER_DIALUP)
                {
                    continue;
                }

                if (req == NULL)
                {
                    req = OslAllocDataPtr(mmi_abm_get_bearer_info_req_struct);
                }

                req->bearer_req_count[req_count].profile_id = g_cnmgr_srv_bearer_list[i].profile_id;

                if (g_cnmgr_srv_bearer_list[i].profile_id != CBM_WIFI_ACCT_ID)
                {
                    /* Only support one SIM network connection even if multiple SIM project */
                    g_cnmgr_srv_cntx.bearer_info_req_sim_id = (cbm_sim_id_enum)g_cnmgr_srv_bearer_list[i].sim_id;
                }

                req->bearer_req_count[req_count].connect_type = srv_cnmgr_convert_cnmgr_connect_type_to_abm(g_cnmgr_srv_bearer_list[i].connect_type);
                
                if (g_cnmgr_srv_bearer_list[i].connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
                {
                    req->bearer_req_count[req_count].dialup_info.bearer_type = GPRS_BEARER_DIALUP;
                    req->bearer_req_count[req_count].dialup_info.context_id = g_cnmgr_srv_bearer_list[i].profile_id;
                    req->bearer_req_count[req_count].dialup_info.sim_id = g_cnmgr_srv_bearer_list[i].sim_id;
                }

                req_count++;
            }
        }

        if (req)
        {
            req->count = req_count;
            mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_GET_BEARER_INFO_REQ, (oslParaType*)req, NULL);

            srv_cnmgr_start_timer();
            g_cnmgr_srv_cntx.get_bearer_info_wait_count = 0;

            return SRV_CNMGR_RESULT_WAIT_FOR_RSP;
        }
    }

    srv_cnmgr_check_and_stop_timer();
    
    /* Reply connection data to application */
    srv_cnmgr_reply_connection_data(MMI_TRUE);

    return SRV_CNMGR_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_bearer_info_cnf_handler
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_ABM_GET_BEARER_INFO_CNF
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  MMI_TRUE: event is handled
 *  MMI_FALSE: event is not handled
 *****************************************************************************/
U8 srv_cnmgr_get_bearer_info_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_get_bearer_info_cnf_struct *cnf;
    U64 send_data_size, recv_data_size;
    U32 acct_id = 0xFFFFFFFF;
    S32 index , i;
#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
    srv_cnmgr_bearer_detail_struct old_data, new_data;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf = (mmi_abm_get_bearer_info_cnf_struct*)msg;

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    /* provide icon info to nwinfo app*/
    srv_cnmgr_notify_nwinfo(cnf);
    if(g_cnmgr_srv_cntx.send_for_nwinfo == MMI_TRUE)
    {
        MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_ONLY_FOR_NWINFO); 
        g_cnmgr_srv_cntx.get_bearer_info_rsp_num--;
        if (g_cnmgr_srv_cntx.get_bearer_info_rsp_num == 0)
        {
            srv_cnmgr_post_nwinfo_evt(MMI_TRUE);
        }        
        return 0;
    }
    
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_FOR_NWINFO_AND_SCRI); 
#endif /* __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
    
    /* Update runtime data */
    srv_cnmgr_update_runtime_data(cnf);

    if (g_cnmgr_srv_cntx.get_bearer_info_rsp_num == 1)
    {
        g_cnmgr_srv_cntx.get_bearer_info_wait_count = g_cnmgr_srv_cntx.bearer_data_update_interval;
    }

    /* Calculate connection data of each bearer */
    for (i = 0; i < cnf->count; i++)
    {
        if (cnf->connect_type == ABM_CONNECT_TYPE_DIALUP)
        {
            if (cnf->bearer_cnf_count[i].dialup_info.bearer_type == CSD_BEARER_DIALUP)
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].dialup_info.call_id, g_cnmgr_srv_cntx.bearer_info_req_sim_id, 0, KAL_FALSE);
            }
            else if (cnf->bearer_cnf_count[i].dialup_info.bearer_type == GPRS_BEARER_DIALUP)
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].dialup_info.context_id, g_cnmgr_srv_cntx.bearer_info_req_sim_id, 0, KAL_FALSE);
            }
            index = srv_cnmgr_get_bearer_node_index(acct_id, SRV_CNMGR_CONNECT_TYPE_DIALUP, cnf->bearer_cnf_count[i].dialup_info.bearer_type);
        }
        else
        {
            if (cnf->bearer_cnf_count[i].profile_id == CBM_WIFI_ACCT_ID)
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].profile_id, CBM_SIM_ID_SIM1, 0, KAL_FALSE);
            }
            else
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].profile_id, g_cnmgr_srv_cntx.bearer_info_req_sim_id, 0, KAL_FALSE);
            }
            index = srv_cnmgr_get_bearer_node_index(acct_id, SRV_CNMGR_CONNECT_TYPE_LOCAL, 0);
        }

        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_GET_BEARER_INFO_CNF,
                  cnf->count,
                  cnf->connect_type,
                  acct_id,
                  index,
                  cnf->bearer_cnf_count[i].result);

        if (index >= 0)
        {
#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
            memcpy(&old_data, &(g_cnmgr_srv_bearer_list[index].detail), sizeof(srv_cnmgr_bearer_detail_struct));
#endif

            if (cnf->bearer_cnf_count[i].result)
            {
                if (cnf->bearer_cnf_count[i].send_data_size < g_cnmgr_srv_bearer_list[index].detail.curr_send_data_size ||
                    cnf->bearer_cnf_count[i].receive_data_size < g_cnmgr_srv_bearer_list[index].detail.curr_recv_data_size)
                {
                    g_cnmgr_srv_bearer_list[index].need_acc = MMI_TRUE;
                }

                if (g_cnmgr_srv_bearer_list[index].need_acc)
                {
                    g_cnmgr_srv_bearer_list[index].need_acc = MMI_FALSE;

                    send_data_size = cnf->bearer_cnf_count[i].send_data_size;
                    recv_data_size = cnf->bearer_cnf_count[i].receive_data_size;
                }
                else
                {
                    send_data_size = cnf->bearer_cnf_count[i].send_data_size - g_cnmgr_srv_bearer_list[index].detail.curr_send_data_size;
                    recv_data_size = cnf->bearer_cnf_count[i].receive_data_size - g_cnmgr_srv_bearer_list[index].detail.curr_recv_data_size;
                }

                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_GET_BEARER_INFO_CNF_DETAIL,
                          index,
                          (U32)cnf->bearer_cnf_count[i].send_data_size,
                          (U32)g_cnmgr_srv_bearer_list[index].detail.curr_send_data_size,
                          (U32)send_data_size,
                          (U32)cnf->bearer_cnf_count[i].receive_data_size,
                          (U32)g_cnmgr_srv_bearer_list[index].detail.curr_recv_data_size,
                          (U32)recv_data_size);

                g_cnmgr_srv_bearer_list[index].detail.curr_send_data_size = cnf->bearer_cnf_count[i].send_data_size;
                g_cnmgr_srv_bearer_list[index].detail.curr_recv_data_size = cnf->bearer_cnf_count[i].receive_data_size;
                g_cnmgr_srv_bearer_list[index].detail.up_speed = send_data_size;
                g_cnmgr_srv_bearer_list[index].detail.down_speed = recv_data_size;
                g_cnmgr_srv_bearer_list[index].detail.send_data_size += send_data_size;
                g_cnmgr_srv_bearer_list[index].detail.recv_data_size += recv_data_size;

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
                if ((g_cnmgr_srv_bearer_list[index].detail.send_data_size + g_cnmgr_srv_bearer_list[index].detail.recv_data_size) != g_cnmgr_srv_bearer_list[index].detail.all_data_size)
                {
                    g_cnmgr_srv_bearer_list[index].detail.update_time = app_getcurrtime();

                    if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_WAITING &&
                        #ifndef __MMI_3G_SWITCH__
                        g_cnmgr_srv_bearer_list[index].sim_id == CBM_SIM_ID_SIM1 &&
                        #else
                        g_cnmgr_srv_bearer_list[index].sim_id ==  g_cnmgr_srv_cntx.cur_3g_sim &&
                        #endif
                        (g_cnmgr_srv_bearer_list[index].bearer_type == SRV_CNMGR_BEARER_TYPE_GPRS ||
                         g_cnmgr_srv_bearer_list[index].bearer_type == SRV_CNMGR_BEARER_TYPE_CSD))
                    {
                        g_cnmgr_srv_cntx.scri_retry_num = 0;
                        SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_MONITORING);
                    }
                }
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

                g_cnmgr_srv_bearer_list[index].detail.all_data_size = g_cnmgr_srv_bearer_list[index].detail.send_data_size + g_cnmgr_srv_bearer_list[index].detail.recv_data_size;
            }
            else
            {
                if (!g_cnmgr_srv_bearer_list[index].need_acc)
                {
                    g_cnmgr_srv_bearer_list[index].need_acc = MMI_TRUE;
                    g_cnmgr_srv_bearer_list[index].detail.up_speed = 0;
                    g_cnmgr_srv_bearer_list[index].detail.down_speed = 0;
                }
            }

#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
            /* Update merged bearer data */
            memcpy(&new_data, &(g_cnmgr_srv_bearer_list[index].detail), sizeof(srv_cnmgr_bearer_detail_struct));
            srv_cnmgr_update_merged_bearer_data(g_cnmgr_srv_bearer_list[index].profile_id,
                                                g_cnmgr_srv_bearer_list[index].connect_type,
                                                g_cnmgr_srv_bearer_list[index].dialup_type,
                                                &old_data,
                                                &new_data);
#endif
        }
    }

    g_cnmgr_srv_cntx.get_bearer_info_rsp_num--;
    if (g_cnmgr_srv_cntx.get_bearer_info_rsp_num == 0)
    {
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        srv_cnmgr_post_nwinfo_evt(MMI_TRUE);
#endif /* __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
        if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_MONITORING ||
            g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_GETTING_PCH_STATUS)
        {
            U8 valid_num = 0, no_data_transfer_num = 0;
            U32 curr_time = app_getcurrtime();
            U32 scri_check_interval;

            MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_LCD_STATUS, srv_backlight_is_lcd_sleep());
            if (srv_backlight_is_lcd_sleep())
            {
                scri_check_interval = g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF];
            }
            else
            {
                scri_check_interval = g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON];
            }

            for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
            {
                if (g_cnmgr_srv_bearer_list[i].valid &&
                    (g_cnmgr_srv_bearer_list[i].bearer_type == SRV_CNMGR_BEARER_TYPE_GPRS ||
                     g_cnmgr_srv_bearer_list[i].bearer_type == SRV_CNMGR_BEARER_TYPE_CSD))
                {
                    valid_num++;
                    if ((curr_time - g_cnmgr_srv_bearer_list[i].detail.update_time) >= scri_check_interval)
                    {
                        no_data_transfer_num++;
                    }
                }
            }

            if (valid_num > 0 && valid_num == no_data_transfer_num)
            {
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
                if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_MONITORING)
                {
                    #ifdef __MMI_3G_SWITCH__
                    mmi_sim_enum cur_3g_sim = srv_netset_get_3g_capability_sim();
                    #endif
                    SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_GETTING_PCH_STATUS);
                    #ifdef __MMI_3G_SWITCH__
                    srv_netset_get_pch_mode(cur_3g_sim, srv_cnmgr_get_pch_status_callback, NULL);
                    #else
                    srv_netset_get_pch_mode(MMI_SIM1, srv_cnmgr_get_pch_status_callback, NULL);
                    #endif
                }
#else
                MMI_BOOL force_send_scri;
                if (srv_cnmgr_can_send_end_ps_data_session_req(&force_send_scri, MMI_FALSE))
                {
                    SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_ENDING_PS_DATA_SESSION);
                    srv_cnmgr_end_ps_data_session_req_handler(force_send_scri);
                }
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
            }
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
            else if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_GETTING_PCH_STATUS)
            {
                SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_MONITORING);
            }
#endif
        }
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

        /* Notify user application */
        srv_cnmgr_reply_connection_data(MMI_FALSE);
        srv_cnmgr_connect_data_update_notify();
#ifdef __MMI_CBM_CONNECTION_MANAGER__
        srv_cnmgr_bearer_data_update_notify();
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_reply_connection_data
 * DESCRIPTION
 *  This API is used to reply connection data to user application
 * PARAMETERS
 *  history_data    [IN]    Use history data or not
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_cnmgr_reply_connection_data(MMI_BOOL history_data)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_connect_data_rsp_struct connect_data_rsp;
    srv_cnmgr_connect_data_cb_funcptr_type cb_func;
    void *user_data;    
    U32 i;
    U8 sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_REPLY_CONNECTION_DATA);

    for (i = 0; i < SRV_CNMGR_MAX_CONNECT_DATA_REQ; i++)
    {
        if (g_cnmgr_srv_cntx.get_connect_data_req_list[i].is_used)
        {
            memset(&connect_data_rsp, 0, sizeof(srv_cnmgr_connect_data_rsp_struct));
            connect_data_rsp.query.bearer_type = g_cnmgr_srv_cntx.get_connect_data_req_list[i].query.bearer_type;
            sim_id = srv_cnmgr_convert_mmi_sim_id_to_cnmgr(g_cnmgr_srv_cntx.get_connect_data_req_list[i].query.sim_id);
            connect_data_rsp.query.sim_id = g_cnmgr_srv_cntx.get_connect_data_req_list[i].query.sim_id;

            if (history_data)
            {
                switch (g_cnmgr_srv_cntx.get_connect_data_req_list[i].query.bearer_type)
                {
#ifdef __TCPIP_OVER_CSD__
                    case SRV_CNMGR_BEARER_TYPE_CSD:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &CNMGR_TBL_PTR(sim_id)->local_csd_data,
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }
#endif /* __TCPIP_OVER_CSD__ */

                    case SRV_CNMGR_BEARER_TYPE_GPRS:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &CNMGR_TBL_PTR(sim_id)->local_gprs_data,
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }

#ifdef __MMI_WLAN_FEATURES__
                    case SRV_CNMGR_BEARER_TYPE_WIFI:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &(g_cnmgr_srv_history_data_cntx.local_wifi_data),
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }
#endif /* __WIFI_SUPPORT__ */

                    case SRV_CNMGR_BEARER_TYPE_SIM_PS:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &CNMGR_TBL_PTR(sim_id)->local_total_data,
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }

                    default:
                        break;
                }

                memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP]),
                       &CNMGR_TBL_PTR(sim_id)->dialup_data,
                       sizeof(srv_cnmgr_connect_data_detail_struct));
            }
            else
            {
                switch (g_cnmgr_srv_cntx.get_connect_data_req_list[i].query.bearer_type)
                {
#ifdef __TCPIP_OVER_CSD__
                    case SRV_CNMGR_BEARER_TYPE_CSD:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &(g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id]),
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }
#endif /* __TCPIP_OVER_CSD__ */

                    case SRV_CNMGR_BEARER_TYPE_GPRS:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &(g_cnmgr_srv_runtime_data_cntx.local_gprs_data[sim_id]),
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }

#ifdef __MMI_WLAN_FEATURES__
                    case SRV_CNMGR_BEARER_TYPE_WIFI:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &(g_cnmgr_srv_runtime_data_cntx.local_wifi_data),
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }
#endif /* __WIFI_SUPPORT__ */

                    case SRV_CNMGR_BEARER_TYPE_SIM_PS:
                    {
                        memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL]),
                               &(g_cnmgr_srv_runtime_data_cntx.local_total_data[sim_id]),
                               sizeof(srv_cnmgr_connect_data_detail_struct));
                        break;
                    }

                    default:
                        break;
                }

                memcpy(&(connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP]),
                       &(g_cnmgr_srv_runtime_data_cntx.dialup_data[sim_id]),
                       sizeof(srv_cnmgr_connect_data_detail_struct));
            }

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_REPLY_CONNECTION_DATA_DETAIL,
                      connect_data_rsp.query.sim_id,
                      connect_data_rsp.query.bearer_type,
                      SRV_CNMGR_CONNECT_TYPE_LOCAL,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL].last_sent_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL].last_recv_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL].last_connect_duration,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL].total_sent_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL].total_recv_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_LOCAL].total_connect_duration);

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_REPLY_CONNECTION_DATA_DETAIL,
                      connect_data_rsp.query.sim_id,
                      connect_data_rsp.query.bearer_type,
                      SRV_CNMGR_CONNECT_TYPE_DIALUP,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP].last_sent_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP].last_recv_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP].last_connect_duration,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP].total_sent_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP].total_recv_size,
                      (U32)connect_data_rsp.data[SRV_CNMGR_CONNECT_TYPE_DIALUP].total_connect_duration);

            /* Should reset request list because application may get connection data in its callback */
            cb_func = g_cnmgr_srv_cntx.get_connect_data_req_list[i].cb_func;
            user_data = g_cnmgr_srv_cntx.get_connect_data_req_list[i].user_data;
            memset(&g_cnmgr_srv_cntx.get_connect_data_req_list[i], 0, sizeof(srv_cnmgr_get_connect_data_req_struct));
            cb_func(&connect_data_rsp, user_data);
        }
    }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_connect_data_update_notify
 * DESCRIPTION
 *  This API is used to notify application when connection data is updated.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_cnmgr_connect_data_update_notify(void)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_cnmgr_connect_data_notify_struct connect_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&connect_data, 0, sizeof(srv_cnmgr_connect_data_notify_struct));

    for (i = 0; i < SRV_CNMGR_SIM_TOTAL; i++)
    {
#ifdef __TCPIP_OVER_CSD__
        memcpy(&(connect_data.sim_data[i][SRV_CNMGR_SIM_BEARER_TYPE_LOCAL_CSD]),
               &(g_cnmgr_srv_runtime_data_cntx.local_csd_data[i]),
               sizeof(srv_cnmgr_connect_data_detail_struct));
#endif

        memcpy(&(connect_data.sim_data[i][SRV_CNMGR_SIM_BEARER_TYPE_LOCAL_GPRS]),
               &(g_cnmgr_srv_runtime_data_cntx.local_gprs_data[i]),
               sizeof(srv_cnmgr_connect_data_detail_struct));

        memcpy(&(connect_data.sim_data[i][SRV_CNMGR_SIM_BEARER_TYPE_LOCAL_SIM_PS]),
               &(g_cnmgr_srv_runtime_data_cntx.local_total_data[i]),
               sizeof(srv_cnmgr_connect_data_detail_struct));

        memcpy(&(connect_data.sim_data[i][SRV_CNMGR_SIM_BEARER_TYPE_DIALUP]),
               &(g_cnmgr_srv_runtime_data_cntx.dialup_data[i]),
               sizeof(srv_cnmgr_connect_data_detail_struct));
    }

#ifdef __MMI_WLAN_FEATURES__
    memcpy(&(connect_data.wifi_data),
           &(g_cnmgr_srv_runtime_data_cntx.local_wifi_data),
           sizeof(srv_cnmgr_connect_data_detail_struct));
#endif

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
    {
        if (g_cnmgr_srv_cntx.connect_data_notify_list[i].is_used &&
            g_cnmgr_srv_cntx.connect_data_notify_list[i].cb_func != NULL)
        {
            g_cnmgr_srv_cntx.connect_data_notify_list[i].cb_func(&connect_data, g_cnmgr_srv_cntx.connect_data_notify_list[i].user_data);
        }
    }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_reset_local_profile
 * DESCRIPTION
 *  Reset connection data (local type)
 * PARAMETERS
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  data_type       [IN]    Data type
 * RETURNS
 *  void
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_reset_local_profile(cbm_sim_id_enum sim_id,
                                                           srv_cnmgr_bearer_type_enum bearer_type,
                                                           srv_cnmgr_connect_data_enum data_type)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_reset_bearer_info_req_struct *reset_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cnmgr_reset_counter_data(SRV_CNMGR_CONNECT_TYPE_LOCAL, sim_id, bearer_type, data_type))
    {
        /* Have already reset it in NVRAM */
        if (sim_id < SRV_CNMGR_SIM_TOTAL)
        {
#ifdef __TCPIP_OVER_CSD__
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_CSD,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_csd_data.total_connect_duration);
#endif
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_GPRS,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_connect_duration);
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_LOCAL_BEARER_DATA,
                      sim_id,
                      SRV_CNMGR_BEARER_TYPE_SIM_PS,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->local_total_data.total_connect_duration);
        }

#ifdef __MMI_WLAN_FEATURES__
        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_LOCAL_BEARER_DATA,
                  sim_id,
                  SRV_CNMGR_BEARER_TYPE_WIFI,
                  (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_sent_size,
                  (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_recv_size,
                  (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_connect_duration,
                  (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_sent_size,
                  (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_recv_size,
                  (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_connect_duration);
#endif
    }
    
    if (data_type == SRV_CNMGR_CONNECT_DATA_LAST_DATA ||
        data_type == SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE ||
        data_type == SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE)
    {
        if (g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num <= 0)
        {
            return SRV_CNMGR_RESULT_SUCCESS;
        }
    }

    if (data_type == SRV_CNMGR_CONNECT_DATA_LAST_CONNECT_DURATION ||
        data_type == SRV_CNMGR_CONNECT_DATA_TOTAL_CONNECT_DURATION ||
        data_type == SRV_CNMGR_CONNECT_DATA_ALL_CONNECT_DURATION)
    {
        return SRV_CNMGR_RESULT_SUCCESS;
    }

    reset_req = OslAllocDataPtr(mmi_abm_reset_bearer_info_req_struct);

    if (reset_req == NULL)
    {
        MMI_ASSERT(0);
    }

    reset_req->connect_type = ABM_CONNECT_TYPE_LOCAL;;

    switch (data_type)
    {  
        case SRV_CNMGR_CONNECT_DATA_ALL_DATA:
        case SRV_CNMGR_CONNECT_DATA_TOTAL_DATA:
        {
            reset_req->reset_all_tx = KAL_TRUE;
            reset_req->reset_all_rx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_ALL_RECV_SIZE:
        case SRV_CNMGR_CONNECT_DATA_TOTAL_RECV_SIZE:
        {
            reset_req->reset_all_rx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_ALL_SENT_SIZE:
        case SRV_CNMGR_CONNECT_DATA_TOTAL_SENT_SIZE:
        {
            reset_req->reset_all_tx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_LAST_DATA:
        {
            reset_req->local[0].profile_id = CNMGR_LOCAL_PTR(g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num - 1)->profile_id;
            reset_req->local[0].reset_rx = KAL_TRUE;
            reset_req->local[0].reset_tx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE:
        {
            reset_req->local[0].profile_id = CNMGR_LOCAL_PTR(g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num - 1)->profile_id;
            reset_req->local[0].reset_tx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE:
        {
            reset_req->local[0].profile_id = CNMGR_LOCAL_PTR(g_cnmgr_srv_history_data_cntx.tcpip_active_bearer_num - 1)->profile_id;
            reset_req->local[0].reset_rx = KAL_TRUE;
            break;
        }
            
        default:
            break;
    }

    if (data_type == SRV_CNMGR_CONNECT_DATA_LAST_DATA ||
        data_type == SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE ||
        data_type == SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE)
    {
        reset_req->count = 1;
    }
    
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_RESET_BEARER_INFO_REQ, (oslParaType*)reset_req, NULL);

    return SRV_CNMGR_RESULT_WAIT_FOR_RSP;
    
#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

    return SRV_CNMGR_RESULT_TOTAL;

#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_reset_dialup_data
 * DESCRIPTION
 *  Reset connection data (dial-up type)
 * PARAMETERS
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  data_type       [IN]    Data type
 * RETURNS
 *  void
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_reset_dialup_data(cbm_sim_id_enum sim_id,
                                                         srv_cnmgr_bearer_type_enum bearer_type,
                                                         srv_cnmgr_connect_data_enum data_type)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_reset_bearer_info_req_struct *reset_req;
    kal_uint8 i, count = 0;
    kal_uint8 tmp_context_id[MAX_DIALUP_BEARER_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cnmgr_reset_counter_data(SRV_CNMGR_CONNECT_TYPE_DIALUP, sim_id, bearer_type, data_type))
    {
        /* Have already reset it in NVRAM */
        if (sim_id < CBM_SIM_ID_TOTAL)
        {
            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_DIALUP_BEARER_DATA,
                      sim_id,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.last_connect_duration,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_sent_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_recv_size,
                      (U32)CNMGR_TBL_PTR(sim_id)->dialup_data.total_connect_duration);
        }
    }

    if (data_type == SRV_CNMGR_CONNECT_DATA_LAST_CONNECT_DURATION ||
        data_type == SRV_CNMGR_CONNECT_DATA_TOTAL_CONNECT_DURATION ||
        data_type == SRV_CNMGR_CONNECT_DATA_ALL_CONNECT_DURATION)
    {
        return SRV_CNMGR_RESULT_SUCCESS;
    }

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE &&
            g_cnmgr_srv_bearer_list[i].connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            tmp_context_id[count] = g_cnmgr_srv_bearer_list[i].profile_id;
            count++;
        }
    }
    if (count == 0)
    {
        if (g_cnmgr_srv_cntx.reset_data_req.req.connect_type == SRV_CNMGR_CONNECT_TYPE_TOTAL &&
            sim_id < CBM_SIM_ID_TOTAL)
        {
            return srv_cnmgr_reset_local_profile(sim_id, g_cnmgr_srv_cntx.reset_data_req.req.bearer_type, g_cnmgr_srv_cntx.reset_data_req.req.data_type);
        }

        return SRV_CNMGR_RESULT_SUCCESS;
    }

    count = ((count > MAX_DIALUP_BEARER_NUM) ? MAX_DIALUP_BEARER_NUM : count);

    reset_req = OslAllocDataPtr(mmi_abm_reset_bearer_info_req_struct);
    reset_req->connect_type = ABM_CONNECT_TYPE_DIALUP;

    /* Reset last session data */
    if (data_type == SRV_CNMGR_CONNECT_DATA_LAST_DATA ||
        data_type == SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE ||
        data_type == SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE ||
        data_type == SRV_CNMGR_CONNECT_DATA_LAST_CONNECT_DURATION)
    {
        reset_req->count = 1;
        reset_req->dialup[0].dialup_info.context_id = CNMGR_TBL_PTR(sim_id)->last_session_context_id;
        reset_req->dialup[0].dialup_info.call_id = 0;
        reset_req->dialup[0].dialup_info.bearer_type = GPRS_BEARER_DIALUP;
        reset_req->dialup[0].dialup_info.sim_id = (kal_uint8)sim_id;
    }
    else
    {
        reset_req->count = count;

        for (i = 0; i < count; i++)
        {
            reset_req->dialup[i].dialup_info.context_id = tmp_context_id[i] ;
            reset_req->dialup[i].dialup_info.call_id = 0;
            reset_req->dialup[i].dialup_info.bearer_type = GPRS_BEARER_DIALUP;
            reset_req->dialup[i].dialup_info.sim_id = (kal_uint8)sim_id;
        }
    }

    switch (data_type)
    {
        case SRV_CNMGR_CONNECT_DATA_ALL_DATA:
        case SRV_CNMGR_CONNECT_DATA_TOTAL_DATA:
        {
            reset_req->reset_all_tx = KAL_TRUE;
            reset_req->reset_all_rx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_ALL_RECV_SIZE:
        case SRV_CNMGR_CONNECT_DATA_TOTAL_RECV_SIZE:
        {
            reset_req->reset_all_rx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_ALL_SENT_SIZE:
        case SRV_CNMGR_CONNECT_DATA_TOTAL_SENT_SIZE:
        {
            reset_req->reset_all_tx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_LAST_DATA:
        {
            reset_req->dialup[0].reset_rx = KAL_TRUE;
            reset_req->dialup[0].reset_tx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE:
        {
            reset_req->dialup[0].reset_tx = KAL_TRUE;
            break;
        }
            
        case SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE:
        {
            reset_req->dialup[0].reset_rx = KAL_TRUE;
            break;
        }
            
        default:
            break;
    }

    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_RESET_BEARER_INFO_REQ, (oslParaType*)reset_req, NULL);

    return SRV_CNMGR_RESULT_WAIT_FOR_RSP;

#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

    return SRV_CNMGR_RESULT_TOTAL;

#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_reset_counter_data
 * DESCRIPTION
 *  Reset connection data maintained by CNMGR
 * PARAMETERS
 *  connect_type    [IN]    Connection type
 *  sim_id          [IN]    SIM id
 *  bearer_type     [IN]    Bearer type
 *  data_type       [IN]    Data type
 * RETURNS
 *  MMI_TRUE: reset data successfully
 *  MMI_FALSE: reset data unsuccessfully
 *****************************************************************************/
MMI_BOOL srv_cnmgr_reset_counter_data(srv_cnmgr_connect_type_enum connect_type,
                                             cbm_sim_id_enum sim_id,
                                             srv_cnmgr_bearer_type_enum bearer_type,
                                             srv_cnmgr_connect_data_enum data_type)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    U8 i;
    MMI_BOOL update = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (data_type & SRV_CNMGR_CONNECT_DATA_TOTAL_CONNECT_DURATION)
    {
        if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            if (CNMGR_TBL_PTR(sim_id)->dialup_data.total_connect_duration != 0)
            {
                update = MMI_TRUE;
            }
            CNMGR_TBL_PTR(sim_id)->dialup_data.total_connect_duration = 0;
            g_cnmgr_srv_runtime_data_cntx.dialup_data[sim_id].total_connect_duration = 0;
        }
        else
        {
#ifdef __TCPIP_OVER_CSD__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_CSD)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_csd_data.total_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_csd_data.total_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id].total_connect_duration = 0;
            }
#endif /* __TCPIP_OVER_CSD__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_gprs_data[sim_id].total_connect_duration = 0;
            }

#ifdef __MMI_WLAN_FEATURES__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_WIFI)
            {
                if (g_cnmgr_srv_history_data_cntx.local_wifi_data.total_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                g_cnmgr_srv_history_data_cntx.local_wifi_data.total_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_wifi_data.total_connect_duration = 0;
            }
#endif /* __WIFI_SUPPORT__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_SIM_PS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_total_data.total_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_total_data.total_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_total_data[sim_id].total_connect_duration = 0;
            }
        }

        /* Reset all connection time */
        for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
        {
            if (g_cnmgr_srv_bearer_list[i].valid)
            {
                g_cnmgr_srv_bearer_list[i].connect_time = 0;
            }
        }
    }

    if (data_type & SRV_CNMGR_CONNECT_DATA_TOTAL_RECV_SIZE)
    {
        if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            if (CNMGR_TBL_PTR(sim_id)->dialup_data.total_recv_size != 0)
            {
                update = MMI_TRUE;
            }
            CNMGR_TBL_PTR(sim_id)->dialup_data.total_recv_size = 0;
            g_cnmgr_srv_runtime_data_cntx.dialup_data[sim_id].total_recv_size = 0;
        }
        else
        {
#ifdef __TCPIP_OVER_CSD__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_CSD)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_csd_data.total_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_csd_data.total_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id].total_recv_size = 0;
            }
#endif /* __TCPIP_OVER_CSD__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_gprs_data[sim_id].total_recv_size = 0;
            }

#ifdef __MMI_WLAN_FEATURES__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_WIFI)
            {
                if (g_cnmgr_srv_history_data_cntx.local_wifi_data.total_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                g_cnmgr_srv_history_data_cntx.local_wifi_data.total_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_wifi_data.total_recv_size = 0;
            }
#endif /* __WIFI_SUPPORT__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_SIM_PS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_total_data.total_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_total_data.total_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_total_data[sim_id].total_recv_size = 0;
            }
        }
    }

    if (data_type & SRV_CNMGR_CONNECT_DATA_TOTAL_SENT_SIZE)
    {
        if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            if (CNMGR_TBL_PTR(sim_id)->dialup_data.total_sent_size != 0)
            {
                update = MMI_TRUE;
            }
            CNMGR_TBL_PTR(sim_id)->dialup_data.total_sent_size = 0;
            g_cnmgr_srv_runtime_data_cntx.dialup_data[sim_id].total_sent_size = 0;
        }
        else
        {
#ifdef __TCPIP_OVER_CSD__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_CSD)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_csd_data.total_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_csd_data.total_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id].total_sent_size = 0;
            }
#endif /* __TCPIP_OVER_CSD__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_gprs_data.total_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_gprs_data[sim_id].total_sent_size = 0;
            }

#ifdef __MMI_WLAN_FEATURES__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_WIFI)
            {
                if (g_cnmgr_srv_history_data_cntx.local_wifi_data.total_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                g_cnmgr_srv_history_data_cntx.local_wifi_data.total_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_wifi_data.total_sent_size = 0;
            }
#endif /* __WIFI_SUPPORT__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_SIM_PS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_total_data.total_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_total_data.total_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_total_data[sim_id].total_sent_size = 0;
            }
        }
    }

    if (data_type & SRV_CNMGR_CONNECT_DATA_LAST_CONNECT_DURATION)
    {
        if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            if (CNMGR_TBL_PTR(sim_id)->dialup_data.last_connect_duration != 0)
            {
                update = MMI_TRUE;
            }
            CNMGR_TBL_PTR(sim_id)->dialup_data.last_connect_duration = 0;
            g_cnmgr_srv_runtime_data_cntx.dialup_data[sim_id].last_connect_duration = 0;
            index = srv_cnmgr_get_bearer_node_index(CNMGR_TBL_PTR(sim_id)->last_session_context_id,
                                                    SRV_CNMGR_CONNECT_TYPE_DIALUP,
                                                    GPRS_BEARER_DIALUP);
        }
        else
        {
#ifdef __TCPIP_OVER_CSD__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_CSD)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_csd_data.last_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_csd_data.last_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id].last_connect_duration = 0;
                index = srv_cnmgr_get_bearer_node_index(CNMGR_TBL_PTR(sim_id)->csd_last_session_profile_id,
                                                        SRV_CNMGR_CONNECT_TYPE_LOCAL,
                                                        0);
                if (index >= 0)
                {
                    g_cnmgr_srv_bearer_list[index].connect_time = 0;
                }
            }
#endif /* __TCPIP_OVER_CSD__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_gprs_data[sim_id].last_connect_duration = 0;
                index = srv_cnmgr_get_bearer_node_index(CNMGR_TBL_PTR(sim_id)->gprs_last_session_profile_id,
                                                        SRV_CNMGR_CONNECT_TYPE_LOCAL,
                                                        0);
                if (index >= 0)
                {
                    g_cnmgr_srv_bearer_list[index].connect_time = 0;
                }
            }

#ifdef __MMI_WLAN_FEATURES__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_WIFI)
            {
                if (g_cnmgr_srv_history_data_cntx.local_wifi_data.last_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                g_cnmgr_srv_history_data_cntx.local_wifi_data.last_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_wifi_data.last_connect_duration = 0;
                index = srv_cnmgr_get_bearer_node_index(g_cnmgr_srv_history_data_cntx.wifi_last_session_profile_id,
                                                        SRV_CNMGR_CONNECT_TYPE_LOCAL,
                                                        0);
                if (index >= 0)
                {
                    g_cnmgr_srv_bearer_list[index].connect_time = 0;
                }
            }
#endif /* __WIFI_SUPPORT__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_SIM_PS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_total_data.last_connect_duration != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_total_data.last_connect_duration = 0;
                g_cnmgr_srv_runtime_data_cntx.local_total_data[sim_id].last_connect_duration = 0;
            }
        }
    }

    if (data_type & SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE)
    {
        if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            if (CNMGR_TBL_PTR(sim_id)->dialup_data.last_recv_size != 0)
            {
                update = MMI_TRUE;
            }
            CNMGR_TBL_PTR(sim_id)->dialup_data.last_recv_size = 0;
            g_cnmgr_srv_runtime_data_cntx.dialup_data[sim_id].last_recv_size = 0;
        }
        else
        {
#ifdef __TCPIP_OVER_CSD__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_CSD)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_csd_data.last_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_csd_data.last_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id].last_recv_size = 0;
            }
#endif /* __TCPIP_OVER_CSD__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_gprs_data[sim_id].last_recv_size = 0;
            }

#ifdef __MMI_WLAN_FEATURES__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_WIFI)
            {
                if (g_cnmgr_srv_history_data_cntx.local_wifi_data.last_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                g_cnmgr_srv_history_data_cntx.local_wifi_data.last_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_wifi_data.last_recv_size = 0;
            }
#endif /* __WIFI_SUPPORT__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_SIM_PS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_total_data.last_recv_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_total_data.last_recv_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_total_data[sim_id].last_recv_size = 0;
            }
        }
    }
        
    if (data_type & SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE)
    {
        if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
        {
            if (CNMGR_TBL_PTR(sim_id)->dialup_data.last_sent_size != 0)
            {
                update = MMI_TRUE;
            }
            CNMGR_TBL_PTR(sim_id)->dialup_data.last_sent_size = 0;
            g_cnmgr_srv_runtime_data_cntx.dialup_data[sim_id].last_sent_size = 0;
        }
        else
        {
#ifdef __TCPIP_OVER_CSD__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_CSD)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_csd_data.last_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_csd_data.last_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_csd_data[sim_id].last_sent_size = 0;
            }
#endif /* __TCPIP_OVER_CSD__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_gprs_data.last_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_gprs_data[sim_id].last_sent_size = 0;
            }

#ifdef __MMI_WLAN_FEATURES__
            if (bearer_type & SRV_CNMGR_BEARER_TYPE_WIFI)
            {
                if (g_cnmgr_srv_history_data_cntx.local_wifi_data.last_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                g_cnmgr_srv_history_data_cntx.local_wifi_data.last_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_wifi_data.last_sent_size = 0;
            }
#endif /* __WIFI_SUPPORT__ */

            if (bearer_type & SRV_CNMGR_BEARER_TYPE_SIM_PS)
            {
                if (CNMGR_TBL_PTR(sim_id)->local_total_data.last_sent_size != 0)
                {
                    update = MMI_TRUE;
                }
                CNMGR_TBL_PTR(sim_id)->local_total_data.last_sent_size = 0;
                g_cnmgr_srv_runtime_data_cntx.local_total_data[sim_id].last_sent_size = 0;
            }
        }
    }

    if (update == MMI_FALSE)
    {
        return MMI_TRUE;
    }

    if (connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP)
    {
        srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_DIALUP,
                               sim_id,
                               (void*)(&CNMGR_TBL_PTR(sim_id)->dialup_data));
    }
    else
    {
        srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_TOTAL,
                               sim_id,
                               (void*)(&CNMGR_TBL_PTR(sim_id)->local_total_data));

#ifdef __TCPIP_OVER_CSD__
        if (bearer_type & SRV_CNMGR_BEARER_TYPE_CSD)
        {
            srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_CSD,
                                   sim_id,
                                   (void*)(&CNMGR_TBL_PTR(sim_id)->local_csd_data));
        }
#endif /* __TCPIP_OVER_CSD__ */

        if (bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS)
        {
            srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_LOCAL_GPRS,
                                   sim_id,
                                   (void*)(&CNMGR_TBL_PTR(sim_id)->local_gprs_data));
        }

#ifdef __MMI_WLAN_FEATURES__
        if (bearer_type & SRV_CNMGR_BEARER_TYPE_WIFI)
        {
            srv_cnmgr_update_nvram(SRV_CNMGR_NVRAM_DATA_WIFI,
                                   CBM_SIM_ID_TOTAL,
                                   (void*)(&g_cnmgr_srv_history_data_cntx.local_wifi_data));
        }
#endif /* __WIFI_SUPPORT__ */
    }
        
    return MMI_TRUE;

#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

    return MMI_TRUE;

#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_reset_connection_data_cnf_handler
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_ABM_RESET_BEARER_INFO_CNF
 *  Continue reset or notify user application
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_cnmgr_reset_connection_data_cnf_handler(void *msg)
{
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_reset_bearer_info_cnf_struct *cnf;
    srv_cnmgr_reset_data_req_detail_struct reset_data_req;
    U8 sim_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf = (mmi_abm_reset_bearer_info_cnf_struct*)msg;
    
    if (cnf->connect_type == ABM_CONNECT_TYPE_DIALUP)
    {
        if (g_cnmgr_srv_cntx.reset_data_req.req.connect_type == SRV_CNMGR_CONNECT_TYPE_TOTAL)
        {
            sim_id = cnf->dialup[0].dialup_info.sim_id;
            if (sim_id < CBM_SIM_ID_TOTAL)
            {
                srv_cnmgr_reset_local_profile(
                    (cbm_sim_id_enum)sim_id,
                    g_cnmgr_srv_cntx.reset_data_req.req.bearer_type,
                    g_cnmgr_srv_cntx.reset_data_req.req.data_type);
                return MMI_TRUE;
            }
        }
    }

    if (g_cnmgr_srv_cntx.reset_data_req.cb_func != NULL)
    {
        memcpy(&reset_data_req, &(g_cnmgr_srv_cntx.reset_data_req), sizeof(srv_cnmgr_reset_data_req_detail_struct));
        memset(&(g_cnmgr_srv_cntx.reset_data_req), 0, sizeof(srv_cnmgr_reset_data_req_detail_struct));
        reset_data_req.cb_func(&(reset_data_req.req), SRV_CNMGR_RESULT_SUCCESS, reset_data_req.user_data);
    }

    return MMI_TRUE;
    
#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

    return MMI_TRUE;

#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_set_data_update_interval
 * DESCRIPTION
 *  This function is used to decide data update interval.
 * PARAMETERS
 *  reset           [IN]    Reset data update interval to default value or not
 *  interval        [IN]    Data update interval (unit: second)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_set_data_update_interval(MMI_BOOL reset, U32 interval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CBM_CONNECTION_MANAGER__) || defined(__MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__) 
    U32 i; 
#endif 

    U32 old_update_interval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_UPDATE_INTERVAL,
              0,
              reset,
              interval,
              g_cnmgr_srv_cntx.bearer_data_update_interval,
              g_cnmgr_srv_cntx.get_bearer_info_wait_count);

    if (reset)
    {
        old_update_interval = g_cnmgr_srv_cntx.bearer_data_update_interval;
        g_cnmgr_srv_cntx.bearer_data_update_interval = SRV_CNMGR_DATA_UPDATE_INTERVAL_DEFAULT_VALUE / SRV_CNMGR_INTERNAL_TIMER_INTERVAL;

#ifdef __MMI_CBM_CONNECTION_MANAGER__
        for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
        {
            if (g_cnmgr_srv_cntx.bearer_data_notify[i].is_used &&
                g_cnmgr_srv_cntx.bearer_data_notify[i].interval > 0 &&
                g_cnmgr_srv_cntx.bearer_data_notify[i].interval < g_cnmgr_srv_cntx.bearer_data_update_interval)
            {
                g_cnmgr_srv_cntx.bearer_data_update_interval = g_cnmgr_srv_cntx.bearer_data_notify[i].interval;
            }
        }
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */

#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
        for (i = 0; i < SRV_CNMGR_MAX_CONNECT_DATA_REQ; i++)
        {
            if (g_cnmgr_srv_cntx.connect_data_notify_list[i].is_used &&
                g_cnmgr_srv_cntx.connect_data_notify_list[i].interval > 0 &&
                g_cnmgr_srv_cntx.connect_data_notify_list[i].interval < g_cnmgr_srv_cntx.bearer_data_update_interval)
            {
                g_cnmgr_srv_cntx.bearer_data_update_interval = g_cnmgr_srv_cntx.connect_data_notify_list[i].interval;
            }
        }
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
        MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_LCD_STATUS, srv_backlight_is_lcd_sleep());
        if (srv_backlight_is_lcd_sleep() &&
            g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF] < g_cnmgr_srv_cntx.bearer_data_update_interval)
        {
            g_cnmgr_srv_cntx.bearer_data_update_interval = g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF];
        }
        else if (srv_backlight_is_lcd_sleep() == MMI_FALSE &&
                 g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON] < g_cnmgr_srv_cntx.bearer_data_update_interval)
        {
            g_cnmgr_srv_cntx.bearer_data_update_interval = g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON];
        }

        if (g_cnmgr_srv_cntx.bearer_data_update_interval > SRV_CNMGR_MAX_BEARER_STATUS_CHECK_TIME)
        {
            g_cnmgr_srv_cntx.bearer_data_update_interval = SRV_CNMGR_MAX_BEARER_STATUS_CHECK_TIME;
        }
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

        if (g_cnmgr_srv_cntx.bearer_data_update_interval < old_update_interval)
        {
            g_cnmgr_srv_cntx.get_bearer_info_wait_count = 0;
        }
    }
    else
    {
        if (interval < g_cnmgr_srv_cntx.bearer_data_update_interval)
        {
            g_cnmgr_srv_cntx.bearer_data_update_interval = interval;
            g_cnmgr_srv_cntx.get_bearer_info_wait_count = 0;
        }
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_UPDATE_INTERVAL,
              1,
              reset,
              interval,
              g_cnmgr_srv_cntx.bearer_data_update_interval,
              g_cnmgr_srv_cntx.get_bearer_info_wait_count);
}


#ifdef __MMI_CBM_CONNECTION_MANAGER__
/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_first_active_bearer_node
 * DESCRIPTION
 *  Get the first valid bearer node from beare list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_cnmgr_bearer_context_struct *srv_cnmgr_get_first_active_bearer_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE &&
            g_cnmgr_srv_bearer_list[i].not_display == MMI_FALSE)
        {
            return &g_cnmgr_srv_bearer_list[i];
        }
    }
    
    return NULL; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_move_bearer_node_to_bearer_list
 * DESCRIPTION
 *  Copy bearer node from backup list to bearer list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_move_bearer_node_to_bearer_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, count, count_backup;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    count_backup = 0;

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid)
        {
            count++;
        }
    }

    for (i = 0; i < SRV_CNMGR_MAX_BACKUP_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_backup_bearer_list[i].valid)
        {
            count_backup++;
        }
    }

    if ((SRV_CNMGR_MAX_BEARER_NUM - count) >= count_backup)
    {
        for (i = 0; i < count_backup; i++)
        {
            srv_cnmgr_add_node_to_bearer_list(&g_cnmgr_srv_backup_bearer_list[i], MMI_FALSE);
#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
            if (g_cnmgr_srv_backup_bearer_list[i].not_display == MMI_FALSE)
            {
                srv_cnmgr_add_node_to_merged_bearer_list(&g_cnmgr_srv_backup_bearer_list[i]);
            }
#endif
            memset(&g_cnmgr_srv_backup_bearer_list[i], 0, sizeof(srv_cnmgr_bearer_context_struct));
        }
    }
    else
    {
        for (i = 0; i < (SRV_CNMGR_MAX_BEARER_NUM - count); i++)
        {
            srv_cnmgr_add_node_to_bearer_list(&g_cnmgr_srv_backup_bearer_list[i], MMI_FALSE);
#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__USB_TETHERING__)
            if (g_cnmgr_srv_backup_bearer_list[i].not_display == MMI_FALSE)
            {
                srv_cnmgr_add_node_to_merged_bearer_list(&g_cnmgr_srv_backup_bearer_list[i]);
            }
#endif
            memset(&g_cnmgr_srv_backup_bearer_list[i], 0, sizeof(srv_cnmgr_bearer_context_struct));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_bearer_data_update_notify
 * DESCRIPTION
 *  This API is used to notify application when bearer data is updated.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_cnmgr_bearer_data_update_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
    {
        if (g_cnmgr_srv_cntx.bearer_data_notify[i].is_used &&
            g_cnmgr_srv_cntx.bearer_data_notify[i].cb_func != NULL)
        {
            g_cnmgr_srv_cntx.bearer_data_notify[i].cb_func(g_cnmgr_srv_cntx.bearer_data_notify[i].user_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_bearer_req_handler
 * DESCRIPTION
 *  Disconnect connection by sending request to ABM
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  sim_id          [IN]    SIM id
 *  connect_type    [IN]    Connection type
 *  dialup_type     [IN]    Dial-up type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_disconnect_bearer_req_handler(U32 profile_id, U8 sim_id, srv_cnmgr_connect_type_enum connect_type, U8 dialup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_disconnect_req_struct *disc_req;
    U32 acct_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_cnmgr_disconnect_bearer_cnf_handler, MSG_ID_MMI_ABM_DISCONNECT_CNF);

    disc_req = OslAllocDataPtr(mmi_abm_disconnect_req_struct);

    acct_id = cbm_encode_data_account_id(profile_id, (cbm_sim_id_enum)sim_id, 0, KAL_FALSE);
    if (connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL)
    {
        disc_req->profile_id = acct_id;
        disc_req->connect_type = srv_cnmgr_convert_cnmgr_connect_type_to_abm(connect_type);
    }
    else
    {
        disc_req->connect_type = ABM_CONNECT_TYPE_DIALUP;    
        disc_req->dialup_info.bearer_type = dialup_type;
        disc_req->dialup_info.sim_id = sim_id;
        if (disc_req->dialup_info.bearer_type == CSD_BEARER_DIALUP)
        {
            disc_req->dialup_info.call_id = profile_id;
        }
        else
        {
            disc_req->dialup_info.context_id = profile_id;
        }
    }
    
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_DISCONNECT_REQ, (oslParaType*)disc_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_bearer_cnf_handler
 * DESCRIPTION
 *  Handler function for MSG_ID_MMI_ABM_DISCONNECT_CNF
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_disconnect_bearer_cnf_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_disconnect_cnf_struct *cnf;
    srv_cnmgr_bearer_context_struct *first_node;
	U32 profile_id = 0xFFFFFFFF;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    cnf = (mmi_abm_disconnect_cnf_struct*)msg;

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_DISCONNECT_CNF);

    if (cnf->connect_type == ABM_CONNECT_TYPE_DIALUP)
    {
        if(cnf->dialup_info.bearer_type == GPRS_BEARER_DIALUP)
        {
            profile_id = cnf->dialup_info.context_id;
        }
        else if (cnf->dialup_info.bearer_type == CSD_BEARER_DIALUP)
        {
            profile_id = cnf->dialup_info.call_id;
        }
    }
    else 
    {
        profile_id = cbm_get_original_account(cnf->profile_id);
    }

    if (cnf->result == KAL_TRUE)
    {
        srv_cnmgr_disconnect_bearer_done(profile_id,
                                         srv_cnmgr_convert_abm_connect_type_to_cnmgr(cnf->connect_type),
                                         SRV_CNMGR_RESULT_SUCCESS);

        if (g_cnmgr_srv_cntx.disc_all_flag)
        {
            first_node = srv_cnmgr_get_first_active_bearer_node();
            if (first_node == NULL)
            {
                g_cnmgr_srv_cntx.disc_all_flag = MMI_FALSE;
                srv_cnmgr_disconnect_all_bearer_done(SRV_CNMGR_RESULT_SUCCESS);
                return;
            }
            first_node->disconnecting = MMI_TRUE;
            srv_cnmgr_disconnect_bearer_req_handler(first_node->profile_id, first_node->sim_id, first_node->connect_type, first_node->dialup_type);
        }
    }
    else
    {
        srv_cnmgr_disconnect_bearer_done(profile_id,
                                         srv_cnmgr_convert_abm_connect_type_to_cnmgr(cnf->connect_type),
                                         SRV_CNMGR_RESULT_FAILED);

        if (g_cnmgr_srv_cntx.disc_all_flag)
        {
            srv_cnmgr_disconnect_all_bearer_done(SRV_CNMGR_RESULT_FAILED);
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_all_bearer_done
 * DESCRIPTION
 *  This API is used to notify application after CNMGR disconnect all bearer.
 * PARAMETERS
 *  result :        [IN]    Execution result
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_cnmgr_disconnect_all_bearer_done(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_DISCONNECT_ALL_BEARER_DONE);

    if (g_cnmgr_srv_cntx.disc_all_req.cb_func != NULL)
    {
        g_cnmgr_srv_cntx.disc_all_req.cb_func(result, g_cnmgr_srv_cntx.disc_all_req.user_data);
        memset(&g_cnmgr_srv_cntx.disc_all_req, 0, sizeof(srv_cnmgr_disc_all_req_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_bearer_done
 * DESCRIPTION
 *  This API is used to notify application after CNMGR disconnect one bearer.
 * PARAMETERS
 *  profile_id :    [IN]    Profile id
 *  connect_type :  [IN]    Connection type
 *  result :        [IN]    Execution result
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_cnmgr_disconnect_bearer_done(U32 profile_id, U8 connect_type, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __USB_TETHERING__
    U8 i, encode_acct;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cnmgr_srv_cntx.disc_req.profile_id == profile_id &&
        g_cnmgr_srv_cntx.disc_req.connect_type == connect_type)
    {
#ifdef __USB_TETHERING__
        for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
        {
            if (g_cnmgr_srv_bearer_list[i].valid &&
                g_cnmgr_srv_bearer_list[i].not_display == MMI_FALSE &&
                g_cnmgr_srv_bearer_list[i].disconnecting == MMI_FALSE)
            {
                encode_acct = cbm_get_original_account(g_cnmgr_srv_bearer_list[i].profile_id);

                if (encode_acct == CBM_USB_TR_PS_ACCT_ID)
                {
                    encode_acct = g_cnmgr_srv_cntx.user_tethering_acct;
                }

                if (encode_acct == g_cnmgr_srv_cntx.disc_req.real_acct &&
                    g_cnmgr_srv_bearer_list[i].connect_type == g_cnmgr_srv_cntx.disc_req.connect_type &&
                    g_cnmgr_srv_bearer_list[i].bearer_status != SRV_CNMGR_BEARER_STATUS_DEACTIVE)
                {
                    if (g_cnmgr_srv_bearer_list[i].disconnecting == MMI_FALSE)
                    {
                        g_cnmgr_srv_bearer_list[i].disconnecting = MMI_TRUE;
                        srv_cnmgr_disconnect_bearer_req_handler(g_cnmgr_srv_bearer_list[i].profile_id,
                                                                g_cnmgr_srv_bearer_list[i].sim_id,
                                                                g_cnmgr_srv_bearer_list[i].connect_type,
                                                                g_cnmgr_srv_bearer_list[i].dialup_type);
                    }

                    g_cnmgr_srv_cntx.disc_req.profile_id = g_cnmgr_srv_bearer_list[i].profile_id;
                    return;
                }
            }
        }
#endif /* __USB_TETHERING__ */

        if (g_cnmgr_srv_cntx.disc_req.cb_func != NULL)
        {
            g_cnmgr_srv_cntx.disc_req.cb_func(result, g_cnmgr_srv_cntx.disc_req.user_data);
            memset(&(g_cnmgr_srv_cntx.disc_req), 0, sizeof(srv_cnmgr_disc_req_struct));
        }
    }
}


#ifdef __USB_TETHERING__
/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_add_node_to_merged_bearer_list
 * DESCRIPTION
 *  Add bearer node to g_cnmgr_srv_merged_bearer_list if CNMGR is not disconnecting all connections now
 * PARAMETERS
 *  node            [IN]    Bearer node
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_add_node_to_merged_bearer_list(srv_cnmgr_bearer_context_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, ori_acct_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ori_acct_id = cbm_get_original_account(node->profile_id);

    if (ori_acct_id == CBM_USB_TR_PS_ACCT_ID)
    {
        ori_acct_id = g_cnmgr_srv_cntx.user_tethering_acct;
    }
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_ADD_NODE_TO_MERGED_BEARER_LIST, node->profile_id, ori_acct_id);

    /* Check whether bearer list already has this bearer node */
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_merged_bearer_list[i].count > 0 &&
            g_cnmgr_srv_merged_bearer_list[i].profile_id == ori_acct_id &&
            g_cnmgr_srv_merged_bearer_list[i].connect_type == node->connect_type &&
            g_cnmgr_srv_merged_bearer_list[i].dialup_type == node->dialup_type)
        {
            for (j = 0; j < SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM; j++)
            {
                if (g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid &&
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].profile_id == cbm_get_original_account(node->profile_id))
                {
                    /* Already exist in merged bearer list -> update info */
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].bearer_status = node->bearer_status;
                    break;
                }
            }

            if (j == SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM)
            {
                for (j = 0; j < SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM; j++)
                {
                    if (g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid == MMI_FALSE)
                    {
                        g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].profile_id = cbm_get_original_account(node->profile_id);
                        g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].bearer_status = node->bearer_status;
                        g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid = MMI_TRUE;
                        g_cnmgr_srv_merged_bearer_list[i].count++;
                    }
                }
            }

            MMI_ASSERT(g_cnmgr_srv_merged_bearer_list[i].count <= SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM);

            /* Decide bearer status */
            srv_cnmgr_decide_merged_bearer_status(i);

            return;
        }
    }

    /* Add node to bearer list */
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_merged_bearer_list[i].count == 0)
        {
            g_cnmgr_srv_merged_bearer_list[i].profile_id = ori_acct_id;
            g_cnmgr_srv_merged_bearer_list[i].sim_id = node->sim_id;
            g_cnmgr_srv_merged_bearer_list[i].dialup_type = node->dialup_type;
            g_cnmgr_srv_merged_bearer_list[i].connect_type = node->connect_type;
            g_cnmgr_srv_merged_bearer_list[i].bearer_status = node->bearer_status;
            g_cnmgr_srv_merged_bearer_list[i].bearer_type = node->bearer_type;
            g_cnmgr_srv_merged_bearer_list[i].real_bearer[0].profile_id = cbm_get_original_account(node->profile_id);
            g_cnmgr_srv_merged_bearer_list[i].real_bearer[0].bearer_status = node->bearer_status;
            g_cnmgr_srv_merged_bearer_list[i].real_bearer[0].valid = MMI_TRUE;
            g_cnmgr_srv_merged_bearer_list[i].count++;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_remove_node_from_merged_bearer_list
 * DESCRIPTION
 *  Remove bearer node from g_cnmgr_srv_merged_bearer_list
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  connect_type    [IN]    Connection type
 *  dialup_type     [IN]    Dial-up type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_remove_node_from_merged_bearer_list(U32 profile_id,
                                                          srv_cnmgr_connect_type_enum connect_type,
                                                          U8 dialup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, k, ori_acct_id;
    U64 up_speed = 0, down_speed = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ori_acct_id = cbm_get_original_account(profile_id);
    if (ori_acct_id == CBM_USB_TR_PS_ACCT_ID)
    {
        ori_acct_id = g_cnmgr_srv_cntx.user_tethering_acct;
    }
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_REMOVE_NODE_FROM_MERGED_BEARER_LIST, profile_id, connect_type, dialup_type, ori_acct_id);

    /* Check whether bearer list already has this bearer node */
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_merged_bearer_list[i].count > 0 &&
            g_cnmgr_srv_merged_bearer_list[i].profile_id == ori_acct_id &&
            g_cnmgr_srv_merged_bearer_list[i].connect_type == connect_type &&
            g_cnmgr_srv_merged_bearer_list[i].dialup_type == dialup_type)
        {
            for (j = 0; j < SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM; j++)
            {
                if (g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid &&
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].profile_id == cbm_get_original_account(profile_id))
                {
                    /* Already exist in merged bearer list -> update info */
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].profile_id = 0;
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid = MMI_FALSE;
                    g_cnmgr_srv_merged_bearer_list[i].count--;
                    break;
                }
            }

            if (g_cnmgr_srv_merged_bearer_list[i].count == 0)
            {
                memset(&g_cnmgr_srv_merged_bearer_list[i], 0, sizeof(srv_cnmgr_merged_bearer_data_struct));

                if (i < SRV_CNMGR_MAX_BEARER_NUM)
                {
                    for (j = i; j < SRV_CNMGR_MAX_BEARER_NUM - 1; j++)
                    {
                        memcpy(&g_cnmgr_srv_merged_bearer_list[j], &g_cnmgr_srv_merged_bearer_list[j + 1], sizeof(srv_cnmgr_merged_bearer_data_struct));
                        memset(&g_cnmgr_srv_merged_bearer_list[j + 1], 0, sizeof(srv_cnmgr_merged_bearer_data_struct));

                        if (g_cnmgr_srv_merged_bearer_list[j].count == 0)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                /* Decide bearer status */
                srv_cnmgr_decide_merged_bearer_status(i);

                /* Update download/upload speed */
                for (j = 0; j < SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM; j++)
                {
                    for (k = 0; k < SRV_CNMGR_MAX_BEARER_NUM; k++)
                    {
                        if (g_cnmgr_srv_bearer_list[k].valid &&
                            g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid &&
                            g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].profile_id == cbm_get_original_account(g_cnmgr_srv_bearer_list[k].profile_id) &&
                            g_cnmgr_srv_merged_bearer_list[i].connect_type == g_cnmgr_srv_bearer_list[k].connect_type &&
                            g_cnmgr_srv_merged_bearer_list[i].dialup_type == g_cnmgr_srv_bearer_list[k].dialup_type &&
                            g_cnmgr_srv_merged_bearer_list[i].sim_id == g_cnmgr_srv_bearer_list[k].sim_id)
                        {
                            up_speed += g_cnmgr_srv_bearer_list[k].detail.up_speed;
                            down_speed += g_cnmgr_srv_bearer_list[k].detail.down_speed;
                            break;
                        }
                    }
                }

                g_cnmgr_srv_merged_bearer_list[i].up_speed = up_speed;
                g_cnmgr_srv_merged_bearer_list[i].down_speed = down_speed;
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_update_merged_bearer_status
 * DESCRIPTION
 *  Update bearer status
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  connect_type    [IN]    Connection type
 *  dialup_type     [IN]    Dial-up type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_update_merged_bearer_status(U32 profile_id, 
                                                  srv_cnmgr_connect_type_enum connect_type, 
                                                  U8 dialup_type,
                                                  srv_cnmgr_bearer_status_enum bearer_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, ori_acct_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ori_acct_id = cbm_get_original_account(profile_id);

    if (ori_acct_id == CBM_USB_TR_PS_ACCT_ID)
    {
        ori_acct_id = g_cnmgr_srv_cntx.user_tethering_acct;
    }

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_merged_bearer_list[i].count > 0 &&
            g_cnmgr_srv_merged_bearer_list[i].profile_id == ori_acct_id &&
            g_cnmgr_srv_merged_bearer_list[i].connect_type == connect_type &&
            g_cnmgr_srv_merged_bearer_list[i].dialup_type == dialup_type)
        {
            for (j = 0; j < SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM; j++)
            {
                if (g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid &&
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].profile_id == cbm_get_original_account(profile_id))
                {
                    /* Already exist in merged bearer list -> update info */
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].bearer_status = bearer_status;

                    /* Decide bearer status */
                    srv_cnmgr_decide_merged_bearer_status(i);

                    if (bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVATING &&
                        g_cnmgr_srv_merged_bearer_list[i].count == 1)
                    {
                        /* Update download/upload speed */
                        g_cnmgr_srv_merged_bearer_list[i].up_speed = 0;
                        g_cnmgr_srv_merged_bearer_list[i].down_speed = 0;
                    }
                    return;
                }
            }
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_decide_merged_bearer_status
 * DESCRIPTION
 *  Decide bearer status
 * PARAMETERS
 *  idx             [IN]    The index of the bearer node
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_decide_merged_bearer_status(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    srv_cnmgr_bearer_status_enum bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM; i++)
    {
        if (g_cnmgr_srv_merged_bearer_list[idx].real_bearer[i].valid)
        {
            if (g_cnmgr_srv_merged_bearer_list[idx].real_bearer[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE ||
                bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
            {
                bearer_status = SRV_CNMGR_BEARER_STATUS_ACTIVE;
            }
            else if (g_cnmgr_srv_merged_bearer_list[idx].real_bearer[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVATING ||
                     bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVATING)
            {
                bearer_status = SRV_CNMGR_BEARER_STATUS_ACTIVATING;
            }
            else if (g_cnmgr_srv_merged_bearer_list[idx].real_bearer[i].bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVATING ||
                     bearer_status == SRV_CNMGR_BEARER_STATUS_DEACTIVATING)
            {
                bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVATING;
            }
        }
    }
    g_cnmgr_srv_merged_bearer_list[idx].bearer_status = bearer_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_update_merged_bearer_data
 * DESCRIPTION
 *  Update bearer data
 * PARAMETERS
 *  profile_id      [IN]    Profile id
 *  connect_type    [IN]    Connection type
 *  dialup_type     [IN]    Dial-up type
 *  old_data        [IN]    Old bearer detail data
 *  new_data        [IN]    New bearer detail data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_update_merged_bearer_data(U32 profile_id, 
                                                srv_cnmgr_connect_type_enum connect_type, 
                                                U8 dialup_type,
                                                srv_cnmgr_bearer_detail_struct *old_data,
                                                srv_cnmgr_bearer_detail_struct *new_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, ori_acct_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ori_acct_id = cbm_get_original_account(profile_id);

    if (ori_acct_id == CBM_USB_TR_PS_ACCT_ID)
    {
        ori_acct_id = g_cnmgr_srv_cntx.user_tethering_acct;
    }

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_merged_bearer_list[i].count > 0 &&
            g_cnmgr_srv_merged_bearer_list[i].profile_id == ori_acct_id &&
            g_cnmgr_srv_merged_bearer_list[i].connect_type == connect_type &&
            g_cnmgr_srv_merged_bearer_list[i].dialup_type == dialup_type)
        {
            for (j = 0; j < SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM; j++)
            {
                if (g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].valid &&
                    g_cnmgr_srv_merged_bearer_list[i].real_bearer[j].profile_id == cbm_get_original_account(profile_id))
                {
                    /* Already exist in merged bearer list -> update info */
                    g_cnmgr_srv_merged_bearer_list[i].send_data_size = g_cnmgr_srv_merged_bearer_list[i].send_data_size - old_data->send_data_size + new_data->send_data_size;
                    g_cnmgr_srv_merged_bearer_list[i].recv_data_size = g_cnmgr_srv_merged_bearer_list[i].recv_data_size - old_data->recv_data_size + new_data->recv_data_size;
                    g_cnmgr_srv_merged_bearer_list[i].all_data_size = g_cnmgr_srv_merged_bearer_list[i].all_data_size - old_data->all_data_size + new_data->all_data_size;
                    g_cnmgr_srv_merged_bearer_list[i].down_speed = g_cnmgr_srv_merged_bearer_list[i].down_speed - old_data->down_speed + new_data->down_speed;
                    g_cnmgr_srv_merged_bearer_list[i].up_speed = g_cnmgr_srv_merged_bearer_list[i].up_speed - old_data->up_speed + new_data->up_speed;
                    return;
                }
            }
            return;
        }
    }
}
#endif /* __USB_TETHERING__ */
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */


#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_set_scri_check_interval
 * DESCRIPTION
 *  This function is used to decide SCRI check interval.
 * PARAMETERS
 *  type :          [IN]    SCRI check timer type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_set_scri_check_interval(srv_cnmgr_scri_check_timer_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 min_value = 0xFFFFFFFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_SCRI_INTERVAL,
              0,
              type,
              g_cnmgr_srv_cntx.scri_check_interval[type]);

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_SCRI_REQ; i++)
    {
        if (g_cnmgr_srv_cntx.scri_req_list[type][i].id > 0 &&
            g_cnmgr_srv_cntx.scri_req_list[type][i].interval < min_value)
        {
            min_value = g_cnmgr_srv_cntx.scri_req_list[type][i].interval;
        }
    }

    if (min_value != 0xFFFFFFFF)
    {
        g_cnmgr_srv_cntx.scri_check_interval[type] = min_value;
    }
    else
    {
        if (type == SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON)
        {
            g_cnmgr_srv_cntx.scri_check_interval[type] = CNMGR_CUSTOM_CFG_DEFAULT_SCRI_LCD_ON_CHECK_TIME;
        }
        else if (type == SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF)
        {
            g_cnmgr_srv_cntx.scri_check_interval[type] = CNMGR_CUSTOM_CFG_DEFAULT_SCRI_LCD_OFF_CHECK_TIME;
        }
    }

    srv_cnmgr_set_data_update_interval(MMI_TRUE, 0);

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_SCRI_INTERVAL,
              1,
              type,
              g_cnmgr_srv_cntx.scri_check_interval[type]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_can_send_end_ps_data_session_req
 * DESCRIPTION
 *  Check whether can send MSG_ID_MMI_NW_END_PS_DATA_SESSION_REQ
 * PARAMETERS
 *  force_send_scri [OUT]   Force send or not
 *  call_prefer     [IN]
 * RETURNS
 *  MMI_TRUE: can send request
 *  MMI_FALSE: can not send request
 *****************************************************************************/
MMI_BOOL srv_cnmgr_can_send_end_ps_data_session_req(MMI_BOOL *force_send_scri, MMI_BOOL call_prefer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 valid_sim_num = 0;
    MMI_BOOL lcd_off = srv_backlight_is_lcd_sleep();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Calculate valid SIM number */
    if (srv_nw_usab_is_usable(MMI_SIM1))
    {
        valid_sim_num++;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_usab_is_usable(MMI_SIM2))
    {
        valid_sim_num++;
    }
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    if (srv_nw_usab_is_usable(MMI_SIM3))
    {
        valid_sim_num++;
    }
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    if (srv_nw_usab_is_usable(MMI_SIM4))
    {
        valid_sim_num++;
    }
#endif

    /*
     * T-Mobile requirement MTR-6513:
     * Fast Dormancy is not activated if the device is operated in tethered mode
     * (i.e. Mobile Device is connected to a laptop)
     */
    if (srv_tethering_is_off(SRV_TETHERING_TYPE_USB) == MMI_FALSE &&
        valid_sim_num <= 1)
    {
        *force_send_scri = MMI_FALSE;
        return MMI_FALSE;
    }

    /* Following is T-Mobile requirement MTR-27882, MTR-27883, MTR-27884, MTR-27885, MTR-27886 */
#ifdef __NO_PSDATA_SEND_SCRI__
    if (lcd_off == MMI_FALSE && valid_sim_num <= 1)
    {
        /* Not send request if display ON and only SIM1 is inserted */
        *force_send_scri = MMI_FALSE;
        return MMI_FALSE;
    }
#endif

    *force_send_scri = MMI_TRUE;

    /* Fill force_send_SCRI */
    if (lcd_off == MMI_FALSE &&
        ((valid_sim_num >= 2 && call_prefer == MMI_TRUE) || valid_sim_num <= 1))
    {
        *force_send_scri = MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_end_ps_data_session_req_handler
 * DESCRIPTION
 *  Send MSG_ID_MMI_NW_END_PS_DATA_SESSION_REQ
 * PARAMETERS
 *  force_send_scri [IN]   Force send or not
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cnmgr_end_ps_data_session_req_handler(MMI_BOOL force_send_scri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_end_ps_data_session_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = OslAllocDataPtr(mmi_nw_end_ps_data_session_req_struct);
    if (req != NULL)
    {
        /* Fill force_send_SCRI */
        req->force_send_SCRI = (force_send_scri ? KAL_TRUE : KAL_FALSE);
        mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_NW_END_PS_DATA_SESSION_REQ, (oslParaType*)req, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_end_ps_data_session_rsp_handler
 * DESCRIPTION
 *  Handler of MSG_ID_MMI_NW_END_PS_DATA_SESSION_RSP
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  MMI_TRUE: event is handled
 *  MMI_FALSE: event is not handled
 *****************************************************************************/
U8 srv_cnmgr_end_ps_data_session_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_end_ps_data_session_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_ENDING_PS_DATA_SESSION)
    {
        rsp = (mmi_nw_end_ps_data_session_rsp_struct*)msg;

        if (rsp->result != SCRI_REQ_SENT &&
            rsp->result != SCRI_NO_PS_DATA_SESSION &&
            g_cnmgr_srv_cntx.scri_retry_num < CNMGR_CUSTOM_CFG_DEFAULT_SCRI_RETRY_NUM)
        {
            g_cnmgr_srv_cntx.scri_retry_num++;
            SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_MONITORING);
        }
        else
        {
            g_cnmgr_srv_cntx.scri_retry_num = 0;
            SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_WAITING);
        }
    }

    return MMI_TRUE;
}


#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_pch_status_callback
 * DESCRIPTION
 *  Get PCH setting - data prefer or call prefer
 * PARAMETERS
 *  ptr_rsp         [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_cnmgr_get_pch_status_callback(mmi_event_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_gprs_transfer_preference_rsp_struct *rsp_msg = NULL;
    MMI_BOOL call_prefer, force_send_scri;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cnmgr_srv_cntx.scri_state == SRV_CNMGR_SCRI_STATE_GETTING_PCH_STATUS)
    {
        if (((srv_netset_rsp_event_struct*)rsp)->result == SRV_NETSET_RSP_RESULT_SUCCESS)
        {
            rsp_msg = ((srv_netset_rsp_event_struct*)rsp)->rsp_data.get_pch_mode_rsp_data;
            
            if (rsp_msg->result && rsp_msg->prefer)
            {
                call_prefer = MMI_TRUE;
            }
            else
            {
                call_prefer = MMI_FALSE;
            }

            if (srv_cnmgr_can_send_end_ps_data_session_req(&force_send_scri, call_prefer))
            {
                SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_ENDING_PS_DATA_SESSION);
                srv_cnmgr_end_ps_data_session_req_handler(force_send_scri);
            }
            else
            {
                SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_MONITORING);
            }
        }
        else
        {
            SRV_CNMGR_ENTER_STATE(g_cnmgr_srv_cntx.scri_state, SRV_CNMGR_SCRI_STATE_MONITORING);
        }
    }

    return MMI_RET_OK;
}
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
#endif /* __MMI_ENABLE_CNMGR_SRV__ */

/************************************************************
 * Global Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_init
 * DESCRIPTION
 *  This API is used to initialize connection management service.
 * PARAMETERS
 *  evt	:	        [IN]	Init event notification
 * RETURN VALUES
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_cnmgr_init(mmi_event_struct *evt)
{
#ifdef __MMI_ENABLE_CNMGR_SRV__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    S16 error;
    S32 i;
#endif 
    
#ifdef __MMI_3G_SWITCH__    
    mmi_sim_enum cur_3g_sim;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_INIT);

    /* Register message handlers */
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_ABM_BEARER_INFO_IND, srv_cnmgr_bearer_info_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_NVRAM_WRITE_CNF, srv_cnmgr_nvram_async_event_handler, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_ABM_GET_BEARER_INFO_CNF, srv_cnmgr_get_bearer_info_cnf_handler, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_ABM_RESET_BEARER_INFO_CNF, srv_cnmgr_reset_connection_data_cnf_handler, MMI_FALSE);

    /* Initialize context */
    memset(&g_cnmgr_srv_cntx, 0, sizeof(srv_cnmgr_context_struct));
    g_cnmgr_srv_cntx.bearer_data_update_interval = SRV_CNMGR_DATA_UPDATE_INTERVAL_DEFAULT_VALUE / SRV_CNMGR_INTERNAL_TIMER_INTERVAL;

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON] = CNMGR_CUSTOM_CFG_DEFAULT_SCRI_LCD_ON_CHECK_TIME;
    g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF] = CNMGR_CUSTOM_CFG_DEFAULT_SCRI_LCD_OFF_CHECK_TIME;
    g_cnmgr_srv_cntx.scri_state = SRV_CNMGR_SCRI_STATE_IDLE;

    if (g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON] < g_cnmgr_srv_cntx.bearer_data_update_interval)
    {
        g_cnmgr_srv_cntx.bearer_data_update_interval = g_cnmgr_srv_cntx.scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON];
    }

    if (g_cnmgr_srv_cntx.bearer_data_update_interval > SRV_CNMGR_MAX_BEARER_STATUS_CHECK_TIME)
    {
        g_cnmgr_srv_cntx.bearer_data_update_interval = SRV_CNMGR_MAX_BEARER_STATUS_CHECK_TIME;
    }

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_END_PS_DATA_SESSION_RSP, srv_cnmgr_end_ps_data_session_rsp_handler, MMI_FALSE);
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

#ifdef __MMI_3G_SWITCH__
    cur_3g_sim = srv_netset_get_3g_capability_sim();
    g_cnmgr_srv_cntx.cur_3g_sim = srv_cnmgr_convert_mmi_sim_id_to_cbm(cur_3g_sim);
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_3G_CAPABILITY_SIM, g_cnmgr_srv_cntx.cur_3g_sim);
#endif

    /* Reset global data */    
    memset(g_cnmgr_srv_bearer_list, 0, sizeof(srv_cnmgr_bearer_context_struct) * SRV_CNMGR_MAX_BEARER_NUM);
#ifdef __MMI_CBM_CONNECTION_MANAGER__
    memset(g_cnmgr_srv_backup_bearer_list, 0, sizeof(srv_cnmgr_bearer_context_struct) * SRV_CNMGR_MAX_BACKUP_BEARER_NUM);
#ifdef __USB_TETHERING__
    memset(g_cnmgr_srv_merged_bearer_list, 0, sizeof(srv_cnmgr_merged_bearer_data_struct) * SRV_CNMGR_MAX_BEARER_NUM);
#endif
#endif

#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    memset(&g_cnmgr_srv_history_data_cntx, 0, sizeof(srv_cnmgr_history_connect_data_context_struct));
    memset(&g_cnmgr_srv_runtime_data_cntx, 0, sizeof(srv_cnmgr_runtime_connect_data_context_struct));

    /* Read data from NVRAM */
    for (i = 0; i < SRV_CNMGR_SIM_TOTAL; i++)
    {
        /* CSD session data */
#ifdef __TCPIP_OVER_CSD__
        ReadRecord(NVRAM_EF_CNMGR_CONNECT_DATA_LID,
                   1 + (i * 4),
                   (void*)(&CNMGR_TBL_PTR(i)->local_csd_data),
                   NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE,
                   &error);
        memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_csd_data[i]),
               &CNMGR_TBL_PTR(i)->local_csd_data,
               sizeof(srv_cnmgr_connect_data_detail_struct));
        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_SESSION_DATA,
                  SRV_CNMGR_CONNECT_TYPE_LOCAL,
                  SRV_CNMGR_BEARER_TYPE_CSD,
                  i,
                  (U32)CNMGR_TBL_PTR(i)->local_csd_data.last_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->local_csd_data.last_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->local_csd_data.last_connect_duration,
                  (U32)CNMGR_TBL_PTR(i)->local_csd_data.total_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->local_csd_data.total_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->local_csd_data.total_connect_duration);
#endif /* __TCPIP_OVER_CSD__ */

        /* GPRS session data */
        ReadRecord(NVRAM_EF_CNMGR_CONNECT_DATA_LID,
                   2 + ( i * 4),
                   (void*)(&CNMGR_TBL_PTR(i)->local_gprs_data),
                   NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE,
                   &error);
        memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_gprs_data[i]),
               &CNMGR_TBL_PTR(i)->local_gprs_data,
               sizeof(srv_cnmgr_connect_data_detail_struct));
        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_SESSION_DATA,
                  SRV_CNMGR_CONNECT_TYPE_LOCAL,
                  SRV_CNMGR_BEARER_TYPE_GPRS,
                  i,
                  (U32)CNMGR_TBL_PTR(i)->local_gprs_data.last_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->local_gprs_data.last_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->local_gprs_data.last_connect_duration,
                  (U32)CNMGR_TBL_PTR(i)->local_gprs_data.total_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->local_gprs_data.total_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->local_gprs_data.total_connect_duration);

        /* Total session data */
        ReadRecord(NVRAM_EF_CNMGR_CONNECT_DATA_LID,
                   3 + (i * 4),
                   (void*)(&CNMGR_TBL_PTR(i)->local_total_data),
                   NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE,
                   &error);
        memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_total_data[i]),
               &CNMGR_TBL_PTR(i)->local_total_data,
               sizeof(srv_cnmgr_connect_data_detail_struct));
        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_SESSION_DATA,
                  SRV_CNMGR_CONNECT_TYPE_LOCAL,
                  SRV_CNMGR_BEARER_TYPE_SIM_PS,
                  i,
                  (U32)CNMGR_TBL_PTR(i)->local_total_data.last_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->local_total_data.last_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->local_total_data.last_connect_duration,
                  (U32)CNMGR_TBL_PTR(i)->local_total_data.total_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->local_total_data.total_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->local_total_data.total_connect_duration);

        /* Dial-up session data */
        ReadRecord(NVRAM_EF_CNMGR_CONNECT_DATA_LID,
                   4 + (i * 4),
                   (void*)(&CNMGR_TBL_PTR(i)->dialup_data),
                   NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE,
                   &error);
        memcpy(&(g_cnmgr_srv_runtime_data_cntx.dialup_data[i]),
               &CNMGR_TBL_PTR(i)->dialup_data,
               sizeof(srv_cnmgr_connect_data_detail_struct));
        MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                  SRV_CNMGR_SESSION_DATA,
                  SRV_CNMGR_CONNECT_TYPE_DIALUP,
                  SRV_CNMGR_BEARER_TYPE_TOTAL,
                  i,
                  (U32)CNMGR_TBL_PTR(i)->dialup_data.last_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->dialup_data.last_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->dialup_data.last_connect_duration,
                  (U32)CNMGR_TBL_PTR(i)->dialup_data.total_sent_size,
                  (U32)CNMGR_TBL_PTR(i)->dialup_data.total_recv_size,
                  (U32)CNMGR_TBL_PTR(i)->dialup_data.total_connect_duration);
    }

    /* Wi-Fi session data */
#ifdef __MMI_WLAN_FEATURES__
    ReadRecord(NVRAM_EF_CNMGR_CONNECT_DATA_LID,
               1 + (SRV_CNMGR_SIM_TOTAL * 4),
               (void*)(&g_cnmgr_srv_history_data_cntx.local_wifi_data),
               NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE,
               &error);
    memcpy(&(g_cnmgr_srv_runtime_data_cntx.local_wifi_data),
           &(g_cnmgr_srv_history_data_cntx.local_wifi_data),
           sizeof(srv_cnmgr_connect_data_detail_struct));
    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_SESSION_DATA,
              SRV_CNMGR_CONNECT_TYPE_LOCAL,
              SRV_CNMGR_BEARER_TYPE_WIFI,
              0,
              (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_sent_size,
              (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_recv_size,
              (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.last_connect_duration,
              (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_sent_size,
              (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_recv_size,
              (U32)g_cnmgr_srv_history_data_cntx.local_wifi_data.total_connect_duration);
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */

    return MMI_RET_OK;

#else /* __MMI_ENABLE_CNMGR_SRV__ */

    return MMI_RET_ERR;

#endif /* __MMI_ENABLE_CNMGR_SRV__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_connection_data
 * DESCRIPTION
 *  This API is used to get connection data.
 * PARAMETERS
 *  query :         [IN]    The connection data that application wants to query
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_get_connection_data(srv_cnmgr_connect_data_query_struct *query,
                                                    srv_cnmgr_connect_data_cb_funcptr_type cb_func,
                                                    void *user_data)
{
#if defined(__MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_GET_CONNECTION_DATA, query->sim_id, query->bearer_type);

    /* Check input paramter */
    if (query == NULL ||
        (query->bearer_type != SRV_CNMGR_BEARER_TYPE_CSD &&
         query->bearer_type != SRV_CNMGR_BEARER_TYPE_GPRS &&
         query->bearer_type != SRV_CNMGR_BEARER_TYPE_SIM_PS &&
         query->bearer_type != SRV_CNMGR_BEARER_TYPE_WIFI))
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    /* Store request in free slot */
    for (i = 0; i < SRV_CNMGR_MAX_CONNECT_DATA_REQ; i++)
    {
        if (g_cnmgr_srv_cntx.get_connect_data_req_list[i].is_used == MMI_FALSE)
        {
            g_cnmgr_srv_cntx.get_connect_data_req_list[i].query.bearer_type = query->bearer_type;
            g_cnmgr_srv_cntx.get_connect_data_req_list[i].query.sim_id = query->sim_id;
            g_cnmgr_srv_cntx.get_connect_data_req_list[i].cb_func = cb_func;
            g_cnmgr_srv_cntx.get_connect_data_req_list[i].user_data = user_data;
            g_cnmgr_srv_cntx.get_connect_data_req_list[i].is_used = MMI_TRUE;

            return srv_cnmgr_get_bearer_info_req_handler();
        }
    }

    return SRV_CNMGR_RESULT_REACH_MAX_SUPPORT_NUM;

#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__  && defined(__TCPIP__)*/

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ && defined(__TCPIP__)*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_active_bearer_list
 * DESCRIPTION
 *  This API is used to get active bearer list.
 * PARAMETERS
 *  bearer_list	:   [OUT]   Active bearer list
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_cnmgr_get_active_bearer_list(srv_cnmgr_bearer_list_struct *bearer_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)
    U8 i, j = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bearer_list == NULL)
    {
        return;
    }

    memset(bearer_list, 0, sizeof(srv_cnmgr_bearer_list_struct));

#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)

    /* Get active bearer */
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
#ifdef __USB_TETHERING__

        if (g_cnmgr_srv_merged_bearer_list[i].count > 0 &&
            g_cnmgr_srv_merged_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE)
        {
            bearer_list->node[j].account_id = cbm_encode_data_account_id(g_cnmgr_srv_merged_bearer_list[i].profile_id,
                                                                         (cbm_sim_id_enum)g_cnmgr_srv_merged_bearer_list[i].sim_id,
                                                                         0,
                                                                         KAL_FALSE);
            bearer_list->node[j].connect_type = g_cnmgr_srv_merged_bearer_list[i].connect_type;
            bearer_list->node[j].dialup_type = g_cnmgr_srv_merged_bearer_list[i].dialup_type;
            bearer_list->node[j].connect_time = g_cnmgr_srv_merged_bearer_list[i].connect_time;
            bearer_list->node[j].all_data_size = g_cnmgr_srv_merged_bearer_list[i].all_data_size;

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_GET_ACTIVE_BEARER_LIST,
                      j,
                      bearer_list->node[j].account_id,
                      bearer_list->node[j].connect_type,
                      bearer_list->node[j].dialup_type,
                      (U32)bearer_list->node[j].connect_time,
                      (U32)bearer_list->node[j].all_data_size);

            j++;
        }

#else /* __USB_TETHERING__ */

        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE &&
            g_cnmgr_srv_bearer_list[i].not_display == MMI_FALSE)
        {
            bearer_list->node[j].account_id = cbm_encode_data_account_id(g_cnmgr_srv_bearer_list[i].profile_id,
                                                                         (cbm_sim_id_enum)g_cnmgr_srv_bearer_list[i].sim_id,
                                                                         0,
                                                                         KAL_FALSE);
            bearer_list->node[j].connect_type = g_cnmgr_srv_bearer_list[i].connect_type;
            bearer_list->node[j].dialup_type = g_cnmgr_srv_bearer_list[i].dialup_type;
            bearer_list->node[j].connect_time = g_cnmgr_srv_bearer_list[i].connect_time;
            bearer_list->node[j].all_data_size = g_cnmgr_srv_bearer_list[i].detail.all_data_size;

            MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                      SRV_CNMGR_GET_ACTIVE_BEARER_LIST,
                      j,
                      bearer_list->node[j].account_id,
                      bearer_list->node[j].connect_type,
                      bearer_list->node[j].dialup_type,
                      (U32)bearer_list->node[j].connect_time,
                      (U32)bearer_list->node[j].all_data_size);

            j++;
        }

#endif /* __USB_TETHERING__ */
    }

    bearer_list->active_node_num = j;
#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_bearer_connection_data
 * DESCRIPTION
 *  This API is used to get bearer connection data.
 * PARAMETERS
 *  bearer :        [IN]    Bearer info (account id and connection type)
 *  bearer_data :   [OUT]   Bearer connection data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_get_bearer_connection_data(srv_cnmgr_bearer_id_struct *bearer, srv_cnmgr_bearer_data_struct *bearer_data)
{
#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 account_id, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bearer == NULL || bearer_data == NULL)
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_GET_BEARER_CONNECTION_DATA, bearer->account_id, bearer->connect_type);

    if ((bearer->connect_type != SRV_CNMGR_CONNECT_TYPE_LOCAL &&
         bearer->connect_type != SRV_CNMGR_CONNECT_TYPE_DIALUP) ||
         bearer_data == NULL)
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    memset(bearer_data, 0, sizeof(srv_cnmgr_bearer_data_struct));

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
#ifdef __USB_TETHERING__

        if (g_cnmgr_srv_merged_bearer_list[i].count > 0)
        {
            account_id = cbm_encode_data_account_id(g_cnmgr_srv_merged_bearer_list[i].profile_id,
                                                    (cbm_sim_id_enum)g_cnmgr_srv_merged_bearer_list[i].sim_id,
                                                    0,
                                                    KAL_FALSE);

            if (account_id == bearer->account_id &&
                g_cnmgr_srv_merged_bearer_list[i].connect_type == bearer->connect_type)
            {
                bearer_data->connect_time = g_cnmgr_srv_merged_bearer_list[i].connect_time;
                bearer_data->all_data_size = g_cnmgr_srv_merged_bearer_list[i].all_data_size;
                bearer_data->recv_data_size = g_cnmgr_srv_merged_bearer_list[i].recv_data_size;
                bearer_data->sent_data_size = g_cnmgr_srv_merged_bearer_list[i].send_data_size;
                bearer_data->upload_rate = g_cnmgr_srv_merged_bearer_list[i].up_speed;
                bearer_data->download_rate = g_cnmgr_srv_merged_bearer_list[i].down_speed;
                bearer_data->bearer_status = g_cnmgr_srv_merged_bearer_list[i].bearer_status;

                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_GET_BEARER_CONNECTION_DATA_RESULT,
                          bearer_data->bearer_status,
                          (U32)bearer_data->connect_time,
                          (U32)bearer_data->all_data_size,
                          (U32)bearer_data->recv_data_size,
                          (U32)bearer_data->sent_data_size,
                          (U32)bearer_data->upload_rate,
                          (U32)bearer_data->download_rate);

                return SRV_CNMGR_RESULT_SUCCESS;
            }
        }

#else /* __USB_TETHERING__ */

        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].not_display == MMI_FALSE)
        {
            account_id = cbm_encode_data_account_id(g_cnmgr_srv_bearer_list[i].profile_id,
                                                    (cbm_sim_id_enum)g_cnmgr_srv_bearer_list[i].sim_id,
                                                    0,
                                                    KAL_FALSE);

            if (account_id == bearer->account_id &&
                g_cnmgr_srv_bearer_list[i].connect_type == bearer->connect_type)
            {
                bearer_data->connect_time = g_cnmgr_srv_bearer_list[i].connect_time;
                bearer_data->all_data_size = g_cnmgr_srv_bearer_list[i].detail.all_data_size;
                bearer_data->recv_data_size = g_cnmgr_srv_bearer_list[i].detail.recv_data_size;
                bearer_data->sent_data_size = g_cnmgr_srv_bearer_list[i].detail.send_data_size;
                bearer_data->upload_rate = g_cnmgr_srv_bearer_list[i].detail.up_speed;
                bearer_data->download_rate = g_cnmgr_srv_bearer_list[i].detail.down_speed;
                bearer_data->bearer_status = g_cnmgr_srv_bearer_list[i].bearer_status;

                MMI_TRACE(SRV_CNMGR_TRC_GROUP,
                          SRV_CNMGR_GET_BEARER_CONNECTION_DATA_RESULT,
                          bearer_data->bearer_status,
                          (U32)bearer_data->connect_time,
                          (U32)bearer_data->all_data_size,
                          (U32)bearer_data->recv_data_size,
                          (U32)bearer_data->sent_data_size,
                          (U32)bearer_data->upload_rate,
                          (U32)bearer_data->download_rate);

                return SRV_CNMGR_RESULT_SUCCESS;
            }
        }

#endif /* __USB_TETHERING__ */
    }

    return SRV_CNMGR_RESULT_INVALID_BEARER;

#else /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_all_bearer
 * DESCRIPTION
 *  This API is used to disconnect all bearer.
 * PARAMETERS
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_disconnect_all_bearer(srv_cnmgr_cb_funcptr_type cb_func, void *user_data)
{
#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_bearer_context_struct *first_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_DISCONNECT_ALL_BEARER);

    if ((first_node = srv_cnmgr_get_first_active_bearer_node()) != NULL)
    {
        if (g_cnmgr_srv_cntx.disc_all_flag == MMI_FALSE)
        {
            if (cb_func == NULL)
            {
                return SRV_CNMGR_RESULT_INVALID_INPUT;
            }

            /* Disconnect all bearer */
            g_cnmgr_srv_cntx.disc_all_flag = MMI_TRUE;
            g_cnmgr_srv_cntx.disc_all_req.cb_func = cb_func;
            g_cnmgr_srv_cntx.disc_all_req.user_data = user_data;
            first_node->disconnecting = MMI_TRUE;
            srv_cnmgr_disconnect_bearer_req_handler(first_node->profile_id, first_node->sim_id, first_node->connect_type, first_node->dialup_type);

            return SRV_CNMGR_RESULT_WAIT_FOR_RSP;
        }

        return SRV_CNMGR_RESULT_REACH_MAX_SUPPORT_NUM;
    }

    return SRV_CNMGR_RESULT_NO_CONNECTION;

#else /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_bearer
 * DESCRIPTION
 *  This API is used to disconnect one bearer.
 * PARAMETERS
 *  bearer :        [IN]    Bearer
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_disconnect_bearer(srv_cnmgr_bearer_id_struct *bearer,
                                                  srv_cnmgr_cb_funcptr_type cb_func,
                                                  void *user_data)
{
#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 account_id, i;
    MMI_BOOL has_data = MMI_FALSE;
    U8 encode_acct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_DISCONNECT_BEARER, bearer->account_id, bearer->connect_type);

    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
        if (g_cnmgr_srv_bearer_list[i].valid &&
            g_cnmgr_srv_bearer_list[i].not_display == MMI_FALSE)
        {
            encode_acct = cbm_get_original_account(g_cnmgr_srv_bearer_list[i].profile_id);

#ifdef __USB_TETHERING__
            if (encode_acct == CBM_USB_TR_PS_ACCT_ID)
            {
                encode_acct = g_cnmgr_srv_cntx.user_tethering_acct;
            }
#endif

            account_id = cbm_encode_data_account_id(encode_acct,
                                                    (cbm_sim_id_enum)g_cnmgr_srv_bearer_list[i].sim_id,
                                                    0,
                                                    KAL_FALSE);

            if (account_id == bearer->account_id &&
                g_cnmgr_srv_bearer_list[i].connect_type == bearer->connect_type)
            {
                has_data = MMI_TRUE;
                if (g_cnmgr_srv_bearer_list[i].bearer_status != SRV_CNMGR_BEARER_STATUS_DEACTIVE)
                {
                    if (g_cnmgr_srv_cntx.disc_req.cb_func == NULL)
                    {
                        if (cb_func == NULL)
                        {
                            return SRV_CNMGR_RESULT_INVALID_INPUT;
                        }

                        if (g_cnmgr_srv_bearer_list[i].disconnecting == MMI_FALSE)
                        {
                            g_cnmgr_srv_bearer_list[i].disconnecting = MMI_TRUE;
                            srv_cnmgr_disconnect_bearer_req_handler(g_cnmgr_srv_bearer_list[i].profile_id,
                                                                    g_cnmgr_srv_bearer_list[i].sim_id,
                                                                    g_cnmgr_srv_bearer_list[i].connect_type,
                                                                    g_cnmgr_srv_bearer_list[i].dialup_type);
                        }

                        g_cnmgr_srv_cntx.disc_req.cb_func = cb_func;
                        g_cnmgr_srv_cntx.disc_req.user_data = user_data;
                        g_cnmgr_srv_cntx.disc_req.profile_id = g_cnmgr_srv_bearer_list[i].profile_id;
                        g_cnmgr_srv_cntx.disc_req.real_acct = encode_acct;
                        g_cnmgr_srv_cntx.disc_req.connect_type = g_cnmgr_srv_bearer_list[i].connect_type;

                        return SRV_CNMGR_RESULT_WAIT_FOR_RSP;
                    }
                    else
                    {
                        return SRV_CNMGR_RESULT_REACH_MAX_SUPPORT_NUM;
                    }
                }
            }
        }
    }

    if (has_data == MMI_TRUE)
    {
        return SRV_CNMGR_RESULT_SUCCESS;
    }
    else
    {
        return SRV_CNMGR_RESULT_INVALID_BEARER;
    }

#else /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_reset_connection_data
 * DESCRIPTION
 *  This API is used to reset connection data.
 * PARAMETERS
 *  reset_req :     [IN]    Reset connection data request
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_reset_connection_data(srv_cnmgr_reset_data_req_struct *reset_req,
                                                      srv_cnmgr_reset_data_cb_funcptr_type cb_func,
                                                      void *user_data)
{
#if defined(__MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (reset_req == NULL || cb_func == NULL)
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    MMI_TRACE(SRV_CNMGR_TRC_GROUP,
              SRV_CNMGR_RESET_CONNECTION_DATA,
              reset_req->sim_id,
              reset_req->bearer_type,
              reset_req->connect_type,
              reset_req->data_type);

    /* Check input paramter */
    if (reset_req->bearer_type != SRV_CNMGR_BEARER_TYPE_CSD &&
        reset_req->bearer_type != SRV_CNMGR_BEARER_TYPE_GPRS &&
        reset_req->bearer_type != SRV_CNMGR_BEARER_TYPE_SIM_PS &&
        reset_req->bearer_type != SRV_CNMGR_BEARER_TYPE_WIFI &&
        reset_req->bearer_type != SRV_CNMGR_BEARER_TYPE_TOTAL)
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    if (reset_req->connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP &&
        reset_req->bearer_type != SRV_CNMGR_BEARER_TYPE_GPRS)
    {
        return SRV_CNMGR_RESULT_NOT_SUPPORT;
    }

    /* Store request in free slot */
    if (g_cnmgr_srv_cntx.reset_data_req.cb_func == NULL)
    {
        memcpy(&(g_cnmgr_srv_cntx.reset_data_req.req), reset_req, sizeof(srv_cnmgr_reset_data_req_struct));
        g_cnmgr_srv_cntx.reset_data_req.cb_func = cb_func;
        g_cnmgr_srv_cntx.reset_data_req.user_data = user_data;

        sim_id = srv_cnmgr_convert_mmi_sim_id_to_cbm(reset_req->sim_id);
        if (reset_req->connect_type == SRV_CNMGR_CONNECT_TYPE_DIALUP ||
            reset_req->connect_type == SRV_CNMGR_CONNECT_TYPE_TOTAL)
        {
            return srv_cnmgr_reset_dialup_data(sim_id, reset_req->bearer_type, reset_req->data_type);
        }
        else if (reset_req->connect_type == SRV_CNMGR_CONNECT_TYPE_LOCAL)
        {
            if (sim_id < CBM_SIM_ID_TOTAL)
            {
                return srv_cnmgr_reset_local_profile(sim_id, reset_req->bearer_type, reset_req->data_type);
            }
        }

        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    return SRV_CNMGR_RESULT_REACH_MAX_SUPPORT_NUM;

#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__  && defined(__TCPIP__)*/

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ && defined(__TCPIP__)*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_register_bearer_data_update_notify
 * DESCRIPTION
 *  This API is used to register application's callback for getting notification
 *  when bearer data is updated.
 * PARAMETERS
 *  interval :      [IN]    Data update interval (unit: millisecond)
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  MMI_TRUE : Register successfully
 *  MMI_FALSE : Fail to register
 *****************************************************************************/
MMI_BOOL srv_cnmgr_register_bearer_data_update_notify(U32 interval,
                                                      srv_cnmgr_notify_cb_funcptr_type cb_func,
                                                      void *user_data)
{
#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_REGISTER_BEARER_DATA_UPDATE_NOTIFY, interval);

    MMI_ASSERT(interval >= SRV_CNMGR_INTERNAL_TIMER_INTERVAL);

    if (cb_func == NULL || interval < SRV_CNMGR_INTERNAL_TIMER_INTERVAL)
    {
        return MMI_FALSE;
    }

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
    {
        if (g_cnmgr_srv_cntx.bearer_data_notify[i].is_used &&
            g_cnmgr_srv_cntx.bearer_data_notify[i].cb_func == cb_func &&
            g_cnmgr_srv_cntx.bearer_data_notify[i].user_data == user_data)
        {
            g_cnmgr_srv_cntx.bearer_data_notify[i].interval = interval / SRV_CNMGR_INTERNAL_TIMER_INTERVAL;
            srv_cnmgr_set_data_update_interval(MMI_TRUE, 0);
            return MMI_TRUE;
        }
    }

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
    {
        if (g_cnmgr_srv_cntx.bearer_data_notify[i].is_used == MMI_FALSE)
        {
            /* Free slot */
            g_cnmgr_srv_cntx.bearer_data_notify[i].is_used = MMI_TRUE;
            g_cnmgr_srv_cntx.bearer_data_notify[i].cb_func = cb_func;
            g_cnmgr_srv_cntx.bearer_data_notify[i].user_data = user_data;
            g_cnmgr_srv_cntx.bearer_data_notify[i].interval = interval / SRV_CNMGR_INTERNAL_TIMER_INTERVAL;

            srv_cnmgr_set_data_update_interval(MMI_FALSE, g_cnmgr_srv_cntx.bearer_data_notify[i].interval);
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

#else /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */

    return MMI_FALSE;
    
#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_deregister_bearer_data_update_notify
 * DESCRIPTION
 *  This API is used to deregister application's callback for getting notification
 *  when bearer data is updated.
 * PARAMETERS
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_deregister_bearer_data_update_notify(srv_cnmgr_notify_cb_funcptr_type cb_func, void *user_data)
{
#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_DEREGISTER_BEARER_DATA_UPDATE_NOTIFY);

    if (cb_func == NULL)
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
    {
        if (g_cnmgr_srv_cntx.bearer_data_notify[i].is_used &&
            g_cnmgr_srv_cntx.bearer_data_notify[i].cb_func == cb_func &&
            g_cnmgr_srv_cntx.bearer_data_notify[i].user_data == user_data)
        {
            memset(&g_cnmgr_srv_cntx.bearer_data_notify[i], 0, sizeof(srv_cnmgr_bearer_data_notify_struct));
            srv_cnmgr_set_data_update_interval(MMI_TRUE, 0);
            return SRV_CNMGR_RESULT_SUCCESS;
        }
    }

    return SRV_CNMGR_RESULT_INVALID_INPUT;

#else /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_register_connection_data_notify
 * DESCRIPTION
 *  This API is used to register application's callback function to let CNMGR
 *  service notify connection data periodically.
 * PARAMETERS
 *  interval :      [IN]	Notification interval
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  MMI_TRUE : Register successfully
 *  MMI_FALSE : Fail to register
 *****************************************************************************/
MMI_BOOL srv_cnmgr_register_connection_data_notify(U32 interval,
                                                   srv_cnmgr_connect_data_notify_cb_funcptr_type cb_func,
                                                   void *user_data)
{
#if defined(__CNMGR_GET_BEARER_DETAIL_INFO_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_REGISTER_CONNECTION_DATA_NOTIFY, interval);

    MMI_ASSERT(interval >= SRV_CNMGR_INTERNAL_TIMER_INTERVAL);

    if (cb_func == NULL || interval < SRV_CNMGR_INTERNAL_TIMER_INTERVAL)
    {
        return MMI_FALSE;
    }

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
    {
        if (g_cnmgr_srv_cntx.connect_data_notify_list[i].is_used == MMI_FALSE)
        {
            /* Free slot */
            g_cnmgr_srv_cntx.connect_data_notify_list[i].is_used = MMI_TRUE;
            g_cnmgr_srv_cntx.connect_data_notify_list[i].cb_func = cb_func;
            g_cnmgr_srv_cntx.connect_data_notify_list[i].user_data = user_data;
            g_cnmgr_srv_cntx.connect_data_notify_list[i].interval = interval / SRV_CNMGR_INTERNAL_TIMER_INTERVAL;

            srv_cnmgr_set_data_update_interval(MMI_FALSE, g_cnmgr_srv_cntx.connect_data_notify_list[i].interval);

            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

#else /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ && defined(__TCPIP__)*/

    return MMI_FALSE;
        
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ && defined(__TCPIP__)*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_deregister_connection_data_notify
 * DESCRIPTION
 *  This API is used to deregister application's callback which is registered by
 *  calling srv_cnmgr_register_connection_data_notify().
 * PARAMETERS
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_deregister_connection_data_notify(srv_cnmgr_connect_data_notify_cb_funcptr_type cb_func,
                                                                  void *user_data)
{
#if defined(__CNMGR_GET_BEARER_DETAIL_INFO_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_DEREGISTER_CONNECTION_DATA_NOTIFY);

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_APP_NUM; i++)
    {
        if (g_cnmgr_srv_cntx.connect_data_notify_list[i].is_used &&
            g_cnmgr_srv_cntx.connect_data_notify_list[i].cb_func == cb_func &&
            g_cnmgr_srv_cntx.connect_data_notify_list[i].user_data == user_data)
        {
            memset(&g_cnmgr_srv_cntx.connect_data_notify_list[i], 0, sizeof(srv_cnmgr_connect_data_notify_req_struct));
            srv_cnmgr_set_data_update_interval(MMI_TRUE, 0);
            return SRV_CNMGR_RESULT_SUCCESS;
        }
    }

    return SRV_CNMGR_RESULT_INVALID_INPUT;

#else  /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ && defined(__TCPIP__)*/

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ && defined(__TCPIP__)*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_bearer_status
 * DESCRIPTION
 *  This API is used to get bearer status.
 * PARAMETERS
 *  acct_id :       [IN]    Data account id
 *  bearer_status : [OUT]   Bearer status
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_get_bearer_status(U32 acct_id, U8 *bearer_status)
{
#if defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, account_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CNMGR_MAX_BEARER_NUM; i++)
    {
#ifdef __USB_TETHERING__
        account_id = cbm_encode_data_account_id(g_cnmgr_srv_merged_bearer_list[i].profile_id,
                                                (cbm_sim_id_enum)g_cnmgr_srv_merged_bearer_list[i].sim_id,
                                                0,
                                                KAL_FALSE);

        if (g_cnmgr_srv_merged_bearer_list[i].count > 0 &&
            account_id == acct_id)
        {
            *bearer_status = g_cnmgr_srv_merged_bearer_list[i].bearer_status;
            return SRV_CNMGR_RESULT_SUCCESS;
        }
#else /* __USB_TETHERING__ */
        account_id = cbm_encode_data_account_id(g_cnmgr_srv_bearer_list[i].profile_id,
                                                (cbm_sim_id_enum)g_cnmgr_srv_bearer_list[i].sim_id,
                                                0,
                                                KAL_FALSE);

        if (g_cnmgr_srv_bearer_list[i].valid &&
            account_id == acct_id &&
            g_cnmgr_srv_bearer_list[i].not_display == MMI_FALSE)
        {
            *bearer_status = g_cnmgr_srv_bearer_list[i].bearer_status;
            return SRV_CNMGR_RESULT_SUCCESS;
        }
#endif /* __USB_TETHERING__ */
    }

    *bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
    return SRV_CNMGR_RESULT_INVALID_BEARER;

#else /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */

    *bearer_status = SRV_CNMGR_BEARER_STATUS_DEACTIVE;
    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && defined(__MMI_CBM_CONNECTION_MANAGER__) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_set_scri_send_check_interval
 * DESCRIPTION
 *  This API is used to set the check interval for sending SCRI to network.
 *
 *  Before 3G Gemini 2.0 is ready, SCRI is usd to disconnecting RRC connection.
 *  CNMGR SRV will send RRC connection disconnect request to protocol if no data
 *  is transmitted for a period of time. The period is the maximum value of all
 *  check intervals set by applications.
 *
 *  After 3G Gemini 2.0 is ready, SCRI is used only for power-saving. CNMGR SRV
 *  will send fast dormancy request to protocol if no data is transmitted for
 *  a period of time. The period is the maximum value of all check intervals set by applications.
 * PARAMETERS
 *  type :          [IN]    SCRI check timer type
 *  interval :      [IN]	SCRI send check interval (unit: millisecond)
 *  id :            [OUT]   If set successfully, id is used to unset SCRI send check interval
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_set_scri_send_check_interval(srv_cnmgr_scri_check_timer_enum type,
                                                             U32 interval,
                                                             U32 *id)
{
#if defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_SET_SCRI_SEND_CHECK_INTERVAL, type, interval);

    *id = 0;

    if (interval < SRV_CNMGR_INTERNAL_TIMER_INTERVAL)
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    for (i = 0; i < SRV_CNMGR_MAX_SUPPORT_SCRI_REQ; i++)
    {
        if (g_cnmgr_srv_cntx.scri_req_list[type][i].id == 0)
        {
            /* Free slot */
            g_cnmgr_srv_cntx.scri_req_list[type][i].id = ++g_cnmgr_srv_req_id_counter;
            *id = g_cnmgr_srv_cntx.scri_req_list[type][i].id;
            if (g_cnmgr_srv_req_id_counter >= SRV_CNMGR_MAX_REQ_ID)
            {
                g_cnmgr_srv_req_id_counter = 0;
            }
            g_cnmgr_srv_cntx.scri_req_list[type][i].interval = interval / SRV_CNMGR_INTERNAL_TIMER_INTERVAL;

            srv_cnmgr_set_scri_check_interval(type);

            return SRV_CNMGR_RESULT_SUCCESS;
        }
    }

    return SRV_CNMGR_RESULT_REACH_MAX_SUPPORT_NUM;

#else /* defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) */

    *id = 0;
    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_unset_scri_send_check_interval
 * DESCRIPTION
 *  This API is used to unset the check interval for sending SCRI to network.
 * PARAMETERS
 *  id :            [IN]    id returned by set function
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_unset_scri_send_check_interval(U32 id)
{
#if defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_UNSET_SCRI_SEND_CHECK_INTERVAL, id);

    for (i = 0; i < SRV_CNMGR_SCRI_CHECK_TIMER_TOTAL; i++)
    {
        for (j = 0; j < SRV_CNMGR_MAX_SUPPORT_SCRI_REQ; j++)
        {
            if (g_cnmgr_srv_cntx.scri_req_list[i][j].id > 0 &&
                g_cnmgr_srv_cntx.scri_req_list[i][j].id == id)
            {
                memset(&g_cnmgr_srv_cntx.scri_req_list[i][j], 0, sizeof(srv_cnmgr_scri_req_struct));
                srv_cnmgr_set_scri_check_interval((srv_cnmgr_scri_check_timer_enum)i);
                return SRV_CNMGR_RESULT_SUCCESS;
            }
        }
    }

    return SRV_CNMGR_RESULT_INVALID_INPUT;

#else /* defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) */

    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_scri_send_check_interval
 * DESCRIPTION
 *  This API is used to get the check interval for sending SCRI to network.
 * PARAMETERS
 *  type :          [IN]    SCRI check timer type
 *  interval :      [OUT]   SCRI send check interval (unit: millisecond)
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
srv_cnmgr_result_enum srv_cnmgr_get_scri_send_check_interval(srv_cnmgr_scri_check_timer_enum type, U32 *interval)
{
#if defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interval == NULL)
    {
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    if (type >= SRV_CNMGR_SCRI_CHECK_TIMER_TOTAL)
    {
        *interval = 0;
        return SRV_CNMGR_RESULT_INVALID_INPUT;
    }

    *interval = g_cnmgr_srv_cntx.scri_check_interval[type] * SRV_CNMGR_INTERNAL_TIMER_INTERVAL;
    return SRV_CNMGR_RESULT_SUCCESS;

#else /* defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) */

    *interval = 0;
    return SRV_CNMGR_RESULT_NOT_SUPPORT;

#endif /* defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_gpio_lcd_sleep_evt_hdlr
 * DESCRIPTION
 *  Handle EVT_ID_GPIO_LCD_SLEEP_IN and EVT_ID_GPIO_LCD_SLEEP_OUT
 * PARAMETERS
 *  evt             [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
MMI_RET srv_cnmgr_gpio_lcd_sleep_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__))
    switch (evt->evt_id)
    {
        case EVT_ID_GPIO_AFTER_LCD_SLEEP_IN:
        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            srv_cnmgr_set_data_update_interval(MMI_TRUE, 0);
            break;

        default:
            break;
    }
#endif /* defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) */

    return MMI_RET_OK;
}

MMI_RET srv_cnmgr_3g_switch_change(mmi_event_struct *evt)
{
#ifdef __MMI_3G_SWITCH__
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
#endif
#endif
    return MMI_RET_OK;
}

#if defined(__TCPIP__) && defined(__MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__)
void srv_cnmgr_collect_data_transfer_info(mmi_abm_get_bearer_info_cnf_struct* cnf)
{
    U32 acct_id = 0xFFFFFFFF;
    S32 index , i;
    U64 send_data_size = 0; 
    U64 recv_data_size = 0;

    
    for (i = 0; i < cnf->count; i++)
    {
        if (cnf->connect_type == ABM_CONNECT_TYPE_DIALUP)
        {
            if (cnf->bearer_cnf_count[i].dialup_info.bearer_type == CSD_BEARER_DIALUP)
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].dialup_info.call_id, g_cnmgr_srv_cntx.bearer_info_req_sim_id, 0, KAL_FALSE);
            }
            else if (cnf->bearer_cnf_count[i].dialup_info.bearer_type == GPRS_BEARER_DIALUP)
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].dialup_info.context_id, g_cnmgr_srv_cntx.bearer_info_req_sim_id, 0, KAL_FALSE);
            }
            index = srv_cnmgr_get_bearer_node_index(acct_id, SRV_CNMGR_CONNECT_TYPE_DIALUP, cnf->bearer_cnf_count[i].dialup_info.bearer_type);
        }
        else
        {
            if (cnf->bearer_cnf_count[i].profile_id == CBM_WIFI_ACCT_ID)
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].profile_id, CBM_SIM_ID_SIM1, 0, KAL_FALSE);
            }
            else
            {
                acct_id = cbm_encode_data_account_id(cnf->bearer_cnf_count[i].profile_id, g_cnmgr_srv_cntx.bearer_info_req_sim_id, 0, KAL_FALSE);
            }
            index = srv_cnmgr_get_bearer_node_index(acct_id, SRV_CNMGR_CONNECT_TYPE_LOCAL, 0);
        }
        if(index >= 0)
        {    
            if (cnf->bearer_cnf_count[i].result)
            {
                if (cnf->bearer_cnf_count[i].send_data_size < g_cnmgr_srv_bearer_list[index].detail.last_send_for_nwinfo||
                    cnf->bearer_cnf_count[i].receive_data_size < g_cnmgr_srv_bearer_list[index].detail.last_recv_for_nwinfo)
                {
                    g_cnmgr_srv_bearer_list[index].need_acc = MMI_TRUE;
                }

                if (g_cnmgr_srv_bearer_list[index].need_acc)
                {
                    g_cnmgr_srv_bearer_list[index].need_acc = MMI_FALSE;

                    send_data_size = cnf->bearer_cnf_count[i].send_data_size;
                    recv_data_size = cnf->bearer_cnf_count[i].receive_data_size;
                }
                else
                {
                    send_data_size = cnf->bearer_cnf_count[i].send_data_size - g_cnmgr_srv_bearer_list[index].detail.last_send_for_nwinfo;
                    recv_data_size = cnf->bearer_cnf_count[i].receive_data_size - g_cnmgr_srv_bearer_list[index].detail.last_recv_for_nwinfo;
                }
            }

            g_cnmgr_srv_bearer_list[index].detail.up_flag = MMI_FALSE;
            g_cnmgr_srv_bearer_list[index].detail.down_flag = MMI_FALSE;
            if(send_data_size != 0)
            {
                g_cnmgr_srv_bearer_list[index].detail.up_flag = MMI_TRUE;
            }
            if(recv_data_size != 0)
            {
                g_cnmgr_srv_bearer_list[index].detail.down_flag = MMI_TRUE;
            }

            g_cnmgr_srv_bearer_list[index].detail.last_recv_for_nwinfo = cnf->bearer_cnf_count[i].receive_data_size;

            g_cnmgr_srv_bearer_list[index].detail.last_send_for_nwinfo = cnf->bearer_cnf_count[i].send_data_size;

        }
    }    

}

void srv_cnmgr_post_nwinfo_evt(MMI_BOOL only_for_nwinfo)
{
    int i = 0;
    srv_cnmgr_notify_nwinfo_evt_struct evt;
    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CNMGR_NOTIFY_NWINFO);
    for(i = 0; i < SRV_CNMGR_MAX_BEARER_NUM ; i++)
    {
        if(g_cnmgr_srv_bearer_list[i].valid == MMI_TRUE
            && g_cnmgr_srv_bearer_list[i].bearer_status == SRV_CNMGR_BEARER_STATUS_ACTIVE
            && (g_cnmgr_srv_bearer_list[i].bearer_type & SRV_CNMGR_BEARER_TYPE_GPRS) )
        {
            if(only_for_nwinfo == MMI_FALSE)
            {
                if(g_cnmgr_srv_bearer_list[i].detail.down_speed != 0)
                {
                    evt.flag[g_cnmgr_srv_bearer_list[i].sim_id].downlink = MMI_TRUE;
                }
                if(g_cnmgr_srv_bearer_list[i].detail.up_speed != 0)
                {
                    evt.flag[g_cnmgr_srv_bearer_list[i].sim_id].uplink = MMI_TRUE;
                }
            }
            else
            {
                if(g_cnmgr_srv_bearer_list[i].detail.down_flag == MMI_TRUE)
                {
                    evt.flag[g_cnmgr_srv_bearer_list[i].sim_id].downlink = MMI_TRUE;
                }
                if(g_cnmgr_srv_bearer_list[i].detail.up_flag == MMI_TRUE)
                {
                    evt.flag[g_cnmgr_srv_bearer_list[i].sim_id].uplink = MMI_TRUE;
                }

            }

        }
    }
    for(i = 0; i < SRV_CNMGR_SIM_TOTAL; i++)
    {
        MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_POST_EVT_TO_NWINFO,
            evt.flag[i].uplink, evt.flag[i].downlink);
    }
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    return;
    
}

void srv_cnmgr_notify_nwinfo(mmi_abm_get_bearer_info_cnf_struct* cnf)
{
    srv_cnmgr_collect_data_transfer_info(cnf);
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
}
#endif /* defined(__TCPIP__) && defined(__MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__) */

