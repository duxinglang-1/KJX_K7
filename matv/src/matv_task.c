/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
	 *	 matv_task.c
	 *
	 * Project:
	 * --------
	 *	 Maui_sw
	 *
	 * Description:
	 * ------------
	 *	 implement matv task
	 *
	 * Author:
	 * -------
	 *	 shaowu.he (mtk70699)
	 *
	 *============================================================================

******************************************************************************
 
 ****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "syscomp_config.h"
#include "app_ltlcom.h"         /* Task message communiction */
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"         /* Event scheduler */
#include "task_config.h"        /* Task creation */
#include "dcl.h"
	 

kal_bool mATV_CLI_enable=KAL_FALSE;


#if defined(__MTK_TARGET__) && defined(__ATV_SUPPORT__)

//DCL_DEV mATV_uart= uart_port_null;//uart_port1;//uart_port_null;//
extern void cli_rx_callback(void);
extern kal_uint8 u1CliUseUartPort;
extern kal_uint8 u1CliUseUartModID;
#if (defined(MT6252H) || defined(MT6252))
extern kal_bool idp_camera_preview_pxd;
kal_uint8 CountDropPixel=0;
extern kal_uint8 prech;   
extern kal_uint8 curch;
#endif

extern void CLI_Init(void);
extern void ATV_i2c_init(void);
extern int TvMainloop(void);

kal_semid	 matv_sem_id = NULL;

extern void matv_kal_take_sem(void);
extern void matv_kal_give_sem(void);
extern void matv_kal_sleep_task(kal_uint32 time_in_ms);

#define atv_uart_slim

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
#ifdef atv_uart_slim
DCL_STATUS matv_UART_function(DCL_DEV port, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS status;
	DCL_HANDLE handle;
	
	handle = DclSerialPort_Open(port,0);
   	status = DclSerialPort_Control(handle, cmd, data);
	DclSerialPort_Close(handle);
	return status;
}
#endif
DCL_UINT16 matv_UART_GetBytes(DCL_DEV port, DCL_UINT8 *Buffaddr, DCL_UINT16 Length, DCL_UINT8 *status, DCL_UINT32 ownerid)
{

	UART_CTRL_GET_BYTES_T data;
	DCL_HANDLE handle;

	data.u4OwenrId = ownerid;
	data.u2Length = Length;
	data.puBuffaddr = Buffaddr;
#if 0//def 0//atv_uart_slim
/* under construction !*/
#else
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
#endif
	
	return data.u2RetSize;

}





DCL_UINT16 matv_UART_GetBytesAvail(DCL_DEV port)
{
	UART_CTRL_RX_AVAIL_T data;
	

#if 0//def 0//atv_uart_slim
/* under construction !*/
#else
	DCL_HANDLE handle;
	 handle = DclSerialPort_Open(port,0);
	 DclSerialPort_Control(handle,SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*)&data);
	 DclSerialPort_Close(handle);
#endif
	 return data.u2RetSize;

}


DCL_UINT16 matv_UART_GetTxRoomLeft(DCL_DEV port)
{
	UART_CTRL_TX_AVAIL_T data;
	
#ifdef atv_uart_slim
	matv_UART_function(port, SIO_CMD_GET_TX_AVAIL, (DCL_CTRL_DATA_T*)&data);
#else
	DCL_HANDLE handle;
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_GET_TX_AVAIL, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
#endif
	return data.u2RetSize;
}

#if atv_slim


