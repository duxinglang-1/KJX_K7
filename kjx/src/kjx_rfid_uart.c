/**********************************************************************************
*Filename:     kjx_rfid.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2015/10/26
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#if defined(__KJX_RFID__)
#include "kjx_include.h"
#ifndef WIN32
#include "Uart_internal.h"             //UART_dafault_rx_cb
#endif
#include "Kjx_prin.h"

extern U8 g_rfid_field;
extern int g_start_rfid;
extern U16 sensor_status;
extern BOOL g_rfid_test_timer;
extern BOOL g_rfid_low_bat;

int rfid_len = 0;
U16 g_rfid_is_on = 0;
#ifdef __KJX_FUN_GPS__
extern U16 g_gps_is_on;
#endif

#if 0//!defined(__KJX_FUN_GPS__)
#define RFID_TEST_PORT2
#endif
     
#if defined(RFID_TEST_PORT2)
#define RFID_UART_PORT		uart_port2
 
#define RFID_UART_UTXD_PIN	  	21 
#define RFID_UART_URXD_PIN	  	20 
#else
#define RFID_UART_PORT		uart_port1 
 
#define RFID_UART_UTXD_PIN	  	22 
#define RFID_UART_URXD_PIN	  	23 
#endif

#define FUN_RFID_PWR_PIN  12
#define RFID_BUFF_MAX_LEN	1024

#if defined(__KJX_AGAINST_THEFT__)
#if defined(__KJX_AGAINST_THEFT_BY_RFID_NUM__)
#define AGAINST_RFID	10101010
#endif
#endif

#define RFID_UART_DEBUG

static module_type gObdUartOwner;
static BOOL rfid_is_use_uart = FALSE;
static BOOL rfid_is_working = FALSE;
static BOOL rfid_send_timeout = TRUE;
BOOL rfid_get_car_info = FALSE;

kal_uint8 g_SleepMode = 0xff;	//睡眠模式句柄
kal_uint8 ObdUartBuffer[RFID_BUFF_MAX_LEN+1]={0};

U8 rfid_field_index = 0;
U8 rfid_field_count[30] = {0xff};

U32 g_kjx_rfid_id = 0;

#if defined(__KJX_AGAINST_THEFT__)
U8 g_str_rfid_against[10] = 0;
extern kal_bool g_rfid_against_theft;
extern void kjx_start_against_theft_alarm(void);
#endif
extern U32 kjx_dj_get_mode_state(void);

void kjx_rfid_turn_off(void);
void kjx_rfid_eint_turn_off_uart(void);

extern void kjx_factory_rfid_test_end(void);

UARTDCBStruct UART_DefaultConfig =
{             
    UART_BAUD_38400,//38400,//UART_BAUD_115200,//UART_BAUD_38400, /* baud; */
    len_8, /* dataBits; */
    sb_1, /*stopBits; */
    pa_none, //pa_odd, /* parity; */
    fc_none, /*no flow control*/
    0x11, /* xonChar; */ 
    0x13, /* xoffChar; */
    KAL_FALSE
};

UARTDCBStruct DJ_dcbcfg =
{ 
	UART_BAUD_19200, //UART_BAUD_9600	baiwenlin 20200726/* baudrate */
	len_8,				/* dataBits; */
	sb_1,				/* stopBits; */
	pa_none,			/* parity; */
	fc_none,			/* flow control */
	0x11,				/* xonChar; */
	0x13,				/* xoffChar; */
	KAL_FALSE
};


void kjx_uart_clear_rx_buf(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLR_BUFFER_T data;
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);
}


void kjx_uart_clear_tx_buf(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLR_BUFFER_T data;
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);
}


void kjx_uart_close_tx_or_rx(UART_PORT port)
{
    DCL_HANDLE gpio_handle;
	
    gpio_handle = DclGPIO_Open(DCL_GPIO,port);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
    DclGPIO_Close(gpio_handle);
}

void kjx_uart_open_tx_or_rx(UART_PORT port)
{
    DCL_HANDLE gpio_handle;
	
    gpio_handle = DclGPIO_Open(DCL_GPIO,port);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,NULL);
    DclGPIO_Close(gpio_handle);
}

void kjx_uart_rx_pure(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_PURGE_T data;
	
    data.u4OwenrId = ownerid;
    data.dir = DCL_RX_BUF;
	
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_PURGE, (DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);
}

