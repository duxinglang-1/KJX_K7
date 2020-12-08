#ifndef _mcfkey_h_
#define _mcfkey_h_

#include "McfCommon.h"


//keyCode --EMkeyCode,keyType--EMKeyEvt
typedef MVOID (*pfnKeyHandler)(MINT nKeyCode,MINT nKeyType);

MVOID McfKey_RegKeyHandler(pfnKeyHandler func);
MVOID McfKey_UnregKeyHandler(MVOID);
#endif
