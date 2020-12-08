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
 *  jwa_mms.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "jal.h"

#ifdef SUPPORT_JSR_205

#include "mmi_frm_gprot.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"
#include "fat_fs.h"
#include "wap_ps_struct.h"
#include "browser_struct.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "mmc_struct.h"

//#include "pushregistry.h"
#include "j2me_trace.h"

#include "jal_internal.h"
#include "jam_msg_handler.h"

#include "jwa_internal.h"

#include "SimCtrlSrvGprot.h"
#include "jam_mvm_manager.h"
#include "Jvm_interface.h"

kal_char j2me_mms_mmsc_addr[J2ME_MMS_MMSC_ADDR_LEN] = {0};

extern kal_mutexid g_jam_async_mms_mvm_mutex;

/* extern kal_char *j2me_dir_path; */

kal_char jwa_mms_msg_part_file_path[] = "D:\\@Java\\mms";

/* static kal_uint8 j2me_mms_msg_type; */
static kal_int8 j2me_mms_result = 0;
static kal_bool j2me_mms_registering = KAL_FALSE;
static kal_bool j2me_mms_init_appid = KAL_FALSE;
static kal_bool j2me_mms_init_appid_incoming = KAL_FALSE;
static kal_bool j2me_mms_in_progress = KAL_FALSE;
static kal_uint8 j2me_mms_register_type = WMA_REGISTRY;
//kal_char j2me_mms_mmsc_addr[J2ME_MMS_MMSC_ADDR_LEN];

static J2me_mms_recv_struct j2me_mms_recv_data = {0, 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL};
static J2me_mms_recv_part_struct j2me_mms_recv_part_data = {0, 0, NULL, 0, NULL, 0, NULL, 0, NULL, 0};
static J2me_mms_registered_appid_struct j2me_mms_appid[J2ME_MMS_REGISTER_APPID_NUM];
static J2me_mms_registered_appid_struct j2me_mms_temp_appid = {0, 0, NULL};
static J2me_mms_registered_appid_struct j2me_mms_temp_appid_for_incoming = {0, 0, NULL};
static J2me_mms_registered_appid_struct j2me_mms_temp_appid_for_recv = {0, 0, NULL};
static J2me_mms_registered_appid_struct j2me_mms_appid_Incoming[J2ME_MMS_REGISTER_APPID_NUM];
static J2me_mms_registered_appid_struct j2me_mms_appid_Incoming2[J2ME_MMS_REGISTER_APPID_NUM];
kal_bool glb_onlynew = KAL_FALSE;
kal_bool j2me_mms_is_more_msg = KAL_FALSE;
kal_bool j2me_mms_is_more_msg_part = KAL_FALSE;
/* static J2me_mms_local_address_struct j2me_mms_local_address = {0,NULL}; */

kal_bool flag_wait_async_mms_msgid;
kal_uint32 J2ME_async_mms_msgid;
extern kal_eventgrpid g_java_event_group_1;

unsigned long readMmsAsyncEvent(void);

static void (*jwa_mms_call_back)(int , int , int );

void J2ME_mms_register(char *application_id, int op, int type, int vm_id);
int jwa_mms_get_state(void);
void jwa_mms_set_state(int);

static kal_bool jwa_mms_mvm_init_result = KAL_FALSE;
static int jwa_mms_state = (int) JWA_MMS_STATE_IDLE;
static jwa_mms_pending_operation_struct j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM];
static kal_int32 j2me_mms_processing_task_vm_id = -1;
static kal_int32 jwa_mms_register_appid_serial_number = 1;

#if (MAX_VM_INSTANCE_NUM > 1)
/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_mvm_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_mvm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(g_jam_async_mms_mvm_mutex);
	if (!jwa_mms_mvm_init_result)
	{
		for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
	    {
			j2me_mms_mvm_pending_task[i].mms_req_ptr = NULL;
			j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
			j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_IDLE;
			j2me_mms_mvm_pending_task[i].vm_id = -1;
	    }
		jwa_mms_mvm_init_result = KAL_TRUE;
	}
	kal_give_mutex(g_jam_async_mms_mvm_mutex);
}

