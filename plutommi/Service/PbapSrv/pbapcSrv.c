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
 *  PbapcSrv.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  phonebook access profile
 *
 * Author:
 * -------
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__
#if defined(__BT_PBAP_CLIENT__)


#include "Conversions.h"
#include "BtcmSrvGprot.h"

#include "BTMMIScr.h"
#include "Bluetooth_struct.h"
#include "Bluetooth_bm_struct.h"

#include "PhoneBookPbap.h"
#include "PbapSrvGprot.h"
#include "PbapcSrv.h"

#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_queue_gprot.h"
//#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "kal_public_api.h"
#include "stack_config.h"
//#include "stack_ltlcom.h"
#include "stack_common.h"
#include "kal_general_types.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"
#include "Unicodexdcl.h"
#include "custom_phb_config.h"
#include "PhbSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
//#include "app_buff_alloc.h"
#include "stdio.h"
#include "vCard.h"
#include "app_str.h"
#include "Tst_def.h"

#define PHB_SRV_HD 1 //PhoneBook Service Handle

static void srv_pbapc_enable_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_disable_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_setpath_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_readfolder_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_readentry_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_readlist_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_connect_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_auth_ind_hdlr(void *ilm_ptr);
static void srv_pbapc_disconnect_ind_hdlr(void *ilm_ptr);
static void srv_pbapc_disconnect_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_abort_cnf_hdlr(void *ilm_ptr);
static void srv_pbapc_abort_ind_hdlr(void *ilm_ptr);
void bt_pbap_client_callback_test(bt_pbap_client_event_notify_struct* msg);
static void srv_pbapc_connect_server(srv_bt_cm_bt_addr *addr);
static void srv_pbapc_set_event_hdlr(void);
static void srv_pbapc_send_msg(U32 msg_id, void *p_local_para);
void srv_pbapc_get_path(mmi_pbapc_path_enum path , kal_int8 *name);
void mmi_pbapc_cm_connect_req(srv_bt_cm_bt_addr *addr);
extern U8  mmi_bt_pbap_proc_inject_string(U8 index, kal_uint8 * string);



/*****************************************************************************
* XML Parse Structure
*****************************************************************************/
typedef struct {
	kal_uint8  num_entries;
	kal_uint8  handle[PBAP_XML_PARSE_NUM];
	char name[PBAP_XML_PARSE_NUM][PBAP_MAX_NAME_LEN/2];
}srv_parse_xml_struct;


srv_pbapc_context_struct  srv_pbapc_cntx;
srv_pbapc_context_struct *srv_pbap_c = &srv_pbapc_cntx;

 srv_parse_xml_struct *srv_pbapc_info = NULL;

/*****************************************************************************
* FUNCTION
*  srv_bt_pbap_dialer_dump_trace_info
* DESCRIPTION
* Dumps buffer data into catcher logs.
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
 void srv_bt_pbap_dialer_dump_trace_info(void *buf, int buf_len)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int max_buf_len = 118;
	kal_uint8* buf1 = (kal_uint8*)buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
  if(buf_len > 0)
  {
      while (buf_len > 0)
      {
                kal_buffer_trace(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_PBAP_RECV_BUFFER_TRACE, max_buf_len, (const kal_uint8*)buf1);
                buf_len = buf_len - max_buf_len;
				buf1 = buf1+max_buf_len;
      }
  }
}

/*****************************************************************************
* FUNCTION
*  srv_btpbapc_init
* DESCRIPTION
*  Initialize PCE context structures and sets event handlers.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_btpbapc_init(void) 
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 srv_pbapc_cntx_init();
	 srv_pbapc_set_event_hdlr();
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_cntx_init
* DESCRIPTION
* Initialize PCE context structures.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_cntx_init(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_profile_struct profile_info_p;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAPC_LOG(SRV_PBAP_CLIENT_CNTX_INIT);

	
	memset(&srv_pbap_c->pbapc_cntx, 0, sizeof(srv_pbap_c->pbapc_cntx));
    srv_pbap_c->pbapc_cntx.cm_conn_id = MMI_PBAPC_INVALID_CONN_ID;
    SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_IDLE);	
	srv_pbap_c->pbapc_cntx.goep_conn_id = 0xff;
	srv_pbap_c->pbapc_cntx.set_path = 0;
	srv_pbap_c->pbapc_cntx.phb_srv_hd = 0;
	srv_pbap_c->pbapc_cntx.bt_pbap_callback_func = NULL;

	profile_info_p.profile_id	= SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID;
	profile_info_p.activater	= srv_pbapc_enable_req;
	profile_info_p.deactivater	= srv_pbapc_disable_req;
	profile_info_p.disconnector = srv_pbapc_disconnect_req;
	srv_bt_cm_profile_register((const srv_bt_cm_profile_struct *)&profile_info_p);	
}

/*****************************************************************************
* FUNCTION
*  srv_btpbapc_deinit
* DESCRIPTION
*  Resets PCE Context structures.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_btpbapc_deinit(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	 
	 srv_pbapc_close(srv_pbap_c->pbapc_cntx.phb_srv_hd);

	memset(&srv_pbap_c->pbapc_cntx, 0, sizeof(srv_pbap_c->pbapc_cntx));
    srv_pbap_c->pbapc_cntx.cm_conn_id = MMI_PBAPC_INVALID_CONN_ID;
    SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_IDLE);	
	srv_pbap_c->pbapc_cntx.goep_conn_id = 0xff;
	srv_pbap_c->pbapc_cntx.set_path = 0;
	srv_pbap_c->pbapc_cntx.phb_srv_hd = 0;
	srv_pbap_c->pbapc_cntx.bt_pbap_callback_func = NULL;
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_enable_req
* DESCRIPTION
*  Register the PCE SDP database record 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void srv_pbapc_enable_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAPC_LOG(SRV_PBAP_CLIENT_ENABLE_REQ);
	
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_IDLE){
		srv_pbapc_send_msg(MSG_ID_BT_PBAPC_ENABLE_REQ, NULL);
		}
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_disable_req
* DESCRIPTION
*  Removes  PCE SDP database record .
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void srv_pbapc_disable_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAPC_LOG(SRV_PBAP_CLIENT_DISABLE_REQ);
	
	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_IDLE);
		
	srv_pbapc_send_msg(MSG_ID_BT_PBAPC_DISABLE_REQ, NULL);
}

/*****************************************************************************
* FUNCTION
*  srv_btpbapc_client_open
* DESCRIPTION
*  Provide service handle to PHB Service.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
int srv_btpbapc_client_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_CONNECTED)
	{
		SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);	
		srv_pbap_c->pbapc_cntx.phb_srv_hd = PHB_SRV_HD;
		
		return srv_pbap_c->pbapc_cntx.phb_srv_hd ;
		
	}

	return -1 ;
}


/*****************************************************************************
* FUNCTION
*  srv_btpbapc_client_register_notifier
* DESCRIPTION
*  Register callback for PHB service.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
int srv_btpbapc_client_register_notifier (int srv_hd, bt_pbap_client_callback callback_ptr )
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 /*----------------------------------------------------------------*/ 
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_OPEN)
	{	
		srv_pbap_c->pbapc_cntx.bt_pbap_callback_func = callback_ptr;
		return MMI_TRUE;
	}
	return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  srv_btpbapc_client_close
