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
 * brs_plmms.c
 *
 * Created by Derek Chen.
 *
 * Plug-in for MMS functionality.
 *
 * Revision history:
 *
 */

/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_plmms.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Plugin for MMS functionality.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/ 

#include "brs_cfg.h"
#ifdef BRS_CONFIG_PLUGIN
#include "brs_plg.h"
#include "brs_if.h"
#include "stk_if.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msf_url.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_chrt.h"

#ifndef MSF_CFG_URI_AGENT

#ifdef OBIGO_Q03C_MMS_V01
/************************************************************
 * Constants
 ************************************************************/


/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  int   r;
} brs_plmms_result_t;

/************************************************************
 * Function declarations
 ************************************************************/

static void
brs_plmms_uri_instantiate (brs_plg_t *pl);

static void
brs_plmms_delete (brs_plg_t *pl);

static void
brs_plmms_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plmms_uri_response (brs_plg_t *pl);

static void
brs_plmms_sig_response (brs_plg_t *pl, int signal, int value);

static int
brs_plmms_is_phone_number (char *number);

/************************************************************
 * Function definitions
 ************************************************************/

void
brs_plmms_register (void)
{
  /* Register to handle the mms scheme: */
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "mms", NULL, brs_plmms_uri_instantiate);
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "mmsto", NULL, brs_plmms_uri_instantiate);
}

static void
brs_plmms_uri_instantiate (brs_plg_t *pl)
{
  brs_plmms_result_t *res;

  pl->pl_request = brs_plmms_uri_request;
  pl->pl_delete = brs_plmms_delete;
  pl->pl_run = brs_plmms_uri_response;
  pl->pl_sig_response = brs_plmms_sig_response;

  res = brs_plg_alloc (sizeof (brs_plmms_result_t));
  res->r = 0;
  pl->pl_data = res;
}


static void
brs_plmms_delete (brs_plg_t *pl)
{
  brs_plmms_result_t *res = pl->pl_data;

  if (res != NULL) {
    brs_plg_free (res);
  }
}


static void
brs_plmms_uri_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  char              *param1 = NULL;
  char              *tmp;

  /* Get the phone number */
  param1 = msf_url_get_path (MSF_MODID_BRS, req->request_url.url);
  if (param1 == NULL)
    goto err_return;
  tmp = msf_cmmn_skip_blanks(param1);
  msf_cmmn_strcpy_lc (param1, tmp);

  /* Send a SMS to the number */
  tmp = msf_url_unescape_string (MSF_MODID_BRS, param1);
  brs_plg_free (param1);
  param1 = tmp;
  if (!brs_plmms_is_phone_number (param1))
    goto err_return;
  BRAif_mmsSend (MSF_MODID_BRS, (MSF_UINT16)(pl->pl_id), param1);

  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plmms_sig_response(pl, 0, HDI_TEL_ERROR_UNSPECIFIED);
  return;

 err_return:
  brs_plg_free (req->request_url.url);
  brs_plg_free (req->request_url.fragment);
  brs_plg_free (req->request_url.headers);

  brs_plg_free (param1);
  brs_plg_abort (pl, STK_ERR_INVALID_URL);
}

static void
brs_plmms_uri_response (brs_plg_t *pl)
{
  brs_plg_response_data_t  ret;

  ret.request_url.headers = NULL;
  ret.request_url.status_code = BRS_PLG_STATUS_NO_NAVIGATION;

  brs_plg_response (pl, &ret);
  brs_plg_done (pl);
}

static void
brs_plmms_sig_response (brs_plg_t *pl, int signal, int value)
{
  brs_plmms_result_t *res = pl->pl_data;

  signal = signal;
  res->r = value;
  brs_plg_schedule (pl);
}


static int
brs_plmms_is_phone_number (char *number)
{
  char *p = number;

  if (number == NULL)
    return 0;

  if (*p == '+')
    p++;

  if (*p == '\0')
    return 0;

  while (*p != '\0') {
    if (!ct_isdigit (*p))
      return 0;
    p++;
  }

  return 1;
}

#endif /* OBIGO_Q03C_MMS_V01 */

#endif /*MSF_CFG_URI_AGENT*/
#endif /* BRS_CONFIG_PLUGIN */
