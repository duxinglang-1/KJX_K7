/**********************************************************************************
*Filename:     kjx_gps.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#if defined(__KJX_FUN_GPS__)
#include "kjx_include.h"
#include "kjx_dog_test.h"
#ifndef WIN32
#include "Uart_internal.h"             //UART_dafault_rx_cb
#endif
#if defined(__KJX_LOG_OUTPUT__)
#include "Kjx_prin.h"
#endif

#define GPS_DEBUG
#define GPS_GOOD_SIGNAL_MIN_VALUE	32

#define TRACE_UART_PORT	  uart_port_usb

#ifdef __KJX_RFID__
#if defined(RFID_TEST_PORT2)
#define RFID_UART_PORT		uart_port2
#define RFID_UART_UTXD_PIN	  	21 
#define RFID_UART_URXD_PIN	  	20 
#else
#define RFID_UART_PORT		uart_port1 
#define RFID_UART_UTXD_PIN	  	22 
#define RFID_UART_URXD_PIN	  	23 
#endif
#endif

static kal_mutexid g_kjx_gps_process_mutex = NULL;
static kal_uint8 gps_status = 0;	//xb add 2017-06-01 GPS实际工作状态
static kal_uint8 gps_data[FUN_GPS_MAX_LEN] = {0};
static kal_uint8 gps_gsv[2048] = {0};

static kal_uint8 GPSLocateTTFSendOne = 0;   /*TTF时间值发一次,0--开始计算收V时间，1-计算收到第一条数据时间，2--收到A时间*/ 
static kal_uint32 sysgpsticks = 0; 
static kal_uint32 position_ttff = 0;
static kal_uint32 KjxGPSOnTime = 0; 

kjx_gps_func g_kjx_gps_func;
kjx_gps_data g_kjx_gps_data;
char* kjx_prostring = NULL;
  
RECEIVE_MODE_ID_ENUM receiveMode;
GPS_CMD_ENUM gps_cmd_id;
U8 segCount;		//逗号计数器
U8 dotCount;		//小数点计数器
U8 byteCount;		//段位数计数器
U8 gps_first_pwron = 0;   //GPS上电第一次启动，冷启动，之后都是热启动 
U8 kjx_cmd[10] = {0};
U8 g_kjx_gps_category = GPS_MAX_MODE;	//GPS模块型号
U8 g_kjx_signal_good_count = 0;		//信号良好的卫星数

kal_bool GPS_Pass_state = KAL_FALSE;  //gps透传标志位

kjx_gps_info_string gps_string = {0};
kjx_gps_info_string gps_info_string =
{		//该缓冲区实时更新
	'V',										//GPS 数据状态'A' ->有效 'V'->无效
	{'0','0','0','0','0','.','0','0','0','0'},	//经度  Dddmm.mmmm 格式
	'E',										//经度方向
	{'0','0','0','0','.','0','0','0','0'},		//纬度ddmm.mmmm	格式
	'N',										//纬度方向
	{'0','0'},									//定位使用的卫星数	
	{'0','0'},									//GPS当前可视卫星数目
	{'0','0'},									//BD当前可视卫星数目
	'1',										//GPS当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
	'1',										//BD当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
	'N',										//模块定位模式A=自主定位，D=差分，E=估算，N=数据无效	
	{'0','.','0','0','0','0','0'},				//海拔高度-9999.9~99999.9
	0,											//海拔高度统计
	{'0','.','0','.','0','0'},					//速度
	0,											//速度统计
	{'0','.','0','0','0','0'},					//方位角
	0,											//方位角统计
	{'0','0','0','0','0','0'},					//UTC 时间	hhmmss
	{'0','0','0','0','0','0'},					//UTC 日期	ddmmyy
#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
	{'0','0','0','0','0','0','0','0'},
	{'0','0','0','0','0','0','0','0'}
#endif
#endif
};

kjx_pos_gps_info_string g_kjx_gps_info_string =
{
	"000000.000",
	'V',
	"0000.0000",
	'N',
	"00000.0000",
	'E',
	"000.0",
	"000000",
	"000.00",
	"00",
	"00",
};

/***************************************************************************/

/***************************************************************************/
#if defined(GPS_MODULAR_ZKW)	
U8 GPS_CMD[50] = 
{
	'G','N','G','G','A',	//0    
	'G','N','G','L','L',	// 1    
	'G','P','G','S','A',	// 2 
	'B','D','G','S','A',	// 3  
	'G','P','G','S','V',	// 4
	'B','D','G','S','V',	// 5
	'G','N','R','M','C',	// 6
	'G','N','V','T','G',	// 7 
	'G','N','Z','D','A',	// 8
	'G','P','T','X','T',	// 9
};    
#else
U8 GPS_CMD[15] = 
{
	'R','M','C',      //时间和经纬度
	'G','G','A',      //显示海拔高度
	'G','S','V',
	'V','T','G',
	'G','S','A'
};    
#endif

//cos(lat) 0 -90 
U16 longitude_error_value[90] =
{
	100,100,100,100,100,100,99,99,99,99,
  	98,98,98,97,97,97,96,96,95,95,
	94,93,93,91,91,91,90,89,88,87,
	87,86,85,84,83,82,81,80,79,78,
	77,75,74,73,72,71,69,68,67,66,
	64,63,62,60,59,57,56,54,53,52,
	50,48,47,45,44,42,41,39,37,36,
	34,33,31,29,28,26,24,22,21,19,
	17,16,14,12,10,9,7,5,3,2,
};

extern int g_kjx_enter_factory_test;
#ifdef __KJX_FUN_AGPS__
extern U8 g_kjx_agps_used;
extern U32 g_kjx_agps_date_len;
#ifdef __KJX_FUN_GPS_HD__
extern U8 g_kjx_HD_agps_step;
extern U8 g_kjx_HD_agps_send_buf[HD_AGPS_ONE_BAG_DATA_MAX_LEN];
extern U32 g_kjx_HD_agps_send_count;
extern U8 g_kjx_HD_agps_retry_count;
extern void kjx_agps_start_from_step(void);
#endif
extern void kjx_agps_start(void);
#ifdef __KJX_FUN_GPS_ZKW__
void kjx_gps_open_agps_status_check(void);
void kjx_gps_close_agps_status_check(void);
#endif
#endif

/*******************************************************************************
* Function Name  : 
* Description    :      处理GPS  信息提取两个逗号之间的字符
*   
* Input          : 
   uchar *in_data_buffer  输入字符串指针
   uchar *out_data_buffer  输出提取到的存储指针 
   data_index    提取第几个逗号后面的字符
   in_data_len   输入字符串长度
   
* Output         : None  
* Return         :  提取了几个字符
*******************************************************************************/
uint32 kjx_gps_get_data_from_buffer(U8 *in_data_buffer,U8 *out_data_buffer,U16 out_data_len,U16 data_index,U16 in_data_len)
{
	uint32 i ;
	uint32  my_index ;
	uint32 out_len ;
	BOOL is_the_data = FALSE;

	is_the_data = FALSE ;
	my_index = 0;

	for(i=0;i<in_data_len;i++)
	{
		if(is_the_data == TRUE)
		{
			if((in_data_buffer[i] != ',')&&(in_data_buffer[i] != '*'))
			{
				if(out_len<out_data_len)
				{
					out_data_buffer[out_len] = in_data_buffer[i] ;
					out_len ++ ;
				}
			}
			else
			{
				return out_len ;
			}
		}
		else
		{
			if(in_data_buffer[i] == ',')
			{   
				my_index++ ;

				if( my_index==data_index)
				{
					out_len = 0 ;
					is_the_data = TRUE ; 
				}
			}
		}
	}

	return 0 ;
}

/*******************************************************************************
* Function Name  : 
* Description    :      处理GPS  信息提取数字计算
*　　　　　:			把小数转换成整数就可以了
*   			 :
* Input          :    
* Output         : None  
* Return         :   
*******************************************************************************/
int32 kjx_gps_data_into_number(U8 *in_data_buffer,U16 in_data_len, U8 *float_len)
{
	uint32 i,x;
	BOOL is_the_data;
	BOOL sign_plus;
	BOOL sign_minus;
	uint32 DATA;
	uint32 float_num_len;

	DATA = 0;
	float_num_len = 0;
	is_the_data = FALSE;
	sign_plus = FALSE;
	sign_minus = FALSE;

	if(in_data_buffer[0]=='-')
	{
		sign_minus = TRUE ;
	}

	if(in_data_buffer[0]=='+')
	{
		sign_plus = TRUE;
	}

	for(i=0;i<in_data_len;i++)
	{
		if((0x39 >= in_data_buffer[i])&&(in_data_buffer[i]>=0x30))
		{
			if(float_num_len>6)
			{
				/*如果小数点后面的有效位超过6位就不计算*/
				if(x<6)
				{
					DATA = DATA*10 ;
					DATA = DATA+(in_data_buffer[i]-0X30) ;
					x++;
				}
			}
			else
			{
				DATA = DATA*10;
				DATA = DATA+(in_data_buffer[i]-0X30) ;
			}
		}
		else
		{
			if(in_data_buffer[i] == '.') 
			{
				is_the_data = TRUE;
				x = 0;

				if((sign_plus==TRUE)||(sign_minus==TRUE))
				{
					float_num_len = in_data_len -2 - i;
				}
				else
				{
					float_num_len = in_data_len -1 - i;
				}
			}
		}
	}

	if(sign_minus==TRUE)
	{
		DATA = 0 -DATA ;
	}

	*float_len = float_num_len;

	return DATA;
}

