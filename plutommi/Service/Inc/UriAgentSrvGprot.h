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
 *    UriAgentSrvGprot.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    URI Agent exported enums, structures, functions and constant definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef _URIAGENTGPROT_H
#define _URIAGENTGPROT_H

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMIDataType.h"

#include "kal_general_types.h"

/****************************************************************************** 
 * Constant
 ******************************************************************************/

/* Maximum number of registered schemes */
#define SRV_URIAGENT_MAX_SCHEME_NUM  (30)
/* Maximum number of registered prefixes */
#define SRV_URIAGENT_MAX_PREFIX_NUM  (10)

/****************************************************************************** 
 * ENUM
 ******************************************************************************/

/* This enumeration defines the application id of URA (URI Request Application) and UHA (URI Handle Application). It can be used for the following condition:
    (1)	It can be used to check if any URI request from the same URA is still in processing.
    (2)	It can be used for URA to translate the result value passed from UHA via callback function. */
typedef enum
{
    SRV_URIAGENT_APPID_SMS,             /* APP id of SMS */
    SRV_URIAGENT_APPID_MMS,             /* APP id of MMS */
    SRV_URIAGENT_APPID_BRW,             /* APP id of Browser */
    SRV_URIAGENT_APPID_EMAIL,           /* APP id of Email */
    SRV_URIAGENT_APPID_STREAMING,       /* APP id of Media / Video Player */
    SRV_URIAGENT_APPID_PHONEBOOK,       /* APP id of Phonebook */
    SRV_URIAGENT_APPID_CALLMANAGER,     /* APP id of Call Manager */
    SRV_URIAGENT_APPID_WIDGET,          /* APP id of Widget engine */
    SRV_URIAGENT_APPID_SNS,				/* APP id of SNS (social networking site) */
    SRV_URIAGENT_APPID_MAX              /* Maximum value of APP id */
} srv_uriagent_appid_enum;

/* This enumeration defines the demand for UHA (URI Handle Application) to process this URI request. These options are assigned by URA (URI Request Application) when sending URI request to URI Agent. */
typedef enum
{
    SRV_URIAGENT_OPTION_UNSPECIFIED = 0x00,         /* URA has no suggestion to process this URI request. */
    SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP = 0x01   /* Confirm popup is needed. */
} srv_uriagent_options_enum;

/* This enumeration defines the error code of dispatching URI request or registering URI request handler by scheme or by prefix. */
typedef enum
{
    SRV_URIAGENT_ERR_OK,                    /* Success to process this request. */
    SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED,  /* Fail to process this registration  because handler was already registered for this scheme; this error code is used for URI request handler registration only. */
    SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED,  /* Fail to process this registration  because handler was already registered for this prefix; this error code is used for URI request handler registration only. */
    SRV_URIAGENT_ERR_PROCESSING,            /* Fail to process this URI request because the previous request from the same URA is  still in processing; this error code is used for URI request dispatch only. */
    SRV_URIAGENT_ERR_UNSUPPORTED            /* Fail to process this request. */
} srv_uriagent_err_enum;

