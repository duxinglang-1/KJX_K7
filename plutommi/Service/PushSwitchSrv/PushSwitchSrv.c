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
 * PushSwitchSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "NwInfoSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "wps_struct.h"
#include "pmg_struct.h"
#include "mmi_frm_events_gprot.h"
#include "DebugInitDef_Int.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "string.h"
#include "kal_trace.h"
#include "MMI_common_app_trc.h"
#include "PushSwitchSrvGprot.h"


/*****************************************************************************
 * Define
 *****************************************************************************/
#define PUSH_SWITCH_DEBUG_MODE              (1)


/*****************************************************************************
 * Struct
 *****************************************************************************/
typedef struct
{
    kal_uint8   sim1_imsi[17];              /* imsi for sim1 */
#ifdef __MMI_DUAL_SIM__
    kal_uint8   sim2_imsi[17];              /* imsi for sim2 */
#endif
    kal_uint8   switch_mode;                /* switch on or off */
} srv_push_switch_setting_struct;

typedef struct
{
    MMI_BOOL is_locking;                    /* service locking or not */
    MMI_BOOL is_ready;                      /* service ready or not */
    srv_push_switch_setting_struct setting; /* setting information */
} srv_push_switch_cntx_struct;


/*****************************************************************************
 * Declarations
 *****************************************************************************/
static srv_push_switch_cntx_struct g_srv_push_cntx;
static void srv_push_switch_wps_status_query_req(void);
static MMI_BOOL srv_push_switch_wps_status_query_rsp(void *msg_struct);
static MMI_BOOL srv_push_switch_wps_ready_ind(void *msg_struct);
static void srv_push_switch_notify(void);
static void srv_push_switch_wps_pmg_turn_on_off_req(srv_push_switch_mode_enum mode);
static void srv_push_switch_read_setting_data(void);
static void srv_push_switch_write_setting_data(void);


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_wps_status_query_req
 * DESCRIPTION
 *  status query request to WPS
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_push_switch_wps_status_query_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_WPS_STATUS_QUERY_REQ);
    
    mmi_frm_send_ilm(MOD_WPS, MSG_ID_WPS_STATUS_QUERY_REQ, NULL, NULL);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WPS_STATUS_QUERY_RSP,
        (PsIntFuncPtr)srv_push_switch_wps_status_query_rsp,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_wps_status_query_rsp
 * DESCRIPTION
 *  status query response from WPS
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_push_switch_wps_status_query_rsp(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_status_query_rsp_struct *rsp = (wps_status_query_rsp_struct*)msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_WPS_STATUS_QUERY_RSP, rsp->status);
    
    mmi_frm_clear_protocol_event_handler(
        MSG_ID_WPS_STATUS_QUERY_RSP, 
        (PsIntFuncPtr)srv_push_switch_wps_status_query_rsp);
    if (rsp->status == WPS_READY_STATUS_OK)
    {
        g_srv_push_cntx.is_locking = MMI_FALSE;
        g_srv_push_cntx.is_ready = MMI_TRUE;
        srv_push_switch_notify();
    }
    else
    {
        mmi_frm_set_protocol_event_handler(
            MSG_ID_WPS_READY_IND,
            (PsIntFuncPtr)srv_push_switch_wps_ready_ind,
            MMI_TRUE);
    }

    /* make sure other app can receive this msg */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_wps_ready_ind
 * DESCRIPTION
 *  wps ready indication from WPS
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_push_switch_wps_ready_ind(void *msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_WPS_STATUS_QUERY_IND);
    
    mmi_frm_clear_protocol_event_handler(
        MSG_ID_WPS_READY_IND, 
        (PsIntFuncPtr)srv_push_switch_wps_ready_ind);
    g_srv_push_cntx.is_locking = MMI_FALSE;
    g_srv_push_cntx.is_ready = MMI_TRUE;
    srv_push_switch_notify();
    
    /* make sure other app can receive this msg */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_notify
 * DESCRIPTION
 *  if sim changed, notify user to decide the push switch
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_push_switch_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR sim1_imsi[SRV_MAX_IMSI_LEN + 1];
#ifdef __MMI_DUAL_SIM__
    CHAR sim2_imsi[SRV_MAX_IMSI_LEN + 1];
#endif
    MMI_BOOL ret = MMI_FALSE;
    srv_push_switch_notify_evt_struct notify_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_NOTIFY);
    
    srv_push_switch_read_setting_data();
    ret = srv_sim_ctrl_get_imsi(MMI_SIM1, sim1_imsi, SRV_MAX_IMSI_LEN + 1);
    if (!ret)
    {
        sim1_imsi[0] = 0;
    }
#ifdef __MMI_DUAL_SIM__
    ret = srv_sim_ctrl_get_imsi(MMI_SIM2, sim2_imsi, SRV_MAX_IMSI_LEN + 1);
    if (!ret)
    {
        sim2_imsi[0] = 0;
    }
#endif

#if PUSH_SWITCH_DEBUG_MODE
    kal_wap_trace(
        MOD_MMI_COMMON_APP, 
        MMI_COMMON_TRC_G6_PUSH_SWITCH, 
        "[SRV_PUSH_SWITCH] nvram sim1 imsi: %s, current sim1 imsi: %s",
        g_srv_push_cntx.setting.sim1_imsi, sim1_imsi);
