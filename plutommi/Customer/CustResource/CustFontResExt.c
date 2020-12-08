/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/************************************************************** 
 FILENAME	:  
 PURPOSE		: Resource file. 
 REMARKS		: nil 
 AUTHOR		: Customization Tool 
 DATE		: . 
 **************************************************************/
#include "CustDataRes.h"
#include "CustResDef.h"

extern CUSTOM_FONT_MAP mtk_CustFontMapEXT[];
extern CUSTOM_FONT_SEARCH_MAP mtk_CustFontSearchMapEXT[];
const unsigned short  mtk_CurrMaxFontNumEXT=0;
#include "CustFontDataHW.h"
const CUSTOM_FONT	mtk_nCustFontNamesEXT[1] = {NULL};
const CUSTPACK_FONT_HEADER mtk_font_header={0, 0, (CUSTOM_FONT *)mtk_nCustFontNamesEXT, mtk_CustFontMapEXT, mtk_CustFontSearchMapEXT};