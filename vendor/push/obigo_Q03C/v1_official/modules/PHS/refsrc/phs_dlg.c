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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */


/*******************************************************************************
 *
 * Filename:
 * ---------
 * phs_dlg.c
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "msf_def.h"
#include "msf_int.h"
#include "msf_cmmn.h"
#include "msf_core.h"
#include "msf_lib.h"
#include "msf_wid.h"

#include "phs_if.h"
#include "phs_dlg.h"
#include "phs_main.h"
#include "phs_rc.h"
#include "phs_sia.h"
#include "pmg_if.h"

/************************************************************
 * Global variables
 ************************************************************/
#ifdef PHS_CFG_PUSH_SLIM_SUPPORT
#ifndef PHS_UNREFERENCED_PARAMETER
#define PHS_UNREFERENCED_PARAMETER(P)          \
   { \
     (P) = (P); \
   }
#endif

int phs_screen_handle;

static phs_queued_push_msg_t    *queued_msgs_list = NULL;
static phs_queued_push_msg_t    *last_msg         = NULL;
static phs_queued_response_t    *queued_response_list = NULL;
static int                       phs_msg_waiting_for_connector_response = 0;
static phs_dlg_t *dlg_list_first = NULL;


/**********************************************************************
 * Constants
 **********************************************************************/

/* Number of handles used by different dialog types: */
#ifdef PHS_CFG_PUSH_SIA_SUPPORT
#define PHS_DLG_SIA_CONFIRM_NUM_HANDLES                     6
#endif
#define PHS_DLG_WHITELIST_NO_MATCH_NUM_HANDLES      6

/* Indices into the array of handles */
#define PHS_DLG_DIALOG_HANDLE                     1

#define PHS_DLG_MESSAGE_HANDLE                    2

#define PHS_DLG_OK_STRING_HANDLE                  3
#define PHS_DLG_OK_ACTION_HANDLE                  4
#define PHS_DLG_CANCEL_STRING_HANDLE              5
#define PHS_DLG_CANCEL_ACTION_HANDLE              6

#define PHS_DLG_NO_SCREEN                         0

/**********************************************************************
 * Type definitions
 **********************************************************************/

/**********************************************************************
 * Local functions
 **********************************************************************/

static phs_dlg_t *
phs_dlg_create (phs_dlg_type_t dialog_type, int msg_id);

static void phs_dlg_add_to_queue (phs_queued_push_msg_t *new_msg);

static void phs_dlg_send_ind (void);

static void phs_launch_dialog (int msg_id, char* info, phs_dlg_type_t dlg_type); 
   
static void *phs_disp_start_whitelist_dialog (int msg_id, char* info);  

static MSF_UINT8 phs_dlg_dialog_action (void *dlg_handle, int response);  

static phs_queued_response_t *phs_dlg_find_response(int msg_id);                

static phs_dlg_t *phs_dlg_find(int msg_id);
/**********************************************************************
 * Exported functions
 **********************************************************************/

void
phs_dlg_init (void)
{
  phs_screen_handle = PHS_DLG_NO_SCREEN;
}

void
phs_dlg_terminate (void)
{
  
  if (phs_screen_handle != PHS_DLG_NO_SCREEN)
     phs_screen_handle = PHS_DLG_NO_SCREEN;
/* Free the dialog queue */
  while (dlg_list_first) 
  {
	  phs_dlg_t *tmp_dlg;
      tmp_dlg = dlg_list_first;
      dlg_list_first = dlg_list_first->next;
      PHS_MEM_FREE (tmp_dlg);
  }

}

/*
 * Create a dialog.
 * Returns a pointer to a struct phs_dlg_st, or NULL on error.
 */
phs_dlg_t * phs_dlgCreate (phs_dlg_type_t dialogType, int numStrings, 
                               MSF_UINT32 strings[], char* info, int msg_id)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  	
	phs_dlg_t  *dlg = NULL;
	pmg_dlg_display_req_t *dlgreq = 0;
    int success = TRUE;
	phs_msg_list_t *msg = NULL;
