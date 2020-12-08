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
 *  SimAccessSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM access Service Handler
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
/**************************************************************
* Header Files Include
**************************************************************/
#include "ProtocolEvents.h"
#include "SimAccessSrvGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "sim_common_enums.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "MMI_features.h"
#include "stack_config.h"
#include "mmi_msg_struct.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "string.h"
/**************************************************************
* MARCO
**************************************************************/
#define SRV_SIM_INVALID_ACCESS_ID              0xFF

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    SrvSimCallbackFunc callback;
    void *user_data;
    srv_sim_action_enum action;
    mmi_sim_enum sim_id;
    MMI_BOOL isUsed;
} srv_sim_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/
static srv_sim_struct srv_sim_data[SRV_SIM_MAX_ACCESS];

/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
static U8 srv_sim_action_num = 0;

/**************************************************************
* Static Function Declaration
**************************************************************/
static MMI_BOOL srv_sim_handle_sim_rsp(void *inMsg, int mod_dest, void *Message);
static MMI_BOOL srv_sim_interl_handle_sim_rsp(void *inMsg, U32 msg_id, mmi_sim_enum sim_id);
static U8 srv_sim_add_action_list(
            sim_file_index_enum file_index,
            mmi_sim_enum sim_id,
            srv_sim_action_enum action,
            SrvSimCallbackFunc callback,
            void *user_data);
static void srv_sim_send_message(mmi_sim_enum sim_id, U16 msg_id, void *local_ptr);

