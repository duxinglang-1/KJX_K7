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
 * SyncSrvRemoteAccntOTA.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Support SyncML OTA from CCA
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "MMIDataType.h"

#include "cbm_api.h"
#include "app_url.h"
#include "conversions.h"

#include "mmi_rp_srv_sync_def.h"
#include "syncml_common_customize.h"
#include "mmi2syncml_struct.h"

#include "DtcntSrvGprot.h"
#include "CcaSrvGprot.h"
#include "NwUsabSrvGprot.h"

#include "SyncSrvDataBaseCfg.h"
#include "SyncSrvDatabase.h"
#include "SyncSrvGprot.h"
#include "SyncSrvRemoteAccnt.h"
#include "SyncSrvRemoteAccntOTA.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef 
 *****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static const U16 srv_sync_ota_cca_map_tbl[] = 
 {
	CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, 
		MMI_CCA_NS_SYNCML_PROXY,0xFFFF,
	CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, 
		MMI_CCA_NS_SYNCML_PORT, 0xFFFF,
	CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, 
		MMI_CCA_NS_SYNCML_PXAUTHINFO, 0xFFFF, 
	CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF,
		MMI_CCA_NS_SYNCML_NAPDEF, 0xFFFF,
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP,
		MMI_CCA_NS_SYNCML_BOOTSTRAP, 0xFFFF,
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
	CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION,
		MMI_CCA_NS_SYNCML_APPLICATION, 0xFFFF,
	CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR,
		MMI_CCA_NS_SYNCML_APPADDR, 0xFFFF,
	CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH, 
		MMI_CCA_NS_SYNCML_APPAUTH, 0xFFFF,
	CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_RESOURCE,
		MMI_CCA_NS_SYNCML_RESOURCE,0xFFFF
 };

static const WCHAR* srv_sync_ota_dup_str[MAX_SYNCML_SV_PROFILES] =
{
	L"_1", L"_2", L"_3", L"_4", L"_5"
};

static srv_sync_ota_cntx_struct *g_srv_sync_ota_cntx;

/*****************************************************************************
* Global Function 
*****************************************************************************/
extern CHAR *syncml_itoa(S32 value, CHAR *s, S32 radix);
extern int applib_url_check_ip(const char* addr , int len);

/*****************************************************************************
* Local Function 
*****************************************************************************/
static void srv_sync_ota_destroy(srv_sync_ota_cntx_struct *obj);

static mmi_sim_enum srv_sync_ota_sim_cbm2cca(cbm_sim_id_enum cbm_sim_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_sim_enum new_sim_id = MMI_SIM1;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch(cbm_sim_id)
	{
		case CBM_SIM_ID_SIM1:
			new_sim_id = MMI_SIM1;
			break;
		case CBM_SIM_ID_SIM2:
			new_sim_id = MMI_SIM2;
			break;
		case CBM_SIM_ID_SIM3:
			new_sim_id = MMI_SIM3;
			break;
		case CBM_SIM_ID_SIM4:
			new_sim_id = MMI_SIM4;
			break;
		default:
			break;
	}
	return new_sim_id;
}

static cbm_sim_id_enum srv_sync_ota_sim_cca2cbm(mmi_sim_enum cca_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum new_sim_id = CBM_SIM_ID_SIM1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cca_sim_id == MMI_SIM_NONE)
    {
        cca_sim_id = srv_nw_usab_get_one_usable_sim();
    }

    switch(cca_sim_id)
    {
        case MMI_SIM1:
            new_sim_id = CBM_SIM_ID_SIM1;
            break;
        case MMI_SIM2:
            new_sim_id = CBM_SIM_ID_SIM2;
            break;
        case MMI_SIM3:
            new_sim_id = CBM_SIM_ID_SIM3;
            break;
        case MMI_SIM4:
            new_sim_id = CBM_SIM_ID_SIM4;
            break;
        default:
            break;
    }
    
    return new_sim_id;
}

static void srv_sync_ota_config_rsp(srv_sync_ota_cntx_struct *obj, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data = OslAllocDataPtr(srv_cca_app_configure_rsp_struct);

	if (obj != NULL)
	{
    	data->sim_id = (U16)srv_sync_ota_sim_cbm2cca((cbm_sim_id_enum)obj->sim_id);
    	data->config_id = obj->conf_id;
    	data->hConfig   = obj->doc_hdl;
	}
	
    data->status = status;

	mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType *)data, NULL);
}

