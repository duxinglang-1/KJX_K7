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
 *   This file implements JAM (Java Application Manager) and other module
 *  adaptation interface layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "jal.h"
#include "jam_internal.h"
#include "jvm_internal.h"
#include "jvm_vcomm.h"
#include "jvm_resource_manager.h" //20101104,changed resource mgr for MVM


/* IO */
#include "drv_comm.h"
////#include "uart_sw.h"
#include "dcl.h"
#include "jam_msg_handler.h"

/*************************************************************************
 * External Declaration
 *************************************************************************/
extern void configurePort(char **ppszError, int hPort, long baudRate, unsigned long options);
extern void closePort(long hPort);

/*************************************************************************
 * Global Definition
 *************************************************************************/
static kal_bool uart1_opened = KAL_FALSE;
static kal_bool ps_uart_opened = KAL_FALSE;
static kal_bool usb_opened = KAL_FALSE;
static kal_bool plug_in_usb_cable = KAL_FALSE;  
jam_comm_read_ind_handler jam_comm_registered_read_ind_handler;
jam_comm_write_ind_handler jam_comm_registered_write_ind_handler;

volatile int jam_comm_mutex_cnt = 0;
volatile module_type jam_comm_mutex_tid = MOD_NIL;
extern kal_mutexid g_jam_comm_mutex;
/*****************************************************************************
 * FUNCTION
 *  jam_comm_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_comm_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI_LOCK; */
    if (kal_get_active_module_id() != jam_comm_mutex_tid)
    {
        kal_take_mutex(g_jam_comm_mutex);
        jam_comm_mutex_tid = kal_get_active_module_id();
    }
    ++jam_comm_mutex_cnt;

}


/*****************************************************************************
 * FUNCTION
 *  jam_comm_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_comm_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jam_comm_mutex_tid == kal_get_active_module_id());

    --jam_comm_mutex_cnt;

    if (jam_comm_mutex_cnt == 0)
    {
        jam_comm_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_comm_mutex);
    }
    /* GDI_UNLOCK; */
}


