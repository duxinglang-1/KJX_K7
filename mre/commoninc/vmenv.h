/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * 
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VM_ENV__
#define __VM_ENV__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmswitch.h"

#include "vmsys.h"
#include "vmdl.h"
#include "vmpromng.h"
#include "vmloader.h"

typedef enum {
	MRE_EVT_START_SUCCESS = 0,	/** succeed to start application async **/		    
    MRE_EVT_START_ASM_READY,    /**<ASM内存分配成功，MRE启动成功。                              */         
	MRE_EVT_START_INTERNEL_ERROR,		/**<系统在启动过程中内部失败。									*/
	MRE_EVT_QUIT							/**<MRE 即将退出的消息。 												*/
} VAM_START_MRE_EVT;

typedef void (*vm_mre_evt_cb_t)(VAM_START_MRE_EVT evt);
typedef void (*vm_mre_app_evt_cb_t)(VMUWSTR fileName, VAM_START_MRE_EVT evt);

#define VM_VLC_START_SUCCESS					(0)
#define VM_VLC_ASYN_ALLOC_ASM					(1)
#define VM_VLC_MASS_STORAGE					(-1)
#define VM_VLC_MEDIA_BUFFER_ALLOC_ERROR		(-2)
#define VM_VLC_INTERNEL_ERROR					(-3)
#define VM_VLC_NOT_ENOUGH_MEMORY            (-4)


#define VM_START_APP_NORMAL              0
#define VM_START_APP_EXIT_PARENT         1
#define VM_START_APP_RESTART_PARENT      2
#define VM_START_APP_NO_SELECT_POPUP     4
#define VM_START_APP_INSTALL             8
#define VM_FLAG_DIS_WLAN_PERFER (0X80000000)

/**
 * 启动MRE 环境，但是不会注册Pen, Keyboard的消息处理也不会
 * 创建MRE 的SCREEN。但关于SCREEN有一个例外，在MRE使用ASM
 * 内存并且内存没有分配到的时候，ASM Framework可能会有自己
 * 的Popup Screen。如果MRE环境已经启动则调用本函数不会有任何
 * 的处理，并且返回启动成功。
 * 
 * @param[in]					state 当前没有用到，默认为0。
 * @return					启动MRE是否成功的返回值。
 * @retval					VM_VLC_START_SUCCESS 启动成功。
 * @retval					VM_VLC_ASYN_ALLOC_ASM ASM没有分配到
 *							系统将异步释放掉其它占用ASM的应用。
 * @retval					VM_VLC_MASS_STOREAGE 手机处在存储模式，MRE启动失败。
 * @retval					VM_VLC_MEDIA_BUFFER_ALLOC_ERROR MRE申请media buffer失败。
 * @retval					VM_VLC_INTERNEL_ERROR MRE内部错误。
 */
VMINT vm_vam_load_core(vm_mre_evt_cb_t vam_cb);

/**
 * @name vm_execute函数的返回值
 * @{
 */
/**
 * 成功启动了指定应用。
 */
#define VM_EXECUTE_APP_SUCCESS					(0)

/**
 * 指定应用为非法的应用程序。
 */
#define VM_EXECUTE_APP_ILLEGAL					(-1)

/**
 * 没有足够的内存启动应用。
 */
#define VM_EXECUTE_APP_NOT_ENOUGH_MEMORY		(-2)

/**
 * 启动栈已满。
 */
#define VM_EXECUTE_APP_CALL_STACK_FULL			(-3)

/**
 * 启动内核内部错误，包括IO读取错误等。
 */
#define VM_EXECUTE_INTERNAL_ERROR				(-4)

/**
 * 应用程序运行参数与平台参数不匹配。
 */
#define VM_EXECUTE_PLATFORM_PARAM_DISMATCH		(-5)

/**
 * 应用程序超过有效期。
 */
#define VM_EXECUTE_TIMESTAMP_ERROR				(-6)

/**
 * 是黑名单的应用不能启动。
 */
#define VM_EXECUTE_BANNED_APP					(-7)

/**
 * 应用程序的IMSI号与平台的IMSI不匹配，启动失败。
 */
#define VM_EXECUTE_IMSI_DISMATCH					(-8)

