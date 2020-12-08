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
 *  DmSrvAcc.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service account manager
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
#ifdef SYNCML_DM_SUPPORT

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_include.h"
#include "MMIDataType.h"
#include "DmSrvAcc.h"
#include "cbm_api.h"
#include "DmSelfRegisterGprot.h"
#include "DmSrvMain.h"
#include "Custom_syncml_dm_config.h"
#include "DtcntSrvGprot.h"
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static srv_dm_acc_cntx_struct acc_cntx;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void srv_dm_acc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_dm_acc_get_acc_req_hdlr, MSG_ID_DM_GET_ACC_REQ);
    srv_dm_acc_check_default_acc_valid();
    acc_cntx.curr_used_record_index = 1;
}


void srv_dm_acc_get_acc_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct nvram_acc;
    dm_account_struct dm_acc;
    dm_get_acc_req_struct *get_acc_req = (dm_get_acc_req_struct*)msg;
    U8 record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_ACC_GET_ACC_REQ_HDLR,
        get_acc_req->server_id);
    if (srv_dm_acc_get_acc_by_server_id(&nvram_acc, &record_index, get_acc_req->server_id) == MMI_TRUE)
    {
        srv_dm_acc_convert_acc_mmi_to_ps(&dm_acc, &nvram_acc);
        acc_cntx.curr_used_record_index = record_index;
        srv_dm_acc_send_get_acc_cnf(&dm_acc);
    }
    else if (srv_dm_acc_get_default_acc(&nvram_acc) == MMI_TRUE)
    {
        srv_dm_acc_convert_acc_mmi_to_ps(&dm_acc, &nvram_acc);
        acc_cntx.curr_used_record_index = 1;
        srv_dm_acc_send_get_acc_cnf(&dm_acc);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


void srv_dm_acc_send_get_acc_cnf(dm_account_struct *acc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_get_acc_cnf_struct *cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf = OslAllocDataPtr(dm_get_acc_cnf_struct);
    //memcpy(&cnf->dm_account, acc, sizeof(dm_get_acc_cnf_struct));
    memcpy(&cnf->dm_account, acc, sizeof(dm_account_struct));
    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_GET_ACC_CNF,
        (oslParaType*)cnf,
        NULL);
}


void srv_dm_acc_save_acc_by_index(nvram_ef_dm_srv_acc_struct *acc, S32 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acc->is_valid = MMI_TRUE;
    WriteRecord(
        NVRAM_EF_DM_SRV_ACC_LID,
        record_index,
        acc,
        sizeof(nvram_ef_dm_srv_acc_struct),
        &error);
}


MMI_BOOL srv_dm_acc_get_acc_by_index(nvram_ef_dm_srv_acc_struct *acc, S32 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_DM_SRV_ACC_LID,
        record_index,
        acc,
        sizeof(nvram_ef_dm_srv_acc_struct),
        &error);

    return MMI_TRUE;
}


MMI_BOOL srv_dm_acc_get_acc_by_server_id(nvram_ef_dm_srv_acc_struct *acc, U8 *record_index, CHAR *server_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct nvram_temp_acc;
    U32 i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i <= NVRAM_EF_DM_SRV_ACC_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_DM_SRV_ACC_LID,
            i,
            &nvram_temp_acc,
            sizeof(nvram_temp_acc),
            &error);
        if (nvram_temp_acc.is_valid == MMI_TRUE)
        {
            if (strncmp(nvram_temp_acc.server_id, server_id, DM_MAX_ID_STR) == 0)
            {
                memcpy(acc, &nvram_temp_acc, sizeof(nvram_ef_dm_srv_acc_struct));
                *record_index = i;
                return MMI_TRUE;
            }
        }
        else
        {
            continue;
        }
    }
    return MMI_FALSE;
}


void srv_dm_acc_save_default_acc(nvram_ef_dm_srv_acc_struct *acc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acc->is_valid = MMI_TRUE;
    WriteRecord(
        NVRAM_EF_DM_SRV_ACC_LID,
        1,
        acc,
        sizeof(nvram_ef_dm_srv_acc_struct),
        &error);
}


MMI_BOOL srv_dm_acc_get_default_acc(nvram_ef_dm_srv_acc_struct *acc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_DM_SRV_ACC_LID,
        1,
        acc,
        sizeof(nvram_ef_dm_srv_acc_struct),
        &error);
    return MMI_TRUE;
}


