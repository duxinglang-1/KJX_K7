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
 *  DmSrvOtap.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service over the air provisioning.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_features.h"
#if defined(SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
#include "DmSrvOtap.h"
#include "DmSrvIprot.h"
#include "DmSrvMain.h"
#include "DmSrvAcc.h"
#include "DmSrvUtil.h"
#include "MMIDataType.h"
#include "CcaSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "App_url.h" // applib_url_is_valid()
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static srv_dm_otap_cntx_struct otap_cntx;
static const U16 proc_tbl[] =
{
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_BOOTSTRAP,   SRV_DM_OTAP_CCA_NS_BOOTSTRAP,   0xFFFF,
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_PROXY,       SRV_DM_OTAP_CCA_NS_PROXY,       0xFFFF,
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_PROXY,       SRV_CCA_NS_OMA_PORT,            SRV_DM_OTAP_CCA_NS_PORT,        0xFFFF,
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_PROXY,       SRV_CCA_NS_OMA_PXAUTHINFO,      SRV_DM_OTAP_CCA_NS_PXAUTHINFO,  0xFFFF,
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_APPLICATION, SRV_DM_OTAP_CCA_NS_APPLICATION, 0xFFFF,
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_APPLICATION, SRV_CCA_NS_OMA_APPADDR,         SRV_DM_OTAP_CCA_NS_APPADDR,     0xFFFF,
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_APPLICATION, SRV_CCA_NS_OMA_PORT,            SRV_DM_OTAP_CCA_NS_APPPORT,     0xFFFF,
    SRV_CCA_NS_TRIGNODE,    SRV_CCA_NS_OMA_APPLICATION, SRV_CCA_NS_OMA_APPAUTH,         SRV_DM_OTAP_CCA_NS_APPAUTH,     0xFFFF
};

/****************************************************************************
 * Local Function
 ****************************************************************************/

void srv_dm_otap_cca_app_get_prof_hdlr(srv_cca_app_get_prof_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_CCA_APP_GET_PROF_HDLR);
    otap_cntx.app_id = newConfigDoc->app_id;
    otap_cntx.prof_id = newConfigDoc->prof_id;

    // could get default acc
    if (1)
    {
        srv_dm_otap_send_cca_app_get_prof_rsp(SRV_CCA_STATUS_OK);
    }
    else
    {
        srv_dm_otap_send_cca_app_get_prof_rsp(SRV_CCA_STATUS_FAIL);
    }
}


void srv_dm_otap_cca_app_configure_hdlr(srv_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_CCA_APP_CONFIGURE_HDLR);
    memset(&otap_cntx, 0x00, sizeof(srv_dm_otap_cntx_struct));

    otap_cntx.config_id = newConfigDoc->config_id;
    otap_cntx.hConfig = newConfigDoc->hConfig;

    /* Extract data SYNCML DM settings from CCA configuration document,
       and store settings in the temporary storage. */
    srv_cca_doc_process(
        newConfigDoc->hConfig,
        proc_tbl,
        sizeof(proc_tbl) / sizeof(proc_tbl[0]),
        NULL,
        srv_dm_otap_proc_cca_nodes,
        NULL);

    if (srv_dm_otap_get_valid_prof_num() == 0)
    {
        srv_dm_otap_send_cca_app_configure_rsp(CCA_STATUS_INVALID_SETTING);
        return;
    }

    otap_cntx.iter = -1;
    srv_dm_otap_find_next_prof();
}


