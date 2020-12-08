#ifndef _mcfpen_h_
#define _mcfpen_h_

#include "McfCommon.h"

typedef MVOID (*pfnPenHandler)(MINT evtType ,MUINT position);//evtType --EMTpEvtTyep

MVOID McfTp_RegPenHandler(pfnPenHandler func);//
MVOID McfTp_UnregPenHandler(MVOID);


#endif
