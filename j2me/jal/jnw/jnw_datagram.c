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
 *   jnw_datagram.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   datagram connection machine dependent API
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include files
*************************************************************************/

#if !defined(__MTK_TARGET__)
/* mdi_datatype.h include MMIDataType.h which conflict with soc_api.h  */
#include "Windows.h"
#endif /* !defined(__MTK_TARGET__) */ 

#include "jal.h"
#include "jam_internal.h"
#include "jnw_internal.h"
#include "jvm_adaptor.h"
#include "jvm_resource_manager.h"   //20101104,change resource mgr for MVM
#include "jam_mvm_manager.h"

#include "app2soc_struct.h"
#include "soc_api.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include <stdlib.h>
#include <string.h>

/* Network */
#include "cbm_api.h"
#include "soc_api.h"
#include "soc2tcpip_struct.h"

#include "cbmSrvGprot.h"
#include "Dtcntsrvgprot.h"

#ifndef J2ME_SLIM_MEMORY_SUPPORT
    #define MIDP_CONNECTION_DEBUG
#endif


/*************************************************************************
 * External Declaration
*************************************************************************/
extern int _active_socket_count;
extern int net_errno;
extern kal_uint32 jnw_created_socket;
extern kal_bool j2me_socket_io_activated;
extern kal_uint8 g_dns_query_num;

extern int jnw_get_errno(void);
extern j2me_soc_get_host_by_addr_ind_struct J2ME_async_ghbaddr_ind[];
extern char *g_pcHostName[J2ME_MAX_SOC_NUM];
extern int socketCloseHandle(int handle);
extern j2me_soc_notify_ind_struct J2ME_asnyc_ind[];

extern kal_int32 readAsyncEvent(kal_int32 handle, kal_int32 dns_idx, kal_uint32 protect);
extern kal_int8 jnw_socket_open_bearer(kal_int32 vm_id);

/*************************************************************************
 * Function Definition
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  _jnw_datagram_gethost_byaddress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dns_idx     [IN]        Dns index
 * RETURNS
 *  result
 *****************************************************************************/
