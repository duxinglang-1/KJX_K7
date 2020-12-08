#ifndef _mcfgzip_h_
#define _mcfgzip_h_

#include "McfCommon.h"

typedef MVOID* (*fpzip_alloc_func)(MUINT);
typedef MVOID  (*fpzip_free_func)(MVOID*);

typedef MVOID* (*_alloc_func)(MUINT);
typedef MVOID (*_free_func)(MVOID*);

typedef MVOID Unzip_Decompressor;

typedef MVOID* (*funzip_alloc_func)(MUINT);
typedef MVOID (*funzip_free_func)(MVOID*);


MVOID* McfUnzip_Create(funzip_alloc_func allocFunc, funzip_free_func freeFunc , MINT nBufferSize);
MINT McfUnzip_Destroy(MVOID* pUnZipInfo);
MINT McfUnzip_SetData(MVOID* pUnZipInfo, MCHAR* pData, MINT nDataLen);
MINT McfUnzip_Uncompress(MVOID* pUnZipInfo, MCHAR** ppData, MINT* pDataLen);



#endif