/**
 * 应用程序使用的证书过期。
 */
#define VM_EXECUTE_CERT_OVERDUE					(-9)

/**
 * 在MRE目录下文件超过5000个则返回该错误码。
 */
#define VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY (-10)

/**
 * 系统没有足够的内存启动该应用。如果退出所有的应用也不能启动该
 * 应用。
 */
#define VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY		(-11)

/* */
#define VM_EXECUTE_SYS_ASYN_ASM     (-12)

#define VM_EXECUTE_SYS_NOT_SUPPORT_VP   (-13)

#define VM_EXECUTE_ONLY_ONE_FOREGROUND   (-14)

#define VM_EXECUTE_MAX_APP_NUM_REACHED   (-15)

#define VM_EXECUTE_VERSION_NOT_MATCH    (-16)
/**@} */

/**
 * 启动应用程序。如果应用启动成功，MRE 会创建MRE 的SCREEN，
 * 失败则不会创建。如果该文件已经被启动，则MRE会直接把
 * 该应用调度到前台。
 * 
 * @param[in]				filename 需要启动的文件名称，需要包含的路径。
 * @return				是否成功启动了应用程序的返回值。
 * @retval				VM_EXECUTE_APP_SUCCESS 启动应用程序成功。
 * @retval				VM_EXECUTE_APP_ILLEGAL 非法的应用程序。
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY 没有足够的内存启动应用程序。
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL 调用堆栈已满。
 * @retval				VM_EXECUTE_INTERNAL_ERROR 启动内核内部错误。
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH 平台参数不匹配。
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR 应用程序超过有效期。
 * @retval				VM_EXECUTE_BANNED_APP 是黑名单的应用不能启动。
 * @retval				VM_EXECUTE_IMSI_DISMATCH 应用程序的IMSI号与平台的IMSI不匹配，启动失败。
 * @retval				VM_EXECUTE_CERT_OVERDUE 应用程序使用的证书过期。
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY MRE目录下文件超过5000个返回该错误码。
 */
VMINT vm_execute(VMWSTR filename, vm_mre_app_evt_cb_t vam_cb);

/**
 * 启动预加载的应用程序。如果应用启动成功，MRE 会创建MRE 的SCREEN，
 * 失败则不会创建。如果该文件已经被启动，则MRE会直接把
 * 该应用调度到前台。
 * 
 * @param[in]				filename 需要启动的文件名称，需要包含的路径。
 * @return				是否成功启动了应用程序的返回值。
 * @retval				VM_EXECUTE_APP_SUCCESS 启动应用程序成功。
 * @retval				VM_EXECUTE_APP_ILLEGAL 非法的应用程序。
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY 没有足够的内存启动应用程序。
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL 调用堆栈已满。
 * @retval				VM_EXECUTE_INTERNAL_ERROR 启动内核内部错误。
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH 平台参数不匹配。
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR 应用程序超过有效期。
 * @retval				VM_EXECUTE_BANNED_APP 是黑名单的应用不能启动。
 * @retval				VM_EXECUTE_IMSI_DISMATCH 应用程序的IMSI号与平台的IMSI不匹配，启动失败。
 * @retval				VM_EXECUTE_CERT_OVERDUE 应用程序使用的证书过期。
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY MRE目录下文件超过5000个返回该错误码。
 */
VMINT vm_execute_preload_app(vm_preload_app_info_t *preload_info, vm_mre_app_evt_cb_t vam_cb);

/**
 * 已经运行的应用程序信息。
 */
typedef struct vm_running_app_info_t
{
	VMWCHAR app_filename[MAX_APP_NAME_LEN + 1];		/**< 当前已经运行的应用程序的名称。*/
	VMINT app_id;										/**< 应用程序编号。							*/
	VMUINT alloc_mem;									/**< 内存占用量，单位为KB。 				*/
}vm_running_app_info_t;

