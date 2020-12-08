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
 * NPR_PUB_interface.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *  a)  数据编码部分
 *  b)  NV操作部分
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
#if defined(__NPR_SIMPLE_TTS__)|| defined(__NPR_TUAN__)|| defined(__NPR_WEIBO__)||defined(__NPR_SIRI_TTS__) || defined ( __NPR_TTS__)

#include "MMI_include.h"

#include "ConnectivityResDef.h"
#include "SettingProfile.h"
//#include "SimDetectionResDef.h"
#include "IdleAppResDef.h"
#include "FileManagerGProt.h"
#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "SoundRecorderResDef.h"
#include "Med_utility.h"
#include "FileManagerResDef.h"

#include "gpioInc.h"    /* TurnOnBacklight */

#include "NPR_PUB_interface.h"
//#include "Mmi_rp_app_npr_def.h"

#include "GlobalResDef.h"
#include "SettingProfileEnum.h"

#include "browser_api.h"

#include "Resource_audio.h"
#include "nvram_common_defs.h"
#include "ProfilesSrvGprot.h"


#include "gpiosrvgprot.h"
extern U16 gCurrLangIndex;


scrolling_text g_npr_pub_scrolling_text;
static BOOL g_npr_pub_scrolling_text_done = FALSE;
gdi_color g_npr_scrolling_bgcolor;


extern void NPR_Pri_GetDay(U8* nSuccessDay, U8* nBaseDay, U8* nIntervalDay, U8* hour, U8* min, char* num);

//#include "../../../../../../ggt/inc/GGT_utility.h" //xuhongfu
//extern void GT_TRACE(const char *fmt, ...);  //xuhongfu

/*************************************************
*  FUNCTION
*  NPR_Pub_GetProjectID
*  DESCRIPTION
*  获取项目ID
*  CALLS
*  
*  PARAMETERS
*  void
*  RETURNS
*  int
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-02
************************************************/
#if 0
int NPR_Pub_GetProjectID(void)
{
        return NPR_PROJECT_ID;  
}

#endif
/*************************************************
*  FUNCTION
*  NPR_Pub_GetPlatformID
*  DESCRIPTION
*  获取平台ID
*  CALLS
*  
*  PARAMETERS
*  void
*  RETURNS
*  int
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-02
************************************************/
#if 0
int NPR_Pub_GetPlatformID(void)
{
        return NPR_PLATFORM_ID;
}
#endif

/*************************************************
*  FUNCTION
*  NPR_Pub_GetSenseType
*  DESCRIPTION
*  获取分辨率类型
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-28
************************************************/
U8 NPR_Pub_GetSenseType(void)
{
        return NPR_SENSE_TYPE;
}


