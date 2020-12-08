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

/*
 * brs_plschmhdlr.c
 *
 * Created by Tarkeswar Roy.
 *
 * Dummy Plug-in for dispatching unknown BRS scheme request and 
 * WTAI request from WMLS to BRA.BRA will dispatch the request to
 * URI Agent in  MMI task
 *
 * Revision history:
 *
 */
 
/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_plschmhdlr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Dummy Plug-in for dispatching unknown BRS scheme request and 
 * WTAI request from WMLS to BRA.BRA will dispatch the request to
 * URI Agent in  MMI task
 *
 * Author:
 * -------
 * 
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
 
#include "brs_cfg.h"
#ifdef BRS_CONFIG_PLUGIN
#include "brs_plg.h"
#include "brs_main.h"
#include "brs_if.h"
#include "stk_if.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msf_url.h"
#include "msf_lib.h"
#include "msf_tel.h"
#include "msf_core.h"
#include "msf_chrt.h"
#include "msf_log.h"


#ifdef MSF_CFG_URI_AGENT

/************************************************************
 * Constants
 ************************************************************/
#define BRS_SCHEME_HDLR_MC              0
#define BRS_SCHEME_HDLR_SD              1
#define BRS_SCHEME_HDLR_AP				2

#define BRS_SCHEME_HDLR_MC_URL        "wtai://wp/mc;"
#define BRS_SCHEME_HDLR_SD_URL        "wtai://wp/sd;"
#define BRS_SCHEME_HDLR_AP_URL        "wtai://wp/ap;"
#define BRS_SCHEME_HDLR_SCOLON        ";"
#define BRS_SCHEME_HDLR_FRAGMENT      "#"

/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  int   r;
  char *result_var;
} brs_plschmhdlr_result_t;


/************************************************************
 * Function declarations
 ************************************************************/
#ifdef OBIGO_Q03C_BROWSER
extern void BAMif_sendURIreq (MSF_UINT16 request_id, const char* scheme, const char* param);
#endif

#ifdef MSF_CFG_UCM_SUPPORT

static void
brs_plschmhdlr_func_instantiate (brs_plg_t *pl);

static void
brs_plschmhdlr_func_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plschmhdlr_func_response (brs_plg_t *pl);

#endif /* MSF_CFG_UCM_SUPPORT */

static void
brs_plschmhdlr_uri_instantiate (brs_plg_t *pl);

static void
brs_plschmhdlr_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plschmhdlr_uri_response (brs_plg_t *pl);

static void
brs_plschmhdlr_sig_response (brs_plg_t *pl, int signal, int value);

static void
brs_plschmhdlr_delete (brs_plg_t *pl);


/************************************************************
 * Function definitions
 ************************************************************/

void
brs_plschmhdlr_register (void)
{

#ifdef MSF_CFG_UCM_SUPPORT
  brs_plg_info_t info;

  
  /* Lib index = 512, and func index = 0, means WTAPublic.makeCall.
   * That function takes one parameter. */
  info.run_wmls_func.num_params = 1;
  brs_plg_register (BRS_PLG_TYPE_RUN_WMLS_FUNC,
                    "512/0", &info, brs_plschmhdlr_func_instantiate);

  /* Lib index = 512, and func index = 1, means WTAPublic.sendDTMF.
   * That function takes one parameter. */
  info.run_wmls_func.num_params = 1;
  brs_plg_register (BRS_PLG_TYPE_RUN_WMLS_FUNC,
                    "512/1", &info, brs_plschmhdlr_func_instantiate);

  /* Lib index = 512, and func index = 0, means WTAPublic.addPBEntry.
   * That function takes two parameters. */
  info.run_wmls_func.num_params = 2;
  brs_plg_register (BRS_PLG_TYPE_RUN_WMLS_FUNC,
                    "512/2", &info, brs_plschmhdlr_func_instantiate);

#endif /* MSF_CFG_UCM_SUPPORT */
  /* Also, register to handle the URI-versions: */
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "dummy_uri", NULL, brs_plschmhdlr_uri_instantiate);

}

#ifdef MSF_CFG_UCM_SUPPORT

static void
brs_plschmhdlr_func_instantiate (brs_plg_t *pl)
{
  brs_plschmhdlr_result_t *res;

  pl->pl_request = brs_plschmhdlr_func_request;
  pl->pl_delete = brs_plschmhdlr_delete;
  pl->pl_run = brs_plschmhdlr_func_response;
  pl->pl_sig_response = brs_plschmhdlr_sig_response;

  res = brs_plg_alloc (sizeof (brs_plschmhdlr_result_t));
  res->r = 0;
  res->result_var = NULL;
  pl->pl_data = res;
}