/**
 * 启动应用程序，如果返回VM_EXECUTE_APP_NOT_ENOUGH_MEMORY，则会向bg_app_infos与
 * app_info_num指针的位置写入当前正在后台运行的进程列表及个数。
 * 在不使用bg_app_infos所指向内存时，必须调用vm_release_app_running_infos释放
 * exist_app_infos所指向的对象。
 *
 * @code 
 * VMINT ret = VM_EXECUTE_APP_SUCCESS;
 * VMUINT infos_num = 0;
 * vm_running_app_info_t* infos = NULL;
 * 
 * ret = vm_execute_app((VMWSTR)L"c:\\mre\\game.vxp", &infos, &infos_num);
 * switch (ret)
 * {
 * case VM_EXECUTE_APP_NOT_ENOUGH_MEMORY:
 *     // 提示用户退出应用可以启动新应用。
 *     if (infos != NULL)
 *     {
 *         vm_release_app_running_infos(infos);
 *     }
 *     break;
 * case VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY:
 *     // 提示应用无法运行，内存需求过大。
 *     break;
 * case VM_EXECUTE_TIMESTAMP_ERROR:
 *     ......
 * }
 * @endcode
 * 
 * @param[in]				filename 需要启动的文件名称。
 * @param[out]			bg_app_infos 正在后台运行的应用程序的信息。
 * @param[out]			app_info_num 正在后台运行的应用程序信息个数。
 * @param[in]				filename 需要启动的文件名称，需要包含的路径。
 * 
 * @return				是否成功启动了应用程序的返回值。
 * @retval				VM_EXECUTE_APP_SUCCESS 启动应用程序成功。
 * @retval				VM_EXECUTE_APP_ILLEGAL 非法的应用程序。
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY 没有足够的内存启动应用程序。
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL 调用堆栈已满。
 * @retval				VM_EXECUTE_INTERNAL_ERROR 启动内核内部错误。
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH 平台参数不匹配。
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR 应用程序超过有效期。
 * @retval				VM_EXECUTE_BANNED_APP 是黑名单的应用不能启动。
 * @retval				VM_EXECUTE_IMSI_DISMATCH 应用程序的IMSI号与平台的IMSI不匹配，启动失败。
 * @retval				VM_EXECUTE_CERT_OVERDUE 应用程序使用的证书过期。
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY MRE目录下文件超过5000个返回该错误码。
 * @retval				VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY 应用所需要内存过大，系统无法满足需求。
 * 
 * @see					vm_release_app_running_infos
 */
VMINT vm_execute_app(VMWSTR filename, vm_running_app_info_t** bg_app_infos, VMUINT* app_info_num);

/**
 * 释放由调用vm_execute_ext产生出来的正在运行的应用程序信息。
 *
 * @param[in]				app_infos 应用程序信息。
 * @see					vm_execute_ext
 */
void vm_release_app_running_infos(vm_running_app_info_t* app_infos);

/**
 * 终止应用程序成功。
 */
#define VM_TERMINATE_SUCCESS					(0)

/**
 * 参数出错。
 */
#define VM_TERMINATE_ERROR_PARAM				(-1)

/**
 * 需要终止的应用程序不存在。
 */
#define VM_TERMINATE_NOT_EXISTS				(-2)

/**
 * 停止在前台运行的进程。
 */
#define VM_TERMINATE_ERROR_STATUS			(-3)

/**
 * 终止后台运行的应用程序。
 * 
 * @code
 * vm_terminate_bg_app((VMWSTR)L"c:\\mre\\game.vxp");
 * @endocde
 * @param[in]					filename 需要终止的应用程序的名称，是绝对路径。
 * @return					是否成功终止应用程序的标志。
 * @retval					VM_TERMINATE_SUCCESS 成功终止应用程序。
 * @retval					VM_TERMINATE_ERROR_PARAM 参数错误。
 * @retval					VM_TERMINATE_NOT_EXISTS 指定的应用程序不存在。
 * @retval					VM_TERMINATE_ERROR_STATUS 停止的应用程序正在前台运行，终止应用
 *							程序失败。
 */
VMINT vm_terminate_bg_app(VMWSTR filename);

/**
 * 如果MRE里有应用正在运行，调用本函数将没有作用;
 * 如果MRE没有运行调用本函数也没有任何作用;
 * 如果MRE没有应用正在运行且MRE环境启动成功，
 * 调用本函数会将MRE环境退出。
 */