MMI_BOOL srv_sync_ota_is_empty_accnt(U8 accnt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *old_nvram_prof;
    U32 i;
    
    MMI_BOOL ret = MMI_TRUE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < g_srv_sync_ota_cntx->num_profiles; i++)
    {
        if (g_srv_sync_ota_cntx->dst_idx[i] == accnt_index)
        {
            return MMI_FALSE; 
        }
    }
    
    old_nvram_prof = (mmi_syncml_account_struct *)OslMalloc(sizeof(mmi_syncml_account_struct));

	srv_sync_read_accnt_buffer(old_nvram_prof, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, accnt_index);

    if (old_nvram_prof->timestamp != 0 
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		&& !old_nvram_prof->read_only
#endif
	)
    {
 	ret = MMI_FALSE;
    }
		
    OslMfree(old_nvram_prof);

    return ret;
}

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_update_match
 * DESCRIPTION
 *  Only update the first matched profile.
 * PARAMETERS
 *  mmi_syncml_account_struct		[IN]		new profile  
 * RETURNS
 *  U8 profile id 
 *****************************************************************************/
static U8 srv_sync_ota_is_update_match(mmi_syncml_account_struct *new_prof, void* usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_ota_cntx_struct *cntx;
    mmi_syncml_account_struct *tmp_prof = NULL;
	MMI_BOOL match_flag = MMI_FALSE;
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_prof != NULL && usr_data != NULL);
	cntx = (srv_sync_ota_cntx_struct*)usr_data;
	
	if (strlen((CHAR*)cntx->prov_url_hash) == 0 &&
		strlen((CHAR*)new_prof->proxy_id_hash) == 0)
	{	
		return SYNCML_INVALID_IDX;
	}
    
	tmp_prof = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
	/* Only update the first matched profile */
	for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
	{
		/* The old profile is empty */
		if (srv_sync_ota_is_empty_accnt(i))
		{
			continue;
		}

		srv_sync_read_accnt_buffer(tmp_prof, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, i);

		/* Any one is empty, don't match */
		if (strlen((CHAR*)tmp_prof->prov_url_hash) == 0 || strlen((CHAR*)cntx->prov_url_hash) == 0)
		{
			continue;
		}
			
		/* check prov url */
		if (memcmp(tmp_prof->prov_url_hash, cntx->prov_url_hash, sizeof(U8) * MAX_SYNCML_HASH_BUF_LEN) != 0)
		{
			continue;
		}
		
		/* New ID is the same the old one and both are valid ? */
		if (strlen((CHAR*)tmp_prof->proxy_id_hash) > 0 && 
			strlen((CHAR*)new_prof->proxy_id_hash) > 0 && 
			memcmp(tmp_prof->proxy_id_hash, new_prof->proxy_id_hash, sizeof(U8) * MAX_SYNCML_HASH_BUF_LEN) == 0)
		{
			match_flag = MMI_TRUE;
		}
		/* Old ID is invalid? */
		else if ((strlen((CHAR*)tmp_prof->proxy_id_hash) > 0))
		{
			continue;
		}
		/* Name match? */
		else if (mmi_ucs2strlen((CHAR*)tmp_prof->account_name) > 0 &&
				 mmi_ucs2strlen((CHAR*)new_prof->account_name) > 0 &&
			     mmi_ucs2cmp((CHAR*)tmp_prof->account_name, (CHAR*)new_prof->account_name) == 0)
		{
			match_flag = MMI_TRUE;
		}
		else
		{
			/* nothing */
			continue;
		}
		
		if (match_flag)
		{
			if (tmp_prof->type != MMI_SYNCML_ACCOUNT_TYPE_FACTORY)
			{
                OslMfree(tmp_prof);
				return i;
			}
			/* factory preconfigured and the flag in prov_flag indicate the SEC type is USERNETWPIN */
			else if (g_srv_sync_ota_cntx->prov_flag & MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE)
			{
			    if (tmp_prof != NULL)
                {
                    OslMfree(tmp_prof);
                }
				return i;
			}
			else
			{
				break;
			}
		}
	}
    
    if (tmp_prof != NULL)
    {
        OslMfree(tmp_prof);
    }

	return SYNCML_INVALID_IDX;
}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_valid_profile_num
 * DESCRIPTION
 *  This function checks if there is any valid profile. every valid coming profile
 *  can be active.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U32 srv_sync_ota_get_valid_profile_num(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_ota_db_info_struct *db_info;
    nvram_ef_syncml_account_struct *new_prof;
    U32 num_prof = 0; /* sanity check for valid profile */
	U32 i, j;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    g_srv_sync_ota_cntx->total_valid = 0;
	
	for (i = 0; i < g_srv_sync_ota_cntx->num_profiles; i++)
	{
	    new_prof = g_srv_sync_ota_cntx->profile[i];

	    if (new_prof != NULL && g_srv_sync_ota_cntx->isvalidprof[i])
		{
		    if (applib_url_is_valid((const char *)new_prof->server_address) != 0 ||
				strcmp((CHAR*)new_prof->server_address, (CHAR*)"http://") == 0)
			{
				g_srv_sync_ota_cntx->isvalidprof[i] = MMI_FALSE;
                new_prof->account_validation &= ~MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
				
				MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PARSE_ERROR_SERVER_IP, i);
				
                continue; /* to check the next buffered profile */
			}
            else
            {
			    new_prof->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_SVR;
            }

			db_info = g_srv_sync_ota_cntx->db_info;
			new_prof->app_to_sync = 0;
			/* check all database address validation. */
		  	for (j = 0; j < srv_sync_get_database_count(); j++)
		  	{
	            if (strlen((CHAR *)new_prof->database_address[db_info[j].id]) == 0 ||
	                strcmp((CHAR *)new_prof->database_address[db_info[j].id], (CHAR *)"./") == 0)
	            {   
	                new_prof->account_validation &= ~db_info[j].valid_mask;
				} 
	            else 
	            {
	                new_prof->account_validation |= db_info[j].valid_mask;
					new_prof->app_to_sync |= db_info[j].db_mask;
	            } 		
		  	}
			
			if (new_prof->app_to_sync == 0)
			{
				continue;
			}
			
            MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_GET_VALID_PROFILE_NUM, i, new_prof->account_validation);

            if (g_srv_sync_ota_cntx->isvalidprof[i] &&
				!(g_srv_sync_ota_cntx->opr_flag & SYNCML_OTA_OPR_DM_UPDATE_MASK))
            {
            #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            	U8 update_prof_idx;
                
				update_prof_idx = srv_sync_ota_is_update_match(new_prof, (void*)g_srv_sync_ota_cntx);
                
                MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_IS_UPDATE_MATCH_RETURN, update_prof_idx);

                if (update_prof_idx != SYNCML_INVALID_IDX)
				{
					/*
					 * If the profile is in use, and can be update, then set it to false.
					 */
					g_srv_sync_ota_cntx->dst_idx[i] = update_prof_idx;
				}
			#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
				g_srv_sync_ota_cntx->total_valid++;	
            }

            num_prof++;
		}

	} /* for num_profiles */
    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_VALID_PROF_NUM, g_srv_sync_ota_cntx->total_valid, num_prof);

    return num_prof;
}

