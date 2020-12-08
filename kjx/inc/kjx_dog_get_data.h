#ifndef KJX_DOG_GET_DATA_H
#define  KJX_DOG_GET_DATA_H

#ifndef ABS
#define ABS(x) ((x) > 0 ? (x) : -(x))
#endif

#ifndef PI
//#define PI 3.1415926535897932384626433832795f
#define   PI     3.1415926535898
#endif

/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/

#define  MAX_DATA   50  /*数据扫描BUFER  最大存储的点数*/

#define MAX_DISTANCE   8000  /*数据扫描的最大距离；单位m*/

#define MAX_READ_DATA   1024*30  /*数据扫描BUFER  大小*/
 
#define  USER_ADDTP   0x0D      /*自建坐标点*/ 


#define  DATABASE_SIGN_ONE_POINT    'X'     /*表示数据有效标记*/
#define  DATABASE_SIGN_TWO_POINT   'W'   /*表示数据有效标记*/ 


#define Is_Invalid   0
#define Is_Ready     1
#define Is_Into        2

#define  radar_shield    0xFF        /*雷达干扰屏蔽区*/

#define  POSITION_ANY   4760   /*  表示任意方向*/

#define  DOG_LEAVE  2   /*离开*/    
#define  DOG_NEAR   0   /*靠近*/

#define  UserData   1      
#define  Database   2    

#define MIN_SPEED  10/*最小报警速度；单位Km*/


typedef struct 
{
     uint8    position ;  	      /* 方向(NE:1 ;  SE :2 ; SW:3 ; NW:4 )*/
	 
     int32    longitude_start ; /*起报点经度*/        
     int32    latitude_start ;    /*起报点纬度*/        
	 
     int32    longitude ;          /*结束点经度*/
     int32    latitude ;             /*结束点纬度*/
	 
     uint8    speed ;               /*测试点速度*/
     uint8    sound_status ;   /*测试点语音提示标记*/
	 
     uint16  position_start ;  /*起报点方向*/
	 
     uint8    data_type ;        /*测试点类型（ Database 是固定数据    UserData是用户自己加的数据 ）*/
     uint32  data_num;         /*记录当前点放在FLASH的那个位置（条数）*/
	 
     uint16  line_position ;   /*开始点和结束点连线的方向*/
	 
     uint32  end_distance ;   /*车离结束点的距离*/
     uint32  start_distance ; /*上次判断离开的车与测试点的距离*/
	 
     uint8    current_status ;/*0表示离开标志 1表示靠近标志*/
     uint16  angle ;               /*车到报警点连线的方向*/
}kjx_dog_use_data;



typedef struct 
{
     BOOL   current_data_is_alert;      /*测试点是否开始报警*/
     BOOL   current_alert_is_updata ; /*测试点更新了报警数据*/
	 
     uint16  end_distance ;                  /*车离报警点的距离*/
     uint8    speed ;                              /*测试点速度*/ 
     uint8    sound_status;                  /*测试点语音提示标记*/
     uint8    data_type ;                       /*测试点类型（ Database 是固定数据    UserData是用户自己加的数据 ）*/
     uint32  data_num;                        /*记录当前点放在FLASH的那个位置（条数）*/
}kjx_dog_alert;


typedef struct 
{
     U16  nYear ;         /*数据库日期版本*/         
     U16  nMonth ;      /*数据库日期版本*/      
     U16  nDay ;          /*数据库日期版本*/      
       
     U16  speed_radar_quiet;   /*雷达自动静音设定0 - 60 公里*/
     U16  speed_limit_alert;     /*超速警告速度设定0 - 150 公里*/
     U16  speed_error_value;   /*速度误差微调设定-10 - +10  (0-20表示)公里*/
     U16  sound_value;             /*音量设置0 - 8 */
     U16  driving_mode;           /* 驾驶模式切换设定0-3(0-安全驾驶限速模式1-照相系统限速模式2-安全驾驶模式3-照相系统模式)*/
     U16  radar_level;               /*雷达侦测等级设定0-2 (0 关闭\1 中\2高)*/
     U16  sound_auto_set;       /*音量自动设定1 开启0 关闭*/
     U16  led_level;                  /*设定 LED  亮度 等级*/
}kjx_dog_database_struct;        


extern uint32 kjx_dog_get_angle_with_two_point(int32 lng1,int32 lat1,int32 lng2,int32 lat2);
extern void kjx_dog_get_distance_with_car_to_alert_point(kjx_dog_use_data *dog_use_data);
#endif
