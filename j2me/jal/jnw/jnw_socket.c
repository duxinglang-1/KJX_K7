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
 *   jam_adaptation.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Network socket APIs
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*************************************************************************
 * Include Header Files
 *************************************************************************/

#if !defined(__MTK_TARGET__)
/* mdi_datatype.h include MMIDataType.h which conflict with soc_api.h  */
#include "Windows.h"
#endif /* !defined(__MTK_TARGET__) */ 

#include "jal.h"
#include "jam_internal.h"
#include "jvm_internal.h"
#include "jnw_internal.h"
#include "jnw_interface.h"
#include "jvm_resource_manager.h" //20101104,changed resource mgr for MVM
#include "jam_mvm_manager.h"

#include "jvm_adaptor.h"

#include "app2cbm_struct.h"
#include "app2soc_struct.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"

/* Network */
#include "cbm_api.h"
#include "soc_api.h"
#include "soc2tcpip_struct.h"

#include "cbmSrvGprot.h"
#include "Dtcntsrvgprot.h"
#include "kal_public_api.h"

#if defined( __NEMO_VM__)
#include "thread_stack_switch.h"
#endif

/*************************************************************************
 * External Declaration
 *************************************************************************/
#ifdef __JBLENDIA__
extern void kjava_recvSocDataToBufPool(int handle);
extern void kjava_processDNSevent(app_soc_get_host_by_name_ind_struct* ind_ptr);
#endif /* __JBLENDIA__ */ 
extern kal_int8 jnw_socket_open_bearer(kal_int32 vm_id);

/*************************************************************************
 * Global Definition
 *************************************************************************/

kal_uint32 J2ME_ori_nw_acc_id[MAX_VM_INSTANCE_NUM];

j2me_soc_notify_ind_struct J2ME_asnyc_ind[J2ME_MAX_SOC_NUM];

kal_uint32 jnw_created_socket;
kal_uint32 J2ME_setasyn_bitmap;
kal_uint32 J2ME_dns_setasyn_bitmap;

/* If these is still ONE pending event, so we record the result in the J2ME_blockedasnyc_ind rather than J2ME_asnyc_ind. */
j2me_soc_notify_ind_struct J2ME_blockedasnyc_ind[J2ME_MAX_SOC_NUM];

/* Record the IND result from SOC of MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND. */
j2me_soc_get_host_by_name_ind_struct J2ME_async_ghbn_ind[J2ME_MAX_SOC_NUM];

/* Record the IND result from SOC of MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND. */
j2me_soc_get_host_by_addr_ind_struct J2ME_async_ghbaddr_ind[J2ME_MAX_SOC_NUM];

int net_errno;
kal_bool j2me_socket_io_activated = KAL_FALSE;

/*
 * When polling a connect of the specified handle. If we have not received the corresponding handle IND, we wet the 
 * * corresponding handle bit ON in J2ME_pendingasyn_bitmap to indicate such pending. 
 */
kal_uint32 J2ME_pendingasyn_bitmap;

extern kal_uint32 J2ME_pendingasyn_bitmap;

/* This is used to record a IND event of the handle has another IND but not processed by JNW yet. */
kal_uint32 J2ME_blockedasyn_bitmap;
extern kal_mutexid g_jam_async_mutex;

extern kal_int32 readAsyncEvent(kal_int32 handle, kal_int32 dns_idx, kal_uint32 protect);
kal_int8 _jnw_process_soc_async_event(soc_event_enum event, kal_int32 handle);

extern j2me_soc_notify_ind_struct J2ME_asnyc_ind[J2ME_MAX_SOC_NUM];
extern j2me_soc_notify_ind_struct J2ME_blockedasnyc_ind[J2ME_MAX_SOC_NUM];

extern kal_uint32 jnw_created_socket;
extern kal_uint32 J2ME_blockedasyn_bitmap;
extern kal_uint32 J2ME_setasyn_bitmap;
extern kal_uint32 J2ME_dns_setasyn_bitmap;
extern j2me_soc_get_host_by_name_ind_struct J2ME_async_ghbn_ind[J2ME_MAX_SOC_NUM];
extern kal_mutexid g_jam_async_mutex;

/* This account is used to determine whether Java can be PAUSE/RESUEM or can just be TERMINATED? */
int _active_socket_count = 0;

char *g_pcHostName[J2ME_MAX_SOC_NUM];
static kal_uint16 csd_disconnect_time = 0;
static kal_bool net_initialized = KAL_FALSE;
static kal_uint8 g_dns_idx = 0;
kal_uint8 g_dns_query_num = 0;
j2me_nwk_event_struct j2me_nwk_bearer_evt[J2ME_MAX_APP_NUM];

#ifndef J2ME_SLIM_MEMORY_SUPPORT
    #define MIDP_CONNECTION_DEBUG
#endif



/* Add callback function to receive asyn event */
java_asyn_ind_table J2ME_asyn_table;

/*************************************************************************
 * Function Definition
 *************************************************************************/
/* XXX - non-suitable API, refine later */
int socketCloseHandle(int handle);


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_get_dns_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int jnw_socket_get_dns_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret_dns_idx = 0;
    int count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_GET_DNS_IDX);
    while ((g_pcHostName[g_dns_idx] != NULL) && 
           (count < J2ME_MAX_SOC_NUM))
    {
        count++;
        g_dns_idx++;
        g_dns_idx = g_dns_idx % J2ME_MAX_SOC_NUM;
    }
    if (count >= J2ME_MAX_SOC_NUM)
    {
        return IO_ERROR;
    }
    
    ret_dns_idx = g_dns_idx;
    g_dns_idx++;
    g_dns_idx = g_dns_idx % J2ME_MAX_SOC_NUM;

    return (int)ret_dns_idx;
}


