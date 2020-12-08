/******************** (C) COPYRIGHT 2016~2017 MEMSENSING **********************
* File Name          : msp880.c
* Author             : ShaoChenglong
* Version            : V1.0
* Date               : 2016-11-1
* Description        : Msp880 application
*******************************************************************************/
#include "msp880.h"

/*******************************************************************************
* Function Name  : msp_read_pressure
* Description    : MSP880 pressure data read £¬ I2C mode
* Input          : *pressure
* Output         : None
* Return         : None
*******************************************************************************/
void msp_read_press(uint32_t *press)
{
    uint8_t temp_data[3] = {0,0,0};
		
	//press read signal, OSR 8192
	msp_WriteBytes(MS_REG_CONFIGURE,MS_PRESS_READ);
		
	msa_DelayMS(50); //10ms delay,wait for ADC convert

    if(msp_register_read_continuously(MS_REG_PRESS_MSB, 3, temp_data) == 0)
	{
		return;
    }

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("reg_55:%d,reg_56:%d,reg_57:%d", temp_data[0],temp_data[1],temp_data[2]);
#endif
#endif
	
	*press = temp_data[0]<<16 |  temp_data[1]<<8 |  temp_data[2];
}

/*******************************************************************************
* Function Name  : msp_read_temperature
* Description    : MSP880 temperature data read £¬ I2C mode
* Input          : *temperature
* Output         : None
* Return         : None
*******************************************************************************/
void msp_read_temperature(uint32_t *temperature)
{
    uint8_t temp_data[2] = {0,0};
		
	//temperature read signal, OSR 1024
	msp_WriteBytes(MS_REG_CONFIGURE,MS_TEMPERATURE_READ);

	msa_DelayMS(10); //3ms delay,wait for ADC convert

    if(msp_register_read_continuously(MS_REG_TEMPERATURE_MSB, 2, temp_data) == 0)
	{
		return;
    }
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("reg_58:%d,reg_59:%d", temp_data[0],temp_data[1]);
#endif
#endif
	
	*temperature =  temp_data[0]<<8 |  temp_data[1];
}


/*******************************************************************************
* Function Name  : msp_register_read_continuously
* Description    : MSP880 data read £¬ I2C mode
* Input          : address , sizeof(data_read) , data_return
* Output         : None
* Return         : 0£ºdata read fail     1:data read success
*******************************************************************************/

int msp_register_read_continuously(uint8_t addr, uint8_t count, uint8_t *data)
{
    int32_t  status = 0;

    status = (count==i2c_read_block_data(addr, count, data)) ? 1 : 0;
		
    return status;
}

/*******************************************************************************
* Function Name  : i2c_read_block_data
* Description    : MSP880 data read £¬ I2C mode
* Input          : address , sizeof(data_read) , data_return
* Output         : None
* Return         : -1:read fail      sizeif(data_read):read success
*******************************************************************************/
int32_t i2c_read_block_data(uint8_t base_addr, uint8_t count, uint8_t *data)
{	
	int32_t i = 0;
	
	for(i = 0; i < count;i++)
	{
		if(i2c_read_byte_data(base_addr+i,(data+i)))
		{
			return -1;					
		}
	}	
	return count;
}

/*******************************************************************************
* Function Name  : i2c_read_byte_data
* Description    : MSP880 data read £¬ I2C mode
* Input          : address ,  data_return
* Output         : None
* Return         : 0:read success     others: read fail
*******************************************************************************/
int32_t  i2c_read_byte_data(uint8_t addr, uint8_t *data)
{
	int status = 0;

	status = msp_ReadBytes(data,addr);
	return (!status);
}

/*******************************************************************************
* Function Name  : msp_ReadBytes
* Description    : MSP880 byte read£¬ I2C mode
* Input          : address ,  data_return
* Output         : None
* Return         : 0:read fail     1£ºread success
*******************************************************************************/