int _jnw_datagram_gethost_byaddress(int dns_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME__JNW_DATAGRAM_GETHOST_BYADDRESS, dns_idx);
    JNW_ENTER();
    
    while (readAsyncEvent(30, dns_idx, KAL_TRUE) != MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND)
    {
        JNW_LEAVE(IO_WOULDBLOCK);
    }

    if (NULL != g_pcHostName[dns_idx])
    {
        free_ctrl_buffer(g_pcHostName[dns_idx]);
        g_pcHostName[dns_idx] = NULL;
    }
    if (J2ME_async_ghbaddr_ind[dns_idx].result == KAL_TRUE)
    {
        JNW_LEAVE(IO_SUCCESS);
    }
    else
    {
        JNW_LEAVE(IO_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _jnw_datagram_set_nonblocking
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void _jnw_datagram_set_nonblocking(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool falsebuf = KAL_TRUE;
    kal_int8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_DATAGRAM_SET_NONBLOCKING, handle);
    ret = soc_setsockopt((kal_int8) handle, SOC_NBIO, (kal_uint8*) & falsebuf, sizeof(kal_bool));
	kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, ret);

    if (ret != SOC_SUCCESS)
    {
        net_errno = ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_datagram_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  exception       [OUT]       
 * RETURNS
 *  int
 *****************************************************************************/
int jnw_datagram_open(int vm_id, int port, int *exception)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sockaddr_struct addr;
    kal_int8 handle;
    kal_int8 ret;
    kal_uint8 option;
	kal_uint32 account_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_INFO, FUNC_J2ME_JNW_DATAGRAM_OPEN, vm_id, port);
    JNW_ENTER();
    ASSERT(vm_id < MAX_VM_INSTANCE_NUM);
    *exception = JNW_SOC_ERROR_DEFAULT;
	account_id = jam_mvm_get_account_id(vm_id);
    if (account_id == 255 || !cbm_is_account_valid(account_id))
    {
   		kal_trace(TRACE_FUNC, INFO_J2ME_JNW_D, account_id);
        JNW_LEAVE(IO_ERROR);
    }
   
    handle = soc_create(SOC_PF_INET, SOC_SOCK_DGRAM, 0, MOD_JASYN_D, account_id);
    if (handle < 0)
    {
		kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, handle);
        net_errno = handle;
		*exception = JNW_SOC_ERROR_OPEN_FAIL;
        JNW_LEAVE(IO_ERROR);
    }
    J2ME_asnyc_ind[handle].error_cause = 0;
    jvm_resource_mgr_register(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_DATAGRAM_DEVICE, handle, NULL, NULL, &socketCloseHandle);
    j2me_socket_io_activated = KAL_TRUE;
    /* Record the created sockets */
    jnw_created_socket |= (1<<handle);

    /* Set ansync mode */
    option = SOC_READ | SOC_WRITE | SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
    ret = soc_setsockopt(handle, SOC_ASYNC, &option, sizeof(kal_uint8));
    if (ret != SOC_SUCCESS)
    {
		kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, ret);
        soc_close(handle);
		net_errno = ret;
        *exception = JNW_SOC_ERROR_ARGUMENT;
        JNW_LEAVE(IO_ERROR);
    }

    if (port > 0)
    {
         /* INADDR_ANY */
        addr.addr[0] = 0x00;
        addr.addr[1] = 0x00;
        addr.addr[2] = 0x00;
        addr.addr[3] = 0x00;

        addr.addr_len = sizeof(long);
        addr.port = (unsigned short)port;

        ret = soc_bind((kal_int8) handle, &addr);
        if (ret != SOC_SUCCESS)
        {
            kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
			kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDD, handle, addr.port, ret);
            soc_close(handle);

			net_errno = ret;
            *exception = JNW_SOC_ERROR_ARGUMENT;
            JNW_LEAVE(IO_ERROR);
        }
    }

    _active_socket_count++;
	kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, handle);
    JNW_LEAVE(handle);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_datagram_get_packetsize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_datagram_get_packetsize(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len;
    kal_int8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_DATAGRAM_GET_PACCKETSIZE, handle);
    JNW_ENTER();
    ret = soc_getsockopt((kal_int8) handle, SOC_PKT_SIZE, (kal_uint8*) & len, sizeof(len));

    if (ret != SOC_SUCCESS)
    {
   		kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
   		kal_trace(TRACE_INFO, INFO_J2ME_JNW_DD, handle, ret);
        net_errno = ret;
        JNW_LEAVE(0);
    }
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, len);
    JNW_LEAVE(len);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_datagram_gethost_byaddress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ipn         [IN]        
 *  host        [OUT]       
 *  dns_idx     [OUT]       
 * RETURNS
 *  int
 *****************************************************************************/
