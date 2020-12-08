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
 *  SrvSmsATHandler.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service AT Command Handler
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
 *****************************************************************************/
#include "MMI_features.h"
#if (defined( __MOD_SMSAL__ ) && defined(__SRV_SMS_AT_SUPPORT__))
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "string.h"

#include "mmi_msg_struct.h"
#include "mmi_common_app_trc.h"
#include "SmsSrvGprot.h"
#include "SmsProtSrv.h"
#include "SmsStorageSrv.h"
#include "SmsStorageCoreSrv.h"
#include "SmsUtilSrv.h"
#include "SmsAtHandlerSrv.h"
#include "ps_public_enum.h"

#include "Rmmi_common_enum.h"
#include "SmsDispatchSrv.h"
#include "ProtocolEvents.h"


/**************************************************************
* MARCO
**************************************************************/


/**************************************************************
* Structure Declaration
**************************************************************/
typedef enum
{
    DEL_FLAG_INDEX                      = 0,
    DEL_FLAG_PREFER_READ                = 1,
    DEL_FLAG_PREFER_READ_SENT           = 2,
    DEL_FLAG_PREFER_READ_SEND_UNSENT    = 3,
    DEL_FLAG_PREFER_ALL                        = 4

} srv_sms_at_del_flag_enum;

typedef struct
{
    U8 mmi_op_count;
    U8 at_op_count;
} srv_sms_at_hdlr_cntx_struct;

typedef struct
{
    U8 source_id;
    U8 at_mem;
    MMI_BOOL is_changed;
    srv_sms_sim_enum sim_id;
    U16 pdu_id;
    U16 index;
    mmi_sms_atcmd_cmgr_res_req_struct *cmgr_res;
}srv_sms_at_cmgr_cntx_struct;

typedef struct
{
    U8 source_id;
    U8 at_mem;
    U8 at_status;
    MMI_BOOL is_mt;
    srv_sms_status_enum msg_status;
    MMI_BOOL is_changed;
    srv_sms_sim_enum sim_id;
    U16 pdu_id;
    U16 curr_index;
    U16 total_num;
    mmi_sms_atcmd_cmgl_res_req_struct *cmgl_res;
}srv_sms_at_cmgl_cntx_struct;

typedef struct
{
    U8 source_id;
    U8 at_mem;
    U8 del_flag;
    MMI_BOOL is_mt;
    srv_sms_status_enum msg_status;
    srv_sms_sim_enum sim_id;
    U16 pdu_id;
    U16 curr_index;
    U16 total_num;
}srv_sms_at_cmgd_cntx_struct;

typedef struct
{
    U8 source_id;
    U8 at_mem;
    srv_sms_sim_enum sim_id;
}srv_sms_at_cmgw_cntx_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_at_hdlr_cntx_struct at_hdlr_cntx;

U32 in_atcm_delete;
U32 in_atcm_cmgl;
/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_at_send_msg(srv_sms_at_cmgd_cntx_struct *cmgd_cntx, 
						MMI_BOOL result,
						srv_sms_cause_enum cause);

static void srv_sms_enter_at_cmd_operating(void);
static void srv_sms_exit_at_cmd_operating(void);

static U16 srv_sms_at_index_to_pdu_id(U16 index, U8 smsal_storage, srv_sms_sim_enum sim_id);
static U16 srv_sms_at_pdu_id_to_index(U16 pdu_id, U8 at_mem, srv_sms_sim_enum sim_id);

static U8 srv_sms_msg_status_to_at_status(srv_sms_status_enum msg_status);
static srv_sms_status_enum srv_sms_at_status_to_msg_status(U8 at_status);

static srv_sms_storage_enum srv_sms_at_mem_to_storage_type(U8 at_mem);

static void srv_sms_at_cmgr_hldr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_at_cmgr_read_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_at_cmgr_update_callback(srv_sms_callback_struct *callback_data);

static void srv_sms_at_cmgl_hldr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_at_cmgl_read_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_at_cmgl_update_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_at_cmgl_read_pdu(srv_sms_at_cmgl_cntx_struct* cmgl_cntx);
static void srv_sms_at_cmgl_set_next_read_index(srv_sms_at_cmgl_cntx_struct* cmgl_cntx);
static void srv_sms_at_cmgl_read_finish(srv_sms_at_cmgl_cntx_struct* cmgl_cntx);
static void srv_sms_at_cmgd_hldr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_at_cmgd_delete_multi(srv_sms_at_cmgd_cntx_struct *cmgd_cntx);
static void srv_sms_at_cmgd_set_next_del_index(srv_sms_at_cmgd_cntx_struct *cmgd_cntx);
static void srv_sms_at_cmgd_delete_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_at_cmgd_del_multi_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_at_cmgw_hldr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_at_cmgw_save_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_at_eqsi_hldr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_at_cgsms_hldr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_at_csas_hldr(void *in_msg, srv_sms_sim_enum sim_id);
static srv_sms_cause_enum srv_sms_at_check_common_error(U8 at_mem);
static MMI_BOOL srv_sms_at_is_mem_valid(U8 at_men);
static void srv_sms_at_send_message(U16 msg_id, void* local_ptr, srv_sms_sim_enum sim_id);


