/**********************************************************************************
*Filename:     kjx_prin.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/18
*
***********************************************************************************/
#if defined(__KJX_LOG_OUTPUT__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "kjx_include.h"
#include "common_nvram_editor_data_item.h"
#include "Nvram_struct.h"
#include "Nvram_common_defs.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#ifndef __va_rounded_size
#define __va_rounded_size(TYPE) (((sizeof(TYPE)+sizeof(int)-1)/sizeof(int))*sizeof(int))
#endif
#ifndef va_start
#define va_start(AP, LASTARG) (AP = ((char *)& (LASTARG) + __va_rounded_size(LASTARG)))
#endif
#ifndef va_arg
#define va_arg(AP, TYPE) (AP += __va_rounded_size(TYPE), *((TYPE *)(AP - __va_rounded_size(TYPE))))
#endif
#ifndef va_end
#define va_end(AP) (AP = (va_list)0 )
#endif

#define KJX_LOG_LENGTH_MAX   1024  //128
#define KJX_LOG_FILE L"Kjxlog.txt"
#define KJX_LOG_OUT_COM

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/

/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
nvram_ef_kjx_log_param_struct kjx_log_param = {0};
port_setting_struct port_setting = {0};

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static U16 log_status_flag = 0;
static U16 log_level = 0;
static char buf[KJX_LOG_LENGTH_MAX] = {0};
static BOOL allow_gprs_log = FALSE; //防止GPRS LOG的重入产生无限递归

/****************************************************************************
* 	Global Variable           			全局变量
*****************************************************************************/

/****************************************************************************
* 	Global Variable - Extern          引用全局变量
*****************************************************************************/

/*****************************************************************************
 *  Local Functions						本地函数
 *****************************************************************************/
 
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void kjx_write_file(const char *fmt, ...){}

