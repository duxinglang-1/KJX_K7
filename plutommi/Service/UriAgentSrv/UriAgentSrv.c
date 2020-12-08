/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 ******************************************************************************/

/******************************************************************************
 * Filename:
 * ---------
 * UriAgentSrv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements main function of URI Agent.
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
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
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 *****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#include "UriAgentSrvProt.h"
#include "kal_trace.h"
#include "app_str.h"
#include "app_url.h"

#ifdef __MMI_URI_AGENT_UT__
#include "UriAgentSrvUT.h"
#endif 

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "stack_msgs.h"
#include "MMI_inet_app_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_common.h"

/****************************************************************************** 
 * Constant
 ******************************************************************************/
#define SRV_URIAGENT_MEM_POOL_SIZE (2560)

/****************************************************************************** 
 * Type Definition
 ******************************************************************************/
typedef struct
{
    U8 num_of_schemes;
    U8 num_of_prefixes;
    MMI_BOOL scheme_encodedURL[SRV_URIAGENT_MAX_SCHEME_NUM];
    MMI_BOOL prefix_encodedURL[SRV_URIAGENT_MAX_PREFIX_NUM];
    kal_uint32 mem_pool[SRV_URIAGENT_MEM_POOL_SIZE / 4];
    char *scheme_list[SRV_URIAGENT_MAX_SCHEME_NUM];
    char *prefix_list[SRV_URIAGENT_MAX_PREFIX_NUM];
    srv_uriagent_uri_request_hdlr_fn scheme_hdlr[SRV_URIAGENT_MAX_SCHEME_NUM];
    srv_uriagent_uri_request_hdlr_fn prefix_hdlr[SRV_URIAGENT_MAX_PREFIX_NUM];
    srv_uriagent_uri_request_hdlr_cb cb[SRV_URIAGENT_APPID_MAX];
    KAL_ADM_ID adm_id;
} srv_uriagent_context_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static srv_uriagent_context_struct g_srv_uriagent_cntx;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void srv_uriagent_uri_request_generic_callback(
                srv_uriagent_appid_enum ura_appid,
                srv_uriagent_appid_enum uha_appid,
                S32 result);
static void srv_uriagent_invoke_uri_request_hdlr_cb_ind(void *msg);
static void *srv_uriagent_malloc(kal_uint32 size);
static void srv_uriagent_mfree(void *mem_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_init
 * DESCRIPTION
 *  Init function of URI Agent.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_srv_uriagent_cntx, 0x0, sizeof(srv_uriagent_context_struct));
    g_srv_uriagent_cntx.adm_id = kal_adm_create(g_srv_uriagent_cntx.mem_pool, SRV_URIAGENT_MEM_POOL_SIZE, NULL, KAL_FALSE);
    SRV_URIAGENT_ASSERT(g_srv_uriagent_cntx.adm_id);
    SetProtocolEventHandler(
        (PsFuncPtr) srv_uriagent_invoke_uri_request_hdlr_cb_ind,
        MSG_ID_SRV_URIAGENT_INVOKE_URI_REQUEST_HDLR_CB_IND);

#ifdef __MMI_URI_AGENT_UT__
    srv_uriagent_ut_main();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_register_hdlr_by_scheme
 * DESCRIPTION
 *  This function is used for UHA (URI Handle Application) to register its URI
 *  request handler "hdlr" to process the specified scheme "scheme". Below is
 *  the generic syntax of URI scheme.
 *  scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )
 * PARAMETERS
 *  scheme      [IN]        URI scheme (null terminated string)
 *  hdlr        [IN]        URI request handler function
 *  encodedURL  [IN]		UHA needs URL encoded string or normal string
 * RETURNS
 *  SRV_URIAGENT_ERR_OK: Success to register handler by scheme
 *  SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED: Fail to register handler because handler was registered by the same scheme
 *  SRV_URIAGENT_ERR_UNSUPPORTED: Fail to register handler due to other reasons
 *****************************************************************************/