/****************************************************************************** 
 * Typedef
 ******************************************************************************/

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_uriagent_uri_request_hdlr_cb
 * DESCRIPTION
 *  This structure defines the function prototype of URI request handler callback.
 *  The function triggering this callback must pass in the correct app id of URA
 *  in "ura_appid" , pass in the correct app id of UHA in "uha_appid" and pass the
 *  result of processing URI request in "result".
 * PARAMETERS
 *  ura_appid:      [IN]    The APP ID of URA.
 *  uha_appid:      [IN]    The APP ID of UHA.
 *  result:         [IN]    The result of processing URI request.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_uriagent_uri_request_hdlr_cb) (srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid,
                                                  S32 result);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_uriagent_uri_request_hdlr_fn
 * DESCRIPTION
 *  This structure defines the function prototype of URI request handler. The function
 *  triggering this URI request handler must pass in the correct "ura_appid", "url",
 *  "param", "options" and the URI request handler callback "cb" if the caller needs
 *  the result of processing this URI request. Please note that URI agent will pass
 *  the whole URL in "url" and will pass the part after ":" in "param".
 *  
 *  If the URI request handler callback "cb" is not NULL, the URI request handler
 *  implementation must be responsible for invoking the URI request handler callback
 *  "cb" with "ura_appid", "uha_appid" and pass the processing result in "result".
 *  
 *  Please note that UHA will be responsible for UI popup for both of normal case and
 *  abnormal case. For example, if UHA detects format error in this URI request, UHA
 *  will display error popup to inform the user. URA can only use the result value
 *  (passed in callback) for non-UI handling.
 * PARAMETERS
 *  ura_appid:      [IN]    The APP ID of URA.
 *  url:            [IN]    The whole URL.
 *  param:          [IN]    The part after ":" in URL.
 *  options:        [IN]    The demand for UHA (URI Handle Application) to process this URI request.
 *  cb:             [IN]    The URI request handler callback.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_uriagent_uri_request_hdlr_fn) (srv_uriagent_appid_enum ura_appid, char *url, char *param,
                                                  srv_uriagent_options_enum options,
                                                  srv_uriagent_uri_request_hdlr_cb cb);

/****************************************************************************** 
 * External Function
 ******************************************************************************/

extern void srv_uriagent_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_register_hdlr_by_scheme
 * DESCRIPTION
 *  This function is responsible for UHA (URI Handle Application) to register its
 *  URI request handler "hdlr" to process the specified scheme "scheme". Below is
 *  the generic syntax of URI scheme.
 *  
 *  scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )
 *  
 *  UHA can use "encodedURL" to decide the URL format passed from URI agent to UHA.
 *  If "encodedURL" is set as MMI_TRUE, it means UHA wants to receive the original
 *  (escape) URL string. If "encodedURL" is set as MMI_FALSE, it means UHA wants to
 *  receive normal (un-escape) URL string and URI agent is responsible for converting
 *  URL string from escape string (ex. "wtai://wp/mc;03%201234567") to normal string
 *  (ex. "wtai://wp/mc;03 1234567").
 *  
 *  All URI handle applications should register their URI request handlers by
 *  scheme (ex. "mailto" scheme) or by prefix (ex. "wtai://wp/mc") during MMI task 
 *  initialization procedure.
 *  
 *  NOTE 1: Before calling scheme registration function, please check if the 
 *  corresponding application id of your UHA is already defined in 
 *  'mmi_uriagent_appid_enum' (which is defined in URIAgentGProt.h). If not, please 
 *  notify URI agent owner to add new application id for your application.
 *  
 *  NOTE 2: Before using scheme registration function, please notify URI agent owner 
 *  because we have MMI_URIAGENT_MAX_SCHEME_NUM limitation. If the total number
 *  of all registered schemes exceeds MMI_URIAGENT_MAX_SCHEME_NUM (defined in
 *  URIAgentGProt.h and is defined as '30' currently), assertion would occur.
 * PARAMETERS
 *  scheme:         [IN]    URI scheme (null terminated string).
 *  hdlr:           [IN]    URI request handler.
 *  encodedURL:     [IN]    To let UHA can decide to receive normal format URL string or encoded URL string; If encodedURL is MMI_TRUE, url and param passed in hdlr (provided by UHA) will be the original format (URL-encoded). If encodedURL is MMI_FALSE, url and param passed in hdlr will be normal format.
 * RETURNS
 *  Status of URI request handler registration.
 * RETURN VALUES
 *  SRV_URIAGENT_ERR_OK:                    URI request handler is registered by scheme successfully.
 *  SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED:  Unable to register URI request handler by scheme because (other) handler had already registered by the same scheme.
 *  SRV_URIAGENT_ERR_UNSUPPORTED:           Unable to register URI request handler due to other reasons, such as invalid scheme, invalid handler, too many registered schemes, etc.
 *****************************************************************************/