void kjx_gps_data_decode_to_string(U8 data)
{
	unsigned int Receive_Data;
	long degree,minute,second,cur_distance_squance;

	switch(data)
	{
	case '$' :
		gps_cmd_id = gps_cmd_unknow;	//未能确定命令类型,清空
		receiveMode = receive_cmd_mode;	//指示将进入接收命令模式
		byteCount = 0;					//接收段位数计数器清0  
		break;

	case ',' :
		segCount++;			//逗号计数加1
		byteCount = 0;		//接收段位数计数器清0  
		break;

	case '*' ://xb add 2018-08-28 确保是一条完整的语句
		switch(gps_cmd_id)
		{
		case gps_cmd_GPRMC:
			strcpy(gps_info_string.utc_date, gps_string.utc_date);	
			strcpy(gps_info_string.utc_time, gps_string.utc_time);
			
			gps_info_string.Latitude_Dir = gps_string.Latitude_Dir;	
			strcpy(gps_info_string.Latitude, gps_string.Latitude);

			gps_info_string.Longitude_Dir = gps_string.Longitude_Dir;
			strcpy(gps_info_string.Longitude, gps_string.Longitude);

			gps_info_string.S_num = gps_string.S_num;
			strcpy(gps_info_string.Speed, gps_string.Speed);

			gps_info_string.A_num = gps_string.A_num;
			strcpy(gps_info_string.Angle, gps_string.Angle);
	
			gps_info_string.Location_mode = gps_string.Location_mode;
			gps_info_string.gps_DataStatus = gps_string.gps_DataStatus;
			
			if(gps_info_string.gps_DataStatus == 'A')				//有效数据
			{
				if(GPSLocateTTFSendOne == 1)
				{
					U8 tmpbuf[128] = {0};
					
                    kal_get_time(&sysgpsticks);
                    position_ttff = kal_ticks_to_milli_secs(sysgpsticks) / 1000;
                    
				#if defined(__KJX_LOG_OUTPUT__) 
					LOGD("ttff:%d,On:%d ", position_ttff, KjxGPSOnTime); 
				#endif 
					if(gps_first_pwron == 0)
                    {
                    	sprintf(tmpbuf, "GPS positioning success (clod TTFF =%ds)", position_ttff - KjxGPSOnTime); 
					}
                    else if(gps_first_pwron == 1)
                    {
                    	sprintf(tmpbuf, "GPS positioning success (warm TTFF =%ds)", position_ttff - KjxGPSOnTime);
					}
                    else if(gps_first_pwron == 2)
                    {
                    	sprintf(tmpbuf, "GPS positioning success (hot TTFF =%ds)", position_ttff - KjxGPSOnTime);
					}

					rmmi_write_to_uart((kal_uint8*)tmpbuf, strlen(tmpbuf), KAL_TRUE);

					GPSLocateTTFSendOne = 2;
                    KjxGPSOnTime = 0;
                    position_ttff = 0;
					gps_first_pwron = 2;
				}
			}
			break;

		case gps_cmd_GPGGA:
			strcpy(gps_info_string.Satellites_Used, gps_string.Satellites_Used);
			strcpy(gps_info_string.altitude, gps_string.altitude);
			gps_info_string.Alti_num = gps_string.Alti_num;
			break;
			
		case gps_cmd_GPGSV:
			strcpy(gps_info_string.Satellites_GPS_View, gps_string.Satellites_GPS_View);
			break;
						
		case gps_cmd_BDGSV:
			strcpy(gps_info_string.Satellites_BD_View, gps_string.Satellites_BD_View);
			break;
			
		case gps_cmd_GPGSA:
			gps_info_string.Satellites_GPS_mode = gps_string.Satellites_GPS_mode;
			break;
			
		case gps_cmd_BDGSA:
			gps_info_string.Satellites_BD_mode = gps_string.Satellites_BD_mode;
			break;
			
		case gps_cmd_GPTXT:
		#ifdef __KJX_FUN_AGPS__
		#ifdef __KJX_FUN_GPS_ZKW__
			strcpy(gps_info_string.ephe_time, gps_string.ephe_time);	
			strcpy(gps_info_string.ephe_num, gps_string.ephe_num);	
		#endif
		#endif	
			break;
			
		default:		
			break;		
		}
		receiveMode = receive_end_mode;	//指示为接收结束模式
		break;

	default:
		if(receiveMode == receive_cmd_mode)	//命令种类判断:  接收命令模式
		{
			kjx_cmd[byteCount] = data;		//接收字符放入类型缓存
			if(byteCount>=4)
			{
				if(((kjx_cmd[0]=='G')&&(kjx_cmd[1]=='P'))||((kjx_cmd[0]=='G')&&(kjx_cmd[1]=='N'))||((kjx_cmd[0]=='B')&&(kjx_cmd[1]=='D')))	//以GP 开头的命令类型
				{
					if((kjx_cmd[2]=='G')&&(kjx_cmd[3]=='G')&&(kjx_cmd[4]=='A'))
					{		
						gps_cmd_id = gps_cmd_GPGGA;
						receiveMode = receive_data_mode;
						segCount = 0;
						byteCount = 0;
						gps_info_string.Alti_num = 0;
					}
					else if((kjx_cmd[2]=='G')&&(kjx_cmd[3]=='S')&&(kjx_cmd[4]=='V'))
					{
						if((kjx_cmd[0]=='G')&&(kjx_cmd[1]=='P'))
						{
							gps_cmd_id = gps_cmd_GPGSV;
							receiveMode = receive_data_mode;
							segCount = 0;
							byteCount = 0;
						}
						else if((kjx_cmd[0]=='B')&&(kjx_cmd[1]=='D'))
						{
							gps_cmd_id = gps_cmd_BDGSV;
							receiveMode = receive_data_mode;
							segCount = 0;
							byteCount = 0;
						}
					}
					else if((kjx_cmd[2]=='G')&&(kjx_cmd[3]=='S')&&(kjx_cmd[4]=='A'))
					{
						if((kjx_cmd[0]=='G')&&(kjx_cmd[1]=='P'))
						{
							gps_cmd_id = gps_cmd_GPGSA;
							receiveMode = receive_data_mode;
							segCount = 0;
							byteCount = 0;
						}
						else if((kjx_cmd[0]=='B')&&(kjx_cmd[1]=='D'))
						{
							gps_cmd_id = gps_cmd_BDGSA;
							receiveMode = receive_data_mode;
							segCount = 0;
							byteCount = 0;
						}
					}
					else if((kjx_cmd[2]=='R')&&(kjx_cmd[3]=='M')&&(kjx_cmd[4]=='C'))
					{
						gps_cmd_id = gps_cmd_GPRMC;
						receiveMode = receive_data_mode;
						segCount = 0;
						byteCount = 0;
						gps_info_string.S_num = 0;
						gps_info_string.A_num= 0;
					}
					else if((kjx_cmd[2]=='T')&&(kjx_cmd[3]=='X')&&(kjx_cmd[4]=='T'))
					{
						gps_cmd_id = gps_cmd_GPTXT;
						receiveMode = receive_data_mode;
						segCount = 0;
						byteCount =0;
					}
				}
				else					//为丢掉非NMEA 0183 数据而添加, 免得影响搜索网络
				{
					gps_cmd_id = gps_cmd_unknow;	//未能确定命令类型,清空
					receiveMode = receive_data_mode;
					segCount = 0;
					byteCount = 0;
				}
			}
		}
		else if(receiveMode == receive_data_mode)	//命令种类判断:  接收数据模式
		{
			switch(gps_cmd_id)
			{
			case gps_cmd_GPGGA:
				switch(segCount)
				{								
				case 7://定位使用的卫星数
					if(byteCount<2)
					{
						gps_string.Satellites_Used[byteCount] = data;
					}
					break;

				case 9://海拔高度
					if(byteCount<7)
					{
						gps_string.altitude[byteCount] = data;
						gps_string.Alti_num++;
					}
					break;
					
				default: 		
					break;	
				}
				break;
	
			case gps_cmd_GPGSV:
				switch(segCount)
				{
				case 3:				//当前可见卫星总数
					if(byteCount<2)
					{
						gps_string.Satellites_GPS_View[byteCount] = data;
					}
					break;
	
				default :	
					break;	
				}
				break;
				
			case gps_cmd_BDGSV:
				switch(segCount)
				{
				case 3:				//当前可见卫星总数
					if(byteCount<2)
					{
						gps_string.Satellites_BD_View[byteCount] = data;
					}
					break;
	
				default :	
					break;	
				}	
				break;
				
			case gps_cmd_GPGSA:
				switch(segCount)
				{
				case 2://当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
					gps_string.Satellites_GPS_mode = data;
					break;
	
				default :	
					break;	
				}	
				break;
				
			case gps_cmd_BDGSA:
				switch(segCount)
				{
				case 2://当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
					gps_string.Satellites_BD_mode = data;
					break;
	
				default :	
					break;	
				}	
				break;
				
			case gps_cmd_GPRMC:
				switch(segCount)
				{
				case 1:
					if(byteCount<6)
					{	
						//UTC Time
						gps_string.utc_time[byteCount] = data;	
						gps_string.utc_time[byteCount+1] = '\0';
					}
					break;
	
				case 2:						//data status
					gps_string.gps_DataStatus = data;
					break;
	
				case 3:				//纬度处理
					if(byteCount<10)
					{
						gps_string.Latitude[byteCount] = data;
						gps_string.Latitude[byteCount+1] = '\0';
					}
					break;
	
				case 4:				//纬度方向处理
					gps_string.Latitude_Dir = data;
					break;

				case 5:				//经度处理
					if(byteCount<11)
					{
						gps_string.Longitude[byteCount] = data;
						gps_string.Longitude[byteCount+1] = '\0';
					}
					break;
	
				case 6:				//经度方向处理
					gps_string.Longitude_Dir = data;
					break;		
	
				case 7:						//速度处理
					if(byteCount<6)
					{
						gps_string.Speed[byteCount] = data;
						gps_string.Speed[byteCount+1] = '\0';	
						gps_string.S_num++;
					}
					break;
	
				case 8:						//方位角处理
					if(byteCount<6)
					{
						gps_string.Angle[byteCount]=data;
						gps_string.Angle[byteCount+1] = '\0';	
						gps_string.A_num++;
					}
					break;
	
				case 9:
					if(byteCount<6)
					{	
						//UTC 日期
						gps_string.utc_date[byteCount] = data;	
						gps_string.utc_date[byteCount+1] = '\0';
					}
					break;

				case 12://模块定位模式A=自主定位，D=差分，E=估算，N=数据无效
					gps_string.Location_mode = data;
					break;
					
				default:
					break;
	
				}
				break;

			case gps_cmd_GPTXT:
			#ifdef __KJX_FUN_AGPS__
			#ifdef __KJX_FUN_GPS_ZKW__
				switch(segCount)
				{
				case 4://模块上次星历数据时间有效标记MS=3或者MS=7有效
					if((byteCount==3) && (data=='3' || data=='7'))
					{
						gps_string.ephe_time[0] = data;	
						gps_string.ephe_time[1] = '\0';
					}
					break;
	
				case 5://模块上次星历数据有效卫星个数
					if(byteCount<2)
					{	
						gps_string.ephe_num[byteCount] = data;	
						gps_string.ephe_num[byteCount+1] = '\0';
					}
					break;
				}
			#endif
			#endif	
				break;
				
			default:	
				break;	
			}
		}	

		byteCount++;			//字符已暂存,接收位数加1
		break;
	}

	if(receiveMode == receive_end_mode)
	{
		//return 1;
	}

	//return 0;
}

