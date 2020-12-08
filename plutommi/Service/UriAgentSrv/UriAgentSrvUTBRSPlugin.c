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
 * UriAgentSrvUTBRSPlugin.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements test cases for URI Agent and Browser integration test.
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
#include "kal_trace.h"
#include <string.h>

#ifdef __MMI_URI_AGENT_UT__

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmiapp_uri_request_generic_hdlr
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
void mmiapp_uri_request_generic_hdlr(
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
    kal_prompt_trace(
        MOD_MMI,
        "ura_appid: %d, uha_appid: %d, options: %x, url: %s",
        ura_appid,
        uha_appid,
        options,
        url);

    if (cb)
    {
        cb(ura_appid, uha_appid, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  sms_scheme_hdlr
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
void sms_scheme_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_SMS, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  mms_scheme_hdlr
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
void mms_scheme_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_MMS, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  rtsp_scheme_hdlr
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
void rtsp_scheme_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_STREAMING, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  tel_scheme_hdlr
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
void tel_scheme_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_CALLMANAGER, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  mailto_scheme_hdlr
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
void mailto_scheme_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_EMAIL, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  http_scheme_hdlr
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
void http_scheme_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_BRW, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  wtai_mc_prefix_hdlr
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
void wtai_mc_prefix_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_CALLMANAGER, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  wtai_sd_prefix_hdlr
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
void wtai_sd_prefix_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_CALLMANAGER, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  wtai_ap_prefix_hdlr
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
void wtai_ap_prefix_hdlr(
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
    mmiapp_uri_request_generic_hdlr(ura_appid, SRV_URIAGENT_APPID_PHONEBOOK, url, param, options, cb);
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_browser_integration_test_register_hdlr_by_scheme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_browser_integration_test_register_hdlr_by_scheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = srv_uriagent_register_hdlr_by_scheme("sms", sms_scheme_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_scheme("smsto", sms_scheme_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_scheme("mms", mms_scheme_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_scheme("mmsto", mms_scheme_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_scheme("rtsp", rtsp_scheme_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_scheme("mailto", mailto_scheme_hdlr, MMI_TRUE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_scheme("tel", tel_scheme_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_browser_integration_test_register_hdlr_by_prefix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_browser_integration_test_register_hdlr_by_prefix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = srv_uriagent_register_hdlr_by_prefix("wtai://wp/mc", wtai_mc_prefix_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_prefix("wtai://wp/sd", wtai_sd_prefix_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
    err_code = srv_uriagent_register_hdlr_by_prefix("wtai://wp/ap", wtai_ap_prefix_hdlr, MMI_FALSE);
    ASSERT(err_code == SRV_URIAGENT_ERR_OK);
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_brsplugin_integration_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uriagent_brsplugin_integration_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_uriagent_browser_integration_test_register_hdlr_by_scheme();
    srv_uriagent_browser_integration_test_register_hdlr_by_prefix();
}

#endif /* __MMI_URI_AGENT_UT__ */ 

#endif /* __MMI_URI_AGENT__ */ 

