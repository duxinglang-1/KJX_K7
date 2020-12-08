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

/*******************************************************************************
 * Filename:
 * ---------
 *  jwa_sms.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *==============================================================================
 *******************************************************************************/

#include "jal.h"

#ifdef SUPPORT_JSR_120
#include "mmi_frm_gprot.h"

#include "mnsms_struct.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"
#include "browser_struct.h"

#define MMIAPI_USING_SMS
#define MMIAPI_USING_BLOCKING
#define SMSQUEUE_DIR ("sms_queue")
#define SMSQUEUE_FILE ("sms_queue\\sms_queuefile.txt")
#define SMSQUEUE_TEMP_FILE  ("sms_queue\\sms_queuefile_temp.txt")
#define SMSQUEUE_SMS_HEADER_SIZE (30)
#define SMSQUEUE_FILE_HEADER_SIZE (5)
#define SMSQUEUE_MAX_FILE_SIZE (5 * 1024)
#define JAVA_SMS_MAX_PORT_NUM (14)

#include "mmiapi_struct.h"
#include "mmiapi_enum.h"
#include "mmiapi.h"

#include "ems.h"
//#include "pushregistry.h"
#include "j2me_trace.h"
//#include "machine_md.h"

#include "jal_internal.h"
#include "jam_msg_handler.h"
#include "jvm_resource_manager.h" //20101104,changed resource mgr for MVM

#include "jwa_internal.h"
#include "jam_internal.h"
#include "SmsSrvGprot.h"
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
#include "FileMgrSrvGProt.h"
#endif

extern int J2ME_sms_unregister_by_resource_manager(int portNumber);

extern float mmi_dt_get_tz(void);


kal_char j2me_sms_smsc_addr[SRV_SMS_MAX_ADDR_LEN + 1] = {0};
kal_bool flag_wait_async_sms_msgid;
kal_uint32 J2ME_async_sms_msgid;
extern kal_eventgrpid g_java_event_group_1;
extern kal_mutexid g_jam_async_sms_mutex; 
extern kal_mutexid g_jam_async_sms_mvm_mutex; 

#if (MMI_MAX_SIM_NUM >= 2)
extern int J2ME_sms_register_sim_type(long portNumber, int type, kal_uint8 sim_type, kal_bool need_result, kal_int32 vm_id);
extern int J2ME_sms_unregister_sim_type(long portNumber, int type, kal_uint8 sim_type, kal_bool need_result, kal_int32 vm_id);
#endif
unsigned long readSmsAsyncEvent(void);

kal_int32 J2ME_sms_enqueue_sms(kal_char** pszError, int type,int len,
    int port, char *buf, kal_uint16 *addr, kal_uint8 addr_len, kal_uint8 *timestamp);
kal_uint8 *J2ME_sms_dequeue_sms(kal_char** pszError, int *type, int *len, 
	int dequeue_port, kal_bool delete_all);
kal_int32 J2ME_sms_check_smsqueue_without_remove(kal_char** pszError, int *type,
    int *len, int check_port, kal_uint16 *addr, kal_uint8 *timestamp, kal_bool only_new);
void J2ME_sms_load_recv_list();

static kal_bool j2me_sms_register_enable = KAL_TRUE;
static int j2me_sms_register_type = -1;
static int j2me_sms_register_port = -1;
static int j2me_sms_result = 0;
static int j2me_sms_receive_len = 0;
static void *j2me_sms_recceive_data_ptr = NULL;
static short j2me_sms_tel_num_ucs2[6 + MAX_CC_ADDR_LEN + 7];
static int jwa_sms_state = (int)JWA_SMS_STATE_IDLE;

void jwa_sms_init_smsc_addr(kal_int32 vm_id);
 
static kal_bool jwa_sms_mvm_init_result = KAL_FALSE;
static jwa_sms_pending_operation_struct j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM];
static kal_int32 j2me_sms_processing_task_vm_id = -1;
static void (*jwa_sms_call_back)(int , int , int ) = NULL; 

static J2me_sms_recv_num_struct j2me_sms_recv_num_list[JAVA_SMS_MAX_PORT_NUM];

static kal_bool sms_init_result = KAL_FALSE;


#if (MAX_VM_INSTANCE_NUM > 1)
/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_mvm_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_mvm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_async_sms_mvm_mutex);
    if (!jwa_sms_mvm_init_result)
    {
        for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
        {
            j2me_sms_mvm_pending_task[i].sms_req_ptr = NULL;
            j2me_sms_mvm_pending_task[i].pending_operation = JWA_SMS_STATE_IDLE;
            j2me_sms_mvm_pending_task[i].vm_id = -1;
        }
        jwa_sms_mvm_init_result = KAL_TRUE;
    }
    kal_give_mutex(g_jam_async_sms_mvm_mutex);
}

/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_mvm_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_mvm_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_async_sms_mvm_mutex);
    if (jwa_sms_mvm_init_result)
    {
        for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
        {
            if (j2me_sms_mvm_pending_task[i].pending_operation == JWA_SMS_STATE_SEND)
            {
                if (j2me_sms_mvm_pending_task[i].sms_req_ptr)
                {
                    if (((mmiapi_sms_send_req_struct*)(j2me_sms_mvm_pending_task[i].sms_req_ptr))->msg)
                    {
                        jvm_free(((mmiapi_sms_send_req_struct*)(j2me_sms_mvm_pending_task[i].sms_req_ptr))->msg);
                    }
                    free_local_para((local_para_struct*)j2me_sms_mvm_pending_task[i].sms_req_ptr);
                }
            }
            else if (j2me_sms_mvm_pending_task[i].pending_operation == JWA_SMS_STATE_REGISTER_PORT)
            {
                if (j2me_sms_mvm_pending_task[i].sms_req_ptr)
                {
                    free_local_para((local_para_struct*)j2me_sms_mvm_pending_task[i].sms_req_ptr);
                }
            }
            j2me_sms_mvm_pending_task[i].sms_req_ptr = NULL;
            j2me_sms_mvm_pending_task[i].pending_operation = JWA_SMS_STATE_IDLE;
            j2me_sms_mvm_pending_task[i].vm_id = -1;
        }
        jwa_sms_mvm_init_result = KAL_FALSE;
    }
    kal_give_mutex(g_jam_async_sms_mvm_mutex);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jwa_sms_register_callback
 * DESCRIPTION
 * register the callback function for SMS response. The first parameter of the call back function
 * is the message id getting from jwa_sms_get_response_primitive, such as MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP,
 * and the second parameter is channel id for channel ralitive messages, conneciton id (or request
 * id) for SMS write and read relative messages, or a dummy number for other messages.
 *  
 * PARAMETERS
 *  callback_ptr [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/ 
void jwa_sms_register_callback(void (*callback_ptr)(int , int , int)) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    jwa_sms_call_back = callback_ptr;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_deregister_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jwa_sms_deregister_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    jwa_sms_call_back = NULL;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_callback_handler
 * DESCRIPTION
 *  connect_id [IN]    connection ID
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void jwa_sms_callback_handler(int result, J2me_sms_reply_enum eventMsg , int vm_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (jwa_sms_call_back != NULL)
    { 
        (*jwa_sms_call_back)(result, eventMsg, vm_id); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_save_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_type        [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_save_result(int rsp_type, int result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rsp_type)
    {

        case MSG_J2ME_SMS_REGISTER_PORT_RSP:
        case MSG_J2ME_SMS_SEND_RSP:
        {
            j2me_sms_result = (kal_uint32) result ? 0 : -1;
        }
            break;

        default:
        {
            ASSERT(0);
        }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_free_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_free_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (j2me_sms_recceive_data_ptr != NULL)
    {
        free_ctrl_buffer(j2me_sms_recceive_data_ptr);
        j2me_sms_recceive_data_ptr = NULL;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  finalizeSms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void finalizeSms()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    J2ME_sms_free_data();
    jwa_sms_set_state(JWA_SMS_STATE_IDLE);
#if (MAX_VM_INSTANCE_NUM > 1)
    J2ME_sms_mvm_deinit();
#endif
    return;
}

#if (MAX_VM_INSTANCE_NUM > 1)
/*****************************************************************************
 * FUNCTION
 *  finalizeSmsByVM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void finalizeSmsByVM(int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_send_abort_req_struct *p = NULL;
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_async_sms_mvm_mutex);
    if (jwa_sms_get_state() != JWA_SMS_STATE_IDLE)
    {
        for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
        {
            if (j2me_sms_mvm_pending_task[i].vm_id == vm_id)
            {
                if (j2me_sms_mvm_pending_task[i].pending_operation == JWA_SMS_STATE_SEND)
                {
                    if (j2me_sms_mvm_pending_task[i].sms_req_ptr)
                    {
                        if (((mmiapi_sms_send_req_struct*)(j2me_sms_mvm_pending_task[i].sms_req_ptr))->msg)
                        {
                            jvm_free(((mmiapi_sms_send_req_struct*)(j2me_sms_mvm_pending_task[i].sms_req_ptr))->msg);
                        }
                        free_local_para((local_para_struct*)j2me_sms_mvm_pending_task[i].sms_req_ptr);
                    }
                }
                else if (j2me_sms_mvm_pending_task[i].pending_operation == JWA_SMS_STATE_REGISTER_PORT)
                {
                    if (j2me_sms_mvm_pending_task[i].sms_req_ptr)
                    {
                        free_local_para((local_para_struct*)j2me_sms_mvm_pending_task[i].sms_req_ptr);
                    }
                }

                for (j = i; j < MAX_VM_INSTANCE_NUM - 1; j++)
                {
                    j2me_sms_mvm_pending_task[j].sms_req_ptr = j2me_sms_mvm_pending_task[j + 1].sms_req_ptr;
                    j2me_sms_mvm_pending_task[j].pending_operation = j2me_sms_mvm_pending_task[j + 1].pending_operation;
                    j2me_sms_mvm_pending_task[j].vm_id = j2me_sms_mvm_pending_task[j + 1].vm_id;
                    if (j2me_sms_mvm_pending_task[j + 1].vm_id == -1)
                    {
                        break;
                    }
                }

                j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].sms_req_ptr = NULL;
                j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_SMS_STATE_IDLE;
                j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;
                break;
            }
        }
        
        if (j2me_sms_processing_task_vm_id == vm_id)
        {
            if (jwa_sms_get_state() == JWA_SMS_STATE_SEND)
            {
                p = NEW_LOCAL_PTR(mmiapi_sms_send_abort_req_struct);
				
                p->blocking_data = NULL;
				
                jwa_sms_set_state(JWA_SMS_STATE_SEND_ABORT);
				
                /* fake module */
                java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_SEND_ABORT_REQ, p);
            }
        }
    }
    else
    {
        j2me_sms_processing_task_vm_id = -1;
    }
	
    kal_give_mutex(g_jam_async_sms_mvm_mutex);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_record_pending_task
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool J2ME_sms_record_pending_task(kal_int32 vm_id,  local_para_struct *local_para_ptr, jwa_sms_state_enum state, char *pBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    if (j2me_sms_processing_task_vm_id != -1 && j2me_sms_processing_task_vm_id != vm_id)
    {
        if ( pBuffer != NULL )
        {
            mmiapi_sms_send_req_struct *p = (mmiapi_sms_send_req_struct*) local_para_ptr;
            int buflength = p->msg_length;
        
            free_ctrl_buffer(p->msg);
            p->msg = (kal_uint8*) jvm_malloc(buflength + 1);
            memset(p->msg, 0,  buflength + 1);
            memcpy(p->msg, pBuffer,  buflength);
        }    
    
        for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
        {
            if (j2me_sms_mvm_pending_task[i].vm_id == vm_id)
            {
                if (j2me_sms_mvm_pending_task[i].pending_operation == JWA_SMS_STATE_SEND)
                {
                    if (j2me_sms_mvm_pending_task[i].sms_req_ptr)
                    {
                        if (((mmiapi_sms_send_req_struct*)(j2me_sms_mvm_pending_task[i].sms_req_ptr))->msg)
                        {
                            jvm_free(((mmiapi_sms_send_req_struct*)(j2me_sms_mvm_pending_task[i].sms_req_ptr))->msg);
                        }
                        free_local_para((local_para_struct*)j2me_sms_mvm_pending_task[i].sms_req_ptr);
                    }
                }
                else if (j2me_sms_mvm_pending_task[i].pending_operation == JWA_SMS_STATE_REGISTER_PORT)
                {
                    if (j2me_sms_mvm_pending_task[i].sms_req_ptr)
                    {
                        free_local_para((local_para_struct*)j2me_sms_mvm_pending_task[i].sms_req_ptr);
                    }
                }
                j2me_sms_mvm_pending_task[i].pending_operation = state;
                j2me_sms_mvm_pending_task[i].sms_req_ptr = (void*) local_para_ptr;
                break;
            }
            else if (j2me_sms_mvm_pending_task[i].vm_id == -1)
            {
                j2me_sms_mvm_pending_task[i].vm_id = vm_id;
                j2me_sms_mvm_pending_task[i].pending_operation = state;
                j2me_sms_mvm_pending_task[i].sms_req_ptr = (void*) local_para_ptr;
                break;
            }
        }

         return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_process_pending_task
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_process_pending_task()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_PROCESS_PENDING_TASK, jam_mvm_get_current_vm_id(),
    j2me_sms_mvm_pending_task[0].vm_id, j2me_sms_mvm_pending_task[0].pending_operation);

    if (jam_mvm_get_current_vm_id() != -1 && j2me_sms_mvm_pending_task[0].vm_id != -1)
    {
        if (j2me_sms_mvm_pending_task[0].pending_operation == JWA_SMS_STATE_REGISTER_PORT)
        { 
            mmiapi_sms_register_port_rsp_struct *fake_rsp;
            mmiapi_sms_register_port_req_struct *p = (mmiapi_sms_register_port_req_struct*) (j2me_sms_mvm_pending_task[0].sms_req_ptr);
            long portNumber = (long) p->port_number;
            int ret;

            for (i = 0; i < MAX_VM_INSTANCE_NUM - 1; i++)
            {
                j2me_sms_mvm_pending_task[i].sms_req_ptr = j2me_sms_mvm_pending_task[i + 1].sms_req_ptr;
                j2me_sms_mvm_pending_task[i].pending_operation = j2me_sms_mvm_pending_task[i + 1].pending_operation;
                j2me_sms_mvm_pending_task[i].vm_id = j2me_sms_mvm_pending_task[i + 1].vm_id;
                if (j2me_sms_mvm_pending_task[i + 1].vm_id == -1)
                {
                    break;
                }
            }
            j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].sms_req_ptr = NULL;
            j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_SMS_STATE_IDLE;
            j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;

#ifdef __SUPPORT_JAVA_PUSH__
            ret = j2me_check_push_register_port(portNumber, WMA_REGISTRY, p->vm_id);
#else
            ret = NON_REGISTERED;
#endif

            if (p->enable)
            {
                if (ret == NON_REGISTERED || ret == J2ME_SMS_PORT_IN_USE_BY_PUSH)
                {
#if (MMI_MAX_SIM_NUM >= 2)
                    ret = J2ME_sms_register_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, p->vm_id);
#if (MMI_MAX_SIM_NUM >= 3)
                    if (ret == 0)
                    {
                        ret = J2ME_sms_register_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, p->vm_id);
                        if (ret == 0)
                        {
#if (MMI_MAX_SIM_NUM >= 4)
                             ret = J2ME_sms_register_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM4, KAL_TRUE, p->vm_id);
                             if (ret != 0)
                             {
                                 J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, p->vm_id);
                                 J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, p->vm_id);
                             }
#endif
                        }
                        else
                        {
                            J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, p->vm_id);
                        }
                    }