int jnw_datagram_gethost_byaddress(int vm_id, int ipn, char *host, int len, int *dns_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result;
	kal_uint32 account_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_DATAGRAM_GETHOST_BYADDRESS, vm_id, ipn, len);
    ASSERT(vm_id < MAX_VM_INSTANCE_NUM);
    JNW_ENTER();

    if ((jam_no_network_connection() && jam_is_in_background_long_time(vm_id)))
    {
        JNW_LEAVE(IO_ERROR);
    }
	
    if (*dns_idx >= 0 &&
		*dns_idx < J2ME_MAX_SOC_NUM &&
        J2ME_async_ghbaddr_ind[*dns_idx].request_id == *dns_idx &&
        J2ME_async_ghbaddr_ind[*dns_idx].result)
    {
        /* we have received the dns result. Thus, we don't need to query the dns again */
        memcpy(host, J2ME_async_ghbaddr_ind[*dns_idx].name, sizeof(J2ME_async_ghbaddr_ind[*dns_idx].name));
        /* clear the dns result */
        memset(&J2ME_async_ghbaddr_ind[*dns_idx], 0, sizeof(j2me_soc_get_host_by_addr_ind_struct));		
		JNW_LEAVE(IO_SUCCESS);
    }
	
	/* obtain a unique dns request index */
	*dns_idx = jnw_socket_get_dns_idx();
	if (*dns_idx == IO_ERROR)
	{
		kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
		JNW_LEAVE(IO_ERROR);
	}
	account_id = jam_mvm_get_account_id(vm_id);
    if (account_id == 255 || !cbm_is_account_valid(account_id))
    {
   		kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, account_id);
        JNW_LEAVE(IO_ERROR);
	}
    result = soc_gethostbyaddr(
                KAL_FALSE, MOD_JASYN_D,
                *dns_idx, host, /* only indicate the request is by Java */
                (kal_uint32 *)&len,
                (const kal_uint8*)&ipn,
                4, 0,account_id);
	if (result < 0)
	{
	    if (result == SOC_WOULDBLOCK) 
	    {
	        if(g_pcHostName[*dns_idx] == NULL)
		    {
				g_pcHostName[*dns_idx] = (char*)get_ctrl_buffer(sizeof(ipn));
				memcpy(g_pcHostName[*dns_idx], &ipn, sizeof(ipn));
		    }		
			g_dns_query_num++;
			JNW_LEAVE(IO_WOULDBLOCK);
	    }
	    else if(result == SOC_LIMIT_RESOURCE)
	    {
	    	JNW_LEAVE(IO_LIMIT_RESOURCE);
	    }
		JNW_LEAVE(IO_ERROR);
	}
 	JNW_LEAVE(IO_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_datagram_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  ipnumber        [IN]        
 *  port            [IN]        
 *  buffer          [IN]        
 *  length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_datagram_send(int vm_id, int handle, int ipnumber, int port, char *buffer, int length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 write_len;
    sockaddr_struct addr;
    int ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_DATAGRAM_SEND, vm_id, handle, ipnumber, port, length);
	JNW_ENTER();

    addr.addr[0] = HADDR_3(ipnumber);
    addr.addr[1] = HADDR_2(ipnumber);
    addr.addr[2] = HADDR_1(ipnumber);
    addr.addr[3] = HADDR_0(ipnumber);

    addr.addr_len = sizeof(ipnumber);
    addr.port = (kal_uint16) port;
    if (J2ME_asnyc_ind[handle].error_cause < 0)
    {
        JNW_LEAVE(IO_ERROR);
    }
    if ((ret = jnw_socket_open_bearer(vm_id)) != IO_SUCCESS)
    {
        if (ret == IO_ERROR)
        {
            kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
            JNW_LEAVE(IO_ERROR);
        }
        /* not ready yet, polling later */
        JNW_LEAVE(IO_WOULDBLOCK);
    }
    
    write_len = soc_sendto((kal_int8) handle, (kal_uint8*) buffer, length, 0, &addr);

    if (write_len <= 0)
    {
        if (write_len == SOC_WOULDBLOCK)
        {
            JNW_LEAVE(IO_WOULDBLOCK);
        }
        JNW_LEAVE(IO_INTERRUPTED);
    }	
	kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, write_len);
    JNW_LEAVE(write_len);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_datagram_recv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  ipnumber       [OUT]       
 *  port             [OUT]       
 *  buffer           [OUT]       
 *  length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_datagram_recv(int vm_id, int handle, int *ipnumber, int *port, char *buffer, int length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 recv_len;
    sockaddr_struct addr;
    int i;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_7, FUNC_J2ME_JNW_DATAGRAM_RECV, vm_id, handle, length);
	JNW_ENTER();

    if (J2ME_asnyc_ind[handle].error_cause < 0)
    {
        JNW_LEAVE(IO_ERROR);
    }
    
    if ((ret = jnw_socket_open_bearer(vm_id)) != IO_SUCCESS)
    {
        if (ret == IO_ERROR)
        {
			kal_trace(TRACE_INFO, INFO_J2ME_JNW_MARKER_FAIL);
            JNW_LEAVE(IO_ERROR);
        }
		JNW_LEAVE(IO_WOULDBLOCK);
    }
    
    recv_len = soc_recvfrom((kal_int8) handle, (kal_uint8*) buffer, length, 0, &addr);

    if (recv_len <= 0)
    {
        net_errno = recv_len;
        if (recv_len == SOC_WOULDBLOCK)
        {
            JNW_LEAVE(IO_WOULDBLOCK);
        }

        JNW_LEAVE(IO_INTERRUPTED);
    }

    *ipnumber = 0;
	
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_D, recv_len);
    kal_trace(TRACE_INFO, INFO_J2ME_JNW_DDDDD, addr.addr[0],addr.addr[1],addr.addr[2],addr.addr[3], (int)addr.port);

    for (i = 0 ; i < addr.addr_len ; i++)
    {
        *ipnumber = (*ipnumber << 8) + addr.addr[i];
    }
    *port = (int)addr.port;

    JNW_LEAVE(recv_len);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_datagram_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_datagram_close(int vm_id, int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_resource_mgr_deregister(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_DATAGRAM_DEVICE,handle);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jnw_socket_close(vm_id, handle);
}