srv_uriagent_err_enum srv_uriagent_register_hdlr_by_scheme(const char *scheme, srv_uriagent_uri_request_hdlr_fn hdlr, MMI_BOOL encodedURL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char **scheme_list = g_srv_uriagent_cntx.scheme_list;
    U8 num_of_schemes = g_srv_uriagent_cntx.num_of_schemes;
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_SCHEME_INFO, num_of_schemes, hdlr);

    /* Check if input parameters are valid and number of registered schemes is less than SRV_URIAGENT_MAX_SCHEME_NUM */
    if (!hdlr || srv_uriagent_check_validity_of_scheme(scheme) == MMI_FALSE ||
        num_of_schemes == SRV_URIAGENT_MAX_SCHEME_NUM)
    {
        MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_SCHEME_ERR_UNSUPPORTED);
        SRV_URIAGENT_ASSERT(0);
        return SRV_URIAGENT_ERR_UNSUPPORTED;
    }

    /* Check if any URI request handler is registered for the same scheme */
    for (index = 0; index < num_of_schemes; index++)
    {
        if (!app_stricmp((kal_char *)scheme, (kal_char *)scheme_list[index]))
        {
            MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_SCHEME_ERR_SCHEME_IS_REGISTERED);
            return SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED;
        }
    }

    /* Allocate memory to store this scheme and its corresponding URI request handler into g_srv_uriagent_cntx */
    scheme_list[num_of_schemes] = srv_uriagent_malloc(strlen(scheme) + 1);

    if (scheme_list[num_of_schemes] == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_SCHEME_ERR_UNSUPPORTED);
        return SRV_URIAGENT_ERR_UNSUPPORTED;
    }

    strcpy(scheme_list[num_of_schemes], scheme);
    scheme_list[num_of_schemes][strlen(scheme)] = '\0';
    g_srv_uriagent_cntx.scheme_hdlr[num_of_schemes] = hdlr;
	g_srv_uriagent_cntx.scheme_encodedURL[num_of_schemes] = encodedURL;
    g_srv_uriagent_cntx.num_of_schemes++;
    return SRV_URIAGENT_ERR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_register_hdlr_by_prefix
 * DESCRIPTION
 *  This function is used for UHA (URI Handle Application) to register its URI
 *  request handler by URI prefix. URI prefix is composed of scheme and format
 *  where scheme and format are divided using colon ":". Below is the generic
 *  syntax of URI prefix.
 *  prefix = scheme ": " format
 *  scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )
 *  format =  *CHARACTER
 * PARAMETERS
 *  prefix      [IN]        URI prefix (null terminated string)
 *  hdlr        [IN]        URI request handler function
 *  encodedURL  [IN]		UHA needs URL encoded string or normal string 
 * RETURNS
 *  SRV_URIAGENT_ERR_OK: Success to register handler by prefix
 *  SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED: Fail to register handler because existing handler was registered by the same prefix
 *  SRV_URIAGENT_ERR_UNSUPPORTED: Fail to register handler due to other reasons
 *****************************************************************************/
