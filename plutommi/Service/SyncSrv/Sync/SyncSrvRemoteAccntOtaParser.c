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
 * SyncSrvRemoteAccntOtaParser.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include <ctype.h> /* islow() */
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "common_nvram_editor_data_item.h"
#include "conversions.h"

#include "DtcntSrvGprot.h"
#include "CcaSrvGprot.h"
#include "cbm_consts.h"

#include "SyncSrvGprot.h"
#include "SyncSrvRemoteAccnt.h"
#include "SyncSrvRemoteAccntOTA.h"
#include "syncml_common_customize.h"

#include "mmi2syncml_struct.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_SYNCML_OTA_NO_PROXY "@CCA@GEN@"
#define MMI_SYNCML_OTA_CAL_NAME_TOTAL  2
#define MMI_SYNCML_OTA_TASK_NAME_TOTAL 1

/*****************************************************************************
 * Typedef 
 *****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/

/*
 * Task and Calendar db has the same mime type, 
 * so SyncmlOTA do opaque match under the fllowing two tables.
 */
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
static const CHAR mmi_syncml_cal_dbname[MMI_SYNCML_OTA_CAL_NAME_TOTAL][MAX_SYNCML_DATABASE_ADDR_LEN] = 
{
	"event",
	"cal",
};
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
static const CHAR mmi_syncml_task_dbname[MMI_SYNCML_OTA_TASK_NAME_TOTAL][MAX_SYNCML_DATABASE_ADDR_LEN] = 
{
	"task",
};
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

/*****************************************************************************
* Global Function 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_sync_is_ascii_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest             [IN]    
 * RETURNS 0,1
 *  
 *****************************************************************************/
static MMI_BOOL srv_sync_is_ascii_format(CHAR *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *p = dest;  
    U8 ansii_max_value = 255;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*p != '\0')
    {
        if (*p < ansii_max_value )
        {
            p++;
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
 *  srv_sync_ota_check_string
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_sync_ota_check_string(CHAR* out_buff, const CHAR* in_buff, U8 max_len, MMI_BOOL trunk_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(out_buff != NULL);
	if (in_buff == NULL || 
		(strlen(in_buff) == 0) ||
		!srv_sync_is_ascii_format((CHAR*)in_buff))
	{
		return MMI_FALSE;
	}
	
	if (strlen(in_buff) < max_len)
	{
		strcpy(out_buff, in_buff);
	}
	else if (trunk_flag) /* trunk the input string */
	{
		strncpy(out_buff, in_buff, max_len - 1);
	}
	else
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
	
}

/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_stristr
 * DESCRIPTION
 *  This function performs strstr in case-insensitive way.
 * PARAMETERS
 *  src_str     [IN]        Source string
 *  tbf_str     [IN]        String to be found
 * RETURNS
 *  NULL: not found
 *  non-NULL: pointer of 1st found substring
 *****************************************************************************/
static CHAR* srv_sync_ota_stristr(const CHAR *src_str, const CHAR *tbf_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 match_flag = 0;   /* reset */
    S32 i = 0;            /* reset */
    S32 j = 0;            /* reset */
    S32 reset_i = -1;     /* reset */
    S32 left, left_fixed;
    CHAR s1, s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_str || !tbf_str || !strlen(tbf_str) || !strlen(src_str) || strlen(tbf_str) > strlen(src_str))
    {
        return NULL;
    }

    left = left_fixed = strlen(tbf_str);

    while (*(src_str + i) && *(tbf_str + j) && left)
    {
        /* both convert to lower case */
        s1 = (CHAR) (islower((S32) * (src_str + i)) ? *(src_str + i) : tolower((S32) * (src_str + i)));
        s2 = (CHAR) (islower((S32) * (tbf_str + j)) ? *(tbf_str + j) : tolower((S32) * (tbf_str + j)));

        if (s1 != s2)
        {
            if (reset_i >= 0)
            {
                i = reset_i + 1;
                reset_i = -1;
            }
            else
            {
                i++;
            }

            j = 0;
            match_flag = 0;
            left = left_fixed;
        }
        else
        {
            if (match_flag == 0)
            {
                /* 1st matched */
                reset_i = i;
                match_flag = 1;
            }

            i++;
            j++;
            left--;
        }
    }

    if (left == 0)
    {
        /* return 1st matched substring */
        return (CHAR*) src_str + i - left_fixed;
    }

    return NULL;
}

static U8 srv_sync_ota_get_db_type(const CHAR* db_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	for (i = 0; i < MMI_SYNCML_OTA_CAL_NAME_TOTAL; i++)
	{
		if (srv_sync_ota_stristr(db_name, mmi_syncml_cal_dbname[i]) != NULL)
		{
		    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_GET_CALENDAR_TYPE);
			return SYNCML_DB_CALENDAR;
		}
	}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	for (i = 0; i < MMI_SYNCML_OTA_TASK_NAME_TOTAL; i++)
	{
		if (srv_sync_ota_stristr(db_name, mmi_syncml_task_dbname[i]) != NULL)
		{
		    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_GET_TASK_TYPE);
			return SYNCML_DB_TASK;
		}
	}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

	return 0;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_new_ota_profile
 * DESCRIPTION
 *  This function allocates a temporary storage for SYNC profile. And it will 
 *  turn on the flag such that we can process subsequent nodes/parameters
 *  again.
 * PARAMETERS
 *  cntx            [IN]            control block for SYNC OTA provisioning
 * RETURNS
 *  On success, return the index of the newly allocated profile. Otherwise, 
 *  return -1, i.e., an invalid index.
 *****************************************************************************/