static srv_sync_ota_status_check(U16 cca_status)
{
	switch(cca_status)
	{
		case SRV_CCA_STATUS_OK:
			g_srv_sync_ota_cntx->opr_flag |= SYNCML_OTA_OPR_INSTALL_MASK;
			break;
			
		case SRV_CCA_STATUS_SETTING_UPDATED:
			g_srv_sync_ota_cntx->opr_flag |= SYNCML_OTA_OPR_UPDATE_MASK;
			break;
			
		case SRV_CCA_STATUS_SETTING_SKIPPED:
			g_srv_sync_ota_cntx->opr_flag |= SYNCML_OTA_OPR_SKIP_MASK;
			break;
			
		case SRV_CCA_STATUS_ENDKEY_PRESSED:
			g_srv_sync_ota_cntx->opr_flag |= SYNCML_OTA_OPR_KEY_END_MASK;
			break;
			
		default:
			break;
	}
}

MMI_BOOL srv_sync_ota_check_exist_accnt_name(
			mmi_syncml_account_struct *new_account, 
			U32 dest_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *accnt_name;
	U32 len;
	U32 j = 0, i = 0;
	MMI_BOOL flag = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	do
	{
		accnt_name = (U8 *)g_srv_sync_ota_cntx->currentprofnamelist[i];
		if ((dest_index != i) &&
			(mmi_ucs2cmp((const CHAR *)new_account->account_name, (const CHAR *)accnt_name) == 0))
		{
			len = mmi_ucs2strlen((const CHAR *)new_account->account_name);
			/* clear the last two char */
			if (len >= (MAX_SYNCML_PROFILE_NAME - 3) ||
				flag)
			{
				new_account->account_name[(len - 2) * ENCODING_LENGTH] = 0;
				new_account->account_name[(len - 2) * ENCODING_LENGTH + 1] = 0;
				new_account->account_name[(len - 1) * ENCODING_LENGTH] = 0;
				new_account->account_name[(len - 1) * ENCODING_LENGTH + 1] = 0;
			}
			
			mmi_ucs2cat((CHAR *)new_account->account_name, (CHAR *)srv_sync_ota_dup_str[j]);
			j++;
			flag = MMI_TRUE;
			i = 0; // need to re-check all the accouts.
			
			continue;
		}
		i++;
	}while(i < MAX_SYNCML_SV_PROFILES);

	return MMI_TRUE;
}

