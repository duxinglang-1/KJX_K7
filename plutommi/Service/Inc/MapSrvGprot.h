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

/******************************************************************************
 * 
 * Filename
 * ---------
 *  MapSrvGprot.h
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================*/
#ifndef __MAP_SRV_GPROT_H__
#define __MAP_SRV_GPROT_H__
#include "MMI_features.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "BtcmSrvGprot.h"

// testing purpose macro not to be used to check in 
#define MMI_TEST_MAP_CODE  
// dont check in 


#define SRV_BT_MAPC_TYPE_SIZE 80 
#define SRV_BT_MAP_MAX_FOLDER_NAME_LEN 256
#define SRV_BT_MAPC_PATH_NAME_LEN 512
#define SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN 160
#define SRV_BT_MAPC_DEV_NAME_LEN 80 
#define SRV_BT_MAP_MAX_DATE_STR_LEN  20
#define SRV_BT_MAP_MAX_CONTACT_STR_LEN       80
#define SRV_BT_MAPC_FILTER_SIZE  10
#define SRV_BT_MAPC_MAX_LIST_COUNT 1024
#define SRV_BT_MAPC_FOLDER_LISTING_SIZE  1024
#define SRV_BT_MAP_MAX_HANDLE_STR_LEN 64

#define SRV_BT_MAPC_PARAMETER_MSGLISTING_NO_FILTER  			0X0000
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_SUBJECT  				0X0001
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_DATETIME  				0X0002
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_SENDER_NAME 			0X0004
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_SENDER_ADDRESSING 	   	0X0008
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_RECEPIENT_NAME     	0X0010
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_RECEPIENT_ADDRESSING 	0X0020
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_TYPE				 	0X0040
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_SIZE				 	0X0080
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_RECEPTION_STATUS	 	0X0100
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_TEXT				 	0X0200
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_ATTACHMENT_SIZE	 	0X0400
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_PRIORITY			 	0X0800
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_READ				 	0X1000
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_SENT				 	0X2000
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_PROTECTED			 	0X4000
#define	SRV_BT_MAPC_PARAMETER_MSGLISTING_REPLY_TOADDRESSING	 	0X8000




#define SRV_BT_MAPC_FILTER_MSG_TYPE_NO_FILTER 	0X00
#define	SRV_BT_MAPC_FILTER_MSG_TYPE_SMS_GSM  	0X01
#define SRV_BT_MAPC_FILTER_MSG_TYPE_SMS_CDMA	0X02
#define	SRV_BT_MAPC_FILTER_MSG_TYPE_EMAIL		0X04
#define	SRV_BT_MAPC_FILTER_MSG_TYPE_MMS 		0X08

#define SRV_BT_MAPC_MAX_SUBJECT_LENGTH 					0XFF
#define SRV_BT_MAPC_MAX_FOLDER_LISTING_SIZE 			0XFFFF
#define SRV_BT_MAPC_MAX_MSG_LISTING_SIZE 				0XFFFF




typedef enum 
{   SRV_BT_MAPC_SUCCESS=0,
		SRV_BT_MAPC_FAIL,
		SRV_BT_MAPC_FAIL_BUSY, 
		SRV_BT_MAPC_FAIL_NOT_FOUND, 
		SRV_BT_MAPC_FAIL_NOT_SUPPORTED,
		SRV_BT_MAPC_FAIL_FORBIDDEN,
		SRV_BT_MAPC_FAIL_TIMEOUT,
		SRV_BT_MAPC_FAIL_NO_RESOURCE,
		SRV_BT_MAPC_FAIL_UNAUTHORIZED,
		SRV_BT_MAPC_FAIL_BAD_FORMAT,
		SRV_BT_MAPC_FAIL_INVALID_PARAMETER,
		SRV_BT_MAPC_FAIL_STORAGE_FULL
}srv_bt_mapc_result_enum;


typedef enum 
{   SRV_BT_MAPC_OFF=0x00,
		SRV_BT_MAPC_ON=0x01
}srv_bt_mapc_status_enum;



