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
 *  Npr_Ttsu_mainscreen.h
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

#ifndef _NPT_TTS_MAIN_H
#define _NPT_TTS_MAIN_H
#include "MMI_features.h"
#ifdef __NPR_TTS_UI__

typedef struct NPR_TTS_read_flag_
{
	U8 read_flag;
	U8 vollevel;
	U8 voicesel;
}NPR_TTS_read_flag;


typedef struct
{
        S32 x1;
        S32 y1;
        S32 x2;
        S32 y2;
}NPR_AITALK_AREA;


typedef struct
{
        S32 x;
        S32 y;
        S32 w;
}NPR_AITALK_TXT;

#define IV_TTS_RESPACK_NUM 6

#endif
#endif