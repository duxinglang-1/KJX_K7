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
 * Jvm_debug.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define constances and enum values
 *   of JAL invocation by virtual com port related routines.
 *
 * Author:
 * -------
 * 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#define ENABLE_JAVA_DEBUGGER_LOG      (0)
#ifdef KDWP_DEBUG 

#include "jvm_interface.h"
#include "jam_internal.h"

kal_uint32 g_jvm_debug_comm_port = 0;
kal_uint32 g_jvm_debug_comm_baudRate = 9600;
kal_uint32 g_jvm_debug_comm_options = (0x20 | 0x10 | 0xC0);
kal_int32 g_jvm_debug_mode = JVM_DEBUG_NONE;
kal_int32 g_jvm_debug_port_connetion = 0;
kal_bool debuggerActive;
kal_int32 _debugger_active;

#define JAVA_DEBUG_BUF_LEN 							(512)
#define DBG_INC_POS(v, len)							(((v)+(len)) % JAVA_DEBUG_BUF_LEN)
#define DBG_INC_WRITER(len)							DBG_INC_POS(dbg_recv_writer, len)
#define DBG_INC_READER(len)							DBG_INC_POS(dbg_recv_reader, len)

static kal_uint32 dbg_recv_buf[JAVA_DEBUG_BUF_LEN/sizeof(kal_uint32)];
static kal_int32 dbg_recv_reader;
static kal_int32 dbg_recv_writer;
static kal_mutexid dbg_mutex;
kal_int32 dbg_recv_size;

extern kal_bool tst_java_debug_mode;
extern kal_bool tst_java_debug_hooked;
extern kal_eventgrpid  tst_event_group;

extern kal_bool j2me_dbg_recv_put(void* buf, kal_uint32 len);
extern kal_bool tst_kdwp_send(const kal_uint8 *pData, kal_uint32 nLen, kal_bool bEnd);

#ifdef ENABLE_JAVA_DEBUGGER_LOG
kal_int32 KDWP_log_handle = 0;
#endif

/****************************************************************************
 * FUNCTION
 *  jvm_debug_read_from_comm
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
void jvm_debug_read_from_comm(kal_int32 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 buffer[20];
    kal_int32 recv;
    kal_int32 loop_count;
    kal_char error[50];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jvm_debug_mode != JVM_DEBUG_COMM && g_jvm_debug_mode != JVM_DEBUG_COMM_MODIS)
    {
        return;
    }

    loop_count = 0;
    while (1) 
    {
        if (g_jvm_debug_mode == JVM_DEBUG_COMM)
        {
            recv = jam_comm_getbytes(port, buffer, 20);
        }
        /*
        else
        {
            recv = readFromPort(&error,g_jvm_debug_port_connetion,buffer,20);
        }
        */

        if(recv <= 0)
        {
            return;	
        }
        else
        {
            j2me_dbg_recv_put(buffer,recv);
        }
	    if (loop_count++ >= 20)
        {   
            break;
        }
    }
    /* resend message to itself */
}

/****************************************************************************
 * FUNCTION
 *  jvm_debug_write_to_comm
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
kal_bool jvm_debug_write_to_comm(const kal_uint8 *pData, kal_uint32 nLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char error[50];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int i = 0;
	kal_uint16 total_send = 0;
	kal_uint32 event_group;
	
    while (total_send < nLen) 
    {
        if (g_jvm_debug_mode == JVM_DEBUG_COMM)
        {
    	    i = jam_comm_putbytes(g_jvm_debug_port_connetion, (kal_uint8*)(&pData[total_send]), 
    							   (kal_uint16)(nLen-total_send));
        }
        /*
        else
        {
            i = writeToPort(&error,g_jvm_debug_port_connetion,&pData[total_send],(nLen-total_send));
        }
        */
    	if(i < 0)
        {   
    		return KAL_FALSE;
        }
    	total_send += i;
    	
    	if (i < (nLen-total_send))
        {
            kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_COMM_WRITE, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        }
    }
    
    if (total_send == nLen)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/****************************************************************************
 * FUNCTION
 *  jvm_debug_send
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
kal_bool jvm_debug_send(const kal_uint8 *pData, kal_uint32 nLen, kal_bool bEnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef ENABLE_JAVA_DEBUGGER_LOG
    kal_uint32 written;
    #endif
    char error[50];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef ENABLE_JAVA_DEBUGGER_LOG
    FS_Write(KDWP_log_handle, "send1:", 6, &written);
    FS_Write(KDWP_log_handle, (kal_uint8*)pData, nLen, &written);
    FS_Write(KDWP_log_handle, "send2:", 6, &written);
    FS_Commit(KDWP_log_handle);
    #endif
    if (g_jvm_debug_mode == JVM_DEBUG_CATCHER)
    {
        return tst_kdwp_send(pData, nLen, bEnd);
    }
    else if (g_jvm_debug_mode == JVM_DEBUG_COMM || g_jvm_debug_mode == JVM_DEBUG_COMM_MODIS)
    {
        return jvm_debug_write_to_comm(pData,nLen);
    }
    else
    {
    }
}

/****************************************************************************
 * FUNCTION
 *  jvm_debug_send
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
void jvm_debug_write_ind_handler(int port)
{
	if(port == g_jvm_debug_comm_port)
	{
		kal_set_eg_events(g_java_event_group_2, JAVA_EG_COMM_WRITE, KAL_OR);
	}
}

/****************************************************************************
 * FUNCTION
 *  jvm_debug_init_create_mutex
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
void jvm_debug_init_create_mutex(void)
{
    if (dbg_mutex == NULL) dbg_mutex = kal_create_mutex("j2me dbg");
}

/****************************************************************************
 * FUNCTION
 *  jvm_debug_init
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
kal_bool jvm_debug_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char error[50];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    #ifdef ENABLE_JAVA_DEBUGGER_LOG
    if(KDWP_log_handle > 0)
    {
        FS_Close(KDWP_log_handle);
        KDWP_log_handle = 0;
    }

    KDWP_log_handle = FS_Open(L"D:\\KDWP.log", FS_READ_WRITE | FS_CREATE_ALWAYS);
    #endif

    if (g_jvm_debug_mode == JVM_DEBUG_CATCHER)
    {
        /* Add to check if need to enter debug mode - Rex Luo */
    	if (tst_java_debug_mode) 
        {
            kal_uint32 event_group;
            
        #ifndef TST_EVENT_KDWPHOOK
            /* Already defined in tst_def.h, however, need include several header files */
            #define TST_EVENT_KDWPHOOK   			(0x10)
        #endif /* TST_EVENT_KDWPHOOK */
        
            /* Wait test hook event notify, clear last value before wait */
            kal_retrieve_eg_events(tst_event_group, TST_EVENT_KDWPHOOK, KAL_OR_CONSUME,&event_group, KAL_SUSPEND);
        
            if (tst_java_debug_hooked) 
            {
                return KAL_TRUE;
            }
        }
    }
    else if (g_jvm_debug_mode == JVM_DEBUG_COMM)
    {
        jam_comm_register_io_ind_handler(jvm_debug_read_from_comm, jvm_debug_write_ind_handler);
        g_jvm_debug_port_connetion = jam_comm_open(g_jvm_debug_comm_port,g_jvm_debug_comm_baudRate,g_jvm_debug_comm_options);
        tst_java_debug_hooked = KAL_TRUE;
       return KAL_TRUE;
    }
    /*
    else if (g_jvm_debug_mode == JVM_DEBUG_COMM_MODIS)
    {
        g_jvm_debug_port_connetion = openPortByNumber(&error,g_jvm_debug_comm_port-1,g_jvm_debug_comm_baudRate,g_jvm_debug_comm_options);
        tst_java_debug_hooked = KAL_TRUE;
    }
    */
    else
    {}

    

    

}