extern srv_uriagent_err_enum srv_uriagent_register_hdlr_by_scheme(
                                const char *scheme,
                                srv_uriagent_uri_request_hdlr_fn hdlr,
                                MMI_BOOL encodedURL);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_register_hdlr_by_prefix
 * DESCRIPTION
 *  This function is responsible for UHA to register its URI request handler by URI
 *  prefix. URI prefix is composed of scheme and format where scheme and format are
 *  divided using colon ":". Below is the generic syntax of URI prefix.
 *  
 *  prefix = scheme ": " format
 *  scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )
 *  format =  *CHARACTER
 *  
 *  UHA sets "encodedURL" to decide the URL format passed from URI agent to UHA.
 *  If "encodedURL" is set as MMI_TRUE, it means UHA wants to receive the
 *  original (escape) URL string. If "encodedURL" is set as MMI_FALSE, it means
 *  UHA wants to receive normal (un-escape) URL string and URI agent is responsible
 *  for converting URL string from escape string (ex. "wtai://wp/mc;03%201234567")
 *  to normal string (ex. "wtai://wp/mc;03 1234567").
 *  
 *  All URI handle applications should register their URI request handlers by 
 *  scheme (ex. "mailto" scheme) or by prefix (ex. "wtai://wp/mc") during MMI
 *  task initialization procedure.
 *  
 *  NOTE 1: Before calling prefix registration function, please check if the corresponding
 *  application id of your UHA is already defined in 'mmi_uriagent_appid_enum' (which is
 *  defined in URIAgentGProt.h). If not, please notify URI agent owner to add new 
 *  application id for your application.
 *  
 *  NOTE 2: Before using prefix registration function, please notify URI agent owner
 *  because we have MMI_URIAGENT_MAX_PREFIX_NUM limitation. If the total number
 *  of all registered prefixes exceeds MMI_URIAGENT_MAX_PREFIX_NUM (defined in 
 *  URIAgentGProt.h and is defined as '10' currently), assertion would occur.
 * PARAMETERS
 *  prefix:     [IN]    URI prefix (null terminated string).
 *  hdlr:       [IN]    URI request handler function.
 *  encodedURL: [IN]    To let UHA can decide to receive normal format URL string or encoded URL string; If encodedURL is MMI_TRUE, url and param passed in hdlr (provided by UHA) will be the original format (URL-encoded). If encodedURL is MMI_FALSE, url and param passed in hdlr will be normal format.
 * RETURNS
 *  Status of URI request handler registration.
 * RETURN VALUES
 *  SRV_URIAGENT_ERR_OK:                    URI request handler is registered by prefix successfully.
 *  SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED:  Unable to register URI request handler by prefix because (other) handler had already registered by the same prefix.
 *  SRV_URIAGENT_ERR_UNSUPPORTED:           Unable to register URI request handler due to other reasons, such as invalid prefix, invalid handler, too many registered prefixes, etc.
 *****************************************************************************/
