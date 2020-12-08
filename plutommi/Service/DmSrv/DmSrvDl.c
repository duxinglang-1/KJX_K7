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
 *  DmSrvDl.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service download manager.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef SYNCML_DM_SUPPORT

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_include.h"
#include "MMIDataType.h"
#include "DmSrvIprot.h"
#include "DmSrvMain.h"
#include "DmSrvDl.h"
#include "DmSrvAcc.h"
#include "mmi_rp_srv_dm_def.h"
#include "DLAgentSrvGprot.h"
#include "Wps_struct.h"
#include "dtcntsrvgprot.h"
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static srv_dm_dl_cntx_struct dl_cntx;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void srv_dm_dl_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_dm_dl_start_dl_ind_hdlr, MSG_ID_DM_START_DL_REQ_IND);
}


/*****************************************************************************
 * FUNCTION
 *  dm_receive_upc_file
 * DESCRIPTION
 *  receive the update package file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        Of file
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_dl_receive_upc_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_RECEIVE_UPC_FILE);
}


/*****************************************************************************
 * FUNCTION
 *  dm_da_fumo_setting
 * DESCRIPTION
 *  When the file is downloaded from WAP browser, we set it as oma download
 *  else, we save it to file system only.
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        
 *  mime_subtype            [IN]        
 *  action                  [IN]        
 *  filesize                [IN]        
 *  url                     [IN]        
 *  mime_type_string        [IN]        
 *  content_len             [IN]        
 *  content                 [IN]        
 *  setting                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_dl_da_fumo_setting(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        U32 filesize,
        S8 *url,
        S8 *mime_type_string,
        U32 content_len,
        S8 *content,
        srv_da_setting_struct *setting)
{
#define DM_UPC_FILE_NAME                    L"UpdatePackage"
#define DM_FOLDER_PATH                      L"@dm\\"
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_DA_FUMO_SETTING);

    if (action != MMI_DA_OMA_DOWNLOAD)
    {
        srv_da_default_setting(
            session_id,
            mime_type,
            mime_subtype,
            action,
            filesize,
            url,
            mime_type_string,
            content_len,
            content,
            setting);
        setting->do_dispatch = MMI_FALSE;
        return;
    }
    else
    {
        srv_da_bypass_setting(
            session_id,
            mime_type,
            mime_subtype,
            action,
            filesize,
            url,
            mime_type_string,
            content_len,
            content,
            setting);
    }

    setting->bypass = MMI_DA_BYPASS_LEVEL_2;
    setting->default_filename = MMI_FALSE;
    mmi_ucs2cpy((S8*) setting->filename, (const S8*)DM_UPC_FILE_NAME);

    setting->can_minimize = MMI_FALSE;
    mmi_ucs2cpy((S8*) setting->folder, (const S8*)DM_FOLDER_PATH);

    setting->filepath_hdlr = NULL;
    setting->percentage_bar = MMI_FALSE;
    setting->report_hdlr = srv_dm_dl_da_report_hdlr;

    setting->storage = SRV_DA_STORAGE_PHONE;
    setting->drv = SRV_FMGR_SYSTEM_DRV;

    setting->keepfile = MMI_FALSE;

    setting->confirm_dispatch = MMI_FALSE;
    setting->confirm_push = MMI_TRUE;
    setting->do_dispatch = MMI_TRUE;
}


void srv_dm_dl_set_status(srv_dm_dl_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_SET_STATUS, status);
    dl_cntx.status = status;
}


srv_dm_dl_status_enum srv_dm_dl_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dl_cntx.status;
}


void srv_dm_dl_start_dl_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_start_dl_res_ind_struct *start_dl = (dm_start_dl_res_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_START_DL_IND_HDLR);
    srv_dm_dl_set_status(SRV_DM_DL_STATUS_IDLE);
#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        srv_dm_dl_send_report_ind(DM_DOWNLOADING_USER_CANCEL);
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    dl_cntx.dl_ind_info = OslMalloc(sizeof(*dl_cntx.dl_ind_info));
    memcpy(dl_cntx.dl_ind_info, start_dl, sizeof(*dl_cntx.dl_ind_info));

    srv_dm_dl_send_app_dl_start_evt();
}


void srv_dm_dl_start_oma_dl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct wps_setting;
    MMI_BOOL show_cnf;
    srv_dtcnt_prof_proxy_info_struct proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_START_OMA_DL);
    /* setting wps */
    wps_setting.use_default = KAL_FALSE;
    if (dl_cntx.dl_ind_info->xpt_type == DM_XPT_TYPE_HTTP)
    {
        wps_setting.conn_type = WPS_CONN_TYPE_HTTP;
    }
    else
    {
        wps_setting.conn_type = WPS_CONN_TYPE_WSP_CO;
    }
    wps_setting.timeout = 30;
    wps_setting.net_id = srv_dm_acc_get_curr_used_dtcnt_id();
    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        wps_setting.net_id,
                        &proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY))
    {
        wps_setting.use_proxy = (kal_bool)proxy_info.use_proxy;
    }
    else
    {
        wps_setting.use_proxy = KAL_FALSE;
    }

    if (wps_setting.use_proxy == KAL_TRUE)
    {
        strncpy(wps_setting.prx_addr, proxy_info.px_addr, DM_MAX_PROXY_LEN + 1);
        wps_setting.prx_port = proxy_info.px_port;
        strncpy((char*)wps_setting.username, (char*)proxy_info.px_authid, WPS_MAX_USERNAME_LEN);
        strncpy((char*)wps_setting.password, (char*)proxy_info.px_authpw, WPS_MAX_PASSWORD_LEN);
    }

    srv_dm_dl_set_status(SRV_DM_DL_STATUS_DL_WAIT_CNF);
    show_cnf = (dl_cntx.dl_ind_info->b_resume == MMI_TRUE) ? MMI_FALSE : MMI_TRUE;
    srv_da_start_oma_download(
        (S8*)dl_cntx.dl_ind_info->ddfilename,
        (void*)&wps_setting,
        (BOOL)show_cnf,
        srv_dm_dl_start_oma_dl_cb_hdlr);
}