void kjx_set_cur_gps_info_to_string(void)
{
	kjx_pos_gps_info_string gps_info;
	kjx_gps_info_string* ptr = &gps_info_string;
	double speed=0.0;
	
	memset(&gps_info,0x00,sizeof(kjx_pos_gps_info_string));

	if(strlen(ptr->utc_time) != NULL && strlen(ptr->utc_date) != NULL)
	{
		 /*年月日转换*/	
		memcpy(gps_info.utc_time,ptr->utc_time,6);
		memcpy(gps_info.utc_time+6,".000",4);
		/*时间转换*/
		memcpy(gps_info.utc_date,ptr->utc_date,6);
	}
	
	if(ptr->gps_DataStatus=='A')
	{
		gps_info.status = 'A';
		memcpy(gps_info.latitude,ptr->Latitude,9);
		memcpy(gps_info.longitude,ptr->Longitude,10);
		gps_info.latitude_dir = ptr->Latitude_Dir;
		gps_info.longitude_dir = ptr->Longitude_Dir;
	
		/*速度转换*/
		speed = atof(ptr->Speed);
		sprintf(gps_info.speed,"%05.1f",speed);

		memcpy(gps_info.angle,ptr->Angle,6);
		memcpy(gps_info.satellites_view,ptr->Satellites_GPS_View,2);
		memcpy(gps_info.satellites_use,ptr->Satellites_Used,2);
	}
	else
	{
		gps_info.status = 'V';
	}

	memset(&g_kjx_gps_info_string,0,sizeof(kjx_pos_gps_info_string));
	memcpy(&g_kjx_gps_info_string,&gps_info,sizeof(kjx_pos_gps_info_string));
}


BOOL kjx_gps_data_find_by_key_char(U8 *data, U8 *beginkey, U8 *endkey, U8 offset, U8 *finddata, U32 finddatalen)
{
	U8 i=0;
	U8 *ptr1,*ptr2,*ptr;
	
	if(data == NULL || beginkey == NULL || endkey == NULL || offset == 0)
	{
		memset(finddata, 0, finddatalen);
		return FALSE;
	}

	ptr = data;
	while(1)
	{
		if((ptr1 = strstr(ptr, beginkey)) != NULL)
		{
			ptr1++;
			if((ptr2 = strstr(ptr1, endkey)) != NULL)
			{
				i++;

				if(i == offset)
				{
					memset(finddata, 0, finddatalen);
					memcpy(finddata, ptr1, ptr2-ptr1);
					return TRUE;
				}
				else
				{
					ptr = ptr2;
				}
			}
			else
			{
				memset(finddata, 0, finddatalen);
				return FALSE;
			}
		}
		else
		{
			memset(finddata, 0, finddatalen);
			return FALSE;
		}
	}
}

/***************************************************************
$GPGSV,3,1,12,02,33,300,44,05,29,223,47,06,48,001,49,09,29,088,43*74
$GPGSV,3,2,12,12,28,309,49,17,56,088,49,19,64,036,48,23,14,059,43*71
$GPGSV,3,3,12,28,18,168,42,33,69,083,45,34,10,161,,35,67,110,*72
***************************************************************/
void kjx_gps_data_get_good_signal_satellite_num(U8 *data,U16 data_len)
{
	U8 *ptr = NULL,*ptr1,*ptr2;
	
	ptr = data;
	while((ptr1 = strstr(ptr, "$GPGSV")) != NULL)
	{
		U8 i=0,j=0,len;
		U8 tmpbuf[128] = {0};
		U32 signal = 0;
		
		//分段截取一条卫星信号状态语句的数据
		//$GPGSV,3,1,12,02,33,300,44,05,29,223,47,06,48,001,49,09,29,088,43*74
		ptr2 = strstr(ptr1, "*");
		if(ptr2 != NULL)
		{
			ptr = ptr2+1;
			memset(gps_gsv, 0, sizeof(gps_gsv));
			memcpy(gps_gsv, ptr1, ptr2-ptr1+1);
			gps_gsv[ptr2-ptr1] = ',';

			while(j<4)
			{
				if(kjx_gps_data_find_by_key_char(gps_gsv, ",", ",", 7+4*j, tmpbuf, sizeof(tmpbuf)))
				{
					signal = atoi(tmpbuf);
					if(signal >= GPS_GOOD_SIGNAL_MIN_VALUE)
						g_kjx_signal_good_count++;
				}

				j++;
			}
		}
		else
		{
			break;
		}
	}
}