extern srv_uriagent_err_enum srv_uriagent_register_hdlr_by_prefix(
                                const char *prefix,
                                srv_uriagent_uri_request_hdlr_fn hdlr,
                                MMI_BOOL encodedURL);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_dispatch_uri_request
 * DESCRIPTION
 *  This function is responsible to dispatch URI request from URA to UHA. URA would
 *  be responsible for passing in the correct "ura_appid", "url" and "options". In
 *  addition, if URA is interested in the result of URI request processing, URA would
 *  provide the URI request callback function "cb" as well. Otherwise, "cb" can be
 *  set as NULL. In general case, URA will provide URI request callback function to
 *  obtain the final result of URI request starting with "wtai://wp/mc", "wtai://wp/sd"
 *  and "wtai://wp/ap". In other case, URA does not care the final result.
 *  
 *  URI agent will always return the error code of dispatching this URI request
 *  before invoking URI request callback "cb".
 *      (1)	If URI agent returns MMI_URIAGENT_ERR_OK, it means this
 *          URI request is passed to the corresponding UHA to handle.
 *      (2)	If URI agent returns MMI_URIAGNET_PROCESSING or
 *          MMI_URIAGENT_UNSUPPORTED, it means this URI request
 *          cannot be passed to UHA because the previous URI request from the
 *          same URA is still in processing, or there is no URI request handler
 *          can be used to process this URI.
 *  
 *  URI agent will trigger URI request callback "cb" (assigned by URA) and pass in
 *  the correct application id "ura_appid" and the result of processing this URI
 *  request in "result" only if "cb" is not NULL and after returning error code
 *  MMI_URIAGENT_ERR_OK. That is, URA should be responsible for
 *  checking the return value from URI agent and does error handling if the return
 *  value is not MMI_URIAGENT_ERR_OK, such as displays error popup.
 *  
 *  NOTE: Before calling this URI request dispatch function, please check if the
 *  corresponding application id of your application is already defined in 
 *  'mmi_uriagent_appid_enum' (which is defined in URIAgentGProt.h). If not,
 *  please notify URI agent owner to add new application id for your application.
 * PARAMETERS
 *  ura_appid:      [IN]    Application id of URA.
 *  url:            [IN]    The whole URL; UTF-8 encoded, null-terminated string.
 *  options:        [IN]    Options to process this URI request.
 *  cb:             [IN]    URI request handler callback.
 * RETURNS
 *  Status of URI request dispatch.
 * RETURN VALUES
 *  SRV_URIAGENT_ERR_OK:            Success to dispatch this URI request to the corresponding UHA.
 *  SRV_URIAGENT_ERR_PROCESSING:    Fail to dispatch this URI request because the previous URI request from the same URA is  still in processing.
 *  SRV_URIAGENT_ERR_UNSUPPORTED:   Fail to dispatch this URI request because no handler is registered to process this kind of URI request.
 *****************************************************************************/
extern srv_uriagent_err_enum srv_uriagent_dispatch_uri_request(
                                srv_uriagent_appid_enum ura_appid,
                                char *url,
                                srv_uriagent_options_enum options,
                                srv_uriagent_uri_request_hdlr_cb cb);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_has_registered_hdlr
 * DESCRIPTION
 *  This function is responsible to check if any URI request handler is registered to process this specified URL or not.
 * PARAMETERS
 *  url:     [IN]    The whole URL (unescape, UTF-8 encoded, null terminated string).
 * RETURNS
 *  Indicate if any URI request handler is registered to process this URL.
 * RETURN VALUES
 *  MMI_TRUE: It has URI request handler to process this URL.
 *  MMI_FALSE: It has no URI request handler to process this URL.
 *****************************************************************************/
extern MMI_BOOL srv_uriagent_has_registered_hdlr(char *url);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_num_of_registered_schemes
 * DESCRIPTION
 *  This function is responsible for retrieving the total number of all registered schemes.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of all registered schemes.
 *****************************************************************************/
extern U8 srv_uriagent_get_num_of_registered_schemes(void);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_registered_scheme_by_index
 * DESCRIPTION
 *  This function is responsible for retrieving the registered scheme by index.
 * PARAMETERS
 *  index:      [IN]    The index of specified scheme.
 * RETURNS
 *  The specified registered scheme.
 *****************************************************************************/
extern const char *srv_uriagent_get_registered_scheme_by_index(U8 index);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_num_of_registered_prefixes
 * DESCRIPTION
 *  This function is responsible for retrieving the total number of all registered prefixes.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of all registered prefixes.
 *****************************************************************************/
extern U8 srv_uriagent_get_num_of_registered_prefixes(void);

/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_get_registered_prefix_by_index
 * DESCRIPTION
 *  This function is responsible for retrieving the registered prefix by index.
 * PARAMETERS
 *  index:      [IN]    The index of specified prefix.
 * RETURNS
 *  The specified registered prefix.
 *****************************************************************************/
extern const char *srv_uriagent_get_registered_prefix_by_index(U8 index);

#endif /* _URIAGENTGPROT_H */ 