#endif
#endif                    
                    j2me_sms_register_enable = KAL_TRUE;
                    j2me_sms_register_type = WMA_REGISTRY;
                    j2me_sms_register_port = (int) portNumber;

                    j2me_sms_processing_task_vm_id = p->vm_id;
                    jwa_sms_set_state(JWA_SMS_STATE_REGISTER_PORT);
	                
#if (MMI_MAX_SIM_NUM >= 2)
                    if (ret == 0)
#endif
                    {
                        /* fake module */
                        java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);
                        return;
                    }   
                }
				
                j2me_sms_register_enable = KAL_TRUE;
                j2me_sms_register_port = (int) portNumber;
            }
            else
            {
                if ((ret != PUSH_REGISTERED) && (ret != PUSH_CONFLICT_REGISTERED) || (ret == J2ME_SMS_PORT_IN_USE_BY_PUSH))
                {
#if (MMI_MAX_SIM_NUM >= 2)
#if (MMI_MAX_SIM_NUM >= 4)
                    ret = J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM4, KAL_TRUE, p->vm_id);
                    if (ret != 0)
                    {
                         J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, p->vm_id);
                         J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, p->vm_id);
                         J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM1, KAL_TRUE, p->vm_id);
                    }
                    else
#endif
                    {
#if (MMI_MAX_SIM_NUM >= 3)
                        ret = J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, p->vm_id);
                        if (ret != 0)
                        {
                            J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, p->vm_id);
                            J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM1, KAL_TRUE, p->vm_id);
                        }
                        else
#endif
                        {
	                    ret = J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, p->vm_id);
                        }
                    }
#endif

                    j2me_sms_register_enable = KAL_FALSE;
                    j2me_sms_register_type = WMA_REGISTRY;

                    j2me_sms_processing_task_vm_id = p->vm_id;
                    jwa_sms_set_state(JWA_SMS_STATE_REGISTER_PORT);
	                
#if (MMI_MAX_SIM_NUM >= 2)
                    if (ret == 0)
#endif
                    {
                       //resouceDereg(JAVA_WMA_SMS_DEVICE, portNumber);    //20101104,changed resource mgr for MVM
                       jvm_resource_mgr_deregister(p->vm_id,JAVA_WMA_SMS_DEVICE,portNumber);
                       /* fake module */
                       java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);
                       return;
                    }
#if (MMI_MAX_SIM_NUM >= 2)
                    else
                    {
                        J2ME_sms_unregister_sim_type(portNumber, WMA_REGISTRY, JWA_SMS_SIM_TYPE_SIM1, KAL_TRUE, p->vm_id);
                    }
#endif
	        }
				
                j2me_sms_register_enable = KAL_FALSE;
	    }

            fake_rsp = NEW_LOCAL_PTR(mmiapi_sms_register_port_rsp_struct);
            fake_rsp->result = KAL_FALSE;
            fake_rsp->cause = 0;
            fake_rsp->vm_id = p->vm_id;

            j2me_sms_register_type = WMA_REGISTRY;
            j2me_sms_processing_task_vm_id = p->vm_id;
            jwa_sms_set_state(JWA_SMS_STATE_REGISTER_PORT);
			
            free_local_para((local_para_struct*) p);
            java_send_msg(MOD_JASYN_D, MOD_JASYN, 0, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP, fake_rsp);
        }
        else if (j2me_sms_mvm_pending_task[0].pending_operation == JWA_SMS_STATE_SEND)
        {
            mmiapi_sms_send_req_struct *p = (mmiapi_sms_send_req_struct*) (j2me_sms_mvm_pending_task[0].sms_req_ptr);
            kal_uint8 *temp_buffer = NULL;

            for (i = 0; i < MAX_VM_INSTANCE_NUM - 1; i++)
            {
                j2me_sms_mvm_pending_task[i].sms_req_ptr = j2me_sms_mvm_pending_task[i + 1].sms_req_ptr;
                j2me_sms_mvm_pending_task[i].pending_operation = j2me_sms_mvm_pending_task[i + 1].pending_operation;
                j2me_sms_mvm_pending_task[i].vm_id = j2me_sms_mvm_pending_task[i + 1].vm_id;
                if (j2me_sms_mvm_pending_task[i + 1].vm_id == -1)
                {
                    break;
                }
            }
            j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].sms_req_ptr = NULL;
            j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_SMS_STATE_IDLE;
            j2me_sms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;

	    temp_buffer = (kal_uint8*) get_ctrl_buffer((kal_uint16) (p->msg_length + 1));
	    memset(temp_buffer, 0, p->msg_length + 1);
	    memcpy(temp_buffer, p->msg, p->msg_length);
	    jvm_free(p->msg);
	    p->msg = temp_buffer;
			
            j2me_sms_processing_task_vm_id = p->vm_id;
	    jwa_sms_set_state(JWA_SMS_STATE_SEND);
	    /* fake module */
	    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_SEND_REQ, p);
        }
    }
    else
    {
        j2me_sms_processing_task_vm_id = -1;
        jwa_sms_set_state(JWA_SMS_STATE_IDLE);	
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_process_pending_task_by_controller
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_process_pending_task_by_controller()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM > 1)
    kal_trace(TRACE_INFO, WMA_SMS_PROCESS_PENDING_TASK_BY_CONTROLLER, j2me_sms_processing_task_vm_id, jwa_sms_get_state());
    
    kal_take_mutex(g_jam_async_sms_mvm_mutex);
    if (j2me_sms_processing_task_vm_id == -1 && jwa_sms_get_state() == JWA_SMS_STATE_IDLE)
    {
        J2ME_sms_process_pending_task();
    }
    kal_give_mutex(g_jam_async_sms_mvm_mutex);
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  readSmsAsyncEvent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long readSmsAsyncEvent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group, ret_msgid;
    kal_status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag_wait_async_sms_msgid = KAL_TRUE;

    result = kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_SMS_NOTIFY_RETREIVE, KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);

    if (result == KAL_NOT_PRESENT)
    {
        return (-2);    /* IO_WOULDBLOCK */
    }
    else
    {
        ret_msgid = J2ME_async_sms_msgid;
        J2ME_async_sms_msgid = 0;
        flag_wait_async_sms_msgid = KAL_FALSE;

        /* 2nd bit notify complete retreive async event */
        kal_set_eg_events(g_java_event_group_1, JAVA_EG_SMS_COMPLETE_RETREIVE, KAL_OR);

        return ret_msgid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_response_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_response_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    kal_int32 vm_id = -1; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (J2ME_async_sms_msgid && flag_wait_async_sms_msgid)
    {
        /* Pedning async event */
        kal_uint32 event_group, polling = 0;
        kal_status result;

        while (1)
        {
            /* 2nd bit indicate wait pending async event consumed */
            result = kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_SMS_COMPLETE_RETREIVE, KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);

            if (result != KAL_NOT_PRESENT || polling++ >= 100)
            {
                break;
            }
            /* To avoid deadlock and complicated timer control, use polling */
            kal_sleep_task(1);
        }
    }

    J2ME_async_sms_msgid = ilm_ptr->msg_id;
    
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP:
        {
            mmiapi_sms_register_port_rsp_struct *p = (mmiapi_sms_register_port_rsp_struct*) ilm_ptr->local_para_ptr;
 
            vm_id = p->vm_id;
            if (vm_id == -1)
            {
                J2ME_async_sms_msgid = 0;
                return;
            }
			
            if (j2me_sms_register_type == WMA_REGISTRY)
            {
                J2ME_sms_save_result(MSG_J2ME_SMS_REGISTER_PORT_RSP, (int)p->result);
            }

            /* Register */
            if (j2me_sms_register_enable == KAL_TRUE)
            {
                if ((j2me_sms_register_type == WMA_REGISTRY) && p->result)
                {
                    int res = 0;
                    
                    /* register success, and we should unregister port when VM shutdown */
                    //res = resouceRegistering(
                    //        JAVA_WMA_SMS_DEVICE,
                    //        (int)j2me_sms_register_port,
                    //        NULL,
                    //        NULL,
                    //        J2ME_sms_unregister_by_resource_manager);
                    //20101104,changed resource mgr for MVM
                    res = jvm_resource_mgr_register(
                            vm_id,
                            JAVA_WMA_SMS_DEVICE,
                            (int)j2me_sms_register_port,
                            NULL,
                            NULL,
                            J2ME_sms_unregister_by_resource_manager);
                    /* If registering resource fails, deregister to native SMS module and report error to Java layer. */
                    if (res == RESOUCE_FAIL)
                    {
                        J2ME_sms_unregister_by_resource_manager(j2me_sms_register_port);
                        J2ME_sms_save_result(MSG_J2ME_SMS_REGISTER_PORT_RSP, (int)(KAL_FALSE));
                    }
                }
                j2me_sms_register_enable = KAL_FALSE;
                j2me_sms_register_port = -1;
            }
            /* Unregister  */
            else
            {
                if (j2me_sms_register_type == PUSH_REGISTRY)
                {
                    j2me_sms_register_type = -1;
                    J2ME_async_sms_msgid = 0;
                    return;
                }
            }
            j2me_sms_register_type = -1;
        }
            break;

        case MSG_ID_MMIAPI_SMS_SEND_RSP:
        {
            mmiapi_sms_send_rsp_struct *p = (mmiapi_sms_send_rsp_struct*) ilm_ptr->local_para_ptr; 
			vm_id = p->vm_id; 
            J2ME_sms_save_result(MSG_J2ME_SMS_SEND_RSP, (int)p->result);
        }
            break;
 
        case MSG_ID_MMIAPI_SMS_SEND_ABORT_RSP:
        {
            jwa_sms_set_state(JWA_SMS_STATE_IDLE);
        }
            break; 

        default:
            ASSERT(0);
            break;

    }

    /* notify J2ME thread to process coming async event */
    kal_set_eg_events(g_java_event_group_1, JAVA_EG_SMS_NOTIFY_RETREIVE, KAL_OR);
    if (jwa_sms_call_back != NULL)
    {
        if (ilm_ptr->msg_id != MSG_ID_MMIAPI_SMS_SEND_ABORT_RSP && jwa_sms_get_state() != JWA_SMS_STATE_SEND_ABORT)
        {
            J2me_sms_reply_enum eventMsg = jwa_sms_get_response_primitive();
            int result = jwa_sms_get_primitive_result();
            if (vm_id != -1)
            {
                jwa_sms_callback_handler(result, eventMsg, vm_id);
            }
        }
    }
	
#if (MAX_VM_INSTANCE_NUM > 1)
    if (jwa_sms_get_state() != JWA_SMS_STATE_SEND_ABORT)
    {
        kal_take_mutex(g_jam_async_sms_mvm_mutex);
        if (j2me_sms_mvm_pending_task[0].vm_id != -1)
        {
            J2ME_sms_process_pending_task();
        }
        else
        {
            j2me_sms_processing_task_vm_id = -1;
            jwa_sms_set_state(JWA_SMS_STATE_IDLE);
        }
        kal_give_mutex(g_jam_async_sms_mvm_mutex);
    }
#endif

    return;
}

#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_register_sim_type
 * DESCRIPTION
 *  register sms port and type
 * PARAMETERS
 *  portNumber      [IN]        
 *  type            [IN]        
 * RETURNS
 *  0 if success, -1 else
 *****************************************************************************/
int J2ME_sms_register_sim_type(long portNumber, int type, kal_uint8 sim_type, kal_bool need_result, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_blocking_data_struct *blocking;
    mmiapi_sms_register_port_req_struct *p;
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_REGISTER, (int)portNumber, (int)type);

    /* Only when the port is not registered, it can apply registration to low-layer */
    p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);

    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

    p->blocking_data = blocking;
    p->enable = KAL_TRUE;
    p->port_number = (int)portNumber;
#if (MMI_MAX_SIM_NUM == 2)
    if (sim_type == JWA_SMS_SIM_TYPE_SIM2)
    {
        p->isSlave = KAL_TRUE;
    }
    else
    {
        p->isSlave = KAL_FALSE;
    }
    p->sim_id = SRV_SMS_SIM_1;
#elif (MMI_MAX_SIM_NUM >=3)
#if (MMI_MAX_SIM_NUM >= 4)
    if (sim_type == JWA_SMS_SIM_TYPE_SIM4)
    {
        p->sim_id = SRV_SMS_SIM_4;
    }
    else
#endif
    if (sim_type == JWA_SMS_SIM_TYPE_SIM3)
    {
        p->sim_id = SRV_SMS_SIM_3;
    }
    else if (sim_type == JWA_SMS_SIM_TYPE_SIM2)
    {
        p->sim_id = SRV_SMS_SIM_2;
    }
    else
    {
        p->sim_id = SRV_SMS_SIM_1;
    }
#endif

    p->vm_id = -1;

    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    if (need_result)
    {
        kal_trace(TRACE_INFO, WMA_SMS_REGISTER1);
        mmiapi_lock(MOD_JASYN_D); /* waiting the register port number result */
        kal_trace(TRACE_INFO, WMA_SMS_REGISTER2, (int)(blocking->result));

        ret = blocking->result ? 0 : -1;
    }

    if ((type == WMA_REGISTRY) && blocking->result && (vm_id != -1))
    {
        /* register success, and we should unregister port when VM shutdown */
        //resouceRegistering(
        //    JAVA_WMA_SMS_DEVICE,
        //    (int)portNumber,
        //    NULL,
        //    NULL,
        //    J2ME_sms_unregister_by_resource_manager);
        //20101104,changed resource mgr for MVM
        jvm_resource_mgr_register(
            vm_id,
            JAVA_WMA_SMS_DEVICE,
            (int)portNumber,
            NULL,
            NULL,
            J2ME_sms_unregister_by_resource_manager);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_unregister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 *  type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int J2ME_sms_unregister_sim_type(long portNumber, int type, kal_uint8 sim_type, kal_bool need_result, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_blocking_data_struct *blocking;
    mmiapi_sms_register_port_req_struct *p;
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER, portNumber);

    //sprintf(_kvmLogStr,"J2ME_sms_unregister_sim_type \n");
    //Kprintf();

    p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

    p->blocking_data = blocking;
    p->enable = KAL_FALSE;
    p->port_number = (int)portNumber;
    p->remove_reminder_data = KAL_TRUE;
#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_type == JWA_SMS_SIM_TYPE_SIM2)
    {
        p->isSlave = KAL_TRUE;
    }
    else
    {
        p->isSlave = KAL_FALSE;
    }
    p->sim_id = SRV_SMS_SIM_1;
#elif (MMI_MAX_SIM_NUM >=3)
#if (MMI_MAX_SIM_NUM >= 4)
    if (sim_type == JWA_SMS_SIM_TYPE_SIM4)
    {
        p->sim_id = SRV_SMS_SIM_4;
    }
	else
#endif
    if (sim_type == JWA_SMS_SIM_TYPE_SIM3)
    {
        p->sim_id = SRV_SMS_SIM_3;
    }
	else if (sim_type == JWA_SMS_SIM_TYPE_SIM2)
    {
        p->sim_id = SRV_SMS_SIM_2;
    }
    else
    {
        p->sim_id = SRV_SMS_SIM_1;
    }
#endif
	
   p->vm_id = -1;

    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    if (need_result) 
    {
        kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER2);
        mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
        kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER3, blocking->result);

        ret = blocking->result ? 0 : -1;
    }
    
    if ((type == WMA_REGISTRY) && blocking->result && (vm_id != -1))
    {
        //resouceDereg(JAVA_WMA_SMS_DEVICE, portNumber);    //20101104,changed resource mgr for MVM
        jvm_resource_mgr_deregister(vm_id,JAVA_WMA_SMS_DEVICE,portNumber);
    }

    return ret;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_register
 * DESCRIPTION
 *  register sms port and type
 * PARAMETERS
 *  portNumber      [IN]        
 *  type            [IN]        
 * RETURNS
 *  0 if success, -1 else
 *****************************************************************************/