static void
brs_plschmhdlr_func_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  int                 num_params = req->run_wmls_func.num_params;
  brs_plg_wmls_var_t *params = req->run_wmls_func.params;
  char					*tmp = NULL,*tmp1;
  int                 r = 0;
  char *scheme = NULL;

  MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRS, BRS_PLSH_FUN_REQ_URI_AGENT_SUPPORT, "BRS URI SUPPORT: brs_plschmhdlr_func_request\n"));

  switch (req->run_wmls_func.func_index) {
  case BRS_SCHEME_HDLR_MC:
    if ((params == NULL) || (num_params != 1)) {
      r = 1;
    }
	else if  ((params[0].type != BRS_PLG_WMLS_VAR_STRING)) {
      r = 2;
    }
    else {
      tmp = msf_cmmn_strcat (MSF_MODID_BRS, BRS_SCHEME_HDLR_MC_URL, params[0]._u.s_val.s);
    }
    break;

  case BRS_SCHEME_HDLR_SD:
    if ((params == NULL) || (num_params != 1)) {
      r = 1;
    }
    else if  ((params[0].type != BRS_PLG_WMLS_VAR_STRING)) {
      r = 2;
    }
    else {
      tmp = msf_cmmn_strcat (MSF_MODID_BRS, BRS_SCHEME_HDLR_SD_URL, params[0]._u.s_val.s);
    }
    break;

    case BRS_SCHEME_HDLR_AP:
    if ((params == NULL) || (num_params != 2)) {
      r = 1;
    }
    else if  ((params[0].type != BRS_PLG_WMLS_VAR_STRING) ||
              (params[1].type != BRS_PLG_WMLS_VAR_STRING)) {
      r = 2;
    }
    else {
       tmp1 = msf_cmmn_str3cat (MSF_MODID_BRS, BRS_SCHEME_HDLR_AP_URL, params[0]._u.s_val.s, BRS_SCHEME_HDLR_SCOLON);
	   tmp = msf_cmmn_strcat (MSF_MODID_BRS, tmp1, params[1]._u.s_val.s);
	   BRS_MEM_FREE (tmp1);
    }
    break;
  }
#ifdef OBIGO_Q03C_BROWSER
  if( r==0 ){
//	  BRAif_launchUnknownUri (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), (MSF_INT8*)tmp, 1);
      scheme = msf_url_get_scheme (MSF_MODID_BRS, tmp);
      BAMif_sendURIreq((MSF_UINT16) (pl->pl_id), scheme, strchr(tmp, ':') + 1);
      BRS_MEM_FREE (scheme);
  }
#endif
  BRS_MEM_FREE (tmp);
  brs_plg_wmlsvar_array_delete (num_params, params);

  if (r == 1) {
    brs_plg_abort (pl, BRS_ERROR_WMLS_INTERPRETING);
  }
  else if (r == 2) {
    brs_plschmhdlr_result_t *res = pl->pl_data;
    
    res->r = 1;
    brs_plschmhdlr_func_response (pl);
  }
}

/*
 * Deliver the response from the WMLScript function call.
 */
static void
brs_plschmhdlr_func_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  res;
  brs_plg_wmls_var_t      *result;
  brs_plschmhdlr_result_t       *p = pl->pl_data;
  int                      r = 1;

  if (p != NULL)
    r = p->r;

  result = brs_plg_alloc (sizeof (brs_plg_wmls_var_t));

  if (r > 0) {
    result->type = BRS_PLG_WMLS_VAR_INVALID;
  }
  else if (r == 0) {
    result->type = BRS_PLG_WMLS_VAR_STRING;
    result->_u.s_val.charset = MSF_CHARSET_UTF_8;
    result->_u.s_val.s_len = 0;
    result->_u.s_val.s = msf_cmmn_strdup (MSF_MODID_BRS, "");
  }
  else {
    result->type = BRS_PLG_WMLS_VAR_INTEGER;
    result->_u.i_val = r;
  }

  res.run_wmls_func.status_code = BRS_PLG_STATUS_OK;
  res.run_wmls_func.result = result;
  brs_plg_response (pl, &res);
  brs_plg_done (pl);
}

#endif /* MSF_CFG_UCM_SUPPORT */

