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
 * DtcntSrvApi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides the data account service interfaces.
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
#include "DtcntSrv.h"
#include "cbm_api.h"
#include "mmi_rp_srv_dtcnt_def.h"

#include "DtcntSrvIntStruct.h"
#include "kal_public_defs.h"
#include "MMI_features.h"
#include "DtcntSrvIprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "DtcntSrvDb.h"
#include "DtcntSrvGprot.h"
#include "cbm_consts.h"
#include "DtcntSrvIntDef.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "DtcntSrvProv.h"
#include "DtcntSrvWlanOtap.h"
#include "DtcntSrvWlan.h"
#include "DtcntSrvIntEnum.h"
#include "fs_func.h"
#include "fs_type.h"
#include "supc_abm_msgs.h"
#include "custom_data_account.h"
#include "fs_errcode.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_queue_gprot.h"
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
#include "CcaSrvGprot.h"
#endif /* __CCA_SUPPORT__ */
#include "TetheringSrvGprot.h"
#include "mmi_frm_nvram_gprot.h"

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern srv_dtcnt_context g_srv_dtcnt_context;
extern kal_mutexid g_srv_dtcnt_mutex_op;


#define DTCNT_EXT_SRV_APIs
/**********************************************************/
/* Service External Interfaces                            */
/**********************************************************/

/* For detail description please refer to DtcntSrvGprot.h */
mmi_ret srv_dtcnt_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_RET_ERR;
#else /* __TCPIP__ */

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_INIT);
    srv_dtcnt_context_init();
    srv_dtcnt_db_store_init();
    return MMI_RET_OK;
#endif    
}

/* For detail description please refer to DtcntSrvGprot.h */
srv_dtcnt_bearer_enum srv_dtcnt_get_bearer_type(U32 acc_id, srv_dtcnt_account_enum acc_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 decoded_acc_id;
    srv_dtcnt_account_info_st *acc_info = NULL;
    srv_dtcnt_bearer_enum out_bearer = SRV_DTCNT_BEARER_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_BEARER_UNKNOWN;
#else /* __TCPIP__ */

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_BEARER_TYPE, acc_id, acc_idx);

    decoded_acc_id = srv_dtcnt_get_real_acct(acc_id, acc_idx);
    
#ifdef __MMI_WLAN_FEATURES__
    if (decoded_acc_id ==  CBM_WIFI_ACCT_ID)
    {
        return SRV_DTCNT_BEARER_WIFI;
    }
#endif /* __MMI_WLAN_FEATURES__ */

SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret)
        return out_bearer;
    
SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info(decoded_acc_id);
    if (acc_info)
    {
        out_bearer = acc_info->bearer_type;
        SRV_DTCNT_GLOBAL_UNLOCK;
    }
    else
    {
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
        srv_dtcnt_account_info_st *sim_acc_info = OslMalloc(sizeof(srv_dtcnt_account_info_st));
        if (sim_acc_info && srv_dtcnt_db_store_qry_sim_acc_info(decoded_acc_id, sim_acc_info))
        {
            out_bearer = sim_acc_info->bearer_type;
        }
        if (sim_acc_info)
        {
            OslMfree(sim_acc_info);
        }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */        
        SRV_DTCNT_GLOBAL_UNLOCK; 
        return out_bearer;        
    }
    return out_bearer;
#endif /* TCPIP */
}

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_get_apn(U32 acc_id, srv_dtcnt_prof_str_info_qry_struct *out_apn, srv_dtcnt_account_enum acc_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

#if defined(__MMI_GPRS_FEATURES__) && defined(__TCPIP__)
    U8 decoded_acc_id;
    srv_dtcnt_account_info_st *acc_info = NULL;
    cbm_account_info_struct acct_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_APN, acc_id, acc_idx, out_apn);
SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret || !out_apn)
        return MMI_FALSE;

    /* Since USB tethering use specific account ID (CBM_USB_TR_PS_ACCT_ID), it need to get real account ID from USB tethering */
    cbm_decode_data_account_id_ext(acc_id, &acct_info);

    if (acct_info.account[acc_idx-1].account_id == CBM_USB_TR_PS_ACCT_ID)
    {
        acc_id = srv_tethering_usb_qurey_acct_id();
    }
    
    decoded_acc_id = srv_dtcnt_get_real_acct(acc_id, acc_idx);
    if(decoded_acc_id == CBM_WIFI_ACCT_ID)
    {
        ret = MMI_FALSE; 
    }
SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info(decoded_acc_id);
    if (acc_info && acc_info->bearer_type == SRV_DTCNT_BEARER_GPRS)
    {
        out_apn->req_len = (strlen((CHAR*)(acc_info->dest_name)) + 1) * ENCODING_LENGTH;
        if (out_apn->dest)
        {
            U16 temp_len = (out_apn->dest_len > out_apn->req_len)? strlen((CHAR *)acc_info->dest_name) : ((out_apn->dest_len-2) / ENCODING_LENGTH);

            kal_mem_set(out_apn->dest, 0, out_apn->dest_len);
            mmi_asc_n_to_ucs2((CHAR *)out_apn->dest, (CHAR *)acc_info->dest_name, temp_len);
        }   
        ret = MMI_TRUE;        
    }
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else if (!acc_info)
    {
        srv_dtcnt_account_info_st *sim_acc_info = OslMalloc(sizeof(srv_dtcnt_account_info_st));
        if(sim_acc_info != NULL)
        {
        kal_mem_set(sim_acc_info, 0, sizeof(srv_dtcnt_account_info_st));
        }
        if (sim_acc_info && srv_dtcnt_db_store_qry_sim_acc_info(decoded_acc_id, sim_acc_info))
        {
            out_apn->req_len = (strlen((CHAR *)sim_acc_info->dest_name) + 1) * ENCODING_LENGTH;
            if (out_apn->dest)
            {
                U16 temp_len = (out_apn->dest_len > out_apn->req_len)? strlen((CHAR *)sim_acc_info->dest_name) : ((out_apn->dest_len-2) / ENCODING_LENGTH);

                kal_mem_set(out_apn->dest, 0, out_apn->dest_len);
                mmi_asc_n_to_ucs2((CHAR *)out_apn->dest, (CHAR *)sim_acc_info->dest_name, temp_len);
            }
            OslMfree(sim_acc_info);
            sim_acc_info = NULL;
            ret = MMI_TRUE;
        }
        if (sim_acc_info)
        {
            OslMfree(sim_acc_info);
        }
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
    else
    {
        ret = MMI_FALSE;
    }
SRV_DTCNT_GLOBAL_UNLOCK;

#endif /* __MMI_GPRS_FEATURES__ && __TCPIP__ */
    return ret;
}

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_set_homepage(U32 acc_id, CHAR *in_homepage, U32 in_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 decoded_acc_id;
    srv_dtcnt_prof_common_header_struct *data;
    srv_dtcnt_result_enum res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else /* __TCPIP__ */

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_SET_HOMEPAGE, acc_id, in_len, in_homepage);
    if (!in_homepage || !in_len)
        return MMI_FALSE;
    
        decoded_acc_id = srv_dtcnt_get_real_acct(acc_id, SRV_DTCNT_ACCOUNT_PRIMARY);
    
    #ifdef __MMI_WLAN_FEATURES__
        if (decoded_acc_id ==  CBM_WIFI_ACCT_ID)
        {
            return MMI_FALSE;
        }
    #endif /* __MMI_WLAN_FEATURES__ */

    SRV_DTCNT_GLOBAL_LOCK;
        ret = srv_dtcnt_db_store_status_check();
    SRV_DTCNT_GLOBAL_UNLOCK;

        if (!ret)
            return MMI_FALSE;

    SRV_DTCNT_GLOBAL_LOCK;
        data = OslMalloc(sizeof(srv_dtcnt_prof_common_header_struct));
        kal_mem_set(data, 0, sizeof(srv_dtcnt_prof_common_header_struct));
        if (in_len < SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN)
            strncpy((CHAR *)data->HomePage, in_homepage, in_len);
        else
            strncpy((CHAR *)data->HomePage, in_homepage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);

        /* disable OTA wap/mms update profile events */
    //#ifdef __CCA_SUPPORT__
	#ifdef __MMI_CCA_SUPPORT__
        g_srv_dtcnt_ota_ongoing = MMI_TRUE;
        res = srv_dtcnt_db_store_update_prof(data, SRV_DTCNT_PROF_FIELD_HOME, decoded_acc_id, 0);
        g_srv_dtcnt_ota_ongoing = MMI_FALSE;
    #else /* !__CCA_SUPPORT__ */
        res = srv_dtcnt_db_store_update_prof(data, SRV_DTCNT_PROF_FIELD_HOME, decoded_acc_id, 0);
    #endif /* __CCA_SUPPORT__ */
        OslMfree(data);    
    SRV_DTCNT_GLOBAL_UNLOCK;

    if (res == SRV_DTCNT_RESULT_SUCCESS)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;    
#endif
}    

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_get_homepage(U32 acc_id, srv_dtcnt_prof_str_info_qry_struct *out_homepage, srv_dtcnt_account_enum acc_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 decoded_acc_id;
    srv_dtcnt_account_info_st *acc_info = NULL;
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    srv_dtcnt_sim_comm_account_info_st *sim_acc_info = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else /* __TCPIP__ */

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_HOMEPAGE, acc_id, acc_idx, out_homepage);
    if(!out_homepage)
    {
        return MMI_FALSE;
    }

    decoded_acc_id = srv_dtcnt_get_real_acct(acc_id, acc_idx);
    
#ifdef __MMI_WLAN_FEATURES__
    if (decoded_acc_id ==  CBM_WIFI_ACCT_ID)
    {
        srv_dtcnt_prof_wlan_struct *tmp_wlan_p = NULL;
SRV_DTCNT_GLOBAL_LOCK;
        if (g_srv_dtcnt_wlan_ctx.connected_wlan_profile)
        {
            tmp_wlan_p = g_srv_dtcnt_wlan_ctx.connected_wlan_profile;
        }
        out_homepage->req_len = tmp_wlan_p ? strlen((CHAR*)tmp_wlan_p->HomePage):0;
        if (out_homepage->dest)
        {
            U16 temp_len = (out_homepage->dest_len > out_homepage->req_len)? out_homepage->req_len : (out_homepage->dest_len-1);
            kal_mem_cpy(out_homepage->dest, tmp_wlan_p->HomePage, temp_len);
            out_homepage->dest[temp_len] = 0;
        }   
SRV_DTCNT_GLOBAL_UNLOCK;        
        return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */

SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret)
        return MMI_FALSE;

SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info(decoded_acc_id);
    if (acc_info)
    {
        srv_dtcnt_prof_common_header_struct *data = OslMalloc(sizeof(srv_dtcnt_prof_common_header_struct)); 
        kal_mem_set(data, 0, sizeof(srv_dtcnt_prof_common_header_struct));
        if (srv_dtcnt_db_store_load_prof(acc_info, data) == SRV_DTCNT_RESULT_SUCCESS)
        {
            out_homepage->req_len = strlen((CHAR *)data->HomePage);
            if (out_homepage->dest)
            {
                U16 temp_len = (out_homepage->dest_len > out_homepage->req_len)? out_homepage->req_len : (out_homepage->dest_len-1);
                kal_mem_cpy(out_homepage->dest, data->HomePage, temp_len);
                out_homepage->dest[temp_len] = 0;
            }   
            OslMfree(data);            
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_TRUE;
        }        
        OslMfree(data);
    }

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else
    {
        sim_acc_info = srv_dtcnt_db_store_get_sim_acc_info(decoded_acc_id);
        if (sim_acc_info)
        {
            out_homepage->req_len = strlen((CHAR *)sim_acc_info->HomePage);
            if (out_homepage->dest)
            {
                U16 temp_len = (out_homepage->dest_len > out_homepage->req_len)? out_homepage->req_len : (out_homepage->dest_len-1);
                kal_mem_cpy(out_homepage->dest, sim_acc_info->HomePage, temp_len);
                out_homepage->dest[temp_len] = 0;
            }
            SRV_DTCNT_GLOBAL_UNLOCK;            
            return MMI_TRUE;
        }
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

SRV_DTCNT_GLOBAL_UNLOCK;
    return MMI_FALSE;    
#endif    
}

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_get_account_name(U32 acc_id, srv_dtcnt_prof_str_info_qry_struct *out_acc_name, srv_dtcnt_account_enum acc_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 decoded_acc_id;
    srv_dtcnt_account_info_st *acc_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else /* __TCPIP__ */

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_ACC_NAME, acc_id, acc_idx, out_acc_name);
    if(!out_acc_name)
    {
        return MMI_FALSE;
    }

        decoded_acc_id = srv_dtcnt_extract_specified_acc_id(acc_id, acc_idx);
    