int J2ME_sms_register(long portNumber, int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    mmiapi_blocking_data_struct *blocking;
    mmiapi_sms_register_port_req_struct *p;
#endif
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_REGISTER, (int)portNumber, (int)type);

#ifdef __SUPPORT_JAVA_PUSH__
    ret = j2me_check_push_register_port(portNumber, type, jam_mvm_get_current_vm_id());
#else
    ret = NON_REGISTERED;
#endif

    if (ret == NON_REGISTERED)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        ret = J2ME_sms_register_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_FALSE, -1);

        if (ret == 0)
        {
            ret = J2ME_sms_register_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_FALSE, -1);

            if (ret != 0)
            {
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_FALSE, -1);
            }
#if (MMI_MAX_SIM_NUM >= 3)
            else
            {
                ret = J2ME_sms_register_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_FALSE, -1);
				
                if (ret != 0)
                {
                    J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_FALSE, -1);
                    J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_FALSE, -1);
                }
#if (MMI_MAX_SIM_NUM >= 4)
                else
                {
                    ret = J2ME_sms_register_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM4, KAL_FALSE, -1);

                    if (ret != 0)
                    {
                        J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_FALSE, -1);
                        J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_FALSE, -1);
                        J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_FALSE, -1);
                    }
                }
#endif
            }
#endif
        }
#else

        /* Only when the port is not registered, it can apply registration to low-layer */
        p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);

        blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

        p->blocking_data = blocking;
        p->enable = KAL_TRUE;
        p->port_number = (int)portNumber;
        p->sim_id = SRV_SMS_SIM_1;

        /* fake module */
        java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

        //kal_trace(TRACE_INFO, WMA_SMS_REGISTER1);
        //mmiapi_lock(MOD_JASYN_D); /* waiting the register port number result */
        //kal_trace(TRACE_INFO, WMA_SMS_REGISTER2, (int)(blocking->result));

        //if ((type == WMA_REGISTRY) && blocking->result)
        //{
            /* register success, and we should unregister port when VM shutdown */
            //resouceRegistering(
            //    JAVA_WMA_SMS_DEVICE,
            //    (int)portNumber,
            //    NULL,
            //    NULL,
            //    J2ME_sms_unregister_by_resource_manager);
        //}

        //ret = blocking->result ? 0 : -1;
		
#endif
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_unregister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 *  type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int J2ME_sms_unregister(long portNumber, int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    mmiapi_blocking_data_struct *blocking;
    mmiapi_sms_register_port_req_struct *p;
#else
    kal_int32 ret_sim1;
    kal_int32 ret_sim2;
    kal_int32 ret_sim3;
    kal_int32 ret_sim4;
#endif
    int ret;
    kal_uint8 *msg = NULL;
    int msg_len = -1;
    int sms_type;
    kal_char *pszError = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER, portNumber);

#ifdef __SUPPORT_JAVA_PUSH__
    ret = j2me_check_push_register_port(portNumber, type, jam_mvm_get_current_vm_id());
#else
    ret = NON_REGISTERED;
#endif

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER1, ret);

    if (((type == WMA_REGISTRY) && (ret != PUSH_REGISTERED) && (ret != PUSH_CONFLICT_REGISTERED)) || 
        ((type == PUSH_REGISTRY) && (ret == PUSH_REGISTERED)))
    {
#if (MMI_MAX_SIM_NUM >= 2)

        ret_sim1 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_TRUE, -1);
        ret_sim2 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, -1);
#if (MMI_MAX_SIM_NUM >= 3)
        ret_sim3 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, -1);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        ret_sim4 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM4, KAL_TRUE, -1);
#endif

        if (ret_sim1 == 0 && ret_sim2 == 0
#if (MMI_MAX_SIM_NUM >= 3)
            && ret_sim3 == 0
#endif
#if (MMI_MAX_SIM_NUM >= 4)
            && ret_sim4 == 0
#endif
            )
        {
            ret = 0;
        }
        else
        {
            ret = -1;
        }
#else

        p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
        blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

        p->blocking_data = blocking;
        p->enable = KAL_FALSE;
        p->port_number = (int)portNumber;
        p->remove_reminder_data = KAL_TRUE;

        /* fake module */
        java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

        kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER2);
        mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
        kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER3, blocking->result);

        ret = blocking->result ? 0 : -1;

        //resouceDereg(JAVA_WMA_SMS_DEVICE, portNumber);    //20101104,changed resource mgr for MVM
        //jvm_resource_mgr_deregister(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_WMA_SMS_DEVICE, portNumber);
#endif 

        msg = J2ME_sms_dequeue_sms(&pszError, &sms_type, &msg_len, (int)portNumber, KAL_TRUE);
        if (msg != NULL)
        {
            jvm_free(msg);
        }
        if (pszError != NULL) 
        {
            //sprintf(_kvmLogStr,"J2ME_sms_unregister: delete sms in file fail\n");
            //Kprintf();
            return -1;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_unregister_by_push
 * DESCRIPTION
 *  This is used for push to deregister the SMS port.
 *  The calling time should be in deleting the Midlet and deregister the 
 *  registered port of SMS
 *
 * PARAMETERS
 *  portNumber      [IN]        
 *  type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int J2ME_sms_unregister_by_push(long portNumber, int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    mmiapi_blocking_data_struct *blocking;
    mmiapi_sms_register_port_req_struct *p;
#else
    kal_int32 ret_sim1;
    kal_int32 ret_sim2;
    kal_int32 ret_sim3;
    kal_int32 ret_sim4;
#endif
    int ret;
    kal_uint8 *msg = NULL;
    int msg_len = -1;
    int sms_type;
    kal_char *pszError = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER, portNumber);

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER1, PUSH_REGISTERED);

    //sprintf(_kvmLogStr,"J2ME_sms_unregister_by_push \n");
    //Kprintf();

    ret = 0;
    if (type == PUSH_REGISTRY)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        ret_sim1 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_FALSE, -1);
        ret_sim2 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_FALSE, -1);
#if (MMI_MAX_SIM_NUM >= 3)
        ret_sim3 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_FALSE, -1);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        ret_sim4 = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM4, KAL_FALSE, -1);
#endif

        if (ret_sim1 == 0 && ret_sim2 == 0
#if (MMI_MAX_SIM_NUM >= 3)
            && ret_sim3 == 0
#endif
#if (MMI_MAX_SIM_NUM >= 4)
            && ret_sim4 == 0
#endif
            )
        {
            ret = 0;
        }
        else
        {
            ret = -1;
        }
#else

        p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
        blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

        p->blocking_data = blocking;
        p->enable = KAL_FALSE;
        p->port_number = (int)portNumber;
        p->remove_reminder_data = KAL_TRUE;
		p->vm_id = -1;

        /* fake module */
        java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

        //kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER2);
        //mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
        //kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER3, blocking->result);

        //ret = blocking->result ? 0 : -1;

        //resouceDereg(JAVA_WMA_SMS_DEVICE, portNumber);    //20101104,changed resource mgr for MVM
        //jvm_resource_mgr_deregister(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_WMA_SMS_DEVICE, portNumber);
#endif
    
        msg = J2ME_sms_dequeue_sms(&pszError, &sms_type, &msg_len, (int)portNumber, KAL_TRUE);
        if (msg != NULL)
        {
            jvm_free(msg);
        }
        if (pszError != NULL) 
        {
            //sprintf(_kvmLogStr,"J2ME_sms_unregister_by_push: delete sms in file fail\n");
            //Kprintf();
            ret = -1;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_unregister_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_unregister_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar* WCHARFilename_sms = NULL;
    mmiapi_sms_register_port_req_struct *p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTERALL);

    p->blocking_data = NULL;
    p->enable = KAL_FALSE;
    p->port_number = (int)-1;

    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    WCHARFilename_sms = (kal_wchar*)jvm_malloc((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_FILE) + 3) * 2);
    if (WCHARFilename_sms == NULL)
    {
        ASSERT(0);
    }
    kal_wsprintf(WCHARFilename_sms, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_FILE);
    if (FS_GetAttributes(WCHARFilename_sms) >= 0)
    {
        if (FS_Delete(WCHARFilename_sms) < 0)
        {
            ASSERT(0);
        }
    }
    J2ME_sms_init();
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_unregister_by_resource_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int J2ME_sms_unregister_by_resource_manager(int portNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_blocking_data_struct *blocking;
    mmiapi_sms_register_port_req_struct *p;
    kal_uint8 *msg = NULL;
    int msg_len = -1;
    int type;
    kal_char *pszError = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR, portNumber);

    //sprintf(_kvmLogStr,"J2ME_sms_unregister_by_resource_manager \n");
    //Kprintf();

#if (MMI_MAX_SIM_NUM == 2)
    p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

    p->blocking_data = blocking;
    p->enable = KAL_FALSE;
    p->port_number = (int)portNumber;
    p->remove_reminder_data = KAL_TRUE;
    p->isSlave = KAL_TRUE;
	
    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR1);
    mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR2);
#elif (MMI_MAX_SIM_NUM >= 3)
#if (MMI_MAX_SIM_NUM >= 4)
    p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

    p->blocking_data = blocking;
    p->enable = KAL_FALSE;
    p->port_number = (int)portNumber;
    p->remove_reminder_data = KAL_TRUE;
    p->sim_id = SRV_SMS_SIM_4;
	
    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR1);
    mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR2);
#endif
    p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

    p->blocking_data = blocking;
    p->enable = KAL_FALSE;
    p->port_number = (int)portNumber;
    p->remove_reminder_data = KAL_TRUE;
    p->sim_id = SRV_SMS_SIM_3;
	
    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR1);
    mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR2);

    p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

    p->blocking_data = blocking;
    p->enable = KAL_FALSE;
    p->port_number = (int)portNumber;
    p->remove_reminder_data = KAL_TRUE;
    p->sim_id = SRV_SMS_SIM_2;
	
    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR1);
    mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR2);
#endif

    p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);
    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);

    p->blocking_data = blocking;
    p->enable = KAL_FALSE;
    p->port_number = (int)portNumber;
    p->remove_reminder_data = KAL_TRUE;
#if (MMI_MAX_SIM_NUM == 2)
    p->isSlave = KAL_FALSE;
    p->sim_id = SRV_SMS_SIM_1;
#elif (MMI_MAX_SIM_NUM >= 3)
    p->sim_id = SRV_SMS_SIM_1;
#endif

    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR1);
    mmiapi_lock(MOD_JASYN_D); /* waiting the unregister port number result */
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER_BY_MGR2);

    msg = J2ME_sms_dequeue_sms(&pszError, &type, &msg_len, (int)portNumber, KAL_TRUE);
    if (msg != NULL)
    {
        jvm_free(msg);
    }
    if (pszError != NULL) 
    {
        //sprintf(_kvmLogStr,"J2ME_sms_unregister_by_resource_manager: delete sms in file fail\n");
        //Kprintf();
        return RESOUCE_FAIL;
    }

    return RESOUCE_NO_ERROR;
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
#endif

/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_ansii_n_to_unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [?]         
 *  pInBuffer       [?]         
 *  len             [IN]        
 * RETURNS
 *  stuff zero between characters
 *****************************************************************************/
U16 J2ME_sms_ansii_n_to_unicode(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 count = -1;
    U8 charLen = 0;
    U8 arrOut[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len)
    {
        mmi_wc_to_ucs2((U16) * pInBuffer, &charLen, arrOut);

        pOutBuffer[++count] = arrOut[0];
        pOutBuffer[++count] = arrOut[1];
        pInBuffer++;

        len--;
    }
    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  j2me_process_recvd_sms_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void *j2me_process_recvd_sms_ind(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_ind_struct *sms_ind_ptr;
    int port;
    int type;
    int msg_len;
    char *buf;
    kal_uint16 *addr;
    kal_uint8 addr_len;
    kal_uint8 scts[7];
    kal_char* pszError = NULL;
    kal_int32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_ind_ptr = (mmiapi_sms_ind_struct*) ilm_ptr->local_para_ptr;
    port = (int) sms_ind_ptr->port_number;
    type = (int) sms_ind_ptr->type;
    msg_len = (int) sms_ind_ptr->con_len;
    buf = (char*) sms_ind_ptr->content;
    addr = sms_ind_ptr->address;
    addr_len = (kal_uint8) (mmi_ucs2strlen((const S8*)sms_ind_ptr->address) * 2);

    scts[0] = (kal_uint8) ((sms_ind_ptr->time.nYear >> 8) & 0xFF);
    scts[1] = (kal_uint8) ((sms_ind_ptr->time.nYear) & 0xFF);
    scts[2] = sms_ind_ptr->time.nMonth;
    scts[3] = sms_ind_ptr->time.nDay;
    scts[4] = sms_ind_ptr->time.nHour;
    scts[5] = sms_ind_ptr->time.nMin;
    scts[6] = sms_ind_ptr->time.nSec;

    ret = J2ME_sms_enqueue_sms(&pszError, type, msg_len, port, buf, addr, addr_len, scts);
    if (msg_len > 0)
    {
        free_ctrl_buffer(buf);
    }
    if (pszError != NULL && ret == -1)
    {
        //sprintf(_kvmLogStr,"j2me_process_recvd_sms_ind: save sms into enqueue file fail \n");
        //Kprintf();
        return NULL;
    }
	
#ifdef __SUPPORT_JAVA_PUSH__
    return push_process_recvd_sms_ind(port);
#else
    return NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_sms_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int sms_fd;
    int result = 0;
    int position = SMSQUEUE_FILE_HEADER_SIZE;
    int i;
    kal_uint8 tmp_buf[SMSQUEUE_FILE_HEADER_SIZE];
    kal_wchar* WCHARFilename_sms = NULL;
    kal_wchar* WCHARFilename_sms_temp = NULL;
    kal_wchar* WCHARFilename_sms_dir = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif

    sms_init_result = KAL_FALSE;

    WCHARFilename_sms = (kal_wchar*)get_ctrl_buffer((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_FILE) + 3) * 2);
    if (WCHARFilename_sms == NULL)
    {
        goto RET;
    }
    WCHARFilename_sms_temp = (kal_wchar*)get_ctrl_buffer((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_TEMP_FILE) + 3) * 2);
    if (WCHARFilename_sms_temp == NULL)
    {
        goto RET;
    }
    WCHARFilename_sms_dir = (kal_wchar*)get_ctrl_buffer((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_DIR) + 3) * 2);
    if (WCHARFilename_sms_dir == NULL)
    {
        goto RET;
    }
    kal_wsprintf(WCHARFilename_sms, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_FILE);
    kal_wsprintf(WCHARFilename_sms_temp, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_TEMP_FILE);
    kal_wsprintf(WCHARFilename_sms_dir, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_DIR);

    result = FS_GetAttributes(WCHARFilename_sms_dir);
    if (result >= 0 && !(result & FS_ATTR_DIR))
    {
        if (FS_Delete(WCHARFilename_sms_dir) < 0)
        {
            goto RET;
        }
    }

    if (result < 0 || !(result & FS_ATTR_DIR))
    {
        if (FS_CreateDir(WCHARFilename_sms_dir) < 0)
        {
            goto RET;
        }
    }

    /* recreate temp queue file and set it to max file size */
    if ((sms_fd = FS_Open(WCHARFilename_sms_temp, O_BINARY | O_TRUNC | O_RDWR)) < 0)
	  {
	  	  goto RET;
	  }

	  if (FS_Seek(sms_fd, SMSQUEUE_MAX_FILE_SIZE, SEEK_SET) < 0)
	  {
	      FS_Close(sms_fd);	
		    goto RET;
	  }
	  FS_Close(sms_fd);	

    /* deal with the queue file if it's existed */
	  if (FS_GetAttributes(WCHARFilename_sms) >= 0) 
	  {
		    if ((sms_fd = FS_Open(WCHARFilename_sms, O_BINARY | O_RDWR)) < 0)
		    {
	          goto RET;
		    }

		    if (FS_GetFileSize(sms_fd, (kal_uint32 *)&result) < 0)
        {
            FS_Close(sms_fd);
	          goto RET;
	      }

          kal_trace(TRACE_INFO, WMA_SMS_PERSISTENT_INIT, result);
   		  FS_Close(sms_fd);
		    if (result == SMSQUEUE_MAX_FILE_SIZE) /* check the file size */
        {
	         	sms_init_result = KAL_TRUE;
			      for (i = 0; i < JAVA_SMS_MAX_PORT_NUM; i++)
	          {
	              j2me_sms_recv_num_list[i].port = (kal_uint16)0;
	    	      	j2me_sms_recv_num_list[i].number = (kal_uint16)0;
	          }
	        	J2ME_sms_load_recv_list();
	        	goto RET;
        }
        
        if (FS_Delete(WCHARFilename_sms) < 0) 
	      {
	          goto RET;
	      }
   	}

	  /* create queue file when the sise doesn't equal to 10k or file doesn't exist 
	   * set size to 10k and set the file header */
	  if ((sms_fd = FS_Open(WCHARFilename_sms, O_BINARY | O_TRUNC | O_RDWR)) >= 0)
	  {
		    if (FS_Seek(sms_fd, SMSQUEUE_MAX_FILE_SIZE, SEEK_SET) >= 0)
		    {
			      if (FS_Seek(sms_fd, 0, SEEK_SET) >= 0)
			      {
			        	tmp_buf[0] = (kal_uint8) ((position & 0xff000000) >> 24);
                tmp_buf[1] = (kal_uint8) ((position & 0x00ff0000) >> 16);
                tmp_buf[2] = (kal_uint8) ((position & 0x0000ff00) >> 8);
                tmp_buf[3] = (kal_uint8) (position & 0x000000ff);
                tmp_buf[4] = ' ';
			          if (FS_Write(sms_fd, tmp_buf, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result) >= 0)
			          {
				            if (result == SMSQUEUE_FILE_HEADER_SIZE)
				            {
				                FS_Close(sms_fd);
				              	sms_init_result = KAL_TRUE;
						            for (i = 0; i < JAVA_SMS_MAX_PORT_NUM; i++)
	                      {
	                          j2me_sms_recv_num_list[i].port = (kal_uint16)0;
	    	            	      j2me_sms_recv_num_list[i].number = (kal_uint16)0;
	                      }
				    	          goto RET;
				            }
				        }
			      }
		    }
		
		    FS_Close(sms_fd);
		    if (FS_Delete(WCHARFilename_sms) < 0)
		    {
		        //sprintf(_kvmLogStr,"J2ME_sms_init: delete queue file fail \n");
    	      //Kprintf();
		    }
	  }
	