void srv_dm_otap_cca_app_update_prof_hdlr(srv_cca_app_update_prof_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct new_acc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_CCA_APP_UPDATE_PROF_HDLR);

    memset(&otap_cntx, 0x00, sizeof(srv_dm_otap_cntx_struct));

    otap_cntx.app_id = newConfigDoc->app_id;
    otap_cntx.prof_id = newConfigDoc->prof_id;
    otap_cntx.hConfig = newConfigDoc->hConfig;

    srv_cca_doc_process(
        newConfigDoc->hConfig,
        proc_tbl,
        sizeof(proc_tbl) / sizeof(proc_tbl[0]),
        NULL,
        srv_dm_otap_proc_cca_nodes,
        NULL);

    /* If there is no correct SYNCML profile, send a INVALID_SETTING response message back to CCA. */
    if (srv_dm_otap_get_valid_prof_num() == 0)
    {
        /* Now, terminate the SYNCML OTA provisioning application. */
        srv_dm_otap_send_cca_app_update_prof_rsp(SRV_CCA_STATUS_FAIL);
        return;
    }

    srv_dm_otap_convert_acc(
        &new_acc,
        otap_cntx.otap_prof);

    srv_dm_acc_save_default_acc(&new_acc);
    srv_dm_otap_send_cca_app_update_prof_rsp(SRV_CCA_STATUS_OK);
}


void srv_dm_otap_send_cca_app_get_prof_rsp(srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_get_prof_rsp_struct *get_prof_rsp;
    S32 hconfig, hroot, hnode, temnode;
    nvram_ef_dm_srv_acc_struct nvram_acc;
    dm_account_struct dm_profile;
    S8 tempint[10];
    S32 auth_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_SEND_CCA_APP_GET_PROF_RSP, status);

    srv_dm_acc_get_default_acc(&nvram_acc);
    srv_dm_acc_convert_acc_mmi_to_ps(&dm_profile, &nvram_acc);

    hroot = srv_cca_doc_node_new(SRV_CCA_NS_DOCROOT);

    /* add proxy node */
    hnode = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PROXY, hroot);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_NODEID, "PROXY_1");
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_PROXY_ID, "PROXY_1");
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_PXADDR, (S8*)dm_profile.conn_setting.proxy_addr);
    srv_cca_doc_nodedata_add_int(hnode, SRV_CCA_NS_OMA_PXADDRTYPE, SRV_CCA_NS_VAL_IPV4);
    srv_cca_doc_nodedata_add_int(hnode, SRV_CCA_NS_DATAACCTID, (S32)dm_profile.conn_setting.data_account_id);

    /* add proxy port node */
    temnode = hnode;
    hnode = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PORT, temnode);
    sprintf((S8*)tempint, "%d", (U32)dm_profile.conn_setting.proxy_port);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_PORTNBR, (S8*) tempint);
    srv_cca_doc_nodedata_add_int(hnode, SRV_CCA_NS_OMA_SERVICE, (S32)SRV_CCA_NS_VAL_OTA_HTTP_TO);

    /* add proxy auth info node */
    hnode = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PXAUTHINFO, temnode);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_PXAUTH_ID, dm_profile.conn_setting.proxy_user_name);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_PXAUTH_PW, dm_profile.conn_setting.proxy_user_pw);

    /* add application node */
    hnode = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_APPLICATION, hroot);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_NODEID, "APPLICATION_1");
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_APPID, "w7");
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_TO_PROXY, "PROXY_1");
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_PROVIDER_ID, dm_profile.server_id);

    /* add app address node */
    temnode = hnode;
    hnode = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_APPADDR, temnode);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_ADDR, dm_profile.server_addr);

    /* add app auth node */
    hnode = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_APPAUTH, temnode);
    srv_cca_doc_nodedata_add_int(hnode, SRV_CCA_NS_OMA_AAUTHLEVEL, SRV_CCA_NS_VAL_APPSRV);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_AAUTHNAME, dm_profile.server_id);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_AAUTHSECRET, dm_profile.server_pw);
    //srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_AAUTHDATA, dm_profile.server_nonce);

    /* add app auth node 2 */
    hnode = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_APPAUTH, temnode);
    srv_cca_doc_nodedata_add_int(hnode, SRV_CCA_NS_OMA_AAUTHLEVEL, SRV_CCA_NS_VAL_CLIENT);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_AAUTHNAME, dm_profile.user_name);
    srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_AAUTHSECRET, dm_profile.user_pw);
    //srv_cca_doc_nodedata_add_str(hnode, SRV_CCA_NS_OMA_AAUTHDATA, dm_profile.client_nonce);

    switch (dm_profile.auth_pref)
    {
        case DM_AUTH_TYPE_BASIC:
        {
            auth_type = (S32)SRV_CCA_NS_VAL_BASIC;
            break;
        }

        case DM_AUTH_TYPE_MD5:
        {
            auth_type = (S32)SRV_CCA_NS_VAL_DIGEST;
            break;
        }

        case DM_AUTH_TYPE_HMAC:
        {
            auth_type = (S32)SRV_CCA_NS_VAL_HMAC;
            break;
        }

        default:
        {
            auth_type = 0;
            break;
        }
    }
    srv_cca_doc_nodedata_add_int(hnode, SRV_CCA_NS_OMA_AAUTHTYPE, auth_type);

    hconfig = srv_cca_doc_new(hroot);

    get_prof_rsp = OslAllocDataPtr(srv_cca_app_get_prof_rsp_struct);
    get_prof_rsp->app_id = otap_cntx.app_id;
    get_prof_rsp->prof_id = otap_cntx.prof_id;
    get_prof_rsp->hConfig = hconfig;
    get_prof_rsp->result = status;

    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_MMI_CCA_APP_GET_PROF_RSP,
        (oslParaType*)&get_prof_rsp,
        NULL);
}