/*****************************************************************************
 * FUNCTION
 *  set_java_csd_timing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_java_csd_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SET_JAVA_CSD_TIMING, csd_disconnect_time, net_initialized);

    /* change the CSD auto disconnect timer once the J2ME environment is initialized */
    if (csd_disconnect_time > 0 && !net_initialized)
    {
        soc_set_csd_auto_disconnect_timer(JAVA_CSD_DISCONNECT_TIME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  restore_java_csd_timing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_java_csd_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_RESTORE_JAVA_CSD_TIMING, csd_disconnect_time, net_initialized);
    if (csd_disconnect_time > 0 && net_initialized)
    {
        soc_set_csd_auto_disconnect_timer(csd_disconnect_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _jnw_socket_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  OriginalHandle      [IN]         
 *  exception           [OUT]           
 * RETURNS
 *  
 *****************************************************************************/
int _jnw_socket_connect(int *OriginalHandle, int *exception)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result;

    /* The following variables are for Bearer Fallback requirement. */
    int handle = *OriginalHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_CONNECT, handle);
    JNW_ENTER();
    *exception = JNW_SOC_ERROR_DEFAULT;
    result = _jnw_process_soc_async_event(SOC_CONNECT, handle);

    if (result == SOC_SUCCESS)
    {
        JNW_LEAVE(result);
    }
    else if (result == SOC_WOULDBLOCK)
    {
        JNW_LEAVE(IO_WOULDBLOCK);
    }
    else
    {
        /*
         * Here, result == SOC_ERROR. 
         */

        /* Decrease the socket count (increase in jnw_socket_open()). */
        jnw_socket_close(-1, handle);
        *exception = JNW_SOC_ERROR_CONNECT_FAIL;

        JNW_LEAVE(IO_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _jnw_socket_gethost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dns_idx     [IN/OUT]        Dns index
 * RETURNS
 *  int
 *****************************************************************************/
int _jnw_socket_gethost(int *dns_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_GETHOST, *dns_idx);
    JNW_ENTER();
    if (readAsyncEvent(31, *dns_idx, KAL_TRUE) != MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND)
    {
        JNW_LEAVE(IO_WOULDBLOCK);
    }
    else
    {
        /* If the corresponding 31 bit has been set. Then we can peek the IND result from the global variable 
           J2ME_async_ghbn_ind we have recorded once we get the message. */

        if (J2ME_async_ghbn_ind[*dns_idx].result == KAL_TRUE)
        {
            if (g_pcHostName[*dns_idx] != NULL)
            {
                free_ctrl_buffer(g_pcHostName[*dns_idx]);
                g_pcHostName[*dns_idx] = NULL;
            }

            JNW_LEAVE(SOC_SUCCESS); /* SUCCESS */
        }
        else
        {
            if (g_pcHostName[*dns_idx] != NULL)
            {
                free_ctrl_buffer(g_pcHostName[*dns_idx]);
                g_pcHostName[*dns_idx] = NULL;
            }
            
            JNW_LEAVE(SOC_ERROR);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_network_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_network_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_NETWORK_INITIALIZE);
    if (!net_initialized)
    {    
        _active_socket_count = 0;

        kal_take_mutex(g_jam_async_mutex);
        kal_mem_set(J2ME_asnyc_ind, 0, sizeof(J2ME_asnyc_ind));
        kal_mem_set(J2ME_blockedasnyc_ind, 0, sizeof(J2ME_blockedasnyc_ind));
        kal_mem_set(J2ME_async_ghbn_ind, 0, sizeof(J2ME_async_ghbn_ind));

        jnw_created_socket = 0;
        J2ME_pendingasyn_bitmap = J2ME_setasyn_bitmap = 0;
        J2ME_dns_setasyn_bitmap = J2ME_blockedasyn_bitmap = 0;
        /* initialize the callback function table */
        J2ME_asyn_table.bearer_callback = NULL;
        J2ME_asyn_table.gethostbyaddr_callback = NULL;
        J2ME_asyn_table.gethostbyname_callback = NULL;
        J2ME_asyn_table.notify_callback = NULL;

        for (i=0; i<J2ME_MAX_SOC_NUM; i++)
        {
            g_pcHostName[i] = NULL;
        }

        kal_give_mutex(g_jam_async_mutex);
        if (!soc_get_csd_auto_disconnect_timer(&csd_disconnect_time))
        {
            csd_disconnect_time = 0;
        }
        else
        {
            set_java_csd_timing();
        }
        
    #ifdef __SSL_SUPPORT__
        /* initialize the tls table */
        jnw_tls_initialize();
    #endif
    
        net_initialized = KAL_TRUE;
        g_dns_query_num = 0;
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            j2me_nwk_bearer_evt[i].app_id = -1;
            j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
            j2me_nwk_bearer_evt[i].wait_event = 0;
        }
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_network_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_network_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_NETWORK_FINALIZE);
    if (net_initialized)
    {
        kal_take_mutex(g_jam_async_mutex);
        kal_mem_set(J2ME_asnyc_ind, 0, sizeof(J2ME_asnyc_ind));
        kal_mem_set(J2ME_blockedasnyc_ind, 0, sizeof(J2ME_blockedasnyc_ind));
        kal_mem_set(J2ME_async_ghbn_ind, 0, sizeof(J2ME_async_ghbn_ind));
        
        jnw_created_socket = 0;
        J2ME_pendingasyn_bitmap = J2ME_setasyn_bitmap = 0;
        J2ME_dns_setasyn_bitmap = J2ME_blockedasyn_bitmap = 0;
        kal_give_mutex(g_jam_async_mutex);
        restore_java_csd_timing();
        net_initialized = KAL_FALSE;
        g_dns_query_num = 0;
        
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            j2me_nwk_bearer_evt[i].app_id = -1;
            j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
            j2me_nwk_bearer_evt[i].wait_event = 0;
        }
    }


}


/*****************************************************************************
 * FUNCTION
 *  jnw_register_callback
 * DESCRIPTION
 *  register the callback function based on type
 * PARAMETERS
 *  type                [IN]        Register type
 *  callback_ptr        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_register_callback(jnw_soc_asyn_ind_enum type, java_async_callback_fn callback_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_REGISTER_CALLBACK, type);
    switch (type)
    {
        case J2ME_NOTIFY_IND:
            J2ME_asyn_table.notify_callback = callback_ptr;
            break;

        case J2ME_HOST_NAME:
            J2ME_asyn_table.gethostbyname_callback = callback_ptr;
            break;

        case J2ME_HOST_ADDR:
            J2ME_asyn_table.gethostbyaddr_callback = callback_ptr;
            break;

        case J2ME_BEARER_INFO:
            J2ME_asyn_table.bearer_callback = callback_ptr;
            break;

        default:
            kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
            break;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_deregister_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        Deregister type
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_deregister_callback(jnw_soc_asyn_ind_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_DEREGISTER_CALLBACK, type);
    switch (type)
    {
        case J2ME_NOTIFY_IND:
            J2ME_asyn_table.notify_callback = NULL;
            break;

        case J2ME_HOST_NAME:
            J2ME_asyn_table.gethostbyname_callback = NULL;
            break;

        case J2ME_HOST_ADDR:
            J2ME_asyn_table.gethostbyaddr_callback = NULL;
            break;

        case J2ME_BEARER_INFO:
            J2ME_asyn_table.bearer_callback = NULL;
            break;

        default:
            kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
            break;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_get_errno
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int jnw_get_errno(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = net_errno;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_GET_ERRNO, result);
    net_errno = 0;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  process_soc_async_ind
 * DESCRIPTION
 *  Called by main while message loop of JDaemon to process incoming message from SOC
 * PARAMETERS
 *  ilm_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void process_soc_async_ind(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;
    kal_int32 handle = -1;
    kal_int16 dns_idx = -1;
    kal_bool in_blocked = KAL_FALSE;
    kal_bool suspend = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_APP_SOC_NOTIFY_IND:
        {
            app_soc_notify_ind_struct *ind_ptr = (app_soc_notify_ind_struct*) ilm_ptr->local_para_ptr;

            handle = ind_ptr->socket_id;
            EXT_ASSERT(handle < 31 && handle >= 0,0,0,0);
            /*for event arrive later than socket closing*/            
            if ((jnw_created_socket & (1<<handle)) == 0) 
            {                
                return;
            }

            /* if previous event is connect indication and not processed (by jnw), 
               we need to suspend process for a while */
            /* Otherwise, we will lose the indication. */
            if ((J2ME_setasyn_bitmap & (1 << handle)) &&
                (handle < J2ME_MAX_SOC_NUM))
            {
                if (J2ME_asnyc_ind[handle].event_type == SOC_CONNECT &&
                    (ind_ptr->event_type != SOC_CLOSE && ind_ptr->event_type != SOC_CONNECT))
                {
                    suspend = KAL_TRUE;
                }
            }

            /* add callback function */
            if (J2ME_asyn_table.notify_callback)
            {
                J2ME_asyn_table.notify_callback(ind_ptr);
            }
           
            if (ind_ptr->event_type == SOC_CLOSE && ind_ptr->error_cause == SOC_CONNRESET)
            {
                /* half close for write end" from server. 
                   This stands for "server won't send data to client anymore */
                return;
            }
            
        }
            break;

        case MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND:
        {
            app_soc_get_host_by_name_ind_struct *ind_ptr =
                (app_soc_get_host_by_name_ind_struct*) ilm_ptr->local_para_ptr;

            handle = 31;
            dns_idx = ind_ptr->request_id;
            
            if (g_dns_query_num > 0)
                g_dns_query_num--;
            /* add callback function */
            if (J2ME_asyn_table.gethostbyname_callback)
            {
                if (g_pcHostName[ind_ptr->request_id] != NULL)
                {
                    free_ctrl_buffer(g_pcHostName[ind_ptr->request_id]);
                    g_pcHostName[ind_ptr->request_id] = NULL;
                }
                J2ME_asyn_table.gethostbyname_callback(ind_ptr);

            }
            
        }
            break;

        case MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND:
        {
            app_soc_get_host_by_addr_ind_struct *ind_ptr =
                (app_soc_get_host_by_addr_ind_struct*) ilm_ptr->local_para_ptr;

            handle = 30;
            dns_idx = ind_ptr->request_id;

            if (g_dns_query_num > 0)
                g_dns_query_num--;
            /* add callback function */
            if (J2ME_asyn_table.gethostbyaddr_callback)
            {
                J2ME_asyn_table.gethostbyaddr_callback(ind_ptr);

            }
        }
            break;

        case MSG_ID_APP_CBM_BEARER_INFO_IND:
        {
            app_cbm_bearer_info_ind_struct *ind_ptr = (app_cbm_bearer_info_ind_struct*) ilm_ptr->local_para_ptr;

            if (ind_ptr->state == CBM_CSD_AUTO_DISC_TIMEOUT)
            {
                for (i = 0; i < J2ME_MAX_SOC_NUM; i++)
                {
                    if (jnw_created_socket & (1 << i))
                    {
                        /* close the socket */
                        jnw_socket_close(-1, i);
                    }
                }
            }
            else
            {
                for (i = 0; i < J2ME_MAX_APP_NUM; i++)
                {
                    if (ind_ptr->state == CBM_ACTIVATED)
                    {
                        if (j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN)
                        {
                            j2me_nwk_bearer_evt[i].wait_event = 0;
                        }
                    }
                    else if (ind_ptr->state == CBM_DEACTIVATED)
                    {
                        if (cbm_get_bearer_status(ind_ptr->account_id) == CBM_DEACTIVATED)
                        {
                            if (j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN)
                            {
                                j2me_nwk_bearer_evt[i].wait_event = JNW_NWK_EVT_CLOSE;
                            }    
                        }
                    }
                }
              
            }
            
            /* add callback function */
            if (J2ME_asyn_table.bearer_callback)
            {
                J2ME_asyn_table.bearer_callback(ind_ptr);

            }
           
            break;
        }
        default:
            ASSERT(0);
            break;
    }

    if (handle == -1)
    {
        return;
    }

    if (suspend)
    {
        /* if can use 2nd bitmap */
        /* If the corresponding bit of J2ME_blockedasyn_bitmap has not been set yet, 
           that is, we at most can record ONE un-process event. */
        if ((J2ME_blockedasyn_bitmap & (1 << handle)) == 0)
        {
            kal_take_mutex(g_jam_async_mutex);
            /* Set the corresponding handle bit ON. */
            J2ME_blockedasyn_bitmap |= (1 << handle);
            in_blocked = KAL_TRUE;
            kal_give_mutex(g_jam_async_mutex);
        }
        else
        {
            /* To avoid overwrite previous set connect indication */
            kal_uint32 sleep_tick = 0;

            do
            {
                kal_sleep_task(1);
                sleep_tick++;

                /* If corresponding handle bit of J2ME_setasyn_bitmap has been processed, 
                   or we have wait more than 20 ticks. */
                if ((J2ME_setasyn_bitmap & (1 << handle)) == 0 || sleep_tick > 20)
                {
                    break;
                }
            } while (1);
        }
    }

    kal_take_mutex(g_jam_async_mutex);

    /* Set the corresponding handle bit of J2ME_setasyn_bitmap ON. 
       But we have not record the result yet 
       (just record that there is an IND message for some handle). */
    if (handle >= 0 && handle < 30)
    {
        J2ME_setasyn_bitmap |= (1 << handle);
    }
    else if (handle >= 30)
    {
        J2ME_dns_setasyn_bitmap |= (1 << dns_idx);
    }

    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_APP_SOC_NOTIFY_IND:
        {
            app_soc_notify_ind_struct *ind_ptr = (app_soc_notify_ind_struct*) ilm_ptr->local_para_ptr;

        #ifdef MIDP_CONNECTION_DEBUG
            sprintf(
                _kvmLogStr,
                "soc indication type=%d, sockid=%d, res=%d error=%d %x %x\n",
                ind_ptr->event_type,
                ind_ptr->socket_id,
                ind_ptr->result,
                ind_ptr->error_cause,
                J2ME_setasyn_bitmap,
                J2ME_pendingasyn_bitmap);
            Kputs(_kvmLogStr);
        #endif /* MIDP_CONNECTION_DEBUG */ 

            if (handle < J2ME_MAX_SOC_NUM)
            {
                if (in_blocked)
                {
                    /* These is still ONE pending event, so we record the result in the J2ME_blockedasnyc_ind rather than J2ME_asnyc_ind. */
                    J2ME_blockedasnyc_ind[handle].event_type = ind_ptr->event_type;
                    J2ME_blockedasnyc_ind[handle].socket_id = ind_ptr->socket_id;
                    J2ME_blockedasnyc_ind[handle].result = ind_ptr->result;

                    /* I additionally record the following information. */
                    J2ME_blockedasnyc_ind[handle].error_cause = ind_ptr->error_cause;
                    J2ME_blockedasnyc_ind[handle].detail_cause = ind_ptr->detail_cause;
                }
                else
                {
                    /* No pending event, so we record the result in the J2ME_asnyc_ind directly. */
                    J2ME_asnyc_ind[handle].event_type = ind_ptr->event_type;
                    J2ME_asnyc_ind[handle].socket_id = ind_ptr->socket_id;
                    J2ME_asnyc_ind[handle].result = ind_ptr->result;

                    /* I additionally record the following information. */
                    J2ME_asnyc_ind[handle].error_cause = ind_ptr->error_cause;
                    J2ME_asnyc_ind[handle].detail_cause = ind_ptr->detail_cause;
                }
            }
        }
            break;

        case MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND:
        {
            /* Record the return structure first. */
            app_soc_get_host_by_name_ind_struct *ind_ptr =
                (app_soc_get_host_by_name_ind_struct*) ilm_ptr->local_para_ptr;

        #ifdef MIDP_CONNECTION_DEBUG
            sprintf(_kvmLogStr, "gethostbyname indication res=%d, addr_len=%d\n", ind_ptr->result, ind_ptr->addr_len);
            Kputs(_kvmLogStr);
        #endif /* MIDP_CONNECTION_DEBUG */ 

            /* use self-defined structure to save memory space */
            /* Record the result in the J2ME_async_ghbn_ind. */
            if (ind_ptr->request_id < J2ME_MAX_SOC_NUM)
            {
                J2ME_async_ghbn_ind[ind_ptr->request_id].result = ind_ptr->result;
                J2ME_async_ghbn_ind[ind_ptr->request_id].request_id = ind_ptr->request_id;
                J2ME_async_ghbn_ind[ind_ptr->request_id].access_id = ind_ptr->access_id;
                memcpy(J2ME_async_ghbn_ind[ind_ptr->request_id].addr, ind_ptr->addr, sizeof(ind_ptr->addr));
                J2ME_async_ghbn_ind[ind_ptr->request_id].addr_len = ind_ptr->addr_len;
                J2ME_async_ghbn_ind[ind_ptr->request_id].error_cause = ind_ptr->error_cause;
                J2ME_async_ghbn_ind[ind_ptr->request_id].detail_cause = ind_ptr->detail_cause;
            }

        }
            break;

        case MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND:
        {
            app_soc_get_host_by_addr_ind_struct *ind_ptr =
                (app_soc_get_host_by_addr_ind_struct*) ilm_ptr->local_para_ptr;

        #ifdef MIDP_CONNECTION_DEBUG
            sprintf(_kvmLogStr, "gethostbyaddress indication res=%d, name=%s\n", ind_ptr->result, ind_ptr->name);
            Kputs(_kvmLogStr);
        #endif /* MIDP_CONNECTION_DEBUG */ 

            /* use self-defined structure to save memory space */
            /* Record the result in the J2ME_async_ghbaddr_ind. */
            if (ind_ptr->request_id < J2ME_MAX_SOC_NUM)
            {
                J2ME_async_ghbaddr_ind[ind_ptr->request_id].result = ind_ptr->result;
                J2ME_async_ghbaddr_ind[ind_ptr->request_id].access_id = ind_ptr->access_id;
                J2ME_async_ghbaddr_ind[ind_ptr->request_id].request_id = ind_ptr->request_id;
                memcpy(J2ME_async_ghbaddr_ind[ind_ptr->request_id].name, ind_ptr->name, sizeof(ind_ptr->name));
            }

        }
            break;

        default:
            break;
    }
    kal_give_mutex(g_jam_async_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  readAsyncEvent
 * DESCRIPTION
 *  J2ME polling set event
 * PARAMETERS
 *  handle      [IN]        
 *  dns_idx     [IN]        
 *  protect     [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 readAsyncEvent(kal_int32 handle, kal_int32 dns_idx, kal_uint32 protect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 result = MSG_ID_APP_SOC_NOTIFY_IND;
    kal_uint32 tmp_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JNW_ENTER();
    if (protect)
    {
        kal_take_mutex(g_jam_async_mutex);
    }

    if (handle < 30)
    {
        if ((J2ME_setasyn_bitmap & (1 << handle)) == 0)
        {
            /* We have not received an corresponding bit IND yet. */
            result = IO_WOULDBLOCK;    /* IO_WOULDBLOCK */
        }
        else
        {
            /* no blocked handle indication */
            /* If there is NO pending IND, then we can clear the corresponding bit 
            of J2ME_setasyn_bitmap directly. */
            tmp_result = (J2ME_blockedasyn_bitmap & (1 << handle)); 
            if (tmp_result == 0)
            {
                /* Clear the corresponding handle bit. */
                J2ME_setasyn_bitmap &= ~(1 << handle);
            }
        }
    }
    else if (handle == 30 || handle == 31)
    {
        if ((J2ME_dns_setasyn_bitmap & (1 << dns_idx)) == 0)
        {
            /* We have not received an corresponding bit IND yet.*/
            result = IO_WOULDBLOCK;    /* IO_WOULDBLOCK */
        }
        else
        {
            if (handle == 31)
            {
                result = MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND;
            }
            else if (handle == 30)
            {
                result = MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND;
            }
            /* Clear the corresponding handle bit. */
            J2ME_dns_setasyn_bitmap &= ~(1 << dns_idx);
        }
    }

    if (protect)
    {
        kal_give_mutex(g_jam_async_mutex);
    }

    JNW_LEAVE(result);
}


/*****************************************************************************
 * FUNCTION
 *  socketCloseHandle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  int
 *****************************************************************************/
int socketCloseHandle(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_SOCKETCLOSEHANDLE, handle);
    jnw_created_socket &= (~(1 << handle));
    status = soc_close((kal_int8) handle);
    if (status != SOC_SUCCESS)
    {
        if (status == SOC_WOULDBLOCK)
        {
            return RESOUCE_NO_ERROR;
        }
        else
        {
            return RESOUCE_FAIL;
        }
    }

    return RESOUCE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  is_socket_activated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool is_socket_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_IS_SOCKET_ACTIVATED, _active_socket_count, j2me_socket_io_activated);
    JNW_ENTER();
    if (_active_socket_count != 0 || j2me_socket_io_activated)
    {
        JNW_LEAVE(KAL_TRUE);
    }
    else
    {
        JNW_LEAVE(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  j2me_deactivate_socket
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
kal_int32 j2me_deactivate_socket(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_DEACTIVATE_SOCKET, vm_id);
    socketDeactive(vm_id);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  socketDeactive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void socketDeactive(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (j2me_socket_io_activated)
    {
        j2me_socket_io_activated = KAL_FALSE;
        cbm_release_bearer(jam_get_app_id(vm_id));
        cbm_abort_app_bearer_event(jam_get_app_id(vm_id));
        soc_abort_dns_query(KAL_TRUE, MOD_JASYN_D, KAL_FALSE, 0, KAL_FALSE, 0, KAL_TRUE, 
        jam_mvm_get_account_id(vm_id));
        g_dns_query_num = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_getipnumber_byname
 * DESCRIPTION
 *  
 * PARAMETERS
 *  host        [IN]            Host name
 *  dns_idx     [IN/OUT]        Dns index
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_getipnumber_byname(int vm_id, char *host, int *dns_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 addr[16];
    kal_uint8 addr_len = 0;
    kal_int8 result;
    kal_bool need_ask_dns = KAL_TRUE;
    kal_uint32 i;
    kal_uint32 account_id;
    int ret;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_GETIPNUMBER_BYNAME, vm_id, host, *dns_idx);
    JNW_ENTER();
    /* important! use this comparison to block the case to connect CSD when 
       Java in paused mode or background running */
    if (jam_no_network_connection() && jam_is_in_background_long_time(vm_id))
    {
        JNW_LEAVE(IO_ERROR);
    }

    if (*dns_idx >= 0 &&
        *dns_idx < J2ME_MAX_SOC_NUM &&
        J2ME_async_ghbn_ind[*dns_idx].request_id == *dns_idx &&
        J2ME_async_ghbn_ind[*dns_idx].result)
    {
        memcpy(addr, J2ME_async_ghbn_ind[*dns_idx].addr, sizeof(addr));
        memset(&J2ME_async_ghbn_ind[*dns_idx], 0, 
        sizeof(j2me_soc_get_host_by_name_ind_struct));
        kal_trace(TRACE_GROUP_7, INFO_J2ME_JNW_DDDDD, addr[0], addr[1], addr[2], addr[3], *(int*)addr);
        JNW_LEAVE(*(int*)addr);
    }
    
    for (i = 0; host[i]; i++)
    {
        if (host[i] < '0' || host[i] > '9')
        {
            if (host[i] != '.')
            {
                need_ask_dns = KAL_TRUE;
                break;
            }
        }
    }

    if (host[i] == 0)
    {
        need_ask_dns = KAL_FALSE;
    }

    if (need_ask_dns)
    {
        /* obtain a unique dns request index */
        *dns_idx = jnw_socket_get_dns_idx();
        
        if (*dns_idx == IO_ERROR)
        {
            /* Over the socket limit */
            kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
            JNW_LEAVE(IO_ERROR);
        }
        
        account_id = jam_mvm_get_account_id(vm_id);;
        if (account_id == 255 || !cbm_is_account_valid(account_id))
        {
            kal_trace(TRACE_GROUP_7, INFO_J2ME_JNW_D, account_id);
            JNW_LEAVE(IO_ERROR);
        }


        if ((ret = jnw_socket_open_bearer(vm_id)) != IO_SUCCESS)
        {
            if (ret == IO_ERROR)
            {
                kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
                JNW_LEAVE(IO_ERROR);
            }
            else
            {
                /* not ready yet, polling later */
                JNW_LEAVE(IO_LIMIT_RESOURCE);
            }
        }
    
        /*Get account id from data account service, ask Ke for detail info*/
        jam_nw_mids_set_bearer_content(account_id, KAL_FALSE, vm_id);

        result = soc_gethostbyname(
                    KAL_FALSE, MOD_JASYN_D,
                    *dns_idx,   /* only indicate the request is by Java */
                    (const kal_char*)host, addr,
                    &addr_len, 0, account_id);
        
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, result);

        if (result == SOC_WOULDBLOCK)
        {
            if (g_pcHostName[*dns_idx] == NULL)
            {
                g_pcHostName[*dns_idx] = (char*)get_ctrl_buffer(strlen(host) + 1);
                strcpy(g_pcHostName[*dns_idx], host);
            }
            g_dns_query_num++;
            JNW_LEAVE(IO_WOULDBLOCK);
        }
        
        if (result == SOC_LIMIT_RESOURCE)
        {
            /* not ready yet, polling later */
            JNW_LEAVE(IO_LIMIT_RESOURCE);
        }
        /*SOC_ERROR will be processed below*/
    }
    else
    {
        /* Transfer ip string to ip addr directly */
        kal_uint8 ipdigit;
        kal_uint8 j = 0;

        /* Native layer only support IP4 */
        for (i = 0; host[i]; i++)
        {
            ipdigit = 0;
            for (; host[i] >= '0' && host[i] <= '9';)
            {
                ipdigit = ipdigit * 10 + (kal_uint8) host[i++] - '0';
            }

            if (j >= 4)
            {
                break;
            }
            addr[j++] = ipdigit;
        }

        addr_len = 4;
        result = SOC_SUCCESS;
    }

    addr[4] = 0;


    kal_trace(TRACE_GROUP_7, INFO_J2ME_JNW_DDDDD, addr[0], addr[1], addr[2], addr[3], result);
    
    /*Here ,Handle all case of SOC_ERROR*/
    if (result != SOC_SUCCESS)
    {
        net_errno = result;
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
        JNW_LEAVE(IO_ERROR);
    }

    JNW_LEAVE(*(int*)addr);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_open
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name            [IN]        
 *  port            [IN]        
 *  exception       [IN]        
 *  fd              [OUT]       
 *  dns_idx         [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_open_newsp(int vm_id, char *name, int port, int *exception, int *fd, int *dns_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sockaddr_struct addr;
    kal_int8 handle;
    kal_int8 result;
    kal_uint8 option;
    kal_int32 ipn;
    int ret;
    kal_uint32 account_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_OPEN_NEWSP, vm_id, name, port, *dns_idx);
    JNW_ENTER();
    ASSERT(vm_id < MAX_VM_INSTANCE_NUM);
    
    *exception = JNW_SOC_ERROR_DEFAULT;
    *fd = -1;

    account_id = jam_mvm_get_account_id(vm_id);
    /* check validity of account id */
    if (account_id == 255 || !cbm_is_account_valid(account_id))
    {
        kal_trace(TRACE_GROUP_7, INFO_J2ME_JNW_D, account_id);
        *exception = JNW_SOC_ERROR_OPEN_FAIL;
        JNW_LEAVE(IO_ERROR);
    }

    if (g_dns_query_num >= J2ME_MAX_DNS_NUM)
    {
        /* not availabe yet, polling later */
        JNW_LEAVE(IO_LIMIT_RESOURCE);
    }
    
    if ((ret = jnw_socket_open_bearer(vm_id)) != IO_SUCCESS)
    {
        if (ret == IO_ERROR)
        {
            kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
            *exception = JNW_SOC_ERROR_OPEN_FAIL;
            JNW_LEAVE(IO_ERROR);
        }
        /*VM vendor need re-invoke later*/
        JNW_LEAVE(IO_LIMIT_RESOURCE);
    }

    if (*dns_idx >= 0 &&
        *dns_idx < J2ME_MAX_SOC_NUM &&
        J2ME_async_ghbn_ind[*dns_idx].request_id == *dns_idx &&
        J2ME_async_ghbn_ind[*dns_idx].result)
    {
        /* we have received the dns result. Thus, we don't need to query the dns again */
        memcpy(&ipn, J2ME_async_ghbn_ind[*dns_idx].addr, sizeof(ipn));
        /* clear the dns result */
        memset(&J2ME_async_ghbn_ind[*dns_idx], 0, sizeof(j2me_soc_get_host_by_name_ind_struct));
        /*reset *dns_idx*/
        *dns_idx = -1;
    }
    else
    {
        *dns_idx = 0;
        ipn = jnw_socket_getipnumber_byname(vm_id, name, dns_idx);
       
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, ipn);
        if (ipn == IO_ERROR)
        {
            *exception = JNW_SOC_ERROR_GET_IP_FAIL;
            JNW_LEAVE(IO_ERROR);
        }
        else if ((ipn == IO_WOULDBLOCK) ||
                 (ipn == IO_LIMIT_RESOURCE))
        {
            /* Fix to deactivate context */
            j2me_socket_io_activated = KAL_TRUE;
            
            JNW_LEAVE(ipn);

        }
    }
    /*Get account id from data account service, ask Ke for detail info*/
    jam_nw_mids_set_bearer_content(account_id, KAL_FALSE, vm_id);

    handle = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_JASYN_D, account_id);

    if (handle < 0 || handle >= J2ME_MAX_SOC_NUM)
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, handle);
        net_errno = handle;
        *exception = JNW_SOC_ERROR_OPEN_FAIL;
        JNW_LEAVE(IO_ERROR);
    }
    
    jvm_resource_mgr_register(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_SOCKET_DEVICE, handle, NULL, NULL, &socketCloseHandle);
    j2me_socket_io_activated = KAL_TRUE;

    /* Clear async indication event */
    kal_take_mutex(g_jam_async_mutex);
    J2ME_setasyn_bitmap &= ~(1 << handle);
    J2ME_asnyc_ind[handle].event_type = 0;
    kal_give_mutex(g_jam_async_mutex);

    /* Record the created sockets */
    jnw_created_socket |= (1<<handle);

    /* Set ansync mode */
    option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
    result = soc_setsockopt(handle, SOC_ASYNC, &option, sizeof(kal_uint8));
    if (result != SOC_SUCCESS)
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D,result);
        jnw_created_socket &= (~(1 << handle));
        soc_close(handle);
        
        net_errno = result;
        *exception = JNW_SOC_ERROR_ARGUMENT;
        JNW_LEAVE(IO_ERROR);
    }

    option = KAL_TRUE;
    result = soc_setsockopt(handle, SOC_NBIO, &option, sizeof(option));

    if (result != SOC_SUCCESS)
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, result);
        jnw_created_socket &= (~(1 << handle));
        soc_close(handle);
        
        net_errno = result;
        *exception = JNW_SOC_ERROR_ARGUMENT;
        JNW_LEAVE(IO_ERROR);
    }

    addr.addr[0] = HADDR_0(ipn);
    addr.addr[1] = HADDR_1(ipn);
    addr.addr[2] = HADDR_2(ipn);
    addr.addr[3] = HADDR_3(ipn);

    addr.addr_len = sizeof(ipn);
    addr.port = (unsigned short)port;

    result = soc_connect((kal_int8) handle, &addr);

    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDDDD,
        addr.addr[0],addr.addr[1],addr.addr[2],addr.addr[3],result);

    if (result != SOC_SUCCESS)
    {
        if (result == SOC_WOULDBLOCK)
        {
            _active_socket_count++;
            *fd = handle;
            JNW_LEAVE(IO_WOULDBLOCK);
        }
        /*handle case of SOC_ERROR*/
        jnw_created_socket &= (~(1 << handle));
        soc_close(handle);
        
        net_errno = result;
        *exception = JNW_SOC_ERROR_CONNECT_FAIL;
        JNW_LEAVE(IO_ERROR);
    }

    /*soc_connect success*/
    *fd = handle;
    _active_socket_count++;
    JNW_LEAVE(handle);
}
/*****************************************************************************
 * FUNCTION
 *  jnw_socket_open
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name            [IN]        
 *  port            [IN]        
 *  exception       [IN]        
 *  fd              [OUT]       
 *  dns_idx         [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_open(int vm_id, char *name, int port, int *exception, int *fd, int *dns_idx)
{
    module_type module_id = kal_get_active_module_id();

    if (module_id == MOD_J2ME || module_id == MOD_J2ME_D)
    {
#ifdef USE_NEWSP_LOADJNI    

        return jnwSocketOpenNewSP(vm_id,name,port,exception,fd,dns_idx);
    
#endif
    }
    
    return jnw_socket_open_newsp(vm_id,name,port,exception,fd,dns_idx);

}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_recv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  p           [OUT]       
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_recv(int handle, char *p, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 recv_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_RECV, handle, len);
    JNW_ENTER();
    recv_len = soc_recv((kal_int8) handle, (kal_uint8*) p, len, 0);

    if (recv_len < 0)
    {
        net_errno = recv_len;

        if (recv_len == SOC_WOULDBLOCK)
        {
            JNW_LEAVE(IO_WOULDBLOCK);
        }
        else
        {
            /* It might be a SOC_BEARER_FAIL case, but currently we just return 
                   IO_INTERRUPTED and let Java level to throw proper exception. */        
            JNW_LEAVE(IO_INTERRUPTED);
        }
    }
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, recv_len);
    JNW_LEAVE(recv_len);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_available(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len;
    kal_int8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_AVAILABLE, handle);
    JNW_ENTER();
    result = soc_getsockopt((kal_int8) handle, SOC_NREAD, (kal_uint8*) & len, sizeof(len));

    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DD, handle, result);

    if (result != SOC_SUCCESS)
    {
        net_errno = result;
        JNW_LEAVE(0);
    }
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, len);
    JNW_LEAVE((int)len);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  p           [IN]        
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_send(int handle, char *p, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 write_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_SEND, handle, len);
    JNW_ENTER();
    write_len = soc_send((kal_int8) handle, (kal_uint8*) p, len, 0);

    if (write_len <= 0)
    {
        net_errno = write_len;

        if (write_len == SOC_WOULDBLOCK)
        {
            JNW_LEAVE(IO_WOULDBLOCK);
        }
        else
        {
            /* It might be a SOC_BEARER_FAIL case, but currently we just return 
                   IO_INTERRUPTED and let Java level to throw proper exception. */
            JNW_LEAVE(IO_INTERRUPTED);
        }
    }
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, write_len);
    JNW_LEAVE(write_len);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_shutdown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_socket_shutdown(int handle, int how)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_SHUTDOWN, handle,
                how&JNW_SOC_SHUT_RD, ((how&JNW_SOC_SHUT_WR)>>1));

    if (how & JNW_SOC_SHUT_RD)
    {
        soc_shutdown((kal_int8) handle, SHUT_RD);
    }

    if (how & JNW_SOC_SHUT_WR)
    {
        soc_shutdown((kal_int8) handle, SHUT_WR);
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_close(int vm_id, int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_CLOSE, vm_id, handle);
    jvm_resource_mgr_deregister(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_SOCKET_DEVICE,handle);
    result = soc_close((kal_int8) handle);

    if (result != SOC_SUCCESS)
    {
        net_errno = result;
        result = IO_ERROR;
    }
    else
    {   /* close sucessfully */
        _active_socket_count--;
        jnw_created_socket &= (~(1 << handle));
        
        if (_active_socket_count == 0)
        {
            j2me_socket_io_activated = KAL_FALSE;
            if (vm_id != -1)
            {
                cbm_abort_app_bearer_event(jam_get_app_id(vm_id));
            }
        }
    }
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, result);
    return (int)result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_serversocket_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  fd              [IN]         
 *  exception       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