* DESCRIPTION
*  Close session with PHB service and remove service handle provided earlier.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
int  srv_btpbapc_client_close(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state >= SRV_PBAPC_STATE_OPEN && srv_pbap_c->pbapc_cntx.state <= SRV_PBAPC_STATE_DISCONECTTING)
	{	
    	SRV_PBAPC_LOG(SRV_PBAP_CLIENT_CLOSE);
		srv_pbap_c->pbapc_cntx.phb_srv_hd = -1;
		 if(srv_pbap_c->pbapc_cntx.state != SRV_PBAPC_STATE_DISCONECTTING)
		 	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_CONNECTED);
		return MMI_TRUE;	
	 
	}
	return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  srv_btpbapc_set_path_req
* DESCRIPTION
*  Sets path on remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
int srv_btpbapc_set_path_req(int srv_hd,  pbap_set_folder_type_enum  type ,
								         mmi_pbapc_path_enum enum_path)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_set_path_req_struct *set_path_req;
	kal_int8         name[PBAP_MAX_NAME_LEN/2+1];	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state >= SRV_PBAPC_STATE_OPEN
												&& srv_pbap_c->pbapc_cntx.state < SRV_PBAPC_STATE_DISCONECTTING)
	{	
		name[0] = 0;


		SRV_PBAPC_LOG2(SRV_PBAP_CLIENT_SET_PATH_REQ, type, name);

		if(type == PBAP_FORWARD_FOLDER)
		{		
			if(enum_path > PBAPC_PATH_SIM_TELECOM && enum_path < PBAPC_PATH_PHONEBOOK)
				return MMI_FALSE;

			if(enum_path >= PBAPC_PATH_PHONEBOOK && enum_path <= PBAPC_PATH_PB_TELECOM && !srv_pbap_c->pbapc_cntx.set_path)
			{
				enum_path += PBAPC_PATH_TELECOM;
			}
			else if(enum_path >= PBAPC_PATH_SIM_PHONEBOOK && enum_path <= PBAPC_PATH_SIM_TELECOM && !srv_pbap_c->pbapc_cntx.set_path)
			{
				enum_path += PBAPC_PATH_SIM + PBAPC_PATH_TELECOM;			
			}
			else if(enum_path > PBAPC_PATH_SIM + PBAPC_PATH_TELECOM + PBAPC_PATH_ROOT)
			{
				enum_path -= PBAPC_PATH_SIM;
				srv_pbapc_get_path(PBAPC_PATH_SIM,name);
			}
			else if(enum_path > PBAPC_PATH_TELECOM + PBAPC_PATH_ROOT)
			{
				enum_path -= PBAPC_PATH_TELECOM;
				srv_pbapc_get_path(PBAPC_PATH_TELECOM,name);
			}
			else 
			{
				srv_pbapc_get_path(enum_path,name);
				enum_path = 0;
			}
			srv_pbap_c->pbapc_cntx.set_path = enum_path;
		}
		
		set_path_req = (bt_pbapc_set_path_req_struct*)OslConstructDataPtr(sizeof(bt_pbapc_set_path_req_struct));
		memset(set_path_req->name,0,PBAP_MAX_NAME_LEN/2+1);

		set_path_req->type = type;
		if(name)
		{
			app_asc_str_n_to_ucs2_str((kal_int8 *)set_path_req->name, (kal_int8 *)name, PBAP_MAX_NAME_LEN/4);
		}

		SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_SETTING_PATH);

		srv_pbapc_send_msg(MSG_ID_BT_PBAPC_SET_PATH_REQ,set_path_req);

		return MMI_TRUE;
	}
	return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_path
