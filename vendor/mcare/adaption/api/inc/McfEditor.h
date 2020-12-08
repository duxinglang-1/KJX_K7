#ifndef _mcfeditor_h_
#define _mcfeditor_h_

#include "McfCommon.h"

MINT McfEditor_EnterEditor(MVOID *pUser,MINT nInputType, MUSHORT nMaxNum,MWCHAR* pDefstr,pfnMcfInputCb handler);

MINT McfEditor_EnterEditorEx(MVOID *pUser,MINT nInputType, MINT nPorperty, MUSHORT nMaxNum,MWCHAR* pDefstr, pfnMcfInputCb handler);

MINT McfEditorInScr_EnterEditor(MVOID *pUser,MINT nInputType, MUSHORT nMaxNum,MWCHAR* pDefstr,pfnMcfInputCb handler);

#endif //

