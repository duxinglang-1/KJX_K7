#ifndef _mcfidle_h_
#define _mcfidle_h_

#include "McfCommon.h"

typedef MINT (*pfnIconFunc)(MINT nIconId);


MINT McfIdle_Init(MVOID);

MVOID McfIdle_Deinit(MVOID);

MVOID McfIdle_SetStatusIcon(MSHORT nIconId,MINT nFlag);

MVOID McfIdle_UpdateStatusIcons(MVOID);

MVOID McfIdle_RegIconPenEventHdlr(pfnIconFunc func);

MBOOL McfIdle_IsStatusIconShow(MSHORT nIconId);

MBOOL McfIdle_IsStatusIconBlink(MSHORT nIconId);

#endif