MMI_BOOL srv_sync_ota_install_new_accnt(U8 dest_index, U16 cca_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_account_struct *old_account = NULL;
    mmi_syncml_account_struct *new_account;
    U8 account_index = dest_index;
    U8 idx;
	U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(g_srv_sync_ota_cntx != NULL, MMI_FALSE);
	
	idx = g_srv_sync_ota_cntx->iter;
	
	SRV_SYNC_LOG2(MMI_SRV_SYNC_OTA_INSTALL, dest_index, cca_status);
	
	RETURN_VAL_IF_FAIL(idx < g_srv_sync_ota_cntx->num_profiles, MMI_FALSE);

	/* set status flag */
	srv_sync_ota_status_check(cca_status);
	
	if (cca_status == SRV_CCA_STATUS_SETTING_UPDATED)
	{
		account_index = g_srv_sync_ota_cntx->dst_idx[idx];
	}
	else if (cca_status == SRV_CCA_STATUS_SETTING_SKIPPED || cca_status == SRV_CCA_STATUS_ENDKEY_PRESSED)
	{
		return MMI_TRUE;
	}
	
    if (!g_srv_sync_ota_cntx->isvalidprof[idx]) 
    {
        return MMI_FALSE;
    }

	/* install new account data. */
    new_account = g_srv_sync_ota_cntx->profile[idx];  
    
    old_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
	srv_sync_read_accnt_buffer(old_account, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, account_index);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__	
	new_account->type = MMI_SYNCML_ACCOUNT_TYPE_OTA; /* provisioning type */
	new_account->read_only = old_account->read_only;
	memcpy(new_account->prov_url_hash, g_srv_sync_ota_cntx->prov_url_hash, MAX_SYNCML_HASH_BUF_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    /* save old account setting */
	//new_account->app_to_sync = old_account->app_to_sync;  
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    new_account->sync_type = old_account->sync_type;   
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif

    new_account->regular_sync = SRV_SYNC_REGULAR_NEVER;    
    new_account->sync_report_status = 0; 

    new_account->transport_type = MMI_SYNCML_TRANS_TYPE_INTERNET;

#if 0
/* under construction !*/
#endif

    OslMfree(old_account);
    
    /* here check the field of the valid profile */
    /* If default account name is "New Account, should set the default value "Account 1/2/3"" */
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

	srv_sync_ota_check_exist_accnt_name(new_account, dest_index);

    /* encode app id and sim id */
    new_account->net_id[g_srv_sync_ota_cntx->sim_id] = 
    	cbm_encode_data_account_id(
            new_account->net_id[g_srv_sync_ota_cntx->sim_id],/* raw data account id */
            (cbm_sim_id_enum)g_srv_sync_ota_cntx->sim_id,
            srv_sync_remote_app_id(),
            KAL_FALSE);                                 /* always ask feature */

	//for (i = 0; i < CBM_SIM_ID_TOTAL; i++)
	for (i = 0; i < 2; i++)
	{
		if (i == g_srv_sync_ota_cntx->sim_id)
		{
			continue;
		}
		new_account->net_id[i] = 
		cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID,
									(cbm_sim_id_enum)i,
									srv_sync_remote_app_id(),
									KAL_FALSE);
	}

	new_account->timestamp = srv_sync_get_current_time();
    srv_sync_write_accnt(SRV_SYNC_REMOTE, new_account, account_index);

    return MMI_TRUE;
}


S32 srv_sync_ota_next_accnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_NEXT_PROF );

	g_srv_sync_ota_cntx->iter++;
  
	while (g_srv_sync_ota_cntx->iter < g_srv_sync_ota_cntx->num_profiles)
	{		
		if (g_srv_sync_ota_cntx->isvalidprof[g_srv_sync_ota_cntx->iter])
		{
			return (S32)g_srv_sync_ota_cntx->iter;
		}

		g_srv_sync_ota_cntx->iter++;
	}
	
	return -1;
}