void srv_dm_dl_send_app_dl_start_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_dl_start_struct dl_start_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dl_start_evt.is_resume = dl_cntx.dl_ind_info->b_resume;
    dl_start_evt.auto_resume = dl_cntx.auto_resume;
    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_DL_START, (void*)&dl_start_evt);
}


void srv_dm_dl_start_app_rsp(dm_ui_interaction_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_START_APP_RSP, result);
    if (result == DM_UI_INTERACTION_ACTION_ACCEPT)
    {
        srv_dm_dl_start_oma_dl();
    }
    else if (result == DM_UI_INTERACTION_ACTION_CANCEL ||
             result == DM_UI_INTERACTION_ACTION_REJECT)
    {
        srv_dm_dl_send_report_ind(DM_DOWNLOADING_USER_CANCEL);
    }

    OslMfree(dl_cntx.dl_ind_info);
}


void srv_dm_dl_start_oma_dl_cb_hdlr(BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_START_OMA_DL_CB_HDLR, success);
    if (success == FALSE)
    {
        srv_dm_dl_send_report_ind(DM_DOWNLOADING_USER_CANCEL);
        srv_dm_dl_set_status(SRV_DM_DL_STATUS_IDLE);
    }
    else
    {
        srv_dm_dl_send_report_ind(DM_DOWNLOADING_UPDATE_PKG);
        srv_dm_dl_set_status(SRV_DM_DL_STATUS_DOWNLOADING);
    }
}


void srv_dm_dl_da_report_hdlr(
        S32 session_id,
        S32 status,
        S32 error,
        U32 seq_num,
        U32 acc_size,
        U32 total_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dl_progress_struct *dl_progress_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_DA_REPORT_HDLR, status, error);

    if ((status == SRV_DA_STATE_PAUSE ||
         status == SRV_DA_STATE_ABORT) &&
        srv_dm_check_nw_available() == MMI_FALSE)
    {
        srv_dm_dl_suspend();
        return;
    }

    switch (status)
    {
        case SRV_DA_STATE_INIT:
        {
            break;
        }

        case SRV_DA_STATE_PAUSE:
        case SRV_DA_STATE_ABORT:
        case SRV_DA_STATE_USER_CANCEL:
        case SRV_DA_STATE_COMPLETE:
        {
            srv_dm_dl_send_app_dl_finish_evt(status, error);
            break;
        }

        case SRV_DA_STATE_DOWNLOADING:
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_DA_DOWNLOADING_INFO, acc_size, total_size);
            dl_cntx.session_id = session_id;
            srv_dm_dl_send_app_dl_progress_evt(acc_size, total_size);
            break;
        }

        default:
            break;
    }
}


void srv_dm_dl_send_app_dl_progress_evt(U32 acc_size, U32 total_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_dl_progress_struct dl_progress_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_size > 0)
    {
        if (acc_size == total_size)
        {
            srv_dm_dl_set_status(SRV_DM_DL_STATUS_PKG_FINISH);
        }
        dl_cntx.percent = acc_size * 100 / total_size;
    }
    else
    {
        dl_cntx.percent = 0;
    }

    dl_progress_evt.acc_size = acc_size;
    dl_progress_evt.total_size = total_size;
    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_DL_PROGRESS, (void*)&dl_progress_evt);
}