srv_uriagent_err_enum srv_uriagent_register_hdlr_by_prefix(const char *prefix, srv_uriagent_uri_request_hdlr_fn hdlr, MMI_BOOL encodedURL)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char **prefix_list = g_srv_uriagent_cntx.prefix_list;
    U8 num_of_prefixes = g_srv_uriagent_cntx.num_of_prefixes;
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_PREFIX_INFO, num_of_prefixes, hdlr);

    /* Check if input parameters are valid and number of registered prefixes is less than SRV_URIAGENT_MAX_PREFIX_NUM */
    if (hdlr == NULL || srv_uriagent_check_validity_of_prefix(prefix) == MMI_FALSE ||
        num_of_prefixes == SRV_URIAGENT_MAX_PREFIX_NUM)
    {
        MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_PREFIX_ERR_UNSUPPORTED);
        SRV_URIAGENT_ASSERT(0);
        return SRV_URIAGENT_ERR_UNSUPPORTED;
    }

    /* Check if any URI request handler is registered for the same prefix */
    for (index = 0; index < num_of_prefixes; index++)
    {
        if (!app_stricmp((kal_char *)prefix, (kal_char *)prefix_list[index]))
        {
            MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_PREFIX_ERR_PREFIX_IS_REGISTERED);
            return SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED;
        }
    }

    /* Allocate memory to store this prefix and its corresponding URI request handler into g_srv_uriagent_cntx */
    prefix_list[num_of_prefixes] = srv_uriagent_malloc(strlen(prefix) + 1);

    if (prefix_list[num_of_prefixes] == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_REGISTER_HDLR_BY_PREFIX_ERR_UNSUPPORTED);
        return SRV_URIAGENT_ERR_UNSUPPORTED;
    }

    strcpy(prefix_list[num_of_prefixes], prefix);
    prefix_list[num_of_prefixes][strlen(prefix)] = '\0';	
    g_srv_uriagent_cntx.prefix_hdlr[num_of_prefixes] = hdlr;
	g_srv_uriagent_cntx.prefix_encodedURL[num_of_prefixes] = encodedURL;
    g_srv_uriagent_cntx.num_of_prefixes++;
    return SRV_URIAGENT_ERR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_dispatch_uri_request
 * DESCRIPTION
 *  This function is responsible to dispatch URI request from URA to UHA.
 * PARAMETERS
 *  ura_appid       [IN]        Application id of URA
 *  url             [IN]        URL (UTF-8 encoded, null terminated string)
 *  options         [IN]        Options to process this URI request
 *  cb              [IN]        URI request callback function
 * RETURNS
 *  SRV_URIAGENT_ERR_OK: Success to dispatch URI request from URA to UHA
 *  SRV_URIAGENT_ERR_PROCESSING: Fail to dispatch URI request from URA to UHA because the previous URI request from the same URA is still in processing
 *  SRV_URIAGENT_ERR_UNSUPPORTED: Fail to dispatch URI request from URA to UHA due to other reasons
 *****************************************************************************/