* DESCRIPTION
*  Get string path for enum path.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void srv_pbapc_get_path(mmi_pbapc_path_enum path , kal_int8 *name)
 {
 	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(path)
	{
		case PBAPC_PATH_SIM:
			app_strlcpy((kal_char*)name,(kal_char*)"SIM1",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_TELECOM:
			app_strlcpy((kal_char*)name,(kal_char*)"telecom",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_PHONEBOOK:
			app_strlcpy((kal_char*)name,(kal_char*)"pb",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_INCOMING:
			app_strlcpy((kal_char*)name,(kal_char*)"ich",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_OUTGOING:
			app_strlcpy((kal_char*)name,(kal_char*)"och",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_MISSED:
			app_strlcpy((kal_char*)name,(kal_char*)"mch",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_COMBINED:
			app_strlcpy((kal_char*)name,(kal_char*)"cch",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_SIM_PHONEBOOK:
			app_strlcpy((kal_char*)name,(kal_char*)"pb",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_SIM_INCOMING:
			app_strlcpy((kal_char*)name,(kal_char*)"ich",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_SIM_OUTGOING:
			app_strlcpy((kal_char*)name,(kal_char*)"och",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_SIM_MISSED:
			app_strlcpy((kal_char*)name,(kal_char*)"mch",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_SIM_COMBINED:
			app_strlcpy((kal_char*)name,(kal_char*)"cch",PBAP_MAX_NAME_LEN/2+1);
			break;
		case PBAPC_PATH_PB_TELECOM:
			app_strlcpy((kal_char*)name,(kal_char*)"cch",PBAP_MAX_NAME_LEN/2+1);  
			break;
		case PBAPC_PATH_SIM_TELECOM:
			app_strlcpy((kal_char*)name,(kal_char*)"cch",PBAP_MAX_NAME_LEN/2+1);  
			break;
		default:
			name = NULL;
	}
}


/*****************************************************************************
* FUNCTION
*  srv_btpbapc_read_folder_req
* DESCRIPTION
*  Sends read folder request on remote device.
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
int srv_btpbapc_read_folder_req(int srv_hd, kal_uint16 folderName [PBAP_MAX_NAME_LEN/2 + 1],
									  PbapVcardFilter filter, PbapVcardFormat format,
 									  kal_uint16 maxListCount, kal_uint16 listStartOffset)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bt_pbapc_read_folder_req_struct *read_folder_req;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state >= SRV_PBAPC_STATE_OPEN
											&& srv_pbap_c->pbapc_cntx.state < SRV_PBAPC_STATE_DISCONECTTING)
	{	
		SRV_PBAPC_LOG3(SRV_PBAP_CLIENT_READ_FOLDER_REQ, format, maxListCount, folderName);
		
		read_folder_req = (bt_pbapc_read_folder_req_struct*)OslConstructDataPtr(sizeof(bt_pbapc_read_folder_req_struct));
		memset(read_folder_req->pbap_data_file, 0,BT_PBAP_MAX_FILEPATH_NAME_LEN);
		memset(read_folder_req->folderName,0,PBAP_MAX_NAME_LEN/2+1);

		app_ucs2_wcsncpy((kal_wchar*)read_folder_req->pbap_data_file, (kal_wchar*)PBAPC_ADP_FOLDER_FILE,BT_PBAP_MAX_FILEPATH_NAME_LEN/2);		
		//if(folderName)
		//	mmi_asc_n_to_wcs((WCHAR *)read_folder_req->folderName, (CHAR *)folderName, PBAP_MAX_NAME_LEN/4);	

		if(folderName)
		app_ucs2_wcsncpy((kal_wchar*)read_folder_req->folderName, (kal_wchar*)folderName,PBAP_MAX_NAME_LEN/4);	

		kal_mem_cpy((kal_uint8*)read_folder_req->filter.byte, (kal_uint8*)filter.byte, PBAP_FILTER_SIZE);
		
		read_folder_req->format = format;
		read_folder_req->maxListCount = maxListCount;
		read_folder_req->listStartOffset = listStartOffset;

		SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_READ_FOLDER);

		srv_pbapc_send_msg(MSG_ID_BT_PBAPC_READ_FOLDER_REQ,read_folder_req);
		
		return TRUE;
	}
	return FALSE;
}

/*****************************************************************************
* FUNCTION
*  srv_btpbapc_read_list_req
* DESCRIPTION
*  Sends read list request on remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
int srv_btpbapc_read_list_req(int srv_hd, kal_uint16 folderName [PBAP_MAX_NAME_LEN/2 + 1] ,									  
									kal_uint8 searchAttribute, kal_uint8 searchValue[MAX_PBAP_SEARCH_VALUE_LENGTH + 1],
									kal_uint8 searchValueLength, kal_uint16 maxListCount, 
									kal_uint16 listStartOffset,kal_uint8 order )
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/			
	bt_pbapc_read_list_req_struct *read_list_req;		
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state >= SRV_PBAPC_STATE_OPEN
											&& srv_pbap_c->pbapc_cntx.state < SRV_PBAPC_STATE_DISCONECTTING)
	{	
		SRV_PBAPC_LOG3(SRV_PBAP_CLIENT_READ_LIST_REQ, searchAttribute, order, folderName);
		
		read_list_req = (bt_pbapc_read_list_req_struct*)OslConstructDataPtr(sizeof(bt_pbapc_read_list_req_struct));
		memset(read_list_req->pbap_data_file,0,BT_PBAP_MAX_FILEPATH_NAME_LEN);
		memset(read_list_req->folderName,0,PBAP_MAX_NAME_LEN/2+1);
		memset(read_list_req->searchValue,0,MAX_PBAP_SEARCH_VALUE_LENGTH + 1);
		
		app_ucs2_wcsncpy((kal_wchar*)read_list_req->pbap_data_file, (kal_wchar*)PBAPC_ADP_LIST_FILE,BT_PBAP_MAX_FILEPATH_NAME_LEN/2);		
		//if(folderName)
		//	app_asc_str_n_to_ucs2_str((kal_int8 *)read_list_req->folderName, (kal_int8 *)folderName, PBAP_MAX_NAME_LEN/4);			
		if(folderName)
		app_ucs2_wcsncpy((kal_wchar*)read_list_req->folderName, (kal_wchar*)folderName,PBAP_MAX_NAME_LEN/4);	
		if(searchValue)
			app_asc_str_n_to_ucs2_str((kal_int8 *)read_list_req->searchValue, (kal_int8 *)searchValue, MAX_PBAP_SEARCH_VALUE_LENGTH/2);		

		read_list_req->searchValueLength = searchValueLength;
		read_list_req->order = order;
		read_list_req->maxListCount = maxListCount;
		read_list_req->listStartOffset = listStartOffset;


		SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_READ_LIST);

		srv_pbapc_send_msg(MSG_ID_BT_PBAPC_READ_LIST_REQ,read_list_req);
		return TRUE;
	}
	return FALSE;			
}


/*****************************************************************************
* FUNCTION
*  srv_btpbapc_read_entry_req
* DESCRIPTION
*  Sends read entry request on remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
int srv_btpbapc_read_entry_req  (int srv_hd, kal_uint16 objName[PBAP_MAX_NAME_LEN/2 + 1],
									  PbapVcardFilter filter, PbapVcardFormat format)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/	
	bt_pbapc_read_entry_req_struct *read_entry_req;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state >= SRV_PBAPC_STATE_OPEN
											&& srv_pbap_c->pbapc_cntx.state < SRV_PBAPC_STATE_DISCONECTTING)
	{	
		SRV_PBAPC_LOG2(SRV_PBAP_CLIENT_READ_ENTRY_REQ, format, objName);

		
		read_entry_req = (bt_pbapc_read_entry_req_struct*)OslConstructDataPtr(sizeof(bt_pbapc_read_entry_req_struct));
		memset(read_entry_req->pbap_data_file,0,BT_PBAP_MAX_FILEPATH_NAME_LEN);		
		memset(read_entry_req->objectName,0,PBAP_MAX_NAME_LEN/2+1);	
				
		app_ucs2_wcsncpy((kal_wchar*)read_entry_req->pbap_data_file, (kal_wchar*)PBAPC_ADP_ENTRY_FILE,BT_PBAP_MAX_FILEPATH_NAME_LEN/2);
		if(objName)   
    		//app_asc_str_n_to_ucs2_str((kal_int8 *)read_entry_req->objectName, (kal_int8 *)objName, PBAP_MAX_NAME_LEN/4);
        app_ucs2_wcsncpy((kal_wchar*)read_entry_req->objectName, (kal_wchar*)objName,PBAP_MAX_NAME_LEN/4);
		kal_mem_cpy((char*)read_entry_req->filter.byte, (char*)filter.byte, PBAP_FILTER_SIZE);
		read_entry_req->format = format;

		SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_READ_ENTRY);


		srv_pbapc_send_msg(MSG_ID_BT_PBAPC_READ_ENTRY_REQ,read_entry_req );

		return MMI_TRUE;
	}
	return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect_req
* DESCRIPTION
*  Sends disconnect request to remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_disconnect_req(U32 conn_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAPC_LOG(SRV_PBAP_CLIENT_DISCONNECT);	
	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_DISCONECTTING);

	srv_pbapc_send_msg(MSG_ID_BT_PBAPC_DISCONNECT_REQ,NULL);
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_abort_req
* DESCRIPTION
*  Sends abort request to remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 void srv_pbapc_abort_req(pbap_set_folder_type_enum folder_type,U16 * name)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAPC_LOG(SRV_PBAP_CLIENT_ABORT_REQ);	

	srv_pbapc_send_msg(MSG_ID_BT_PBAPC_ABORT_REQ,NULL);
}


 /*****************************************************************************
* FUNCTION
*  srv_pbapc_send_msg
* DESCRIPTION
*  Sends message to another module.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_send_msg(U32 msg_id, void *p_local_para)
{
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 //ilm_struct *ilm_send;
 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 /*ilm_send = allocate_ilm(MOD_MMI);
	 ilm_send->src_mod_id = MOD_MMI;
	 ilm_send->dest_mod_id = MOD_BT;
	 ilm_send->sap_id = BT_PBAP_SAP;
	 ilm_send->msg_id = (kal_uint16) msg_id;
	 ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
	 ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;
 
	 msg_send_ext_queue(ilm_send);*/
	 srv_bt_cm_send_msg(MOD_BT, BT_PBAP_SAP, msg_id, (void*)p_local_para, NULL);
 }



 /*****************************************************************************
  * FUNCTION
  *  srv_pbapc_close
  * DESCRIPTION
  *  Disables PCE and removes SDP record.
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void srv_pbapc_close(S32 srv_hd)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state >= SRV_PBAPC_STATE_OPEN && srv_pbap_c->pbapc_cntx.state <= SRV_PBAPC_STATE_DISCONECTTING)
	 {	 	
    SRV_PBAPC_LOG(SRV_PBAP_CLIENT_CLOSE);
		 srv_pbap_c->pbapc_cntx.phb_srv_hd = -1 ;
		 if(srv_pbap_c->pbapc_cntx.state != SRV_PBAPC_STATE_DISCONECTTING)
		 	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_CONNECTED);
	 
	 }
 }

/*****************************************************************************
* FUNCTION
*  srv_btpbapc_disconnect_client
* DESCRIPTION
*  Disconnects from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
int srv_btpbapc_disconnect_client(int srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //bt_pbap_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == srv_pbap_c->pbapc_cntx.phb_srv_hd && srv_pbap_c->pbapc_cntx.state >= SRV_PBAPC_STATE_CONNECTED 
											&& srv_pbap_c->pbapc_cntx.state < SRV_PBAPC_STATE_DISCONECTTING)
	{
		SRV_PBAPC_LOG(SRV_PBAP_CLIENT_DISCONNECT_CLIENT);	 
		srv_pbap_c->pbapc_cntx.cm_conn_id = MMI_PBAPC_INVALID_CONN_ID;
		srv_pbapc_disconnect_req(0);

		return MMI_TRUE;
	}
	return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_send_begin
* DESCRIPTION
*  Sends conncet request to remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 S32 srv_pbapc_send_begin(int sv_hd , srv_bt_cm_bt_addr *addr)
 {
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 conn_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   SRV_PBAPC_LOG(SRV_PBAP_CLIENT_SEND_BEGIN);
   

	conn_id	= srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID, addr, NULL);

	if (conn_id < 0)
        return SRV_PBAPC_SEND_FAIL;

    srv_pbap_c->pbapc_cntx.cm_conn_id = conn_id;
	
    srv_pbap_c->pbapc_cntx.bt_device.uap = addr->uap;
	srv_pbap_c->pbapc_cntx.bt_device.lap = addr->lap;
	srv_pbap_c->pbapc_cntx.bt_device.nap = addr->nap;

	srv_pbapc_connect_server(addr);
	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_CONNECTING1);

	return SRV_PBAPC_STATE_CONNECTING1;
 }

 /*****************************************************************************
* FUNCTION
*  srv_pbapc_connect_server
* DESCRIPTION
*  Concets to remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 static void srv_pbapc_connect_server(srv_bt_cm_bt_addr *addr)
 {
	  /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 bt_pbapc_connect_req_struct *req;
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
   SRV_PBAPC_LOG(SRV_PBAP_CLIENT_CONNECT_SERVER);
	 
	 req = (bt_pbapc_connect_req_struct*)construct_local_para(sizeof(bt_pbapc_connect_req_struct), TD_CTRL);

	 req->bd_addr.lap = addr->lap;
	 req->bd_addr.uap = addr->uap;
	 req->bd_addr.nap = addr->nap;
	 
	 srv_pbapc_send_msg(MSG_ID_BT_PBAPC_CONNECT_REQ, req);
 }


 /*****************************************************************************
 * FUNCTION
 *  srv_pbapc_set_event_hdlr
 * DESCRIPTION
 *  Sets event handler for messages from PBAP ADP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbapc_set_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAPC_LOG(SRV_PBAP_SET_EVENT_HDLR); 

	SetProtocolEventHandler((PsFuncPtr) srv_pbapc_enable_cnf_hdlr, MSG_ID_BT_PBAPC_ENABLE_CNF);

	SetProtocolEventHandler((PsFuncPtr) srv_pbapc_disable_cnf_hdlr, MSG_ID_BT_PBAPC_DISABLE_CNF);
       
    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_setpath_cnf_hdlr, MSG_ID_BT_PBAPC_SET_PATH_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_readfolder_cnf_hdlr, MSG_ID_BT_PBAPC_READ_FOLDER_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_readentry_cnf_hdlr, MSG_ID_BT_PBAPC_READ_ENTRY_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_readlist_cnf_hdlr, MSG_ID_BT_PBAPC_READ_LIST_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_connect_cnf_hdlr, MSG_ID_BT_PBAPC_CONNECT_CNF);

    SetProtocolEventHandler((PsFuncPtr)srv_pbapc_auth_ind_hdlr, MSG_ID_BT_PBAPC_AUTH_CHALLENGE_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_disconnect_ind_hdlr, MSG_ID_BT_PBAPC_DISCONNECT_IND);
	
	SetProtocolEventHandler((PsFuncPtr) srv_pbapc_disconnect_cnf_hdlr, MSG_ID_BT_PBAPC_DISCONNECT_CNF);
	
	 SetProtocolEventHandler((PsFuncPtr) srv_pbapc_abort_cnf_hdlr, MSG_ID_BT_PBAPC_ABORT_CNF);
	
    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_abort_ind_hdlr, MSG_ID_BT_PBAPC_ABORT_IND);
	
	//mmi_frm_set_protocol_event_handler(MSG_ID_TST_INJECT_STRING, (PsIntFuncPtr)mmi_bt_pbap_proc_inject_string, MMI_TRUE);

}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_enable_cnf_hdlr
* DESCRIPTION
*  Handles enable response from Remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 static void srv_pbapc_enable_cnf_hdlr(void *ilm_ptr)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 bt_pbapc_enable_cnf_struct *enable_rsp = (bt_pbapc_enable_cnf_struct*)ilm_ptr;
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_ENABLE);

    SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_ENABLE_CNF, enable_rsp->register_result);	 
	 	
	 srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID);	 
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_disable_cnf_hdlr
* DESCRIPTION
* Handles disable response from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disable_cnf_hdlr(void *ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_disable_cnf_struct *deregister_rsp = (bt_pbapc_disable_cnf_struct*)ilm_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_IDLE);

    SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_DISABLE_CNF, deregister_rsp->deregister_result);	
	
	srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID);	
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_setpath_cnf_hdlr
* DESCRIPTION
*  Hnadles set path response from remote device  nad sends set path request if path still left.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_setpath_cnf_hdlr(void *ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_set_path_cnf_struct *setpath_rsp = (bt_pbapc_set_path_cnf_struct*)ilm_ptr;
	bt_pbap_client_event_notify_struct event_notify;
	bt_pbap_client_set_path_rsp_struct set_path_rsp_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_SETTING_PATH)
	{
		SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_SET_PATH_RSP_CNF, setpath_rsp->cnf_code);			

		if(setpath_rsp->cnf_code == GOEP_STATUS_SUCCESS)
		{
			if(srv_pbap_c->pbapc_cntx.set_path && srv_pbap_c->pbapc_cntx.set_path != PBAPC_PATH_PB_TELECOM && srv_pbap_c->pbapc_cntx.set_path != PBAPC_PATH_SIM_TELECOM)
			{
				srv_btpbapc_set_path_req(srv_pbap_c->pbapc_cntx.phb_srv_hd,PBAP_FORWARD_FOLDER , srv_pbap_c->pbapc_cntx.set_path);
			}		
			else
			{
				SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_PATH_SET);
				srv_pbap_c->pbapc_cntx.set_path = 0;
				set_path_rsp_struct.cnf_code = setpath_rsp->cnf_code;

				event_notify.data = (void*)&set_path_rsp_struct;
				event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
				event_notify.type = EVT_ID_PBAPC_SET_PATH_RSP;

				srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
			}
		}
		else
		{
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);
			set_path_rsp_struct.cnf_code = setpath_rsp->cnf_code;

			event_notify.data = (void*)&set_path_rsp_struct;
			event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
			event_notify.type = EVT_ID_PBAPC_SET_PATH_RSP;

			if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
				srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
		}

	}
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_readfolder_cnf_hdlr
* DESCRIPTION
*  Handles read folder response from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_readfolder_cnf_hdlr(void * ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_read_folder_cnf_struct *read_folder_rsp = (bt_pbapc_read_folder_cnf_struct*)ilm_ptr;
	bt_pbap_client_event_notify_struct event_notify;
	bt_pbap_client_read_folder_rsp_struct read_folder_rsp_struct;

#ifdef PBAPC_BUF_TRACE
	char *buf = NULL;
	unsigned int buf_len = 0;
	int fhandle = -1;
	int result = 0;
	unsigned int filesize = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_READ_FOLDER)
	{
	    read_folder_rsp_struct.cnf_code = read_folder_rsp->cnf_code;
		read_folder_rsp_struct.newMissedCalls = read_folder_rsp->newMissedCalls;
		read_folder_rsp_struct.phoneBookSize = read_folder_rsp->phoneBookSize;

		SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_FOLDER_RSP_CNF, read_folder_rsp->cnf_code);	

		if(read_folder_rsp->cnf_code == GOEP_STATUS_SUCCESS)
		{
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_READ_FOLDER);
#ifdef PBAPC_BUF_TRACE
			 fhandle = FS_Open((WCHAR *)PBAPC_ADP_FOLDER_FILE,FS_READ_ONLY);		 
			 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_FOLDER_RSP_CNF, fhandle);				 
			 if(fhandle>0)
			 {
				 FS_GetFileSize(fhandle , &filesize);
				 buf = (char*)OslMalloc(filesize+1);
				 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_FOLDER_RSP_CNF, filesize);
				 result  = FS_Read(fhandle, (void*)buf, filesize, &buf_len);
				 FS_Close(fhandle);

				 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_FOLDER_RSP_CNF, result);	
			 
			 	if(!result)
			 		srv_bt_pbap_dialer_dump_trace_info(buf,buf_len);
			 }
#endif
		}
		else
		{
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);
		}

		event_notify.data = (void*)&read_folder_rsp_struct;
		event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
		event_notify.type = EVT_ID_PBAPC_READ_FOLDER_RSP;
		if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
			srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
	}
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_readlist_cnf_hdlr
* DESCRIPTION
*  Handles read list response from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_readlist_cnf_hdlr(void * ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_read_list_cnf_struct *read_list_rsp = (bt_pbapc_read_list_cnf_struct*)ilm_ptr;
	bt_pbap_client_read_list_rsp_struct read_list_rsp_struct = {0};
	bt_pbap_client_event_notify_struct event_notify;
	int i= 0 ;
#ifdef PBAPC_BUF_TRACE

	char *buf = NULL;
	unsigned int buf_len = 0;
	int fhandle = -1;
	int result = 0;
	unsigned int filesize = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_READ_LIST)
	{
		read_list_rsp_struct.cnf_code = read_list_rsp->cnf_code;
		read_list_rsp_struct.newMissedCalls = read_list_rsp->newMissedCalls;
		read_list_rsp_struct.phoneBookSize = read_list_rsp->phoneBookSize;

		SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_LIST_RSP_CNF, read_list_rsp->cnf_code);	

		if(read_list_rsp->cnf_code == GOEP_STATUS_SUCCESS)
		{	
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_READ_LIST);
#ifdef PBAPC_BUF_TRACE
			 fhandle = FS_Open((WCHAR *)PBAPC_ADP_LIST_FILE,FS_READ_ONLY);
			 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_LIST_RSP_CNF, fhandle);				 
			 if(fhandle>0)
			 {
				 FS_GetFileSize(fhandle , &filesize);
				 buf = (char*)OslMalloc(filesize+1);
				  SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_LIST_RSP_CNF, filesize);
				 result  = FS_Read(fhandle, (void*)buf, filesize, &buf_len);
				 FS_Close(fhandle);

				 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_LIST_RSP_CNF, result);	
			 	
				if(!result)
				{
			 		srv_bt_pbap_dialer_dump_trace_info(buf,buf_len);
			 	}
			}
#endif

		}		
		else
		{
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);
		}
		
		event_notify.data = (void*)&read_list_rsp_struct;
		event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
		event_notify.type = EVT_ID_PBAPC_READ_LIST_RSP;
		if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
			srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
	}

//	if(read_list_rsp->cnf_code == GOEP_STATUS_SUCCESS)
	//	srv_pbapc_parse_xml_file(PBAPC_ADP_LIST_FILE);
	
		
}

void bt_pbapc_read_data()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	srv_pbapc_parse_xml_file(PBAPC_ADP_LIST_FILE);

}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_readentry_cnf_hdlr
* DESCRIPTION
*  Handles read entry response from remote dvice.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_readentry_cnf_hdlr(void * ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_read_entry_cnf_struct *read_entry_rsp = (bt_pbapc_read_entry_cnf_struct*)ilm_ptr;
	bt_pbap_client_read_entry_struct read_entry_rsp_struct;
	bt_pbap_client_event_notify_struct event_notify;

	char *buf = NULL;
#ifdef PBAPC_BUF_TRACE
	unsigned int buf_len = 0;
	int fhandle = -1;
	int result = 0;
	unsigned int filesize = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_READ_ENTRY)
	{

		SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_ENTRY_CNF, read_entry_rsp->cnf_code);	

		if(read_entry_rsp->cnf_code == GOEP_STATUS_SUCCESS)
		{
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_READ_ENTRY);
#ifdef PBAPC_BUF_TRACE
			 fhandle = FS_Open((WCHAR *)PBAPC_ADP_ENTRY_FILE,FS_READ_ONLY);			 
			 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_ENTRY_CNF, fhandle);				 
			 if(fhandle>0){
				 FS_GetFileSize(fhandle , &filesize);
				 buf = (char*)OslMalloc(filesize+1);
				 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_ENTRY_CNF, filesize);
				 result  = FS_Read(fhandle, (void*)buf, filesize, &buf_len);
				 FS_Close(fhandle);
				 SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_READ_ENTRY_CNF, result);				 	
			 if(!result)
			 	srv_bt_pbap_dialer_dump_trace_info(buf,buf_len);
			}
#endif
		}
		else
		{
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_READ_LIST);
		}
		 
		read_entry_rsp_struct.cnf_code = read_entry_rsp->cnf_code;
		event_notify.data = (void*)&read_entry_rsp_struct;
		event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
		event_notify.type = EVT_ID_PBAPC_READ_ENTRY_RSP;
		if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
			srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
	}
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_connect_cnf_hdlr
* DESCRIPTION
* Handles conncet confirmation from remote device.
* PARAMETERSf
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_connect_cnf_hdlr(void *ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_connect_cnf_struct *connect_rsp = (bt_pbapc_connect_cnf_struct*)ilm_ptr;
    //bt_pbap_client_connect_rsp_struct connect_rsp_struct;
	//bt_pbap_client_event_notify_struct event_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_CONNECTING1 || 
			srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_CONNECTING2)
	{
        SRV_PBAPC_LOG2(SRV_PBAP_CLIENT_CONNECT_CNF, connect_rsp->cnf_code, connect_rsp->cm_conn_id);			

		if(connect_rsp->cnf_code == GOEP_STATUS_SUCCESS)
		{
			srv_bt_cm_connect_ind(srv_pbap_c->pbapc_cntx.cm_conn_id);
			srv_pbap_c->pbapc_cntx.goep_conn_id = connect_rsp->cm_conn_id;
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_CONNECTED);
		}
		else
		{
			srv_bt_cm_stop_conn(srv_pbap_c->pbapc_cntx.cm_conn_id);
			srv_pbap_c->pbapc_cntx.cm_conn_id = MMI_PBAPC_INVALID_CONN_ID;
			SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_IDLE);
		}
		
		//SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	}
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect_cnf_hdlr
* DESCRIPTION
*  Hanldes disconnect confirmation from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disconnect_cnf_hdlr(void * ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_disconnect_cnf_struct *disconnect_rsp = (bt_pbapc_disconnect_cnf_struct*)ilm_ptr;
	bt_pbap_client_disconnect_rsp_struct disconnect_rsp_struct;
	bt_pbap_client_event_notify_struct event_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_DISCONECTTING)
	{
		srv_pbap_c->pbapc_cntx.goep_conn_id = 0xff;

       SRV_PBAPC_LOG1(SRV_PBAP_CLIENT_DISCONNECT_CNF, disconnect_rsp->cnf_code);		
		srv_bt_cm_stop_conn(srv_pbap_c->pbapc_cntx.cm_conn_id);
		
		SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);

	    disconnect_rsp_struct.cnf_code = disconnect_rsp->cnf_code;
		
		event_notify.data = (void*)&disconnect_rsp_struct;
		event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
		event_notify.type = EVT_ID_PBAPC_DISCONNECT_RSP;
		if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
			srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
	}
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect_ind_hdlr
* DESCRIPTION
*  Handles disconnect indication from rote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disconnect_ind_hdlr(void * ilm_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   bt_pbap_client_disconnect_ind_struct disconnect_ind_struct;
	bt_pbap_client_event_notify_struct event_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   SRV_PBAPC_LOG(SRV_PBAP_CLIENT_DISCONNECT_IND);	
	srv_pbap_c->pbapc_cntx.goep_conn_id = 0xff;
	srv_bt_cm_stop_conn(srv_pbap_c->pbapc_cntx.cm_conn_id);
		
	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_IDLE);	

	disconnect_ind_struct.cnf_code = 0;

	event_notify.data = (void*)&disconnect_ind_struct;
	event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
	event_notify.type = EVT_ID_PBAPC_DISCONNECT_IND;
	if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
		srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);

	srv_pbap_c->pbapc_cntx.phb_srv_hd = -1;
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_abort_ind_hdlr
* DESCRIPTION
*  Handles abort indication from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_abort_ind_hdlr(void *ilm_ptr)  
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	bt_pbap_client_event_notify_struct event_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   SRV_PBAPC_LOG(SRV_PBAP_CLIENT_ABORT_IND);
	
	srv_pbap_c->pbapc_cntx.goep_conn_id = 0xff;
	srv_bt_cm_stop_conn(srv_pbap_c->pbapc_cntx.cm_conn_id);
		
	SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);	
	
	event_notify.data = NULL;
	event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
	event_notify.type = EVT_ID_PBAPC_ABORT_IND;
	if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
		srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_abort_cnf_hdlr
* DESCRIPTION
*  Handles abort confirmation from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_abort_cnf_hdlr(void *ilm_ptr)  
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbap_client_event_notify_struct event_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_pbap_c->pbapc_cntx.state == SRV_PBAPC_STATE_DISCONECTTING)
		{
		srv_pbap_c->pbapc_cntx.goep_conn_id = 0xff;
		srv_bt_cm_stop_conn(srv_pbap_c->pbapc_cntx.cm_conn_id);

		SRV_PBAPC_STATE_TRANS(SRV_PBAPC_STATE_OPEN);
		
		event_notify.data = NULL;
		event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
		event_notify.type = EVT_ID_PBAPC_ABORT_RSP;
		if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
			srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);
	}
}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_auth_ind_hdlr
* DESCRIPTION
*  Hanldes authentication indiaction from remote device
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_auth_ind_hdlr(void *ilm_ptr)  
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_pbapc_auth_challenge_ind_struct *auth_ind = (bt_pbapc_auth_challenge_ind_struct*)ilm_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   SRV_PBAPC_LOG(SRV_PBAP_CLIENT_AUTHT_IND);
}


/*****************************************************************************
* FUNCTION
*  mmi_pbapc_cm_connect_req
* DESCRIPTION
*  Makes connection request to Remote device. 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_pbapc_cm_connect_req(srv_bt_cm_bt_addr *addr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//srv_btpbapc_client_open();

	srv_pbap_c->pbapc_cntx.bt_pbap_callback_func = bt_pbap_client_callback_test;
	srv_pbap_c->pbapc_cntx.phb_srv_hd = PHB_SRV_HD;
	
	srv_pbap_c->pbapc_cntx.bt_device.uap = addr->uap;
	srv_pbap_c->pbapc_cntx.bt_device.lap = addr->lap;
	srv_pbap_c->pbapc_cntx.bt_device.nap = addr->nap;


	result = srv_pbapc_send_begin(srv_pbap_c->pbapc_cntx.phb_srv_hd,addr);

	if(result < 0)
	{
		srv_pbapc_close(srv_pbap_c->pbapc_cntx.phb_srv_hd); 
	}
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_parse_xml_file
* DESCRIPTION
*  Parses the XML PBAP list file.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL srv_pbapc_parse_xml_file(kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result = 0;
	bt_pbap_list_data_rsp_struct read_list_data_struct;
	bt_pbap_client_event_notify_struct event_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *xml_parser = NULL;


    xml_parser = (XML_PARSER_STRUCT*) OslMalloc(sizeof(XML_PARSER_STRUCT));
    result = xml_new_parser(xml_parser);
    if (result)
    {
        xml_close_parser(xml_parser);
        OslMfree(xml_parser);
        xml_parser = NULL;
        return MMI_TRUE;
    }

    srv_pbapc_info = (srv_parse_xml_struct*) OslMalloc(sizeof(srv_parse_xml_struct));
	if(!srv_pbapc_info)
		return MMI_FALSE;
	
	kal_mem_set(srv_pbapc_info,0,sizeof(srv_pbapc_info));
	if(!srv_pbapc_info->handle || !srv_pbapc_info->name)
		return MMI_FALSE;
	
	kal_mem_set(&srv_pbapc_info->handle,0,sizeof(srv_pbapc_info->handle));
	kal_mem_set(&srv_pbapc_info->name,0,sizeof(srv_pbapc_info->name));
	srv_pbapc_info->num_entries = -1;

    xml_register_element_handler(xml_parser, srv_pbapc_xml_start_element_hdlr, srv_pbabc_xml_end_element_hdlr);
    xml_register_data_handler(xml_parser, srv_pbapc_xml_data_hdlr);
    result = xml_parse(xml_parser, filename);
    xml_close_parser(xml_parser);

	kal_mem_cpy((char*)read_list_data_struct.handle, (char*)srv_pbapc_info->handle, srv_pbapc_info->num_entries+1);
	kal_mem_cpy((char*)read_list_data_struct.name, (char*)srv_pbapc_info->name, (srv_pbapc_info->num_entries+1)*(PBAP_MAX_NAME_LEN/2));
	read_list_data_struct.num_entries = srv_pbapc_info->num_entries+1;
	read_list_data_struct.more = 0;

	event_notify.data = (void*)&read_list_data_struct;
	event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;
	event_notify.type = EVT_ID_PBAPC_READ_DATA_RSP;

	if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
		srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);

	kal_mem_set(&srv_pbapc_info->handle,0,sizeof(srv_pbapc_info->handle));
	kal_mem_set(&srv_pbapc_info->name,0,sizeof(srv_pbapc_info->name));
	srv_pbapc_info->num_entries = -1;
	OslMfree(srv_pbapc_info);
	read_list_data_struct.more = 0;

    OslMfree(xml_parser);
    xml_parser = NULL;

    if (result == XML_RESULT_OK)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_xml_data_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error)
{

}

/*****************************************************************************
* FUNCTION
*  srv_pbapc_xml_start_element_hdlr
* DESCRIPTION
*  Stores parsed XML each  list element into a global structure one by one and sends response to PHB srv.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(!error){

		if(srv_pbapc_info->num_entries+1 == PBAP_XML_PARSE_NUM)
	{
		bt_pbap_list_data_rsp_struct read_list_data_struct = {0};
	bt_pbap_client_event_notify_struct event_notify;
			kal_mem_cpy((char*)read_list_data_struct.handle, (char*)srv_pbapc_info->handle, PBAP_XML_PARSE_NUM);
			kal_mem_cpy((char*)read_list_data_struct.name, (char*)srv_pbapc_info->name, PBAP_XML_PARSE_NUM*(PBAP_MAX_NAME_LEN/2));
			read_list_data_struct.num_entries = srv_pbapc_info->num_entries;
			read_list_data_struct.more = 1;

			event_notify.data = (void*)&read_list_data_struct;
			event_notify.srvhd = srv_pbap_c->pbapc_cntx.phb_srv_hd ;  
			event_notify.type = EVT_ID_PBAPC_READ_DATA_RSP;

			//srv_pbap_c->pbapc_cntx.bt_pbap_callback_func = bt_pbap_client_callback_test;

			if(srv_pbap_c->pbapc_cntx.bt_pbap_callback_func != NULL)
				srv_pbap_c->pbapc_cntx.bt_pbap_callback_func((void*)&event_notify);

			kal_mem_set(&srv_pbapc_info->handle,0,sizeof(srv_pbapc_info->handle));
			kal_mem_set(&srv_pbapc_info->name,0,sizeof(srv_pbapc_info->name));
			srv_pbapc_info->num_entries = -1;
	}

    if (!strcmp(PBAP_XML_ELEMNT_VCARD, el))
    {
		
		if ((!strcmp(PBAP_XML_ELEMNT_HANDLE, attr[0])) || (!strcmp(PBAP_XML_ELEMNT_HANDLE, attr[0])))
		{
		    srv_pbapc_info->num_entries++;
			
	        if (!strcmp(PBAP_XML_ELEMNT_HANDLE, attr[0]))
	        {
	        	srv_pbapc_info->handle[srv_pbapc_info->num_entries] = atoi(attr[1]);
	        }
			else
				srv_pbapc_info->handle[srv_pbapc_info->num_entries] = -1;
			
			if (!strcmp(PBAP_XML_ELEMNT_NAME, attr[2]))
	        {           
	        	//srv_pbapc_info->name[srv_pbapc_info->num_entries] = (char*)OslMalloc(strlen(attr[3]+1));
	        	//strcpy(srv_pbapc_info->name[srv_pbapc_info->num_entries],attr[3]);
				kal_mem_cpy((char*)srv_pbapc_info->name[srv_pbapc_info->num_entries],attr[3] , (PBAP_MAX_NAME_LEN/2));
			}
    	}
    }	
	}

}

/*****************************************************************************
* FUNCTION
*  srv_pbabc_xml_end_element_hdlr
* DESCRIPTION
*  Displays the details of the selected phonebook entry
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbabc_xml_end_element_hdlr(void *data, const char *el, int error)
{
}


/*****************************************************************************
* FUNCTION
*  mmi_bt_pbap_proc_inject_string
* DESCRIPTION
*  Inject string from catcher.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U8  mmi_bt_pbap_proc_inject_string(U8 index, kal_uint8 * string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    if (strcmp((char*)string, "BTP_path_root") == 0)   
    {
		srv_btpbapc_set_path_req(1,PBAP_ROOT_FOLDER,NULL);
		return 1;														

    }
	if (strcmp((char*)string, "BTP_sim_pb") == 0)  
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_SIM_PHONEBOOK);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_sim_combined") == 0)   
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_SIM_COMBINED);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_incoming") == 0)  
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_INCOMING);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_outgoing") == 0)  
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_OUTGOING);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_combined") == 0)   
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_COMBINED);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_path_pb") == 0)   
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_PHONEBOOK);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_path_sim1") == 0)   
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_SIM_PHONEBOOK);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_path_telecom") == 0)   
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_PB_TELECOM);
		return 1;														
    }
	if (strcmp((char*)string, "BTP_slim_telecom") == 0)   
    {
		srv_btpbapc_set_path_req(1,PBAP_FORWARD_FOLDER,PBAPC_PATH_SIM_TELECOM);
		return 1;														
    }
    else if (strcmp((char*)string, "BTP_read_pb") == 0)   
   	{
				PbapVcardFilter filter;
				PbapVcardFormat format = 0;
				int i =0;
				for(i=0;i<7;i++)
					filter.byte[i] = 0;

					filter.byte[0] = filter.byte[0]^0xFF;

   		 		srv_btpbapc_read_folder_req(1, (kal_uint16*)"telecom/pb.vcf", filter, format,10, 0);
				return 1;								
   	}
	else if (strcmp((char*)string, "BTP_read_ich") == 0)   
   	{
				PbapVcardFilter filter;
				PbapVcardFormat format = 0;
				int i =0;
				for(i=0;i<7;i++)
					filter.byte[i] = 0;

					filter.byte[0] = filter.byte[0]^0xFF;

   		 		srv_btpbapc_read_folder_req(1, (kal_uint16*)"telecom/ich.vcf", filter, format,10, 0);
				return 1;								
   	}
    else if (strcmp((char*)string, "BTP_read_missed") == 0)  
   	{
				PbapVcardFilter filter;
				int i =0;
				for(i=0;i<7;i++)
					filter.byte[i] = 0;

					filter.byte[0] = filter.byte[0]^0xFF;
				
   		 		srv_btpbapc_read_folder_req(1, (kal_uint16*)"telecom/mch.vcf", filter, 0,10, 0);
				return 1;				
    }
	else if (strcmp((char*)string, "BTP_read_outgoing") == 0)  
   	{
				PbapVcardFilter filter;
				int i =0;
				for(i=0;i<7;i++)
					filter.byte[i] = 0;

					filter.byte[0] = filter.byte[0]^0xFF;
				
   		 		srv_btpbapc_read_folder_req(1, (kal_uint16*)"telecom/och.vcf", filter, 0,10, 0);
				return 1;				
    }
	else if (strcmp((char*)string, "BTP_read_combined") == 0)   
   	{
				PbapVcardFilter filter;
				int i =0;
				for(i=0;i<7;i++)
					filter.byte[i] = 0;

					filter.byte[0] = filter.byte[0]^0xFF;
				
   		 		srv_btpbapc_read_folder_req(1, (kal_uint16*)"telecom/cch.vcf", filter, 0,10, 0);
				return 1;				
    }
	else if (strcmp((char*)string, "BTP_read_list_ich") == 0)
	{
		kal_uint8 *searchValue = 0;
		srv_btpbapc_read_list_req(1, (kal_uint16*)"ich",0, searchValue,0, 10, 0,0 );
				return 1;				
    }
	else if (strcmp((char*)string, "BTP_read_list_pb1") == 0)
	{
		kal_uint8 *searchValue = 0;
		srv_btpbapc_read_list_req(1, NULL,0, searchValue,0, 10, 0,0 );
				return 1;				
    }
	else if (strcmp((char*)string, "BTP_read_list_pb") == 0)
	{
		kal_uint8 *searchValue = 0;
		srv_btpbapc_read_list_req(1, (kal_uint16*)"pb" ,0, searchValue,0, 10, 0,0 );
		return 1;
	}
	else if (strcmp((char*)string, "BTP_read_list_mch") == 0)
	{
		kal_uint8 *searchValue = 0;
		srv_btpbapc_read_list_req(1, (kal_uint16*)"mch" ,0, searchValue,0, 10, 0,0 );
		return 1;
	}
	else if (strcmp((char*)string, "BTP_read_1") == 0)
	{
				PbapVcardFilter filter;
				PbapVcardFormat format = 0;
				int i =0;
				for(i=0;i<7;i++)
					filter.byte[i] = 0;

					filter.byte[0] = filter.byte[0]^0xFF;
					
			srv_btpbapc_read_entry_req(1, (kal_uint16*)"1.vcf" ,filter, format);
		
		return 1;
	}
	else if (strcmp((char*)string, "BTP_read_2") == 0)
	{
				PbapVcardFilter filter;
				PbapVcardFormat format = 0;
				int i =0;
				for(i=0;i<7;i++)
					filter.byte[i] = 0;

					filter.byte[0] = filter.byte[0]^0xFF;
					
			srv_btpbapc_read_entry_req(1, (kal_uint16*)"2.vcf" ,filter, format);
		
		return 1;
	}
	return 0;
}

void bt_pbap_client_callback_test(bt_pbap_client_event_notify_struct* msg)
{
	bt_pbap_list_data_rsp_struct *POINTER1 = (bt_pbap_list_data_rsp_struct*)msg->data;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	   #ifdef __MMI_BT_AUTO_POWER_SWITCH__
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
       #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
       #endif
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
#endif

#endif /* __BT_PBAP_CLIENT__ */
#endif /* __srv_MTK_SUPPORT__ */ 