#ifdef __MMI_WLAN_FEATURES__
    if (decoded_acc_id ==  CBM_WIFI_ACCT_ID)
    {
        out_acc_name->req_len = (mmi_ucs2strlen((CHAR *)GetString(STR_ID_SRV_DTCNT_WLAN))+1) * ENCODING_LENGTH;
        if (out_acc_name->dest)
        {
            kal_mem_set(out_acc_name->dest, 0, out_acc_name->dest_len);
            mmi_ucs2ncpy((char *)out_acc_name->dest, GetString(STR_ID_SRV_DTCNT_WLAN), (out_acc_name->dest_len / ENCODING_LENGTH)-1);
        }   
        return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */

SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret)
        return MMI_FALSE;

SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info(decoded_acc_id);
    if (acc_info)
    {
        out_acc_name->req_len = (mmi_ucs2strlen((char *)acc_info->acc_name) + 1) * ENCODING_LENGTH;
        if (out_acc_name->dest)
        {
            kal_mem_set(out_acc_name->dest, 0, out_acc_name->dest_len);
            mmi_ucs2ncpy((char *)out_acc_name->dest, (char *)acc_info->acc_name, (out_acc_name->dest_len / ENCODING_LENGTH)-1);
        }   
        ret = MMI_TRUE;        
    }
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else
    {
        srv_dtcnt_account_info_st *sim_acc_info = OslMalloc(sizeof(srv_dtcnt_account_info_st));
        kal_mem_set(sim_acc_info, 0, sizeof(srv_dtcnt_account_info_st));
        if (sim_acc_info && srv_dtcnt_db_store_qry_sim_acc_info(decoded_acc_id, sim_acc_info))
        {
            out_acc_name->req_len = (mmi_ucs2strlen((char *)sim_acc_info->acc_name) + 1) * ENCODING_LENGTH;
            if (out_acc_name->dest)
            {
                kal_mem_set(out_acc_name->dest, 0, out_acc_name->dest_len);
                mmi_ucs2ncpy((char *)out_acc_name->dest, (char *)sim_acc_info->acc_name, (out_acc_name->dest_len / ENCODING_LENGTH)-1);
            }
            OslMfree(sim_acc_info);
            sim_acc_info = NULL;
            ret = MMI_TRUE;
        }
        else
        {
            ret = MMI_FALSE;
        }
        if (sim_acc_info)
        {
            OslMfree(sim_acc_info);
        }
    }
#else /* !__DTCNT_SIM_PROFILES_SUPPORT__ */
    else
    {
        ret = MMI_FALSE;
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */    
SRV_DTCNT_GLOBAL_UNLOCK;
    return ret;

#endif
}         

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_get_csd_number(U32 acc_id, srv_dtcnt_prof_str_info_qry_struct *out_csd, srv_dtcnt_account_enum acc_idx)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

#ifdef __TCPIP_OVER_CSD__
    U8 decoded_acc_id;
    srv_dtcnt_account_info_st *acc_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_CSD_NUMBER, acc_id, acc_idx, out_csd);
SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret || !out_csd)
        return MMI_FALSE;

    decoded_acc_id = srv_dtcnt_get_real_acct(acc_id, acc_idx);
    
SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info(decoded_acc_id);
    if (acc_info && acc_info->bearer_type == SRV_DTCNT_BEARER_CSD)
    {
        out_csd->req_len = (strlen((CHAR *)acc_info->dest_name) + 1) * ENCODING_LENGTH;
        if (out_csd->dest)
        {
            U16 temp_len = (out_csd->dest_len > out_csd->req_len)? strlen((CHAR *)acc_info->dest_name) : ((out_csd->dest_len-2) / ENCODING_LENGTH);
            kal_mem_set(out_csd->dest, 0, out_csd->dest_len);
            mmi_asc_n_to_ucs2((CHAR *)out_csd->dest, (CHAR *)acc_info->dest_name, temp_len);
        }        
        ret = MMI_TRUE;        
    }
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else if (!acc_info)
    {
        srv_dtcnt_account_info_st *sim_acc_info = OslMalloc(sizeof(srv_dtcnt_account_info_st));
        kal_mem_set(sim_acc_info, 0, sizeof(srv_dtcnt_account_info_st));
        if (sim_acc_info && srv_dtcnt_db_store_qry_sim_acc_info(decoded_acc_id, sim_acc_info))
        {
            out_csd->req_len = (strlen((CHAR *)sim_acc_info->dest_name) + 1) * ENCODING_LENGTH;
            if (out_csd->dest)
            {
                U16 temp_len = (out_csd->dest_len > out_csd->req_len)? strlen((CHAR *)sim_acc_info->dest_name) : ((out_csd->dest_len-2) / ENCODING_LENGTH);

                kal_mem_set(out_csd->dest, 0, out_csd->dest_len);
                mmi_asc_n_to_ucs2((CHAR *)out_csd->dest, (CHAR *)sim_acc_info->dest_name, temp_len);
            }
            OslMfree(sim_acc_info);
            sim_acc_info = NULL;
            ret = MMI_TRUE;
        }
        if (sim_acc_info)
        {
            OslMfree(sim_acc_info);
        }

    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
    else
    {
        ret = MMI_FALSE;
    }
SRV_DTCNT_GLOBAL_UNLOCK;

#endif /* __TCPIP_OVER_CSD__ */
    return ret;
}         

     

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_get_proxy_info(U32 acc_id, srv_dtcnt_prof_proxy_info_struct *out_px_info, srv_dtcnt_account_enum acc_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 decoded_acc_id;
    srv_dtcnt_account_info_st *acc_info = NULL;
    MMI_BOOL ret;
    //cbm_account_info_struct acct_info;

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    srv_dtcnt_sim_comm_account_info_st *sim_acc_info = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_PROXY_INFO, acc_id, acc_idx, out_px_info);
    if(!out_px_info)
    {
        return MMI_FALSE;
    }
    decoded_acc_id = srv_dtcnt_get_real_acct(acc_id, acc_idx);
#ifdef __MMI_WLAN_FEATURES__
    if (decoded_acc_id == CBM_WIFI_ACCT_ID)
    {
        srv_dtcnt_prof_wlan_struct *tmp_wlan_p = NULL;

        out_px_info->acc_id = CBM_WIFI_ACCT_ID;
        out_px_info->px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
        out_px_info->px_port = 80;

        SRV_DTCNT_GLOBAL_LOCK;
        if (g_srv_dtcnt_wlan_ctx.connected_wlan_profile)
        {
            tmp_wlan_p = g_srv_dtcnt_wlan_ctx.connected_wlan_profile;
        }
        
        if (tmp_wlan_p)
        {            
            if (tmp_wlan_p->use_proxy)
            {
                out_px_info->use_proxy = 1;
                out_px_info->px_port = tmp_wlan_p->px_port;            
                kal_mem_cpy(out_px_info->px_addr, tmp_wlan_p->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
                out_px_info->px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN] = 0;
                kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G6_DTCNT, "[DA SRV API]proxy is: %s, port is: %u", out_px_info->px_addr, out_px_info->px_port);                
                strncpy((CHAR*)out_px_info->px_authid, (CHAR*)tmp_wlan_p->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
                strncpy((CHAR*)out_px_info->px_authpw, (CHAR*)tmp_wlan_p->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1);
            }
            else
            {
                out_px_info->use_proxy = 0;
                kal_mem_set(out_px_info->px_addr, 0, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1);
                kal_mem_set(out_px_info->px_authid, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
                kal_mem_set(out_px_info->px_authpw, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1);
            }
            strncpy((CHAR*)out_px_info->px_startpage, (CHAR*)tmp_wlan_p->HomePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);            
        }
        else
        {
            out_px_info->use_proxy = 0;
            kal_mem_set(out_px_info->px_addr, 0, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1);
            kal_mem_set(out_px_info->px_authid, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
            kal_mem_set(out_px_info->px_authpw, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1);
            kal_mem_set(out_px_info->px_startpage, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
        }
        SRV_DTCNT_GLOBAL_UNLOCK;
        return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */

SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret)
        return MMI_FALSE;

SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info(decoded_acc_id);
    if (acc_info)
    {
        srv_dtcnt_prof_common_header_struct *data = OslMalloc(sizeof(srv_dtcnt_prof_common_header_struct));
        kal_mem_set(data, 0, sizeof(srv_dtcnt_prof_common_header_struct));
        if (srv_dtcnt_db_store_load_prof(acc_info, data) == SRV_DTCNT_RESULT_SUCCESS)
        {
            cbm_account_info_struct acct_info;

            kal_mem_set(out_px_info, 0, sizeof(srv_dtcnt_prof_proxy_info_struct));
            cbm_decode_data_account_id_ext(acc_id, &acct_info);

            acct_info.account[acc_idx-1].account_id = acc_info->acc_id;
            cbm_encode_data_account_id_ext(acc_id, &(out_px_info->acc_id), &acct_info);

            if (!acc_info->use_proxy)
            {
                out_px_info->px_service = acc_info->px_service;
                out_px_info->px_port = data->px_port;
            }
            else
            {
                out_px_info->use_proxy = 1;
                out_px_info->px_service = acc_info->px_service;
                out_px_info->px_addrtype = SRV_DTCNT_ADDR_TYPE_IPv4;
                out_px_info->px_port = data->px_port;
                kal_mem_cpy(out_px_info->px_addr, data->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
                out_px_info->px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN] = 0;
                kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G6_DTCNT, "[DA SRV API]proxy is: %s, port is: %u", out_px_info->px_addr, out_px_info->px_port);                
                strncpy((CHAR*)out_px_info->px_authid, (CHAR*)data->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
                strncpy((CHAR*)out_px_info->px_authpw, (CHAR*)data->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1);
                strncpy((CHAR*)out_px_info->px_startpage, (CHAR*)data->HomePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
            }
            OslMfree(data);            
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_TRUE;
        }
        OslMfree(data);
    }    

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else
    {
        sim_acc_info = srv_dtcnt_db_store_get_sim_acc_info(decoded_acc_id);
        if (sim_acc_info)
        {
            cbm_account_info_struct acct_info;
            kal_mem_set(out_px_info, 0, sizeof(srv_dtcnt_prof_proxy_info_struct));
            if (cbm_decode_data_account_id_ext(acc_id, &acct_info) != CBM_OK)
            {
                MMI_ASSERT(0);
            }
            acct_info.account[acc_idx-1].account_id = sim_acc_info->acc_id;
            if (cbm_encode_data_account_id_ext(acc_id, &(out_px_info->acc_id), &acct_info) != CBM_OK)
            {
                MMI_ASSERT(0);
            }

            if (!sim_acc_info->use_proxy)
            {
                out_px_info->px_service = sim_acc_info->px_service;
                out_px_info->px_port = sim_acc_info->px_port;
            }
            else
            {
                out_px_info->use_proxy = 1;
                out_px_info->px_service = sim_acc_info->px_service;
                out_px_info->px_addrtype = SRV_DTCNT_ADDR_TYPE_IPv4;
                out_px_info->px_port = sim_acc_info->px_port;
                kal_mem_cpy(out_px_info->px_addr, (CHAR*)sim_acc_info->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
                out_px_info->px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN] = 0;
                kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G6_DTCNT, "[DA SRV API]proxy is: %s, port is: %u", out_px_info->px_addr, out_px_info->px_port);                
                strncpy((CHAR*)out_px_info->px_authid, (CHAR*)sim_acc_info->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
                strncpy((CHAR*)out_px_info->px_authpw, (CHAR*)sim_acc_info->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1);
                strncpy((CHAR*)out_px_info->px_startpage, (CHAR*)sim_acc_info->HomePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);           
            }
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_TRUE;
        }
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
    SRV_DTCNT_GLOBAL_UNLOCK;
    return MMI_FALSE;
#endif /* __TCPIP__ */

}         

/* For detail description please refer to DtcntSrvGprot.h */
srv_dtcnt_result_enum srv_dtcnt_get_auto_acc_id(U32 acc_id, U32 *acc_id_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct acct_info;
    int i;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_AUTO_ACC_ID, acc_id, acc_id_out);
    if (!acc_id_out)
        return SRV_DTCNT_RESULT_FAILED;
    *acc_id_out = acc_id;
    cbm_decode_data_account_id_ext(acc_id, &acct_info);

SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
    if (!ret)
    {
        SRV_DTCNT_GLOBAL_UNLOCK;
        return SRV_DTCNT_RESULT_FAILED;
    }    
    else
    {
        for (i = 0; i < acct_info.acct_num; i++)
        {
            if (acct_info.account[i].account_id == CBM_DEFAULT_ACCT_ID)
            {
                    srv_dtcnt_db_store_find_best_fit_acct(acct_info.app_id, 
                                        &(acct_info.account[i].account_id),
                                        &(acct_info.account[i].sim_id));

                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_AUTO_ACC_ID_BEST_FIT, acct_info.account[i].account_id);
                break;
            }
        }
    }
SRV_DTCNT_GLOBAL_UNLOCK;

    cbm_encode_data_account_id_ext(acc_id, acc_id_out, &acct_info);

    return SRV_DTCNT_RESULT_SUCCESS;
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvGprot.h */
srv_dtcnt_result_enum srv_dtcnt_get_acc_id_by_apn(CHAR *apn, U32 *acc_id_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    store_status;
    srv_dtcnt_result_enum ret;
    srv_dtcnt_account_info_st *acc_info = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_ACC_ID_BY_APN, apn, acc_id_out);
    if (!acc_id_out || !apn)
        return SRV_DTCNT_RESULT_INVALID_INPUT;

SRV_DTCNT_GLOBAL_LOCK;
    store_status = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;
    if (!store_status)
        return SRV_DTCNT_RESULT_FAILED;

SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info_by_apn(apn);
    if (acc_info)
    {
        cbm_sim_id_enum sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(acc_info->sim_info);
        *acc_id_out = cbm_encode_data_account_id((U32)acc_info->acc_id, sim_id, 0, KAL_FALSE);
        ret = SRV_DTCNT_RESULT_SUCCESS;
    }
    else
    {
        *acc_id_out = CBM_INVALID_NWK_ACCT_ID;
        ret = SRV_DTCNT_RESULT_FAILED;
    }
SRV_DTCNT_GLOBAL_UNLOCK;

    return ret;
#endif /* __TCPIP__ */

}
    

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_get_sim_preference(srv_dtcnt_sim_type_enum *sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_SIM_PREFERENCE, sim_type);

    if (sim_type == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        *sim_type = g_srv_dtcnt_store_ctx.sim_preference;
        return MMI_TRUE;
    }
#else /* __TCPIP__ */
    return MMI_FALSE;
#endif /* __TCPIP__ */
}

/* For detail description please refer to DtcntSrvGprot.h */
void srv_dtcnt_prov_dm_update_ind(U16 appid, S32 profid, S32 hconfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_PROV_DM_UPDATE_IND);
//#if defined(__CCA_SUPPORT__) && defined(SYNCML_DM_SUPPORT)
#if defined(__MMI_CCA_SUPPORT__) && defined(SYNCML_DM_SUPPORT)
    srv_dtcnt_ota_dm_update_ind(appid, profid, hconfig);
#endif
#endif /* __TCPIP__ */
}         

