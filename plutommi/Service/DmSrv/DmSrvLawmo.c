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
 *  DmSrvLawmo.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service lawmo.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_include.h"
#include "CbmSrvGprot.h"
#include "DmSrvLawmo.h"
#include "DmSrvMain.h"
#include "DmSrvGprot.h"
#include "TimerEvents.h"
#include "Mmi_rp_srv_dm_def.h"
#include "ModeSwitchSrvGprot.h"
#include "Common_nvram_editor_data_item.h"
#include "Nvram_common_defs.h"
#include "UcmSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "rmmi_struct.h" // ATCI

/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
#ifdef __DM_LAWMO_SUPPORT__
srv_dm_lawmo_context_struct g_srv_dm_lawmo_cntx;
srv_dm_lawmo_context_struct *g_srv_dm_lawmo_cntx_ptr = &g_srv_dm_lawmo_cntx;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void srv_dm_lawmo_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetProtocolEventHandler(srv_dm_lawmo_cmd_rsp_hdlr, MSG_ID_RMMI_LOCK_AT_CMD_CNF);
    SetProtocolEventHandler(srv_dm_lawmo_req_ind_hdlr, MSG_ID_DM_LAWMO_REQ);

    srv_dm_lawmo_get_status_from_nvram();

    if (g_srv_dm_lawmo_cntx_ptr->lock_status == SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK)
    {
        srv_cbm_disallow_nwk_srv(
            SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI | SRV_CBM_BEARER_DIALUP,
            srv_dm_get_cbm_app_id());
    }

    srv_cbm_set_allowed_app_nwk_srv(
        SRV_CBM_BEARER_PS,
        srv_dm_get_cbm_app_id());
}


