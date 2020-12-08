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
 *   
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares JTA modules thread related structures and definitions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_SETTING_C
#define _MMA_SETTING_C

#if defined(MMS_SUPPORT)

#include "MMI_features.h"
#include "MMIDataType.h" 


#include "kal_public_defs.h" 

#include "mma_api.h"
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "custom_wap_config.h"
#include "mmsadp.h"
#include "conversions.h"
#include "app_ua.h"


#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#include "EngineerModeInetAppGprot.h" /* Added for Engineer Mode */



/* MSF */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_url.h"    /* MSF: URL API */
#include "msm.h"


/* STK */
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */
#else
#include "nts_if.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
/*
Header files for mma_msg_struct

*/

#include "mma_def.h"
#include "mma_env.h"
#include "UmSrvStruct.h"
#include "mma_main.h"
#include "mma_setting.h"
#include "mma_utilities.h"
#include "mma_interface.h"
#include "mmi_rp_srv_mms_def.h"

extern void mma_trim_utf8_string(char *str);
extern char *mma_ucs2_to_utf8_string(const kal_wchar *ucs2_str);


/************************************************************
 * Constants
 ************************************************************/
 mma_setting_context_struct g_mma_setting_cntx = {0};


#define MMA_CFG_MESSAGE_SIZE_MAXIMUM            (wap_custom_get_max_mms_msg_size())

#if defined(WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER) && WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER == 0
#define MMA_CFG_MAX_RETR_SIZE                   0
#else 
#define MMA_CFG_MAX_RETR_SIZE                   (MMA_CFG_MESSAGE_SIZE_MAXIMUM + wap_custom_get_mms_delta_retrival_size())
#endif 

#define MMA_DUMMY_STRING_HANDLE_NULL_STRING     ""

/* ! The default setting for allowing immediate retrieval from only one server
    ""=not used */
#define MMA_CFG_IM_SERVER                       MMA_DUMMY_STRING_HANDLE_NULL_STRING

/**********************************************************************
 * Type definitions
 **********************************************************************/