/* For detail description please refer to DtcntSrvGprot.h */
void srv_dtcnt_prov_dm_retrieve_ind(U16 appid, S32 profid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_PROV_DM_RETRIEVE_IND);
//#if defined(__CCA_SUPPORT__) && defined(SYNCML_DM_SUPPORT)
#if defined(__MMI_CCA_SUPPORT__) && defined(SYNCML_DM_SUPPORT)
    srv_dtcnt_ota_dm_retrieve_ind(appid, profid);
#endif
#endif /* __TCPIP__ */
}         

//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
/* For detail description please refer to DtcntSrvGprot.h */
void srv_dtcnt_prov_proc_cca_doc(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_PROV_PROC_CCA_DOC);
    srv_dtcnt_ota_proc_cca_doc(newConfigDoc);
#endif /* __TCPIP__ */
}

/* For detail description please refer to DtcntSrvGprot.h */
cca_status_enum srv_dtcnt_prov_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return CCA_STATUS_FAIL;
#else /* __TCPIP__ */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_PROV_IS_CCA_TARGET);
    return srv_dtcnt_ota_is_cca_target(conf_id, doc_hdl, data_list);
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvGprot.h */
void srv_dtcnt_prov_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __TCPIP__
   MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_PROV_WLAN_PROC_CCA_DOC);
#ifdef __MMI_WLAN_FEATURES__
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
    srv_dtcnt_wlan_proc_cca_doc(conf_id, doc_hdl);
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __TCPIP__ */
}         

/* For detail description please refer to DtcntSrvGprot.h */
cca_status_enum srv_dtcnt_prov_wlan_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_PROV_WLAN_IS_CCA_TARGET);
    
#if defined(__MMI_WLAN_FEATURES__) && defined(__TCPIP__)

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
    return srv_dtcnt_wlan_is_cca_target(conf_id, doc_hdl, data_list);
#else
    return CCA_STATUS_FAIL;
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */


#else /* !defined(__MMI_WLAN_FEATURES__) && defined(__TCPIP__) */
    return CCA_STATUS_FAIL;
#endif /* __MMI_WLAN_FEATURES__ */

}         
#endif /* __CCA_SUPPORT__*/

/* For detail description please refer to DtcntSrvGprot.h */
srv_dtcnt_wlan_status_enum srv_dtcnt_wlan_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
            return SRV_DTCNT_WLAN_STATUS_INACTIVE;

        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:            
        case SRV_DTCNT_WLAN_STATE_INIT:
        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
            return SRV_DTCNT_WLAN_STATUS_ACTIVE;

        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            return SRV_DTCNT_WLAN_STATUS_CONNECTED;

        default:
            return SRV_DTCNT_WLAN_STATUS_INACTIVE;
    }
#else /* defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__) */
    return SRV_DTCNT_WLAN_STATUS_INACTIVE;
#endif /* defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__) */
}         

/* For detail description please refer to DtcntSrvGprot.h */
void srv_dtcnt_wlan_hw_reset_on(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_WLAN_HW_RESET_ON, callback);

#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_hw_reset(MMI_TRUE, callback, user_data);
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ */
    if (callback)
    {
        callback(user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
    }
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && defined(__TCPIP__) */
}         

/* For detail description please refer to DtcntSrvGprot.h */
void srv_dtcnt_wlan_hw_reset_off(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_WLAN_HW_RESET_OFF, callback);

#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_hw_reset(MMI_FALSE, callback, user_data);
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || __TCPIP__ */
    if (callback)
    {
        callback(user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
    }
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
#endif /* __TCPIP__ */
}         

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_wlan_get_connected_ap_ssid(srv_dtcnt_prof_str_info_qry_struct *ssid_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_WLAN_GET_AP_SSID, ssid_out);

#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined (__TCPIP__)
    if(!ssid_out)
    {
        return MMI_FALSE;
    }

    if(srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_CONNECTED)
    {
        return MMI_FALSE;
    }

    ssid_out->req_len = g_srv_dtcnt_wlan_ctx.cur_ssid_len;
    if (!ssid_out->dest)
    {
        return MMI_TRUE;
    }
    else
    {
        U16 temp_len = ((ssid_out->dest_len-1) > ssid_out->req_len)? (ssid_out->req_len) : (ssid_out->dest_len-1);
        kal_mem_cpy(ssid_out->dest, g_srv_dtcnt_wlan_ctx.cur_ssid, temp_len);
        ssid_out->dest[temp_len] = 0;
    }   
    return MMI_TRUE;

#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return MMI_FALSE;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}         

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_wlan_get_connected_ap_rssi(S32 *rssi_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_WLAN_GET_AP_RSSI, rssi_out);

#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    if(!rssi_out)
    {
        return MMI_FALSE;
    }

    if(srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_CONNECTED)
    {
        return MMI_FALSE;
    }
    *rssi_out = g_srv_dtcnt_wlan_ctx.cur_ap_info.rssi;
    return MMI_TRUE;
    
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return MMI_FALSE;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_wlan_get_mac_address(srv_dtcnt_prof_str_info_qry_struct *mac_address_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_WLAN_GET_MAC_ADDRESS, mac_address_out);

#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined (__TCPIP__)
    if(!mac_address_out)
    {
        return MMI_FALSE;
    }

    if(srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_ACTIVE &&
       srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_CONNECTED)
    {
        return MMI_FALSE;
    }

    mac_address_out->req_len = WNDRV_MAC_ADDRESS_LEN;
    if (mac_address_out->dest_len < WNDRV_MAC_ADDRESS_LEN || !mac_address_out->dest)
    {
        return MMI_FALSE;
    }
    else
    {
        kal_mem_cpy(mac_address_out->dest, g_srv_dtcnt_wlan_ctx.mac_addr, WNDRV_MAC_ADDRESS_LEN);
    }   
    return MMI_TRUE;

#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return MMI_FALSE;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}         

/* For detail description please refer to DtcntSrvGprot.h */
MMI_BOOL srv_dtcnt_wlan_is_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *exclusive_ip_addr)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    //U16 length = 0;
    //U16 length_store = 0;
    U8 * result = NULL;
    U8 * temp_para = NULL;
    U8 * temp_store = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    //if (exclusive_ip_addr == NULL || (length = strlen((const char *)exclusive_ip_addr->ip_addr))==0)
    if (exclusive_ip_addr == NULL || (strlen((const char *)exclusive_ip_addr->ip_addr))==0)
    {
        return MMI_FALSE;
    }
    kal_wap_trace(MOD_MMI_CONN_APP,MMI_CONN_TRC_G6_DTCNT,"[DA SRV API]query URL: %s",exclusive_ip_addr->ip_addr);    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM,
              g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips);

    for (i = 0; i < g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips; i++)
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
        #endif
        temp_para = (U8 *)strstr((const char *)exclusive_ip_addr->ip_addr,"://");
        if(temp_para != NULL)
        {
            temp_para += 3;
        }
        else
        {
            temp_para = exclusive_ip_addr->ip_addr;
        }
        temp_store = (U8 *)strstr((const char *)g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr,"://");
        if(temp_store != NULL)
        {
            temp_store += 3;
        }
        else
        {
            temp_store = g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr;
        }
        result = (U8 *)strstr((const char *)temp_para, (const char *)temp_store);
        if( result == temp_para)
        {
            return MMI_TRUE;
        }
    }
    
    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif
}


#define DTCNT_INT_SRV_APIs

/**********************************************************************/
/* Service Internal Interfaces                                        */
/**********************************************************************/

MMI_BOOL srv_dtcnt_wlan_get_connected_ap_bssid(U8 * bssid)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    if(g_srv_dtcnt_wlan_ctx.state != SRV_DTCNT_WLAN_STATE_CONNECTED)
    {
        return MMI_FALSE;
    }
    memcpy(bssid, g_srv_dtcnt_wlan_ctx.cur_bssid, WNDRV_MAC_ADDRESS_LEN);
    return MMI_TRUE;
#else

    return MMI_FALSE;

#endif 
}
srv_dtcnt_wlan_state_enum srv_dtcnt_wlan_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    return g_srv_dtcnt_wlan_ctx.state;
#else
    
    return SRV_DTCNT_WLAN_STATE_TOTAL;
   