RET:
  	if (WCHARFilename_sms)
	  {
	      free_ctrl_buffer(WCHARFilename_sms);
	  }
	  if (WCHARFilename_sms_temp)
	  {
	      free_ctrl_buffer(WCHARFilename_sms_temp);
	  }
	  if (WCHARFilename_sms_dir)
	  {
	      free_ctrl_buffer(WCHARFilename_sms_dir);
	  }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_load_recv_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [?]         
 *  len             [?]         
 *  check_port      [IN]        
 *  addr            [?]         
 *  timestamp       [?]
 *  only_new        [IN]
 * RETURNS
 *  
 *****************************************************************************/
void J2ME_sms_load_recv_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  int sms_fd;
    kal_uint8 tmp_buf[SMSQUEUE_SMS_HEADER_SIZE];
	  kal_uint8 tmp_header[SMSQUEUE_FILE_HEADER_SIZE];
    kal_int32 size;
    int result;
	  int result_size;
    int port;
	  int len;
	  int i;
    kal_uint8 addr_len = 0;
    kal_int32 position = 0;
	  kal_wchar* WCHARFilename_sms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_PERSISTENT_LOAD_LIST);

	  WCHARFilename_sms = (kal_wchar*)get_ctrl_buffer((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_FILE) + 3) * 2);
	  if (WCHARFilename_sms == NULL)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_load_recv_list: malloc sms string fail\n");
        //Kprintf();
		    goto FAIL1;
    }
	  kal_wsprintf(WCHARFilename_sms, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_FILE);

	  if ((sms_fd = FS_Open(WCHARFilename_sms, O_BINARY | O_RDONLY)) < 0) 
	  {
	     //sprintf(_kvmLogStr, "J2ME_sms_load_recv_list: open file fail\n");
        //Kprintf();
	      goto FAIL1;
	  }
	 
	  result = FS_Read(sms_fd, tmp_header, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result_size);
	  if (result < 0 || result_size != SMSQUEUE_FILE_HEADER_SIZE)
	  {
        //sprintf(_kvmLogStr, "J2ME_sms_load_recv_list: seek file to beginning fail\n");
        //Kprintf();
        goto FAIL;
    }
	
	  size =
          ((tmp_header[0] & 0xFF) << 24) | ((tmp_header[1] & 0xFF) << 16) | ((tmp_header[2] & 0xFF) << 8) | (tmp_header[3] &
                                                                                                      0xFF);
    position += SMSQUEUE_FILE_HEADER_SIZE;

    while (position < size)
    {
        result = FS_Read(sms_fd, tmp_buf, SMSQUEUE_SMS_HEADER_SIZE, (kal_uint32 *)&result_size);
        if (result < 0 || result_size != SMSQUEUE_SMS_HEADER_SIZE)
		    {
            //sprintf(_kvmLogStr, "J2ME_sms_load_recv_list: FS_GetFilePosition fail\n");
            //Kprintf();
            goto FAIL;
        }
        
        len =
             ((tmp_buf[5] & 0xFF) << 24) | ((tmp_buf[6] & 0xFF) << 16) | ((tmp_buf[7] & 0xFF) << 8) | (tmp_buf[8] &
                                                                                                      0xFF);
		    port =
            ((tmp_buf[10] & 0xFF) << 24) | ((tmp_buf[11] & 0xFF) << 16) | ((tmp_buf[12] & 0xFF) << 8) | (tmp_buf[13] &
                                                                                                         0xFF);
		    addr_len = (tmp_buf[23] & 0xFF);
        		
        for (i = 0; i < JAVA_SMS_MAX_PORT_NUM; i++)
		    {
		        if (j2me_sms_recv_num_list[i].port == (kal_uint16)port)
			      {
			          j2me_sms_recv_num_list[i].number++;
				        break;
		        }
			      else if (j2me_sms_recv_num_list[i].port == (kal_uint16)0)
			      {
			          j2me_sms_recv_num_list[i].port = (kal_uint16)port;
			        	j2me_sms_recv_num_list[i].number = (kal_uint16)1;
			        	break;
		      	}
        }

		    if (addr_len)
		    {
		        addr_len++;
	      }

		    if (FS_Seek(sms_fd, addr_len + len + 1, SEEK_CUR) < 0)
        {
            //sprintf(_kvmLogStr, "J2ME_sms_load_recv_list: seek file to next sms fail\n");
            //Kprintf();
            goto FAIL;
        }
	
        position += (SMSQUEUE_SMS_HEADER_SIZE + addr_len + len + 1);
    }
	
    FS_Close(sms_fd);

    free_ctrl_buffer(WCHARFilename_sms);
    return;

FAIL:
	  FS_Close(sms_fd);
FAIL1:
	  ASSERT(0);
    if (WCHARFilename_sms)
	  {
	      free_ctrl_buffer(WCHARFilename_sms);
	  }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_enqueue_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  len             [IN]        
 *  port            [IN]        
 *  buf             [?]         
 *  addr            [?]         
 *  addr_len        [IN]        
 *  timestamp       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 J2ME_sms_enqueue_sms(
    kal_char** pszError,
    int type,
    int len,
    int port,
    char *buf,
    kal_uint16 *addr,
    kal_uint8 addr_len,
    kal_uint8 *timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  int sms_fd;
	  int position = 0;
	  int check_flag = 0;
	  int result;
	  int result_size;
	  kal_uint8 i = 0;
    kal_uint8 tmp_buf[SMSQUEUE_SMS_HEADER_SIZE];
	  kal_uint8 tmp_header[SMSQUEUE_FILE_HEADER_SIZE];
	  kal_wchar* WCHARFilename_sms = NULL;
	  kal_wchar* WCHARFilename_sms_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_PERSISTENT_ENQUEUE, (int)port, (int)len, (int)addr_len);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return -1;
    }
#endif
    kal_take_mutex(g_jam_async_sms_mutex);

	  if (!sms_init_result)
	  {
	      J2ME_sms_init();
		    if (!sms_init_result)
		    {
		        //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: reinit fail\n");
            //Kprintf();
		        goto FAIL1;
		    }
	  }

    /* Copy queue file to a temp file and modify it */
    WCHARFilename_sms = (kal_wchar*)jvm_malloc((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_FILE) + 3) * 2);
	  if (WCHARFilename_sms == NULL)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: malloc sms string fail\n");
        //Kprintf();
		    goto FAIL1;
    }
	  WCHARFilename_sms_temp = (kal_wchar*)jvm_malloc((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_TEMP_FILE) + 3) * 2);
	  if (WCHARFilename_sms_temp == NULL)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: malloc sms temp string fail\n");
        //Kprintf();
		    goto FAIL1;
    }
	  kal_wsprintf(WCHARFilename_sms, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_FILE);
	  kal_wsprintf(WCHARFilename_sms_temp, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_TEMP_FILE);
	  if (FS_Move(WCHARFilename_sms, WCHARFilename_sms_temp, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0) != FS_NO_ERROR) 
	  {
	     // sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: copy queue file fail\n");
        //Kprintf();
	      goto FAIL1;
	  }

	  if ((sms_fd = FS_Open(WCHARFilename_sms_temp, O_BINARY | O_RDWR)) < 0) 
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: open file fail\n");
        //Kprintf();
	      goto FAIL1;
	  }

    result = FS_Read(sms_fd, tmp_header, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result_size);
	  if (result < 0 || result_size != SMSQUEUE_FILE_HEADER_SIZE)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: read file header fail: %d, %d \n", SMSQUEUE_FILE_HEADER_SIZE, result_size);
        //Kprintf();
        goto FAIL;
	  }
	
	  position =
            ((tmp_header[0] & 0xFF) << 24) | ((tmp_header[1] & 0xFF) << 16) | ((tmp_header[2] & 0xFF) << 8) | (tmp_header[3] &
                                                                                                      0xFF);

    if (addr_len)
    {
        addr_len++;
    }
	
	  if ((position + SMSQUEUE_SMS_HEADER_SIZE + addr_len + len + 1) > SMSQUEUE_MAX_FILE_SIZE)
    {
    	  kal_trace(TRACE_INFO, WMA_SMS_PERSISTENT_ENQUEUE_FULL);
		    FS_Close(sms_fd);
		    jvm_free(WCHARFilename_sms);
	      jvm_free(WCHARFilename_sms_temp);
	      *pszError = "J2ME_sms_enqueue_sms";
	      kal_give_mutex(g_jam_async_sms_mutex);
        return (-1);
    }

    if (FS_Seek(sms_fd, position, SEEK_SET) < 0)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: seek position fail \n");
        //Kprintf();
        goto FAIL;
    }

    tmp_buf[i++] = (kal_uint8) ((type & 0xff000000) >> 24);
    tmp_buf[i++] = (kal_uint8) ((type & 0x00ff0000) >> 16);
    tmp_buf[i++] = (kal_uint8) ((type & 0x0000ff00) >> 8);
    tmp_buf[i++] = (kal_uint8) (type & 0x000000ff);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = (kal_uint8) ((len & 0xff000000) >> 24);
    tmp_buf[i++] = (kal_uint8) ((len & 0x00ff0000) >> 16);
    tmp_buf[i++] = (kal_uint8) ((len & 0x0000ff00) >> 8);
    tmp_buf[i++] = (kal_uint8) (len & 0x000000ff);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = (kal_uint8) ((port & 0xff000000) >> 24);
    tmp_buf[i++] = (kal_uint8) ((port & 0x00ff0000) >> 16);
    tmp_buf[i++] = (kal_uint8) ((port & 0x0000ff00) >> 8);
    tmp_buf[i++] = (kal_uint8) (port & 0x000000ff);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = (kal_uint8) (timestamp[0] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[1] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[2] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[3] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[4] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[5] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[6] & 0xFF);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = (kal_uint8) (addr_len - 1);
    tmp_buf[i++] = ' ';
	  tmp_buf[i++] = (kal_uint8) ((check_flag & 0xff000000) >> 24);
    tmp_buf[i++] = (kal_uint8) ((check_flag & 0x00ff0000) >> 16);
    tmp_buf[i++] = (kal_uint8) ((check_flag & 0x0000ff00) >> 8);
    tmp_buf[i++] = (kal_uint8) (check_flag & 0x000000ff);
    tmp_buf[i++] = ' ';

    //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: buf: %s\n", tmp_buf);
    //Kprintf();

    /* write the sms to the queue as type len port timestamp addr_len check_flag addr buf\n */
	  result = FS_Write(sms_fd, tmp_buf, i, (kal_uint32 *)&result_size);
    if (result < 0 || result_size != i)   /* SMSQUEUE_SMS_HEADER_SIZE */
	  {
	     // sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: write sms header fail: %d, %d \n", i, result_size);
        //Kprintf();
        goto FAIL;
	  }

    if (addr_len)
    {
        result = FS_Write(sms_fd, addr, (addr_len - 1), (kal_uint32 *)&result_size);
        if (result < 0 || result_size != (addr_len - 1))
        {
	          //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: write sms address fail: %d, %d \n", addr_len - 1, result_size);
            //Kprintf();
            goto FAIL;
	      }
        tmp_buf[0] = ' ';
		    result = FS_Write(sms_fd, tmp_buf, 1, (kal_uint32 *)&result_size);
        if (result < 0 || result_size != 1)
		    {
	          //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: write sms address space fail: %d, %d \n", 1, result_size);
            //Kprintf();
            goto FAIL;
	      }
    }

    if (len)
    {
        result = FS_Write(sms_fd, buf, len, (kal_uint32 *)&result_size);
        if (result < 0 || result_size != len)
		    {
	         // sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: write sms content fail: %d, %d \n", len, result_size);
            //Kprintf();
            goto FAIL;
	      }
    }
	
	  result = FS_Write(sms_fd, "\n", 1, (kal_uint32 *)&result_size);
    if (result < 0 || result_size != 1)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: write end fail: %d, %d \n", 1, result_size);
        //Kprintf();
        goto FAIL;
	  }

	  /* seek to the file beginning and modify file header */
	  if (FS_Seek(sms_fd, 0, SEEK_SET) < 0)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: seek file header fail \n");
        //Kprintf();
        goto FAIL;
    }
	
    position += (SMSQUEUE_SMS_HEADER_SIZE + addr_len + len + 1);
	  tmp_header[0] = (kal_uint8) ((position & 0xff000000) >> 24);
	  tmp_header[1] = (kal_uint8) ((position & 0x00ff0000) >> 16);
	  tmp_header[2] = (kal_uint8) ((position & 0x0000ff00) >> 8);
	  tmp_header[3] = (kal_uint8) (position & 0x000000ff);
	  tmp_header[4] = ' ';
    result = FS_Write(sms_fd, tmp_header, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result_size);
	  if (result < 0 || result_size != SMSQUEUE_FILE_HEADER_SIZE)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: write file header fail: %d, %d \n", len, result_size);
        //Kprintf();
        goto FAIL;
	  }

    FS_Close(sms_fd);

    /* change sms queue file */
  	if (FS_Delete(WCHARFilename_sms) < 0)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: delete smsqueue file fail \n");
        //Kprintf();
	      goto FAIL1;
	  }
	  if (FS_Rename(WCHARFilename_sms_temp, WCHARFilename_sms) < 0)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: rename smsqueue temp file fail \n");
        //Kprintf();
        goto FAIL1;
	  }
	  if ((sms_fd = FS_Open(WCHARFilename_sms_temp, O_BINARY | O_TRUNC | O_RDWR)) < 0)
	  {
		    //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: create temp file fail \n");
        //Kprintf();
		    sms_init_result = KAL_FALSE;
        goto FAIL1;
	  }
	  if (FS_Seek(sms_fd, SMSQUEUE_MAX_FILE_SIZE, SEEK_SET) < 0)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: seek temp file fail \n");
        //Kprintf();
		    sms_init_result = KAL_FALSE;
        goto FAIL;
	  }
	  FS_Close(sms_fd);

    jvm_free(WCHARFilename_sms);
	  jvm_free(WCHARFilename_sms_temp);

    for (i = 0; i < JAVA_SMS_MAX_PORT_NUM; i++)
	  {
	      if (j2me_sms_recv_num_list[i].port == (kal_uint16)port)
		    {
		        j2me_sms_recv_num_list[i].number++;
		      	break;
	      }
		    else if (j2me_sms_recv_num_list[i].port == (kal_uint16)0)
	    	{
		        j2me_sms_recv_num_list[i].port = (kal_uint16)port;
			      j2me_sms_recv_num_list[i].number = (kal_uint16)1;
			      break;
		    }
	  }
	
    kal_give_mutex(g_jam_async_sms_mutex);
    return 0;
	