#endif
DCL_UINT16 matv_UART_PutBytes(DCL_DEV port, DCL_UINT8 *Buffaddr, DCL_UINT16 Length, DCL_UINT32 ownerid)
{

	UART_CTRL_PUT_BYTES_T data;
	DCL_HANDLE handle;

	data.u4OwenrId = ownerid;
	data.u2Length = Length;
	data.puBuffaddr = Buffaddr;
	
#ifdef atv_uart_slim
	matv_UART_function(port, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
#else	 
	 handle = DclSerialPort_Open(port,0);
	 DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	 DclSerialPort_Close(handle);
#endif
	 return data.u2RetSize;	

}   

void matv_PutUARTByte(DCL_DEV port, DCL_UINT8 data)
{

	UART_CTRL_PUT_UART_BYTE_T data1;
	DCL_HANDLE handle;
	data1.uData = data;
#ifdef atv_uart_slim
	matv_UART_function(port, SIO_CMD_PUT_UART_BYTE, (DCL_CTRL_DATA_T*)&data1);
#else
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_PUT_UART_BYTE, (DCL_CTRL_DATA_T*)&data1);
	DclSerialPort_Close(handle);
#endif
}
void matv_UART_TurnOnPower(UART_PORT port, kal_bool enable) 
{
	UART_CTRL_POWERON_T data;
	DCL_HANDLE handle;
	data.bFlag_Poweron = enable;
	
#ifdef atv_uart_slim
	matv_UART_function(port, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);
#else
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
#endif
}