void srv_dm_acc_remove_acc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_dm_srv_acc_struct nvram_acc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_acc.is_valid = KAL_FALSE;
    WriteRecord(
        NVRAM_EF_DM_SRV_ACC_LID,
        1,
        &nvram_acc,
        sizeof(nvram_acc),
        &error);
}


void srv_dm_acc_convert_acc_mmi_to_ps(dm_account_struct *dm_acc, const nvram_ef_dm_srv_acc_struct *nvram_acc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_proxy_info_struct proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strncpy(dm_acc->server_id, nvram_acc->server_id, DM_MAX_ID_STR);
    strncpy(dm_acc->server_pw, nvram_acc->server_pw, DM_MAX_ID_STR);
    strncpy(dm_acc->server_addr, nvram_acc->server_addr, DM_MAX_URI_SIZE);
    strncpy(dm_acc->user_name, nvram_acc->user_name, DM_MAX_ID_STR);
    strncpy(dm_acc->user_pw, nvram_acc->user_pw, DM_MAX_ID_STR);
    dm_acc->auth_pref = nvram_acc->auth_pref;
    dm_acc->conn_setting.data_account_id = cbm_encode_data_account_id(
                                            nvram_acc->dtcnt_id,
                                            mmi_frm_sim_to_index(srv_dm_get_reg_sim()),
                                            srv_dm_get_cbm_app_id(),
                                            MMI_FALSE);
    srv_dm_acc_get_proxy_info(dm_acc->conn_setting.data_account_id, &proxy_info);
    if (proxy_info.proxy_is_used == MMI_TRUE)
    {
        dm_acc->conn_setting.proxy_used = MMI_TRUE;
        strncpy(dm_acc->conn_setting.proxy_addr, proxy_info.proxy_addr, DM_MAX_PROXY_LEN + 1);
        dm_acc->conn_setting.proxy_port = proxy_info.proxy_port;
    }
    else
    {
        dm_acc->conn_setting.proxy_used = MMI_FALSE;
    }
}


void srv_dm_acc_convert_acc_ps_to_mmi(nvram_ef_dm_srv_acc_struct *nvram_acc, const dm_account_struct *dm_acc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


void srv_dm_acc_check_default_acc_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__OP01__) || defined(__OP02__)
    nvram_ef_dm_srv_acc_struct dm_acc;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_DM_SRV_ACC_LID,
        1,
        (void*)&dm_acc,
        sizeof(dm_acc),
        &error);
    if (dm_acc.is_valid == KAL_FALSE)
    {
        srv_dm_acc_restore_default_acc();
    }
#endif
}


void srv_dm_acc_restore_default_acc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct dm_acc;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_ACC_RESTORE_DEFAULT_ACC);
    memset(&dm_acc, 0x00, sizeof(dm_acc));

    dm_acc.dtcnt_id = CBM_DEFAULT_ACCT_ID;
    dm_acc.auth_pref = DM_CUSTOM_CFG_DEFAULT_PROFILE_AUTH_TYPE;
    dm_acc.is_valid = KAL_TRUE;
    mmi_wcscpy((WCHAR*)dm_acc.acc_name, DM_CUSTOM_CNF_DEFAULT_PROFILE_ACC_NAME);
    strcpy(dm_acc.server_id, DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVERID);
    strcpy(dm_acc.server_pw, DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_PW);
    strcpy(dm_acc.server_addr, DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR);
    strcpy(dm_acc.user_name, DM_CUSTOM_CFG_DEFAULT_PROFILE_USERNAME);
    strcpy(dm_acc.user_pw, DM_CUSTOM_CFG_DEFAULT_PROFILE_USERPW);

    WriteRecord(
        NVRAM_EF_DM_SRV_ACC_LID,
        1,
        (void*)&dm_acc,
        sizeof(dm_acc),
        &error);
}


