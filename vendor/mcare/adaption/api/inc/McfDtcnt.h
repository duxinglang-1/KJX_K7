#ifndef _mcfdtcnt_h_
#define _mcfdtcnt_h_

#include "McfCommon.h"

//每个平台需实现的函数
MBOOL McfDtcnt_OpenNetworkBearer(McfDtcntInfo *pDataAcct);
MBOOL McfDtcnt_CloseNetworkBearer(McfDtcntInfo *pDataAcct);
MINT McfDtcnt_IsNetworkReady(MVOID);
MBOOL McfDtcnt_GetApnInfo(MApnInfo *pApnInfo,MINT simId);


//内部使用函数，其他平台不需要实现
McfDtcntInfo *McfDtcnt_GetDataAcctInfo(MVOID);
MBOOL McfDtcnt_HoldNetworkBearer(McfDtcntInfo *pDataAcct);

MINT McfDtcnt_EntrySelection(MVOID *pParam);
MINT McfDtcnt_GetProxyInfo(MCHAR *pProxy,MINT nLen,MUSHORT *pPort);

#endif