void srv_sync_ota_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RETURN_IF_FAIL(g_srv_sync_ota_cntx != NULL);
    
    /* Priority of these rsp enum:
     *      ENDKEY > UPDATED > OK > SKIPPED > INVALID */
	if (g_srv_sync_ota_cntx->opr_flag & SYNCML_OTA_OPR_KEY_END_MASK)
	{
		srv_sync_ota_config_rsp(g_srv_sync_ota_cntx, CCA_STATUS_ENDKEY_PRESSED);
	}
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__	
    /* When at leaset 1 profile is matched and updated successfully */
    else if (g_srv_sync_ota_cntx->opr_flag & SYNCML_OTA_OPR_UPDATE_MASK)
    {
        srv_sync_ota_config_rsp(g_srv_sync_ota_cntx, CCA_STATUS_SETTING_UPDATED);
    }    
#endif  /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    /* When at lease 1 profile has been installed successfylly and no profile is updated */
    else if ((g_srv_sync_ota_cntx->opr_flag & SYNCML_OTA_OPR_INSTALL_MASK) ||
			 (g_srv_sync_ota_cntx->opr_flag & SYNCML_OTA_OPR_REPLACE_MASK))
    {
        srv_sync_ota_config_rsp(g_srv_sync_ota_cntx, CCA_STATUS_OK);
    }
    /* When user skipped the installation of all profiles ,causing no profiles installed. */
    else if (g_srv_sync_ota_cntx->opr_flag & SYNCML_OTA_OPR_SKIP_MASK)
    {
        srv_sync_ota_config_rsp(g_srv_sync_ota_cntx, CCA_STATUS_SETTING_SKIPPED);
    }
    else
    {
        srv_sync_ota_config_rsp(g_srv_sync_ota_cntx, CCA_STATUS_ENDKEY_PRESSED);
    }

	srv_sync_ota_destroy(g_srv_sync_ota_cntx);
	g_srv_sync_ota_cntx = NULL;
}

static U32 srv_sync_ota_dbinfo_callback(U32 index, void *data, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item = (srv_sync_database_cfg_item_type *)data;
    srv_sync_ota_db_info_struct *db_info = (srv_sync_ota_db_info_struct *)usr_data;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	db_info[index].id = item->id;
	db_info[index].mime = item->mime;
	db_info[index].db_mask = item->type;

	return RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_create
 * DESCRIPTION
 *  This function allocates and initializes the control block of SYNCML OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static srv_sync_ota_cntx_struct *srv_sync_ota_create(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sync_ota_cntx_struct *obj;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_NEW_OTA_CNTX );
    obj = (srv_sync_ota_cntx_struct *)OslMalloc(sizeof(srv_sync_ota_cntx_struct));
    memset(obj, 0, sizeof(srv_sync_ota_cntx_struct));

    obj->conf_id = conf_id;
    obj->doc_hdl = doc_hdl;
	
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++) 
    {
        obj->dst_idx[i] = SYNCML_INVALID_IDX;
    }
	
	obj->db_info = (srv_sync_ota_db_info_struct *)OslMalloc(sizeof(srv_sync_ota_db_info_struct) * srv_sync_get_database_count());
	
	srv_sync_database_foreach_ext(srv_sync_ota_dbinfo_callback, (void *)obj->db_info);

    return obj;
}

static void srv_sync_ota_destroy(srv_sync_ota_cntx_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

    for (i = 0; i < obj->num_profiles; i++) 
    {
        if (obj->profile[i] == NULL) 
        {
            continue;
        }
		
        OslMfree(obj->profile[i]);
    }

	SYNC_MFREE(obj->db_info);
	
    OslMfree(obj);

    obj = NULL;
}


static void srv_sync_ota_notify_mmi(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_ota_ind_evt_struct cca_evt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&cca_evt, EVT_ID_SRV_SYNC_OTA_IND);

	cca_evt.total = g_srv_sync_ota_cntx->total_valid;
	
  // locate the first valid profile.
	while (g_srv_sync_ota_cntx->iter < g_srv_sync_ota_cntx->num_profiles)
	{		
		if (g_srv_sync_ota_cntx->isvalidprof[g_srv_sync_ota_cntx->iter])
		{
			break;
		}

		g_srv_sync_ota_cntx->iter++;
	} 
  
	MMI_FRM_CB_EMIT_POST_EVENT(&cca_evt);
}

#define GLOBAL_FUCTION

