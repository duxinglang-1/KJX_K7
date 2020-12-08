#ifndef KJX_DOG_GPS_DATA_H
#define KJX_DOG_GPS_DATA_H

#if defined(__KJX_DOG__)

/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/

#define  __KJX_DOG_GPS_DATA_EXTERN__   /*GPS数据辅助计算*/

typedef enum
{
    DOG_POSITION_NONE,
    DOG_POSITION_NE,
    DOG_POSITION_SE,
    DOG_POSITION_SW,
    DOG_POSITION_NW,
} DOG_POSITION_TYPE;

/*当前的GPS 数据*/
typedef struct 
{
     int32   longitude;              /*  经度NTU经度 = 116.34528 * 100000 = 11634528（NTU）= -116.34528 * 100000 = -11634528（NTU） */    
     int32   latitude;                /*  纬度 NTU纬度 = 39.21028 * 100000 = 3921028（NTU）= -39.21028 * 100000 = -3921028（NTU）*/  
	 
     uint32 longitude_gps;      /*  经度 004388535  DDDMM.MMMM  */    
     uint32 latitude_gps;        /*  纬度 51459414   DDMM.MMMM     */    
	 
     uint16 altitude;                /*提取的海拔高度 hpgaodu = 11233;     //1123.3米  */
     uint16 angle;                   /*提取的行驶角度值 jiaodu = 3459;          //345.9度*/
	 
     uint16 speed_knot;          /*  speed_knot = 1587;    = 158.7knot /H 海里*/    
     uint16 speed_mile;          /*  speed_mile = 1587;     = 158.7mile /H 英里 */   
     uint16 speed_kh;             /*  speed_kh = 1587;       = 158.7KM   /H 公里 */   
	 
     S8      data_status;          /*  GPS数据A = 数据可用，V = 数据不可用。*/
     U16    position;                /*   NE = 1 ;    SE = 2 ;    SW = 3;    NW = 4 ; */
     U16    lgn_error_value;   /* 当前的经度误差，以100 NTU为标准  比如说 80表示100NTU  100米但是只有80M*/    
     U16    direction ;             /* 方向0 - 7 */
     U16    satellite_total;      /*提取卫星数 */
	 
     MYTIME  date;                 /*  日期 */
     MYTIME  time;                 /*  时间 */
}kjx_dog_gps_data;

extern void kjx_dog_gps_data_decode(U8 *data,U16 data_len);
extern void kjx_dog_get_data_start(void);
extern void kjx_trace_dog(const char *fmt, ...);
#endif
#endif/*KJX_DOG_GPS_DATA_H*/