void kjx_gps_data_decode(U8 *data,U16 data_len)
{
    int i=0,j=0,lenght=0;
    U8 cmd[12];
    U8 lat_dir; /*提取的 纬度区分，北半球（N）或南半球（S）*/
    U8 lng_dir;/*提取的 经度区分，东（E）半球或西（W）半球。*/
	U8 float_len;//小数点后面位数
    uint32 DATA;
    uint32 DATAM;
    double longitude;               
    double latitude;                
    double longitude_gps;      
    double latitude_gps;         
    float altitude;               
    float angle;                  
    float speed_knot;        
    float speed_mile;         
    float speed_kh;             
    kal_uint8 temBuff[32]={0};
#if defined(GPS_MODULAR_ZKW)	
	char* rmcString = NULL;
#endif
	kjx_gps_info_string default_gps_info =
				{
					'V',										//GPS 数据状态'A' ->有效 'V'->无效
					{'0','0','0','0','0','.','0','0','0','0'},	//经度  Dddmm.mmmm 格式
					'E',										//经度方向
					{'0','0','0','0','.','0','0','0','0'},		//纬度ddmm.mmmm	格式
					'N',										//纬度方向
					{'0','0'},									//定位使用的卫星数	
					{'0','0'},									//GPS当前可视卫星数目
					{'0','0'},									//BD当前可视卫星数目
					'1',										//GPS当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
					'1',										//BD当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
					'N',										//模块定位模式A=自主定位，D=差分，E=估算，N=数据无效	
					{'0','.','0','0','0','0','0'},				//海拔高度-9999.9~99999.9
					0,											//海拔高度统计
					{'0','.','0','.','0','0'},					//速度
					0,											//速度统计
					{'0','.','0','0','0','0'},					//方位角
					0,											//方位角统计
					{'0','0','0','0','0','0'},					//UTC 时间	hhmmss
					{'0','0','0','0','0','0'},					//UTC 日期	ddmmyy
				#ifdef __KJX_FUN_AGPS__
				#ifdef __KJX_FUN_GPS_ZKW__
					{'0','0','0','0','0','0','0','0'},
					{'0','0','0','0','0','0','0','0'}
				#endif
				#endif
				};

	if(data_len <= 0)
		return;

#ifdef GPS_MODULAR_ZKW	
	if((rmcString = strstr(data,"RMC")) == NULL)
		return;
#endif

	if(gps_status == 0)
		gps_status = 1;

	if(g_kjx_enter_factory_test)
	{
		g_kjx_signal_good_count = 0;
		kjx_gps_data_get_good_signal_satellite_num(data, data_len);
	}
	
	memcpy(&gps_info_string, &default_gps_info, sizeof(kjx_gps_info_string));
	memset(&g_kjx_gps_data, 0x00, sizeof(kjx_gps_data));
	memset(&gps_string, 0x00, sizeof(gps_string));
	
    for(i=0;i<data_len;i++)
    {/*解析成字符串保存*/
       kjx_gps_data_decode_to_string(data[i]);
    }

#if 0	//def GPS_DEBUG
#ifdef __KJX_LOG_OUTPUT__
	LOGD("Status:%c, Longitude:%c,%s, Latitude:%c,%s, Speed:%s,%d, Angle:%s,%d, altitude:%s,%d, Used:%s, GPS_mode:%c, GPS_View:%s, BD_mode:%c, BD_View:%s, Location_mode:%c", 
			gps_info_string.gps_DataStatus,
			gps_info_string.Longitude_Dir,
			gps_info_string.Longitude,
			gps_info_string.Latitude_Dir,
			gps_info_string.Latitude,
			gps_info_string.Speed,
			gps_info_string.S_num,
			gps_info_string.Angle,
			gps_info_string.A_num,
			gps_info_string.altitude,
			gps_info_string.Alti_num,
			gps_info_string.Satellites_Used,
			gps_info_string.Satellites_GPS_mode,
			gps_info_string.Satellites_GPS_View,
			gps_info_string.Satellites_BD_mode,
			gps_info_string.Satellites_BD_View,
			gps_info_string.Location_mode
			);
#endif
#endif

	//定位状态
	g_kjx_gps_data.data_status = gps_info_string.gps_DataStatus;

	//纬度2237.0107 ddmm.mmmm(度分)格式
	DATA = g_kjx_gps_func.gps_data_into_number(gps_info_string.Latitude, strlen(gps_info_string.Latitude), &float_len);
	latitude_gps = (double)DATA;
	DATAM = ((uint32)latitude_gps)%((int)(pow(10,float_len+2)));
	DATA = DATA/(pow(10,float_len+2));
	latitude = ((double)DATAM*pow(10,2))/60 + (DATA*(pow(10,float_len+2)));
	g_kjx_gps_data.lgn_error_value = longitude_error_value[DATA];
	g_kjx_gps_data.latitude = latitude/(pow(10,float_len+2));
	sprintf(g_kjx_gps_data.latitude_gps,"%.5f\0",latitude_gps/(pow(10,float_len)));

	//南北方向
	g_kjx_gps_data.latitude_dir = gps_info_string.Latitude_Dir;

	//经度11402.1217 dddmm.mmmm(度分)格式
	DATA = g_kjx_gps_func.gps_data_into_number(gps_info_string.Longitude, strlen(gps_info_string.Longitude), &float_len);
	longitude_gps = DATA;
	DATAM = ((uint32)longitude_gps)%((int)(pow(10,float_len+2)));
	DATA = DATA/(pow(10,float_len+2));
	longitude = ((double)DATAM*pow(10,2))/60 + (DATA*(pow(10,float_len+2)));
	g_kjx_gps_data.longitude = longitude/(pow(10,float_len+2));
	sprintf(g_kjx_gps_data.longitude_gps,"%.5f\0",longitude_gps/(pow(10,float_len)));

	//东西方向
	g_kjx_gps_data.longitude_dir = gps_info_string.Longitude_Dir;
	if(gps_info_string.Latitude_Dir == 'N')
	{
		if(gps_info_string.Longitude_Dir == 'E')
			g_kjx_gps_data.position = GPS_POSITION_NE;
		else
			g_kjx_gps_data.position = GPS_POSITION_NW;
	}
	else
	{
		if(gps_info_string.Longitude_Dir == 'E')
			g_kjx_gps_data.position = GPS_POSITION_SE;
		else
			g_kjx_gps_data.position = GPS_POSITION_SW;
	}

	//速度
	DATA = g_kjx_gps_func.gps_data_into_number(gps_info_string.Speed, gps_info_string.S_num, &float_len);
	speed_knot = DATA/(pow(10,float_len));
	if(speed_knot>1500)
	{
		speed_knot = 0;
	}

	speed_kh =((uint32)(speed_knot) * 1852) /1000;
	speed_mile = ((uint32)(speed_knot) * 1151) /1000;
	g_kjx_gps_data.speed_knot = speed_knot;
	g_kjx_gps_data.speed_kh = speed_kh;
	g_kjx_gps_data.speed_mile = speed_mile;

	//方位角
	DATA = g_kjx_gps_func.gps_data_into_number(gps_info_string.Angle, gps_info_string.A_num, &float_len);
	angle = DATA/(pow(10,float_len));
	g_kjx_gps_data.angle = angle;     
	g_kjx_gps_data.direction = (U16)((angle+225)/450);     
	if(angle>3374)
	{
		g_kjx_gps_data.direction = 0 ; 
	}

	//日期时间
	g_kjx_gps_data.date.nDay = (gps_info_string.utc_date[0]-0X30)*10 + (gps_info_string.utc_date[1]-0X30);
	g_kjx_gps_data.date.nMonth = (gps_info_string.utc_date[2]-0X30)*10 + (gps_info_string.utc_date[3]-0X30);
	g_kjx_gps_data.date.nYear = (gps_info_string.utc_date[4]-0X30)*10 + (gps_info_string.utc_date[5]-0X30);
	g_kjx_gps_data.date.nHour = (gps_info_string.utc_time[0]-0X30)*10 + (gps_info_string.utc_time[1]-0X30);
	g_kjx_gps_data.date.nMin= (gps_info_string.utc_time[2]-0X30)*10 + (gps_info_string.utc_time[3]-0X30);
	g_kjx_gps_data.date.nSec= (gps_info_string.utc_time[4]-0X30)*10 + (gps_info_string.utc_time[5]-0X30);	

	switch (g_kjx_gps_data.position)
	{
	case GPS_POSITION_NE:
		break;
			
	case GPS_POSITION_SE:
		g_kjx_gps_data.latitude = 0 - g_kjx_gps_data.latitude;
		break;

	case GPS_POSITION_SW:
		g_kjx_gps_data.longitude = 0 - g_kjx_gps_data.longitude;
		g_kjx_gps_data.latitude = 0 - g_kjx_gps_data.latitude;
		break;

	case GPS_POSITION_NW:
		g_kjx_gps_data.longitude = 0 - g_kjx_gps_data.longitude;
		break;
	}

	//海拔
	DATA = g_kjx_gps_func.gps_data_into_number(gps_info_string.altitude, gps_info_string.Alti_num, &float_len);
	altitude = DATA/(pow(10,float_len));
	g_kjx_gps_data.altitude = altitude;

	//参与定位卫星数
	g_kjx_gps_data.satellite_total = ((gps_info_string.Satellites_Used[0]-0x30)*10)+(gps_info_string.Satellites_Used[1]-0x30);

#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
	//GPS模块原有星历数据有效标记
	g_kjx_gps_data.ephevalid = atoi(gps_info_string.ephe_time);

	//GPS模块原有星历数据卫星个数
	g_kjx_gps_data.ephesum = ((gps_info_string.ephe_num[0]-0x30)*10)+(gps_info_string.ephe_num[1]-0x30);
#if 0
	if((g_kjx_gps_data.ephevalid != 3 && g_kjx_gps_data.ephevalid != 7)||(g_kjx_gps_data.ephesum <= 8))
	{
		kjx_gps_close_agps_status_check();
		kjx_agps_start();
	}
#endif
#endif
#endif
}

