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

//const S8 CustAdoPath[]=CUST_ADO_PATH;
const unsigned short  mtk_CurrMaxAudioNumEXT=16;
#include "CustAdoDataHWExt.h"
const CUSTOM_AUDIO	mtk_nCustAudioNamesEXT[]={
(U8*)&________CUSTOMER__AUDIO__EMPTYAUDIO_MP3_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__TONE__POWERON_MP3_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__TONE__POWEROFF_MP3_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__TONE__CS03_MID_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__TONE__CS04_MID_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__TONE__CS05_MID_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__RING__S1IMY01_IMY_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__RING__S1IMY02_IMY_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__RING__S1IMY03_IMY_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__RING__S1IMY04_IMY_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__USERPROFILES__RING__S1IMY05_IMY_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__ALARM__001_MP3_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__ALARM__002_MP3_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__ALARM__003_MP3_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__ALARM__004_MP3_,
(U8*)&________CUSTOMER__AUDIO__PLUTO__ALARM__005_MP3_,
};



const CUSTPACK_AUDIO_HEADER mtk_audio_header={16, (CUSTOM_AUDIO *)mtk_nCustAudioNamesEXT};