void srv_dm_lawmo_get_status_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_get_lock_status_from_nvram();
    if (g_srv_dm_lawmo_cntx_ptr->lock_status == SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_LAWMO_REBOOT_LOCK);
        g_srv_dm_lawmo_cntx_ptr->lock_cmd = SRV_DM_LAWMO_LOCK_CMD_LOCK;
        g_srv_dm_lawmo_cntx_ptr->lock_status = SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_LAWMO_REBOOT_UNLOCK);
        g_srv_dm_lawmo_cntx_ptr->lock_cmd = -1;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_req_ind_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_LAWMO_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_lawmo_req_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_lawmo_req_struct *lawmo_cmd_ptr;
    static MMI_BOOL is_holding_msg = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_LAWMO_REQ_IND_HDLR);
    if (srv_dm_check_restore_factory() == MMI_TRUE)
    {
        return;
    }

    if (msg)
    {
        lawmo_cmd_ptr = (dm_lawmo_req_struct*)msg;

        if (MMI_TRUE == srv_mode_switch_is_switching())
        {
            if (is_holding_msg == MMI_FALSE)
            {
                hold_local_para((local_para_struct*)msg);
                is_holding_msg = MMI_TRUE;
            }
            StartTimerEx(
                TIMER_ID_DM_SRV_LAWMO_TRY_SWITCH_MODE,
                5000,
                srv_dm_lawmo_req_ind_hdlr,
                msg);
            return;
        }
        else
        {
            if (is_holding_msg == MMI_TRUE)
            {
                free_local_para((local_para_struct*)msg);
            }
            is_holding_msg = MMI_FALSE;
        }

        srv_dm_lawmo_get_cmd((U32)lawmo_cmd_ptr->command);
        g_srv_dm_lawmo_cntx_ptr->is_server_cmd = MMI_TRUE;

        switch(g_srv_dm_lawmo_cntx_ptr->lock_cmd)
        {
            case SRV_DM_LAWMO_LOCK_CMD_LOCK:
            {
                srv_dm_lawmo_send_req_ind(DM_LAWMO_SUCESS);
                if (g_srv_dm_lawmo_cntx_ptr->lock_status == SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK)
                {
                    return;
                }
                break;
            }
            
            case SRV_DM_LAWMO_LOCK_CMD_UNLOCK:
            {
                srv_dm_lawmo_send_req_ind(DM_LAWMO_SUCESS);
                if (g_srv_dm_lawmo_cntx_ptr->lock_status == SRV_DM_LAWMO_LOCK_STATUS_NONE)
                {
                    return;
                }
                break;
            }

            default:
                break;
        }

        switch (g_srv_dm_lawmo_cntx_ptr->wipe_cmd)
        {
            case SRV_DM_LAWMO_WIPE_CMD_START:
            {
                if (g_srv_dm_lawmo_cntx_ptr->wipe_status == SRV_DM_LAWMO_WIPE_STATUS_BOOTUP_WIPE_FINISH)
                {
                    srv_dm_lawmo_send_req_ind(DM_LAWMO_SUCESS);
                    return;
                }
                else if (g_srv_dm_lawmo_cntx_ptr->wipe_status != SRV_DM_LAWMO_WIPE_STATUS_NONE)
                {
                    return;
                }
                break;
            }

            default:
                break;
        }
    }
    
    //g_srv_dm_lawmo_cntx_ptr->mo_type = srv_dm_get_mo_type(g_srv_dm_lawmo_cntx_ptr->mo_cmd);
    g_srv_dm_lawmo_cntx_ptr->is_cmd_success = MMI_TRUE;
    //srv_dm_change_status_on_command();

    if (g_srv_dm_lawmo_cntx_ptr->wipe_cmd == SRV_DM_LAWMO_WIPE_CMD_START)
    {
        srv_dm_lawmo_save_wipe_status_to_nvram(MMI_TRUE);
        g_srv_dm_lawmo_cntx_ptr->wipe_status = SRV_DM_LAWMO_WIPE_STATUS_START;
        /*send wipe to FMGR*/
        srv_dm_lawmo_wipe_send_evt(SRV_DM_LAWMO_WIPE_CMD_START);

        g_srv_dm_lawmo_cntx_ptr->wipe_status = SRV_DM_LAWMO_WIPE_STATUS_FMGR_FORMAT;
        srv_dm_lawmo_wipe_send_evt(SRV_DM_LAWMO_WIPE_CMD_FMGR_FORMAT);
        return;
    }

    if (g_srv_dm_lawmo_cntx_ptr->lock_cmd == SRV_DM_LAWMO_LOCK_CMD_LOCK)
    {
        srv_dm_lawmo_save_lock_status_to_nvram(MMI_TRUE);
        srv_cbm_disallow_nwk_srv(
            SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
            srv_dm_get_cbm_app_id());

        srv_dm_lawmo_lock_send_evt(SRV_DM_LAWMO_LOCK_CMD_LOCK);
        return;
    }

    if (g_srv_dm_lawmo_cntx_ptr->lock_cmd == SRV_DM_LAWMO_LOCK_CMD_UNLOCK)
    {
        srv_dm_lawmo_save_lock_status_to_nvram(MMI_FALSE);
        
        srv_cbm_allow_nwk_srv(
            SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
            srv_dm_get_cbm_app_id());

        srv_dm_lawmo_lock_send_evt(SRV_DM_LAWMO_LOCK_CMD_UNLOCK);  
        return;
    }
    
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
#endif
void srv_dm_lawmo_dummy_cb(MMI_BOOL result, CHAR *debug_info)
{
    
}


void srv_dm_lawmo_lock_report_cb(MMI_BOOL result, CHAR *debug_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_print_string_trace(
        MOD_MMI_CONN_APP,
        TRACE_GROUP_3,
        "[DM][SRV] lock result:%d, debug_info=%s",
        result,
        debug_info);
}