#ifdef PHS_CFG_PUSH_SIA_SUPPORT

	phs_sia_item_t *sia = NULL;
#endif
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
   
	switch (dialogType)
	{ 
		case PHS_DLG_WHITELIST_NO_MATCH:

			msg = (phs_msg_list_t *)info;
			dlg = phs_dlg_create (dialogType, msg_id);
			if (dlg != NULL)
			{
			dlg->dlg_handle = (void*)PMG_DLG_UNKNOWN_ADDR;
	        dlgreq = pmg_lib_new_dlg_display_req();
		    dlgreq->dlgType = PMG_DLG_UNKNOWN_ADDR;
			dlgreq->dlgInfo.msgInfo.msgType = pmg_lib_msg_get_msgType(msg->content_type_int);
			if (msg->fromAddr.type == MSF_SOCKADDR_TYPE_SMS)
			{
				MSF_UINT16 len1 = 0, len2 = 0;
				char *addr1 = NULL, *addr2 = NULL;	           
	            dlgreq->dlgInfo.msgInfo.smscType = PMG_ADDR_PHONE;
		        dlgreq->dlgInfo.msgInfo.fromType = PMG_ADDR_PHONE;
			    pmg_lib_msg_log_address((const char*)(msg->fromAddr.addr), msg->fromAddr.addrLen);
				success = pmg_lib_extract_address (&msg->fromAddr, &addr1, &len1, &addr2, &len2);
	            if (!success)
		        {
			        break;
				}
	            dlgreq->dlgInfo.msgInfo.from = pmg_lib_cvt_addr(addr1, len1, PMG_ADDR_PHONE, 1);
		        dlgreq->dlgInfo.msgInfo.smsc = pmg_lib_cvt_addr(addr2, len2, PMG_ADDR_PHONE, 1);
			} 
	        else if (msg->fromAddr.type == MSF_SOCKADDR_TYPE_IPV4) 
		    {
			    dlgreq->dlgInfo.msgInfo.smscType = PMG_ADDR_NULL;
				dlgreq->dlgInfo.msgInfo.fromType = PMG_ADDR_IP;
	            dlgreq->dlgInfo.msgInfo.from = pmg_lib_cvt_addr((const char *)msg->fromAddr.addr,
														msg->fromAddr.addrLen, PMG_ADDR_IP, 1);
				if (!dlgreq->dlgInfo.msgInfo.from || strlen(dlgreq->dlgInfo.msgInfo.from) == 0)
				{
					success = FALSE;
					break;
				}
			} 
			else 
	        {
		        dlgreq->dlgInfo.msgInfo.smscType = PMG_ADDR_NULL;
			    dlgreq->dlgInfo.msgInfo.fromType = PMG_ADDR_TEXT;
				dlgreq->dlgInfo.msgInfo.from = pmg_lib_cvt_addr((const char *)msg->fromAddr.addr,
					                                  msg->fromAddr.addrLen, PMG_ADDR_TEXT, 1);
				if (!dlgreq->dlgInfo.msgInfo.from || strlen(dlgreq->dlgInfo.msgInfo.from) == 0)
				{
					success = FALSE;
	                break;
		        }
			}
			if (dlgreq->dlgInfo.msgInfo.msgType == PMG_MSGTYPE_SI && msg->parsed_info.text)
			{
				dlgreq->dlgInfo.msgInfo.text = pmg_lib_cvt_text(msg->parsed_info.text);
			}

	        if ((dlgreq->dlgInfo.msgInfo.msgType == PMG_MSGTYPE_SI || 
		        dlgreq->dlgInfo.msgInfo.msgType == PMG_MSGTYPE_SL) && msg->parsed_info.href)
			{
				dlgreq->dlgInfo.msgInfo.href = pmg_lib_cvt_href(msg->parsed_info.href);
			}

			PMGif_displayDialog(dlgreq);
			}
			break;
#ifdef PHS_CFG_PUSH_SIA_SUPPORT
		case PHS_DLG_SIA_CONFIRM:
#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES
			sia = (phs_sia_item_t *)info;
			dlg = phs_dlg_create (dialogType, msg_id);
			if (dlg != NULL)
			{
			dlg->dlg_handle = (void*)PMG_DLG_SIA_CONFIRM;
			dlgreq = pmg_lib_new_dlg_display_req();
			dlgreq->dlgType = PMG_DLG_SIA_CONFIRM;
			dlgreq->dlgInfo.siaInfo.port = sia->serverport;
			pmg_lib_msg_log_address((const char *)sia->address, (MSF_INT16)sia->address_len);
			dlgreq->dlgInfo.siaInfo.host = pmg_lib_cvt_addr((const char *)sia->address, (MSF_INT16)sia->address_len, PMG_ADDR_IP, 1);
            if (!dlgreq->dlgInfo.siaInfo.host || strlen(dlgreq->dlgInfo.siaInfo.host) == 0)
			{
				success = FALSE;
			break;
			}
			PMGif_displayDialog(dlgreq);
			}
#endif
			break;
#endif
    }
    return ((dlg != NULL) ? dlg : NULL) ;
}

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
phs_dlgDelete (phs_dlg_t *dlg, int moreDialogs)
{
  if (!moreDialogs) 
  {
       phs_screen_handle = PHS_DLG_NO_SCREEN;
  }
  PHS_MEM_FREE (dlg);
}