MMI_BOOL srv_sync_ota_get_info(void *info, U8 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_ota_accnt_info_struct *ota_info;
	U8 curr_idx;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(info != NULL, MMI_FALSE)
  curr_idx = g_srv_sync_ota_cntx->iter;

  RETURN_VAL_IF_FAIL(curr_idx < g_srv_sync_ota_cntx->num_profiles, MMI_FALSE)

  curr_idx = g_srv_sync_ota_cntx->iter;

	ota_info = (srv_sync_ota_accnt_info_struct *)info;
	ota_info->accnt = g_srv_sync_ota_cntx->profile[curr_idx];
	ota_info->updateble = MMI_FALSE;
  
	#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__  
	if (g_srv_sync_ota_cntx->dst_idx[curr_idx] != SYNCML_INVALID_IDX)
	{
		ota_info->dest_idx = g_srv_sync_ota_cntx->dst_idx[curr_idx];
		ota_info->updateble = MMI_TRUE;
	}
	#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
	
	return MMI_TRUE;
}

void srv_sync_ota_proc_cca_doc(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_configure_ind_struct* new_doc;
    nvram_ef_syncml_account_struct *accnt;
    //cca_status_enum status;    
    U32 i;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_doc = (srv_cca_app_configure_ind_struct*)param;
    MMI_ASSERT(new_doc != NULL);
    
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PROC_CCA, new_doc->config_id, new_doc->hConfig);

    g_srv_sync_ota_cntx = srv_sync_ota_create(new_doc->config_id, new_doc->hConfig);
	
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	/* check the provisioning type */
    if (new_doc->prov_type != MMI_CCA_PROV_TYPE_OTA_PROV)
	{
		srv_sync_ota_config_rsp(g_srv_sync_ota_cntx, CCA_STATUS_INVALID_SETTING);
		srv_sync_ota_destroy(g_srv_sync_ota_cntx);
		return;
	}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    g_srv_sync_ota_cntx->sim_id = (U16)srv_sync_ota_sim_cca2cbm((mmi_sim_enum)new_doc->sim_id); /* config sim id */

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    g_srv_sync_ota_cntx->prov_flag = new_doc->prov_flag;
#endif

    /* this flag is to control re-entry SCR_ID_SYNC_OTA_PROFILE_INSTALL 
	 * for installing next profile. 
	 */
	 //g_syncml_ota_next_profile = 0;   
    /* Extract data syncml settings from CCA configuration document, and store 
       settings in the temporary storage. */
    //status = srv_cca_doc_process(
            srv_cca_doc_process(
                new_doc->hConfig, 
                srv_sync_ota_cca_map_tbl,
                sizeof(srv_sync_ota_cca_map_tbl) / sizeof(U16),
                NULL, 
                srv_sync_ota_proc_cca_nodes, 
                g_srv_sync_ota_cntx);
    
    /* No valid profile */
    if (srv_sync_ota_get_valid_profile_num() == 0 || g_srv_sync_ota_cntx->total_valid == 0) 
    {        
        /* Now, terminate the SYNCML OTA provisioning application. */
        srv_sync_ota_config_rsp(g_srv_sync_ota_cntx, CCA_STATUS_INVALID_SETTING);
        srv_sync_ota_destroy(g_srv_sync_ota_cntx);
        return;
    }

    /* Setup callback to free memory and send message back to CCA when users
       press END key and return to idle screen, or when the app exits. */
    /*read current profile name list from NVRAM*/
    accnt = (nvram_ef_syncml_account_struct *)OslMalloc(sizeof(nvram_ef_syncml_account_struct));
  
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {    
		srv_sync_read_accnt_buffer(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, i);
        mmi_ucs2cpy((CHAR *)g_srv_sync_ota_cntx->currentprofnamelist[i],(CHAR *)accnt->account_name);
    }
    
    OslMfree(accnt);

	// notify MMI
	srv_sync_ota_notify_mmi();
}


