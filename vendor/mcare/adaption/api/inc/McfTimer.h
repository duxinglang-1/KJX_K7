#ifndef _mcftimer_h_
#define _mcftimer_h_ 

#include "McfCommon.h"

MTmHandle McfTm_StartTimer(MVOID *pUser,MUINT nInterval,pfnTimerFuncPtr expireFunc);
MVOID McfTm_StopTimer(MTmHandle timerHd);
MVOID McfTm_StopAllTimer(MVOID);


MVOID McfInitTimer(MVOID);
MVOID McfDeInitTimer(MVOID);

#endif //_MCR_TIMER_H_