kal_bool matv_UART_Open(DCL_DEV port, DCL_UINT32 ownerid)
{
    UART_CTRL_OPEN_T data;
	DCL_HANDLE handle;
	
	DCL_STATUS status;
	data.u4OwenrId = ownerid;
#ifdef atv_uart_slim
	status = matv_UART_function(port, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
#else
	handle = DclSerialPort_Open(port,0);
   	status = DclSerialPort_Control(handle,SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
#endif
	 if(STATUS_OK != status)
		return KAL_FALSE;
	 else
	 	return KAL_TRUE;
}


void matv_UART_Register_RX_cb(DCL_DEV port, DCL_UINT32 ownerid, DCL_UART_RX_FUNC func)
{
	UART_CTRL_REG_RX_CB_T data;
	DCL_HANDLE handle;
	data.u4OwenrId = ownerid;
	data.func = func;
	
#ifdef atv_uart_slim
	matv_UART_function(port, SIO_CMD_REG_RX_CB, (DCL_CTRL_DATA_T*)&data);
#else
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_REG_RX_CB, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
#endif
}

void matv_UART_SetDCBConfig(DCL_DEV port, UART_CONFIG_T *UART_Config, DCL_UINT32 ownerid)
{
	UART_CTRL_DCB_T data;
	DCL_HANDLE handle;
	
	data.u4OwenrId = ownerid;
	data.rUARTConfig.u4Baud = UART_Config->u4Baud;
	data.rUARTConfig.u1DataBits = UART_Config->u1DataBits;
	data.rUARTConfig.u1StopBits = UART_Config->u1StopBits;
	data.rUARTConfig.u1Parity = UART_Config->u1DataBits;
	data.rUARTConfig.u1FlowControl = UART_Config->u1FlowControl;
	data.rUARTConfig.ucXonChar = UART_Config->ucXonChar;
	data.rUARTConfig.ucXoffChar = UART_Config->ucXoffChar;
	data.rUARTConfig.fgDSRCheck = UART_Config->fgDSRCheck;
#ifdef atv_uart_slim
	matv_UART_function(port, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
#else
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
#endif

}

void matv_UART_Close(DCL_DEV port, DCL_UINT32 ownerid)
{
	UART_CTRL_CLOSE_T data;
	DCL_HANDLE handle;
	data.u4OwenrId = ownerid;

	
#ifdef atv_uart_slim
	matv_UART_function(port, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
#else
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
#endif
}


kal_int8 CLI_RECIEVE_CMD_DONE = 0;
void mATV_task_uartRx(DCL_UINT32 u4Port)
{
//		 cli_rx_callback();
	CLI_RECIEVE_CMD_DONE = 1;
}
	 
static UART_CONFIG_T matv_uart_dcb=
	 {
		 UART_BAUD_921600,
		 LEN_8,
		 SB_1,
		 PA_NONE,
		 FC_NONE,
		 0,
		 0,
		 DCL_FALSE
	 };
	 
	 kal_uint8 cli_init(DCL_DEV port)
	 {
		 kal_bool ret;
		 matv_UART_TurnOnPower(port, KAL_TRUE);
    	 ret= matv_UART_Open(port, MOD_MATV);
		 if(ret) 
		 {	 
			 matv_UART_Register_RX_cb(port, MOD_MATV, mATV_task_uartRx);
			 matv_UART_SetDCBConfig(port,&matv_uart_dcb, MOD_MATV); 
			 
			 u1CliUseUartPort=port;
			 u1CliUseUartModID=MOD_MATV;
			 CLI_Init();
		 }
	 
		 return ret;
	 }
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
	 
	 extern kal_bool bMatv_powerOn;
	 kal_eventgrpid matv_event_id;
	 void mATV_task_main(task_entry_struct *task_entry_ptr)
	 {
		 /*----------------------------------------------------------------*/
		 /* Local Variables 											   */
		 /*----------------------------------------------------------------*/
		 kal_uint32 event_group;
		 int wait_ms;
#if (defined(MT6223P)||defined(MT6223)||defined(__DIRECT_SENSOR_V2_SUPPORT__)||(defined(FM_INTERFACE_I2C)&&(!defined(MT5192FM))) )
	     matvdrv_ps_init(KAL_TRUE);
#endif
		 /*----------------------------------------------------------------*/
		 /* Code Body													   */
		 /*----------------------------------------------------------------*/
		 while(1)
		 {
			 kal_retrieve_eg_events(matv_event_id,1,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
			 matv_kal_take_sem();
	 
			 if(mATV_CLI_enable && (u1CliUseUartPort==uart_port_null))
			 {
				 ATV_i2c_init();
				 cli_init(uart_port1);	//	For build error	 DCL_UART1
			 }
			 if(mATV_CLI_enable)
			 {
				if(CLI_RECIEVE_CMD_DONE == 1)
				{
					cli_rx_callback();
					CLI_RECIEVE_CMD_DONE =0;
				}
			 }
		  #if (defined(MT6252H) || defined(MT6252))
			if(idp_camera_preview_pxd==KAL_TRUE&&prech==curch)
			 {
			  if(CountDropPixel==0)
			     {
			      CountDropPixel++;
			      idp_camera_preview_pxd=KAL_FALSE;
			     }
			  else
				 {
				  vTVD_TV_FreqHopping(26000);
			      idp_camera_preview_pxd=KAL_FALSE;
			      prech=0xff;
			      CountDropPixel=0;
			 	 }
			 }  
		   #endif 
			 wait_ms=TvMainloop();
			 
			 if(!mATV_CLI_enable)
			 {
				 matv_UART_Close(u1CliUseUartPort, MOD_MATV);
				 u1CliUseUartPort=uart_port_null;
			 }
	 
			 matv_kal_give_sem();
			 matv_kal_sleep_task((wait_ms));
							  if(bMatv_powerOn)
				   kal_set_eg_events(matv_event_id,1,KAL_OR);
		
	 }
}
	 
	 kal_bool mATV_task_init(task_indx_type task_indx)
	 {
			 u1CliUseUartPort=uart_port_null;
		 
			 matv_sem_id = kal_create_sem("MATV_SEM", 1);
			 matv_event_id = kal_create_event_group("matv_wait_events");
			 return KAL_TRUE;
	 }
	 
	 kal_bool mATV_task_reset(task_indx_type task_indx)
	 {
		 
		 return KAL_TRUE;
	 }
	 
#endif /* __MTK_TARGET__ && __ATV_SUPPORT__ */
	 
	 kal_bool mATV_task_create(comptask_handler_struct **handle)
	 {
	 
#if defined(__MTK_TARGET__) && defined(__ATV_SUPPORT__)	
		 /*----------------------------------------------------------------*/
		 /* Local Variables 											   */
		 /*----------------------------------------------------------------*/
		 static const comptask_handler_struct mATV_task_handler_info = 
		 {
			 mATV_task_main,  /* task entry function */
			 mATV_task_init,	   /* task initialization function */
			 NULL,			 /* task configuration function */
			 mATV_task_reset,	   /* task reset handler */
			 NULL,			 /* task termination handler */
		 };
	 
		 /*------------------------------------
		 ----------------------------*/
		 /* Code Body													   */
		 /*----------------------------------------------------------------*/
		 *handle = (comptask_handler_struct*) & mATV_task_handler_info;
	 
		 return KAL_TRUE;
	 
#else
	 
		 return KAL_FALSE;
	 
#endif /* __MTK_TARGET__ && __ATV_SUPPORT__ */
	 }







