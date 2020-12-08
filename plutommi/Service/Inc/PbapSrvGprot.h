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
 *  PhoneBookPBAP.h
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
 * -------
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_PBAP_GPROT_H__
#define __SRV_PBAP_GPROT_H__

#include "MMI_features.h"

#ifdef __MMI_BT_SUPPORT__
#if defined(__MMI_PBAP_SUPPORT__) 

#include "MMIDataType.h"
#include "BtcmSrvGprot.h"

/*max device name, the name is display on when authorize ind received*/
#define MAX_DEV_NAME  80

/*pbap service return result, it indicates the service can use*/
#define SRV_PBAP_RESULT_OK            0

/*pbap service return result, it indicates the service currently can not used*/
#define SRV_PBAP_RESULT_INVALID_HANDLE  -1

/*pbap service return result, it indicates user set the parameter not right*/
#define SRV_PBAP_RESULT_INVALID_PARAMETERS        -2

/*pbap service return result, it indicates service currently is busy*/
#define SRV_PBAP_RESULT_BUSY        -3

/*pbap service event: if want to know pbap register message, it should care this event*/
#define SRV_PBAP_EVENT_START    0x0001

/*pbap service event: if want to know pbap deregister message, it should care this event*/
#define SRV_PBAP_EVENT_STOP    0x0002

/*pbap service event: if want to know pbap authorize message, it should care this event*/
#define SRV_PBAP_EVENT_AUTHORIZE_NOTIFY  0x0004

/*pbap service event: if want to know pbap authentication message, it should care this event*/
#define SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY    0x0008

/*pbap service event: if want to know pbap connect message, it should care this event*/
#define SRV_PBAP_EVENT_CONN_NOTIFY   0x0010

/*pbap service event: if want to know pbap disconnect message, it should care this event*/
#define SRV_PBAP_EVENT_DISCONN_NOTIFY   0x0020

/*****************************************************************************
 *  authorize struct, when service received opposite authorize_ind, will use this struct
 *  to notify mmi
 *    conn_id:  it indicates this authorize process connect id, it is sole
 *    bt_addr:  it indicates the opposite device bt address
 *    dev_name: it indicates the opposite device name, if modified to nickname, will use it
 *
*****************************************************************************/
typedef struct
{
    U32 conn_id;                    /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;      /* bt address, it indicate which device want to connect pbap*/
    U8 dev_name[MAX_DEV_NAME];      /* server UI used, if not paired device, ui use the it */
} srv_pbap_auth_notify_struct;

/*****************************************************************************
 *  connect struct, pbap client to connect pbap server, server will received connect_ind
 *    conn_id:  it indicates this process connect id, it is sole
 *    bt_addr:  it indicates the opposite device bt address
 *    dev_name: it indicates the opposite device name, if modified to nickname, will use it
 *
*****************************************************************************/
typedef struct
{
    U32 conn_id;                    /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;        /*server UI used to notify cm, */
    U8 dev_name[MAX_DEV_NAME]; /* server UI used, if not paired device, ui use the it */
} srv_pbap_conn_notify_struct;

/*****************************************************************************
 *  disconnect struct, pbap client or server want to disconnect the connection, 
 *  after connection disconnected, will received disconnect_ind, and use it to notify mmi
 *    conn_id:  it indicates this authorize process connect id, it is sole
 *    bt_addr:  it indicates the opposite device bt address
 *
*****************************************************************************/
typedef struct
{
    U32 conn_id;        /*cm conn_id, UI use it to notify cm*/
    srv_bt_cm_bt_addr bt_addr;
    MMI_BOOL disconnect_from_cm;
}srv_pbap_disconn_notify_struct;

/*****************************************************************************
 *  authentication struct, BT stack want to challenge the device, will use this struct
 *  to notify 
 *    dev_name: it indicates the opposite device name, if modified to nickname, will use it
 *
*****************************************************************************/
typedef struct
{
    U8 dev_name[MAX_DEV_NAME]; /* utf8 encoding */ 
} srv_pbap_authentication_notify_struct;

/*****************************************************************************
 *  notify callback, when service happened some event,and will use the callback
 *  to notify the user who care the events
 *    srv_hd:  [in] it indicates who register the callback, it is sole
 *    event: [in] it indicates the app care what event
 *    para: [in] if mmi does not want to record some data, it can send to service,
 *               when service finished one event, will give the data to mmi also.
 *
*****************************************************************************/
typedef S32(*bt_notify) (S32 srv_hd, U32 event, void *para);

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_init
 * DESCRIPTION
 *  init pbap service, it will initialize variable
 * PARAMETERS
 *  vaoid      : 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_deinit
 * DESCRIPTION
 *  deinit pbap, when bt power off, will deinit it
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_open
 * DESCRIPTION
 *  open a pbap service
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  srv_hd : return a hanlder to record who open the pbap
 *****************************************************************************/
extern S32 srv_pbap_open(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_close
 * DESCRIPTION
 *  close pbap service
 * PARAMETERS
 *  srv_hd      : [IN] which want to close pbap
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_close(S32 srv_hd);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_set_notify
 * DESCRIPTION
 *  mmi set owner callback and event to service
 * PARAMETERS
 *  srv_hd      : [IN]record who use the pbap
 *  event_mask  : [IN] MMI care the event
 *  notifier    : [IN] MMI register callback
 * RETURNS
 *  S32         : service current result
 *****************************************************************************/
extern S32 srv_pbap_set_notify(S32 srv_hd, U32 event_mask, bt_notify notifier);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_activate
 * DESCRIPTION
 *  activate the pbap server
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32         : service current result
 *****************************************************************************/
extern void srv_pbap_activate(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_deactivate
 * DESCRIPTION
 *  deactivate the pbap, if deactive, pbab server will not be used
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern void srv_pbap_deactivate(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_disconnect_client
 * DESCRIPTION
 *  pbap server disconnect client
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 *  conn_id     : [IN] pbap server disconnect client
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_disconnect_client(U32 conn_id);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_accept_conn
 * DESCRIPTION
 *  pbap server accept connection from pbap client
 * PARAMETERS
 *  app_id      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern S32 srv_pbap_accept_conn(S32 srv_hd, U8 *password);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_reject_conn
 * DESCRIPTION
 *  pbap server reject connection from pbap client
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern S32 srv_pbap_reject_conn(S32 srv_hd);

#ifdef __cplusplus
}
#endif


#endif /* defined(__MMI_PBAP_SUPPORT__) */

#ifdef __BT_PBAP_CLIENT__

#define PCE_DEFINED
#include "MMIDataType.h"
#include "Bluetooth_struct.h"

extern void srv_btpbapc_init(void);

#define PBAP_XML_PARSE_NUM 		 20

/*****************Response Event Ids***********************/
	typedef  enum {

	EVT_ID_PBAPC_CONNECT_RSP,
	EVT_ID_PBAPC_CONNECT_IND,
	EVT_ID_PBAPC_DISCONNECT_RSP,
	EVT_ID_PBAPC_READ_FOLDER_RSP,
	EVT_ID_PBAPC_READ_LIST_RSP,
	EVT_ID_PBAPC_READ_ENTRY_RSP,
	EVT_ID_PBAPC_SET_PATH_RSP,
	EVT_ID_PBAPC_DISCONNECT_IND,
	EVT_ID_PBAPC_ENABLE_RSP,
	EVT_ID__PBAPC_DISABLE_RSP,
	EVT_ID_PBAPC_ABORT_IND,
	EVT_ID_PBAPC_ABORT_RSP,
	EVT_ID_PBAPC_AUTH_CHALLENGE_IND,
	EVT_ID_PBAPC_READ_DATA_RSP
}bt_pbap_client_event_enum;


      /*          Response Structures        */

typedef struct {
	void *data;
	kal_uint8 srvhd;
	bt_pbap_client_event_enum  type;
} bt_pbap_client_event_notify_struct ;


typedef  struct {
    kal_uint8  cnf_code;  //0 for success
} bt_pbap_client_connect_rsp_struct;

typedef  struct {
    kal_uint8  cnf_code;  //0 for success
} bt_pbap_client_connect_ind_struct;


typedef  struct {
    kal_uint8  cnf_code;  //0 for success
} bt_pbap_client_disconnect_rsp_struct;

typedef  struct {
    kal_uint8  cnf_code;  //0 for success
} bt_pbap_client_disconnect_ind_struct;



typedef  struct {
    kal_uint8  cnf_code;  //0 for success
} bt_pbap_client_set_path_rsp_struct ;

typedef  struct {
    kal_uint8  cnf_code;  //0 for success
} bt_pbap_client_read_entry_struct;

typedef  struct {
	kal_uint8  cnf_code;
	kal_uint16 phoneBookSize; //0xffff indicates have only data
	kal_uint16 newMissedCalls;  //0xffff means type is not MCH
} bt_pbap_client_read_folder_rsp_struct;

typedef  struct {
	kal_uint8  cnf_code;
	kal_uint16 phoneBookSize; //0xffff indicates have only data
	kal_uint16 newMissedCalls;  //0xffff means type is not MCH
} bt_pbap_client_read_list_rsp_struct;

typedef struct {
	int more;                                              // 1 for moredata from PBAP SRV, 0 for no more data
	int  num_entries;                                      //No. of useful entries in the handle and name array
	kal_uint8  handle[PBAP_XML_PARSE_NUM];                 //List of handles on remote device
	char name[PBAP_XML_PARSE_NUM][PBAP_MAX_NAME_LEN/2];    //list of names ,name is mapped one to one for handle
}bt_pbap_list_data_rsp_struct;


/**********  Filters for PCE *****************/

typedef U8 PbapVcardFilterBit;

#define PBAP_VCARD_FILTER_VER       0        /* Version (Bit 0) */
#define PBAP_VCARD_FILTER_FN        1        /* Formatted Name (Bit 1) */
#define PBAP_VCARD_FILTER_N         2        /* Structured Presentation of Name (Bit 2) */
#define PBAP_VCARD_FILTER_PHOTO     3        /* Associated Image or Photo (Bit 3) */
#define PBAP_VCARD_FILTER_BDAY      4        /* Birthday (Bit 4) */
#define PBAP_VCARD_FILTER_ADR       5        /* Delivery Address (Bit 5) */
#define PBAP_VCARD_FILTER_LABEL     6        /* Delivery (Bit 6) */
#define PBAP_VCARD_FILTER_TEL       7        /* Telephone (Bit 7) */
#define PBAP_VCARD_FILTER_EMAIL     8        /* Electronic Mail Address (Bit 8) */
#define PBAP_VCARD_FILTER_MAILER    9        /* Electronic Mail (Bit 9) */
#define PBAP_VCARD_FILTER_TZ        10       /* Time Zone (Bit 10) */
#define PBAP_VCARD_FILTER_GEO       11       /* Geographic Position (Bit 11) */
#define PBAP_VCARD_FILTER_TITLE     12       /* Job (Bit 12) */
#define PBAP_VCARD_FILTER_ROLE      13       /* Role within the Organization (Bit 13) */
#define PBAP_VCARD_FILTER_LOGO      14       /* Organization Logo (Bit 14) */
#define PBAP_VCARD_FILTER_AGENT     15       /* vCard of Person Representing (Bit 15) */
#define PBAP_VCARD_FILTER_ORG       16       /* Name of Organization (Bit 16) */
#define PBAP_VCARD_FILTER_NOTE      17       /* Comments (Bit 17) */
#define PBAP_VCARD_FILTER_REV       18       /* Revision (Bit 18) */
#define PBAP_VCARD_FILTER_SOUND     19       /* Pronunciation of Name (Bit 19) */
#define PBAP_VCARD_FILTER_URL       20       /* Uniform Resource Locator (Bit 20) */
#define PBAP_VCARD_FILTER_UID       21       /* Unique ID (Bit 21) */
#define PBAP_VCARD_FILTER_KEY       22       /* Public Encryption Key (Bit 22) */
#define PBAP_VCARD_FILTER_NICK      23       /* Nickname (Bit 23) */
#define PBAP_VCARD_FILTER_CAT       24       /* Categories (Bit 24) */
#define PBAP_VCARD_FILTER_PRODID    25       /* Product Id (Bit 25) */
#define PBAP_VCARD_FILTER_CLASS     26       /* Class Information (Bit 26) */
#define PBAP_VCARD_FILTER_SORT_STR  27       /* Sort string (Bit 27) */
#define PBAP_VCARD_FILTER_TIMESTAMP 28       /* Time stamp (Bit 28) */
/* Bits 29-38 Reserved for future use */
#define PBAP_VCARD_FILTER_PROP      39       /* Use of a proprietary filter (Bit 39) */
/* Bits 40-63 Reserved for proprietary filter usage */

/************  Path for PSE *********/

typedef enum{
 	PBAPC_PATH_ROOT = 1,
	PBAPC_PATH_PHONEBOOK ,         /* Phone Phonebook path is used */
	PBAPC_PATH_INCOMING,           /* Phone Incoming call path is used */
	PBAPC_PATH_OUTGOING,           /*Phone  Outgoing call path is used */
	PBAPC_PATH_MISSED,             /*Phone  Missed call path is used */
	PBAPC_PATH_COMBINED,	 	   /*Phone  Combined call path is used */
	PBAPC_PATH_PB_TELECOM ,		   /*Phone Telecom  path is used */ 			       
	PBAPC_PATH_SIM_PHONEBOOK,  	   /*SIM  Phonebook path is used */	    
	PBAPC_PATH_SIM_INCOMING,	   /*SIM  Incoming call  path is used */       
	PBAPC_PATH_SIM_OUTGOING,  	   /* SIM Outgoing call path is used */	      
	PBAPC_PATH_SIM_MISSED,  	   /* SIM Missed call path is used */
	PBAPC_PATH_SIM_COMBINED,	   /* SIM Combined call path is used */
	PBAPC_PATH_SIM_TELECOM,		   /* SIM Telecom call path is used */
	PBAPC_PATH_TELECOM,            /* Should not be used by PHB  SRV*/
	PBAPC_PATH_SIM,				   /* Should not be used by PHB  SRV*/
	PBAPC_PATH_INVALID			   /* Should not be used by PHB  SRV*/
} mmi_pbapc_path_enum;



typedef void (*bt_pbap_client_callback)(bt_pbap_client_event_notify_struct* msg);


/*  Provides a Service handle t  ****/
extern int  srv_btpbapc_client_open(void);

/* Registers Callback function  ****/
extern int srv_btpbapc_client_register_notifier (int srv_hd, bt_pbap_client_callback ptr );

/* Read a Vcard from remote device ****/
extern int srv_btpbapc_read_entry_req  (int srv_hd, kal_uint16 objName[PBAP_MAX_NAME_LEN/2 + 1],
									  PbapVcardFilter filter, PbapVcardFormat format);
/* Sets working path on remote device ***/
extern int srv_btpbapc_set_path_req(int srv_hd,	pbap_set_folder_type_enum  type ,
									 mmi_pbapc_path_enum path);

/* Reads list of vcard entries for a given path from remote device ****/
extern int srv_btpbapc_read_list_req(int srv_hd, kal_uint16 folderName [PBAP_MAX_NAME_LEN/2 + 1] ,									  
									kal_uint8 searchAttribute, kal_uint8 searchValue[MAX_PBAP_SEARCH_VALUE_LENGTH + 1],
									kal_uint8 searchValueLength, kal_uint16 maxListCount, 
									kal_uint16 listStartOffset,kal_uint8 order );

/* Reads complete folder for a given path from remote device ***/
extern int srv_btpbapc_read_folder_req(int srv_hd, kal_uint16 folderName [PBAP_MAX_NAME_LEN/2 + 1],
									  PbapVcardFilter filter, PbapVcardFormat format,
 									  kal_uint16 maxListCount, kal_uint16 listStartOffset);

/* In validates the service handle ***/
extern int  srv_btpbapc_client_close(int srv_hd);

/* Disconnects from remote device***/
extern int srv_btpbapc_disconnect_client(int srv_hd);


extern void bt_pbap_callback_func(bt_pbap_client_event_notify_struct *msg );

extern void bt_pbapc_read_data();

 
#endif /*__BT_PBAP_CLIENT__*/

#endif /* __MMI_BT_SUPPORT__ */

#endif 

