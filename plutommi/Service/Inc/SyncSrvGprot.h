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
 *  SyncSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of sync service
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_GPROT_H__
#define __SYNC_SRV_GPROT_H__

#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"

/****************************************************************************
 * Define
 ****************************************************************************/
#define SRV_SYNC_OK                  200
#define SRV_SYNC_NOT_FOUND           211          /* Wen, */
#define SRV_SYNC_FAIL                500
#define SRV_SYNC_INVALID_CREDENTIAL  401
#define SRV_SYNC_MISSING_CREDENTIAL  407
#define SRV_SYNC_DEVICE_FULL         420
#define SRV_SYNC_PAYMENT_REQUIRED    402

/* yln added, other code need to be displayed */
#define SRV_SYNC_CODE_FORBIDDEN      403          /* Server busy */
#define SRV_SYNC_INCOMPLETE_CMD      412
#define SRV_SYNC_DEVICE_FULL         420
#define SRV_SYNC_SERVICE_UNAVAILABLE 503          /* Server busy */
#define SRV_SYNC_DATASTORE_FAIL      510
#define SRV_SYNC_SVR_FAIL            511
#define SRV_SYNC_ERR_OCCUR           512
#define SRV_SYNC_PROTOCOL_UNSUPPORT  513

/* account valid mask  */
#define MMI_SYNCML_ACCOUNT_VALID_MASK_NAME  0x0001
#define MMI_SYNCML_ACCOUNT_VALID_MASK_SVR   0x0002
#define MMI_SYNCML_ACCOUNT_VALID_MASK_CON   0x0004  /* phonebook validation mask */
#define MMI_SYNCML_ACCOUNT_VALID_MASK_CAL   0x0008
#define MMI_SYNCML_ACCOUNT_VALID_MASK_TASK  0x0010
#define MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE  0x0020
#define MMI_SYNCML_ACCOUNT_VALID_MASK_BKM   0x0040
#define MMI_SYNCML_ACCOUNT_VALID_MASK_EMAIL 0x0080 
/* ... reserved for other database */
#define MMI_SYNCML_ACCOUNT_VALID_MASK_CONN  0x8000  /* connection validation mask net_id*/

#define SRV_SYNC_MAX_DEV_NAME_LEN   	  64    /* Device sync */
/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
	SRV_SYNC_RET_OK,
	SRV_SYNC_RET_FAIL,
	SRV_SYNC_RET_ERROR_INVALID_SYNC,
	SRV_SYNC_RET_ERROR_INVALID_ACCNT,
	SRV_SYNC_RET_ERROR_INVALID_DATABASE,
	SRV_SYNC_RET_ERROR_BUSY,
	SRV_SYNC_RET_ERROR_NO_SELECTED_DB,
	SRV_SYNC_RET_ERROR_DB_NOT_READY,
	SRV_SYNC_RET_ERROR_WAP_NOT_READY,
	SRV_SYNC_RET_ERROR_INVALID_DATA_ACCOUNT,
	SRV_SYNC_RET_TOAL
}srv_sync_ret_enum;

typedef enum
{
	SRV_SYNC_REMOTE,
	SRV_SYNC_PHONE,
	SRV_SYNC_PC,	
	SRV_SYNC_TOTAL,
}srv_sync_enum;

typedef enum
{
	SRV_SYNC_ANSWER_REJECT,
	SRV_SYNC_ANSWER_ACCEPT,
	SRV_SYNC_ANSWER_TOTAL
}srv_sync_answer_enum;

typedef enum
{
	SRV_SYNC_ACTION_SEND,
	SRV_SYNC_ACTION_RECV,
	SRV_SYNC_ACTION_TOTAL
}srv_sync_action_enum;

typedef enum
{
	SRV_SYNC_REGULAR_NEVER,
	SRV_SYNC_REGULAR_AT_PWRON,
	SRV_SYNC_REGULAR_AT_DATA_CHANGE,
	SRV_SYNC_REGULAR_EVERY_DAY,
	SRV_SYNC_REGULAR_EVERY_WEEK,
	SRV_SYNC_REGULAR_EVERY_MONTH,
	SRV_SYNC_REGULAR_TOTAL
}srv_sync_regular_enum;

typedef enum
{
	SRV_SYNC_ACCNT_OP_ADD,
	SRV_SYNC_ACCNT_OP_MODIFY,
	SRV_SYNC_ACCNT_OP_DEL,
	SRV_SYNC_ACCNT_OP_TOTAL
}srv_sync_accnt_op_enum;

typedef enum
{
	SRV_SYNC_CM_NOTIFY_CONN,
	SRV_SYNC_CM_NOTIFY_DISCONN,
	SRV_SYNC_CM_NOTIFY_TOTAL
}srv_sync_cm_notify_enum;


typedef enum
{
    SRV_SYNC_ACCNT_TRANS_TYPE_INTERNET,
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    SRV_SYNC_ACCNT_TRANS_TYPE_BT,
#endif
    SRV_SYNC_ACCNT_TRANS_TYPE_TOTAL
}srv_sync_accnt_trans_type_enum;

typedef MMI_BOOL (*srv_sync_check_conn_funcptr)(U32 conn_id);

/****************************************************************************
 * Global functions
 ****************************************************************************/

#ifdef __BUILD_DOM__
/*
 * DESCRIPTION
 *  Event ID of Sync.
 *  Sync service will send evt to notify AP.
 */
typedef enum
{
    /*
     * [INTERNAL]
     *
     * Structure:
     *  srv_sync_evt_struct
     */
    EVT_ID_SRV_SYNC_ASK_CONN = SRV_SYNC_BASE,
    EVT_ID_SRV_SYNC_ASK_SYNC,
    EVT_ID_SRV_SYNC_PROGRESS,
    EVT_ID_SRV_SYNC_FINISH,
    EVT_ID_SRV_SYNC_CM,
	EVT_ID_SRV_SYNC_BG_START,
	EVT_ID_SRV_SYNC_BG_FINISH,
	EVT_ID_SRV_SYNC_ACCNT_OP,
    EVT_ID_SRV_SYNC_TOTAL
} srv_sync_evt_id_enum;

#endif /*__BUILD_DOM__*/

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SYNC_FINISH, to notify AP about reminder's stage.
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER   
	U32 result;
    srv_sync_enum sync;
    U8	accnt_index;
} srv_sync_finish_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SYNC_PROGRESS, to notify AP about reminder's stage.
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	srv_sync_action_enum action;
	U16 db_id;			/* database id */
	U16 curr;			/*  current number of */
	U32 total;			/* total number of noc */
    srv_sync_enum sync;
    U8	accnt_index;
} srv_sync_progress_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SYNC_ASK, to notify AP about reminder's stage.
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	U8 accnt_index;
	U16 regular;
	U32 notify_timestamp;
    srv_sync_enum sync;
	U32 lap;
	U8 uap;
	U16 nap;
} srv_sync_ask_sync_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SYNC_ASK, to notify AP about reminder's stage.
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	U32 lap;
	U8 uap;
	U16 nap;
	CHAR name[SRV_SYNC_MAX_DEV_NAME_LEN];
} srv_sync_ask_conn_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SYNC_ASK, to notify AP about reminder's stage.
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	U16 notify;
} srv_sync_cm_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SYNC_ACCNT_OP, to notify AP about account change
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	U16 operation;
	U8 index;
	MMI_BOOL clear;
	srv_sync_enum sync;
} srv_sync_accnt_op_evt_struct;

#ifdef __MMI_SYNCML_CCA_SUPPORT__
/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SYNC_OTA_IND, to notify AP about account change
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
	U16 total;
} srv_sync_ota_ind_evt_struct;


