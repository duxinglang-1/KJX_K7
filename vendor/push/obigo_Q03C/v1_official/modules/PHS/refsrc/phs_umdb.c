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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   phs_umdb.c
 *
 * Project:
 * --------
 *   MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/* MSF */
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_lib.h"
//#include "msf_ucmi.h"
//#include "msf_ucdg.h"
#include "msf_pipe.h"
#include "msf_log.h"

/* STK */
#include "stk_if.h"


/* PHS */
#include "phs_cfg.h"
#include "phs_sig.h"
#include "phs_msg.h"
#ifdef PHS_CONFIG_MULTIPART
#include "phs_mprt.h"
#endif /* PHS_CONFIG_MULTIPART */
//#include "phs_int.h"
#include "phs_dlg.h"
#include "phs_main.h"
#include "phs_umdb.h"

//#include "umdb_utl.h"
#include "msf_errc.h"

#include "pmg_if.h"
#include "phs_if.h"

#if(MMI_MAX_SIM_NUM >= 2)
#include "cbm_api.h"
#endif /* (MMI_MAX_SIM_NUM >= 2)*/

/**********************************************************************
 * Exported global variables
 **********************************************************************/


/**********************************************************************
 * Internal global variables
 **********************************************************************/
static MSF_UINT8 phs_priority_phs[] = {PHS_PRIO_LOW, PHS_PRIO_MEDIUM, PHS_PRIO_HIGH, PHS_PRIO_NONE, PHS_PRIO_DELETE, PHS_PRIO_CACHE};
static MSF_UINT8 phs_priority_pmg[] = {PMG_MSGPRIO_LOW, PMG_MSGPRIO_MEDIUM, PMG_MSGPRIO_HIGH, PMG_MSGPRIO_NONE, PMG_MSGPRIO_DELETE, PMG_MSGPRIO_CACHE};


/**********************************************************************
 * Forward declarations of local functions:
 **********************************************************************/



static MSF_UINT8
phs_umdb_conv_pmg_phs_priority(MSF_UINT8 priority, int dire)
{
  /* dire: 1 = PMG->PHS,  -1=PMG<-PHS */
  int i;
  int size;

  size = sizeof(phs_priority_phs);
  /* for MAUI_02100925 add log */
  MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PHS,
                   PHS_UMDB_PRIORITY_CONVERSION, "PHS: priority =%d, direction = %d, phs_priority_phs size=%d", (int)priority, (int)dire, (int)size));
  for (i=0; i<size; i++) {
    if (dire>0 && phs_priority_pmg[i]==priority)
      return phs_priority_phs[i];
    if (dire<0 && phs_priority_phs[i]==priority)
      return phs_priority_pmg[i];
  }
  ASSERT(0);
  return 255;
}



/**************************************************************
 *  External functions                                        *
 **************************************************************/

/* return TRUE if handled, FALSE otherwise */
int
phs_umdb_handle_external_signal (MSF_UINT8    srcModule,
                                 MSF_UINT16   signal,
                                 void        *p)
{
  if (srcModule != MSF_MODID_PMG)
    return FALSE;

  switch (signal) {
  case PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY:
    {
      pmg_get_msg_by_attribute_reply_t *pmg_reply_data = (pmg_get_msg_by_attribute_reply_t*)p;
      umdb_oper_reply_get_filtered_t *umdb_reply_data;

      umdb_reply_data = phs_mem_alloc(sizeof(umdb_oper_reply_get_filtered_t));
      memset(umdb_reply_data, 0, sizeof(umdb_oper_reply_get_filtered_t));

      if (pmg_reply_data->result)
        ((pmg_full_msg_t*)(pmg_reply_data->msg))->arrived = 0; // arrived field used as umdb_msg_t object  

      umdb_reply_data->transaction_id = pmg_reply_data->transID;
      umdb_reply_data->to_sub_mod_id = PHS_MODULE_MSG;
      umdb_reply_data->nbr_of_msgs = pmg_reply_data->result;
      umdb_reply_data->msg_list = (umdb_msg_list_handle_t*)(pmg_reply_data->msg);
      umdb_reply_data->nbr_of_errors = 0;
      umdb_reply_data->error_list = 0;
      umdb_reply_data->complete = 1;
      umdb_reply_data->result = UMDB_RESULT_SUCCESS;

      PHS_SIGNAL_SENDTO_P (PHS_MODULE_MSG, PHS_MSG_SIG_PMG_MESSAGE_DATA, (void*)umdb_reply_data);
    }
    return TRUE;

  default:
    return FALSE;
  }
}


