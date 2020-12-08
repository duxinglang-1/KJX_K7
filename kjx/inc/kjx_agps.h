/**********************************************************************************
*Filename:     kjx_agps.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/04/04
*
***********************************************************************************/
#ifndef __KJX_AGPS_H__
#define __KJX_AGPS_H__

#if defined(__KJX_FUN_AGPS__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define KJX_AGPS_SOCKET_BUFF_SIZE 1024*2
	
#define KJX_UBLOX_AGPS_DOMAIN_NAME "agps.u-blox.com"
#define KJX_UBLOX_AGPS_PORT  46434
	
#define KJX_AGPS_DATA_MAX_LEN	(10*1024)
#define KJX_AGPS_DATA_FILE_NAME	L"AGPS.dat"

#ifdef __KJX_FUN_GPS_HD__
#define HD_AGPS_ONE_BAG_DATA_MAX_LEN	1024
#endif

/*****************************************************************************
*Enum					枚举类型定义
*****************************************************************************/
#ifdef __KJX_FUN_GPS_HD__
typedef enum
{
	STEP_AID_READY,
	STEP_AID_TIME,
	STEP_AID_POS,
	STEP_AID_PEPH_GPS,
	STEP_AID_PEPH_BDS,
	STEP_AID_MAX
}HD_AGPS_STEP_ENUM;
#endif

/*****************************************************************************
 *Struct					数据结构定义
 *****************************************************************************/
typedef struct
{
	S8 cmd[8];
	S8 user[32];
	S8 pwd[12];
	S8 lat[12];
	S8 lon[12];
	U32 pacc;
}kjx_ublox_agps_request_pack_struct;


typedef struct
{
	kal_int8 socket_id;
	kal_int8 access_id;
	S8 pRecvBuff[KJX_AGPS_SOCKET_BUFF_SIZE];
	S8 pSendBuff[KJX_AGPS_SOCKET_BUFF_SIZE];
	kal_int32 totalSize;
	kal_int32 recvBuffsize;
} kjx_agps_socket_context;

/*****************************************************************************
*Local variable				局部变量
*****************************************************************************/

/****************************************************************************
*Global Variable     			全局变量
*****************************************************************************/
extern kjx_agps_socket_context g_kjx_agps_socket_context;

/****************************************************************************
*Global Variable - Extern          	引用全局变量
*****************************************************************************/

/*****************************************************************************
*Global Functions				全局函数
*****************************************************************************/
extern void kjx_ublox_agps_request(void);
extern void kjx_agps_socket_init(void);
extern void kjx_agps_socket_connect_ublox(void);
extern void kjx_agps_socket_read_handle(void);

#endif/*__KJX_FUN_AGPS__*/
#endif/*__KJX_AGPS_H__*/