srv_dm_acc_install_acc_result_enum srv_dm_acc_install_acc(nvram_ef_dm_srv_acc_struct *acc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct nvram_temp_acc;
    U32 i;
    U32 first_invalid_index = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i <= NVRAM_EF_DM_SRV_ACC_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_DM_SRV_ACC_LID,
            i,
            &nvram_temp_acc,
            sizeof(nvram_temp_acc),
            &error);
        if (nvram_temp_acc.is_valid == MMI_TRUE)
        {
            if (strncmp(nvram_temp_acc.server_id, acc->server_id, DM_MAX_ID_STR) == 0)
            {
                acc->is_valid = MMI_TRUE;
                WriteRecord(
                    NVRAM_EF_DM_SRV_ACC_LID,
                    i,
                    acc,
                    sizeof(nvram_ef_dm_srv_acc_struct),
                    &error);
                return SRV_DM_ACC_INSTALL_ACC_RESULT_UPDATE;
            }
        }
        else
        {
            if (first_invalid_index == 0)
            {
                first_invalid_index = i;
            }
            continue;
        }
    }

    if (first_invalid_index != 0)
    {
        acc->is_valid = MMI_TRUE;
        WriteRecord(
            NVRAM_EF_DM_SRV_ACC_LID,
            first_invalid_index,
            acc,
            sizeof(nvram_ef_dm_srv_acc_struct),
            &error);
        return SRV_DM_ACC_INSTALL_ACC_RESULT_NEW;
    }

    return SRV_DM_ACC_INSTALL_ACC_RESULT_FULL;
}


MMI_BOOL srv_dm_acc_check_server_id_exist(CHAR *server_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct nvram_temp_acc;
    U32 i;
    S16 error;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i <= NVRAM_EF_DM_SRV_ACC_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_DM_SRV_ACC_LID,
            i,
            &nvram_temp_acc,
            sizeof(nvram_temp_acc),
            &error);
        if (nvram_temp_acc.is_valid == MMI_TRUE)
        {
            if (strncmp(nvram_temp_acc.server_id, server_id, DM_MAX_ID_STR) == 0)
            {
                ret = MMI_TRUE;
                break;
            }
        }
        else
        {
            continue;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_ACC_CHECK_SERVER_ID_EXIST,
        ret);

    return ret;
}


mmi_ret srv_dm_acc_dtcnt_changed_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_acct_delete_ind_evt_struct *dtcnt_del_info = (srv_dtcnt_acct_delete_ind_evt_struct*)evt;
    srv_dtcnt_acct_update_ind_evt_struct *dtcnt_update_info = (srv_dtcnt_acct_update_ind_evt_struct*)evt;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_ACC_DTCNT_CHANGED_HDLR,
        evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        {
            if (dtcnt_del_info->cause == 0)
            {
                for (i = 0; i < dtcnt_del_info->del_num; i++)
                {
                }
            }
            break;
        }

        case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        {
            if (dtcnt_update_info->cause == 1) // provisioning replace
            {
            }
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}


U32 srv_dm_acc_get_curr_used_dtcnt_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct acc;
    U32 dtcnt_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_acc_get_acc_by_index(&acc, acc_cntx.curr_used_record_index);
    dtcnt_id = cbm_encode_data_account_id(
            acc.dtcnt_id,
            mmi_frm_sim_to_index(srv_dm_get_reg_sim()),
            srv_dm_get_cbm_app_id(),
            MMI_FALSE);

    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_ACC_GET_CURR_USED_DTCNT,
        dtcnt_id);
    return dtcnt_id;
}


void srv_dm_acc_get_proxy_info(kal_uint32 data_account_id, dm_proxy_info_struct *proxy_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 decode_account_id;
    U32 actual_account_id;
    srv_dtcnt_prof_proxy_info_struct temp_proxy_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbm_decode_data_account_id(data_account_id, NULL, NULL, NULL, &decode_account_id);
    if (CBM_DEFAULT_ACCT_ID == decode_account_id)
    {
        srv_dtcnt_get_auto_acc_id(data_account_id, &actual_account_id);
    }
    else
    {
        actual_account_id = data_account_id;
    }

    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        actual_account_id,
                        &temp_proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY))
    {            
        if (temp_proxy_info.use_proxy)
        {
            proxy_info->proxy_is_used = MMI_TRUE;
            strncpy(proxy_info->proxy_addr, temp_proxy_info.px_addr, DM_MAX_PROXY_LEN + 1);
            proxy_info->proxy_port = (U32)temp_proxy_info.px_port;
        }
        else
        {
            proxy_info->proxy_is_used = MMI_FALSE;
        }
    }
    else
    {
        proxy_info->proxy_is_used = MMI_FALSE;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_ACC_GET_PROXY_INFO,
        data_account_id,
        proxy_info->proxy_is_used,
        proxy_info->proxy_addr,
        proxy_info->proxy_port);
}

#endif /* SYNCML_DM_SUPPORT */