FAIL:
	  FS_Close(sms_fd);
FAIL1:
	  ASSERT(0);
	  if (WCHARFilename_sms)
	  {
	      jvm_free(WCHARFilename_sms);
	  }
	  if (WCHARFilename_sms_temp)
	  {
	      jvm_free(WCHARFilename_sms_temp);
	  }
	  *pszError = "J2ME_sms_enqueue_sms";
	  kal_give_mutex(g_jam_async_sms_mutex);
    return (-1);
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_dequeue_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [?]         
 *  len                 [?]         
 *  dequeue_port        [IN]
 *  delete_all          [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *J2ME_sms_dequeue_sms(kal_char** pszError, int *type, int *len, int dequeue_port, kal_bool delete_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int sms_fd = -1, sms_temp_fd = -1;
    kal_uint8 *buf = NULL;
    kal_uint8 tmp_buf[SMSQUEUE_SMS_HEADER_SIZE];
	  kal_uint8 *tmp_content = NULL;
	  kal_uint8 tmp_header[SMSQUEUE_FILE_HEADER_SIZE];
    kal_int32 size, entry_size, rw_len;
    int result;
	  int result_size;
    int port;
	  int i, j;
    kal_bool found = KAL_FALSE;
    kal_uint8 addr_len = 0;
    int temp_len = 0;
	  int position = 0;
	  kal_uint8 port_str[13];
	  kal_wchar* WCHARFilename_sms = NULL;
	  kal_wchar* WCHARFilename_sms_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_PERSISTENT_DEQUEUE, (int)dequeue_port);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return NULL;
    }
#endif
	  kal_take_mutex(g_jam_async_sms_mutex);
    /* initialize invalid value */
    *type = -1;
    *len = -1;
	
  	if (!sms_init_result)
	  {
	      J2ME_sms_init();
		    if (!sms_init_result)
		    {
		        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: reinit fail\n");
            //Kprintf();
		        goto FAIL2;
	    	}
	  }

	  WCHARFilename_sms = (kal_wchar*)jvm_malloc((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_FILE) + 3) * 2);
	  if (WCHARFilename_sms == NULL)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: malloc sms string fail\n");
        //Kprintf();
		    goto FAIL1;
    }
	  WCHARFilename_sms_temp = (kal_wchar*)jvm_malloc((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_TEMP_FILE) + 3) * 2);
	  if (WCHARFilename_sms_temp == NULL)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_enqueue_sms: malloc sms temp string fail\n");
        //Kprintf();
		    goto FAIL1;
    }
	  kal_wsprintf(WCHARFilename_sms, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_FILE);
	  kal_wsprintf(WCHARFilename_sms_temp, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_TEMP_FILE);

    /* open queue file and create temp queue file, set the temp file size */
    if ((sms_fd = FS_Open(WCHARFilename_sms, O_BINARY | O_RDWR)) < 0) 
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: open queue file fail\n");
        //Kprintf();
	      goto FAIL2;
	  }

	  if (FS_Delete(WCHARFilename_sms_temp) < 0) 
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: delete queue file fail\n");
        //Kprintf();
	      goto FAIL1;
	  }

	  if ((sms_temp_fd = FS_Open(WCHARFilename_sms_temp, O_BINARY | O_TRUNC | O_RDWR)) < 0) 
	  {
	     // sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: open temp queue file fail\n");
        //Kprintf();
	      goto FAIL1;
	  }

	  if (FS_Seek(sms_temp_fd, SMSQUEUE_MAX_FILE_SIZE, SEEK_SET) < 0)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: set temp queue file size fail\n");
        //Kprintf();
		    sms_init_result = KAL_FALSE;
		    goto FAIL;
    }
	
    if (FS_Seek(sms_temp_fd, 0, SEEK_SET) < 0)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: seek temp queue file fail\n");
        //Kprintf();
		    goto FAIL;
    }

    entry_size = SMSQUEUE_MAX_FILE_SIZE;
	  tmp_content= (kal_uint8*) jvm_malloc(512);
    ASSERT(tmp_content);
	  memset(tmp_content, 0, 512);
    while (entry_size > 0)
    {
		    rw_len = (entry_size > 512 ? 512 : entry_size);
		    result = FS_Write(sms_temp_fd, tmp_content, rw_len, (kal_uint32 *)&result_size);
        if (result < 0 || result_size != rw_len)
		    {
            //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: write 0 to temp file fail\n");
            //Kprintf();
		        goto FAIL;
        }
        entry_size -= rw_len;
    }
	  jvm_free(tmp_content);

	
	  if (FS_Seek(sms_temp_fd, 0, SEEK_SET) < 0)
	  {
	     	//sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: seek temp queue file fail\n");
	  	  //Kprintf();
	  	  goto FAIL;
	  }

    result = FS_Read(sms_fd, tmp_header, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result_size);
 	  if (result < 0 || result_size != SMSQUEUE_FILE_HEADER_SIZE)
	  {
        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: read file header fail\n");
        //Kprintf();
		    goto FAIL;
    }	
	
   	position =
            ((tmp_header[0] & 0xFF) << 24) | ((tmp_header[1] & 0xFF) << 16) | ((tmp_header[2] & 0xFF) << 8) | (tmp_header[3] &
                                                                                                      0xFF);
    result = FS_Write(sms_temp_fd, tmp_header, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result_size);
	  if (result < 0 || result_size != SMSQUEUE_FILE_HEADER_SIZE)
	  {
        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: write file header fail\n");
        //Kprintf();
		    goto FAIL;
    }

    size = position - SMSQUEUE_FILE_HEADER_SIZE;

    while (size > 0)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: size = %d\n", size);
        //Kprintf();
		    result = FS_Read(sms_fd, tmp_buf, SMSQUEUE_SMS_HEADER_SIZE, (kal_uint32 *)&result_size);
        if (result < 0 || result_size != SMSQUEUE_SMS_HEADER_SIZE)
		    {
            //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: read sms header fail\n");
            //Kprintf();
		        goto FAIL;
        }

		    temp_len = 
			      ((tmp_buf[5] & 0xFF) << 24) | ((tmp_buf[6] & 0xFF) << 16) | ((tmp_buf[7] & 0xFF) << 8) | (tmp_buf[8] &
                                                                                                      0xFF);
        port =
            ((tmp_buf[10] & 0xFF) << 24) | ((tmp_buf[11] & 0xFF) << 16) | ((tmp_buf[12] & 0xFF) << 8) | (tmp_buf[13] &
                                                                                                         0xFF);
        addr_len = (tmp_buf[23] & 0xFF);

		    if (addr_len)
		    {
		        addr_len++;
		    }

        if (port == dequeue_port && found == KAL_FALSE && delete_all == KAL_FALSE) /* retrieve a sms */
        {
            *type = 
				         ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3] &
                                                                                                      0xFF);
            *len = temp_len;

			      if (FS_Seek(sms_fd, addr_len, SEEK_CUR) < 0)
            {
                //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: seek temp queue file to next sms fail\n");
                //Kprintf();
		            goto FAIL;
            }
            buf = (kal_uint8*) get_ctrl_buffer((*len) + 1);
			      ASSERT(buf);
            memset(buf, 0x00, ((*len) + 1));
			      result = FS_Read(sms_fd, buf, *len, (kal_uint32 *)&result_size);
            if (result < 0 || result_size != *len)
			      {
                //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: read sms content to buffer fail\n");
                //Kprintf();
		            goto FAIL;
            }
		      	if (FS_Seek(sms_fd, 1, SEEK_CUR) < 0)
            {
                //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: seek temp queue file to next sms fail\n");
                //Kprintf();
		            goto FAIL;
            }
            found = KAL_TRUE;
		      	position -= (SMSQUEUE_SMS_HEADER_SIZE + addr_len + temp_len + 1);
        }
		    else if (port == dequeue_port && delete_all == KAL_TRUE) /* delete all sms of the port */
		    {
		        if (FS_Seek(sms_fd, addr_len + temp_len + 1, SEEK_CUR) < 0)
            {
                //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: seek temp queue file to next sms fail\n");
                //Kprintf();
		            goto FAIL;
            }
			      found = KAL_TRUE;
			      position -= (SMSQUEUE_SMS_HEADER_SIZE + addr_len + temp_len + 1);
		    }
        else  /* copy the entry to tmp file */
        {
            result = FS_Write(sms_temp_fd, tmp_buf, SMSQUEUE_SMS_HEADER_SIZE, (kal_uint32 *)&result_size);
            if (result < 0 || result_size != SMSQUEUE_SMS_HEADER_SIZE)
		       	{
                //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: write sms header to temp file fail\n");
                //Kprintf();
		            goto FAIL;
            }
         
            entry_size = addr_len + temp_len + 1;
			      tmp_content= (kal_uint8*) jvm_malloc(512);
            ASSERT(tmp_content);
            while (entry_size > 0)
            {
                memset(tmp_content, 0, 512);
                rw_len = (entry_size > 512 ? 512 : entry_size);
				        result = FS_Read(sms_fd, tmp_content, rw_len, (kal_uint32 *)&result_size);
                if (result < 0 || result_size != rw_len)
				        {
                    //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: read sms content to temp file fail\n");
                    //Kprintf();
		                goto FAIL;
                }
				        result = FS_Write(sms_temp_fd, tmp_content, rw_len, (kal_uint32 *)&result_size);
                if (result < 0 || result_size != rw_len)
				        {
                    //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: write sms content to temp file fail\n");
                    //Kprintf();
		                goto FAIL;
                }
                entry_size -= rw_len;
            }
		       	jvm_free(tmp_content);
        }

        size -= (SMSQUEUE_SMS_HEADER_SIZE + addr_len + temp_len + 1);

		    if (found && !delete_all)
		    {
		        entry_size = size;
		      	tmp_content= (kal_uint8*) jvm_malloc(512);
            ASSERT(tmp_content);
            while (entry_size > 0)
            {
                memset(tmp_content, 0, 512);
                rw_len = (entry_size > 512 ? 512 : entry_size);
				        result = FS_Read(sms_fd, tmp_content, rw_len, (kal_uint32 *)&result_size);
                if (result < 0 || result_size != rw_len)
				        {
                    //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: read remain content to temp file fail\n");
                    //Kprintf();
		                goto FAIL;
                }
				        result = FS_Write(sms_temp_fd, tmp_content, rw_len, (kal_uint32 *)&result_size);
                if (result < 0 || result_size != rw_len)
				        {
                    //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: write remain content to temp file fail\n");
                    //Kprintf();
		                goto FAIL;
                }
                entry_size -= rw_len;
            }
			      jvm_free(tmp_content);
                  kal_trace(TRACE_INFO, WMA_SMS_PERSISTENT_DEQUEUE_FOUND, *len, addr_len);
			      break;
		    }
    }

	  if (found)
	  {
	      /* seek to the beginning and set the file header */
	      if (FS_Seek(sms_temp_fd, 0, SEEK_SET) < 0)
        {
            //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: set position to reset file header fail \n");
            //Kprintf();
		        goto FAIL;
        }

        tmp_header[0] = (kal_uint8) ((position & 0xff000000) >> 24);
	      tmp_header[1] = (kal_uint8) ((position & 0x00ff0000) >> 16);
	      tmp_header[2] = (kal_uint8) ((position & 0x0000ff00) >> 8);
	      tmp_header[3] = (kal_uint8) (position & 0x000000ff);
	      tmp_header[4] = ' ';
		    result = FS_Write(sms_temp_fd, tmp_header, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result_size);
	      if (result < 0 || result_size != SMSQUEUE_FILE_HEADER_SIZE)
	      {
            //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: write file header fail \n");
            //Kprintf();
		        goto FAIL;
        }

		    for (i = 0; i < JAVA_SMS_MAX_PORT_NUM; i++)
		    {
		        if (j2me_sms_recv_num_list[i].port == (kal_uint16)dequeue_port)
		        {
		            if (delete_all)
		            {
		                j2me_sms_recv_num_list[i].number = (kal_uint16)0;
			        	}
				        else
				        {
				            j2me_sms_recv_num_list[i].number--;
				        }

				        if (j2me_sms_recv_num_list[i].number == (kal_uint16)0)
		            {
					          j2me_sms_recv_num_list[i].port = (kal_uint16)0;
				          	for (j = i; j < JAVA_SMS_MAX_PORT_NUM - 1; j++)
					          {
					              j2me_sms_recv_num_list[j].port = j2me_sms_recv_num_list[j + 1].port;
				                j2me_sms_recv_num_list[j].number = j2me_sms_recv_num_list[j + 1].number;
						            if (j2me_sms_recv_num_list[j + 1].port == (kal_uint16)0)
		                    {
		                        break;
		                    }
					          }
					          sprintf((char *)port_str, "sms://:%d", (int)dequeue_port);
		                jpush_push_set_unavailable_by_connection((char *)port_str);
				        }
				        break;
		        }
	      }
	  }

    FS_Close(sms_fd);
    FS_Close(sms_temp_fd);

    /* Delete old queue file, and update new queue file */
    if (FS_Delete(WCHARFilename_sms) < 0)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: delete sms queue file fail \n");
        //Kprintf();
		    goto FAIL2;
    }
    if (FS_Rename(WCHARFilename_sms_temp, WCHARFilename_sms) < 0)
	  {
        //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: rename sms temp queue file fail \n");
        //Kprintf();
        goto FAIL2;
    }
	  if ((sms_fd = FS_Open(WCHARFilename_sms_temp, O_BINARY | O_TRUNC | O_RDWR)) < 0)
	  {
		    //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: create temp file fail \n");
        //Kprintf();
		    sms_init_result = KAL_FALSE;
        goto FAIL2;
	  }
	  if (FS_Seek(sms_fd, SMSQUEUE_MAX_FILE_SIZE, SEEK_SET) < 0)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_dequeue_sms: seek temp file fail \n");
        //Kprintf();
	      sms_init_result = KAL_FALSE;
        goto FAIL1;
	  }
	  FS_Close(sms_fd);

    jvm_free(WCHARFilename_sms);
	  jvm_free(WCHARFilename_sms_temp);
	  kal_give_mutex(g_jam_async_sms_mutex);
    return buf;