#define SYNC_OTA_DM_UPDATE
/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_construct_cca_doc_for_dm
 * DESCRIPTION
 *  This function construct cca document for DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sync_ota_construct_cca_doc_for_dm(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_ind_struct *get_prof;
    mmi_cca_app_get_prof_rsp_struct *data;
	
    S32 hconfig, hroot, hnode ,temnode,connect_type;
	S32 orgin_netid;
    mmi_syncml_account_struct *dm_account = NULL;    
    U8 temp[MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];
    CHAR temp_ip_addr[MAX_SYNCML_PROXY_IP_ADDR_LEN];
    CHAR tempint[10];
    U32 i;
    srv_dtcnt_prof_proxy_info_struct *proxy_info = NULL;
	srv_sync_ota_db_info_struct *db_info;
	U16 sim_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_CONSTRUCT_DOC_FOR_DM );
    get_prof = (mmi_cca_app_get_prof_ind_struct *)param;
    MMI_ASSERT(get_prof != NULL);
    
    dm_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
	
  //  mmi_syncml_read_account_from_nvram((U8)get_prof->prof_id, (void*)dm_account);

	srv_sync_read_accnt_buffer(dm_account,
								NVRAM_EF_SYNCML_ACCOUNT_SIZE,
								SRV_SYNC_REMOTE,
								(U8)(get_prof->prof_id - 1));
	
    hroot = mmi_cca_doc_new_rootnode();
    if (!hroot)
    {
        MMI_ASSERT(0);
    }
	
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PROXY, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release (hroot); 
        MMI_ASSERT(0);
    }
	
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_NODEID, "PROXY_1");
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PROXY_ID, "PROXY_1");
	temp_ip_addr[0] = 0;

    proxy_info = (srv_dtcnt_prof_proxy_info_struct*)OslMalloc(sizeof(srv_dtcnt_prof_proxy_info_struct));

	sim_id = (U16)srv_sync_ota_sim_cca2cbm((mmi_sim_enum)get_prof->sim_id);
    srv_dtcnt_get_proxy_info(
        dm_account->net_id[sim_id], 
        proxy_info, 
        SRV_DTCNT_ACCOUNT_PRIMARY);

    for (i = 0; i < 4; i++)
	{
		syncml_itoa((S32) proxy_info->px_addr[i], (CHAR*)tempint, 10);
		strcat(temp_ip_addr,tempint);
		if (i < 3)
		{     
			strcat(temp_ip_addr,".");
		}
	}        
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXADDR, (CHAR*)temp_ip_addr);
	mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4);
	
	//g_syncml_ota_use_proxy_flag = (MMI_BOOL)proxy_info->use_proxy;
				
	/* Get the original net id */
	orgin_netid = (S32)cbm_get_original_account(dm_account->net_id[sim_id]);
	mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_DATAACCTID, orgin_netid);   
	
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PORT, temnode);
	syncml_itoa((S32)proxy_info->px_port, (CHAR*)(tempint), (S32)10);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PORTNBR, (CHAR*)tempint);
	connect_type = (dm_account->transport_type == SYNCML_TRANS_HTTP) ? CCA_NS_VAL_OTA_HTTP_TO : CCA_NS_VAL_CL_WSP;
	mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_OMA_SERVICE, (S32)connect_type);    
	
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PXAUTHINFO, temnode);
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXAUTH_ID, (CHAR*)proxy_info->px_authid);    
	mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXAUTH_PW, (CHAR*)proxy_info->px_authpw); 
	 
    OslMfree(proxy_info);

    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPLICATION, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release (hroot); 
        MMI_ASSERT(0);
    }
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_NODEID , "APPLICATION_1");
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_APPID, "w5");
	
	mmi_chset_ucs2_to_utf8_string((U8*) temp,                        
		MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH, 
		(U8*)dm_account->account_name);
	
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_NAME ,(CHAR*)temp);
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_TO_PROXY , "PROXY_1");
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPADDR, temnode);  
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_ADDR , (CHAR*)dm_account->server_address);
	
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPAUTH, temnode);  
	mmi_cca_doc_add_nodedata_int (hnode,CCA_NS_OMA_AAUTHLEVEL , CCA_NS_VAL_CLIENT);
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_AAUTHNAME , (CHAR*)dm_account->server_username);
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_AAUTHSECRET , (CHAR*)dm_account->server_password);

	// construct database address
	db_info = (srv_sync_ota_db_info_struct*)OslMalloc(sizeof(srv_sync_ota_db_info_struct) * srv_sync_get_database_count());
	srv_sync_database_foreach_ext(srv_sync_ota_dbinfo_callback, (void *)db_info);
	
	for (i = 0; i < srv_sync_get_database_count(); i++)
	{
	    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_RESOURCE, temnode);  
		mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AACCEPT, (CHAR *)db_info[i].mime);
		mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_URI, (CHAR*)dm_account->database_address[db_info[i].id]);
		mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHNAME, (CHAR*)dm_account->database_username[db_info[i].id]);
		mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_AAUTHSECRET, (CHAR*)dm_account->database_password[db_info[i].id]);       
	}
		
	OslMfree(db_info);
	db_info = NULL;
		
    hconfig = mmi_cca_doc_new (hroot);

    data = OslAllocDataPtr(mmi_cca_app_get_prof_rsp_struct);
	
    data->sim_id = (U16)srv_sync_ota_sim_cbm2cca(cbm_get_sim_id(dm_account->net_id[sim_id]));
	
    data->app_id = get_prof->app_id;
    data->prof_id = get_prof->prof_id; 
    data->hConfig = hconfig;
    data->result = CCA_STATUS_OK;    
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_GET_PROF_RSP, (oslParaType *)data, NULL);
	
    OslMfree(dm_account);  
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_install_cca_doc_from_dm
 * DESCRIPTION
 *  This function install the new setting into NVRAM from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