bool msp_ReadBytes(uint8_t* Data, uint8_t RegAddr)
{
#ifdef KJX_MTK_TARGET
	kal_int32 i, j;
#endif
	SW_i2c_start();						//start bit

#ifdef KJX_MTK_TARGET
	//Need to confirm this delay
   	for (j = 0; j < delay_long; j++);
#endif
	ms_SendByte(MS_I2C_Addr << 1);		//slave address|write bit
	if(FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display ack check fail when send write id		
		SW_i2c_stop();
		return FALSE;
	}

	ms_SendByte(RegAddr);				//send RegAddr
	if(FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display ack check fail when send RegAddr
		SW_i2c_stop();
		return FALSE;
	}

	ms_Restart();						//restart bit

  	ms_SendByte(MS_I2C_Addr<<1 | MS_I2C_Addr_Read);		//slave address|read bit
	if(FALSE == ms_ChkAck())
	{
		//TO_DO: display ack check fail when send read id		
		SW_i2c_stop();
		return FALSE;
	}

	*Data = ms_ReadByteNAck();

	SW_i2c_stop();						//stop bit

	//TO_DO: add debug code to display the data received

	return TRUE;
	
}
/*******************************************************************************
* Function Name  : msp_WriteBytes
* Description    : MSP880 date write£¬ I2C mode
* Input          : address ,  data_write
* Output         : None
* Return         : 0:write fail     1£ºwrite success
*******************************************************************************/
bool msp_WriteBytes(uint8_t RegAddr, uint8_t Data)
{
	SW_i2c_start();						//start bit

	ms_SendByte(MS_I2C_Addr<<1 | MS_I2C_Addr_Write);		//slave address|write bit
	if(FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display check ack fail when send write id
		SW_i2c_stop();
		return FALSE;
	}

	ms_SendByte(RegAddr);				//send RegAddr
	if(FALSE == ms_ChkAck())		//check Ack bit
	{
		//TO_DO: display check ack fail when send RegAddr

		SW_i2c_stop();
		return FALSE;
	}

	ms_SendByte(Data);					//send parameter
	if(FALSE == ms_ChkAck())
	{
		//TO_DO: display check ack fail when send data

		SW_i2c_stop();
		return FALSE;
	}

	SW_i2c_stop();						//stop bit

	return TRUE;
}


/*******************************************************************************
* Function Name  : ms_SendByte
* Description    : MSP880 send byte£¬ I2C mode
* Input          : data
* Output         : None
* Return         : 0:read fail     1£ºread success
*******************************************************************************/

void ms_SendByte(uint8_t Data) 
{
  int32_t i;
	
	for (i=7; i>=0; i--) 
	{            
		if ((Data>>i)&0x01) 
		{               
			MS_I2C_DATA_HIGH;	              
		} 
		else 
		{ 
			MS_I2C_DATA_LOW;                  
		}
		SW_i2c_one_clk();                        
	}		
}

/*******************************************************************************
* Function Name  : SW_i2c_start
* Description    : I2C start, software mode
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SW_i2c_start(void)
{
#ifdef KJX_MTK_TARGET
	kal_int32 i, j;

	MS_SDA_OUT;
	MS_SCL_OUT;
	
	MS_I2C_DATA_HIGH;
	MS_I2C_CLK_HIGH;	
	for (j = 0; j < delay_short; j++);
	MS_I2C_DATA_LOW;
	for (j = 0; j < delay_short; j++);
	MS_I2C_CLK_LOW;
	for (j = 0; j < delay_short; j++);

#else

	MS_SCL_OUT;

	MS_SDA_OUT;
	
	MS_I2C_DATA_HIGH;
	MS_I2C_CLK_HIGH;
	st_delay_us(40);		//40us
	MS_I2C_DATA_LOW;
	st_delay_us(20);		//20us
	MS_I2C_CLK_LOW;
	st_delay_us(20);		//20us
#endif
}

/*******************************************************************************
* Function Name  : SW_i2c_stop
* Description    : I2C stop, software mode
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SW_i2c_stop(void)
{
#ifdef KJX_MTK_TARGET
	kal_int32 i, j;

	MS_SCL_OUT;
	MS_SDA_OUT;

	MS_I2C_DATA_LOW;
	for (j = 0; j < delay_short; j++);
	MS_I2C_CLK_HIGH;
	for (j = 0; j < delay_short; j++);
	MS_I2C_DATA_HIGH;	
	for (j = 0; j < delay_short; j++);

#else

	MS_SCL_OUT;
	MS_SDA_OUT;

	MS_I2C_DATA_LOW;
	st_delay_us(20);		//20us
	MS_I2C_CLK_HIGH;
	st_delay_us(20);		//20us
	MS_I2C_DATA_HIGH;
  	st_delay_us(20);		//20us
#endif
}
/*******************************************************************************
* Function Name  : ms_Restart
* Description    : I2C restart, software mode
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

void ms_Restart(void)
{
#ifdef KJX_MTK_TARGET
	kal_int32 i, j;

	MS_SCL_OUT;
	MS_SDA_OUT;
	for(j = 0; j < delay_short; j++);
	MS_I2C_CLK_HIGH;
	for(j = 0; j < delay_short; j++);
	MS_I2C_DATA_HIGH;
	for(j = 0; j < delay_short; j++);
	
	MS_I2C_DATA_LOW;
	for(j = 0; j < delay_short; j++);
	MS_I2C_CLK_LOW;
	for(j = 0; j < delay_short; j++);

#else

	MS_SCL_OUT;
	MS_SDA_OUT;

	st_delay_us(40);    //40us
	MS_I2C_DATA_HIGH;
	st_delay_us(20);		//20us
	MS_I2C_CLK_HIGH;
	st_delay_us(40);
	MS_I2C_DATA_LOW;
	st_delay_us(40);		//20us
	MS_I2C_CLK_LOW;
	st_delay_us(20);		//20us
#endif	
}

/*******************************************************************************
* Function Name  : SW_i2c_one_clk   
* Description    : I2C one clk send
* Input          : None
* Output         : None
* Return         : None
* Notice         : the max frequence of i2c clk is 400K, then the min clk is 2.5us
*******************************************************************************/
void SW_i2c_one_clk(void)
{
#ifdef KJX_MTK_TARGET
	kal_int32 i, j;

	for (j = 0; j < delay_long; j++);
	MS_I2C_CLK_HIGH;
	for (j = 0; j < delay_long; j++);
	MS_I2C_CLK_LOW;
	for (j = 0; j < delay_short; j++);

#else

	st_delay_us(10);		//10us
	MS_I2C_CLK_HIGH;
	st_delay_us(20);		//20us
	MS_I2C_CLK_LOW;
	st_delay_us(10);		//10us
#endif
}

