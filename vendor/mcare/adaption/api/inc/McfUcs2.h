#ifndef _mcfucs2_h_
#define _mcfucs2_h_

#include "McfCommon.h"

MUSHORT McfUcs2_AscToUcs2(MUSHORT *pOutBuf, const MCHAR *pInBuf);

MUSHORT McfUcs2_AscNToUcs2(MUSHORT *pOutBuf, const MCHAR *pInBuf, MUINT nCount);

MUSHORT McfUcs2_Ucs2ToAsc(MCHAR *pOutBuf, const MUSHORT *pInBuf);

MUSHORT McfUcs2_Ucs2NToAsc(MCHAR *pOutBuf, const MUSHORT *pInBuf, MUINT nCount);

#endif
