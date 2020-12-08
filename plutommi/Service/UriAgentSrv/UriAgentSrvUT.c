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
 * URIAgentUT.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements test case of URI Agent UT.
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
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
#include "UriAgentSrvUT.h"
#include <stdio.h>
#include <string.h>

#ifdef __MMI_URI_AGENT_UT__

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  smsapp_uri_request_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  uha_appid       [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void smsapp_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ura_appid == SRV_URIAGENT_APPID_SMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmsapp_uri_request_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  uha_appid       [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmsapp_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ura_appid == SRV_URIAGENT_APPID_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  brwapp_uri_request_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  uha_appid       [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void brwapp_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ura_appid == SRV_URIAGENT_APPID_BRW);
}


/*****************************************************************************
 * FUNCTION
 *  uri_request_generic_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  uha_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uri_request_generic_hdlr(
        srv_uriagent_appid_enum ura_appid,
        srv_uriagent_appid_enum uha_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb)
    {
        cb(ura_appid, uha_appid, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  unused_uri_request_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  uha_appid       [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void unused_uri_request_cb(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  scheme_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void scheme_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[URI Agent UT] scheme_uri_request_hdlr(), ura_appid = %d, url = %s", ura_appid, url);
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_STREAMING, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  schemeA_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void schemeA_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[URI Agent UT] schemeA_uri_request_hdlr(), ura_appid = %d, url = %s", ura_appid, url);
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_CALLMANAGER, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  schemeB_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void schemeB_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[URI Agent UT] schemeB_uri_request_hdlr(), ura_appid = %d, url = %s", ura_appid, url);
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_PHONEBOOK, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  scheme_format_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void scheme_format_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(
        MOD_MMI,
        "[URI Agent UT] scheme_format_uri_request_hdlr(), ura_appid = %d, url = %s",
        ura_appid,
        url);
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_STREAMING, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  scheme_formatA_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void scheme_formatA_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(
        MOD_MMI,
        "[URI Agent UT] scheme_formatA_uri_request_hdlr(), ura_appid = %d, url = %s",
        ura_appid,
        url);
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_CALLMANAGER, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  scheme_formatB_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void scheme_formatB_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(
        MOD_MMI,
        "[URI Agent UT] scheme_formatB_uri_request_hdlr(), ura_appid = %d, url = %s",
        ura_appid,
        url);
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_PHONEBOOK, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  used_scheme_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void used_scheme_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_STREAMING, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  unused_scheme_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void unused_scheme_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  used_prefix_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void used_prefix_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_STREAMING, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  unused_prefix_uri_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [IN]        
 *  param           [IN]        
 *  options         [IN]        
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void unused_prefix_uri_request_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_register_hdlr_by_scheme_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_register_hdlr_by_scheme_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    char scheme[10];
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." ) */

    /* TC-URIAgent-A000: Success to register handler by scheme "scheme" */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme", scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-E000: Query information of all registered schemes (one registered scheme "scheme") */
    ASSERT(srv_uriagent_get_num_of_registered_schemes() == 1);
    ASSERT(strcmp(srv_uriagent_get_registered_scheme_by_index(0), "scheme") == 0);

    /* TC-URIAgent-A001: Success to register handler by scheme "schemeA" */
    err_code = srv_uriagent_register_hdlr_by_scheme("schemeA", schemeA_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-E001: Query information of all registered schemes (two registered schemes "scheme" and "schemeA") */
    ASSERT(srv_uriagent_get_num_of_registered_schemes() == 2);
    ASSERT(strcmp(srv_uriagent_get_registered_scheme_by_index(0), "scheme") == 0);
    ASSERT(strcmp(srv_uriagent_get_registered_scheme_by_index(1), "schemeA") == 0);

    /* TC-URIAgent-A002: Success to register handler by scheme "schemeB" */
    err_code = srv_uriagent_register_hdlr_by_scheme("schemeB", schemeB_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-E002: Query information of all registered schemes (three registered schemes "scheme" and "schemeA" and "schemeB") */
    ASSERT(srv_uriagent_get_num_of_registered_schemes() == 3);
    ASSERT(strcmp(srv_uriagent_get_registered_scheme_by_index(0), "scheme") == 0);
    ASSERT(strcmp(srv_uriagent_get_registered_scheme_by_index(1), "schemeA") == 0);
    ASSERT(strcmp(srv_uriagent_get_registered_scheme_by_index(2), "schemeB") == 0);

    /* TC-URIAgent-A100: Fail to register handler by scheme becuase handler is registered by the same scheme "scheme" */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED);

    /* TC-URIAgent-A101: Fail to register handler by scheme becuase handler is registered by the same scheme "schemeA" */
    err_code = srv_uriagent_register_hdlr_by_scheme("schemeA", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED);

    /* TC-URIAgent-A102: Fail to register handler by scheme becuase handler is registered by the same scheme "schemeB" */
    err_code = srv_uriagent_register_hdlr_by_scheme("schemeB", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED);

    /* TC-URIAgent-A200: Fail to register handler due to invalid URI scheme (scheme is NULL) */
    err_code = srv_uriagent_register_hdlr_by_scheme(NULL, unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A201: Fail to register handler due to invalid URI scheme (the first character of scheme is ' ') */
    err_code = srv_uriagent_register_hdlr_by_scheme(" scheme", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A202: Fail to register handler due to invalid URI scheme (the first character of scheme is '1') */
    err_code = srv_uriagent_register_hdlr_by_scheme("1scheme", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A203: Fail to register handler due to invalid URI scheme (the first character of scheme is '+') */
    err_code = srv_uriagent_register_hdlr_by_scheme("+scheme", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A204: Fail to register handler due to invalid URI scheme (the first character of scheme is '-') */
    err_code = srv_uriagent_register_hdlr_by_scheme("-scheme", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A205: Fail to register handler due to invalid URI scheme (the first character of scheme is '.') */
    err_code = srv_uriagent_register_hdlr_by_scheme(".scheme", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A206: Fail to register handler due to invalid URI scheme (the first character of scheme is '_') */
    err_code = srv_uriagent_register_hdlr_by_scheme("_scheme", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A207: Fail to register handler due to invalid URI scheme (scheme has invalid character '*') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme*", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A208: Fail to register handler due to invalid URI scheme (scheme has invalid character ':') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme:", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A209: Fail to register handler due to invalid URI scheme (scheme has invalid character '%') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme%", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A210: Fail to register handler due to invalid URI scheme (scheme has invalid character ' ' at the end) */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme ", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A211: Fail to register handler due to invalid URI scheme (scheme has invalid character '#') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme#", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A212: Fail to register handler due to invalid URI scheme (scheme has invalid character '@') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme@", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A213: Fail to register handler due to invalid URI scheme (scheme has invalid character '!') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme!", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A214: Fail to register handler due to invalid URI scheme (scheme has invalid character '=') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme=", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A215: Fail to register handler due to invalid URI scheme (scheme has invalid character '|') */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme|", unused_scheme_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-A300: Fail to register handler due to invalid URI request handler (handler is NULL) */
    err_code = srv_uriagent_register_hdlr_by_scheme("scheme1", NULL, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    for (i = 0; i <= SRV_URIAGENT_MAX_SCHEME_NUM; i++)
    {
        sprintf(scheme, "scheme%03d", i);

        if (srv_uriagent_get_num_of_registered_schemes() < SRV_URIAGENT_MAX_SCHEME_NUM)
        {
            /* TC-URIAgent-A003: Success to register handler by scheme */
            err_code = srv_uriagent_register_hdlr_by_scheme(scheme, used_scheme_uri_request_hdlr, MMI_FALSE);
            ASSERT(err_code == SRV_URIAGENT_ERR_OK);
        }
        else
        {
            /* TC-URIAgent-A400: Fail to register handler by scheme due to too many registered schemes */
            err_code = srv_uriagent_register_hdlr_by_scheme(scheme, unused_scheme_uri_request_hdlr, MMI_FALSE);
            ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);
        }

        if (srv_uriagent_get_num_of_registered_schemes() < SRV_URIAGENT_MAX_SCHEME_NUM)
        {
            /* TC-URIAgent-A103: Fail to register handler by scheme becuase handler is registered by the same scheme */
            err_code = srv_uriagent_register_hdlr_by_scheme(scheme, unused_scheme_uri_request_hdlr, MMI_FALSE);
            ASSERT(err_code == SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_register_hdlr_by_prefix_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_register_hdlr_by_prefix_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    char prefix[17];
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * prefix = scheme ":" format
     * scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." ) 
     * format = *(CHARACTER) 
     */

    /* TC-URIAgent-B000: Success to register handler by prefix "scheme:format" */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme:format", scheme_format_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-F000: Query information of all registered prefixes (one registered prefix "scheme:format") */
    ASSERT(srv_uriagent_get_num_of_registered_prefixes() == 1);
    ASSERT(strcmp(srv_uriagent_get_registered_prefix_by_index(0), "scheme:format") == 0);

    /* TC-URIAgent-B001: Success to register handler by prefix "scheme:formatA" */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme:formatA", scheme_formatA_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-F001: Query information of all registered prefixes (two registered prefixes "scheme:format" and "scheme:formatA") */
    ASSERT(srv_uriagent_get_num_of_registered_prefixes() == 2);
    ASSERT(strcmp(srv_uriagent_get_registered_prefix_by_index(0), "scheme:format") == 0);
    ASSERT(strcmp(srv_uriagent_get_registered_prefix_by_index(1), "scheme:formatA") == 0);

    /* TC-URIAgent-B002: Success to register handler by prefix "scheme:formatB" */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme:formatB", scheme_formatB_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-F002: Query information of all registered prefixes (three registered prefixes "scheme:format" and "scheme:formatA" and "scheme:formatB") */
    ASSERT(srv_uriagent_get_num_of_registered_prefixes() == 3);
    ASSERT(strcmp(srv_uriagent_get_registered_prefix_by_index(0), "scheme:format") == 0);
    ASSERT(strcmp(srv_uriagent_get_registered_prefix_by_index(1), "scheme:formatA") == 0);
    ASSERT(strcmp(srv_uriagent_get_registered_prefix_by_index(2), "scheme:formatB") == 0);

    /* TC-URIAgent-B100: Fail to register handler by prefix becuase handler is registered by the same prefix "scheme:format" */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED);

    /* TC-URIAgent-B101: Fail to register handler by prefix becuase handler is registered by the same prefix "scheme:formatA" */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme:formatA", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED);

    /* TC-URIAgent-B102: Fail to register handler by prefix becuase handler is registered by the same prefix "scheme:formatB" */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme:formatB", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED);

    /* TC-URIAgent-B200: Fail to register handler due to invalid URI prefix (prefix is NULL) */
    err_code = srv_uriagent_register_hdlr_by_prefix(NULL, unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B201: Fail to register handler due to invalid URI prefix (the first character of prefix is ' ') */
    err_code = srv_uriagent_register_hdlr_by_prefix(" scheme:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B202: Fail to register handler due to invalid URI prefix (the first character of prefix is '1') */
    err_code = srv_uriagent_register_hdlr_by_prefix("1scheme:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B203: Fail to register handler due to invalid URI prefix (the first character of prefix is '+') */
    err_code = srv_uriagent_register_hdlr_by_prefix("+scheme:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B204: Fail to register handler due to invalid URI prefix (the first character of prefix is '-') */
    err_code = srv_uriagent_register_hdlr_by_prefix("-scheme:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B205: Fail to register handler due to invalid URI prefix (the first character of prefix is '.') */
    err_code = srv_uriagent_register_hdlr_by_prefix(".scheme:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B206: Fail to register handler due to invalid URI prefix (the first character of prefix is '_') */
    err_code = srv_uriagent_register_hdlr_by_prefix("_scheme:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B207: Fail to register handler due to invalid URI prefix (prefix has invalid character '*' in scheme) */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme*:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B208: Fail to register handler due to invalid URI prefix (prefix has no character ':') */
    err_code = srv_uriagent_register_hdlr_by_prefix("schemeformat", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B209: Fail to register handler due to invalid URI prefix (prefix has invalid character '%' in scheme) */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme%:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B210: Fail to register handler due to invalid URI prefix (prefix has invalid character ' ' in scheme) */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme :format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B211: Fail to register handler due to invalid URI prefix (prefix has invalid character '#' in scheme) */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme#:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B212: Fail to register handler due to invalid URI prefix (prefix has invalid character '$' in scheme) */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme$:format", unused_prefix_uri_request_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-B300: Fail to register handler due to invalid URI request handler (handler is NULL) */
    err_code = srv_uriagent_register_hdlr_by_prefix("scheme:format", NULL, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    for (i = 0; i < (SRV_URIAGENT_MAX_PREFIX_NUM); i++)
    {
        sprintf(prefix, "scheme:format%03d", i);

        if (srv_uriagent_get_num_of_registered_prefixes() < SRV_URIAGENT_MAX_PREFIX_NUM)
        {
            /* TC-URIAgent-B003: Success to register handler by prefix */
            err_code = srv_uriagent_register_hdlr_by_prefix(prefix, used_prefix_uri_request_hdlr, MMI_FALSE);
            ASSERT(err_code == SRV_URIAGENT_ERR_OK);
        }
        else
        {
            /* TC-URIAgent-B400: Fail to register handler by prefix due to too many registered prefixes */
            err_code = srv_uriagent_register_hdlr_by_prefix(prefix, unused_prefix_uri_request_hdlr, MMI_FALSE);
            ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);
        }

        if (srv_uriagent_get_num_of_registered_prefixes() < SRV_URIAGENT_MAX_PREFIX_NUM)
        {
            /* TC-URIAgent-B103: Fail to register handler by prefix becuase handler is registered by the same prefix */
            err_code = srv_uriagent_register_hdlr_by_prefix(prefix, unused_prefix_uri_request_hdlr, MMI_FALSE);
            ASSERT(err_code == SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_has_registered_hdlr_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_has_registered_hdlr_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL retVal = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TC-URIAgent-C000: Check if any handler is registered to process this URI request: URL is "scheme:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("scheme:ThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C001: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With Space " */
    retVal = srv_uriagent_has_registered_hdlr("scheme: This Is URL With Space ");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C002: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With : And Space" */
    retVal = srv_uriagent_has_registered_hdlr("scheme: This Is URL With : And Space");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C003: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With ^_^" */
    retVal = srv_uriagent_has_registered_hdlr("scheme: This Is URL With ^_^");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C004: Check if any handler is registered to process this URI request: URL is "scheme: This Is URL With %" */
    retVal = srv_uriagent_has_registered_hdlr("scheme: This Is URL With %");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C005: Check if any handler is registered to process this URI request: URL is "scheme::This Is URL With Double :" */
    retVal = srv_uriagent_has_registered_hdlr("scheme::This Is URL With Double :");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C006: Check if any handler is registered to process this URI request: URL is "schemeA:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("schemeA:ThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C007: Check if any handler is registered to process this URI request: URL is "schemeB:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("schemeB:ThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C008: Check if any handler is registered to process this URI request: URL is "scheme:formatThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("scheme:formatThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C009: Check if any handler is registered to process this URI request: URL is "scheme:formatAThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("scheme:formatAThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C010: Check if any handler is registered to process this URI request: URL is "scheme:formatBThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("scheme:formatBThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C011: Check if any handler is registered to process this URI request: URL is "scheme:formatCThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("scheme:formatCThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C100: Check if any handler is registered to process this URI request: URL is "schemeC:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("schemeC:ThisIsURL");
    ASSERT(retVal == MMI_FALSE);

    /* TC-URIAgent-C101: Check if any handler is registered to process this URI request: URL is "schemeAB:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("schemeAB:ThisIsURL");
    ASSERT(retVal == MMI_FALSE);

    /* TC-URIAgent-C102: Check if any handler is registered to process this URI request: URL is "schemeBB:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("schemeBB:ThisIsURL");
    ASSERT(retVal == MMI_FALSE);

    /* TC-URIAgent-C103: Check if any handler is registered to process this URI request: URL is "unsupportedscheme:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("unsupportedscheme:ThisIsURL");
    ASSERT(retVal == MMI_FALSE);

    /* TC-URIAgent-C104: Check if any handler is registered to process this URI request: URL is "schemeThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("schemeThisIsURL");
    ASSERT(retVal == MMI_FALSE);

    /* TC-URIAgent-C105: Check if any handler is registered to process this URI request: URL is " " */
    retVal = srv_uriagent_has_registered_hdlr(" ");
    ASSERT(retVal == MMI_FALSE);

    /* TC-URIAgent-C106: Check if any handler is registered to process this URI request: URL is NULL */
    retVal = srv_uriagent_has_registered_hdlr(NULL);
    ASSERT(retVal == MMI_FALSE);

    /* TC-URIAgent-C200: Check if any handler is registered to process this URI request: URL is "SCHEME:ThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("SCHEME:ThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C201: Check if any handler is registered to process this URI request: URL is "sChEmE: This Is URL With Space " */
    retVal = srv_uriagent_has_registered_hdlr("sChEmE: This Is URL With Space ");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C202: Check if any handler is registered to process this URI request: URL is "SCHEME:FORMATThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("SCHEME:FORMATThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C203: Check if any handler is registered to process this URI request: URL is "scheme:FORMATAThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("scheme:FORMATAThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C204: Check if any handler is registered to process this URI request: URL is "scheme:formatbThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("scheme:formatbThisIsURL");
    ASSERT(retVal == MMI_TRUE);

    /* TC-URIAgent-C205: Check if any handler is registered to process this URI request: URL is "SCHEME:formatCThisIsURL" */
    retVal = srv_uriagent_has_registered_hdlr("SCHEME:formatCThisIsURL");
    ASSERT(retVal == MMI_TRUE);
	
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_dispatch_uri_request_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_dispatch_uri_request_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* TC-URIAgent-D000: Success to dispatch URI request "scheme:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "scheme:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D001: Success to dispatch URI request "scheme:ThisIsURL" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "scheme:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                smsapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D002: Success to dispatch URI request "schemeA:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "schemeA:ThisIsURL",
                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D003: Success to dispatch URI request "schemeA:ThisIsURL" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "schemeA:ThisIsURL",
                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,
                mmsapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D004: Success to dispatch URI request "schemeB:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "schemeB:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D005: Success to dispatch URI request "schemeB:ThisIsURL" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "schemeB:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                brwapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D006: Success to dispatch URI request "scheme:formatThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "scheme:formatThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D007: Success to dispatch URI request "scheme:formatThisIsURL" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "scheme:formatThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                smsapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D008: Success to dispatch URI request "scheme:formatAThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "scheme:formatAThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D009: Success to dispatch URI request "scheme:formatAThisIsURL" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "scheme:formatAThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                mmsapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D010: Success to dispatch URI request "scheme:formatBThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "scheme:formatBThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D011: Success to dispatch URI request "scheme:formatBThisIsURL" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "scheme:formatBThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                brwapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D012: Success to dispatch URI request "scheme:formatC This Is URL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "scheme:formatC This Is URL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D013: Success to dispatch URI request "scheme:formatC This Is URL" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "scheme:formatC This Is URL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                mmsapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D014: Success to dispatch URI request "scheme::format This Is URL With Double :" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "scheme::format This Is URL With Double :",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D015: Success to dispatch URI request "scheme::format This Is URL With Double :" from URA to UHA (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "scheme::format This Is URL With Double :",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                smsapp_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);

    /* TC-URIAgent-D100: Fail to dispatch URI request because URL is NULL (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_SMS, NULL, SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP, NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-D101: Fail to dispatch URI request beacause URL is NULL (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                NULL,
                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,
                unused_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-D102: Fail to dispatch URI request due to unsupported URL "unsupportedscheme:ThisIsURL" (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "unsupportedscheme:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-D103: Fail to dispatch URI request due to unsupported URL "unsupportedscheme:ThisIsURL" (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "unsupportedscheme:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                unused_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-D104: Fail to dispatch URI request due to unsupported URL " scheme:ThisIsURL" (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_EMAIL,
                " scheme:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-D105: Fail to dispatch URI request due to unsupported URL " scheme:ThisIsURL" (callback is not NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_EMAIL,
                " scheme:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                unused_uri_request_cb);
    ASSERT(err_code == SRV_URIAGENT_ERR_UNSUPPORTED);

    /* TC-URIAgent-D200: Success to dispatch URI request "SCHEME:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "SCHEME:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


    /* TC-URIAgent-D201: Success to dispatch URI request "SCHEMEA:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "SCHEMEA:ThisIsURL",
                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


    /* TC-URIAgent-D202: Success to dispatch URI request "schemeb:ThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "schemeb:ThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


    /* TC-URIAgent-D203: Success to dispatch URI request "SCHEME:FORMATThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "SCHEME:FORMATThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


    /* TC-URIAgent-D204: Success to dispatch URI request "SCHEME:FORMATAThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "SCHEME:FORMATAThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


    /* TC-URIAgent-D205: Success to dispatch URI request "scheme:formatbThisIsURL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                "scheme:formatbThisIsURL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


    /* TC-URIAgent-D206: Success to dispatch URI request "SCHEME:formatC This Is URL" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_MMS,
                "SCHEME:formatC This Is URL",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


    /* TC-URIAgent-D207: Success to dispatch URI request "SCHEME::format This Is URL With Double :" from URA to UHA (callback is NULL) */
    err_code = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_SMS,
                "SCHEME::format This Is URL With Double :",
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                NULL);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);


}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_uriagent_register_hdlr_by_scheme_unit_test();
    srv_uriagent_register_hdlr_by_prefix_unit_test();
    srv_uriagent_has_registered_hdlr_unit_test();
    srv_uriagent_dispatch_uri_request_unit_test();
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_ut_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_ut_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    srv_uriagent_brsplugin_integration_test();
#endif 
}

#endif /* __MMI_URI_AGENT_UT__ */ 

#endif /* __MMI_URI_AGENT__ */ 

