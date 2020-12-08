/**********************************************************************************
*Filename:     kjx_socket.h
*
*Description:
*
*Author:        caoweijie
*
*Datetime:    2013/12/17
*
***********************************************************************************/
#if !defined(KJX_NET_H)
#define KJX_NET_H

#if defined(__KJX_FUN__)

#if !defined(KJX_FORMAT_ACSSII)
#define KJX_SOCKET_HEADER_BYTE   2
#define KJX_SOCKET_PACKLEN_BYTE   2
#define KJX_SOCKET_IMEI_BYTE   7
#define KJX_SOCKET_TATOL_BYTE   1
#define KJX_SOCKET_SIGN_BYTE   1
#define KJX_SOCKET_COMMAND_BYTE   2
#define KJX_SOCKET_CRC_BYTE   2
#define KJX_SOCKET_END_BYTE   2
#endif

#define NET_DEBUG

//#define KJX_DOMAIN	"bb.kejiaxun.com"  //120.132.37.66
//#define KJX_PORT	6600

#define CMNET_ACCOUNT_NAME	L"GPRSNET"
#define CMWAP_ACCOUNT_NAME	L"GPRSWAP"

typedef struct
{
   char apnMode[32];	/* cmnet */
   char userName[32];	/* NULL */
   char passWord[32];	/* NULL */
} kjxApnInfo;

typedef struct
{
   kjxApnInfo apn;	/* APN */
   char domain[256];	/* ÓòÃû */
   int port;             /* ¶Ë¿Ú */
} kjxNetInfo;

#endif/*__KJX_FUN__*/
#endif/*KJX_NET_H*/

