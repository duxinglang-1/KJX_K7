#ifndef _mcfsms_h_
#define _mcfsms_h_

#include "McfCommon.h"

MINT McfSms_SendSms(MVOID *pUser,MINT simId,MINT nOption,const MCHAR *pNumber,const MCHAR*pData,MINT dataSize,MINT  encodeType, pfnMcfSmsSendCb sendSmsCb);
MVOID McfSms_WriteMsg(MCHAR *pNumber,MINT nNumberCnt,MWCHAR *pContent,MINT nSize);

#endif
