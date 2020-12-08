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
 *  SmsDispatchSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service dispatch Handler
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
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "DebugInitDef_Int.h"
#include "string.h"

#include "mmi_msg_struct.h"
#include "ProtocolEvents.h"
#include "SmsSrvGprot.h"
#include "SmsDispatchSrv.h"
#include "SmsUtilSrv.h"


/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_MAX_CHANNEL MMI_SIM_TOTAL

#define SRV_SMS_MAX_ACTION 10
#define SRV_SMS_INVALID_ACCESS_ID              0xFF

#define SRV_SMS_MAX_SEND_NUM 3

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    MMI_BOOL isUsed;
    U8 file_index;
    srv_sms_sim_enum sim_id;
    U32 msg_id;    
    SrvSmsDispCallbackFunc callback;
    void *user_data;
}srv_sms_sim_struct;


typedef struct
{ 
    MMI_BOOL isUsed;
    U8 access_id;
    srv_sms_sim_enum sim_id;
    U32 msg_id;
    SrvSmsDispCallbackFunc callback;
    void *user_data;    
}srv_sms_disp_send_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/
const U32 read_map[SRV_SMS_FILE_INDEX_ALL] = 
                {
                    PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ,
                    PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ,
                    PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ,
                    PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ,
                    0,
                    PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ,
                #ifdef __MMI_MSG_REL4_SUPPORT__
                    PRT_MSG_ID_MMI_SMS_GET_MBI_REQ,                     
                    PRT_MSG_ID_MMI_SMS_GET_MSP_REQ,
                #else
                    0,
                    0,
                #endif
                    0,                       
                    PRT_MSG_ID_MMI_SMS_GET_CB_MODE_REQ
                    
                };
const U32 write_map[SRV_SMS_FILE_INDEX_ALL] = 
                {
                    PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ,
                    0,
                    PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ,
                    PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ,
                    PRT_MSG_ID_MMI_SMS_SET_MSG_WAITING_REQ,
                    PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ,
                #ifdef __MMI_MSG_REL4_SUPPORT__
                    PRT_MSG_ID_MMI_SMS_SET_MBI_REQ,                     
                    PRT_MSG_ID_MMI_SMS_SET_MSP_REQ,
                #else
                    0,
                    0,
                #endif 
                    PRT_MSG_ID_MMI_CB_SUBSCRIBE_REQ,
                    PRT_MSG_ID_MMI_SMS_SET_CB_MODE_REQ
                };

const U8 source_seq_num[3][2] = 
{
    0,0,
    0,1,
    1,1
};
/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_sim_struct srv_sms_sim_cb_data[SRV_SMS_MAX_ACTION];
static U8 srv_sms_curr_action_num;

static srv_sms_disp_send_struct srv_sms_send_cb_data[SRV_SMS_MAX_CHANNEL][SRV_SMS_MAX_SEND_NUM];
/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_handle_sms_normal_ind(U16 evt_id,srv_sms_sim_enum sim_id, U32 msg_id, void *inMsg);
static MMI_BOOL srv_sms_handle_new_ind(void *inMsg, int mod_dest, void *Message);

static MMI_BOOL srv_sms_handle_sim_rsp(void *inMsg, int mod_dest, void *Message);

static U32 srv_sms_get_mapping_msg_id(
            srv_sms_sim_file_index_enum file_index,
            MMI_BOOL is_read);
static U32 srv_sms_get_rsp_mapping_msg_id(U32 msg_id);            
            
static U8 srv_sms_add_disp_action(
            srv_sms_sim_file_index_enum file_index,
            srv_sms_sim_enum sim_id,
            U32 msg_id,
            SrvSmsDispCallbackFunc callback,
            void *user_data);

static void srv_sms_delete_disp_action(U8 action_number);

static MMI_BOOL srv_sms_disp_send_sms_rsp(void *inMsg, int mod_dest, void *Message);
static void srv_sms_handle_sms_send_rsp(srv_sms_sim_enum sim_id, U32 msg_id, void *inMsg);
static MMI_BOOL srv_sms_disp_send_abort_sms_rsp(void *inMsg, int mod_dest, void *Message);
static srv_sms_sim_enum srv_sms_get_sim_id_by_module(int mod_dest);
static U8 srv_sms_get_index_by_sim_id(srv_sms_sim_enum sim_id);

/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_dispatch_init
 * DESCRIPTION
 *  SMS Service dispatcher init function
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
 void srv_sms_dispatch_init(void)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_DELIVER_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_STARTUP_READ_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PRT_MSG_ID_MMI_CB_MSG_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PRT_MSG_ID_MMI_SMS_CB_GS_CHANGE_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_GET_MEM_STATUS_IND);