static void
brs_plschmhdlr_uri_instantiate (brs_plg_t *pl)
{
  brs_plschmhdlr_result_t *res;

  pl->pl_request = brs_plschmhdlr_uri_request;
  pl->pl_delete = brs_plschmhdlr_delete;
  pl->pl_run = brs_plschmhdlr_uri_response;
  pl->pl_sig_response = brs_plschmhdlr_sig_response;

  res = brs_plg_alloc (sizeof (brs_plschmhdlr_result_t));
  res->r = 0;
  res->result_var = NULL;
  pl->pl_data = res;
}

static void
brs_plschmhdlr_delete (brs_plg_t *pl)
{
  brs_plschmhdlr_result_t *res = pl->pl_data;

  if (res != NULL) {
    brs_plg_free (res->result_var);
    brs_plg_free (res);
  }
}



static void
brs_plschmhdlr_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  brs_plschmhdlr_result_t *res;
  char              *param1 = NULL, *scheme = NULL;
  char              *result_var = NULL;
  char *complete_url = NULL;


  MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRS, BRS_PLSH_URI_REQ_URI_AGENT_SUPPORT, "BRS URI SUPPORT: brs_plschmhdlr_uri_request\n"));
  res = pl->pl_data;
  res->result_var = NULL;
   /* Check the scheme of the url */
  scheme = msf_url_get_scheme (MSF_MODID_BRS, req->request_url.url);
  if (msf_cmmn_strcmp_nc (scheme, "wtai") == 0)
  {
	  param1 = msf_url_get_parameters (MSF_MODID_BRS, req->request_url.url);
	  if (param1 != NULL)
	  {
		  result_var = strchr (/*param1*/req->request_url.url, '!');
		  if (result_var != NULL)
		  {
			*result_var = '\0';
			result_var++;
			res->result_var = msf_url_unescape_string (MSF_MODID_BRS, result_var);
		  }
		  if(strstr(req->request_url.url, "/ap"))
		  {
			char *tmp_url = NULL;
			if((strchr (param1, ';')) == NULL)
			{
				tmp_url = msf_cmmn_strcat (MSF_MODID_BRS, req->request_url.url, ";");
				brs_plg_free (req->request_url.url);
				req->request_url.url = tmp_url;
            }
          }
	  }
  }
/*
  if (req->request_url.fragment != NULL)
  {
		tmp = msf_cmmn_str3cat (MSF_MODID_BRS, req->request_url.url, BRS_SCHEME_HDLR_FRAGMENT, req->request_url.fragment);
		BRAif_launchUnknownUri (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), (MSF_INT8*)tmp, 1);
		BRS_MEM_FREE (tmp);
  }
  else
  {
		BRAif_launchUnknownUri (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), (MSF_INT8*)req->request_url.url, 1);
  }
  */
#ifdef OBIGO_Q03C_BROWSER
  if (req->request_url.fragment)
  {
      complete_url = msf_cmmn_str3cat(MSF_MODID_BRS, req->request_url.url, "#", req->request_url.fragment);
      BAMif_sendURIreq((MSF_UINT16) (pl->pl_id), scheme, strchr(complete_url, ':') + 1);
  }

  else
  {
      BAMif_sendURIreq((MSF_UINT16) (pl->pl_id), scheme, strchr(req->request_url.url, ':') + 1);
  }
#endif


  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plg_free(complete_url);
  brs_plg_free(scheme);
  return;

/* err_return:
  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plg_abort (pl, STK_ERR_INVALID_URL);
*/
}

static void
brs_plschmhdlr_uri_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  ret;
  brs_plschmhdlr_result_t       *res = pl->pl_data;
  char                     buf[20];

  if ((res != NULL) && (res->result_var != NULL))
  {
    if (res->r == 0) {
      buf[0] = '\0';
    }
    else {
      sprintf (buf, "%d", res->r);
    }
    brs_plg_set_wml_variable (pl, res->result_var, buf);
  }

  ret.request_url.headers = NULL;
  ret.request_url.status_code = BRS_PLG_STATUS_NO_NAVIGATION;

  brs_plg_response (pl, &ret);
  brs_plg_done (pl);
}

static void
brs_plschmhdlr_sig_response (brs_plg_t *pl, int signal, int value)
{
  brs_plschmhdlr_result_t *res = pl->pl_data;

  signal = signal;
  res->r = value;
  brs_plg_schedule (pl);
}


#endif /*MSF_CFG_URI_AGENT*/
#endif /* BRS_CONFIG_PLUGIN */