/*************************************************************************
 * Function Definition
 *************************************************************************/	
void j2me_dbg_recv_flush(void)
{
	kal_take_mutex(dbg_mutex);
	dbg_recv_reader = 0;
	dbg_recv_writer = 0;
	dbg_recv_size = 0;
	kal_give_mutex(dbg_mutex);
}

kal_uint32 j2me_dbg_recv_get(void* buf, kal_uint32 len)
{
	kal_uint32 real_recv = 0;

	if (dbg_recv_size > 0) {
		
		kal_take_mutex(dbg_mutex);

		real_recv = (len >= dbg_recv_size) ? dbg_recv_size : len;
		
		/* Copy data from ring buffer */
		if (dbg_recv_reader + real_recv >= JAVA_DEBUG_BUF_LEN) {
			kal_uint32 tmp = JAVA_DEBUG_BUF_LEN - dbg_recv_reader;

			if (tmp) kal_mem_cpy(buf, &((kal_uint8*)dbg_recv_buf)[dbg_recv_reader], tmp);
			kal_mem_cpy(&((kal_uint8*)buf)[tmp], dbg_recv_buf, real_recv-tmp);
		} else {
			kal_mem_cpy(buf, &((kal_uint8*)dbg_recv_buf)[dbg_recv_reader], real_recv);
		}

		dbg_recv_reader = DBG_INC_READER(real_recv);
		dbg_recv_size -= real_recv;

		kal_give_mutex(dbg_mutex);
	}
		
	return real_recv;
}

kal_bool j2me_dbg_recv_put(void* buf, kal_uint32 len)
{
	kal_bool result = KAL_FALSE;

    #ifdef ENABLE_JAVA_DEBUGGER_LOG
    kal_uint32 written;  
    FS_Write(KDWP_log_handle, "recv1:", 6, &written);
    FS_Write(KDWP_log_handle, buf, len, &written);
    FS_Write(KDWP_log_handle, "recv2:", 6, &written);
    FS_Commit(KDWP_log_handle);
    #endif

	if (dbg_recv_size + len <= JAVA_DEBUG_BUF_LEN) {		
		if (dbg_mutex) kal_take_mutex(dbg_mutex);

		/* Copy data to ring buffer */
		if (dbg_recv_writer + len >= JAVA_DEBUG_BUF_LEN) {
			kal_uint32 tmp = JAVA_DEBUG_BUF_LEN - dbg_recv_writer;

			if (tmp) kal_mem_cpy(&((kal_uint8*)dbg_recv_buf)[dbg_recv_writer], buf, tmp);
			kal_mem_cpy(dbg_recv_buf, &((kal_uint8*)buf)[tmp], len-tmp);

		} else {
			kal_mem_cpy(&((kal_uint8*)dbg_recv_buf)[dbg_recv_writer], buf, len);
		}

		dbg_recv_writer = DBG_INC_WRITER(len);
		dbg_recv_size += len;
		result = KAL_TRUE;
		if (dbg_mutex) kal_give_mutex(dbg_mutex);
	} else {
		kal_print("JVM Debug Warning: recv overflow");
		ASSERT(0);
	}

	return result;
}

#endif