void vm_vam_unload_core(void);

void vm_vam_unload_core_by_asm(void);

#define		VAM_IN_USE					1
#define		VAM_OUT_OF_USE			0

/*
 * 通知内核VAM的状态
 *  
 * @param[in] 			VAM_IN_USE 表示VAM正在运行，VAM_OUT_OF_USE 表示VAM已经退出。
*/
void vm_vam_set_vam_state(VMINT state);

/**
 * VAM 向MRE申请内存。
 * 
 * @param[in]				size 需要申请的内存数。
 * @return				NULL 分配失败，否则为内存的首地址。
 */
void* vm_vam_malloc(VMINT size);

/**
 * VAM 释放内存时调用。
 * 
 * @param[in]				p 需要释放的内存首地址。  
 */
void vm_vam_free(void* p);


/*
 * 判断应用程序是否在运行。
 *
 * @param[in]				vxp_filename	应用的文件名，必须是全路径。
 * @return				如果应用程序正在运行，返回1，否则返回0。
 */
VMINT vm_vam_app_is_running(VMWSTR vxp_filename);

#define		LOAD_VAM_RES_PARAM_ERROR				(-1)
#define		LOAD_VAM_RES_FAIL							(-2)
#define		LOAD_VAM_RES_INSUFFICIENT_BUF			(-3)

/*
 * 从文件中装载指定的资源
 *  
 * @param[in]					filename 文件的名称。
 * @param[in] 				res_name 资源名称。
 * @param[out]				res_size 接受资源长度的指针。
 * @param[in]					cache_buf 外部缓存 。
 * @param[in] 				cache_size 外部缓存的长度。
 * @return					加载资源成功返回0, 否则返回负数的错误码。
*/
int vm_vam_load_resource_from_file( short * filename, char * res_name, int * res_size, char * cache_buf, int cache_size );

/**
 * 语言类型。
 */
typedef enum LANGUAGE_TYPE{
	ENG = 0,		/**<英语。			*/
	CHS,		/**<简体中文。 	*/
	CHT			/**<繁体中文。 	*/
}LANGUAGE_TYPE;

/**
* 从配置文件中获取GIF数据至内存。详见unpackGIFZM.h和unpackGIFZM3.c
* 
* @param[in] 					gifzm 数据源。
* @param[out] 				data_buf 接受数据的缓存。
* @param[out] 				data_len 传回GIF数据长度。
* @return					成功时返回0，否则返回负数的错误码。
*							当data_buf为空时，该接口查询所需要获取的数据的大小，有data_len返回。
*							当data_buf不为空时，data_len的初始值为data_buf的大小, 
*							接口执行完，data_len返回数据的实际大小。
*/
VMINT vm_vam_get_gif_data(VMUINT8 *gifzm, VMUINT8 ** data_buf, VMINT *data_len);

/**
* 从配置文件中获取字符串数据至内存。详见unpackGIFZM.h和unpackGIFZM3.c
* 
* @param[in]					gifzm 数据源。
* @param[out]				data_buf 接受数据的缓存。
* @param[in]					lan 语言类型。
* @param[out]				data_len 传回string数据长度。
* @param[out]				font 传回字符串字体大小。
* @param[out]               data_size 字模size
* @return					成功时返回0，否则返回负数的错误码。
*							当data_buf为空时，该接口查询所需要获取的数据的大小，有data_len返回。
*							当data_buf不为空时，data_len的初始值为data_buf的大小, 
*							接口执行完，data_len返回数据的实际大小。
*/
VMINT vm_vam_get_string_data(VMUINT8* gifzm, VMUINT8** data_buf, LANGUAGE_TYPE lan, VMINT* data_len, VMINT* font, VMINT *data_size);


/**
 * 获取像素宽度
 * @param[in] zimo_buf 指向字模数据的指针 
 * @param[in] str_len 字符个数 
 *
 * @return  字模的像素宽度 
 */
VMINT vm_vam_measure_zimo_string(VMUINT8 *zimo_buf, VMINT str_len);