FAIL:
	  FS_Close(sms_temp_fd);
FAIL1:
	  FS_Close(sms_fd);
FAIL2:
	  ASSERT(0);
	  if (WCHARFilename_sms)
	  {
	      jvm_free(WCHARFilename_sms);
	  }
	  if (WCHARFilename_sms_temp)
	  {
	      jvm_free(WCHARFilename_sms_temp);
	  }
	  *pszError = "J2ME_sms_dequeue_sms";
	  kal_give_mutex(g_jam_async_sms_mutex);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_sms_check_smsqueue_without_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [?]         
 *  len             [?]         
 *  check_port      [IN]        
 *  addr            [?]         
 *  timestamp       [?]
 *  only_new        [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 J2ME_sms_check_smsqueue_without_remove(
            kal_char** pszError,
            int *type,
            int *len,
            int check_port,
            kal_uint16 *addr,
            kal_uint8 *timestamp,
            kal_bool only_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  int sms_fd;
    kal_uint8 tmp_buf[SMSQUEUE_SMS_HEADER_SIZE];
	  kal_uint8 tmp_header[SMSQUEUE_FILE_HEADER_SIZE];
    kal_int32 size;
    int result;
	  int result_size;
    int port = 0;
    kal_uint8 addr_len = 0;
	  int check_flag = 0;
    kal_int32 position = 0;
	  kal_bool found = KAL_FALSE;
	  kal_wchar* WCHARFilename_sms = NULL;
	  kal_wchar* WCHARFilename_sms_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_PERSISTENT_CHECK, (int)check_port);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return -1;
    }
#endif
    kal_take_mutex(g_jam_async_sms_mutex);
    /* initialize invalid value */
    *type = -1;
    *len = -1;

	  if (!sms_init_result)
	  {
		    J2ME_sms_init();
		    if (!sms_init_result)
		    {
			      goto FAIL1;;
		    }
	  }

    /* Copy queue file to a temp file and modify it */
	  WCHARFilename_sms = (kal_wchar*)jvm_malloc((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_FILE) + 3) * 2);
	  if (WCHARFilename_sms == NULL)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: malloc sms string fail\n");
        //Kprintf();
		    goto FAIL1;
    }
	  WCHARFilename_sms_temp = (kal_wchar*)jvm_malloc((strlen(j2me_sys_dir_path) + strlen(SMSQUEUE_TEMP_FILE) + 3) * 2);
	  if (WCHARFilename_sms_temp == NULL)
    {
        //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: malloc sms temp string fail\n");
        //Kprintf();
		    goto FAIL1;
    }
	  kal_wsprintf(WCHARFilename_sms, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_FILE);
	  kal_wsprintf(WCHARFilename_sms_temp, "%s\\%s", j2me_sys_dir_path, SMSQUEUE_TEMP_FILE);
	  if (FS_Move(WCHARFilename_sms, WCHARFilename_sms_temp, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0) != FS_NO_ERROR) 
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: copy queue file fail\n");
        //Kprintf();
	      goto FAIL1;
	  }

    /* open temp queue file, read the file header */
	  if ((sms_fd = FS_Open(WCHARFilename_sms_temp, O_BINARY | O_RDWR)) < 0) 
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: open file fail\n");
        //Kprintf();
	      goto FAIL1;
	  }
	 
	  result = FS_Read(sms_fd, tmp_header, SMSQUEUE_FILE_HEADER_SIZE, (kal_uint32 *)&result_size);
	  if (result < 0 || result_size != SMSQUEUE_FILE_HEADER_SIZE)
   	{
        //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: seek file to beginning fail\n");
        //Kprintf();
        goto FAIL;
    }
	
	  size =
         ((tmp_header[0] & 0xFF) << 24) | ((tmp_header[1] & 0xFF) << 16) | ((tmp_header[2] & 0xFF) << 8) | (tmp_header[3] &
                                                                                                      0xFF);
    position += SMSQUEUE_FILE_HEADER_SIZE;

    while (position < size)
    {
        result = FS_Read(sms_fd, tmp_buf, SMSQUEUE_SMS_HEADER_SIZE, (kal_uint32 *)&result_size);
        if (result < 0 || result_size != SMSQUEUE_SMS_HEADER_SIZE)
		    {
            //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: FS_GetFilePosition fail\n");
            //Kprintf();
            goto FAIL;
        }
        
        *len =
             ((tmp_buf[5] & 0xFF) << 24) | ((tmp_buf[6] & 0xFF) << 16) | ((tmp_buf[7] & 0xFF) << 8) | (tmp_buf[8] &
                                                                                                      0xFF);
		    port =
             ((tmp_buf[10] & 0xFF) << 24) | ((tmp_buf[11] & 0xFF) << 16) | ((tmp_buf[12] & 0xFF) << 8) | (tmp_buf[13] &
                                                                                                         0xFF);
		    addr_len = (tmp_buf[23] & 0xFF);
		
		    check_flag =
             ((tmp_buf[25] & 0xFF) << 24) | ((tmp_buf[26] & 0xFF) << 16) | ((tmp_buf[27] & 0xFF) << 8) | (tmp_buf[28] &
                                                                                                         0xFF);
        		
        if (port == check_port)
        {
            if(only_new)
            {
                if (check_flag == 0)
                {
					           found = KAL_TRUE;
                     break;
                }
            }
			      else
			      {
				        found = KAL_TRUE;
                break;
			      }
        }

		    if (addr_len)
		    {
		        addr_len++;
		    }

		    if (FS_Seek(sms_fd, addr_len + *len + 1, SEEK_CUR) < 0)
        {
            //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: seek file to next sms fail\n");
            //Kprintf();
            goto FAIL;
        }
	
        position += (SMSQUEUE_SMS_HEADER_SIZE + addr_len + *len + 1);
    }

    /* if found out a sms, set the check_flag of this sms to 1 */
	  if (found)
	  {
        *type =
             ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3] &
                                                                                                      0xFF);
        
		    timestamp[0] = (tmp_buf[15] & 0xFF);
        timestamp[1] = (tmp_buf[16] & 0xFF);
        timestamp[2] = (tmp_buf[17] & 0xFF);
        timestamp[3] = (tmp_buf[18] & 0xFF);
        timestamp[4] = (tmp_buf[19] & 0xFF);
        timestamp[5] = (tmp_buf[20] & 0xFF);
        timestamp[6] = (tmp_buf[21] & 0xFF);

		    memset(addr, 0x00, sizeof(addr));
        if (addr_len > 0)
        {
            kal_wsprintf(addr, "%s", "sms://");
            result = FS_Read(sms_fd, &addr[6], addr_len, (kal_uint32 *)&result_size);
            if (result < 0 || result_size != addr_len)
			      {
                //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: read sms address fail\n");
                //Kprintf();
                goto FAIL;
            }
			      //kal_wsprintf(&addr[kal_wstrlen(addr)], ":%d", port);
        }

		    if (check_flag == 0)
		    {
		        if (FS_Seek(sms_fd, position, SEEK_SET) < 0)
            {
                //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: seek to sms header fail\n");
                //Kprintf();
                goto FAIL;
            }
		        check_flag = 1;
		        tmp_buf[25] = (kal_uint8) ((check_flag & 0xff000000) >> 24);
            tmp_buf[26] = (kal_uint8) ((check_flag & 0x00ff0000) >> 16);
            tmp_buf[27] = (kal_uint8) ((check_flag & 0x0000ff00) >> 8);
            tmp_buf[28] = (kal_uint8) (check_flag & 0x000000ff);
            tmp_buf[29] = ' ';
		      	result = FS_Write(sms_fd, tmp_buf, SMSQUEUE_SMS_HEADER_SIZE, (kal_uint32 *)&result_size);
		        if (result < 0 || result_size != SMSQUEUE_SMS_HEADER_SIZE)
		        {
		            //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: write sms header fail\n");
                //Kprintf();
                goto FAIL;
		        }
		    }
	  }
	
    FS_Close(sms_fd);

	  if (FS_Delete(WCHARFilename_sms) < 0)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: delete smsqueue file fail \n");
        //Kprintf();
	      goto FAIL1;
	  }
	  if (FS_Rename(WCHARFilename_sms_temp, WCHARFilename_sms) < 0)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: rename smsqueue temp file fail \n");
        //Kprintf();
        goto FAIL1;
	  }
	  if ((sms_fd = FS_Open(WCHARFilename_sms_temp, O_BINARY | O_TRUNC | O_RDWR)) < 0)
	  {
		    //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: create temp file fail \n");
        //Kprintf();
		   sms_init_result = KAL_FALSE;
        goto FAIL1;
	  }
	  if (FS_Seek(sms_fd, SMSQUEUE_MAX_FILE_SIZE, SEEK_SET) < 0)
	  {
	      //sprintf(_kvmLogStr, "J2ME_sms_check_smsqueue_without_remove: seek temp file fail \n");
        //Kprintf();
		    sms_init_result = KAL_FALSE;
        goto FAIL;
	  }
	  FS_Close(sms_fd);

    jvm_free(WCHARFilename_sms);
	  jvm_free(WCHARFilename_sms_temp);
	  kal_give_mutex(g_jam_async_sms_mutex);
    return 0;

FAIL:
	  FS_Close(sms_fd);
FAIL1:
	  ASSERT(0);
    if (WCHARFilename_sms)
	  {
	      jvm_free(WCHARFilename_sms);
	  }
	  if (WCHARFilename_sms_temp)
	  {
	      jvm_free(WCHARFilename_sms_temp);
	  }
	  *pszError = "J2ME_sms_dequeue_sms";
  	kal_give_mutex(g_jam_async_sms_mutex);
    return (-1);
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_register
 * DESCRIPTION
 *  register sms port and type
 * PARAMETERS
 *  portNumber      [IN]        
 *  type            [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int jwa_sms_register(long portNumber, int type, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_register_port_req_struct *p;
    int ret;
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_REGISTER, (int)portNumber, (int)type);

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* SMS service is not available during bg running state */
    	if (jam_mvm_get_current_vm_id() == -1)
        {
            //sprintf(_kvmLogStr,"jwa_sms_register: BG running state \n");
        	//Kprintf();
            
            return J2ME_SMS_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */

#ifdef __SUPPORT_JAVA_PUSH__
    ret = j2me_check_push_register_port(portNumber, type, vm_id);
#else
    ret = NON_REGISTERED;
#endif

    if (ret == NON_REGISTERED)
    {
        /* Only when the port is not registered, it can apply registration to low-layer */
        p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);

        p->blocking_data = NULL;
        p->enable = KAL_TRUE;
        p->port_number = (int)portNumber;

#if (MMI_MAX_SIM_NUM == 2)
        p->isSlave = KAL_FALSE;
        p->sim_id = SRV_SMS_SIM_1;
#elif (MMI_MAX_SIM_NUM >= 3)
        p->sim_id = SRV_SMS_SIM_1;
#endif
		p->vm_id = vm_id;

#if (MAX_VM_INSTANCE_NUM > 1)		
		kal_take_mutex(g_jam_async_sms_mvm_mutex);
		
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
#else   
        if ( J2ME_sms_record_pending_task(vm_id, p, JWA_SMS_STATE_REGISTER_PORT, NULL) == KAL_FALSE )
#endif 
#endif
		{
#if (MMI_MAX_SIM_NUM >= 2)
#if (MMI_MAX_SIM_NUM >= 4)
            ret = J2ME_sms_register_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM4, KAL_TRUE, vm_id);

            if (ret != 0)
            {
                free_local_para((local_para_struct*)p);
            #if (MAX_VM_INSTANCE_NUM > 1)
                kal_give_mutex(g_jam_async_sms_mvm_mutex);
            #endif
                return J2ME_SMS_NOT_AVAILABLE;
            }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
            ret = J2ME_sms_register_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, vm_id);

            if (ret != 0)
            {
                free_local_para((local_para_struct*)p);
#if (MMI_MAX_SIM_NUM >= 4)
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM4, KAL_TRUE, vm_id);
#endif
            #if (MAX_VM_INSTANCE_NUM > 1)
                kal_give_mutex(g_jam_async_sms_mvm_mutex);
            #endif
                return J2ME_SMS_NOT_AVAILABLE;
            }
#endif
        	ret = J2ME_sms_register_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, vm_id);

        	if (ret != 0)
        	{
        	    free_local_para((local_para_struct*)p);
#if (MMI_MAX_SIM_NUM >= 4)
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM4, KAL_TRUE, vm_id);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
			    J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, vm_id);
#endif
			#if (MAX_VM_INSTANCE_NUM > 1)
				kal_give_mutex(g_jam_async_sms_mvm_mutex);
			#endif
           		return J2ME_SMS_NOT_AVAILABLE;
        	}
#endif

			j2me_sms_register_enable = KAL_TRUE;
        	j2me_sms_register_type = type;
        	j2me_sms_register_port = (int)portNumber;

			j2me_sms_processing_task_vm_id = vm_id;
        	jwa_sms_set_state(JWA_SMS_STATE_REGISTER_PORT);
			
			/* fake module */
			java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);
		}
		
#if (MAX_VM_INSTANCE_NUM > 1)
		kal_give_mutex(g_jam_async_sms_mvm_mutex);