int jnw_serversocket_open(int vm_id, int port, int *fd, int *exception)
{
#ifdef __JAVA_SUPPORT_SERVER_SOCKET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sockaddr_struct addr;
    kal_int8 handle, result;
    kal_uint8 option;
    kal_int8 ret;
    kal_uint32 account_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SERVERSOCKET_OPEN, vm_id, port);
    ASSERT(vm_id < MAX_VM_INSTANCE_NUM);
    JNW_ENTER();
    
    *exception = JNW_SOC_ERROR_DEFAULT;
    *fd = -1;
    /*get java saved data account to open bearer*/
    account_id = jam_mvm_get_account_id(vm_id);
    /* check validity of account id */
    if (account_id == 255 || !cbm_is_account_valid(account_id))
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, account_id);
        *exception = JNW_SOC_ERROR_OPEN_FAIL;
        JNW_LEAVE(IO_ERROR);
    }

    // Display always-ask screen
    if ((ret = jnw_socket_open_bearer(vm_id)) != IO_SUCCESS)
    {
        if (ret == IO_ERROR)
        {
            kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
            *exception = JNW_SOC_ERROR_OPEN_FAIL;
            //return IO_ERROR;
        }
        
        JNW_LEAVE(ret);
    }
    
    /*update data account,may be modified by "bearer switch", ask Ke Wang for detail info*/
    jam_nw_mids_set_bearer_content(account_id, KAL_FALSE, vm_id);

    handle = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0, MOD_JASYN_D, account_id);

    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DD, handle, port);

    if (handle < 0 || handle >= J2ME_MAX_SOC_NUM)
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, handle);
        net_errno = handle;
        *exception = JNW_SOC_ERROR_OPEN_FAIL;
        JNW_LEAVE(IO_ERROR);
    }

    //resouceRegistering(JAVA_IO_SOCKET_DEVICE, handle, NULL, NULL, &socketCloseHandle);    //20101104: changed resource manager for MVM
    jvm_resource_mgr_register(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_SOCKET_DEVICE, handle, NULL, NULL, &socketCloseHandle);

    /* Set async mode */
    option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
    result = soc_setsockopt(handle, SOC_ASYNC, &option, sizeof(kal_uint8));
    if (result != SOC_SUCCESS)
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, result);
        soc_close(handle);

        net_errno = result;
        *exception = JNW_SOC_ERROR_ARGUMENT;
        JNW_LEAVE(IO_ERROR);
    }
    
    option = KAL_TRUE;
    result = soc_setsockopt(handle, SOC_NBIO, &option, sizeof(option));
    if (result != SOC_SUCCESS)
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, result);
        soc_close(handle);

        net_errno = result;
        *exception = JNW_SOC_ERROR_ARGUMENT;
        JNW_LEAVE(IO_ERROR);
    }

    /* INADDR_ANY */
    addr.addr[0] = 0x00;
    addr.addr[1] = 0x00;
    addr.addr[2] = 0x00;
    addr.addr[3] = 0x00;

    addr.addr_len = sizeof(long);
    addr.port = (unsigned short)port;

    result = soc_bind((kal_int8) handle, &addr);

    if (result != SOC_SUCCESS)
    {
        soc_close(handle);
        net_errno = result;
        *exception = JNW_SOC_ERROR_OPEN_FAIL;
        return IO_ERROR;
    }
    result = soc_listen(handle, 5);

    if (result != SOC_SUCCESS)
        {
        soc_close(handle);
        net_errno = result;
        *exception = JNW_SOC_ERROR_OPEN_FAIL;
        JNW_LEAVE(IO_ERROR);
    }
    
    j2me_socket_io_activated = KAL_TRUE;
     _active_socket_count++;
    /* Record the created sockets */
    jnw_created_socket |= (1<<handle);
    *fd = handle;
    JNW_LEAVE(IO_SUCCESS);
        