void srv_sync_ota_install_cca_doc_from_dm(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_update_prof_ind_struct *update_prof;
    mmi_cca_app_update_prof_rsp_struct *data;
    mmi_syncml_account_struct* new_prof;
    mmi_syncml_account_struct *tmp_nvram = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_INSTALL_DOC_FROM_DM);
    update_prof = (mmi_cca_app_update_prof_ind_struct *)param;
    MMI_ASSERT(update_prof != NULL);
    
    g_srv_sync_ota_cntx = srv_sync_ota_create(0, update_prof->hConfig); 
    
    data = (mmi_cca_app_update_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
	/* set dm-update flag */
	g_srv_sync_ota_cntx->opr_flag |= SYNCML_OTA_OPR_DM_UPDATE_MASK;
		
    mmi_cca_doc_process(update_prof->hConfig, 
                        srv_sync_ota_cca_map_tbl,
                        sizeof(srv_sync_ota_cca_map_tbl) / sizeof(U16),
                        NULL, 
                        srv_sync_ota_proc_cca_nodes, 
                        g_srv_sync_ota_cntx);

    if (srv_sync_ota_get_valid_profile_num() == 0) 
    {
        data->result = CCA_STATUS_INVALID_SETTING;
    }
    else
    {   
        tmp_nvram = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));

        new_prof = g_srv_sync_ota_cntx->profile[0];
           
        //new_prof->account_id = update_prof->prof_id; 
        
		srv_sync_read_accnt_buffer(tmp_nvram, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, (update_prof->prof_id - 1));
		/*
		 * <1>
		 *     If the profile name has been changed, clear the PROVURL and ID hash buffer.
		 *     CCA spec 12.3.1
		 * <2>
		 *	   The three hash buffers won't be taken by cca doc construction for dm
		 * 		to avoid hash the buffer again.
		 */
		 
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		if (mmi_ucs2cmp((CHAR*)new_prof->account_name, (CHAR*)tmp_nvram->account_name) != 0)
		{
			memcpy(new_prof->prov_url_hash, "\0", 1);
			memcpy(new_prof->proxy_id_hash, "\0", 1);
		}
		else
		{
			memcpy(new_prof->prov_url_hash, tmp_nvram->prov_url_hash, MAX_SYNCML_HASH_BUF_LEN);
			memcpy(new_prof->proxy_id_hash, tmp_nvram->proxy_id_hash, MAX_SYNCML_HASH_BUF_LEN);
		}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

        /* save old account setting */
        new_prof->app_to_sync = tmp_nvram->app_to_sync;  
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        new_prof->sync_type = tmp_nvram->sync_type;   
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif
        new_prof->regular_sync = tmp_nvram->regular_sync;  
        
        new_prof->sync_report_status = tmp_nvram->sync_report_status; 

        /* update global variables */
//        g_mmi_syncml_cntx.account_validation[update_prof->prof_id - 1] = new_prof->account_validation; 

  //      g_mmi_syncml_cntx.regular_sync_notify[update_prof->prof_id - 1] = 0;

    //    mmi_ucs2cpy((CHAR*)g_mmi_syncml_cntx.account_name_display[update_prof->prof_id - 1], (CHAR*)new_prof->account_name);

        OslMfree(tmp_nvram);

		srv_sync_write_accnt(SRV_SYNC_REMOTE, new_prof, (update_prof->prof_id - 1));
		
        data->result = CCA_STATUS_OK;
    }

	srv_sync_ota_destroy(g_srv_sync_ota_cntx);
    

    data->sim_id = update_prof->sim_id;
    data->app_id = update_prof->app_id;
    data->prof_id = update_prof->prof_id;
    data->hConfig = update_prof->hConfig;
        
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP, (oslParaType *)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_checking_for_dm
 * DESCRIPTION
 *  This function used to check whether hanset can receive the new setting from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  0,1
 *****************************************************************************/
S32 srv_sync_ota_checking_for_dm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    if (mmi_frm_group_is_present(GRP_ID_SYNC_MAIN) || srv_sync_is_synchronizing())
	if (srv_sync_is_synchronizing())
    {
        return 0x0;
    }
    else
    {
        return 0x1;
    }
}