/*
 * Returns all messages with a specific attribute.
 * SI: attribute = si-id.
 * SL: attribute = href.
 */
void
phs_umdb_get_msg (MSF_UINT16  transaction_id,
                  char       *attribute,
                  MSF_UINT8   msg_type)
{
/* 
	attribute:
		SI: si-id
		SL: href

	msg_type = {UMDB_MSG_TYPE_PUSH_SI, UMDB_MSG_TYPE_PUSH_SL}

	
	must send message data to PHS_MODULE_MSG via PHS_MSG_SIG_UMDB_MESSAGE_DATA signal
	handled by phs_handle_umdb_message_data(umdb_oper_reply_get_filtered_t *umdb_result)

	umdb_oper_reply_get_filtered_t:
		transaction_id = transaction_id from phs_umdb_get_msg()
		nbr_of_msgs = {0, 1}
		msg_list = handle to msg list (umdb_msg_list_handle_t)
                   PHS calls phs_umdb_get_msg_from_list() to retrieve first message in list
							 each message is type of umdb_msg_t
									key_value_list
									==============
									SL
										* phs_umdb_get_attribute_read (UMDB_MSG_ATTRIBUTE_READ)
										* phs_umdb_get_attribute_sl_priority (PUSH_SL_PLG_ATTRIBUTE_PRIORITY)
									SI
										* phs_umdb_get_attribute_created (UMDB_MSG_ATTRIBUTE_TIMESTAMP)
										

	called by phs_handle_parsed_msg
*/
  if (msg_type == UMDB_MSG_TYPE_PUSH_SI)
    msg_type = PMG_MSGTYPE_SI;
  else if (msg_type == UMDB_MSG_TYPE_PUSH_SL)
    msg_type = PMG_MSGTYPE_SL;

  PMGif_getMsgByAttribute(MSF_MODID_PHS, transaction_id, msg_type, attribute);
}


/*
 * Deletes a message with a specific msg id.
 */
void
phs_umdb_delete_msg (MSF_UINT32 msg_id, MSF_UINT8 is_replace)
{
/*
  Deletes a message with a specific msg id.
	replied signal not processed, therefore assume deletion must succeed
	called by phs_handle_umdb_message_data
*/
  PMGif_deleteMsg (MSF_MODID_PHS, msg_id, is_replace);
}


void
phs_umdb_create_msg (phs_msg_list_t  *msg,
                     MSF_UINT8        msg_type)
{


/*
	replied signal nore processed, assumes message is created succesfully

	umdb_oper_create_msg_t
		transaction_id: umdb filled (not really being used)
		UMDB_MSG_ATTRIBUTE_FROM = phs_msg_list_t.initiator_uri (UTF8)
		UMDB_MSG_ATTRIBUTE_TIMESTAMP = msg->parsed_info.created or system time in GMT (unsigned int)
		UMDB_MSG_ATTRIBUTE_FOLDER = UMDB_MSG_FOLDER_INBOX (unsigned char)
		UMDB_MSG_ATTRIBUTE_READ = FALSE (bool/unsigned char)
		
			SI
		======
		PUSH_SI_PLG_ATTRIBUTE_HREF = msg->parsed_info.href or "" (UTF8)
		PUSH_SI_PLG_ATTRIBUTE_PRIORITY = msg->parsed_info.priority (unsigned char)
		PUSH_SI_PLG_ATTRIBUTE_EXPIRES = msg->parsed_info.expired (unsigned int)
		PUSH_SI_PLG_ATTRIBUTE_SI_ID = msg->parsed_info.si_id or "" (UTF8)
		UMDB_MSG_ATTRIBUTE_SUBJECT = msg->parsed_info.text or "" (UTF8)
		UMDB_MSG_ATTRIBUTE_STATUS_INFO
			msg->parsed_info.nbr_of_info_elements (int)
			msg->parsed_info.info_attrs[i] (UTF8)
			msg->parsed_info.info_contents[i] (UTF8)
		
			SL
		======
		PUSH_SL_PLG_ATTRIBUTE_HREF = msg->parsed_info.href or "" (UTF8)
		PUSH_SL_PLG_ATTRIBUTE_PRIORITY = msg->parsed_info.priority (unsigned char)


	msg->id not used, UMDB creates an unique msg id itself

	called by phs_msg_store_msg_in_umdb
*/
  pmg_full_msg_t *pmgMsg;
  int i;
  char *addr;
  
/* for SMSC */
  int success = 0;
  char *fromaddr1 = NULL;
  char *fromaddr2 = NULL;
  MSF_UINT16    fromaddr1_len = 0;
  MSF_UINT16    fromaddr2_len = 0;

  MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PHS_UMDB_98A157487EDC360AC52CA3DCC5D818DC, "PMG: phs_umdb_create_msg()\n"));

  pmgMsg = pmg_lib_new_msg();
  pmg_lib_msg_set_created (pmgMsg, msg->parsed_info.created);
  pmg_lib_msg_set_read (pmgMsg, 0);
  pmg_lib_msg_set_priority (pmgMsg, phs_umdb_conv_pmg_phs_priority((MSF_UINT8)msg->parsed_info.priority, -1));
  pmg_lib_msg_set_href (pmgMsg, msg->parsed_info.href);