#else /* __JAVA_SUPPORT_SERVER_SOCKET__ */
    *exception = JNW_SOC_ERROR_OPEN_FAIL;
    JNW_LEAVE(IO_ERROR);
#endif /* __JAVA_SUPPORT_SERVER_SOCKET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  jnw_serversocket_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_serversocket_accept(int handle)
{
#ifdef __JAVA_SUPPORT_SERVER_SOCKET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 result;
    sockaddr_struct addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SERVERSOCKET_ACCEPT, handle);
    JNW_ENTER();
    result = soc_accept((kal_int8) handle, &addr);
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDDDD, addr.addr[0], addr.addr[1], addr.addr[2], addr.addr[3], addr.port);
    
    if (result < 0)
    {
        net_errno = result;
        if (result == SOC_WOULDBLOCK)
        {
            JNW_LEAVE(IO_WOULDBLOCK);
        }
        else
        {
            JNW_LEAVE(IO_ERROR);
        }
    }
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DD, handle, result);
    JNW_LEAVE((int)result);
#else /* __JAVA_SUPPORT_SERVER_SOCKET__ */
    JNW_LEAVE(IO_ERROR);
#endif /* __JAVA_SUPPORT_SERVER_SOCKET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jnw_serversocket_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_serversocket_close(int vm_id, int handle)
{
#ifdef __JAVA_SUPPORT_SERVER_SOCKET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SERVERSOCKET_CLOSE, vm_id, handle);
    return jnw_socket_close(vm_id, handle);
#else /* __JAVA_SUPPORT_SERVER_SOCKET__ */
    return IO_ERROR;
#endif /* !__JAVA_SUPPORT_SERVER_SOCKET__ */
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_getsockopt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  flag            [IN]        
 *  optval          [IN]        
 *  exception       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_getsockopt(int handle, int flag, int *optval, int *exception)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 result;
    kal_uint16 option;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_GETSOCKOPT, handle, flag);
    JNW_ENTER();
    switch (flag)
    {
        case 1: /* LINGER */
        {
            soc_linger_struct linger_val;

            option = SOC_LINGER;
            result = soc_getsockopt((kal_int8) handle, option, (kal_uint8*) & linger_val, sizeof(soc_linger_struct));
            if (linger_val.onoff)
            {
                *optval = linger_val.linger_time;
            }
            else
            {
                *optval = 0;
            }

            break;
        }
        case 0: /* DELAY */
        {
            kal_bool nodelay_val = KAL_FALSE;

            option = SOC_NODELAY;
            result = soc_getsockopt((kal_int8) handle, option, (kal_uint8*) & nodelay_val, sizeof(kal_bool));
            *optval = !nodelay_val;

            break;
        }
        case 2: /* KEEPALIVE */
        {
            kal_bool keepalive_val = KAL_FALSE;

            option = SOC_KEEPALIVE;
            result = soc_getsockopt((kal_int8) handle, option, (kal_uint8*) & keepalive_val, sizeof(kal_bool));
            *optval = keepalive_val;

            break;
        }
        case 3: /* RCVBUF */
        {
            option = SOC_RCVBUF;
            result = soc_getsockopt((kal_int8) handle, option, (kal_uint8*) optval, sizeof(kal_int32));
            break;
        }
        case 4: /* SNDBUF */
        {
            option = SOC_SENDBUF;
            result = soc_getsockopt((kal_int8) handle, option, (kal_uint8*) optval, sizeof(kal_int32));
            break;
        }
        default:    /* IllegalArgumentException */
            *exception = JNW_SOC_ERROR_ARGUMENT;
            result = IO_ERROR;
    }

    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DD, *optval, result);

    if (result == SOC_SUCCESS)
    {
        JNW_LEAVE(IO_SUCCESS);
    }
    else
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
        net_errno = result;
        *exception = JNW_SOC_ERROR_ARGUMENT;
        JNW_LEAVE(IO_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_setsockopt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  flag            [IN]        
 *  optval          [IN]        
 *  exception       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_setsockopt(int handle, int flag, int optval, int *exception)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 result;
    kal_uint16 option = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_SETSOCKOPT, handle, flag, optval);
    *exception = JNW_SOC_ERROR_DEFAULT;
    JNW_ENTER();
    switch (flag)
    {
        case 1: /* LINGER */
        {
            soc_linger_struct linger_val;

            option = SOC_LINGER;
            linger_val.onoff = KAL_TRUE;
            linger_val.linger_time = optval;

            result = soc_setsockopt((kal_int8) handle, option, (kal_uint8*) & linger_val, sizeof(soc_linger_struct));
            break;
        }
        case 0: /* DELAY */
        {

            kal_bool nodelay_val = KAL_FALSE;

            option = SOC_NODELAY;
            if (!optval)
            {
                nodelay_val = KAL_TRUE;
            }

            result = soc_setsockopt((kal_int8) handle, option, (kal_uint8*) & nodelay_val, sizeof(kal_bool));
            break;
        }
        case 2: /* KEEPALIVE */
        {
            kal_bool keepalive_val = KAL_FALSE;

            option = SOC_KEEPALIVE;
            if (optval)
            {
                keepalive_val = KAL_TRUE;
            }

            result = soc_setsockopt((kal_int8) handle, option, (kal_uint8*) & keepalive_val, sizeof(kal_bool));
            break;
        }
        case 3: /* RCVBUF */
        {
            option = SOC_RCVBUF;
            result = soc_setsockopt((kal_int8) handle, option, (kal_uint8*) & optval, sizeof(kal_int32));
            break;
        }
        case 4: /* SNDBUF */
        {
            option = SOC_SENDBUF;
            result = soc_setsockopt((kal_int8) handle, option, (kal_uint8*) & optval, sizeof(kal_int32));
            break;
        }
        default:    /* IllegalArgumentException */
            *exception = JNW_SOC_ERROR_ARGUMENT;
            result = IO_ERROR;
    }
    
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, result);
    if (result == SOC_SUCCESS)
    {
        JNW_LEAVE(IO_SUCCESS);
    }
    else
    {
        kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
        net_errno = result;
        *exception = JNW_SOC_ERROR_ARGUMENT;
        JNW_LEAVE(IO_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_getipnumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  local       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *jnw_socket_getipnumber(int handle, int local)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Only support IP4 */
    static kal_int8 ipnumber[16];
    kal_int8 result;
    sockaddr_struct addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_GETIPNUMBER, handle, local);
    JNW_ENTER();
    result = soc_getsockaddr((kal_int8) handle, local ? KAL_TRUE : KAL_FALSE, &addr);

    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDDDD, addr.addr[0], addr.addr[1], addr.addr[2], 
              addr.addr[3], result);

    if (result != SOC_SUCCESS)
    {
        net_errno = result;
        JNW_LEAVE(NULL);
    }

    /* Only support IP4 */
    sprintf(ipnumber, "%d.%d.%d.%d", addr.addr[0], addr.addr[1], addr.addr[2], addr.addr[3]);

    JNW_LEAVE(ipnumber);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_getport
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  local       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_socket_getport(int handle, int local)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 result;
    sockaddr_struct addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_GETPORT, handle, local);
    JNW_ENTER();
    result = soc_getsockaddr((kal_int8) handle, local ? KAL_TRUE : KAL_FALSE, &addr);

    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, result);

    if (result != SOC_SUCCESS)
    {
        net_errno = result;
        JNW_LEAVE(IO_ERROR);
    }

    JNW_LEAVE((int)addr.port);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_getlocaladdress_string
 * DESCRIPTION
 *  fd   [IN]   socket id
 * PARAMETERS
 *  fd      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *jnw_getlocaladdress_string(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 ip[4];
    kal_int8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_GETLOCALADDRESS_STRING, handle);
    JNW_ENTER();
    result = soc_get_account_localip((kal_int8)handle, ip);

    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDDDD, ip[0], ip[1], ip[2], ip[3], result);

    if (result != SOC_SUCCESS)
    {
        net_errno = result;
        JNW_LEAVE(NULL);
    }

    JNW_LEAVE((char*)ip);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_socket_open_bearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_socket_open_bearer(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_uint32 account_id;
    kal_int8 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_SOCKET_OPEN_BEARER, vm_id);
    JNW_ENTER();
    account_id = jam_mvm_get_account_id(vm_id);
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, account_id);
    if (cbm_get_bearer_status(account_id) == CBM_ACTIVATED)
    {
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            if (j2me_nwk_bearer_evt[i].app_id == vm_id)
            {
                j2me_nwk_bearer_evt[i].app_id = -1;
                j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
                j2me_nwk_bearer_evt[i].wait_event = 0;
            }
        }                
        JNW_LEAVE(IO_SUCCESS);
    }
    else
    {
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            if (j2me_nwk_bearer_evt[i].app_id == vm_id)
            {
                if ((j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN) ||
                    (j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_CLOSE))
                {
                    break;
                }
            }
        }
        if (i < J2ME_MAX_APP_NUM)
        {
            if (j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN)
            {
                kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDD, 7, account_id, 0);
                JNW_LEAVE(IO_WOULDBLOCK);
            }
            else
            {
                kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDD, 8, account_id, 0);
                j2me_nwk_bearer_evt[i].app_id = -1;
                j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
                j2me_nwk_bearer_evt[i].wait_event = 0;
                JNW_LEAVE(IO_ERROR);
            }
        }
        else
        {
            for (i = 0; i < J2ME_MAX_APP_NUM; i++)
            {
                if (j2me_nwk_bearer_evt[i].app_id == -1)
                {
                        
                    /* bearer is not activated yet */
                    j2me_nwk_bearer_evt[i].app_id = vm_id;
                    j2me_nwk_bearer_evt[i].account_id = account_id;
                    j2me_nwk_bearer_evt[i].wait_event = JNW_NWK_EVT_OPEN;
                   
                    ret = cbm_open_bearer(account_id);
                    if (ret == CBM_WOULDBLOCK)
                    {
                        kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDD, 9, account_id, ret);
                        JNW_LEAVE(IO_WOULDBLOCK);
                    }
                    
                    j2me_nwk_bearer_evt[i].app_id = -1;
                    j2me_nwk_bearer_evt[i].wait_event = 0;
                    j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
                    if(ret != CBM_OK)
                    {
                        kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDD, 10, account_id, ret);
                        JNW_LEAVE(IO_ERROR);
                    }
                    else
                    {
                        JNW_LEAVE(IO_SUCCESS);
                    }
                    
                }
            }
        }
    }
    JNW_LEAVE(IO_ERROR);
}