static S16 srv_sync_ota_new_profile(srv_sync_ota_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_ef_syncml_account_struct *prof;
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_NEW_OTA_PROF, cntx->num_profiles);
    
    if (cntx->num_profiles >= MMI_MAX_SYNCML_ACCOUNTS) 
    {
        return -1;
    }
    
    /* Obtain the index. */
    index = cntx->num_profiles;
    
    prof = (nvram_ef_syncml_account_struct *)OslMalloc(sizeof(nvram_ef_syncml_account_struct));
	memset(prof, 0, sizeof(nvram_ef_syncml_account_struct));
	mmi_ucs2cpy((CHAR *)prof->account_name, (CHAR *)DEFAULT_CCA_PROFILE_NAME);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	memcpy((PU8)prof->prov_url_hash, "\0", 1);
	memcpy((PU8)prof->proxy_id_hash, "\0", 1);
#endif    

	cntx->profile[index] = prof;
	
    return index;
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_parser_node_bootstrap
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum srv_sync_ota_parser_node_bootstrap
(
	cca_iterator_struct *param_list,
	void *usr_data
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_ota_cntx_struct *cntx;
	cca_core_data_struct *param;
	cca_status_enum state = CCA_STATUS_OK;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(param_list != NULL && usr_data != NULL);
	cntx = (mmi_syncml_ota_cntx_struct*)usr_data;
	
	/* Only get the first provurl*/
	if (cntx->opr_flag & SYNCML_OTA_OPR_PROV_MASK)
	{
		return CCA_STATUS_OK;
	}
	else
	{
		cntx->opr_flag |= SYNCML_OTA_OPR_PROV_MASK;
	}
	
	while (srv_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
	{
        switch (param->id)
        {                 				
        	case CCA_NS_OMA_PROVURL: /* for (TPS) (Trusted Provisioning Server) */
				if (param->values.s[0] != NULL && strlen(param->values.s[0]) > 0)
				{
					state = 
						srv_cca_generate_hash_value(param->values.s[0], 
												    cntx->prov_url_hash,
												    MAX_SYNCML_HASH_BUF_LEN);

					if (state != CCA_STATUS_OK)
				 	{
				 		memcpy(cntx->prov_url_hash, "\0", 1);
				 	}
				}
				else 
				{
					memcpy(cntx->prov_url_hash, "\0", 1);
				}
				break;
				
			default:
				break;
        }
	}
    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PARSE_BOOTSTRAP, cntx->opr_flag, state);
    
	return CCA_STATUS_OK;
}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_parser_node_app
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum srv_sync_ota_parser_node_app
(
	nvram_ef_syncml_account_struct* new_account,
	cca_iterator_struct *param_list,
	U8 prof_idx,
	void *usr_data
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_ota_cntx_struct *cntx;
	cca_core_data_struct *param;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_account != NULL && param_list != NULL && usr_data != NULL);
	cntx = (mmi_syncml_ota_cntx_struct*)usr_data;
	
    while (srv_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_APPID:
                /*syncml appid is "w5" */
                if (param->values.s[0] != NULL)
                {
                    if (strcmp((CHAR *)param->values.s[0], (CHAR *)"w5") != 0)
                    {
                        return CCA_STATUS_FAIL;
                    }
                    
                }
                break;
        
            case CCA_NS_OMA_NAME: 
                if (strlen(param->values.s[0]) > 0)
                {
					mmi_chset_utf8_to_ucs2_string(
                        new_account->account_name, 
						MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH, 
						(U8 *)param->values.s[0]);
                }
                break;
        
            case CCA_NS_OMA_TO_PROXY:
				srv_sync_ota_check_string((CHAR *)&cntx->app_to_proxy[prof_idx], 
										param->values.s[0], 
										MAX_SYNCML_PROXY_ID_LEN,
										MMI_TRUE);
                break;
                
            case CCA_NS_OMA_ADDR:
				cntx->isvalidprof[prof_idx] = 
					srv_sync_ota_check_string((CHAR *)&new_account->server_address, 
											param->values.s[0], 
											MAX_SYNCML_SERVER_ADDR_LEN,
											MMI_FALSE);
			
                break;

				
            default:
                break;
				
        } /* switch */
    } /* while */

	return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_parser_node_app_addr
 * DESCRIPTION
 *  parse appaddress node from OMA DM
 * PARAMETERS
 *  new_account        [IN]		profile info
 *  param_list  	   [IN]		param list
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static cca_status_enum srv_sync_ota_parser_node_app_addr
(
	nvram_ef_syncml_account_struct* new_account,
	cca_iterator_struct *param_list
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_core_data_struct *param;
	cca_status_enum status;
	MMI_BOOL ret = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_account != NULL && param_list != NULL);
	
    while (srv_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_ADDR:			
				ret = srv_sync_ota_check_string((CHAR *)&new_account->server_address, 
											param->values.s[0], 
											MAX_SYNCML_SERVER_ADDR_LEN,
											MMI_FALSE);

                break;
				
			default:
				break;
    	}
	}
	
	if (ret)
	{
		status = CCA_STATUS_OK;
	}
	else
	{
		status = CCA_STATUS_FAIL;
	}
	MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PARSE_APP_ADDR, status);
	return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_parser_node_app_authinfo
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  new_account        [IN]		profile info
 *  param_list  	   [IN]		param list
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum srv_sync_ota_parser_node_app_authinfo
(
	nvram_ef_syncml_account_struct* new_account,
	cca_iterator_struct *param_list
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_core_data_struct *param;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_account != NULL && param_list != NULL);
	
    while (srv_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_AAUTHLEVEL: 
                /*Predefine this param is received earlier than any other params of this node.
                If authlevel is not CCA_NS_VAL_CLIENT,we pass this node*/
                 if (param->values.i[0] != 0)
                 {
                    if (param->values.i[0] != CCA_NS_VAL_CLIENT)
                    {
                        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PARSE_APP_ADDR_AUTH, param->values.i[0]);
                        return CCA_STATUS_FAIL;
                    }
                 } 
                break;    
                 
            case CCA_NS_OMA_AAUTHNAME:
				srv_sync_ota_check_string((CHAR *)&new_account->server_username, 
				     					param->values.s[0], 
										MAX_SYNCML_USERNAME,
										MMI_TRUE);						
                break;
                
            case CCA_NS_OMA_AAUTHSECRET:
				srv_sync_ota_check_string((CHAR*)&new_account->server_password, 
										param->values.s[0], 
										MAX_SYNCML_PASSWORD,
										MMI_TRUE);						
                break;            

            default:
                break;
                
        }
    }
	
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_parser_node_proxy
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum srv_sync_ota_parser_node_proxy
(
	mmi_syncml_ota_proxy_cntx_struct* new_proxy,
	cca_iterator_struct *param_list,
	void* usr_data
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_core_data_struct *param;
	cca_status_enum cca_state = CCA_STATUS_FAIL;
	mmi_syncml_ota_cntx_struct *cntx;
	U8 barer_type;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_proxy != NULL && param_list != NULL && usr_data != NULL);
	cntx = (mmi_syncml_ota_cntx_struct*)usr_data;
	
    while (srv_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
    {   
        switch (param->id)
        {
            case CCA_NS_OMA_PROXY_ID:
			{
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
				if (strlen(param->values.s[0]) > 0 && srv_sync_is_ascii_format(param->values.s[0]))
				{
					cca_state = 
						mmi_cca_generate_hash_value(param->values.s[0], 
												    new_proxy->proxy_id_hash, 
													MAX_SYNCML_HASH_BUF_LEN);
					if (cca_state != CCA_STATUS_OK)
					{
						memcpy((void*)&new_proxy->proxy_id_hash, "\0", 1);
					}
				}
				else
				{
					memcpy((void*)&new_proxy->proxy_id_hash, "\0", 1);
				}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

             	srv_sync_ota_check_string((CHAR*)&new_proxy->proxy_id, 
										param->values.s[0], 
										MAX_SYNCML_PROXY_ID_LEN,
										MMI_TRUE);
                break;
        	}  

            case CCA_NS_DATAACCTID:
            {
                /* If data isn't ABM_E_SOCKET_BEARER_GSM_GPRS ,we pass this node */
                barer_type = srv_dtcnt_get_bearer_type(param->values.i[0], SRV_DTCNT_ACCOUNT_PRIMARY);
                
                MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PARSE_PROXY, barer_type, param->values.i[0]);
                
				if (barer_type != SRV_DTCNT_BEARER_GPRS && barer_type != SRV_DTCNT_BEARER_WIFI)
				{
					memset(new_proxy, 0, sizeof(mmi_syncml_ota_proxy_cntx_struct));
					return CCA_STATUS_FAIL;
				}
				else
                {
                    new_proxy->valid = MMI_TRUE;
                    cntx->num_proxy++;
                  	new_proxy->dataaccountid = (U32)param->values.i[0];
                }
                break;  
            }
            
            default:
                break;
                
        }                
    }

	return cca_state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_parser_node_resource
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static cca_status_enum srv_sync_ota_parser_node_resource(
							nvram_ef_syncml_account_struct* new_prof,
							cca_iterator_struct *param_list,
							void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_cca_core_data_struct *param;
	
    CHAR accept[MAX_SYNCML_MIME_LEN] = {0};           /*"text/x-vcalendar" or "text/x-vcard"*/
    CHAR temp_db_addr[MAX_SYNCML_DATABASE_ADDR_LEN] = {0};
    CHAR temp_db_username[MAX_SYNCML_USERNAME] = {0};    
    CHAR temp_db_password[MAX_SYNCML_PASSWORD] = {0}; 
    U8 flag_address = 0;
    U8 flag_username = 0;
    U8 flag_password = 0;
	//U8 db_type = 0;
	
	srv_sync_ota_db_info_struct *db_info = (srv_sync_ota_db_info_struct *)usr_data;
    U8 i = 0;
	MMI_BOOL is_find = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(new_prof != NULL && param_list != NULL);

    /* we can't confirm the four node order;
        CCA_NS_OMA_URI,CCA_NS_OMA_AAUTHNAME,CCA_NS_OMA_AAUTHSECRET,CCA_NS_OMA_AACCEPT
    */
	
	while (srv_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
	{   
        MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PARSE_RESOURCE, param->id);

        switch (param->id)
        {
            case CCA_NS_OMA_AAUTHTYPE:
                /*reversed */
                break;    
                
            case CCA_NS_OMA_AACCEPT:
				srv_sync_ota_check_string(
					(CHAR*)&accept,
					param->values.s[0], 
					MAX_SYNCML_MIME_LEN,
					MMI_TRUE);
				
				/* accept is coming after other node */
				for (i = 0; i < srv_sync_get_database_count(); i++)
				{
					if (strcmp((CHAR *)accept, (CHAR *)db_info[i].mime) == 0 &&
						(new_prof->database_address[db_info[i].id][0] == 0))
					{
						if (flag_address == 1)
						{
							srv_sync_ota_check_string(
								(CHAR*)&new_prof->database_address[db_info[i].id], 
								(CHAR*)&temp_db_addr, 
								MAX_SYNCML_DATABASE_ADDR_LEN,
								MMI_TRUE);
							flag_address = 0;
						}
						if (flag_username == 1)
						{
							srv_sync_ota_check_string(
								(CHAR*)&new_prof->database_username[db_info[i].id], 
								(CHAR*)&temp_db_username, 
								MAX_SYNCML_USERNAME,
								MMI_TRUE);
							flag_username = 0;
						}
						if (flag_password == 1)
						{
							srv_sync_ota_check_string(
								(CHAR*)&new_prof->database_password[db_info[i].id], 
								(CHAR*)&temp_db_password, 
								MAX_SYNCML_PASSWORD,
								MMI_TRUE);
							
							flag_password = 0;
						}
						
						break;
					}
				}
                break;
                
            case CCA_NS_OMA_URI:
				is_find = MMI_FALSE;
				for (i = 0; i < srv_sync_get_database_count(); i++)
				{
					if (strcmp((CHAR *)accept, (CHAR *)db_info[i].mime) == 0 &&
						(new_prof->database_address[db_info[i].id][0] == 0))
					{
						srv_sync_ota_check_string(
							(CHAR*)&new_prof->database_address[db_info[i].id], 
							param->values.s[0], 
							MAX_SYNCML_DATABASE_ADDR_LEN,
							MMI_TRUE);

						is_find = MMI_TRUE;
					break;
				}
				}

                if (!is_find)
                {
                    flag_address = 1;
                	srv_sync_ota_check_string(
						(CHAR*)&temp_db_addr, 
						param->values.s[0], 
						MAX_SYNCML_DATABASE_ADDR_LEN,
						MMI_TRUE);
					
                    /* Only Calendar and Task has this type */
                   // db_type = srv_sync_ota_get_db_type(param->values.s[0]);
                   srv_sync_ota_get_db_type(param->values.s[0]);
                }
                break;
        
            case CCA_NS_OMA_AAUTHNAME:
				is_find = MMI_FALSE;
				for (i = 0; i < srv_sync_get_database_count(); i++)
				{
					if (strcmp((CHAR *)accept, (CHAR *)db_info[i].mime) == 0 &&
						(new_prof->database_username[db_info[i].id][0] == 0))
					{
						srv_sync_ota_check_string(
							(CHAR*)&new_prof->database_username[db_info[i].id], 
							param->values.s[0], 
							MAX_SYNCML_USERNAME,
							MMI_TRUE);	


						is_find = MMI_TRUE;
					break;
				}
				}

                if (!is_find)
                {
                    flag_username = 1;
					 srv_sync_ota_check_string(
						(CHAR*)&temp_db_username, 
						param->values.s[0], 
						MAX_SYNCML_USERNAME,
                    	MMI_TRUE);
                }
                
                break;
                
            case CCA_NS_OMA_AAUTHSECRET:
				is_find = MMI_FALSE;
				for (i = 0; i < srv_sync_get_database_count(); i++)
				{
					if (strcmp((CHAR *)accept, (CHAR *)db_info[i].mime) == 0 &&
						(new_prof->database_password[db_info[i].id] == 0))
					{
						srv_sync_ota_check_string(
						   (CHAR*)&new_prof->database_password[db_info[i].id], 
						   param->values.s[0], 
						   MAX_SYNCML_PASSWORD,
						   MMI_TRUE); 
						
						is_find = MMI_TRUE;
					break;
				}
				}
                if (!is_find)
                {
                    flag_password = 1;
					srv_sync_ota_check_string(
						(CHAR*)&temp_db_password, 
						param->values.s[0], 
						MAX_SYNCML_PASSWORD,
                    	MMI_TRUE); 
                    
                }
                break;            
        
            default:
                break;
                
        }

    }
	return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sync_set_proxy_for_account
 * DESCRIPTION
 *  check the matchment btw proxy id and application
 * PARAMETERS
 *  cntx        ota context ptr
 *  index_prof  the target profile index
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static void srv_sync_set_proxy_for_account(mmi_syncml_ota_cntx_struct *cntx,  S16 index_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL proxy_check_flag = MMI_TRUE;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cntx->num_proxy; i++)
    {
        /* for dm update:
        * If dm update and the original is use proxy, client should check the matchment.
        * ,if original use-proxy flag is 0, client will don't check the matchment and copy to memo directly
        */
        //if ((cntx->opr_flag & SYNCML_OTA_OPR_DM_UPDATE_MASK) && !g_syncml_ota_use_proxy_flag)
        if (cntx->opr_flag & SYNCML_OTA_OPR_DM_UPDATE_MASK)
        {
           proxy_check_flag = MMI_FALSE;
        }

        if (proxy_check_flag && !cntx->proxy[i].valid)
        {
           continue;
        }
       
        /* If find out specified proxy */
        if (strcmp((CHAR *)cntx->app_to_proxy[index_prof], (CHAR *)cntx->proxy[i].proxy_id) == 0)
        {      
            if (cntx->proxy[i].dataaccountid == 0)
            {   
                cntx->profile[index_prof]->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CONN;
                cntx->profile[index_prof]->net_id[cntx->sim_id] = CBM_DEFAULT_ACCT_ID;  
            }
            else
            {               
                cntx->profile[index_prof]->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CONN;
                cntx->profile[index_prof]->net_id[cntx->sim_id] = cntx->proxy[i].dataaccountid;   
            }
            
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            /* copy valid hash to profile */
            memcpy((CHAR *)cntx->profile[index_prof]->proxy_id_hash, (CHAR *)cntx->proxy[i].proxy_id_hash, MAX_SYNCML_HASH_BUF_LEN);
#endif  

            MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, 
            		  MMI_SYNC_SRV_OTAP_SET_PROXY_FOR_ACCOUNT, 
            		  i, 
            		  cntx->profile[index_prof]->net_id[cntx->sim_id]); 

            return;
            
       } /* if*/
       
   } /* for_i */

   /* If No matched proxy, we will set default account */
   if (i == cntx->num_proxy)
   {
       MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_PARSE_ERROR_NO_MATCH_PX); 
       cntx->profile[index_prof]->net_id[cntx->sim_id] = CBM_DEFAULT_ACCT_ID;
       cntx->profile[index_prof]->account_validation |= MMI_SYNCML_ACCOUNT_VALID_MASK_CONN;
   }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_sync_ota_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sync_ota_proxy_cntx_struct *new_proxy;
    nvram_ef_syncml_account_struct *new_prof;
    mmi_syncml_ota_cntx_struct *cntx;
    
    cca_status_enum status = CCA_STATUS_OK;
    S16 index_profile;
	S16 index_proxy;
	    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_syncml_ota_cntx_struct*)user_data;
    index_profile = cntx->num_profiles;
    index_proxy = cntx->num_proxy;
    
    MMI_TRACE( MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_OTAP_CCA_NODES, symbol);
    switch (symbol)
    {
    		
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
		case MMI_CCA_NS_SYNCML_BOOTSTRAP:
		{
			/* for TPS */
			status = srv_sync_ota_parser_node_bootstrap(param_list, user_data);
			break;
		}
#endif

        case MMI_CCA_NS_SYNCML_PROXY:
		{
            if ((cntx->num_proxy + 1) > MMI_MAX_SYNCML_ACCOUNTS)
            {
                return CCA_STATUS_OK;
            }
            new_proxy = &cntx->proxy[index_proxy];
            status = srv_sync_ota_parser_node_proxy(new_proxy, param_list, user_data);
			if (status != CCA_STATUS_OK)
			{
				return status;
			}
            break;
        }   
        
        case MMI_CCA_NS_SYNCML_APPLICATION:
        {
            /* When start process this node,we predefine all the node proxy have already been processed */            
            /* Prepare a storage for the new profile. And get the new index. */
            if ((index_profile = srv_sync_ota_new_profile(cntx)) < 0)
            {
                return CCA_STATUS_FAIL;
            }
            
            cntx->num_profiles++;
            new_prof = cntx->profile[index_profile];
			status = srv_sync_ota_parser_node_app(new_prof, param_list, (U8)index_profile, user_data);
            if (status != CCA_STATUS_OK)
        	{
        		cntx->isvalidprof[index_profile] = MMI_FALSE;
        		return status;
        	}
            else
            {
                cntx->isvalidprof[index_profile] = MMI_TRUE;
                
                /* config proxy for account */
    			srv_sync_set_proxy_for_account(cntx, index_profile);
            }
            break;
        }

		/* for oma dm update */
        case MMI_CCA_NS_SYNCML_APPADDR:
		{
            new_prof = cntx->profile[index_profile - 1];
			status = srv_sync_ota_parser_node_app_addr(new_prof, param_list);
            if (status != CCA_STATUS_OK)
        	{
        		cntx->isvalidprof[index_profile] = MMI_FALSE;
        		return status;
        	}

			break;
		}
		
        case MMI_CCA_NS_SYNCML_APPAUTH:
        {
			if (!cntx->isvalidprof[index_profile - 1])
			{
				break;
			}
			
            new_prof = cntx->profile[index_profile - 1];
            status = srv_sync_ota_parser_node_app_authinfo(new_prof, param_list);
			if (status != CCA_STATUS_OK)
			{
				cntx->isvalidprof[index_profile - 1] = MMI_FALSE;
			}
            break;
        }
        
        case MMI_CCA_NS_SYNCML_RESOURCE:
        {
			if (!cntx->isvalidprof[index_profile - 1])
			{
				break;
			}
            new_prof = cntx->profile[index_profile - 1];
            status = srv_sync_ota_parser_node_resource(new_prof, param_list, cntx->db_info);
            break;          
        }
        
        default:
            return CCA_STATUS_OK;
                        
    }
    
    return status;
}