srv_uriagent_err_enum srv_uriagent_dispatch_uri_request(
                        srv_uriagent_appid_enum ura_appid,
                        char *url,
                        srv_uriagent_options_enum options,
                        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;
	char *normal_url = NULL;
    char **scheme_list = g_srv_uriagent_cntx.scheme_list;
    char **prefix_list = g_srv_uriagent_cntx.prefix_list;
    U8 num_of_schemes = g_srv_uriagent_cntx.num_of_schemes;
    U8 num_of_prefixes = g_srv_uriagent_cntx.num_of_prefixes;
    U16 index = 0;
    U16 len = 0;
    U16 prefix_idx = 0;
    U16 prefix_len = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_DISPATCH_URI_REQUEST_INFO, ura_appid, options, cb);

    /* Check if input parameters are valid */
    if (ura_appid >= SRV_URIAGENT_APPID_MAX || url == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_DISPATCH_URI_REQUEST_ERR_UNSUPPORTED);
        SRV_URIAGENT_ASSERT(ura_appid < SRV_URIAGENT_APPID_MAX);
        return SRV_URIAGENT_ERR_UNSUPPORTED;
    }

    /* Check if any URI request from the same URA is still in processing */
    if (g_srv_uriagent_cntx.cb[ura_appid])
    {
        MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_DISPATCH_URI_REQUEST_ERR_PROCESSING);
        return SRV_URIAGENT_ERR_PROCESSING;
    }

    /* Check if any URI request handler (which was registered by prefix) can be used to process this URL and use the most matched one */
    for (index = 0; index < num_of_prefixes; index++)
    {
        len = strlen(prefix_list[index]);
        if (!app_strnicmp((kal_char *)url, (kal_char *)prefix_list[index], len) && len > prefix_len)
        {
            prefix_idx = index;
            prefix_len = len;
        }
    }

    if (prefix_len)
    {
        g_srv_uriagent_cntx.cb[ura_appid] = cb;				

		if (g_srv_uriagent_cntx.prefix_encodedURL[prefix_idx] == MMI_FALSE)
		{
	    	normal_url = srv_uriagent_malloc(strlen(url) + 1);
			memset(normal_url, 0x0, strlen(url) + 1);
			result = applib_cvt_escape_string_to_normal_string(url, strlen(url), normal_url, strlen(url));
			MMI_ASSERT(result == MMI_TRUE);			
		}
        g_srv_uriagent_cntx.prefix_hdlr[prefix_idx] (ura_appid, 
													 (normal_url == NULL ? url : normal_url),													
													 strchr((normal_url == NULL ? url : normal_url), ':') + 1, 
													 options,
           	                                         (cb == NULL ? NULL : srv_uriagent_uri_request_generic_callback));
		srv_uriagent_mfree(normal_url);
        return SRV_URIAGENT_ERR_OK;
    }

    /* Check if any URI request handler (which was registered by scheme) can be used to process this URL */
    for (index = 0; index < num_of_schemes; index++)
    {
        len = strlen(scheme_list[index]);
        if (!app_strnicmp((kal_char *)url, (kal_char *)scheme_list[index], len) && url[len] == ':')
        {        
            g_srv_uriagent_cntx.cb[ura_appid] = cb;

			if (g_srv_uriagent_cntx.scheme_encodedURL[index] == MMI_FALSE)
			{
	    		normal_url = srv_uriagent_malloc(strlen(url) + 1);
				memset(normal_url, 0x0, strlen(url) + 1);
				result = applib_cvt_escape_string_to_normal_string(url, strlen(url), normal_url, strlen(url));
				MMI_ASSERT(result == MMI_TRUE);			
			}			
            g_srv_uriagent_cntx.scheme_hdlr[index] (ura_appid, 
													(normal_url == NULL ? url : normal_url), 
													strchr((normal_url == NULL ? url : normal_url), ':') + 1, 
													options,
                                                    (cb == NULL ? NULL : srv_uriagent_uri_request_generic_callback));
			srv_uriagent_mfree(normal_url);
            return SRV_URIAGENT_ERR_OK;
        }
    }

    /* Unable to find any URI request handler to process this URL */
    MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_DISPATCH_URI_REQUEST_ERR_UNSUPPORTED);
    return SRV_URIAGENT_ERR_UNSUPPORTED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_has_registered_hdlr
 * DESCRIPTION
 *  Check if any URI request handler can be used to process this specified URL.
 * PARAMETERS
 *  url     [IN]        URL (unescape, UTF-8 encoded, null terminated string)
 * RETURNS
 *  MMI_TRUE: It has handler to process this URI request
 *  MMI_FALSE: It has no handler to process this URI request
 *****************************************************************************/
MMI_BOOL srv_uriagent_has_registered_hdlr(char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char **scheme_list = g_srv_uriagent_cntx.scheme_list;
    char **prefix_list = g_srv_uriagent_cntx.prefix_list;
    U8 num_of_schemes = g_srv_uriagent_cntx.num_of_schemes;
    U8 num_of_prefixes = g_srv_uriagent_cntx.num_of_prefixes;
    U16 index = 0;
    U16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url)
    {
        /* Check if any URI request handler (which was registered by prefix) can be used to process this URL */
        for (index = 0; index < num_of_prefixes; index++)
        {
            len = strlen(prefix_list[index]);
            if (!app_strnicmp(url, prefix_list[index], len) )
            {
                return MMI_TRUE;
            }
        }

        /* Check if any URI request handler (which was registered by scheme) can be used to process this URL */
        for (index = 0; index < num_of_schemes; index++)
        {
            len = strlen(scheme_list[index]);
            if (!app_strnicmp(url, scheme_list[index], len) && url[len] == ':')
            {
                return MMI_TRUE;
            }
        }
    }
    /* Unable to find any URI request handler to process this URL */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_num_of_registered_schemes
 * DESCRIPTION
 *  Retrieve the total number of all registered schemes.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_uriagent_get_num_of_registered_schemes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_uriagent_cntx.num_of_schemes;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_registered_scheme_by_index
 * DESCRIPTION
 *  Retrieve the registered scheme by index.
 * PARAMETERS
 *  index       [IN]        Index of the specified registered scheme
 * RETURNS
 *  
 *****************************************************************************/
