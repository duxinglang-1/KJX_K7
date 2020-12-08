/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of Shenzhen Newpolar Technology co.,Ltd. (C) 2010
*
*  --------------------
*******************************************************************************
 * Filename:
 * ---------
 *  NPR_TTSu_gprot.h
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *提供外部接口
 * Author:
 * -------
 * huyucheng
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is record changes history! 
 * 
 * DATE                     EDIT       DESCRIPTION
 *2012/4/11         hyc       创建文件
 *==============================================================================
 *******************************************************************************/

#ifndef _NPT_TTS_GPROT_H
#define _NPT_TTS_GPROT_H
#include "MMI_features.h"
#ifdef __NPR_TTS_UI__
#include "Npr_Ttsu_mainscreen.h"
typedef enum 
{
	NPR_TTS_INCOMING_CALL,
	NPR_TTS_RECV_SMS,
	NPR_TTS_SMS_AUTO,
	NPR_TTS_MENU,
	NPR_TTS_TIME_AUTO,
	NPR_TTS_TIME_HAND,
	NPR_TTS_KEYPAD,
	NPR_TTS_FLAG_MAX
}NPR_TTS_type;


extern NPR_TTS_read_flag Npr_Tts_flag_cntx;
extern MMI_BOOL NPR_TTS_get_menu_read_enble(void);
extern int NPR_TTS_menu_read(char * pText);
extern void NPR_TTS_PlayAnyTime(void);
extern void NPR_TTS_PlayAutoTime(void);
extern void Npr_Tts_set_vol_lev(char lev);
#endif
#endif