void kjx_uart_tx_pure(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_PURGE_T data;
	
    data.u4OwenrId = ownerid;
    data.dir = DCL_TX_BUF;
	
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_PURGE, (DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);
}


void kjx_uart_set_owner(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_OWNER_T data;
	
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
}

module_type kjx_uart_get_owner_id(UART_PORT port)
{

	DCL_HANDLE handle;
	UART_CTRL_OWNER_T data;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&data);
	return (module_type)(data.u4OwenrId);
}

void kjx_uart_setDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{

	DCL_HANDLE handle;
	UART_CTRL_DCB_T data;
	DCL_STATUS state_u = 0;
	data.u4OwenrId = ownerid;
	data.rUARTConfig.u4Baud = UART_Config->baud;
	data.rUARTConfig.u1DataBits = UART_Config->dataBits;
	data.rUARTConfig.u1StopBits = UART_Config->stopBits;
	data.rUARTConfig.u1Parity = UART_Config->parity;
	data.rUARTConfig.u1FlowControl = UART_Config->flowControl;
	data.rUARTConfig.ucXonChar = UART_Config->xonChar;
	data.rUARTConfig.ucXoffChar = UART_Config->xoffChar;
	data.rUARTConfig.fgDSRCheck = UART_Config->DSRCheck;


	handle = DclSerialPort_Open(port,0);
	state_u = DclSerialPort_Control(handle,SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
	LOGD("kjx_uart_setDCBConfig,baud=%d,state_u=%d",UART_Config->baud,state_u);
}


 kal_uint16 kjx_rfid_uart_write_data(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{

    DCL_HANDLE handle;
    UART_CTRL_PUT_BYTES_T data;

    kjx_uart_clear_tx_buf(RFID_UART_PORT,MOD_MMI);
    kjx_uart_clear_rx_buf(RFID_UART_PORT,MOD_MMI);
    kjx_uart_tx_pure(RFID_UART_PORT, MOD_MMI);
    kjx_uart_rx_pure(RFID_UART_PORT, MOD_MMI);
	 
    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;

    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;
}
extern nvram_ef_kjx_nvram_struct g_kjx_nvram_struct;

U16 kjx_dj_uart_write(U8 *buffer,U16 len)
{
	LOGD("kjx_dj_uart_write %d",kjx_dj_get_mode_state());
	if(kjx_dj_get_mode_state())
	{
	
		LOGD("%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,",
				buffer[0],
				buffer[1],
				buffer[2],
				buffer[3],
				buffer[4],
				buffer[5],
				buffer[6],
				buffer[7]);
		return kjx_rfid_uart_write_data(RFID_UART_PORT,buffer,len,MOD_MMI);
	}
	else
	{
		
	}
	
	return 0;
}
kal_uint16 kjx_rfid_uart_read_data(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_GET_BYTES_T data;

    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;
    data.pustatus = 0;
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;
}

kal_uint16 kjx_rfid_uart_get_rx_avail(UART_PORT port)
{
    DCL_HANDLE handle;
    UART_CTRL_RX_AVAIL_T data;
    
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
    return data.u2RetSize;
}


void kjx_rfid_uart_turnon_power(UART_PORT port, kal_bool on)
{
    DCL_HANDLE handle;
    UART_CTRL_POWERON_T data;
    
    handle = DclSerialPort_Open(port, 0);
    data.bFlag_Poweron = on;
    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
}

kal_bool kjx_rfid_uart_close(UART_PORT port, module_type ownerid)
{
	DCL_HANDLE handle;
	UART_CTRL_CLOSE_T data;
	DCL_STATUS status;
	data.u4OwenrId = ownerid;
	
    handle = DclSerialPort_Open(port,0);
	status = DclSerialPort_Control(handle,SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
    if(STATUS_OK != status)
        return KAL_FALSE;
    else
        return KAL_TRUE;
}

void kjx_rfid_test_close_uart(void)
{
    kjx_rfid_uart_close(0, MOD_MMI);
}

kal_bool kjx_rfid_uart_open(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_OPEN_T data;
    DCL_STATUS status;
    data.u4OwenrId = ownerid;	
	
    handle = DclSerialPort_Open(port, 0);
    status = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
    if(STATUS_OK != status)
        return KAL_FALSE;
    else
        return KAL_TRUE;
}

void kjx_rfid_decode_data(kal_uint8 *databuf, kal_uint16 datalen)
{
	uint8 temBuf[16];
	U8 checktmp = 0;
#if defined(__KJX_POSITION_TRIGGER_PLAY__)||defined(__KJX_SERVER_CMD_PLAY__)
	extern U8 g_play_cause;
#endif
	U32 myId = 0x00000000;
	extern U32 kjx_rfid_id;
	U8 flag,filter,field;

#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("%02x %02x %02x %02x %02x %02x %02x %02x",  
				databuf[0],databuf[1],databuf[2],databuf[3],databuf[4],databuf[5],databuf[6],databuf[7]);
#endif
#endif

	checktmp = databuf[0]^databuf[1]^databuf[2]^databuf[3]^databuf[4]^databuf[5];
	if((databuf[0] != 0xDD)||(databuf[7] != 0x55))
	{
	#ifdef RFID_UART_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("data error");
	#endif
    #endif
		return;
	}
	else if(checktmp != databuf[6])
	{
	#ifdef RFID_UART_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)                                                                                                                                                                                                             
		LOGD("check error, checktmp:%d, rfidData[6]:%d", checktmp, databuf[6]);
	#endif
	#endif
	}
	else
	{
		//flag status
		flag = (databuf[5]&0x80)>>7;
	#ifdef RFID_UART_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("flag:%d", flag);
	#endif
	#endif
		
		//filter status
		filter = (databuf[5]&0x71)>>4;
	#ifdef RFID_UART_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("filter:%d", filter);
	#endif
	#endif

		//field status
		field = (databuf[5]&0x0E)>>1;
	#ifdef RFID_UART_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("field:%d", field);
	#endif
	#endif

	#ifdef RFID_UART_DEBUG
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("g_start_rfid:%d", g_start_rfid);
	#endif
	#endif
		
		//ID
		memset(temBuf, 0x00, sizeof(temBuf));
		sprintf(temBuf,"%02x%02x%02x%02x",databuf[1],databuf[2],databuf[3],databuf[4]);
		myId = atoi(temBuf);

	#if defined(__KJX_RESET_USED_COUNT__)&&!defined(__KJX_AGAINST_THEFT_TO_PILE__)
		if(myId == RESET_RFID)
		{
			kjx_handle_receive_reset_rfid(0);
		}
		else
	#endif
		{
	    #ifdef RFID_UART_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("temBuf:%s, myId:%d", temBuf, myId);
		#endif
	    #endif

		#ifdef __KJX_AGAINST_THEFT__
			strcpy(g_str_rfid_against, temBuf);
		
			if(g_rfid_against_theft)
			{
			#ifdef RFID_UART_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("已经触发报警状态");
			#endif
			#endif

				return;
			}
		#ifdef __KJX_AGAINST_THEFT_BY_RFID_NUM__
			else if(myId == AGAINST_RFID)
			{
			#ifdef RFID_UART_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("报警发射源触发报警!");
			#endif
			#endif
		
				kjx_start_against_theft_alarm();
				return; 	
			}
		#else
			else if(flag == 1)
			{
			#ifdef RFID_UART_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("报警桩触发报警!");
			#endif
			#endif

				kjx_start_against_theft_alarm();
				return;		
			}
		#endif

		#ifdef __KJX_AGAINST_THEFT_TO_PILE__
			else
			{
			#ifdef RFID_UART_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("触发防盗报警桩报警!");
			#endif
			#endif

				kjx_start_against_theft_alarm();
				return;	
			}
		#endif
		#endif
		
			//bat status
			if(databuf[5]&0x01)
			{
				g_rfid_low_bat = FALSE;
			}
			else
			{
				g_rfid_low_bat = TRUE;
			}
			
			//field status
			g_rfid_field = (databuf[5]&0x0E)>>1;
			if(kjx_get_foctory_test_mode() == 1)
			{
				rfid_field_count[rfid_field_index++] = g_rfid_field;
				if(rfid_field_index > sizeof(rfid_field_count) -1)
					rfid_field_index = 0;
			}

		#ifdef RFID_UART_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("g_start_rfid:%d, kjx_rfid_low_bat:%d, g_rfid_field:%d", g_start_rfid, g_rfid_low_bat, g_rfid_field);
		#endif
		#endif

		#if defined(__KJX_POSITION_TRIGGER_PLAY__)||defined(__KJX_SERVER_CMD_PLAY__)
			g_play_cause = 0;
		#endif

			if(IsMyTimerExist(KJX_TIMER_RESET_SHOW))
				return;
			
			g_kjx_rfid_id = myId;
			kjx_rfid_id = myId;

			if(kjx_get_foctory_test_mode() == 0)	//xb add 2017-08-24 工厂测试模式下面只收数据不播放
	        {
	        	kjx_rfid_check_id();				
			}
		}
	}
}

/*****************************************************************************
* FUNCTION
*  	kjx_rfid_get_data
* DESCRIPTION
*   获取RFID数据: Head(1byte)+ID(4bytes)+Status(1byte)+Check(1byte)+End(1byte)
*                       包头:	0xDD；
*                       ID:	发射模块的ID（高字节在前，16进制）；
*                       Status:	(1)低电标志
*									最低位为0  即xxxx xxx0  低电量
*                                 	最低位为1  即xxxx xxx1  电量正常
*								(2)场强度
*									低字节的高三位表示
*									即xxxx 001x，取值范围0~5
*                       校验字：包头开始至电量状态的异或校验；
*                       包尾：0x55；
* PARAMETERS
*
* RETURNS
*	none
* 
* Author
*   xiebiao 2016-08-23
*****************************************************************************/
void kjx_rfid_get_data(U16 dataLen)
{
	U16 i = 0;
	uint8 rfidData[128];

#if 1	//def RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("dataLen:%d", dataLen);
#endif
#endif
	
	while(i < dataLen)
	{
		if(ObdUartBuffer[i+0] == 0xDD && ObdUartBuffer[i+7] == 0x55)
		{
			memset(rfidData, 0x00, sizeof(rfidData));
			memcpy(rfidData, (void*)&ObdUartBuffer[i], 8);
			kjx_rfid_decode_data(rfidData, 8);

			i+=8;
			if(i >= dataLen)
				break;
		}
		else
		{
			i++;
		}
	}
}

void kjx_rfid_uart_handler(void *msg)
{
    uart_ready_to_read_ind_struct *tmp = (uart_ready_to_read_ind_struct *)msg;
    kal_uint16 len=0,write_len=0,send_len=0;
    int i=0;
    static BOOL is_close = FALSE;

	if(tmp->port == RFID_UART_PORT)
	{
		if(srv_shutdown_is_running())
		{
		#ifdef RFID_UART_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("shutdown_is_running return");
		#endif
		#endif
			return;
		}

	    len = kjx_rfid_uart_get_rx_avail(RFID_UART_PORT);
	    if(len > 0)
	    {
	        memset(ObdUartBuffer, 0, sizeof(ObdUartBuffer));
	        len = kjx_rfid_uart_read_data(RFID_UART_PORT, ObdUartBuffer, RFID_BUFF_MAX_LEN, MOD_MMI);
			if(len > 0)
			{
				LOGD("%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,",
						ObdUartBuffer[0],
						ObdUartBuffer[1],
						ObdUartBuffer[2],
						ObdUartBuffer[3],
						ObdUartBuffer[4],
						ObdUartBuffer[5],
						ObdUartBuffer[6],
						ObdUartBuffer[7]);
			}
			else
			{
				LOGD("recv 0");
			}
	    }
		else
		{
			LOGD("recv1 0");
		}
	 
	    kjx_uart_clear_rx_buf(RFID_UART_PORT, MOD_MMI);//清空接收缓冲区
	    kjx_uart_rx_pure(RFID_UART_PORT, MOD_MMI);

		if(kjx_dj_get_mode_state())
		{
			LOGD("djjjjjj recv");
			kjx_dj_get_req(ObdUartBuffer,len);
			
		}
		else
		{
			if(len > 0)
			{	 
				kjx_rfid_get_data(len);
			}
			
			kjx_rfid_eint_turn_off_uart();//xb add 2016-09-23 读取完成关闭串口以省电
		}
	}
#ifdef __KJX_FUN_GPS__
	else if(tmp->port == FUN_GPS_UART)
	{
		kjx_gps_recv_data_from_uart(msg);
	}
#endif
}


// 禁止休眠，休眠后串口收发会有问题
void kjx_rfid_uart_set_sleep(kal_bool state)
{
#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("state:%d", state);
#endif
#endif

	if(KAL_TRUE == state)
	{
		if(0xff == g_SleepMode)
            g_SleepMode = L1SM_GetHandle();

		L1SM_SleepDisable(g_SleepMode);
	}
	else
	{
		if(0xff == g_SleepMode)
			g_SleepMode = L1SM_GetHandle();

	#ifdef __KJX_FUN_GPS__
		if(g_gps_is_on == 0)
	#endif	
		L1SM_SleepEnable(g_SleepMode);
	}
}


void kjx_rfid_disable_sleep(void)
{
#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(g_SleepMode==0xff)
		return;

	g_rfid_is_on = 1;
	L1SM_SleepDisable(g_SleepMode);
}

void kjx_rfid_enable_sleep(void)
{
#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if(g_SleepMode==0xff)
		return;

	g_rfid_is_on = 0;
	
#ifdef __KJX_FUN_GPS__
	if(g_gps_is_on == 0)
#endif
	L1SM_SleepEnable(g_SleepMode);
	kal_sleep_task(1);
}

 
void kjx_rfid_turn_on(void)
{
#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("begin");
#endif
#endif

	if(g_SleepMode==0xff)
		return;

	kjx_rfid_disable_sleep();
}

void kjx_rfid_turn_off(void)
{ 
#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	//LOGD("begin");
#endif
#endif

	if(g_SleepMode==0xff)
		return;

	kjx_rfid_enable_sleep();
}

BOOL kjx_rfid_is_on(void)
{
#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("g_rfid_is_on:%d", g_rfid_is_on);
#endif
#endif

    if(g_rfid_is_on)
        return TRUE;
    else
        return FALSE;
}

void kjx_rfid_close(void)
{
	DCL_HANDLE gpio_handle;

	kjx_rfid_uart_close(RFID_UART_PORT, MOD_MMI);
	kjx_rfid_uart_turnon_power(RFID_UART_PORT, KAL_FALSE);
	
	gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_RFID_PWR_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
	DclGPIO_Close(gpio_handle);

	gpio_handle = DclGPIO_Open(DCL_GPIO,RFID_UART_URXD_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
	DclGPIO_Close(gpio_handle);
	
	gpio_handle = DclGPIO_Open(DCL_GPIO,RFID_UART_UTXD_PIN);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
	DclGPIO_Close(gpio_handle);	 
}

void kjx_rfid_uart_init(void)
{  	
	DCL_HANDLE gpio_handle;

#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif	
	rfid_is_use_uart = TRUE;
	gObdUartOwner = kjx_uart_get_owner_id(RFID_UART_PORT);//记录我们要用的串口的当前占有者

	//if(kjx_uart_get_owner_id(RFID_UART_PORT) != MOD_MMI)
	{
		kjx_rfid_uart_close(RFID_UART_PORT, gObdUartOwner);
	}
	//kjx_rfid_uart_turnon_power(RFID_UART_PORT, KAL_FALSE);

	gpio_handle = DclGPIO_Open(DCL_GPIO, RFID_UART_URXD_PIN);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_1, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Close(gpio_handle);
		
	gpio_handle = DclGPIO_Open(DCL_GPIO, RFID_UART_UTXD_PIN);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_1, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Close(gpio_handle);

	gpio_handle = DclGPIO_Open(DCL_GPIO, FUN_RFID_PWR_PIN);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Close(gpio_handle);

	kjx_uart_set_owner(RFID_UART_PORT, MOD_MMI);//申明要占用这个串口
	kjx_rfid_uart_turnon_power(RFID_UART_PORT, KAL_TRUE);
	kjx_rfid_uart_open(RFID_UART_PORT, MOD_MMI);
	kjx_uart_setDCBConfig(RFID_UART_PORT, &UART_DefaultConfig,MOD_MMI);//配置串口
    kjx_uart_tx_pure(RFID_UART_PORT, MOD_MMI);
    kjx_uart_rx_pure(RFID_UART_PORT, MOD_MMI);
	kjx_uart_clear_tx_buf(RFID_UART_PORT, MOD_MMI);//清空发送缓冲区
	kjx_uart_clear_rx_buf(RFID_UART_PORT, MOD_MMI);//清空接收缓冲区

	if(g_SleepMode == 0xff)
		g_SleepMode = L1SM_GetHandle();

	StartTimer(KJX_TIMER_ID_RFID_CLOSE, 1000, kjx_rfid_turn_off);

#ifndef WIN32 
    U_Register_RX_cb(RFID_UART_PORT, MOD_MMI, UART_dafault_rx_cb);
    U_Register_TX_cb(RFID_UART_PORT, MOD_MMI, UART_dafault_tx_cb);
#endif

    mmi_frm_set_protocol_event_handler(MSG_ID_UART_READY_TO_READ_IND, kjx_rfid_uart_handler, MMI_TRUE);
}

void kjx_dj_uart_init(void)
{  	
	DCL_HANDLE gpio_handle;

#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif	
	rfid_is_use_uart = TRUE;
	gObdUartOwner = kjx_uart_get_owner_id(RFID_UART_PORT);//记录我们要用的串口的当前占有者
	//kjx_rfid_close();
	//if(kjx_uart_get_owner_id(RFID_UART_PORT) != MOD_MMI)
	{
		kjx_rfid_uart_close(RFID_UART_PORT, gObdUartOwner);
	}

	gpio_handle = DclGPIO_Open(DCL_GPIO, RFID_UART_URXD_PIN);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_1, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Close(gpio_handle);
		
	gpio_handle = DclGPIO_Open(DCL_GPIO, RFID_UART_UTXD_PIN);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_1, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Close(gpio_handle);

	gpio_handle = DclGPIO_Open(DCL_GPIO, FUN_RFID_PWR_PIN);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Close(gpio_handle);

	kjx_uart_set_owner(RFID_UART_PORT, MOD_MMI);//申明要占用这个串口
	kjx_rfid_uart_turnon_power(RFID_UART_PORT, KAL_TRUE);
	kjx_rfid_uart_open(RFID_UART_PORT, MOD_MMI);
	kjx_uart_setDCBConfig(RFID_UART_PORT, &DJ_dcbcfg,MOD_MMI);//配置串口
    kjx_uart_tx_pure(RFID_UART_PORT, MOD_MMI);
    kjx_uart_rx_pure(RFID_UART_PORT, MOD_MMI);
	kjx_uart_clear_tx_buf(RFID_UART_PORT, MOD_MMI);//清空发送缓冲区
	kjx_uart_clear_rx_buf(RFID_UART_PORT, MOD_MMI);//清空接收缓冲区

	if(g_SleepMode == 0xff)
		g_SleepMode = L1SM_GetHandle();

	//StartTimer(KJX_TIMER_ID_RFID_CLOSE, 1000, kjx_rfid_turn_off);

#ifndef WIN32 
    U_Register_RX_cb(RFID_UART_PORT, MOD_MMI, UART_dafault_rx_cb);
    U_Register_TX_cb(RFID_UART_PORT, MOD_MMI, UART_dafault_tx_cb);
#endif

    mmi_frm_set_protocol_event_handler(MSG_ID_UART_READY_TO_READ_IND, kjx_rfid_uart_handler, MMI_TRUE);
}


void kjx_rfid_eint_turn_off_uart(void)
{
	ilm_struct *fmr_ilm;

	if(!kjx_rfid_is_on())
		return;
#if 1	//xb add 2016-09-23 
	kjx_rfid_turn_off();
#else
	DRV_SendPrimitive(fmr_ilm,MOD_UART1_HISR,MOD_RFID_EINT,MSG_ID_FUN_TURN_OFF_RFID_EINT_REQ,NULL, KJX_RFID_EINT);
	msg_send_ext_queue(fmr_ilm);
#endif
}

void kjx_read_gpio_5(void)
{
	char value = 0;
	
	StopTimer(KJX_TIMER_ID_PLAY_TTS_AFTER+1);

	value = GPIO_ReadIO(5);
	StartTimer(KJX_TIMER_ID_PLAY_TTS_AFTER+1,1000, kjx_read_gpio_5);
}

void kjx_rfid_eint_init(void)
{ 
	char value = 0;
	static BOOL firstInto = TRUE;

#ifdef RFID_UART_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	StopTimer(KJX_TIMER_ID_RFID_EINT_INIT);
	
	if(!firstInto)
	{
		g_rfid_test_timer = TRUE;
	}

	firstInto = FALSE;
	
	if(kjx_rfid_will_stop_work())
	{
		StartTimer(KJX_TIMER_ID_RFID_EINT_INIT,1000*30, kjx_rfid_eint_init);
		return;
	}
	GPIO_ModeSetup(5,3);
	GPIO_InitIO(0, 5);

	GPIO_ModeSetup(49,1);
	GPIO_InitIO(0, 49);

	GPIO_ModeSetup(50,1);
	GPIO_InitIO(0, 50);

	GPIO_ModeSetup(51,1);
	GPIO_InitIO(0, 51);

	GPIO_ModeSetup(52,1);
	GPIO_InitIO(0, 52);

	GPIO_ModeSetup(53,1);
	GPIO_InitIO(0, 53);
   
}

#endif/*__KJX_RFID__*/
#endif/*__KJX_FUN__*/
