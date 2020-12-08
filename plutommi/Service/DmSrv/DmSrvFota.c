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
 *  DmSrvFota.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service FOTA manager.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __DM_FOTA_SUPPORT__
/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_include.h"
#include "MMIDataType.h"
#include "DmSrvIprot.h"
#include "DmSrvMain.h"
#include "DmSrvFota.h"
#include "Mmi_rp_srv_dm_def.h"
#include "Fota_gprot.h"
#include "DmPsUpdateAgentInterface.h"
#include "UcmSrvGprot.h"
#include "AlarmSrvGprot.h"
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static srv_dm_fota_cntx_struct fota_cntx;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void srv_dm_fota_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_dm_fota_update_req_ind_hdlr, MSG_ID_DM_UPDATE_REQ_IND);
    SetProtocolEventHandler(srv_dm_fota_reset_ind_hdlr, MSG_ID_DM_RESET_IND);
    SetProtocolEventHandler(srv_dm_fota_query_user_init_fota_rsp_hdlr, MSG_ID_DM_USER_INIT_FOTA_RSP);
}


void srv_dm_fota_set_status(srv_dm_fota_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_FOTA_SET_STATUS, status);
    fota_cntx.status = status;
}


srv_dm_fota_status_enum srv_dm_fota_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return fota_cntx.status;
}


void srv_dm_fota_bootup_check_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    U8 fota_update_flag;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(
        NVRAM_DM_FOTA_UPDATE_FLAG,
        &fota_update_flag,
        DS_BYTE,
        &error);
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_FOTA_BOOTUP_CHECK_UPDATE, fota_update_flag);

    if (fota_update_flag == 1)
    {
        if (FOTA_InitializeUpdateRecord() >= 0)
        {
            FOTA_update_result result = FOTA_Inform_Update_State();
            srv_dm_app_adp_evt_fota_update_result_struct fota_update_evt;

            if (result == TDL_UPDATE_SUCCESSFUL)
            {
                fota_update_evt.result = MMI_TRUE;
                srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_FOTA_UPDATE_RESULT, (void*)&fota_update_evt);
            }
            else if (result == TDL_UPDATE_FAIL)
            {
                fota_update_evt.result = MMI_FALSE;
                srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_FOTA_UPDATE_RESULT, (void*)&fota_update_evt);
            }
        }

        fota_update_flag = 0;
        WriteValue(
            NVRAM_DM_FOTA_UPDATE_FLAG,
            &fota_update_flag,
            DS_BYTE,
            &error);
    }
#endif /* __MTK_TARGET__ */
}


void srv_dm_fota_update_req_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_fota_update_ind_struct *update_ind = (dm_fota_update_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_FOTA_UPDATE_REQ_IND_HDLR);
    // ignore the notification ui mode
    fota_cntx.ui_mode = DM_UI_MODE_USERINTERACTION;
    srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_UPDATE_WAIT_CNF);

    switch (fota_cntx.ui_mode)
    {
        case DM_UI_MODE_BACKGROUND: /* not response to DM PS */
        {
            srv_dm_fota_send_update_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
            break;
        }

        case DM_UI_MODE_INFORMATION:    /* display pop up screen */
        {
            srv_dm_fota_send_update_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
            srv_dm_fota_send_app_update_evt();
            break;
        }

        case DM_UI_MODE_USERINTERACTION:    /* display confirm screen */
        {
            srv_dm_fota_send_app_update_evt();
            break;
        }

        default:
            break;
    }
}


void srv_dm_fota_send_update_rsp(dm_ui_interaction_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_fota_update_rsp_struct *update_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_UPDATE_CNF);
    update_rsp = OslAllocDataPtr(dm_fota_update_rsp_struct);
    update_rsp->ui_interaction = result;
    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_UPDATE_RES,
        (oslParaType*)update_rsp,
        NULL);
}


void srv_dm_fota_send_app_update_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_fota_display_update_struct update_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_ucm_is_any_call()) // user may press confirm by mistake
    {
        srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_UPDATE_DEFER);
        srv_dm_defer_user_interaction(
            SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE,
            SRV_DM_TIME_USER_INTERACTION_DEFER);
    }
    else
    {
        if (fota_cntx.ui_mode == DM_UI_MODE_USERINTERACTION)
        {
            srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_UPDATE_WAIT_CNF);
        }
        
        update_evt.ui_mode = fota_cntx.ui_mode;
        
        srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE, (void*)&update_evt);
    }
}