void srv_dm_otap_send_cca_app_configure_rsp(srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_configure_rsp_struct *cfg_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_SEND_CCA_APP_CONFIGURE_RSP, status);
    cfg_rsp = OslAllocDataPtr(srv_cca_app_configure_rsp_struct);
    cfg_rsp->config_id = otap_cntx.config_id;
    cfg_rsp->hConfig =  otap_cntx.hConfig;
    cfg_rsp->status = status;

    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_MMI_CCA_APP_CONFIGURE_RSP,
        (oslParaType*)cfg_rsp,
        NULL);

    if (otap_cntx.otap_prof != NULL)
    {
        OslMfree(otap_cntx.otap_prof);
    }
    if (otap_cntx.proxy != NULL)
    {
        OslMfree(otap_cntx.proxy);
    }
}


void srv_dm_otap_send_cca_app_update_prof_rsp(srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_update_prof_rsp_struct *update_prof_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_SEND_CCA_APP_UPDATE_PROF_RSP, status);
    update_prof_rsp = OslAllocDataPtr(srv_cca_app_update_prof_rsp_struct);
    update_prof_rsp->app_id = otap_cntx.app_id;
    update_prof_rsp->prof_id = otap_cntx.prof_id;
    update_prof_rsp->hConfig = otap_cntx.hConfig;
    update_prof_rsp->result = status;

    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP,
        (oslParaType*)&update_prof_rsp,
        NULL);
    if (otap_cntx.otap_prof != NULL)
    {
        OslMfree(otap_cntx.otap_prof);
    }
    if (otap_cntx.proxy != NULL)
    {
        OslMfree(otap_cntx.proxy);
    }
}


void srv_dm_otap_send_app_install_prof_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_OTAP_INSTALL_PROF, NULL);
}


void srv_dm_otap_install_prof_app_rsp(srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_INSTALL_PROF_APP_RSP, status);
    switch (status)
    {
        case SRV_CCA_STATUS_OK:
        {
            srv_dm_otap_install_prof();
            break;
        }

        case SRV_CCA_STATUS_ENDKEY_PRESSED:
        {
            if (otap_cntx.cca_status == SRV_CCA_STATUS_SETTING_UPDATED)
            {
                otap_cntx.cca_status = SRV_CCA_STATUS_ENDKEY_SETTING_UPDATED;
            }
            else
            {
                otap_cntx.cca_status = SRV_CCA_STATUS_ENDKEY_PRESSED;
            }
            srv_dm_otap_send_cca_app_configure_rsp(otap_cntx.cca_status);
            break;
        }

        case SRV_CCA_STATUS_SETTING_SKIPPED:
        {
            otap_cntx.cca_status = SRV_CCA_STATUS_SETTING_SKIPPED;
            srv_dm_otap_find_next_prof();
            break;
        }

        default:
            break;
    }
}