typedef struct{
	MMI_BOOL updateble;
	U16 dest_idx;
	void *accnt;
}srv_sync_ota_accnt_info_struct;
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_sync_init
 * DESCRIPTION
 *  sync initialization
 * PARAMETERS
 *  	void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_id srv_sync_init(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_start
 * DESCRIPTION
 *  start sync
 * PARAMETERS
 *  	type			:[IN]	sync type
 *	accnt_index	:[IN]	accnt index
 *	database		:[IN]	database
 *  	usr_data		:[IN]	usr_data can be anything.
 * RETURNS
 *  srv_sync_ret_enum
 *****************************************************************************/
extern srv_sync_ret_enum srv_sync_start(
								srv_sync_enum sync, 
								U8 accnt_index,
								U32 database,
								void *usr_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_abort
 * DESCRIPTION
 *  start sync
 * PARAMETERS
 *  type					:[IN]	sync type
 *	accnt_index		:[IN]	Reminder expiry time
 *  usr_data			:[IN]	The user data
 * RETURNS
 *  srv_sync_ret_enum
 *****************************************************************************/
extern srv_sync_ret_enum srv_sync_abort(srv_sync_enum sync);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_get_database_count
 * DESCRIPTION
 *  Get total database
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 srv_sync_get_database_count(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_is_database_ready
 * DESCRIPTION
 *  Get total database
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
extern MMI_BOOL srv_sync_is_database_ready(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_answer
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  answer	:[IN]	answer enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sync_answer(srv_sync_answer_enum answer);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_is_db_synchronizing
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  database	:[IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sync_is_db_synchronizing(U32 database);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_is_synchronizing
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  answer	:[IN]	answer enum
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sync_is_synchronizing(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sync_active_sync_info
 * DESCRIPTION
 *  Get the current active sync infomation.
 * PARAMETERS
 *	sync		:[OUT]	sync
 *	index	:[OUT]	accnt index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sync_active_sync_info(srv_sync_enum *sync, U8 *index);

/*****************************************************************************
 * FUNCTION
 *  srv_sync_read_accnt
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  answer	:[IN]	answer enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void *srv_sync_read_accnt(srv_sync_enum sync, U8 accnt_index);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_read_accnt_buffer
 * DESCRIPTION
 *  read accnt info
 * PARAMETERS
 *  buffer			:[IN]	answer enum
 *  size			:[IN]	answer enum
 *  sync			:[IN]	answer enum
 *  accnt_index	:[IN]	answer enum
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sync_read_accnt_buffer(void *buffer, U32 size, srv_sync_enum sync, U8 accnt_index);

/*****************************************************************************
 * FUNCTION
 *  srv_sync_write_accnt
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  answer	:[IN]	answer enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sync_write_accnt(srv_sync_enum sync, void *accnt, U8 accnt_index);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_get_current_time
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  answer	:[IN]	answer enum
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 srv_sync_get_current_time(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_accnt_new_index
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  sync		:[IN]	answer enum
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_sync_accnt_new_index(srv_sync_enum sync);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_remote_app_id
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  sync		:[IN]	answer enum
 * RETURNS
 *  S32
 *****************************************************************************/
extern U8 srv_sync_remote_app_id(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_check_regular_sync
 * DESCRIPTION
 *  Check where there is regular sync
 * PARAMETERS
 *  sync		:[IN]	answer enum
 * RETURNS
 *  S32
 *****************************************************************************/
extern void srv_sync_check_regular_sync(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sync_has_regular_sync
 * DESCRIPTION
 *  Check where there is regular sync
 * PARAMETERS
 *  regular_sync		:[IN]	regular sync
 * RETURNS
 *  S32	return the first account index who has this regular sync
 *****************************************************************************/
extern S32 srv_sync_has_regular_sync(U16 regular_sync);

/*****************************************************************************
 * FUNCTION
 *  srv_sync_finish_regular_sync
 * DESCRIPTION
 *  Check where there is regular sync
 * PARAMETERS
 *  sync		:[IN]	answer enum
 * RETURNS
 *  S32
 *****************************************************************************/
extern void srv_sync_finish_regular_sync(U8 index);

#ifdef __MMI_SYNCML_CCA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_proc_cca_doc
 * DESCRIPTION
 *  handle document from CCA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sync_ota_proc_cca_doc(void *param);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_construct_cca_doc_for_dm
 * DESCRIPTION
 *  This function construct cca document for DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sync_ota_construct_cca_doc_for_dm(void* param);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_install_cca_doc_from_dm
 * DESCRIPTION
 *  This function install the new setting into NVRAM from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
extern void srv_sync_ota_install_cca_doc_from_dm(void *param);

/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_checking_for_dm
 * DESCRIPTION
 *  This function used to check whether hanset can receive the new setting from DM.
 * PARAMETERS
 *  void
 * RETURNS
 *  0,1
 *****************************************************************************/
extern S32 srv_sync_ota_checking_for_dm(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_install_new_accnt
 * DESCRIPTION
 *	Install ota accnt to accnt list.
 * PARAMETERS
 *	dest_index	[IN]		dest accnt index
 *	dest_index	[IN]		cca status
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sync_ota_install_new_accnt(U8 dest_index, U16 cca_status);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_is_empty_accnt
 * DESCRIPTION
 *  To check whether the accnt is empty accnt
 * PARAMETERS
 *	accnt_index	[IN]		accnt index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sync_ota_is_empty_accnt(U8 accnt_index);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_get_info
 * DESCRIPTION
 *  Get the next ota account index.
 * PARAMETERS
 *	info		[OUT]	accnt info
 *	index	[IN]		accnt index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sync_ota_get_info(void *info, U8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_next_accnt
 * DESCRIPTION
 *  Get the next ota account index.
 * PARAMETERS
 *  void
 * RETURNS
 *  S8
 *****************************************************************************/
extern S32 srv_sync_ota_next_accnt(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sync_ota_finish
 * DESCRIPTION
 *  finish ota process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sync_ota_finish(void);

#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __SYNC_SRV_GPROT_H__ */