#endif
}
srv_dtcnt_wlan_switch_state_enum srv_dtcnt_wlan_switch_state()
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_state_enum state =  g_srv_dtcnt_wlan_ctx.state;

    if(g_srv_dtcnt_wlan_prefer_ctx.need_awake == MMI_TRUE)
    {
        return SRV_DTCNT_WLAN_SWITCH_STATE_OPEN;
    }
   
    switch(state)
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
            return SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE;
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            return SRV_DTCNT_WLAN_SWITCH_STATE_CLOSING;
        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
            return SRV_DTCNT_WLAN_SWITCH_STATE_OPENING;
        case SRV_DTCNT_WLAN_STATE_INIT:
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            return SRV_DTCNT_WLAN_SWITCH_STATE_OPEN;
    }
    return SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE;
#else

    return SRV_DTCNT_WLAN_SWITCH_STATE_TOTAL;

#endif
}
/* For detail description please refer to DtcntSrvIprot.h */
MMI_BOOL srv_dtcnt_get_connection_type(U32 acc_id, srv_dtcnt_connection_type_enum *conn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    srv_dtcnt_account_info_st *acc_info = NULL;
    srv_dtcnt_prof_px_srv_enum px_srv;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_CONN_TYPE, acc_id, conn_type);
SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret || !conn_type)
        return MMI_FALSE;

#ifdef __MMI_WLAN_FEATURES__
    if (acc_id ==  CBM_WIFI_ACCT_ID)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_WLAN_FEATURES__ */
    
SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info((U8)acc_id);
    if (acc_info)
    {
        px_srv = acc_info->px_service; 
    }    
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else
    {
        srv_dtcnt_account_info_st *sim_acc_info = OslMalloc(sizeof(srv_dtcnt_account_info_st));
        kal_mem_set(sim_acc_info, 0, sizeof(srv_dtcnt_account_info_st));
        if (sim_acc_info && srv_dtcnt_db_store_qry_sim_acc_info((U8)acc_id, sim_acc_info))
        {
            px_srv = sim_acc_info->px_service;
            OslMfree(sim_acc_info);
        }
        else
        {
            if (sim_acc_info)
            {
                OslMfree(sim_acc_info);
            }
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_FALSE; 
        }
    }
#else /* !__DTCNT_SIM_PROFILES_SUPPORT__ */
    else
    {
        SRV_DTCNT_GLOBAL_UNLOCK;
        return MMI_FALSE;        
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
SRV_DTCNT_GLOBAL_UNLOCK;

    switch (px_srv)
    {
        case SRV_DTCNT_PROF_PX_SRV_CL_WSP:
        case SRV_DTCNT_PROF_PX_SRV_CO_WSP:
        case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP:
        case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP:
        case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA:
        case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA:
            *conn_type = SRV_DTCNT_CONN_TYPE_WAP;
            break;
        default:
            *conn_type = SRV_DTCNT_CONN_TYPE_HTTP;
            break;
    }
    return MMI_TRUE;
#endif /* __TCPIP__ */
}


/* For detail description please refer to DtcntSrvIprot.h */
MMI_BOOL srv_dtcnt_get_sim_info(U32 acc_id, srv_dtcnt_sim_type_enum *sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    const srv_dtcnt_account_info_st *acc_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_GET_SIM_INFO, acc_id, sim_info);
SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret || !sim_info)
        return MMI_FALSE;

#ifdef __MMI_WLAN_FEATURES__
    if (acc_id ==  CBM_WIFI_ACCT_ID)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_WLAN_FEATURES__ */
    
SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info((U8)acc_id);
    if (acc_info)
    {
        *sim_info = acc_info->sim_info;
        SRV_DTCNT_GLOBAL_UNLOCK;
        return MMI_TRUE;
    }
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else
    {
        srv_dtcnt_account_info_st *sim_acc_info = OslMalloc(sizeof(srv_dtcnt_account_info_st));
        kal_mem_set(sim_acc_info, 0, sizeof(srv_dtcnt_account_info_st));
        if (sim_acc_info && srv_dtcnt_db_store_qry_sim_acc_info((U8)acc_id, sim_acc_info))
        {
            *sim_info = sim_acc_info->sim_info;
            OslMfree(sim_acc_info);
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_TRUE;
        }
        if (sim_acc_info)
        {
            OslMfree(sim_acc_info);
        }
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
SRV_DTCNT_GLOBAL_UNLOCK;
    return MMI_FALSE;
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
MMI_BOOL srv_dtcnt_acct_is_read_only(U32 acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    const srv_dtcnt_account_info_st *acc_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_ACCT_IS_READ_ONLY, acc_id);
SRV_DTCNT_GLOBAL_LOCK;
    ret = srv_dtcnt_db_store_status_check();
SRV_DTCNT_GLOBAL_UNLOCK;

    if (!ret)
        return MMI_FALSE;

#ifdef __MMI_WLAN_FEATURES__
    if (acc_id ==  CBM_WIFI_ACCT_ID)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_WLAN_FEATURES__ */
    
SRV_DTCNT_GLOBAL_LOCK;
    acc_info = srv_dtcnt_db_store_get_acc_info((U8)acc_id);
    if (acc_info)
    {
        MMI_BOOL result = acc_info->readonly ? MMI_TRUE: MMI_FALSE;
            SRV_DTCNT_GLOBAL_UNLOCK;
        return result;
    }
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else
    {
        srv_dtcnt_account_info_st *sim_acc_info = OslMalloc(sizeof(srv_dtcnt_account_info_st));
        SRV_DTCNT_GLOBAL_UNLOCK;
        if (sim_acc_info)
        {
            OslMfree(sim_acc_info);
            return MMI_TRUE;
        }
        return MMI_FALSE;
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
SRV_DTCNT_GLOBAL_UNLOCK;
    return MMI_FALSE;
#endif /* __TCPIP__ */

}


/* For detail description please refer to DtcntSrvIprot.h */
MMI_BOOL srv_dtcnt_set_sim_preference(srv_dtcnt_sim_type_enum sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_SET_SIM_PREFERENCE, sim_type);
    // MMI_ASSERT(sim_type >= SRV_DTCNT_SIM_TYPE_NONE && sim_type < SRV_DTCNT_SIM_TYPE_TOTAL);
    MMI_ASSERT(sim_type < SRV_DTCNT_SIM_TYPE_TOTAL);

    if (sim_type != g_srv_dtcnt_store_ctx.sim_preference)
    {
        srv_dtcnt_sim_type_enum sim_id_old = g_srv_dtcnt_store_ctx.sim_preference;
        g_srv_dtcnt_store_ctx.sim_preference = sim_type;
        
        if (srv_dtcnt_db_fileio_write_store_info_file() == MMI_FALSE)
        {
            g_srv_dtcnt_store_ctx.sim_preference = sim_id_old;
            
            return MMI_FALSE;
        }
        else
        {
            srv_dtcnt_sim_preference_update_ind_evt_struct evt;
            
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND);
            evt.sim_id = sim_type;
            evt.sim_id_old = sim_id_old;
            MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
            return MMI_TRUE;
        }
    }
    
    return MMI_TRUE;
#else /* __TCPIP__ */
    return MMI_FALSE;
#endif /* __TCPIP__ */
}


/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_CREATE);
    /* check database folder is created or not */
    if (!srv_dtcnt_db_file_path_exist(SRV_DTCNT_DB_PATH))
    {
        int res;
        
        srv_dtcnt_db_atomic_begin(SRV_DTCNT_DB_TRANS_CREATE, 0);
        /* create db folder */
        res = FS_CreateDir(SRV_DTCNT_DB_PATH);
        if (res < 0)
        {
            goto create_fs_err;            
        }

        res = FS_CreateDir(SRV_DTCNT_SIM_PROF_PATH);
        if (res < 0)
        {
            goto create_fs_err;            
        }

        res = FS_Open (SRV_DTCNT_SIM_PROF_RESET_FILE, FS_CREATE_ALWAYS);
        if (res < 0)
        {
            return SRV_DTCNT_RESULT_FS_ERROR;
        }
        FS_Close(res);

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_CREATE_DB_PATH_CREATE);
    }

    /* check database config file is created or not */
    if (!srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_CONFIG_FILENAME))
    {
        srv_dtcnt_db_config_struct srv_dtcnt_db_config = {0,};
        srv_dtcnt_result_enum err;
        
        /* create config file */
        err = srv_dtcnt_db_fileio_save_data(SRV_DTCNT_DB_CONFIG_FILENAME, (const void *)&srv_dtcnt_db_config, sizeof(srv_dtcnt_db_config_struct));
        if (err == SRV_DTCNT_RESULT_FS_ERROR)
        {
            goto create_fs_err;
        }
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_CREATE_CONF_FILE_CREATE);
        srv_dtcnt_db_atomic_end();
        return SRV_DTCNT_RESULT_SUCCESS;        
    }
    else 
    {
        srv_dtcnt_db_trans_type_enum trans_type;

        /* error handling for writing config file done but atomic file not done */
        if (srv_dtcnt_db_atomic_peek_status(&trans_type, 0) &&
            trans_type == SRV_DTCNT_DB_TRANS_CREATE)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_CREATE_END_CREATE_ATOMIC_OP);
            srv_dtcnt_db_atomic_end();
            return SRV_DTCNT_RESULT_SUCCESS;
        }

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_CREATE_EXISTS);
        return SRV_DTCNT_RESULT_ONE_STORE_EXISTS;
    }
    
create_fs_err:
    srv_dtcnt_db_atomic_end();
    return SRV_DTCNT_RESULT_FS_ERROR;    
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_config(U32 prof_config, srv_dtcnt_bearer_enum prof_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_db_config_struct srv_dtcnt_db_config = {0,};
    srv_dtcnt_result_enum err;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_CONFIG, prof_config, prof_type);
    
    /* check database is created before */
    if (!srv_dtcnt_db_file_path_exist(SRV_DTCNT_DB_PATH) ||
        !srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_CONFIG_FILENAME))
    {
        return SRV_DTCNT_RESULT_INVALID_STORE;
    }
    
    /* check is available to config the database */
    err = srv_dtcnt_db_fileio_read_data(SRV_DTCNT_DB_CONFIG_FILENAME, (void *)&srv_dtcnt_db_config, sizeof(srv_dtcnt_db_config_struct), 0);
    if (err == SRV_DTCNT_RESULT_FS_ERROR || srv_dtcnt_db_config.store_commit)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }

    /* check params */
    if (!prof_config)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    switch (prof_type)
    {
        case SRV_DTCNT_BEARER_CSD:
            srv_dtcnt_db_config.csd_fields |= prof_config;
            break;
        case SRV_DTCNT_BEARER_GPRS:
            srv_dtcnt_db_config.gprs_fields |= prof_config;
            break;
        default:
            return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    err = srv_dtcnt_db_fileio_save_data(SRV_DTCNT_DB_CONFIG_FILENAME, (const void *)&srv_dtcnt_db_config, sizeof(srv_dtcnt_db_config_struct));
    if (err == SRV_DTCNT_RESULT_FS_ERROR)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }
    return SRV_DTCNT_RESULT_SUCCESS;
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_commit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_db_config_struct srv_dtcnt_db_config = {0,};
    srv_dtcnt_result_enum err;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_COMMIT);
    /* check database is created before */
    if (!srv_dtcnt_db_file_path_exist(SRV_DTCNT_DB_PATH) ||
        !srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_CONFIG_FILENAME))
    {
        return SRV_DTCNT_RESULT_INVALID_STORE;
    }

    /* check is available to config the database */
    err = srv_dtcnt_db_fileio_read_data(SRV_DTCNT_DB_CONFIG_FILENAME, (void *)&srv_dtcnt_db_config, sizeof(srv_dtcnt_db_config_struct), 0);
    if (err == SRV_DTCNT_RESULT_FS_ERROR)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }

    /* write commit flag */
    srv_dtcnt_db_config.store_commit = 1;
    err = srv_dtcnt_db_fileio_save_data(SRV_DTCNT_DB_CONFIG_FILENAME, (const void *)&srv_dtcnt_db_config, sizeof(srv_dtcnt_db_config_struct));
    if (err == SRV_DTCNT_RESULT_FS_ERROR)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }
    return SRV_DTCNT_RESULT_SUCCESS;
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_status_enum status;
    srv_dtcnt_db_trans_type_enum trans_type;
    U32 acc_id;
    srv_dtcnt_db_config_struct srv_dtcnt_db_config = {0,};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_OPEN);
    /* --- 0. check atomic operation --- */
    if (srv_dtcnt_db_atomic_peek_status(&trans_type, &acc_id))
    {
        switch (trans_type)
        {
            case SRV_DTCNT_DB_TRANS_CREATE:
                return SRV_DTCNT_RESULT_INVALID_STORE;
                
            case SRV_DTCNT_DB_TRANS_FIRST_BOOTUP:
                SRV_DTCNT_GLOBAL_LOCK;
                goto first_bootup_start;
                
            case SRV_DTCNT_DB_TRANS_ADD:
            case SRV_DTCNT_DB_TRANS_DELETE:
                break;
        }
    }