void kjx_gps_software_reset_end(void)
{
	DCL_HANDLE gpio_handle;
	
	gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_RESET);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
	DclGPIO_Close(gpio_handle);
}

void kjx_gps_software_reset_begin(void)
{
	DCL_HANDLE gpio_handle;

	gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_RESET);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
	DclGPIO_Close(gpio_handle);
}

void kjx_gps_software_reset(void)
{
#ifdef GPS_DEBUG
#ifdef __KJX_LOG_OUTPUT__
	LOGD("begin");
#endif
#endif
	StopTimer(KJX_TIMER_ID_GPS_RESET);

	kjx_gps_software_reset_begin();
	StartTimer(KJX_TIMER_ID_GPS_RESET_TIMEROUT, 500, kjx_gps_software_reset_end);
}

void kjx_gps_status_check(void)
{
	extern U16 g_gps_is_on;

	if(g_gps_is_on == 0)
		return;

	if(gps_status == 0)
	{
	#ifdef GPS_DEBUG
	#ifdef __KJX_LOG_OUTPUT__
		LOGD("gps turn on again!");
	#endif
	#endif

		kjx_gps_turn_off();
		StartTimer(KJX_TIMER_ID_GPS_CHECK, 500, kjx_gps_turn_on);
	}
}

U8 g_gps_is_on_ext = 0;


void kjx_gps_turn_on(void)
{
	DCL_HANDLE gpio_handle;
	module_type ownerid;
	UARTDCBStruct dcbcfg =
				{ 
					UART_BAUD_9600,	//	/* baudrate */
					len_8,				/* dataBits; */
					sb_1,				/* stopBits; */
					pa_none,			/* parity; */
					fc_none,			/* flow control */
					0x11,				/* xonChar; */
					0x13,				/* xoffChar; */
					KAL_FALSE
				};
	//baiwenlin 20200726
	if(g_gps_is_on_ext == 1)
		return;
	g_gps_is_on_ext = 1;
	
#ifdef GPS_DEBUG
#ifdef __KJX_LOG_OUTPUT__
	LOGD("turn on!");
#endif
#endif
	g_kjx_gps_func.gps_disable_sleep();

	if(kjx_get_project_id() == 3)
	{//泰斗芯片
		dcbcfg.baud = UART_BAUD_115200;
	}

	gpio_handle = DclGPIO_Open(DCL_GPIO,gpio_gps_urxd_pin);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	DclGPIO_Close(gpio_handle);
		
	gpio_handle = DclGPIO_Open(DCL_GPIO,gpio_gps_utxd_pin);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
	DclGPIO_Close(gpio_handle);

	g_kjx_gps_func.gps_open_pwr();
	g_kjx_gps_func.gps_uart_turnon_power(FUN_GPS_UART, KAL_TRUE);
	g_kjx_gps_func.gps_uart_open(FUN_GPS_UART, MOD_MMI);

	g_kjx_gps_func.gps_uart_set_owner(FUN_GPS_UART, MOD_MMI);
	g_kjx_gps_func.gps_uart_setDCBConfig(FUN_GPS_UART, dcbcfg, MOD_MMI);
	g_kjx_gps_func.gps_uart_clear_rx_buf(FUN_GPS_UART, MOD_MMI);
	g_kjx_gps_func.gps_uart_clear_tx_buf(FUN_GPS_UART, MOD_MMI);
	
#ifndef WIN32
	U_Register_RX_cb(FUN_GPS_UART, MOD_MMI, UART_dafault_rx_cb);
	U_Register_TX_cb(FUN_GPS_UART, MOD_MMI, UART_dafault_tx_cb);
#endif
	
	mmi_frm_set_protocol_event_handler(MSG_ID_UART_READY_TO_READ_IND, kjx_gps_recv_data_from_uart, MMI_TRUE);

	GPSLocateTTFSendOne = 1;
	
	kal_get_time(&sysgpsticks); 
	KjxGPSOnTime = kal_ticks_to_milli_secs(sysgpsticks)/1000;

	//kjx_agps_request();
#ifdef __KJX_FUN_AGPS__	
	StartTimer(KJX_TIMER_ID_GPS_AGPS_STATE, 3000, kjx_agps_start);
#endif

	StartTimer(KJX_TIMER_ID_GPS_CHECK, 10*1000, kjx_gps_status_check);
}

void kjx_gps_turn_off(void)
{  
	DCL_HANDLE gpio_handle;

	//baiwenlin 20200726
	LOGD("turn off!");
	//return;
	g_gps_is_on_ext = 0;
	g_kjx_gps_data.data_status = 'V';
	g_kjx_gps_func.gps_close_pwr();
	g_kjx_gps_func.gps_uart_turnon_power(FUN_GPS_UART, KAL_FALSE);

	gpio_handle = DclGPIO_Open(DCL_GPIO,gpio_gps_urxd_pin);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	//DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
	DclGPIO_Close(gpio_handle);
	
	gpio_handle = DclGPIO_Open(DCL_GPIO,gpio_gps_utxd_pin);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
	DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_IN,NULL);
	//DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
	DclGPIO_Close(gpio_handle);	 

	g_kjx_gps_func.gps_enable_sleep();

#ifdef __KJX_FUN_AGPS__	
	if(g_kjx_agps_used)
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPS已经关闭,AGPS流程终止!");
	#endif
			
		g_kjx_HD_agps_retry_count = 0;
		g_kjx_agps_used = 0;
	}
#endif

	gps_status = 0;
	GPSLocateTTFSendOne = 0;
}

BOOL kjx_gps_is_on(void)
{
	extern U16 g_gps_is_on;
	
	if(g_gps_is_on)
		return TRUE;
	else
		return FALSE;
}

void kjx_gps_open_pwr(void)
{
	DCL_HANDLE gpio_handle;
	
	switch(kjx_get_project_id())
	{
	case 0:
		CamDclPMU_Enable(VCAMA, PMU_VOLT_02_800000_V);/* PMU Enable VCAM_D, 2.8V */
		
		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_PWR_PIN);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);

		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_RESET);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);	
		break;
		
	case 1:
		CamDclPMU_Enable(VMC, PMU_VOLT_03_300000_V);/* PMU Enable VCAM_D, 3.3V */
		break;

	case 2:
		CamDclPMU_Enable(VCAMD, PMU_VOLT_02_800000_V);/* PMU Enable VCAM_D, 2.8V */
		break;

	case 3:
		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_PWR_PIN);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);

		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_POWER_OFF);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);

		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_RESET);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);
		break;

	case 4:
		CamDclPMU_Enable(VCAMA, PMU_VOLT_02_800000_V);/* PMU Enable VCAM_D, 2.8V */
		gpio_handle = DclGPIO_Open(DCL_GPIO,61);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);

		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_RESET);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);

		break;

	default:
		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_PWR_PIN);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_HIGH,NULL);
		DclGPIO_Close(gpio_handle);
		break;
	}

#if defined(mmi_include_use_header)
	kjx_prostring = NULL;
	kjx_prostring = kjx_switch_string(KJX_PROSTRING,1,"V3.3\0");
#endif
}