/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * 
 */
int
phs_dlgGetType (int msg_id)
{
	phs_queued_response_t    *tmp_rsp_list;
    tmp_rsp_list = phs_dlg_find_response(msg_id);
    if (tmp_rsp_list != NULL)		
    return tmp_rsp_list->dlg_type;
   else
   	  return 0;
}

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered 
 */
int
phs_dlgGetResponse (int msg_id)
{
	phs_queued_response_t    *tmp_rsp_list;
    tmp_rsp_list = phs_dlg_find_response(msg_id);
    if (tmp_rsp_list != NULL)	
    return tmp_rsp_list->response;
    else
	  return 0;	
}


/**********************************************************************
 * Local functions
 **********************************************************************/

static phs_dlg_t *
phs_dlg_create (phs_dlg_type_t dialog_type, int msg_id)
{
   phs_dlg_t *dlg = phs_mem_alloc (sizeof(phs_dlg_t));
	if (dlg != NULL)
	{
    dlg->type       = dialog_type;
    dlg->response   = 0;
    dlg->dlg_handle = NULL;
    dlg->msg_id     = msg_id;
    dlg->next       = NULL;
    return dlg;
}
	else
	{
		return NULL;
	}
}





void phs_dlg_display_dialog(int mod_id, int msg_id, char* info, phs_dlg_type_t dlg_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	phs_queued_push_msg_t *msg;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	msg = phs_mem_alloc (sizeof(phs_queued_push_msg_t));
	if (msg != NULL)
	{
	msg->msg_id       = msg_id;
	msg->mod_id       = mod_id;
	msg->info         = info;
	msg->next_msg     = NULL;
	msg->dlg_type     = dlg_type;

	phs_dlg_add_to_queue (msg);
	if (!phs_msg_waiting_for_connector_response) 
	{
		phs_msg_waiting_for_connector_response = 1;
		phs_dlg_send_ind();
	}

	}
	else
	{
		MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PHS_DIALOG_MEMORY_EMPTY, "PHS: memory full for dialog"));
	}
}

static void phs_dlg_send_ind ()
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
	void *signal_buffer;  
#endif
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	
#ifdef __OBIGO_FRMW2__
	signal_buffer = MSF_SIGNAL_CREATE (PHS_SIG_SHOW_DIALOG, MSF_MODID_PHS,
								MSF_MODID_PHS, 0);
	if (signal_buffer != NULL) 
	{
      MSF_SIGNAL_SEND (signal_buffer);
	} 