SRV_DTCNT_GLOBAL_LOCK;
    status = srv_dtcnt_db_store_info_file_open();
    /* --- 1. check info file to identify first open case --- */
    if (status == SRV_DTCNT_STORE_STATUS_FIRST_BOOTUP)
    {
        srv_dtcnt_result_enum err;        
        
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_OPEN_FIRST_BOOTUP);
        /* --- 1.1 first open case : check store created already otherwise return error --- */
        /* check database is created before */
        if (!srv_dtcnt_db_file_path_exist(SRV_DTCNT_DB_PATH) ||
            !srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_CONFIG_FILENAME))
        {
            SRV_DTCNT_GLOBAL_UNLOCK;
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_OPEN_FAILED_PATH_FILE_NOT_FOUND);
            return SRV_DTCNT_RESULT_INVALID_STORE;
        }

        srv_dtcnt_db_atomic_begin(SRV_DTCNT_DB_TRANS_FIRST_BOOTUP, 0);
first_bootup_start:
        /* check is available to config the database */
        err = srv_dtcnt_db_fileio_read_data(SRV_DTCNT_DB_CONFIG_FILENAME, (void *)&srv_dtcnt_db_config, sizeof(srv_dtcnt_db_config_struct), 0);
        if (err == SRV_DTCNT_RESULT_FS_ERROR)
        {
            SRV_DTCNT_GLOBAL_UNLOCK;
            return SRV_DTCNT_RESULT_FS_ERROR;
        }

        if (!srv_dtcnt_db_config.store_commit)
        {
            if (srv_dtcnt_db_config.csd_fields || srv_dtcnt_db_config.gprs_fields)
            {
                SRV_DTCNT_GLOBAL_UNLOCK;
                return SRV_DTCNT_RESULT_STORE_NOT_COMMIT;
            }
            else
            {
                srv_dtcnt_db_config.csd_fields = srv_dtcnt_db_config.gprs_fields = SRV_DTCNT_PROF_CONFIG_ALL_ENABLE;
            }
        }        

        /* --- 1.2 first open case : create store info file --- */
        if (srv_dtcnt_db_config.csd_fields & SRV_DTCNT_PROF_CONFIG_DEFAULT_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.csd_fields |= 
                                (SRV_DTCNT_PROF_FIELD_NAME|
                                 SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM|
                                 SRV_DTCNT_PROF_FIELD_AUTH_USER_INFO|
                                 SRV_DTCNT_PROF_FIELD_ACC_TYPE|
                                 SRV_DTCNT_PROF_FIELD_SIM_TYPE|
                                 SRV_DTCNT_PROF_FIELD_HASH_VAL|
                                 SRV_DTCNT_PROF_FIELD_READONLY|
                                 SRV_DTCNT_PROF_FIELD_USER_DATA);

            g_srv_dtcnt_store_ctx.ctrl_block.csd_fields |= (SRV_DTCNT_PROF_FIELD_DIAL_TYPE|SRV_DTCNT_PROF_FIELD_DATA_RATE);
        }
        if (srv_dtcnt_db_config.csd_fields & SRV_DTCNT_PROF_CONFIG_APP_TYPE_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.csd_fields |= SRV_DTCNT_PROF_FIELD_APP_TYPE;
        }
        if (srv_dtcnt_db_config.csd_fields & SRV_DTCNT_PROF_CONFIG_INET_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.csd_fields |= 
                                (SRV_DTCNT_PROF_FIELD_INET_IP|
                                 SRV_DTCNT_PROF_FIELD_INET_MASK|
                                 SRV_DTCNT_PROF_FIELD_INET_PRI_DNS|
                                 SRV_DTCNT_PROF_FIELD_INET_SEC_DNS);
        }
        if (srv_dtcnt_db_config.csd_fields & SRV_DTCNT_PROF_CONFIG_PROXY_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.csd_fields |= 
                                (SRV_DTCNT_PROF_FIELD_PX_ADDR|
                                 SRV_DTCNT_PROF_FIELD_PX_PORT|
                                 SRV_DTCNT_PROF_FIELD_PX_AUTH|
                                 SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE|
                                 SRV_DTCNT_PROF_FIELD_USE_PX);
        }
        if (srv_dtcnt_db_config.csd_fields & SRV_DTCNT_PROF_CONFIG_HOME_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.csd_fields |= SRV_DTCNT_PROF_FIELD_HOME;
        }

        if (srv_dtcnt_db_config.gprs_fields & SRV_DTCNT_PROF_CONFIG_DEFAULT_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields |= 
                                (SRV_DTCNT_PROF_FIELD_NAME|
                                 SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM|
                                 SRV_DTCNT_PROF_FIELD_AUTH_USER_INFO|
                                 SRV_DTCNT_PROF_FIELD_ACC_TYPE|
                                 SRV_DTCNT_PROF_FIELD_SIM_TYPE|
                                 SRV_DTCNT_PROF_FIELD_HASH_VAL|
                                 SRV_DTCNT_PROF_FIELD_READONLY|
                                 SRV_DTCNT_PROF_FIELD_USER_DATA);

            g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields |= SRV_DTCNT_PROF_FIELD_AUTH_TYPE;
        }
        if (srv_dtcnt_db_config.gprs_fields & SRV_DTCNT_PROF_CONFIG_APP_TYPE_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields |= SRV_DTCNT_PROF_FIELD_APP_TYPE;
        }
        if (srv_dtcnt_db_config.gprs_fields & SRV_DTCNT_PROF_CONFIG_INET_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields |= 
                                (SRV_DTCNT_PROF_FIELD_INET_IP|
                                 SRV_DTCNT_PROF_FIELD_INET_MASK|
                                 SRV_DTCNT_PROF_FIELD_INET_PRI_DNS|
                                 SRV_DTCNT_PROF_FIELD_INET_SEC_DNS);
        }
        if (srv_dtcnt_db_config.gprs_fields & SRV_DTCNT_PROF_CONFIG_PROXY_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields |= 
                                (SRV_DTCNT_PROF_FIELD_PX_ADDR|
                                 SRV_DTCNT_PROF_FIELD_PX_PORT|
                                 SRV_DTCNT_PROF_FIELD_PX_AUTH|
                                 SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE|
                                 SRV_DTCNT_PROF_FIELD_USE_PX);
        }
        if (srv_dtcnt_db_config.gprs_fields & SRV_DTCNT_PROF_CONFIG_HOME_ENABLE)
        {
            g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields |= SRV_DTCNT_PROF_FIELD_HOME;
        }

        g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num = 0;
        err = srv_dtcnt_db_fileio_save_data(SRV_DTCNT_DB_STORE_INFOFILE_NAME, (void *)&g_srv_dtcnt_store_ctx, sizeof(srv_dtcnt_store_info_context));
        if (err == SRV_DTCNT_RESULT_FS_ERROR)
        {
            srv_dtcnt_db_atomic_end();
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_OPEN_FAILED_INFO_FILE_WRITE_FAIL);
            SRV_DTCNT_GLOBAL_UNLOCK;
            return SRV_DTCNT_RESULT_FS_ERROR;
        }

        /* compute checksum for corruption check */

        g_srv_dtcnt_context.info_file_fp = FS_Open (SRV_DTCNT_DB_STORE_INFOFILE_NAME, FS_READ_WRITE|FS_COMMITTED);
        g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_FIRST_BOOTUP;
        srv_dtcnt_db_atomic_end();
        SRV_DTCNT_GLOBAL_UNLOCK;
        return SRV_DTCNT_RESULT_FIRST_BOOTUP;
    }
    else
    {
        srv_dtcnt_result_enum ret = SRV_DTCNT_RESULT_SUCCESS;
        switch (status)
        {
            case SRV_DTCNT_STORE_STATUS_RESET_FACTORY:
                ret = SRV_DTCNT_RESULT_RESET_FACTORY;
                break;

            case SRV_DTCNT_STORE_STATUS_OPENED:
                break;

            case SRV_DTCNT_STORE_STATUS_CORRUPT:
            case SRV_DTCNT_STORE_STATUS_FS_ERROR:
                SRV_DTCNT_GLOBAL_UNLOCK;
                return SRV_DTCNT_RESULT_FS_ERROR;

            default:
                SRV_DTCNT_GLOBAL_UNLOCK;
                return SRV_DTCNT_RESULT_FAILED;
        }

        switch (trans_type)
        {
            case SRV_DTCNT_DB_TRANS_ADD:
            case SRV_DTCNT_DB_TRANS_DELETE:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_OPEN_END_ATOMIC_OP, trans_type);
                srv_dtcnt_db_atomic_terminate_trans(trans_type, acc_id);
                break;
        }
        SRV_DTCNT_GLOBAL_UNLOCK;
        return ret;
    }
#endif
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_qry_ids(srv_dtcnt_store_prof_qry_struct *qry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_acc_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_QRY_IDS, qry);
    if (!qry)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    if(srv_dtcnt_db_store_check_ignore_num()==MMI_FALSE)
    {
            return SRV_DTCNT_RESULT_INVALID_STORE;
    }

    kal_mem_set(qry->ids, 0, (sizeof(U32) * SRV_DTCNT_PROF_MAX_ACCOUNT_NUM));
    qry->num_ids = 0;
#ifdef __MMI_WLAN_FEATURES__
    if (qry->qry_info.filters & SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE)
    {
    if ((qry->qry_info.bearer_qry_info == SRV_DTCNT_BEARER_WIFI) &&
        !(g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num || g_srv_dtcnt_wlan_setting_ctx.infra_prof_num))
    {
        return SRV_DTCNT_RESULT_SUCCESS;
    }
    }
#endif /* __MMI_WLAN_FEATURES__ */
    temp_acc_num = g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num;
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
    temp_acc_num += g_srv_dtcnt_store_ctx.ctrl_block.csd_sim_acc_num;
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
    temp_acc_num += g_srv_dtcnt_store_ctx.ctrl_block.gprs_sim_acc_num;
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

    if ((!temp_acc_num || qry->qry_info.filters == 0) &&
        qry->qry_info.bearer_qry_info != SRV_DTCNT_BEARER_WIFI)
    {
        return SRV_DTCNT_RESULT_SUCCESS;
    }
    else
    {
        if (!srv_dtcnt_db_store_qry_check(qry))
        {
            return SRV_DTCNT_RESULT_INVALID_INPUT;
        }
        srv_dtcnt_db_store_ids_qry(qry);
        return SRV_DTCNT_RESULT_SUCCESS;
    }
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_qry_prof(U32 acc_prof_id, srv_dtcnt_store_prof_data_struct *qry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_QRY_PROF, acc_prof_id, qry);
    if (!qry)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    if(srv_dtcnt_db_store_check_ignore_num()==MMI_FALSE)
    {
            return SRV_DTCNT_RESULT_INVALID_STORE;
    }

    /* query wlan profile */
    if (acc_prof_id > CBM_DEFAULT_ACCT_ID)
    {
        return srv_dtcnt_db_store_wlan_prof_qry(acc_prof_id, qry);
    }
    /* query csd/gprs profile */
    else
    {
        return srv_dtcnt_db_store_prof_qry((U8)acc_prof_id, qry);
    }
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_add_prof(srv_dtcnt_store_prof_data_struct *prof, U32 *acc_prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_ADD_PROF, acc_prof_id, prof);
    if (!prof || !acc_prof_id || !(prof->prof_data) || !(prof->prof_fields) ||
        (prof->prof_type == SRV_DTCNT_BEARER_UNKNOWN) || (prof->prof_type == SRV_DTCNT_BEARER_TOTAL))
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    if(srv_dtcnt_db_store_check_ignore_num()==MMI_FALSE)
    {
            return SRV_DTCNT_RESULT_INVALID_STORE;
    }
 
SRV_DTCNT_GLOBAL_LOCK;
    if (prof->prof_type == SRV_DTCNT_BEARER_WIFI)
    {
        ret = srv_dtcnt_db_store_add_wlan_prof((srv_dtcnt_prof_wlan_struct *)prof->prof_data, prof->prof_fields, acc_prof_id);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_ADD_WLAN_PROF, *acc_prof_id);
    }
    else /* CSD/GPRS */
    {
        ret = srv_dtcnt_db_store_add_prof(prof->prof_data, prof->prof_fields, prof->prof_type, acc_prof_id);
    }
SRV_DTCNT_GLOBAL_UNLOCK;
    return ret;
#endif
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_update_prof(U32 acc_prof_id, srv_dtcnt_store_prof_data_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_UPDATE_PROF, acc_prof_id, prof);
    if (!prof  || !(prof->prof_data) || !(prof->prof_fields) ||
        (prof->prof_type == SRV_DTCNT_BEARER_UNKNOWN) || (prof->prof_type == SRV_DTCNT_BEARER_TOTAL))
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    if(srv_dtcnt_db_store_check_ignore_num()==MMI_FALSE)
    {
            return SRV_DTCNT_RESULT_INVALID_STORE;
    }

SRV_DTCNT_GLOBAL_LOCK;
    if (prof->prof_type == SRV_DTCNT_BEARER_WIFI)
    {
        ret = srv_dtcnt_db_store_update_wlan_prof((srv_dtcnt_prof_wlan_struct *)prof->prof_data, prof->prof_fields, acc_prof_id);
    }
    else /* CSD/GPRS */
    {
        ret = srv_dtcnt_db_store_update_prof(prof->prof_data, prof->prof_fields, acc_prof_id, 0);
    }
SRV_DTCNT_GLOBAL_UNLOCK;
    return ret;
#endif
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_delete_prof(U32 acc_prof_id, MMI_BOOL force_exec, void *user_data, srv_dtcnt_store_delete_cb_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_DELETE_PROF, acc_prof_id, callback);
    if(srv_dtcnt_db_store_check_ignore_num()==MMI_FALSE)
    {
            return SRV_DTCNT_RESULT_INVALID_STORE;
    }

SRV_DTCNT_GLOBAL_LOCK;
    if (acc_prof_id > CBM_DEFAULT_ACCT_ID)
    {
        srv_dtcnt_db_store_del_wlan_profile(acc_prof_id);
        ret = SRV_DTCNT_RESULT_SUCCESS;
    }
    else
    {
        ret = srv_dtcnt_db_store_del_account((U8)acc_prof_id, force_exec, user_data, callback);
    }
SRV_DTCNT_GLOBAL_UNLOCK;    
    return ret;
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_store_delete_prof_by_qry(srv_dtcnt_store_prof_qry_filter_struct *qry, MMI_BOOL force_exec, void *user_data, srv_dtcnt_store_delete_cb_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_qry_struct qry_ids;
    srv_dtcnt_result_enum ret;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return SRV_DTCNT_RESULT_FAILED;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_STORE_DELETE_PROF_BY_QRY, qry, callback);
    memset(&qry_ids, 0, sizeof(srv_dtcnt_store_prof_qry_struct));
    if (!qry || !(qry->filters))
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    kal_mem_cpy(&(qry_ids.qry_info), qry, sizeof(srv_dtcnt_store_prof_qry_filter_struct));    
    ret =srv_dtcnt_store_qry_ids(&qry_ids);
    if (ret != SRV_DTCNT_RESULT_SUCCESS || qry_ids.num_ids == 0)
    {
        return ret;
    }
    else /* success and also num_ids > 0 */
    {
        while (qry_ids.num_ids)
        {
            srv_dtcnt_store_delete_prof(qry_ids.ids[--qry_ids.num_ids], force_exec, user_data, callback);
        }
    }
    return SRV_DTCNT_RESULT_SUCCESS;    
#endif /* __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_init(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_job_struct new_wlan_job;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_INIT_REQ, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state());

    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        if (callback != NULL)
        {
            callback(user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
        }
        srv_dtcnt_wlan_post_init_res_event(SRV_DTCNT_WLAN_REQ_RES_FAILED);

        return SRV_DTCNT_RESULT_FAILED;
    }

#ifdef __MMI_TETHERING_WIFI__
    if(srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS) == MMI_FALSE)
    {
    		MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_INIT_CHECK_TETHERING);
    		g_init_callback.callback = callback;
    		g_init_callback.user_data = user_data;
        srv_tethering_stop(SRV_TETHERING_TYPE_WIFI_HS,srv_dtcnt_wlan_stop_wifi_tethering_callback_func,NULL);
        return SRV_DTCNT_RESULT_PROCESSING;
    }
#endif
    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            if (callback)
            {
                new_wlan_job.cb_func_ptr = (void *)callback;
                new_wlan_job.user_data = user_data;
                srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_INIT, NULL, &new_wlan_job);
            }
            else
            {
                srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_INIT, NULL, NULL);
            }
            return SRV_DTCNT_RESULT_PROCESSING;

        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_INIT:
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DEINIT) != NULL)
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_DEINIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            }            
            if (callback)
            {
                callback(user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
            }
            srv_dtcnt_wlan_post_init_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
            return SRV_DTCNT_RESULT_SUCCESS;

        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DEINIT) != NULL)
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_DEINIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            }            
            if (callback)
            {
                new_wlan_job.cb_func_ptr = (void *)callback;
                new_wlan_job.user_data = user_data;
                srv_dtcnt_wlan_append_proc_job(&new_wlan_job);
            }
            return SRV_DTCNT_RESULT_PROCESSING;

        default:
            return SRV_DTCNT_RESULT_FAILED;
    }
    
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return SRV_DTCNT_RESULT_FAILED;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_deinit(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_job_struct new_wlan_job;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DEINIT_REQ, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state());

    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        if (callback != NULL)
        {
            callback(user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
        }
        srv_dtcnt_wlan_post_deinit_res_event(SRV_DTCNT_WLAN_REQ_RES_FAILED);

        return SRV_DTCNT_RESULT_FAILED;
    }

    if (callback)
    {
        new_wlan_job.cb_func_ptr = (void *)callback;
        new_wlan_job.user_data = user_data;
    }
    
    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
            if (callback)
            {
                callback(user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
            }
            srv_dtcnt_wlan_post_deinit_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
            return SRV_DTCNT_RESULT_SUCCESS;

        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_CONNECT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_INIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT) == NULL)
            {
                srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT, NULL, NULL);
            }
            goto processing;

        case SRV_DTCNT_WLAN_STATE_CONNECTED:                     
            srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT, NULL, NULL);
        case SRV_DTCNT_WLAN_STATE_INIT:
            goto processing;
            
        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:            
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_CONNECT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_INIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            goto processing;
            
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_CONNECT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_INIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_DEINIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            srv_dtcnt_wlan_clear_scan_action();
            if (callback)
            {
                srv_dtcnt_wlan_append_proc_job(&new_wlan_job);
            }            
            return SRV_DTCNT_RESULT_PROCESSING;
            
        default:
            return SRV_DTCNT_RESULT_FAILED;            
    }

processing:
    srv_dtcnt_wlan_clear_scan_action();
    if (callback)
    {
        srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DEINIT, NULL, &new_wlan_job);
    }
    else
    {
        srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DEINIT, NULL, NULL);
    }
    return SRV_DTCNT_RESULT_PROCESSING;

#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return SRV_DTCNT_RESULT_FAILED;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */

}

/* For detail description please refer to DtcntSrvIprot.h */
U32 srv_dtcnt_wlan_scan(srv_dtcnt_wlan_scan_res_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SCAN_REQ, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state());

    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        srv_dtcnt_wlan_scan_result_struct scan_res;
        scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_FAILED;
        srv_dtcnt_wlan_post_scan_res_event(&scan_res);
        if(callback != NULL)
        {
            callback(0, user_data, &scan_res);
        }
        return SRV_DTCNT_RESULT_FAILED;
    }
 
            return srv_dtcnt_wlan_new_scan_job(callback, user_data);
    
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return 0;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}

/* For detail description please refer to DtcntSrvIprot.h */
void srv_dtcnt_wlan_scan_abort(U32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_scan_state_enum  scan_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SCAN_ABORT_REQ, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state(), job_id);
    if ( job_id != 0 )
    {
        scan_state = srv_dtcnt_wlan_scan_state();
        switch (scan_state)
        {
            case SRV_DTCNT_WLAN_SCAN_STATE_NULL:
            case SRV_DTCNT_WLAN_SCAN_STATE_WAITING:
                srv_dtcnt_wlan_abort_scan_job(scan_state, job_id);
            default:
                return;
        }
    }
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_connect_by_db_prof(srv_dtcnt_wlan_conn_res_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_job_struct new_wlan_job;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONNECT_REQ_BY_DB, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state());

    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        srv_dtcnt_wlan_conn_res_struct *conn_res;
        conn_res = OslMalloc(sizeof(srv_dtcnt_wlan_conn_res_struct));
        conn_res->result = SRV_DTCNT_RESULT_FAILED;
        if( callback != NULL )
        {
            callback(user_data, conn_res);
        }
        srv_dtcnt_wlan_post_conn_res_event(conn_res, EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND);
        OslMfree(conn_res);
        return SRV_DTCNT_RESULT_FAILED;
    }

    if (callback)
    {
        new_wlan_job.cb_func_ptr = (void *)callback;
        new_wlan_job.user_data = user_data;
    }
    
    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_INIT, NULL, NULL);
            break;

        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT) == NULL)
            {
                srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT, NULL, NULL);
            }
            break;

        case SRV_DTCNT_WLAN_STATE_INIT:
        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
            break;

        default:
            return SRV_DTCNT_RESULT_STATE_ERROR;
    }

    if (callback)
    {
        srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_CONNECT, NULL, &new_wlan_job);
    }
    else
    {
        srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_CONNECT, NULL, NULL);
    }
    return SRV_DTCNT_RESULT_PROCESSING;
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return SRV_DTCNT_RESULT_STATE_ERROR;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_connect_by_app_prof(srv_dtcnt_wlan_conn_prof_struct *app_profs, srv_dtcnt_wlan_conn_res_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_job_struct new_wlan_job;
    srv_dtcnt_wlan_conn_prof_struct *srv_profs;
    U32 srv_len = 0, i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONNECT_REQ_BY_AP, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state());

    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        srv_dtcnt_wlan_conn_res_struct *conn_res;
        conn_res = OslMalloc(sizeof(srv_dtcnt_wlan_conn_res_struct));
         conn_res->result = SRV_DTCNT_RESULT_FAILED;
        if( callback != NULL )
        {
            callback(user_data, conn_res);
        }
        srv_dtcnt_wlan_post_conn_res_event(conn_res, EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND);
        OslMfree(conn_res);
        return SRV_DTCNT_RESULT_FAILED;

    }

    if (!app_profs)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    if (callback)
    {
        new_wlan_job.cb_func_ptr = (void *)callback;
        new_wlan_job.user_data = user_data;
    }
    
    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_INIT, NULL, NULL);
            break;

        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT) == NULL)
            {
                srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT, NULL, NULL);
            }
            break;

        case SRV_DTCNT_WLAN_STATE_INIT:
        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
            break;

        default:
            return SRV_DTCNT_RESULT_STATE_ERROR;
    }

    srv_len = sizeof(srv_dtcnt_wlan_conn_prof_struct) + (sizeof(srv_dtcnt_prof_wlan_struct) + sizeof(srv_dtcnt_prof_wlan_struct *)) * app_profs->num_prof + sizeof(srv_dtcnt_prof_wlan_struct **);
    srv_profs = (srv_dtcnt_wlan_conn_prof_struct *)OslMalloc(srv_len);
    memset(srv_profs, 0, srv_len);
    
    srv_profs->num_prof = app_profs->num_prof;
    srv_profs->connect_type = app_profs->connect_type;
    srv_profs->prof_data = (srv_dtcnt_prof_wlan_struct **)((char *)srv_profs + sizeof(srv_dtcnt_wlan_conn_prof_struct));

    for (i = 0; i < app_profs->num_prof; i++)
    {
        srv_profs->prof_data[i] = (srv_dtcnt_prof_wlan_struct *)((char *)srv_profs->prof_data + 
                                sizeof(srv_dtcnt_prof_wlan_struct **) + 
                                (sizeof(srv_dtcnt_prof_wlan_struct) + 
                                sizeof(srv_dtcnt_prof_wlan_struct *)) * i);
        memcpy(srv_profs->prof_data[i],  app_profs->prof_data[i], sizeof(srv_dtcnt_prof_wlan_struct));
    }

    if (callback)
    {
        srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_CONNECT, srv_profs, &new_wlan_job);
    }
    else
    {
        srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_CONNECT, srv_profs, NULL);
    }
    return SRV_DTCNT_RESULT_PROCESSING;
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__*/
    return SRV_DTCNT_RESULT_STATE_ERROR;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    srv_dtcnt_wlan_job_struct new_wlan_job;
    new_wlan_job.cb_func_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DISCONNECT_REQ, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state());
    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        srv_dtcnt_wlan_post_disc_res_event(SRV_DTCNT_WLAN_REQ_RES_FAILED);
        return SRV_DTCNT_RESULT_FAILED;
    }

    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
        case SRV_DTCNT_WLAN_STATE_INIT:
        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            srv_dtcnt_wlan_post_disc_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);            
            return SRV_DTCNT_RESULT_SUCCESS;

        case SRV_DTCNT_WLAN_STATE_CONNECTED:
        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
            srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DISCONNECT, NULL, &new_wlan_job);
            return SRV_DTCNT_RESULT_PROCESSING;
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_CONNECT) != NULL)
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_CONNECT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
                if(!g_srv_dtcnt_wlan_ctx.proc_job_list)
                {
                    srv_dtcnt_wlan_append_proc_job(&new_wlan_job);
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_WLAN_DISCONNECT_REQ_APPEND_PROC_JOB);
                }

            }
            return SRV_DTCNT_RESULT_IGNORE;

        default:
            return SRV_DTCNT_RESULT_STATE_ERROR;            
    }
#else /* !__MMI_WLAN_FEATURES__ || !__MTAK_TARGET__ || !__TCPIP__ */
    return SRV_DTCNT_RESULT_STATE_ERROR;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */
}

/* For detail description please refer to DtcntSrvIprot.h */
void srv_dtcnt_wlan_init_profile(srv_dtcnt_prof_wlan_struct *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    memset(profile, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    profile->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
    profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
    profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
    profile->eap_auth_type = WLAN_EAP_TLS;
    #ifdef WLAN_EAP_AKA_SUPPORT
        profile->eap_auth_type |= WLAN_EAP_AKA;
    #endif
#ifdef WLAN_EAP_PEAP_SUPPORT
    profile->eap_peap_auth_type = WLAN_EAP_TLS;
#endif
#ifdef WLAN_EAP_TTLS_SUPPORT
#if defined(WLAN_EAP_SIM_SUPPORT) && defined(WLAN_EAP_AKA_SUPPORT)
    profile->eap_ttls_auth_type = WLAN_EAP_SIM;
    profile->eap_ttls_auth_type |= WLAN_EAP_AKA;
#else
    profile->eap_ttls_auth_type = WLAN_EAP_TLS;
#endif
#endif
    profile->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64;
    profile->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX;
    profile->peap_version = SUPC_PHASE1_PEAP_0 | SUPC_PHASE1_PEAP_1;
    profile->use_dhcp = MMI_TRUE;
#endif /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */  
}

void srv_dtcnt_wlan_auth_cancel(void)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    srv_dtcnt_wlan_disconnect();
#endif
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_set_power_mode(
                        srv_dtcnt_wlan_power_mode_enum pwr_mode,
                        srv_dtcnt_wlan_cb_func_ptr callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SET_POWER_MODE, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state(), pwr_mode);

    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        if (callback != NULL)
        {
            callback(user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
        }
        return SRV_DTCNT_RESULT_FAILED;
    }

        if(g_srv_dtcnt_wlan_ctx.set_pwr_mode_job != NULL)
        {
            return SRV_DTCNT_RESULT_SUCCESS;
        }
        if(callback != NULL)
        {
            g_srv_dtcnt_wlan_ctx.set_pwr_mode_job = OslMalloc(sizeof(srv_dtcnt_wlan_job_struct));
            g_srv_dtcnt_wlan_ctx.set_pwr_mode_job->cb_func_ptr = (void *)callback;
            g_srv_dtcnt_wlan_ctx.set_pwr_mode_job->user_data = user_data;
        }

        srv_dtcnt_wlan_set_ps_mode_req(pwr_mode);
        
        return SRV_DTCNT_RESULT_PROCESSING;
#else /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */  

    return SRV_DTCNT_RESULT_FAILED;

#endif
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_get_power_mode(
                        srv_dtcnt_wlan_power_mode_enum *out_pwr_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_GET_POWER_MODE, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state(), out_pwr_mode);

    *out_pwr_mode = g_srv_dtcnt_wlan_setting_ctx.pwr_mode;

    return SRV_DTCNT_RESULT_SUCCESS;
#else /* __MMI_WLAN_FEATURES__ && __MTK_TARGET__ && __TCPIP__ */  

    return SRV_DTCNT_RESULT_FAILED;

#endif
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_add_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *exclusive_ip_addr)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S16 error;
    U16 length = 0;
    U16 length_store = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (exclusive_ip_addr == NULL || (length = strlen((const char *)exclusive_ip_addr->ip_addr))==0 )
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }
    kal_wap_trace(MOD_MMI_CONN_APP,MMI_CONN_TRC_G6_DTCNT,"[DA SRV API]add URL: %s",exclusive_ip_addr->ip_addr);    
    
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM; i++)
    {
        length_store = strlen((const char *)g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr);
        if(length == length_store && 
            strncmp((const char *)exclusive_ip_addr->ip_addr,
            (const char *)g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr,length)==0)
        {
            return SRV_DTCNT_RESULT_SUCCESS;
        }
        if ( length_store == 0 )
        {
            memcpy(&g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
                   exclusive_ip_addr,
                   sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct));
            g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips++;

            // Write to NVRAM
            if (WriteRecord(NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID,
                            (U16)(i + 1),
                            (void*)&g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
                            NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE,
                            &error) < NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE)
            {
                MMI_ASSERT(0);
            }
            
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM,
                      g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips);
            
            return SRV_DTCNT_RESULT_SUCCESS;
        }
    }
    
    return SRV_DTCNT_RESULT_FAILED;
#else
    return SRV_DTCNT_RESULT_FAILED;
#endif

}


/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_delete_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *exclusive_ip_addr)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S16 error;
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/              
    if (exclusive_ip_addr == NULL || (length = strlen((const char *)exclusive_ip_addr->ip_addr))==0 )
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }
    kal_wap_trace(MOD_MMI_CONN_APP,MMI_CONN_TRC_G6_DTCNT,"[DA SRV API]delete URL: %s",exclusive_ip_addr->ip_addr); 
    for (i = 0; i < g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips; i++)
    {
        if (strlen((const char *)g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr)== length
            && strncmp((const char *)exclusive_ip_addr->ip_addr,
                   (const char *)g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr,
                   length) == 0)
        {
            break;
        }
    }
    
    /* cannot find matched IP */
    if (i == g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }
    /* find matched IP */
    else
    {
        g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips--;
        
        for (; i < g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips; i++)
        {
            memcpy(&g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
                   &g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i+1],
                   sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct));
            // Write to NVRAM
            if (WriteRecord(NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID,
                            (U16)(i + 1),
                            (void*)&g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
                            NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE,
                            &error) < NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE)
            {
                MMI_ASSERT(0);
            }
        }
        memset(&g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
               0,
               sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct));
        // Write to NVRAM
        if (WriteRecord(NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID,
                        (U16)(i + 1),
                        (void*)&g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
                        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE,
                        &error) < NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE)
        {
            MMI_ASSERT(0);
        }
        
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM,
                  g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips);
        
        return SRV_DTCNT_RESULT_SUCCESS;
    }
#else
    return SRV_DTCNT_RESULT_FAILED;
#endif
}

/* For detail description please refer to DtcntSrvIprot.h */
srv_dtcnt_result_enum srv_dtcnt_wlan_qry_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *qry_list)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_QRY_PROXY_EXCLUSIVE_IP_ADDR, qry_list);
    

    if (qry_list == NULL)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM,
              g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips);
    
    memset(qry_list, 0, sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct));
   
    for (i = 0; i < g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips; i++)
    {
        memcpy(&qry_list->ips[i],
               &g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
               sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct));
    }
    qry_list->num_ips = g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM,
          g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips);    
    return SRV_DTCNT_RESULT_SUCCESS;
#else
    return SRV_DTCNT_RESULT_FAILED;
#endif
}


void srv_dtcnt_wlan_send_portal_login_start_req(U8 app_id)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    mmi_abm_wifi_portal_login_start_req_struct *p;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SEND_LOGIN_START_REQ_TO_ABM,app_id);

    SetProtocolEventHandler(srv_dtcnt_wlan_portal_login_start_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_START_CNF);
    p = (mmi_abm_wifi_portal_login_start_req_struct*) OslConstructDataPtr(sizeof(mmi_abm_wifi_portal_login_start_req_struct));
    p->app_id = app_id;
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_START_REQ, (oslParaType *)p, NULL);
#endif
}
void srv_dtcnt_wlan_send_portal_logout_req(void)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SEND_LOGOUT_REQ_TO_ABM);

    SetProtocolEventHandler(srv_dtcnt_wlan_portal_logout_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_PORTAL_LOGOUT_CNF);
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_PORTAL_LOGOUT_REQ, NULL, NULL);
#endif
}
void srv_dtcnt_wlan_send_portal_login_stop_req(MMI_BOOL result)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    mmi_abm_wifi_portal_login_stop_req_struct *p;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SEND_LOGIN_STOP_REQ_TO_ABM,result);

    SetProtocolEventHandler(srv_dtcnt_wlan_portal_login_stop_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_STOP_CNF);
    p = (mmi_abm_wifi_portal_login_stop_req_struct*) OslConstructDataPtr(sizeof(mmi_abm_wifi_portal_login_stop_req_struct));
    p->result = result;
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_STOP_REQ, (oslParaType *)p, NULL);
#endif
}
MMI_BOOL srv_dtcnt_wlan_in_blacklist(supc_abm_bss_info_struct * scan_ap)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__) && defined(__MMI_OP01_WIFI__)
    srv_dtcnt_wlan_network_type_enum network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_TOTAL;
    srv_dtcnt_wlan_auth_mode_enum auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_TOTAL;        
    //srv_dtcnt_wlan_encrypt_mode_enum encrypt_mode; 
    U32 ap_num = g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num + g_srv_dtcnt_wlan_setting_ctx.infra_prof_num;
    U32 i = 0;  
    switch (scan_ap->network_type)
    {
        case WNDRV_SUPC_NETWORK_AUTO_UNKNOWN:
            network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
            break;
        case WNDRV_SUPC_NETWORK_IBSS:
            network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC;
            break;
        case WNDRV_SUPC_NETWORK_INFRASTRUCTURE:
            network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
            break;
    }
    if (scan_ap->rsn_ie_info_p == MMI_TRUE)
    {
        if(scan_ap->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_PSK || 
            scan_ap->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE )
        {
            auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
        }
        if(scan_ap->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_IEEE8021X)
        {
            auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY;
        }
    }
    else if(scan_ap->wpa_ie_info_p == MMI_TRUE)
    {
        if(scan_ap->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK || 
            scan_ap->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE )
        {
            auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK;
        }
        if(scan_ap->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_IEEE8021X)
        {
            auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY;
        }
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if(scan_ap->wapi_ie_info_p == MMI_TRUE)
    {
        if(scan_ap->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (scan_ap->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_PSK)
            {
                auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK;
            }
            else if (scan_ap->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_WAI)
            {
                auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT;
            }
        }
    }
#endif
#endif
    else if(scan_ap->privacy > 0)
    {
        if(scan_ap->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
        }
        else if (scan_ap->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        }
    }
    else
    {
        auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
    }
    for(i = 0; i < ap_num; i++)
    {
        if(g_srv_dtcnt_wlan_prof_list_p[i]->ssid_len == scan_ap->ssid_len &&
            !strncmp((const char *)g_srv_dtcnt_wlan_prof_list_p[i]->ssid, (const char *)scan_ap->ssid, scan_ap->ssid_len) &&
            auth_mode == g_srv_dtcnt_wlan_prof_list_p[i]->auth_mode &&
            network_type == g_srv_dtcnt_wlan_prof_list_p[i]->network_type)
        {
            if(g_srv_dtcnt_wlan_prof_list_p[i]->ap_type == SRV_DTCNT_WLAN_AP_BLACK_LIST)
            {
                return MMI_TRUE;
            }
        }
    }
#endif
    return MMI_FALSE;
}