/*************************************************
*  FUNCTION
*  NPR_Pub_AscToUcs2
*  DESCRIPTION
*  Converts Ansii encode string to unicode
*  CALLS
*  
*  PARAMETERS
*  pOutBuffer      [OUT]     
*  pInBuffer       [IN]  
*  RETURNS
*  U16
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
U16 NPR_Pub_AscToUcs2(S8 * pOutBuffer, S8 * pInBuffer)
{
        return mmi_asc_to_ucs2(pOutBuffer, pInBuffer);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Ucs2ToAsc
*  DESCRIPTION
*  Converts Unicode encode string to Ascii
*  CALLS
*  
*  PARAMETERS
*  pOutBuffer      [OUT]     
*  pInBuffer       [IN]    
*  RETURNS
*  U16
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
U16 NPR_Pub_Ucs2ToAsc(S8 * pOutBuffer, S8 * pInBuffer)
{
        return mmi_ucs2_to_asc(pOutBuffer, pInBuffer);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Ucs2NToAsc
*  DESCRIPTION
*  Converts N character Unicode encode string to Ascii
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  pOutBuffer      [OUT]         
*  pInBuffer       [IN]         
*  len             [IN]   
*  RETURNS
*  U16
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
U16 NPR_Pub_Ucs2NToAsc(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    return mmi_ucs2_n_to_asc(pOutBuffer, pInBuffer, len);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Ucs2ncpy
*  DESCRIPTION
*  copies the one UCS2 encoded string to other
*  CALLS
*  
*  PARAMETERS
*  strDestination      [OUT]       StrDest-> Destination array
*  strSource           [IN]        
*  size                [IN]  
*  RETURNS
*  CHAR * -> pointer to destination string or NULL
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
char * NPR_Pub_Ucs2ncpy(char *strDestination, const char *strSource, U32 size)
{
        return (char*)mmi_ucs2ncpy(strDestination, strSource, size);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Ucs2cat
*  DESCRIPTION
*  
*  CALLS
*  
*  PARAMETERS
*  strDestination      [OUT]         
*  strSource           [IN]  
*  RETURNS
*  CHAR *
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
char * NPR_Pub_Ucs2cat(char *strDestination, const char *strSource)
{
        return (char*)mmi_ucs2cat(strDestination, strSource);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Ucs2cpy
*  DESCRIPTION
*  copies the one UCS2 encoded string to other
*  CALLS
*  
*  PARAMETERS
*  strDestination      [OUT]       StrDest-> Destination array
*  strSource           [IN] 
*  RETURNS
*  CHAR * -> pointer to destination string or NULL
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
char * NPR_Pub_Ucs2cpy(char *strDestination, const char *strSource)
{
        return (char*)mmi_ucs2cpy(strDestination, strSource);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_ucs2strlen
*  DESCRIPTION
*  Gives the length of UCS2 encoded string
*  CALLS
*  
*  PARAMETERS
*  arrOut      [IN]        array containing  UCS2 encoded characters
*  RETURNS
*  S32-> Status
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
S32 NPR_Pub_ucs2strlen(const char *arrOut)
{
        return mmi_ucs2strlen(arrOut);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_ucs2toi
*  DESCRIPTION
*  to parse over a int number, including positive and negative signs (+,-).
*  CALLS
*  
*  PARAMETERS
*  strSrc          [IN]        
*  out_num         [?]         Is the parsed int number
*  read_length     [?]     
*  RETURNS
*  1: parse successfully ; -1: parse number fail.
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-14
************************************************/
S32 NPR_Pub_ucs2toi(const char *strSrc, S32 *out_num, S32 *read_length)
{
        return mmi_ucs2toi(strSrc, out_num, read_length);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_ucs2find
*  DESCRIPTION
*  search for the break_chars and store how many chars have been read over to reach
*  the desired break_char in read_length
*  CALLS
*  
*  PARAMETERS
*  strSrc          [IN]        
*  break_chars     [IN]        
*  read_length     [?]         
*  direction       [IN]        1: sesarch forward ; -1: search backward.
*  RETURNS
*  1: found the break_chars ;  -1: searched over the whole strSrc and do not fing the break_chars
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-14
************************************************/
S32 NPR_Pub_ucs2find(const char *strSrc, const char *break_chars, S32 *read_length, S16 direction)
{
        return mmi_ucs2find(strSrc, break_chars, read_length, direction);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_PrintText
*  DESCRIPTION
*  Print text to screen 
*  CALLS
*  
*  PARAMETERS
*  S32 x: 
*  S32 y:
*  UI_font_type f:
*  color c: text color
*  UI_string_type text:  text for print
*  RETURNS
*  void
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
void NPR_Pub_PrintText(S32 x, S32 y, UI_font_type f, color c, UI_string_type text, BOOL is_underline)
{
        if(is_underline)
        {
                f->underline = 1;
        }
        else
        {
                f->underline = 0;
        }
        gui_set_font(f);
        gui_set_text_color(c);
        gui_move_text_cursor(x,y);
        gui_print_text(text);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Utf8ToUcs2String
*  DESCRIPTION
*  Converts utf-8 encode string to unicode
*  CALLS
*  
*  PARAMETERS
*  dest            [OUT]       
*  dest_size       [IN]        
*  src             [IN]     
*  src_size     [IN]
*  RETURNS
*  void
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
void NPR_Pub_Utf8ToUcs2String(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src, kal_int32 src_size)
{
        char* tempStr = NULL;
#if defined (__MED_IN_ASM__)
        tempStr = (char*)applib_asm_alloc_anonymous(src_size + 1);
#else
        tempStr = (char*)med_alloc_ext_mem(src_size + 1);
#endif

        if(NULL != tempStr)
        {
                memset(tempStr, 0, src_size + 1);
                memcpy((char *)tempStr, (const char *)src, src_size);
                mmi_chset_utf8_to_ucs2_string(dest, dest_size, tempStr);
#if defined (__MED_IN_ASM__)
		applib_asm_free_anonymous(tempStr)	;
#else
             med_free_ext_mem((void**)&tempStr);
#endif
        }
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Ucs2ToUtf8String
*  DESCRIPTION
*  Converts unicode encode string to utf-8
*  CALLS
*  
*  PARAMETERS
*  dest            [OUT]       
*  dest_size       [IN]        
*  src             [IN] 
*  RETURNS
*  kal_int32
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-19
************************************************/
kal_int32 NPR_Pub_Ucs2ToUtf8String(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src)
{
        return mmi_chset_ucs2_to_utf8_string(dest, dest_size, src);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_AnsiiNToUnicodeString
*  DESCRIPTION
*  Converts N character Ansii encode string to unicode
*  CALLS
*  
*  PARAMETERS
*  pOutBuffer      [OUT]         
*  pInBuffer       [IN]         
*  len             [IN]      
*  RETURNS
*  U16
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-01
************************************************/
U16 NPR_Pub_AnsiiNToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
        return mmi_asc_n_to_ucs2(pOutBuffer, pInBuffer, len);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_UCS2Wcsstr
*  DESCRIPTION
*  Find a substring.
*  CALLS
*  
*  PARAMETERS
*  string        [IN]  UCS2 encoded string(wide-character) to search.       
*  str_char_set  [IN]  UCS2 encoded string(wide-character) to search for.   
*  RETURNS
*  Returns a pointer to the first occurrence of str_char_set in string, or 
*  NULL if str_char_set does not appear in string. If str_char_set points to 
*  a string of zero length, the function returns string. 
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-01
************************************************/
U16 * NPR_Pub_UCS2Wcsstr(U16 *string, const U16 *str_char_set)
{
        return (U16 *)mmi_wcsstr(string, str_char_set);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_UCS2Wcschr
*  DESCRIPTION
*  Searches a UCS2 encoded string(wide-character) for a given wide-character,
*  CALLS
*  
*  PARAMETERS
*  string        [IN]  UCS2 encoded string(wide-character) to search in.       
*  ch            [IN]  UCS2 encoded wide-character to search for.  
*  RETURNS
*  returns pointer to the first occurrence of ch in string
*  returns NULL if ch does not occur in string
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-01
************************************************/
U16 * NPR_Pub_UCS2Wcschr(const U16 *string,  U16 ch)
{
        if(string == NULL)
                return NULL;
        return (U16 *)mmi_wcschr(string,  ch);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Strcmp
*  DESCRIPTION
*  字符串比较函数
*  CALLS
*  
*  PARAMETERS
*  str1 : 字符串1
*  str2 : 字符串2
*  RETURNS
*  int : 0为俩字符串相等
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-22
************************************************/
int NPR_Pub_Strcmp(const char * str1, const char *str2)
{
        return strcmp(str1, str2);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Strcpy
*  DESCRIPTION
*  将str2的内容复制到str1中
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  char*
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-29
************************************************/
char* NPR_Pub_Strcpy(char* str1, const char* str2)
{
        return strcpy(str1,str2);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Strlen
*  DESCRIPTION
*  获取字符串长度
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-02
************************************************/
U32 NPR_Pub_Strlen(char* str)
{
        return strlen(str);
}


 

/*****************************************************************************
* FUNCTION
*  NPR_Pub_ReadRecord
* DESCRIPTION
*  This function is to read record from NVRAM.
* PARAMETERS
*  nLID            :[IN]        NVRAM Data Item LID
*  nRecordId       :[IN]        Record Index
*  pBuffer         :[OUT]       read data buffer
*  nBufferSize     :[IN]        buffer size
*  pError          :[OUT]       Success:NVRAM_READ_SUCCESS
*                              Fail:   NVRAM_READ_FAIL
*                              Other:  NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ
*                                      NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ
* RETURNS
*  Data read success return data read number, fail return -1, FS Check 0
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-22
************************************************/
S32 NPR_Pub_ReadRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError)
{
	S32 ret = 0;
        ret = ReadRecord(nLID, nRecordId, pBuffer, nBufferSize, pError);
        return ret;
}


/*****************************************************************************
* FUNCTION
*  NPR_Pub_WriteRecord
* DESCRIPTION
*  This function is to write record to NVRAM.
* PARAMETERS
*  nLID            :[IN]        NVRAM Data Item LID
*  nRecordId       :[IN]        Record Index
*  pBuffer         :[OUT]       read data buffer
*  nBufferSize     :[IN]        buffer size
*  pError          :[OUT]       Success:NVRAM_READ_SUCCESS
*                              Fail:   NVRAM_READ_FAIL
*                              Other:  NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ
*                                      NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ
* RETURNS
*  Data read success return data read number, fail return -1, FS Check 0
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-22
************************************************/
S32 NPR_Pub_WriteRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError)
{
        S32 ret = 0;
        ret = WriteRecord(nLID, nRecordId, pBuffer, nBufferSize, pError);
        return ret;
}


/*************************************************
*  FUNCTION
*  NPR_Pub_MallocMem
*  DESCRIPTION
*  申请较大的内存空间
*  CALLS
*  
*  PARAMETERS
*  int : size
*  RETURNS
*  void * 
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-30
************************************************/
void* NPR_Pub_AllocBigMem(unsigned int size)
{
    void * ptr = NULL;  

	
    #if 1//def WIN32
	

#if defined (__MED_IN_ASM__)
	return (void*)applib_asm_alloc_anonymous(size);
#else
      return (void*)med_alloc_ext_mem(size);
#endif
       // ptr = mmi_frm_scrmem_alloc_framebuffer(size);
    #else
        module_type modid=stack_get_active_module_id();

        if(modid==MOD_MED)
        {
        }
        #if defined(MT6235)||defined(MT6238)||defined(MT6235B)|| defined (MT6239)
            else if(media_get_ext_buffer_cacheable(modid,(void**)&ptr,size)==0)
            {
                return ptr;
            }	
        #else
            else if(media_get_ext_buffer(modid,(void**)&ptr,size)==0)
            {
                return ptr;
            }
        #endif
    #endif
    return ptr;
}


/*************************************************
*  FUNCTION
*  NPR_Pub_FreeBigMem
*  DESCRIPTION
*  释放内存空间
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-30
************************************************/
void NPR_Pub_FreeBigMem(void* p)
{
   #if defined (__MED_IN_ASM__)
	applib_asm_free_anonymous(p);
   #else
       med_free_ext_mem((void**)&p);
   #endif
}


/*************************************************
*  FUNCTION
*  NPR_Pub_MallocSmallMem
*  DESCRIPTION
*  申请较小的内存空间
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  void*
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-30
************************************************/
void* NPR_Pub_AllocSmallMem(unsigned int size)
{
        
        void * ptr = NULL;  
        ptr = (void*)OslMalloc(size);
        return ptr;
}


/*************************************************
*  FUNCTION
*  NPR_Pub_FreeSmallMem
*  DESCRIPTION
*  释放较小的内存空间
*  CALLS
*  
*  PARAMETERS
*  void*
*  RETURNS
*  void
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-01
************************************************/
void NPR_Pub_FreeSmallMem(void* p)
{
        OslMfree(p);
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Rand
*  DESCRIPTION
*  获取随机变量
*  CALLS
*  
*  PARAMETERS
*  int 
*  RETURNS
*  int
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-30
************************************************/
int NPR_Pub_Rand(int size)
{
        int seed = 0;
        int ret = 0;

        kal_get_time((kal_uint32 *)&seed);
        srand(seed);
        ret = rand()%size;

        return ret;
}


/*************************************************
*  FUNCTION
*  NPR_Pub_Pow10
*  DESCRIPTION
*  计算10的N次方
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-20
************************************************/
int NPR_Pub_Pow10(int index)
{
        int i, ret = 1;

        for (i = 0; i < index; i++)
        {
                ret = ret * 10;
        }
        return ret;
}


/*************************************************
*  FUNCTION
*  NPR_Pub_PlayTone
*  DESCRIPTION
*  播放声音，用于测试
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-12-20
************************************************/
void NPR_Pub_PlayTone(void)
{
#if 0
	srv_prof_ret ret;
	srv_vibrator_on();
	ret = srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);
	GT_TRACE("NPR_Pub_PlayTone ret=%d",ret);
#else
      mdi_result ret =  mdi_audio_play_id_with_vol_path(
                 TONE_WARNING1,
                 DEVICE_AUDIO_PLAY_ONCE,
                 MDI_AUD_VOL_MUTE(6),
                 MDI_DEVICE_SPEAKER_BOTH);
//GT_TRACE("NPR_Pub_PlayTone ret=%d",ret);
#endif
}

 
 



 //示例
//NPR_Pub_trace_to_file(1, "JD_Entry_MusicRadarPre   index = %d(%s:%d)",index,  __FILE__, __LINE__);
/*************************************************
*  FUNCTION
*  NPR_Pub_trace_to_file
*  DESCRIPTION
*  trace 函数
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-23
************************************************/
void NPR_Pub_trace_to_file(U8 type, const char *format, ... )
{
#ifdef NPR_TRACE
        static char str[1024] = { 0 };
        FS_HANDLE  hFile;
        va_list args;
        MYTIME  date_time={0};

        S8 tempStr[64];
        U16 dirPath[128];
        U32 uWriteSize; 

        char time_str[64] = {0};

        memset(dirPath, 0, sizeof(dirPath));
        memset(tempStr, 0, sizeof(tempStr));
        va_start( args, format );
        _vsnprintf( str, sizeof(str), format, args );
        va_end( args );

        GetDateTime(&date_time);
        sprintf((S8 *)time_str, "time: %d:%d:%d \r\n", date_time.nHour, date_time.nMin, date_time.nSec);

        str[1024-1] = 0;
        if(1 == type)
        {
                hFile = NPR_File_FileOperate(FILE_HANDLE_OPEN, "Trace", FS_OPEN_DIR | FS_READ_ONLY, FALSE);
                if (hFile < 0)
                {
                        FS_Close(hFile);
                        NPR_File_FileOperate(FILE_HANDLE_CREATEDIR, "Trace", FS_OPEN_DIR | FS_READ_ONLY, FALSE);
                }
                else
                {
                        FS_Close(hFile);
                }
                hFile = NPR_File_FileOperate( FILE_HANDLE_OPEN, "Trace\\trace.txt",FS_CREATE  |FS_READ_WRITE, FALSE);
                if(hFile)
                {
                        FS_Seek(hFile,0,FS_FILE_END);
                        FS_Write( hFile, str, strlen(str),&uWriteSize);
                        //FS_Write( hFile, "\r\n", 2 ,&uWriteSize);
                        FS_Write( hFile, time_str, strlen(time_str) ,&uWriteSize);
                        FS_Close( hFile );
                }
        }
        else
        {
                rmmi_write_to_uart((kal_uint8 *) str, strlen(str), KAL_TRUE);
        }
#endif
}

void NPR_Pub_WriteInfoToFile(int len, char* p, char * filePath)
{
#ifdef NPR_TRACE
        FS_HANDLE hFile;	
        U32 uWriteSize;
        int result = FS_NO_ERROR;

        hFile = NPR_File_FileOperate(FILE_HANDLE_OPEN, filePath, FS_READ_WRITE|FS_CREATE, FALSE);

        if(hFile >= FS_NO_ERROR)
        {
                FS_Seek(hFile, 0, FS_FILE_END);
                result = FS_Write(hFile, p, len, &uWriteSize);
                FS_Write( hFile, "\r\n", 2 ,&uWriteSize);
                FS_Write( hFile, "\r\n", 2 ,&uWriteSize);
                result = FS_Write( hFile, "****Cutting line****", 20 ,&uWriteSize);
                FS_Write( hFile, "\r\n", 2 ,&uWriteSize);
                FS_Write( hFile, "\r\n", 2 ,&uWriteSize);
        }
        FS_Close(hFile);
#endif
}

void NPR_Pub_RegisterPenHandlers(npr_pen_hdlr down_pen_fp, npr_pen_hdlr up_pen_fp, npr_pen_hdlr move_pen_fp)
{
#ifdef __MMI_TOUCH_SCREEN__	
        wgui_clear_pen_handlers();
        if(NULL != down_pen_fp)
        {
                mmi_pen_register_down_handler((mmi_pen_hdlr)down_pen_fp);
        }
        if(NULL != up_pen_fp)
        {
                mmi_pen_register_up_handler((mmi_pen_hdlr)up_pen_fp);
        }
        if(NULL != move_pen_fp)
        {
                mmi_pen_register_move_handler((mmi_pen_hdlr)move_pen_fp);
        }
#endif
}

U16 NPR_Pub_GetKeyCode(U16 index)
{
    	U16 keycode;
	
    	switch(index)
    	{
        	case ENUM_KEY_UP_ARROW:
            		keycode = KEY_UP_ARROW;
            		break;
        	case ENUM_KEY_DOWN_ARROW:
            		keycode = KEY_DOWN_ARROW;
            		break;
        	case ENUM_KEY_LEFT_ARROW:
            		keycode = KEY_LEFT_ARROW;
            		break;
        	case ENUM_KEY_RIGHT_ARROW:
            		keycode = KEY_RIGHT_ARROW;
            		break;
        	case ENUM_KEY_VOL_UP:
            		keycode = KEY_VOL_UP;
            		break;
        	case ENUM_KEY_VOL_DOWN:
            		keycode = KEY_VOL_DOWN;
            		break;
        	case ENUM_KEY_ENTER:
            		keycode = KEY_ENTER;
            		break;
        	case ENUM_KEY_LSK:
            		keycode = KEY_LSK;
            		break;
        	case ENUM_KEY_RSK:
            		keycode = KEY_RSK;
            		break;
        	case ENUM_KEY_2:
            		keycode = KEY_2;
            		break;
        	case ENUM_KEY_4:
            		keycode = KEY_4;
            		break;
        	case ENUM_KEY_6:
            		keycode = KEY_6;
            		break;
        	case ENUM_KEY_8:
            		keycode = KEY_8;
            		break;
	case ENUM_KEY_1:
    		keycode = KEY_1;
    		break;
	case ENUM_KEY_3:
    		keycode = KEY_3;
    		break;
	case ENUM_KEY_5:
    		keycode = KEY_5;
    		break;
	case ENUM_KEY_7:
    		keycode = KEY_7;
    		break;
	case ENUM_KEY_9:
    		keycode = KEY_9;
    		break;
	case ENUM_KEY_0:
    		keycode = KEY_0;
    		break;
	case ENUM_KEY_STAR:
    		keycode = KEY_STAR;
    		break;
	case ENUM_KEY_POUND:
    		keycode = KEY_POUND;
    		break;
	case ENUM_KEY_END:
    		keycode = KEY_END;
    		break;
        	default:
            		break;
    	}
		
    	return keycode;
}

UI_font_type NPR_Pub_Getfont(void)
{
#if defined (__MMI_MAINLCD_240X400__)
        return &MMI_small_font;
#else
        return &MMI_large_font;
#endif
        ///MMI_small_font
        ///MMI_medium_font
        ///MMI_large_font
}

void NPR_Pub_GobackIdleScreen(void)
{
	 //troy 暂时屏蔽，编译通过GoBackToHistory(IDLE_SCREEN_ID);
}

void NPR_Pub_ClearAllKeyHandler(void)
{
	ClearAllKeyHandler();
}

S32 NPR_Pub_ShowLimitLineText(S32 x1, S32 y1, S32 width, color c, UI_string_type strBuffer, BOOL is_underline)
{   
    UI_string_type chrPtr = strBuffer;
    U32 chrW = 0;
    U32 chrH = 0;
    S32 lineTextW, lineTextH;
    U8 lineNum = 1;
    U32 x = x1;
    U8 lineTextC = 0;
    U8 i=0;
    UI_font_type f = NPR_Pub_Getfont();
    U16 printedTextC = 0, totalC = mmi_ucs2strlen((CHAR *)strBuffer);
        
    if(is_underline)
        f->underline = 1;

    gui_set_font(f);
    chrW = NPR_SM_CHINESE_CHARACTER_W;
    chrH = NPR_PUB_LINE_INTERVAL + 2;
    gui_set_text_color(c);
    lineTextC = width / chrW;
    while(app_ucs2_strlen((kal_int8*) chrPtr) >= lineTextC && printedTextC < totalC)
    {
        if(printedTextC + lineTextC > totalC) lineTextC = totalC - printedTextC;
        lineTextW = gui_get_string_width_n(chrPtr, lineTextC);
        for(i = 0; lineTextW < width, printedTextC + lineTextC < totalC; i++, lineTextC++)
        {
            lineTextW = gui_get_string_width_n(chrPtr, lineTextC);
            if(lineTextW > width)
            {
                lineTextC--;
                break;
            }
        }
        lineTextH = gui_get_string_height(chrPtr);
        
        gui_move_text_cursor(x, y1 + (lineNum - 1) * chrH + (chrH - lineTextH >> 1));
        gui_print_text_n(chrPtr, lineTextC);
        printedTextC += lineTextC;
        lineNum++;
        chrPtr += lineTextC;
        lineTextC = width / chrW;
    }
    if(app_ucs2_strlen((kal_int8*) chrPtr) < lineTextC && printedTextC < totalC)
    {
        lineTextH = gui_get_string_height(chrPtr);
        gui_move_text_cursor(x, y1 + lineNum * chrH - lineTextH);
        gui_print_text(chrPtr);
    }

    f->underline = 0;
    return (lineNum - 1);
}
U16 g_npr_font_width = 0;
U16 NPR_Pub_GetfontWidth(void)
{
        if(g_npr_font_width == 0)
        {
                g_npr_font_width = NPR_SM_CHINESE_CHARACTER_W;
        }
        return g_npr_font_width;
}

void NPR_Pub_WapStartBrowser(kal_uint8 * UniUrl)
{
}

void NPR_Pub_TurnOnBacklight(void)
{
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);//TurnOnBacklight(0);
}

void NPR_Pub_TurnOffBacklight(void)
{
        srv_backlight_turn_off();//TurnOffBacklight();
}


void NPR_Pub_SetScrollingBGColor(gdi_color bg_color)
{
        g_npr_scrolling_bgcolor = bg_color;
}

void NPR_Pub_ScrollingText_Background(S32 x1,S32 y1,S32 x2,S32 y2)
{
        //gdi_color bg_color = gdi_act_color_from_rgb(255,0, 0, 0);//GDI_COLOR_TRANSPARENT
        gdi_draw_solid_rect(x1, y1, x2, y2, g_npr_scrolling_bgcolor);
}

void NPR_Pub_ScrollingText_Handler(void)
{
        gui_handle_scrolling_text(&g_npr_pub_scrolling_text);
}

void NPR_Pub_ScrollingText(S32 x1,S32 y1,S32 x2,S32 y2,color text_color,color border_color,UI_string_type text)
{
        S32 character_height, w;

        S32 jd_width = x2-x1;
        S32 jd_higt = y2-y1;

        /* stop previous scroll text */
        if (g_npr_pub_scrolling_text_done)
        {
                gui_scrolling_text_stop(&g_npr_pub_scrolling_text);
        }
        else
        {
                g_npr_pub_scrolling_text_done = TRUE;
        }
        gui_create_scrolling_text(
                &g_npr_pub_scrolling_text,
                x1,
                y1,
                jd_width,
                jd_higt,
                text,
                NPR_Pub_ScrollingText_Handler,
                NPR_Pub_ScrollingText_Background,
                text_color,
                border_color
                );

#if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
#endif 

        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);

        /* title */
        gui_scrolling_text_stop(&g_npr_pub_scrolling_text);
        gui_set_font(NPR_Pub_Getfont());
        gui_measure_string(text, &w, &character_height);
        if (w > jd_width)
        {
                /* scrolling */
                gui_change_scrolling_text(&g_npr_pub_scrolling_text, text);
                gui_show_scrolling_text(&g_npr_pub_scrolling_text);
        }
        else
        {
                /* background */
                NPR_Pub_ScrollingText_Background(x1, y1,x2,y2);

                gui_push_text_clip();
                gui_set_text_clip(x1, y1, x2, y2);
                gui_set_text_color(text_color);
                if (r2lMMIFlag)
                {
                        gui_move_text_cursor(x1 + (jd_width + w) / 2, y1);
                }
                else
                {
                        gui_move_text_cursor(x1 + (jd_width - w) / 2, y1);
                }
                gui_set_line_height(character_height);
                gui_print_text(text);
                gui_pop_text_clip();
        }

        gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

void NPR_Pub_Stop_ScrollingText(void)
{
        gui_scrolling_text_stop(&g_npr_pub_scrolling_text);
}
srv_prof_volume_level NPR_Pub_Get_Volume_Level(void)
{
	srv_prof_volume_level vol_level;
	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, &vol_level);
	return vol_level;
}



/*************************************************
*  FUNCTION
*  NPR_File_CheckTCard
*  DESCRIPTION
*  检查T卡是否存在
*  CALLS
*  
*  PARAMETERS
*  void
*  RETURNS
*  U8
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-23
************************************************/
U8 NPR_File_CheckTCard(void)
{
        return srv_fmgr_drv_has_accessible_removable_drv();//fmgr_is_msdc_present();
}


/*************************************************
*  FUNCTION
*  NPR_File_GetDrv
*  DESCRIPTION
*  获取存储器盘符
*  CALLS
*  
*  PARAMETERS
*  void
*  RETURNS
*  U8
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-23
************************************************/
int NPR_File_GetDrv(void)
{
        if(NPR_File_CheckTCard())
        {
                return SRV_FMGR_CARD_DRV;//MMI_CARD_DRV;    //T卡
        }
        else
        {
                return SRV_FMGR_PUBLIC_DRV;//MMI_PUBLIC_DRV;  //C盘
        }
}



/*************************************************
*  FUNCTION
*  NPR_File_FileOperate
*  DESCRIPTION
*  封装文件操作各类函数
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-23
************************************************/
int  NPR_File_FileOperate(NPR_FILE_HANDLE_ENUM type, char * filePath, UINT flag, BOOL is_hidden)
{
        S8 tempStr[64];
        U16 dirPath[128];
        FS_HANDLE hFile = FS_NO_ERROR;	

        memset(dirPath, 0, sizeof(dirPath));
        memset(tempStr, 0, sizeof(tempStr));
        sprintf((S8 *)tempStr, "%c:\\%s", NPR_File_GetDrv(), filePath);
        NPR_Pub_AscToUcs2((S8 *)dirPath, (S8 *)tempStr);

        switch(type)
        {
                case FILE_HANDLE_OPEN:
                        hFile = FS_Open((U16 *)dirPath, flag);
                        break;
                case FILE_HANDLE_CREATEDIR:
                        FS_CreateDir((U16*)dirPath);
                        if(is_hidden)
                        {
                                FS_SetAttributes((U16*)dirPath, FS_ATTR_DIR | FS_ATTR_HIDDEN);
                        }
                        break;
                case FILE_HANDLE_DELETE:
                        hFile = FS_Delete((WCHAR *)dirPath);
                        break;
                case FILE_HANDLE_DELETE_DIR:
                        hFile = FS_XDelete(dirPath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
                        break;
                default:
                        break;
        }
        return hFile;
}

BOOL NPR_File_DiskFreeSpace(U64 *pdisk_free_space)
{
	U64 disk_free_space;
    	U64 disk_total_space;
	
    	S32 fs_ret;
    	FS_DiskInfo disk_info;

	 S8 tempStr[64];
        U16 dirPath[128];
   
        memset(dirPath, 0, sizeof(dirPath));
        memset(tempStr, 0, sizeof(tempStr));
        sprintf((S8 *)tempStr, "%c:\\", NPR_File_GetDrv());
        NPR_Pub_AscToUcs2((S8 *)dirPath, (S8 *)tempStr);
	
	fs_ret = FS_GetDiskInfo((PU16) dirPath, 	&disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    	disk_free_space = 0;
    	disk_total_space = 0;
		
    	if (fs_ret >= 0)
    	{
        	disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        	disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

		*pdisk_free_space = disk_free_space;
		
              return TRUE;
    	}
		
    	return FALSE;
}


void NPR_Radar_SuspendBackgroundPlay(void)
{
        /* suspend background play */
        mdi_audio_suspend_background_play();
}

void NPR_Radar_ResumeBackgroundPlaly(void)
{
     
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, FALSE);

        /* resume background audio */
        mdi_audio_resume_background_play();
      
}
extern icontext_button MMI_softkeys[WGUI_MAX_SOFTKEYS];
BOOL NPR_Scr_CheckLSKPosition(U32 x, U32 y)
{
#ifdef __MMI_TOUCH_SCREEN__
        if((x>MMI_softkeys[MMI_LEFT_SOFTKEY].x)&&(x<(MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width  ))
                &&(y>MMI_softkeys[MMI_LEFT_SOFTKEY].y)&&(y<(MMI_softkeys[MMI_LEFT_SOFTKEY].y + MMI_softkeys[MMI_LEFT_SOFTKEY].height )))
        {
                return TRUE;
        }
        else
        {
                return FALSE;
        }
#else
        return FALSE;
#endif
}

BOOL NPR_Scr_CheckRSKPosition(U32 x, U32 y)
{
#ifdef __MMI_TOUCH_SCREEN__
        if((x>MMI_softkeys[MMI_RIGHT_SOFTKEY].x)&&(x<(MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width))&&
                (y>MMI_softkeys[MMI_RIGHT_SOFTKEY].y)&&(y<(MMI_softkeys[MMI_RIGHT_SOFTKEY].y + MMI_softkeys[MMI_RIGHT_SOFTKEY].height )))
        {
                return TRUE;
        }
        else
        {
                return FALSE;
        }
#else
        return FALSE;
#endif
}
#if 0
/*************************************************
*  FUNCTION
*  NPR_Http_IntToBit
*  DESCRIPTION
*  字符格式转换，由INT转成BIT
*  CALLS
*  
*  PARAMETERS
*  int
*  RETURNS
*  int
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-22
************************************************/
int NPR_Http_IntToBit(int data, int destlen, char *dest)
{
        char buf[5]={0};
        U8 byteFirst;
        U8 byteSecond;
        U8 byteThree;
        U8 byteFour;
        int totalByte;

        byteFirst     = data% 0x100;	
        byteSecond = (data/ 0x100) % 0x100;		
        byteThree   = (data/ 0x10000) % 0x100;			
        byteFour     = (data/ 0x1000000) % 0x100;

        sprintf(buf,"%c%c%c%c", byteFirst, byteSecond, byteThree, byteFour);
        memcpy((void *)(dest + destlen), (const void *)buf, sizeof(int));	

        totalByte = byteFirst + byteSecond + byteThree + byteFour;	

        return totalByte;
}


/*************************************************
*  FUNCTION
*  NPR_Http_BitToInt
*  DESCRIPTION
*  字符格式转换，由bit转成int
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  int
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-22
************************************************/
int NPR_Http_BitToInt(char *p)
{
        U8 * ptr;
        U8 byteFirst;
        U8 byteSecond;
        U8 byteThree;
        U8 byteFour;
        int total;

        ptr = (U8 *)p;

        byteFirst = *(U8 *)ptr;	
        byteSecond = *(U8 *)(ptr + 1);	
        byteThree = *(U8 *)(ptr + 2);	
        byteFour = *(U8 *)(ptr + 3);		
        total = byteFirst + byteSecond * 0x100 + byteThree * 0x10000+ byteFour * 0x1000000;

        return total;
}



/*************************************************
*  FUNCTION
*  NPR_Http_U8ToBit
*  DESCRIPTION
*  
*  CALLS
*  
*  PARAMETERS
*  
*  RETURNS
*  void
*  AUTHOR
*  Troy.Guan 
*  DATE
*  2010-11-22
************************************************/
void NPR_Http_U8ToBit(U8 data, int destlen, char *dest)
{
        char buf[2]={0};

        sprintf(buf, "%c", data);
        memcpy((void *)(dest + destlen), (const void *)buf, sizeof(U8));	
}

#endif
U16 NPR_TTS_GetCompileDateTime(char  *pBuf) 
{
	sprintf(pBuf, "Date(%s)Time(%s)", __DATE__, __TIME__);
	return strlen(pBuf);
}
U16 AnsiiToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer)
{
    return mmi_asc_to_ucs2(pOutBuffer, pInBuffer);
}

char g_imei_cntx[20] = {0};
static void NPR_GetIMEIRsp(unsigned char* imei)
{
    memset(g_imei_cntx, 0, sizeof(g_imei_cntx));
    if(imei != NULL)
        strncpy(g_imei_cntx, (char*)(imei), 16);
}

static void NPR_SysGetIMEIRsp(void *inMsg)
{
	mmi_nw_get_imei_rsp_struct *local_data_p = (mmi_nw_get_imei_rsp_struct*) inMsg;
	
	ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);

	if (local_data_p->result == 1)
	{
		NPR_GetIMEIRsp(local_data_p->imei);
	}
	else
	{
		NPR_GetIMEIRsp(NULL);
	}
	
}

static void NPR_SysGetIMEI(void)
{
	ilm_struct  * ilm_ptr = NULL;
	SetProtocolEventHandler(NPR_SysGetIMEIRsp, MSG_ID_MMI_NW_GET_IMEI_RSP);
	/* allocate the ilm struct memory */
	ilm_ptr = allocate_ilm(MOD_MMI);

	/* fill the member of the ilm struct */
	ilm_ptr->msg_id         = MSG_ID_MMI_NW_GET_IMEI_REQ;
	ilm_ptr->local_para_ptr = (local_para_struct *) NULL;
	ilm_ptr->peer_buff_ptr  = (peer_buff_struct *) NULL;

	/* send the message */
	SEND_ILM(MOD_MMI, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}


char *IV_GetImeiNumber()
{
	NPR_SysGetIMEI();
	return (char *)(g_imei_cntx);
}

#endif

