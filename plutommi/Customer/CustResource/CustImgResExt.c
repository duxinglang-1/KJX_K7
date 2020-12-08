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

//const S8 CustImgPath[]=CUST_IMG_PATH;
const unsigned short  mtk_CurrMaxImageNumEXT=4;
#include "CustImgDataHWExt.h"
const CUSTOM_IMAGE	mtk_nCustImageNamesEXT[]={
(U8*)&________CUSTOMER__IMAGES__PLUTO__MAINLCD__ACTIVE__POWERONOFF__LOGO_BMP_,
(U8*)&________CUSTOMER__IMAGES__PLUTO__MAINLCD__ACTIVE__POWERONOFF__POON_GIF_,
(U8*)&________CUSTOMER__IMAGES__PLUTO__MAINLCD__ACTIVE__POWERONOFF__POOFF_GIF_,
(U8*)&________CUSTOMER__IMAGES__PLUTO__MAINLCD__IDLESCREEN__WALLPAPER__WALL01_BMP_,
};



const CUSTPACK_IMAGE_HEADER mtk_image_header={4, (CUSTOM_IMAGE *)mtk_nCustImageNamesEXT};