/**************************************************************
* Function Defination
**************************************************************/
static void srv_sms_at_send_msg(srv_sms_at_cmgd_cntx_struct *cmgd_cntx, 
								 MMI_BOOL result,
								 srv_sms_cause_enum cause)
{
	mmi_sms_atcmd_cmgd_res_req_struct *cmgd_res;
	srv_sms_sim_enum sim_id;
	sim_id = cmgd_cntx->sim_id;
	
	cmgd_res = (mmi_sms_atcmd_cmgd_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgd_res_req_struct));
	cmgd_res->source_id = cmgd_cntx->source_id;
	cmgd_res->result = result;
	cmgd_res->cause = cause;
	OslMfree(cmgd_cntx);
	srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGD_RES_REQ, cmgd_res, sim_id);
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_sms_at_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_EVENT_PROC, evt->evt_id);

    if (evt->evt_id == EVT_ID_SRV_SMS_PS_AT_IND)
    {
        mmi_evt_sms_disp_struct *event_data = (mmi_evt_sms_disp_struct*)evt;
        void *in_msg = event_data->data;
        srv_sms_sim_enum sim_id = (srv_sms_sim_enum)event_data->sim_id;
        srv_sms_at_cmd_enum cmd_type;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_EVENT_PROC_1, event_data->msg_id);

        switch (event_data->msg_id)
        {
            case PTR_MSG_ID_MMI_SMS_ATCMD_CMGR_IND:
                srv_sms_at_cmgr_hldr(in_msg, sim_id);
                cmd_type = SRV_SMS_AT_CMD_CMGR;
                break;

            case PTR_MSG_ID_SRV_SMS_ATCMD_CMGL_IND:
                srv_sms_at_cmgl_hldr(in_msg, sim_id);
                cmd_type = SRV_SMS_AT_CMD_CMGL;
                break;

            case PTR_MSG_ID_SRV_SMS_ATCMD_CMGD_IND:
                srv_sms_at_cmgd_hldr(in_msg, sim_id);
                cmd_type = SRV_SMS_AT_CMD_CMGD;
                break;

            case PTR_MSG_ID_SRV_SMS_ATCMD_CMGW_IND:
                srv_sms_at_cmgw_hldr(in_msg, sim_id);
                cmd_type = SRV_SMS_AT_CMD_CMGW;
                break;

            case PTR_MSG_ID_SRV_SMS_ATCMD_EQSI_IND:
                srv_sms_at_eqsi_hldr(in_msg, sim_id);
                cmd_type = SRV_SMS_AT_CMD_EQSI;
                break;

            case PTR_MSG_ID_SRV_SMS_ATCMR_CGSMS_IND:
                srv_sms_at_cgsms_hldr(in_msg, sim_id);
                cmd_type = SRV_SMS_AT_CMD_CGSMS;
                break;

            case PTR_MSG_ID_SRV_SMS_ATCMR_CSAS_IND:
                srv_sms_at_csas_hldr(in_msg, sim_id);
                cmd_type = SRV_SMS_AT_CMD_CSAS;
                break;

            default:
                cmd_type = SRV_SMS_AT_CMD_NONE;
                break;
        }

        if (srv_sms_is_in_mmi_operating() == MMI_FALSE)
        {
            srv_sms_event_at_cmd_ind_struct event_info;

            event_info.sim_id = sim_id;
            event_info.cmd_type = cmd_type;

            srv_sms_emit_event(EVT_ID_SRV_SMS_AT_CMD_IND, &event_info);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_enter_mmi_operating
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_enter_mmi_operating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ENTER_MMI_OPERATING, at_hdlr_cntx.mmi_op_count);

    at_hdlr_cntx.mmi_op_count++;

    MMI_ASSERT(at_hdlr_cntx.mmi_op_count > 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_exit_mmi_operating
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_exit_mmi_operating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_EXIT_MMI_OPERATING, at_hdlr_cntx.mmi_op_count);

    MMI_ASSERT(at_hdlr_cntx.mmi_op_count > 0);

    at_hdlr_cntx.mmi_op_count--;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_in_mmi_operating
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_in_mmi_operating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_IN_MMI_OPERATING, at_hdlr_cntx.mmi_op_count);

    if (at_hdlr_cntx.mmi_op_count > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_enter_at_cmd_operating
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_enter_at_cmd_operating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ENTER_AT_CMD_OPERATING, at_hdlr_cntx.at_op_count);

    at_hdlr_cntx.at_op_count++;

    MMI_ASSERT(at_hdlr_cntx.at_op_count > 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_exit_at_cmd_operating
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_exit_at_cmd_operating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_EXIT_AT_CMD_OPERATING, at_hdlr_cntx.at_op_count);

    MMI_ASSERT(at_hdlr_cntx.at_op_count > 0);

    at_hdlr_cntx.at_op_count--;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_in_at_cmd_operating
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_in_at_cmd_operating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_IN_AT_CMD_OPERATING, at_hdlr_cntx.at_op_count);

    if (at_hdlr_cntx.at_op_count > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_status_to_at_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_sms_msg_status_to_at_status(srv_sms_status_enum msg_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 at_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_STATUS_TO_AT_STATUS, msg_status);

    /* Reference TS 07.05 Clause 3.1 */
    switch (msg_status)
    {
        case SRV_SMS_STATUS_UNREAD:
            at_status = SMSAL_REC_UNREAD;
            break;

        case SRV_SMS_STATUS_READ:
            at_status = SMSAL_REC_READ;
            break;

        case SRV_SMS_STATUS_SENT:
            at_status = SMSAL_STO_SENT;
            break;

        case SRV_SMS_STATUS_DRAFT:
            at_status = SMSAL_STO_DRAFT;
            break;

        case SRV_SMS_STATUS_UNSENT:
        default:
            at_status = SMSAL_STO_UNSENT;
            break;
    }

    return at_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_status_to_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_status_enum srv_sms_at_status_to_msg_status(U8 at_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_STATUS_TO_MSG_STATUS, at_status);

    /* Reference TS 07.05 Clause 3.1 */
    switch (at_status)
    {
        case SMSAL_REC_UNREAD:
            msg_status = SRV_SMS_STATUS_UNREAD;
            break;

        case SMSAL_REC_READ:
            msg_status = SRV_SMS_STATUS_READ;
            break;

        case SMSAL_STO_SENT:
            msg_status = SRV_SMS_STATUS_SENT;
            break;

        case SMSAL_STO_DRAFT:
            msg_status = SRV_SMS_STATUS_DRAFT;
            break;

        case SMSAL_STO_UNSENT:
        default:
            msg_status = SRV_SMS_STATUS_UNSENT;
            break;
    }

    return msg_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_mem_to_storage_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_storage_enum srv_sms_at_mem_to_storage_type(U8 at_mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_storage_enum storage_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_ME_TO_STORAGE_TYPE, at_mem);

    switch (at_mem)
    {
        case SMSAL_ME:
            storage_type = SRV_SMS_STORAGE_ME;
            break;

        case SMSAL_SM:
            storage_type = SRV_SMS_STORAGE_SIM;
            break;

        case SMSAL_MT:
        default:
            storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
            break;
    }

    return storage_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_index_to_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_at_index_to_pdu_id(U16 index, U8 at_mem, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_INDEX_TO_PDU_ID, index, at_mem, sim_id);

    switch (at_mem)
    {
        case SMSAL_ME:
            pdu_id = srv_sms_me_record_index_to_pdu_id(index);
            break;

        case SMSAL_SM:
            pdu_id = srv_sms_sim_record_index_to_pdu_id(index, sim_id);
            break;

        case SMSAL_MT:
        default:
        {
        #ifdef __SRV_SMS_MULTI_SIM__
            sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

            if (index < memory_status->me_total)
            {
                pdu_id = index;   
            }
            else
            {
                U16 record_index;

                record_index = index - memory_status->me_total;

                pdu_id = srv_sms_sim_record_index_to_pdu_id(record_index, sim_id);
            }
        #else /* __SRV_SMS_MULTI_SIM__ */
            pdu_id = index;
        #endif /* __SRV_SMS_MULTI_SIM__ */
            break;
        }
    }

    return pdu_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_pdu_id_to_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_at_pdu_id_to_index(U16 pdu_id, U8 at_mem, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_PDU_ID_TO_INDEX, pdu_id);

    switch (at_mem)
    {
        case SMSAL_ME:
            index = srv_sms_pdu_id_to_me_record_index(pdu_id);
            break;

        case SMSAL_SM:
        {
            srv_sms_sim_enum temp_sim_id;

            index = srv_sms_pdu_id_to_sim_record_index(pdu_id, &temp_sim_id);
            break;
        }

        case SMSAL_MT:
        default:
        {
        #ifdef __SRV_SMS_MULTI_SIM__
            sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

            if (pdu_id < memory_status->me_total)
            {
                index = pdu_id;   
            }
            else
            {
                srv_sms_sim_enum temp_sim_id;
                U16 record_index;

                record_index = srv_sms_pdu_id_to_sim_record_index(pdu_id, &temp_sim_id);

                if (record_index == SRV_SMS_INVALID_INDEX)
                {
                    index = SRV_SMS_INVALID_INDEX;
                }
                else
                {
                    index = memory_status->me_total + record_index;
                }
            }
        #else /* __SRV_SMS_MULTI_SIM__ */
            index = pdu_id;
        #endif /* __SRV_SMS_MULTI_SIM__ */
            break;
        }
    }

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgr_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgr_hldr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    mmi_sms_atcmd_cmgr_ind_struct *cmgr_ind = (mmi_sms_atcmd_cmgr_ind_struct*)in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGR_HLDR, sim_id);

    srv_sms_enter_at_cmd_operating();

    error_cause = srv_sms_at_check_common_error(cmgr_ind->mem);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        U16 pdu_id;
        srv_sms_at_cmgr_cntx_struct *cmgr_cntx;

        pdu_id = srv_sms_at_index_to_pdu_id((U16)cmgr_ind->index, cmgr_ind->mem, sim_id);

        cmgr_cntx = OslMalloc(sizeof(srv_sms_at_cmgr_cntx_struct));

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGR_HLDR_1, cmgr_ind->mem, cmgr_ind->index);

        cmgr_cntx->pdu_id = pdu_id;
        cmgr_cntx->at_mem = cmgr_ind->mem;
        cmgr_cntx->index = cmgr_ind->index;
        cmgr_cntx->sim_id = sim_id;
        cmgr_cntx->is_changed = (MMI_BOOL)cmgr_ind->esmss_mode;
        cmgr_cntx->source_id = cmgr_ind->source_id;

        srv_sms_read_pdu(
            pdu_id,
            srv_sms_at_cmgr_read_callback,
            cmgr_cntx);
    }
    else
    {
        mmi_sms_atcmd_cmgr_res_req_struct *cmgr_res;

        cmgr_res = (mmi_sms_atcmd_cmgr_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgr_res_req_struct));

        cmgr_res->source_id = cmgr_ind->source_id;
        cmgr_res->result = KAL_FALSE;
        cmgr_res->cause = error_cause;

        srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGR_RES_REQ, cmgr_res, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgr_read_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgr_read_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_at_cmgr_cntx_struct *cmgr_cntx;
    mmi_sms_atcmd_cmgr_res_req_struct *cmgr_res;
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGR_READ_CALLBACK, callback_data->result);

    cmgr_cntx = (srv_sms_at_cmgr_cntx_struct*)callback_data->user_data;

    sim_id = cmgr_cntx->sim_id;
    
    cmgr_res = (mmi_sms_atcmd_cmgr_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgr_res_req_struct));

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_read_pdu_cb_struct *read_cb_data;
        srv_sms_spdu_struct *spdu_data;

        read_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;
        spdu_data = read_cb_data->spdu_data;

        cmgr_res->source_id = cmgr_cntx->source_id;
        cmgr_res->result = KAL_TRUE;
        cmgr_res->cause = SRV_SMS_CAUSE_NO_ERROR;
        cmgr_res->mem = cmgr_cntx->at_mem;
        cmgr_res->index = cmgr_cntx->index;
        cmgr_res->pdu_length = SRV_SMS_MAX_PDU_SIZE;
        memcpy(cmgr_res->pdu, read_cb_data->spdu_data->pdu, SRV_SMS_MAX_PDU_SIZE);

        if ((cmgr_cntx->is_changed) && (spdu_data->status == SRV_SMS_STATUS_UNREAD))
        {
            cmgr_res->stat = srv_sms_msg_status_to_at_status(SRV_SMS_STATUS_READ);

            cmgr_cntx->cmgr_res = (void*)cmgr_res;

            spdu_data->status = SRV_SMS_STATUS_READ;

            srv_sms_msg_update_pdu(
                cmgr_cntx->pdu_id,
                spdu_data,
                srv_sms_at_cmgr_update_callback,
                cmgr_cntx);

            spdu_data->status = SRV_SMS_STATUS_UNREAD;
        }
        else
        {
            cmgr_res->stat = (kal_uint8)srv_sms_msg_status_to_at_status((srv_sms_status_enum)spdu_data->status);

            OslMfree(cmgr_cntx);

            srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGR_RES_REQ, cmgr_res, sim_id);
        }
    }
    else
    {
        cmgr_res->source_id = cmgr_cntx->source_id;
        cmgr_res->result = KAL_FALSE;
        cmgr_res->cause = callback_data->cause;

        OslMfree(cmgr_cntx);

        srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGR_RES_REQ, cmgr_res, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgr_update_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgr_update_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_at_cmgr_cntx_struct *cmgr_cntx;
    mmi_sms_atcmd_cmgr_res_req_struct *cmgr_res;
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGR_UPDATE_CALLBACK, callback_data->result);

    cmgr_cntx = (srv_sms_at_cmgr_cntx_struct*)callback_data->user_data;

    sim_id = cmgr_cntx->sim_id;
    cmgr_res = cmgr_cntx->cmgr_res;

    OslMfree(cmgr_cntx);

    srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGR_RES_REQ, cmgr_res, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgl_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgl_hldr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    mmi_sms_atcmd_cmgl_ind_struct *cmgl_ind = (mmi_sms_atcmd_cmgl_ind_struct*)in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGL_HLDR, sim_id);

    srv_sms_enter_at_cmd_operating();

    error_cause = srv_sms_at_check_common_error(cmgl_ind->mem);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_at_cmgl_cntx_struct *cmgl_cntx;
        sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

        cmgl_cntx = OslMalloc(sizeof(srv_sms_at_cmgl_cntx_struct));

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGL_HLDR_1, cmgl_ind->mem, cmgl_ind->stat);

        cmgl_cntx->source_id = cmgl_ind->source_id;
        cmgl_cntx->at_mem = cmgl_ind->mem;
        cmgl_cntx->at_status = cmgl_ind->stat;
        cmgl_cntx->sim_id = sim_id;
        cmgl_cntx->is_changed = (MMI_BOOL)cmgl_ind->esmss_mode;

        /* Set Listed Message's Status */
        if (cmgl_ind->stat != SMSAL_ALL)
        {
            cmgl_cntx->msg_status = srv_sms_at_status_to_msg_status(cmgl_ind->stat);

            if (cmgl_ind->stat == SMSAL_STO_UNSENT)
            {
                cmgl_cntx->msg_status |= SRV_SMS_STATUS_DRAFT;
            }
        }

        cmgl_cntx->curr_index = 0;
        cmgl_cntx->is_mt = MMI_FALSE;

        /* If the at memory is MT, read ME SMS first */
        switch (cmgl_cntx->at_mem)
        {
            case SMSAL_SM:
            {
                U32 index;

                index = srv_sms_sim_id_to_sim_index(sim_id);

                cmgl_cntx->pdu_id = srv_sms_sim_record_index_to_pdu_id(0, sim_id);
                cmgl_cntx->total_num = memory_status->sim_total[index];
                break;
            }

            case SMSAL_ME:
            case SMSAL_MT:
            {
                cmgl_cntx->pdu_id = srv_sms_me_record_index_to_pdu_id(0);
                cmgl_cntx->total_num = memory_status->me_total;

                if (cmgl_cntx->at_mem == SMSAL_MT)
                {
                    cmgl_cntx->is_mt = MMI_TRUE;
                }
                break;
            }

            default:
            {
                MMI_ASSERT(0);
                break;
            }
        }
        in_atcm_cmgl ++;
        srv_sms_at_cmgl_read_pdu(cmgl_cntx);
    }
    else
    {
        mmi_sms_atcmd_cmgl_res_req_struct *cmgl_res;

        cmgl_res = (mmi_sms_atcmd_cmgl_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgl_res_req_struct));

        cmgl_res->source_id = cmgl_ind->source_id;
        cmgl_res->is_complete = KAL_TRUE;
        cmgl_res->result = KAL_FALSE;
        cmgl_res->cause = error_cause;
        in_atcm_cmgl --;
        srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGL_RES_REQ, cmgl_res, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgl_read_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgl_read_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_at_cmgl_cntx_struct *cmgl_cntx;
    MMI_BOOL is_update = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGL_READ_CALLBACK, callback_data->result);

    cmgl_cntx = (srv_sms_at_cmgl_cntx_struct*)callback_data->user_data;

    if (callback_data->result == MMI_TRUE)
    {
        mmi_sms_atcmd_cmgl_res_req_struct *cmgl_res;
        srv_sms_read_pdu_cb_struct *read_cb_data;
        srv_sms_spdu_struct *spdu_data;

        cmgl_res = (mmi_sms_atcmd_cmgl_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgl_res_req_struct));

        read_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;
        spdu_data = read_cb_data->spdu_data;

        cmgl_res->source_id = cmgl_cntx->source_id;
        cmgl_res->result = KAL_TRUE;
        cmgl_res->cause = SRV_SMS_CAUSE_NO_ERROR;
        cmgl_res->mem = cmgl_cntx->at_mem;

        cmgl_res->index = srv_sms_at_pdu_id_to_index(
                            cmgl_cntx->pdu_id,
                            cmgl_cntx->at_mem,
                            cmgl_cntx->sim_id);

        cmgl_res->stat = srv_sms_msg_status_to_at_status((srv_sms_status_enum)spdu_data->status);
        cmgl_res->pdu_length = SRV_SMS_MAX_PDU_SIZE;
        memcpy(cmgl_res->pdu, read_cb_data->spdu_data->pdu, SRV_SMS_MAX_PDU_SIZE);

        cmgl_res->is_complete = KAL_FALSE;

        if ((cmgl_cntx->is_changed) && (spdu_data->status == SRV_SMS_STATUS_UNREAD))
        {
            is_update = MMI_TRUE;

            cmgl_cntx->cmgl_res = cmgl_res;

            spdu_data->status = SRV_SMS_STATUS_READ;

            srv_sms_msg_update_pdu(
                cmgl_cntx->pdu_id,
                spdu_data,
                srv_sms_at_cmgl_update_callback,
                cmgl_cntx);

            spdu_data->status = SRV_SMS_STATUS_UNREAD;
        }
        else
        {
            cmgl_res->stat = (kal_uint8)srv_sms_msg_status_to_at_status((srv_sms_status_enum)spdu_data->status);

            /* Can't use srv_sms_at_send_message, because it will decrement the at_op_count;
             * the at_op_count should be decremented when this operation is finished */
            srv_sms_disp_send_msg_req(MSG_ID_MMI_SMS_ATCMD_CMGL_RES_REQ, cmgl_cntx->sim_id, cmgl_res);
        }
    }

    if (is_update == MMI_FALSE)
    {
        cmgl_cntx->curr_index++;
        cmgl_cntx->pdu_id++;

        srv_sms_at_cmgl_read_pdu(cmgl_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgl_update_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgl_update_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_at_cmgl_cntx_struct *cmgl_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGL_UPDATE_CALLBACK, callback_data->result);

    cmgl_cntx = (srv_sms_at_cmgl_cntx_struct*)callback_data->user_data;

    /* Can't use srv_sms_at_send_message, because it will decrement the at_op_count;
     * the at_op_count should be decremented when this operation is finished */
    srv_sms_disp_send_msg_req(MSG_ID_MMI_SMS_ATCMD_CMGL_RES_REQ, cmgl_cntx->sim_id, cmgl_cntx->cmgl_res);

    cmgl_cntx->curr_index++;
    cmgl_cntx->pdu_id++;

    srv_sms_at_cmgl_read_pdu(cmgl_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgl_read_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgl_read_pdu(srv_sms_at_cmgl_cntx_struct* cmgl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGL_READ_PDU, cmgl_cntx->is_mt);

    srv_sms_at_cmgl_set_next_read_index(cmgl_cntx);

    if (cmgl_cntx->curr_index < cmgl_cntx->total_num)
    {
        srv_sms_read_pdu(
            cmgl_cntx->pdu_id,
            srv_sms_at_cmgl_read_callback,
            cmgl_cntx);
    }
    else
    {
        if (cmgl_cntx->is_mt == MMI_TRUE)
        {
            sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
            U32 index;

            index = srv_sms_sim_id_to_sim_index(cmgl_cntx->sim_id);

            cmgl_cntx->pdu_id = srv_sms_sim_record_index_to_pdu_id(0, cmgl_cntx->sim_id);
            cmgl_cntx->total_num = memory_status->sim_total[index];

            cmgl_cntx->curr_index = 0;

            cmgl_cntx->is_mt = MMI_FALSE;

            srv_sms_at_cmgl_read_pdu(cmgl_cntx);
        }
        else
        {
            in_atcm_cmgl --;
            srv_sms_at_cmgl_read_finish(cmgl_cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgl_set_next_read_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgl_set_next_read_index(srv_sms_at_cmgl_cntx_struct* cmgl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cmgl_cntx->at_status == SMSAL_ALL)
    {
        while (cmgl_cntx->curr_index < cmgl_cntx->total_num)
        {
            if (srv_sms_is_pdu_exist(cmgl_cntx->pdu_id) == MMI_TRUE)
            {
                break;
            }

            cmgl_cntx->curr_index++;
            cmgl_cntx->pdu_id++;
        }
    }
    else
    {        
        while (cmgl_cntx->curr_index < cmgl_cntx->total_num)
        {
            if (srv_sms_is_pdu_exist(cmgl_cntx->pdu_id) == MMI_TRUE)
            {
                srv_sms_status_enum status;

                status = srv_sms_get_pdu_status(cmgl_cntx->pdu_id);

                if (status & cmgl_cntx->msg_status)
                {
                    break;
                }
            }
        
            cmgl_cntx->curr_index++;
            cmgl_cntx->pdu_id++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgl_read_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgl_read_finish(srv_sms_at_cmgl_cntx_struct* cmgl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_atcmd_cmgl_res_req_struct *cmgl_res;
    srv_sms_sim_enum sim_id = cmgl_cntx->sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGL_READ_FINISH);

    cmgl_res = (mmi_sms_atcmd_cmgl_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgl_res_req_struct));

    cmgl_res->source_id = cmgl_cntx->source_id;
    cmgl_res->result = KAL_TRUE;
    cmgl_res->cause = SRV_SMS_CAUSE_NO_ERROR;
    cmgl_res->is_complete = KAL_TRUE;

    OslMfree(cmgl_cntx);

    srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGL_RES_REQ, cmgl_res, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgd_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgd_hldr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    mmi_sms_atcmd_cmgd_ind_struct *cmgd_ind = (mmi_sms_atcmd_cmgd_ind_struct*)in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGD_HLDR, sim_id);

    srv_sms_enter_at_cmd_operating();

    error_cause = srv_sms_at_check_common_error(cmgd_ind->mem);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_at_cmgd_cntx_struct *cmgd_cntx;

        cmgd_cntx = OslMalloc(sizeof(srv_sms_at_cmgd_cntx_struct));

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGD_HLDR_1, cmgd_ind->mem, cmgd_ind->delflag, cmgd_ind->index);

        cmgd_cntx->source_id = cmgd_ind->source_id;
        cmgd_cntx->at_mem = cmgd_ind->mem;
        cmgd_cntx->del_flag = cmgd_ind->delflag;
        cmgd_cntx->msg_status = SRV_SMS_STATUS_NONE;
        cmgd_cntx->sim_id = sim_id;

        switch (cmgd_ind->delflag)
        {
            case DEL_FLAG_INDEX:
            {
                U16 pdu_id;

                pdu_id = srv_sms_at_index_to_pdu_id((U16)cmgd_ind->index, cmgd_ind->mem, sim_id);
        
                srv_sms_msg_delete_pdu(
                    pdu_id,
                    srv_sms_at_cmgd_delete_callback,
                    cmgd_cntx);
                break;
            }

            case DEL_FLAG_PREFER_READ:
            case DEL_FLAG_PREFER_READ_SENT:
            case DEL_FLAG_PREFER_READ_SEND_UNSENT:
            case DEL_FLAG_PREFER_ALL:
            {
                sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

                switch (cmgd_cntx->del_flag)
                {
                    case DEL_FLAG_PREFER_READ:
                        cmgd_cntx->msg_status = SRV_SMS_STATUS_READ;
                        break;

                    case DEL_FLAG_PREFER_READ_SENT:
                        cmgd_cntx->msg_status = (srv_sms_status_enum)(SRV_SMS_STATUS_READ | SRV_SMS_STATUS_SENT);
                        break;

                    case DEL_FLAG_PREFER_READ_SEND_UNSENT:
                        cmgd_cntx->msg_status = (srv_sms_status_enum)(SRV_SMS_STATUS_READ | SRV_SMS_STATUS_SENT | SRV_SMS_STATUS_UNSENT | SRV_SMS_STATUS_DRAFT);
                        break;

                    case DEL_FLAG_PREFER_ALL:
                        break;

                    default:
                        MMI_ASSERT(0);
                        break;
                }

                cmgd_cntx->curr_index = 0;
                cmgd_cntx->is_mt = MMI_FALSE;

                switch (cmgd_cntx->at_mem)
                {
                    case SMSAL_SM:
                    {
                        U32 index;

                        index = srv_sms_sim_id_to_sim_index(sim_id);

                        cmgd_cntx->pdu_id = srv_sms_sim_record_index_to_pdu_id(0, sim_id);
                        cmgd_cntx->total_num = memory_status->sim_total[index];
                        break;
                    }

                    case SMSAL_ME:
                    case SMSAL_MT:
                    {
                        cmgd_cntx->pdu_id = srv_sms_me_record_index_to_pdu_id(0);
                        cmgd_cntx->total_num = memory_status->me_total;

                        if (cmgd_cntx->at_mem == SMSAL_MT)
                        {
                            cmgd_cntx->is_mt = MMI_TRUE;
                        }
                        break;
                    }

                    default:
                    {
                        MMI_ASSERT(0);
                        break;
                    }
                }
                in_atcm_delete ++;
                srv_sms_at_cmgd_delete_multi(cmgd_cntx);
                break;
            }

            default:
            {
                mmi_sms_atcmd_cmgd_res_req_struct *cmgd_res;

                OslMfree(cmgd_cntx);

                cmgd_res = (mmi_sms_atcmd_cmgd_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgd_res_req_struct));

                cmgd_res->source_id = cmgd_ind->source_id;
                cmgd_res->result = KAL_FALSE;
                cmgd_res->cause = SRV_SMS_CAUSE_INVALID_TEXT_PARA;

                srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGD_RES_REQ, cmgd_res, sim_id);
                break;
            }
        }
    }
    else
    {
        mmi_sms_atcmd_cmgd_res_req_struct *cmgd_res;

        cmgd_res = (mmi_sms_atcmd_cmgd_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgd_res_req_struct));

        cmgd_res->source_id = cmgd_ind->source_id;
        cmgd_res->result = KAL_FALSE;
        cmgd_res->cause = error_cause;

        srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGD_RES_REQ, cmgd_res, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgd_delete_multi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgd_delete_multi(srv_sms_at_cmgd_cntx_struct *cmgd_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGD_DELETE_MULTI, cmgd_cntx->curr_index);

    srv_sms_at_cmgd_set_next_del_index(cmgd_cntx);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGD_DELETE_MULTI_1, cmgd_cntx->curr_index);

    if (cmgd_cntx->curr_index < cmgd_cntx->total_num)
    {
        srv_sms_msg_delete_pdu(
            cmgd_cntx->pdu_id,
            srv_sms_at_cmgd_del_multi_callback,
            cmgd_cntx);
    }
    else
    {
        if (cmgd_cntx->is_mt == MMI_TRUE)
        {
            sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
            U32 index;

            index = srv_sms_sim_id_to_sim_index(cmgd_cntx->sim_id);

            cmgd_cntx->pdu_id = srv_sms_sim_record_index_to_pdu_id(0, cmgd_cntx->sim_id);
            cmgd_cntx->total_num = memory_status->sim_total[index];

            cmgd_cntx->curr_index = 0;
            cmgd_cntx->is_mt = MMI_FALSE;

            srv_sms_at_cmgd_delete_multi(cmgd_cntx);
        }
        else
        {
            in_atcm_delete--;
            srv_sms_at_send_msg(cmgd_cntx, MMI_TRUE ,SRV_SMS_CAUSE_NO_ERROR);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgd_set_next_del_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgd_set_next_del_index(srv_sms_at_cmgd_cntx_struct *cmgd_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cmgd_cntx->del_flag == DEL_FLAG_PREFER_ALL)
    {
        while (cmgd_cntx->curr_index < cmgd_cntx->total_num)
        {
            if (srv_sms_is_pdu_exist(cmgd_cntx->pdu_id) == MMI_TRUE)
            {
                break;
            }

            cmgd_cntx->curr_index++;
            cmgd_cntx->pdu_id++;
        }
    }
    else
    {
        while (cmgd_cntx->curr_index < cmgd_cntx->total_num)
        {
            if (srv_sms_is_pdu_exist(cmgd_cntx->pdu_id) == MMI_TRUE)
            {
                srv_sms_status_enum curr_status;

                curr_status = srv_sms_get_pdu_status(cmgd_cntx->pdu_id);

                if (curr_status & cmgd_cntx->msg_status)
                {
                    break;
                }
            }

            cmgd_cntx->curr_index++;
            cmgd_cntx->pdu_id++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgd_delete_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgd_delete_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_at_cmgd_cntx_struct *cmgd_cntx;
    mmi_sms_atcmd_cmgd_res_req_struct *cmgd_res;
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGD_DELETE_CALLBACK, callback_data->result);

    cmgd_cntx = (srv_sms_at_cmgd_cntx_struct*)callback_data->user_data;

    sim_id = cmgd_cntx->sim_id;

    cmgd_res = (mmi_sms_atcmd_cmgd_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgd_res_req_struct));

    cmgd_res->source_id = cmgd_cntx->source_id;

    if (callback_data->result == MMI_TRUE)
    {
        cmgd_res->result = KAL_TRUE;
        cmgd_res->cause = SRV_SMS_CAUSE_NO_ERROR;
    }
    else
    {
        cmgd_res->result = KAL_FALSE;
        cmgd_res->cause = callback_data->cause;
    }

    OslMfree(cmgd_cntx);

    srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGD_RES_REQ, cmgd_res, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgd_del_multi_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
 //06.11 slim
static void srv_sms_at_cmgd_del_multi_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_at_cmgd_cntx_struct *cmgd_cntx;
    srv_sms_cause_enum cause;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGD_DEL_MULTI_CALLBACK, callback_data->result);

    cmgd_cntx = (srv_sms_at_cmgd_cntx_struct*)callback_data->user_data;
    cause = callback_data->cause;
    if (callback_data->result == MMI_TRUE)
    {
        cmgd_cntx->curr_index++;
        cmgd_cntx->pdu_id++;

        srv_sms_at_cmgd_delete_multi(cmgd_cntx);
    }
    else
    {
        in_atcm_delete--;
        srv_sms_at_send_msg(cmgd_cntx, MMI_FALSE ,cause);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgw_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgw_hldr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    mmi_sms_atcmd_cmgw_ind_struct *cmgw_ind = (mmi_sms_atcmd_cmgw_ind_struct*)in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGW_HLDR, sim_id);

    srv_sms_enter_at_cmd_operating();

    error_cause = srv_sms_at_check_common_error(cmgw_ind->mem);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_at_cmgw_cntx_struct *cmgw_cntx;
        srv_sms_msg_add_pdu_struct add_pdu_data;

        cmgw_cntx = OslMalloc(sizeof(srv_sms_at_cmgw_cntx_struct));

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGW_HLDR_1, cmgw_ind->mem, cmgw_ind->stat);

        cmgw_cntx->source_id = cmgw_ind->source_id;
        cmgw_cntx->at_mem = cmgw_ind->mem;
        cmgw_cntx->sim_id = sim_id;

        /* Fill the add pdu Data */
        add_pdu_data.status = srv_sms_at_status_to_msg_status(cmgw_ind->stat);
        add_pdu_data.pdu_raw_data = cmgw_ind->pdu;
        add_pdu_data.raw_data_size = (U8)cmgw_ind->pdu_length;
        add_pdu_data.storage_type = srv_sms_at_mem_to_storage_type(cmgw_ind->mem);
        add_pdu_data.decode_data = NULL;
        add_pdu_data.sim_id = sim_id;
        add_pdu_data.is_hidden = MMI_FALSE;
        add_pdu_data.is_search_concat = MMI_TRUE;
        add_pdu_data.msg_id = SRV_SMS_INVALID_MSG_ID;
        srv_sms_msg_add_pdu(
            &add_pdu_data,
            srv_sms_at_cmgw_save_callback,
            cmgw_cntx);
    }
    else
    {
        mmi_sms_atcmd_cmgw_res_req_struct *cmgw_res;

        cmgw_res = (mmi_sms_atcmd_cmgw_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgw_res_req_struct));

        cmgw_res->source_id = cmgw_ind->source_id;
        cmgw_res->result = KAL_FALSE;
        cmgw_res->cause = error_cause;

        srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGW_RES_REQ, cmgw_res, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cmgw_save_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cmgw_save_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_at_cmgw_cntx_struct *cmgw_cntx;
    mmi_sms_atcmd_cmgw_res_req_struct *cmgw_res;
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CMGW_SAVE_CALLBACK, callback_data->result);

    cmgw_cntx = (srv_sms_at_cmgw_cntx_struct*)callback_data->user_data;

    sim_id = cmgw_cntx->sim_id;

    cmgw_res = (mmi_sms_atcmd_cmgw_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_cmgw_res_req_struct));

    cmgw_res->source_id = cmgw_cntx->source_id;

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_msg_add_pdu_cb_struct *add_msg_pdu_cb_data;

        add_msg_pdu_cb_data = (srv_sms_msg_add_pdu_cb_struct*)callback_data->action_data;

        cmgw_res->index = srv_sms_at_pdu_id_to_index(
                            add_msg_pdu_cb_data->pdu_id,
                            cmgw_cntx->at_mem,
                            cmgw_cntx->sim_id);

        cmgw_res->result = KAL_TRUE;
        cmgw_res->cause = SRV_SMS_CAUSE_NO_ERROR;
    }
    else
    {
        cmgw_res->result = KAL_FALSE;
        cmgw_res->cause = callback_data->cause;
    }

    OslMfree(cmgw_cntx);

    srv_sms_at_send_message(MSG_ID_MMI_SMS_ATCMD_CMGW_RES_REQ, cmgw_res, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_eqsi_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_eqsi_hldr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_atcmd_eqsi_ind_struct *eqsi_ind = (mmi_sms_atcmd_eqsi_ind_struct*)in_msg;
    mmi_sms_atcmd_eqsi_res_req_struct *eqsi_res;
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_EQSI_HLDR, sim_id);

    eqsi_res = (mmi_sms_atcmd_eqsi_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_atcmd_eqsi_res_req_struct));

    eqsi_res->begin = 0;

    eqsi_res->source_id = eqsi_ind->source_id;
    eqsi_res->mem = eqsi_ind->mem;

    switch (eqsi_ind->mem)
    {
        case RMMI_SMSAL_SM:
        {
            U32 index;

            index = srv_sms_sim_id_to_sim_index(sim_id);
        
            eqsi_res->end = memory_status->sim_total[index];
            eqsi_res->used = memory_status->sim_used[index];
            break;
        }
        
        case RMMI_SMSAL_ME:
        {
            eqsi_res->end = memory_status->me_total;
            eqsi_res->used = memory_status->me_used;
            break;
        }
    
        case RMMI_SMSAL_MT:
        default:
        {
            U32 index;

            eqsi_res->end = memory_status->me_total;
            eqsi_res->used = memory_status->me_used;            

            index = srv_sms_sim_id_to_sim_index(sim_id);

            eqsi_res->end += memory_status->sim_total[index];
            eqsi_res->used += memory_status->sim_used[index];
            break;            
        }
    }

    if (eqsi_res->end > 0)
    {
        eqsi_res->end--;
    }

    srv_sms_disp_send_msg_req(MSG_ID_MMI_SMS_ATCMD_EQSI_RES_REQ, sim_id, eqsi_res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_cgsms_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_cgsms_hldr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CGSMS_HLDR, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_csas_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_csas_hldr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CSAS_HLDR, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_check_common_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_at_check_common_error(U8 at_mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CHECK_COMMON_ERROR, storage_cntx.is_ready);

    if (storage_cntx.is_ready == MMI_FALSE)
    {
        error_cause = SRV_SMS_CAUSE_NOT_READY;
    }
    else if (srv_sms_is_in_mmi_operating() == MMI_TRUE)
    {
        error_cause = SRV_SMS_CAUSE_OP_NOT_ALLOWED;
    }
    else if (srv_sms_at_is_mem_valid(at_mem) == MMI_FALSE)
    {
        error_cause = SRV_SMS_CAUSE_INVALID_PDU_PARA;
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_NO_ERROR;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_CHECK_COMMON_ERROR_1, error_cause);

    return error_cause;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_is_mem_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_at_is_mem_valid(U8 at_men)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((at_men == SMSAL_ME) || (at_men == SMSAL_SM) || (at_men == SMSAL_MT))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_at_send_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_at_send_message(U16 msg_id, void* local_ptr, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_AT_SEND_MESSAGE);

    srv_sms_exit_at_cmd_operating();

    srv_sms_disp_send_msg_req(msg_id, sim_id, local_ptr);
}
#endif /* (defined( __MOD_SMSAL__ ) && defined(__SRV_SMS_AT_SUPPORT__)) */