#ifdef __SRV_SMS_AT_SUPPORT__
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_ATCMD_CMGL_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_ATCMR_CGSMS_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_ATCMR_CSAS_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_ATCMD_CMGD_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_ATCMD_CMGW_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_SRV_SMS_ATCMD_EQSI_IND);
    SetProtocolEventHandler((PsIntFuncPtr) srv_sms_handle_new_ind, PTR_MSG_ID_MMI_SMS_ATCMD_CMGR_IND);
#endif /* __SRV_SMS_AT_SUPPORT__ */

    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP);

    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_CB_SUBSCRIBE_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);

#ifdef __MMI_MSG_REL4_SUPPORT__
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_MBI_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_MBI_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_MSP_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_GET_MSP_RSP);
#endif /* __MMI_MSG_REL4_SUPPORT__ */
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_handle_sim_rsp, PRT_MSG_ID_MMI_SMS_SET_MSG_WAITING_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_disp_send_sms_rsp, PTR_MSG_ID_SRV_SMS_SEND_PDU_SMS_MSG_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)srv_sms_disp_send_abort_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_sms_ind
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_handle_sms_normal_ind(U16 evt_id, srv_sms_sim_enum sim_id, U32 msg_id, void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_sms_disp_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&data, evt_id);
    data.data = inMsg;
    data.msg_id = msg_id;
    data.sim_id = sim_id;  

    MMI_FRM_CB_EMIT_EVENT(&data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_new_ind
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_handle_new_ind(void *inMsg, int mod_dest, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE * msg = (MYQUEUE *)Message;
    U16 event_id = EVT_ID_SRV_SMS_BEGIN;
    srv_sms_sim_enum sim_id = srv_sms_get_sim_id_by_module(mod_dest);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(msg->oslMsgId)
    {
    case PTR_MSG_ID_SRV_SMS_DELIVER_IND:
    case PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND:
    case PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND:
        event_id = EVT_ID_SRV_SMS_PS_RECEIVER_IND;
    	break;
        
    case PTR_MSG_ID_SRV_SMS_STARTUP_READ_IND:
     case PTR_MSG_ID_SRV_SMS_GET_MEM_STATUS_IND:
        event_id = EVT_ID_SRV_SMS_PS_NORMAL_IND;
        break;
#ifdef __SRV_CBS_SUPPORT__
    case PRT_MSG_ID_MMI_CB_MSG_IND:
        event_id = EVT_ID_SRV_SMS_PS_CB_MSG_IND;
    	break;
    case PRT_MSG_ID_MMI_SMS_CB_GS_CHANGE_IND:
        event_id = EVT_ID_SRV_SMS_PS_CB_GS_CHANGE_IND;
        break;
#endif
    case PTR_MSG_ID_MMI_SMS_ATCMD_CMGR_IND:
    case PTR_MSG_ID_SRV_SMS_ATCMD_CMGL_IND:
    case PTR_MSG_ID_SRV_SMS_ATCMD_CMGD_IND:
    case PTR_MSG_ID_SRV_SMS_ATCMD_CMGW_IND:
    case PTR_MSG_ID_SRV_SMS_ATCMD_EQSI_IND:
    case PTR_MSG_ID_SRV_SMS_ATCMR_CGSMS_IND:
    case PTR_MSG_ID_SRV_SMS_ATCMR_CSAS_IND:
        event_id = EVT_ID_SRV_SMS_PS_AT_IND;
    default:
        break;
    }
    if (event_id != EVT_ID_SRV_SMS_BEGIN)
    {
        srv_sms_handle_sms_normal_ind(event_id, sim_id, msg->oslMsgId, inMsg);
    }
    
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_interl_handle_sim_rsp
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_interl_handle_sim_rsp(void *inMsg, U32 msg_id, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    srv_sms_disp_cb_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < SRV_SMS_MAX_ACTION; i++)
    {
        if (srv_sms_sim_cb_data[i].msg_id == msg_id && srv_sms_sim_cb_data[i].sim_id == sim_id)
        {
            SrvSmsDispCallbackFunc callback = srv_sms_sim_cb_data[i].callback;
            callback_data.data= inMsg;
            callback_data.user_data = srv_sms_sim_cb_data[i].user_data;
            callback_data.msg_id= msg_id;
            callback_data.sim_id = sim_id;
            srv_sms_delete_disp_action(i);
            if (callback)
            {
                callback(&callback_data);
            }
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_sim_rsp
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_handle_sim_rsp(void *inMsg, int mod_dest, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE * msg = (MYQUEUE *)Message;
    srv_sms_sim_enum sim_id = srv_sms_get_sim_id_by_module(mod_dest);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_interl_handle_sim_rsp(inMsg, msg->oslMsgId, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mapping_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_index      [IN]        
 *  data            [IN]         
 *  sim_id          [IN]                
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_sms_get_mapping_msg_id(
            srv_sms_sim_file_index_enum file_index,
            MMI_BOOL is_read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_index >= SRV_SMS_FILE_INDEX_ALL)
    {
        MMI_ASSERT(0);
    }
    if (is_read == MMI_TRUE)
    {
        return read_map[file_index];
    }
    else
    {
        return write_map[file_index];
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_rsp_mapping_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *                  
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_sms_get_rsp_mapping_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 rsp_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (msg_id)
    {
        case PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP;
            break;

    #ifdef __MMI_MSG_REL4_SUPPORT__
        case PRT_MSG_ID_MMI_SMS_GET_MBI_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_MBI_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_GET_MSP_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_MSP_RSP;
            break;
    #endif /* __MMI_MSG_REL4_SUPPORT__ */

        case PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_SET_MSG_WAITING_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_MSG_WAITING_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP;
            break;

    #ifdef __MMI_MSG_REL4_SUPPORT__
        case PRT_MSG_ID_MMI_SMS_SET_MBI_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_MBI_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_SET_MSP_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_MSP_RSP;
            break;
    #endif /* __MMI_MSG_REL4_SUPPORT__ */

        case PRT_MSG_ID_MMI_CB_SUBSCRIBE_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_CB_SUBSCRIBE_RSP;
            break;
            
        case PRT_MSG_ID_MMI_SMS_SET_CB_MODE_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP;
            break;

        case PRT_MSG_ID_MMI_SMS_GET_CB_MODE_REQ:
            rsp_msg_id = PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP;
            break;

        default:
            rsp_msg_id = 0;
            break;
    }

    return rsp_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_disp_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_index      [IN]        
 *  data            [?]         
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_sms_add_disp_action(
            srv_sms_sim_file_index_enum file_index,
            srv_sms_sim_enum sim_id,
            U32 msg_id,
            SrvSmsDispCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_curr_action_num == SRV_SMS_MAX_ACTION - 1)
    {
        return SRV_SMS_INVALID_ACCESS_ID;
    }
    else
    {
        srv_sms_sim_cb_data[srv_sms_curr_action_num].callback = callback;
        srv_sms_sim_cb_data[srv_sms_curr_action_num].user_data = user_data;
        srv_sms_sim_cb_data[srv_sms_curr_action_num].sim_id = sim_id;
        srv_sms_sim_cb_data[srv_sms_curr_action_num].file_index = file_index;
        srv_sms_sim_cb_data[srv_sms_curr_action_num].isUsed = MMI_TRUE;
        srv_sms_sim_cb_data[srv_sms_curr_action_num++].msg_id = srv_sms_get_rsp_mapping_msg_id(msg_id);        
    }
    
    return srv_sms_curr_action_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_disp_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_index      [IN]        
 *  data            [?]         
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_delete_disp_action(U8 action_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(action_number <= SRV_SMS_MAX_ACTION);   
    if (action_number == srv_sms_curr_action_num)
    {
        memset(&srv_sms_sim_cb_data[action_number],0, sizeof(srv_sms_sim_struct));
    }
    else
    {
        memcpy(&srv_sms_sim_cb_data[action_number], &srv_sms_sim_cb_data[action_number + 1], (srv_sms_curr_action_num - action_number ) * sizeof(srv_sms_sim_struct));
    }
    srv_sms_curr_action_num--; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_disp_send_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg      [IN]        
 *  data            [IN]         
 *  callback          [IN]
 *  user_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void srv_sms_disp_send_msg_req(
        U32 msg_id,
        srv_sms_sim_enum sim_id,
        void *data)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type mod_type = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_id == SRV_SMS_SIM_2)
    {
        mod_type = MOD_L4C_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)    
    else if (sim_id == SRV_SMS_SIM_3)
    {
        mod_type = MOD_L4C_3;
    }
#endif    
#if (MMI_MAX_SIM_NUM >= 4)    
    else if (sim_id == SRV_SMS_SIM_4)
    {
        mod_type = MOD_L4C_4;
    }
#endif    
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
    SRV_SMS_SEND_ILM(mod_type, msg_id, data);     
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_sim_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_index      [IN]        
 *  data            [?]         
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_write_sim_req(
            srv_sms_sim_file_index_enum file_index,
            U16 record_index,
            U16 record_size,            
            void *data,
            srv_sms_sim_enum sim_id,
            SrvSmsDispCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = srv_sms_get_mapping_msg_id(file_index, MMI_FALSE);
    void *dataPtr = NULL;
    U8 access_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    access_id = srv_sms_add_disp_action(file_index, sim_id, msg_id, callback, user_data);

    if (access_id == SRV_SMS_INVALID_ACCESS_ID)
    {
        return MMI_FALSE;
    }
    if (record_size > 0)
    {
        dataPtr = (void*) OslConstructDataPtr(record_size);
        memcpy(dataPtr, data, record_size);
    }
    else
    {
        dataPtr = data;
    }
    srv_sms_disp_send_msg_req(msg_id, sim_id, dataPtr); 
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_sim_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_index      [IN]        
 *  data            [?]         
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_read_sim_req(
            srv_sms_sim_file_index_enum file_index,
            U16 record_index,
            U16 record_size,
            srv_sms_sim_enum sim_id,
            SrvSmsDispCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *dataPtr = NULL;
    U8 access_id;
    U32 msg_id = srv_sms_get_mapping_msg_id(file_index, MMI_TRUE);    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    access_id = srv_sms_add_disp_action(file_index, sim_id, msg_id, callback, user_data);

    if (access_id == SRV_SMS_INVALID_ACCESS_ID)
    {
        return MMI_FALSE;
    }
    if (msg_id == PRT_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ)
    {
        dataPtr = (void*) OslConstructDataPtr(sizeof(mmi_sms_get_profile_params_req_struct));
        ((mmi_sms_get_profile_params_req_struct*)dataPtr)->profile_no = (kal_uint8)record_index;
    }
    srv_sms_disp_send_msg_req(msg_id, sim_id, dataPtr);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_send_sms(void *data, srv_sms_sim_enum sim_id, SrvSmsDispCallbackFunc callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    mmi_sms_send_pdu_msg_req_struct *msgreq;
    U8 chanel = srv_sms_get_index_by_sim_id(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SMS_MAX_SEND_NUM; i++)
    {
        if (srv_sms_send_cb_data[chanel][i].isUsed == MMI_FALSE)
        {
            break;
        }
    }
    if (i == SRV_SMS_MAX_SEND_NUM)
    {
        return MMI_FALSE;
    }
    srv_sms_send_cb_data[chanel][i].msg_id = PTR_MSG_ID_SRV_SMS_SEND_PDU_SMS_MSG_REQ;
    srv_sms_send_cb_data[chanel][i].callback = callback;
    srv_sms_send_cb_data[chanel][i].user_data = user_data;
    srv_sms_send_cb_data[chanel][i].isUsed = MMI_TRUE;
    msgreq = (mmi_sms_send_pdu_msg_req_struct*) OslConstructDataPtr(sizeof(mmi_sms_send_pdu_msg_req_struct));
    msgreq->data_len = ((mmi_sms_send_pdu_msg_req_struct *)data)->data_len;
    msgreq->mms_mode = ((mmi_sms_send_pdu_msg_req_struct *)data)->mms_mode;
    msgreq->reply_index = ((mmi_sms_send_pdu_msg_req_struct *)data)->reply_index;
    msgreq->length = ((mmi_sms_send_pdu_msg_req_struct *)data)->length;
    memcpy(msgreq->pdu, ((mmi_sms_send_pdu_msg_req_struct *)data)->pdu, 176);
    msgreq->source_id = source_seq_num[i][0];
    msgreq->seq_num = source_seq_num[i][1];
    srv_sms_disp_send_msg_req(PTR_MSG_ID_SRV_SMS_SEND_PDU_SMS_MSG_REQ, sim_id, msgreq);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_abort_sendig_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_abort_sendig_sms(void *data, srv_sms_sim_enum sim_id, SrvSmsDispCallbackFunc callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    mmi_sms_abort_req_struct *msgreq;
    U8 chanel = srv_sms_get_index_by_sim_id(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SMS_MAX_SEND_NUM; i++)
    {
        if (srv_sms_send_cb_data[chanel][i].user_data == user_data && srv_sms_send_cb_data[chanel][i].isUsed == MMI_TRUE)
        {
            break;
        }
    }
    if (i == SRV_SMS_MAX_SEND_NUM)
    {
        srv_sms_disp_cb_struct cb_data;
        mmi_sms_send_abort_finish_ind_struct abort_rsp;

        abort_rsp.result = MMI_FALSE;        
        cb_data.user_data = user_data;
        cb_data.data = &abort_rsp;
        if (callback)
        {
            callback(&cb_data);
        }
        
        return MMI_FALSE;
    }
    srv_sms_send_cb_data[chanel][i].msg_id = PRT_MSG_ID_MMI_SMS_ABORT_REQ;
    srv_sms_send_cb_data[chanel][i].callback = callback;

    msgreq = (mmi_sms_abort_req_struct*) OslConstructDataPtr(sizeof(mmi_sms_abort_req_struct));
    msgreq->source_id = source_seq_num[i][0];
    msgreq->seq_num = source_seq_num[i][1];
    srv_sms_disp_send_msg_req(PRT_MSG_ID_MMI_SMS_ABORT_REQ, sim_id, msgreq);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_disp_send_sms_rsp
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_disp_send_sms_rsp(void *inMsg, int mod_dest, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = ((MYQUEUE *)Message)->oslMsgId;
    srv_sms_sim_enum sim_id = srv_sms_get_sim_id_by_module(mod_dest);


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_handle_sms_send_rsp(sim_id, msg_id, inMsg);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_sms_send_rsp
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_handle_sms_send_rsp(srv_sms_sim_enum sim_id, U32 msg_id, void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 channel = 0;
    U8 source_id = 0;
    U8 seq_num = 0;
    srv_sms_disp_cb_struct cb_data;
    U8 sim = srv_sms_get_index_by_sim_id(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == PTR_MSG_ID_SRV_SMS_SEND_PDU_SMS_MSG_RSP)
    {
        source_id = ((mmi_sms_send_pdu_msg_rsp_struct *)inMsg)->source_id;
        seq_num = ((mmi_sms_send_pdu_msg_rsp_struct *)inMsg)->seq_num;
    }
    else if (msg_id == PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND)
    {
        source_id = ((mmi_sms_send_abort_finish_ind_struct *)inMsg)->source_id;
        seq_num = ((mmi_sms_send_abort_finish_ind_struct *)inMsg)->seq_num;    
    }
    channel = source_id + seq_num;
    if (msg_id == PTR_MSG_ID_SRV_SMS_SEND_PDU_SMS_MSG_RSP && srv_sms_send_cb_data[sim][channel].msg_id == PRT_MSG_ID_MMI_SMS_ABORT_REQ)
    {
        return;
    }
    if (srv_sms_send_cb_data[sim][channel].isUsed == MMI_TRUE)
    {
        srv_sms_send_cb_data[sim][channel].isUsed = MMI_FALSE;
        if (srv_sms_send_cb_data[sim][channel].callback)
        {
            cb_data.data = inMsg;
            cb_data.user_data = srv_sms_send_cb_data[sim][channel].user_data;
            srv_sms_send_cb_data[sim][channel].callback(&cb_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_disp_send_abort_sms_rsp
 * DESCRIPTION
 *  Handle send abort indication
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_disp_send_abort_sms_rsp(void *inMsg, int mod_dest, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = ((MYQUEUE *)Message)->oslMsgId;
    srv_sms_sim_enum sim_id = srv_sms_get_sim_id_by_module(mod_dest);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_handle_sms_send_rsp(sim_id, msg_id, inMsg);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sim_id_by_module
 * DESCRIPTION
 *  Handle new SMS indication
 * PARAMETERS
 *  mod_dest       [IN]        module id
 * RETURNS
 *  void
 *****************************************************************************/
static srv_sms_sim_enum srv_sms_get_sim_id_by_module(int mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if (MMI_MAX_SIM_NUM >= 2)
    if (mod_dest == MOD_L4C_2)
    {
        sim_id = SRV_SMS_SIM_2;
    }
 #if (MMI_MAX_SIM_NUM >= 3)   
    else if (mod_dest == MOD_L4C_3)
    {
        sim_id = SRV_SMS_SIM_3;
    }
 #endif
 #if (MMI_MAX_SIM_NUM >= 4)
    else if (mod_dest == MOD_L4C_4)
    {
        sim_id = SRV_SMS_SIM_4;
    }
 #endif   
 #endif        /*  (MMI_MAX_SIM_NUM >= 2) */    
    return sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_index_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS        
 *  sim_id          [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_sms_get_index_by_sim_id(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_id == SRV_SMS_SIM_2)
    {
        index = 1;
    }
#if (MMI_MAX_SIM_NUM >= 3)        
    else if (sim_id == SRV_SMS_SIM_3)
    {
        index = 2;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)        
    else if (sim_id == SRV_SMS_SIM_4)
    {
        index = 3;
    }
#endif    
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
    
    return index;
}
#endif /* __MOD_SMSAL__ */ 

