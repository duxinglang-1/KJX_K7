#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
#include "kal_release.h"
#include "dcl.h"
#include "gsensor_sensor_I2C.h"
#include "us_timer.h"               /* For ust_get_current_time() API*/
#include "Dcl_uart.h"

extern const char gpio_ms_i2c_clk_pin;
extern const char gpio_ms_i2c_data_pin;


#define  DELAY_TIME  1100    /* uSec */
#define SDA  gpio_ms_i2c_data_pin //94    //69 //把你的SDA 的GPIO 号 代替
#define SCL   gpio_ms_i2c_clk_pin  // (2|0x80)    //68   //把你的SCL 的GPIO 号 代替
#define  SDA_Port  SDA_Port_read(gpio_ms_i2c_data_pin)
#define GPIO_IO_HIGH 1
#define GPIO_IO_LOW  0

  //其余设置不要动
UINT8 Addr_RW;

#define MS_I2C_DELAY \
{\
	volatile int count=0;\
	for(;count<DELAY_TIME;count++);\
}


UINT8 SDA_Port_read(UINT8 port)
{
     DCL_HANDLE handle;
     GPIO_CTRL_READ_T rf_read;
	 
     handle=DclGPIO_Open(DCL_GPIO,port);	
     DclGPIO_Control(handle,GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&rf_read);
     DclGPIO_Close(handle);

	dbg_print("rf_read.u1IOData  %d  \r\n",rf_read.u1IOData);
     return (kal_uint8)rf_read.u1IOData;
}


/*********** Set Config registar **********************/
void Set_SDA_IO(void)
{
    DCL_HANDLE handle;
	
    handle=DclGPIO_Open(DCL_GPIO,SDA);	
    DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,NULL);
    DclGPIO_Close(handle);    
}

void Set_SCL_IO(void)
{
    DCL_HANDLE handle;
	
    handle=DclGPIO_Open(DCL_GPIO,SCL);	
    DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,NULL);
    DclGPIO_Close(handle);    
}

void SetSDAInput(void)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO,SDA);	
    DclGPIO_Control(handle,GPIO_CMD_SET_DIR_IN,NULL);	
    DclGPIO_Close(handle);   
}

void SetSDAOutput(void)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO,SDA);	
    DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,NULL);	
    DclGPIO_Close(handle);  
}

void SetSCLOutput(void)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO,SCL);	
    DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,NULL);	
    DclGPIO_Close(handle);   
}

void SetSCLHigh(void)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO,SCL);	
    DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,NULL);	
    DclGPIO_Close(handle);   
}

void SetSCLLow(void)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO,SCL);	
    DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,NULL);	
    DclGPIO_Close(handle);   
}

void SetSDAHigh(void)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO,SDA);	
    DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,NULL);	
    DclGPIO_Close(handle);  
}

void SetSDALow(void)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO,SDA);	
    DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,NULL);	
    DclGPIO_Close(handle);  
}


/******* Delay a lTime uSec ********/
void DelayTime( lTime )
{
    /* make a delay process at hera */
    unsigned long i;

    for(i=0;i<lTime;i++)
    {
        ;
    }
}

UINT8 GetACKSign(void) 
{
    UINT8 ACKSign;

    SetSDAInput();
 //   SetSDAHigh();
    DelayTime(DELAY_TIME);
    SetSCLHigh();
    DelayTime(DELAY_TIME);
    
    ACKSign= SDA_Port;      /* Get a bit signal from SDA port */ 
    return ACKSign;
}

void SendACKSign(void)
{
    SetSDAOutput();
    DelayTime(DELAY_TIME);
    SetSDALow();
    DelayTime(DELAY_TIME);
    
    SetSCLHigh();
    DelayTime(DELAY_TIME);
    SetSCLLow(); 
}
void SendNoACKSign(void)
{
   // SetSDAOutput();
    DelayTime(DELAY_TIME);
    //SetSDALow();
    DelayTime(DELAY_TIME);
    
    SetSCLHigh();
    DelayTime(DELAY_TIME);
    SetSCLLow(); 


}
UINT16 I2COpen(void)
{
    Set_SDA_IO(); 
    Set_SCL_IO(); 

    SetSDAOutput(); 
    SetSCLOutput(); 

    SetSCLHigh();  
    SetSDAHigh();

    return I2CERR_NO_ERROR; 
}

