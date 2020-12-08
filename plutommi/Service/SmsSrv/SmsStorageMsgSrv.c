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
 *  SmsStorageManagerSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage Manager core codes
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
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "DateTimeType.h"
#include "app_datetime.h"

#include "mmi_common_app_trc.h"
#include "mmi_msg_struct.h"
#include "ProtocolEvents.h"
#include "mmi_msg_context.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsStorageSrv.h"
#include "SmsConverterSrv.h"
#include "SmsStorageCoreSrv.h"
#include "SmsUtilSrv.h"
#include "SmsDispatchSrv.h"
#include "sim_common_enums.h"
#include "ps_public_enum.h"
#include "SimCtrlSrvGprot.h"
#ifdef __SRV_SMS_SIM_CUST_DATA__
#include "SmsStorageSimCustSrv.h"
#endif /* __SRV_SMS_SIM_CUST_DATA__ */
#include "SimAccessSrvGprot.h"
#include "BootupSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "SatSrvGprot.h"


/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_MAX_SPDU_MULTI_AMOUNT   (SRV_SMS_MAX_BUFF_SIZE / SRV_SMS_MAX_SPDU_SIZE)
#ifdef __SRV_SMS_MULTI_ADDR__
#define SMS_STO_STATE_ME_INIT_DONE      (SMS_STO_STATE_LOAD_PDU_DONE | SMS_STO_STATE_LOAD_ADDR_DONE)
#else /* __SRV_SMS_MULTI_ADDR__ */
#define SMS_STO_STATE_ME_INIT_DONE      (SMS_STO_STATE_LOAD_PDU_DONE)
#endif /* __SRV_SMS_MULTI_ADDR__ */


/**************************************************************
* Structure Declaration
**************************************************************/
typedef enum
{
    SMS_STO_STATE_NONE              = 0x0000,
    SMS_STO_STATE_STARTUP_IND       = 0x0001,
    /* flag of whether the gotten number is real SIM SMS record number,
     * this flag is set only when the SIM card have been valid once */
    SMS_STO_STATE_REAL_NUM          = 0x0002,
    /* flag of whether it is in getting number state */
    SMS_STO_STATE_GETTING_NUM       = 0x0004,
    /* flag of whether continue to load SMS */
    SMS_STO_STATE_LOADING           = 0x0008,
    /* flag of whether remove the loaded SMS, and reload again */
    SMS_STO_STATE_RELOAD            = 0x0010,
    SMS_STO_STATE_GET_NUM_DONE      = 0x0020,
    SMS_STO_STATE_INIT_DONE         = 0x0040,
    SMS_STO_STATE_SEND_RES          = 0x0080,
    SMS_STO_STATE_LOAD_PDU_DONE     = 0x0100,
    SMS_STO_STATE_LOAD_ADDR_DONE    = 0x0200
} sms_storage_state_enum;

typedef struct
{
    U32 sim_index;
    U16 curr_index;
    U16 total;
} sms_init_sim_struct;

typedef struct
{
    U16 curr_index;
    U16 total;
    U16 remain;
} sms_init_me_struct;

typedef struct
{
    U16 curr_index;
    U16 total_num;
    srv_sms_sim_enum sim_id;
} sms_sim_refresh_cntx_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    sms_init_me_struct *me_cntx;
} srv_sms_evt_startup_read_me_sms_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/ 

MMI_BOOL is_in_sim_refresh[SMS_SIM_NUM];
/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static sms_storage_state_enum sms_sim_sto_flag[SMS_SIM_NUM];
static sms_storage_state_enum sms_me_sto_flag;


/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_read_ind_hdlr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_get_mem_status_ind_hdlr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_sms_startup_get_sim_num(srv_sms_sim_enum sim_id);
static void srv_sms_startup_get_sim_num_callback(srv_sim_cb_struct* callback_data);
static void srv_sms_startup_get_num_done_hdlr(void);
static void srv_sms_startup_read_sim_sms(U16 total_num, srv_sms_sim_enum sim_id);
static void srv_sms_startup_read_sim_sms_hdlr(sms_init_sim_struct *sim_cntx, srv_sms_sim_enum sim_id);
static void srv_sms_startup_read_sim_sms_callback(srv_sms_callback_struct* callback_data);
static void srv_sms_startup_read_me_sms(U16 total_num);
static void srv_sms_startup_read_me_sms_hdlr(sms_init_me_struct *me_cntx);
static void srv_sms_startup_read_me_sms_callback(srv_sms_callback_struct* callback_data);
#ifdef __SRV_SMS_MULTI_ADDR__
static void srv_sms_startup_load_addr_callback(srv_sms_callback_struct *callback_data);
#endif /* __SRV_SMS_MULTI_ADDR__ */
static void srv_sms_startup_init_me_done_hdlr(void);
static void srv_sms_startup_init_done_hdlr(void);
static void srv_sms_startup_set_memory_status(sms_memory_status_struct *memory_status);

static void srv_sms_startup_add_sim_msg_node(
                U16 pdu_id,
                U16 record_index,
                srv_sms_sim_enum sim_id,
                srv_sms_spdu_struct *spdu_data);

static U16 srv_sms_startup_add_msg_node(
            U16 pdu_id,
            srv_sms_spdu_struct *spdu_data,
            srv_sms_status_enum status,
            srv_sms_storage_enum storage_type);

static void srv_sms_startup_remove_pdu_node(U16 pdu_id);
static void srv_sms_startup_send_startup_res(MMI_BOOL result);
static MMI_BOOL srv_sms_startup_is_init_done(void);
static MMI_BOOL srv_sms_startup_is_get_num_done(void);
static void srv_sms_startup_reload_sim_sms(srv_sms_sim_enum sim_id);
static void srv_sms_startup_remove_all_sim_sms(srv_sms_sim_enum sim_id);
static void srv_sms_startup_ready_change_hdlr(MMI_BOOL is_ready);
static void srv_sms_startup_set_memory_status_int(sms_memory_status_struct *memory_status, U16 remain_space);
static void srv_sms_sim_refresh_event_hdlr_int(srv_sat_sim_refresh_event_struct *event_data);