void srv_dm_lawmo_wipe_report_cb(MMI_BOOL result, CHAR *debug_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct evt;
    MMI_BOOL finish = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_print_string_trace(
        MOD_MMI_CONN_APP,
        TRACE_GROUP_3,
        "[DM][SRV] wipe result:%d, debug_info=%s",
        result,
        debug_info);

    if (g_srv_dm_lawmo_cntx_ptr->wipe_status == SRV_DM_LAWMO_WIPE_STATUS_FMGR_FORMAT)
    {
        g_srv_dm_lawmo_cntx_ptr->wipe_app_number = mmi_frm_cb_register_receiver_count(EVT_ID_SRV_DM_LAWMO_WIPE_IND);
        if (g_srv_dm_lawmo_cntx_ptr->wipe_app_number > 0)
        {
            srv_dm_lawmo_wipe_send_evt(SRV_DM_LAWMO_WIPE_CMD_APP_WIPE);
            g_srv_dm_lawmo_cntx_ptr->wipe_status = SRV_DM_LAWMO_WIPE_STATUS_APP_WIPE;
        }
        else
        {
            finish = MMI_TRUE;
        }
    }
    else if (g_srv_dm_lawmo_cntx_ptr->wipe_status == SRV_DM_LAWMO_WIPE_STATUS_APP_WIPE)
    {
        g_srv_dm_lawmo_cntx_ptr->wipe_app_number--;
        if (g_srv_dm_lawmo_cntx_ptr->wipe_app_number == 0)
        {
            finish = MMI_TRUE;
        }
    }

    if (finish != MMI_FALSE)
    {
        srv_dm_lawmo_save_wipe_status_to_nvram(MMI_FALSE);
        if (g_srv_dm_lawmo_cntx_ptr->is_server_cmd == MMI_TRUE)
        {
        g_srv_dm_lawmo_cntx_ptr->wipe_status = SRV_DM_LAWMO_WIPE_STATUS_NONE;
        srv_dm_lawmo_send_req_ind(DM_LAWMO_SUCESS);
        }
        else
        {
            g_srv_dm_lawmo_cntx_ptr->wipe_status = SRV_DM_LAWMO_WIPE_STATUS_BOOTUP_WIPE_FINISH;
        }
        
        evt.size = sizeof(srv_dm_lawmo_wipe_ind_evt_struct);
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND);
        
        evt.cmd = SRV_DM_LAWMO_WIPE_CMD_FINISH;
        evt.cb = srv_dm_lawmo_wipe_report_cb;
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_lock_send_evt
 * DESCRIPTION
 *  function to call the app callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_lawmo_lock_send_evt(srv_dm_lawmo_lock_cmd_enum lock_cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_no_callback = MMI_TRUE;
    srv_dm_lawmo_lock_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_LAWMO_LOCK_SEND_EVT, lock_cmd);

    evt.size = sizeof(srv_dm_lawmo_lock_ind_evt_struct);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DM_LAWMO_LOCK_IND);
    evt.cmd = lock_cmd;
    evt.cb = srv_dm_lawmo_lock_report_cb;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

    srv_dm_lawmo_send_cmd_req(g_srv_dm_lawmo_cntx_ptr->lock_cmd);
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_wipe_send_evt
 * DESCRIPTION
 *  function to call the special app callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_lawmo_wipe_send_evt(srv_dm_lawmo_wipe_cmd_enum wipe_cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_LAWMO_WIPE_SEND_EVT, wipe_cmd);

    evt.size = sizeof(srv_dm_lawmo_wipe_ind_evt_struct);
    if (wipe_cmd == SRV_DM_LAWMO_WIPE_CMD_APP_WIPE)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DM_LAWMO_WIPE_IND);
        evt.cb = srv_dm_lawmo_wipe_report_cb;
    }
    else if (wipe_cmd == SRV_DM_LAWMO_WIPE_CMD_FMGR_FORMAT)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND);
        evt.cb = srv_dm_lawmo_wipe_report_cb;
    }
    else
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND);
        evt.cb = srv_dm_lawmo_dummy_cb;
    }
    evt.cmd = wipe_cmd;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_send_cmd_req
 * DESCRIPTION
 *  function to send the lawmo cmd message, also as the callback function to register the lawmo command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_lawmo_send_cmd_req(srv_dm_lawmo_lock_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rmmi_lock_at_cmd_req_struct *rmmi_lock_at_cmd_req_struct_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rmmi_lock_at_cmd_req_struct_ptr = OslAllocDataPtr(rmmi_lock_at_cmd_req_struct);
    if (cmd == SRV_DM_LAWMO_LOCK_CMD_LOCK)
    {
        rmmi_lock_at_cmd_req_struct_ptr->lock = KAL_TRUE;
    }
    else
    {
        rmmi_lock_at_cmd_req_struct_ptr->lock = KAL_FALSE;
    }

    mmi_frm_send_ilm(
        MOD_ATCI,
        MSG_ID_RMMI_LOCK_AT_CMD_REQ,
        (oslParaType*)rmmi_lock_at_cmd_req_struct_ptr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_send_req_ind
 * DESCRIPTION
 *  function to send the lawmo cmd message, also as the callback function to register the lawmo command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_lawmo_send_req_ind(dm_lawmo_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_lawmo_result_struct *lawmo_cmd_rsp_struct_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lawmo_cmd_rsp_struct_ptr = OslAllocDataPtr(dm_lawmo_result_struct);
    lawmo_cmd_rsp_struct_ptr->result = result;
    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_LAWMO_RSP,
        (oslParaType*)lawmo_cmd_rsp_struct_ptr,
        NULL);
}


mmi_ret srv_dm_lawmo_internal_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct *lawmo_wipe_ind = (srv_dm_lawmo_wipe_ind_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lawmo_wipe_ind->cmd)
    {
        case SRV_DM_LAWMO_WIPE_CMD_START:
            g_srv_dm_lawmo_cntx_ptr->wipe_status = SRV_DM_LAWMO_WIPE_STATUS_FMGR_FORMAT;
            srv_dm_lawmo_wipe_send_evt(SRV_DM_LAWMO_WIPE_CMD_FMGR_FORMAT);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_get_cmd
 * DESCRIPTION
 *  function to change the command from DM to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_lawmo_get_cmd(dm_lawmo_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_dm_lawmo_cntx_ptr->lock_cmd = SRV_DM_LAWMO_LOCK_CMD_NONE;
    g_srv_dm_lawmo_cntx_ptr->wipe_cmd = SRV_DM_LAWMO_WIPE_CMD_NONE;
    switch (cmd)
    {
        case DM_LAWMO_CMD_FULL_LOCK:
            g_srv_dm_lawmo_cntx_ptr->lock_cmd = SRV_DM_LAWMO_LOCK_CMD_LOCK;
            break;

        case DM_LAWMO_CMD_PART_LOCK:
            g_srv_dm_lawmo_cntx_ptr->lock_cmd = SRV_DM_LAWMO_LOCK_CMD_LOCK;
            break;

        case DM_LAWMO_CMD_UNLOCK:
            g_srv_dm_lawmo_cntx_ptr->lock_cmd = SRV_DM_LAWMO_LOCK_CMD_UNLOCK;
            break;

        case DM_LAWMO_CMD_FATORY_RESET:
            g_srv_dm_lawmo_cntx_ptr->wipe_cmd = SRV_DM_LAWMO_WIPE_CMD_START;
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_is_phone_lock
 * DESCRIPTION
 *  function to check is the phone locked
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE:   phone locked
 *  FALSE:  phone unlocked
 *****************************************************************************/
MMI_BOOL srv_dm_lawmo_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // MMI not init
    if (srv_dm_init_get_status() == SRV_DM_INIT_STATUS_IDLE ||
        srv_bootup_is_launched() == MMI_FALSE)
    {
        nvram_ef_dm_app_lawmo_info_struct lawmo_info;
        S16 error;
        ReadRecord(
            NVRAM_EF_DM_APP_LAWMO_INFO_LID,
            1,
            &lawmo_info,
            sizeof(nvram_ef_dm_app_lawmo_info_struct),
            &error);
        ret = lawmo_info.is_locked;
    }
    else
    {
        if (g_srv_dm_lawmo_cntx_ptr->lock_status == SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK)
        {
            ret = MMI_TRUE;
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_LAWMO_IS_LOCK, ret);
    return ret;
}


MMI_BOOL srv_dm_lawmo_is_wiping(void)
{
    if (g_srv_dm_lawmo_cntx_ptr->wipe_status != SRV_DM_LAWMO_WIPE_STATUS_NONE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void srv_dm_lawmo_save_lock_status_to_nvram(MMI_BOOL is_locked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_lawmo_info_struct lawmo_info;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_LAWMO_SAVE_LOCK_STATUS_TO_NVRAM,
        is_locked);
    ReadRecord(
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        1,
        &lawmo_info,
        sizeof(nvram_ef_dm_app_lawmo_info_struct),
        &error);
    lawmo_info.is_locked = is_locked;
    WriteRecord(
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        1,
        &lawmo_info,
        sizeof(nvram_ef_dm_app_lawmo_info_struct),
        &error);

    g_srv_dm_lawmo_cntx_ptr->lock_status =
        is_locked ? SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK : SRV_DM_LAWMO_LOCK_STATUS_NONE;
}


MMI_BOOL srv_dm_lawmo_get_lock_status_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_lawmo_info_struct lawmo_info;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        1,
        &lawmo_info,
        sizeof(nvram_ef_dm_app_lawmo_info_struct),
        &error);
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_LAWMO_GET_LOCK_STATUS_FROM_NVRAM,
        lawmo_info.is_locked);
    g_srv_dm_lawmo_cntx_ptr->lock_status = 
        lawmo_info.is_locked ? SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK : SRV_DM_LAWMO_LOCK_STATUS_NONE;
    return lawmo_info.is_locked;
}


void srv_dm_lawmo_save_wipe_status_to_nvram(MMI_BOOL is_wipping)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_lawmo_info_struct lawmo_info;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_LAWMO_SAVE_WIPE_STATUS_TO_NVRAM,
        is_wipping);
    ReadRecord(
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        1,
        &lawmo_info,
        sizeof(nvram_ef_dm_app_lawmo_info_struct),
        &error);
    lawmo_info.is_wipping = is_wipping;
    WriteRecord(
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        1,
        &lawmo_info,
        sizeof(nvram_ef_dm_app_lawmo_info_struct),
        &error);
}