UINT16 I2CClose(void)   
{

    SetSDAOutput(); 
    SetSCLOutput(); 

    SetSCLHigh();
    SetSDAHigh();

    return I2CERR_NO_ERROR; 
}

UINT16  I2CStart(void)
{
	DCL_HANDLE sda_handle, scl_handle;
		
	sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	scl_handle = DclGPIO_Open(DCL_GPIO, SCL);
		
	DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
    
	DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);		
	DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);

	DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	MS_I2C_DELAY;
	DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
	MS_I2C_DELAY;

	DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
	MS_I2C_DELAY;
	DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
	MS_I2C_DELAY;

	DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
	MS_I2C_DELAY;
	DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
	MS_I2C_DELAY;
	return 0;
}


/*
UINT16 I2CStart(void) 
{
    int i;
    UINT8 Data_Bit,ACKSign,TmpDat;
    Data_Bit = 8;

    SetSDAOutput();
    SetSCLOutput();
    SetSCLHigh();
    SetSDAHigh();
    DelayTime(DELAY_TIME);
    
    SetSDALow();
    DelayTime(DELAY_TIME);
    
    SetSCLLow();  
    DelayTime(DELAY_TIME);

    
    for(i=7;i>=0;i--)
    {
        DelayTime(DELAY_TIME);
        Data_Bit=(Addr_RW>>i)& 0x01; 
        
        if(Data_Bit)
            SetSDAHigh();
        else
            SetSDALow();
        
        DelayTime(DELAY_TIME);
        SetSCLHigh();
        
        DelayTime(DELAY_TIME);
        SetSCLLow();
        DelayTime(DELAY_TIME);
        
    }

   return GetACKSign();

}
*/
UINT16 I2CStop(void)
{
	DCL_HANDLE sda_handle, scl_handle;
 	
	sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
	scl_handle = DclGPIO_Open(DCL_GPIO, SCL);
	
	DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
	
	DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	
	DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	MS_I2C_DELAY;
	DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
	MS_I2C_DELAY;

	DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
	MS_I2C_DELAY;
	DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
	MS_I2C_DELAY; 
	return I2CERR_NO_ERROR; 
}

/*
UINT16 I2CStop(void)
{
    SetSDAOutput();
    SetSCLOutput();
    SetSCLLow();
    SetSDALow();
    DelayTime(DELAY_TIME);
    
    SetSCLHigh();
    DelayTime(DELAY_TIME);

    SetSDAHigh();
    DelayTime(DELAY_TIME);  

    return I2CERR_NO_ERROR; 
}*/


UINT16 I2CSetTransferMode( BYTE dwMode )
{

   switch (dwMode)
    {
       case 0:
              Addr_RW =Addr_RW & 0xFE;
              break;
       case 1:
              Addr_RW =Addr_RW | 0x01;
              break;
       default:
             break;
          
    }
 
    return I2CERR_NO_ERROR; 
}


UINT16 I2CSetSlaveAddress( BYTE bSlave )
{
    UINT8 TmpDat;

    TmpDat = bSlave<<1;
    Addr_RW = TmpDat&0xfe;

    return I2CERR_NO_ERROR; 
}

BOOL I2CWriteData(BYTE ucData)
{
	//kal_bool bRet;
	int i;
	kal_bool ret;
	kal_uint8 ucMask;
	DCL_STATUS status = STATUS_INVALID_OPERATION;
	GPIO_CTRL_READ_T sda_read;
	I2C_CTRL_CONT_WRITE_T write;
	DCL_HANDLE sda_handle, scl_handle;
#if 0
	if(gpio_ms_i2c_data_pin == 0xFF) // HW I2C
	{
		if(ms_i2c_configure_done)
		{
			write.pu1Data = &ucData;
			write.u4DataLen = 1;
			write.u4TransferNum = 1;
			status = DclSI2C_Control(ms_i2c_handle, I2C_CMD_CONT_WRITE, (DCL_CTRL_DATA_T *)&write);
		}
		ret = (status == STATUS_OK)?KAL_TRUE:KAL_FALSE;
	}
	else
#endif
	{
		sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
		scl_handle = DclGPIO_Open(DCL_GPIO, SCL);
		
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
		
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		
		for(i = 0, ucMask = 0x80; i < 8; i++, ucMask >>= 1)
		{
			if(ucData & ucMask)
				DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
			else
				DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
			MS_I2C_DELAY;
			DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
			MS_I2C_DELAY;
			DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
			MS_I2C_DELAY;
		}
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_IN, NULL);
	
		DclGPIO_Control(sda_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&sda_read);
		
		DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
		MS_I2C_DELAY;
		DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
		MS_I2C_DELAY;
	
		ret = (sda_read.u1IOData == GPIO_IO_HIGH)?KAL_TRUE:KAL_FALSE;
	}
	return ret;
}