typedef enum 
{   SRV_BT_CHARSET_NATIVE=0x00,
		SRV_BT_CHARSET_UTF8=0x01
}srv_bt_map_charset_enum;

typedef enum 
{   SRV_BT_MAPC_NO_READ_FILTER =0X00,
		SRV_BT_MAPC_UNREAD=0X01,
		SRV_BT_MAPC_READ
}srv_bt_mapc_filter_read_status_enum;


typedef enum 
{   SRV_BT_MAPC_NONE=0X00,
		SRV_BT_MAPC_FOLDERL_LIST_ONLY =0X01,
		SRV_BT_MAPC_MESSAGE_LIST_ONLY=0X02,
		SRV_BT_MAPC_BOTH
}srv_bt_mapc_listing_enum;

typedef enum 
{
    SRV_BT_MAP_MSG_STATUS_READ     = 0x0,
    SRV_BT_MAP_MSG_STATUS_UNREAD   = 0x1,
    SRV_BT_MAP_MSG_STATUS_DELETE   = 0x2,
    SRV_BT_MAP_MSG_STATUS_UNDELETE
} srv_bt_mapc_msg_status_enum;

typedef enum 
{   SRV_BT_MAPC_ROOT =0X00,
		SRV_BT_MAPC_NEXT,
		SRV_BT_MAPC_FORWARD,
		SRV_BT_MAPC_BACK,
		SRV_BT_MAPC_END
}srv_btmapc_folder_flag_enum;

typedef enum 
{   SRV_BT_MAPC_NO_PRIORITY =0X0,
		SRV_BT_MAPC_HIGH_PRIORITY=0X1,
		SRV_BT_MAPC_LOW_PRIORITY=0X2
}srv_bt_mapc_filter_priority_status_enum;


typedef enum 
{		SRV_BT_MAPC_EVT_ID_CONNECT_RSP,
		SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP,
		SRV_BT_MAPC_EVT_ID_FOLDER_LISTING_RSP,       // notifying for success or error 
		SRV_BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP,          // notifying for error or sucess 
 		SRV_BT_MAPC_EVT_ID_SET_MSG_STATUS_RSP,     /* data inside the folders is update please update application accordingly */
		SRV_BT_MAPC_EVT_ID_GET_MSG_RSP, // returning the message body to parsed by sms
		SRV_BT_MAPC_EVT_ID_PUSH_MSG_RSP,
		SRV_BT_MAPC_EVT_ID_UPDATE_INBOX_RSP,
		SRV_BT_MAPC_EVT_ID_MNS_IND,    // Mns indication to the application from server to client
		SRV_BT_MAPC_EVT_ID_ABORT_RSP,
		SRV_BT_MAPC_EVT_ID_DISCONNECT_RSP,
		SRV_BT_MAPC_EVT_ID_DISCONNECT_IND,
		SRV_BT_MAPC_EVT_ID_ERROR,
 		SRV_BT_MAPC_EVT_ID_INVALID
}srv_bt_mapc_cbevent_enum;


/*
2. set_folder  function
BT_MAPC_EVT_SET_FOLDER : for setting the current folder position
*/             //      -->  ---> response success or error code
/*typedef struct
{
  srv_bt_mapc_folder_flag_enum   flags;        // up down or root 
	U8   name[BT_MAPC_FOLDER_NAME_SIZE];         // name of folder to go
}bt_mapc_set_folder;
*/
/*
BT_MAPC_EVT_ID_SET_FOLDER_RSP : to give the reponse code error or sucess 
*/
typedef struct
	{
		srv_bt_mapc_result_enum Error;
		void *user_data;
	}srv_bt_mapc_set_folder_res;	

/*
3. get_folder_listing       

BT_MAPC_EVT_GET_FOLDER_LISTING : inorder to get the folder listing               
     a. request structure
	 just notify to get the folder listing 
*/	 

