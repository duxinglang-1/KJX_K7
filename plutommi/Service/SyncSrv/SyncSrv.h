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
 *  SyncSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of syncml service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_H__
#define __SYNC_SRV_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "SyncSrvGprot.h"
#include "MMI_trc_int.h"
#include "MMI_conn_app_trc.h"

/*****************************************************************************
 * Define 
 ******************************************************************************/
#define SYNCML_OK                  SRV_SYNC_OK
#define SYNCML_NOT_FOUND           SRV_SYNC_NOT_FOUND
#define SYNCML_FAIL                SRV_SYNC_FAIL
#define SYNCML_INVALID_CREDENTIAL  SRV_SYNC_INVALID_CREDENTIAL
#define SYNCML_MISSING_CREDENTIAL  SRV_SYNC_MISSING_CREDENTIAL
#define SYNCML_DEVICE_FULL         SRV_SYNC_DEVICE_FULL
#define SYNCML_PAYMENT_REQUIRED    SRV_SYNC_PAYMENT_REQUIRED
	/* yln added, other code need to be displayed */
#define SYNCML_CODE_FORBIDDEN      SRV_SYNC_CODE_FORBIDDEN
#define SYNCML_INCOMPLETE_CMD      SRV_SYNC_INCOMPLETE_CMD
#define SYNCML_SERVICE_UNAVAILABLE SRV_SYNC_SERVICE_UNAVAILABLE          /* Server busy */
#define SYNCML_DATASTORE_FAIL      SRV_SYNC_DATASTORE_FAIL
#define SYNCML_SVR_FAIL            SRV_SYNC_SVR_FAIL
#define SYNCML_ERR_OCCUR           SRV_SYNC_ERR_OCCUR
#define SYNCML_PROTOCOL_UNSUPPORT  SRV_SYNC_PROTOCOL_UNSUPPORT

#define SYNCML_VOBJ_PATH     			L"Z:\\@SyncML\\syncvobj.tmp"
#define RETURN_IF_FAIL(p) if(!(p)){return;}
#define RETURN_VAL_IF_FAIL(p, ret) if(!(p)){ return (ret);}

#define TYPE_CAST(type, ptr) ((type *)ptr)
#define GET_OBJ_PRIV(type, obj) ((type *)(obj->priv))

#define SYNC_MALLOC(_type) ((_type *)OslMalloc(sizeof(_type)))
#define SYNC_MFREE(_ptr)	{if (_ptr) {OslMfree(_ptr); _ptr = NULL; }}

#define SRV_SYNC_LOG0(sub_grp) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp)

#define SRV_SYNC_LOG1(sub_grp, arg) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg)
		
#define SRV_SYNC_LOG2(sub_grp, arg1, arg2) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg1, arg2)

#define SRV_SYNC_LOG3(sub_grp, arg1, arg2, arg3) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg1, arg2, arg3)
		
#define SRV_SYNC_LOG6(sub_grp, arg1, arg2, arg3, arg4, arg5, arg6) \
			MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, sub_grp, arg1, arg2, arg3, arg4, arg5, arg6)

/*****************************************************************************
 * Typedef 
 ******************************************************************************/

typedef enum{
	SRV_SYNC_STATE_IDLE,
	SRV_SYNC_STATE_START,
	SRV_SYNC_STATE_SYNCING,
	SRV_SYNC_STATE_ABORTING,
	SRV_SYNC_STATE_TOTAL
}srv_sync_state_enum;

typedef enum
{
    /* shall map to SYNCML_OP_ENUM in SyncML task */
    SYNCML_RECORD_GET = 0,
    SYNCML_RECORD_ADD,
    SYNCML_RECORD_MODIFY,
    SYNCML_RECORD_DELETE,
    SYNCML_RECORD_MOVE,
    SYNCML_RECORD_ALL,
    SYNCML_RECORD_GET_DEL_NOTIFY,
    SYNCML_RECORD_GET_MOVE_NOTIFY,
    SYNCML_RECORD_ERASE /* clear the change log of this record */
}srv_sync_operation_type_enum;


typedef enum{
	RET_OK,
	RET_STOP,
	RET_TOTAL
}Ret;

typedef struct
{
    U8 operation; /* add, modify, delete, move */
    U8 database;
	U8 more_data;
    U8 charset;
	U16 luid;
    U16 result;
    U16 count; /* for query luid list */
	U16 unused;
    U16 *luid_buf;	
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__    
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
} srv_sync_request_struct;

struct srv_sync_cntx;
typedef struct srv_sync_cntx srv_sync_type;

struct srv_sync_cm_cntx;
typedef struct srv_sync_cm_cntx srv_sync_cm_type;

struct srv_sync_database_cntx;
typedef struct srv_sync_database_cntx srv_sync_database_type;

struct srv_sync_accnt_cntx;
typedef struct srv_sync_accnt_cntx srv_sync_accnt_type;

struct srv_sync_changelog_cntx;
typedef struct srv_sync_changelog_cntx srv_sync_changelog_type;

typedef Ret (*srv_sync_visist_funcptr)(void *data, void* usr_data);
typedef void (*srv_sync_msg_hdlr_funcptr)(void *info);

/*****************************************************************************
 * Global function 
 *****************************************************************************/
extern srv_sync_accnt_type *srv_sync_active_accnt(void);
extern srv_sync_type *srv_sync_active_sync(void);
extern void srv_sync_set_last_error(const U16 error_str);
extern MMI_BOOL srv_sync_is_state(srv_sync_state_enum state);
extern U32 srv_sync_foreach_database(srv_sync_visist_funcptr visit, void* usr_data);
extern srv_sync_database_type *srv_sync_find_database(const U32 database_type);
extern srv_sync_database_type *srv_sync_get_database(const U32 index);
extern U32 srv_sync_get_total_database(void);

extern void srv_sync_set_record_rsp(srv_sync_request_struct *sync_req);
extern void srv_sync_get_record_rsp(srv_sync_request_struct *req);
extern void srv_sync_query_luid_list_rsp(srv_sync_request_struct *req);
extern void sync_srv_clean_luid_list_rsp(void);
extern void srv_sync_reset_cntx(void);
extern void srv_sync_msg_init(void);
extern void srv_sync_get_imei_req(void);
extern void srv_sync_send_abort_sync(void);
extern void srv_sync_set_state(srv_sync_state_enum state);
extern void srv_sync_deinit(void);
extern srv_sync_ret_enum srv_sync_on_start(srv_sync_enum sync, U8 accnt_index, U32 database, void *usr_data);
extern void srv_sync_reset_database(U32 db_mask);
extern void srv_sync_msg_simulator(void *msg, U32 msg_id);
extern void srv_sync_dummy_finish(void);
#endif /* __SYNC_SRV_H__ */

