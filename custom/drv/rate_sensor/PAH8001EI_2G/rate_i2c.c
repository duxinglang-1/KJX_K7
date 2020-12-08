

#include "kal_release.h"
#include "custom_config.h"
#include "gpio_sw.h"
#include "drv_comm.h"
#include "eint.h"
#include "motion_sensor.h"
#include "rate_sensor_custom.h"
#include "rate_sensor_I2C.h"
#include "motion_sensor_hw_define.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "dcl.h"
#include "us_timer.h"
#include "rate_i2c_custom.h"


/******************************************
	us delay for software I2C
	uint:us
*******************************************/
void SW_i2c_MAG3110_udelay(kal_uint32 delay)
{
	kal_uint32 ust = 0; //ust_get_current_time
	kal_uint32 count = 0;
	kal_uint32 break_count = 0;
	
	ust = ust_get_current_time();
	do{
		if(ust_get_current_time() != ust)
			count++;
		else
			break_count++;
	}while((count < delay) && (break_count < 0xFFFFFF));
}
/******************************************
	software I2C start bit
*******************************************/
void SW_i2c_MAG3110_start(void)
{
	MS_CLK_PIN_GPIO_MODE;
	MS_I2C_CLK_OUTPUT;

	MS_DATA_PIN_GPIO_MODE;
	MS_I2C_DATA_OUTPUT;
	
	MS_I2C_DATA_HIGH;
	MS_I2C_CLK_HIGH;
	SW_i2c_MAG3110_udelay(40);		//20
	MS_I2C_DATA_LOW;
	SW_i2c_MAG3110_udelay(20);		//10
	MS_I2C_CLK_LOW;
	SW_i2c_MAG3110_udelay(20);		//10
}

/******************************************
	software I2C stop bit
*******************************************/
void SW_i2c_MAG3110_stop(void)
{
	MS_I2C_CLK_OUTPUT;
	MS_I2C_DATA_OUTPUT;
	
	SW_i2c_MAG3110_udelay(20);		//10
	MS_I2C_CLK_HIGH;
	SW_i2c_MAG3110_udelay(20);		//10
	MS_I2C_DATA_LOW;
	SW_i2c_MAG3110_udelay(20);		//10
	MS_I2C_DATA_HIGH;
}

/******************************************
	software I2C one clock
*******************************************/
void SW_i2c_MAG3110_one_clk(void)
{
	SW_i2c_MAG3110_udelay(10);		//5
	MS_I2C_CLK_HIGH;
	SW_i2c_MAG3110_udelay(20);		//10
	MS_I2C_CLK_LOW;
	SW_i2c_MAG3110_udelay(10);		//5
}

/******************************************
	software I2C read byte with ack
*******************************************/
kal_uint8 ms_ReadByteAck_MAG3110(void)
{
	kal_int8 i;
	kal_uint8 data;

	MS_I2C_DATA_INPUT; 
	data = 0; 
	
	for (i=7; i>=0; i--) 
	{
		if (MS_I2C_GET_BIT)
		{
			data |= (0x01<<i);
		}
		SW_i2c_MAG3110_one_clk();
	}			                                

	MS_I2C_DATA_OUTPUT;                    
	MS_I2C_DATA_LOW;                       
	SW_i2c_MAG3110_one_clk();                         

	return data;
}

/******************************************
	software I2C read byte without ack
*******************************************/
kal_uint8 ms_ReadByteNAck_MAG3110(void)
{
	kal_int8 i;
	kal_uint8 data;

	MS_I2C_DATA_INPUT; 
	data = 0; 
	
	for (i=7; i>=0; i--) 
	{
		if (MS_I2C_GET_BIT)
		{
			data |= (0x01<<i);
		}
		SW_i2c_MAG3110_one_clk();
	}			                                

	MS_I2C_DATA_OUTPUT;                                           
	MS_I2C_DATA_HIGH;
	SW_i2c_MAG3110_one_clk();                         
	
	return data;
}

/******************************************
	software I2C send byte
*******************************************/
void ms_SendByte_MAG3110(kal_uint8 sData) 
{
	kal_int8 i;
	
	for (i=7; i>=0; i--) 
	{            
		if ((sData>>i)&0x01) 
		{               
			MS_I2C_DATA_HIGH;	              
		} 
		else 
		{ 
			MS_I2C_DATA_LOW;                  
		}
		SW_i2c_MAG3110_one_clk();                        
	}		
}
/******************************************
	software I2C check ack bit
*******************************************/
kal_bool ms_ChkAck_MAG3110(void)
{
	MS_I2C_DATA_INPUT;
	SW_i2c_MAG3110_udelay(10);		//5
	MS_I2C_CLK_HIGH;
	SW_i2c_MAG3110_udelay(10);		//5

	if(MS_I2C_GET_BIT)		//Non-ack
	{
		SW_i2c_MAG3110_udelay(10);	//5
		MS_I2C_CLK_LOW;
		SW_i2c_MAG3110_udelay(10);	//5
		MS_I2C_DATA_OUTPUT;
		MS_I2C_DATA_LOW;
		
		return KAL_FALSE;
	}
	else					//Ack
	{
		SW_i2c_MAG3110_udelay(10);	//5
		MS_I2C_CLK_LOW;
		SW_i2c_MAG3110_udelay(10);	//5
		MS_I2C_DATA_OUTPUT;
		MS_I2C_DATA_LOW;

		return KAL_TRUE;
	}
}

/******************************************
	software I2C restart bit
*******************************************/
void ms_Restart_MAG3110(void)
{
	MS_I2C_CLK_OUTPUT;
	MS_I2C_DATA_OUTPUT;

	SW_i2c_MAG3110_udelay(40);
	MS_I2C_DATA_HIGH;
	SW_i2c_MAG3110_udelay(20);		//10
	MS_I2C_CLK_HIGH;
	SW_i2c_MAG3110_udelay(40);
	MS_I2C_DATA_LOW;
	SW_i2c_MAG3110_udelay(20);		//10
	MS_I2C_CLK_LOW;
	SW_i2c_MAG3110_udelay(20);		//10
}



