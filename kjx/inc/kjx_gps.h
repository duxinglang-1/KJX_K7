/**********************************************************************************
*Filename:     kjx_gps.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#if !defined(KJX_GPS_H)
#define KJX_GPS_H

#if defined(__KJX_FUN__)
#if defined(__KJX_FUN_GPS__)
extern const char gpio_gps_power_pin;
extern const char gpio_gps_urxd_pin;
extern const char gpio_gps_utxd_pin;

#define KJX_PROSTRING "S1 W80"

//U16 FUN_GPS_UART = uart_port2;
//U16 FUN_GPS_PWR_PIN = gpio_gps_power_pin;   
#define FUN_GPS_UART  uart_port2
#define FUN_GPS_PWR_PIN    gpio_gps_power_pin

#define GPS_MODULAR_ZKW   /*使用中科微模块*/

//泰斗芯片
//U16 FUN_GPS_TD_POWER_OFF = 19;   
//U16 FUN_GPS_TD_RESET = 0;   
#define FUN_GPS_TD_POWER_OFF     19 
#define FUN_GPS_TD_RESET    0   
#define FUN_GPS_MAX_LEN 3072

typedef enum
{
    GPS_POSITION_NONE,
    GPS_POSITION_NE,
    GPS_POSITION_SE,
    GPS_POSITION_SW,
    GPS_POSITION_NW,
} GPS_POSITION_TYPE;


/*当前的GPS 数据*/
typedef struct 
{
	S8 latitude_gps[16]; //[10];		/*  纬度 51459414   DDMM.MMMM     */   
	S8 longitude_gps[16];//[11];		/*  经度 004388535  DDDMM.MMMM  */    
	 
	double latitude;                /*  纬度 NTU纬度 = 39.21028 * 100000 = 3921028（NTU）= -39.21028 * 100000 = -3921028（NTU）*/  
	double longitude;				/*  经度NTU经度 = 116.34528 * 100000 = 11634528（NTU）= -116.34528 * 100000 = -11634528（NTU） */    

	S8 longitude_dir;
	S8 latitude_dir;

	float altitude;					/*提取的海拔高度 hpgaodu = 11233;     //1123.3米  */
	float angle;                 	/*提取的行驶角度值 jiaodu = 3459;          //345.9度*/

	float speed_knot;			/*  speed_knot = 1587;    = 158.7knot /H 海里*/    
	float speed_mile;			/*  speed_mile = 1587;     = 158.7mile /H 英里 */   
	float speed_kh;             /*  speed_kh = 1587;       = 158.7KM   /H 公里 */   

	S8 data_status;				/*  GPS数据A = 数据可用，V = 数据不可用。*/
	U16 position;				/*   NE = 1 ;    SE = 2 ;    SW = 3;    NW = 4 ; */
	U16 lgn_error_value;		/* 当前的经度误差，以100 NTU为标准  比如说 80表示100NTU  100米但是只有80M*/    
	U16 direction ;             /* 方向0 - 7 */
	U16 satellite_total;		/*提取卫星数 */

	MYTIME date;				/*  日期 */
#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
	U8 ephevalid;				//GPS模块上次星历时间是否有效
	U8 ephesum;					//GPS模块上次星历卫星数目
#endif
#endif	
}kjx_gps_data;

typedef enum
{
	receive_cmd_mode,
	receive_data_mode,
	receive_end_mode
}RECEIVE_MODE_ID_ENUM;

typedef enum
{
	gps_cmd_unknow,
	gps_cmd_GPRMC,
	gps_cmd_GPGGA,
	gps_cmd_GPGSV,
	gps_cmd_BDGSV,
	gps_cmd_GPGSA,					
	gps_cmd_BDGSA,
	gps_cmd_GPTXT
}GPS_CMD_ENUM;

typedef enum
{
	GPS_ZKW_MODE,		//中科微GPS模块
	GPS_HD_MODE,		//华大GPS模块
	GPS_TD_MODE,		//泰斗GPS模块
	GPS_UBLOX_MODE,		//ublox GPS模块
	GPS_MAX_MODE
}GPS_CATEGORY_ENUM;

typedef struct
{
	S8 gps_DataStatus;
	S8 Longitude[16];
	S8 Longitude_Dir;
	S8 Latitude[16];
	S8 Latitude_Dir;
	S8 Satellites_Used[8];
	S8 Satellites_GPS_View[8];	//GPS当前可视卫星数目
	S8 Satellites_BD_View[8];	//BD当前可视卫星数目
	S8 Satellites_GPS_mode;	//GPS当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
	S8 Satellites_BD_mode;	//BD当前定位形式1 = 未定位， 2 = 二维定位， 3 = 三维定位。
	S8 Location_mode;		//模块定位模式A=自主定位，D=差分，E=估算，N=数据无效
	S8 altitude[10];		//海拔高度-9999.9~99999.9
	S8 Alti_num;
	S8 Speed[8];
	S8 S_num;
	S8 Angle[8];
	S8 A_num;
	S8 utc_time[8];
	S8 utc_date[8];
#ifdef __KJX_FUN_AGPS__
#ifdef __KJX_FUN_GPS_ZKW__
	U8 ephe_time[8];		//GPS模块上次星历时间是否有效
	U8 ephe_num[8];		//GPS模块上次星历卫星数目
#endif
#endif
}kjx_gps_info_string;