/**************************************************************
* Function Defination
**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sim_acess_init
 * DESCRIPTION
 *  SIM access Service init function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sim_acess_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_WRITE_SIM_RSP, (PsIntFuncPtr) srv_sim_handle_sim_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_READ_SIM_RSP, (PsIntFuncPtr) srv_sim_handle_sim_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_FILE_INFO_RSP, (PsIntFuncPtr) srv_sim_handle_sim_rsp, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_handle_sim_rsp
 * DESCRIPTION
 *  Handle SIM access respond function
 * PARAMETERS
 *  inMsg           [IN]        Input message
 *  mod_dest        [IN]        
 *  Message         [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sim_handle_sim_rsp(void *inMsg, int mod_dest, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *msg = (MYQUEUE*) Message;
    mmi_sim_enum sim_id = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (MMI_MAX_SIM_NUM >=2)
    if (mod_dest == MOD_L4C_2)
    {
        sim_id = MMI_SIM2;
    }
#if (MMI_MAX_SIM_NUM >=3)
	else if (mod_dest == MOD_L4C_3)
	{
		sim_id = MMI_SIM3;
	}
#endif
#if (MMI_MAX_SIM_NUM >=4)
	else if (mod_dest == MOD_L4C_4)
	{
		sim_id = MMI_SIM4;
	}
#endif
 #endif /* MMI_MAX_SIM_NUM >=2 */
    return srv_sim_interl_handle_sim_rsp(inMsg, msg->oslMsgId, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_interl_handle_sim_rsp
 * DESCRIPTION
 *  Handle SIM access respond function
 * PARAMETERS
 *  inMsg       [IN]        Input message
 *  msg_id      [IN]        
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sim_interl_handle_sim_rsp(void *inMsg, U32 msg_id, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 access_id = 0;
    srv_sim_cb_struct callback_data;
    void *data = NULL;
    void *file_data = NULL;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == MSG_ID_MMI_SMU_WRITE_SIM_RSP)
    {
        mmi_smu_write_sim_rsp_struct *sim_data = (mmi_smu_write_sim_rsp_struct*) inMsg;

        access_id = sim_data->access_id;
        if (access_id == 0 || access_id > SRV_SIM_MAX_ACCESS)
        {
            return MMI_FALSE;
        }
        else
        {
            access_id--;
        }
        msg_id = MSG_ID_MMI_SMU_WRITE_SIM_REQ;
        callback_data.result = sim_data->result;
        callback_data.cause = sim_data->cause;
        callback_data.data = NULL;
    }
    else if (msg_id == MSG_ID_MMI_SMU_READ_SIM_RSP)
    {
        mmi_smu_read_sim_rsp_struct *sim_data = (mmi_smu_read_sim_rsp_struct*) inMsg;

        access_id = sim_data->access_id;
        if (access_id == 0 || access_id > SRV_SIM_MAX_ACCESS)
        {
            return MMI_FALSE;
        }
        else
        {
            access_id --;
        }
        msg_id = MSG_ID_MMI_SMU_READ_SIM_REQ;
        if (sim_data->result.flag == L4C_OK)
        {
            callback_data.result = MMI_TRUE;
            callback_data.cause = SIM_CMD_SUCCESS;
        }
        else
        {
            callback_data.result = MMI_FALSE;
            callback_data.cause = sim_data->result.cause;
        }

        data = (void*)OslMalloc(sizeof(srv_sim_data_struct));
        ((srv_sim_data_struct*) data)->length = sim_data->length;
        if (sim_data->length > 0)
        {
            file_data = OslMalloc(sim_data->length);
            memcpy(file_data, sim_data->data, sim_data->length);
            ((srv_sim_data_struct*) data)->data = file_data;
        }
        callback_data.data = data;
    }
    else if (msg_id == MSG_ID_MMI_SMU_READ_FILE_INFO_RSP)
    {
        mmi_smu_read_file_info_rsp_struct *sim_data = (mmi_smu_read_file_info_rsp_struct*) inMsg;

        access_id = sim_data->access_id;
        if (access_id == 0 || access_id > SRV_SIM_MAX_ACCESS)
        {
            return MMI_FALSE;
        }
        else
        {
            access_id --;
        }
        msg_id = MSG_ID_MMI_SMU_READ_FILE_INFO_REQ;
        if (sim_data->result.flag == L4C_OK)
        {
            callback_data.result = MMI_TRUE;
            callback_data.cause = SIM_CMD_SUCCESS;
        }
        else
        {
            callback_data.result = MMI_FALSE;
            callback_data.cause = sim_data->result.cause;
        }
        data = (void*)OslMalloc(sizeof(srv_sim_file_info_struct));
        ((srv_sim_file_info_struct*) data)->file_size = sim_data->file_size;
        ((srv_sim_file_info_struct*) data)->num_of_rec = sim_data->num_of_rec;
        ((srv_sim_file_info_struct*) data)->file_type = sim_data->file_type;
        callback_data.data = data;
    }

    if ( srv_sim_data[access_id].sim_id == sim_id && srv_sim_data[access_id].isUsed)
    {
        SrvSimCallbackFunc callback = srv_sim_data[access_id].callback;

        callback_data.user_data = srv_sim_data[access_id].user_data;
        callback_data.action = srv_sim_data[access_id].action;
        callback_data.sim_id = sim_id;
        memset(&srv_sim_data[access_id], 0, sizeof(srv_sim_struct));
        srv_sim_action_num--;
        if (callback)
        {
            callback(&callback_data);
        }
        ret = MMI_TRUE;
    }
    if (data != NULL)
    {
        OslMfree(data);
    }
    if (file_data != NULL)
    {
        OslMfree(file_data);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_add_action_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_index      [IN]        
 *  sim_id          [IN]        
 *  action          [IN]        
 *  callback        [IN]        
 *  user_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_sim_add_action_list(
            sim_file_index_enum file_index,
            mmi_sim_enum sim_id,
            srv_sim_action_enum action,
            SrvSimCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 access_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_action_num == SRV_SIM_MAX_ACCESS)
    {
        return SRV_SIM_INVALID_ACCESS_ID;
    }
    else
    {
        if (srv_sim_action_num > 0 && srv_sim_data[srv_sim_action_num - 1].isUsed == MMI_FALSE)
        {
            access_id = srv_sim_action_num - 1;
        }
        else
        {
            U8 i = 0;

            for (i = 0; i < SRV_SIM_MAX_ACCESS; i++)
            {
                if (srv_sim_data[i].isUsed == MMI_FALSE)
                {
                    access_id = i;
                    break;
                }
            }
        }
        srv_sim_data[access_id].callback = callback;
        srv_sim_data[access_id].user_data = user_data;
        srv_sim_data[access_id].sim_id = sim_id;
        srv_sim_data[access_id].isUsed = MMI_TRUE;
        srv_sim_data[access_id].action = action;
    }
    srv_sim_action_num++;

    return access_id + 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_send_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id          [IN]        
 *  msg_id          [IN]        
 *  local_ptr       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_send_message(mmi_sim_enum sim_id, U16 msg_id, void *local_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type mod_type = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >=2)
    if (sim_id == MMI_SIM2)
    {
        mod_type = MOD_L4C_2;
    }

#if (MMI_MAX_SIM_NUM >=3)
   else if (sim_id == MMI_SIM3)
   {
	    mod_type = MOD_L4C_3;
   }

#endif
#if (MMI_MAX_SIM_NUM >=4)
   else if (sim_id == MMI_SIM4)
    {
 	    mod_type = MOD_L4C_4;
    }

#endif
#endif /* MMI_MAX_SIM_NUM  >=2 */ 
    mmi_frm_send_ilm((oslModuleType)mod_type, (oslMsgType)msg_id, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_read_record
 * DESCRIPTION
 *  Handle SIM access respond function
 * PARAMETERS
 *  file_index          [IN]        
 *  file_path           [IN]         
 *  record_index        [IN]        
 *  record_size         [IN]        
 *  sim_id              [IN]        
 *  callback            [IN]        
 *  user_data           [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sim_read_record(
            U16 file_index,
            U8 *file_path,
            U16 record_index,
            U16 record_size,
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *dataPtr = NULL;
    U8 access_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    access_id = srv_sim_add_action_list((sim_file_index_enum)file_index, sim_id, SRV_SIM_READ_RECORD, callback, user_data);

    if (access_id == SRV_SIM_INVALID_ACCESS_ID)
    {
        return MMI_FALSE;
    }
    dataPtr = (void*)OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    ((mmi_smu_read_sim_req_struct*) dataPtr)->file_idx = file_index;
    if (file_path != NULL)
    {
        memcpy(((mmi_smu_read_sim_req_struct*) dataPtr)->path, file_path, 6);
    }
    else
    {
        memset(((mmi_smu_read_sim_req_struct*) dataPtr)->path, 0, 6);
    }
    ((mmi_smu_read_sim_req_struct*) dataPtr)->para = record_index;
    ((mmi_smu_read_sim_req_struct*) dataPtr)->length = record_size;
    ((mmi_smu_read_sim_req_struct*) dataPtr)->access_id = access_id;
    srv_sim_send_message(sim_id, MSG_ID_MMI_SMU_READ_SIM_REQ, dataPtr);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_read_binary
 * DESCRIPTION
 *  Handle SIM access respond function
 * PARAMETERS
 *  file_index      [IN]        
 *  file_path       [IN]         
 *  offset          [IN]        
 *  length          [IN]        
 *  sim_id          [IN]        
 *  callback        [IN]        
 *  user_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sim_read_binary(
            U16 file_index,
            U8 *file_path,
            U16 offset,
            U16 length,
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *dataPtr = NULL;
    U8 access_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    access_id = srv_sim_add_action_list((sim_file_index_enum)file_index, sim_id, SRV_SIM_READ_BINARY, callback, user_data);

    if (access_id == SRV_SIM_INVALID_ACCESS_ID)
    {
        return MMI_FALSE;
    }
    dataPtr = (void*)OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    ((mmi_smu_read_sim_req_struct*) dataPtr)->file_idx = file_index;
    if (file_path != NULL)
    {
        memcpy(((mmi_smu_read_sim_req_struct*) dataPtr)->path, file_path, 6);
    }
    else
    {
        memset(((mmi_smu_read_sim_req_struct*) dataPtr)->path, 0, 6);
    }
    ((mmi_smu_read_sim_req_struct*) dataPtr)->para = offset;
    ((mmi_smu_read_sim_req_struct*) dataPtr)->length = length;
    ((mmi_smu_read_sim_req_struct*) dataPtr)->access_id = access_id;
    srv_sim_send_message(sim_id, MSG_ID_MMI_SMU_READ_SIM_REQ, dataPtr);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_write_record
 * DESCRIPTION
 *  Handle SIM access respond function
 * PARAMETERS
 *  file_index          [IN]        
 *  file_path           [IN]         
 *  record_index        [IN]        
 *  record_size         [IN]        
 *  data                [IN]         
 *  sim_id              [IN]        
 *  callback            [IN]        
 *  user_data           [IN]      
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sim_write_record(
            U16 file_index,
            U8 *file_path,
            U16 record_index,
            U16 record_size,
            U8 *data,
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *dataPtr = NULL;
    U8 access_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_size > 255)
    {
        return MMI_FALSE;
    }
    access_id = srv_sim_add_action_list((sim_file_index_enum)file_index, sim_id, SRV_SIM_WRITE_RECORD, callback, user_data);

    if (access_id == SRV_SIM_INVALID_ACCESS_ID)
    {
        return MMI_FALSE;
    }
    dataPtr = (void*)OslConstructDataPtr(sizeof(mmi_smu_write_sim_req_struct));
    ((mmi_smu_write_sim_req_struct*) dataPtr)->file_idx = file_index;
    if (file_path != NULL)
    {
        memcpy(((mmi_smu_write_sim_req_struct*) dataPtr)->path, file_path, 6);
    }
    else
    {
        memset(((mmi_smu_write_sim_req_struct*) dataPtr)->path, 0, 6);
    }
    ((mmi_smu_write_sim_req_struct*) dataPtr)->para = (U8)record_index;
    ((mmi_smu_write_sim_req_struct*) dataPtr)->length = record_size;

    ((mmi_smu_write_sim_req_struct*) dataPtr)->access_id = access_id;
    if (data != NULL && record_size != 0)
    {
        memcpy(((mmi_smu_write_sim_req_struct*) dataPtr)->data, data, record_size);
    }
    srv_sim_send_message(sim_id, MSG_ID_MMI_SMU_WRITE_SIM_REQ, dataPtr);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_write_binary
 * DESCRIPTION
 *  Write binary data to SIM 
 * PARAMETERS
 *  file_index      [IN]        file index,  refer to sim_file_index_enum      
 *  file_path       [IN]         file path, refer to sim_file_id_enum       
 *  offset          [IN]        
 *  length          [IN]        
 *  data            [IN]         
 *  sim_id          [IN]        sim id, refer to mmi_sim_enum, only valid from dual sim project         
 *  callback        [IN]        callback function
 *  user_data       [IN]        user data 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sim_write_binary(
            U16 file_index,
            U8 *file_path,
            U16 offset,
            U16 length,
            void *data,
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *dataPtr = NULL;
    U8 access_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length > 255)
    {
        return MMI_FALSE;
    }
    access_id = srv_sim_add_action_list((sim_file_index_enum)file_index, sim_id, SRV_SIM_WRITE_BIANRY, callback, user_data);
    if (access_id == SRV_SIM_INVALID_ACCESS_ID)
    {
        return MMI_FALSE;
    }
    dataPtr = (void*)OslConstructDataPtr(sizeof(mmi_smu_write_sim_req_struct));
    ((mmi_smu_write_sim_req_struct*) dataPtr)->file_idx = file_index;
    if (file_path != NULL)
    {
        memcpy(((mmi_smu_write_sim_req_struct*) dataPtr)->path, file_path, 6);
    }
    else
    {
        memset(((mmi_smu_write_sim_req_struct*) dataPtr)->path, 0, 6);
    }
    ((mmi_smu_write_sim_req_struct*) dataPtr)->para = (U8)offset;
    ((mmi_smu_write_sim_req_struct*) dataPtr)->length = length;
    ((mmi_smu_write_sim_req_struct*) dataPtr)->access_id = access_id;
    if (data != NULL && length != 0)
    {
        memcpy(((mmi_smu_write_sim_req_struct*) dataPtr)->data, data, length);
    }
    srv_sim_send_message(sim_id, MSG_ID_MMI_SMU_WRITE_SIM_REQ, dataPtr);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_get_file_info
 * DESCRIPTION
 *  Get SIM file information
 * PARAMETERS
 *  file_index      [IN]        file index,  refer to sim_file_index_enum,  caller only need to set one of file_index and file_path 
 *  file_path       [IN]         file path, refer to sim_file_id_enum
 *  sim_id          [IN]        sim id, refer to mmi_sim_enum, only valid from dual sim project
 *  callback        [IN]        callback function
 *  user_data       [IN]         user data
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sim_get_file_info(
            U16 file_index,
            U8 *file_path,
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *dataPtr = NULL;
    U8 access_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    access_id = srv_sim_add_action_list((sim_file_index_enum)file_index, sim_id, SRV_SIM_GET_FILE_INF, callback, user_data);

    if (access_id == SRV_SIM_INVALID_ACCESS_ID)
    {
        return MMI_FALSE;
    }
    dataPtr = (void*)OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    ((mmi_smu_read_file_info_req_struct*) dataPtr)->file_idx = file_index;
    if (file_path != NULL)
    {
        memcpy(((mmi_smu_read_file_info_req_struct*) dataPtr)->path, file_path, 6);
    }
    else
    {
        memset(((mmi_smu_read_file_info_req_struct*) dataPtr)->path, 0, 6);
    }
    ((mmi_smu_read_file_info_req_struct*) dataPtr)->access_id = access_id;
    srv_sim_send_message(sim_id, PRT_MMI_SMU_READ_FILE_INFO_REQ, dataPtr);

    return MMI_TRUE;
}