/***************************************************/
/*			motion sensor read and write APIs 				  */
/*=================================================*/
/***************************************************/
/******************************************
	MAG3110 ms delay function
		uint: ms
*******************************************/
void MAG3110_DelayMS(kal_uint16 delay)
{
	kal_uint16 i=0;

	for(i=0; i<delay; i++)
	{
		SW_i2c_MAG3110_udelay(1000);
	}
}

/******************************************
	MAG3110 read bytes
*******************************************/
kal_bool MAG3110_ReadByte(kal_uint8* Data, kal_uint8 RegAddr)
{
	SW_i2c_MAG3110_start();						//start bit
	ms_SendByte_MAG3110(MS_SLAVEADDR_W);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send write id		
		dbg_print("ack fail when send wid in readbytes");
		dbg_print("ack fail when send wid in readbytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}
		
	ms_SendByte_MAG3110(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send RegAddr
		dbg_print("ack fail when send Reg in readbytes");
		dbg_print("ack fail when send Reg in readbytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_Restart_MAG3110();						//restart bit

	ms_SendByte_MAG3110(MS_SLAVEADDR_R);		//slave address|read bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())
	{
		//TO_DO: display ack check fail when send read id		
		dbg_print("ack fail when send rid in readbytes");
		dbg_print("ack fail when send rid in readbytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	*Data = ms_ReadByteNAck_MAG3110();
       dbg_print("ReceiveID[8] %d ",*Data);
	SW_i2c_MAG3110_stop();						//stop bit

	//TO_DO: add debug code to display the data received

	return KAL_TRUE;
	
}

/******************************************
	MAG3110 contunious read bytes
*******************************************/
kal_bool MAG3110_ConReadBytes(kal_uint8* Data, kal_uint8 RegAddr, kal_uint16 Length)
{
	kal_uint8* Data_ptr;
	kal_uint16 i;

	Data_ptr = Data;
	
	SW_i2c_MAG3110_start();						//start bit
	ms_SendByte_MAG3110(MS_SLAVEADDR_W);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send write id		
		dbg_print("ack fail when send wid in conread");
		dbg_print("ack fail when send wid in conread\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}
		
	ms_SendByte_MAG3110(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send RegAddr		
		dbg_print("ack fail when send Reg in conread");
		dbg_print("ack fail when send Reg in conread\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_Restart_MAG3110();						//restart bit

	ms_SendByte_MAG3110(MS_SLAVEADDR_R);		//slave address|read bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())
	{
		//TO_DO: display ack check fail when send read id		
		dbg_print("ack fail when send rid in conread");
		dbg_print("ack fail when send rid in conread\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	for(i=Length; i>1; i--)
	{
		*Data_ptr = ms_ReadByteAck_MAG3110();	//read byte with ack
		Data_ptr++;
	}
	
	*Data_ptr = ms_ReadByteNAck_MAG3110();		//read byte with non-ack to stop reading

	SW_i2c_MAG3110_stop();						//stop bit

	//TO_DO: add debug code to display the data received

	return KAL_TRUE;
}

/******************************************
	MAG3110 write bytes
*******************************************/
kal_bool MAG3110_WriteByte(kal_uint8 RegAddr, kal_uint8 Data)
{
	SW_i2c_MAG3110_start();						//start bit

	ms_SendByte_MAG3110(MS_SLAVEADDR_W);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display check ack fail when send write id
		dbg_print("ack fail when send wid in writebytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_SendByte_MAG3110(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display check ack fail when send RegAddr
		dbg_print("ack fail when send Reg in wirtebytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_SendByte_MAG3110(Data);					//send parameter
	if(KAL_FALSE == ms_ChkAck_MAG3110())
	{
		//TO_DO: display check ack fail when send data
		dbg_print("ack fail when send para in writebytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	SW_i2c_MAG3110_stop();						//stop bit

	return KAL_TRUE;
}


/***************************************************/
/*		    MAG3110 motion sensor driver APIs   	 			  */
/*=================================================*/
/***************************************************/

/******************************************
	motion sensor power control function
[parameters]:
	TRUE 	power on
	FALSE	power off
*******************************************/
kal_bool MAG3110_power_ctrl(unsigned char  Flag)
{
	kal_bool temp_result = KAL_FALSE;
	kal_uint8 temp = 1;
       kal_uint8	reg_val =0;


	if(Flag)
	{ 
		//MAG3110_WriteByte(MS_CTRL_REG2,0x80);	
		//MAG3110_WriteByte(MS_CTRL_REG1,0x01);	
	}
	else
	{
		//MAG3110_WriteByte(MS_CTRL_REG1,0x00);	
	}

	
	return KAL_TRUE;
}

/******************************************
	motion sensor get power status function
	Power on return KAL_TRUE
	Power off return KAL_FALSE
*******************************************/
kal_bool MAG3110_power_status(void)
{
	return 0;
}




/******************************************
	motion sensor read ID function
*******************************************/

void MAG3110_ReadID(void)
{
	kal_uint8 ID_data[2] = {0};
	kal_bool temp_result = KAL_FALSE;
	
	//temp_result = MAG3110_ConReadBytes(ID_data, MS_CHIP_ID, 2);
	temp_result =  MAG3110_ReadByte(ID_data, MS_CHIP_ID);

	//mag3110_reg_data = ID_data[0];

	if(KAL_FALSE == temp_result)
	{
		dbg_print("Motion Sensor read id fail\n\r");
		dbg_print("Motion Sensor read id fail\n\r");

	}
	else
	{   
		dbg_print("CHIP_ID:%x, VERSION_ID:%x \n\r", ID_data[0]);
        dbg_print("VERSION_ID %x ",ID_data[0]);
	}
}


unsigned char Check_Mag3110_exist(void);

unsigned char check_MAG3110_exist(void)
{
 unsigned char ret;
#if 0
    if(MAG3110_exist)
	return 1;
    else
	return 0;
#else
  ret =  Check_Mag3110_exist();
  return ret;
#endif
}

/******************************************
	motion sensor power up function
*******************************************/


#if !defined(__UBL__) && !defined(__FUE__) && !defined(WIN32)
void MSDC_turnOnVMC(kal_bool turnOnLdo);
void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable);
void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up);
#endif

void MAG3110_pwr_up(void)
{
	kal_bool pwr_result = KAL_FALSE;
	kal_bool is_power_on = KAL_FALSE;

	dbg_print("MAG3110_pwr_up\n\r");


  #if defined(_OPT_MAG_I2C_USE_MSDC_) && !defined(WIN32)
    #if !defined(__UBL__) && !defined(__FUE__)
    #if defined(M66)
    MS_CLK_PIN_GPIO_MODE;
    MS_I2C_CLK_OUTPUT;
    
    MS_DATA_PIN_GPIO_MODE;
    MS_I2C_DATA_OUTPUT;
    
    
    GPIO_PullenSetup(MS_SCL,1);
    GPIO_PullSelSetup(MS_SCL,0);
    
    GPIO_PullenSetup(MS_SDA,1);
    GPIO_PullSelSetup(MS_SDA,0);
    #endif

    MSDC_turnOnVMC(1);
    #endif
  #endif



	is_power_on = MAG3110_power_status();

	if(KAL_FALSE == is_power_on)
	{
		pwr_result = MAG3110_power_ctrl(KAL_TRUE);
	
		if(KAL_FALSE == pwr_result)
		{
			dbg_print("Motion Sensor power up fail!");			
			dbg_print("Motion Sensor power up fail!\n\r");
		}
		else
		{
			dbg_print("Motion Sensor power up succeed!\n\r");
		}
	}
	
	MAG3110_ReadID();
}

/******************************************
	motion sensor power down function
*******************************************/
void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable);
void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up);
unsigned char get_mag3110_data(void);
void MAG3110_pwr_down(void)
{
	kal_bool pwr_result = KAL_FALSE;
	kal_bool is_power_on = KAL_FALSE;
	
	dbg_print("MAG3110_pwr_down\n\r");



    #if defined(_OPT_MAG_I2C_USE_MSDC_) && !defined(WIN32)
      #if !defined(__UBL__) && !defined(__FUE__)
      MSDC_turnOnVMC(1);
      #endif
    #endif

       get_mag3110_data();
       get_mag3110_data();
       get_mag3110_data();
	
	is_power_on = MAG3110_power_status();

	if(KAL_TRUE == is_power_on)
	{
		pwr_result = MAG3110_power_ctrl(KAL_FALSE);
	
		if(KAL_FALSE == pwr_result)
		{
			dbg_print("Motion Sensor power down fail!");
			dbg_print("Motion Sensor power down fail!\n\r");
		}
		else
		{
			dbg_print("Motion Sensor power down succeed!\n\r");
		}
	}


       get_mag3110_data();
       get_mag3110_data();
       get_mag3110_data();
	SW_i2c_MAG3110_stop();		

	#if 0
	if(gpio_e_compass_sensor_int_pin!=0xff)
 	{
             GPIO_ModeSetup(gpio_e_compass_sensor_int_pin,0);
             GPIO_InitIO(1,gpio_e_compass_sensor_int_pin);
             GPIO_WriteIO(1,gpio_e_compass_sensor_int_pin);
 	}
	#endif
	

	
}


unsigned char Check_Mag3110_exist(void)
{
   MAG3110_pwr_up();
   MAG3110_pwr_down();

 //  if(mag3110_reg_data == 0xC4)
 //  	return 1;
 //  else
 //  	return 0;
}


void get_magnetic_raw_data(signed short *p_x,signed short *p_y,signed short *p_z)
{
  unsigned short x,y,z;
  unsigned char reg_value[2];

  
 /* MAG3110_ReadByte(&reg_value[0], MS_X_MSB);
  MAG3110_ReadByte(&reg_value[1], MS_X_LSB);
  *p_x = reg_value[0]<<8|reg_value[1];  

  
  MAG3110_ReadByte(&reg_value[0], MS_Y_MSB);
  MAG3110_ReadByte(&reg_value[1], MS_Y_LSB);
  *p_y = reg_value[0]<<8|reg_value[1];  

  
  MAG3110_ReadByte(&reg_value[0], MS_Z_MSB);
  MAG3110_ReadByte(&reg_value[1], MS_Z_LSB);
  *p_z = reg_value[0]<<8|reg_value[1];  */
}

unsigned char get_mag3110_data(void)
{
  unsigned short x,y,z;
  unsigned char reg_value[2];

  /*
  MAG3110_ReadByte(&reg_value[0], MS_STATUS);
  dbg_print("MS_STATUS %x ,",reg_value[0]);

  
  MAG3110_ReadByte(&reg_value[0], MS_X_MSB);
  MAG3110_ReadByte(&reg_value[1], MS_X_LSB);
  x = reg_value[0]<<8|reg_value[1];  
  dbg_print("MS_X %d",x);

  
  MAG3110_ReadByte(&reg_value[0], MS_Y_MSB);
  MAG3110_ReadByte(&reg_value[1], MS_Y_LSB);
  y = reg_value[0]<<8|reg_value[1];  
  dbg_print("MS_Y %d",y);

  
  MAG3110_ReadByte(&reg_value[0], MS_Z_MSB);
  MAG3110_ReadByte(&reg_value[1], MS_Z_LSB);
  z = reg_value[0]<<8|reg_value[1];  
  dbg_print("MS_Z %d",z);
*/
  return 1;
}

void MAG3110_handler(void *ptr)
{
   get_mag3110_data();
   //uem_start_timer(MAG3110_SENSOR_TIMER,MAG3110_handler,1080);   
}

void MAG3110_test_func(void)
{
  static unsigned char start_symbol=0;

  if(start_symbol)
  	return;
  else
  	start_symbol = 1;
  
  MAG3110_pwr_up();
  //uem_start_timer(MAG3110_SENSOR_TIMER,MAG3110_handler,1000);
}

typedef    signed char           u8;

kal_int16 st_x,st_y,st_z,st_fall_state;
kal_int32 st_pressure;

u8 I2C_ReadID( u8 DeviceAddress)
{

    kal_uint8 ReceiveID[11] = {0};
    
	kal_bool temp_result = KAL_FALSE;
	SW_i2c_MAG3110_start();
    ms_SendByte_MAG3110(DeviceAddress| 0x01);
    if(!ms_ChkAck_MAG3110())
        {
          dbg_print("ST Sensor read id fail\n\r");
          SW_i2c_MAG3110_stop();
          return 0;
        }  
	ReceiveID[0]=ms_ReadByteAck_MAG3110();
	ReceiveID[1]=ms_ReadByteAck_MAG3110();
	ReceiveID[2]=ms_ReadByteAck_MAG3110();
	ReceiveID[3]=ms_ReadByteAck_MAG3110();
	ReceiveID[4]=ms_ReadByteAck_MAG3110();
	ReceiveID[5]=ms_ReadByteAck_MAG3110();
	ReceiveID[6]=ms_ReadByteAck_MAG3110();
	ReceiveID[7]=ms_ReadByteAck_MAG3110();
	ReceiveID[8]=ms_ReadByteAck_MAG3110();
	ReceiveID[9]=ms_ReadByteAck_MAG3110();
       ReceiveID[10]=ms_ReadByteNAck_MAG3110();
    SW_i2c_MAG3110_stop();
    dbg_print("0VERSION_ID %x ",ReceiveID[0]);
    dbg_print("1VERSION_ID %x ",ReceiveID[1]);
    dbg_print("2VERSION_ID %x ",ReceiveID[2]);
    dbg_print("3VERSION_ID %x ",ReceiveID[3]);
   st_pressure =( kal_int32)( ( kal_int32)((ReceiveID[0]<<24)&0xff000000)+( kal_int32)((ReceiveID[1]<<16)&0xff0000)+( kal_int32)((ReceiveID[2]<<8)&0xff00)+( kal_int32)ReceiveID[3]);
   st_x=( kal_int16)(((ReceiveID[4]<<8)&0xff00)+ReceiveID[5]);
    st_y=( kal_int16)( ((ReceiveID[6]<<8)&0xff00)+ReceiveID[7]);
   st_z=( kal_int16)(((ReceiveID[8]<<8)&0xff00)+ReceiveID[7]);
   dbg_print("2VERSION_ID %x ",ReceiveID[9]);
    //dbg_print"3VERSION_ID %x ",ReceiveID[3]);
   st_fall_state=( kal_int16)ReceiveID[10];
    //dbg_print"0VERSION_ID %x ",ReceiveID[0]);
    //dbg_print"1VERSION_ID %x ",ReceiveID[1]);
    dbg_print("pressure %d ",st_pressure);
    //dbg_print"2VERSION_ID %x ",ReceiveID[2]);
    //dbg_print"3VERSION_ID %x ",ReceiveID[3]);
   dbg_print("Gsensor X %d ",st_x);
    //dbg_print"4VERSION_ID %x ",ReceiveID[4]);
   // dbg_print"5VERSION_ID %x ",ReceiveID[5]);
    dbg_print("Gsensor y%d ",st_y);
  //  dbg_print"6VERSION_ID %x ",ReceiveID[6]);
   // dbg_print"7VERSION_ID %x ",ReceiveID[7]);
    dbg_print("Gsensor z%d ",st_z);
   // dbg_print"7VERSION_ID %x ",ReceiveID[8]);
   dbg_print("fall state%d ",st_fall_state);

}        
void ST_DETECT_handler(void )
{
   I2C_ReadID(0x08);
   //uem_start_timer(BMA223_STEP_COUNT_TIMER,ST_DETECT_handler,1080);   
}

u8 Reart_8001_I2C_ReadID( u8 DeviceAddress)
{

    kal_uint8 ReceiveID[13] = {0};
    
	kal_bool temp_result = KAL_FALSE;
	SW_i2c_MAG3110_start();
      ms_SendByte_MAG3110(DeviceAddress);
      if(!ms_ChkAck_MAG3110())
        {
          dbg_print("ST Sensor read id fail\n\r");
          SW_i2c_MAG3110_stop();
          return 0;
        }  
	  ms_SendByte_MAG3110(0x00);
	  if(!ms_ChkAck_MAG3110())
        {
          dbg_print("ST Sensor read id111 fail\n\r");
          SW_i2c_MAG3110_stop();
          return 0;
        }  
	  
      ms_SendByte_MAG3110(DeviceAddress| 0x01);
     if(!ms_ChkAck_MAG3110())
        {
          dbg_print("ST Sensor read id fail\n\r");
          SW_i2c_MAG3110_stop();
          return 0;
        }  
	  
	#if 0
	ReceiveID[0]=ms_ReadByteAck_MAG3110();
	ReceiveID[1]=ms_ReadByteAck_MAG3110();
	ReceiveID[2]=ms_ReadByteAck_MAG3110();
	ReceiveID[3]=ms_ReadByteAck_MAG3110();
	ReceiveID[4]=ms_ReadByteAck_MAG3110();
	ReceiveID[5]=ms_ReadByteAck_MAG3110();
	ReceiveID[6]=ms_ReadByteAck_MAG3110();
	ReceiveID[7]=ms_ReadByteAck_MAG3110();
	ReceiveID[8]=ms_ReadByteAck_MAG3110();
	ReceiveID[9]=ms_ReadByteAck_MAG3110();
	ReceiveID[10]=ms_ReadByteAck_MAG3110();
	ReceiveID[11]=ms_ReadByteAck_MAG3110();
       ReceiveID[12]=ms_ReadByteNAck_MAG3110();
       SW_i2c_MAG3110_stop();
	 #endif
	 //ReceiveID[0]=ms_ReadByteAck_MAG3110();
	 
	ReceiveID[8]=ms_ReadByteNAck_MAG3110();
	dbg_print("ReceiveSTART ");
       //dbg_print"ReceiveID[0] %d ",ReceiveID[0]);
	 #if 0
	dbg_print"ReceiveID[1] %d ",ReceiveID[1]);
	dbg_print"ReceiveID[2] %d ",ReceiveID[2]);
	dbg_print"ReceiveID[3] %d ",ReceiveID[3]);
	dbg_print"ReceiveID[4] %d ",ReceiveID[4]);
	dbg_print"ReceiveID[5] %d ",ReceiveID[5]);
	dbg_print"ReceiveID[6] %d ",ReceiveID[6]);
	dbg_print"ReceiveID[7] %d ",ReceiveID[7]);
	dbg_print"ReceiveID[8] %d ",ReceiveID[8]);
	dbg_print"ReceiveID[9] %d ",ReceiveID[9]);
	dbg_print"ReceiveID[10] %d ",ReceiveID[10]);
	dbg_print"ReceiveID[11] %d ",ReceiveID[11]);
	dbg_print"ReceiveID[12] %d ",ReceiveID[12]);
	#endif
	dbg_print("ReceiveID[8] %d ",ReceiveID[8]);
       dbg_print("ReceivesSTOP ");
}    
kal_uint8 PXI_ID;
kal_bool PXI8001_ReadByte(kal_uint8* Data, kal_uint8 RegAddr)
{
	SW_i2c_MAG3110_start();						//start bit
	ms_SendByte_MAG3110(0x33<<1);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send write id		
		dbg_print("ack fail when send wid in readbytes");
		dbg_print("ack fail when send wid in readbytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}
		
	ms_SendByte_MAG3110(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send RegAddr
		dbg_print( "ack fail when send Reg in readbytes");
		dbg_print("ack fail when send Reg in readbytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_Restart_MAG3110();						//restart bit

	ms_SendByte_MAG3110((0x33<<1)|0x01);		//slave address|read bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())
	{
		//TO_DO: display ack check fail when send read id		
		dbg_print( "ack fail when send rid in readbytes");
		dbg_print("ack fail when send rid in readbytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	*Data = ms_ReadByteNAck_MAG3110();
       
	SW_i2c_MAG3110_stop();						//stop bit

	//TO_DO: add debug code to display the data received

	return KAL_TRUE;
	
}
/******************************************
	MAG3110 contunious read bytes
*******************************************/
kal_bool PXI8001_ConReadBytes(kal_uint8* Data, kal_uint8 RegAddr, kal_uint16 Length)
{
	kal_uint8* Data_ptr;
	kal_uint16 i;

	Data_ptr = Data;
	
	SW_i2c_MAG3110_start();						//start bit
	ms_SendByte_MAG3110(0x33<<1);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send write id		
		
		dbg_print("ack fail when send wid in conread\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}
		
	ms_SendByte_MAG3110(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display ack check fail when send RegAddr		
		
		dbg_print("ack fail when send Reg in conread11\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_Restart_MAG3110();						//restart bit

	ms_SendByte_MAG3110((0x33<<1)|0x01);		//slave address|read bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())
	{
		//TO_DO: display ack check fail when send read id		
		
		dbg_print("ack fail when send rid in conread1111\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	for(i=Length; i>1; i--)
	{
		*Data_ptr = ms_ReadByteAck_MAG3110();	//read byte with ack
		Data_ptr++;
	}
	
	*Data_ptr = ms_ReadByteNAck_MAG3110();		//read byte with non-ack to stop reading

	SW_i2c_MAG3110_stop();						//stop bit

	//TO_DO: add debug code to display the data received

	return KAL_TRUE;
}

/******************************************
	MAG3110 write bytes
*******************************************/
kal_bool PXI8001_WriteByte(kal_uint8 RegAddr, kal_uint8 Data)
{
	SW_i2c_MAG3110_start();						//start bit

	ms_SendByte_MAG3110(0x33<<1);		//slave address|write bit
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display check ack fail when send write id
		dbg_print("ack fail when send wid in writebytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_SendByte_MAG3110(RegAddr);				//send RegAddr
	if(KAL_FALSE == ms_ChkAck_MAG3110())		//check Ack bit
	{
		//TO_DO: display check ack fail when send RegAddr
		dbg_print("ack fail when send Reg in wirtebytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	ms_SendByte_MAG3110(Data);					//send parameter
	if(KAL_FALSE == ms_ChkAck_MAG3110())
	{
		//TO_DO: display check ack fail when send data
		dbg_print("ack fail when send para in writebytes\n\r");
		SW_i2c_MAG3110_stop();
		return KAL_FALSE;
	}

	SW_i2c_MAG3110_stop();						//stop bit

	return KAL_TRUE;
}



void ST_8001_Heart_Rate_handler(void )
{
   //Reart_8001_I2C_ReadID(0x33<<1);
  
    PXI8001_ReadByte(&PXI_ID, 0x01);
   dbg_print("PXI8001_ID %x ",PXI_ID);
   //uem_start_timer(BMA223_STEP_COUNT_TIMER,ST_8001_Heart_Rate_handler,1080);   
}

u8 Reart_I2C_ReadID( u8 DeviceAddress)
{

    kal_uint8 ReceiveID[13] = {0};
    
	kal_bool temp_result = KAL_FALSE;
	SW_i2c_MAG3110_start();
    ms_SendByte_MAG3110(DeviceAddress| 0x01);
    if(!ms_ChkAck_MAG3110())
        {
          dbg_print("ST Sensor read id fail\n\r");
          SW_i2c_MAG3110_stop();
          return 0;
        }  
	#if 0
	ReceiveID[0]=ms_ReadByteAck_MAG3110();
	ReceiveID[1]=ms_ReadByteAck_MAG3110();
	ReceiveID[2]=ms_ReadByteAck_MAG3110();
	ReceiveID[3]=ms_ReadByteAck_MAG3110();
	ReceiveID[4]=ms_ReadByteAck_MAG3110();
	ReceiveID[5]=ms_ReadByteAck_MAG3110();
	ReceiveID[6]=ms_ReadByteAck_MAG3110();
	ReceiveID[7]=ms_ReadByteAck_MAG3110();
	ReceiveID[8]=ms_ReadByteAck_MAG3110();
	ReceiveID[9]=ms_ReadByteAck_MAG3110();
	ReceiveID[10]=ms_ReadByteAck_MAG3110();
	ReceiveID[11]=ms_ReadByteAck_MAG3110();
       ReceiveID[12]=ms_ReadByteNAck_MAG3110();
       SW_i2c_MAG3110_stop();
	 #endif
	ReceiveID[0]=ms_ReadByteAck_MAG3110();
	ReceiveID[8]=ms_ReadByteNAck_MAG3110();
	dbg_print("ReceiveSTART ");
       dbg_print("ReceiveID[0] %d ",ReceiveID[0]);
	 #if 0
	dbg_print"ReceiveID[1] %d ",ReceiveID[1]);
	dbg_print"ReceiveID[2] %d ",ReceiveID[2]);
	dbg_print"ReceiveID[3] %d ",ReceiveID[3]);
	dbg_print"ReceiveID[4] %d ",ReceiveID[4]);
	dbg_print"ReceiveID[5] %d ",ReceiveID[5]);
	dbg_print"ReceiveID[6] %d ",ReceiveID[6]);
	dbg_print"ReceiveID[7] %d ",ReceiveID[7]);
	dbg_print"ReceiveID[8] %d ",ReceiveID[8]);
	dbg_print"ReceiveID[9] %d ",ReceiveID[9]);
	dbg_print"ReceiveID[10] %d ",ReceiveID[10]);
	dbg_print"ReceiveID[11] %d ",ReceiveID[11]);
	dbg_print"ReceiveID[12] %d ",ReceiveID[12]);
	#endif
	dbg_print("ReceiveID[8] %d ",ReceiveID[8]);
       dbg_print("ReceivesSTOP ");
}    

void ST_Heart_Rate_handler(void )
{
   Reart_I2C_ReadID(0x08);
   //uem_start_timer(BMA223_STEP_COUNT_TIMER,ST_Heart_Rate_handler,1080);   
}



typedef struct { 
kal_uint8  HRD_Data[13] ; 
 float MEMS_Data[3] ; 
}ppg_mems_data_t; 
#define FIFO_SIZE 	8
#define FIFO_SIZE_M1 	(FIFO_SIZE-1)
static ppg_mems_data_t _ppg_mems_data[FIFO_SIZE] ; 
static int _read_index = 0 ; 
static int _write_index = 0 ; 
kal_uint8 Frame_Count=0; 


///////////////////////////////////////
//void write_pixart_init_register();
static void led_ctrl(kal_uint8 touch);
kal_bool isFIFOEmpty(void);
kal_bool Pop(ppg_mems_data_t *data);
kal_bool Push(ppg_mems_data_t *data);
kal_bool Pixart_HRD(void);
extern kal_bool PXI8001_ReadByte(kal_uint8* Data, kal_uint8 RegAddr);
extern kal_bool PXI8001_ConReadBytes(kal_uint8* Data, kal_uint8 RegAddr, kal_uint16 Length);
extern kal_bool PXI8001_WriteByte(kal_uint8 RegAddr, kal_uint8 Data);
extern void SW_i2c_MAG3110_udelay(kal_uint32 delay);



kal_bool isFIFOEmpty(void) 
{ 
 return (_write_index == _read_index) ; 
} 

kal_bool Push(ppg_mems_data_t *data) //Push return data must be KAL_TRUE. If return KAL_FALSE, please increase FIFO size.   
{ 
 int tmp = _write_index ; 
tmp++; 
if(tmp >= FIFO_SIZE) 
  tmp = 0 ; 
 if(tmp == _read_index) 
return KAL_FALSE; 
 _ppg_mems_data[tmp] = *data ;  
 _write_index = tmp ; 
return KAL_TRUE; 
} 

kal_bool Pop(ppg_mems_data_t *data) 
{ 
 int tmp ; 
if(isFIFOEmpty()) 
return KAL_FALSE; 
 *data = _ppg_mems_data[_read_index] ; 
 tmp = _read_index + 1; 
if(tmp >= FIFO_SIZE) 
  tmp = 0 ;
 _read_index = tmp ; 
return KAL_TRUE; 
} 



void pah8001_sensor_init_ext()
{
		kal_uint8 temp;


		GPO_WriteIO( 1, 27 );

		PXI8001_WriteByte(0x06,0x82); //Reset 
		//Delay(); //about 10ms 
		SW_i2c_MAG3110_udelay(100);
		PXI8001_WriteByte(0x09,0x5A); 
		PXI8001_WriteByte(0x05,0x99); 
		//temp = PXI8001_ReadByte(&temp,0x17); 
		PXI8001_ReadByte(&temp,0x17); 
		PXI8001_WriteByte(0x17,temp|0x80); 
		PXI8001_WriteByte(0x27,0xFF); 
		PXI8001_WriteByte(0x28,0xFA); 
		PXI8001_WriteByte(0x29,0x0A); 
		PXI8001_WriteByte(0x2A,0xC8); 
		PXI8001_WriteByte(0x2B,0xA0); 
		PXI8001_WriteByte(0x2C,0x8C); 
		PXI8001_WriteByte(0x2D,0x64); 
		PXI8001_WriteByte(0x42,0x20); 
		PXI8001_WriteByte(0x48,0x00); 
		//PXI8001_WriteByte(0x4D,0x1A);//for wrist application 
		PXI8001_WriteByte(0x4D,0x18); //for fingertip application 
		PXI8001_WriteByte(0x7A,0xB5); 
		PXI8001_WriteByte(0x7F,0x01); 
		PXI8001_WriteByte(0x07,0x48); 
		PXI8001_WriteByte(0x23,0x3C); 
		PXI8001_WriteByte(0x26,0x0F); 
		PXI8001_WriteByte(0x2E,0x48); 
		PXI8001_WriteByte(0x38,0xEA); 
		PXI8001_WriteByte(0x42,0xA4); 
		PXI8001_WriteByte(0x43,0x41); 
		PXI8001_WriteByte(0x44,0x41); 
		PXI8001_WriteByte(0x45,0x24); 
		PXI8001_WriteByte(0x46,0xC0); 
		PXI8001_WriteByte(0x52,0x32); 
		PXI8001_WriteByte(0x53,0x28); 
		PXI8001_WriteByte(0x56,0x60); 
		PXI8001_WriteByte(0x57,0x28); 
		PXI8001_WriteByte(0x6D,0x02); 
		PXI8001_WriteByte(0x0F,0xC8); 
		PXI8001_WriteByte(0x7F,0x00); 
		PXI8001_WriteByte(0x5D,0x81); 

		Pixart_HRD();
		
}



/***********************LED Control Start***********************************/ 
#define LED_INC_DEC_STEP 2 
#define LED_CTRL_EXPO_TIME_HI_BOUND   496 
#define LED_CTRL_EXPO_TIME_LOW_BOUND 32 
#define LED_CTRL_EXPO_TIME_HI 420 
#define LED_CTRL_EXPO_TIME_LOW 64 
#define LED_CURRENT_HI 31 
#define LED_CURRENT_LOW 1 
#define STATE_COUNT_TH 3 
#define DEFAULT_LED_STEP 10 
static kal_uint8 _led_step = DEFAULT_LED_STEP;  
static kal_uint8 _state = 0, _state_count = 0; 
static kal_uint8 _led_current_change_flag = 0; 
static kal_uint8 _sleepflag = 1 ; 


static void led_ctrl(kal_uint8 touch) 
{ 
if(touch == 0x80) 
{ 
kal_uint8 data; 
kal_uint16 Frame_Average, EP_L, EP_H, Exposure_Line; 
PXI8001_WriteByte(0x7f,0x00); 
PXI8001_WriteByte(0x5, 0x98); 
PXI8001_WriteByte(0x7f,0x01);  //PXI8001_WriteByte(0x42,0xA4);   
PXI8001_WriteByte(0x7f,0x00); 
//data = PXI8001_ReadByte(&data,0x33); 
PXI8001_ReadByte(&data,0x33);
EP_H=data&0x03; 
PXI8001_ReadByte(&data,0x32); 
EP_L=data; 
Exposure_Line=(EP_H<<8)+EP_L; 
PXI8001_WriteByte(0x7f,0x01); 
if(_sleepflag==1) 
{ 
PXI8001_WriteByte(0x38, (0xE0|DEFAULT_LED_STEP)); 
_sleepflag = 0 ; 
} 
  if (_state_count <= STATE_COUNT_TH) { 
_state_count++; 
_led_current_change_flag = 0; 
} 
else { 
_state_count = 0; 
if(_state == 0) 
{ 
if( (Exposure_Line>=LED_CTRL_EXPO_TIME_HI_BOUND) ||  
(Exposure_Line<=LED_CTRL_EXPO_TIME_LOW_BOUND ) 
) 

{ 
//PXI8001_WriteByte(0x7f,0x01); 
PXI8001_ReadByte(&data,0x38); 
_led_step=data&0x1f; 
if( (Exposure_Line>=LED_CTRL_EXPO_TIME_HI_BOUND) 
&& (_led_step < LED_CURRENT_HI)) 
{ 
_state = 1 ; 
_led_step=_led_step+LED_INC_DEC_STEP; 
if(_led_step>LED_CURRENT_HI) 
_led_step=LED_CURRENT_HI; 
PXI8001_WriteByte(0x38, (_led_step|0xE0)); 
_led_current_change_flag = 1; 
} 
else if((Exposure_Line<=LED_CTRL_EXPO_TIME_LOW_BOUND) 
&& (_led_step > LED_CURRENT_LOW)) 
{ 
_state = 2 ; 
if(_led_step<=(LED_CURRENT_LOW+LED_INC_DEC_STEP)) 
_led_step=LED_CURRENT_LOW; 
else 
_led_step=_led_step-LED_INC_DEC_STEP; 
PXI8001_WriteByte(0x38, (_led_step|0xE0)); 
_led_current_change_flag = 1; 
}else 
{ 
_state = 0 ; 
_led_current_change_flag = 0; 
} 
} 
else { 
_led_current_change_flag = 0; 
} 
} 
else if(_state == 1) 
{ 
if(Exposure_Line > LED_CTRL_EXPO_TIME_HI) 
{ 
_state = 1 ; 
_led_step=_led_step+LED_INC_DEC_STEP; 
if(_led_step>=LED_CURRENT_HI) 
{ 
_state = 0 ; 
_led_step=LED_CURRENT_HI; 
} 
PXI8001_WriteByte(0x38, (_led_step|0xE0)); 
_led_current_change_flag = 1; 
} 
else 
{ 
_state = 0 ; 
_led_current_change_flag = 0; 
} 
} 
else 
{ 
 
if(Exposure_Line < LED_CTRL_EXPO_TIME_LOW) 
{ 
_state = 2 ; 
if(_led_step<=(LED_CURRENT_LOW+LED_INC_DEC_STEP)) 
{ 
_state = 0 ; 
_led_step=LED_CURRENT_LOW; 
} 
else 
_led_step=_led_step-LED_INC_DEC_STEP; 
PXI8001_WriteByte(0x38, (_led_step|0xE0)); 
_led_current_change_flag = 1; 
} 
else 
{ 
_state = 0; 
_led_current_change_flag = 0; 
} 
} 
} 
} 
else 
{ 
PXI8001_WriteByte(0x7f,0x00); 
PXI8001_WriteByte(0x5, 0xB8); 
PXI8001_WriteByte(0x7F, 0x01);  
//PXI8001_WriteByte(0x42,0xA0); 
_led_step = DEFAULT_LED_STEP; 
//PXI8001_WriteByte(0x38, (0xE0 | DEFAULT_LED_STEP));  
PXI8001_WriteByte(0x38, 0xFF); 
_sleepflag = 1; 
_led_current_change_flag = 0; 
} 
} 
/***********************LED Control End ***********************************/



kal_bool Pixart_HRD(void)  
{ 
		kal_uint8 buffer[4]={0}; 
		kal_uint8 tmp=0; 
		 kal_uint32 HWCounter = 0 ; 
		ppg_mems_data_t ppg_mems_data; 
		//Check Touch Status for power saving  
		PXI8001_WriteByte(0x7F,0x00); //bank0 
		PXI8001_ReadByte(&tmp,0x59); 
		dbg_print("tmp =%d ",tmp);
		tmp = tmp&0x80;
		dbg_print("tmp =%d ",tmp);
		led_ctrl(tmp);
		//PXI8001_WriteByte(0x7F,0x01); //bank1 
		 //check status: 0 is not ready, 1 is ready, 2 is loss one data¡­
		PXI8001_ReadByte(&ppg_mems_data.HRD_Data[0],0x68);
		ppg_mems_data.HRD_Data[0] = ppg_mems_data.HRD_Data[0]&0x0f; 
		if(ppg_mems_data.HRD_Data[0] ==0) 
		{ 
			PXI8001_WriteByte(0x7F,0x00); //bank0 
			return KAL_FALSE; 
		} 
		else 
		{ 

#if 0
		//Only support burst read (0x64~0x67), when using I2C interface 
		ppg_mems_data.HRD_Data[1]=PXI8001_ReadByte(&ppg_mems_data.HRD_Data[1],0x64)&0xff; 
		ppg_mems_data.HRD_Data[2]=PXI8001_ReadByte(&ppg_mems_data.HRD_Data[2],0x65)&0xff; 
		ppg_mems_data.HRD_Data[3]=PXI8001_ReadByte(&ppg_mems_data.HRD_Data[3],0x66)&0xff; 
		ppg_mems_data.HRD_Data[4]=PXI8001_ReadByte(&ppg_mems_data.HRD_Data[4],0x67)&0xff; 
		//Only support burst read (0x1A~0x1C), when using I2C interface 
		ppg_mems_data.HRD_Data[5]=PXI8001_ReadByte(&ppg_mems_data.HRD_Data[5],0x1A)&0xff; 
		ppg_mems_data.HRD_Data[6]=PXI8001_ReadByte(&ppg_mems_data.HRD_Data[6],0x1B)&0xff; 
		ppg_mems_data.HRD_Data[7]=PXI8001_ReadByte(&ppg_mems_data.HRD_Data[7],0x1C)&0xff; 
		ppg_mems_data.HRD_Data[8]=Frame_Count++; 
		HWCounter = GetHWCounter(); 
		ppg_mems_data.HRD_Data[9]=ToMSec(HWCounter) ; //translate HW counter to msec 
		ReStartHWCounter(); 

#elif 1
		PXI8001_ConReadBytes(&ppg_mems_data.HRD_Data[1], 0x64, 4);
		//Only support burst read (0x1A~0x1C), when using I2C interface 
		PXI8001_ConReadBytes(&ppg_mems_data.HRD_Data[5], 0x1A, 3);
		{
		 kal_uint32  ticks_ptrgxx;
		 kal_get_time(&ticks_ptrgxx);
		 dbg_print("gxxticks=%d ",ticks_ptrgxx);
		}
		ppg_mems_data.HRD_Data[8]=Frame_Count++; 
		//HWCounter = GetHWCounter(); 
		ppg_mems_data.HRD_Data[9]=0 ; //translate HW counter to msec 
#endif
		/***********************HW counter explanation start***********************************/ 
		//HW counter is MCU background counter.  
		//These functions read heart rate data ready interval time then provide to lib. (Unit is ms) 
		//For example: polling time is 40ms 
		//Heart rate data ready interval time is 40ms or 80ms, because sensor ready is about 50ms. 
		//ppg_mems_data.HRD_Data[9]=40 or 80, first time provide 0 is OK. 
		/*********************** HW counter explanation end***********************************/
		ppg_mems_data.HRD_Data[10]=_led_current_change_flag; 
		PXI8001_WriteByte(0x7F,0x00); //bank0 
		  //bit7 is Touch Flag (bit7=1 is meant Touch, and bit7=0 is meant No Touch) 
		PXI8001_ReadByte(&ppg_mems_data.HRD_Data[11],(0x59)); //Check Touch Flag 
		ppg_mems_data.HRD_Data[11]=ppg_mems_data.HRD_Data[11]&0x80;
		ppg_mems_data.HRD_Data[12]= ppg_mems_data.HRD_Data[6]; 
		/***********************G sensor explanation start***********************************/
		//If no G sensor, please set ppg_mems_data.MEMS_Data[3] = {0}; 
		//Please set G sensor default range = ¡À2G. 
		  //If G sensor output data format is not 16bit, please change to 16bit format. 
		  //For example: G sensor is 12bit 
		  //ppg_mems_data.MEMS_Data[0] = ReadGSensorX() <<4; 
		  //ppg_mems_data.MEMS_Data[1] = ReadGSensorY() <<4; 
		  //ppg_mems_data.MEMS_Data[2] = ReadGSensorZ() <<4; 
		  //MEMS_SensorX() data must be largest when let hand down at static state. 
		  //MEMS_SensorZ() data must be largest when let hand horizontal on the table at static state. 
		/***********************G sensor explanation end***********************************/
#if 0
		ppg_mems_data.MEMS_Data[0] = ReadGSensorX(); 
		ppg_mems_data.MEMS_Data[1] = ReadGSensorY(); 
		ppg_mems_data.MEMS_Data[2] = ReadGSensorZ(); 
#elif 1
		ppg_mems_data.MEMS_Data[0] = 0; 
		ppg_mems_data.MEMS_Data[1] = 0; 
		ppg_mems_data.MEMS_Data[2] = 0; 
#endif
		  Push(&ppg_mems_data); //Save data into FIFO 
		  dbg_print("HRD_DataSTART!!!!!!!!!!");
		 dbg_print("HRD_Data[0] %x ",ppg_mems_data.HRD_Data[0]);
		 dbg_print("HRD_Data[1] %x ",ppg_mems_data.HRD_Data[1]);
		 dbg_print("HRD_Data[2] %x ",ppg_mems_data.HRD_Data[2]);
		 dbg_print("HRD_Data[3] %x ",ppg_mems_data.HRD_Data[3]);
		 dbg_print("HRD_Data[4] %x ",ppg_mems_data.HRD_Data[4]);
		 dbg_print("HRD_Data[5] %x ",ppg_mems_data.HRD_Data[5]);
		 dbg_print("HRD_Data[6] %x ",ppg_mems_data.HRD_Data[6]);
		 dbg_print("HRD_Data[7] %x ",ppg_mems_data.HRD_Data[7]);
		 dbg_print("HRD_Data[8] %x ",ppg_mems_data.HRD_Data[8]);
		 dbg_print("HRD_Data[9] %x ",ppg_mems_data.HRD_Data[9]);
		 dbg_print("HRD_Data[10] %x ",ppg_mems_data.HRD_Data[10]);
		 dbg_print("HRD_Data[11] %x ",ppg_mems_data.HRD_Data[11]);
		 dbg_print("HRD_Data[12] %x ",ppg_mems_data.HRD_Data[12]);
		 dbg_print("HRD_DataSTop!!!!!!!!!!!!!!!!!!");
		return KAL_TRUE; 
	} 
} 

void PAH8001_Heart_Rate_handler(void )
{
   Pixart_HRD() ;
   //uem_start_timer(BMA223_STEP_COUNT_TIMER,PAH8001_Heart_Rate_handler,10);   
}

#if 0
void TimerISR()  //interrupt per 40ms 
{ 
Pixart_HRD() ; 
} 
#endif