#endif

        kal_trace(TRACE_INFO, WMA_SMS_REGISTER1);

        return J2ME_SMS_BLOCK;
    }
    return J2ME_SMS_PORT_IN_USE_BY_PUSH;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_send_binary_message
 * DESCRIPTION
 *  send binary message
 * PARAMETERS
 *  addr            [?]         
 *  pBuffer         [?]         
 *  buflength       [IN]        
 *  portNumber      [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int jwa_sms_send_binary_message(unsigned short *addr, char *pBuffer, int buflength, long portNumber, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    int i;
    mmiapi_sms_send_req_struct *p = NULL;
    kal_uint8 sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_SEND_BINARY);

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* SMS service is not available during bg running state */
    	if (jam_mvm_get_current_vm_id() == -1)
        {
            //sprintf(_kvmLogStr,"jwa_sms_send_binary_message: BG running state \n");
        	//Kprintf();
        
            return J2ME_SMS_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */

    p = NEW_LOCAL_PTR(mmiapi_sms_send_req_struct);

    //buflength <<= 1;    /* for ucs2 length */

    p->blocking_data = NULL;

    p->dcs = SRV_SMS_DCS_8BIT;
    p->port_number = (int)portNumber;

#if (MMI_MAX_SIM_NUM == 2)
    if (jam_mvm_get_valid_sim_id(vm_id) == CBM_SIM_ID_SIM2)
    {
        p->isSlave = KAL_TRUE;
    }
    else
    {
        p->isSlave = KAL_FALSE;
    }
#elif (MMI_MAX_SIM_NUM >= 3)
    sim_id = jam_mvm_get_valid_sim_id(vm_id);
#if (MMI_MAX_SIM_NUM >= 4)
    if (sim_id == CBM_SIM_ID_SIM4)
    {
        p->sim_id = SRV_SMS_SIM_4;
    }
    else
#endif
    if (sim_id == CBM_SIM_ID_SIM3)
    {
        p->sim_id = SRV_SMS_SIM_3;
    }
    else if (sim_id == CBM_SIM_ID_SIM2)
    {
        p->sim_id = SRV_SMS_SIM_2;
    }
    else 
    {
        p->sim_id = SRV_SMS_SIM_1;
    }
#endif

    /* Check if the size exceeds the limitation of control buffer */
    if (buflength >= 2048)
    {
        free_local_para((local_para_struct*) p);
        return J2ME_SMS_CONTENT_SIZE_EXCEED;
    }

    /* Prevent to allocate control buffer with zero size */
    /*if (buflength == 0)
    {
        buflength += 2;
    }*/
    
    p->msg = (kal_uint8*) get_ctrl_buffer((kal_uint16) (buflength + 1));

     p->msg_length = buflength;

    //J2ME_sms_ansii_n_to_unicode((S8*) p->msg, (S8*) pBuffer, (U32) (p->msg_length) / 2);
    memset(p->msg, 0, buflength + 1);
	  memcpy(p->msg, pBuffer, buflength);

    if (addr[0] == (short)'+')
    {
        p->addr.type = MMIAPI_SMS_ADDR_TYPE_INTERNATIONAL;
        addr++;
    }
    else
    {
        p->addr.type = MMIAPI_SMS_ADDR_TYPE_DEFAULT;
    }

    len = (int)mmi_ucs2strlen((const S8*)addr);
    if (len > MAX_CC_ADDR_LEN / ENCODING_LENGTH)
    {
        len = MAX_CC_ADDR_LEN / ENCODING_LENGTH;
    }
    p->addr.length = len;
    mmi_ucs2_n_to_asc((S8*) p->addr.number, (S8*) addr, p->addr.length * ENCODING_LENGTH);
    p->addr.number[p->addr.length] = '\0';

    /* Display the sending icon */
    p->isNotDispSendingIcon = KAL_FALSE;

    p->vm_id = vm_id;

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_take_mutex(g_jam_async_sms_mvm_mutex);

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
#else
    if ( J2ME_sms_record_pending_task(vm_id, p, JWA_SMS_STATE_SEND, pBuffer) == KAL_FALSE )
#endif
#endif
    {
		j2me_sms_processing_task_vm_id = vm_id;
        jwa_sms_set_state(JWA_SMS_STATE_SEND);

        /* fake module */
        java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_SEND_REQ, p);
    }

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_give_mutex(g_jam_async_sms_mvm_mutex);
#endif

    kal_trace(TRACE_INFO, WMA_SMS_SEND_BINARY1);

    return J2ME_SMS_BLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_send_text_message
 * DESCRIPTION
 *  send text message
 * PARAMETERS
 *  addr            [?]         
 *  pBuffer         [?]         
 *  buflength       [IN]        
 *  portNumber      [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int jwa_sms_send_text_message(unsigned short *addr, unsigned short *pBuffer, int buflength, long portNumber, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
	int i;
    mmiapi_sms_send_req_struct *p = NULL;
    kal_uint8 sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_SEND_TEXT);

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* SMS service is not available during bg running state */
    	if (jam_mvm_get_current_vm_id() == -1)
        {
            //sprintf(_kvmLogStr,"jwa_sms_send_text_message: BG running state \n");
        	//Kprintf();
        
            return J2ME_SMS_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */

    p = NEW_LOCAL_PTR(mmiapi_sms_send_req_struct);

    buflength <<= 1;    /* for ucs2 length */

    p->dcs = SRV_SMS_DCS_UCS2;

    p->blocking_data = NULL;

    p->port_number = (int)portNumber;

#if (MMI_MAX_SIM_NUM == 2)
    if (jam_mvm_get_valid_sim_id(vm_id) == CBM_SIM_ID_SIM2)
    {
        p->isSlave = KAL_TRUE;
    }
    else
    {
        p->isSlave = KAL_FALSE;
    }
#elif (MMI_MAX_SIM_NUM >= 3)
    sim_id = jam_mvm_get_valid_sim_id(vm_id);
#if (MMI_MAX_SIM_NUM >= 4)
    if (sim_id == CBM_SIM_ID_SIM4)
    {
        p->sim_id = SRV_SMS_SIM_4;
    }
    else
#endif
    if (sim_id == CBM_SIM_ID_SIM3)
    {
        p->sim_id = SRV_SMS_SIM_3;
    }
    else if (sim_id == CBM_SIM_ID_SIM2)
    {
        p->sim_id = SRV_SMS_SIM_2;
    }
    else 
    {
        p->sim_id = SRV_SMS_SIM_1;
    }
#endif

	/* The max control buffer size is 2K. So we limit the max size 1920 here. */
	if (buflength > 1920)
    {
        free_local_para((local_para_struct*) p);
        return J2ME_SMS_CONTENT_SIZE_EXCEED;
    }
    
    p->msg = (kal_uint8*) get_ctrl_buffer((kal_uint16) (buflength + 1));
	  memset((S8*) p->msg, 0, (buflength + 1));
	  memcpy(p->msg, pBuffer, buflength);
    p->msg_length = buflength;

    if (addr[0] == (short)'+')
    {
        p->addr.type = MMIAPI_SMS_ADDR_TYPE_INTERNATIONAL;
        addr++;
    }
    else
    {
        p->addr.type = MMIAPI_SMS_ADDR_TYPE_DEFAULT;
    }

    len = (int)mmi_ucs2strlen((const S8*)addr);
    if (len > MAX_CC_ADDR_LEN / ENCODING_LENGTH)
    {
        len = MAX_CC_ADDR_LEN / ENCODING_LENGTH;
    }
    p->addr.length = len;

    mmi_ucs2_n_to_asc((S8*) p->addr.number, (S8*) addr, p->addr.length * ENCODING_LENGTH);
    p->addr.number[p->addr.length] = '\0';
    
    /* Display the sending icon */
    p->isNotDispSendingIcon = KAL_FALSE;

    p->vm_id = vm_id;

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_take_mutex(g_jam_async_sms_mvm_mutex);

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
#else
    if ( J2ME_sms_record_pending_task(vm_id, p, JWA_SMS_STATE_SEND, pBuffer) == KAL_FALSE )
#endif
#endif
    {
		j2me_sms_processing_task_vm_id = vm_id;
        jwa_sms_set_state(JWA_SMS_STATE_SEND);

    	/* fake module */
    	java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_SEND_REQ, p);
    }

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_give_mutex(g_jam_async_sms_mvm_mutex);
#endif

    kal_trace(TRACE_INFO, WMA_SMS_SEND_TEXT1);
    return J2ME_SMS_BLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  _jwa_sms_check_incoming_msg
 * DESCRIPTION
 *  check if message coming
 * PARAMETERS
 *  portNumber      [IN]        
 *  only_new        [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int _jwa_sms_check_incoming_msg(long portNumber, kal_bool only_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmiapi_sms_check_incoming_msg_req_struct *p = NEW_LOCAL_PTR(mmiapi_sms_check_incoming_msg_req_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_CHECK_INCOMING, (int)portNumber);

    /*p->blocking_data = NULL;
    p->port_number = (int)portNumber;
    p->only_new = (kal_bool) only_new;

    jwa_sms_set_state(JWA_SMS_STATE_CHECK_INCOMING_MSG);*/

    /* fake module */
    //SEND_MESSAGE(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_CHECK_INCOMING_MSG_REQ, p, NULL);

    kal_trace(TRACE_INFO, WMA_SMS_CHECK_INCOMING1);

    return J2ME_SMS_BLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_check_incoming_msg
 * DESCRIPTION
 *  check if message coming
 * PARAMETERS
 *  portNumber      [IN]        
 *  only_new        [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int jwa_sms_check_incoming_msg(long portNumber, kal_bool only_new, int *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  kal_uint8 timestamp[7];                
	  kal_int32 ret = -1;
	  int msg_len = 0;
      int type = -1;
	  int i;
	  kal_char *pszError = NULL;
	  kal_bool checked = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(TRACE_INFO, WMA_SMS_CHECK_INCOMING, (int)portNumber);

	for (i = 0; i < JAVA_SMS_MAX_PORT_NUM; i++)
	{
	    if (j2me_sms_recv_num_list[i].port == (kal_uint16)portNumber)
		{
		    checked = KAL_TRUE;
		    break;
	    }
		else if (j2me_sms_recv_num_list[i].port == (kal_uint16)0)
		{
		    break;
		}
    }

	  if (checked)
	  {
	      ret = J2ME_sms_check_smsqueue_without_remove(&pszError, &type, &msg_len, portNumber, 
		    (kal_uint16*)j2me_sms_tel_num_ucs2, (kal_uint8*)timestamp, only_new);
        if (pszError == NULL && ret != -1) 
	      {      
		        *result = type;
        }
	      else
	      {
		        *result = -1;
	      }
	  }
	  else
	  {
	      *result = -1;
	  }	  

	  kal_trace(TRACE_INFO, WMA_SMS_CHECK_INCOMING1);
      return J2ME_SMS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  _jwa_sms_receive_binary_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int _jwa_sms_receive_binary_msg_req(long portNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmiapi_sms_get_incoming_msg_req_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_incoming_msg_req_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_RECV_BINARY, (int)portNumber);

    //p->blocking_data = NULL;
    //p->port_number = (int)portNumber;
    
    //jwa_sms_set_state(JWA_SMS_STATE_GET_INCOMING_MSG);

    /* fake module */
    //SEND_MESSAGE(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_REQ, p, NULL);

    kal_trace(TRACE_INFO, WMA_SMS_RECV_BINARY1);
    return J2ME_SMS_BLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_receive_binary_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int jwa_sms_receive_binary_msg_req(long port)
{  	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint8 *msg = NULL;
	int msg_len = -1;
	int type;
	kal_char *pszError = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(TRACE_INFO, WMA_SMS_RECV_BINARY, (int)port);

    /* If found an matched entry in persistent queue, send */
	msg = J2ME_sms_dequeue_sms(&pszError, &type, &msg_len, (int)port, KAL_FALSE);
	if (pszError == NULL) 
	{
        j2me_sms_receive_len = msg_len;
        J2ME_sms_free_data();
        j2me_sms_recceive_data_ptr = (void*)msg;
		
        jwa_sms_set_state(JWA_SMS_STATE_GET_INCOMING_MSG);
		
        kal_trace(TRACE_INFO, WMA_SMS_RECV_BINARY1);
        return J2ME_SMS_OK;
	}
	
	if (msg != NULL)
	{
	    free_ctrl_buffer(msg);
	}
	
	return J2ME_SMS_NOT_AVAILABLE;
}

/*****************************************************************************
 * FUNCTION
 *  jwa_sms_receive_binary_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  len     [?]     
 * RETURNS
 *  pointer to received buffer
 *****************************************************************************/
char *jwa_sms_receive_binary_msg_rsp(int *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JWA_SMS_STATE_GET_INCOMING_MSG == jwa_sms_get_state())
    {
        jwa_sms_set_state(JWA_SMS_STATE_IDLE);
    }
    else
    {
        //sprintf(_kvmLogStr,"jwa_sms_receive_binary_msg_rsp: STRANGE state= %d\n", jwa_sms_get_state());
        //Kprintf();
	    ASSERT(0);
    }

	if (j2me_sms_recceive_data_ptr)
	{
	    *len = j2me_sms_receive_len;
	}
	else
	{
        *len = 0;
	}
    return (char*)j2me_sms_recceive_data_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  _jwa_sms_receive_text_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int _jwa_sms_receive_text_msg_req(long portNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmiapi_sms_get_incoming_msg_req_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_incoming_msg_req_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_RECV_TEXT, (int)portNumber);

    //p->blocking_data = NULL;
    //p->port_number = (int)portNumber;

    jwa_sms_set_state(JWA_SMS_STATE_GET_INCOMING_MSG);

    /* fake module */
    //SEND_MESSAGE(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_REQ, p, NULL);

    kal_trace(TRACE_INFO, WMA_SMS_RECV_TEXT1);

    return J2ME_SMS_BLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_receive_text_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int jwa_sms_receive_text_msg_req(long port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint8 *msg = NULL;
	int msg_len = -1;
	int type;
	kal_char *pszError = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(TRACE_INFO, WMA_SMS_RECV_TEXT, (int)port);

    /* If found an matched entry in persistent queue, send */
    msg = J2ME_sms_dequeue_sms(&pszError, &type, &msg_len, port, KAL_FALSE);
	if (pszError == NULL) 
	{
        j2me_sms_receive_len = msg_len;
        J2ME_sms_free_data();
        j2me_sms_recceive_data_ptr = (void*)msg;
		
        jwa_sms_set_state(JWA_SMS_STATE_GET_INCOMING_MSG);
		
        kal_trace(TRACE_INFO, WMA_SMS_RECV_TEXT1);
	    return J2ME_SMS_OK;
	}

	if (msg != NULL)
	{
	    free_ctrl_buffer(msg);
	}

	return J2ME_SMS_NOT_AVAILABLE;
}

/*****************************************************************************
 * FUNCTION
 *  jwa_sms_receive_text_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  len     [?]     
 * RETURNS
 *  pointer to received buffer
 *****************************************************************************/
unsigned short *jwa_sms_receive_text_msg_rsp(int *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JWA_SMS_STATE_GET_INCOMING_MSG == jwa_sms_get_state())
    {
        jwa_sms_set_state(JWA_SMS_STATE_IDLE);
    }
    else
    {
        //sprintf(_kvmLogStr,"jwa_sms_receive_text_msg_rsp: STRANGE state= %d\n", jwa_sms_get_state());
        //Kprintf();
	      ASSERT(0);
    }
    
    if (j2me_sms_recceive_data_ptr)
	{
	    *len = j2me_sms_receive_len;
	}
	else
	{
        *len = 0;
	}
    return (unsigned short*)(j2me_sms_recceive_data_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_number_of_text_segments
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pBuffer         [?]         
 *  pBufferLen      [IN]        
 * RETURNS
 *  number of text message segments
 *****************************************************************************/
int jwa_sms_number_of_text_segments(unsigned short *pBuffer, int pBufferLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData ems_data;
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_NO_TEXT_SEGMENT, pBufferLen);
    if (pBufferLen * 2 <= 140)
    {
        return 1;
    }
	
    if (InitializeEMSData(&ems_data, (kal_uint8) SMSAL_UCS2_DCS) == EMS_OK)
    {
        kal_mem_cpy(ems_data.textBuffer, pBuffer, pBufferLen * 2);
        ems_data.textLength = pBufferLen * 2;
        if (EMSCalculateLength(&ems_data) == EMS_OK)
        {
            ret = ems_data.Reminder.requiredSegment;
            kal_trace(TRACE_INFO, WMA_SMS_NO_TEXT_SEGMENT1, ret);
        }
        ReleaseEMSData(&ems_data);

    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_number_of_binary_segments
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pBuffer         [?]         
 *  pBufferLen      [IN]        
 * RETURNS
 *  number of binary message segments
 *****************************************************************************/
int jwa_sms_number_of_binary_segments(char *pBuffer, int pBufferLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData ems_data;
    int ret = 0;
    kal_uint8 *ucs2_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_NO_BINARY_SEGMENT, pBufferLen);

    /* Return 0 if the message object cannot be sent using the underlying protocol  */
    if ((pBufferLen << 1) > 2048)
    {
        return 0;
    }

    if (pBufferLen == 0)
    {
        return 0;
    }

    if (pBufferLen <= 140)
    {
        return 1;
    }

    ucs2_buffer = (kal_uint8*) get_ctrl_buffer((kal_uint16) (pBufferLen << 1));

    J2ME_sms_ansii_n_to_unicode((S8*) ucs2_buffer, (S8*) pBuffer, (U32) pBufferLen);

    if (InitializeEMSData(&ems_data, (kal_uint8) SMSAL_8BIT_DCS) == EMS_OK)
    {
        kal_mem_cpy(ems_data.textBuffer, pBuffer, pBufferLen);
        ems_data.textLength = pBufferLen;
        if (EMSCalculateLength(&ems_data) == EMS_OK)
        {
            ret = ems_data.Reminder.requiredSegment;
            kal_trace(TRACE_INFO, WMA_SMS_NO_BINARY_SEGMENT1, ret);
        }
        ReleaseEMSData(&ems_data);
    }
    free_ctrl_buffer(ucs2_buffer);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_unregister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 *  type            [IN]        
 * RETURNS
 *  J2me_sms_result_enum
 *****************************************************************************/
int jwa_sms_unregister(long portNumber, int type, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_register_port_req_struct *p;
    int ret;
	kal_uint8 *msg = NULL;
	int msg_len = -1;
	int sms_type;
	kal_char *pszError = NULL;

#if (MMI_MAX_SIM_NUM >= 2)
    kal_int32 ret_sim;
#endif
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER, portNumber);

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* SMS service is not available during bg running state */
    	if (jam_mvm_get_current_vm_id() == -1)
        {
    	      //sprintf(_kvmLogStr,"jwa_sms_unregister: BG running state \n");
    	      //Kprintf();
    			
    	      return J2ME_SMS_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */

#ifdef __SUPPORT_JAVA_PUSH__
    ret = j2me_check_push_register_port(portNumber, type, vm_id);
#else
    ret = NON_REGISTERED;
#endif

    kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER1, ret);

    if (((type == WMA_REGISTRY) && (ret != PUSH_REGISTERED) && (ret != PUSH_CONFLICT_REGISTERED)) || 
        ((type == PUSH_REGISTRY) && (ret == PUSH_REGISTERED)))
    {
	    msg = J2ME_sms_dequeue_sms(&pszError, &sms_type, &msg_len, (int)portNumber, KAL_TRUE);
	    if (msg != NULL)
	    {
	        jvm_free(msg);
	    }
	    if (pszError != NULL) 
	    {
	        //sprintf(_kvmLogStr,"jwa_sms_unregister: delete sms in queue file fail\n");
            //Kprintf();
	        return J2ME_SMS_NOT_AVAILABLE;
	    }

        p = NEW_LOCAL_PTR(mmiapi_sms_register_port_req_struct);

        p->blocking_data = NULL;
        p->enable = KAL_FALSE;
        p->port_number = (int)portNumber;
        p->remove_reminder_data = KAL_TRUE;

#if (MMI_MAX_SIM_NUM == 2)
        p->isSlave = KAL_FALSE;
        p->sim_id = SRV_SMS_SIM_1;
#elif (MMI_MAX_SIM_NUM >= 3)
        p->sim_id = SRV_SMS_SIM_1;
#endif

		p->vm_id = vm_id;

#if (MAX_VM_INSTANCE_NUM > 1)				
		kal_take_mutex(g_jam_async_sms_mvm_mutex);
				
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
#else
        if ( J2ME_sms_record_pending_task(vm_id, p, JWA_SMS_STATE_REGISTER_PORT, NULL) == KAL_FALSE )
#endif
#endif
		{
#if (MMI_MAX_SIM_NUM >= 2)
#if (MMI_MAX_SIM_NUM >= 4)
            ret_sim = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM4, KAL_TRUE, vm_id);

            if (ret_sim != 0)
            {
                free_local_para((local_para_struct*)p);
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, vm_id);
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, vm_id);
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_TRUE, vm_id);
            #if (MAX_VM_INSTANCE_NUM > 1)
                kal_give_mutex(g_jam_async_sms_mvm_mutex);
            #endif
                return J2ME_SMS_NOT_AVAILABLE;
            }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
            ret_sim = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM3, KAL_TRUE, vm_id);

            if (ret_sim != 0)
            {
                free_local_para((local_para_struct*)p);
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, vm_id);
            	J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_TRUE, vm_id);
            #if (MAX_VM_INSTANCE_NUM > 1)
                kal_give_mutex(g_jam_async_sms_mvm_mutex);
            #endif
            	return J2ME_SMS_NOT_AVAILABLE;
            }
#endif
            ret_sim = J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM2, KAL_TRUE, vm_id);

            if (ret_sim != 0)
            {
                free_local_para((local_para_struct*)p);
                J2ME_sms_unregister_sim_type(portNumber, type, JWA_SMS_SIM_TYPE_SIM1, KAL_TRUE, vm_id);
            #if (MAX_VM_INSTANCE_NUM > 1)
                 kal_give_mutex(g_jam_async_sms_mvm_mutex);
            #endif
                return J2ME_SMS_NOT_AVAILABLE;
            }
#endif

			j2me_sms_register_enable = KAL_FALSE;
            j2me_sms_register_type = type;

			j2me_sms_processing_task_vm_id = vm_id;				
			jwa_sms_set_state(JWA_SMS_STATE_REGISTER_PORT);

			/* fake module */
			java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ, p);

			//resouceDereg(JAVA_WMA_SMS_DEVICE, portNumber);    //20101104,changed resource mgr for MVM
			jvm_resource_mgr_deregister(vm_id,JAVA_WMA_SMS_DEVICE,portNumber);
		}
				
