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
 *  DmSrvScomo.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service scomo.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#ifdef __DM_SCOMO_SUPPORT__
#include "mmi_include.h"
#include "mmi_conn_app_trc.h"
#include "DmSrvLawmo.h"
#include "DmSrvMain.h"
#include "DmSrvScomo.h"
#include "Common_nvram_editor_data_item.h"
#include "Nvram_common_defs.h"

/****************************************************************************
 * Global Variable
 ****************************************************************************/
static srv_dm_scomo_context_struct g_srv_dm_scomo_cntx;

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static MMI_BOOL g_dmui_scomo_waiting_ps_rsp_operate_by_user;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void srv_dm_scomo_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_dm_scomo_install_by_srv_ind_hdlr, MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_IND);
    SetProtocolEventHandler(srv_dm_scomo_remove_by_srv_ind_hdlr, MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_IND);
    SetProtocolEventHandler(srv_dm_scomo_install_by_user_rsp_hdlr, MSG_ID_DM_SCOMO_INSTALL_BY_USER_RSP);
    SetProtocolEventHandler(srv_dm_scomo_remove_by_user_rsp_hdlr, MSG_ID_DM_SCOMO_REMOVE_BY_USER_RSP);
}

void srv_dm_scomo_reset_report_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_scomo_report_info_struct dm_app_scomo_report_info;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(
        &dm_app_scomo_report_info,
        0x00,
        sizeof(nvram_ef_dm_app_scomo_report_info_struct));
    WriteRecord(
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        1,
        &dm_app_scomo_report_info,
        sizeof(nvram_ef_dm_app_scomo_report_info_struct),
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_install_by_srv_ind_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_install_by_srv_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_scomo_report_info_struct nvram_dm_app_scomo_report_info;
    srv_dm_scomo_java_cmd_info_struct        scomo_dm_cmd_info;
    dm_scomo_install_by_server_ind_struct   *install_by_srv_ind_struct_ptr;
    dm_scomo_install_by_server_cnf_struct   *install_by_srv_cnf_struct_ptr;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SCOMO_INSTALL_BY_SERVER_IND);
    if (srv_dm_check_restore_factory() == MMI_TRUE)
    {
        return;
    }

    ReadRecord(
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        1,
        &nvram_dm_app_scomo_report_info,
        sizeof(nvram_ef_dm_app_scomo_report_info_struct),
        &error);

    if (nvram_dm_app_scomo_report_info.is_info_valid)
    {
        install_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_server_cnf_struct);
        memcpy(install_by_srv_cnf_struct_ptr->id,        nvram_dm_app_scomo_report_info.dm_software_id,     DM_SCOMO_MAX_ID);
        memcpy(install_by_srv_cnf_struct_ptr->gen_id,    nvram_dm_app_scomo_report_info.app_software_id,    DM_SCOMO_MAX_ID);
        memcpy(install_by_srv_cnf_struct_ptr->name,      nvram_dm_app_scomo_report_info.software_name,      DM_SCOMO_MAX_NAME * 2);
        memcpy(install_by_srv_cnf_struct_ptr->version,   nvram_dm_app_scomo_report_info.software_version,   DM_SCOMO_MAX_NAME);
        install_by_srv_cnf_struct_ptr->result = (dm_scomo_error_code_enum)nvram_dm_app_scomo_report_info.result;
        mmi_frm_send_ilm(
            MOD_DM,
            MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_CNF,
            (oslParaType*)install_by_srv_cnf_struct_ptr,
            NULL);
    }
    else
    {
        install_by_srv_ind_struct_ptr = (dm_scomo_install_by_server_ind_struct*)msg;
        g_srv_dm_scomo_cntx.scomo_cmd = srv_dm_scomo_get_cmd(install_by_srv_ind_struct_ptr->command);
        //g_srv_dm_scomo_cntx.mo_type = srv_dm_get_mo_type(g_srv_dm_scomo_cntx.mo_cmd);
        srv_dm_scomo_change_status_on_command();
        memcpy(scomo_dm_cmd_info.dm_software_id,    install_by_srv_ind_struct_ptr->id,          DM_SCOMO_MAX_ID);
        memset(scomo_dm_cmd_info.app_software_id,   0,                                          DM_SCOMO_MAX_ID);
        memcpy(scomo_dm_cmd_info.pkg_install_path,  install_by_srv_ind_struct_ptr->file_name,   DM_SCOMO_MAX_FILE_NAME * 2);
        memcpy(scomo_dm_cmd_info.pkg_network_url,   install_by_srv_ind_struct_ptr->install_url, DM_SCOMO_MAX_URL);
        if (srv_dm_lawmo_is_locked() ||
            g_srv_dm_scomo_cntx.callback == NULL)
        {
            /* When locked, reject SCOMO command */
            install_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_server_cnf_struct);
            memcpy(install_by_srv_cnf_struct_ptr->id, install_by_srv_ind_struct_ptr->id, DM_SCOMO_MAX_ID);
            if (g_srv_dm_scomo_cntx.callback == NULL)
            {
                install_by_srv_cnf_struct_ptr->result = DM_SCOMO_CLIENT_ERROR;
            }
            else
            {
                install_by_srv_cnf_struct_ptr->result = DM_SCOMO_OPERATION_REJECT;
            }
            mmi_frm_send_ilm(
                MOD_DM,
                MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_CNF,
                (oslParaType*)install_by_srv_cnf_struct_ptr,
                NULL);
            return;
        }
        else if (install_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_NOTSPECIFIED ||
                 install_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_USERINTERACTION)
        {
            scomo_dm_cmd_info.display_mode = SRV_DM_SCOMO_DISPLAY_MODE_CONFIRM;
        }
        else if (install_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_INFORMATION)
        {
            scomo_dm_cmd_info.display_mode = SRV_DM_SCOMO_DISPLAY_MODE_INFO;
        }
        else
        {
            scomo_dm_cmd_info.display_mode = SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND;
        }

        (*(srv_dm_scomo_cmd_notify_cb)g_srv_dm_scomo_cntx.callback)(
            g_srv_dm_scomo_cntx.scomo_cmd,
            &scomo_dm_cmd_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_remove_by_srv_ind_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_remove_by_srv_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_scomo_report_info_struct    nvram_dm_app_scomo_report_info;
    srv_dm_scomo_java_cmd_info_struct           scomo_dm_cmd_info;
    dm_scomo_remove_by_server_ind_struct        *remove_by_srv_ind_struct_ptr;
    dm_scomo_remove_by_server_cnf_struct        *remove_by_srv_cnf_struct_ptr;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SCOMO_REMOVE_BY_SERVER_IND);
    if (srv_dm_check_restore_factory() == MMI_TRUE)
    {
        return;
    }

    ReadRecord(
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        1,
        &nvram_dm_app_scomo_report_info,
        sizeof(nvram_ef_dm_app_scomo_report_info_struct),
        &error);

    if (nvram_dm_app_scomo_report_info.is_info_valid)
    {
        remove_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_server_cnf_struct);
        memcpy(remove_by_srv_cnf_struct_ptr->gen_id,    nvram_dm_app_scomo_report_info.app_software_id,    DM_SCOMO_MAX_ID);
        remove_by_srv_cnf_struct_ptr->result = (dm_scomo_error_code_enum)nvram_dm_app_scomo_report_info.result;
        mmi_frm_send_ilm(
            MOD_DM,
            MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_CNF,
            (oslParaType*)remove_by_srv_cnf_struct_ptr,
            NULL);
    }
    else
    {
        remove_by_srv_ind_struct_ptr = (dm_scomo_remove_by_server_ind_struct*)msg;
        g_srv_dm_scomo_cntx.scomo_cmd = srv_dm_scomo_get_cmd(remove_by_srv_ind_struct_ptr->command);
        //g_srv_dm_scomo_cntx.mo_type = srv_dm_get_mo_type(g_srv_dm_scomo_cntx.mo_cmd);
        srv_dm_scomo_change_status_on_command();
        memset(scomo_dm_cmd_info.dm_software_id,    0,                                      DM_SCOMO_MAX_ID);
        memcpy(scomo_dm_cmd_info.app_software_id,   remove_by_srv_ind_struct_ptr->gen_id,   DM_SCOMO_MAX_ID);
        memset(scomo_dm_cmd_info.pkg_install_path,  0,                                      DM_SCOMO_MAX_FILE_NAME * 2);
        memset(scomo_dm_cmd_info.pkg_network_url,   0,                                      DM_SCOMO_MAX_URL);

        if (g_srv_dm_scomo_cntx.callback == NULL)
        {
            remove_by_srv_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_server_cnf_struct);
            remove_by_srv_cnf_struct_ptr->result = DM_SCOMO_CLIENT_ERROR;

            mmi_frm_send_ilm(
                MOD_DM,
                MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_CNF,
                (oslParaType*)remove_by_srv_cnf_struct_ptr,
                NULL);
            return;
        }
        else if (srv_dm_lawmo_is_locked())
        {
            scomo_dm_cmd_info.display_mode = SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND;
        }
        else if (remove_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_NOTSPECIFIED ||
            remove_by_srv_ind_struct_ptr->ui_mode == DM_UI_MODE_USERINTERACTION)
        {
            scomo_dm_cmd_info.display_mode = SRV_DM_SCOMO_DISPLAY_MODE_CONFIRM;
        }
        else
        {
            scomo_dm_cmd_info.display_mode = SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND;
        }

        (*(srv_dm_scomo_cmd_notify_cb)g_srv_dm_scomo_cntx.callback)(
            g_srv_dm_scomo_cntx.scomo_cmd,
            &scomo_dm_cmd_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_install_by_user_rsp_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_INSTALL_BY_USER_RSP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_install_by_user_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dmui_scomo_waiting_ps_rsp_operate_by_user = MMI_FALSE;
    srv_dm_scomo_handle_unfinished_report();
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_remove_by_user_rsp_hdlr
 * DESCRIPTION
 *  function to handle the MSG_ID_DM_SCOMO_REMOVE_BY_USER_RSP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_remove_by_user_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dmui_scomo_waiting_ps_rsp_operate_by_user = MMI_FALSE;
    srv_dm_scomo_handle_unfinished_report();
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_register_notify
 * DESCRIPTION
 *  app register the SCOMO callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_dm_scomo_result_enum srv_dm_scomo_register_notify(srv_dm_scomo_cmd_notify_cb scomo_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(scomo_callback);
    g_srv_dm_scomo_cntx.callback = (void*)scomo_callback;

    return SRV_DM_SCOMO_RESULT_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_switch_error_code
 * DESCRIPTION
 *  function to switch the error code from app to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
dm_scomo_error_code_enum srv_dm_scomo_switch_error_code(srv_dm_scomo_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case SRV_DM_SCOMO_RESULT_SUCCESS:
             return DM_SCOMO_SUCCESSFUL;
             
        case SRV_DM_SCOMO_RESULT_FAILURE:
            return DM_SCOMO_CLIENT_ERROR;

        case SRV_DM_SCOMO_RESULT_USER_CANCEL:
            return DM_SCOMO_USER_CANCEL;
        
        case SRV_DM_SCOMO_RESULT_DOWNLOAD_FAIL:
            return DM_SCOMO_DOWNLOAD_PACKET_FAIL;

        case SRV_DM_SCOMO_RESULT_AUTH_FAIL:
            return DM_SCOMO_AUTH_FAIL;

        case SRV_DM_SCOMO_RESULT_DOWNLOAD_OUT_MEMORY:
            return DM_SCOMO_DOWNLOAD_OUT_MEMORY;

        case SRV_DM_SCOMO_RESULT_INSTALL_FAIL:
            return DM_SCOMO_INSTALL_FAIL;
                
        case SRV_DM_SCOMO_RESULT_INSTALL_OUT_MEMORY:
            return DM_SCOMO_INSTALL_OUT_MEOMORY;
                
        case SRV_DM_SCOMO_RESULT_PACKAGE_INVALID:
            return DM_SCOMO_PACKAGE_INVALID;
                
        case SRV_DM_SCOMO_RESULT_REMOVE_FAIL:
            return DM_SCOMO_REMOVE_FAIL;
                
        case SRV_DM_SCOMO_RESULT_ACTIVE_FAIL:
            return DM_SCOMO_ACTIVE_FAIL;
                
        case SRV_DM_SCOMO_RESULT_DEACTIVE_FAIL:
            return DM_SCOMO_DEACTIVE_FAIL;
            
        case SRV_DM_SCOMO_RESULT_OPERATION_REJECT:
            return DM_SCOMO_OPERATION_REJECT;
            
        case SRV_DM_SCOMO_RESULT_DOWNLOAD_SERVER_ERROR:
            return DM_SCOMO_DOWNLOAD_SERVER_ERROR;

        default:
            MMI_ASSERT(0);
			return DM_SCOMO_CLIENT_ERROR;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_change_status_on_command
 * DESCRIPTION
 *  function to change the status before opreate command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_change_status_on_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_dm_scomo_cntx.scomo_cmd)
    {

        case SRV_DM_SCOMO_CMD_INSTALL:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_INSTALL;
            break;
            
        case SRV_DM_SCOMO_CMD_INSTALL_INACTIVE:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_INSTALL_INACTIVE;
            break;
            
        case SRV_DM_SCOMO_CMD_ACTIVATE:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_ACTIVATE;
            break;
            
        case SRV_DM_SCOMO_CMD_INACTIVATE:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_INACTIVATE;
            break;
            
        case SRV_DM_SCOMO_CMD_REMOVE:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_REMOVE;
            break;

        case SRV_DM_SCOMO_CMD_REMOVE_ALL:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_REMOVE_ALL;
            break;

        default:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_NONE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_change_status_after_command
 * DESCRIPTION
 *  function to change the status before opreate command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_change_status_after_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_dm_scomo_cntx.scomo_cmd)
    {
        case SRV_DM_SCOMO_CMD_INSTALL:
        case SRV_DM_SCOMO_CMD_INSTALL_INACTIVE:
        case SRV_DM_SCOMO_CMD_ACTIVATE:
        case SRV_DM_SCOMO_CMD_INACTIVATE:
        case SRV_DM_SCOMO_CMD_REMOVE:
        case SRV_DM_SCOMO_CMD_REMOVE_ALL:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_NONE;
            break;
            
        default:
            g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_NONE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_report
 * DESCRIPTION
 *  function for app to report the SCOMO result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_report(
        srv_dm_scomo_cmd_enum cmd,
        srv_dm_scomo_result_enum result,
        srv_dm_scomo_java_report_info_struct *scomo_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_app_scomo_report_info_struct    *dm_app_scomo_report_info;
    dm_scomo_install_by_server_cnf_struct       *install_by_server_cnf_struct_ptr;
    dm_scomo_remove_by_server_cnf_struct        *remove_by_server_cnf_struct_ptr;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*scomo_info->dm_software_id != 0) /* dm server command */
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SCOMO_REPORT_SERVER_CMD);

        /* send message */
        dm_app_scomo_report_info = (nvram_ef_dm_app_scomo_report_info_struct*)OslMalloc(sizeof(nvram_ef_dm_app_scomo_report_info_struct));
        dm_app_scomo_report_info->is_info_valid = 1;
        dm_app_scomo_report_info->command = cmd;
        dm_app_scomo_report_info->result = result;
        memcpy(dm_app_scomo_report_info->dm_software_id,    scomo_info->dm_software_id,     DM_MAX_ID_LEN);
        memcpy(dm_app_scomo_report_info->app_software_id,   scomo_info->app_software_id,    DM_MAX_ID_LEN);
        memcpy(dm_app_scomo_report_info->software_name,     scomo_info->software_name,      DM_MAX_NAME_LEN * 2);
        memcpy(dm_app_scomo_report_info->software_version,  scomo_info->software_version,   DM_MAX_NAME_LEN);
        if (cmd == SRV_DM_SCOMO_CMD_INSTALL || cmd == SRV_DM_SCOMO_CMD_INSTALL_INACTIVE)
        {
            install_by_server_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_server_cnf_struct);
            memcpy(install_by_server_cnf_struct_ptr->id,        scomo_info->dm_software_id,     DM_SCOMO_MAX_ID);
            memcpy(install_by_server_cnf_struct_ptr->gen_id,    scomo_info->app_software_id,    DM_SCOMO_MAX_ID);
            memcpy(install_by_server_cnf_struct_ptr->name,      scomo_info->software_name,      DM_SCOMO_MAX_NAME * 2);
            memcpy(install_by_server_cnf_struct_ptr->version,   scomo_info->software_version,   DM_SCOMO_MAX_NAME);
            install_by_server_cnf_struct_ptr->result = srv_dm_scomo_switch_error_code(result);
            mmi_frm_send_ilm(
                MOD_DM,
                MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_CNF,
                (oslParaType*)install_by_server_cnf_struct_ptr,
                NULL);
        }
        else if (cmd == SRV_DM_SCOMO_CMD_REMOVE)
        {
            remove_by_server_cnf_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_server_cnf_struct);
            memcpy(remove_by_server_cnf_struct_ptr->gen_id,    scomo_info->app_software_id,    DM_SCOMO_MAX_ID);
            remove_by_server_cnf_struct_ptr->result = srv_dm_scomo_switch_error_code(result);
            mmi_frm_send_ilm(
                MOD_DM,
                MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_CNF,
                (oslParaType*)remove_by_server_cnf_struct_ptr,
                NULL);
        }

        WriteRecord(
            NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
            1,
            dm_app_scomo_report_info,
            sizeof(nvram_ef_dm_app_scomo_report_info_struct),
            &error);
        OslMfree(dm_app_scomo_report_info);

        g_srv_dm_scomo_cntx.scomo_status = SRV_DM_SCOMO_STATUS_NONE;
        g_srv_dm_scomo_cntx.scomo_cmd = SRV_DM_SCOMO_CMD_NONE;
    }
    else /* user operation */
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SCOMO_REPORT_APP_CMD);
        srv_dm_scomo_app_operate_notify(
            cmd,
            scomo_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_app_operate_notify
 * DESCRIPTION
 *  function for app to notiry the operation by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_app_operate_notify(
                srv_dm_scomo_cmd_enum cmd,
                srv_dm_scomo_java_report_info_struct *scomo_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_scomo_app_report_save_file_info_struct *app_cmd_save_file_info;
    FS_HANDLE fh_scomo_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh_scomo_info = FS_Open(DM_SCOMO_APP_CMD_INFO_FILE_NAME, FS_READ_WRITE | FS_CREATE);
    if (fh_scomo_info < 0)
    {
        FS_Delete(DM_SCOMO_APP_CMD_INFO_FILE_NAME);
        return;
    }

    FS_Seek(fh_scomo_info, 0, FS_FILE_END);

    app_cmd_save_file_info = (srv_dm_scomo_app_report_save_file_info_struct*)OslMalloc(sizeof(srv_dm_scomo_app_report_save_file_info_struct));
    memcpy(
        &app_cmd_save_file_info->app_cmd_info,
        scomo_info,
        sizeof(srv_dm_scomo_java_report_info_struct));
    app_cmd_save_file_info->cmd = cmd;
    
    FS_Write(
        fh_scomo_info,
        app_cmd_save_file_info,
        sizeof(srv_dm_scomo_app_report_save_file_info_struct),
        NULL);
    FS_Close(fh_scomo_info);
    OslMfree(app_cmd_save_file_info);

    if (g_dmui_scomo_waiting_ps_rsp_operate_by_user == MMI_FALSE)
    {
        srv_dm_scomo_handle_unfinished_report();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_handle_unfinished_report
 * DESCRIPTION
 *  function to handle report to DM PS that unfinished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_scomo_handle_unfinished_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_scomo_app_report_save_file_info_struct *app_cmd_save_file_info = NULL;
    dm_scomo_install_by_user_req_struct       *install_by_user_req_struct_ptr;
    dm_scomo_remove_by_user_req_struct        *remove_by_user_req_struct_ptr;
    U32 file_len;
    static U32 fs_read_index = 0;
    U32 fs_read_len;
    FS_HANDLE fh_scomo_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SCOMO_HANDLE_UNFINISHED_REPORT);
    fh_scomo_info = FS_Open(DM_SCOMO_APP_CMD_INFO_FILE_NAME, FS_READ_ONLY);

    if (fh_scomo_info < 0)
    {
        return;
    }

    if (FS_NO_ERROR == FS_GetFileSize(fh_scomo_info, &file_len))
    {
        if (file_len > 0)
        {
            /* read the file and send msg to DM PS */
            FS_Seek(
                fh_scomo_info,
                fs_read_index * sizeof(srv_dm_scomo_app_report_save_file_info_struct),
                FS_FILE_BEGIN);
            fs_read_index++;

            app_cmd_save_file_info = (srv_dm_scomo_app_report_save_file_info_struct*)OslMalloc(sizeof(srv_dm_scomo_app_report_save_file_info_struct));

            if (FS_NO_ERROR != FS_Read(
                                fh_scomo_info,
                                app_cmd_save_file_info,
                                sizeof(srv_dm_scomo_app_report_save_file_info_struct),
                                &fs_read_len))
            {
                goto fs_error;
            }

            if (fs_read_len < sizeof(srv_dm_scomo_app_report_save_file_info_struct))
            {
                goto fs_error;
            }

            FS_Close(fh_scomo_info);

            g_dmui_scomo_waiting_ps_rsp_operate_by_user = MMI_TRUE;

            /* send msg */
            if (app_cmd_save_file_info->cmd == SRV_DM_SCOMO_CMD_INSTALL ||
                app_cmd_save_file_info->cmd== SRV_DM_SCOMO_CMD_INSTALL_INACTIVE)
            {
                install_by_user_req_struct_ptr = OslAllocDataPtr(dm_scomo_install_by_user_req_struct);
                memcpy(install_by_user_req_struct_ptr->gen_id,    app_cmd_save_file_info->app_cmd_info.app_software_id,    DM_SCOMO_MAX_ID);
                memcpy(install_by_user_req_struct_ptr->name,      app_cmd_save_file_info->app_cmd_info.software_name,      DM_SCOMO_MAX_NAME * 2);
                memcpy(install_by_user_req_struct_ptr->version,   app_cmd_save_file_info->app_cmd_info.software_version,   DM_SCOMO_MAX_NAME);
                mmi_frm_send_ilm(
                    MOD_DM,
                    MSG_ID_DM_SCOMO_INSTALL_BY_USER_REQ,
                    (oslParaType*)install_by_user_req_struct_ptr,
                    NULL);
            }
            else if (app_cmd_save_file_info->cmd == SRV_DM_SCOMO_CMD_REMOVE ||
                     app_cmd_save_file_info->cmd == SRV_DM_SCOMO_CMD_REMOVE_ALL)
            {
                remove_by_user_req_struct_ptr = OslAllocDataPtr(dm_scomo_remove_by_user_req_struct);
                memcpy(remove_by_user_req_struct_ptr->gen_id,    app_cmd_save_file_info->app_cmd_info.app_software_id,    DM_SCOMO_MAX_ID);
                if (app_cmd_save_file_info->cmd == SRV_DM_SCOMO_CMD_REMOVE_ALL)
                {
                    remove_by_user_req_struct_ptr->delete_all = MMI_TRUE;
                }
                else
                {
                    remove_by_user_req_struct_ptr->delete_all = MMI_FALSE;
                }
                mmi_frm_send_ilm(
                    MOD_DM,
                    MSG_ID_DM_SCOMO_REMOVE_BY_USER_REQ,
                    (oslParaType*)remove_by_user_req_struct_ptr,
                    NULL);
            }

            if (app_cmd_save_file_info)
            {
                OslMfree(app_cmd_save_file_info);
            }
            return;
        }
        else
        {
            goto fs_error;
        }
    }
    else
    {
        goto fs_error;
    }
    return;

fs_error:
    fs_read_index = 0;
    FS_Close(fh_scomo_info);
    FS_Delete(DM_SCOMO_APP_CMD_INFO_FILE_NAME);
    if (app_cmd_save_file_info)
    {
        OslMfree(app_cmd_save_file_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_dm_scomo_get_cmd
 * DESCRIPTION
 *  function to change the command from DM to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_dm_scomo_cmd_enum srv_dm_scomo_get_cmd(dm_scomo_command_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_scomo_cmd_enum mo_cmd = SRV_DM_SCOMO_CMD_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cmd)
    {
        case DM_SCOMO_INSTALL_COMMAND:
            mo_cmd = SRV_DM_SCOMO_CMD_INSTALL;
            break;

        case DM_SCOMO_INSTALL_INACTIVE_COMMAND:
            mo_cmd = SRV_DM_SCOMO_CMD_INSTALL_INACTIVE;
            break;

        case DM_SCOMO_REMOVE_COMMAND:
            mo_cmd = SRV_DM_SCOMO_CMD_REMOVE;
            break;

        default:
            MMI_ASSERT(0);
    }
    
    return mo_cmd;
}

void mmi_dmui_scomo_report(
        mmi_dmui_app_id_enum app_id,
        mmi_dmui_cmd_enum cmd,
        mmi_dmui_result_enum result,
        mmi_dmui_scomo_app_report_info_struct *scomo_info)
{
    return;
}
                    
mmi_dmui_result_enum mmi_dmui_scomo_register_notify(
                       mmi_dmui_app_id_enum app_id,
                       mmi_dmui_mo_type_enum mo_type,
                       mmi_dmui_scomo_cb scomo_callback)
{
   return MMI_DMUI_RESULT_SUCCESS;
}
#endif /* __DM_SCOMO_SUPPORT__ */