srv_cca_status_enum srv_dm_otap_proc_cca_nodes(
                        S32 hConfig,
                        S32 node_hdl,
                        U16 symbol,
                        cca_iterator_struct *param_list,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status = SRV_CCA_STATUS_OK;
    srv_cca_core_data_struct *param;
    S32 index_acc = otap_cntx.num_acc;
    S32 index_proxy = otap_cntx.num_proxy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (symbol)
    {
        case SRV_DM_OTAP_CCA_NS_BOOTSTRAP:
        {
            break;
        }

        case SRV_DM_OTAP_CCA_NS_PROXY:    /* 0 */
        {
            if (otap_cntx.num_proxy >= NVRAM_EF_DM_SRV_ACC_TOTAL)
            {
                return SRV_CCA_STATUS_SETTING_SKIPPED;
            }

            otap_cntx.proxy = (srv_dm_otap_proxy_struct*)OslMalloc(sizeof(srv_dm_otap_proxy_struct));
            otap_cntx.num_proxy++;

            while (srv_cca_doc_nodedata_next(param_list, &param) == SRV_CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case SRV_CCA_NS_OMA_PROXY_ID:   /* 0x0c02 */
                    {
                        if (param->values.s[0])
                        {
                            if (srv_dm_check_asc_format(param->values.s[0]) == MMI_TRUE)
                            {
                                mmi_cca_generate_hash_value(
                                    (S8*)param->values.s[0],
                                    otap_cntx.proxy->proxy_id,
                                    DM_MD5_HASH_LENGTH);
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_DATAACCTID: /* 0x0403 */
                    {
                        otap_cntx.proxy->dtcnt_id= param->values.i[0];
                        break;
                    }

                    case SRV_CCA_NS_OMA_PROXY_PW:   /* 0x0c03 */
                    case SRV_CCA_NS_OMA_PPGAUTH_TYPE:   /* 0x0c04 */
                    case SRV_CCA_NS_OMA_PROXY_PROVIDER_ID:  /* 0x0c05 */
                    case SRV_CCA_NS_OMA_NAME:   /* 0x0c06 */
                    case SRV_CCA_NS_OMA_STARTPAGE:  /* 0x0c0a */
                    case SRV_CCA_NS_OMA_BASAUTH_ID: /* 0x0c0b */
                    case SRV_CCA_NS_OMA_BASAUTH_PW: /* 0x0c0c */
                    case SRV_CCA_NS_OMA_PHYSICAL_PROXY_ID:  /* 0x0c17 */
                    case SRV_CCA_NS_OMA_PXADDR: /* 0x0c18 */
                    case SRV_CCA_NS_OMA_PXADDRTYPE: /* 0x0c19 */
                    case SRV_CCA_NS_OMA_PXADDR_FQDN:    /* 0x0c1a */
                    {
                        break;
                    }

                    default:
                        break;
                }
            } /* End of while */

            break;
        } /* END of case SRV_DM_OTAP_CCA_NS_PROXY: */

        case SRV_DM_OTAP_CCA_NS_PORT: /* 2 */
        {
            while (srv_cca_doc_nodedata_next(param_list, &param) == SRV_CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case SRV_CCA_NS_OMA_PORTNBR:    /* 0x0c15 */
                    case SRV_CCA_NS_OMA_SERVICE:
                    default:
                        break;

                }
            }

            break;
        } /* END of case SRV_DM_OTAP_CCA_NS_PORT: */

        case SRV_DM_OTAP_CCA_NS_PXAUTHINFO:   /* 3 */
        {
            while (srv_cca_doc_nodedata_next(param_list, &param) == SRV_CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case SRV_CCA_NS_OMA_PXAUTH_TYPE:
                    case SRV_CCA_NS_OMA_PXAUTH_ID:
                    case SRV_CCA_NS_OMA_PXAUTH_PW:
                    default:
                        break;
                }
            }
            break;
        } /* END of case SRV_DM_OTAP_CCA_NS_PXAUTHINFO: */

        case SRV_DM_OTAP_CCA_NS_APPLICATION:  /* 1 */
        {
            if (otap_cntx.num_acc >= NVRAM_EF_DM_SRV_ACC_TOTAL)
            {
                return SRV_CCA_STATUS_SETTING_SKIPPED;
            }

            otap_cntx.otap_prof = (srv_dm_otap_prof_struct*)OslMalloc(sizeof(srv_dm_otap_prof_struct));
            otap_cntx.otap_prof->is_valid = MMI_TRUE;
            otap_cntx.num_acc++;

            while (srv_cca_doc_nodedata_next(param_list, &param) == SRV_CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case SRV_CCA_NS_OMA_APPID:  /* 0c4c *//* syncml dm appid is "w7" */
                    {
                        if (param->values.s[0])
                        {
                            if (strcmp((S8*)param->values.s[0], (S8*)"w7") != 0)
                            {
                                return SRV_CCA_STATUS_FAIL;
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_PROVIDER_ID:    /* provide id */
                    {
                        if (param->values.s[0])
                        {
                            if (srv_dm_check_asc_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                if (param->values.s[0][0] == '/0' ||
                                    strlen((S8*)param->values.s[0]) > DM_MAX_ID_STR)
                                {
                                    otap_cntx.otap_prof->is_valid = MMI_FALSE;
                                    break;
                                }
                                else
                                {
                                    strncpy(
                                        (S8*)otap_cntx.otap_prof->acc.server_id,
                                        param->values.s[0],
                                        DM_MAX_ID_STR);
                                }
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_NAME:   /* 0c06 *//* acct name & unused */
                    case SRV_CCA_NS_OMA_INIT:
                        break;

                    case SRV_CCA_NS_OMA_TO_PROXY:   /* 0x0c50 */
                    {
                        if (param->values.s[0])
                        {
                            if (srv_dm_check_asc_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                srv_cca_generate_hash_value(
                                        (S8*)param->values.s[0],
                                    otap_cntx.otap_prof->proxy_id,
                                    DM_MD5_HASH_LENGTH);
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_ADDR:   /* server address */
                    {
                        if (param->values.s[0])
                        {
                            if (srv_dm_check_asc_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                strncpy(
                                    (S8*) otap_cntx.otap_prof->acc.server_addr,
                                    param->values.s[0],
                                    DM_MAX_URI_SIZE);
                                if (strlen((S8*) param->values.s[0]) > DM_MAX_URI_SIZE)
                                {
                                    otap_cntx.otap_prof->is_valid = MMI_FALSE;
                                }
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_ADDRTYPE:   /* must be Alpha */
                    {
                        if (param->values.i[0] != SRV_CCA_NS_VAL_ALPHA)
                        {
                            return SRV_CCA_STATUS_FAIL;
                        }
                        break;
                    }

                    default:
                        break;

                }
            }   /* END of while loop */

            break;
        }
            /* END of case SRV_DM_OTAP_CCA_NS_APPLICATION: */

        case SRV_DM_OTAP_CCA_NS_APPPORT:  /* 2 */
        {
            while (srv_cca_doc_nodedata_next(param_list, &param) == SRV_CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case SRV_CCA_NS_OMA_PORTNBR:    /* 0x0c15 */
                    {
                        break;
                    }

                    case SRV_CCA_NS_OMA_SERVICE:
                    {
                        /* If data isn't whether CCA_NS_VAL_CL_WSP nor CCA_NS_VAL_OTA_HTTP_TO,
                           we pass this node */
                        if (param->values.i[0] != SRV_CCA_NS_VAL_OTA_HTTP_TO)
                        {
                        }
                        break;
                    }

                    default:
                        break;
                }
            }
            break;
        } /* END of case SRV_DM_OTAP_CCA_NS_APPPORT: */

        case SRV_DM_OTAP_CCA_NS_APPADDR:  /* 4 */
        {
            while (srv_cca_doc_nodedata_next(param_list, &param) == SRV_CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case SRV_CCA_NS_OMA_ADDR:   /* server address */
                    {
                        if (param->values.s[0])
                        {
                            if (srv_dm_check_asc_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                strncpy(
                                    (S8*)otap_cntx.otap_prof->acc.server_addr,
                                    param->values.s[0],
                                    DM_MAX_URI_SIZE);

                                if (strlen((S8*)param->values.s[0]) > DM_MAX_URI_SIZE)
                                {
                                    otap_cntx.otap_prof->is_valid = MMI_FALSE;
                                }
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_ADDRTYPE:   /* must be Alpha */
                    {
                        if (param->values.i[0] != SRV_CCA_NS_VAL_ALPHA)
                        {
                            return SRV_CCA_STATUS_FAIL;
                        }
                        break;
                    }

                    default:
                        break;

                }
            }

            break;
        }
            /* END of case SRV_DM_OTAP_CCA_NS_APPADDR: */

        case SRV_DM_OTAP_CCA_NS_APPAUTH:  /* 6 */
        {
            srv_dm_otap_auth_struct auth_data;

            memset(&auth_data, 0x00, sizeof(srv_dm_otap_auth_struct));

            while (srv_cca_doc_nodedata_next(param_list, &param) == SRV_CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case SRV_CCA_NS_OMA_AAUTHLEVEL:
                    {
                        /* Predefine this param is received earlier than any other params of this node.
                           If authlevel is not CCA_NS_VAL_CLIENT,we pass this node */
                        switch (param->values.i[0])
                        {
                            case SRV_CCA_NS_VAL_APPSRV: /* save AAUTHNAME AAUTHSECRET as username userpassword */
                                auth_data.auth_level = SRV_CCA_NS_VAL_APPSRV;
                                break;

                            case SRV_CCA_NS_VAL_OBEX:
                                return SRV_CCA_STATUS_FAIL;
                                break;

                            case SRV_CCA_NS_VAL_CLIENT:
                                auth_data.auth_level = SRV_CCA_NS_VAL_CLIENT;
                                break;

                            default:
                                return SRV_CCA_STATUS_FAIL;
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_AAUTHTYPE:
                    {
                        switch (param->values.i[0])
                        {
                            case SRV_CCA_NS_VAL_BASIC:  /* BASIC auth Type */
                                auth_data.auth_pref = DM_AUTH_TYPE_BASIC;
                                break;

                            case SRV_CCA_NS_VAL_DIGEST: /* MD5 auth type */
                                auth_data.auth_pref = DM_AUTH_TYPE_MD5;
                                break;

                            case SRV_CCA_NS_VAL_HMAC:   /* HMAC auth type */
                                auth_data.auth_pref = DM_AUTH_TYPE_HMAC;
                                break;

                            case SRV_CCA_NS_VAL_HTTP_BASIC:
                            case SRV_CCA_NS_VAL_HTTP_DIGEST:
                            case SRV_CCA_NS_VAL_WTLS_SS:
                            case SRV_CCA_NS_VAL_X509:
                            case SRV_CCA_NS_VAL_SECURID:
                            case SRV_CCA_NS_VAL_SAFEWORD:
                            case SRV_CCA_NS_VAL_DIGIPASS:
                                return SRV_CCA_STATUS_FAIL;
                                break;

                            default:    /* None auth type */
                                auth_data.auth_pref = DM_AUTH_TYPE_NONE;
                                break;

                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_AAUTHNAME:  /* user name */
                    {
                        if (param->values.s[0])
                        {
                            if (srv_dm_check_asc_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                strncpy(
                                    (S8*)auth_data.auth_name,
                                    param->values.s[0],
                                    DM_MAX_ID_STR);

                                if (strlen(param->values.s[0]) > DM_MAX_ID_STR)
                                {
                                    otap_cntx.otap_prof->is_valid = MMI_FALSE;
                                }
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_AAUTHSECRET:    /* user password */
                    {
                        if (param->values.s[0])
                        {
                            if (srv_dm_check_asc_format((S8*)param->values.s[0]) == MMI_TRUE)
                            {
                                strncpy(
                                    (S8*)auth_data.auth_pw,
                                    param->values.s[0],
                                    DM_MAX_ID_STR);
                                if (strlen(param->values.s[0]) > DM_MAX_ID_STR)
                                {
                                    otap_cntx.otap_prof->is_valid = MMI_FALSE;
                                }
                            }
                        }
                        break;
                    }

                    case SRV_CCA_NS_OMA_AAUTHDATA:  /* nonce name */
                    {
                        break;
                    }

                    default:
                        break;

                }
            }

            switch (auth_data.auth_level)
            {
                case SRV_CCA_NS_VAL_APPSRV:
                {
                    strcpy(otap_cntx.otap_prof->acc.server_pw, auth_data.auth_pw);
                    //strcpy(otap_cntx.otap_prof->acc.server_nonce, auth_data.auth_nonce);
                    break;
                }

                case SRV_CCA_NS_VAL_CLIENT:
                {
                    strcpy(otap_cntx.otap_prof->acc.user_name, auth_data.auth_name);
                    strcpy(otap_cntx.otap_prof->acc.user_pw, auth_data.auth_pw);
                    //strcpy(otap_cntx.otap_prof.client_nonce, auth_data.auth_nonce);
                    otap_cntx.otap_prof->acc.auth_pref = auth_data.auth_pref;
                    break;
                }

                default:
                    break;
            }

            break;
        }

        default:
            return SRV_CCA_STATUS_OK;
    }
    return status;
}


U8 srv_dm_otap_get_valid_prof_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (otap_cntx.valid_profile_num == 0)
    {
        if (otap_cntx.otap_prof != NULL &&
            srv_dm_otap_check_otap_prof_valid(otap_cntx.otap_prof) == MMI_TRUE)
        {
            otap_cntx.valid_profile_num++;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_GET_VALID_PROF_NUM, otap_cntx.valid_profile_num);
    return otap_cntx.valid_profile_num;
}


MMI_BOOL srv_dm_otap_check_otap_prof_valid(srv_dm_otap_prof_struct *otap_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 proxy_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (otap_prof->is_valid == MMI_TRUE)
    {
        if (otap_prof->acc.server_id[0] == '/0' ||
            otap_prof->acc.server_pw[0] == '/0' ||
            //otap_prof->acc.server_nonce[0] == '/0' ||
            otap_prof->acc.user_name[0] == '/0' ||
            applib_url_is_valid((char*)otap_prof->acc.server_addr) != 0)
        {
            otap_prof->is_valid = MMI_FALSE;
        }

        /* match proxy (data account) */
        for (proxy_index = 0; proxy_index < otap_cntx.num_proxy; proxy_index++)
        {
            if (!memcmp(otap_cntx.proxy->proxy_id,
                        otap_prof->proxy_id,
                        DM_MD5_HASH_LENGTH))
            {
                if (srv_dtcnt_get_bearer_type((U32)otap_cntx.proxy->dtcnt_id, SRV_DTCNT_ACCOUNT_PRIMARY) == 
                        DATA_ACCOUNT_BEARER_CSD)
                {
                    otap_prof->is_valid = MMI_FALSE;
                }
                else
                {
                    /* add data account id */
                    otap_prof->acc.dtcnt_id =
                        otap_cntx.proxy->dtcnt_id;
                    break;
                }
            }
        }

        /* match proxy ID failed */
        if (proxy_index == otap_cntx.num_proxy)
        {
            otap_prof->acc.dtcnt_id = CBM_DEFAULT_ACCT_ID;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_CHECK_OTAP_PROF_VALID, otap_prof->is_valid);
    return otap_prof->is_valid;
}


MMI_BOOL srv_dm_otap_check_curr_prof_is_to_udpate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_otap_prof_struct *curr_prof = srv_dm_otap_get_curr_prof();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dm_acc_check_server_id_exist(curr_prof->acc.server_id) == MMI_TRUE)
    {
        curr_prof->match_update = MMI_TRUE;
    }
    else
    {
        curr_prof->match_update = MMI_FALSE;
    }
    
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_OTAP_CHECK_CURR_PROF_IS_TO_UPDATE,
        curr_prof->match_update);
    return curr_prof->match_update;
}


MMI_BOOL srv_dm_otap_check_update_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (otap_cntx.cca_status == SRV_CCA_STATUS_SETTING_UPDATED)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void srv_dm_otap_install_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_dm_srv_acc_struct new_acc;
    srv_dm_acc_install_acc_result_enum install_result;
    srv_dm_otap_prof_struct *curr_prof = srv_dm_otap_get_curr_prof();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_INSTALL_PROF);

    srv_dm_otap_convert_acc(
        &new_acc,
        curr_prof);

    install_result = srv_dm_acc_install_acc(&new_acc);
    if (install_result == SRV_DM_ACC_INSTALL_ACC_RESULT_NEW)
    {
        otap_cntx.num_installed++;
        otap_cntx.cca_status = SRV_CCA_STATUS_OK;
    }
    else if (install_result == SRV_DM_ACC_INSTALL_ACC_RESULT_UPDATE)
    {
        otap_cntx.num_installed++;
        otap_cntx.cca_status = SRV_CCA_STATUS_SETTING_UPDATED;
    }
    else
    {
        srv_dm_send_app_display_nmgr_popup_evt(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_FAILED));
        otap_cntx.cca_status = SRV_CCA_STATUS_SETTING_NOT_INSTALLED;
    }

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    // directly replace
#else
    // replace confirm
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    srv_dm_otap_find_next_prof();
}


void srv_dm_otap_find_next_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    otap_cntx.iter++;
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_OTAP_FIND_NEXT_PROF, otap_cntx.iter);
    if (otap_cntx.iter < otap_cntx.num_acc)
    {
        if (otap_cntx.otap_prof->is_valid)
        {
            srv_dm_otap_send_app_install_prof_evt();
        }
        else
        {
            srv_dm_otap_find_next_prof();
        }
    }
    else
    {
        srv_dm_otap_send_cca_app_configure_rsp(otap_cntx.cca_status);
    }
}


void srv_dm_otap_convert_acc(
    nvram_ef_dm_srv_acc_struct *dm_acc,
    const srv_dm_otap_prof_struct *otap_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(dm_acc, &otap_prof->acc, sizeof(nvram_ef_dm_srv_acc_struct));
}


srv_dm_otap_prof_struct* srv_dm_otap_get_curr_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return otap_cntx.otap_prof;
}


U8* srv_dm_otap_get_curr_prof_server_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return otap_cntx.otap_prof->acc.server_id;
}


U8* srv_dm_otap_get_curr_prof_server_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return otap_cntx.otap_prof->acc.server_addr;
}


U8 srv_dm_otap_get_curr_prof_iter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return otap_cntx.iter;
}


S32 srv_dm_otap_get_curr_valid_prof_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 curr_valid_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i <= otap_cntx.iter; i++)
    {
        if (otap_cntx.otap_prof->is_valid == MMI_TRUE)
        {
            curr_valid_num++;
        }
    }
    return curr_valid_num;
}
#endif /* defined(SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */

