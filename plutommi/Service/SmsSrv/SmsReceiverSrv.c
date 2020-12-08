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
 *  SmsReceiverSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service receiver Handler
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "stack_config.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_srv_sms_def.h"
#include "string.h"

#include "mmi_msg_struct.h"
#include "ProtocolEvents.h"
#include "SmsSrvGprot.h"
#include "SmsProtSrv.h"
#include "Smslib.h"
#include "ps_public_utility.h"
#include "SmsStorageSrv.h"
#include "SmsDispatchSrv.h" 
#include "SmsStorageCoreSrv.h" 
#include "SmsUtilSrv.h"
#include "SmsConverterSrv.h"
#include "SmsStatusReportSrv.h"
#include "SmsAtHandlerSrv.h"
#include "ems.h"


/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_INVALID_NUM   0xff
#define SRV_SMS_DATA_SIZE	15
#define SRV_SMS_MSG_CONTENT_NUM 20

typedef enum
{
    SRV_SMS_TYPE_NORMAL,
    SRV_SMS_TYPE_REPLACE,
    SRV_SMS_TYPE_CLASS0,

    SRV_SMS_TYPE_END
}srv_sms_type_enum;


typedef enum
{
    SRV_SMS_FCS_NO_ERR        = 0x00,
    /* (U)SIM SMS storage full */
    SRV_SMS_FCS_SIM_FULL    = 0xd0,
    /* No SMS storage capability in (U)SIM */
    SRV_SMS_FCS_NO_SIM_MEM,
    /* Error in MS */
    SRV_SMS_FCS_ERR_IN_SM,
    SRV_SMS_FCS_ERR_IN_TCARD,
    /* Memory Capacity Exceeded */
    SRV_SMS_FCS_MEM_EXCEED,
    
    SRV_SMS_UNKNOWN_ERR = 0xff
}srv_sms_tp_fcs_enum;

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U16 desport;
    module_type mod_src;
    srv_sms_sim_enum sim_id;
    SrvSmsEventFunc callback;
    void* user_data;
}srv_sms_data_check_struct;


typedef struct
{
    U8 segment;
    U8 nextindex;
    U16 msglen;
    U16 msg_id;
    void *data;
} srv_sms_content_struct;

typedef struct
{
    srv_sms_storage_enum storage;
    U16 msg_id;
    srv_sms_sim_enum sim_id;
    mmi_sms_new_msg_pdu_ind_struct *new_pdu;
    void *data;
} srv_sms_general_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/
#define SRV_SMS_MAX_DATA_SIZE   15
#define SRV_SMS_LMS_TIME_OUT    1000*3
#define SRV_SMS_DATA_LMS_COUNTER_NUM      10*10
#define SRV_SMS_LMS_COUNTER_NUM      10

/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_data_check_struct srv_sms_data_check[SRV_SMS_MAX_DATA_SIZE];
static U8 srv_sms_data_check_num = 0;

static srv_sms_new_msg_struct srv_sms_data_msg[SRV_SMS_MAX_DATA_SIZE + 1];
static srv_sms_content_struct srv_sms_content[SRV_SMS_MSG_CONTENT_NUM + 1];
static U8 srv_sms_data_counter[SRV_SMS_DATA_SIZE + 1];
static U8 srv_sms_data_counting = MMI_FALSE;
static void srv_sms_handle_new_waitting_msg(srv_sms_sim_enum sim_id, mmi_sms_msg_waiting_ind_struct *data);
static void srv_sms_status_report_ind(srv_sms_sim_enum sim_id, smslib_general_struct *data);
static void srv_sms_add_sms_to_await(srv_sms_sim_enum sim_id, smslib_general_struct *smslib_data);
static void srv_sms_handle_new_msg(srv_sms_sim_enum sim_id, mmi_sms_new_msg_pdu_ind_struct *data);
static void srv_sms_save_sms_callback(srv_sms_callback_struct* callback_data);
static void srv_sms_delete_sms_callback(srv_sms_callback_struct* data);
static void srv_sms_get_add_pdu_data(srv_sms_msg_add_pdu_struct* add_pdu, srv_sms_general_struct* general_data);
static void srv_sms_send_sms_ack(
                MMI_BOOL result,
                srv_sms_tp_fcs_enum error_cause,
                srv_sms_sim_enum sim_id,
                U16 pdu_id,
                U8 msg_class,
                MMI_BOOL is_msg_wait,
                MMI_BOOL is_store);
static U8 srv_sms_check_sms_port(U32 port, srv_sms_sim_enum sim_id);
static void srv_sms_add_new_data(U16 msg_id,  U16 pdu_id, srv_sms_new_msg_struct *entry, U16 length, U8 *data);
//static void srv_sms_delete_sms_in_awaited(U16 msg_id);
static void srv_sms_handle_new_data(void);
static MMI_BOOL srv_sms_check_concatenate_data(U8 *index);
static void srv_sms_indicate_data(U8 index);
static U8 srv_sms_check_data(void);
static void srv_sms_timeout_concatenate_data(void);
static U8 srv_sms_check_data_complete(U8 index);
static U8 srv_sms_get_data(U8 index, srv_sms_new_msg_struct *data, U8 *content);
static void srv_sms_free_data(U8 index);
static void srv_sms_free_new_data(void);
static U8 srv_sms_add_data_segment(U8 index, U8 segment, srv_sms_new_msg_struct *entry);
static U8 srv_sms_add_data_entry(void);


/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_convert_new_data_sms(srv_sms_new_msg_struct *data, smslib_general_struct *entry,  
            srv_sms_storage_enum storage, srv_sms_sim_enum sim_id);
static void srv_sms_convert_status_report(
                smslib_general_struct *data,
                srv_sms_status_report_ind_struct *entry);

static void srv_sms_handle_new_data(void);
static MMI_BOOL srv_sms_is_replace_sms(U8 pid);