#ifdef __MMI_DUAL_SIM__
    kal_wap_trace(
        MOD_MMI_COMMON_APP, 
        MMI_COMMON_TRC_G6_PUSH_SWITCH, 
        "[SRV_PUSH_SWITCH] nvram sim2 imsi: %s, current sim2 imsi: %s",
        g_srv_push_cntx.setting.sim2_imsi, sim2_imsi);
#endif
#endif

    /* check sim changed or not */
#ifdef __MMI_DUAL_SIM__
    if (strcmp(sim1_imsi, (CHAR*)g_srv_push_cntx.setting.sim1_imsi) != 0 ||
        strcmp(sim2_imsi, (CHAR*)g_srv_push_cntx.setting.sim2_imsi) != 0)
#else
    if (strcmp(sim1_imsi, (CHAR*)g_srv_push_cntx.setting.sim1_imsi) != 0)
#endif
    {
        strcpy((CHAR*)g_srv_push_cntx.setting.sim1_imsi, sim1_imsi);
#ifdef __MMI_DUAL_SIM__
        strcpy((CHAR*)g_srv_push_cntx.setting.sim2_imsi, sim2_imsi);
#endif
        srv_push_switch_write_setting_data();
        MMI_FRM_INIT_EVENT(&notify_evt, EVT_ID_SRV_PUSH_SWITCH_NOTIFY);
        MMI_FRM_CB_EMIT_POST_EVENT(&notify_evt);
    }
    else
    {
        if (g_srv_push_cntx.setting.switch_mode == SRV_PUSH_SWITCH_MODE_OFF)
        {
            srv_push_switch_wps_pmg_turn_on_off_req(SRV_PUSH_SWITCH_MODE_OFF);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_wps_pmg_turn_on_off_req
 * DESCRIPTION
 *  wps pmg turn on/off request to WPS
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_push_switch_wps_pmg_turn_on_off_req(srv_push_switch_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_push_turn_on_off_req_struct *turn_on_off_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_WPS_PMG_TURN_ON_OFF_REQ, mode);
    
    turn_on_off_req = (wps_pmg_push_turn_on_off_req_struct*)construct_local_para(
                        sizeof(wps_pmg_push_turn_on_off_req_struct), TD_RESET);
    turn_on_off_req ->push_turn_on_switch = (kal_uint8)mode;

    mmi_frm_send_ilm(MOD_WPS, MSG_ID_WPS_PMG_TURN_ON_OFF_PUSH_REQ, (oslParaType*)turn_on_off_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_read_setting_data
 * DESCRIPTION
 *  read setting data from nvram
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_push_switch_read_setting_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_READ_SETTING_DATA);
    
    ReadRecord(
        NVRAM_EF_PUSH_SWITCH_SETTING_LID, 
        1, 
        &g_srv_push_cntx.setting, 
        NVRAM_EF_PUSH_SWITCH_SETTING_SIZE, 
        &error);
    
    if (error != NVRAM_READ_SUCCESS)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_FAIL_WITH_CAUSE, error, __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_write_setting_data
 * DESCRIPTION
 *  write setting data to nvram
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_push_switch_write_setting_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_WRITE_SETTING_DATA);
    
    WriteRecord(
        NVRAM_EF_PUSH_SWITCH_SETTING_LID, 
        1, 
        &g_srv_push_cntx.setting, 
        NVRAM_EF_PUSH_SWITCH_SETTING_SIZE, 
        &error);
    
    if (error != NVRAM_WRITE_SUCCESS)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_PUSH_SWITCH, TRC_SRV_PUSH_SWITCH_FAIL_WITH_CAUSE, error, __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_nw_availability_changed_hdlr
 * DESCRIPTION
 *  event hdlr for EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_push_switch_nw_availability_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *service_evt = 
        (srv_nw_info_service_availability_changed_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_COMMON_TRC_G6_PUSH_SWITCH, 
        TRC_SRV_PUSH_SWITCH_NW_CHANGED_HDLR,
        service_evt->old_status, service_evt->new_status, service_evt->sim, g_srv_push_cntx.is_locking);

    if (service_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE)
    {
        if (!g_srv_push_cntx.is_locking)
        {
            srv_push_switch_wps_status_query_req();
            g_srv_push_cntx.is_locking = MMI_TRUE;
        }
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_check_service_ready
 * DESCRIPTION
 *  push switch service is ready or not
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_push_switch_check_service_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(srv_nw_usab_is_any_network_available() && g_srv_push_cntx.is_ready);
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_get_mode
 * DESCRIPTION
 *  get push switch mode, on or off
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_push_switch_mode_enum srv_push_switch_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_push_switch_mode_enum)g_srv_push_cntx.setting.switch_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_switch_set_mode
 * DESCRIPTION
 *  set push switch mode, on or off
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_push_switch_set_mode(srv_push_switch_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_push_cntx.is_ready)
    {
        return MMI_FALSE;
    }

    /* save switch mode if needed */
    if (g_srv_push_cntx.setting.switch_mode != mode)
    {
        g_srv_push_cntx.setting.switch_mode = mode;
        srv_push_switch_write_setting_data();
    }

    /* set switch mode to pmg module */
    srv_push_switch_wps_pmg_turn_on_off_req(mode);

    return MMI_TRUE;
}

#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