#else
MSF_SIGNAL_SEND (MSF_MODID_PHS, MSF_MODID_PHS, PHS_SIG_SHOW_DIALOG, 0);
#endif

}
static void phs_dlg_add_to_queue (phs_queued_push_msg_t *new_msg)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
  if (queued_msgs_list) 
  {
    last_msg->next_msg = new_msg;
    last_msg = new_msg;
  }
  else 
  {
    queued_msgs_list = new_msg;
    last_msg = new_msg;
  }
} 


void phs_dlg_ready_to_launch ()
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	
  if (queued_msgs_list) 
  {
 	phs_queued_response_t *rsp;
    phs_queued_push_msg_t *msg = queued_msgs_list;
/* launch the first entry in queued_msgs_list */
    phs_launch_dialog (msg->msg_id, msg->info, msg->dlg_type);

	rsp = phs_mem_alloc(sizeof(phs_queued_response_t));
    rsp->msg_id = msg->msg_id;
    rsp->mod_id = msg->mod_id;
    rsp->dlg_type = msg->dlg_type;
    rsp->next = queued_response_list;
    queued_response_list = rsp;
    queued_msgs_list = queued_msgs_list->next_msg;
    PHS_MEM_FREE (msg);
    msg = NULL;
	if (queued_msgs_list) 
    {
/* again the same process of signaling PHS_SIG_DISPLAY_DLG */ 
	  phs_dlg_send_ind ();
    }
    else 
    {
      phs_msg_waiting_for_connector_response = 0;
    }
  }
  else
  {
	phs_msg_waiting_for_connector_response = 0;
  }
}

static void phs_launch_dialog (int msg_id, char* info, phs_dlg_type_t dlg_type)
                       
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
  
  switch (dlg_type)
  {
  case PHS_DLG_WHITELIST_NO_MATCH:
	  if (!phs_disp_start_whitelist_dialog(msg_id, info))
	  {
		  MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PHS_DIALOG_MEMORY_EMPTY, "PHS: memory full for dialog"));
		  return;
	  }
	  break;
#ifdef PHS_CFG_PUSH_SIA_SUPPORT
  case PHS_DLG_SIA_CONFIRM:

	if (!phs_disp_start_sia_dialog(msg_id, info))
	{
		MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PHS_DIALOG_MEMORY_EMPTY, "PHS: memory full for dialog"));
		return;
	}
	  
	  break;
#endif
  default:
	  break;
  }
}

#ifdef PHS_CFG_PUSH_SIA_SUPPORT
void *phs_disp_start_sia_dialog (int msg_id, char* info)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  	phs_dlg_t  *new_dialog;
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
 	new_dialog = phs_dlgCreate (PHS_DLG_SIA_CONFIRM, 0, NULL, info, msg_id);
	if (new_dialog != NULL)
	{
/* register the dialog */
		phs_register_dialog (MSF_MODID_PHS, new_dialog);
		return new_dialog->dlg_handle;
	}
	else
	{
		MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PHS_DIALOG_MEMORY_EMPTY, "PHS: memory full for dialog"));
		return NULL;
	}
}
#endif

static void *phs_disp_start_whitelist_dialog (int msg_id, char* info)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  	phs_dlg_t  *new_dialog;
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
 	new_dialog = phs_dlgCreate (PHS_DLG_WHITELIST_NO_MATCH, 0, NULL, info, msg_id);
	if (new_dialog != NULL)
	{
/* register the dialog */
		phs_register_dialog (MSF_MODID_PHS, new_dialog);
		return new_dialog->dlg_handle;
	}
	else
	{
		MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PHS_DIALOG_MEMORY_EMPTY, "PHS: memory full for dialog"));
		return NULL;
	}
}

void
phs_register_dialog (int phs_module, phs_dlg_t *dlg)
{	
    phs_dlg_t *tmp_dlg;
    if (dlg_list_first != NULL){
      tmp_dlg = dlg_list_first;
      while(tmp_dlg->next != NULL) tmp_dlg = tmp_dlg->next;
      tmp_dlg->next = dlg;
    } else
    {
      dlg_list_first = dlg;
    }
}