void srv_dm_fota_update_app_rsp(dm_ui_interaction_enum result, U32 defer_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_FOTA_UPDATE_APP_RSP, result, defer_time);
    switch (result)
    {
        case DM_UI_INTERACTION_ACTION_ACCEPT:
        {
            srv_dm_fota_send_update_rsp(result);
            break;
        }

        case DM_UI_INTERACTION_ACTION_DEFER:
        {
            srv_dm_defer_user_interaction(
                SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE,
                defer_time);

            srv_dm_fota_send_update_rsp(result);
            srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_UPDATE_DEFER);
            break;
        }

        default:
            break;
    }
}


void srv_dm_fota_resume_update_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_cancel_defer_user_interaction();
    srv_dm_fota_send_app_update_evt();
}


void srv_dm_fota_reset_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_reset_ind_struct *reset_ind = (dm_reset_ind_struct*)msg;
    S16 error;
    U8 fota_update_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_FOTA_RESET_IND_HDLR, reset_ind->result);
    if (reset_ind->result)
    {
        fota_update_flag = 1;
        WriteValue(
            NVRAM_DM_FOTA_UPDATE_FLAG,
            &fota_update_flag,
            DS_BYTE,
            &error);
        srv_alm_pwr_reset(MMI_FALSE, 3);
    }
    else
    {
        srv_dm_send_app_display_nmgr_popup_evt(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_ID_DMUI_NOTIF_REBOOT_FAIL));
    }
}


void srv_dm_fota_query_update(srv_dm_fota_query_cb_func_type cb, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_fota_status_enum status = srv_dm_fota_get_status();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fota_cntx.query_cb = cb;
    fota_cntx.query_user_data = user_data;

    if (srv_dm_init_get_status() != SRV_DM_INIT_STATUS_SRV_INIT_FINISH)
    {
        srv_dm_fota_query_report_app(SRV_DM_FOTA_QUERY_RESULT_NOT_READY);
        return;
    }

    if (status != SRV_DM_FOTA_STATUS_IDLE)
    {
        srv_dm_fota_query_report_app(SRV_DM_FOTA_QUERY_RESULT_ON_OPERATING);
        if (status == SRV_DM_FOTA_STATUS_UPDATE_DEFER)
        {
            srv_dm_fota_resume_update_notify();
        }
        return;
    }
    srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_USER_QUERY);
    srv_dm_fota_query_send_user_init_fota_req();
}


void srv_dm_fota_query_send_user_init_fota_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(MOD_DM, MSG_ID_DM_USER_INIT_FOTA_REQ, NULL, NULL);
}


void srv_dm_fota_query_user_init_fota_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_user_fota_update_rsp_struct *rsp = (dm_user_fota_update_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!rsp->result)
    {
        srv_dm_fota_query_finish(SRV_DM_FOTA_QUERY_RESULT_FAIL);
    }
}


void srv_dm_fota_query_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dm_fota_get_status() != SRV_DM_FOTA_STATUS_IDLE)
    {
        mmi_frm_send_ilm(MOD_DM, MSG_ID_DM_CANCEL_REQ, NULL, NULL);
    }
    srv_dm_fota_query_finish(SRV_DM_FOTA_QUERY_RESULT_CANCEL);
}


void srv_dm_fota_query_report_app(srv_dm_fota_query_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fota_cntx.query_cb != NULL)
    {
        (*fota_cntx.query_cb)(
            result,
            fota_cntx.query_user_data);
    }
    fota_cntx.query_cb = NULL;
    fota_cntx.query_user_data = NULL;
}


void srv_dm_fota_query_finish(srv_dm_fota_query_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result != SRV_DM_FOTA_QUERY_RESULT_CANCEL)
    {
        srv_dm_fota_query_report_app(result);
    }
    srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_IDLE);
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


#define DM_FOTA_UT
void ut_srv_dm_dl_send_update_ind(void)
{
    dm_fota_update_ind_struct *ptr;
    ptr = OslAllocDataPtr(dm_fota_update_ind_struct);
    ptr->ui_mode = DM_UI_MODE_NOTSPECIFIED;
    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_DM_UPDATE_REQ_IND,
        (oslParaType*)ptr,
        NULL);
}

#endif /* __DM_FOTA_SUPPORT__ */
