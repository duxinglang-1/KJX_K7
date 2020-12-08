#ifndef __SRV_VRE_DOWNLOADGPROT_H__
#define __SRV_VRE_DOWNLOADGPROT_H__

#define __SRV_VRE_DL__

#ifdef __cplusplus
extern "C" {
#endif

#include "MMIDataType.h"

/*************************************************** Download service Interfaces *****************************************************/

#define SRV_VRE_DL_DONE                1  //整个VXP下载完成
#define SRV_VRE_DL_SUCCESS             0  //成功
#define SRV_VRE_DL_ERR                 -1 //失败
#define SRV_VRE_DL_NET_ERR             -2 //网络错误         
#define SRV_VRE_DL_SAVE_ERR            -3 //保存错误
#define SRV_VRE_DL_APP_NOT_EXIST       -4 //应用不存在
#define SRV_VRE_DL_SPACE_FULL          -5 //空间不足
#define SRV_VRE_DL_OTHER_ERR           -6 //其它错误
#define SRV_VRE_DL_FILE_NOT_EXIST      -7 //文件不存在
#define SRV_VRE_DL_IO_ERROR            -8 //I/O 操作错误
#define SRV_VRE_DL_ERR_DOWNLOADING     -9 //Downloading a app, please stop it first.




#define  MAX_LEN_FILE_NAME                  (260)
#define  VAM_LEN_MD5                        (32)  


#define VRE_SRV_INT_SIZE                    sizeof(U32)


/*
*   应用下载状态类型定义
*/
typedef enum 
{
    APPDLSTATE_UNKNOWN = 0,         //未知状态
    APPDLSTATE_DOWNLOADING,         //正在下载  
    APPDLSTATE_FAIL,                //下载失败
    APPDLSTATE_OK,                  //已下载
    APPDLSTATE_NOT,                 //未下载
    APPDLSTATE_PAUSE,               //暂停下载
    APPDLSTATE_WAIT                 //等待下载
}E_AppDlState_t;





typedef struct
{
    /* Need to fill in when start */
    U32       nAppid;                                    /*应用ID*/
    WCHAR     szFilename[MAX_LEN_FILE_NAME + 1];         /*文件名*/

    /*Internal paramter*/
    S32       nPercent;                                  /*任务进度*/
    S32       nFilehandle;                               /*临时文件句柄*/
    S32       nRetryCount;                               /*重试次数*/
    U32       nFilesize;                                 /*文件大小*/
    U32       nDownloadsize;                             /*已下载大小*/
    WCHAR     szVXPDigest[VAM_LEN_MD5 + 1];              /*对vxp文件做的摘要*/
    E_AppDlState_t eState;                               /*任务状态*/
} VRE_DL_ITEM;


extern MMI_BOOL srv_vre_dl_is_running(void);

extern S32 srv_vre_dl_init(void);

extern S32 srv_vre_dl_deinit(void);

extern S32 srv_vre_dl_start(U32 appid, U16 *file_path, void(*download_app_cb)(S32 nResult, VRE_DL_ITEM *pDownload));

extern S32 srv_vre_dl_stop(S32 handle);

extern S32 srv_vre_dl_cancel(S32 handle);





/************************************************************** Get Info Interfaces *************************************************/

///////////////APP_VERSION
#define VM_APP_VERSION_APPNAME_LEN (40)
#define VM_APP_VERSION_FILENAME_LEN (20)

/*
* @sync_cb  回调函数。
*
* @	appid             为需要检查的应用程序编号.
* @	nResult为0 	  表示从服务器获取信息成功.
* @	app_version 	  表示当前服务器上的应用版本号,与本地的版本号比较来判定是否需要下载.
* @  	app_name	  表示appid 对应的app_name，为ucs2编码
* @	app_file_name  	  表示appid 对应的app_file_name，为ucs2编码
* @	app_filesize      表示当前服务器上对应版本号的应用程序的文件大小,单位为字节.
*
*/
typedef void (*sync_cb)(U32 appid, S32 nResult, S32 app_version, U8 *app_name,U8 *app_file_name,S32 app_filesize);

/**
* 检查应用程序的版本号,为异步接口.
* 
* @appid	为需要检查的应用程序编号.
* @sync_cb  	回调函数。
*
* @ return 0 发出请求成功，否则为失败。
*/
S32 srv_vre_dl_check_app_version (U32 appid, sync_cb sync_callback);


S32 srv_vre_dl_cancel_check_app_version (void);




/************************************************************** Update Interfaces *********************************************************/
#define AM_UPDATE_BILLING_INTERVAL      3

#define AM_NVRAM_READ_MAX_VALUE         16

#define VAM_RES_PATH_SIZE               (1024 * 4)

#define UPDATE_CONFIG_PATH "/update/config.txt?timezonzeid=China&permission=%s&cert=%s&appblalst=%s&channel=%s&appstore=%s"



#define VRE_SRV_CDR_NO_SYSC_CDR	                					(0)
#define VRE_SRV_CDR_NVRAM_NEED_FOR_SYNC_CDR				    (1)
#define VRE_SRV_CDR_TIME_NEED_FOR_SYNC_CDR					(2)




/*
*	系统配置数据类型
*/
typedef enum 
{
	VRE_SYSTEM_TIME = 1,  /*系统时间*/
	VRE_PUBLIC_KEY,       /*public key*/
	VRE_PERMISSION_BLACK_LIST, /*系统权限*/
	VRE_APPLICATION_BLACK_LIST,/*黑名单*/
	VRE_PAYMENT_CHANNEL,/*计费通道*/
	VRE_APPSTORE_VERSION,/*AS是否更新标志*/
	VRE_SHOW_FEE_HINT /*计费信息提示标志*/
}E_SysCfgCnt_t;


extern S32 srv_vre_update_sync_cdr(void (*sync_cb)(S32 nResult));

extern void srv_vre_update_cancel_sync_cdr(void);

extern S32 srv_vre_update_is_sync_cdr(void);






/*********************************************************** Data Account Interfaces *********************************************************/
typedef enum
{
    SRV_VRE_DA_SIM1,
    SRV_VRE_DA_SIM1_PX,
    SRV_VRE_DA_SIM2,
    SRV_VRE_DA_SIM2_PX,
    SRV_VRE_DA_WIFI_ONLY
}srv_vre_da_type;


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_init
 * DESCRIPTION
 *  VRE service, init VRE data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vre_da_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_deinit
 * DESCRIPTION
 *  VRE service, deinit VRE data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vre_da_deinit(void);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_get_app_id
 * DESCRIPTION
 *  VRE service, data account , to get a app ID
 * PARAMETERS
 *  void
 * RETURNS
 *  Application ID
 *****************************************************************************/
extern U8   srv_vre_da_get_app_id(void);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_get_account_id
 * DESCRIPTION
 *  VRE service, data account , to get a data account ID from NVRAM, could use this interface
 * PARAMETERS
 *  da_type         [IN]        The type of VRE Data account want to get
 * RETURNS
 *  Data Account ID of needed type.
 *****************************************************************************/
extern U32  srv_vre_da_get_account_id(srv_vre_da_type da_type);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_set_account_id
 * DESCRIPTION
 *  VRE service, data account , to Set a data account ID to NVRAM, could use this interface
 * PARAMETERS
 *  da_type         [IN]        The type of VRE Data account want to get
 *  da_id           [IN]        Data Account ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vre_da_set_account_id(srv_vre_da_type da_type, U16 da_id);



#ifdef __cplusplus
}
#endif

#endif /* __SRV_VRE_DOWNLOAD_H__ */