/* for SMSC */
/* set FROM and SMSC address */
  if (msg->fromAddr.type == MSF_SOCKADDR_TYPE_SMS) 
  {
    /* extract addresses */
    pmg_lib_msg_log_address((const char*)(msg->fromAddr.addr), msg->fromAddr.addrLen);

    success = pmg_lib_extract_address (&(msg->fromAddr),&fromaddr1, &fromaddr1_len,&fromaddr2, &fromaddr2_len);
    if (success) 
	{
      /* Originating Address */
     if (fromaddr1_len)
     pmg_lib_msg_set_from (pmgMsg, (const char*)fromaddr1, (MSF_INT16)(fromaddr1_len), PMG_ADDR_PHONE);
      /* SMSC Address */
     if (fromaddr2_len)
     pmg_lib_msg_set_smsc (pmgMsg, (const char*)fromaddr2, (MSF_INT16)(fromaddr2_len), PMG_ADDR_PHONE);
  
	} 
  }  
  else if (msg->fromAddr.type == MSF_SOCKADDR_TYPE_IPV4)
  {
    /* Originating Address */
    pmg_lib_msg_set_from (pmgMsg, (const char*)msg->fromAddr.addr, (MSF_INT16)(msg->fromAddr.addrLen), PMG_ADDR_IP);
    /* SMSC Address */
    pmg_lib_msg_set_smsc (pmgMsg, (const char*)msg->fromAddr.addr, (MSF_INT16)msg->fromAddr.addrLen, PMG_ADDR_IP);

  } 
  else 
  {
    addr = phs_mem_alloc(msg->fromAddr.addrLen + 1);
    memset(addr, 0, msg->fromAddr.addrLen + 1);
    memcpy(addr, msg->fromAddr.addr, msg->fromAddr.addrLen);

    /* Originating Address */
    pmg_lib_msg_set_from (pmgMsg, addr, msg->fromAddr.addrLen, PMG_ADDR_TEXT);
    /* SMSC Address */
    pmg_lib_msg_set_smsc (pmgMsg, addr, msg->fromAddr.addrLen, PMG_ADDR_TEXT);

    PHS_MEM_FREE(addr);
  }
	
	pmg_lib_msg_set_sim_id (pmgMsg, msg->sim_id);


  if (msg_type == UMDB_MSG_TYPE_PUSH_SI) {
    pmg_lib_msg_set_msgType (pmgMsg, PMG_MSGTYPE_SI);
    pmg_lib_msg_set_expired (pmgMsg, msg->parsed_info.expired);
    pmg_lib_msg_set_siid (pmgMsg, msg->parsed_info.si_id);
    pmg_lib_msg_set_text (pmgMsg, msg->parsed_info.text);
    for (i=0; i<msg->parsed_info.nbr_of_info_elements; i++)
      pmg_lib_msg_add_infoitem (pmgMsg, msg->parsed_info.info_attrs[i], msg->parsed_info.info_contents[i]);

  } else if (msg_type == UMDB_MSG_TYPE_PUSH_SL) {
    pmg_lib_msg_set_msgType (pmgMsg, PMG_MSGTYPE_SL);
  }


  PMGif_createMsg(MSF_MODID_PHS, pmgMsg);
}


/*
 * Terminate UMDB Access
 */
/* ARK PMG OLD CODE START */ 
 /*
void
phs_umdb_terminate_umdb_access (void)
{
#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES
  phs_main_umdb_terminated ();
#endif
}
*/
/* ARK PMG OLD CODE START */
/*****************************************************************************
 * Functions to delete reply data from UMDB.
 *****************************************************************************/