#if (MAX_VM_INSTANCE_NUM > 1)
		kal_give_mutex(g_jam_async_sms_mvm_mutex);
#endif

        kal_trace(TRACE_INFO, WMA_SMS_UNREGISTER2);

        return J2ME_SMS_BLOCK;
    }
    

    if ((type == WMA_REGISTRY) && ((ret == PUSH_REGISTERED) || (ret == PUSH_CONFLICT_REGISTERED)))
    {
        return J2ME_SMS_PORT_IN_USE_BY_PUSH;
    }
    else if((type == PUSH_REGISTRY) && (ret == WMA_REGISTERED))
    {
        return J2ME_SMS_PORT_IN_USE;
    }
    else if((type == PUSH_REGISTRY) && (ret == PUSH_CONFLICT_REGISTERED))
    {
        return J2ME_SMS_PORT_IN_USE_BY_PUSH;
    }
    else
    {
        return J2ME_SMS_PORT_NOT_IN_USE;
    }    
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
 *  jwa_sms_get_ori_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 * RETURNS
 *  time of sms send or received
 *****************************************************************************/
kal_bool jwa_sms_get_ori_timestamp(long portNumber, kal_uint8* time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_blocking_data_struct *blocking;
    kal_uint8 scts[7];
    mmiapi_sms_get_incoming_msg_timestamp_req_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_incoming_msg_timestamp_req_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);
    blocking->result_ptr = (void*)scts;

    p->blocking_data = blocking;
    p->port_number = (int)portNumber;

    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_TIMESTAMP_REQ, p);

    mmiapi_lock(MOD_JASYN_D); /* waiting the check incoming result */

    memcpy(time, scts, 7);
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 * RETURNS
 *  time of sms send or received
 *****************************************************************************/
kal_uint64 jwa_sms_get_timestamp(long portNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint8 scts[7];        
    kal_uint64 time = 0;
    kal_int32 ret = -1;
    int msg_len = 0;
    int type = 0;
	kal_uint16 year;
	kal_char *pszError = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = J2ME_sms_check_smsqueue_without_remove(&pszError, &type, &msg_len, portNumber, 
	    (kal_uint16*)j2me_sms_tel_num_ucs2, (kal_uint8*)scts, KAL_FALSE);
    if (pszError == NULL && ret != -1) 
    {           
        year = (((kal_uint16) scts[0] << 8) & 0xFF00) | ((kal_uint16) scts[1] & 0x00FF);
		//sprintf(_kvmLogStr,"jwa_sms_get_timestamp: year = [%d]\n", (int)year);
        //Kprintf();
		
		time = (kal_uint64) getJulianOffsetTimeInMillis(
                                 year,   /* year */
                                 scts[2] - 1,   /* month */
                                 scts[3], /* day */
                                 scts[4], /* hour */
                                 scts[5], /* minute */
                                 scts[6], /* second */
                                 (int)0);

        /* adjust the timezone to GMT - local time offset, the TimeZone class will add local time offset */
        time -= (kal_uint64) (((int)(mmi_dt_get_tz() * 60)) * 60 * 1000);
    }

	return time;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_incoming_msg_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 *  len             [?]         
 * RETURNS
 *  sender address of sms
 *****************************************************************************/
unsigned short *_jwa_sms_get_incoming_msg_addr(long portNumber, int *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tel_num[6 + MAX_CC_ADDR_LEN + 6];
    int i;

    l4c_number_struct *addr_num, ADDR_NUM;
    mmiapi_blocking_data_struct *blocking;
    mmiapi_sms_get_incoming_msg_timestamp_req_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_incoming_msg_timestamp_req_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_num = &ADDR_NUM;

    blocking = mmiapi_get_blocking_data(MOD_JASYN_D);
    blocking->result_ptr = (void*)&ADDR_NUM;

    p->blocking_data = blocking;
    p->port_number = (int)portNumber;

    /* fake module */
    java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_ADDRESS_REQ, p);

    mmiapi_lock(MOD_JASYN_D); /* waiting the check incoming result */

    strcpy((char*)tel_num, "sms://");
    if (addr_num->type == MMIAPI_SMS_ADDR_TYPE_INTERNATIONAL)
    {
        tel_num[6] = '+';
        strcpy((char*)(tel_num + 7), (char*)addr_num->number);
    }
    else
    {
        strcpy((char*)(tel_num + 6), (char*)addr_num->number);
    }

    i = strlen((char*)tel_num);
    sprintf((char*)(tel_num + i), ":%d", (int)portNumber);

    mmi_asc_to_ucs2((S8*) j2me_sms_tel_num_ucs2, (S8*) tel_num);

    *len = mmi_ucs2strlen((const S8*)j2me_sms_tel_num_ucs2) * 2;
    return (unsigned short*)j2me_sms_tel_num_ucs2;
}



/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_incoming_msg_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  portNumber      [IN]        
 *  len             [?]         
 * RETURNS
 *  sender address of sms
 *****************************************************************************/
unsigned short *jwa_sms_get_incoming_msg_addr(long portNumber, int *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint8 time[7];        
    kal_int32 ret = -1;
    int msg_len = 0;
    int type = 0;
	kal_char *pszError = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(j2me_sms_tel_num_ucs2, 0x00, sizeof(j2me_sms_tel_num_ucs2));
	ret = J2ME_sms_check_smsqueue_without_remove(&pszError, &type, &msg_len, portNumber, 
	    (kal_uint16*)j2me_sms_tel_num_ucs2, (kal_uint8*)time, KAL_FALSE);
    if (pszError == NULL && ret != -1) 
    {            
        *len = mmi_ucs2strlen((const S8*)j2me_sms_tel_num_ucs2);
    }
	else
	{
	    *len = 0;
	}

    return (unsigned short*)j2me_sms_tel_num_ucs2;
}



/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_primitive_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jwa_sms_get_primitive_result()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jwa_sms_state_enum state = (jwa_sms_state_enum)jwa_sms_get_state();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (state)
    {
        case JWA_SMS_STATE_SEND:
        case JWA_SMS_STATE_CHECK_INCOMING_MSG:
        case JWA_SMS_STATE_REGISTER_PORT:
        {
            jwa_sms_set_state(JWA_SMS_STATE_IDLE);
        }
        break;

        case JWA_SMS_STATE_GET_INCOMING_MSG:
        {
            /* set idle after the content is gotten by caller. */
        }
        break;

        default:
        {

        }
        break;
    }
    
    return (int)j2me_sms_result;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_response_primitive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jwa_sms_get_response_primitive()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    unsigned long message_id;
    int result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message_id = readSmsAsyncEvent();

    switch (message_id)
    {
        case MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP:
        {
            result = MSG_J2ME_SMS_REGISTER_PORT_RSP;
        }
            break;

        case MSG_ID_MMIAPI_SMS_SEND_RSP:
        {
            result = MSG_J2ME_SMS_SEND_RSP;
        }
            break;

        default:
        {
            result = -1;
        }
            break;

    }

    return (result);

}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jwa_sms_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jwa_sms_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    finalizeSms();
    return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jwa_sms_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_GET_STATE, jwa_sms_state);

    return jwa_sms_state;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_set_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jwa_sms_set_state(int state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_SMS_SET_STATE, state, jwa_sms_state);

    jwa_sms_state = state;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_initialize_vm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id  [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jwa_sms_initialize_vm(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM > 1)
	J2ME_sms_mvm_init();
#endif
	jwa_sms_init_smsc_addr(vm_id);

	return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_finalize_vm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id  [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jwa_sms_finalize_vm(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM > 1)
    finalizeSmsByVM(vm_id);
#endif
	return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_smsc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_char *jwa_sms_get_smsc_addr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//sprintf(_kvmLogStr,"jwa_sms_get_smsc_addr\n");
	//Kprintf(); 
	
	return j2me_sms_smsc_addr;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_init_smsc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jwa_sms_init_smsc_addr(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//sprintf(_kvmLogStr,"jwa_sms_init_smsc_addr\n");
	  //Kprintf(); 

	  if (!mmi_java_is_no_sim())
    {
        mmiapi_sms_get_smsc_addr_req_struct* p;
      
        p = construct_local_para(sizeof(mmiapi_sms_get_smsc_addr_req_struct), TD_CTRL);
      
        p->mod_id = MOD_JASYN;
		
#if (MMI_MAX_SIM_NUM == 2)
        if (jam_mvm_get_valid_sim_id(vm_id) == CBM_SIM_ID_SIM2)
        {
            p->isSlave = KAL_TRUE;
        }
        else
		    {
			      p->isSlave = KAL_FALSE;
		    }
#elif (MMI_MAX_SIM_NUM >= 3)
        sim_id = jam_mvm_get_valid_sim_id(vm_id);
#if (MMI_MAX_SIM_NUM >= 4)
        if (sim_id == CBM_SIM_ID_SIM4)
        {
            p->sim_id = SRV_SMS_SIM_4;
        }
        else
#endif
        if (sim_id == CBM_SIM_ID_SIM3)
        {
            p->sim_id = SRV_SMS_SIM_3;
        }
        else if (sim_id == CBM_SIM_ID_SIM2)
        {
            p->sim_id = SRV_SMS_SIM_2;
        }
        else 
        {
            p->sim_id = SRV_SMS_SIM_1;
        }
#endif

        java_send_msg(MOD_JASYN_D, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_SMS_GET_SMSC_ADDR_REQ, p);
    }
	  else
	  {
	      memset(j2me_sms_smsc_addr, 0, SRV_SMS_MAX_ADDR_LEN + 1);
	  }
}


/*****************************************************************************
 * FUNCTION
 *  jwa_sms_get_smsc_addr_handler
 * DESCRIPTION
 *  Get SMSC address string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jwa_sms_get_smsc_addr_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  mmiapi_sms_get_smsc_addr_rsp_struct *p = (mmiapi_sms_get_smsc_addr_rsp_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	  //sprintf(_kvmLogStr,"jwa_sms_get_smsc_addr_handler");
	  //Kprintf(); 
	
	  memset(j2me_sms_smsc_addr, 0, SRV_SMS_MAX_ADDR_LEN + 1);
    if(p->result == KAL_TRUE)
	  {
		    memcpy(j2me_sms_smsc_addr, (kal_char*)p->sc_addr, p->sc_addr_len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  is_sms_activated
 * DESCRIPTION
 *  check if there is any pending sms requests
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if there is pending sms request, FALSE otherwise.
 *****************************************************************************/
kal_bool is_sms_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int state = jwa_sms_get_state();
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state == JWA_SMS_STATE_SEND ||
        state == JWA_SMS_STATE_GET_INCOMING_MSG ||
        state == JWA_SMS_STATE_REGISTER_PORT)
    {
        ret = KAL_TRUE;
    }
    else
    {
        ret = KAL_FALSE;
    }
    kal_trace(TRACE_INFO, WMA_SMS_IS_ACTIVATED, (int)ret, state);
    return ret;
}

#endif //#ifdef SUPPORT_JSR_120