void srv_dm_dl_progress_app_rsp(dm_dl_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_PROGRESS_APP_RSP, status);
    if (status == DM_DOWNLOADING_USER_CANCEL)
    {
        srv_dm_dl_send_report_ind(status);
        srv_da_stop_dl(dl_cntx.session_id);
        srv_dm_dl_set_status(SRV_DM_DL_STATUS_IDLE);
    }
}


void srv_dm_dl_send_app_dl_finish_evt(S32 status, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_dl_finish_struct dl_finish_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case SRV_DA_STATE_COMPLETE:
        {
            dl_finish_evt.cause = SRV_DM_APP_ADP_DL_FINISH;
            srv_dm_dl_set_status(SRV_DM_DL_STATUS_FINISH);
            srv_dm_dl_send_report_ind(DM_DOWNLOADED_UPDATE_PKG);
            break;
        }

        case SRV_DA_STATE_PAUSE:
        case SRV_DA_STATE_ABORT:
        {
            srv_dm_dl_set_status(SRV_DM_DL_STATUS_IDLE);

            if (error == SRV_DA_ERROR_DISK_FULL)
            {
                dl_finish_evt.cause = SRV_DM_APP_ADP_DL_NO_MEM;
            }
            else
            {
                dl_finish_evt.cause = SRV_DM_APP_ADP_DL_CANCEL;
            }
            srv_da_stop_dl(dl_cntx.session_id);
            srv_dm_dl_send_report_ind(DM_DOWNLOADING_FAILED);
            break;
        }

        case SRV_DA_STATE_USER_CANCEL:
        {
            dl_finish_evt.cause = SRV_DM_APP_ADP_DL_CANCEL;
            srv_dm_dl_set_status(SRV_DM_DL_STATUS_IDLE);
            srv_dm_dl_send_report_ind(DM_DOWNLOADING_USER_CANCEL);
            break;
        }

        default:
            break;
    }

    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_DL_FINISH, (void*)&dl_finish_evt);
}


MMI_BOOL srv_dm_dl_check_suspend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL nw_available = srv_dm_check_nw_available();
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nw_available == MMI_TRUE)
    {
        StopTimer(TIMER_ID_DM_SRV_DL_AUTO_RESUME);
        ret = MMI_FALSE;
    }
    else
    {
        if (srv_dm_dl_get_status() == SRV_DM_DL_STATUS_DOWNLOADING)
        {
            srv_da_remove_dl(dl_cntx.session_id);
        }
        ret = MMI_TRUE;
    }
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_CHECK_SUSPEND, ret);
}


void srv_dm_dl_suspend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_dl_finish_struct dl_finish_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_SUSPEND);
    srv_dm_dl_set_status(SRV_DM_DL_STATUS_SUSPEND);
    srv_dm_dl_send_report_ind(DM_DOWNLOADING_NETWORK_CLOSE);

    dl_cntx.auto_resume = MMI_TRUE;
    StartTimer(
        TIMER_ID_DM_SRV_DL_AUTO_RESUME,
        SRV_DM_TIME_DL_AUTO_RESUME,
        srv_dm_dl_auto_resume_timeout_hdlr);

    dl_finish_evt.cause = SRV_DM_APP_ADP_DL_NW_UNAVAIL;
    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_DL_FINISH, (void*)&dl_finish_evt);
}


void srv_dm_dl_auto_resume_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_AUTO_RESUME_TIMEOUT_HDLR);
    dl_cntx.auto_resume = MMI_FALSE;
}


void srv_dm_dl_send_report_ind(dm_dl_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_dl_report_struct *dl_report_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_SEND_REPORT_IND, status);
    dl_report_ptr = OslAllocDataPtr(dm_dl_report_struct);
    dl_report_ptr->status = status;

    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_DL_REPORT,
        (local_para_struct*)dl_report_ptr,
        NULL);
}


U32 srv_dm_dl_get_curr_percent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_DL_GET_CURR_PERCENT, dl_cntx.percent);
    return dl_cntx.percent;
}


void ut_srv_dm_dl_send_start_dl_ind(void)
{
    dm_ui_mode_struct *ptr;
    ptr = OslAllocDataPtr(dm_ui_mode_struct);
    ptr->ui_mode = DM_UI_MODE_USERINTERACTION;
    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_DM_NOTIFICATION_INIT_SESSION_REQ_IND,
        (oslParaType*)ptr,
        NULL);
}
#endif /* SYNCML_DM_SUPPORT */
