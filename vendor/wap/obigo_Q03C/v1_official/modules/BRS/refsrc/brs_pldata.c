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
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * brs_pldata.c
 *
 *
 * Revision history:
 *
 */
 
/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_pldata.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/  
#include "brs_cfg.h"
#ifdef BRS_CONFIG_PLUGIN
#include "msf_cmmn.h"
#include "msf_hdr.h"
#include "msf_lib.h"
#include "msf_url.h"

#include "brs_if.h"
#include "brs_plg.h"


/**********************************************************************
 * Defines
 **********************************************************************/

#define BRS_PLDATA_MAX_PARAM  5 

/**********************************************************************
 * Type Definitions
 **********************************************************************/

typedef struct {
  int   pos;
  int   len;
  char *buf;
} brs_pldata_data_t;


/**********************************************************************
 * Function Declarations
 **********************************************************************/

static void
brs_pldata_instantiate (brs_plg_t *pl);

static void
brs_pldata_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_pldata_delete (brs_plg_t *pl);

static void
brs_pldata_write_data (brs_plg_t *pl);


/**********************************************************************
 * Exported Functions
 **********************************************************************/

void
brs_pldata_register (void)
{
  brs_plg_info_t info;

  info.request_url.empty = 0;
  (void) brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "data", &info, brs_pldata_instantiate);
}


/**********************************************************************
 * Local Functions
 **********************************************************************/


static void
brs_pldata_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  brs_plg_response_data_t  res;
  brs_pldata_data_t         *data;
  char                    *url = NULL;
  char                    *tmp;
  const char              *mime_type;
  const char              *charset = NULL;
  char                    *urldata;
  int                      base64 = 0;
  char                    *param_name[BRS_PLDATA_MAX_PARAM];
  char                    *param_value[BRS_PLDATA_MAX_PARAM];
  int                      i, n, len;
  char                     lenbuf[16];

  if (req->request_url.url == NULL) {
    goto error;
  }
  url = msf_url_unescape_string (MSF_MODID_BRS, req->request_url.url);
  if (url == NULL) {
    goto error;
  }
  tmp = strchr (url, ':');
  if (tmp == NULL) {
    goto error;
  }
  tmp = msf_cmmn_skip_blanks (tmp + 1);
  urldata = strchr (tmp, ',');
  if (urldata == NULL) {
    goto error;
  }
  urldata[0] = '\0';

  n = msf_hdr_get_n_parameters_list (MSF_MODID_BRS, tmp, BRS_PLDATA_MAX_PARAM, param_name, param_value);
  n = MIN (n, BRS_PLDATA_MAX_PARAM);

  if ((n == 0) || (param_name[0] == NULL) || (strlen (param_name[0]) == 0) ||
      (tmp[0] == ';')) {
    mime_type = "text/plain";
  }
  else {
    mime_type = param_name[0];
  }

  for (i = 0; i < n; i++) {
    if (param_name[i] != NULL) {
      if (msf_cmmn_strcmp_nc (param_name[i], "charset") == 0) {
        charset = param_value[i];
      }
      else if (msf_cmmn_strcmp_nc (param_name[i], "base64") == 0) {
        base64 = 1;
      }
    }
  }

  data = brs_plg_alloc (sizeof (brs_pldata_data_t));
  data->pos = 0;
  pl->pl_data = data;
  pl->pl_run = brs_pldata_write_data;

  urldata += 1;
  len = strlen (urldata);
  if (base64) {
    int dlen = msf_cmmn_base64_decode_len (urldata, len);

    data->buf = brs_plg_alloc (dlen);
    (void) msf_cmmn_base64_decode (urldata, len, data->buf, &dlen);
    data->len = dlen;
  }
  else {
    data->len = len;
    data->buf = brs_plg_alloc (len);
    memcpy (data->buf, urldata, len);
  }
  sprintf (lenbuf, "%d", data->len);

  len = strlen (mime_type) + strlen (lenbuf) + 34;
  if (charset != NULL) {
    len += strlen (charset) + 9;
  }
  tmp = brs_plg_alloc (len + 1);
  if (charset != NULL) {
    sprintf (tmp, "Content-Type: %s;charset=%s\r\nContent-Length: %s\r\n",
             mime_type, charset, lenbuf);
  }
  else {
    sprintf (tmp, "Content-Type: %s\r\nContent-Length: %s\r\n", mime_type, lenbuf);
  }
  res.request_url.headers = tmp;
  res.request_url.status_code = BRS_PLG_STATUS_OK;
  brs_plg_response (pl, &res);

  brs_pldata_write_data (pl);

  for (i = 0; i < n; i++) {
    brs_plg_free (param_name[i]);
    brs_plg_free (param_value[i]);
  }
  brs_plg_free (req->request_url.headers);
  brs_plg_free (req->request_url.url);
  brs_plg_free (url);
  return;

 error:
  brs_plg_free (req->request_url.headers);
  brs_plg_free (req->request_url.url);
  brs_plg_free (url);
  brs_plg_abort (pl, BRS_ERROR_INVALID_URL);
}

static void
brs_pldata_delete (brs_plg_t *pl)
{
  brs_plg_free (pl->pl_data);
}

static void
brs_pldata_instantiate (brs_plg_t *pl)
{
  pl->pl_request = brs_pldata_request;
  pl->pl_delete = brs_pldata_delete;
  pl->pl_run = NULL;
  pl->pl_sig_response = NULL;
  pl->pl_data = NULL;
}


/**
 * Write data to the plugin sink
 */
static void
brs_pldata_write_data (brs_plg_t *pl)
{
  brs_pldata_data_t *data = (brs_pldata_data_t *)pl->pl_data;

  while (data->pos < data->len) {
    int rem_len = data->len - data->pos;
    int r;

    r = brs_plg_sink_write (pl, (void *)(data->buf + data->pos), rem_len);
    if (r == BRS_PLG_ERROR_DELAYED) {
      return;
    }
    else if (r < 0) {
      brs_plg_abort (pl, BRS_ERROR_INTERNAL);
      return;
    }
    data->pos += r;
  }

  brs_plg_done (pl);
}

#endif /* BRS_CONFIG_PLUGIN */