/*******************************************************************************
* Function Name  : ms_ChkAck   
* Description    : I2C Ack
* Input          : None
* Output         : None
* Return         : 1:Ack    0:no Ack
*******************************************************************************/
bool ms_ChkAck(void)
{
#ifdef KJX_MTK_TARGET
	kal_int32 i, j;

	MS_SDA_IN;
	for (j = 0; j < delay_short; j++);
	MS_I2C_CLK_HIGH;
	for (j = 0; j < delay_long; j++);

	if(MS_I2C_GET_BIT)		//Non-ack
	{
		for (j = 0; j < delay_long; j++);
		MS_I2C_CLK_LOW;		
		for (j = 0; j < delay_long; j++);		
		MS_SDA_OUT;
		MS_I2C_DATA_LOW;
		return FALSE;
	}
	else					//Ack
	{
		for (j = 0; j < delay_long; j++);
		MS_I2C_CLK_LOW;		
		for (j = 0; j < delay_long; j++);		
		MS_SDA_OUT;
		MS_I2C_DATA_LOW;
		return TRUE;
	}	

#else

	MS_SDA_IN;
	
	st_delay_us(10);		//10us
	MS_I2C_CLK_HIGH;
	st_delay_us(10);		//10us

	if(MS_I2C_GET_BIT)		//Non-ack
	{
		st_delay_us(10);	//10us
		MS_I2C_CLK_LOW;
		st_delay_us(10);	//10us
	
		MS_SDA_OUT;
		MS_I2C_DATA_LOW;
		
		return FALSE;
	}
	else					//Ack
	{
		st_delay_us(10);	//10us
		MS_I2C_CLK_LOW;
		st_delay_us(10);	//10us
	
		MS_SDA_OUT;
		MS_I2C_DATA_LOW;

		return TRUE;
	}
#endif
}

/*******************************************************************************
* Function Name  : ms_ReadByteNAck   
* Description    : I2C data read without ack
* Input          : None
* Output         : None
* Return         : data read
*******************************************************************************/
uint8_t ms_ReadByteNAck(void)
{
	int32_t i;
	uint8_t data;

	MS_SDA_IN;
	data = 0; 
	
	for (i=7; i>=0; i--) 
	{
		if (MS_I2C_GET_BIT)
		{
			data |= (0x01<<i);
		}
		SW_i2c_one_clk();
	}			                                

	MS_SDA_OUT;                                          
	MS_I2C_DATA_HIGH;
	SW_i2c_one_clk();                         
	
	return data;
}

/*******************************************************************************
* Function Name  : msa_DelayMS
* Description    : delay ms
* Input          : time_cnt 
* Output         : None
* Return         : None
*******************************************************************************/
void msa_DelayMS(uint32_t delay)
{
	uint32_t i=0;

	for(i=0; i<delay; i++)
	{
		st_delay_us(700);
	}
}

/*******************************************************************************
* Function Name  : st_delay_us
* Description    : us delay for STM32F429, HLK 168Mhz
* Input          : time_cnt 
* Output         : None
* Return         : None
*******************************************************************************/
void st_delay_us(uint32_t delay)
{
	uint32_t i;

	while(delay--)
	{	
		i = 42;	
		while(i--);	
	}
}


/************************ (C) COPYRIGHT MEMSENSING *****END OF FILE****/