MMI_BOOL srv_dm_lawmo_get_wipe_status_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_lawmo_info_struct lawmo_info;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        1,
        &lawmo_info,
        sizeof(nvram_ef_dm_app_lawmo_info_struct),
        &error);
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_LAWMO_GET_WIPE_STATUS_FROM_NVRAM,
        lawmo_info.is_wipping);
    return lawmo_info.is_wipping;
}


void srv_dm_lawmo_exe_lock_cmd(srv_dm_lawmo_lock_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_LAWMO_EXE_LOCK_CMD,
        cmd);
    if (cmd == SRV_DM_LAWMO_LOCK_CMD_LOCK)
    {
        g_srv_dm_lawmo_cntx_ptr->lock_cmd = SRV_DM_LAWMO_LOCK_CMD_LOCK;
        srv_dm_lawmo_req_ind_hdlr(NULL);
    }
}


void srv_dm_lawmo_exe_wipe_cmd(srv_dm_lawmo_wipe_cmd_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_LAWMO_EXE_WIPE_CMD,
        cmd);
    if (cmd == SRV_DM_LAWMO_WIPE_CMD_START)
    {
        g_srv_dm_lawmo_cntx_ptr->wipe_cmd = SRV_DM_LAWMO_WIPE_CMD_START;
        srv_dm_lawmo_req_ind_hdlr(NULL);
    }
}

#endif /* __DM_LAWMO_SUPPORT__ */


/*below code used to compile with app that not update code*/
//#if 0
/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_register_notify
 * DESCRIPTION
 *  app register the LAWMO callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_dmui_result_enum mmi_dmui_lawmo_register_notify(
                        mmi_dmui_app_id_enum app_id,
                        mmi_dmui_mo_type_enum mo_type,
                        mmi_dmui_lawmo_cb lawmo_callback)
{
    return MMI_DMUI_RESULT_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_report
 * DESCRIPTION
 *  function for app to report the LAWMO result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_report(
        mmi_dmui_app_id_enum app_id,
        mmi_dmui_cmd_enum cmd,
        mmi_dmui_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_is_phone_lock
 * DESCRIPTION
 *  function to check is the phone locked
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE:   phone locked
 *  FALSE:  phone unlocked
 *****************************************************************************/
kal_int8 mmi_dmui_is_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_int8)(srv_dm_lawmo_is_locked() || srv_dm_lawmo_is_wiping());
}

mmi_dmui_status_enum mmi_dmui_get_status(mmi_dmui_mo_type_enum mo_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_dmui_status_enum)0;
}

//#endif
//#endif /* __DM_MO_SUPPORT__ */