/**
 * 检查临时文件是否合法及下载进度。
 * 
 * @param[in]					filename 临时文件的名称。
 * @param[out]				progress	接受进度数据的指针。 
 * @return					如果临时文件合法返回0, 否则返回负数的错误码。
 *							返回0时, progress指向的数据代表进度（0 - 100）。
*/
VMINT vm_vam_check_tempfile(VMSHORT * filename, VMINT* progress);

/**
 * 取消下载。
 */
void vm_vam_cancel_download(void);

/**
 * 设置SIM卡。
 *
 * @param[in]					choose_index 选中的SIM卡编号，1为SIM卡一，2为SIM卡二。
 * @return                                	设置成功返回0，否则返回-1
 */
VMINT vm_vam_set_sim_card(VMINT choose_index);

/**
 * 设置网络类型。
 *
 * @param[in]					net_type 网络类型，1为GPRS，2为WIFI。
 * @return                             	设置成功返回0，否则返回-1
 */
VMINT vm_vam_set_net_type(VMINT net_type);

/**
 * 得到当前已经设置的卡的索引。
 * 
 * @param[out]				得到卡索引的指针。
 * @return					是否成功得到SIM卡索引的标志。
 * @retval					TRUE(1) 成功得到SIM卡索引。
 * @retval					FALSE(0) 失败，没有得到SIM卡索引。
 */
VMINT vm_vam_get_sim_card(VMINT* sim_index);

/**
 * 得到当前网络类型。
 * 
 * @param[out]				得到网络类型的指针。
 * @return					是否成功得到网络类型的标志。
 * @retval					TRUE(1) 成功得到网络类型。
 * @retval					FALSE(0) 失败，没有得到网络类型。
 */
VMINT vm_vam_get_net_type(VMINT* net_type);

/**
 * 设置网络连接点。
 * 
 * @param[in] 				point_type 连接点类型，1为CMWAP，2为CMNET。
 * @return                             	设置成功返回0，否则返回-1
 */
//VMINT vm_vam_set_connection_point(VMINT point_type);

/**
 * 验证应用程序是否有效
 * 
 * @param[in]					vxp_filename VXP文件的文件名，带全路径
 * @return					应用程序验证通过,返回0, 否则返回负数的错误码。参考vmcerter.h
 */
VMINT vm_vam_app_is_valid(VMWSTR vxp_filename);

#define  VAM_DL_DONE             	1  //整个VXP下载完成
#define  VAM_DL_OK               		0  //成功
#define  VAM_DL_ERR              		-1 //失败
#define  VAM_DL_NET_ERR         	-2 //网络错误         
#define  VAM_DL_SAVE_ERR         	-3 //保存错误
#define  VAM_DL_APP_NOT_EXIST  -4 //应用不存在
#define  VAM_DL_SPACE_FULL       	-5 //空间不足
#define  VAM_DL_OTHER_ERR        	-6 //其它错误
#define  VAM_DL_FILE_NOT_EXIST -7 //文件不存在
#define  VAM_DL_IO_ERROR        -8 //I/O 操作错误


/**
 * 发起应用下载* @param download_app_cb     下载应用回调
 *                             @param nResult  下载结果:VAM_DL_OK = 成功发送请求或者成功下载完一块
 *                                                      VAM_DL_DONE = 全部下载完成
 *                                                      VAM_DL_ERR等错误码
                                                        VAM_DL_IO_ERROR 文件操作错误
														VAM_DL_SPACE_FULL 空间不足
 *                             @param nPercent nResult不为VAM_DL_DONE时表示下载进度,否则表示存储盘符
 *
 * @param[in] 			    download_app_cb     下载应用回调。
 * @param[out] 				nResult  下载结果:VAM_DL_OK = 成功发送请求或者成功下载完一块
 *                                            VAM_DL_DONE = 全部下载完成
 *                                            VAM_DL_ERR等错误码
 * @paramp[out] 			nPercent nResult不为VAM_DL_DONE时表示下载进度,否则表示存储盘符
 * @param[in] 				pszVersionID 应用版本号ID。
 * @param[in]				pszFileName 文件名。
 * @param[in] 				nBlockSize 下载块大小。
 * @return                  成功发起下载请求返回VAM_DL_OK, 否则返回错误码(VAM_DL_ERR, VAM_DL_IO_ERROR, VAM_DL_SPACE_FULL)。
 */
