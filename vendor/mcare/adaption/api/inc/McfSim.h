#ifndef _mcfsim_h_
#define _mcfsim_h_
                                      
                                      
#include "McfCommon.h"


MINT McfSim_GetValidSim(MVOID);
MINT McfSim_GetSimOperator(MINT simId);
MINT McfSim_IsInFlightMode(MVOID);
 MVOID McfMisc_GetSimImsi(MINT simId, MCHAR * pImsi, MINT nSize);

#endif