const char *srv_uriagent_get_registered_scheme_by_index(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_srv_uriagent_cntx.num_of_schemes)
    {
        return (const char*)g_srv_uriagent_cntx.scheme_list[index];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_num_of_registered_prefixes
 * DESCRIPTION
 *  Retrieve total number of all registered prefixes.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_uriagent_get_num_of_registered_prefixes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_uriagent_cntx.num_of_prefixes;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_registered_prefix_by_index
 * DESCRIPTION
 *  Retrieve the registered prefix by index.
 * PARAMETERS
 *  index       [IN]        Index of the specified registered prefix
 * RETURNS
 *  
 *****************************************************************************/
const char *srv_uriagent_get_registered_prefix_by_index(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_srv_uriagent_cntx.num_of_prefixes)
    {
        return (const char*)g_srv_uriagent_cntx.prefix_list[index];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_uri_request_generic_callback
 * DESCRIPTION
 *  Generic URI request handler callback function provided by URI agent. This
 *  function will be invoked by UHA (URI Handle Application). In this function,
 *  URI agent sends a primitive to itself.
 * PARAMETERS
 *  ura_appid       [IN]        Application id of URA
 *  uha_appid       [IN]        Application id of UHA
 *  result          [IN]        Result of processing URI request
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_uriagent_uri_request_generic_callback(
                srv_uriagent_appid_enum ura_appid,
                srv_uriagent_appid_enum uha_appid,
                S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uriagent_invoke_uri_request_hdlr_cb_ind_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_URI_REQUEST_GENERIC_CALLBACK_INFO, ura_appid, uha_appid, result);

    if (ura_appid >= SRV_URIAGENT_APPID_MAX || uha_appid >= SRV_URIAGENT_APPID_MAX)
    {
        SRV_URIAGENT_ASSERT(0);
        return;
    }

	myMsgPtr = OslAllocDataPtr(srv_uriagent_invoke_uri_request_hdlr_cb_ind_struct);

    myMsgPtr->cb = g_srv_uriagent_cntx.cb[ura_appid];
    myMsgPtr->ura_appid = ura_appid;
    myMsgPtr->uha_appid = uha_appid;
    myMsgPtr->result = result;

	mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_URIAGENT_INVOKE_URI_REQUEST_HDLR_CB_IND, (oslParaType*) myMsgPtr, NULL);

    g_srv_uriagent_cntx.cb[ura_appid] = NULL;
}



/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_invoke_uri_request_hdlr_cb_ind
 * DESCRIPTION
 *  Invoke the callback function provided by URA (URI Request Application)
 * PARAMETERS
 *  msg     [IN]        Local parameter of message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_uriagent_invoke_uri_request_hdlr_cb_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uriagent_invoke_uri_request_hdlr_cb_ind_struct *localBuff_p =
        (srv_uriagent_invoke_uri_request_hdlr_cb_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localBuff_p->cb(localBuff_p->ura_appid, localBuff_p->uha_appid, localBuff_p->result);
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_malloc
 * DESCRIPTION
 *  Memory allocation function
 * PARAMETERS
 *  size        [IN]        Memory size
 * RETURNS
 *  void
 *****************************************************************************/
static void *srv_uriagent_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    kal_uint32 mempool_max_alloc = 0;
    kal_uint32 mempool_total_left = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(g_srv_uriagent_cntx.adm_id, (kal_uint32) size);

    if (!ptr)
    {
        mempool_max_alloc = kal_adm_get_max_alloc_size(g_srv_uriagent_cntx.adm_id);
        mempool_total_left = kal_adm_get_total_left_size(g_srv_uriagent_cntx.adm_id);

        MMI_TRACE(MMI_INET_TRC_G2_URIAGENT, SRV_URIAGENT_MALLOC_INFO, size, mempool_max_alloc, mempool_total_left);
        SRV_URIAGENT_ASSERT(0);
    }
    return ptr;
}

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_mfree
 * DESCRIPTION
 *  Memory free function
 * PARAMETERS
 *  mem_addr    [IN]        Memory address
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_uriagent_mfree(void *mem_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mem_addr != NULL)
	{
		kal_adm_free(g_srv_uriagent_cntx.adm_id, mem_addr);
	}
}
	
#endif /* __MMI_URI_AGENT__ */ 

