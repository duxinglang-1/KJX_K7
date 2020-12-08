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
 *  NPR_TTSgprot.h
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
 *2010/08/10         hyc       创建文件
 *==============================================================================
 *******************************************************************************/

#ifndef _NPT_TTS_GPROT_H
#define _NPT_TTS_GPROT_H
#ifdef __NPR_TTS__
#define SRV_SMS_MAX_ADDR_LEN (60)
typedef	int ivBool;

typedef enum 
{
    NPR_NV_FLAG_INCOMING_CALL,
    NPR_NV_FLAG_RECV_SMS,
    NPR_NV_FLAG_SMS_AUTO,
    NPR_NV_FLAG_TIME_AUTO,
    NPR_NV_FLAG_KEYPAD,
    NPR_NV_FLAG_VOLUME
}NPR_TTS_NV_FLAG;

typedef enum 
{
    NPR_FLAG_IS_NUM,
    //NPR_FLAG_PLAY_TEXT,
    NPR_FLAG_KEYPAD,
    NPR_FLAG_HAS_A_NEW_MSG,
    NPR_FLAG_WINKING,
    NPR_FLAG_SHOWED_POP,
    NPR_FLAG_CANT_TOUCH,
    //NPR_FLAG_INDICATED_ALARM,
    NPR_FLAG_IMSI_DIDNT_INIT, //这此前的枚举增删要重新将NPR_AitalkWrap_Iservice.obj打包
    NPR_FLAG_TOTAL
}NPR_TTS_FLAG;

typedef enum{
    NRP_RES_FILE_NONE, //无任何资源文件
    NRP_RES_FILE_ONLY_TTS = 0X01,
    NRP_RES_FILE_ONLY_IVESR = 0X02,
    NRP_RES_FILE_BOTH = (NRP_RES_FILE_ONLY_TTS | NRP_RES_FILE_ONLY_IVESR)    
}NRP_RES_FILE_STATUS;

typedef enum{
    NPR_AITALK_FUN_MAIN_TYPE_NIGHT_CHATTING, //夜话
    NPR_AITALK_FUN_MAIN_TYPE_GUFFAW, //爆笑
    NPR_AITALK_FUN_MAIN_TYPE_COLD_JOKE, //冷笑话
    NPR_AITALK_FUN_MAIN_TYPE_THROUGH, //穿越
    NPR_AITALK_FUN_MAIN_TYPE_TINY_NOVEL, //微小说
    NPR_AITALK_FUN_MAIN_TYPE_SCANDAL_ENCYCLOPEDIA, //糗百 //5
    NPR_AITALK_FUN_MAIN_TYPE_LOVE_WORDS, //情话
    NPR_AITALK_FUN_MAIN_TYPE_MYSTERY, //灵异
    NPR_AITALK_FUN_MAIN_TYPE_POEM, //诗词
    NPR_AITALK_FUN_MAIN_TYPE_MAX //全部
}NPR_AITALK_FUN_MAIN_TYPE;

typedef enum{
    NPR_AITALK_PATH_NIGHT_CHATTING, //夜话
    NPR_AITALK_PATH_GUFFAW, //爆笑
    NPR_AITALK_PATH_COLD_JOKE, //冷笑话
    NPR_AITALK_PATH_THROUGH, //穿越
    NPR_AITALK_PATH_TINY_NOVEL, //微小说
    NPR_AITALK_PATH_SCANDAL_ENCYCLOPEDIA, //糗百 //5
    NPR_AITALK_PATH_LOVE_WORDS, //情话
    NPR_AITALK_PATH_MYSTERY, //灵异
    NPR_AITALK_PATH_POEM, //诗词
    NPR_AITALK_PATH_FEE_INFO,
    NPR_AITALK_PATH_FEE_ORDER,
    NPR_AITALK_PATH_TMP_FEE_ORDER,
    NPR_AITALK_PATH_TYPE_MAX //全部
}NPR_AITALK_PATH_TYPE;

extern BOOL NPR_TTS_check_if_ready(void);
extern void IFLYTEK_TTSPlayer_Stop(void);
extern BOOL NPR_TTSPlayer_IsRun(void);
extern ivBool IFLYTEK_TTSPlayer_IsPlaying(void);

extern BOOL NPR_AiTalk_GetFlag(NPR_TTS_FLAG type);
extern void NPR_AiTalk_SetFlag(NPR_TTS_FLAG type, BOOL value);

extern NRP_RES_FILE_STATUS NPR_Check_Res_File( void);
extern void IV_TTS_Media_Stop(void);

#endif
#endif
