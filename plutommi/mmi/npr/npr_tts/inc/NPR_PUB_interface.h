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
 *  NPR_PUB_interface.h
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *  提供外部接口给其他模块使用
 *
 * Author:
 * -------
 * Troy.Guan
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is record changes history! 
 * 
 * DATE                     EDIT       DESCRIPTION
 *2010/11/19          Troy       创建文件
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#if 1//def __NPR_TTS_LOWCOST__
#ifndef NPR_PUB_INTERFACE_H
#define NPR_PUB_INTERFACE_H

#include "gui_data_types.h"
#include "gdi_include.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "SndrecResDef.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"
#include "TimerEvents.h"
#include "PixtelDataTypes.h"

#include "FileMgrGProt.h"

#define IV_TTS_Trace

#define NPR_PROJECT_ID   3

#define NPR_PLATFORM_ID 6

#define NPR_SENSE_TYPE 1  //240320

#ifndef FMGR_MAX_FILE_LEN
#define FMGR_MAX_FILE_LEN           (MAX_SUBMENU_CHARACTERS)
#endif

#ifndef FMGR_MAX_PATH_LEN
#define FMGR_MAX_PATH_LEN (260)
#endif

typedef enum
{
    	ENUM_KEY_UP_ARROW = 0,           
 	ENUM_KEY_DOWN_ARROW = 1,
       ENUM_KEY_LEFT_ARROW = 2,
       ENUM_KEY_RIGHT_ARROW = 3,
       ENUM_KEY_VOL_UP = 4,
       ENUM_KEY_VOL_DOWN = 5,
       ENUM_KEY_ENTER = 6,
       ENUM_KEY_LSK = 7,
       ENUM_KEY_RSK = 8,
       ENUM_KEY_2 = 9,
       ENUM_KEY_4 = 10,
       ENUM_KEY_6 = 11,
       ENUM_KEY_8 = 12,
       ENUM_KEY_1 = 13,
       ENUM_KEY_3 = 14,
       ENUM_KEY_5 = 15,
       ENUM_KEY_7 = 16,
       ENUM_KEY_9 = 17,
       ENUM_KEY_0 = 18,
       ENUM_KEY_STAR = 19,
       ENUM_KEY_POUND = 20,
       ENUM_KEY_END = 21,
       ENUM_KEY_TOTAL
} NPR_PUB_KEY_CODE_ENUM;

typedef struct
{
    S16 x;
    S16 y;
} npr_point_struct;

typedef struct
{
        S32 list_max;
        S32 list_count;
        S32 list_index;
        S32 list_offset;

	 S32 rect_x1;
        S32 rect_y1;
        S32 rect_x2;
        S32 rect_y2;

        S32 slide_h;
        S32 slide_y;

}NPR_RADAR_SCR_LIST;

typedef void (*npr_pen_hdlr) (npr_point_struct pos);

typedef enum
{
        FILE_HANDLE_OPEN = 0,           
        FILE_HANDLE_CREATEDIR ,
        FILE_HANDLE_DELETE ,
        FILE_HANDLE_DELETE_DIR,

        FILE_HANDLE_TOTAL
} NPR_FILE_HANDLE_ENUM;

typedef void (*aitalk_vfp) (void);
typedef void (*aitalk_pfp)(mmi_pen_point_struct pos);

typedef struct
{
   S32 len;
	S8 url[256]; 
}RES_DOWN_URL_STRUCT;



typedef struct
{
	S8 path[128]; 
}RES_DOWN_SAVE_PATH_STRUCT;

typedef struct
{
	 U32 netTotalSize;
        U32 netRecvLen;
        U32 startPoint;
        U32 endPoint;
        U8 bPointTimes;
		
}NPR_RADAR_LOAD_INFO;

#define NPR_SM_CHINESE_CHARACTER_W \
    gui_get_character_width(((UI_character_type *)GetString(STR_GLOBAL_OK))[0]) //调用之前必须有过gui_set_font的调用否则返回值不对
#define NPR_PUB_LINE_INTERVAL (gui_get_character_height() + 2) //调用之前必须有过gui_set_font的调用否则返回值不对

extern int  NPR_File_FileOperate(NPR_FILE_HANDLE_ENUM type, char * filePath, UINT flag, BOOL is_hidden);
extern BOOL NPR_File_DiskFreeSpace(U64 *pdisk_free_space);
extern int NPR_File_GetDrv(void);
extern int NPR_Pub_GetProjectID(void);
extern int NPR_Pub_GetPlatformID(void);
extern U8 NPR_Pub_GetSenseType(void);

extern U16 NPR_Pub_AscToUcs2(S8 * pOutBuffer, S8 * pInBuffer);
extern U16 NPR_Pub_Ucs2ToAsc(S8 * pOutBuffer, S8 * pInBuffer);
extern U16 NPR_Pub_Ucs2NToAsc(S8 *pOutBuffer, S8 *pInBuffer, U32 len);
extern char * NPR_Pub_Ucs2ncpy(char *strDestination, const char *strSource, U32 size);
extern char * NPR_Pub_Ucs2cat(char *strDestination, const char *strSource);
extern char * NPR_Pub_Ucs2cpy(char *strDestination, const char *strSource);
extern S32 NPR_Pub_ucs2strlen(const char *arrOut);
extern S32 NPR_Pub_ucs2toi(const char *strSrc, S32 *out_num, S32 *read_length);
extern S32 NPR_Pub_ucs2find(const char *strSrc, const char *break_chars, S32 *read_length, S16 direction);
extern void NPR_Pub_PrintText(S32 x, S32 y, UI_font_type f, color c, UI_string_type text, BOOL is_underline);
extern void NPR_Pub_Utf8ToUcs2String(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src, kal_int32 src_size);
extern kal_int32 NPR_Pub_Ucs2ToUtf8String(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern U16 NPR_Pub_AnsiiNToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 * NPR_Pub_UCS2Wcsstr(U16 *string, const U16 *str_char_set);
extern U16 * NPR_Pub_UCS2Wcschr(const U16 *string,  U16 ch);
extern int NPR_Pub_Strcmp(const char * str1, const char *str2);
extern char* NPR_Pub_Strcpy(char* str1, const char* str2);
extern U32 NPR_Pub_Strlen(char* str);
extern U16 NPR_Pub_GetTimerID(U8 index);
extern nvram_lid_enum NPR_Pub_GetNvramLID(U8 index);
extern S32 NPR_Pub_ReadRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError);
extern S32 NPR_Pub_WriteRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError);
extern void* NPR_Pub_AllocBigMem(unsigned int size);
extern void NPR_Pub_FreeBigMem(void* p);
extern void* NPR_Pub_AllocSmallMem(unsigned int size);
extern void NPR_Pub_FreeSmallMen(void* p);
extern int NPR_Pub_Rand(int size);
//extern void NPR_Pub_GetDateTime(MYTIME *dt);
extern int NPR_Pub_Pow10(int index);
extern void NPR_Pub_PlayTone(void);

extern void NPR_Pub_trace_to_file(U8 type, const char *format, ... );
extern void NPR_Pub_WriteInfoToFile(int len, char* p, char * filePath);

extern void NPR_Pub_GobackIdleScreen(void);

extern void NPR_Pub_TurnOnBacklight(void);
extern void NPR_Pub_TurnOffBacklight(void);
extern UI_font_type NPR_Pub_Getfont(void);
#endif
#endif