int phs_deregister_dialog (phs_dlg_t *dlg)
{
  phs_dlg_t *tmp_dlg, *prev;

  for (prev = NULL, tmp_dlg = dlg_list_first; tmp_dlg != NULL;
    prev = tmp_dlg, tmp_dlg = tmp_dlg->next) 
  {
    if (tmp_dlg == dlg) 
    {
      if (prev != NULL)
        prev->next = tmp_dlg->next;
      else
        dlg_list_first = tmp_dlg->next;
      break;
    }
  }
  if (dlg_list_first == NULL)
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }

}
void phs_dlg_response (void* dlg_handle, int res_type)
{
    if (!phs_dlg_dialog_action ((void*)dlg_handle, (MSF_INT32)res_type)) 
    {
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PHS,
                   PHS_DIALOG_ACTION_ERROR, "PHS:DIALOG RESPONSE=%d", (MSF_INT32)res_type)); 

    }
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

static MSF_UINT8 phs_dlg_dialog_action (void *dlg_handle, int response)
{
    phs_dlg_t *tmp_dlg;

    for (tmp_dlg = dlg_list_first; tmp_dlg != NULL; tmp_dlg = tmp_dlg->next) 
    {
        if (tmp_dlg->dlg_handle == dlg_handle) 
        {
            tmp_dlg->response = response;
            phs_dlg_postResponse(tmp_dlg->msg_id,response);
            return TRUE;
        }
    }

    return FALSE;
} /* phs_dlg_dialog_action */

void phs_dlg_postResponse(int msg_id, int response)
{
  phs_queued_response_t    *tmp_rsp_list;
  tmp_rsp_list = phs_dlg_find_response(msg_id);
  if (tmp_rsp_list != NULL)
  {
      tmp_rsp_list->response = response;
      PHS_SIGNAL_SENDTO_P (tmp_rsp_list->mod_id, PHS_SIG_DIALOG_RESPONSE, &(tmp_rsp_list->msg_id));
  }
}

static phs_queued_response_t *phs_dlg_find_response(int msg_id)
{
  phs_queued_response_t    *tmp_rsp_list;
  tmp_rsp_list = queued_response_list;
  while(tmp_rsp_list != NULL && tmp_rsp_list->msg_id != msg_id)
  {
    tmp_rsp_list = tmp_rsp_list->next;
  }
  return tmp_rsp_list;
}

void phs_dlg_delete_response_element(int msg_id)
{  
  phs_queued_response_t *response = queued_response_list;
  phs_queued_response_t *prev = NULL;

  
  while (response && response->msg_id != msg_id)
  {  
    prev = response;
    response = response->next;
  }
  
  
  if (NULL == response)
  {
        
  }
  else if (NULL == prev)
  {  
    
    queued_response_list = response->next;
    PHS_MEM_FREE(response);
    response = NULL;
  }
  else
  {    
    
    prev->next = response->next;
    PHS_MEM_FREE(response);
    response = NULL;
    prev = NULL;
  }
}

void phs_dlg_close_dialog (int msg_id)
{
	phs_dlg_t *dlg;
    int more_dialogs;
    dlg = phs_dlg_find(msg_id);
    more_dialogs = phs_deregister_dialog (dlg); 
    phs_dlgDelete (dlg, more_dialogs);
	phs_dlg_delete_response_element (msg_id);

}

static phs_dlg_t *phs_dlg_find(int msg_id)
{
  phs_dlg_t *tmp_dlg;
  tmp_dlg = dlg_list_first;
  while(tmp_dlg != NULL && tmp_dlg->msg_id != msg_id) 
  {
    tmp_dlg = tmp_dlg->next;
  }
  if (tmp_dlg != NULL && tmp_dlg->msg_id == msg_id)
    return tmp_dlg;
  else
    return NULL;
}

#endif