VMINT vm_vam_download_app(void(*download_app_cb)(VMINT nResult, VMINT nPercent), 
	VMUINT32 nAppID/*VMWSTR pszVersionID*/, VMWSTR pszFileName, VMINT nBlockSize);


#define			VMM_RET_NO_SYSC_CDR								(0)
#define			VAM_RET_NVRAM_NEED_FOR_SYNC_CDR				(1)
#define			VAM_RET_TIME_NEED_FOR_SYNC_CDR					(2)

/**
 * 是否需要同步计费。
 * 
 * @return					是否需要更新的标志。
 * @retval					VMM_RET_NO_SYSC_CDR 表示不需要更新。
 * @retval					VAM_RET_NVRAM_NEED_FOR_SYNC_CDR NVRAM满需要更新。
 * @retval					VAM_RET_TIME_NEED_FOR_SYNC_CDR 时间到需要更新。
 */
VMINT vm_vam_is_sync_cdr(void);

/**
 * 向服务器同步计费请求。
 * 
 * @param[in/out]				sync_cb 成功或失败的回调，参数nResult为0表示成功否则为失败。
 * @return					成功发起同步返回VAM_DL_OK, 否则返回错误码(VAM_DL_ERR, VAM_DL_IO_ERROR)。
 */
VMINT vm_vam_sync_cdr(void (*sync_cb)(VMINT nResult));

/**
 * 得到用户的余额。
 * 
 * @param[out]				user_balance 用户余额。
 * @return					0 表示已经得到余额，否则为失败。
 */
VMINT vm_vam_get_user_balance(VMUINT* user_balance);

/**
  * 取消计费更新
  */
void vm_vam_cancel_sync_cdr(void);
/**
 * 注册申请释放空间函数
 *
 * @param mem_calloc_cb   申请空间接口
 * @param mem_free_cb     释放空间接口
 */
void vm_am_pre_download_app(void *(* mem_calloc_cb)(int size), void (* mem_free_cb)(void *ptr));


/**
 * 获取应用版本号
 *
 * @param[in] 文件名
 * @param[out] 得到的版本号
 *
 * @return 获取成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
VMINT vm_get_app_version(VMWSTR filename, VMINT * version);

/*
 * 检测有无更新的请求
 *
 * @return  如果有应用程序的更新请求，返回更新请求的version id,否则返回null。
 */
VMWSTR vm_vam_need_update(void);

/*
 * 清除更新，当vam获取更新请求的version id后，应该通知mre清除更新的version id。
 */
void vm_vam_clean_update(void);

/**
 * 退出所有进程，退出MRE环境。如果MRE没有启动则调用本函数
 * 将不会有任何作用。
 */
void vm_exit(void);
void vm_exit_ex(VMINT param);

/**
 * ASM 回收内存的操作的callback函数。
 */
void vm_exit_by_asm(void);

/**
 * 获得内置程序首地址列表。
 * 
 * @param[out]			app_array_ptr 内置程序首地址列表的指针。
 * @param[out]			app_array_len_ptr 内置程序个数。
 */
void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr);


/*****************************************************************************
 * FUNCTION
 *  vm_vam_get_core_asm_size
 * DESCRIPTION
 *  Get the ASM size of MRE core by byte.
 * RETURNS
 *  ASM size of MRE core by byte.
 *****************************************************************************/
VMUINT vm_vam_get_core_asm_size(void);


extern void vm_start_app(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT flag);
extern void vm_start_app_with_para(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT is_parent_exit,void* parameter,VMINT parameter_size);


/**
 * 交换字符串字节顺序
 *
 * @param 				pwDesData 交换后的字串
 * @param 				pwSrcData 源数据
 */
extern void vm_vam_string_byte_switch(VMWCHAR * pwDesData, VMWCHAR * pwSrcData);

extern VMINT vm_vam_get_app_version(VMWSTR filename, VMCHAR * appversion);

extern VMINT vm_vam_parse_time_data(vm_time_t *timestamp, char* str_time);

extern VMINT vm_vam_get_today_from_2000(void);

#ifdef __cplusplus
}
#endif
#endif