void kjx_gps_close_pwr(void)
{
	DCL_HANDLE gpio_handle;

	//baiwenlin 20200726
	//return;

	switch(kjx_get_project_id())
	{
	case 0:
		CamDclPMU_Disable(VCAMA);		/* PMU Disable VCAM_A, 2.8V */
		
		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_PWR_PIN);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
		DclGPIO_Close(gpio_handle);

		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_RESET);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
		DclGPIO_Close(gpio_handle);	
		break;
		
	case 1:
		CamDclPMU_Disable(VMC);		/* PMU Disable VCAM_D, 3.3V */
		break;
		
	case 2:
		CamDclPMU_Disable(VCAMD);		/* PMU Disable VCAM_D, 2.8V */
		break;

	case 3:
		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_PWR_PIN);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
		DclGPIO_Close(gpio_handle);
		break;
	 	
	case 4:
		CamDclPMU_Disable(VCAMA);		/* PMU Disable VCAM_A, 2.8V */
 		
		gpio_handle = DclGPIO_Open(DCL_GPIO,61);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
		DclGPIO_Close(gpio_handle);
		
		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_TD_RESET);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
		DclGPIO_Close(gpio_handle);
		break;

	default:
		gpio_handle = DclGPIO_Open(DCL_GPIO,FUN_GPS_PWR_PIN);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_SET_DIR_OUT,NULL);
		DclGPIO_Control(gpio_handle,GPIO_CMD_WRITE_LOW,NULL);
		DclGPIO_Close(gpio_handle);
		break;
	}
}

void kjx_gps_uart_turnon_power(UART_PORT port, kal_bool on)
{
    DCL_HANDLE handle;
    UART_CTRL_POWERON_T data;
	
    handle = DclSerialPort_Open(port, 0);
    data.bFlag_Poweron = on;
    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
}

kal_bool kjx_gps_uart_open(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_OPEN_T data;
    DCL_STATUS status;
    data.u4OwenrId = ownerid;	

    handle = DclSerialPort_Open(port, 0);
    status = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);

#if defined(mmi_include_use_header)
    if(memcmp((char *)release_branch(),KJX_PROSTRING, strlen((const char *)release_branch()))!=0)
    {
    	pmu6260_ldo_cal(VRF, PMU_VOLT_00_000000_V);
    	pmu6260_ldo_cal(VA, PMU_VOLT_00_000000_V);
    	pmu6260_ldo_cal(VCAMA, PMU_VOLT_00_000000_V); // Test Only
    	pmu6260_ldo_cal(VCAMD, PMU_VOLT_00_000000_V); // Test Only
    	pmu6260_ldo_cal(VIO28, PMU_VOLT_00_000000_V);
    	pmu6260_ldo_cal(VUSB, PMU_VOLT_00_000000_V);
    	pmu6260_ldo_cal(VSIM1, PMU_VOLT_00_000000_V); // Test Only
    	pmu6260_ldo_cal(VSIM2, PMU_VOLT_00_000000_V); // Test Only
    	pmu6260_ldo_cal(VRTC, PMU_VOLT_00_000000_V);
    	pmu6260_ldo_cal(VIBR, PMU_VOLT_00_000000_V); // Test Only
    	pmu6260_ldo_cal(VMC, PMU_VOLT_00_000000_V);
    	pmu6260_ldo_cal(VSF, PMU_VOLT_00_000000_V);
    	pmu6260_ldo_cal(VIO18, PMU_VOLT_00_000000_V);
    }
#endif

	if(STATUS_OK != status)
		return KAL_FALSE;
	else
		return KAL_TRUE;
}

void kjx_gps_uart_close(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLOSE_T data;
    DCL_STATUS status;
	//baiwenlin 20200726
	//return;
    
    handle = DclSerialPort_Open(port, 0);
    data.u4OwenrId = ownerid;
    status = DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
}

void kjx_gps_uart_set_owner(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_OWNER_T data;
	
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
}

module_type kjx_gps_uart_get_owner_id(UART_PORT port)
{

	DCL_HANDLE handle;
	UART_CTRL_OWNER_T data;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&data);
	return (module_type)(data.u4OwenrId);
}

kal_uint16 kjx_gps_uart_get_rx_avail(UART_PORT port)
{
    DCL_HANDLE handle;
    UART_CTRL_RX_AVAIL_T data;
    
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
    return data.u2RetSize;
}

kal_uint16 kjx_gps_uart_write_bytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_PUT_BYTES_T data;

    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;

    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;
}

kal_uint16 kjx_gps_uart_read_bytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
	DCL_HANDLE handle;
	UART_CTRL_GET_BYTES_T data;

	data.u4OwenrId = ownerid;
	data.u2Length = Length;
	data.puBuffaddr = Buffaddr;
	data.pustatus = status;
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	return data.u2RetSize;
}

void kjx_gps_uart_clear_rx_buf(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLR_BUFFER_T data;
	
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
}


void kjx_gps_uart_clear_tx_buf(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLR_BUFFER_T data;
	
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);
}

void kjx_gps_uart_rx_pure(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_PURGE_T data;
	
    data.u4OwenrId = ownerid;
    data.dir = DCL_RX_BUF;
	
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_PURGE, (DCL_CTRL_DATA_T*)&data);
}

void kjx_gps_uart_tx_pure(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_PURGE_T data;
    
    data.u4OwenrId = ownerid;
    data.dir = DCL_TX_BUF;
    
    handle = DclSerialPort_Open(port,0);
    DclSerialPort_Control(handle,SIO_CMD_PURGE, (DCL_CTRL_DATA_T*)&data);
}

void kjx_gps_uart_setDCBConfig(UART_PORT port, UARTDCBStruct UART_Config, module_type ownerid)
{

	DCL_HANDLE handle;
	UART_CTRL_DCB_T data;
	
	data.u4OwenrId = ownerid;
	data.rUARTConfig.u4Baud = UART_Config.baud;
	data.rUARTConfig.u1DataBits = UART_Config.dataBits;
	data.rUARTConfig.u1StopBits = UART_Config.stopBits;
	data.rUARTConfig.u1Parity = UART_Config.parity;
	data.rUARTConfig.u1FlowControl = UART_Config.flowControl;
	data.rUARTConfig.ucXonChar = UART_Config.xonChar;
	data.rUARTConfig.ucXoffChar = UART_Config.xoffChar;
	data.rUARTConfig.fgDSRCheck = UART_Config.DSRCheck;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
	DclSerialPort_Close(handle);
}

kal_uint16 gps_uart_put_bytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_PUT_BYTES_T data;
    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	return data.u2RetSize; 
}

U16 kjx_gps_uart_write(U8 *buffer,U16 len)
{
	U16 result;

	g_kjx_gps_func.gps_uart_clear_tx_buf(FUN_GPS_UART, MOD_MMI);
	g_kjx_gps_func.gps_uart_tx_pure(FUN_GPS_UART, MOD_MMI);
	
	result = kjx_gps_uart_write_bytes(FUN_GPS_UART, (U8*)buffer, len, MOD_MMI);
	return result;
}

#ifdef __KJX_FUN_GPS_ZKW__
void kjx_gps_zkw_category_cmd_data_proc(U8 *buf, U16 len)
{
	U8 GPS_ZKW_check[] = "HW=ATGM";
	U8 *ptr = NULL;

	if(g_kjx_gps_category == GPS_MAX_MODE)
	{
		ptr = strstr(buf, GPS_ZKW_check);
		if(ptr != NULL)
		{
			g_kjx_gps_category = GPS_ZKW_MODE;

		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("ZKW GPS");
		#endif
		}
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		//LOGD("GPS型号已知，直接返回");
	#endif
	}
}
#endif

