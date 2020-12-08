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
 * brs_plab.c
 *
 * Created by Anders Edenbrandt, Fri May 04 16:14:19 2001.
 *
 * Revision history:
 *   010608, AED: Added dynamic version string
 *   021015, AED: Modified for Mobile Suite 2.0
 */
 
/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_plab.c
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
#include "msf_lib.h"
#include "msf_url.h"

#include "brs_if.h"
#include "brs_plg.h"


/************************************************************
 * Type definitions
 ************************************************************/

typedef struct {
  int pos;
  int len;
} brs_plab_data_t;


/************************************************************
 * Global static variables
 ************************************************************/

static char *about_text = NULL;

static char about_brs[] =
  "<?xml version='1.0'?>\n"
  "<html>\n"
  " <head>\n"
  "  <title>About BRS</title>\n"
  " </head>\n"
  " <body>\n"
  "  <p align='center'>\n"
  "   Teleca Mobile Suite - Browser Service<br/>\n"
  "   Copyright 2002, Teleca Mobile Technologies AB<br/>\n"
  "  </p>\n"
  " </body>\n"
  "</html>\n";

static char about_homepage[] =
  "<?xml version='1.0'?>\n"
  "<html>\n"
  "</html>\n";



/************************************************************
 * Function declarations
 ************************************************************/

static void
brs_plab_instantiate (brs_plg_t *pl);

static void
brs_plab_request (brs_plg_t *pl, brs_plg_request_data_t *req);

static void
brs_plab_delete (brs_plg_t *pl);

static void
brs_plab_write_html_page (brs_plg_t *pl);


/************************************************************
 * Function definitions
 ************************************************************/

void
brs_plab_register (void)
{
  brs_plg_info_t info;

  info.request_url.empty = 0;
  brs_plg_register (BRS_PLG_TYPE_REQUEST_URL, "about", &info, brs_plab_instantiate);
}

static void
brs_plab_instantiate (brs_plg_t *pl)
{
  pl->pl_request = brs_plab_request;
  pl->pl_delete = brs_plab_delete;
  pl->pl_run = NULL;
  pl->pl_sig_response = NULL;
  pl->pl_data = NULL;
}

static void
brs_plab_delete (brs_plg_t *pl)
{
  brs_plg_free (pl->pl_data);
}

static void
brs_plab_request (brs_plg_t *pl, brs_plg_request_data_t *req)
{
  brs_plg_response_data_t  res;
  brs_plab_data_t         *data;
  char                    *host, *path;
  int                      err = 0;

  host = msf_url_get_host (MSF_MODID_BRS, req->request_url.url);
  path = msf_url_get_path (MSF_MODID_BRS, req->request_url.url);
  if ((host != NULL) || (path == NULL) || (strcmp (path, "brs") && strcmp (path, "homepage"))) {
    err = 1;
  }
  else
  {
	  if(strcmp (path, "brs") == 0)
	  {
			about_text = about_brs;
	  }
	  else if (strcmp (path, "homepage") == 0)
	  {
			about_text = about_homepage;
	  }
  }

  brs_plg_free (host);
  brs_plg_free (path);
  brs_plg_free (req->request_url.headers);

  if (err) {
    brs_plg_abort (pl, BRS_ERROR_INVALID_URL);
    return;
  }

  /* First the response, where we supply status code and headers. */
  res.request_url.headers = msf_cmmn_strdup (MSF_MODID_BRS,
                                             "Content-Type: text/html\r\n");
  res.request_url.status_code = BRS_PLG_STATUS_OK;
  brs_plg_response (pl, &res);

  data = brs_plg_alloc (sizeof (brs_plab_data_t));
  data->len = strlen (about_text);
  data->pos = 0;
  pl->pl_data = data;
  pl->pl_run = brs_plab_write_html_page;

  brs_plab_write_html_page (pl);
}

static void
brs_plab_write_html_page (brs_plg_t *pl)
{
  brs_plab_data_t *data = (brs_plab_data_t *)pl->pl_data;

  while (data->pos < data->len) {
    int rem_len = data->len - data->pos;
    int r;

    r = brs_plg_sink_write (pl, (void *)(about_text + data->pos), rem_len);
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