/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_mvm_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_mvm_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(g_jam_async_mms_mvm_mutex);
	if (jwa_mms_mvm_init_result)
	{
		for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
	    {
	        if (j2me_mms_mvm_pending_task[i].mms_req_ptr)
		    {
		        free_local_para((local_para_struct*)j2me_mms_mvm_pending_task[i].mms_req_ptr);
		    }
			if (j2me_mms_mvm_pending_task[i].mms_req_buff)
			{
				free_peer_buff((peer_buff_struct*)j2me_mms_mvm_pending_task[i].mms_req_buff);
			}
			j2me_mms_mvm_pending_task[i].mms_req_ptr = NULL;
			j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
			j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_IDLE;
			j2me_mms_mvm_pending_task[i].vm_id = -1;
	    }
		jwa_mms_mvm_init_result = KAL_FALSE;
	}
	kal_give_mutex(g_jam_async_mms_mvm_mutex);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_register_callback
 * DESCRIPTION
 * register the callback function for MMS response. The first parameter of the call back function
 * is the message id getting from jwa_mms_get_response_primitive, such as MSG_ID_WAP_MMC_SEND_APPMMS_RSP,
 * and the second parameter is channel id for channel ralitive messages, conneciton id (or request
 * id) for MMS write and read relative messages, or a dummy number for other messages.
 *  
 * PARAMETERS
 *  callback_ptr [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
void jwa_mms_register_callback(void (*callback_ptr)(int , int , int ))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    jwa_mms_call_back = callback_ptr;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_deregister_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jwa_mms_deregister_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    jwa_mms_call_back = NULL;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_callback_handler
 * DESCRIPTION
 *  connect_id [IN]    connection ID
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void jwa_mms_callback_handler(int result, J2me_mms_reply_enum eventMsg, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (jwa_mms_call_back != NULL)
    {
        (*jwa_mms_call_back)(result, eventMsg, vm_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_WAP:
            sap_id = J2ME_WAP_SAP;
            break;
        default:
            sap_id = J2ME_WAP_SAP;
            break;
    }   /* switch (dst_id) */

    msg_send6(MOD_JASYN_D, dst_id, sap_id, ilm_id, local_para_ptr, peer_buff_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_send_fake_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_send_fake_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send6(MOD_J2ME_D, MOD_JASYN, J2ME_WAP_SAP, ilm_id, local_para_ptr, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_delete_appid_by_resource_manger
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_int32
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 J2ME_mms_delete_appid_by_resource_manger(kal_int32 serial_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
    {
        if (j2me_mms_appid[i].serial_number == serial_number)
        {
            J2ME_mms_register((char*)j2me_mms_appid[i].app_id, 1, WMA_REGISTRY, -1);       /* 1 for remove */
				
            j2me_mms_appid[i].app_id_len = 0;
            jvm_free(j2me_mms_appid[i].app_id);
            j2me_mms_appid[i].app_id = NULL;
            j2me_mms_appid[i].serial_number = 0;
            for (j = i; j < J2ME_MMS_REGISTER_APPID_NUM - 1; j++)
            {
                j2me_mms_appid[j].app_id_len = j2me_mms_appid[j + 1].app_id_len;
                j2me_mms_appid[j].app_id = j2me_mms_appid[j + 1].app_id;
                j2me_mms_appid[j].serial_number = j2me_mms_appid[j + 1].serial_number;
                if (j2me_mms_appid[j + 1].app_id == NULL)
                {
                    break;
                }
            }
            j2me_mms_appid[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id_len = 0;
            j2me_mms_appid[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id = NULL;
            j2me_mms_appid[J2ME_MMS_REGISTER_APPID_NUM - 1].serial_number = 0;
            break;
        }
    }
    
    return RESOUCE_NO_ERROR;    
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_add_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_add_appid(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!j2me_mms_init_appid)
    {
        for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
        {
            j2me_mms_appid[i].app_id = NULL;
            j2me_mms_appid[i].app_id_len = 0;
            j2me_mms_appid[i].serial_number = 0;
        }
        j2me_mms_init_appid = KAL_TRUE;
    }

    for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
    {
        if (j2me_mms_appid[i].app_id_len == 0)
        {
            break;
        }
		if(strncmp((char*)j2me_mms_appid[i].app_id, (char*)j2me_mms_temp_appid.app_id,
                 j2me_mms_temp_appid.app_id_len) == 0)
        {
            return;
        }
    }

    if (i >= J2ME_MMS_REGISTER_APPID_NUM)
    {
        j2me_mms_result = -1;
        return;
    }

    j2me_mms_appid[i].app_id_len = j2me_mms_temp_appid.app_id_len;

    j2me_mms_appid[i].app_id = (kal_uint8*) jvm_malloc(j2me_mms_temp_appid.app_id_len + 1);
    memcpy(j2me_mms_appid[i].app_id, j2me_mms_temp_appid.app_id, j2me_mms_temp_appid.app_id_len);
    j2me_mms_appid[i].app_id[j2me_mms_temp_appid.app_id_len] = 0;

    j2me_mms_appid[i].serial_number = jwa_mms_register_appid_serial_number;
    jwa_mms_register_appid_serial_number++;

    jvm_resource_mgr_register(
        vm_id,
        JAVA_WMA_MMS_DEVICE,
        (int)j2me_mms_appid[i].serial_number,
        NULL,
        NULL,
        J2ME_mms_delete_appid_by_resource_manger);
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_add_appid_Incoming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_add_appid_Incoming()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!j2me_mms_init_appid_incoming)
    {
        for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
        {
            j2me_mms_appid_Incoming[i].app_id = NULL;
            j2me_mms_appid_Incoming[i].app_id_len = 0;
			j2me_mms_appid_Incoming2[i].app_id = NULL;
            j2me_mms_appid_Incoming2[i].app_id_len = 0;
        }
        j2me_mms_init_appid_incoming = KAL_TRUE;
    }
	if(glb_onlynew)
	{
	   for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
       {
           if (j2me_mms_appid_Incoming[i].app_id_len == 0)
           {
              break;
           }
		   /*if the add appid has already exist ,no need to add it again*/
		   if(strncmp((char*)j2me_mms_appid_Incoming[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
                 j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
	       {
	          return;
	       }
         
       }

       if (i >= J2ME_MMS_REGISTER_APPID_NUM)
       {
          j2me_mms_result = -1;
          return;
       }

       j2me_mms_appid_Incoming[i].app_id_len = j2me_mms_temp_appid_for_incoming.app_id_len;

       j2me_mms_appid_Incoming[i].app_id = (kal_uint8*) jvm_malloc(j2me_mms_temp_appid_for_incoming.app_id_len + 1);
       memcpy(j2me_mms_appid_Incoming[i].app_id, j2me_mms_temp_appid_for_incoming.app_id, j2me_mms_temp_appid_for_incoming.app_id_len);
       j2me_mms_appid_Incoming[i].app_id[j2me_mms_temp_appid_for_incoming.app_id_len] = 0;
    }
	else
	{
       /*kal_prompt_trace(MOD_J2ME,"<VM>--->ADD in false");*/
	   for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
       {
           if (j2me_mms_appid_Incoming2[i].app_id_len == 0)
           {
              break;
           }
		   /*if the add appid has already exist ,no need to add it again*/
		   if(strncmp((char*)j2me_mms_appid_Incoming2[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
                 j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
	       {
	          return;
	       }
         
       }

       if (i >= J2ME_MMS_REGISTER_APPID_NUM)
       {
          j2me_mms_result = -1;
          return;
       }

       j2me_mms_appid_Incoming2[i].app_id_len = j2me_mms_temp_appid_for_incoming.app_id_len;

       j2me_mms_appid_Incoming2[i].app_id = (kal_uint8*) jvm_malloc(j2me_mms_temp_appid_for_incoming.app_id_len + 1);
       memcpy(j2me_mms_appid_Incoming2[i].app_id, j2me_mms_temp_appid_for_incoming.app_id, j2me_mms_temp_appid_for_incoming.app_id_len);
       j2me_mms_appid_Incoming2[i].app_id[j2me_mms_temp_appid_for_incoming.app_id_len] = 0;
	}

}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_delete_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_delete_appid(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
    {
        if (j2me_mms_appid[i].app_id_len == j2me_mms_temp_appid.app_id_len)
        {
            if (strncmp
                ((char*)j2me_mms_appid[i].app_id, (char*)j2me_mms_temp_appid.app_id,
                 j2me_mms_temp_appid.app_id_len) == 0)
            {
                jvm_resource_mgr_deregister(vm_id, JAVA_WMA_MMS_DEVICE, j2me_mms_appid[i].serial_number);
				
                j2me_mms_appid[i].app_id_len = 0;
                jvm_free(j2me_mms_appid[i].app_id);
                j2me_mms_appid[i].app_id = NULL;
				j2me_mms_appid[i].serial_number = 0;
				for (j = i; j < J2ME_MMS_REGISTER_APPID_NUM - 1; j++)
		        {
		            j2me_mms_appid[j].app_id_len = j2me_mms_appid[j + 1].app_id_len;
			        j2me_mms_appid[j].app_id = j2me_mms_appid[j + 1].app_id;
					j2me_mms_appid[j].serial_number = j2me_mms_appid[j + 1].serial_number;
			        if (j2me_mms_appid[j + 1].app_id == NULL)
			        {
			            break;
			        }
		        }
				j2me_mms_appid[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id_len = 0;
				j2me_mms_appid[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id = NULL;
				j2me_mms_appid[J2ME_MMS_REGISTER_APPID_NUM - 1].serial_number = 0;
                break;
            }
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_delete_appid_Incoming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_delete_appid_Incoming()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
	{
        if (j2me_mms_appid_Incoming[i].app_id_len == j2me_mms_temp_appid_for_incoming.app_id_len)
        {
            if (strncmp
                ((char*)j2me_mms_appid_Incoming[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
                j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
            {
                j2me_mms_appid_Incoming[i].app_id_len = 0;
                jvm_free(j2me_mms_appid_Incoming[i].app_id);
                j2me_mms_appid_Incoming[i].app_id = NULL;
		        for (j = i; j < J2ME_MMS_REGISTER_APPID_NUM - 1; j++)
		        {
		            j2me_mms_appid_Incoming[j].app_id_len = j2me_mms_appid_Incoming[j + 1].app_id_len;
			        j2me_mms_appid_Incoming[j].app_id = j2me_mms_appid_Incoming[j + 1].app_id;
			        if (j2me_mms_appid_Incoming[j + 1].app_id == NULL)
			        {
			            break;
			        }
		        }
				j2me_mms_appid_Incoming[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id_len = 0;
				j2me_mms_appid_Incoming[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id = NULL;
		        break;
            }
        }/*if*/
    }
	
    for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
    {
		if (j2me_mms_appid_Incoming2[i].app_id_len == j2me_mms_temp_appid_for_incoming.app_id_len)
        {
            if (strncmp
               ((char*)j2me_mms_appid_Incoming2[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
                j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
            {
                j2me_mms_appid_Incoming2[i].app_id_len = 0;
                jvm_free(j2me_mms_appid_Incoming2[i].app_id);
                j2me_mms_appid_Incoming2[i].app_id = NULL;
		        for (j = i; j < J2ME_MMS_REGISTER_APPID_NUM - 1; j++)
	            {
		            j2me_mms_appid_Incoming2[j].app_id_len = j2me_mms_appid_Incoming2[j + 1].app_id_len;
		            j2me_mms_appid_Incoming2[j].app_id = j2me_mms_appid_Incoming2[j + 1].app_id;
		            if (j2me_mms_appid_Incoming2[j + 1].app_id == NULL)
	   	            {
			            break;
			        }
		        }
				j2me_mms_appid_Incoming2[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id_len = 0;
				j2me_mms_appid_Incoming2[J2ME_MMS_REGISTER_APPID_NUM - 1].app_id = NULL;
                break;
            }
        }/*if*/
    }/*for*/
    return;
}



/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_reset_temp_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_reset_temp_appid()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    j2me_mms_temp_appid.app_id_len = 0;

    if (j2me_mms_temp_appid.app_id != NULL)
    {
        jvm_free(j2me_mms_temp_appid.app_id);
        j2me_mms_temp_appid.app_id = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_reset_temp_appid_for_incoming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_reset_temp_appid_for_incoming()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    j2me_mms_temp_appid_for_incoming.app_id_len = 0;

    if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
    {
        jvm_free(j2me_mms_temp_appid_for_incoming.app_id);
        j2me_mms_temp_appid_for_incoming.app_id = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_reset_temp_appid_for_recv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_reset_temp_appid_for_recv()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    j2me_mms_temp_appid_for_recv.app_id_len = 0;

    if (j2me_mms_temp_appid_for_recv.app_id != NULL)
    {
        jvm_free(j2me_mms_temp_appid_for_recv.app_id);
        j2me_mms_temp_appid_for_recv.app_id = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_reset_recv_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_reset_recv_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (j2me_mms_recv_data.start_cnt_id != NULL)
    {
        jvm_free(j2me_mms_recv_data.start_cnt_id);
        j2me_mms_recv_data.start_cnt_id = NULL;
    }

    if (j2me_mms_recv_data.reply_app_id != NULL)
    {
        jvm_free(j2me_mms_recv_data.reply_app_id);
        j2me_mms_recv_data.reply_app_id = NULL;
    }

    if (j2me_mms_recv_data.peer_buffer != NULL)
    {
        jvm_free(j2me_mms_recv_data.peer_buffer);
        j2me_mms_recv_data.peer_buffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_reset_recv_part_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void J2ME_mms_reset_recv_part_data(kal_bool filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (j2me_mms_recv_part_data.content_type != NULL)
    {
        jvm_free(j2me_mms_recv_part_data.content_type);
        j2me_mms_recv_part_data.content_type = NULL;
    }

    if (j2me_mms_recv_part_data.content_id != NULL)
    {
        jvm_free(j2me_mms_recv_part_data.content_id);
        j2me_mms_recv_part_data.content_id = NULL;
    }

    if (j2me_mms_recv_part_data.content_location != NULL)
    {
        jvm_free(j2me_mms_recv_part_data.content_location);
        j2me_mms_recv_part_data.content_location = NULL;
    }

    if (filepath && j2me_mms_recv_part_data.filepath != NULL)
    {
        jvm_free(j2me_mms_recv_part_data.filepath);
        j2me_mms_recv_part_data.filepath = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_get_message_sent_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint64 J2ME_mms_get_message_sent_time()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint64) j2me_mms_recv_data.date;
}


#if (MAX_VM_INSTANCE_NUM > 1)
/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_process_pending_task
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_process_pending_task()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
	kal_int32 vm_id = -1;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_INFO, WMA_MMS_PROCESS_PENDING_TASK, jam_mvm_get_current_vm_id(),
	          j2me_mms_mvm_pending_task[0].vm_id, j2me_mms_mvm_pending_task[0].pending_operation);
    
	if (jam_mvm_get_current_vm_id() != -1 && j2me_mms_mvm_pending_task[0].vm_id != -1)
	{
	    vm_id = j2me_mms_mvm_pending_task[0].vm_id;
		
		if (j2me_mms_mvm_pending_task[0].pending_operation == JWA_MMS_STATE_REGISTER_APPID)
		{ 
		    wap_mmc_cfg_appmms_appid_rsp_struct *fake_rsp;
		    wap_mmc_cfg_appmms_appid_req_struct *p = (wap_mmc_cfg_appmms_appid_req_struct*) (j2me_mms_mvm_pending_task[0].mms_req_ptr);
            int ret;

		    for (i = 0; i < MAX_VM_INSTANCE_NUM - 1; i++)
		    {
		        j2me_mms_mvm_pending_task[i].mms_req_ptr = j2me_mms_mvm_pending_task[i + 1].mms_req_ptr;
				j2me_mms_mvm_pending_task[i].mms_req_buff = j2me_mms_mvm_pending_task[i + 1].mms_req_buff;
		        j2me_mms_mvm_pending_task[i].pending_operation = j2me_mms_mvm_pending_task[i + 1].pending_operation;
		        j2me_mms_mvm_pending_task[i].vm_id = j2me_mms_mvm_pending_task[i + 1].vm_id;
		        if (j2me_mms_mvm_pending_task[i + 1].vm_id == -1)
		        {
		            break;
		        }
		    }
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_ptr = NULL;
			j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_buff = NULL;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_MMS_STATE_IDLE;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;

            if (srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
#endif
                )
		    {
		        ret = jpush_push_checkappid((kal_char*)p->app_id, WMA_REGISTRY, vm_id);
				
				if ( ret == NON_REGISTERED )
			    {
			        if (p->op == 0)
			        {
			            j2me_mms_registering = KAL_TRUE;
			        }
					else
					{
					    J2ME_mms_reset_temp_appid_for_incoming();
			            j2me_mms_temp_appid_for_incoming.app_id_len = p->app_id_len;
			            j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);
			            if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
			            {
			                memcpy(j2me_mms_temp_appid_for_incoming.app_id, p->app_id, p->app_id_len);
			                j2me_mms_temp_appid_for_incoming.app_id[p->app_id_len] = '\0';
							J2ME_mms_delete_appid_Incoming();
			            }
						J2ME_mms_reset_temp_appid_for_incoming();
					}

		            J2ME_mms_reset_temp_appid();
		            j2me_mms_temp_appid.app_id_len = p->app_id_len;
		            j2me_mms_temp_appid.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);

		            if (j2me_mms_temp_appid.app_id != NULL)
		            {
		                memcpy(j2me_mms_temp_appid.app_id, p->app_id, p->app_id_len);
		                j2me_mms_temp_appid.app_id[p->app_id_len] = '\0';
		            }
					
				    j2me_mms_register_type = WMA_REGISTRY;
				
				    j2me_mms_processing_task_vm_id = vm_id;
				    jwa_mms_set_state(JWA_MMS_STATE_REGISTER_APPID);

			        J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ, mms_get_service_module(MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ));
					return;
			    }
		    }

	        /* construct the fake request and response */
	        if (p->op == 1)
	        {
	            J2ME_mms_reset_temp_appid_for_incoming();
	            j2me_mms_temp_appid_for_incoming.app_id_len = p->app_id_len;
	            j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);
	            if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
	            {
	                memcpy(j2me_mms_temp_appid_for_incoming.app_id, p->app_id, p->app_id_len);
	                j2me_mms_temp_appid_for_incoming.app_id[p->app_id_len] = '\0';
					J2ME_mms_delete_appid_Incoming();
	            }
				J2ME_mms_reset_temp_appid_for_incoming();
	        }

			free_local_para((local_para_struct*) p);

            fake_rsp = (wap_mmc_cfg_appmms_appid_rsp_struct*) construct_local_para(
                                                sizeof(wap_mmc_cfg_appmms_appid_rsp_struct),
                                                TD_CTRL);
	        fake_rsp->result = 0;
            fake_rsp->vm_id = vm_id;

		    j2me_mms_processing_task_vm_id = vm_id;
		    jwa_mms_set_state(JWA_MMS_STATE_REGISTER_APPID);

			j2me_mms_register_type = WMA_REGISTRY;
	        j2me_mms_temp_appid.app_id_len = 0;

	        J2ME_mms_send_fake_ilm(fake_rsp, NULL, MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP);
		}
		else if (j2me_mms_mvm_pending_task[0].pending_operation == JWA_MMS_STATE_CHECK_INCOMING_MSG)
		{
		    wap_mmc_check_appmms_coming_rsp_struct *fake_rsp;
		    wap_mmc_check_appmms_coming_req_struct *p = (wap_mmc_check_appmms_coming_req_struct*) (j2me_mms_mvm_pending_task[0].mms_req_ptr);
		    kal_bool checked = KAL_FALSE;

		    for (i = 0; i < MAX_VM_INSTANCE_NUM - 1; i++)
		    {
		        j2me_mms_mvm_pending_task[i].mms_req_ptr = j2me_mms_mvm_pending_task[i + 1].mms_req_ptr;
				j2me_mms_mvm_pending_task[i].mms_req_buff = j2me_mms_mvm_pending_task[i + 1].mms_req_buff;
		        j2me_mms_mvm_pending_task[i].pending_operation = j2me_mms_mvm_pending_task[i + 1].pending_operation;
		        j2me_mms_mvm_pending_task[i].vm_id = j2me_mms_mvm_pending_task[i + 1].vm_id;
		        if (j2me_mms_mvm_pending_task[i + 1].vm_id == -1)
		        {
		            break;
		        }
		    }
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_ptr = NULL;
			j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_buff = NULL;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_MMS_STATE_IDLE;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;

            if (srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
#endif
                )
		    {
		    	glb_onlynew = p->only_new;
			
				J2ME_mms_reset_temp_appid_for_incoming();
		        j2me_mms_temp_appid_for_incoming.app_id_len = p->app_id_len;
		        j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);
		        if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
		        {
		            memcpy(j2me_mms_temp_appid_for_incoming.app_id, p->app_id, p->app_id_len);
		            j2me_mms_temp_appid_for_incoming.app_id[p->app_id_len] = '\0';
		        }
					
		        if(glb_onlynew)
				{
				   for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
		           {
		               if (j2me_mms_appid_Incoming[i].app_id_len == j2me_mms_temp_appid_for_incoming.app_id_len)
		               {
		                   if (strncmp
		                       ((char*)j2me_mms_appid_Incoming[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
		                        j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
		                   {
		                       checked = KAL_TRUE;  /*It means no incoming message on the checked application id*/
		                       break;
		                   }
		               }/*if*/
		            }/*for*/
		        }
				else
			    {
					for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
				    {
					    if (j2me_mms_appid_Incoming2[i].app_id_len == j2me_mms_temp_appid_for_incoming.app_id_len)
					    {
					        if (strncmp((char*)j2me_mms_appid_Incoming2[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
							    j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
						    {
						         checked = KAL_TRUE;  /*It means no incoming message on the checked application id*/
						         break;
						    }
					    }/*if*/
				    }/*for*/

				}

				j2me_mms_processing_task_vm_id = vm_id;
				jwa_mms_set_state(JWA_MMS_STATE_CHECK_INCOMING_MSG);

				if(!checked)
			    {
		            J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ, mms_get_service_module(MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ));
					return;
		        }
			}

			/*Free the locol para*/
		    free_local_para((local_para_struct*) p);

			fake_rsp = (wap_mmc_check_appmms_coming_rsp_struct*)
                                          construct_local_para(sizeof(wap_mmc_check_appmms_coming_rsp_struct), TD_CTRL);
		   
		    /* construct the fake request and response */
            fake_rsp->result = 0;

			J2ME_mms_reset_temp_appid_for_incoming();
	        j2me_mms_temp_appid_for_incoming.app_id_len = p->app_id_len;
	        j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);
	        if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
	        {
	            memcpy(j2me_mms_temp_appid_for_incoming.app_id, p->app_id, p->app_id_len);
	            j2me_mms_temp_appid_for_incoming.app_id[p->app_id_len] = '\0';
	        }
			
			j2me_mms_processing_task_vm_id = vm_id;
			jwa_mms_set_state(JWA_MMS_STATE_CHECK_INCOMING_MSG);

			J2ME_mms_send_fake_ilm(fake_rsp, NULL, MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP);
		}
		else if (j2me_mms_mvm_pending_task[0].pending_operation == JWA_MMS_STATE_SEND)
		{
		    wap_mmc_send_appmms_rsp_struct *fake_rsp;
			wap_mmc_send_appmms_req_struct *p = (wap_mmc_send_appmms_req_struct*) (j2me_mms_mvm_pending_task[0].mms_req_ptr);
    		peer_buff_struct *peer_buff_ptr = (peer_buff_struct*) (j2me_mms_mvm_pending_task[0].mms_req_buff);

			for (i = 0; i < MAX_VM_INSTANCE_NUM - 1; i++)
		    {
		        j2me_mms_mvm_pending_task[i].mms_req_ptr = j2me_mms_mvm_pending_task[i + 1].mms_req_ptr;
				j2me_mms_mvm_pending_task[i].mms_req_buff = j2me_mms_mvm_pending_task[i + 1].mms_req_buff;
		        j2me_mms_mvm_pending_task[i].pending_operation = j2me_mms_mvm_pending_task[i + 1].pending_operation;
		        j2me_mms_mvm_pending_task[i].vm_id = j2me_mms_mvm_pending_task[i + 1].vm_id;
		        if (j2me_mms_mvm_pending_task[i + 1].vm_id == -1)
		        {
		            break;
		        }
		    }
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_ptr = NULL;
			j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_buff = NULL;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_MMS_STATE_IDLE;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;

           if (srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
               || srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
               || srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
               || srv_sim_ctrl_is_available(MMI_SIM4)
#endif
               )
		    {
				j2me_mms_processing_task_vm_id = vm_id;
				jwa_mms_set_state(JWA_MMS_STATE_SEND);
				
		        j2me_mms_in_progress = KAL_TRUE;
		    
		    	J2ME_mms_send_ilm(p, peer_buff_ptr, MSG_ID_WAP_MMC_SEND_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_SEND_APPMMS_REQ));
				return;
			}

			free_local_para((local_para_struct*) p);
			free_peer_buff((peer_buff_struct*) peer_buff_ptr);

			fake_rsp = (wap_mmc_send_appmms_rsp_struct*)
                                          construct_local_para(sizeof(wap_mmc_send_appmms_rsp_struct), TD_CTRL);
			/* construct the fake request and response */
			fake_rsp->result = MMC_RESULT_ERROR;

			j2me_mms_processing_task_vm_id = vm_id;
			jwa_mms_set_state(JWA_MMS_STATE_SEND);
				
		    j2me_mms_in_progress = KAL_TRUE;
			
			J2ME_mms_send_fake_ilm(fake_rsp, NULL, MSG_ID_WAP_MMC_SEND_APPMMS_RSP);
		}
		else if (j2me_mms_mvm_pending_task[0].pending_operation == JWA_MMS_STATE_GET_INCOMING_MSG)
		{
		    wap_mmc_recv_appmms_rsp_struct *fake_rsp;
			wap_mmc_recv_appmms_req_struct *p = (wap_mmc_recv_appmms_req_struct*) (j2me_mms_mvm_pending_task[0].mms_req_ptr);

			for (i = 0; i < MAX_VM_INSTANCE_NUM - 1; i++)
		    {
		        j2me_mms_mvm_pending_task[i].mms_req_ptr = j2me_mms_mvm_pending_task[i + 1].mms_req_ptr;
				j2me_mms_mvm_pending_task[i].mms_req_buff = j2me_mms_mvm_pending_task[i + 1].mms_req_buff;
		        j2me_mms_mvm_pending_task[i].pending_operation = j2me_mms_mvm_pending_task[i + 1].pending_operation;
		        j2me_mms_mvm_pending_task[i].vm_id = j2me_mms_mvm_pending_task[i + 1].vm_id;
		        if (j2me_mms_mvm_pending_task[i + 1].vm_id == -1)
		        {
		            break;
		        }
		    }
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_ptr = NULL;
			j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_buff = NULL;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_MMS_STATE_IDLE;
		    j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;

            if (srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
#endif
                )
		    {
		    	J2ME_mms_reset_temp_appid_for_recv();
			    j2me_mms_temp_appid_for_recv.app_id_len = p->app_id_len;
			    j2me_mms_temp_appid_for_recv.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);
			    if (j2me_mms_temp_appid_for_recv.app_id != NULL)
			    {
			        memcpy(j2me_mms_temp_appid_for_recv.app_id, p->app_id, p->app_id_len);
			        j2me_mms_temp_appid_for_recv.app_id[p->app_id_len] = '\0';
			    }

				j2me_mms_processing_task_vm_id = vm_id;
				jwa_mms_set_state(JWA_MMS_STATE_GET_INCOMING_MSG);

			    j2me_mms_in_progress = KAL_TRUE;
			    J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_RECV_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_RECV_APPMMS_REQ));
				return;
			}

			free_local_para((local_para_struct*) p);

			fake_rsp = (wap_mmc_recv_appmms_rsp_struct*)
                                          construct_local_para(sizeof(wap_mmc_recv_appmms_rsp_struct), TD_CTRL);
			/* construct the fake request and response */
			fake_rsp->result = MMC_RESULT_ERROR;

			j2me_mms_processing_task_vm_id = vm_id;
			jwa_mms_set_state(JWA_MMS_STATE_GET_INCOMING_MSG);

			j2me_mms_in_progress = KAL_TRUE;
			
			J2ME_mms_send_fake_ilm(p, NULL, MSG_ID_WAP_MMC_RECV_APPMMS_RSP);
		}
	}
	else
	{
	    j2me_mms_processing_task_vm_id = -1;
	    jwa_mms_set_state(JWA_MMS_STATE_IDLE);	
	}
}
#endif


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_process_pending_task_by_controller
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_process_pending_task_by_controller()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM > 1)
    kal_trace(TRACE_INFO, WMA_MMS_PROCESS_PENDING_TASK_BY_CONTROLLER, j2me_mms_processing_task_vm_id, jwa_sms_get_state());
    
	kal_take_mutex(g_jam_async_mms_mvm_mutex);
	if (j2me_mms_processing_task_vm_id == -1 && jwa_mms_get_state() == JWA_MMS_STATE_IDLE)
	{
	    J2ME_mms_process_pending_task();
	}
	kal_give_mutex(g_jam_async_mms_mvm_mutex);
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_save_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_save_result(mmc_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMC_RESULT_OK)
    {
        j2me_mms_result = 0;
    }
    else
    {
        j2me_mms_result = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  readMmsAsyncEvent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long readMmsAsyncEvent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group, ret_msgid;
    kal_status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag_wait_async_mms_msgid = KAL_TRUE;

    result = kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_MMS_NOTIFY_RETREIVE, KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);

    if (result == KAL_NOT_PRESENT)
    {
        return (-2);    /* IO_WOULDBLOCK */
    }
    else
    {
        ret_msgid = J2ME_async_mms_msgid;
        J2ME_async_mms_msgid = 0;
        flag_wait_async_mms_msgid = KAL_FALSE;

        /* 2nd bit notify complete retreive async event */
        kal_set_eg_events(g_java_event_group_1, JAVA_EG_MMS_COMPLETE_RETREIVE, KAL_OR);

        return ret_msgid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_response_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_response_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (J2ME_async_mms_msgid && flag_wait_async_mms_msgid)
    {
        /* Pedning async event */
        kal_uint32 event_group, polling = 0;
        kal_status result;

        while (1)
        {
            /* 2nd bit indicate wait pending async event consumed */
            result = kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_MMS_COMPLETE_RETREIVE, KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);

            if (result != KAL_NOT_PRESENT || polling++ >= 100)
            {
                break;
            }
            /* To avoid deadlock and complicated timer control, use polling */
            kal_sleep_task(1);
        }
    }

    J2ME_async_mms_msgid = ilm_ptr->msg_id;

    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_WAP_MMC_SEND_APPMMS_RSP:
        {
            wap_mmc_send_appmms_rsp_struct *p = (wap_mmc_send_appmms_rsp_struct*) ilm_ptr->local_para_ptr;

            J2ME_mms_save_result(p->result);
            
            j2me_mms_in_progress = KAL_FALSE;            
        }
            break;

        case MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND:
        {
            wap_mmc_post_appmms_msg_part_ind_struct *p =
                (wap_mmc_post_appmms_msg_part_ind_struct*) ilm_ptr->local_para_ptr;

            J2ME_mms_save_result(p->result);
        }
            break;

        case MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP:
        {
            wap_mmc_cfg_appmms_appid_rsp_struct *p = (wap_mmc_cfg_appmms_appid_rsp_struct*) ilm_ptr->local_para_ptr;

			if (p->vm_id == -1)
			{
			    J2ME_async_mms_msgid = 0;
				return;
			}

            J2ME_mms_save_result(p->result);

            if (p->result == MMC_RESULT_OK && j2me_mms_temp_appid.app_id_len != 0)
            {
                if (j2me_mms_register_type == WMA_REGISTRY)
                {
                    if (j2me_mms_registering)
                    {
                        J2ME_mms_add_appid(p->vm_id);
                    }
                    else
                    {
                        J2ME_mms_delete_appid(p->vm_id);
                    }
                }
            }
            j2me_mms_registering = KAL_FALSE;
			
			if (j2me_mms_register_type == WMA_REGISTRY)
			{
			    J2ME_mms_reset_temp_appid();
			}

            if (j2me_mms_register_type == PUSH_REGISTRY)
            {
                J2ME_async_mms_msgid = 0;
            }
        }
            break;

        case MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP:
        {
            wap_mmc_check_appmms_coming_rsp_struct *p =
                (wap_mmc_check_appmms_coming_rsp_struct*) ilm_ptr->local_para_ptr;

            if (p->result)
            {
                j2me_mms_result = 1;
            }
            else
            {
                j2me_mms_result = 0;
		        J2ME_mms_add_appid_Incoming();
            }
			J2ME_mms_reset_temp_appid_for_incoming();
        }
            break;

        case MSG_ID_WAP_MMC_RECV_APPMMS_RSP:
        {
            kal_uint16 len;
            wap_mmc_recv_appmms_rsp_struct *p = (wap_mmc_recv_appmms_rsp_struct*) ilm_ptr->local_para_ptr;
            kal_uint8 *pdu_ptr = NULL;

            J2ME_mms_reset_recv_data();
            J2ME_mms_save_result(p->result);

            if (p->result == MMC_RESULT_OK)
            {
                pdu_ptr = get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len);
                
                /* j2me_mms_recv_data.transId = p->transId; */
                j2me_mms_recv_data.priority = p->priority;
                j2me_mms_recv_data.from_addr_no = p->from_addr_no;
                j2me_mms_recv_data.to_addr_no = p->to_addr_no;
                j2me_mms_recv_data.cc_addr_no = p->cc_addr_no;
                j2me_mms_recv_data.bdy_part_no = p->bdy_part_no;
                j2me_mms_recv_data.date = (kal_uint64) p->date;
                j2me_mms_recv_data.start_cnt_id_len = p->start_cnt_id_len;
                j2me_mms_recv_data.reply_app_id_len = p->reply_app_id_len;
                j2me_mms_recv_data.peer_buffer_len = len;

                if (p->bdy_part_no == 0)
                {
                    if (p->is_more_msg == KAL_FALSE)
                    {
                        jpush_push_set_unavailable_by_connection((char *)j2me_mms_temp_appid_for_recv.app_id);
                    }
                    J2ME_mms_reset_temp_appid_for_recv();
                    j2me_mms_in_progress = KAL_FALSE;
                }
		        else
		        {
		            j2me_mms_is_more_msg = p->is_more_msg;
		        }

                if (j2me_mms_recv_data.start_cnt_id_len > 0)
                {
                    j2me_mms_recv_data.start_cnt_id = (kal_uint8*) jvm_malloc(p->start_cnt_id_len);
                    if (j2me_mms_recv_data.start_cnt_id == NULL)
                    {
                        J2ME_mms_save_result(MMC_RESULT_INSUFFICIENT_MEMORY);
                        break;
                    }
                    memcpy(j2me_mms_recv_data.start_cnt_id, p->start_cnt_id, p->start_cnt_id_len);
                }

                if (j2me_mms_recv_data.reply_app_id_len > 0)
                {
                    j2me_mms_recv_data.reply_app_id = (kal_uint8*) jvm_malloc(p->reply_app_id_len);
                    if (j2me_mms_recv_data.reply_app_id == NULL)
                    {
                        J2ME_mms_save_result(MMC_RESULT_INSUFFICIENT_MEMORY);
                        break;
                    }
                    memcpy(j2me_mms_recv_data.reply_app_id, p->reply_app_id, p->reply_app_id_len);
                }

                if (pdu_ptr != NULL && len > 0)
                {
                    j2me_mms_recv_data.peer_buffer = (kal_uint8*) jvm_malloc(len);
                    if (j2me_mms_recv_data.peer_buffer == NULL)
                    {
                        J2ME_mms_save_result(MMC_RESULT_INSUFFICIENT_MEMORY);
                        break;
                    }
                    memcpy(j2me_mms_recv_data.peer_buffer, pdu_ptr, len);
                }
            }
            else
            {
                J2ME_mms_reset_temp_appid_for_recv();
                j2me_mms_in_progress = KAL_FALSE;
            }
        }
            break;

        case MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP:
        {

            wap_mmc_read_appmms_msg_part_rsp_struct *p =
                (wap_mmc_read_appmms_msg_part_rsp_struct*) ilm_ptr->local_para_ptr;

            J2ME_mms_reset_recv_part_data(KAL_TRUE);
            J2ME_mms_save_result(p->result);

            if (p->result == MMC_RESULT_OK)
            {
                j2me_mms_recv_part_data.encoding_scheme = p->encoding_scheme;
                j2me_mms_recv_part_data.content_type_len = p->content_type_len;
                j2me_mms_recv_part_data.content_id_len = p->content_id_len;
                j2me_mms_recv_part_data.content_location_len = p->content_location_len;
                j2me_mms_recv_part_data.filepath_len = p->filepath_len;

                if (j2me_mms_recv_part_data.content_type_len > 0)
                {
                    j2me_mms_recv_part_data.content_type = (kal_uint8*) jvm_malloc(p->content_type_len);
                    if (j2me_mms_recv_part_data.content_type == NULL)
                    {
                        J2ME_mms_save_result(MMC_RESULT_INSUFFICIENT_MEMORY);
                        break;
                    }
                    memcpy(j2me_mms_recv_part_data.content_type, p->content_type, p->content_type_len);
                }
                if (j2me_mms_recv_part_data.content_id_len > 0)
                {
                    j2me_mms_recv_part_data.content_id = (kal_uint8*) jvm_malloc(p->content_id_len);
                    if (j2me_mms_recv_part_data.content_id == NULL)
                    {
                        J2ME_mms_save_result(MMC_RESULT_INSUFFICIENT_MEMORY);
                        break;
                    }
                    memcpy(j2me_mms_recv_part_data.content_id, p->content_id, p->content_id_len);
                }
                if (j2me_mms_recv_part_data.content_location_len > 0)
                {
                    j2me_mms_recv_part_data.content_location = (kal_uint8*) jvm_malloc(p->content_location_len);
                    if (j2me_mms_recv_part_data.content_location == NULL)
                    {
                        J2ME_mms_save_result(MMC_RESULT_INSUFFICIENT_MEMORY);
                        break;
                    }
                    memcpy(j2me_mms_recv_part_data.content_location, p->content_location, p->content_location_len);
                }
                if (j2me_mms_recv_part_data.filepath_len > 0)
                {

                    j2me_mms_recv_part_data.filepath = (kal_wchar*) jvm_malloc((p->filepath_len + 1) * 2);
                    if (j2me_mms_recv_part_data.filepath == NULL)
                    {
                        J2ME_mms_save_result(MMC_RESULT_INSUFFICIENT_MEMORY);
                        break;
                    }
                    kal_wstrncpy(j2me_mms_recv_part_data.filepath, p->filepath, p->filepath_len);

                    /* Reset file size  */
                    j2me_mms_recv_part_data.file_size = 0;
                }
				if (j2me_mms_is_more_msg_part == KAL_FALSE)
				{
				    if (j2me_mms_is_more_msg == KAL_FALSE)
                    {
                        jpush_push_set_unavailable_by_connection((char *)j2me_mms_temp_appid_for_recv.app_id);
						j2me_mms_in_progress = KAL_FALSE;
                    }
                	J2ME_mms_reset_temp_appid_for_recv();
				}
            }
            else
            {
                J2ME_mms_reset_temp_appid_for_recv();
                j2me_mms_in_progress = KAL_FALSE;
            }
        }
            break;

        case MSG_ID_WAP_MMC_ABORT_APPMMS_RSP:
        {
            j2me_mms_in_progress = KAL_FALSE;
            jwa_mms_set_state(JWA_MMS_STATE_IDLE);
        } 
            break;
            
        default:
            break;

    }

    /* notify J2ME thread to process coming async event */
    kal_set_eg_events(g_java_event_group_1, JAVA_EG_MMS_NOTIFY_RETREIVE, KAL_OR);

    if (jwa_mms_call_back != NULL)
    {
        if (ilm_ptr->msg_id != MSG_ID_WAP_MMC_ABORT_APPMMS_RSP && jwa_mms_get_state() != JWA_MMS_STATE_ABORT)
        {
	        J2me_mms_reply_enum eventMsg = jwa_mms_get_response_primitive();
	        int result = jwa_mms_get_primitive_result();
	        jwa_mms_callback_handler(result, eventMsg, (int)j2me_mms_processing_task_vm_id);
    	}
    }

#if (MAX_VM_INSTANCE_NUM > 1)
	if (jwa_mms_get_state() != JWA_MMS_STATE_ABORT && !j2me_mms_in_progress)
	{
		kal_take_mutex(g_jam_async_mms_mvm_mutex);
		if (j2me_mms_mvm_pending_task[0].vm_id != -1)
		{
		    J2ME_mms_process_pending_task();
		}
		else
		{
		    j2me_mms_processing_task_vm_id = -1;
		    jwa_mms_set_state(JWA_MMS_STATE_IDLE);
		}
		kal_give_mutex(g_jam_async_mms_mvm_mutex);
	}
#endif

    return;
}


/*****************************************************************************
 * FUNCTION
 *  j2me_process_recvd_mms_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void *j2me_process_recvd_mms_ind(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_appmms_new_mms_ind_struct *mms_ind_ptr = (wap_mmc_appmms_new_mms_ind_struct*) ilm_ptr->local_para_ptr;
    pushentry_struct *p = NULL;
    kal_uint8 *appid = jvm_malloc(mms_ind_ptr->app_id_len + 1);
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (appid != NULL)
    {
        J2ME_mms_reset_temp_appid_for_incoming();
        j2me_mms_temp_appid_for_incoming.app_id_len = mms_ind_ptr->app_id_len;
        j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(mms_ind_ptr->app_id_len + 1);
        if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
        {
           memcpy(j2me_mms_temp_appid_for_incoming.app_id, mms_ind_ptr->app_id, mms_ind_ptr->app_id_len);
           j2me_mms_temp_appid_for_incoming.app_id[mms_ind_ptr->app_id_len] = '\0';
		   J2ME_mms_delete_appid_Incoming();
        }
		J2ME_mms_reset_temp_appid_for_incoming();
        	
        memcpy(appid, mms_ind_ptr->app_id, mms_ind_ptr->app_id_len);
        appid[mms_ind_ptr->app_id_len] = 0;
        p = push_process_recvd_mms_ind((char*)appid);
        jvm_free(appid);
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  application_id      [?]         
 *  op                  [IN]        0 for register, 1 for unregister
 *  type                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_register(char *application_id, int op, int type, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_cfg_appmms_appid_req_struct *p;
    //ilm_struct fake_register_ilm;
    wap_mmc_cfg_appmms_appid_rsp_struct *fake_register_rsp;
    char *appid = application_id;
    int appIdLen;
    int ret;
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wap_mmc_cfg_appmms_appid_req_struct*) construct_local_para(
                                                sizeof(wap_mmc_cfg_appmms_appid_req_struct),
                                                TD_CTRL);
    appIdLen = strlen(appid);

    p->op = op;
    p->app_id_len = appIdLen;

    memcpy((S8*) p->app_id, appid, appIdLen);
    p->app_id[appIdLen] = '\0';
    p->ind_module = MOD_JASYN_D;
	if (type == WMA_REGISTRY)
    {
        p->vm_id = vm_id;
    }
	else
	{
	    p->vm_id = -1;
	}
	
#if (MAX_VM_INSTANCE_NUM > 1)
	kal_take_mutex(g_jam_async_mms_mvm_mutex);

	if (vm_id != -1 && j2me_mms_processing_task_vm_id != -1 && j2me_mms_processing_task_vm_id != vm_id && type == WMA_REGISTRY)
	{	
		for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
		{
			if (j2me_mms_mvm_pending_task[i].vm_id == vm_id)
			{
				if (j2me_mms_mvm_pending_task[i].mms_req_ptr)
				{
					free_local_para((local_para_struct*)j2me_mms_mvm_pending_task[i].mms_req_ptr);
				}
				if (j2me_mms_mvm_pending_task[i].mms_req_buff)
				{
					free_peer_buff((peer_buff_struct*)j2me_mms_mvm_pending_task[i].mms_req_buff);
				}
				j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_REGISTER_APPID;
				j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
				j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
				break;
			}
			else if (j2me_mms_mvm_pending_task[i].vm_id == -1)
			{
				j2me_mms_mvm_pending_task[i].vm_id = vm_id;
				j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_REGISTER_APPID;
				j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
				j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
				break;
			}
		}
	}
	else
#endif
	{   
	    /* check push if register this application id */
	    ret = jpush_push_checkappid(application_id, type, vm_id);

	    /* no registry */
	    if ( ret == NON_REGISTERED )
	    {
	        if (op == 0)
	        {
	            if (type == WMA_REGISTRY && vm_id >= 0)
	            {
	                j2me_mms_registering = KAL_TRUE;
	            }
	        }
			else
			{
			    J2ME_mms_reset_temp_appid_for_incoming();
	            j2me_mms_temp_appid_for_incoming.app_id_len = appIdLen;
	            j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(appIdLen + 1);
	            if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
	            {
	                memcpy(j2me_mms_temp_appid_for_incoming.app_id, appid, appIdLen);
	                j2me_mms_temp_appid_for_incoming.app_id[appIdLen] = '\0';
					J2ME_mms_delete_appid_Incoming();
	            }
				J2ME_mms_reset_temp_appid_for_incoming();
			}

	        if (type == WMA_REGISTRY && vm_id >= 0)
	        {
	            J2ME_mms_reset_temp_appid();
	            j2me_mms_temp_appid.app_id_len = p->app_id_len;
	            j2me_mms_temp_appid.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);

	            if (j2me_mms_temp_appid.app_id != NULL)
	            {
	                memcpy(j2me_mms_temp_appid.app_id, p->app_id, p->app_id_len);
	                j2me_mms_temp_appid.app_id[p->app_id_len] = '\0';
	            }
			    j2me_mms_register_type = type;
			
			    j2me_mms_processing_task_vm_id = vm_id;
			    jwa_mms_set_state(JWA_MMS_STATE_REGISTER_APPID);
	        }
	        
            j2me_mms_register_type = type;

	        J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ, mms_get_service_module(MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ));
	    }
	    else
	    {
	        /* construct the fake request and response */
	        if (op == 1)
	        {
	            J2ME_mms_reset_temp_appid_for_incoming();
	            j2me_mms_temp_appid_for_incoming.app_id_len = appIdLen;
	            j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(appIdLen + 1);
	            if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
	            {
	                memcpy(j2me_mms_temp_appid_for_incoming.app_id, appid, appIdLen);
	                j2me_mms_temp_appid_for_incoming.app_id[appIdLen] = '\0';
					J2ME_mms_delete_appid_Incoming();
	            }
				J2ME_mms_reset_temp_appid_for_incoming();
	        }

			free_local_para((local_para_struct*) p);
			
		    if (type == WMA_REGISTRY && vm_id >= 0)
		    {
	            fake_register_rsp = (wap_mmc_cfg_appmms_appid_rsp_struct*) construct_local_para(
	                                                sizeof(wap_mmc_cfg_appmms_appid_rsp_struct),
	                                                TD_CTRL);
		        fake_register_rsp->result = 0;
	            fake_register_rsp->vm_id = vm_id;

			    j2me_mms_processing_task_vm_id = vm_id;
			    jwa_mms_set_state(JWA_MMS_STATE_REGISTER_APPID);
		        
		        /*fake_register_ilm.dest_mod_id = MOD_JASYN_D;
		              fake_register_ilm.src_mod_id = MOD_WAP;
		              fake_register_ilm.msg_id = MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP;
		              fake_register_ilm.sap_id = J2ME_WAP_SAP;
		              fake_register_ilm.local_para_ptr = (local_para_struct*) &fake_register_rsp;
		              fake_register_ilm.peer_buff_ptr = NULL;*/

				j2me_mms_register_type = type;
		        j2me_mms_temp_appid.app_id_len = 0;

		        //J2ME_mms_response_handler(&fake_register_ilm);
		        J2ME_mms_send_fake_ilm(fake_register_rsp, NULL, MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP);
		    }
	    }
	}

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_give_mutex(g_jam_async_mms_mvm_mutex);
#endif

    return;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_mms_register_by_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  application_id      [?]         
 *  op                  [IN]        0 for register, 1 for unregister
 *  type                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void J2ME_mms_register_by_push(char *application_id, int op, int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_cfg_appmms_appid_req_struct *p;
    ilm_struct fake_register_ilm;
    char *appid = application_id;
    int appIdLen;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* currently, it only use for deregister */
    if (type == PUSH_REGISTRY && op == 1)
    {
        p = (wap_mmc_cfg_appmms_appid_req_struct*) construct_local_para(
                                                    sizeof(wap_mmc_cfg_appmms_appid_req_struct),
                                                    TD_CTRL);
        appIdLen = strlen(appid);

        p->op = op;
        p->app_id_len = appIdLen;

        memcpy((S8*) p->app_id, appid, appIdLen);
        p->app_id[appIdLen] = '\0';
        p->ind_module = MOD_JASYN_D;
        p->vm_id = -1;

        if (op == 0)
        {
            j2me_mms_registering = KAL_TRUE;
        }
	    else
	    {
	        J2ME_mms_reset_temp_appid_for_incoming();
        	j2me_mms_temp_appid_for_incoming.app_id_len = appIdLen;
        	j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(appIdLen + 1);
        	if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
        	{
            	memcpy(j2me_mms_temp_appid_for_incoming.app_id, appid, appIdLen);
            	j2me_mms_temp_appid_for_incoming.app_id[appIdLen] = '\0';
			    J2ME_mms_delete_appid_Incoming();
        	}
		    J2ME_mms_reset_temp_appid_for_incoming();
	    }
		
        j2me_mms_register_type = type;

        J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ, mms_get_service_module(MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id_len      [IN]        
 *  app_id          [?]         
 *  operation       [IN]        
 *  type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jwa_mms_register(int app_id_len, char *app_id, int operation, int type, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int appIdLen = app_id_len;
    char *applicationId = app_id;
    int op = operation;
    int register_type = type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        )
    {
        return J2ME_MMS_INVALID_SIM;
    }

#ifdef J2ME_SUPPORT_BACKGROUND
    if(jam_mvm_is_vm_support_bg(vm_id))
    {
        /* MMS service is not available during bg running state */
    	if (jam_mvm_get_current_vm_id() == -1)
        {
            //sprintf(_kvmLogStr,"jwa_mms_register: BG running state \n");
        	//  Kprintf();
        
            return J2ME_MMS_NOT_AVAILABLE;
        }
    }
#endif /* J2ME_SUPPORT_BACKGROUND */

    if (appIdLen > 0)
    {
        char *appId = NULL;

        appId = (char*)jvm_malloc(appIdLen + 1);
        memset((S8*) appId, 0, (appIdLen + 1));
        memcpy(appId, applicationId, appIdLen);

        J2ME_mms_register(appId, op, register_type, vm_id);

        jvm_free(appId);

        return J2ME_MMS_OK;
    }
    else
    {
        return J2ME_MMS_INVALID_PARAMETER;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_send_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  send_data           [?]         
 *  msg_info_len        [IN]        
 *  msg_info            [?]         
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_send_message(jwa_mms_send_req_struct *send_data, kal_uint32 msg_info_len, kal_uint8 *msg_info, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    jwa_mms_send_req_struct *send_req_data = send_data;
    kal_uint32 peerBufLen = msg_info_len;
    kal_uint8 *msg_info_data = msg_info;

    wap_mmc_send_appmms_req_struct *p;
    peer_buff_struct *peer_buff_ptr;
    kal_uint16 dummyLen = 0;
	int i;
    kal_uint8 sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        )
    {
        return J2ME_MMS_INVALID_SIM;
    }

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* MMS service is not available during bg running state */
        if (jam_mvm_get_current_vm_id() == -1)
        {
            //sprintf(_kvmLogStr,"jwa_mms_send_message: BG running state \n");
        	//Kprintf();
    
            /* if MMS is in progress, JAL should send the abort indication to Wap Task */
    #if (MAX_VM_INSTANCE_NUM == 1)
            if ( j2me_mms_in_progress == KAL_TRUE )
            {
                J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
                j2me_mms_in_progress = KAL_FALSE;
            }
    #endif
        
            return J2ME_MMS_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */

    p = (wap_mmc_send_appmms_req_struct*) construct_local_para(sizeof(wap_mmc_send_appmms_req_struct), TD_CTRL);

    p->priority = (kal_uint8) send_req_data->priority;
    p->to_addr_no = (kal_uint8) send_req_data->to_addr_no;
    p->cc_addr_no = (kal_uint8) send_req_data->cc_addr_no;
    p->bcc_addr_no = (kal_uint8) send_req_data->bcc_addr_no;
    p->bdy_part_no = (kal_uint8) send_req_data->bdy_part_no;
    p->app_id_len = (kal_uint8) send_req_data->app_id_len;
    p->reply_app_id_len = (kal_uint8) send_req_data->reply_app_id_len;
    p->start_cnt_id_len = (kal_uint8) send_req_data->start_cnt_id_len;

#if (MMI_MAX_SIM_NUM >= 2)
    sim_id = jam_mvm_get_valid_sim_id(vm_id);
    if (sim_id == CBM_SIM_ID_SIM4)
    {
        p->simId = MMC_SIM_CARD_SIM4;
    }
    else if (sim_id == CBM_SIM_ID_SIM3)
    {
        p->simId = MMC_SIM_CARD_SIM3;
    }
    else if (sim_id == CBM_SIM_ID_SIM2)
    {
        p->simId = MMC_SIM_CARD_SIM2;
    }
    else 
    {
        p->simId = MMC_SIM_CARD_SIM1;
    }
#endif

    if (p->app_id_len > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        free_local_para((local_para_struct*) p);
        return J2ME_MMS_INVALID_PARAMETER;
    }
    if (p->reply_app_id_len > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        free_local_para((local_para_struct*) p);
        return J2ME_MMS_INVALID_PARAMETER;
    }
    if (p->start_cnt_id_len > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        free_local_para((local_para_struct*) p);
        return J2ME_MMS_INVALID_PARAMETER;
    }
    if (peerBufLen > J2ME_MMS_PEER_BUFFER_LEN)
    {
        free_local_para((local_para_struct*) p);
        return J2ME_MMS_INVALID_PARAMETER;
    }

    p->delivery_time = (kal_uint32) (send_req_data->delivery_time / 1000);

    if (p->app_id_len > 0)
    {
        memcpy(p->app_id, send_req_data->app_id, p->app_id_len);
        p->app_id[p->app_id_len] = '\0';
    }
    else
    {
        p->app_id[0] = '\0';
    }

    if (p->reply_app_id_len > 0)
    {
        memcpy(p->reply_app_id, send_req_data->reply_app_id, p->reply_app_id_len);
        p->reply_app_id[p->reply_app_id_len] = '\0';
    }
    else
    {
        p->reply_app_id[0] = '\0';
    }

    if (p->start_cnt_id_len > 0)
    {
        memcpy(p->start_cnt_id, send_req_data->start_cnt_id, p->start_cnt_id_len);
        p->start_cnt_id[p->start_cnt_id_len] = '\0';
        p->mms_type = J2ME_MMS_RELATED;
    }
    else
    {
        p->start_cnt_id[0] = '\0';
        p->mms_type = J2ME_MMS_MIXED;
    }

    if (peerBufLen > 0)
    {
        peer_buff_ptr = construct_peer_buff((kal_uint16) peerBufLen, 0, 0, TD_CTRL);
        memcpy(get_peer_buff_pdu(peer_buff_ptr, &dummyLen), msg_info_data, peerBufLen);
    }
    else
    {
        peer_buff_ptr = NULL;
    }

    p->send_by_file = 0;
    p->filepath_len = 0;
    p->filepath[0] = 0;
	
#if (MAX_VM_INSTANCE_NUM > 1)
	kal_take_mutex(g_jam_async_mms_mvm_mutex);

	if (j2me_mms_processing_task_vm_id != -1 && j2me_mms_processing_task_vm_id != vm_id)
	{	
		for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
        {
            if (j2me_mms_mvm_pending_task[i].vm_id == vm_id)
            {
	   	 		if (j2me_mms_mvm_pending_task[i].mms_req_ptr)
	    		{
	        		free_local_para((local_para_struct*)j2me_mms_mvm_pending_task[i].mms_req_ptr);
	    		}
				if (j2me_mms_mvm_pending_task[i].mms_req_buff)
				{
				    free_peer_buff((peer_buff_struct*)j2me_mms_mvm_pending_task[i].mms_req_buff);
				}
		        j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_SEND;
				j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
				j2me_mms_mvm_pending_task[i].mms_req_buff = peer_buff_ptr;
				break;
            }
			else if (j2me_mms_mvm_pending_task[i].vm_id == -1)
			{
			    j2me_mms_mvm_pending_task[i].vm_id = vm_id;
				j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_SEND;
				j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
				j2me_mms_mvm_pending_task[i].mms_req_buff = peer_buff_ptr;
			    break;
			}
		}
	}
    else
#endif
    {
		j2me_mms_processing_task_vm_id = vm_id;
		jwa_mms_set_state(JWA_MMS_STATE_SEND);
        j2me_mms_in_progress = KAL_TRUE;
    
    	J2ME_mms_send_ilm(p, peer_buff_ptr, MSG_ID_WAP_MMC_SEND_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_SEND_APPMMS_REQ));
    }

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_give_mutex(g_jam_async_mms_mvm_mutex);
#endif

    return J2ME_MMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_send_message_part
 * DESCRIPTION
 *  
 * PARAMETERS
 *  send_msg_part_data      [?]     
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_send_message_part(jwa_mms_send_msg_part_req_struct *send_msg_part_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jwa_mms_send_msg_part_req_struct *send_part = send_msg_part_data;

    wap_mmc_post_appmms_msg_part_res_struct *p;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        )
    {
    	/* if MMS is in progress, JAL should send the abort indication to Wap Task */
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
            J2ME_mms_reset_temp_appid_for_recv();
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        }
        return J2ME_MMS_INVALID_SIM;
    }

#ifdef J2ME_SUPPORT_BACKGROUND
    /* MMS service is not available during bg running state */
    if (vm_id == -1)
    {
        //sprintf(_kvmLogStr,"jwa_mms_send_message_part: BG running state \n");
    	//Kprintf();

        /* if MMS is in progress, JAL should send the abort indication to Wap Task */ 
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        } 
    
        return J2ME_MMS_NOT_AVAILABLE;
    }
#endif /* J2ME_SUPPORT_BACKGROUND */

    p = (wap_mmc_post_appmms_msg_part_res_struct*)
        construct_local_para(sizeof(wap_mmc_post_appmms_msg_part_res_struct), TD_CTRL);

    p->encoding_scheme = (mmc_charset_enum) send_part->encoding_scheme;
    p->content_type_len = (kal_uint8) send_part->content_type_len;
    p->content_id_len = (kal_uint8) send_part->content_id_len;
    p->content_location_len = (kal_uint8) send_part->content_location_len;
    p->filepath_len = (kal_uint8) send_part->filepath_len;

    if (p->content_type_len > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        free_local_para((local_para_struct*) p);
		/* if MMS is in progress, JAL should send the abort indication to Wap Task */
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
            J2ME_mms_reset_temp_appid_for_recv();
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        }
        return J2ME_MMS_INVALID_PARAMETER;
    }
    if (p->content_id_len > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        free_local_para((local_para_struct*) p);
		/* if MMS is in progress, JAL should send the abort indication to Wap Task */
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
            J2ME_mms_reset_temp_appid_for_recv();
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        }
        return J2ME_MMS_INVALID_PARAMETER;
    }
    if (p->content_location_len > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        free_local_para((local_para_struct*) p);
		/* if MMS is in progress, JAL should send the abort indication to Wap Task */
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
            J2ME_mms_reset_temp_appid_for_recv();
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        }
        return J2ME_MMS_INVALID_PARAMETER;
    }
    if (p->filepath_len > J2ME_MMS_MAX_FILE_PATH_LEN)
    {
        free_local_para((local_para_struct*) p);
		/* if MMS is in progress, JAL should send the abort indication to Wap Task */
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
            J2ME_mms_reset_temp_appid_for_recv();
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        }
        return J2ME_MMS_INVALID_PARAMETER;
    }

    if (p->content_type_len > 0)
    {
        memcpy(p->content_type, send_part->content_type, p->content_type_len);
        p->content_type[p->content_type_len] = '\0';
    }
    else
    {
        p->content_type[0] = '\0';
    }

    if (p->content_id_len > 0)
    {
        memcpy(p->content_id, send_part->content_id, p->content_id_len);
        p->content_id[p->content_id_len] = '\0';
    }
    else
    {
        p->content_id[0] = '\0';
    }

    if (p->content_location_len > 0)
    {
        memcpy(p->content_location, send_part->content_location, p->content_location_len);
        p->content_location[p->content_location_len] = '\0';
    }
    else
    {
        p->content_location[0] = '\0';
    }

    if (p->filepath_len > 0)
    {
        kal_uint8 *filepath = jvm_malloc(p->filepath_len + 1);

        memset(filepath, 0, p->filepath_len + 1);
        strncpy((kal_char*) filepath, (kal_char*) (send_part->filepath), p->filepath_len);

        kal_wsprintf(p->filepath, "%s", filepath);
        p->filepath_len = kal_wstrlen(p->filepath);

        jvm_free(filepath);
    }

    J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES, mms_get_service_module(MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES));

    return J2ME_MMS_OK;

}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_message_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id_length       [IN]        
 *  app_id              [?]         
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_message_req(int app_id_length, char *app_id, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 appIdLen = (kal_uint8) app_id_length;
    char *appId = app_id;

    wap_mmc_recv_appmms_req_struct *p;
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        )
    {
        return J2ME_MMS_INVALID_SIM;
    }

    if (appIdLen == 0)
    {
        return J2ME_MMS_INVALID_PARAMETER;
    }

    if (appIdLen > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        return J2ME_MMS_INVALID_PARAMETER;
    }

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* MMS service is not available during bg running state */
        if (jam_mvm_get_current_vm_id() == -1)
        {
            //sprintf(_kvmLogStr,"jwa_mms_get_message_req: BG running state \n");
        	//Kprintf();
    
            /* if MMS is in progress, JAL should send the abort indication to Wap Task */
    #if (MAX_VM_INSTANCE_NUM == 1)
            if ( j2me_mms_in_progress == KAL_TRUE )
            {
                J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
                j2me_mms_in_progress = KAL_FALSE;
            }
    #endif
    
            return J2ME_MMS_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */

    p = (wap_mmc_recv_appmms_req_struct*) construct_local_para(sizeof(wap_mmc_recv_appmms_req_struct), TD_CTRL);
    p->app_id_len = appIdLen;

    memcpy(p->app_id, appId, p->app_id_len);
    p->app_id[p->app_id_len] = '\0';

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_take_mutex(g_jam_async_mms_mvm_mutex);

	if (j2me_mms_processing_task_vm_id != -1 && j2me_mms_processing_task_vm_id != vm_id)
	{   
		for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
		{
			if (j2me_mms_mvm_pending_task[i].vm_id == vm_id)
			{
				if (j2me_mms_mvm_pending_task[i].mms_req_ptr)
				{
					free_local_para((local_para_struct*)j2me_mms_mvm_pending_task[i].mms_req_ptr);
				}
				if (j2me_mms_mvm_pending_task[i].mms_req_buff)
				{
					free_peer_buff((peer_buff_struct*)j2me_mms_mvm_pending_task[i].mms_req_buff);
				}
				j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_GET_INCOMING_MSG;
				j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
				j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
				break;
			}
			else if (j2me_mms_mvm_pending_task[i].vm_id == -1)
			{
				j2me_mms_mvm_pending_task[i].vm_id = vm_id;
				j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_GET_INCOMING_MSG;
				j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
				j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
				break;
			}
		}
	}
	else
#endif
    {
        J2ME_mms_reset_temp_appid_for_recv();
	    j2me_mms_temp_appid_for_recv.app_id_len = appIdLen;
	    j2me_mms_temp_appid_for_recv.app_id = (kal_uint8*) jvm_malloc(appIdLen + 1);
	    if (j2me_mms_temp_appid_for_recv.app_id != NULL)
	    {
	        memcpy(j2me_mms_temp_appid_for_recv.app_id, appId, appIdLen);
	        j2me_mms_temp_appid_for_recv.app_id[appIdLen] = '\0';
	    }

		j2me_mms_processing_task_vm_id = vm_id;
		jwa_mms_set_state(JWA_MMS_STATE_GET_INCOMING_MSG);

	    j2me_mms_in_progress = KAL_TRUE;
	    J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_RECV_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_RECV_APPMMS_REQ));
    }

#if (MAX_VM_INSTANCE_NUM > 1)
	kal_give_mutex(g_jam_async_mms_mvm_mutex);
#endif	  

    return J2ME_MMS_OK;

}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_message_part_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  more        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_message_part_req(int more)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        )
    {
        J2ME_mms_reset_temp_appid_for_recv();
		/* if MMS is in progress, JAL should send the abort indication to Wap Task */
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
            J2ME_mms_reset_temp_appid_for_recv();
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        }
        return J2ME_MMS_INVALID_SIM;
    }

#ifdef J2ME_SUPPORT_BACKGROUND
    /* MMS service is not available during bg running state */
    if (jam_mvm_get_current_vm_id() == -1)
    {
        //sprintf(_kvmLogStr,"jwa_mms_get_message_part_req: BG running state \n");
    	//Kprintf();

        /* if MMS is in progress, JAL should send the abort indication to Wap Task */
        if ( j2me_mms_in_progress == KAL_TRUE )
        {
            J2ME_mms_reset_temp_appid_for_recv();
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
            J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
            j2me_mms_in_progress = KAL_FALSE;
        }
    
        return J2ME_MMS_NOT_AVAILABLE;
    }
#endif /* J2ME_SUPPORT_BACKGROUND */

    if (more == 0)
    {
        j2me_mms_is_more_msg_part = KAL_FALSE;
        j2me_mms_in_progress = KAL_FALSE;
    }
	else
	{
	    j2me_mms_is_more_msg_part = KAL_TRUE;
	}

    J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ, mms_get_service_module(MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ));

    return J2ME_MMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_check_incoming_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id_len      [IN]        
 *  app_id          [?]         
 *  only_new        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_check_incoming_message(int app_id_len, char *app_id, kal_bool only_new, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int appIdLen = app_id_len;
    kal_uint8 *appId = (kal_uint8*) app_id;
    kal_bool onlyNew = only_new;
    kal_bool checked = KAL_FALSE;
    wap_mmc_check_appmms_coming_req_struct *p;
    wap_mmc_check_appmms_coming_rsp_struct *fake_incoming_rsp;
    //ilm_struct fake_register_ilm_Incoming;  
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        )
    {
        return J2ME_MMS_INVALID_SIM;
    }

    if (appIdLen == -1)
    {
        return J2ME_MMS_INVALID_PARAMETER;
    }
    else if (appIdLen > J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN)
    {
        return J2ME_MMS_INVALID_PARAMETER;
    }
    
#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* MMS service is not available during bg running state */
        if (jam_mvm_get_current_vm_id() == -1)
        {
            //sprintf(_kvmLogStr,"jwa_mms_check_incoming_message: BG running state \n");
        	//Kprintf();
        
            return J2ME_MMS_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */
    
    else
    {

        p = (wap_mmc_check_appmms_coming_req_struct*)
            construct_local_para(sizeof(wap_mmc_check_appmms_coming_req_struct), TD_CTRL);

        p->only_new = (kal_bool) onlyNew;
        p->app_id_len = appIdLen;

        memcpy(p->app_id, appId, p->app_id_len);
        p->app_id[p->app_id_len] = '\0';

#if (MAX_VM_INSTANCE_NUM > 1)
		kal_take_mutex(g_jam_async_mms_mvm_mutex);
	
		if (j2me_mms_processing_task_vm_id != -1 && j2me_mms_processing_task_vm_id != vm_id)
		{	
			for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
			{
				if (j2me_mms_mvm_pending_task[i].vm_id == vm_id)
				{
					if (j2me_mms_mvm_pending_task[i].mms_req_ptr)
					{
						free_local_para((local_para_struct*)j2me_mms_mvm_pending_task[i].mms_req_ptr);
					}
					if (j2me_mms_mvm_pending_task[i].mms_req_buff)
					{
						free_peer_buff((peer_buff_struct*)j2me_mms_mvm_pending_task[i].mms_req_buff);
					}
					j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_CHECK_INCOMING_MSG;
					j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
					j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
					break;
				}
				else if (j2me_mms_mvm_pending_task[i].vm_id == -1)
				{
					j2me_mms_mvm_pending_task[i].vm_id = vm_id;
					j2me_mms_mvm_pending_task[i].pending_operation = JWA_MMS_STATE_CHECK_INCOMING_MSG;
					j2me_mms_mvm_pending_task[i].mms_req_ptr = (void*) p;
					j2me_mms_mvm_pending_task[i].mms_req_buff = NULL;
					break;
				}
			}
		}
		else
#endif
		{
		    glb_onlynew = only_new;
			
			J2ME_mms_reset_temp_appid_for_incoming();
	        j2me_mms_temp_appid_for_incoming.app_id_len = p->app_id_len;
	        j2me_mms_temp_appid_for_incoming.app_id = (kal_uint8*) jvm_malloc(p->app_id_len + 1);

	        if (j2me_mms_temp_appid_for_incoming.app_id != NULL)
	        {
	            memcpy(j2me_mms_temp_appid_for_incoming.app_id, p->app_id, p->app_id_len);
	            j2me_mms_temp_appid_for_incoming.app_id[p->app_id_len] = '\0';
	        }
				
	        if(glb_onlynew)
			{
			   for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
	           {
	               if (j2me_mms_appid_Incoming[i].app_id_len == j2me_mms_temp_appid_for_incoming.app_id_len)
	               {
	                   if (strncmp
	                       ((char*)j2me_mms_appid_Incoming[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
	                        j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
	                   {
	                       checked = KAL_TRUE;  /*It means no incoming message on the checked application id*/
	                       break;
	                   }
	               }/*if*/
	            }/*for*/
	        }
			else
		    {
				for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
			    {
				    if (j2me_mms_appid_Incoming2[i].app_id_len == j2me_mms_temp_appid_for_incoming.app_id_len)
				    {
				        if (strncmp((char*)j2me_mms_appid_Incoming2[i].app_id, (char*)j2me_mms_temp_appid_for_incoming.app_id,
						    j2me_mms_temp_appid_for_incoming.app_id_len) == 0)
					    {
					         checked = KAL_TRUE;  /*It means no incoming message on the checked application id*/
					         break;
					    }
				    }/*if*/
			    }/*for*/
			}

			j2me_mms_processing_task_vm_id = vm_id;
			jwa_mms_set_state(JWA_MMS_STATE_CHECK_INCOMING_MSG);

			if(!checked)
		    {
	            J2ME_mms_send_ilm(p, NULL, MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ, mms_get_service_module(MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ));
	        }
			else
	        {
	            /*Free the locol para*/
			    free_local_para((local_para_struct*) p);

				fake_incoming_rsp = (wap_mmc_check_appmms_coming_rsp_struct*)
                                              construct_local_para(sizeof(wap_mmc_check_appmms_coming_rsp_struct), TD_CTRL);
			   
			    /* construct the fake request and response */
	            fake_incoming_rsp->result = 0; 
	            /*fake_register_ilm_Incoming.dest_mod_id = MOD_JASYN_D;
	                     fake_register_ilm_Incoming.src_mod_id = MOD_WAP;
	                     fake_register_ilm_Incoming.msg_id = MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP;
	                     fake_register_ilm_Incoming.sap_id = J2ME_WAP_SAP;
	                     fake_register_ilm_Incoming.local_para_ptr = (local_para_struct*) &fake_register_rsp_Incoming;
	                     fake_register_ilm_Incoming.peer_buff_ptr = NULL;
	                     J2ME_mms_response_handler(&fake_register_ilm_Incoming);*/
				J2ME_mms_send_fake_ilm(fake_incoming_rsp, NULL, MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP);
			}
		}
		
#if (MAX_VM_INSTANCE_NUM > 1)
		kal_give_mutex(g_jam_async_mms_mvm_mutex);
#endif
    }

    return J2ME_MMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  receive_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_message(jwa_mms_receive_msg_struct *receive_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jwa_mms_receive_msg_struct *receiveData = receive_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    receiveData->priority = j2me_mms_recv_data.priority;
    receiveData->from_addr_no = j2me_mms_recv_data.from_addr_no;
    receiveData->to_addr_no = j2me_mms_recv_data.to_addr_no;
    receiveData->cc_addr_no = j2me_mms_recv_data.cc_addr_no;
    receiveData->bdy_part_no = j2me_mms_recv_data.bdy_part_no;
    receiveData->start_cnt_id_len = j2me_mms_recv_data.start_cnt_id_len;
    receiveData->reply_app_id_len = j2me_mms_recv_data.reply_app_id_len;
    receiveData->msg_info_len = j2me_mms_recv_data.peer_buffer_len;
    receiveData->date = j2me_mms_recv_data.date;

    if (j2me_mms_recv_data.start_cnt_id != NULL)
    {
        receiveData->start_cnt_id = j2me_mms_recv_data.start_cnt_id;
    }
    else
    {
        receiveData->start_cnt_id = NULL;
    }

    if (j2me_mms_recv_data.reply_app_id != NULL)
    {
        receiveData->reply_app_id = j2me_mms_recv_data.reply_app_id;
    }
    else
    {
        receiveData->reply_app_id = NULL;
    }

    if (j2me_mms_recv_data.peer_buffer != NULL)
    {
        receiveData->msg_info = j2me_mms_recv_data.peer_buffer;
    }
    else
    {
        receiveData->msg_info = NULL;
    }

    /* J2ME_mms_reset_recv_data(); */

    return J2ME_MMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_reset_recv_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_reset_recv_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    J2ME_mms_reset_recv_data();

    return J2ME_MMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_mseesag_part
 * DESCRIPTION
 *  
 * PARAMETERS
 *  receive_msg_part        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_mseesag_part(jwa_mms_receive_msg_part_struct *receive_msg_part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 filesize = 0;

    jwa_mms_receive_msg_part_struct *receive_msg_part_data = receive_msg_part;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    receive_msg_part_data->encoding_scheme = j2me_mms_recv_part_data.encoding_scheme;
    receive_msg_part_data->content_type_len = j2me_mms_recv_part_data.content_type_len;
    receive_msg_part_data->content_id_len = j2me_mms_recv_part_data.content_id_len;
    receive_msg_part_data->content_location_len = j2me_mms_recv_part_data.content_location_len;

    if (j2me_mms_recv_part_data.filepath_len > 0)
    {
        FS_HANDLE fh;

        fh = FS_Open(j2me_mms_recv_part_data.filepath, FS_READ_ONLY);
        if (fh < 0)
        {
            FS_Close(fh);
            return J2ME_MMS_READ_MSG_CONTENT_PART_FILE_ERROR;
        }
        if (FS_GetFileSize(fh, &filesize) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return J2ME_MMS_READ_MSG_CONTENT_PART_FILE_ERROR;
        }
        FS_Close(fh);
    }

    j2me_mms_recv_part_data.file_size = filesize;

    receive_msg_part_data->file_size = j2me_mms_recv_part_data.file_size;

    if (j2me_mms_recv_part_data.content_type != NULL)
    {
        receive_msg_part_data->content_type = j2me_mms_recv_part_data.content_type;
    }
    if (j2me_mms_recv_part_data.content_id != NULL)
    {
        receive_msg_part_data->content_id = j2me_mms_recv_part_data.content_id;
    }
    if (j2me_mms_recv_part_data.content_location != NULL)
    {
        receive_msg_part_data->content_location = j2me_mms_recv_part_data.content_location;
    }

    /* J2ME_mms_reset_recv_part_data(KAL_FALSE); */

    return J2ME_MMS_OK;

}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_message_part_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  receive_msg_part        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_message_part_content(jwa_mms_receive_msg_part_content_struct *receive_msg_part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar* filepath = NULL;
    kal_uint8 filename[] = "mms_temp_content";
    kal_uint8 filepath_len = 100;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (j2me_mms_recv_part_data.filepath_len == 0 || j2me_mms_recv_part_data.filepath == NULL)
    {
        return J2ME_MMS_EMPTY_MSG_CONTENT_PART;
    }

    if (j2me_mms_recv_part_data.file_size == 0)
    {
        FS_HANDLE fh;
        kal_uint32 filesize;

        fh = FS_Open(j2me_mms_recv_part_data.filepath, FS_READ_ONLY);
        if (fh < 0)
        {
            FS_Close(fh);
            return J2ME_MMS_READ_MSG_CONTENT_PART_FILE_ERROR;
        }
        if (FS_GetFileSize(fh, &filesize) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return J2ME_MMS_READ_MSG_CONTENT_PART_FILE_ERROR;
        }
        j2me_mms_recv_part_data.file_size = filesize;
        FS_Close(fh);
    }

    filepath = get_ctrl_buffer(filepath_len * 2);

    kal_wsprintf(filepath, "%s\\%s", jwa_mms_msg_part_file_path, filename);

    //FS_Delete(filepath);
    //FS_Rename(j2me_mms_recv_part_data.filepath, filepath);

    FS_Move(j2me_mms_recv_part_data.filepath, filepath, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0);

    receive_msg_part->file_size = j2me_mms_recv_part_data.file_size;
    mmi_ucs2_to_asc((S8*) receive_msg_part->filepath, (S8*) filepath);
    receive_msg_part->filepath_len = strlen((char*)receive_msg_part->filepath);

    J2ME_mms_reset_recv_part_data(KAL_TRUE);

    free_ctrl_buffer(filepath);
    filepath = NULL;

    return J2ME_MMS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_primitive_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_primitive_result()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jwa_mms_state_enum state = (jwa_mms_state_enum)jwa_mms_get_state();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case JWA_MMS_STATE_CHECK_INCOMING_MSG:
        case JWA_MMS_STATE_REGISTER_APPID:
		case JWA_MMS_STATE_SEND:
        case JWA_MMS_STATE_GET_INCOMING_MSG:
        {
            jwa_mms_set_state(JWA_MMS_STATE_IDLE);
        }
        break;

        default:
        {

        }
        break;
    }

    return (int)j2me_mms_result;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_response_primitive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_response_primitive()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    unsigned long message_id;
    int result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message_id = readMmsAsyncEvent();

    switch (message_id)
    {
        case MSG_ID_WAP_MMC_SEND_APPMMS_RSP:
        {
            result = MSG_MMS_SEND_APPMMS_RSP;
        }
            break;

        case MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND:
        {
            result = MSG_MMS_POST_APPMMS_MSG_PART_IND;
        }
            break;

        case MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP:
        {
            result = MSG_MMS_CFG_APPMMS_APPID_RSP;
        }
            break;

        case MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP:
        {
            result = MSG_MMS_CHECK_APPMMS_COMING_RSP;
        }
            break;

        case MSG_ID_WAP_MMC_RECV_APPMMS_RSP:
        {
            result = MSG_MMS_RECV_APPMMS_RSP;
        }
            break;

        case MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP:
        {
            result = MSG_MMS_READ_APPMMS_CONTENT_RSP;
        }
            break;

            /*
             * case MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_RSP:{
             * result = MSG_MMS_PHB_GET_ENTRY_BY_INDEX_RSP;
             * }
             * break;
             */
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
 *  jwa_mms_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jwa_mms_initialize(void)
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
 *  jwa_mms_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jwa_mms_finalize()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    finalizeMms();
    return J2ME_NO_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  finalizeMms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void finalizeMms()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
	kal_wchar path[15];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    J2ME_mms_reset_recv_data();
    J2ME_mms_reset_recv_part_data(KAL_TRUE);
    J2ME_mms_reset_temp_appid_for_incoming();
	J2ME_mms_reset_temp_appid_for_recv();

#if (MAX_VM_INSTANCE_NUM > 1)
	J2ME_mms_mvm_deinit();
#endif

    /* Delete all the mms part files */
	memset(path, 0, 15 * 2);
	kal_wsprintf(path, "%s", jwa_mms_msg_part_file_path);
	if (FS_GetAttributes(path) >= 0)
	{
		FS_XDelete(path, FS_FILE_TYPE|FS_RECURSIVE_TYPE, NULL, 0);
	}

    if (j2me_mms_in_progress || (jwa_mms_get_state() != JWA_MMS_STATE_IDLE) && (jwa_mms_get_state() != JWA_MMS_STATE_ABORT))
    {
		jwa_mms_set_state(JWA_MMS_STATE_ABORT);
        J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
        j2me_mms_in_progress = KAL_FALSE;
    }

    for (i = 0; i < J2ME_MMS_REGISTER_APPID_NUM; i++)
    {
        if (j2me_mms_appid[i].app_id_len != 0 && j2me_mms_appid[i].app_id != NULL)
        {
            J2ME_mms_register((char*)j2me_mms_appid[i].app_id, 1, WMA_REGISTRY, -1);       /* 1 for remove */

            j2me_mms_appid[i].app_id_len = 0;
            jvm_free(j2me_mms_appid[i].app_id);
            j2me_mms_appid[i].app_id = NULL;
            j2me_mms_appid[i].serial_number = 0;
        }
		
		j2me_mms_appid_Incoming[i].app_id_len = 0;
		if (j2me_mms_appid_Incoming[i].app_id != NULL)
        {
            jvm_free(j2me_mms_appid_Incoming[i].app_id);
            j2me_mms_appid_Incoming[i].app_id = NULL;
        }
		
		j2me_mms_appid_Incoming2[i].app_id_len = 0;
		if (j2me_mms_appid_Incoming[i].app_id != NULL)
        {
            jvm_free(j2me_mms_appid_Incoming2[i].app_id);
            j2me_mms_appid_Incoming2[i].app_id = NULL;
        }
    }
}




#if (MAX_VM_INSTANCE_NUM > 1)
/*****************************************************************************
 * FUNCTION
 *  finalizeMmsByVM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void finalizeMmsByVM(int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_async_mms_mvm_mutex);
	if (jwa_mms_get_state() != JWA_MMS_STATE_IDLE)
	{
	    for (i = 0; i < MAX_VM_INSTANCE_NUM; i++)
        {
            if (j2me_mms_mvm_pending_task[i].vm_id == vm_id)
            {
                if (j2me_mms_mvm_pending_task[i].mms_req_ptr)
			    {
			        free_local_para((local_para_struct*)j2me_mms_mvm_pending_task[i].mms_req_ptr);
			    }
				if (j2me_mms_mvm_pending_task[i].mms_req_buff)
				{
					free_peer_buff((peer_buff_struct*)j2me_mms_mvm_pending_task[i].mms_req_buff);
				}

				for (j = i; j < MAX_VM_INSTANCE_NUM - 1; j++)
				{
				    j2me_mms_mvm_pending_task[j].mms_req_ptr = j2me_mms_mvm_pending_task[j + 1].mms_req_ptr;
					j2me_mms_mvm_pending_task[j].mms_req_buff = j2me_mms_mvm_pending_task[j + 1].mms_req_buff;
				    j2me_mms_mvm_pending_task[j].pending_operation = j2me_mms_mvm_pending_task[j + 1].pending_operation;
				    j2me_mms_mvm_pending_task[j].vm_id = j2me_mms_mvm_pending_task[j + 1].vm_id;
					if (j2me_mms_mvm_pending_task[j + 1].vm_id == -1)
					{
					    break;
					}
				}

				j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_ptr = NULL;
				j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].mms_req_buff = NULL;
				j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].pending_operation = JWA_MMS_STATE_IDLE;
				j2me_mms_mvm_pending_task[MAX_VM_INSTANCE_NUM - 1].vm_id = -1;
				break;
            }
	    }

		if (j2me_mms_processing_task_vm_id == vm_id)
		{
		    J2ME_mms_reset_recv_data();
		    J2ME_mms_reset_recv_part_data(KAL_TRUE);
		    J2ME_mms_reset_temp_appid_for_incoming();
			J2ME_mms_reset_temp_appid_for_recv();
		    
			jwa_mms_set_state(JWA_MMS_STATE_ABORT);
		    J2ME_mms_send_ilm(NULL, NULL, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ, mms_get_service_module(MSG_ID_WAP_MMC_ABORT_APPMMS_REQ));
		}
	}
	else
	{
	    j2me_mms_processing_task_vm_id = -1;
	}
	kal_give_mutex(g_jam_async_mms_mvm_mutex);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jwa_mms_get_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jwa_mms_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_MMS_GET_STATE, jwa_mms_state);

    return jwa_mms_state;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_set_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jwa_mms_set_state(int state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, WMA_MMS_SET_STATE, state, jwa_mms_state);

    jwa_mms_state = state;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_mmsc_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_int32
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jwa_mms_mmsc_init(kal_int32 vm_id)
{
    kal_bool abort_received = KAL_FALSE;
    kal_int32 dst_mod;
    wap_mmc_get_mms_prof_req_struct* get_mms_prof;
    kal_uint8 sim_id;

#if defined(SUPPORT_JSR_205)
    if(vm_id < 0 || vm_id >= MAX_VM_INSTANCE_NUM)
    {
        return J2ME_NO_ERROR;
    }
	
    if (!mmi_java_is_no_network_service())
    {
        wap_mmc_get_mms_prof_req_struct *get_mms_prof;
      
        get_mms_prof = construct_local_para(sizeof(wap_mmc_get_mms_prof_req_struct), TD_CTRL);
      
        get_mms_prof->access_id = WAP_MMS_PROF_MMSC_ADDRESS;
     
#if (MMI_MAX_SIM_NUM >= 2)
        sim_id = jam_mvm_get_valid_sim_id(vm_id);
        if (sim_id == CBM_SIM_ID_SIM4)
        {
            get_mms_prof->simId = MMC_SIM_CARD_SIM4;
        }
        else if (sim_id == CBM_SIM_ID_SIM3)
        {
            get_mms_prof->simId = MMC_SIM_CARD_SIM3;
        }
        else if (sim_id == CBM_SIM_ID_SIM2)
        {
            get_mms_prof->simId = MMC_SIM_CARD_SIM2;
        }
        else 
        {
            get_mms_prof->simId = MMC_SIM_CARD_SIM1;
        }
#endif
        dst_mod = mms_get_service_module(MSG_ID_WAP_MMC_GET_MMS_PROF_REQ);
        java_send_msg_from_active_mod(dst_mod,J2ME_MMI_SAP,MSG_ID_WAP_MMC_GET_MMS_PROF_REQ,get_mms_prof);
        get_next_event(KAL_TRUE, MSG_ID_WAP_MMC_GET_MMS_PROF_RSP, KAL_FALSE, KAL_TRUE, &abort_received);
      
    }
#endif /* defined(SUPPORT_JSR_205) */ 
    if(abort_received)
        return USER_CANCEL;
	
    return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_initialize_vm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_int32
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jwa_mms_initialize_vm(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_wchar path[15];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	jwa_mms_msg_part_file_path[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);

	memset(path, 0, 15 * 2);
	kal_wsprintf(path, "%c:\\@Java", jwa_mms_msg_part_file_path[0]);
	check_and_create_hidden_folder(path);

	memset(path, 0, 15 * 2);
	kal_wsprintf(path, "%c:\\@Java\\mms", jwa_mms_msg_part_file_path[0]);
	check_and_create_hidden_folder(path);
	
#if (MAX_VM_INSTANCE_NUM > 1)
	J2ME_mms_mvm_init();
#endif

	return jwa_mms_mmsc_init(vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  jwa_mms_finalize_vm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_int32
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jwa_mms_finalize_vm(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM > 1)
    finalizeMmsByVM(vm_id);
#endif
	return J2ME_NO_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  is_mms_activated
 * DESCRIPTION
 *  check if there is any pending mms requests
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if there is pending mms request, FALSE otherwise.
 *****************************************************************************/
BOOL is_mms_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (j2me_mms_in_progress)
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
 *  jwa_mms_get_mmsc_addr
 * DESCRIPTION
 *  Get MMSC address string in ascii with null terminator
 * PARAMETERS
 *  void
 * RETURNS
 *  MMSC address string
 *****************************************************************************/
kal_char* jwa_mms_get_mmsc_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_char*)j2me_mms_mmsc_addr;
}

#endif /* SUPPORT_JSR_205 */