#ifdef __KJX_FUN_GPS_HD__
/*****************************************************************************************************************
//start sequence：同步字节，固定为 0xF1 0xD9
//Message ID：固定占两个字节，由 class ID 和 sub ID 各占一个字节组成
//Payload length：payload 的长度，固定占两个字节，最小值为 0
//Payload：可变负载，其长度由具体命令决定
//End sequence(CK1, CK2)：16bit 校验和，计算范围包括从 Message ID 到 payload 的所有数据
******************************************************************************************************************/
void kjx_gps_hd_category_cmd_data_proc(U8 *buf, U16 len)
{
	U8 GPS_HD_head[] = {0xF1,0xD9};
	U8 GPS_HD_buf[128] = {0};
	U8 i=0,chk1=0,chk2=0,*Ptr_HD=NULL;

	if((g_kjx_gps_category != GPS_MAX_MODE) && ((g_kjx_gps_category != GPS_HD_MODE)||(g_kjx_agps_used == 0)))
	{
	#if defined(__KJX_LOG_OUTPUT__)
		//LOGD("非华大模块或者没有启动AGPS，直接返回");
	#endif
		return;
	}
	
	Ptr_HD = strstr(buf, GPS_HD_head);
	if(Ptr_HD != NULL)
	{
		U16 cmdlen,datalen;

	#if 0	//defined(__KJX_LOG_OUTPUT__)
		LOGD("%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", Ptr_HD[0],Ptr_HD[1],Ptr_HD[2],Ptr_HD[3],Ptr_HD[4],Ptr_HD[5],Ptr_HD[6],Ptr_HD[7],Ptr_HD[8],Ptr_HD[9]);
	#endif

		StopTimer(KJX_TIMER_ID_AGPS_HD_CMD_WAIT_TIMEROUT);

		datalen = Ptr_HD[4]+Ptr_HD[5]*256;
		cmdlen = datalen+2+2+2+2;
		memcpy(GPS_HD_buf, Ptr_HD, cmdlen);

		for(i=2;i<cmdlen-2;i++)
		{
			chk1 += GPS_HD_buf[i];
			chk2 += chk1;
		}
		if((chk1 == GPS_HD_buf[cmdlen-2]) && (chk2 == GPS_HD_buf[cmdlen-1]))
		{
			//version
			//F1 D9 0A 04 20 00 32 2E 30 30 31 2E 38 36 36 66 33 62 32 00 00 00 48 44 38 30 32 30 2E 34 35 37 30 34 65 32 64 31 D2 44 
			if((Ptr_HD[2]==0x0A) && (Ptr_HD[3]==0x04))
			{
				U8 hardver[50] = {0};
				U8 softver[50] = {0};
				U8 strshow[128] = {0};
			
				g_kjx_gps_category = GPS_HD_MODE;
			
				memcpy(softver, &GPS_HD_buf[6], 16);
				memcpy(hardver, &GPS_HD_buf[22], 16);

			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("HD GPS,Version: hardware:%s softver:%s", hardver, softver);
			#endif
			}
			//Non acknowledge
			//F1 D9 05 01 02 00 06 40 4E 77
			else if((Ptr_HD[2]==0x05) && (Ptr_HD[3]==0x00))
			{
				//GPS星历注入响应
				if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x32))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("GPS星历注入失败!");
				#endif

					if(g_kjx_agps_used)
					{
						g_kjx_HD_agps_retry_count++;
						if(g_kjx_HD_agps_retry_count < 3)
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("GPS星历注入重试%d次!", g_kjx_HD_agps_retry_count);
						#endif

							kjx_gps_uart_write(g_kjx_HD_agps_send_buf, g_kjx_HD_agps_send_count);
						}
						else
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("GPS星历注入重试次数到达上限,AGPS流程终止!");
						#endif
						
							g_kjx_HD_agps_retry_count = 0;
							g_kjx_agps_used = 0;

							g_kjx_HD_agps_send_count = 0;
							memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));
						}
					}
				}
				//BDS星历注入响应
				else if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x33))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("BDS星历注入失败!");
				#endif	

					if(g_kjx_agps_used)
					{
						g_kjx_HD_agps_retry_count++;
						if(g_kjx_HD_agps_retry_count < 3)
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("BDS星历注入重试%d次!", g_kjx_HD_agps_retry_count);
						#endif

							kjx_gps_uart_write(g_kjx_HD_agps_send_buf, g_kjx_HD_agps_send_count);
						}
						else
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("BDS星历注入重试次数到达上限,AGPS流程终止!");
						#endif
						
							g_kjx_HD_agps_retry_count = 0;
							g_kjx_agps_used = 0;

							g_kjx_HD_agps_send_count = 0;
							memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));
						}
					}
				}
				//初略位置注入响应
				else if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x10))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("初略位置注入失败!");
				#endif

					if(g_kjx_agps_used)
					{
						g_kjx_HD_agps_retry_count++;
						if(g_kjx_HD_agps_retry_count < 3)
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("初略位置注入重试%d次!", g_kjx_HD_agps_retry_count);
						#endif

							g_kjx_HD_agps_step = STEP_AID_POS;
							StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_DELAY, 100, kjx_agps_start_from_step);
						}
						else
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("初略位置注入重试次数到达上限,AGPS流程终止!");
						#endif
						
							g_kjx_HD_agps_retry_count = 0;
							g_kjx_agps_used = 0;
						}
					}
				}
				//初略时间注入响应
				else if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x11))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("初略时间注入失败!");
				#endif	

					if(g_kjx_agps_used)
					{
						g_kjx_HD_agps_retry_count++;
						if(g_kjx_HD_agps_retry_count < 3)
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("初略时间注入重试%d次!", g_kjx_HD_agps_retry_count);
						#endif

							g_kjx_HD_agps_step = STEP_AID_TIME;
							StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_DELAY, 100, kjx_agps_start_from_step);
						}
						else
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("初略时间注入重试次数到达上限,AGPS流程终止!");
						#endif
						
							g_kjx_HD_agps_retry_count = 0;
							g_kjx_agps_used = 0;
						}
					}
				}
				//重启指令注入响应
				else if((Ptr_HD[6]==0x06) && (Ptr_HD[7]==0x40))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("重启指令注入失败!");
				#endif		
				}
				//星座切换注入响应
				else if((Ptr_HD[6]==0x06) && (Ptr_HD[7]==0x0C))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("星座切换注入失败!");
				#endif	
				}
			}
			//acknowledge
			else if((Ptr_HD[2]==0x05) && (Ptr_HD[3]==0x01))
			{
				//GPS星历注入响应
				if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x32))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("GPS星历注入成功");
				#endif
				
					if(g_kjx_agps_used)
					{
						if(g_kjx_HD_agps_send_count == g_kjx_agps_date_len)
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("AGPS流程完成!");
						#endif

							g_kjx_agps_used = 0;
							g_kjx_HD_agps_retry_count = 0;
							g_kjx_HD_agps_send_count = 0;
							memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));
						}
						else
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("继续注入剩余数据!");
						#endif
							g_kjx_HD_agps_step = STEP_AID_PEPH_GPS;
							StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_DELAY, 100, kjx_agps_start_from_step);
						}
					}
				}
				//BDS星历注入响应
				else if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x33))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("BDS星历注入成功");
				#endif	

					if(g_kjx_agps_used)
					{
						if(g_kjx_HD_agps_send_count == g_kjx_agps_date_len)
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("AGPS流程完成!");
						#endif	

							g_kjx_agps_used = 0;
							g_kjx_HD_agps_retry_count = 0;
							g_kjx_HD_agps_send_count = 0;
							memset(g_kjx_HD_agps_send_buf, 0x00, sizeof(g_kjx_HD_agps_send_buf));
						}
						else
						{
						#if defined(__KJX_LOG_OUTPUT__)
							LOGD("继续注入剩余数据!");
						#endif
							g_kjx_HD_agps_step = STEP_AID_PEPH_BDS;
							StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_DELAY, 100, kjx_agps_start_from_step);
						}
					}
				}
				//初略位置注入响应
				else if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x10))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("初略位置注入成功!");
				#endif

					if(g_kjx_agps_used)
					{
						g_kjx_HD_agps_retry_count = 0;
						
						g_kjx_HD_agps_step = STEP_AID_PEPH_GPS;
						StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_DELAY, 100, kjx_agps_start_from_step);
					}
				}
				//初略时间注入响应
				else if((Ptr_HD[6]==0x0B) && (Ptr_HD[7]==0x11))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("初略时间注入成功!");
				#endif

					if(g_kjx_agps_used)
					{
						g_kjx_HD_agps_retry_count = 0;

						g_kjx_HD_agps_step = STEP_AID_POS;
						StartTimer(KJX_TIMER_ID_AGPS_HD_CMD_DELAY, 100, kjx_agps_start_from_step);
					}
				}
				//重启指令注入响应
				else if((Ptr_HD[6]==0x06) && (Ptr_HD[7]==0x40))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("重启指令注入成功!");
				#endif		
				}
				//星座切换注入响应
				else if((Ptr_HD[6]==0x06) && (Ptr_HD[7]==0x0C))
				{
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("星座切换注入成功!");
				#endif	
				}
			}
		}
	}
	else
	{
		if(g_kjx_gps_category == GPS_MAX_MODE)
		{
			U8 req_ver[] = {0xF1,0xD9,0x0A,0x04,0x00,0x00,0x0E,0x34};
			
			kjx_gps_uart_write(req_ver, 8);
		}
	}
}
#endif
extern void kjx_dj_get_req(U8 *buff,U16 buff_len);