/*
UINT16 I2CWriteData( BYTE bData )
{
    UINT8 Data_Bit,ACKSign,TmpDat;
    SINT8 i;

    SetSDAOutput();
    SetSCLLow();
    
    for(i=7;i>=0;i--)
    {
        DelayTime(DELAY_TIME);
        Data_Bit=(bData>>i)& 0x01;

        if(Data_Bit)
            SetSDAHigh();
        else
            SetSDALow();
        
        DelayTime(DELAY_TIME);
        SetSCLHigh();
        DelayTime(DELAY_TIME);
        SetSCLLow();
        
    }
    ACKSign=GetACKSign();

    return ACKSign;

}
*/

kal_uint8 I2CReadData(UINT8* pbData, UINT8 bAck)
{
	kal_uint8 ucRet = 0;
	int i;
	I2C_CTRL_CONT_READ_T read;
	GPIO_CTRL_READ_T sda_read;
	DCL_STATUS status;
	DCL_HANDLE sda_handle, scl_handle;
#if 0
	if(SDA == 0xFF) // HW I2C
	{
		if(ms_i2c_configure_done)
		{
			read.pu1Data = &ucRet;
			read.u4DataLen = 1;
			read.u4TransferNum = 1;
			status = DclSI2C_Control(ms_i2c_handle, I2C_CMD_CONT_READ, (DCL_CTRL_DATA_T *)&read);
			if(status != STATUS_OK)
				return 0;
		}
	}
	else
#endif

	{
		sda_handle = DclGPIO_Open(DCL_GPIO, SDA);
		scl_handle = DclGPIO_Open(DCL_GPIO, SCL);
		
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
		
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_IN, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		
		for(i = 7; i >= 0; i--)
		{
			DclGPIO_Control(sda_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&sda_read);
			ucRet |= sda_read.u1IOData << i;
	
			DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
			MS_I2C_DELAY;
			DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
			MS_I2C_DELAY;
		}
	
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	
		if(bAck)
			DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
		else
			DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
		MS_I2C_DELAY;
	
		DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
		MS_I2C_DELAY;
		DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
		MS_I2C_DELAY;

	}
	
	* pbData = ucRet;
	  return I2CERR_NO_ERROR;
}

#if 0
UINT16 I2CReadData( UINT8* pbData, UINT8 bAck )
{
    UINT8 Data_Bit,ACKSign;
    UINT8 readdata = 0;
    UINT8 i=8;
    
    SetSDAInput(); 
//    SetSDAHigh();
    readdata = SDA_Port ; 
   dbg_print("readdata1 :    %d  \r\n",readdata);	
    while (i--)
    {
        readdata<<=1;
        SetSCLLow(); 
        DelayTime(DELAY_TIME);
        
        SetSCLHigh(); 
        DelayTime(DELAY_TIME);
        readdata |= SDA_Port ;      /* Get a bit signal from SDA port */ 
     }
    SetSCLLow(); 
    DelayTime(DELAY_TIME);

    * pbData = readdata;

	  dbg_print("readdata :    %d  \r\n",readdata);
if(bAck == 1)
{
    SendACKSign();
}
else
{
   SendNoACKSign();
}
    
    return I2CERR_NO_ERROR;
}
#endif

UINT16 I2CGetConnectionType( BYTE* pbType )
{
    return I2CERR_NO_ERROR;
}
#endif