/*****************************************************************************
 * FUNCTION
 *  _jnw_process_soc_async_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 _jnw_process_soc_async_event(soc_event_enum event, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 event_type;
    kal_bool result;

    /* I add the following variables to record the SOC error cause. */
    /*kal_int8 l_i1ErrorCause = 0;*/

    /* kal_int32 l_i4DetailCause = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_PROCESS_SOC_ASYNC_EVENT, event, handle);
    JNW_ENTER();
    /* Block to wait previous pending request complete */
    /* Only this function will set/modify this variable. 
       return IO_WOULDBLOCK directly when:
       1. There is some other handle pending there. 
       &&
       2. The currently polling handle is not at pending state. */
    if (J2ME_pendingasyn_bitmap != 0 && (J2ME_pendingasyn_bitmap & (1 << handle)) == 0)
    {
        JNW_LEAVE(IO_WOULDBLOCK);
    }

    kal_take_mutex(g_jam_async_mutex);
    {
        if (readAsyncEvent(handle, -1, KAL_FALSE) == IO_WOULDBLOCK)
        {
            /* Set the corresponding handle bit ON in J2ME_pendingasyn_bitmap. */
            J2ME_pendingasyn_bitmap |= (1 << handle);
            kal_give_mutex(g_jam_async_mutex);

            JNW_LEAVE(IO_WOULDBLOCK);
        }

        /* If we have received the corresponding handle bit IND, 
           clear the corresponding handle bit in 
           J2ME_pendingasyn_bitmap (no matter we have set it before). */
        J2ME_pendingasyn_bitmap &= ~(1 << handle);

        /* Retrieve the result from corresponding handle column of J2ME_asnyc_ind. */
        event_type = J2ME_asnyc_ind[handle].event_type;
        J2ME_asnyc_ind[handle].event_type = 0;

        /* Note that if the result is false, we should further check the error cause 
           to see whether it need Bearer Fallback or not. */
        result = J2ME_asnyc_ind[handle].result;

        /*l_i1ErrorCause = J2ME_asnyc_ind[handle].error_cause;*/
        /* l_i4DetailCause = J2ME_asnyc_ind[handle].detail_cause; */

        /* If have blocked handle indication, copy from blocked indication */
        if (J2ME_blockedasyn_bitmap & (1 << handle))
        {
            /* Copy the IND result from blocked structure to current structure. */
            memcpy(&J2ME_asnyc_ind[handle], &J2ME_blockedasnyc_ind[handle], sizeof(j2me_soc_notify_ind_struct));

            /* Clear the corresponding handle bit of J2ME_blockedasyn_bitmap. */
            J2ME_blockedasyn_bitmap &= ~(1 << handle);
        }
    }
    kal_give_mutex(g_jam_async_mutex);

    /* Pre-check close */
    if (event_type == SOC_CLOSE)
    {

    #ifdef MIDP_CONNECTION_DEBUG
        sprintf(
            _kvmLogStr,
            "J2ME Error: socket connection broken %d %x %x",
            handle,
            J2ME_setasyn_bitmap,
            J2ME_pendingasyn_bitmap);
        Kputs(_kvmLogStr);
    #endif /* MIDP_CONNECTION_DEBUG */ 

        JNW_LEAVE(IO_ERROR);
    }

    if (event_type != event)
    {
        /* Not our currently polling event. Return IO_WOULDBLOCK directly. */

    #ifdef MIDP_CONNECTION_DEBUG
        sprintf(
            _kvmLogStr,
            "J2ME Waring: drop event (socket%d, %d) %x, %x",
            handle,
            event_type,
            J2ME_setasyn_bitmap,
            J2ME_pendingasyn_bitmap);
        Kputs(_kvmLogStr);
    #endif /* MIDP_CONNECTION_DEBUG */ 

        JNW_LEAVE(IO_WOULDBLOCK);
    }

    /* It is our currently polling event. Return result directly (OK or ERROR). */
    if (result == KAL_TRUE)
    {
        JNW_LEAVE(IO_SUCCESS);
    }
    else
    {
        JNW_LEAVE(IO_ERROR);
    }
}


void _jnw_socket_enter(kal_char *file, kal_uint32 line)
{
    kal_trace(TRACE_GROUP_7, INFO_J2ME_JNW_SOCKET_ENTER, line);
}


void _jnw_socket_leave(kal_char *file, kal_uint32 line)
{
    kal_trace(TRACE_GROUP_7, INFO_J2ME_JNW_SOCKET_LEAVE, line);
}
