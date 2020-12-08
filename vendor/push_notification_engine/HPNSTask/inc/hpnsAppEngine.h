#ifndef _HPNS_APP_ENGINE_H_
#define _HPNS_APP_ENGINE_H_

#include "hpnsPlatform.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"


enum {
	HPNS_MSG_REG_REQ,
	HPNS_MSG_REG_RSP,
	HPNS_MSG_UNREG_REQ,
	HPNS_MSG_UNREG_RSP,	
	HPNS_MSG_REGID_CHANGED_NOTIFICATION,
	HPNS_MSG_NOTIFICATION,
	HPNS_MSG_NOTIFICATION_RSP,
	HPNS_MSG_PUSH_NOTIFICATION_SWITCH,
	HPNS_MSG_CHANGE_CONNECT_MODE,
	HPNS_MSG_NETWORK_STATE_CHANGED,
	HPNS_MSG_UPLOAD_STATIC_DATA,
	HPNS_MSG_DATA_READ_IND, // engine internal, but platform shall provide it
	HPNS_MSG_DATA_WRITE_IND,// engine internal, but platform shall provide it
	HPNS_MSG_NW_ERROR_IND,  // engine internal, but platform shall provide it
	HPNS_MSG_MAX
}; 

typedef struct {
	kal_uint32 appId;
	kal_uint8  senderId[HPNS_SENDER_LEN];
	kal_uint8  regId[HPNS_REGID_LEN*2];
	kal_uint8  appCode;
	kal_uint8  payload[1];
}SHpnsRegInfo;

typedef struct{
    kal_uint32 appId;
    kal_uint32 numOfCTViaNCWithKey;
    kal_uint32 numOfCTViaNCNoKey;
    kal_uint32 numOfCTViaPopWithKey; 
    kal_uint32 numOfCTViaPopNoKey; 
    kal_uint32 numOfCTViaBannerWithKey; 
    kal_uint32 numOfCTViaBannerNoKey; 
    kal_uint32 numOfCTViaMenuWithBadge; 
	kal_uint32 numOfCTViaBadgeNoKey;
    kal_uint32 numOfCTViaOthers;
}SHpnsAppStatistics;

extern  char *hpnsAppEngineMsg[];
extern  unsigned short  hpnsPollingTimeList[];

#define HPNS_PUSH_NOTIFICATION_ON         1
#define HPNS_PUSH_NOTIFICATION_OFF        2


#define HPNS_NETWORK_STATE_ON             1
#define HPNS_NETWORK_STATE_OFF            2

#define HPNS_NCM_MANUAL                   1
#define HPNS_NCM_POLL                     2
#define HPNS_NCM_AUTO                     3

#define HPNS_APN_DEFAULT                  0
#define HPNS_APN_WIFI                     1
#define HPNS_APN_GPRS                     2
#define HPNS_APN_WCDMA                    3
#define HPNS_APN_INTERNAL                 4


#define HPNS_SERVICE_NOT_AVAILABLE       100
#define HPNS_TOO_MANY_REGISTRATIONS      101
#define HPNS_INVALID_DATA_CONNECTION     102
#define HPNS_LAST_MSG_ON_PROCESSING      103 
#define HPNS_SYSTEM_ERROR                104
#define HPNS_PUSH_NOTIFICATION_SUSPEND   105

#define HPNS_INVALID_APPID               151
#define HPNS_INVALID_SENDER              152


int   hpnsSendMsgToEngine(int mid, kal_uint8 *pMsg, int msgLen); 
int   hpnsSendMsgToUI(int mid, kal_uint8 *pMsg, int msgLen); 
int   hpnsInitTask(void);
int   hpnsGetAppStatisticsInfo(SHpnsAppStatistics  *hpnsAppStatistic);
int   hpnsApiQueryAppViaAppId(kal_uint32 appId, char regId[], kal_uint32 regIdLen);
int   hpnsApiGetConfigInfo(kal_uint16 *majorVersion, kal_uint16 *minorVersion, kal_uint32 *connStatus, char hidstr[]);
int   hpnsApiGetPushServiceStatus(void);
int   hpnsApiChangeNetworkStatusOn(kal_uint32 apnType);
int   hpnsApiChangeNetworkStatusOff(void);
int   hpnsStaticDataSendBack(kal_uint8 flag);
kal_uint8 hpnsGetAppId(void);
kal_uint32 hpnsGetAccountId(void);

kal_bool nmsCreateLocalMemoryPool(void);

#endif

