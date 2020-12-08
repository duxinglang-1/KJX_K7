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
 *   w32_uart.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Uart simulating functions
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "kal_release.h"
#include "dcl.h"

//typedef DCL_DEV UART_PORT;
extern kal_bool _UART_Open(UART_PORT port, module_type owner);
extern void _UART_Close(UART_PORT port, module_type ownerid);
extern kal_uint16 _UART_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
extern kal_uint16 _UART_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
extern kal_uint16 _UART_GetBytesAvail(UART_PORT port);
extern kal_uint16 _UART_GetTxRoomLeft(UART_PORT port);
extern module_type _UART_GetOwnerID(UART_PORT port);
//typedef void* HANDLE;
//extern HANDLE UARTHandle[256];

#define DCL_UART_MAGIC_NUM  0x40000000
#define DCL_UART_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_UART_MAGIC_NUM)
#define DCL_UART_GET_DEV(handle_) ((handle_) & (~DCL_UART_MAGIC_NUM))

DCL_STATUS DclSerialPort_Initialize(void)
{
	return STATUS_OK;
}

DCL_HANDLE DclSerialPort_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if((dev<uart_port1) ||(dev>uart_max_port))
		return STATUS_INVALID_DEVICE;
	 return (DCL_UART_MAGIC_NUM | dev);
}

DCL_STATUS DclSerialPort_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_OK;
}

DCL_STATUS DclSerialPort_RegisterCallback(DCL_HANDLE handle, Seriport_HANDLER_T* uart_handler_cb)
{
	return STATUS_OK;
}


DCL_STATUS DclSerialPort_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_DEV Device;

	if (!DCL_UART_IS_HANDLE_MAGIC(handle))
    {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
    }
 		
 	if(handle == STATUS_INVALID_DEVICE)
 		return STATUS_FAIL;

	Device = DCL_UART_GET_DEV(handle);
	
	switch (cmd)
	{
	case SIO_CMD_INIT:
		break;
	case SIO_CMD_OPEN:
		{
			UART_CTRL_OPEN_T* prCtrlOpen;
			kal_bool fg = KAL_FALSE;
			prCtrlOpen = &(data->rUARTCtrlOPEN);
			fg = _UART_Open((UART_PORT)Device,prCtrlOpen->u4OwenrId);
			if(fg == KAL_FALSE)
				return STATUS_FAIL;
		}
		break;
	case SIO_CMD_CLOSE:
		{
			UART_CTRL_CLOSE_T* prCtrlClose;
			prCtrlClose = &(data->rUARTCtrlCLOSE);
			_UART_Close((UART_PORT)Device,prCtrlClose->u4OwenrId);
		}
		break;
	case SIO_CMD_GET_BYTES:
		{
			UART_CTRL_GET_BYTES_T* prCtrlGetBytes;
			prCtrlGetBytes = &(data->rUARTCtrlGETBYTES);
			prCtrlGetBytes->u2RetSize = _UART_GetBytes((UART_PORT)Device, prCtrlGetBytes->puBuffaddr, prCtrlGetBytes->u2Length, prCtrlGetBytes->pustatus, prCtrlGetBytes->u4OwenrId);
		}
		break;
	case SIO_CMD_PUT_BYTES:
		{
			UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
			prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
			prCtrlPutBytes->u2RetSize = _UART_PutBytes((UART_PORT)Device, prCtrlPutBytes->puBuffaddr, prCtrlPutBytes->u2Length, prCtrlPutBytes->u4OwenrId);
		}
		break;
	case SIO_CMD_GET_RX_AVAIL:
		{
			UART_CTRL_RX_AVAIL_T* prCtrlRXAvail;
			prCtrlRXAvail = &(data->rUARTCtrlRXAVAIL);
			prCtrlRXAvail->u2RetSize = 0;
		}
		break;
	case SIO_CMD_GET_TX_AVAIL:
		{
			UART_CTRL_TX_AVAIL_T* prCtrlTXAvail;
			prCtrlTXAvail = &(data->rUARTCtrlTXAVAIL);
			prCtrlTXAvail->u2RetSize = 0;
		}
		break;
	case SIO_CMD_PUT_ISR_BYTES:
	case SIO_CMD_GET_ISR_TX_AVAIL:
	case SIO_CMD_PURGE:
	case SIO_CMD_SET_OWNER:
	case SIO_CMD_SET_FLOW_CTRL:
	case SIO_CMD_CONFIG_ESCAPE:
	case SIO_CMD_SET_DCB_CONFIG:
	case SIO_CMD_CTRL_DCD:
	case SIO_CMD_CTRL_BREAK:
	case SIO_CMD_CLR_RX_BUF:
	case SIO_CMD_CLR_TX_BUF:
	case SIO_CMD_SET_BAUDRATE:
	case SIO_CMD_SEND_ISR_DATA:
		break;
	case SIO_CMD_SEND_DATA:
		{
			UART_CTRL_SEND_DATA_T* prCtrlSendData;
			prCtrlSendData = &(data->rUARTCtrlSENDDATA);
			prCtrlSendData->u2RetSize = 0;
		}
		break;
	case SIO_CMD_GET_OWNER_ID:
		{
			UART_CTRL_OWNER_T* prCtrlOwner;
			prCtrlOwner = &(data->rUARTCtrlOWNER);
			prCtrlOwner->u4OwenrId =  _UART_GetOwnerID((UART_PORT)Device);
		}
		break;
	case SIO_CMD_SET_AUTOBAUD_DIV:
	case SIO_CMD_REG_RX_CB:
		break;
	case SIO_CMD_GET_UART_BYTE:
		{
			UART_CTRL_GET_UART_BYTE_T* prCtrlGetUartByte;
			prCtrlGetUartByte = &(data->rUARTCtrlGETUARTBYTE);
			prCtrlGetUartByte->uByte = 0;
		}
		break;
	case SIO_CMD_PUT_UART_BYTE:
	case SIO_CMD_PUT_UART_BYTES:
	case SIO_CMD_READ_DCB_CONFIG:
	case SIO_CMD_CTRL_RI:
	case SIO_CMD_CTRL_DTR:
	case SIO_CMD_READ_HW_STATUS:
	case UART_CMD_SET_FIFO_TRIGGER:
	case UART_CMD_POWER_ON:
	case UART_CMD_CHECK_TX_BUF_EMPTY:
	case UART_CMD_CHECK_TX_SEND_OUT:
	case UART_CMD_GET_TX_BUF_SIZE:
	case UART_CMD_SLEEP_TX_ENABLE:
	case UART_CMD_CTRL_SLEEP_MODE:
	case UART_CMD_SWITCH_PORT:
	case UART_CMD_BOOTUP_INIT:
	case UART_CMD_BOOT_PUTBYTES:
	case UART_CMD_LOOPBACK:
	case UART_CMD_ASSERT_WAIT_SEND_OUT:
	case UART_CMD_CTRL_USE_VFIFO:
	break;

	default:
		return STATUS_INVALID_CMD;
	}

	return STATUS_OK;
}
DCL_STATUS DclSerialPort_Close(DCL_HANDLE handle)
{
	return STATUS_OK;
}