void
phs_umdb_free_get_data (void *oper_data)
{
/*
	called by phs_handle_umdb_message_data to free umdb_oper_reply_get_filtered_t
*/
  pmg_full_msg_t *pmgMsg;
  umdb_msg_t *umdbMsg = 0;

  pmgMsg = (pmg_full_msg_t*)(((umdb_oper_reply_get_filtered_t*)oper_data)->msg_list);
  if (pmgMsg) {
    if (pmgMsg->arrived)
      umdbMsg = (umdb_msg_t*)(pmgMsg->arrived);

    if (umdbMsg) {
      PHS_MEM_FREE(umdbMsg);
      pmgMsg->arrived = 0;
    }
    pmg_lib_release_msg(pmgMsg);
  }

  PHS_MEM_FREE((umdb_oper_reply_get_filtered_t*)oper_data);
}

/*****************************************************************************
 * Local functions.
 *****************************************************************************/






/*****************************************************************************
 * Filter list operations.
 *****************************************************************************/


/*****************************************************************************
 * Msg id list operations.
 *****************************************************************************/



/*****************************************************************************
 * Msg list operations.
 *****************************************************************************/


umdb_msg_t*
phs_umdb_get_msg_from_list (umdb_msg_list_handle_t *list_handle)
{
/*
	retrieve first message in list
	called by phs_handle_umdb_message_data
*/
  pmg_full_msg_t *pmgMsg;
  umdb_msg_t *umdbMsg;

  pmgMsg = (pmg_full_msg_t*)list_handle;
  umdbMsg = phs_mem_alloc(sizeof(umdb_msg_t));
  memset(umdbMsg, 0, sizeof(umdb_msg_t));

  umdbMsg->key_value_list = (umdb_attr_key_value_list_handle_t*)pmgMsg;
  umdbMsg->msg_id = (umdb_msg_id_t)(pmgMsg->msgID);
  pmgMsg->arrived = (int)umdbMsg;

  return umdbMsg;
}


/*****************************************************************************
 * Attribute key list operations.
 *****************************************************************************/

MSF_BOOL
phs_umdb_get_attribute_read (umdb_attr_key_value_list_handle_t *key_value_list)
{
/*
	return the value of UMDB_MSG_ATTRIBUTE_READ property in the key_value_list_handle given
	called by phs_handle_umdb_message_data
*/
  pmg_full_msg_t *pmgMsg = (pmg_full_msg_t*)key_value_list;

  return (MSF_BOOL)(pmgMsg->read);
}

MSF_UINT8
phs_umdb_get_attribute_sl_priority (umdb_attr_key_value_list_handle_t *key_value_list)
{
/*
	return the value of PUSH_SL_PLG_ATTRIBUTE_PRIORITY property in the key_value_list_handle given
	called by phs_handle_umdb_message_data
*/
  pmg_full_msg_t *pmgMsg = (pmg_full_msg_t*)key_value_list;

  return phs_umdb_conv_pmg_phs_priority(pmgMsg->priority, 1);
}


MSF_UINT32
phs_umdb_get_attribute_created (umdb_attr_key_value_list_handle_t *key_value_list)
{
/*
	return the value of UMDB_MSG_ATTRIBUTE_TIMESTAMP property in the key_value_list_handle given
	called by phs_handle_umdb_message_data
*/
  pmg_full_msg_t *pmgMsg = (pmg_full_msg_t*)key_value_list;
  return (MSF_UINT32)(pmgMsg->created);
}

/*****************************************************************************
 * 	Called by phs_send_push_to_content_router to forward message to DA
 *****************************************************************************/

void
phs_umdb_content_data_route (MSF_UINT8 src_modId, char* startOptions, 
                         pmg_content_data_t* contentData, int sendAck, MSF_UINT8 id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	pmg_content_send_t   send;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	send.destModId = 0;
	send.sendAck = (MSF_UINT8)(((sendAck >= 0) && (sendAck <= 2)) ? sendAck : 1);
	send.id = id;
	send.startOptions = startOptions;
	if (contentData == NULL) 
	{
		send.contentDataExists = 0;
		send.contentData = NULL;
	}
	else 
	{
		/* if contentData != NULL, msf_content_send_no_drm_no_ext API work*/
		contentData->contentDRMDataExists = 0;
		contentData->contentDRMData = NULL;
		contentData->auxTypeIdentifier = NULL;

		send.contentDataExists = 1;
		send.contentData = contentData;

		if (send.contentData->contentDRMData != NULL)
			contentData->contentDRMDataExists = 1;
		else
			contentData->contentDRMDataExists = 0;
	    if (src_modId != MSF_MODID_PHS)
		{
			contentData->attrLength = 0;
			contentData->attrString = NULL;
        }
	}
	PMGif_contentDataRoute(src_modId, &send);
 }