/**************************************************************
* Function Defination
**************************************************************/
static MMI_BOOL srv_sms_startup_get_result(sms_storage_state_enum state)
{
	U32 i;
	MMI_BOOL result = MMI_TRUE;
	for (i = 0; i < SMS_SIM_NUM; i++)
	{		   
		if (!(sms_sim_sto_flag[i] & state))
		{
            result = MMI_FALSE;
            break;
		}
	}
	return result;
}


static void srv_sms_startup_set_memory_status_int(sms_memory_status_struct *memory_status, U16 remain_space)
{
    U32 i;
	for (i = 0; i < SMS_SIM_NUM; i++)
	{
		if (memory_status->sim_total[i] < SRV_SMS_MAX_SIM_SMS_ENTRY)
		{
		    remain_space += (SRV_SMS_MAX_SIM_SMS_ENTRY - memory_status->sim_total[i]);
		}
	}
	for (i = 0; i < SMS_SIM_NUM; i++)
	{
		if (memory_status->sim_total[i] > SRV_SMS_MAX_SIM_SMS_ENTRY)
		{
			if (remain_space > 0)
			{
				if (memory_status->sim_total[i] < (SRV_SMS_MAX_SIM_SMS_ENTRY + remain_space))
				{
					remain_space = (SRV_SMS_MAX_SIM_SMS_ENTRY + remain_space) - memory_status->sim_total[i];
				}
				else
				{
					memory_status->sim_total[i] = SRV_SMS_MAX_SIM_SMS_ENTRY + remain_space;
					remain_space = 0;
				}
			}
			else
			{
				memory_status->sim_total[i] = SRV_SMS_MAX_SIM_SMS_ENTRY;
			}
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_storage_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_storage_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STORAGE_INIT);
    srv_sms_storage_reset_data();

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        sms_sim_sto_flag[i] = SMS_STO_STATE_NONE;
    }

    sms_me_sto_flag = SMS_STO_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_storage_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sms_storage_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_sms_disp_struct *event_data = (mmi_evt_sms_disp_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STORAGE_EVENT_PROC, event_data->msg_id);

    switch (event_data->msg_id)
    {
        case PTR_MSG_ID_SRV_SMS_STARTUP_READ_IND:
            srv_sms_read_ind_hdlr(event_data->data, (srv_sms_sim_enum)event_data->sim_id);
            break;

        case PTR_MSG_ID_SRV_SMS_GET_MEM_STATUS_IND:
            srv_sms_get_mem_status_ind_hdlr(event_data->data, (srv_sms_sim_enum)event_data->sim_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_read_ind_hdlr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_startup_read_ind_struct *read_ind = (mmi_sms_startup_read_ind_struct*)in_msg;
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_IND_HDLR, sim_id, sms_sim_sto_flag[index]);

    if (!sms_sim_sto_flag[index])
    {
        sms_sim_sto_flag[index] = SMS_STO_STATE_STARTUP_IND;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_IND_HDLR_1, read_ind->sim_status);

        if (read_ind->sim_status == L4C_SIM_INSERTED)
        {
            memory_status->is_sim_valid[index] = MMI_TRUE;

            srv_sms_startup_get_sim_num(sim_id);
        }
        else
        {
        #ifdef __SRV_SMS_SIM_CUST_DATA__
            U8 imsi_num[SRV_SMS_IMSI_LEN];
        #endif /* __SRV_SMS_SIM_CUST_DATA__ */

            memory_status->sim_total[index] = 0;
            memory_status->is_sim_valid[index] = MMI_FALSE;

        #ifdef __SRV_SMS_SIM_CUST_DATA__
            imsi_num[0] = '\0';
            srv_sms_set_sim_cust_cntx(0, imsi_num, sim_id);
        #endif /* __SRV_SMS_SIM_CUST_DATA__ */

            sms_sim_sto_flag[index] |= SMS_STO_STATE_GET_NUM_DONE;

            srv_sms_startup_get_num_done_hdlr();
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_IND_HDLR_2, sms_me_sto_flag);

    if (!sms_me_sto_flag)
    {
        sms_me_sto_flag = SMS_STO_STATE_STARTUP_IND;

#ifndef __SRV_SMS_SIM_MEMORY_BASE__
        /* Need to Set ME Total first for add PDU node when the read ME SMS */
        memory_status->me_total = SRV_SMS_MAX_ME_SMS_ENTRY;
        srv_sms_startup_read_me_sms(SRV_SMS_MAX_ME_SMS_ENTRY);
#endif /* __SRV_SMS_SIM_MEMORY_BASE__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    srv_sms_load_ext_addr(srv_sms_startup_load_addr_callback, NULL);
#endif /* __SRV_SMS_MULTI_ADDR__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mem_status_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_mem_status_ind_hdlr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_mem_status_ind_struct *get_mem_ind = (mmi_sms_get_mem_status_ind_struct*)in_msg;
    mmi_sms_get_mem_status_res_req_struct *get_res_req;
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MEM_STATUS_IND_HDLR, sim_id);

    get_res_req = (mmi_sms_get_mem_status_res_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_get_mem_status_res_req_struct));

    index = srv_sms_sim_id_to_sim_index(sim_id);

    get_res_req->source_id = get_mem_ind->source_id;
    get_res_req->me_max_num = memory_status->me_total;
    get_res_req->me_current_num = memory_status->me_used;
    get_res_req->sim_max_num = memory_status->sim_total[index];
    get_res_req->sim_current_num = memory_status->sim_used[index];
    /* Not Supported Status Report Memory */
    get_res_req->sr_max_num = 0;
    get_res_req->sr_current_num = 0;

    srv_sms_disp_send_msg_req(MSG_ID_MMI_SMS_GET_MEM_STATUS_RES_REQ, sim_id, get_res_req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_refresh_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_refresh_event_hdlr_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/

static void srv_sms_sim_refresh_event_hdlr_int(srv_sat_sim_refresh_event_struct *event_data)
{
    
    srv_sms_event_sim_refresh_struct refresh_event_info;
    srv_sms_sim_enum sim_id = (srv_sms_sim_enum)(event_data->sim_id | MMI_GSM);
    U32 index;
    /* Exec SIM Refreshe Event */
    refresh_event_info.sim_id = sim_id;
    srv_sms_emit_event(EVT_ID_SRV_SMS_SIM_REFRESH, &refresh_event_info);
    index = srv_sms_sim_id_to_sim_index(sim_id);
    srv_sms_startup_ready_change_hdlr(MMI_FALSE);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_REFRESH_HDLR_1, sms_sim_sto_flag[index]);
    if (sms_sim_sto_flag[index] & SMS_STO_STATE_STARTUP_IND)
    {
        if (sms_sim_sto_flag[index] & SMS_STO_STATE_INIT_DONE) 
        {
            srv_sms_startup_reload_sim_sms(sim_id);
        }
        else
        {
            if (sms_sim_sto_flag[index] & SMS_STO_STATE_LOADING)
            {
                sms_sim_sto_flag[index] |= SMS_STO_STATE_RELOAD;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_refresh_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sms_sim_refresh_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_sat_sim_refresh_event_struct *event_data = (srv_sat_sim_refresh_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MEM_STATUS_IND_HDLR, event_data->sim_id);
    if(event_data->full_change)
    {
        srv_sms_sim_refresh_event_hdlr_int(event_data);
    }
    else if (event_data->refresh_type == SRV_SAT_REFRESH_FILE_CHANGE)
    {
        for (i = 0; i < event_data->num_of_file; i++)
        {
            if (event_data->file_list[i] == FILE_SMS_IDX)
            {
                srv_sms_sim_refresh_event_hdlr_int(event_data);
                break;
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_status_changed_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sms_sim_status_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *event_data = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    sms_storage_state_enum curr_sim_sto_flag;
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_STATUS_CHANGED_HDLR, event_data->sim, event_data->is_available_before, event_data->is_available_now);

#if (MMI_MAX_SIM_NUM >= 2)
    if (event_data->sim == MMI_SIM2)
    {
        sim_id = SRV_SMS_SIM_2;
        index = 1;
    }
#if (MMI_MAX_SIM_NUM >= 3)    
    else if (event_data->sim == MMI_SIM3)
    {
        sim_id = SRV_SMS_SIM_3;
        index = 2;
    }
#endif    
#if (MMI_MAX_SIM_NUM >= 4)    
    else if (event_data->sim == MMI_SIM4)
    {
        sim_id = SRV_SMS_SIM_4;
        index = 3;
    }    
#endif
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
    curr_sim_sto_flag = sms_sim_sto_flag[index];

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_STATUS_CHANGED_HDLR_1, curr_sim_sto_flag);

    if ((!srv_bootup_is_booting()) &&
        (curr_sim_sto_flag & SMS_STO_STATE_STARTUP_IND) &&
        (event_data->is_available_before != event_data->is_available_now))
    {
        sms_storage_state_enum reset_flag;

        memory_status->is_sim_valid[index] = event_data->is_available_now;

        /* Available --> Not Available */
        if (event_data->is_available_before)
        {
            MMI_BOOL is_removed = MMI_FALSE;

            reset_flag = (sms_storage_state_enum)(SMS_STO_STATE_LOADING | SMS_STO_STATE_GETTING_NUM |
                                                 SMS_STO_STATE_RELOAD);

            /* If the SIM card is removed, need to Clear */
            if (event_data->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
            {
                reset_flag |= SMS_STO_STATE_REAL_NUM;
                is_removed = MMI_TRUE;
            }

            sms_sim_sto_flag[index] &= (~reset_flag);

            if (curr_sim_sto_flag & SMS_STO_STATE_INIT_DONE)
            {
                srv_sms_startup_ready_change_hdlr(MMI_FALSE);
                srv_sms_startup_remove_all_sim_sms(sim_id);

                if (is_removed)
                {
                    memory_status->sim_total[index] = 0;
                    memory_status->sim_used[index] = 0;
                }

                srv_sms_startup_ready_change_hdlr(MMI_TRUE);
            }
            else if (curr_sim_sto_flag & SMS_STO_STATE_LOADING)
            {
                /* If it is loading, don't need to continue */
                sms_sim_sto_flag[index] |= SMS_STO_STATE_INIT_DONE;
            }
        }
        else /* Not Available --> Available */
        {
            /* If it have gotten the SIM SMS record number, don't need to
             * count the range, only need to reload the SIM SMS;
             * Else, need to get the SIM SMS record number first,
             * then count the range again, and reload all ME and SIM SMS */
            is_in_sim_refresh[index] = MMI_TRUE;
            if (curr_sim_sto_flag & SMS_STO_STATE_REAL_NUM)
            {
                if (curr_sim_sto_flag & SMS_STO_STATE_INIT_DONE)
                {
                    srv_sms_startup_ready_change_hdlr(MMI_FALSE);

                    srv_sms_startup_reload_sim_sms(sim_id);
                }
            }
            else
            {
                sms_storage_state_enum reset_flag;
                U32 i;

                srv_sms_startup_ready_change_hdlr(MMI_FALSE);

                reset_flag = (sms_storage_state_enum)(SMS_STO_STATE_LOADING | SMS_STO_STATE_RELOAD |
                                                      SMS_STO_STATE_INIT_DONE | SMS_STO_STATE_GETTING_NUM |
                                                      SMS_STO_STATE_GET_NUM_DONE);

            #ifdef __SRV_SMS_SIM_MEMORY_BASE__
                curr_sim_sto_flag = sms_me_sto_flag;

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_STATUS_CHANGED_HDLR_2, curr_sim_sto_flag);

                sms_me_sto_flag &= ~reset_flag;

                /* if it is SIM memory based, need to recount the range of me memory,
                 * and reload me SMS, so, remove All ME SMS first */
                if (curr_sim_sto_flag & SMS_STO_STATE_INIT_DONE)
                {
                    U16 me_total;
                    U32 j;

                    me_total = memory_status->me_total;

                    for (j = 0; j < me_total; j++)
                    {
                        srv_sms_startup_remove_pdu_node(j);
                    }


                }
            #endif /* __SRV_SMS_SIM_MEMORY_BASE__ */

                /* Remove All SIM SMS */
                for (i = 0; i < SMS_SIM_NUM; i++)
                {
                    curr_sim_sto_flag = sms_sim_sto_flag[i];

                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_STATUS_CHANGED_HDLR_3, i, curr_sim_sto_flag);

                    sms_sim_sto_flag[i] &= ~reset_flag;

                    if (curr_sim_sto_flag & SMS_STO_STATE_INIT_DONE)
                    {
                        srv_sms_sim_enum tmp_sim_id;

                        tmp_sim_id = srv_sms_sim_index_to_sim_id(i);

                        srv_sms_startup_remove_all_sim_sms(tmp_sim_id);
                    }
                }

                /* Get SIM SMS Record Number For Re-Count the range,
                 * and reload all ME and SIM SMS */
                for (i = 0; i < SMS_SIM_NUM; i++)
                {
                    if (sms_sim_sto_flag[i] & SMS_STO_STATE_STARTUP_IND)
                    {
                        srv_sms_sim_enum tmp_sim_id;

                        tmp_sim_id = srv_sms_sim_index_to_sim_id(i);

                        srv_sms_startup_get_sim_num(tmp_sim_id);
                    }
                }
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_get_sim_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_get_sim_num(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    mmi_sim_enum mmi_sim_id = (mmi_sim_enum)(sim_id & 0xFF);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_GET_SIM_NUM, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    /* If it is geting SIM SMS record number, and SIM card change to invalid,
     * we will dicard the result of geting SIM SMS record number */
    sms_sim_sto_flag[index] |= SMS_STO_STATE_GETTING_NUM;

    /* Get SIM SMS Record Number */
    srv_sim_get_file_info(
        FILE_SMS_IDX,
        NULL,
        mmi_sim_id,
        srv_sms_startup_get_sim_num_callback,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_get_sim_num_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_get_sim_num_callback(srv_sim_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_file_info_struct *file_info = (srv_sim_file_info_struct*)callback_data->data;
    srv_sms_sim_enum sim_id = (srv_sms_sim_enum)(callback_data->sim_id | MMI_GSM);
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U16 total_record;
    U32 index;
#ifdef __SRV_SMS_SIM_CUST_DATA__
    U8 imsi_num[SRV_SMS_IMSI_LEN];
#endif /* __SRV_SMS_SIM_CUST_DATA__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_GET_SIM_NUM_CALLBACK, sim_id, callback_data->cause, file_info->num_of_rec);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_GET_SIM_NUM_CALLBACK_1, sms_sim_sto_flag[index]);

    /* If the SIM card changes from avaliable to not validable in getting SIM SMS record,
     * Set it number to 0 */
    if ((sms_sim_sto_flag[index] & SMS_STO_STATE_GETTING_NUM) &&
        (callback_data->cause == SIM_CMD_SUCCESS))
    {
    #ifdef __SRV_SMS_SIM_CUST_DATA__
        MMI_BOOL result;
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */

        total_record = file_info->num_of_rec;

        sms_sim_sto_flag[index] |= SMS_STO_STATE_REAL_NUM;

    #ifdef __SRV_SMS_SIM_CUST_DATA__
        result = srv_sim_ctrl_get_imsi(
                    (mmi_sim_enum)(sim_id & 0x00FF),
                    (CHAR*)imsi_num,
                    SRV_SMS_IMSI_LEN);

        if (!result)
        {
            srv_sms_get_default_imsi(imsi_num, sim_id);
        }
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */
    }
    else
    {
        memory_status->is_sim_valid[index] = MMI_FALSE;

        total_record = 0;
    #ifdef __SRV_SMS_SIM_CUST_DATA__
        imsi_num[0] = '\0';
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */
    }

    /* Set Memory Status */
    memory_status->sim_total[index] = total_record;

#ifdef __SRV_SMS_SIM_CUST_DATA__
    srv_sms_set_sim_cust_cntx(total_record, imsi_num, sim_id);
#endif /* __SRV_SMS_SIM_CUST_DATA__ */

    sms_sim_sto_flag[index] &= (~SMS_STO_STATE_GETTING_NUM);
    sms_sim_sto_flag[index] |= SMS_STO_STATE_GET_NUM_DONE;

    srv_sms_startup_get_num_done_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_get_num_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_get_num_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_GET_NUM_DONE_HDLR);

    if (srv_sms_startup_is_get_num_done())
    {
        U32 i;
        srv_sms_sim_enum sim_id;
        sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

        /* Initialize SIM Card Customization Data */
    #ifdef __SRV_SMS_SIM_CUST_DATA__
        srv_sms_sim_cust_init();
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */

        srv_sms_startup_set_memory_status(memory_status);

        /* Read SIM Card SMS */
        for (i = 0; i < SMS_SIM_NUM; i++)
        {
            sim_id = srv_sms_sim_index_to_sim_id(i);

            srv_sms_startup_read_sim_sms(memory_status->sim_total[i], sim_id);
        }

        /* Read ME SMS if it is SIM Card Based */
    #ifdef __SRV_SMS_SIM_MEMORY_BASE__
        srv_sms_startup_read_me_sms(memory_status->me_total);
    #endif /* __SRV_SMS_SIM_MEMORY_BASE__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_read_sim_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_read_sim_sms(U16 total_num, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_init_sim_struct *sim_cntx;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_SIM_SMS, total_num, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    sim_cntx = OslMalloc(sizeof(sms_init_sim_struct));
    sim_cntx->curr_index = 0;
    sim_cntx->total = total_num;
    sim_cntx->sim_index = index;

    sms_sim_sto_flag[index] |= SMS_STO_STATE_LOADING;

    srv_sms_startup_read_sim_sms_hdlr(sim_cntx, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_read_sim_sms_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_read_sim_sms_hdlr(sms_init_sim_struct *sim_cntx, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_SIM_SMS_HDLR, sim_id, sim_cntx->curr_index);

    if (sim_cntx->curr_index < sim_cntx->total)
    {
        srv_sms_read_sim_sms(
            sim_cntx->curr_index,
            sim_id,
            srv_sms_startup_read_sim_sms_callback,
            sim_cntx);
    }
    else
    {
        U32 index;

        OslMfree(sim_cntx);

        index = srv_sms_sim_id_to_sim_index(sim_id);

        sms_sim_sto_flag[index] &= (~SMS_STO_STATE_LOADING);
        sms_sim_sto_flag[index] |= SMS_STO_STATE_INIT_DONE;

        srv_sms_startup_init_done_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_read_sim_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_read_sim_sms_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_init_sim_struct *sim_cntx = (sms_init_sim_struct*)callback_data->user_data;
    srv_sms_spdu_struct *spdu_data;
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    spdu_data = (srv_sms_spdu_struct*)callback_data->action_data;
#if (MMI_MAX_SIM_NUM >= 2)
    sim_id = (srv_sms_sim_enum)spdu_data->sim_id;
#endif /*  (MMI_MAX_SIM_NUM >= 2) */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_SIM_SMS_CALLBACK, sim_id, sim_cntx->curr_index);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_SIM_SMS_CALLBACK_1, sms_sim_sto_flag[index]);

    if (sms_sim_sto_flag[index] & SMS_STO_STATE_LOADING)
    {
        if (sms_sim_sto_flag[index] & SMS_STO_STATE_RELOAD)
        {
            U16 start_pdu_id;
            U16 sim_total = sim_cntx->curr_index;
            U32 i;

            sms_sim_sto_flag[index] &= (~SMS_STO_STATE_RELOAD);

            start_pdu_id = srv_sms_sim_record_index_to_pdu_id(0, sim_id);

            for (i = start_pdu_id; i < (U32)(start_pdu_id + sim_total); i++)
            {
                srv_sms_startup_remove_pdu_node(i);
            }

            /* Reload again */
            sim_cntx->curr_index = 0;
        }
        else
        {
            U16 record_index = sim_cntx->curr_index;
            U16 pdu_id;

            sim_cntx->curr_index++;

            pdu_id = srv_sms_sim_record_index_to_pdu_id(record_index, sim_id);

            MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_SIM_SMS_CALLBACK_2, callback_data->result);

            if (callback_data->result)
            {
                srv_sms_startup_add_sim_msg_node(
                    pdu_id,
                    record_index,
                    sim_id,
                    spdu_data);
            }
            else
            {
                srv_sms_pdu_list[pdu_id].type = (SRV_SMS_NODE_INVALID | SRV_SMS_NODE_USED);

                /* Update Memory Status, if the record is invalid, consider it as USED */
                storage_cntx.memory_status.sim_used[index]++;
            }
        }

        srv_sms_startup_read_sim_sms_hdlr(sim_cntx, sim_id);
    }
    else
    {
        U16 sim_total;
        U16 start_pdu_id;
        U32 i;

        sim_total = sim_cntx->curr_index;

        OslMfree(sim_cntx);

        if (sim_total > 0)
        {
            start_pdu_id = srv_sms_sim_record_index_to_pdu_id(0, sim_id);

            for (i = start_pdu_id; i < (U32)(start_pdu_id + sim_total); i++)
            {
                srv_sms_startup_remove_pdu_node(i);
            }
        }

        /* If the SIM card is removed */
        if (!(sms_sim_sto_flag[index] & SMS_STO_STATE_REAL_NUM))
        {
            sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

            memory_status->sim_total[index] = 0;
            memory_status->sim_used[index] = 0;
        }

        srv_sms_startup_init_done_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_read_me_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_read_me_sms(U16 total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_init_me_struct *me_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_ME_SMS, total_num);

    me_cntx = OslMalloc(sizeof(sms_init_me_struct));

    me_cntx->total = total_num;
    me_cntx->remain = total_num;
    me_cntx->curr_index = 0;

    sms_me_sto_flag |= SMS_STO_STATE_LOADING;

    srv_sms_startup_read_me_sms_hdlr(me_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_read_me_sms_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_read_me_sms_hdlr(sms_init_me_struct *me_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_ME_SMS_HDLR, me_cntx->remain, me_cntx->curr_index);

    if (me_cntx->remain > 0)
    {
        //srv_sms_evt_startup_read_me_sms_struct post_evt;
        U16 start_record_index = me_cntx->curr_index + 1;
        U16 record_amount;
        void *buffer;
        U16 buffer_size;
        S16 error_code;
        S32 result;
        U32 i;
        U16 pdu_id = me_cntx->curr_index;

        if (me_cntx->remain > SRV_SMS_MAX_SPDU_MULTI_AMOUNT)
        {
            record_amount = SRV_SMS_MAX_SPDU_MULTI_AMOUNT;

            me_cntx->remain -= SRV_SMS_MAX_SPDU_MULTI_AMOUNT;
        }
        else
        {
            record_amount = me_cntx->remain;
            me_cntx->remain = 0;
        }
        me_cntx->curr_index += record_amount;

        buffer_size = sizeof(srv_sms_spdu_struct) * record_amount;

        buffer = OslMalloc(buffer_size);

        result = ReadMultiRecord(
                    NVRAM_EF_SRV_SMS_PDU_LID,
                    start_record_index,
                    buffer,
                    buffer_size,
                    record_amount,
                    &error_code);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_ME_SMS_HDLR_1, result, error_code);

        if (result > 0)
        {
            srv_sms_spdu_struct *spdu_data = (srv_sms_spdu_struct*)buffer;

            for (i = 0; i < record_amount; i++)
            {
                srv_sms_status_enum status;

                MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);

                status = srv_sms_spdu_status_to_msg_status(
                            spdu_data->status,
                            SRV_SMS_STORAGE_ME);

                if (status != SRV_SMS_STATUS_NONE)
                {
                    srv_sms_startup_add_msg_node(
                        pdu_id,
                        spdu_data,
                        status,
                        SRV_SMS_STORAGE_ME);
                }

                pdu_id++;
                spdu_data++;
            }
        }
        else
        {
            for (i = 0; i < record_amount; i++)
            {
                MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);
                srv_sms_pdu_list[pdu_id++].type = (SRV_SMS_NODE_INVALID | SRV_SMS_NODE_USED);
            }

            /* Update Memory Status, if the records are invalid, consider them as USED */
            storage_cntx.memory_status.me_used += record_amount;
        }

        OslMfree(buffer);

        SRV_SMS_POST_CALLBACK(
            SRV_SMS_ACTION_READ,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            NULL,
            me_cntx,
            srv_sms_startup_read_me_sms_callback);
    }
    else
    {
        OslMfree(me_cntx);

        sms_me_sto_flag &= (~SMS_STO_STATE_LOADING);
        sms_me_sto_flag |= SMS_STO_STATE_LOAD_PDU_DONE;

        srv_sms_startup_init_me_done_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_read_me_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_read_me_sms_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_init_me_struct *me_cntx = (sms_init_me_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_ME_SMS_CALLBACK, sms_me_sto_flag);

    if (sms_me_sto_flag & SMS_STO_STATE_LOADING)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READ_ME_SMS_CALLBACK_1, me_cntx->curr_index);

        if (sms_me_sto_flag & SMS_STO_STATE_RELOAD)
        {
            U16 me_total = me_cntx->curr_index;
            U32 i;

            sms_me_sto_flag &= (~SMS_STO_STATE_RELOAD);

            for (i = 0; i < me_total; i++)
            {
                srv_sms_startup_remove_pdu_node(i);
            }

            /* Reload again */
            me_cntx->curr_index = 0;
            me_cntx->remain = me_cntx->total;
        }

        srv_sms_startup_read_me_sms_hdlr(me_cntx);
    }
    else
    {
        U16 me_total = me_cntx->curr_index;
        U32 i;

        OslMfree(me_cntx);

        for (i = 0; i < me_total; i++)
        {
            srv_sms_startup_remove_pdu_node(i);
        }

        srv_sms_startup_init_done_hdlr();
    }
}


#ifdef __SRV_SMS_MULTI_ADDR__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_load_ext_addr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_load_addr_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_me_sto_flag |= SMS_STO_STATE_LOAD_ADDR_DONE;

    srv_sms_startup_init_me_done_hdlr();
}
#endif /* __SRV_SMS_MULTI_ADDR__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_init_me_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_init_me_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((sms_me_sto_flag & SMS_STO_STATE_ME_INIT_DONE) == SMS_STO_STATE_ME_INIT_DONE)
    {
        sms_me_sto_flag |= SMS_STO_STATE_INIT_DONE;

    #ifdef __SRV_SMS_MULTI_ADDR__
        srv_sms_update_ext_addr_info();
    #endif /* __SRV_SMS_MULTI_ADDR__ */

        srv_sms_startup_init_done_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_init_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_init_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_INIT_DONE_HDLR);

    if (srv_sms_startup_is_init_done())
    {
        srv_sms_startup_send_startup_res(MMI_TRUE);        

        srv_sms_startup_ready_change_hdlr(MMI_TRUE);

        /* Send Memory Full Indication To UI */
        srv_sms_handle_mem_change(MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_set_memory_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_set_memory_status(sms_memory_status_struct *memory_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
#ifdef __SRV_SMS_SIM_MEMORY_BASE__
    U16 sim_total = 0;
#endif
    U16 remain_space = 0;
    U16 sim_start;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_SIM_MEMORY_BASE__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_SET_MEMORY_STATUS_0);

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_SET_MEMORY_STATUS_2, i, memory_status->sim_total[i]);

        sim_total += memory_status->sim_total[i];
    }

    if (sim_total > (SRV_SMS_MAX_SIM_SMS_ENTRY * SMS_SIM_NUM))
    {
        if (sim_total > SRV_SMS_MAX_SMS_ENTRY)
        {
            memory_status->me_total = 0;

            remain_space = SRV_SMS_MAX_ME_SMS_ENTRY;
            srv_sms_startup_set_memory_status_int(memory_status, remain_space);
        }
        else
        {
            memory_status->me_total = SRV_SMS_MAX_SMS_ENTRY - sim_total;
        }
    }
    else
    {
        memory_status->me_total = SRV_SMS_MAX_ME_SMS_ENTRY;
    }
#else /* __SRV_SMS_SIM_MEMORY_BASE__ */
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_SET_MEMORY_STATUS_1);

    srv_sms_startup_set_memory_status_int(memory_status, remain_space);
#endif /* __SRV_SMS_SIM_MEMORY_BASE__ */

    sim_start = memory_status->me_total;

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        memory_status->sim_start[i] = sim_start;
        sim_start += memory_status->sim_total[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_add_sim_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_add_sim_msg_node(
                U16 pdu_id,
                U16 record_index,
                srv_sms_sim_enum sim_id,
                srv_sms_spdu_struct *spdu_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status;
#ifdef __SRV_SMS_SIM_CUST_DATA__
    srv_sms_sim_cust_data_struct cust_data;
    MMI_BOOL is_reset = MMI_FALSE;
#endif /* __SRV_SMS_SIM_CUST_DATA__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_ADD_SIM_MSG_NODE, record_index);

#ifdef __SRV_SMS_SIM_TIMESTAMP__
    cust_data.timestamp = spdu_data->timestamp;
#endif /* __SRV_SMS_SIM_TIMESTAMP__ */
#ifdef __SRV_SMS_RESEND_COUNT__
    cust_data.resend_count = spdu_data->resend_count;
#endif /* __SRV_SMS_RESEND_COUNT__ */
#ifdef __SRV_SMS_DELIVERY_STATUS__
    cust_data.tp_st = spdu_data->tp_st;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

    status = srv_sms_spdu_status_to_msg_status(spdu_data->status, SRV_SMS_STORAGE_SIM);

    if (status != SRV_SMS_STATUS_NONE)
    {
    #ifdef __SRV_SMS_SIM_CUST_DATA__
        if ((status == SRV_SMS_STATUS_UNREAD) || (status == SRV_SMS_STATUS_READ))
        {
        /* If it is a delivery type SMS
         * 1> The timestamp should be 0;
         * 2> The resend count should be 0. */
        #ifdef __SRV_SMS_SIM_TIMESTAMP__
            if (spdu_data->timestamp > 0)
            {
                cust_data.timestamp = 0;
                is_reset = MMI_TRUE;
            }
        #endif /* __SRV_SMS_SIM_TIMESTAMP__ */
                
        #ifdef __SRV_SMS_RESEND_COUNT__
            if (spdu_data->resend_count > 0)
            {
                cust_data.resend_count = 0;
                is_reset = MMI_TRUE;
            }
        #endif /* __SRV_SMS_RESEND_COUNT__ */
        }
    #ifdef __SRV_SMS_SIM_TIMESTAMP__
        else
        {
            /* If it is a submit type SMS without timestamp, assign a default value */
            if (spdu_data->timestamp == 0)
            {
                MYTIME local_time;

                DTGetRTCTime(&local_time);

                cust_data.timestamp = mmi_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);
                is_reset = MMI_TRUE;
            }
        }
    #endif /* __SRV_SMS_SIM_TIMESTAMP__ */

    #ifdef __SRV_SMS_DELIVERY_STATUS__
        if (status == SRV_SMS_STATUS_SENT)
        {
            if (spdu_data->tp_st == SRV_SMS_SRS_INVALID)
            {
                cust_data.tp_st = SRV_SMS_SRS_NONE;
                is_reset = MMI_TRUE;
            }
        }
        else
        {
            if (spdu_data->tp_st != SRV_SMS_SRS_INVALID)
            {
                cust_data.tp_st = SRV_SMS_SRS_INVALID;
                is_reset = MMI_TRUE;
            }
        }
    #endif /* __SRV_SMS_DELIVERY_STATUS__ */

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_ADD_SIM_MSG_NODE_1, is_reset);

        if (is_reset)
        {
            srv_sms_read_write_sim_cust_data(
                record_index,
                sim_id,
                &cust_data,
                MMI_FALSE);

        #ifdef __SRV_SMS_SIM_TIMESTAMP__
            spdu_data->timestamp = cust_data.timestamp;
        #endif /* __SRV_SMS_SIM_TIMESTAMP__ */
        #ifdef __SRV_SMS_RESEND_COUNT__
            spdu_data->resend_count = cust_data.resend_count;
        #endif /* __SRV_SMS_RESEND_COUNT__ */
        #ifdef __SRV_SMS_DELIVERY_STATUS__
            spdu_data->tp_st = cust_data.tp_st;
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */
        }
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */

        srv_sms_startup_add_msg_node(
            pdu_id,
            spdu_data,
            status,
            SRV_SMS_STORAGE_SIM);
    }
#ifdef __SRV_SMS_SIM_CUST_DATA__
    else
    {
        if ( (0) 
        #ifdef __SRV_SMS_SIM_TIMESTAMP__
            || (spdu_data->timestamp > 0)
        #endif /* __SRV_SMS_SIM_TIMESTAMP__ */
        #ifdef __SRV_SMS_RESEND_COUNT__
            || (spdu_data->resend_count > 0)
        #endif /* __SRV_SMS_RESEND_COUNT__ */
        #ifdef __SRV_SMS_DELIVERY_STATUS__
            || (spdu_data->tp_st != SRV_SMS_SRS_INVALID)
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */
            )
        {
            is_reset = MMI_TRUE;
        }

        if (is_reset)
        {
            srv_sms_read_write_sim_cust_data(
                record_index,
                sim_id,
                &cust_data,
                MMI_FALSE);
        }
    }
#endif /* __SRV_SMS_SIM_CUST_DATA__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_add_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_sms_startup_add_msg_node(
            U16 pdu_id,
            srv_sms_spdu_struct *spdu_data,
            srv_sms_status_enum status,
            srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
    srv_sms_msg_node_struct msg_node;
    srv_sms_pdu_node_struct pdu_node;
    U8 curr_seg;
    U8 pdu_len;
    U8 msg_ref;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    sim_id = (srv_sms_sim_enum)spdu_data->sim_id;
#endif /*  (MMI_MAX_SIM_NUM >= 2) */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_ADD_MSG_NODE, pdu_id, storage_type, sim_id);
    memset(&msg_node,0,sizeof(srv_sms_msg_node_struct));
    /* For status, it may set the UNSUPPORT Flag;
     * For Timestamp, only when the SMS is READ or UNREAD */
    msg_node.status = SRV_SMS_STATUS_NONE;
    msg_node.timestamp = 0;

    result = srv_sms_get_msg_info_from_pdu(
                &msg_node,
                &curr_seg,
                &msg_ref,
                &pdu_len,
                spdu_data->pdu);

    if (result)
    {
        srv_sms_status_enum new_status = status;

        /* Set Other Information of the Msg Node */
        msg_node.storage_type = storage_type;

        if (storage_type == SRV_SMS_STORAGE_SIM)
        {
            if ((new_status == SRV_SMS_STATUS_UNSENT) && (msg_node.number[0] == '\0'))
            {
                new_status = SRV_SMS_STATUS_DRAFT;
            }
        }

        if ((new_status != SRV_SMS_STATUS_UNREAD) &&
            (new_status != SRV_SMS_STATUS_READ))
        {
            msg_node.timestamp = spdu_data->timestamp;
        }

    #ifdef __SRV_SMS_MULTI_SIM__
        msg_node.sim_id = sim_id;
    #endif /* __SRV_SMS_MULTI_SIM__ */

    #ifdef __SRV_SMS_MULTI_ADDR__
        msg_node.ext_addr_num = spdu_data->addr_num;
        msg_node.start_addr_id = spdu_data->start_addr_id;
    #endif /* __SRV_SMS_MULTI_ADDR__ */

    #ifdef __SRV_SMS_RESEND_COUNT__
        msg_node.resend_count = spdu_data->resend_count;
    #endif /* __SRV_SMS_RESEND_COUNT__ */

        msg_node.status |= new_status;

    #ifdef __SRV_SMS_MSG_EXT_STATUS__ 
    	msg_node.ext_status = 0;
    #endif /* __SRV_SMS_MSG_EXT_STATUS__ */

        msg_node.start_pdu_id = SRV_SMS_INVALID_PDU_ID;

        /* Fill PDU Node */
        srv_sms_init_pdu_node(&pdu_node);
        pdu_node.segment = curr_seg;
        pdu_node.status = new_status;
    #ifdef __SRV_SMS_DELIVERY_STATUS__
        pdu_node.msg_ref = msg_ref;
        pdu_node.tp_st = spdu_data->tp_st;
    #endif /* __SRV_SMS_DELIVERY_STATUS__ */

        srv_sms_add_pdu_node(pdu_id, &pdu_node);

        msg_id = srv_sms_search_concatenated_sms(&msg_node, curr_seg);

        if (msg_id == SRV_SMS_INVALID_MSG_ID)
        {
            msg_id = srv_sms_add_msg_node(&msg_node);
        }
        else
        {
            srv_sms_update_msg_node(msg_id, &msg_node, curr_seg);
        }

        srv_sms_concat_pdu_to_msg(msg_id, pdu_id);

    #if (0)
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
    }

    return msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_remove_pdu_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_remove_pdu_node(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_REMOVE_PDU_NODE, pdu_id);

    msg_id = srv_sms_get_msg_id_by_pdu(pdu_id);

    srv_sms_delete_pdu_node(pdu_id);

    if (msg_id != SRV_SMS_INVALID_MSG_ID)
    {
        if (srv_sms_msg_list[msg_id].start_pdu_id == SRV_SMS_INVALID_PDU_ID)
        {
            srv_sms_delete_msg_node(msg_id,NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_is_init_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_startup_is_init_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_sim_done = MMI_TRUE;
    MMI_BOOL result = MMI_FALSE;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_IS_INIT_DONE, sms_me_sto_flag);

	is_sim_done = srv_sms_startup_get_result(SMS_STO_STATE_INIT_DONE);
    if (is_sim_done && (sms_me_sto_flag & SMS_STO_STATE_INIT_DONE))
    {
        result = MMI_TRUE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_IS_INIT_DONE_2, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_is_get_num_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_startup_is_get_num_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	result = srv_sms_startup_get_result(SMS_STO_STATE_GET_NUM_DONE);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_IS_GET_NUM_DONE_1, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_send_startup_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_send_startup_res(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;
    U32 i;
    mmi_sms_startup_read_res_rsp_struct *read_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_SEND_STARTUP_RES, result);

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        if (!(sms_sim_sto_flag[i] & SMS_STO_STATE_SEND_RES))
        {
            sms_sim_sto_flag[i] |= SMS_STO_STATE_SEND_RES;

            sim_id = srv_sms_sim_index_to_sim_id(i);

            read_res = (mmi_sms_startup_read_res_rsp_struct*)OslConstructDataPtr(sizeof(mmi_sms_startup_read_res_rsp_struct));
            read_res->result = result;        

            srv_sms_disp_send_msg_req(
                PTR_MSG_ID_SRV_SMS_STARTUP_READ_RES_REQ,
                sim_id,
                read_res);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_reload_sim_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_reload_sim_sms(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sim_total;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_RELOAD_SIM_SMS, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    sim_total = storage_cntx.memory_status.sim_total[index];

    if (sim_total > 0)
    {
        sms_sim_sto_flag[index] &= (~SMS_STO_STATE_INIT_DONE);

        srv_sms_startup_remove_all_sim_sms(sim_id);
        srv_sms_startup_read_sim_sms(sim_total, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_remove_all_sim_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_remove_all_sim_sms(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sim_total;
    U32 index;
    U16 start_pdu_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_REMOVE_ALL_SIM_SMS, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    sim_total = storage_cntx.memory_status.sim_total[index];

    if (sim_total > 0)
    {
        start_pdu_id = srv_sms_sim_record_index_to_pdu_id(0, sim_id);

        for (i = start_pdu_id; i < (U32)(start_pdu_id + sim_total); i++)
        {
            srv_sms_startup_remove_pdu_node(i);
        }

        srv_sms_handle_mem_change(MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_startup_ready_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_startup_ready_change_hdlr(MMI_BOOL is_ready)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STARTUP_READY_CHANGE_HDLR, storage_cntx.is_ready, is_ready);

    if (storage_cntx.is_ready != is_ready)
    {
        srv_sms_event_sms_ready_struct ready_event_info;
        MMI_BOOL int_result;

        storage_cntx.is_ready = is_ready;

        ready_event_info.is_sms_ready = is_ready;

        /* Exec SMS Not Ready Interrupt Event */
        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_READY, &ready_event_info);

        /* Exec SMS Not Ready Event */
        if (!int_result)
        {
            srv_sms_emit_event(EVT_ID_SRV_SMS_READY, &ready_event_info);
        }
    }
}
#endif /* __MOD_SMSAL__ */