/*	
	b. responce structure
	BT_MAPC_EVT_ID_FOLDER_LISTING_RSP
*/
	 typedef struct
	{
		srv_bt_mapc_result_enum Error;
		U16 list_size;
		U16 data_size;
		U8  file[SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN+1];        // X-obex /folder listing   
		void *user_data;
	}srv_bt_mapc_get_folder_listing_cnf_struct;
 
	typedef struct
	{
	srv_bt_mapc_result_enum result;
	U16 list_size;
	MMI_BOOL unread;
	U8 datetime[SRV_BT_MAP_MAX_DATE_STR_LEN+1];
	U8 file[SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN+1];
	void *user_data;
	}srv_bt_mapc_message_listing_cnf;

/*
4. get_message_listing_function
BT_MAPC_EVT_GET_MESSAGE_LISTING : Inorder to get message listing 
	a.
	set up following properties for getting message listing 
*/
	 typedef struct
	{
		U16   Maxlistcount;
	  U16	  ListStartOffset;
		U32	  ParameterMask;
		U32	  FilterMessageType;
		srv_bt_mapc_filter_read_status_enum	  FilterReadStatus;
		srv_bt_mapc_filter_priority_status_enum	  FilterPriority;
		U8	  FilterPeriodBegin[SRV_BT_MAP_MAX_DATE_STR_LEN+1];
		U8	  FilterPeriodEnd[SRV_BT_MAP_MAX_DATE_STR_LEN+1];
		U8	  FilterRecipient[SRV_BT_MAPC_FILTER_SIZE];
		U8	  FilterOriginator[SRV_BT_MAPC_FILTER_SIZE];
		U8	  SubjectLength;
	}srv_bt_mapc_set_msg_listing_prop_struct;
	
/*
	b. response 
	BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP
*/
	typedef struct
	{
		srv_bt_mapc_result_enum Error;
		U8  unread;   //on or off
		U8 	datetime[SRV_BT_MAP_MAX_DATE_STR_LEN+1];
		U16 list_size;
		U8  file[SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN + 1];	
		void *user_data;
	}srv_bt_mapc_get_msg_listing_rsp;
	
	
	
/*	
	
5. get_message_function
BT_MAPC_EVT_GET_MESSAGE  
	a. request
*//*	
	typedef struct
	{
		U8   msg_handle[SRV_BT_MAP_MAX_HANDLE_STR_LEN+1];        
		U8  charset;
		U8  attachment;
		U8  fraq_request;
		void*  body;
	}srv_bt_mapc_get_message;
	*/
	
/*
	b. response
	BT_MAPC_EVT_ID_GET_MSG_RSP
*/
	typedef struct
	{	srv_bt_mapc_result_enum Error;
		U16  data_size;
		kal_uint8  file[SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN + 1];
		void *user_data;
	}srv_bt_mapc_message_cnf_struct;   // body of message

/*	
6. set_message_status_function 
	a. request
BT_MAPC_EVT_SET_MESSAGE_STATUS
*/	
	
/*
	B. response;
	BT_MAPC_EVT_ID_SET_MSG_STATUS_RSP
*/
 	typedef struct
	{
	srv_bt_mapc_result_enum Error;
	void *user_data;
	}srv_bt_mapc_set_message_status_rsp;
	
	
		
		
/*	
7. Srv_map_push_message_function
	a. Request
	BT_MAPC_EVT_PUSH_MESSAGE
*/
	 typedef struct
	{
		U8   child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN+1];           //folder name to push
		U8   Retry;
		U8   charset;
		U16  data_size;
		U8   file[SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN + 1];
		void *user_data;
	}srv_bt_mapc_push_message_req_struct;
/*
	b. response
	BT_MAPC_EVT_ID_PUSH_MSG_RSP
*/
	typedef struct
	{
		srv_bt_mapc_result_enum Error;
		U16 Handle[SRV_BT_MAP_MAX_HANDLE_STR_LEN];
		void *user_data;
	}srv_bt_mapc_push_message_status_res;
	
	
	
	
	
/*	
8.  Srv_bt_map_update_inbox
	BT_MAPC_EVT_UPDATE_INBOX
	a. Request
*/
	 