/*****************************************************************************
 * FUNCTION
 *  jam_comm_register_io_ind_handler
 * DESCRIPTION
 *  Comm adaptation
 * PARAMETERS
 *  read_handler        [IN]        
 *  write_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jam_comm_register_io_ind_handler(jam_comm_read_ind_handler read_handler, jam_comm_write_ind_handler write_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_comm_registered_read_ind_handler = read_handler;
    jam_comm_registered_write_ind_handler = write_handler;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_set_owner
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 *  ownerid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_io_uart_set_owner(UART_PORT port, module_type ownerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    DCL_HANDLE handle;
    UART_CTRL_OWNER_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.u4OwenrId = ownerid;

    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*) & data);

}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_sleepOnTx_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  enable_flag     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_io_uart_sleepOnTx_enable(UART_PORT port, UART_SLEEP_ON_TX enable_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;
    UART_CTRL_SLEEP_ON_TX_ENABLE_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.bFlag = (UART_SLEEP_ON_TX_T) enable_flag;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, UART_CMD_SLEEP_TX_ENABLE, (DCL_CTRL_DATA_T*) & data);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_setDCBConfig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  UART_Config     [?]         
 *  ownerid         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_io_uart_setDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    DCL_HANDLE handle;
    UART_CTRL_DCB_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.u4OwenrId = ownerid;
    data.rUARTConfig.u4Baud = UART_Config->baud;
    data.rUARTConfig.u1DataBits = UART_Config->dataBits;
    data.rUARTConfig.u1StopBits = UART_Config->stopBits;
    data.rUARTConfig.u1Parity = UART_Config->parity;
    data.rUARTConfig.u1FlowControl = UART_Config->flowControl;
    data.rUARTConfig.ucXonChar = UART_Config->xonChar;
    data.rUARTConfig.ucXoffChar = UART_Config->xoffChar;
    data.rUARTConfig.fgDSRCheck = (DCL_BOOLEAN) UART_Config->DSRCheck;

    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*) & data);

}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 *  ownerid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_io_uart_open(UART_PORT port, module_type ownerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;
    UART_CTRL_OPEN_T data;

    DCL_STATUS status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    status = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*) & data);
 
    return status == STATUS_OK ? KAL_TRUE:KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 *  ownerid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_io_uart_close(UART_PORT port, module_type ownerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;
    UART_CTRL_CLOSE_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*) & data);

}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_get_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  Buffaddr        [?]         
 *  Length          [IN]        
 *  status          [?]         
 *  ownerid         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 jvm_io_uart_get_bytes(
            UART_PORT port,
            kal_uint8 *Buffaddr,
            kal_uint16 Length,
            kal_uint8 *status,
            module_type ownerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    DCL_HANDLE handle;
    UART_CTRL_GET_BYTES_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;
    data.pustatus = status;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*) & data);
    return data.u2RetSize;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_put_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  Buffaddr        [?]         
 *  Length          [IN]        
 *  ownerid         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 jvm_io_uart_put_bytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    DCL_HANDLE handle;
    UART_CTRL_PUT_BYTES_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;

    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*) & data);
    return data.u2RetSize;

	
}


/*****************************************************************************
 * FUNCTION
 *  jvm_io_uart_get_bytes_avail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 jvm_io_uart_get_bytes_avail(UART_PORT port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    DCL_HANDLE handle;
    UART_CTRL_RX_AVAIL_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*) & data);
    return data.u2RetSize;
}


/*****************************************************************************
 * FUNCTION
 *  commCloseDereg
 * DESCRIPTION
 *  Comm adaptation
 * PARAMETERS
 *  hPort       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int commCloseDereg(int hPort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UARTDCBStruct dcb = 
    {
    #ifdef __PS_SERVICE__
        UART_BAUD_115200,
    #else 
        UART_BAUD_57600,    /* baud rate */
    #endif 
        len_8,              /* dataBits; */
        sb_1,               /* stopBits; */
        pa_none,            /* parity; */
        fc_hw,              /* no flow control; */
        0x11,               /* xonChar; */
        0x13,               /* xoffChar; */
        KAL_FALSE
    };
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_comm_mutex_lock();
    ASSERT(hPort == PS_UART_PORT || hPort == uart_port1 || hPort == uart_port_usb);

    if(hPort == PS_UART_PORT)
    {
        jvm_io_uart_set_owner(hPort, MOD_L4C);
        jvm_io_uart_sleepOnTx_enable((UART_PORT) hPort, uart_sleep_on_tx_allow);
        jvm_io_uart_setDCBConfig((UART_PORT) hPort, &dcb, MOD_L4C);
        ps_uart_opened = KAL_FALSE;
    }
    else
    {
        if(hPort == uart_port1){
            uart1_opened = KAL_FALSE;
            jvm_io_uart_close((UART_PORT)hPort, MOD_JASYN);
        }
        else if(hPort == uart_port_usb && usb_opened)
        {
            usb_opened= KAL_FALSE;
            jvm_io_uart_close((UART_PORT)hPort, MOD_JASYN);
        }
    }
    jam_comm_mutex_unlock();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  commCloseHandle
 * DESCRIPTION
 *  Comm adaptation
 * PARAMETERS
 *  hPort       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int commCloseHandle(int hPort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /*Begin Added by Yanbin Ren*/
#ifdef __JAVA_VIRTUAL_COMM__
        if(KAL_TRUE == java_vcomm_opened)
        {
            java_vcomm_close(hPort);
            java_vcomm_opened = KAL_FALSE;
            return RESOUCE_NO_ERROR;
        }
#endif
    
        /*End Added by Yanbin Ren*/
    jam_comm_mutex_lock();
    commCloseDereg(hPort);

    if (jam_vm_is_busy())
    {
        //resouceDereg(JAVA_IO_COMM_DEVICE, hPort); //20101104,changed resource mgr for MVM
        jvm_resource_mgr_deregister(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_COMM_DEVICE,hPort);
    }
    jam_comm_mutex_unlock();
    return RESOUCE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jam_comm_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  baudRate        [IN]        
 *  options         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jam_comm_open(long port, long baudRate, long options)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /*Begin Added by Yanbin Ren*/
#ifdef __JAVA_VIRTUAL_COMM__ 
    if((port == 0) && (baudRate ==2400))
    {
        if(KAL_TRUE == java_vcomm_opened)
            return port;
        if(KAL_FALSE == java_vcomm_open(port))
        {
            return -1;
        }
        java_vcomm_opened = KAL_TRUE;
        return port;
    }
#endif
    /*End Added by Yanbin Ren*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN, port, baudRate, options);   
    jam_comm_mutex_lock();
    if(port == 1 && !ps_uart_opened)
    {
        port = PS_UART_PORT;
        kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_1);         
        jvm_io_uart_set_owner((UART_PORT)port, MOD_JASYN);
    }
    else if(port == 0 && ((!plug_in_usb_cable&&!uart1_opened)||(plug_in_usb_cable&&!usb_opened)))
    {
        if(plug_in_usb_cable)
        {
            port = uart_port_usb;
            kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_0_USB);  
        }            
        else
        {
            port = uart_port1;
            kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_0_UART);  
        }            
           
        if(/*UART_Open*/jvm_io_uart_open((UART_PORT) port, MOD_JASYN) == KAL_FALSE)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_1_FAIL);  
            jam_comm_mutex_unlock();               
            return -1;
        }
    }
    else
    {
        jam_comm_mutex_unlock();
        return -1;
    }
    kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_OK);
                  
    if(port == PS_UART_PORT)
    {
        ps_uart_opened = KAL_TRUE;
        kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_PORT, 0);                 
       
    }
    else if(port == uart_port1)
    {
        uart1_opened = KAL_TRUE;
        kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_PORT, 1);        
    }
    else if(port == uart_port_usb)
    {
        usb_opened = KAL_TRUE;
        kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_OPEN_PORT, 2);
        
    }
    else
    {
        ASSERT(0);
    }

    jam_comm_config((kal_uint32) port, baudRate, options);
    jvm_io_uart_sleepOnTx_enable((UART_PORT)port, uart_sleep_on_tx_forbid);

    if (jam_vm_is_busy())
    {
        //resouceRegistering(JAVA_IO_COMM_DEVICE, (int)port, NULL, NULL, &commCloseDereg); //20101104, changed resource mgr for MVM
        jvm_resource_mgr_register(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_COMM_DEVICE, (int)port, NULL, NULL, &commCloseDereg);
    }
    jam_comm_mutex_unlock();

    return port;
}