void kjx_write_log_to_file(char* buffer, kal_int32 len)
{
	FS_HANDLE file = 0;
	U8 drive;
    U32 written = 0;
    char FilePathBuf[30] = {0};
    char FilePath[60] = {0};

	drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
	sprintf(FilePathBuf, "%c:\\", drive);

    mmi_asc_to_ucs2((CHAR*)FilePath, (CHAR*)FilePathBuf);
	mmi_ucs2cat((CHAR*)FilePath,(const CHAR*)KJX_LOG_FILE);
    file = FS_Open((const WCHAR *)FilePath, FS_READ_WRITE);
    if(file >= FS_NO_ERROR)
    {
        FS_Seek(file, 0, FS_FILE_END);
        FS_Write(file, (void*)buffer, len, &written);
        FS_Commit(file);
        FS_Close(file);
    }
    else if(file == FS_FILE_NOT_FOUND)
    {
        file = FS_Open((const WCHAR *)FilePath, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if(file >= FS_NO_ERROR)
        {
            FS_Seek(file, 0, FS_FILE_END);
            FS_Write(file, (void*)buffer, len, &written);
            FS_Commit(file);
            FS_Close(file);
        }
    }	
}

void kjx_log_to_file(const char *fmt, ...)
{
	va_list lstArg;
	kal_uint16 nLen=0;
	applib_time_struct currTime;
	char *p=get_ctrl_buffer(KJX_LOG_BUFF_SIZE);
	if(!p)
	{
		return;
	}
	
	memset(p, 0x00, KJX_LOG_BUFF_SIZE);
	memset(&currTime, 0x00, sizeof(currTime));
	applib_dt_get_rtc_time(&currTime);
	sprintf(p, "[%04d/%02d/%02d, %02d:%02d.%02d]", currTime.nYear,currTime.nMonth, currTime.nDay, currTime.nHour, currTime.nMin, currTime.nSec);
	nLen=strlen(p);

	va_start(lstArg, fmt);
	nLen = vsnprintf(p+nLen, KJX_LOG_BUFF_SIZE-2-nLen, fmt, lstArg);
	va_end(lstArg);
	strcat(p, "\r\n");
	nLen=strlen(p);

	kjx_write_log_to_file(p, nLen);

	free_ctrl_buffer(p);
}

void kjx_trace(const char *fmt, ...)
{
#if !defined(__KJX_LOG_OUTPUT__)
	va_list lstArg;
	kal_uint16 nLen=0;
	applib_time_struct currTime;
	
	char *p=get_ctrl_buffer(KJX_LOG_BUFF_SIZE);
	if(!p)
	{
		return;
	}
	
	memset(p, 0x00, KJX_LOG_BUFF_SIZE);
	memset(&currTime, 0x00, sizeof(currTime));
	applib_dt_get_rtc_time(&currTime);
	sprintf(p, "[%04d/%02d/%02d, %02d:%02d.%02d]", currTime.nYear,currTime.nMonth, currTime.nDay, currTime.nHour, currTime.nMin, currTime.nSec);
	nLen=strlen(p);

	va_start(lstArg, fmt);
	nLen = vsnprintf(p+nLen, KJX_LOG_BUFF_SIZE-2-nLen, fmt, lstArg);
	va_end(lstArg);
	strcat(p, "\r\n");
	nLen=strlen(p);

#ifdef KJX_LOG_OUT_COM
	rmmi_write_to_uart((kal_uint8*)p, nLen, KAL_TRUE);
#else
	kjx_write_log_to_file(p, nLen);
#endif

	free_ctrl_buffer(p);
#endif
}


/******************************************************************************
 *  Function    -  log_printftofile
 *
 *  Purpose     -  输出LOG信息到文件
 *
 *  Description -  NULL
 *
 *
 * modification history
 * ----------------------------------------
 * v1.0  ,
 * ----------------------------------------
 ******************************************************************************/
 void log_printftofile(char* log_PintfBuf, kal_bool  is_delete_file)
 {
 	FS_HANDLE file = 0;
	U8 drive;
    U32 written = 0;
    char FilePathBuf[30] = {0};
    char FilePath[60] = {0};

	drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
	sprintf(FilePathBuf, "%c:\\", drive);
    mmi_asc_to_ucs2((CHAR*)FilePath, (CHAR*)FilePathBuf);
	mmi_ucs2cat((CHAR*)FilePath,(const CHAR*)KJX_LOG_FILE);

	if(is_delete_file)
    {
    	file = FS_Open((const WCHAR*)FilePath, FS_OPEN_NO_DIR | FS_READ_ONLY);
		if(file >= 0)
        {
        	FS_Close(file);
            FS_Delete((const WCHAR*)FilePath);
		}
	}
	else
	{
		if(strlen((const char*)log_PintfBuf) > 0)
		{
			file = FS_Open((const WCHAR *)FilePath, FS_READ_WRITE);
		    if(file >= FS_NO_ERROR)
		    {
		        FS_Seek(file, 0, FS_FILE_END);
		        FS_Write(file, (void*)log_PintfBuf, strlen(log_PintfBuf), &written);
		        FS_Commit(file);
		        FS_Close(file);
		    }
		    else if(file == FS_FILE_NOT_FOUND)
		    {
		        file = FS_Open((const WCHAR *)FilePath, FS_READ_WRITE | FS_CREATE_ALWAYS);
		        if(file >= FS_NO_ERROR)
		        {
		            FS_Seek(file, 0, FS_FILE_END);
		            FS_Write(file, (void*)log_PintfBuf, strlen(log_PintfBuf), &written);
		            FS_Commit(file);
		            FS_Close(file);
		        }
		    }
		}
	}
}

/******************************************************************************
 *  Function    -  Kjx_Log_Init
 *
 *  Purpose     -
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * V1.0  , 2017-01-12
 * ----------------------------------------
 ******************************************************************************/
 void Tracker_Log_Init(void)
 {
 	kal_bool ret;
    S16 Error;
	
    ReadRecord(NVRAM_EF_KJX_LOG_PARAM_LID, 1, (void *)&kjx_log_param, NVRAM_EF_KJX_LOG_PARAM_SIZE, &Error);

#if defined(__AT_APP__)
	ReadRecord(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE, &Error);
#endif

	if(LOG_OFF == kjx_log_param.logd_target)
    {
    	return;
	}
    if(LOG_FILE == kjx_log_param.logd_target)
    {
    	//log_file_int();
    }
    else
    {
    	kjx_log_param.logd_target = LOG_CATCHER;
        WriteRecord(NVRAM_EF_KJX_LOG_PARAM_LID, 1, (void *)&kjx_log_param, NVRAM_EF_KJX_LOG_PARAM_SIZE, &Error);
	}
}

/******************************************************************************
 *  Function    -  LOGD
 *
 *  Purpose     -  日志通过串口打印输出函数
 *
 *  Description -  日志输出级别
 *                 1   ～ 10    ---- 错误
 *                 11  ～ 100   ---- 指令反馈
 *                 101 ～ 1000  ---- 调式信息
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-02-2011,  Cml  written
 * ----------------------------------------
 ******************************************************************************/
 void LOGDD(ENUM_LOG_MODULE module, ENUM_LOG_LEVEL level, const char *fun_name, const char *fmt, ...)
 {
 	static BOOL allow_gprs_log = TRUE; //防止GPRS LOG的重入产生无限递归
    U16 str_len = 0;
    MYTIME t;

	if((kjx_log_param.logd_target == LOG_OFF) || (level < 1) || ((module < kjx_log_param.logd_module[L_CON]) && (module > kjx_log_param.logd_module[L_SYS])) || (kjx_log_param.logd_module[module] == 0))
	{
		allow_gprs_log = TRUE;
        return;
	}
	
    if(FALSE == allow_gprs_log)
    {
    	//kal_prompt_trace(MOD_TST, " LOGDD 递归调用,禁止运行,退出");
    }
	
    if(1)
    {
    	va_list args;
        int n = 0;
		/*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
		memset(buf, 0, sizeof(buf));
        va_start(args, fmt);
        DTGetRTCTime(&t);
        if(kjx_log_param.logd_target == LOG_GPRS)
        {
        	sprintf(buf, "$$log,[%04d/%02d/%02d-%02d:%02d:%02d]..%s>>", t.nYear, t.nMonth, t.nDay, t.nHour, t.nMin, t.nSec, fun_name);
			str_len = strlen(buf);
		}
        else
        {
        	sprintf(buf, "[%04d/%02d/%02d-%02d:%02d:%02d]..%s>>", t.nYear, t.nMonth, t.nDay, t.nHour, t.nMin, t.nSec, fun_name);
			str_len = strlen(buf);
		}
	#if defined(WIN32)
		n = str_len + _vsnprintf(&buf[str_len], sizeof(buf), fmt, args);
	#else
		n = str_len + vsnprintf(&buf[str_len], sizeof(buf), fmt, args);
	#endif /* WIN32 */
        va_end(args);
        //这里N操作100的长度直接退出，打太长可能会导致重启
        if(n > KJX_LOG_LENGTH_MAX - 4)
        {
        	return;
		}
		
        if(n > 0)
        {
        	int bp;
            kal_uint16 ret = 0;
            *(buf + n) = '\r';
            *(buf + n + 1) = '\n';
            n += 2;
            if(kjx_log_param.logd_target == LOG_AUTO)  //Catcher
            {
            	;
			}
		#if defined(__KJX_AT_APP__)
			else if(kjx_log_param.logd_target == LOG_SERIAL)   //串口
            {
            	rmmi_write_to_uart((kal_uint8*)buf, n, KAL_TRUE);
			}
		#endif
			else if(kjx_log_param.logd_target == LOG_CATCHER)
            {
            	kal_prompt_trace(MOD_TST, "%s", buf);
			}
            else if(kjx_log_param.logd_target == LOG_FILE)
            {
				log_printftofile(buf, 0);
			}
            else if(kjx_log_param.logd_target == LOG_GPRS)
            {
            	allow_gprs_log = FALSE;
			#if 0
				kal_prompt_trace(MOD_TST," %s ,%d,%d",buf,n,tracker_login_info.Success);
				if(tracker_login_info.Success == TRUE&&soc_content.sendstate >= SOCKET_CONNECTED)
				{
					Tracker_GPRS_Socket_Send_Req((U8 *)buf,n);
				}
                else
                {
                	//kal_prompt_trace(MOD_TST, " LOGDD * %s", buf);
                	rmmi_write_to_uart((kal_uint8*)buf, n, KAL_TRUE);
				}
			#endif
				allow_gprs_log = TRUE;
				return;
			}
		}
	}
    return;
}

/******************************************************************************
*  Function    -  Kjx_Log_Modue_Info
*
*  Purpose     -  设置日志输出
*
*  Description -	AT^GT_CM=LOG,0#   关闭
*					AT^GT_CM=LOG,255#  开所有日志
*					AT^GT_CM=LOG,3,5#  开短信日志
*
* modification history
 * ----------------------------------------
* v1.0  , 2013-01-08, guojie  written
 * ----------------------------------------
******************************************************************************/
char* Kjx_Log_Modue_Info(void)
{
	static char String[100] = {0};

	//module:[0 0 0 0 0 0 0 ],target:1
    memset(String, 0, sizeof(String));
    // 主小区、相邻小区及信号强度
    sprintf(String, "module:[%d,%d,%d,%d,%d,%d,%d],target:%d", kjx_log_param.logd_module[L_CON],
            kjx_log_param.logd_module[L_DRV],
            kjx_log_param.logd_module[L_SOC],
            kjx_log_param.logd_module[L_CMD],
            kjx_log_param.logd_module[L_OS],
            kjx_log_param.logd_module[L_APP],
            kjx_log_param.logd_module[L_SYS],
            kjx_log_param.logd_target);
    return String;
}

#endif/*__KJX_LOG_OUTPUT__*/