/*
	b. response
BT_MAPC_EVT_UPDATE_INBOX
	
*/
	typedef struct
	{
		srv_bt_mapc_result_enum Error;
		void *user_data;
	}srv_bt_mapc_update_inbox_res;		
		             // check list of error 
		             
/*
9. connect response structure
*/
	typedef struct
	{
		srv_bt_mapc_result_enum Error;
		void *user_data;
	}srv_bt_mapc_connect_rsp;

	typedef struct
	{
		srv_bt_mapc_result_enum Error;
		void *user_data;
	}srv_bt_mapc_disconnect_rsp;				 

/*
10. for MNS Related indication notify sms owner about the updates and get the response from it.
		notified through callback
*/
	typedef struct
	{
		U16 data_size;
		U8   file[SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN + 1];
	}srv_bt_mapc_mns_send_event_ind_struct;
	
	//response 
	typedef struct
{   
		srv_bt_mapc_result_enum result;
	}srv_bt_mapc_mns_send_event_rsp_struct;

	/*
	11 About abort confirmation response
	*/
		typedef struct
	{
		srv_bt_mapc_result_enum Error;
		void *user_data;
	}srv_mapc_abort_cnf;	

typedef void (*srv_bt_mapc_notify_cb)(S32 srv_hd, srv_bt_mapc_cbevent_enum event, void* para);

void srv_bt_mapc_init(void);

void srv_bt_mapc_deinit(void);
// to get a service handle
S32 srv_mapc_open(U32 app_id);
// to close the handle 
S32 srv_mapc_close(U32 srv_hd);
/*application need to register the callback to receive events from the BT MAP cleint service*/
void srv_bt_mapc_register_callback(S32 srv_hd, srv_bt_mapc_notify_cb srv_map_callback);    
/*
Now the following apis should be called according to functionality required .
*/
 
void srv_bt_mapc_connect_req(srv_bt_cm_bt_addr dev_addr);
#ifdef MMI_TEST_MAP_CODE
void srv_bt_mapc_test_code(srv_bt_cm_bt_addr dev_addr);
#endif
/*
its response will be of structure srv_bt_mapc_connect_rsp from the callback 
*/

void srv_bt_mapc_push_message_req(srv_bt_mapc_push_message_req_struct *msg,void *user_data);
/*
and in this structure should be passed of type srv_bt_mapc_push_message_req_struct.
*/
void srv_mapc_disconnect(void *user_data);

U8 srv_mapc_change_folder(U8 *folder,srv_btmapc_folder_flag_enum flag,srv_bt_mapc_listing_enum list_type,void *user_data);
void srv_bt_mapc_abort_req(void *user_data);

void srv_bt_mapc_get_msg_req(U8 *handle,MMI_BOOL attachment,srv_bt_map_charset_enum charset,void *user_data);

S8 srv_bt_mapc_set_msg_listing_prop(srv_bt_mapc_set_msg_listing_prop_struct *msg);

MMI_BOOL srv_bt_mapc_is_new_connection(void);

void srv_bt_mapc_set_message_status_req(U8 *handle,srv_bt_mapc_msg_status_enum status_val,void *user_data);

void srv_bt_mapc_mns_send_event_rsp(srv_bt_mapc_mns_send_event_rsp_struct rsp);

/*****************************************************************************************************************
*																												 *
*Now the callback related items that needs to be  handled and informed to sms application                        *
*																												 *
*																												 *
*****************************************************************************************************************/



/*BT_MAPC_EVT_ID_MSG_IND:when application receives this event,
 it needs to typecast this void* para to bt_mapc_srv_map_get_msg_listing_ind */
/*
	typedef struct
	{
		U8 new_message;   //on or off
		U8 	datetime[SRV_BT_MAP_MAX_DATE_STR_LEN+1];
		U16 list_size;
		U8  file[SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN + 1];
	}srv_bt_mapc_get_msg_listing_ind;
*/



#endif /*__MAP_SRV_GPROT_H__*/