/*****************************************************************************
 * FUNCTION
 *  jam_comm_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port            [IN]        
 *  baud_rate       [IN]        
 *  options         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jam_comm_config(kal_uint32 port, long baud_rate, unsigned long options)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UARTDCBStruct DCB = 
    {
        UART_BAUD_115200,   /* baud; */
        len_8,              /* dataBits; */
        sb_1,               /* stopBits; */
        pa_none,            /* parity; */
        fc_none,            /* no flow control */
        0x11,               /* xonChar; */
        0x13,               /* xoffChar; */
        KAL_FALSE
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the port number is not legal */
    jam_comm_mutex_lock();
    if(!(port == PS_UART_PORT && ps_uart_opened) && 
       ((!plug_in_usb_cable && !(port == uart_port1 && uart1_opened)) ||
       (plug_in_usb_cable && !(port == uart_port_usb && usb_opened)))
      )
    {
        jam_comm_mutex_unlock();
        return;
    }

    DCB.baud = baud_rate;

    /* 0-4 = no, odd,e ven, mark, space */
    if (options & COMM_ODD_PARITY)
    {
        DCB.parity = pa_odd;
    }
    else if (options & COMM_EVEN_PARITY)
    {
        DCB.parity = pa_even;
    }

    /* CTS output flow control */
    if (options & COMM_AUTO_CTS || options & COMM_AUTO_RTS)
    {
        DCB.flowControl = fc_hw;
    }

    /* BITS_PER_CHAR_8 is 2 bits and includes BITS_PER_CHAR_7 */
    if ((options & COMM_BITS_PER_CHAR_8) == COMM_BITS_PER_CHAR_8)
    {
        DCB.dataBits = len_8;
    }
    else
    {
        DCB.dataBits = len_7;
    }

    /* StopBits 0,1,2 = 1, 1.5, 2 */
    if (options & COMM_STOP_BITS_2)
    {
        DCB.stopBits = sb_2;
    }

    jvm_io_uart_setDCBConfig((UART_PORT)port, &DCB, MOD_JASYN);
    jam_comm_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jam_comm_putbytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 *  buffer      [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jam_comm_putbytes(kal_uint32 port, kal_uint8 *buffer, kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /*Begin Added by Yanbin Ren*/
#ifdef __JAVA_VIRTUAL_COMM__ 
    if((port == 0) && (java_vcomm_opened == KAL_TRUE))
    {
        return java_vcomm_write(port,buffer,len);
    }
#endif
     /*End Added by Yanbin Ren*/

    //kal_print_string_trace(MOD_J2ME,TRACE_GROUP_9,"jam_comm_putbytes");                        

    jam_comm_mutex_lock();
    /* the port number is not legal */
    if(!(port == PS_UART_PORT && ps_uart_opened) && 
       ((!plug_in_usb_cable && !(port == uart_port1 && uart1_opened)) ||
       (plug_in_usb_cable && !(port == uart_port_usb && usb_opened)))
      )
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_PUT_BYTES,0,port,plug_in_usb_cable,uart1_opened,plug_in_usb_cable,usb_opened);
        jam_comm_mutex_unlock();
        return -1;
    }
    ret = jvm_io_uart_put_bytes((UART_PORT)port, buffer, len, MOD_JASYN);
    jam_comm_mutex_unlock();
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jam_comm_getbytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 *  buffer      [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jam_comm_getbytes(kal_uint32 port, kal_uint8 *buffer, kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Begin Added by Yanbin Ren*/
#ifdef __JAVA_VIRTUAL_COMM__ 
    if((port == 0) && (java_vcomm_opened == KAL_TRUE))
    {
        return java_vcomm_read(port,buffer,len);
    }
#endif
    /*End Added by Yanbin Ren*/
    
    jam_comm_mutex_lock();
    /* the port number is not legal */
    if(!(port == PS_UART_PORT && ps_uart_opened) && 
       ((!plug_in_usb_cable && !(port == uart_port1 && uart1_opened)) ||
       (plug_in_usb_cable && !(port == uart_port_usb && usb_opened)))
      )
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_GET_BYTES,0,port,plug_in_usb_cable,uart1_opened,plug_in_usb_cable,usb_opened); 
        jam_comm_mutex_unlock();
        return -1;
    }
    ret = jvm_io_uart_get_bytes((UART_PORT)port, buffer, len, NULL, MOD_JASYN);
    /* debug for see what is recv */    
    /*
    if(ret != 0)
    {
        kal_char content[50];
        kal_char log[65];
        kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_GET_BYTES,1,port,plug_in_usb_cable,uart1_opened,plug_in_usb_cable,usb_opened); 
        strcpy(log,"get byte: ");        
        strncpy(content,(kal_char*)buffer,49);  
        strcat(log,content);
        kal_prompt_trace(MOD_J2ME,log);        
    } 
    */   
    jam_comm_mutex_unlock();
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_comm_usb_in_java_register_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  usb_is_plug_in        [BOOL]        
 * RETURNS
 *  
 *****************************************************************************/
void jvm_comm_usb_in_java_register_cb(kal_bool usb_is_plug_in)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_9, FUNC_JVM_IO_COMM_USB_PLUG_IN, usb_is_plug_in); 
    jam_comm_mutex_lock();
    plug_in_usb_cable = usb_is_plug_in;
    if(!usb_is_plug_in && usb_opened)
    {
        commCloseHandle(uart_port_usb);
    }
    jam_comm_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jam_comm_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jam_comm_available(kal_uint32 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jvm_io_uart_get_bytes_avail(port);
}

