#ifndef _mcfchset_h_
#define _mcfchset_h_

#include "McfCommon.h"


MINT McfChset_utf8_to_ucs2(MUSHORT* pDest, MINT nSize, MCHAR *pSrc);
MINT McfChset_ucs2_to_utf8(MCHAR* pDest, MINT nSize, MUSHORT *pSrc);
//MINT McfChset_gb2312_to_ucs2(MUSHORT* pDest, MINT size, MCHAR *pSrc);


#endif