/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_normal_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *                
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_receiver_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset( srv_sms_content, 0, sizeof(srv_sms_content_struct) * (SRV_SMS_MSG_CONTENT_NUM + 1));
    memset(srv_sms_data_msg , SRV_SMS_INVALID_NUM,  sizeof(srv_sms_new_msg_struct) * (SRV_SMS_DATA_SIZE + 1));
    memset(srv_sms_data_counter, SRV_SMS_INVALID_NUM, sizeof(U8) * (SRV_SMS_DATA_SIZE + 1));
    for (i = 0; i < (SRV_SMS_MSG_CONTENT_NUM + 1); i++)
    {
        srv_sms_content[i].segment = SRV_SMS_INVALID_NUM;
        srv_sms_content[i].nextindex = SRV_SMS_INVALID_NUM;
        srv_sms_content[i].msg_id = 0xffff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_normal_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *                
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sms_handle_normal_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_sms_disp_struct *ev_data = (mmi_evt_sms_disp_struct*)evt;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ev_data->msg_id)
    {
    case PTR_MSG_ID_SRV_SMS_DELIVER_IND:
    {
        srv_sms_handle_new_msg((srv_sms_sim_enum)ev_data->sim_id, (mmi_sms_new_msg_pdu_ind_struct *)ev_data->data);
    }
    break;
    case PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND:
    {
		srv_sms_handle_new_waitting_msg((srv_sms_sim_enum)ev_data->sim_id, (mmi_sms_msg_waiting_ind_struct*)ev_data->data);
    }
    break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_new_waitting_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id       [IN]
 *  data         [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_handle_new_waitting_msg(srv_sms_sim_enum sim_id, mmi_sms_msg_waiting_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_msg_waitting_struct *event_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_data = OslMalloc(sizeof(srv_sms_event_msg_waitting_struct));
    event_data->sim_id = sim_id;
    event_data->msg_data = data;
    srv_sms_emit_event(EVT_ID_SRV_SMS_NEW_MSG_WAITING, event_data);
    OslMfree(event_data);
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_status_report_ind
 * DESCRIPTION
 *  Handle status report
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_status_report_ind(srv_sms_sim_enum sim_id,  smslib_general_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_report_ind_struct staus_report;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_convert_status_report(data, &staus_report);
    srv_sms_status_report_ind_hdlr(&staus_report, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_sms_to_await
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id       [IN]
 *  smslib_data         [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_add_sms_to_await(srv_sms_sim_enum sim_id, smslib_general_struct *smslib_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_new_msg_struct * new_msg = OslMalloc(sizeof(srv_sms_new_msg_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    srv_sms_convert_new_data_sms(new_msg, smslib_data, SRV_SMS_STORAGE_UNSPECIFIC, sim_id);

    srv_sms_send_sms_ack(
        MMI_TRUE,
        SRV_SMS_FCS_NO_ERR,
        sim_id,
        SRV_SMS_INVALID_PDU_ID,
        (U8)smslib_data->tpdu.msg_class,
        (MMI_BOOL)smslib_data->tpdu.msg_wait.is_msg_wait,
        (MMI_BOOL)smslib_data->tpdu.msg_wait.need_store);

    /* put to awaited list last entry, from now on only process new data as awaited list last entry */
    srv_sms_add_new_data(SRV_SMS_INVALID_MSG_ID, SRV_SMS_INVALID_MSG_ID,  new_msg, smslib_data->forMMI_UserData_length, smslib_data->forMMI_UserData);
    
    /* process new sms data */
    srv_sms_handle_new_data();

    smslib_dealloc_sms_struct(smslib_data);
    OslMfree(new_msg);
    OslMfree(smslib_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_new_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id       [IN]
 *  data         [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_handle_new_msg(srv_sms_sim_enum sim_id, mmi_sms_new_msg_pdu_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smslib_general_struct *app_lib_data = OslMalloc(sizeof(smslib_general_struct));    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    smslib_decode_pdu(data->pdu, (kal_uint8)data->pdu_length, app_lib_data);
    smslib_get_msg_content(KAL_FALSE, app_lib_data, NULL);
  
    if ((app_lib_data->tpdu.msg_wait.is_msg_wait && app_lib_data->tpdu.msg_wait.need_store == MMI_FALSE) ||
        app_lib_data->tpdu.data.deliver_tpdu.pid == SRV_SMS_PID_TYPE_0 )
    {
        srv_sms_send_sms_ack(
            MMI_TRUE,
            SRV_SMS_FCS_NO_ERR,
            sim_id,
            SRV_SMS_INVALID_PDU_ID,
            (U8)app_lib_data->tpdu.msg_class,
            MMI_TRUE,
            MMI_FALSE);

        smslib_dealloc_sms_struct(app_lib_data);
        OslMfree(app_lib_data);
        
    	return;
    }

    if (srv_sms_check_sms_port(app_lib_data->tpdu.port.dest_port, sim_id) != SRV_SMS_INVALID_NUM
        ||(!(srv_sms_is_replace_sms(app_lib_data->tpdu.data.deliver_tpdu.pid)) && app_lib_data->tpdu.msg_class == SMSLIB_CLASS0))
    {
        srv_sms_add_sms_to_await(sim_id, app_lib_data);
    }
    /* the following is handle sms normal case */
    else
    {
        
        if (app_lib_data->tpdu.mti == SMSLIB_MTI_DELIVER || app_lib_data->tpdu.mti == SMSLIB_MTI_UNSPECIFIED)
        { 
            srv_sms_find_msg_struct find_data = {0};
            U16 msg_id;
            srv_sms_msg_add_pdu_struct add_pdu;
            srv_sms_general_struct * sms_general_data = OslMalloc(sizeof(srv_sms_general_struct));

            sms_general_data->data = (void *)app_lib_data;
            sms_general_data->sim_id = sim_id;
            sms_general_data->new_pdu = NULL;

            find_data.sim_id = sim_id;
            find_data.pid = (srv_sms_pid_enum)app_lib_data->tpdu.data.deliver_tpdu.pid;
            find_data.mti = (srv_sms_mti_enum)app_lib_data->tpdu.mti;
            find_data.ref_num = app_lib_data->tpdu.concat_info.ref;
            find_data.total_seg = app_lib_data->tpdu.concat_info.total_seg;
            srv_sms_convert_l4_num_to_ascii_num((U8*)find_data.address, &(app_lib_data->forMMI_TPAddr), SRV_SMS_MAX_ADDR_LEN);
            /* handle replace message */
            if (srv_sms_is_replace_sms(app_lib_data->tpdu.data.deliver_tpdu.pid) == MMI_TRUE)
            {      
                find_data.is_check_concat = MMI_FALSE;
                if (app_lib_data->tpdu.msg_class  == SMSLIB_CLASS2)
                {
                	find_data.storage_type = SRV_SMS_STORAGE_SIM;
                }
                else
                {
                	find_data.storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
                }
                if ((msg_id = srv_sms_find_msg(&find_data)) != SRV_SMS_INVALID_MSG_ID)
                {
                    sms_general_data->new_pdu = OslMalloc(sizeof(mmi_sms_new_msg_pdu_ind_struct));
                    memcpy(sms_general_data->new_pdu, data, sizeof(mmi_sms_new_msg_pdu_ind_struct));
                    srv_sms_delete_msg_bg(msg_id, srv_sms_delete_sms_callback, (void *)sms_general_data);
                    //srv_sms_delete_sms_in_awaited(msg_id);
                    return;
                }
                else if (app_lib_data->tpdu.msg_class  == SMSLIB_CLASS0)
                {
                    srv_sms_add_sms_to_await(sim_id, app_lib_data);
                    return;
                }
            }
            sms_general_data->new_pdu = OslMalloc(sizeof(mmi_sms_new_msg_pdu_ind_struct));
            memcpy(sms_general_data->new_pdu, data, sizeof(mmi_sms_new_msg_pdu_ind_struct));
            srv_sms_get_add_pdu_data(&add_pdu, sms_general_data);
            if (app_lib_data->tpdu.concat_info.total_seg > 1)
            {
                find_data.is_check_concat = MMI_TRUE;
                find_data.not_exist_seg = app_lib_data->tpdu.concat_info.seg;
                find_data.storage_type = add_pdu.storage_type;
            #if (defined(__SRV_SMS_PREFER_STORAGE_SETTING__) && defined(__SRV_SMS_SIMBOX_SUPPORT__))
                if (add_pdu.storage_type == SRV_SMS_STORAGE_SIM)
                {
                    find_data.storage_type = SRV_SMS_STORAGE_SIM;
                }
             #endif /*(defined(__SRV_SMS_PREFER_STORAGE_SETTING__)&&defined(__SRV_SMS_SIMBOX_SUPPORT__)) */ 
                if ((msg_id = srv_sms_find_msg(&find_data)) != SRV_SMS_INVALID_MSG_ID)
                {
                    add_pdu.msg_id = msg_id;
                    sms_general_data->msg_id = msg_id;
                    srv_sms_msg_add_pdu(&add_pdu, srv_sms_save_sms_callback, (void *)sms_general_data);
                    return;
                } 
            }
            add_pdu.is_hidden = MMI_TRUE;
            add_pdu.is_search_concat = MMI_FALSE;
            srv_sms_msg_add_pdu(&add_pdu, srv_sms_save_sms_callback, (void *)sms_general_data);      
        }
        else if (app_lib_data->tpdu.mti == SMSLIB_MTI_STATUS_REPORT)
        {
            srv_sms_status_report_ind(sim_id,  (smslib_general_struct *)app_lib_data);

            smslib_dealloc_sms_struct(app_lib_data);
            OslMfree(app_lib_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data         [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_save_sms_callback(srv_sms_callback_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_general_struct *general_data = (srv_sms_general_struct *)data->user_data;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_msg_add_pdu_cb_struct *msg_info = (srv_sms_msg_add_pdu_cb_struct *)data->action_data;
#endif
    srv_sms_new_msg_struct *msg_data = OslMalloc(sizeof(srv_sms_new_msg_struct));
    smslib_general_struct * app_lib_data = (smslib_general_struct *)general_data->data;
    srv_sms_tp_fcs_enum error_cause = SRV_SMS_FCS_NO_ERR;
    U16 pdu_id = SRV_SMS_INVALID_PDU_ID;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if (defined(__SRV_SMS_PREFER_STORAGE_SETTING__) && defined(__SRV_SMS_SIMBOX_SUPPORT__))
    if (general_data->storage == SRV_SMS_STORAGE_SIM 
        && !(srv_sms_is_memory_full(SRV_SMS_STORAGE_ME, general_data->sim_id))
        && (srv_sms_get_prefer_storage(general_data->sim_id) == SRV_SMS_STORAGE_SIM))
    {
            srv_sms_find_msg_struct find_data = {0};
            U16 msg_id;
            srv_sms_msg_add_pdu_struct add_pdu;

            if (data->result == MMI_TRUE && data->action == SRV_SMS_ACTION_SAVE)
            {
                srv_sms_msg_add_pdu_cb_struct *add_cb_data;
                
                add_cb_data = (srv_sms_msg_add_pdu_cb_struct*)data->action_data;
                srv_sms_unhide_msg(add_cb_data->msg_id);
            }            
            
            find_data.sim_id = general_data->sim_id;
            find_data.pid = app_lib_data->tpdu.data.deliver_tpdu.pid;
            find_data.mti = app_lib_data->tpdu.mti;
            find_data.ref_num = app_lib_data->tpdu.concat_info.ref;
            find_data.total_seg = app_lib_data->tpdu.concat_info.total_seg;
            srv_sms_convert_l4_num_to_ascii_num((U8*)find_data.address, &(app_lib_data->forMMI_TPAddr), SRV_SMS_MAX_ADDR_LEN);
            srv_sms_get_add_pdu_data(&add_pdu, general_data);
            general_data->storage = SRV_SMS_STORAGE_ME;
            add_pdu.storage_type = SRV_SMS_STORAGE_ME;
            if (app_lib_data->tpdu.concat_info.total_seg > 1)
            {
                find_data.is_check_concat = MMI_TRUE;
                find_data.not_exist_seg = app_lib_data->tpdu.concat_info.seg;
                find_data.storage_type = SRV_SMS_STORAGE_ME;
                if ((msg_id = srv_sms_find_msg(&find_data)) != SRV_SMS_INVALID_MSG_ID)
                {
                    add_pdu.msg_id = msg_id;
                    general_data->msg_id = msg_id;
                    srv_sms_msg_add_pdu(&add_pdu, srv_sms_save_sms_callback, (void *)general_data);
                    return;
                } 
            }
            add_pdu.is_hidden = MMI_TRUE;
            add_pdu.is_search_concat = MMI_FALSE;
            srv_sms_msg_add_pdu(&add_pdu, srv_sms_save_sms_callback, (void *)general_data); 
        return;
    }
#endif /* (defined(__SRV_SMS_PREFER_STORAGE_SETTING__) && defined(__SRV_SMS_SIMBOX_SUPPORT__)) */

    if (data->result == MMI_FALSE)
    {
        error_cause = SRV_SMS_UNKNOWN_ERR;
        if (data->cause == SRV_SMS_CAUSE_MEM_FULL)    
        {
            srv_sms_event_mem_exceed_struct *event_data;

            event_data = OslMalloc(sizeof(srv_sms_event_mem_exceed_struct));
            event_data->sim_id = general_data->sim_id;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if (msg_info->pdu_id >= SRV_SMS_MAX_MSG_NUM)
            {
                general_data->storage = SRV_SMS_STORAGE_TCARD;
            }
        #endif
            if (srv_sms_is_memory_full(SRV_SMS_STORAGE_UNSPECIFIC, general_data->sim_id))
            {
                error_cause = SRV_SMS_FCS_MEM_EXCEED;
            #ifdef __SRV_SMS_SIMBOX_SUPPORT__
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	            if(!srv_sms_get_unused_space(SRV_SMS_STORAGE_TCARD, general_data->sim_id))
                {
                    event_data->mem_type = SRV_SMS_MEM_NORMAL | SRV_SMS_MEM_TCARD_ONLY;
                }  
                else
            #endif
                {
                    event_data->mem_type = SRV_SMS_MEM_ME_ONLY;
                }
	        #else 
                event_data->mem_type = SRV_SMS_MEM_NORMAL;
	        #endif
                
            }
            else if(general_data->storage == SRV_SMS_STORAGE_SIM)
            {
                error_cause = SRV_SMS_FCS_SIM_FULL;
                event_data->mem_type = SRV_SMS_MEM_SIM_ONLY;
            }
            else
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if (general_data->storage == SRV_SMS_STORAGE_TCARD)
                {
                    error_cause = SRV_SMS_FCS_ERR_IN_TCARD;
                    event_data->mem_type = SRV_SMS_MEM_TCARD_ONLY;
                }
            #else
                error_cause = SRV_SMS_FCS_ERR_IN_SM;
                event_data->mem_type = SRV_SMS_MEM_ME_ONLY;
            #endif
                error_cause = SRV_SMS_FCS_ERR_IN_SM;
                event_data->mem_type = SRV_SMS_MEM_ME_ONLY;
            }
            srv_sms_emit_event(EVT_ID_SRV_SMS_MEM_EXCEED, event_data);
            OslMfree(event_data);
        }
    }
    else
    {    
        U16 msg_id;
        MMI_BOOL is_replace;
        U8 pid;
        
        if (data->action == SRV_SMS_ACTION_SAVE)
        {
            srv_sms_msg_add_pdu_cb_struct *add_cb_data;

        	add_cb_data = (srv_sms_msg_add_pdu_cb_struct*)data->action_data;

        	pdu_id = add_cb_data->pdu_id;
        	msg_id = add_cb_data->msg_id;
        }
        else
        {
            srv_sms_msg_add_pdu_cb_struct *append_cb_data;
        	append_cb_data = (srv_sms_msg_add_pdu_cb_struct*)data->action_data;

        	pdu_id = append_cb_data->pdu_id;
        	msg_id = general_data->msg_id;
        }
        srv_sms_convert_new_data_sms(msg_data, app_lib_data, general_data->storage, general_data->sim_id);
     #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(msg_id >= SRV_SMS_MAX_MSG_NUM)
        {     
            srv_sms_tcard_msg_node_struct *tcard_msg_node;
            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            pid = tcard_msg_node->pid;
        }
        else
    #endif
        {
            srv_sms_msg_node_struct *temp_msg_node;
            
            temp_msg_node = srv_sms_get_msg_node(msg_id);
            pid = temp_msg_node->pid;
        }
        
        is_replace = srv_sms_is_replace_sms(pid);
        if (srv_sms_is_msg_hidden(msg_id) == MMI_TRUE && (!is_replace))
        {               
            /* put to awaited list last entry, from now on only process new data as awaited list last entry */
            srv_sms_add_new_data(msg_id, pdu_id, msg_data, app_lib_data->pdu_len, app_lib_data->forMMI_UserData);    
            /* process new sms data */
            srv_sms_handle_new_data();
        }
        else
        {
            srv_sms_event_new_sms_struct *event_data;
            
            event_data = OslMalloc(sizeof(srv_sms_event_new_sms_struct));
            event_data->msg_data = msg_data;
            event_data->msg_id = msg_id;
            if (srv_sms_is_msg_hidden(msg_id) == MMI_TRUE)
            {
                MMI_BOOL result;
                result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_NEW_MSG, event_data); 
     
                
                if(!result)
                {
                    srv_sms_unhide_msg(msg_id);
                    srv_sms_emit_event(EVT_ID_SRV_SMS_NEW_MSG, event_data);
                }
            }
            else
            {
                srv_sms_emit_event(EVT_ID_SRV_SMS_NEW_MSG, event_data);
            }            
            OslMfree(event_data);
        }
    }

    srv_sms_send_sms_ack(
        data->result,
        error_cause,
        general_data->sim_id,
        pdu_id,
        (U8)app_lib_data->tpdu.msg_class,
        (MMI_BOOL)app_lib_data->tpdu.msg_wait.is_msg_wait,
        (MMI_BOOL)app_lib_data->tpdu.msg_wait.need_store);
        
    smslib_dealloc_sms_struct(app_lib_data);
    OslMfree(app_lib_data);
    if (general_data->new_pdu != NULL)
    {
        OslMfree(general_data->new_pdu);
        general_data->new_pdu = NULL;
    }
    OslMfree(general_data);
    OslMfree(msg_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data         [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_delete_sms_callback(srv_sms_callback_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_general_struct *general_data = (srv_sms_general_struct *)data->user_data;
    srv_sms_msg_add_pdu_struct add_pdu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_add_pdu_data(&add_pdu, general_data);
    srv_sms_msg_add_pdu(&add_pdu, srv_sms_save_sms_callback, (void *)general_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_add_pdu_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  add_pdu         [OUT]
 *  general_data    [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_add_pdu_data(srv_sms_msg_add_pdu_struct* add_pdu, srv_sms_general_struct* general_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smslib_general_struct * app_lib_data = (smslib_general_struct *)general_data->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    add_pdu->status = SRV_SMS_STATUS_UNREAD;
    add_pdu->pdu_raw_data = general_data->new_pdu->pdu;
    add_pdu->sim_id = general_data->sim_id;
    add_pdu->raw_data_size = (U8)general_data->new_pdu->pdu_length;
    add_pdu->decode_data = app_lib_data;
    add_pdu->is_hidden = MMI_FALSE;
    add_pdu->is_search_concat = MMI_FALSE;
    add_pdu->msg_id = SRV_SMS_INVALID_INDEX;
    if (app_lib_data->tpdu.msg_class  == SMSLIB_CLASS2)
    {
        add_pdu->storage_type = SRV_SMS_STORAGE_SIM;
    }
    else
    {
        add_pdu->storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    #if (defined(__SRV_SMS_PREFER_STORAGE_SETTING__)&&defined(__SRV_SMS_SIMBOX_SUPPORT__))
        if ((srv_sms_get_prefer_storage(general_data->sim_id) == SRV_SMS_STORAGE_SIM 
            && (!srv_sms_is_memory_full(SRV_SMS_STORAGE_SIM, general_data->sim_id)))
            || (srv_sms_get_prefer_storage(general_data->sim_id) == SRV_SMS_STORAGE_ME 
            && (srv_sms_is_memory_full(SRV_SMS_STORAGE_ME, general_data->sim_id))))
        {
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	        add_pdu->storage_type = SRV_SMS_STORAGE_TCARD;
	#else
	        add_pdu->storage_type = SRV_SMS_STORAGE_SIM;
	#endif
            
        }      
     #endif /*(defined(__SRV_SMS_PREFER_STORAGE_SETTING__)&&defined(__SRV_SMS_SIMBOX_SUPPORT__)) */
    }
    general_data->storage = add_pdu->storage_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_sms_ack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data         [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_sms_ack(
                MMI_BOOL result,
                srv_sms_tp_fcs_enum error_cause,
                srv_sms_sim_enum sim_id,
                U16 pdu_id,
                U8 msg_class,
                MMI_BOOL is_msg_wait,
                MMI_BOOL is_store)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_send_deliver_report_req_struct *req_msg;
    srv_sms_storage_enum storage_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_msg = OslConstructDataPtr(sizeof(mmi_sms_send_deliver_report_req_struct));

    if (result == MMI_TRUE)
    {
        srv_sms_update_sms_counter(sim_id, SRV_SMS_COUNT_RECV);
    }

    req_msg->result = result;
    req_msg->error_cause = error_cause;

    if (pdu_id == SRV_SMS_INVALID_PDU_ID)
    {
        storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
        req_msg->index = SRV_SMS_INVALID_PDU_ID;
    }
    else
    {
        srv_sms_sim_enum tmp_sim_id;
    
        req_msg->index = srv_sms_pdu_id_to_record_index(pdu_id, &storage_type, &tmp_sim_id);
    }

    req_msg->mem = srv_sms_storage_type_to_protocol_mem(storage_type);

    req_msg->msg_class = msg_class;
    req_msg->is_msg_wait = (kal_bool)is_msg_wait;
    req_msg->msg_wait_store = (kal_uint8)is_store;

    srv_sms_disp_send_msg_req(PTR_MSG_ID_SRV_SMS_DELIVER_REPORT_REQ, sim_id, req_msg);    
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_reg_port
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_src         [IN]        
 *  port_num        [IN]        
 *  withdata        [IN]        
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_reg_port(
                    U16 port_num,
                    srv_sms_sim_enum sim_id,
                    SrvSmsEventFunc callback,
                    void *user_data)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_data_check_num < SRV_SMS_MAX_DATA_SIZE)
    {
        srv_sms_data_check[srv_sms_data_check_num].desport = port_num;
        srv_sms_data_check[srv_sms_data_check_num].sim_id = sim_id;
        srv_sms_data_check[srv_sms_data_check_num].callback = callback;
        srv_sms_data_check[srv_sms_data_check_num].user_data = user_data;
     
        srv_sms_data_check_num++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_unreg_port
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_src         [IN]        
 *  port_num        [IN]        
 * RETURNS
 *  void
*****************************************************************************/
void* srv_sms_unreg_port(
                    U16 port_num,
                    srv_sms_sim_enum sim_id,
                    SrvSmsEventFunc callback,
                    void *user_data)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = srv_sms_data_check_num;
    void *userData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i > 0)
    {
        i--;
        if ((srv_sms_data_check[i].desport == port_num) && (srv_sms_data_check[i].sim_id == sim_id)
            && (srv_sms_data_check[i].callback == callback )
            )
        {
            U8 j = i + 1;

            userData = srv_sms_data_check[i].user_data;
            for (j = (i + 1); j <= srv_sms_data_check_num; j++)
            {
                memcpy(
                    & srv_sms_data_check[j - 1],
                    & srv_sms_data_check[j],
                    sizeof(srv_sms_data_check_struct));
            }
            srv_sms_data_check_num--;
            break;
        }
    }
    return userData;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_dest_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id         [IN]               
 * RETURNS
 *  module_type
*****************************************************************************/
module_type srv_sms_get_dest_module(U16 msg_id)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (module_type)srv_sms_data_check[msg_id].desport;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_new_data_sms
 * DESCRIPTION
 *  convert mt structure to entry structure
 * PARAMETERS
 *  data        [IN]        New data
 *  entry       [OUT]       Message entry
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_convert_new_data_sms(srv_sms_new_msg_struct *data, smslib_general_struct *smslib_data, srv_sms_storage_enum storage, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data->dest_port = (U16)smslib_data->tpdu.port.dest_port;
    data->src_port = (U16)smslib_data->tpdu.port.src_port;
    data->dcs = srv_sms_smslib_alphabet_to_dcs(smslib_data->tpdu.alphabet_type);
    data->message_len = smslib_data->forMMI_UserData_length;
    data->mti = smslib_data->tpdu.mti;
    data->ref = smslib_data->tpdu.concat_info.ref;
    data->seg = smslib_data->tpdu.concat_info.seg;
    data->total_seg = smslib_data->tpdu.concat_info.total_seg;
    data->sim_id = sim_id;
    srv_sms_scts_to_mytime(&data->timestamp, smslib_data->tpdu.data.deliver_tpdu.scts);
    data->pid = smslib_data->tpdu.data.deliver_tpdu.pid;
    data->fo = smslib_data->tpdu.fo;
    data->storage_type = storage;
    srv_sms_convert_l4_num_to_ascii_num(data->number, &smslib_data->forMMI_TPAddr, SRV_SMS_MAX_ADDR_LEN);
    srv_sms_convert_l4_num_to_ascii_num(data->sc_number, &smslib_data->forMMI_SCAAddr, SRV_SMS_MAX_ADDR_LEN); 
    data->data[0] = SRV_SMS_MSG_CONTENT_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_status_report
 * DESCRIPTION
 *  convert status report structure to entry structure
 * PARAMETERS
 *  data        [IN]        Data
 *  entry       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_convert_status_report(
        smslib_general_struct *sms_lib_data,
        srv_sms_status_report_ind_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->fo = sms_lib_data->tpdu.fo;
    memcpy(entry->discharge_time, sms_lib_data->tpdu.data.report_tpdu.dis_time, 7);
    srv_sms_convert_l4_num_to_ascii_num(entry->number, &(sms_lib_data->forMMI_TPAddr), SRV_SMS_MAX_ADDR_LEN);
    entry->tp_st = sms_lib_data->tpdu.data.report_tpdu.status;
    entry->msg_ref = sms_lib_data->tpdu.data.report_tpdu.msg_ref;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_sms_port
 * DESCRIPTION
 *  check sms port
 * PARAMETERS
 *  entry       [IN]        Entry
 *  length      [IN]        
 *  data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_sms_check_sms_port(U32 port, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = srv_sms_data_check_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i > 0)
    {
        i--;
        if ((srv_sms_data_check[i].desport == (U16)port) && (srv_sms_data_check[i].sim_id == sim_id))
        {
            return i;
        }
    }
    return SRV_SMS_INVALID_NUM;

}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_new_data
 * DESCRIPTION
 *  free new sms buff
 * PARAMETERS
 *  entry       [IN]        Entry
 *  length      [IN]        
 *  data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_add_new_data(U16 msg_id,  U16 pdu_id, srv_sms_new_msg_struct *entry, U16 length, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 segment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_convert_segment(
        &entry->total_seg,
        &entry->seg,
        &segment,
        entry->total_seg,
        entry->seg);

	entry->msg_id = msg_id;
    memcpy(&srv_sms_data_msg[SRV_SMS_DATA_SIZE], entry, sizeof(srv_sms_new_msg_struct));
    srv_sms_data_msg[SRV_SMS_DATA_SIZE].data[0] = SRV_SMS_MSG_CONTENT_NUM;

    /* handle message content part */
    srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].msg_id = pdu_id;
    srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].nextindex = SRV_SMS_INVALID_NUM;
    srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].segment = segment;
    srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].msglen = length;
    if (srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data != NULL)
    {
        OslMfree(srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data);
        srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data = NULL;
    }
    if (length)
    {
        srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data = OslMalloc(length);
        memcpy(srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data, data, length);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_sms_in_awaited
 * DESCRIPTION
 *  delete one SMS from awaited list
 * PARAMETERS
 *  msg_id       [IN]        Msg id       
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_new_data
 * DESCRIPTION
 *  handle new SMS with port number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_handle_new_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check segment */
    if (srv_sms_check_concatenate_data(&index) == MMI_TRUE)
    {
        srv_sms_indicate_data(index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_concatenate_data
 * DESCRIPTION
 *  Check concatenate data
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  index
 *****************************************************************************/
static MMI_BOOL srv_sms_check_concatenate_data(U8 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_new_msg_struct *entry =
        (srv_sms_new_msg_struct*) &srv_sms_data_msg[SRV_SMS_DATA_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((entry->total_seg % SRV_SMS_MAX_SEG) == 1) &&
        (entry->total_seg == entry->seg))
    {
        *index = SRV_SMS_DATA_SIZE;
        
        return MMI_TRUE;
    }
    else
    {
        U8 awaited_index = srv_sms_check_data();

        /* the last entry in the mmi_frm_sms_data belongs to one of the segments of the entry with index awaited_index in the data list */
        if (awaited_index != SRV_SMS_INVALID_NUM)
        {
            if (srv_sms_check_data_complete(awaited_index) == TRUE)
            {
                srv_sms_data_counter[awaited_index] = SRV_SMS_INVALID_NUM;
                *index = awaited_index;
                return MMI_TRUE;
            }
            /* not all segments of this message are arrived */
            else
            {
                U32 dataindex = 0;

                /* check if srv_sms_content is full */
                while (dataindex < SRV_SMS_MSG_CONTENT_NUM)
                {
                    if (srv_sms_content[dataindex].segment == SRV_SMS_INVALID_NUM)
                    {
                        /* srv_sms_content is not full, restart the counter to keep waiting for other segment's arriving */
                        srv_sms_data_counter[awaited_index] = 0;
                        *index = awaited_index;
                        return MMI_FALSE;
                    }
                    dataindex++;
                }
                /* srv_sms_content is full, reset the counter and free this message */
                srv_sms_data_counter[awaited_index] = SRV_SMS_INVALID_NUM;
                srv_sms_free_data(awaited_index);
                *index = awaited_index;
                return MMI_FALSE;
            }
        }
        else
        {
            /* cannot find any match in data list, add one entry with index awaited_index in the mmi_frm_sms_data */
            awaited_index = srv_sms_add_data_entry();
            /* find an empty entry in the data list and add successfully */
            if (awaited_index != SRV_SMS_INVALID_NUM)
            {
                srv_sms_free_new_data();
                /* the timer is not started yet */
                if (srv_sms_data_counting == MMI_FALSE)
                {
                    StartTimer(
                        SRV_SMS_LMS_RECV_TIMER_ID,
                        SRV_SMS_LMS_TIME_OUT,
                        srv_sms_timeout_concatenate_data);
                    srv_sms_data_counting = MMI_TRUE;
                }
                srv_sms_data_counter[awaited_index] = 0;
                *index = SRV_SMS_INVALID_NUM;
                return MMI_FALSE;
            }
            /* data list or content list is full and the segment should be discarded */
            else
            {
                srv_sms_free_new_data();
                *index = SRV_SMS_DATA_SIZE;
                return MMI_FALSE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_indicate_data
 * DESCRIPTION
 *  Indicate new SMS with port number
 * PARAMETERS
 *  index       [IN]        Data index
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_indicate_data(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    srv_sms_new_msg_struct *data = OslMalloc(sizeof(srv_sms_new_msg_struct));

    U16 content_len =  SRV_SMS_MAX_BUFF_SIZE;
    U8 *content = OslMalloc(content_len);
    srv_sms_event_new_sms_struct *event_data;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(content, 0, content_len);
    srv_sms_get_data(index, data, content);
    event_data = OslMalloc(sizeof(srv_sms_event_new_sms_struct));
    event_data->msg_data = data;
    event_data->content = content;
    while (i < srv_sms_data_check_num)
    {
        if ((srv_sms_data_check[i].desport == data->dest_port)
            && (srv_sms_data_check[i].sim_id== data->sim_id))
        { 
            srv_sms_event_struct evt_data;
             
            if (index == SRV_SMS_DATA_SIZE)
            {
                /* add one entry with index awaited_index in the mmi_frm_sms_data */
                U8 awaited_index = srv_sms_add_data_entry();

                /* find an empty entry in the data list and add successfully */
                if (awaited_index != SRV_SMS_INVALID_NUM)
                {
                    srv_sms_free_new_data();
                }
            }
            evt_data.event_info = event_data;
            evt_data.user_data = srv_sms_data_check[i].user_data;
            event_data->msg_id = i;
            srv_sms_data_check[i].callback((void*)&evt_data);
            srv_sms_free_data(index);
            break;
        }
        i++;
    }
    
    if (i == srv_sms_data_check_num)
    {
        i  = srv_sms_data_msg[index].data[0];
        event_data->msg_id = srv_sms_data_msg[index].msg_id;
	/* Execute Message Delete Interrupt Event */
        result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_NEW_MSG, event_data);
        if (result == MMI_FALSE)
        {
            /* Emit Message Delete Event */
            if (srv_sms_data_msg[index].msg_id != SRV_SMS_INVALID_MSG_ID)
            {
            	srv_sms_unhide_msg(srv_sms_data_msg[index].msg_id);
            }			
            srv_sms_emit_event(EVT_ID_SRV_SMS_NEW_MSG, event_data);
        } 
        srv_sms_free_data(index);
    }
    OslMfree(event_data);
    OslMfree(data);
    OslMfree(content);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_data
 * DESCRIPTION
 *  Check SMS with port in data list
 * PARAMETERS
 *  void
 * RETURNS
 *  index
 *****************************************************************************/
static U8 srv_sms_check_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find the entry in the data list that matches the last entry in the mmi_frm_sms_data */
    U32 i = 0;
    srv_sms_new_msg_struct *datainfo = &srv_sms_data_msg[SRV_SMS_DATA_SIZE];
    U8 thisseg = srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].segment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((datainfo->total_seg % SRV_SMS_MAX_SEG) == 1) &&
        (datainfo->total_seg == datainfo->seg))
    {
        return SRV_SMS_DATA_SIZE;
    }

    while (i < SRV_SMS_DATA_SIZE)
    {
        srv_sms_new_msg_struct *data = &srv_sms_data_msg[i];

        if ((data->total_seg == datainfo->total_seg) && (data->seg == datainfo->seg) &&
            (data->ref == datainfo->ref) &&
            ((strcmp((CHAR *) data->number, (CHAR *) datainfo->number)) == 0)
    #ifdef __MMI_DUAL_SIM_MASTER__
            && (data->sim_id== datainfo->sim_id)
    #endif 
            )
        {
            U32 j = srv_sms_data_msg[i].data[0];

            while (j != SRV_SMS_INVALID_NUM)
            {
                /* find exactly the same entry in the data list as the last entry */
                if (srv_sms_content[j].segment == thisseg)
                {
                    break;
                }
                /* thisseg is smaller than the current smallest segment number of this message */
                else if (srv_sms_content[j].segment > thisseg)
                {
                    /* if add data segment fail, the last entry is not duplicated, so it cannot free here */
                    if (srv_sms_add_data_segment(i, thisseg, datainfo) == TRUE)
                    {
                        srv_sms_free_new_data();
                    }
                    return i;
                }
                /* thisseg is greater than the current largest segment number of this message */
                else if (srv_sms_content[j].segment < thisseg &&
                         srv_sms_content[j].nextindex == SRV_SMS_INVALID_NUM)
                {
                    /* if add data segment fail, the last entry is not duplicated, so it cannot free here */
                    if (srv_sms_add_data_segment(i, thisseg, datainfo) == TRUE)
                    {
                        srv_sms_free_new_data();
                    }
                    return i;
                }
                j = srv_sms_content[j].nextindex;
            }
        }
        i++;
    }
    return SRV_SMS_INVALID_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_timeout_concatenate_data
 * DESCRIPTION
 *  timeout check concatenate SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_timeout_concatenate_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 awaited_remain = FALSE;
    U8 counter_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < SRV_SMS_DATA_SIZE)
    {
        if (srv_sms_data_counter[i] != SRV_SMS_INVALID_NUM)
        {
            srv_sms_data_counter[i]++;

            /* Give twice time for data to be re-assembled. */
            if (srv_sms_check_sms_port(srv_sms_data_msg[i].dest_port, srv_sms_data_msg[i].sim_id) != SRV_SMS_INVALID_NUM)
            {
                counter_num = SRV_SMS_DATA_LMS_COUNTER_NUM;            
            }
            else
            {
                counter_num = SRV_SMS_LMS_COUNTER_NUM; 
            }
            
            if (srv_sms_data_counter[i] == counter_num)
            {
                srv_sms_indicate_data(i);
                srv_sms_data_counter[i] = SRV_SMS_INVALID_NUM;
            }
            else
            {
                awaited_remain = TRUE;
            }
        }
        i++;
    }
    /* timer expires but still some segments are missing in the srv_sms_awaited */
    if (awaited_remain == TRUE)
    {
        StartTimer(SRV_SMS_LMS_RECV_TIMER_ID, SRV_SMS_LMS_TIME_OUT, srv_sms_timeout_concatenate_data);
    }
    else
    {
        srv_sms_data_counting = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_data_complete
 * DESCRIPTION
 *  Check SMS with port completeness
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  TRUE: complete, FALSE: not
 *****************************************************************************/
static U8 srv_sms_check_data_complete(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    srv_sms_new_msg_struct *data = (srv_sms_new_msg_struct*)&srv_sms_data_msg[index];
    U8 total_seg = ((data->total_seg - data->seg + 1) > SRV_SMS_MAX_SEG) ?
        SRV_SMS_MAX_SEG : (data->total_seg - data->seg + 1);
    U32 dataindex = srv_sms_data_msg[index].data[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the message has only one segment */
    if (index == SRV_SMS_DATA_SIZE)
    {
        return TRUE;
    }
    while (dataindex != SRV_SMS_INVALID_NUM)
    {
        if (srv_sms_content[dataindex].segment != (i + 1))
        {
            return FALSE;
        }
        dataindex = srv_sms_content[dataindex].nextindex;
        i++;
    }
    if (i == total_seg)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_data
 * DESCRIPTION
 *  Get SMS with port: get content
 * PARAMETERS
 *  index       [IN]        Index
 *  data        [OUT]       Entry info
 *  content     [OUT]       Content
 * RETURNS
 *  TRUE: OK, FALSE: content empty
 *****************************************************************************/
static U8 srv_sms_get_data(U8 index, srv_sms_new_msg_struct *data, U8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(data, &srv_sms_data_msg[index], sizeof(srv_sms_new_msg_struct));

    if (srv_sms_data_msg[index].message_len == 0)
    {
        return FALSE;
    }

    memset(content, 0, srv_sms_data_msg[index].message_len);

    if (srv_sms_data_msg[index].dcs == SRV_SMS_DCS_UCS2 || srv_sms_data_msg[index].dcs == SRV_SMS_DCS_7BIT)
    {
        U32 i = srv_sms_data_msg[index].data[0];
        U8 *textBuff = NULL;
        U8 *textBuffShifted = NULL;
        U8 *TPUD[1];
        U8 TPUDLEN[1];
        U8 is_obj_present = 0;
        U16 buffLen = srv_sms_data_msg[index].message_len;
        U16 textLen = 0;
        U16 total_len = 0;

        if (srv_sms_data_msg[index].dcs == SRV_SMS_DCS_7BIT)
        {
            buffLen *= 2;
        }

        if (buffLen)
        {
            buffLen = (buffLen < SRV_SMS_MAX_BUFF_SIZE - ENCODING_LENGTH) ? buffLen : (SRV_SMS_MAX_BUFF_SIZE - ENCODING_LENGTH);
            textBuff = OslMalloc(buffLen);
            textBuffShifted = textBuff;

            while (i != SRV_SMS_INVALID_NUM)
            {
                TPUDLEN[0] = (U8) srv_sms_content[i].msglen;
                TPUD[0] = (U8*) srv_sms_content[i].data;
                EMSMsgPreview(
                    1,
                    srv_sms_data_msg[index].dcs,
                    (U8)GetUDHIBit(srv_sms_data_msg[index].fo),
                    TPUD,
                    TPUDLEN,
                    buffLen,
                    textBuffShifted,
                    &is_obj_present,
                    &textLen);

                total_len += textLen;
                textBuffShifted += textLen;
                buffLen -= textLen;
                textLen = 0;

                i = srv_sms_content[i].nextindex;
            }

            memcpy(content, textBuff, total_len);
            data->message_len = total_len;
            OslMfree(textBuff);
        }
        else
        {
            memset(content, 0, ENCODING_LENGTH);
        }
        return TRUE;
    }
    else
    {
        U32 i = srv_sms_data_msg[index].data[0];
        U16 len = 0;
        U8 udhl = 0;

        while (i != SRV_SMS_INVALID_NUM)
        {
            CHAR* data =  (CHAR*)srv_sms_content[i].data;
            udhl = 0;

            if (GetUDHIBit(srv_sms_data_msg[index].fo))
            {
                udhl = *data;
                if (udhl >= srv_sms_content[i].msglen)
                {
                    srv_sms_content[i].msglen = 0;
                }
                else
                {                    
                    srv_sms_content[i].msglen -= (udhl + 1);
                }
            }
            memcpy((content) + len, (data + udhl + 1), srv_sms_content[i].msglen);
            len += srv_sms_content[i].msglen;
            i = srv_sms_content[i].nextindex;
        }
        data->message_len = len;
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_data
 * DESCRIPTION
 *  Free SMS with port number by index
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_free_data(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = srv_sms_data_msg[index].data[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i != SRV_SMS_INVALID_NUM)
    {
        U8 nextindex = srv_sms_content[i].nextindex;

        if (srv_sms_content[i].data != NULL)
        {
            OslMfree(srv_sms_content[i].data);
            srv_sms_content[i].data = NULL;
        }
        srv_sms_content[i].msglen = 0;
        srv_sms_content[i].nextindex = SRV_SMS_INVALID_NUM;
        srv_sms_content[i].segment = SRV_SMS_INVALID_NUM;
        srv_sms_content[i].msg_id = 0xffff;
        i = nextindex;
    }
    memset(& srv_sms_data_msg[index], SRV_SMS_INVALID_NUM, sizeof(srv_sms_new_msg_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_new_data
 * DESCRIPTION
 *  free new sms buff
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_free_new_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data != NULL)
    {
        OslMfree(srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data);
        srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data = NULL;
    }
    srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].msglen = 0;
    srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].nextindex = SRV_SMS_INVALID_NUM;
    srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].segment = SRV_SMS_INVALID_NUM;
    memset(
        & srv_sms_data_msg[SRV_SMS_DATA_SIZE],
        SRV_SMS_INVALID_NUM,
        sizeof(srv_sms_new_msg_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_data_segment
 * DESCRIPTION
 *  add one segment to awaited entry
 * PARAMETERS
 *  index       [IN]        Index
 *  segment     [IN]        Segment
 *  entry       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_sms_add_data_segment(U8 index, U8 segment, srv_sms_new_msg_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 islast = TRUE;
    U32 dataindex = 0;
    U8 thisdataindex = srv_sms_data_msg[index].data[0];
    U8 prevdataindex = SRV_SMS_INVALID_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find an empty entry in srv_sms_content in order to move the last entry to that entry */
    while (dataindex < SRV_SMS_MSG_CONTENT_NUM)
    {
        if (srv_sms_content[dataindex].msglen == 0)
        {
            break;  /* found empty entry */
        }
        dataindex++;
    }
    /* if srv_sms_content is full and cannot find any empty entry, don't have to move */
    if (dataindex != SRV_SMS_MSG_CONTENT_NUM)
    {
        /* move the actual data of the last entry to the entry with the index dataindex in srv_sms_content */
        if (entry->message_len)
        {
            srv_sms_content[dataindex].data = OslMalloc(entry->message_len);
            memcpy(
                srv_sms_content[dataindex].data,
                srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data,
                entry->message_len);
        }
        srv_sms_content[dataindex].msglen = entry->message_len;
        srv_sms_content[dataindex].segment = segment;
        srv_sms_content[dataindex].msg_id = srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].msg_id;
    }
    srv_sms_data_msg[index].message_len += entry->message_len;
    MMI_ASSERT(srv_sms_data_msg[index].message_len <= SRV_SMS_MAX_SEG * SRV_SMS_MSG_LEN);

    /* thisdataindex is the current smallest segment index of this message */
    if (srv_sms_content[thisdataindex].segment > segment)
    {
        islast = FALSE;
        /* dataindex is inserted in the head, now dataindex is the current smallest segment index of this message */
        srv_sms_content[dataindex].nextindex = thisdataindex;
        srv_sms_data_msg[index].data[0] = dataindex;
    }
    else
    {
        while (srv_sms_content[thisdataindex].nextindex != SRV_SMS_INVALID_NUM)
        {
            prevdataindex = thisdataindex;
            thisdataindex = srv_sms_content[thisdataindex].nextindex;
            if (srv_sms_content[thisdataindex].segment > segment)
            {
                islast = FALSE;
                break;
            }
        }
    }

    if (islast == TRUE)
    {
        /* dataindex is inserted in the tail, now dataindex is the current largest segment index of this message */
        srv_sms_content[thisdataindex].nextindex = dataindex;
        srv_sms_content[dataindex].nextindex = SRV_SMS_INVALID_NUM;
    }
    else
    {
        /* dataindex is inserted in the middle */
        if (prevdataindex != SRV_SMS_INVALID_NUM)
        {
            srv_sms_content[prevdataindex].nextindex = dataindex;
        }
        srv_sms_content[dataindex].nextindex = thisdataindex;
    }
    /* srv_sms_content is full and cannot handle other new segment coming anymore */
    if (dataindex == SRV_SMS_MSG_CONTENT_NUM)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_data_entry
 * DESCRIPTION
 *  add sms to awaited list
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: inserted, FALSE: not inserted
 *****************************************************************************/
static U8 srv_sms_add_data_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 dataindex = 0;
    U16 length = srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].msglen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (dataindex < SRV_SMS_MSG_CONTENT_NUM)
    {
        if (srv_sms_content[dataindex].segment == SRV_SMS_INVALID_NUM)
        {
            break;  /* found empty entry */
        }
        dataindex++;
    }
    /* cannot find any empty entry in srv_sms_content */
    if (dataindex == SRV_SMS_MSG_CONTENT_NUM)
    {
        return SRV_SMS_INVALID_NUM;
    }

    srv_sms_content[dataindex].msglen = srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].msglen;
    srv_sms_content[dataindex].nextindex = srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].nextindex;
    srv_sms_content[dataindex].segment = srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].segment;
    /* srv_sms_content[dataindex].data=srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data; */
    /* srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data=NULL; */
    if (length)
    {
        srv_sms_content[dataindex].data = OslMalloc(length);
        memcpy(srv_sms_content[dataindex].data, srv_sms_content[SRV_SMS_MSG_CONTENT_NUM].data, length);
    }

    while (i < SRV_SMS_DATA_SIZE)
    {
        if (srv_sms_data_msg[i].data[0] == SRV_SMS_INVALID_NUM)
        {
            memcpy(
                &(srv_sms_data_msg[i]),
                &(srv_sms_data_msg[SRV_SMS_DATA_SIZE]),
                sizeof(srv_sms_new_msg_struct));
            srv_sms_data_msg[i].data[0] = dataindex;
            return i;
        }
        i++;
    }
    /* cannot find any empty entry in srv_sms_data_msg */
    return SRV_SMS_INVALID_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_replace_sms
 * DESCRIPTION
 *  check whether current pid is replace type
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: YES, FALSE: not replace sms
 *****************************************************************************/
static MMI_BOOL srv_sms_is_replace_sms(U8 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pid)
    {
        case SRV_SMS_PID_REPLACE_TYPE_1:
        case SRV_SMS_PID_REPLACE_TYPE_2:
        case SRV_SMS_PID_REPLACE_TYPE_3:
        case SRV_SMS_PID_REPLACE_TYPE_4:
        case SRV_SMS_PID_REPLACE_TYPE_5:
        case SRV_SMS_PID_REPLACE_TYPE_6:
        case SRV_SMS_PID_REPLACE_TYPE_7:
            return MMI_TRUE;
        default:
            break;
    }
    return MMI_FALSE;
}

#endif /* __MOD_SMSAL__ */ 