extern MmsVersion mma_get_mms_version_from_em(void);
extern void mmsa_profile_updated(MSF_UINT8 simId);
extern void mmsa_service_resumed(void);
/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_index_from_mms_sim_id
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MSF_INT32 mma_setting_get_index_from_mms_sim_id(MSF_INT32 sim_id)
{
    return (sim_id - MMS_SIM_CARD_SIM1);
}
/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_target_user_agent_ind_hdlr
 * DESCRIPTION
 *  This function is used to set user agent
 * PARAMETERS
 *  source                      [IN]        
 *  target_data_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_set_target_user_agent_ind_hdlr(module_type source, mms_target_data_user_agent_struct *target_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char* user_agent;
    const char* ua_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        /* for test only */
        MMA_FREE(target_data_p);
        return;
    }

    user_agent = applib_inet_get_user_agent_string();
    ua_profile = applib_inet_get_user_agent_profile();
    if(g_mma_setting_cntx.user_agent != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.user_agent)
    }
    g_mma_setting_cntx.user_agent = (kal_uint8*)MMA_CALLOC(strlen(user_agent) + 1);
    memcpy((char*)g_mma_setting_cntx.user_agent, (char*)user_agent, strlen(user_agent) + 1);
    if(g_mma_setting_cntx.ua_profile != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.ua_profile)
    }
    g_mma_setting_cntx.ua_profile = (kal_uint8*)MMA_CALLOC(strlen(ua_profile) + 1);
    memcpy((char*)g_mma_setting_cntx.ua_profile, (char*)ua_profile, strlen(ua_profile) + 1);

	MMA_FREE(target_data_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_target_plmn_number_ind_hdlr
 * DESCRIPTION
 *  This function is used to set plmn number
 * PARAMETERS
 *  source                      [IN]        
 *  target_data_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_set_target_plmn_number_ind_hdlr(module_type source, mms_target_data_plmn_number_struct *target_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(target_data_p);
   
	/* will write soon */
	MMA_FREE(target_data_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_target_owner_number_ind_hdlr
 * DESCRIPTION
 *  This function is used to set owner number
 * PARAMETERS
 *  source                      [IN]        
 *  target_data_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_set_target_owner_number_ind_hdlr(module_type source, mms_target_data_owner_number_struct *target_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(target_data_p);
    
	/* will write soon */
	MMA_FREE(target_data_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_target_mmsc_version_ind_hdlr
 * DESCRIPTION
 *  This function is used to set version
 * PARAMETERS
 *  source                      [IN]        
 *  target_data_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_set_target_mmsc_version_ind_hdlr(module_type source, mms_target_data_mms_version_struct *target_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        /* for test only */
        MMA_FREE(target_data_p);
        return;
    }
   	
    if (g_mma_setting_cntx.setting)
    {
        g_mma_setting_cntx.setting->mms_version = mma_get_mms_version_from_em();
    }

	
	MMA_FREE(target_data_p);
	
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_free_profile
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  resume_mms_service      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_setting_free_profile(mma_setting_profile_struct * profile_p)
{
    if(profile_p->mmsc_url_uri != NULL)
    {
        MMA_FREE(profile_p->mmsc_url_uri);
    }
    if(profile_p->mmsc_url_server != NULL)
    {
        MMA_FREE(profile_p->mmsc_url_server);
    }
    if(profile_p->mmsc_url_scheme != NULL)
    {
        MMA_FREE(profile_p->mmsc_url_scheme);
    }
    if(profile_p->username != NULL)
    {
        MMA_FREE(profile_p->username);
    }
    if(profile_p->password != NULL)
    {
        MMA_FREE(profile_p->password);
    }
    if(profile_p->proxy_addr != NULL)
    {
        MMA_FREE(profile_p->proxy_addr);
    }
    MMA_FREE(profile_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_setting_update_mms_profile
 * DESCRIPTION
 *  This function is used to update mms profile to mms service.
 * PARAMETERS
 *  mms_mma_set_profile_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_setting_update_mms_profile(wap_mma_set_profile_req_struct *mms_mma_set_profile_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 sim_index = 0;
    MSF_INT32 url_len = 0;
    kal_uint8 * homepage_url = NULL;
    mma_setting_profile_struct * profile_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_get_module_status(MSF_MODID_MSM) != MODULE_STATUS_ACTIVE &&
        msm_get_module_status(MSF_MODID_MMS) == MODULE_STATUS_ACTIVE)
    {
        return MMA_RESULT_FAIL_NOT_READY;
    }
    if (mms_mma_set_profile_p == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
    profile_p = (mma_setting_profile_struct*) MMA_CALLOC(sizeof(mma_setting_profile_struct));
    url_len = (kal_wstrlen(mms_mma_set_profile_p->homepage_url) + 1) * 3;
    if (url_len > 3)
    {
        homepage_url = (kal_uint8*)MMA_CALLOC(url_len);
        ASSERT(homepage_url);
        if (mmi_chset_ucs2_to_utf8_string(
                (kal_uint8*) homepage_url,
                (kal_int32) url_len,
                (kal_uint8*) mms_mma_set_profile_p->homepage_url) < 0)
        {
            ASSERT(0);
        }
    }
    mma_setting_split_mmsc((char*)homepage_url, (char**)(&(profile_p->mmsc_url_server)), &(profile_p->mmsc_url_port), (char**)(&(profile_p->mmsc_url_uri)) ,(char**)(&(profile_p->mmsc_url_scheme)));
    MMA_FREE(homepage_url);
    url_len = (kal_wstrlen(mms_mma_set_profile_p->username) + 1) * 3;
    if (url_len > 3)
    {
        profile_p->username = (kal_uint8*)MMA_CALLOC(url_len);
        ASSERT(profile_p->username);
        if (mmi_chset_ucs2_to_utf8_string(
                (kal_uint8*)  profile_p->username,
                (kal_int32) url_len,
                (kal_uint8*) mms_mma_set_profile_p->username) < 0)
        {
            ASSERT(0);
        }
    }
    url_len = (kal_wstrlen(mms_mma_set_profile_p->password) + 1) * 3;
    if (url_len > 3)
    {
        profile_p->password = (kal_uint8*)MMA_CALLOC(url_len);
        ASSERT(profile_p->password);
        if (mmi_chset_ucs2_to_utf8_string(
                (kal_uint8*) profile_p->password,
                (kal_int32) url_len,
                (kal_uint8*) mms_mma_set_profile_p->password) < 0)
        {
            ASSERT(0);
        }
    }
    profile_p->proxy_addr = (kal_uint8*)MMA_CALLOC(strlen((char*)mms_mma_set_profile_p->proxy_addr)+1);
    ASSERT(profile_p->proxy_addr);

    strcpy((char*)profile_p->proxy_addr,(char*)mms_mma_set_profile_p->proxy_addr);
    if (strlen((char*)mms_mma_set_profile_p->proxy_addr) > 0)
    {
        profile_p->proxy_port = mms_mma_set_profile_p->proxy_port;
    }
    switch (mms_mma_set_profile_p->connection_type)
    {
        case MMA_CONN_TYPE_HTTP_PROXY:
        case MMA_CONN_TYPE_HTTP_DIRECT:
            profile_p->connection_type = STK_CONNECTION_TYPE_HTTP;
            break;
        case MMA_CONN_TYPE_WSP_CL:
            profile_p->connection_type = STK_CONNECTION_TYPE_WSP_CL;
            profile_p->proxy_port = 9200;
            break;
        case MMA_CONN_TYPE_WSP_CO:
            profile_p->connection_type = STK_CONNECTION_TYPE_WSP_CO;
            profile_p->proxy_port = 9201;
            break;
        case MMA_CONN_TYPE_WSP_SEC_CL:
            profile_p->connection_type = STK_CONNECTION_TYPE_WSP_CL;
            profile_p->proxy_port = 9202;
            break;
        case MMA_CONN_TYPE_WSP_SEC_CO:
            profile_p->connection_type = STK_CONNECTION_TYPE_WSP_CO;
            profile_p->proxy_port = 9203;
            break;
        default:
            return MMA_RESULT_FAIL;
    }
    profile_p->data_account = mms_mma_set_profile_p->data_account;
    sim_index = mma_setting_get_index_from_mms_sim_id(translate_mma_sim_to_mms_sim(mms_mma_set_profile_p->sim_id));
    if(g_mma_setting_cntx.profile[sim_index]!= NULL)
    {
        mma_setting_free_profile(g_mma_setting_cntx.profile[sim_index]);
        g_mma_setting_cntx.profile[sim_index] = NULL;
    }
    else
    {
        g_mma_setting_cntx.is_suspended[sim_index] = FALSE;
    }
	g_mma_setting_cntx.profile[sim_index] = profile_p;
    
    return MMA_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_split_mmsc
 * DESCRIPTION
 *  This function is used to update mms profile to mms service.
 * PARAMETERS
 *  str         [IN]         
 *  server      [IN]        
 *  port        [IN]         
 *  uri         [IN]        
 *  scheme      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mma_setting_split_mmsc(char *str, char **server, kal_uint32 *port, char **uri, char **scheme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *tmp_scheme;
    char *tmp_port;
    char *tmp_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_trim_utf8_string(str);
    if (!msf_url_is_valid(str))
    {
        return KAL_FALSE;
    }

    tmp_port = msf_url_get_port(MSF_MODID_MMA, (const char*)str);
    if (tmp_port)
    {
        *port = (unsigned int)atoi(tmp_port);
        MMA_FREE(tmp_port);
    }

    tmp_scheme = msf_url_get_scheme(MSF_MODID_MMA, str);
    *server = msf_url_get_host(MSF_MODID_MMA, str);
    if (*server == NULL)
    {
        *server = (char*)msf_cmmn_strdup(MSF_MODID_MMA, MMA_DUMMY_STRING_HANDLE_NULL_STRING);
    }
    tmp_path = (char*)msf_url_find_path((const char*)str);
    if (NULL != tmp_scheme)
    {
        *scheme = (char*)MMA_CALLOC(strlen(tmp_scheme) + 1 + 3);
        sprintf(*scheme, "%s://", tmp_scheme);
        MMA_FREE(tmp_scheme);
    }
    else
    {
        *scheme = (char*)msf_cmmn_strdup(MSF_MODID_MMA, MMA_DUMMY_STRING_HANDLE_NULL_STRING);
    }
    if (NULL != tmp_path)
    {
        *uri = (char*)msf_cmmn_strdup(MSF_MODID_MMA, tmp_path);
    }
    else
    {
        *uri = (char*)msf_cmmn_strdup(MSF_MODID_MMA, MMA_DUMMY_STRING_HANDLE_NULL_STRING);
    }
    return KAL_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_profile_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                      [IN]        
 *  mms_mma_set_profile_p       [IN]         
 * RETURNS
 *  void 
 *****************************************************************************/
static void mma_setting_set_profile_req_hdlr(module_type source, wap_mma_set_profile_req_struct *mms_mma_set_profile_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_set_profile_p);

    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        /* for test only */
        mms_mma_send_set_profile_rsp(
        MMA_APP_SOURCE_MODULE,
        mms_mma_set_profile_p->app_id,
        mms_mma_set_profile_p->req_id,
        MMA_RESULT_FAIL_NOT_READY);
        MMA_FREE(mms_mma_set_profile_p);
        return ;
    }

    result = mma_setting_update_mms_profile(mms_mma_set_profile_p);
    mmsa_profile_updated(translate_mma_sim_to_mms_sim(mms_mma_set_profile_p->sim_id));
    mms_mma_send_set_profile_rsp(
        MMA_APP_SOURCE_MODULE,
        mms_mma_set_profile_p->app_id,
        mms_mma_set_profile_p->req_id,
        result);
    MMA_FREE(mms_mma_set_profile_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_setting_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                          [IN]        
 *  mms_mma_set_mms_setting_p       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_set_setting_req_hdlr(module_type source, wap_mma_set_setting_req_struct *mms_mma_set_mms_setting_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_set_mms_setting_p);

    if (msm_get_module_status(MSF_MODID_MSM) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_set_mms_setting_rsp(
            source,
            mms_mma_set_mms_setting_p->app_id,
            mms_mma_set_mms_setting_p->req_id,
            (kal_uint8) MMA_RESULT_FAIL_NOT_READY);
        MMA_FREE(mms_mma_set_mms_setting_p);
        return ;
    }
    else
    {
        if (g_mma_setting_cntx.setting != NULL)
        {
            MMA_FREE(g_mma_setting_cntx.setting);
            g_mma_setting_cntx.setting = NULL;
        }
        g_mma_setting_cntx.setting = mms_mma_set_mms_setting_p;
        g_mma_setting_cntx.setting->mms_version = mma_get_mms_version_from_em();
        mms_mma_send_set_mms_setting_rsp(
            source,
            mms_mma_set_mms_setting_p->app_id,
            mms_mma_set_mms_setting_p->req_id,
            (kal_uint8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_setting_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_setting_req_p       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_get_setting_req_hdlr(module_type source, wap_mma_get_setting_req_struct *get_setting_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_setting_rsp_struct *get_setting_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_setting_req_p);
    get_setting_rsp_p = (wap_mma_get_setting_rsp_struct*) MMA_CALLOC(sizeof(wap_mma_get_setting_rsp_struct));
    ASSERT(get_setting_rsp_p);

    get_setting_rsp_p->app_id = get_setting_req_p->app_id;
    get_setting_rsp_p->req_id = get_setting_req_p->req_id;

    if (g_mma_setting_cntx.setting == NULL)
    {
        get_setting_rsp_p->result = MMA_RESULT_FAIL_NOT_READY;
        mms_mma_send_get_setting_rsp(source, get_setting_rsp_p);
        MMA_FREE(get_setting_rsp_p);
    }
    else
    {
        get_setting_rsp_p->result = MMA_RESULT_OK;

        get_setting_rsp_p->mms_version = g_mma_setting_cntx.setting->mms_version;
        get_setting_rsp_p->creation_mode = g_mma_setting_cntx.setting->compose_sending_setting.creation_mode;
        get_setting_rsp_p->priority = g_mma_setting_cntx.setting->compose_sending_setting.priority;
        get_setting_rsp_p->validity_period = g_mma_setting_cntx.setting->compose_sending_setting.validity_period;
        get_setting_rsp_p->delivery_time = g_mma_setting_cntx.setting->compose_sending_setting.delivery_time;
        get_setting_rsp_p->delivery_report = g_mma_setting_cntx.setting->compose_sending_setting.delivery_report;
        get_setting_rsp_p->read_report = g_mma_setting_cntx.setting->compose_sending_setting.read_report;
        get_setting_rsp_p->max_mms_size = g_mma_setting_cntx.setting->compose_sending_setting.max_mms_size;
        get_setting_rsp_p->image_resize = g_mma_setting_cntx.setting->compose_sending_setting.image_resize;
        get_setting_rsp_p->signature = g_mma_setting_cntx.setting->compose_sending_setting.signature;
        get_setting_rsp_p->sliding_time = g_mma_setting_cntx.setting->compose_sending_setting.sliding_time;
        get_setting_rsp_p->layout = g_mma_setting_cntx.setting->compose_sending_setting.layout;
        get_setting_rsp_p->add_as_drm = g_mma_setting_cntx.setting->compose_sending_setting.add_as_drm;
        get_setting_rsp_p->max_no_pages = g_mma_setting_cntx.setting->compose_sending_setting.max_no_pages;
        get_setting_rsp_p->best_page_duration = g_mma_setting_cntx.setting->compose_sending_setting.best_page_duration;
        get_setting_rsp_p->reply_charging = g_mma_setting_cntx.setting->compose_sending_setting.reply_charging;
        get_setting_rsp_p->request_type = g_mma_setting_cntx.setting->compose_sending_setting.request_type;
        get_setting_rsp_p->deadline_for_reply = g_mma_setting_cntx.setting->compose_sending_setting.deadline_for_reply;
        get_setting_rsp_p->hide_sender = g_mma_setting_cntx.setting->compose_sending_setting.hide_sender;
        get_setting_rsp_p->size = g_mma_setting_cntx.setting->compose_sending_setting.size;
        get_setting_rsp_p->retrieval_setting.advertisement_filter =
            g_mma_setting_cntx.setting->retrieval_setting.advertisement_filter;
        get_setting_rsp_p->retrieval_setting.home_network = g_mma_setting_cntx.setting->retrieval_setting.home_network;
        get_setting_rsp_p->retrieval_setting.roaming = g_mma_setting_cntx.setting->retrieval_setting.roaming;
        get_setting_rsp_p->retrieval_setting.anonymous_filter =
            g_mma_setting_cntx.setting->retrieval_setting.anonymous_filter;
        get_setting_rsp_p->retrieval_setting.delivery_report =
            g_mma_setting_cntx.setting->retrieval_setting.delivery_report;

        mms_mma_send_get_setting_rsp(source, get_setting_rsp_p);
        MMA_FREE(get_setting_rsp_p);
    }
    MMA_FREE(get_setting_req_p);
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_target_roaming_ind_hdlr
 * DESCRIPTION
 *  This function is used to set roaming
 * PARAMETERS
 *  source                      [IN]        
 *  target_data_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_set_target_roaming_ind_hdlr(module_type source, mms_target_data_roaming_status_struct *target_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 sim_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(target_data_p);
    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        /* for test only */
       MMA_FREE(target_data_p);
        return;
    }
    sim_index = mma_setting_get_index_from_mms_sim_id(translate_mma_sim_to_mms_sim(target_data_p->sim_id));
    g_mma_setting_cntx.is_roaming[sim_index] = target_data_p->is_roaming;
	MMA_FREE(target_data_p);
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_free_rr_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mma_setting_free_rr_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mma_setting_cntx.rr_res.rr_text_your_msg != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_your_msg);
    }
	if(g_mma_setting_cntx.rr_res.rr_text_from != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_from);
    }
    if(g_mma_setting_cntx.rr_res.rr_text_to != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_to);
    }
    if(g_mma_setting_cntx.rr_res.rr_text_msgId != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_msgId);
    }
    if(g_mma_setting_cntx.rr_res.rr_text_read != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_read);
    }
    if(g_mma_setting_cntx.rr_res.rr_text_sent != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_sent);
    }
    if(g_mma_setting_cntx.rr_res.rr_text_was_read != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_was_read);
    }
	if(g_mma_setting_cntx.rr_res.rr_text_subject != NULL)
    {
        MMA_FREE(g_mma_setting_cntx.rr_res.rr_text_subject);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mma_setting_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 index;
    const char* user_agent;
    const char* ua_profile;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < MMA_MAX_SIM_COUNT; index++)
    {
        g_mma_setting_cntx.profile[index] = NULL;
        g_mma_setting_cntx.is_roaming[index] = 0;
        g_mma_setting_cntx.is_suspended[index] = TRUE;
    }
    g_mma_setting_cntx.setting = NULL;  
    user_agent = applib_inet_get_user_agent_string();
    ua_profile = applib_inet_get_user_agent_profile();
    g_mma_setting_cntx.user_agent = (kal_uint8*)MMA_CALLOC(strlen(user_agent) + 1);
    memcpy((char*)g_mma_setting_cntx.user_agent, (char*)user_agent, strlen(user_agent) + 1);
    g_mma_setting_cntx.ua_profile = (kal_uint8*)MMA_CALLOC(strlen(ua_profile) + 1);
    memcpy((char*)g_mma_setting_cntx.ua_profile, (char*)ua_profile, strlen(ua_profile) + 1);
    return KAL_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mma_setting_terminate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_setting_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_FREE(g_mma_setting_cntx.setting);
    for(index = 0; index < MMA_MAX_SIM_COUNT; index++)
    {
        if(g_mma_setting_cntx.profile[index] != NULL)
        {
            mma_setting_free_profile(g_mma_setting_cntx.profile[index]);
            g_mma_setting_cntx.profile[index] = NULL;
        }
    }
    mma_setting_free_rr_data();
    MMA_FREE(g_mma_setting_cntx.user_agent);
    MMA_FREE(g_mma_setting_cntx.ua_profile);
    memset(&g_mma_setting_cntx, 0x00, sizeof(mma_setting_context_struct));
    return KAL_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mma_setting_process_int_sig
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_setting_process_int_sig(mma_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sig);
    switch (sig->type)
    {
        case MMA_INT_SIG_TYPE_MSG_SET_PROFILE_REQ:
            mma_setting_set_profile_req_hdlr((module_type) sig->i_param, (wap_mma_set_profile_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_SET_SETTING_REQ:
            mma_setting_set_setting_req_hdlr((module_type) sig->i_param, (wap_mma_set_setting_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_GET_SETTING_REQ:
            mma_setting_get_setting_req_hdlr((module_type) sig->i_param, (wap_mma_get_setting_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_SET_ROAMING_STATUS:
			mma_setting_set_target_roaming_ind_hdlr((module_type) sig->i_param, (mms_target_data_roaming_status_struct*) sig->p_param);
			break;
        case MMA_INT_SIG_TYPE_MSG_SET_MMSC_VERSION:
			mma_setting_set_target_mmsc_version_ind_hdlr((module_type) sig->i_param, (mms_target_data_mms_version_struct*) sig->p_param);
			break;
		case MMA_INT_SIG_TYPE_MSG_SET_USER_AGENT:
			mma_setting_set_target_user_agent_ind_hdlr((module_type) sig->i_param, (mms_target_data_user_agent_struct*) sig->p_param);
			break;
		case MMA_INT_SIG_TYPE_MSG_SET_PLMN_NUMBER:
			mma_setting_set_target_plmn_number_ind_hdlr((module_type) sig->i_param, (mms_target_data_plmn_number_struct*) sig->p_param);
			break;
		case MMA_INT_SIG_TYPE_MSG_SET_OWNER_NUMBER:
			mma_setting_set_target_owner_number_ind_hdlr((module_type) sig->i_param, (mms_target_data_owner_number_struct*) sig->p_param);
			break;
       default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_profile
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mma_setting_profile_struct * mma_setting_get_profile(MSF_INT32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mma_setting_get_index_from_mms_sim_id(sim_id);
    return g_mma_setting_cntx.profile[sim_index];
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_settings
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
wap_mma_set_setting_req_struct * mma_setting_get_settings()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_setting_cntx.setting;
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_is_supended
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mma_setting_is_supended(MSF_INT32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mma_setting_get_index_from_mms_sim_id(sim_id);
    return ((kal_bool)(g_mma_setting_cntx.is_suspended[sim_index]));
}


/*****************************************************************************
 * FUNCTION
 *  mma_setting_is_roaming
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mma_setting_is_roaming(MSF_INT32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mma_setting_get_index_from_mms_sim_id(sim_id);
    return ((kal_bool)(g_mma_setting_cntx.is_roaming[sim_index]));
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_user_agent
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 * mma_setting_get_user_agent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_setting_cntx.user_agent;
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_user_prof
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 * mma_setting_get_user_prof()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_setting_cntx.ua_profile;
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_rr_settings
 * DESCRIPTION
 *  This function is used to remove the pending signal from the queue.
 * PARAMETERS
 *  sig     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mma_setting_read_report_res_struct mma_setting_get_rr_settings()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_setting_cntx.rr_res;
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_10_rr_string_res
 * DESCRIPTION
 *  Update string resource to mms v1.0 read report
 * PARAMETERS
 *  Key      [IN]         
 *  resId           [IN]        
 *  key             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
char *mma_setting_set_10_rr_string_res(unsigned short resId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *ucs2_str = NULL;
    char *utf8_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ucs2_str = (char*)GetString(resId);

	if (ucs2_str)
	{
		utf8_str = (char*)mma_ucs2_to_utf8_string((const kal_wchar*)ucs2_str);
	}           
	return utf8_str;
}

/*****************************************************************************
 * FUNCTION
 *  mma_setting_set_registry_10_rr_all_string_res
 * DESCRIPTION
 *  Update mms v1.0 read report string resources in registry
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 ****************************************************************************/
mma_result_enum mma_setting_set_registry_10_rr_all_string_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_setting_free_rr_data();
    g_mma_setting_cntx.rr_res.rr_text_your_msg = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_YOUR_MSG);
    g_mma_setting_cntx.rr_res.rr_text_from = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_FROM);
    g_mma_setting_cntx.rr_res.rr_text_to = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_TO);
    g_mma_setting_cntx.rr_res.rr_text_msgId = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_MSGID);
    g_mma_setting_cntx.rr_res.rr_text_read = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_READ);
    g_mma_setting_cntx.rr_res.rr_text_sent = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_SENT);
    g_mma_setting_cntx.rr_res.rr_text_was_read = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_WAS_READ);
    g_mma_setting_cntx.rr_res.rr_text_subject = (kal_uint8*)mma_setting_set_10_rr_string_res(MMS_STR_ID_RR_TEXT_SUBJECT);	
		
	return MMA_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_max_size
 * DESCRIPTION
 *  This function is used to get the max_size
 * PARAMETERS
 *  sim_id
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 mma_setting_get_max_retrival_size()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 max_mms_retrival_size_value_i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    max_mms_retrival_size_value_i = MMA_MAX_MMS_SIZE + wap_custom_get_mms_delta_retrival_size();
#else
/* It seems not good to pass extra limit, without knowing exact size. But its a feature. */
    max_mms_retrival_size_value_i = g_mma_setting_cntx.setting->compose_sending_setting.max_mms_size + (wap_custom_get_mms_delta_retrival_size());
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    max_mms_retrival_size_value_i += wap_custom_get_mms_user_element_header_size(); 
#endif  /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */
    return max_mms_retrival_size_value_i;
}
/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_account_id
 * DESCRIPTION
 *  This function is used to return account id.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 mma_setting_get_account_id(kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mma_setting_get_index_from_mms_sim_id(sim_id);
    return g_mma_setting_cntx.profile[sim_index]->data_account;
}

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_get_setting_max_mms_size
 * DESCRIPTION
 *  return size to msgmgr
 * PARAMETERS
 *  void
 * RETURNS
 *  size
 *****************************************************************************/
kal_uint32 mma_get_setting_max_mms_size(void)
{
	return g_mma_setting_cntx.setting->compose_sending_setting.max_mms_size;
}
#endif

#ifdef __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_get_setting_slide_timing
 * DESCRIPTION
 *  returns slide timing
 * PARAMETERS
 *  void
 * RETURNS
 *  size
 *****************************************************************************/

kal_uint32 mma_get_setting_slide_timing(void)
{
    return g_mma_setting_cntx.setting->compose_sending_setting.sliding_time.value;
}
#endif  /* __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mma_setting_get_preffered_storage
 * DESCRIPTION
 *  This function is used to get the preffered storage
 * PARAMETERS
 *  VOID
 * RETURNS
 *  Will returns the preffered storage
 *****************************************************************************/
kal_uint8 mma_setting_get_preffered_storage(void)
{
    /* No Need to put any intelligence here */
    return g_mma_setting_cntx.setting->preffered_storage;

}

#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_SETTING_C */