typedef struct
{
    S8 utc_time[16];
    S8 status;
    S8 latitude[16];
    S8 latitude_dir;
    S8 longitude[16];
    S8 longitude_dir;
    S8 speed[8];
    S8 utc_date[8];
    S8 angle[8];
    S8 satellites_view[8];
    S8 satellites_use[8];
}kjx_pos_gps_info_string;

/***************************************************************************************/
extern kal_bool GPS_Pass_state;
extern U8 g_kjx_gps_category;

/***************************************************************************************/
typedef void (*kjxPsVoidFunc) (void);
typedef void (*kjxPsVoid1Func) (void*);
typedef void (*kjxPsUart1Func)(UART_PORT, module_type);
typedef kal_uint16 (*kjxPsUart2Func)(UART_PORT);
typedef kal_uint16 (*kjxPsUart3Func)(UART_PORT, kal_uint8 *, kal_uint16, kal_uint8 *, module_type);
typedef void (*kjxPsUart4Func)(UART_PORT, kal_bool);
typedef void (*kjxPsUart5Func)(UART_PORT, UARTDCBStruct, module_type);
typedef void (*kjxPsGpsDate1Func)(char*,int,void*);
typedef kal_uint32 (*kjxPsGpsDate2Func)(U8 *,U8 *,U16,U16,U16);
typedef kal_int32 (*kjxPsGpsDate3Func)(U8 *,U16, U8 *);
typedef void (*kjxPsGpsDate4Func)(U8 *,U16);
typedef void (*kjxPsGpsDate5Func)(void*,kjx_gps_data);
typedef void (*kjxPsTimeSyncFunc)(kjx_gps_data);
typedef BOOL (*kjxPsGpsStatusFunc) (void);

typedef struct
{
    kjxPsVoidFunc gps_turn_on;
    kjxPsVoidFunc gps_turn_off;
    kjxPsVoidFunc gps_disable_sleep;
    kjxPsVoidFunc gps_enable_sleep;
    kjxPsVoidFunc gps_open_pwr;
    kjxPsVoidFunc gps_close_pwr;
    kjxPsVoid1Func gps_recv_data_from_uart;//void (*gps_recv_data_from_uart)(void *msg);
    kjxPsUart1Func gps_uart_clear_rx_buf;//void (*gps_uart_clear_rx_buf)(UART_PORT port, module_type ownerid);
    kjxPsUart1Func gps_uart_clear_tx_buf;//void (*gps_uart_clear_tx_buf)(UART_PORT port, module_type ownerid);
    kjxPsUart1Func gps_uart_rx_pure;//void (*gps_uart_rx_pure)(UART_PORT port, module_type ownerid);
    kjxPsUart1Func gps_uart_tx_pure;//void (*gps_uart_tx_pure)(UART_PORT port, module_type ownerid);
    kjxPsUart1Func gps_uart_open;//void (*gps_uart_open)(UART_PORT port, module_type ownerid);
    kjxPsUart1Func gps_uart_close;//void (*gps_uart_close)(UART_PORT port, module_type ownerid);
    kjxPsUart1Func gps_uart_set_owner;//void (*gps_uart_set_owner)(UART_PORT port, module_type ownerid);
    kjxPsUart2Func gps_uart_get_owner_id;//kal_uint16 (*gps_uart_get_owner_id)(UART_PORT port);
    kjxPsUart2Func gps_uart_get_rx_avail;//kal_uint16 (*gps_uart_get_rx_avail)(UART_PORT port);
    kjxPsUart3Func gps_uart_read_bytes;////kal_uint16 (*gps_uart_read_bytes)(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
    kjxPsUart4Func gps_uart_turnon_power;//void (*gps_uart_turnon_power)(UART_PORT port, kal_bool on);
    kjxPsUart5Func gps_uart_setDCBConfig;//void (*gps_uart_setDCBConfig)(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid);
    kjxPsGpsDate1Func get_data_with_decode;//void (*get_data_with_decode)(char* gps_data,int len,void* g_kjx_gps_func);
    kjxPsGpsDate2Func gps_get_data_from_buffer;//uint32 (*gps_get_data_from_buffer)(U8 *in_data_buffer,U8 *out_data_buffer,U16 out_data_len,U16 data_index,U16 in_data_len);
    kjxPsGpsDate3Func gps_data_into_number;//int32 (*gps_data_into_number)(U8 *in_data_buffer,U16 in_data_len, U8 *float_len);
    kjxPsGpsDate4Func gps_data_decode;//void (*gps_data_decode)(U8 *data,U16 data_len,kjx_gps_data g_kjx_gps_data);
    kjxPsGpsDate5Func gps_do_something_with_data;//void (*gps_do_something_with_data)(void* g_kjx_gps_func,kjx_gps_data g_kjx_gps_data);
    kjxPsTimeSyncFunc gps_time_sync;//void (*gps_time_sync)(kjx_gps_data g_kjx_gps_data);
    kjxPsTimeSyncFunc gps_do_something_with_custom;//void (*gps_time_sync)(kjx_gps_data g_kjx_gps_data);
    kjxPsGpsStatusFunc gps_is_on;
    kjxPsGpsDate4Func extern_do_somthing;
} kjx_gps_func;

/*************************************************************************************/
extern U16 kjx_gps_uart_write(U8 *buffer,U16 len);
extern void kjx_gps_software_reset(void);

#endif
#endif
#endif