MMI_BOOL srv_dtcnt_get_wlan_prefer_setting(srv_dtcnt_wlan_prefer_struct * wlan_prefer_ctx)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__)

    if(wlan_prefer_ctx == NULL)
    {
        return MMI_FALSE;
    }
    memcpy(wlan_prefer_ctx, &g_srv_dtcnt_wlan_prefer_ctx, sizeof(srv_dtcnt_wlan_prefer_struct));
    return MMI_TRUE;
#else

    return MMI_FALSE;

#endif
}
MMI_BOOL srv_dtcnt_set_wlan_prefer_setting(srv_dtcnt_wlan_prefer_struct *wlan_prefer_ctx)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__)
    S32 size = 0;
    S16 error = 0;

    if(wlan_prefer_ctx == NULL)
    {
        return MMI_FALSE;
    }    
    memcpy(&g_srv_dtcnt_wlan_prefer_ctx, wlan_prefer_ctx, sizeof(srv_dtcnt_wlan_prefer_struct));
    
    size = WriteRecord(
                NVRAM_EF_CMCC_WIFI_SETTING_LID, 
                1, 
                (void*)&g_srv_dtcnt_wlan_prefer_ctx, 
                NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
                (S16 *)&error);

    if(size < NVRAM_MAX_CMCC_WIFI_SETTING_SIZE)
    {
        MMI_ASSERT(0);
    }
    return MMI_TRUE;
#else

    return MMI_FALSE;

#endif
}
#define DTCNT_PROPRIETARY_SRV_APIs
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_is_valid_hexstring
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_is_valid_hexstring(U8 *src, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        if (src[i] >= '0' && src[i] <= '9')
        {
            continue;
        }
        else if (src[i] >= 'A' && src[i] <= 'F')
        {
            continue;
        }
        else if (src[i] >= 'a' && src[i] <= 'f')
        {
            continue;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_hex_to_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [?]         
 *  src         [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_hex_to_string(U8 *dest, U8 *src, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len % 2 != 0)
    {
        return MMI_FALSE;
    }

    kal_mem_set(dest, 0, len / 2 + 1);

    for (i = 0, j = 0; i < len; i++)
    {
        j = (i - i % 2) / 2;
        if (src[i] >= '0' && src[i] <= '9')
        {
            dest[j] += (src[i] - '0') << 4 * ((i + 1) % 2);
        }
        else if (src[i] >= 'A' && src[i] <= 'F')
        {
            dest[j] += (src[i] - 'A' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else if (src[i] >= 'a' && src[i] <= 'f')
        {
            dest[j] += (src[i] - 'a' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_set_default_acc
 * DESCRIPTION
 *  To get specified account as the default account for auto selection
 * PARAMETERS
 *  acc_id      :   [IN]        specified account ID.
 * RETURNS
 *  MMI_TRUE    :   Set successfully
 *  MMI_FALSE   :   Set failed
 *****************************************************************************/
MMI_BOOL srv_dtcnt_set_default_acc(U32 acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    #ifdef __DTCNT_SIM_PROFILES_SUPPORT__ 
    int fs_err, written;
    #endif
    U8 temp_def_acc_idx, temp_bak_acc_idx;
    srv_dtcnt_sim_type_enum sim_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __TCPIP__
    return MMI_FALSE;
#else

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_API_SET_DEFAULT_ACC_ID, acc_id);
SRV_DTCNT_GLOBAL_LOCK;

    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == acc_id)            
        {        
            sim_info = g_srv_dtcnt_store_ctx.acc_list[i].sim_info;
            temp_def_acc_idx = (U8)g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1];
            temp_bak_acc_idx = (U8)g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1];
            if (temp_def_acc_idx && temp_def_acc_idx <= SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
            {
                g_srv_dtcnt_store_ctx.acc_list[temp_def_acc_idx-1].app_type &= ~DTCNT_APPTYPE_DEF;
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = i+1;
                g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1] = 0;
                g_srv_dtcnt_store_ctx.acc_list[i].app_type |= DTCNT_APPTYPE_DEF;                
            }
            else
            {
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = i+1;
                g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1] = 0;
                g_srv_dtcnt_store_ctx.acc_list[i].app_type |= DTCNT_APPTYPE_DEF;
            }

            if (!srv_dtcnt_db_fileio_write_store_info_file())
            {

                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = temp_def_acc_idx;
                g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1] = temp_bak_acc_idx;
                if (g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] && 
                    g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] <= SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
                {
                    g_srv_dtcnt_store_ctx.acc_list[temp_def_acc_idx-1].app_type |= DTCNT_APPTYPE_DEF;
                }                
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_FALSE;
            }
            else
            {
                srv_dtcnt_db_store_send_acc_update_post_evt(g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                                            0, 2);  
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_TRUE;
            }
        }
    }

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
    for (i = 0; i < MAX_CSD_SIM_PROV_NUM; i++)
    {
        if (csd_sim_acc_list[i].comm_header.in_use &&
            csd_sim_acc_list[i].comm_header.acc_id == acc_id)            
        {        
            sim_info = csd_sim_acc_list[i].comm_header.sim_info;
            temp_def_acc_idx = (U8)g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1];
            temp_bak_acc_idx = (U8)g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1];        
            if (g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] && g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] <= SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
            {
                g_srv_dtcnt_store_ctx.acc_list[temp_def_acc_idx-1].app_type &= ~DTCNT_APPTYPE_DEF;
                g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1] = temp_def_acc_idx;
            }
            else
            {                
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM+i+1;
            }
            fs_err = FS_Write(g_srv_dtcnt_context.info_file_fp, &(g_srv_dtcnt_store_ctx), sizeof(srv_dtcnt_store_info_context), (UINT *)&written);
            if (fs_err < FS_NO_ERROR || written != sizeof(srv_dtcnt_store_info_context))
            {
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = temp_def_acc_idx;
                g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1] = temp_bak_acc_idx;
                if (g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] && 
                    g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] <= SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
                {
                    g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1]-1].app_type &= DTCNT_APPTYPE_DEF;
                }                
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_FALSE;
            }
            else
            {
                srv_dtcnt_db_store_send_acc_update_post_evt(g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                                            0, 2);
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_TRUE;
            }            
        }
    }
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
    for (i = 0; i < MAX_GPRS_SIM_PROV_NUM; i++)
    {
        if (gprs_sim_acc_list[i].comm_header.in_use &&
            gprs_sim_acc_list[i].comm_header.acc_id == acc_id)
        {        
            sim_info = gprs_sim_acc_list[i].comm_header.sim_info;
            temp_def_acc_idx = (U8)g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1];
            temp_bak_acc_idx = (U8)g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1];        
            if (g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1]&& g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] <= SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
            {
                g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1]-1].app_type &= ~DTCNT_APPTYPE_DEF;
                g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1] = temp_def_acc_idx;
            }
            else
            {                
            #ifdef __TCPIP_OVER_CSD__
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM+MAX_CSD_SIM_PROV_NUM+SRV_DTCNT_RESERVED_DM_ACC_NUM+i+1;
            #else /* !__TCPIP_OVER_CSD__ */
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM+SRV_DTCNT_RESERVED_DM_ACC_NUM+i+1;
            #endif /* __TCPIP_OVER_CSD__ */            
            }

            if (!srv_dtcnt_db_fileio_write_store_info_file())
            {
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = temp_def_acc_idx;
                g_srv_dtcnt_store_ctx.backup_acc_idx[sim_info-1] = temp_bak_acc_idx;
                if (g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] && 
                    g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] <= SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
                {
                    g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1]-1].app_type &= DTCNT_APPTYPE_DEF;
                }                
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_FALSE;
            }
            else
            {
                srv_dtcnt_db_store_send_acc_update_post_evt(g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                                            0, 2);
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_TRUE;
            }
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

SRV_DTCNT_GLOBAL_UNLOCK;
    return MMI_FALSE;
#endif /* __TCPIP__ */

}

MMI_BOOL srv_dtcnt_get_default_account(srv_dtcnt_sim_type_enum sim_id, U32 * account_id)
{
    MMI_BOOL ret;
    int i = 0;
    int gprs_id = 0xFF;
    int csd_id = 0xFF;
    int default_index = 0;
    
    #ifndef __TCPIP__
        return MMI_FALSE;
    #else
    SRV_DTCNT_GLOBAL_LOCK;
        ret = srv_dtcnt_db_store_status_check();
        if(!ret)
        {
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_FALSE;
        }
        default_index = g_srv_dtcnt_store_ctx.default_acc_idx[sim_id-1];
        if(default_index != 0)
        {
            if(g_srv_dtcnt_store_ctx.acc_list[default_index-1].in_use != 0)
            {
                *account_id = default_index - 1;
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_TRUE;
        }
        else
        {
                g_srv_dtcnt_store_ctx.acc_list[default_index-1].app_type &= ~DTCNT_APPTYPE_DEF;
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_id-1] = 0;
            }

        }
            for(i=0; i<SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
            {
            if(g_srv_dtcnt_store_ctx.acc_list[i].sim_info == sim_id
                && g_srv_dtcnt_store_ctx.acc_list[i].in_use != 0)
                {
                    if(g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS )
                    {
                        gprs_id = i;
                        break;
                    }
                    else if(g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_CSD )
                    {
                        csd_id = i;
                    }
                }
            }
            if(gprs_id != 0xFF)
            {
                i = gprs_id;
            }
            else if(csd_id != 0xFF)
            {
                i = csd_id;
            }
            else 
            {
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_FALSE;
            }
            g_srv_dtcnt_store_ctx.acc_list[i].app_type |= DTCNT_APPTYPE_DEF;
            g_srv_dtcnt_store_ctx.default_acc_idx[sim_id-1] = i+1;
            if(!srv_dtcnt_db_fileio_write_store_info_file())
            {
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_id-1] = 0;
                g_srv_dtcnt_store_ctx.acc_list[i].app_type &= ~DTCNT_APPTYPE_DEF;
                SRV_DTCNT_GLOBAL_UNLOCK;
                return MMI_FALSE;                        
            }
            *account_id = i;
            SRV_DTCNT_GLOBAL_UNLOCK;
            return MMI_TRUE;
#endif /* __TCPIP__ */

}