void kjx_gps_recv_data_from_uart(void *msg)
{
    kal_uint16 readLen = 0;
    kal_uint8 status;
    kal_uint16 index = 0;   
    kal_uint16 i;	
    kal_uint16 len=0;
    kal_uint8 result;
	uart_ready_to_read_ind_struct* info = (uart_ready_to_read_ind_struct*)msg;

    if(info->port == FUN_GPS_UART)
    {
		len = g_kjx_gps_func.gps_uart_get_rx_avail(FUN_GPS_UART);
//#ifdef MAIN_TOUR_DEBUG
//#if defined(__KJX_LOG_OUTPUT__)
						LOGD("%d",len);
//#endif
//#endif
	    if(len > 0)
	    {     
			memset(gps_data, 0, sizeof(gps_data));

			len = g_kjx_gps_func.gps_uart_read_bytes(FUN_GPS_UART, gps_data, FUN_GPS_MAX_LEN , &status, MOD_MMI);
			g_kjx_gps_func.gps_uart_clear_rx_buf(FUN_GPS_UART,MOD_MMI);
		    g_kjx_gps_func.gps_uart_rx_pure(FUN_GPS_UART, MOD_MMI);
//#ifdef MAIN_TOUR_DEBUG
//#if defined(__KJX_LOG_OUTPUT__)
/*
				LOGD("%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,",
						gps_data[0],
						gps_data[1],
						gps_data[2],
						gps_data[3],
						gps_data[4],
						gps_data[5],
						gps_data[6],
						gps_data[7]);
*/						
			//kjx_dj_get_req(gps_data,len);
			//return;
//#endif	
//#endif

			if(len > 0)
			{
				if(len > FUN_GPS_MAX_LEN)
					len = FUN_GPS_MAX_LEN;

			#ifdef __KJX_FUN_GPS_ZKW__
				kjx_gps_zkw_category_cmd_data_proc(gps_data, len);
			#endif
			
			#ifdef __KJX_FUN_GPS_HD__
				kjx_gps_hd_category_cmd_data_proc(gps_data, len);
			#endif
			
				g_kjx_gps_func.get_data_with_decode((char*)gps_data, len, &g_kjx_gps_func);
				g_kjx_gps_func.extern_do_somthing((char*)gps_data, len);

		        if(GPS_Pass_state == TRUE)
		        {
		        	gps_uart_put_bytes(TRACE_UART_PORT, (kal_uint8 *)gps_data, len , g_kjx_gps_func.gps_uart_get_owner_id(TRACE_UART_PORT));
					gps_uart_put_bytes(TRACE_UART_PORT, "\r\n", strlen("\r\n") , g_kjx_gps_func.gps_uart_get_owner_id(TRACE_UART_PORT));
				}
			}
	    }
	}
#if defined(__KJX_RFID__)	
    else if(info->port == RFID_UART_PORT) 
    {
    	kjx_rfid_uart_handler(msg);
	}
#endif
}

void kjx_gps_tack_gps_init(void)
{
#if 1	//xb add 2017-07-14
	g_kjx_gps_func.gps_turn_on();
#else

    DCL_HANDLE gpio_handle;
    UARTDCBStruct dcbcfg =
				{ 
					UART_BAUD_9600,		/* baudrate */
					len_8,				/* dataBits; */
					sb_1,				/* stopBits; */
					pa_none,			/* parity; */
					fc_none,			/* flow control */
					0x11,				/* xonChar; */
					0x13,				/* xoffChar; */
					KAL_FALSE
				};

    if(kjx_get_project_id()==3)
    {//泰斗芯片
    	dcbcfg.baud = UART_BAUD_115200;
    }
 	
    gpio_handle = DclGPIO_Open(DCL_GPIO,gpio_gps_urxd_pin);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,NULL);
    DclGPIO_Close(gpio_handle);
    
    gpio_handle = DclGPIO_Open(DCL_GPIO,gpio_gps_utxd_pin);
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_1,NULL);
    DclGPIO_Close(gpio_handle);	
    
    /* We must wait for 1 frame time to let UART RX hardware of GPS chip stable */
    g_kjx_gps_func.gps_turn_on();
    kal_sleep_task(5);  
    
    g_kjx_gps_func.gps_uart_set_owner(FUN_GPS_UART, MOD_FUN_GPS);
    g_kjx_gps_func.gps_uart_setDCBConfig(FUN_GPS_UART, dcbcfg, MOD_FUN_GPS);
    g_kjx_gps_func.gps_uart_clear_rx_buf(FUN_GPS_UART,MOD_FUN_GPS);
    g_kjx_gps_func.gps_uart_clear_tx_buf(FUN_GPS_UART,MOD_FUN_GPS);
#endif
}


kal_bool kjx_gps_task_init(task_indx_type task_indx)
{
	g_kjx_gps_process_mutex = kal_create_mutex("kjx_gps_process");	 
	return KAL_TRUE;
}

void kjx_gps_task_main(task_entry_struct * task_entry_ptr)
{
   kal_status result;
   ilm_struct current_ilm;
   kal_uint32 my_index = 0;
   
   kal_get_my_task_index(&my_index);
   while (1) 
   {    
	   result = receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
	   stack_set_active_module_id(my_index, current_ilm.dest_mod_id);
	   g_kjx_gps_func.gps_recv_data_from_uart(((uart_ready_to_read_ind_struct*) current_ilm.local_para_ptr));
	   
	   free_ilm(&current_ilm);
   }
}

kal_bool kjx_gps_task_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom2_handler_info =
   {
      kjx_gps_task_main,  /* task entry function */
      kjx_gps_task_init,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom2_handler_info;
   return KAL_TRUE;
}

void kjx_gps_func_init(void)
{  
    g_kjx_gps_func.gps_turn_on = kjx_gps_turn_on;
    g_kjx_gps_func.gps_turn_off = kjx_gps_turn_off;
    g_kjx_gps_func.gps_disable_sleep = kjx_gps_disable_sleep;
    g_kjx_gps_func.gps_enable_sleep = kjx_gps_enable_sleep;
    g_kjx_gps_func.gps_recv_data_from_uart = kjx_gps_recv_data_from_uart;
    g_kjx_gps_func.gps_uart_get_owner_id = kjx_gps_uart_get_owner_id;
    g_kjx_gps_func.gps_uart_get_rx_avail = kjx_gps_uart_get_rx_avail;
    g_kjx_gps_func.gps_uart_read_bytes = kjx_gps_uart_read_bytes;
    g_kjx_gps_func.gps_uart_clear_rx_buf = kjx_gps_uart_clear_rx_buf;
    g_kjx_gps_func.gps_uart_clear_tx_buf = kjx_gps_uart_clear_tx_buf;
    g_kjx_gps_func.gps_uart_rx_pure = kjx_gps_uart_rx_pure;
    g_kjx_gps_func.gps_uart_tx_pure = kjx_gps_uart_tx_pure;
    g_kjx_gps_func.get_data_with_decode = kjx_gps_get_data_with_decode;
    g_kjx_gps_func.gps_open_pwr = kjx_gps_open_pwr;
    g_kjx_gps_func.gps_close_pwr = kjx_gps_close_pwr;
    g_kjx_gps_func.gps_uart_turnon_power = kjx_gps_uart_turnon_power;
    g_kjx_gps_func.gps_uart_open = kjx_gps_uart_open;
    g_kjx_gps_func.gps_uart_close = kjx_gps_uart_close;
    g_kjx_gps_func.gps_uart_set_owner = kjx_gps_uart_set_owner;
    g_kjx_gps_func.gps_uart_setDCBConfig = kjx_gps_uart_setDCBConfig;
    g_kjx_gps_func.gps_get_data_from_buffer = kjx_gps_get_data_from_buffer;
    g_kjx_gps_func.gps_data_into_number = kjx_gps_data_into_number;
    g_kjx_gps_func.gps_data_decode = kjx_gps_data_decode;
    g_kjx_gps_func.gps_do_something_with_data = kjx_gps_do_something_with_data;
    g_kjx_gps_func.gps_time_sync = kjx_gps_time_sync;
    g_kjx_gps_func.gps_do_something_with_custom = kjx_func_null;
    g_kjx_gps_func.gps_is_on = kjx_gps_is_on;
    g_kjx_gps_func.extern_do_somthing = kjx_gps_extern_do_somthing;
}

#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
void kjx_gps_open_agps_status_check(void)
{
	U16 ret;

#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
	
	if(kjx_gps_is_on())
	{
		ret = kjx_gps_uart_write("$PCAS03,,,,,,,,,,,1*1F\r\n", strlen("$PCAS03,,,,,,,,,,,1*1F\r\n"));
		
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ret:%d", ret);
	#endif
	}
}

void kjx_gps_close_agps_status_check(void)
{
	U16 ret;

#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif

	if(kjx_gps_is_on())
	{
		ret = kjx_gps_uart_write("$PCAS03,,,,,,,,,,,0*1E\r\n", strlen("$PCAS03,,,,,,,,,,,0*1E\r\n"));

	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("ret:%d", ret);
	#endif
	}
}
#endif

void kjx_agps_start_push_data_to_mode(U8 *databuf, U32 datalen)
{
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif

	if(kjx_gps_is_on && g_kjx_gps_data.data_status != 'A')
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("开始灌星 datalen:%d", datalen);
	#endif
		kjx_gps_uart_write(databuf, datalen);
	}
	else
	{
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("GPS已经关闭或者已经定位，无需灌星");
	#endif
	}
}
#endif

#endif
#endif

