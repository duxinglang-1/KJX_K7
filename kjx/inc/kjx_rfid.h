/**********************************************************************************
*Filename:     kjx_rfid.h
*
*Description:
*
*Author:        caoweijie
*
*Datetime:    2015/09/02
*
***********************************************************************************/
#if !defined(KJX_RFID_H)
#define KJX_RFID_H

#if defined(__KJX_FUN__)
/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "med_api.h"	//media_get_ext_buffer	media_free_ext_buffer

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define BLOCK_WITH_RFID
#define BLOCK_WITH_VOICE_PUSH	
	
#define MAX_RFID_FILE 	100  /*最大播报文件*/	
#define AUDIODIR L":\\Audio\\"

#if defined(__KJX_TOURIST_MAP_SUPPORT__)
#define IMAGEDIR L":\\Audio\\IMG\\"
#endif

#define AUDIOPLAYINFO	L"PlayInfos"
#define AUDIONAMEINFO	L"NameInfos"
#define AUDIOPLAYREC	L"PlayRec"
#define AUDIOPLAYCFG	L"PlayCfg"
#define AUDIOSEQUENINFO L"PlaySeque"
#define MAX_RFID_LEN	8
#define MAX_PLAY_NAME_LEN	250
#define MAX_SHOW_NAME_LEN	250

#if defined(__KJX_RESET_USED_COUNT__)
#define RESET_RFID	66666666
#endif

#if defined(__KJX_RFID_SEQUENTIAL_TRIGGER__)
#define MAX_RFID_SEQUENTIAL_LINE	20	//最大线路条数
#endif

#define RFID_DEBUG

/*****************************************************************************
*Enum					枚举类型定义
*****************************************************************************/

/*****************************************************************************
 *Struct					数据结构定义
 *****************************************************************************/
struct kjxRfidInfo
{
	char rfid_id[MAX_RFID_LEN+1];
	char file_name[MAX_PLAY_NAME_LEN+1];
	U32 durtime;
	U8 played;
	struct kjxRfidInfo *next;
};

typedef struct
{
	int maxID;
	struct kjxRfidInfo *rfidinfo;
} kjxRfidPlayInfo;

#ifdef __KJX_TOUR_NAME_STORE_CARD__
struct kjxNameInfo
{
	char rfid_id[MAX_RFID_LEN+1];
	char name[MAX_SHOW_NAME_LEN+1];
	struct kjxNameInfo *next;
};

typedef struct
{
	int maxID;
	struct kjxNameInfo *nameinfo;
}kjxTourNameInfo;
#endif


typedef struct kjxRfidInfo KJXRFIDINFO;
typedef struct kjxNameInfo KJXNAMEINFO;

#if defined(__KJX_RESET_USED_COUNT__)
struct kjxRecordInfo
{
	char rfid_id[MAX_RFID_LEN+1];
	U32 count;
	struct kjxRecordInfo *next;
};

typedef struct
{
	int maxID;
	struct kjxRecordInfo *recinfo;
}kjxPlayRecInfo;

typedef struct kjxRecordInfo KJXRECORDINFO;
#endif

#ifdef __KJX_RFID_SEQUENTIAL_TRIGGER__
struct kjxDotInfo
{
	U32 rfid_id;
	struct kjxDotInfo *next;
};

typedef struct
{
	U32 maxdot;
	struct kjxDotInfo *DotInfo;
}kjxLineInfo;

typedef struct
{
	U32 maxLine;
	kjxLineInfo LineInfo[MAX_RFID_SEQUENTIAL_LINE];
}KjxRfidSequenInfo;

typedef struct kjxDotInfo KJXDOTINFO;

#endif
/*****************************************************************************
*Local variable				局部变量
*****************************************************************************/

/****************************************************************************
*Global Variable - Extern          全局变量
*****************************************************************************/

/****************************************************************************
*Global Variable - Extern          引用全局变量
*****************************************************************************/

/*****************************************************************************
*Global Functions	- Extern		引用外部函数
*****************************************************************************/

/*****************************************************************************
 *Local Functions			本地函数
*****************************************************************************/
static void kjx_rfid_play_cb_hdlr(S32 result, void *user_data);
static void kjx_update_play_timer(void);
static KJXRFIDINFO *kjx_rfid_get_file_id(U32 rfid_num);
#ifdef __KJX_RFID_SEQUENTIAL_TRIGGER__
static void kjx_rfid_sequential_played_infor_reset(void);
#endif


/*****************************************************************************
 *Global Functions			全局函数
*****************************************************************************/
extern BOOL kjx_rfid_is_in_play(void);
extern void kjx_rfid_check_id(void);
extern void kjx_rfid_uart_init(void);
extern void kjx_rfid_continue_play_audio(void);
extern void kjx_rfid_pause_play_audio(void);
extern void kjx_rfid_resume_play_audio(void);
extern void kjx_rfid_stop_play_audio(void);
extern void kjx_rfid_play_audio_again(void);
#if defined(__KJX_AUDIO_FILE_DECODE__)
extern void kjx_decode_string(char* buffer, U32 buflen);
extern void kjx_encode_string(char* buffer, U32 buflen);
#endif
extern KJXNAMEINFO *kjx_rfid_nameinfo_find(U32 rfid_id);
extern KJXRFIDINFO *kjx_rfid_playinfo_find(U32 rfid_id);

#endif/*__KJX_FUN__*/
#endif/*KJX_RFID_H*/
