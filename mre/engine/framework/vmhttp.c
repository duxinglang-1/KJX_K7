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

/*******************************************************************************
* Filename:
* ---------
*  
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "vmswitch.h"

#ifdef __MRE_LIB_HTTP__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>

#include "vmhttp.h"
#include "vmsys.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "httputil.h"
#include "vmmod.h"
#include "vmsock.h"

#include "vmpromng.h"
#include "vmresmng.h"

#include "vmlog.h"



/**
 * HTTP模块自用日志函数，可分行打印长数据。
#define _vm_http_log_long(...)	
#define _vm_http_log_long(fmt, len)	
static void _vm_http_log_long(char *fmt, int len)
{
    if (len > 0) {	
        char text[100];
        int i = 0, t_size = sizeof(text); 
        //char *text=(char*)vm_malloc(t_size);
        //if (NULL == text) return;
        vm_log_debug("\n");							
        while (i < len) {													
            memset(text, 0x00,  t_size);						
            memcpy(text, fmt+i, t_size-1<len-i ? t_size-1 : len-i);	
            vm_log_debug("\n%s", text);								
            i += t_size-1; 
        } 												
        MMI_TRACE("\n"); 
        //vm_free(text); 
    }
}
 */



/*debug function in vmresmng.c*/
//extern void vm_print_res_table(void);

/* HTTP状态回调
#define NOTIFY_HTTP_STATE(hook, state, param, session, sessionInStateNotifyFunc, callback_flag) \
if (hook != NULL)\
{\
    if (sessionInStateNotifyFunc)\
    {\
        callback_flag++;\
        ((yesSessionInStateNotifyFunc)(hook))(state, param, session);\
        callback_flag--;\
    }\
    else\
    {\
        callback_flag++;\
        ((noSessionInStateNotifyFunc)(hook))(state, param);\
        callback_flag--;\
     }\
}*/

/* HTTP结果回调
#define NOTIFY_HTTP_RESULT(hook, state, session_ptr, callback_flag) \
if (hook != NULL)\
{\
    callback_flag++;\
    hook(state, session_ptr);\
    callback_flag--;\
}*/

#define RESPONSE_BUFFER_SIZE 					(1024 * 2)
#define CRLF			"\r\n"
#define CRLF_LEN		(2)//strlen(CRLF)
#define SPACE		' '
#define MIN(a, b)	(a >= b ? b : a)
#define MAX(a, b)	(a <= b ? b : a)

/* 
 * 以chunk编码方式接收或发送数据时，
 * TCP管道中操作数据块的最小值。
 */
#define HTTP_MIN_CHUNK_SIZE (16)	

typedef void (*noSessionInStateNotifyFunc)(int state, int param);
typedef void (*yesSessionInStateNotifyFunc)(int state, int param, void* session); 
typedef void (*ResultNotifyFunc)(int, void*);

/**
  * 当前buffer 里数据的类型，状态行，头(response-header和entity-header)，
  * 响应体。如果是transfer-coding 是chunked，那么在chunk extion data里也
  * 有可能包含entity-header，但是buffer的类型应该还是chunk_trailer.
  */
typedef enum {
    state_line = 0, 
    head,
    fixed_body, 
    chunk_size, 
    chunk_data, 
    chunk_trailer, 
    read_eof
}HTTP_RESPONSE_BUFFER_TYPE;

/**
  * HTTP response 的缓冲。
  */
typedef struct http_response_buffer_t {
    HTTP_RESPONSE_BUFFER_TYPE receive_type;		/* 当前收取的http response 的类型。 	*/
    VMUINT receive_num;							/* 当前在buffer 里已经有的字节数。 */
    VMUINT8 buffer[RESPONSE_BUFFER_SIZE];			/* http response 的缓冲。 					*/
    VMUINT chunk_size;							/* 只有在http response 的transfer-coding 为
                                                     chunked 的时候该字段才有意义。	*/
}http_response_buffer_t;

/**
  * TCP 写或读函数的返回值。
  *
  * OP_COMPLETE 对于TCP连接操作完成，可能是写或读。
  * OP_BLOCK 对于TCP连接被阻塞。
  * OP_ERROR 对于TCP连接失败。
  */
#define OP_COMPLETE				(1)
#define OP_BLOCK				(0)
#define OP_ERROR				(-1)
#define OP_USER_TERMINATE		(-2)

/*
 * 描述http session 的结构信息。
 * 
 * http_module_alloted 
 * 是否是http module 分配出的session 空间。
 *
 * use_proxy 
 * 是否采取cmwap的连接。
 *
 * tcp_connected 
 * tcp是否已经连接上了。
 *
 * receive_completed 
 * 0表示没有收完了http response，否则表示收完了。 
 *
 * sent http request 
 * 已经发出的请求的字节数。
 *
 * read http 
 * response里已经写到http session 里的resbody 字段的字节数。
 *
 * socket_handle
 * tcp的连接句柄。
 *
 * callback_lock
 * 回调到用户代码里则加1,从用户代码里回来则减1。
 * 
 * user_terminate_flag
 * 如果callback_lock不等于0，用户又调用了取消请求相关的
 * 函数则把该标志置成TRUE。初始为FALSE。
 * 
 * buffer
 * 用于存放响应的缓冲。
 *
 * sessionInStateNotifyFunc
 * 为TRUE表示在状态回调的时候需要把session回送回去，否者不回送。
 *
 * http_state_notify
 * 客户程序为了得到http通讯的各个状态，注册到http 模块内的函数指针。
 * 对于sessionInStateNotifyFunc为TRUE的函数签名
 * void (*http_state_notify)(int state, int param)
 * 对于sessionInStateNotifyFunc为FALSE的函数签名
 * void (*http_state_notify)(int state, int param, void* session)
 *
 * http_session_ptr 
 * 指向http session 的结构体指针 同时也是该单元是否已经启用的标志。
 */
typedef struct session_item_info {
    VMUINT8 http_module_alloted;
    VMUINT8 use_proxy;
    VMUINT8 tcp_connected;
    VMUINT8 receive_completed;
    VMUINT sent;
    VMUINT read;
    VMINT socket_handle;
    HTTP_METHOD	method;
    VMINT callback_lock;
    VMINT user_terminate_flag;
    http_response_buffer_t* buffer;
    VMINT sessionInStateNotifyFunc;
    void* http_state_notify;
    http_session_t* http_session_ptr;
    
    /* 新接口对应支持字段*/
    VMINT http_handle;	/* HTTP 句柄*/
    VMCHAR* req_url;	/* 可自定义长度的请求报文头URL */
    VMUINT8* req_body;	/* 可自定义长度的请求报文体 */
    VMINT req_body_length;	/* 可自定义长度的请求报文体长度 */
    void* sender;	/* HTTP 请求报文体发送回调函数，由应用端提供 */
    void* receiver;	/* HTTP 响应报文体接收回调函数，由应用端提供 */
    http_request_t* 	http_request;	/** HTTP请求指针，可由应用端提供，或内核自行维护 */

    VMUINT8* chunk_buffer_ptr;	/* 以chunk编码分块发送HTTP请求体时使用的缓冲区指针 */
    VMUINT chunk_buffer_length;	/* chunk_buffer_ptr中待发送的数据长度 */
    VMUINT chunk_buffer_sent;	/* chunk_buffer_ptr中已发送的数据长度 */
    VMINT req_eof;	/* HTTP请求结束符 */

    VMINT range_size;	/* The size of range per request. Range:bytes=%d-%d */
	//abm hold
    VMUINT32 account_id;
}session_item_info;

/*
  * http module是否已经启动的标志。
  */
//static VMINT http_module_started = FALSE;

/*
  * 返回http 通信状态的通知函数。
  */
static void (*notify_state_callback)(VMINT state, VMINT param) = NULL;

/*
  * 代理模式标志。
  */
static int use_proxy = HTTP_USE_CMWAP;

/*
  * 当前正在处理的HTTP句柄。
  */
static VMINT current_handle = -1;

/********************************************************
 * 函数定义部分 
 *******************************************************/
 /**
  * dump all http res infos
static void _vm_dump_http_res()
{
    VMINT ret = -1;
    VMINT p_handle = -1;
    VMINT res_handle = -1;
    VMINT res_size = 0;
    session_item_info * sii = NULL;
    
    _vm_http_log("{HTTP DEBUG} enter _vm_dump_http_res.");
    * 遍历所有HTTP 资源，取出具有对应SOCKET 句柄的资源 *
    res_handle = vm_res_findfirst(p_handle, VM_RES_TYPE_HTTP_HANDLE);
    _vm_http_log("{HTTP DEBUG} _vm_dump_http_res - after vm_res_findfirst - res_handle:%d, p_handle:%d .", res_handle, p_handle);
    if (VM_RES_NOT_FIND == res_handle)
    {
        _vm_http_log("{HTTP DEBUG} _vm_dump_http_res - vm_res_findfirst - failed - res_handle:%d, p_handle:%d .", res_handle, p_handle);
        return;
    }
    do {
        _vm_http_log("{HTTP DEBUG} _vm_dump_http_res - in do{...} - res_handle:%d, p_handle:%d .", res_handle, p_handle);

        ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, res_handle, (void **)&sii, &res_size);
        _vm_http_log("{HTTP DEBUG} _vm_dump_http_res - in do{...} - after vm_res_get_data - "
            "ret:%d, res_handle:%d, p_handle:%d, sii:%p .", ret, res_handle, p_handle, sii);
        
        res_handle = vm_res_findnext(p_handle, VM_RES_TYPE_HTTP_HANDLE);
        _vm_http_log("{HTTP DEBUG} _vm_dump_http_res - after vm_res_findnext - res_handle:%d, p_handle:%d .", res_handle, p_handle);
    } 
    while (VM_RES_NOT_FIND != res_handle);
    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
    _vm_http_log("{HTTP DEBUG} leave _vm_dump_http_res.");
}
  */

/*
  * 初始化http模块的函数。
  */
static VMINT vm_initialize_http_module(void);

/*
  * http模块的清理函数。
  */
static VMINT vm_finialize_http_module(void);

/**
  * 分配http session item，如果参数http_session_ptr为null，那么
  * 表示该http session空间的分配是由http module完成的。
  * 如果返回一个指向NULL的指针，表示资源不够，
  * 无法分配出一个http session item。
  */
static session_item_info* vm_allot_ssesion_item(http_session_t*);

/**
  * 回收http session item。如果分配了http response所需要的空间。
  * 那么该函数里将负责释放掉分配了的内存。
  */
static void vm_ret_session_item(session_item_info*);

/**
  * 由http 模块里注册到tcp 模块里的回调函数。
  */
static void vm_tcp_module_hook(VMINT, VMINT);

/**
  * 根据socket id 查找http sesion item ，如果找不到
  * 则返回一个NULL。
  */
static session_item_info* vm_get_item_info(VMINT handle, VMINT type);

/**
  * 发送HTTP request的函数。
  *
  * @param 			ptr 指针当前需要写入数据的http session的包装结构。
  * @return 			OP_COMPLETE	表示写数据完毕。
  *					OP_BLOCK 写数据的时候，TCP链路阻塞。
  *					OP_ERROR 写数据的时候TCP链接发生错误。
  */
static VMINT vm_http_write_data(session_item_info* ptr);

/**
  * 读取HTTP response的函数。
  *
  * @param 			ptr 当前需要读取数据的http session的包装结构。
  * @return 			OP_COMPLETE	表示读数据完毕。
  *					OP_BLOCK 读数据的时候，TCP链路阻塞。
  *					OP_ERROR 读数据的时候TCP链接发生错误。
  */
static VMINT vm_http_read_data(session_item_info* ptr);

/*
  * HTTP 模块的生命周期函数。
  */
static VMINT http_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);

/*
  * 把16进制字符串转化为10进制整数。如"FF" 转为255。
  */
static VMINT hex_cstring_to_oct(VMUINT8* str, VMINT* val);
extern const char* applib_inet_get_user_agent_string(void);
extern void *_vm_kernel_calloc(int size);
extern void _vm_kernel_free(void* ptr);

/*****************************************************************************
 * FUNCTION
 *  http_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT http_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event)
    {
    case EVT_MOD_INIT:
// 		if (0 != vm_initialize_http_module())
// 			return -1;
        vm_initialize_http_module();
        break;
// 	case EVT_MOD_ACTIVE:
// 		break;
// 	case EVT_MOD_INACTIVE:
// 		break;
    case EVT_MOD_RELEASE:
        vm_finialize_http_module();
        break;
// 	default :
// 		vm_log_error("{HTTP MODULE} Receive unkown[%d] event.", event);
// 		return -2;
    }

    return 0;
}

static VMINT vm_http_send_data_int(session_item_info * item_info_ptr)
{
    VMINT ret = 0;
    while(item_info_ptr->chunk_buffer_sent < item_info_ptr->chunk_buffer_length)
    {
        ret = vm_tcp_write(item_info_ptr->socket_handle,
            item_info_ptr->chunk_buffer_ptr+item_info_ptr->chunk_buffer_sent, 
            item_info_ptr->chunk_buffer_length-item_info_ptr->chunk_buffer_sent);
        if (ret > 0)
        {
            item_info_ptr->chunk_buffer_sent += ret;
        }

    }

    return ret;

}

static VMINT vm_http_data_prepare_int(session_item_info * sii, http_request_t * req_p)
{
    http_request_t * req_tmp = NULL;
    http_head_t * head_tmp = NULL;
    char * body_tmp = NULL;
    sii->http_request = vm_malloc(sizeof(http_request_t));
    if (NULL == sii->http_request)
    {
        vm_ret_session_item(sii);
        return -5;
    }
    req_tmp = sii->http_request;
    memset(req_tmp, 0, sizeof(http_request_t));
    //sii->http_request = asyn_request->http_request;
    //memcpy(sii->http_request, asyn_request->http_request, sizeof(http_request_t));
    memcpy(req_tmp->url, req_p->url, sizeof(req_tmp->url));
    req_tmp->nhead = req_p->nhead;
    req_tmp->nbody = req_p->nbody;
    if (req_p->heads)
    {
        VMINT i = 0;
        req_tmp->heads = vm_malloc(sizeof(http_head_t) * req_p->nhead);
        if (NULL == req_tmp->heads)
        {
            vm_ret_session_item(sii);
            return -6;
        }
        head_tmp = req_tmp->heads;
        memset(head_tmp, 0, sizeof(sizeof(http_head_t)) * req_p->nhead);
        for (i = 0; i < req_p->nhead; i++)
        {
            memcpy(head_tmp[i].name, req_p->heads[i].name, sizeof(head_tmp->name));
            memcpy(head_tmp[i].value, req_p->heads[i].value, sizeof(head_tmp->value));
        }
    }
    if (req_p->body)
    {
        req_tmp->body = vm_malloc(req_p->nbody);
        if (NULL == req_tmp->body)
        {
            vm_ret_session_item(sii);
            return -7;
        }
        body_tmp = req_tmp->body;
        memset(body_tmp, 0, req_p->nbody);
        memcpy(body_tmp, req_p->body, (req_p->nbody));
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  _vm_reg_http_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_http_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	int res_code = REG_MRE_MODULE_SUCCESS;
// 	res_code = _vm_reg_module("HTTP MODULE", (MOD_EVT_PROCESS)http_mod_evt_proc);
// 	if (REG_MRE_MODULE_SUCCESS != res_code)
// 	{
// 		vm_log_error("Failed to regisiter HTTP module. Error Code : %d .", res_code);
// 	}
// 	return res_code;

    return _vm_reg_module("HTP", (MOD_EVT_PROCESS)http_mod_evt_proc);
}


/*****************************************************************************
 * FUNCTION
 *  vm_cancel_all_http_sessions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_cancel_all_http_sessions(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * TODO:
     * 0. foreach http connections
     * 1. close tcp connection
     * 2. set user terminate flag
     * 3. release http resource 
*/
    VMINT p_handle = -1;
    VMINT res_handle = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	if (!http_module_started)
// 		return;

    /* 取当前进程句柄 */
    p_handle = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_554 , p_handle, current_handle);
    //_vm_dump_http_res();	
    
    /* 遍历进程的HTTP 资源，取出具有对应SOCKET 句柄的资源 */
        while (VM_RES_NOT_FIND != 
        (res_handle = vm_res_findfirst(p_handle, VM_RES_TYPE_HTTP_HANDLE)) )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_561 , res_handle);
        vm_http_free_handle(res_handle);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_563 , res_handle);
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }
    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);

    //_vm_dump_http_res();	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_578 , p_handle, current_handle);
    return;	
}


/*****************************************************************************
 * FUNCTION
 *  hex_cstring_to_oct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [?]     
 *  val     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT hex_cstring_to_oct(VMUINT8* str, VMINT* val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str)
    {
        VMINT len  = 0, i = 0, sum = 0;

        if ((len = strlen((char*)str)) > 0)
        {
            VMUINT8 chr = 0;
            VMINT exp = 1;

            for (i = 0; i < len; i++)
            {
                exp = ((i < len - 1) ? 16 : 1);
                chr = *(str + i);
                
                if (chr >= '0' && chr <= '9')
                {
                    sum = (sum + (chr - '0')) * exp;
                }
                else if (chr >= 'A' && chr <= 'F')
                {
                    sum = (sum + ((chr - 'A') + 10)) * exp;
                }
                else if (chr >= 'a' && chr <= 'f')
                {
                    sum = (sum + ((chr - 'a')+ 10)) * exp;
                }
                else
                    return -1;
            }

            *val = sum;
            return 0;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_item_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static session_item_info* vm_get_item_info(VMINT handle, VMINT type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * foreach res of current process
     * find res with socket_handle == handle
*/
    VMINT p_handle = -1;
    VMINT res_handle = -1;
    VMINT res_size = 0;
    session_item_info* info_ptr = NULL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_670 , handle, current_handle);
    //_vm_dump_http_res();	

    /* 取所有HTTP资源。
    TCP回调发生时，进程可能已被切换至后台运行。
    因此保持p_handle值为-1，取所有HTTP类型的资源。
    */
    //p_handle = vm_pmng_get_current_handle();
    
    /* 遍历所有HTTP 资源，取出具有对应SOCKET 句柄的资源 */
    if (VM_RES_NOT_FIND == 
        (res_handle = vm_res_findfirst(p_handle, VM_RES_TYPE_HTTP_HANDLE)) )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_683 , handle, current_handle, p_handle);
        vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
        return NULL;
    }
    do {
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_688 , res_handle, p_handle);
        if (VM_RES_OK != 
            vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, res_handle, (void **)&info_ptr, &res_size) )
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_692 , handle, res_handle);
            continue;
        }
        
        if (info_ptr->http_session_ptr)
        {/* session有效，且socket句柄匹配 */
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_699 , handle, res_handle, p_handle);
            if (0 == type)
            {
                if (info_ptr->socket_handle == handle)
                {
                    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
                    return info_ptr;
                }
            }
            else if (1 == type)
            {
                if (info_ptr->http_handle == handle)
                {
                    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
                    return info_ptr;
                }
            }
            //break;
        }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_704 , res_handle, p_handle);
    }
    while (VM_RES_NOT_FIND != 
        (res_handle = vm_res_findnext(p_handle, VM_RES_TYPE_HTTP_HANDLE)) );
    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);

    //_vm_dump_http_res();	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_711 , handle, current_handle);
    return NULL;
}

/* HTTP状态回调*/

static VMINT vm_http_get_ssi_info(const http_session_t * session, session_item_info ** sii, VMINT * p_handle)
{
    //session_item_info * sii = NULL;
    
    if (NULL == session)
        return 0;
    
    *sii = vm_get_item_info(session->s, 1);
    if (NULL == sii)
        return 0;

    if (0 > (*p_handle = vm_res_get_process_handle(VM_RES_TYPE_HTTP_HANDLE, (*sii)->http_handle)))
    {
        return 0;
    }
    
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  NOTIFY_HTTP_STATE
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hook                            [?]         
 *  state                           [IN]        
 *  param                           [IN]        
 *  session                         [?]         
 *  sessionInStateNotifyFunc        [IN]        
 *  callback_flag                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void NOTIFY_HTTP_STATE(
                void *hook,
                int state,
                int param,
                http_session_t *session,
                int sessionInStateNotifyFunc,
                int callback_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    VMINT p_handle = -1;
    session_item_info * sii = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
    if (0 == vm_http_get_ssi_info(session, &sii, &p_handle))
    {
        return;
    }
    #endif
    
    if (hook != NULL)
    {
        if (sessionInStateNotifyFunc)
        {
            //callback_flag++;
            sii->callback_lock++;
            PMNG_WRAP_CALLBACK(p_handle, 
                ((yesSessionInStateNotifyFunc)(hook))(state, param, session));
            //callback_flag--;
            sii->callback_lock--;
        }
        else
        {
            //callback_flag++;
            sii->callback_lock++;
            PMNG_WRAP_CALLBACK(p_handle, 
                ((noSessionInStateNotifyFunc)(hook))(state, param));
            //callback_flag--;
            sii->callback_lock--;
         }
    }
}

/* HTTP结果回调*/


/*****************************************************************************
 * FUNCTION
 *  NOTIFY_HTTP_RESULT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hook                [IN]        
 *  state               [IN]        
 *  session_ptr         [?]         
 *  callback_flag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void NOTIFY_HTTP_RESULT(ResultNotifyFunc hook, int state, http_session_t* session_ptr, int callback_flag) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    VMINT p_handle = -1;
    session_item_info * sii = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
    if (0 == vm_http_get_ssi_info(session_ptr, &sii, &p_handle))
    {
        return;
    }
    #endif
    
    if (hook != NULL)
    {
        //callback_flag++;
        sii->callback_lock++;
        PMNG_WRAP_CALLBACK(p_handle, 
            hook(state, session_ptr));
        //callback_flag--;
        sii->callback_lock--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_write_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_info_ptr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_http_write_data(session_item_info* item_info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * what is doing when back from block?
     * 
     * 0. send all data(maybe only http head) in reqbuf
     * 1. send data in chunk
     * get http handle via session info
     * item_info_ptr->sender(handle, NULL);
     * 2. send data with customize size
     * send req_body
     * 3. send data directly
     * nothing
     * 
     * check customize req_body 
     * == NULL
     * origin flow
     * != NULL
     * new flow
*/
    VMINT ret = 0;
    http_session_t * sii_tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_869 , current_handle);
    
    if (item_info_ptr)
    {
        // lf modified
        if (NULL == item_info_ptr->http_session_ptr)
        {
            return OP_ERROR;
        }
        sii_tmp = item_info_ptr->http_session_ptr;
        NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_SENDING, 
                (sii_tmp->nreqbuf > 0 ? 
                (item_info_ptr->sent * 100 / (unsigned int)(sii_tmp->nreqbuf+item_info_ptr->req_body_length)) : 0), 
                sii_tmp, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
        if (item_info_ptr->user_terminate_flag)
            return OP_USER_TERMINATE;

        while ((int)item_info_ptr->sent < sii_tmp->nreqbuf && 
            (ret = vm_tcp_write(item_info_ptr->socket_handle, 
            sii_tmp->reqbuf + item_info_ptr->sent, 
            sii_tmp->nreqbuf - item_info_ptr->sent)) > 0)
        {
            item_info_ptr->sent += ret;
            NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_SENDING, 
                (sii_tmp->nreqbuf > 0 ? 
                (item_info_ptr->sent * 100 / (unsigned int)(sii_tmp->nreqbuf+item_info_ptr->req_body_length)) : 0),
                sii_tmp, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
            if (item_info_ptr->user_terminate_flag)
                return OP_USER_TERMINATE;
        }

        if ((int)item_info_ptr->sent < sii_tmp->nreqbuf)
        {
            /* 还没有写完所有的http request 。结果是小于0或等于0。 */
            if (ret < 0)
                return OP_ERROR;
            else 
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_901 , item_info_ptr->socket_handle);
                return OP_BLOCK;
            }
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_905 , sii_tmp->nreqbuf, item_info_ptr->sent);
        
        /* 有不定长请求报文体需要发送 */
        if (item_info_ptr->req_body != NULL && item_info_ptr->req_body_length > 0)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_910 , item_info_ptr->req_body_length);
            //vm_log_debug_long((char*)item_info_ptr->req_body, item_info_ptr->req_body_length);
            
            /* 
            已发送的HTTP 报文总长度 
            item_info_ptr->sent	
            应小于
            需要发送的请求报文头长度与报文体长度之和
            item_info_ptr->http_session_ptr->nreqbuf + item_info_ptr->req_body_length
            */
            while ((int)item_info_ptr->sent < sii_tmp->nreqbuf+item_info_ptr->req_body_length && 
                (ret = vm_tcp_write(item_info_ptr->socket_handle, 
                item_info_ptr->req_body + item_info_ptr->sent-sii_tmp->nreqbuf, 
                sii_tmp->nreqbuf+item_info_ptr->req_body_length - item_info_ptr->sent)) > 0)
            {
                item_info_ptr->sent += ret;
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_926 , ret, item_info_ptr->sent);
                
                NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_SENDING, 
                    (sii_tmp->nreqbuf > 0 ? 
                    (item_info_ptr->sent * 100 / (unsigned int)(sii_tmp->nreqbuf+item_info_ptr->req_body_length)) : 0),
                    sii_tmp, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
                if (item_info_ptr->user_terminate_flag)
                    return OP_USER_TERMINATE;
            }

            if ((int)item_info_ptr->sent < sii_tmp->nreqbuf+item_info_ptr->req_body_length)
            {
                /* 还没有写完所有的http request 。结果是小于0或等于0。 */
                if (ret < 0)
                    return OP_ERROR;
                else 
                {
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_943 , item_info_ptr->socket_handle);
                    return OP_BLOCK;
                }
            }
        }
        
        if (item_info_ptr->sender != NULL)
        {/* 调用应用端回调函数发送请求体数据 */
        
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_952 , 
                item_info_ptr->chunk_buffer_sent, item_info_ptr->chunk_buffer_length);
            //vm_log_debug_long((char*)item_info_ptr->chunk_buffer_ptr, (int)item_info_ptr->chunk_buffer_length);

            /* 
             * 前一个chunk数据块尚未发送成功，继续发送直至完成。
             */
            ret = vm_http_send_data_int(item_info_ptr);
            if (0 > ret)
            {
                return OP_ERROR;
            }
            else if (0 == ret)
            {
                return OP_BLOCK;
            }

            
            if (!item_info_ptr->req_eof)
            {/* 应用的请求数据尚未发送完成 */
            
                /* 
                 * 调用应用端数据上传函数 
                 * 直接发送时，返回发送数据的总大小；>0
                 * chunk编码发送时，返回最后一块数据编码后的chunk块大小；>0
                 * 阻塞或链路异常时，返回错误代码。
                 */
                ret = ((http_data_sender)item_info_ptr->sender)(
                    item_info_ptr->http_handle, (void*)sii_tmp); 

                if (ret > 0)
                {
                    /* 非chunk编码时，直接返回成功 */
                    if (item_info_ptr->req_body_length > 0)
                        return OP_COMPLETE;
                
                    /* 应用的请求数据以chunk编码方式发送完成 */
                    item_info_ptr->req_eof = TRUE;
                    
                    /* 
                     * 发送chunk编码的结束符CRLF
                     */
                    memset(item_info_ptr->chunk_buffer_ptr, 0, HTTP_REQUEST_BUFSIZE);
                    memcpy(item_info_ptr->chunk_buffer_ptr, CRLF, CRLF_LEN);
                    item_info_ptr->chunk_buffer_length = CRLF_LEN;
                    item_info_ptr->chunk_buffer_sent = 0;
            
                    ret = vm_http_send_data_int(item_info_ptr);
                    if (0 > ret)
                    {
                        return OP_ERROR;
                    }
                    else if (0 == ret)
                    {
                        return OP_BLOCK;
                    }

                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1030 , 
                        item_info_ptr->chunk_buffer_sent, item_info_ptr->chunk_buffer_length);
                    //vm_log_debug_long((char*)item_info_ptr->chunk_buffer_ptr, (int)item_info_ptr->chunk_buffer_length);

                    /* 请求体发送完成，释放chunk_buffer_ptr内存 */
                    if (item_info_ptr->chunk_buffer_ptr)
                    {
                        vm_free(item_info_ptr->chunk_buffer_ptr);
                        item_info_ptr->chunk_buffer_ptr = NULL;
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1039 );
                    }
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1042 , item_info_ptr->socket_handle);
                    return OP_COMPLETE;
                }
                else if (ret == 0)
                {
                    MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_1047 , item_info_ptr->socket_handle);
                    return OP_BLOCK;
                }
                else
                {
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1052 , item_info_ptr->socket_handle, ret);
                    return OP_ERROR;
                }
            }
        }
        
    }

    return OP_COMPLETE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_readline_from_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer          [?]         
 *  buffer_size     [IN]        
 *  length_ptr      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static VMUINT8 vm_readline_from_buffer(VMUINT8* buffer, VMUINT buffer_size, VMUINT* length_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* ptr = (VMUINT8*)strstr((char*)buffer, CRLF);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ptr)
        return 1;

    if (buffer == ptr)
        *length_ptr = 0;
    else
        *length_ptr = ptr - buffer;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_moveout_line_from_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer          [?]         
 *  buffer_size     [IN]        
 *  data_length     [?]         
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_moveout_line_from_buffer(VMUINT8 *buffer, VMUINT buffer_size, VMUINT *data_length, VMUINT length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const unsigned int real_length = length + CRLF_LEN;
    unsigned int i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*data_length) >= real_length)
    {
        while (i + real_length < (*data_length))
        {
            *(buffer + i) = *(buffer + i + real_length);
            i++;
        }

        if (buffer_size >= (*data_length))
            memset(buffer + ((*data_length) - real_length), 0, buffer_size - ((*data_length) - real_length));

        *data_length = (*data_length) - real_length;
    }
    else
        memset(buffer, 0, *data_length);
    
}

/**
 * move data in buffer
 *
 * @param[in/out]		to, start address that data is moving to
 * @param[in/out]		from, start address that data is moving from
 * @param[in]			len, length of data to move
 *
 * @return	
 */
/*FLOW:
static int _vm_move_buffer_data(unsigned char* to, unsigned char* from, int len)
{
----------------------------------------------
|		<-	 ++++++++++++++++++++++
----------------------------------------------
++++++++++++++++++++++	->		|
----------------------------------------------
to, from would not be modified.
TODO: what if extends the buffer's size?

    unsigned int ret = 0;
    unsigned char* p_to = NULL;	
    unsigned char* p_from = NULL;	
    _vm_http_log("{HTTP MODULE} _vm_move_buffer_data - to:%p, from:%p, len:%d", to, from, len);
    if (to < from)
    {
        p_to = to;
        p_from  = from;
        while (len-- > 0)
        {
            *p_to++ = *p_from++;
        }
        ret = from-to;
        memset(p_to, 0, ret);
        _vm_http_log("{HTTP MODULE} _vm_move_buffer_data - p_to:%p, p_from:%p, ret:%d", p_to, p_from, ret);
    }
    else
    {
        p_to = to + len;
        p_from  = from + len;
        while (len-- > 0)
        {
            *p_to-- = *p_from--;
        }
        ret = to-from;
        memset(from, 0, ret);
        _vm_http_log("{HTTP MODULE} _vm_move_buffer_data - p_to:%p, p_from:%p, ret:%d", p_to, p_from, ret);
    }
    _vm_http_log("{HTTP MODULE} _vm_move_buffer_data - to:%p, from:%p, len:%d", to, from, len);
    return ret;
}
*/


/*****************************************************************************
 * FUNCTION
 *  _vm_call_receiver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_info_ptr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static int _vm_call_receiver(session_item_info* item_info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 调用应用端数据下载函数 */
    int ret = ((http_data_receiver)item_info_ptr->receiver)(item_info_ptr->http_handle, 
            (void*)item_info_ptr->http_session_ptr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret > 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1218 , item_info_ptr->socket_handle);
        return OP_COMPLETE;
    }
    else if (ret == 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1223 , item_info_ptr->socket_handle);
        return OP_BLOCK;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1228 , item_info_ptr->socket_handle);
        return OP_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_read_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_info_ptr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_http_read_data(session_item_info* item_info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * 1. reveive data in buffer with buffer size
     * 2. get head info from buffer
     * 3. switch receive type
     * 1. directly
     * 2. chunk
     * item_info_ptr->receiver != NULL
*/

    VMINT ret = 0;
    VMUINT line_size = 0;
    VMUINT8* ptr = NULL;
    http_response_buffer_t * res_buf_tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* const unsigned int CRLF_LEN = CRLF_LEN; */

    if (item_info_ptr && !item_info_ptr->receive_completed)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1270 , item_info_ptr->buffer->buffer, item_info_ptr->buffer->buffer+RESPONSE_BUFFER_SIZE, item_info_ptr->buffer->receive_type);
        
        if (!item_info_ptr->buffer)
            return OP_ERROR;
        res_buf_tmp = item_info_ptr->buffer;
        switch (res_buf_tmp->receive_type)
        { 
        case state_line:
RECEIVE_STATE_LINE:
            if (RESPONSE_BUFFER_SIZE <= res_buf_tmp->receive_num)
                return OP_ERROR;

            NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_STATUS, 0, 
                item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
            if (item_info_ptr->user_terminate_flag)
                return OP_USER_TERMINATE;
            
            ret = vm_tcp_read(item_info_ptr->socket_handle, 
                res_buf_tmp->buffer + res_buf_tmp->receive_num, 
                RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num);
            if (ret > 0)
            {
                res_buf_tmp->receive_num += ret;
                
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1294 );
                //vm_log_debug_long((char*)item_info_ptr->buffer->buffer, (int)item_info_ptr->buffer->receive_num);
                
                if (vm_readline_from_buffer(res_buf_tmp->buffer, 
                    res_buf_tmp->receive_num, &line_size) == 0)
                {/* 从buffer中读取一行数据，取得line_size */
                
                    /* 
                      * HTTP状态行已经读取完毕。
                      */
                    if (line_size > 0 && res_buf_tmp->receive_num >= line_size)
                    {/* line_size有效 */
                    
                        if ((ptr = (VMUINT8*)strchr((char *)res_buf_tmp->buffer, SPACE)) != NULL)
                        {/* 取buffer中的空格符 */
                        
                            char* res_ptr = NULL;
                            VMUINT8* ptr_state_end = (VMUINT8*)strchr((char*)(ptr + 1), SPACE);
                            
                            /* 
                              * 如果没有取HTTP 状态行里的第二个SPACE，
                              * 那么直接返回读错误。 
                              */
                            if (!ptr_state_end ||ptr + 1 == ptr_state_end 
                                || ptr_state_end >= res_buf_tmp->buffer + line_size)
                                return OP_ERROR;

                            res_ptr = (char*)vm_calloc(ptr_state_end - ptr);
                            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1322 , res_ptr);
                            if (res_ptr)
                            {
                                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1325 , res_ptr, res_ptr+(int)(ptr_state_end - ptr));
                            
                                /* 计算HTTP响应状态码 */
                                //memset(res_ptr, 0, ptr_state_end - ptr);
                                memcpy(res_ptr, ptr + 1, (ptr_state_end - ptr) - 1);
                                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1330 , res_ptr, res_ptr+(ptr_state_end - ptr) - 1);

                                item_info_ptr->http_session_ptr->res_code = atoi(res_ptr);
                                vm_free(res_ptr); 
                                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1334 , item_info_ptr->http_session_ptr->res_code);
                                if (item_info_ptr->http_session_ptr->res_code != 0)
                                {
                                    vm_moveout_line_from_buffer(res_buf_tmp->buffer, 
                                        RESPONSE_BUFFER_SIZE, &(res_buf_tmp->receive_num), line_size);
                                    //item_info_ptr->buffer->receive_num -= (line_size + CRLF_LEN);
                                    res_buf_tmp->receive_type = head;
                                    goto RECEIVE_HEAD;
                                }
                            }
                        }
                    }

                    return OP_ERROR;
                }
                else
                {
                    /* 
                      * 还没有收完 状态行。
                      */
                    goto RECEIVE_STATE_LINE;
                }
            }
            else if (ret < 0)
                return OP_ERROR;
            else
            {
                return OP_BLOCK;
            }
            //break;
        case head:
RECEIVE_HEAD:
            NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_HEADS, 0,
                item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
            if (item_info_ptr->user_terminate_flag)
                return OP_USER_TERMINATE;
            
            while (res_buf_tmp->receive_num > 0
                && vm_readline_from_buffer(res_buf_tmp->buffer, 
                res_buf_tmp->receive_num, &line_size) == 0)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1375 , res_buf_tmp->receive_num, line_size, item_info_ptr->http_session_ptr->nresbuf);
                //vm_log_debug_long((char*)item_info_ptr->buffer->buffer, (int)item_info_ptr->buffer->receive_num);
                if (line_size > 0)
                {
                    /*
                     * 读到了一行响应头。
                     */
                    if ((item_info_ptr->http_session_ptr->nresbuf + line_size + CRLF_LEN) <=
                        HTTP_RESPONSE_HEADSIZE)
                    {
                        memcpy(item_info_ptr->http_session_ptr->resbuf + item_info_ptr->http_session_ptr->nresbuf, 
                            res_buf_tmp->buffer, line_size + CRLF_LEN);
                        item_info_ptr->http_session_ptr->nresbuf += (line_size + CRLF_LEN);

                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1389 , item_info_ptr->http_session_ptr->nresbuf, 
                            item_info_ptr->http_session_ptr->resbuf, item_info_ptr->http_session_ptr->resbuf+HTTP_RESPONSE_HEADSIZE, item_info_ptr->http_session_ptr->resbuf+line_size + CRLF_LEN);
                        //vm_log_debug_long((char*)item_info_ptr->http_session_ptr->resbuf, (int)item_info_ptr->http_session_ptr->nresbuf);
                        
                    }
                    vm_moveout_line_from_buffer(res_buf_tmp->buffer, 
                        RESPONSE_BUFFER_SIZE, &(res_buf_tmp->receive_num), line_size);
                }
                else
                {
                    /*
                      * 读到了一行空行，标志着响应体的开始。
                      */
                    char head_value[55];
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1403 , head_value, head_value+sizeof(head_value));

                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1405 , res_buf_tmp->receive_num, line_size, item_info_ptr->http_session_ptr->nresbuf);
                    //vm_log_debug_long((char*)item_info_ptr->buffer->buffer, (int)item_info_ptr->buffer->receive_num);
                
                    /* 将空行从buffer 中移除 */
                    vm_moveout_line_from_buffer(res_buf_tmp->buffer, 
                        RESPONSE_BUFFER_SIZE, &(res_buf_tmp->receive_num), line_size);
                    
                    item_info_ptr->http_session_ptr->nresbody = 0;
                    item_info_ptr->http_session_ptr->resbody = NULL;
                    if (get_http_head(item_info_ptr->http_session_ptr, 
                        "Content-Length", head_value) == 0)
                    {
                        item_info_ptr->http_session_ptr->nresbody = atoi(head_value);
                        res_buf_tmp->receive_type = fixed_body;

                        if (item_info_ptr->http_session_ptr->nresbody > 0)
                        {
                            /* 分块下载HTTP 请求报文体 */
                            if (item_info_ptr->receiver != NULL)
                            {
                                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1425 , res_buf_tmp->receive_type);

                                return _vm_call_receiver(item_info_ptr);
                                    
                                /* 调用应用端数据下载函数 
                                ret = ((http_data_receiver)item_info_ptr->receiver)(
                                    item_info_ptr->http_handle, (void*)item_info_ptr->http_session_ptr);

                                if (ret > 0)
                                {
                                    _vm_http_log("{HTTP MODULE} http[%d] (Content-Length) - receiver complete.", 
                                        item_info_ptr->socket_handle);
                                    return OP_COMPLETE;
                                }
                                else if (ret == 0)
                                {
                                    _vm_http_log("{HTTP MODULE} http[%d] (Content-Length) - receiver wait data to receive.", 
                                        item_info_ptr->socket_handle);
                                    return OP_BLOCK;
                                }
                                else
                                {
                                    vm_log_error("{HTTP MODULE} http[%d] (Content-Length) - receiver error.", 
                                        item_info_ptr->socket_handle);
                                    return OP_ERROR;
                                }*/
                            }

                            if ((item_info_ptr->http_session_ptr->resbody = vm_malloc(item_info_ptr->http_session_ptr->nresbody)) == NULL)
                                return OP_ERROR;
                            //else
                                //memset(item_info_ptr->http_session_ptr->resbody, 0, item_info_ptr->http_session_ptr->nresbody);
                            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1457 , item_info_ptr->http_session_ptr->resbody, item_info_ptr->http_session_ptr->resbody+item_info_ptr->http_session_ptr->nresbody, item_info_ptr->http_session_ptr->resbody, item_info_ptr->http_session_ptr->nresbody);
                        }
                        else if (item_info_ptr->http_session_ptr->nresbody == 0)
                        {
                        /* 如果响应报文体长度为0, 返回成功消息 */
                            return OP_COMPLETE;
                        }
                        else	// if (item_info_ptr->http_session_ptr->nresbody < 0)
                        {
                            return OP_ERROR;
                        }
                            
                        goto FIX_BODY;
                    }
                    else if (get_http_head(item_info_ptr->http_session_ptr, 
                        "Transfer-Encoding", head_value) == 0) 
                    {
                        if (strcmp("chunked", head_value) == 0 || strcmp("Chunked", head_value) == 0)
                        {
                            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1476 );
                            res_buf_tmp->receive_type = chunk_size;

                            /* 分块下载HTTP 请求报文体 */
                            if (item_info_ptr->receiver != NULL)
                            {
                                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1482 , res_buf_tmp->receive_type);
                                
                                return _vm_call_receiver(item_info_ptr);
                                
                                /* 调用应用端数据下载函数 
                                ret = ((http_data_receiver)item_info_ptr->receiver)(
                                    item_info_ptr->http_handle, (void*)item_info_ptr->http_session_ptr);
    
                                if (ret > 0)
                                {
                                    vm_log_info("{HTTP MODULE}http[%d] (chunked) - receiver complete.", 
                                        item_info_ptr->socket_handle);
                                    return OP_COMPLETE;
                                }
                                else if (ret == 0)
                                {
                                    vm_log_warn("{HTTP MODULE}http[%d] (chunked) - receiver wait data to receive.", 
                                        item_info_ptr->socket_handle);
                                    return OP_BLOCK;
                                }
                                else
                                {
                                    vm_log_error("{HTTP MODULE}http[%d] (chunked) - receiver error.", 
                                        item_info_ptr->socket_handle);
                                    return OP_ERROR;
                                }*/
                            }

                            goto CHUNK_SIZE;
                        }
                    }
                    else		/* 一直读至流的结束 */
                    {
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1515 );
                        res_buf_tmp->receive_type = read_eof;
                        goto READ_EOF;
                    }

                    return OP_ERROR;
                }
            }

            if ((ret = vm_tcp_read(item_info_ptr->socket_handle, 
                res_buf_tmp->buffer + res_buf_tmp->receive_num, 
                RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num)) > 0)
            {
                res_buf_tmp->receive_num += ret;
                
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1530 );
                //vm_log_debug_long((char*)item_info_ptr->buffer->buffer, (int)item_info_ptr->buffer->receive_num);
                
                goto RECEIVE_HEAD;
            }
            else if (ret == 0)
                return OP_BLOCK;
            else
                return OP_ERROR;
            
            //break;
        case fixed_body:
FIX_BODY:

            /*FLOW:
            0. read http head, clear buffer
            分块下载HTTP 请求报文体 */
            if (item_info_ptr->receiver != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1549 , res_buf_tmp->receive_type);
                
                return _vm_call_receiver(item_info_ptr);
                
                /* 调用应用端数据下载函数 
                ret = ((http_data_receiver)item_info_ptr->receiver)(
                    item_info_ptr->http_handle, (void*)item_info_ptr->http_session_ptr);

                if (ret > 0)
                {
                    vm_log_info("{HTTP MODULE} http[%d] (Content-Length) - receiver complete.", 
                        item_info_ptr->socket_handle);
                    return OP_COMPLETE;
                }
                else if (ret == 0)
                {
                    vm_log_warn("{HTTP MODULE} http[%d] (Content-Length) - receiver wait data to receive.", 
                        item_info_ptr->socket_handle);
                    return OP_BLOCK;
                }
                else
                {
                    vm_log_error("{HTTP MODULE} http[%d] (Content-Length) - receiver error.", 
                        item_info_ptr->socket_handle);
                    return OP_ERROR;
                }*/
            }

            /*
             * 先读出缓冲里剩余的字节。
             */
            if (res_buf_tmp->receive_num > 0)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1582 , res_buf_tmp->receive_num, item_info_ptr->http_session_ptr->nresbody, item_info_ptr->read);
                //vm_log_debug_long((char*)item_info_ptr->buffer->buffer, (int)item_info_ptr->buffer->receive_num);
                
                if (item_info_ptr->http_session_ptr->resbody != NULL && 
                    (int)res_buf_tmp->receive_num <= item_info_ptr->http_session_ptr->nresbody)
                {
                    memcpy(item_info_ptr->http_session_ptr->resbody+ item_info_ptr->read, 
                        res_buf_tmp->buffer, res_buf_tmp->receive_num);
                    memset(res_buf_tmp->buffer, 0, RESPONSE_BUFFER_SIZE);
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1592 , 
                        item_info_ptr->http_session_ptr->nresbody, res_buf_tmp->receive_num);
                    //vm_log_debug_long((char*)item_info_ptr->http_session_ptr->resbody, (int)item_info_ptr->http_session_ptr->nresbody);

                    /*
                      * 如果加上缓冲里的字节数已经收完了所有的响应，
                      * 那么返回OP_COMPLETE。
                      */
                    if ((int)res_buf_tmp->receive_num == item_info_ptr->http_session_ptr->nresbody)
                    {
                        item_info_ptr->read = item_info_ptr->http_session_ptr->nresbody;
                        res_buf_tmp->receive_num = 0;
                        NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 100, 
                            item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
                        if (item_info_ptr->user_terminate_flag)
                            return OP_USER_TERMINATE;

                        // lf modified
                        //MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1609 , 
                            //item_info_ptr->http_session_ptr->nresbody, item_info_ptr->buffer->receive_num);
                        //vm_log_debug_long((char*)item_info_ptr->http_session_ptr->resbody, (int)item_info_ptr->http_session_ptr->nresbody);
                    
                        return OP_COMPLETE;
                    }
                    item_info_ptr->read = res_buf_tmp->receive_num;
                    res_buf_tmp->receive_num = 0;
                }
                else
                    return OP_ERROR;
            }

            /*
              * 如果响应体的长度为0，那么则也返回OP_COMPLETE。
              */
            if (item_info_ptr->http_session_ptr->nresbody == 0)
            {
                NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 100, 
                    item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
                if (item_info_ptr->user_terminate_flag)
                    return OP_USER_TERMINATE;
                return OP_COMPLETE;
            }

            /*
              * 接着收剩余的字节。
              */
            NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 
                (item_info_ptr->read * 100 / item_info_ptr->http_session_ptr->nresbody), 
                item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
            if (item_info_ptr->user_terminate_flag)
                return OP_USER_TERMINATE;
            while (item_info_ptr->http_session_ptr->resbody != NULL 
                && (ret = vm_tcp_read(item_info_ptr->socket_handle, 
                item_info_ptr->http_session_ptr->resbody + item_info_ptr->read, 
                item_info_ptr->http_session_ptr->nresbody - item_info_ptr->read)) > 0)
            {
                item_info_ptr->read += ret;

                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1649 , item_info_ptr->http_session_ptr->nresbody, item_info_ptr->read);
                //vm_log_debug_long((char*)item_info_ptr->http_session_ptr->resbody, (int)item_info_ptr->http_session_ptr->nresbody);
                
                NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 
                    (item_info_ptr->read  * 100 / item_info_ptr->http_session_ptr->nresbody),
                    item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
                if (item_info_ptr->user_terminate_flag)
                    return OP_USER_TERMINATE;
                if ((int)item_info_ptr->read >= item_info_ptr->http_session_ptr->nresbody)
                    return OP_COMPLETE;
                //else
                //	return OP_BLOCK; // 这里一定要保证tcp还会有VM_TCP_EVT_CAN_READ消息调过来。
                        
            }

            if (ret == 0)
                return OP_BLOCK;
            else
                return OP_ERROR;
            
            //break;
        case read_eof:
READ_EOF:
            if (item_info_ptr->receiver != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1674 , res_buf_tmp->receive_type);
                
                return _vm_call_receiver(item_info_ptr);
                
                /* 调用应用端数据下载函数 
                ret = ((http_data_receiver)item_info_ptr->receiver)(
                    item_info_ptr->http_handle, (void*)item_info_ptr->http_session_ptr);

                if (ret > 0)
                {
                    vm_log_info("{HTTP MODULE} http[%d] (Content-Length) - receiver complete.", 
                        item_info_ptr->socket_handle);
                    return OP_COMPLETE;
                }
                else if (ret == 0)
                {
                    vm_log_warn("{HTTP MODULE} http[%d] (Content-Length) - receiver wait data to receive.", 
                        item_info_ptr->socket_handle);
                    return OP_BLOCK;
                }
                else
                {
                    vm_log_error("{HTTP MODULE} http[%d] (Content-Length) - receiver error.", 
                        item_info_ptr->socket_handle);
                    return OP_ERROR;
                }*/
            }

            while (TRUE)
            {
                if (res_buf_tmp->receive_num == 0)
                {
                    if ((ret = vm_tcp_read(item_info_ptr->socket_handle, 
                        res_buf_tmp->buffer, RESPONSE_BUFFER_SIZE)) <= 0)
                    {
                        if (ret  == 0)
                            return OP_BLOCK;
                        else if (ret == VM_TCP_READ_EOF)
                        {
                            NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 
                                100, item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
                            if (item_info_ptr->user_terminate_flag)
                                return OP_USER_TERMINATE;
                            return OP_COMPLETE;
                        }
                        else
                            return OP_ERROR;
                    }
                    else
                        res_buf_tmp->receive_num = ret;
                }

                if (item_info_ptr->http_session_ptr->resbody == NULL)
                {
                    if ((item_info_ptr->http_session_ptr->resbody 
                        = vm_malloc(res_buf_tmp->receive_num)) == NULL)
                    {
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1731 );
                        return OP_ERROR;
                    }
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1734 , item_info_ptr->http_session_ptr->resbody);
                    memcpy(item_info_ptr->http_session_ptr->resbody, 
                        res_buf_tmp->buffer, res_buf_tmp->receive_num);
                    item_info_ptr->http_session_ptr->nresbody = res_buf_tmp->receive_num;

                    memset(res_buf_tmp->buffer, 0, RESPONSE_BUFFER_SIZE);
                    res_buf_tmp->receive_num = 0;
                }
                else
                {
                    if ((ptr = vm_realloc(item_info_ptr->http_session_ptr->resbody, 
                        item_info_ptr->http_session_ptr->nresbody + res_buf_tmp->receive_num))
                        == NULL)
                    {
                        item_info_ptr->http_session_ptr->resbody = NULL;
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1749 );
                        return OP_ERROR;
                    }

                    item_info_ptr->http_session_ptr->resbody = ptr;
                    memcpy(item_info_ptr->http_session_ptr->resbody 
                        + item_info_ptr->http_session_ptr->nresbody, res_buf_tmp->buffer, 
                        res_buf_tmp->receive_num);
                    item_info_ptr->http_session_ptr->nresbody += res_buf_tmp->receive_num;

                    memset(res_buf_tmp->buffer, 0, RESPONSE_BUFFER_SIZE);
                    res_buf_tmp->receive_num = 0;
                }
            }

            //break;
        case chunk_size:
CHUNK_SIZE:		

            /* 分块下载HTTP 请求报文体 */
            if (item_info_ptr->receiver != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1771 , res_buf_tmp->receive_type);
                
                /* 调用应用端数据下载函数 */
                ret = ((http_data_receiver)item_info_ptr->receiver)(
                    item_info_ptr->http_handle, (void*)item_info_ptr->http_session_ptr);

                if (ret > 0)
                {
                    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMHTTP_1779 , item_info_ptr->socket_handle);
                    return OP_COMPLETE;
                }
                else if (ret == 0)
                {
                    MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_1784 , item_info_ptr->socket_handle);
                    return OP_BLOCK;
                }
                else
                {
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1789 , item_info_ptr->socket_handle);
                    return OP_ERROR;
                }
            }
    
            if (res_buf_tmp->receive_num > 0)
            {
                VMUINT8 *p1 = NULL, *p2 = NULL;
                VMUINT len = 0;

                /* 在buffer 中找第一个CRLF 符 */
                if ( (p1 = (VMUINT8*)strstr((char*)res_buf_tmp->buffer, CRLF)) != NULL)
                {
                    VMUINT8 size_str[9];
                    VMINT chunk_data_size = 0;

                    memset(size_str, 0, sizeof(size_str));
                    if ((p1 - res_buf_tmp->buffer) > (sizeof(size_str) - 1))
                    {
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1808 );
                        return OP_ERROR;
                    }

                    for (p2 = res_buf_tmp->buffer; p2 < p1; p2++)
                        *(size_str + (p2 -  res_buf_tmp->buffer)) = *p2;
                    
                    /* 计算chunk size  */
                    if (hex_cstring_to_oct(size_str, &chunk_data_size) != 0)
                    {
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1818 , size_str);
                        return OP_ERROR;
                    }
                    else
                    {
                        if (chunk_data_size >= 0)
                        {
                            /*
                             * 从buffer把chunk size和CRLF移出。
                             */
                            p2 = p1 + CRLF_LEN;
                            p1 = res_buf_tmp->buffer;
                            while (p2 < res_buf_tmp->buffer + RESPONSE_BUFFER_SIZE)
                                *p1++ = *p2++;
                            if (p1 < res_buf_tmp->buffer + RESPONSE_BUFFER_SIZE)
                                memset(p1, 0, (res_buf_tmp->buffer + RESPONSE_BUFFER_SIZE) - p1);
                            res_buf_tmp->receive_num -= (p2 -p1);
/*
                            item_info_ptr->buffer->receive_num -= 
                                _vm_move_buffer_data(p1, p2, item_info_ptr->buffer->receive_num);
*/
                            
                            /*
                             * 如果chunk size大于0，分配chunk data的空间，跳转
                             * 到相应逻辑。
                             */
                            res_buf_tmp->chunk_size = chunk_data_size;
                            if (res_buf_tmp->chunk_size == 0)
                            {
                                /* chunk size 为0, 说明为最后一个chunk */
                                res_buf_tmp->receive_type = chunk_trailer;
                                goto CHUNK_TRAILER;
                            }
                            else
                            {
                                if (item_info_ptr->http_session_ptr->resbody)
                                {
                                    if (item_info_ptr->http_session_ptr->nresbody + chunk_data_size > item_info_ptr->range_size)
                                    {
                                        VMUINT8* relloc_ptr = NULL;

                                        if ((relloc_ptr = (VMUINT8*)vm_realloc(item_info_ptr->http_session_ptr->resbody, 
                                            item_info_ptr->http_session_ptr->nresbody + chunk_data_size)) == NULL)
                                        {
                                            item_info_ptr->http_session_ptr->resbody = NULL;
                                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1863 , chunk_data_size);
                                            return OP_ERROR;
                                        }

                                        item_info_ptr->http_session_ptr->resbody = relloc_ptr;
                                    }
                                }
                                else
                                {
                                    if (item_info_ptr->range_size > 0)
                                    {
                                        if ((item_info_ptr->http_session_ptr->resbody = (VMUINT8*)vm_malloc(item_info_ptr->range_size)) == NULL)
                                        {
                                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1876 , chunk_data_size);
                                            return OP_ERROR;
                                        }
                                    }
                                    else
                                    {
                                        if ((item_info_ptr->http_session_ptr->resbody = (VMUINT8*)vm_malloc(chunk_data_size)) == NULL)
                                        {
                                             MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1884 , chunk_data_size);
                                            return OP_ERROR;
                                        }
                                    }
                                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1888 , item_info_ptr->http_session_ptr->resbody);
                                }

                                item_info_ptr->http_session_ptr->nresbody += chunk_data_size;
                                res_buf_tmp->receive_type = chunk_data;
                                goto CHUNK_DATA;
                            }
                        }
                        else
                            return OP_ERROR;
                    }
                }
                
                /*
                 *   如果有chunk-extension则从buffer里移除。
                 */
                while ((p1 = (VMUINT8*)strchr((char*)res_buf_tmp->buffer, ';')) != NULL)
                {
                    if (p1 >= res_buf_tmp->buffer + RESPONSE_BUFFER_SIZE)
                    {
                        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_1908 );
                        return OP_ERROR;
                    }
                
                    if ((p2 = (VMUINT8*)strchr((char*)p1 + 1, ';')) != NULL)
                    {
                        /*
                         * 去除一个chunk-extension。
                         */
                        while (p2 < (res_buf_tmp->buffer + res_buf_tmp->receive_num) 
                            && p2 < (res_buf_tmp->buffer + RESPONSE_BUFFER_SIZE))
                        {
                            *p1 = *p2;
                            
                            p1++;
                            p2++;
                        }
                        memset(res_buf_tmp->buffer + res_buf_tmp->receive_num 
                            - (p2 - p1), 0, (p2 - p1));
                        res_buf_tmp->receive_num -= (p2 - p1);
                        continue;
                    }
                    else
                    {
                        if (res_buf_tmp->receive_num >= RESPONSE_BUFFER_SIZE)
                        {
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_1934 );
                            return OP_ERROR;
                        }
                        
                        /*
                         * 开始收下一个chunk-extension或一个CRLF。
                         */
                        if ((len = vm_tcp_read(item_info_ptr->socket_handle, 
                            res_buf_tmp->buffer + res_buf_tmp->receive_num, 
                            RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num)) > 0)
                        {
                            res_buf_tmp->receive_num += len;
                            goto CHUNK_SIZE;
                        }
                        else if (len == 0)
                            return OP_BLOCK;
                        else
                            return OP_ERROR;
                    }
                }
                
                /*
                 * 如果在当前的buffer里没有CRLF或';'那么代码会走到这里。
                 */
                if (res_buf_tmp->receive_num >= RESPONSE_BUFFER_SIZE)
                    return OP_ERROR;
                if ((len = vm_tcp_read(item_info_ptr->socket_handle, 
                    res_buf_tmp->buffer + res_buf_tmp->receive_num, 
                    RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num)) > 0)
                {
                    res_buf_tmp->receive_num += len;
                    goto CHUNK_SIZE;
                }
                else if (len == 0)
                    return OP_BLOCK;
                else
                    return OP_ERROR;
            }
            else
            {
                int len = vm_tcp_read(item_info_ptr->socket_handle, 
                    res_buf_tmp->buffer, RESPONSE_BUFFER_SIZE);

                if (len > 0)
                {
                    res_buf_tmp->receive_num += len;
                    goto CHUNK_SIZE;
                }
                else if (len == 0)
                    return OP_BLOCK;
                else
                    return OP_ERROR;
            }
            
            //break;
        case chunk_data:
CHUNK_DATA:

            /* 分块下载HTTP 请求报文体 */
            if (item_info_ptr->receiver != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_1995 , res_buf_tmp->receive_type);
                
                return _vm_call_receiver(item_info_ptr);
                                    
                /* 调用应用端数据下载函数 
                ret = ((http_data_receiver)item_info_ptr->receiver)(
                    item_info_ptr->http_handle, (void*)item_info_ptr->http_session_ptr);

                if (ret > 0)
                {
                    vm_log_info("{HTTP MODULE}http[%d] (chunked) - receiver complete.", 
                        item_info_ptr->socket_handle);
                    return OP_COMPLETE;
                }
                else if (ret == 0)
                {
                    vm_log_warn("{HTTP MODULE}http[%d] (chunked) - receiver wait data to receive.", 
                        item_info_ptr->socket_handle);
                    return OP_BLOCK;
                }
                else
                {
                    vm_log_error("{HTTP MODULE}http[%d] (chunked) - receiver error.", 
                        item_info_ptr->socket_handle);
                    return OP_ERROR;
                }*/
            }
    
            NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 60, 
                item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
            if (item_info_ptr->user_terminate_flag)
                return OP_USER_TERMINATE;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2028 , res_buf_tmp->chunk_size);
                
            while (res_buf_tmp->chunk_size > 0)
            {
                /*
                  * buffer里还没有数据。
                  */
                if (res_buf_tmp->receive_num == 0)
                {
                    if ((ret = vm_tcp_read(item_info_ptr->socket_handle, 
                        res_buf_tmp->buffer, RESPONSE_BUFFER_SIZE)) > 0)
                    {
                        res_buf_tmp->receive_num += ret;
                        
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2042 , ret, res_buf_tmp->receive_num);
                        
                        goto CHUNK_DATA;
                    }
                    else if (ret == 0)
                    {
                        return OP_BLOCK;
                    }
                    else
                        return OP_ERROR;
                }

                /*
                  * 把chunk data拷贝到session 的resbody的字段。
                  */
                if (item_info_ptr->http_session_ptr->resbody 
                    && res_buf_tmp->chunk_size <= (item_info_ptr->http_session_ptr->nresbody - item_info_ptr->read))
                {
                    const unsigned int cpyLen = MIN(res_buf_tmp->receive_num, 
                        res_buf_tmp->chunk_size);
                    unsigned int i = 0;
                    
                    memcpy(item_info_ptr->http_session_ptr->resbody + item_info_ptr->read, 
                        res_buf_tmp->buffer, cpyLen);
                    
                    /* 从buffer中移除已保存的chunk data */
                    item_info_ptr->read += cpyLen;							// 修改已经在resbody已经读入的数据。
                    res_buf_tmp->chunk_size -= cpyLen;				// 减去还要收的chunk size 的大小。
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2071 , 
                        item_info_ptr->read, cpyLen, res_buf_tmp->chunk_size);
                    for (i = 0; i < (res_buf_tmp->receive_num - cpyLen); i++)
                        *(res_buf_tmp->buffer  + i) = *(res_buf_tmp->buffer  + i + cpyLen);
                    memset(res_buf_tmp->buffer + i, 0, cpyLen);
                    res_buf_tmp->receive_num -= cpyLen;				// 修改buffer里已经读入的。
/*
                    item_info_ptr->buffer->receive_num -= _vm_move_buffer_data(item_info_ptr->buffer->buffer, 
                        item_info_ptr->buffer->buffer + cpyLen, item_info_ptr->buffer->receive_num);
*/ 

                }
                else
                {
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2085 );
                    return OP_ERROR;
                }
                
            } 	
            
            if ((ptr = (VMUINT8*)strstr((char*)res_buf_tmp->buffer, CRLF)) != NULL)
            {
                /*
                 * CRLF应该在buffer里的首地址位置上，从buffer里移出。
                 */
                if (res_buf_tmp->buffer == ptr)	
                {
                    unsigned int i = 0;
                    const int move_size = CRLF_LEN;
                    for (i = 0; i < (res_buf_tmp->receive_num - move_size); i++)
                        *(res_buf_tmp->buffer + i) = *(res_buf_tmp->buffer + i + move_size);
                    res_buf_tmp->receive_num -= move_size;
                    memset(res_buf_tmp->buffer + res_buf_tmp->receive_num, 
                        0, RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num);
/*
                    item_info_ptr->buffer->receive_num -= _vm_move_buffer_data(item_info_ptr->buffer->buffer, 
                        item_info_ptr->buffer->buffer + move_size, item_info_ptr->buffer->receive_num);
*/


                    res_buf_tmp->receive_type = chunk_size;

                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2113 , 
                        move_size, res_buf_tmp->receive_num);
                    
                    goto CHUNK_SIZE;
                }
                else
                {
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2120 );
                    return OP_ERROR;
                }
            }
            else
            {
                if (res_buf_tmp->receive_num >= CRLF_LEN)
                {
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2128 );
                    return OP_ERROR;
                }
                else
                {					
                    if ((ret = vm_tcp_read(item_info_ptr->socket_handle, 
                        res_buf_tmp->buffer + res_buf_tmp->receive_num, 
                        RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num)) > 0)
                    {
                        res_buf_tmp->receive_num += ret;
                        
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2139 , 
                            ret, res_buf_tmp->receive_num);
                        
                        goto CHUNK_DATA;
                    }
                    else if (ret == 0)
                        return OP_BLOCK;
                    else 
                        return OP_ERROR;
                }
            }
            
            //break;
        case chunk_trailer:
CHUNK_TRAILER:
            if (res_buf_tmp->receive_num > 0)
            {
                VMUINT8* p2 = NULL, *p1 = res_buf_tmp->buffer;
                
                while ((p2 = (VMUINT8*)strstr((char*)p1, CRLF)) != NULL)
                {

                    if (p2 == p1)
                    {
                        /*
                         * 只可能发生在buffer的开头就是一个CRLF。
                         */
                        NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 100, 
                            item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
                        if (item_info_ptr->user_terminate_flag)
                            return OP_USER_TERMINATE;
                        return OP_COMPLETE;
                    }
                    else if ((unsigned int)(p2 - p1) == CRLF_LEN)
                    {
                        /*
                         * 读完了所有的entity head并且读到一个chunk的结束符。
                         */
                        NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 100, 
                            item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
                        if (item_info_ptr->user_terminate_flag)
                            return OP_USER_TERMINATE;
                        return OP_COMPLETE;	
                    }
                    else
                    {
                        /*
                         * 把entity head加到http_session_ptr所指向的resbuf里。
                         */
                        if (p2 - p1 <= (HTTP_RESPONSE_HEADSIZE 
                            - item_info_ptr->http_session_ptr->nresbuf))
                        {
                            memcpy(item_info_ptr->http_session_ptr->resbuf + item_info_ptr->http_session_ptr->nresbuf, 
                                p1 + CRLF_LEN, p2 - p1);
                            item_info_ptr->http_session_ptr->nresbuf += (p2 - p1);
                        }
                        else
                        {	
                            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_2197 );
                        }	
                        p1 = p2;
                        p2 += CRLF_LEN;
                    }	
                }
                
                if (p1 > res_buf_tmp->buffer)
                {
                    for (p2 = p1 + CRLF_LEN, p1 = res_buf_tmp->buffer; 
                        p2 < res_buf_tmp->buffer + res_buf_tmp->receive_num; 
                        p1++, p2++)
                        *p1 = *p2;
/*
                    item_info_ptr->buffer->receive_num -= _vm_move_buffer_data(p1, p1 + CRLF_LEN, 
                        item_info_ptr->buffer->receive_num);
*/

                }	

                if (res_buf_tmp->receive_num >= RESPONSE_BUFFER_SIZE)
                    return OP_ERROR;
                else
                {
                    if ((ret = vm_tcp_read(item_info_ptr->socket_handle, 
                        res_buf_tmp->buffer + res_buf_tmp->receive_num, 
                        RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num)) > 0)
                    {
                        res_buf_tmp->receive_num += ret;
                        goto CHUNK_TRAILER;
                    }
                    else if (ret == 0)
                        return OP_BLOCK;
                    else
                        return OP_ERROR;
                }
            }
            else
            {
                if ((ret = vm_tcp_read(item_info_ptr->socket_handle, 
                    res_buf_tmp + res_buf_tmp->receive_num, 
                    RESPONSE_BUFFER_SIZE - res_buf_tmp->receive_num)) > 0)
                {
                    res_buf_tmp->receive_num += ret;
                    goto CHUNK_TRAILER;
                }
                else if (ret == 0)
                    return OP_BLOCK;
                else
                    return OP_ERROR;
            }	
            //break;
        default:
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_2250 );
            return OP_ERROR;
        }		
    }

    NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_RECV_BODY, 100, 
        item_info_ptr->http_session_ptr, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);
    if (item_info_ptr->user_terminate_flag)
        return OP_USER_TERMINATE;
    return OP_COMPLETE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_tcp_module_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_tcp_module_hook(VMINT handle, VMINT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    session_item_info* item_info_ptr;
    
    http_session_t * ssi_tmp;
    //VMINT ret = OP_COMPLETE;
    VMINT res, bcall = 1;
#ifdef MRE_ENABLE_HTTP_DEBUG
    int rs_ms = 0, re_ms = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	if (!http_module_started)
// 		return;
    
    //vm_print_res_table();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2293 , handle, event, current_handle);
    //_vm_dump_http_res();	

    /* 根据socket句柄取session_item_info */
    if ( NULL == (item_info_ptr = vm_get_item_info(handle, 0)) )
    {
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_2299 , handle);
        return;
    }
    ssi_tmp = item_info_ptr->http_session_ptr;
    //res_handle = item_info_ptr->http_handle;
    
    switch(event)
    {
    /* TCP 连接成功，直接写。 */
    case VM_TCP_EVT_CONNECTED:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2308 , item_info_ptr->socket_handle);
        
        item_info_ptr->tcp_connected = TRUE;
        NOTIFY_HTTP_STATE(item_info_ptr->http_state_notify, HTTP_STATE_CONNECTING, 
            0, ssi_tmp, item_info_ptr->sessionInStateNotifyFunc, item_info_ptr->callback_lock);

        if (item_info_ptr->user_terminate_flag)
        {
            bcall = 0;
            //vm_tcp_close(handle);
            //vm_ret_session_item(item_info_ptr);
            break;
        }
    /* 可以向通道里写数据。 */
    case VM_TCP_EVT_CAN_WRITE:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2322 , item_info_ptr->socket_handle);
        
        switch ((vm_http_write_data(item_info_ptr)) )
        {
        case OP_BLOCK:
            return;
            //break;
        case OP_COMPLETE:
            goto READ;
        default:
            /* 如果不是用户取消则回调到用户 */
            if (!ssi_tmp || item_info_ptr->user_terminate_flag)
            {
                //vm_gb2312_to_ucs2(item_info_ptr->http_session_ptr->lasterr, 50, "写数据失败。");
                bcall = 0;
                break;
            }
            res = -1;
            vm_wstrcpy(ssi_tmp->lasterr, (VMWSTR)L"http write data failed");
        }
        break;
    /* 可以向通道里读数据。*/
    case VM_TCP_EVT_CAN_READ:
READ:	
#ifdef MRE_ENABLE_HTTP_DEBUG
        rs_ms = vm_get_tick_count();
#endif
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2352 , item_info_ptr->socket_handle);
        
        switch ((vm_http_read_data(item_info_ptr) ))
        {
        case OP_BLOCK:
            return;
            //break;
        case OP_COMPLETE:
#ifdef MRE_ENABLE_HTTP_DEBUG
        re_ms = vm_get_tick_count();
        // lf modified
        //MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2361 , item_info_ptr->http_session_ptr->nresbody, re_ms-rs_ms);
#endif
            item_info_ptr->receive_completed = TRUE;
            // lf modified
            if (!ssi_tmp)
            {
                bcall = 0;
                break;
            }
            res = 0;
            //TODO: what if vm_exit_app is executed.

            break;
        default:
            /* 用户终止和读取错误都会走到这里。 */
            if (!ssi_tmp || item_info_ptr->user_terminate_flag)
            {
                //vm_gb2312_to_ucs2(item_info_ptr->http_session_ptr->lasterr, 50, "读数据失败。");
                bcall = 0;
                break;
            }
            res = -7;
            vm_wstrcpy(ssi_tmp->lasterr, (VMWSTR)L"http read data failed");

        }
        break;
    /* 只有在连接的时候才会有该消息。*/
    case VM_TCP_EVT_PIPE_BROKEN:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2392 , item_info_ptr->socket_handle);
        
        if (!ssi_tmp)
        {
            //vm_gb2312_to_ucs2(item_info_ptr->http_session_ptr->lasterr, 50, "HTTP连接失败。");
            bcall = 0;
            break;
        }
        vm_wstrcpy(ssi_tmp->lasterr, (VMWSTR)L"http connection broken");
        res = -2;
        break;
    /* 只有在CMNET 的时候才可能有该消息。 */
    case VM_TCP_EVT_HOST_NOT_FOUND:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2408 , item_info_ptr->socket_handle);
        
        if (!ssi_tmp)
        {
            //vm_gb2312_to_ucs2(item_info_ptr->http_session_ptr->lasterr, 50, "DNS解析失败。");
            bcall = 0;
            break;
        }
        res = -3;
        vm_wstrcpy(ssi_tmp->lasterr, (VMWSTR)L"http dns parse failed");
        break;
    /* 对等端主动关闭了TCP连接。 */
    case VM_TCP_EVT_PIPE_CLOSED:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2424 , item_info_ptr->socket_handle);

        if (!ssi_tmp)
        {
            //vm_gb2312_to_ucs2(item_info_ptr->http_session_ptr->lasterr, 50, 
            //	"客户端还没有接收完数据，对等端就关闭了TCP连接。");
            bcall = 0;
            break;
        }
        vm_wstrcpy(ssi_tmp->lasterr, (VMWSTR)L"http read not finished, connection closed");
        res = -8;
        break;
    default:
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_2440 , handle, event);
        bcall = 0;
        break;
    };

    if (bcall)
    {
        NOTIFY_HTTP_RESULT(ssi_tmp->hook, 
            res, ssi_tmp, item_info_ptr->callback_lock);
    }
    vm_tcp_close(handle);
    vm_ret_session_item(item_info_ptr);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2442 , bcall);
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_notify_process_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process_handle      [IN]        
 *  sys_state           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_http_notify_process_status(VM_P_HANDLE process_handle, VMINT sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_handle = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2467 , process_handle, sys_state, current_handle);
    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2471 , process_handle);

        while (VM_RES_NOT_FIND != 
            (res_handle = vm_res_findfirst(process_handle, VM_RES_TYPE_HTTP_HANDLE)) )
        {
            vm_http_free_handle(res_handle);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2477 , process_handle, res_handle);
            /* 
             * vm_http_free_handle中释放资源的操作可能执行不到，
             * 再释放一次保证资源被释放 。
             */
            if (VM_RES_OK != 
                vm_res_release_data(VM_RES_TYPE_HTTP_HANDLE, res_handle) )
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2485 , res_handle, current_handle);
            }
        }
        vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE); 
        
        vm_cancel_all_http_sessions();
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2491 , process_handle);
        break;
    }
    //_vm_dump_http_res();	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2495 , process_handle, sys_state, current_handle);
}


/*****************************************************************************
 * FUNCTION
 *  vm_initialize_http_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_initialize_http_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //__FILE__, __FUNCTION__, __LINE__
    //_vm_http_log("__FILE__:%s, __LINE__:%d \n", __FILE__, __LINE__);
    //_vm_http_log("{HTTP MODULE} enter vm_initialize_http_module - current_handle:%d .", current_handle);

    /*如果将vmhttp.c加入模拟器中运行，请保留此句
    vm_res_init();*/

// 	http_module_started = TRUE;
// 	if (VM_RES_OK != 
// 		(vm_res_type_set_notify_callback(VM_RES_TYPE_HTTP_HANDLE, vm_http_notify_process_status)) )
// 	{
// 		return -1;
// 	}
    //_vm_http_log("{HTTP MODULE} leave vm_initialize_http_module - current_handle:%d .", current_handle);
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_HTTP_HANDLE, vm_http_notify_process_status);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_finialize_http_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_finialize_http_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //_vm_http_log("{HTTP MODULE} enter vm_finialize_http_module - current_handle:%d .", current_handle);
// 	if (http_module_started)
//	{
        vm_cancel_all_http_sessions();
// 		http_module_started = FALSE;
//	}
    //_vm_http_log("{HTTP MODULE} leave vm_finialize_http_module - current_handle:%d .", current_handle);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_allot_ssesion_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  http_session_ptr        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static session_item_info* vm_allot_ssesion_item(http_session_t* http_session_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * 1. check available http res
     * 2. initialize session info
     * 3. return session info
     * ****
     * if vm_http_fetch_handle called before
     * get session info from resmng by current_handle
     * return session info
     * if vm_http_fetch_handle not called before
     * check if exist available http res
     * malloc memory for session info 
     * sii = vm_malloc(sizeof(session_item_info));
     * sii->buffer = vm_malloc(sizeof(http_response_buffer_t));
     * sii->http_session_ptr = vm_malloc(sizeof(http_session_t));
     * save session info in resmng
     * return session info              
*/
    VMINT p_handle = -1;
    VMINT res_handle = -1;
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	if (!http_module_started)
// 		return NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2612 , current_handle);

    /* 
     * 取当前进程句柄。
     * HTTP 句柄已生成，之前必定调用了vm_http_fetch_handle ? 
     */
    p_handle = vm_pmng_get_current_handle();
    if (current_handle > 0)  
    {	
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2621 , current_handle);
    
        /* current_handle非当前进程所申请 */
        if (vm_res_get_process_handle(VM_RES_TYPE_HTTP_HANDLE, current_handle) != p_handle )
        {
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2626 , current_handle, p_handle);
            return NULL;
        }
        
        /* 获取current_handle 对应的资源 */
        if (VM_RES_OK != vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&sii, &res_size) )
        {
            MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMHTTP_2633 , current_handle);
            
            //TODO: check "http_session_ptr" in "ptr"
            return NULL;
        }

        return sii;
    }
    else		
    {
    /* 
     * 2 种情况走到此流程:
     * 	1. 从vm_http_fetch_handle 中调用, 新流程
     * 	2. 在vm_asyn_http_req 	中调用, 老流程
     */
        /* 检查是否有可用HTTP 资源 */
        if (vm_res_type_avaliable_handle(VM_RES_TYPE_HTTP_HANDLE, p_handle) <= 0 )
        {
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2651 , 
                p_handle, current_handle, vm_res_get_data_list_count_by_proecss(p_handle, VM_RES_TYPE_HTTP_HANDLE));
            return NULL;
        }

        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2656 , current_handle);
            
         /* 创建session_item_info */
        sii = vm_calloc(sizeof(session_item_info));
        if (!sii) 
        {
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2662 );
            return NULL;
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2665 , sii, sii, sii+sizeof(session_item_info));
        //memset(sii, 0, sizeof(session_item_info));
        
        //sii->http_state_notify = NULL;
        sii->method = POST;
        sii->socket_handle = -1;
        //sii->use_proxy = FALSE;
        //sii->tcp_connected = FALSE;
        //sii->sent = 0;
        //sii->read = 0;
        //sii->receive_completed = FALSE;
        //sii->callback_lock = 0;
        //sii->user_terminate_flag = FALSE;

        sii->http_handle= -1;
        //sii->req_url = NULL;
        //sii->req_body = NULL;
        //sii->req_body_length = 0;
        //sii->sender = NULL;
        //sii->receiver = NULL;
        //sii->http_request = NULL;
        
        //sii->chunk_buffer_ptr = NULL;
        //sii->chunk_buffer_length = 0;
        //sii->chunk_buffer_sent = 0;
        //sii->req_eof = FALSE;

        sii->buffer = vm_calloc(sizeof(http_response_buffer_t));
        if (!sii->buffer) 
        {
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2695 , sizeof(http_response_buffer_t));
            vm_free(sii); 
            //sii = NULL;
            return NULL;
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2700 , sii->buffer, sii->buffer, sii->buffer+sizeof(http_response_buffer_t));
        //memset(sii->buffer, 0, sizeof(http_response_buffer_t));
        sii->buffer->receive_type = state_line;

        if (!http_session_ptr)	/* http_session_ptr 由HTTP 模块创建 */
        {
            sii->http_module_alloted = TRUE;
            sii->http_session_ptr = vm_calloc(sizeof(http_session_t));
            if (!sii->http_session_ptr)
            {
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2710 , sizeof(http_session_t));
                vm_free(sii->buffer); 
                //sii->buffer = NULL;
                vm_free(sii); 
                //sii = NULL;
                return NULL;
            }
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2717 , sii->http_session_ptr, sii->http_session_ptr, sii->http_session_ptr+sizeof(http_session_t));
            //memset(sii->http_session_ptr, 0, sizeof(http_session_t));
        }
        else		/* http_session_ptr 由应用提供 */
        {
            
            sii->http_module_alloted = FALSE;
            sii->http_session_ptr = http_session_ptr;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2725 );
            
            /*
            http_session_ptr->resbody = NULL;
            http_session_ptr->nresbody = 0;
            http_session_ptr->nreqbuf = 0;
            memset(http_session_ptr->reqbuf, 0, sizeof(http_session_ptr->reqbuf));
            memset(http_session_ptr->resbuf, 0, sizeof(http_session_ptr->resbuf));
            */
            // lf modified ??? !!!
            //memset(http_session_ptr, 0, sizeof(http_session_ptr));
        }

         /* 保存HTTP 资源*/
        res_handle = vm_res_save_data(VM_RES_TYPE_HTTP_HANDLE, (void *)sii, res_size, NULL, p_handle);
        if (res_handle < 0)
        {/* 保存资源失败 */
        
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2743 , res_handle);
            vm_ret_session_item(sii);
            return NULL;
        }
        
        sii->http_handle = res_handle;
        current_handle = res_handle;
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2751 , res_handle, current_handle);		
            
        return sii;
    }

    //MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_2756 , current_handle);

    /* 没有可用HTTP 资源 */
    //return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vm_ret_session_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_item_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_ret_session_item(session_item_info* session_item_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * vm_res_release_data(VM_RES_TYPE_HTTP_HANDLE, session_item_ptr->http_handle);
     * vm_free(session_item_ptr->http_session_ptr->resbody);
     * vm_free(session_item_ptr->http_session_ptr);
     * vm_free(session_item_ptr->buffer);
     * vm_free(session_item_ptr);
*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2790 , current_handle);

    /* if vm_exit_app executed. 
    if ( !vm_pmng_get_current_handle() && VM_PMNG_UNLOAD == vm_pmng_state(VM_PMNG_CUR_HANDLE) )  //TODO: what if invoked from AM(PID:0)
    {
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_2795 );
        return;
    }*/
    
    //if (session_item_ptr && http_module_started)
    if (session_item_ptr)// && http_module_started
    {
        /* 释放资源空间*/
        if (VM_RES_OK != 
            vm_res_release_data(VM_RES_TYPE_HTTP_HANDLE, session_item_ptr->http_handle) )
        {
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_2806 );
            return;
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2808 , session_item_ptr->http_handle, current_handle);

        /*
          * 释放由于http response body而分出来的内存空间。
             */
        if (session_item_ptr->http_session_ptr->nresbody > 0 
            && session_item_ptr->http_session_ptr->resbody)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2816 , session_item_ptr->http_session_ptr->nresbody, session_item_ptr->http_session_ptr->resbody, session_item_ptr->http_handle, current_handle);
            
            vm_free(session_item_ptr->http_session_ptr->resbody);
            //session_item_ptr->http_session_ptr->resbody = NULL;
            //session_item_ptr->http_session_ptr->nresbody = 0;
        }
        
        /* 是由http module分配http session 空间的。*/
        if (session_item_ptr->http_module_alloted) 
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2826 , session_item_ptr->http_session_ptr, session_item_ptr->http_handle, current_handle);
            
            vm_free(session_item_ptr->http_session_ptr);
        }

        if (session_item_ptr->buffer)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2833 , session_item_ptr->buffer, session_item_ptr->http_handle, current_handle);
            
            vm_free(session_item_ptr->buffer);
            //session_item_ptr->buffer = NULL;
        }

        if (session_item_ptr->http_request)
        {
            if (session_item_ptr->http_request->heads)
            {
                vm_free(session_item_ptr->http_request->heads);
                //session_item_ptr->http_request->heads = NULL;
                //session_item_ptr->http_request->nhead = 0;
            }
            if (session_item_ptr->http_request->body)
            {
                vm_free(session_item_ptr->http_request->body);
                //session_item_ptr->http_request->body = NULL;
                //session_item_ptr->http_request->nbody = 0;
            }
            vm_free(session_item_ptr->http_request);
            //session_item_ptr->http_request = NULL;
            //memset(session_item_ptr->http_request->url, 0, sizeof(session_item_ptr->http_request->url));
        }
/*
        if (session_item_ptr->http_request)
        {
            _vm_http_log("{HTTP MODULE} vm_ret_session_item - before vm_free - "
                "http_request:%p, http_handle:%d, current_handle:%d .", 
            session_item_ptr->http_request, 
            session_item_ptr->http_handle, current_handle);
            
            vm_free(session_item_ptr->http_request);
            //session_item_ptr->http_request = NULL;
        }
        session_item_ptr->http_module_alloted = 0;
        session_item_ptr->http_session_ptr = NULL;
        session_item_ptr->http_state_notify = NULL;
        session_item_ptr->use_proxy = FALSE;
        session_item_ptr->method = POST;
        session_item_ptr->socket_handle = -1;
        session_item_ptr->tcp_connected = FALSE;
        session_item_ptr->receive_completed = FALSE;
        session_item_ptr->sent = 0;
        session_item_ptr->read = 0;

        session_item_ptr->http_handle= -1;
        session_item_ptr->req_url = NULL;
        session_item_ptr->req_body = NULL;
        session_item_ptr->req_body_length = 0;
        session_item_ptr->sender = NULL;
        session_item_ptr->receiver = NULL;
        session_item_ptr->http_request = NULL;
*/
        if (session_item_ptr->chunk_buffer_ptr)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2871 , session_item_ptr->chunk_buffer_ptr, session_item_ptr->http_handle, current_handle);
            
            vm_free(session_item_ptr->chunk_buffer_ptr);
            //session_item_ptr->chunk_buffer_ptr = NULL;
        }
/*
        session_item_ptr->chunk_buffer_length = 0;
        session_item_ptr->chunk_buffer_sent = 0;
        session_item_ptr->req_eof = FALSE;
*/
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2881 , session_item_ptr, session_item_ptr->http_handle, current_handle);

        vm_free(session_item_ptr);

        session_item_ptr = NULL;

        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2887 );
    }
    
    /* 重置当前HTTP句柄 */
    current_handle = -1;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2893 , current_handle);
    //return;
}


/*****************************************************************************
 * FUNCTION
 *  vm_reg_http_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_reg_http_notification(void (*f)(VMINT state, VMINT param)) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT p_handle = -1;
    VMINT res_size = 0;
    session_item_info* sii = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	if (!http_module_started)
// 		return;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2923 , current_handle);
    
    notify_state_callback = f;

    /* HTTP 句柄已生成，之前必定调用了vm_http_fetch_handle ? */
    if (current_handle > 0)  
    {	
        p_handle = vm_pmng_get_current_handle();
    
        /* current_handle 为当前进程所申请 */
        if (p_handle == vm_res_get_process_handle(VM_RES_TYPE_HTTP_HANDLE, current_handle) )
        {
            /* 获取current_handle 对应的资源 */
            if (VM_RES_OK 
                == vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&sii, &res_size))
            {
                sii->http_state_notify = (void*)f;
                
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2941 , current_handle);
            }
        }
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2946 , current_handle);
}


/*****************************************************************************
 * FUNCTION
 *  vm_enable_proxy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  _use_proxy      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_enable_proxy(VMINT _use_proxy) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT p_handle = -1;
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	if (!http_module_started)
// 		return;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2975 , current_handle);
    
    use_proxy = _use_proxy;

    /* HTTP 句柄已生成，之前必定调用了vm_http_fetch_handle ? */
    if (current_handle > 0)  
    {	
        p_handle = vm_pmng_get_current_handle();
    
        /* current_handle 为当前进程所申请 */
        if (p_handle == vm_res_get_process_handle(VM_RES_TYPE_HTTP_HANDLE, current_handle) )
        {
            /* 获取current_handle 对应的资源 */
            if (VM_RES_OK 
                == vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&sii, &res_size))
            {
                sii->use_proxy= _use_proxy;
                
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2993 , current_handle);
            }
        }
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_2998 , current_handle);
}


/*****************************************************************************
 * FUNCTION
 *  vm_add_default_headers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_add_default_headers(session_item_info* item_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3022 , item_info);
    
    /* 添加默认请求头信息*/
    add_http_request_head(item_info->http_session_ptr, "Host", "localhost");
    add_http_request_head(item_info->http_session_ptr, "User-Agent", (VMCHAR*)applib_inet_get_user_agent_string());
    add_http_request_head(item_info->http_session_ptr, "Accept", "*/*");
    add_http_request_head(item_info->http_session_ptr, "Accept-Language", "zh_CN,zh");
    add_http_request_head(item_info->http_session_ptr, "Accept-Charset", "UTF-8,ISO-8859-1,US-ASCII,ISO-10646-UCS-2;q=0.6");
    add_http_request_head(item_info->http_session_ptr, "Accept-Encoding", "identity");
    add_http_request_head(item_info->http_session_ptr, "Connection", "close");

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3033 , item_info);
    
    /* 添加request 中的用户自定义请求头 */
    for (i = 0; i < (unsigned int)(item_info->http_request->nhead); i++)
    {
        if ( !strcmp(item_info->http_request->heads[i].name, "MRE-AM-BlockSize") )
        {
            item_info->range_size = atoi(item_info->http_request->heads[i].value);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3041 , item_info->range_size);
            continue;
        }
        
        /* 
          * 开始加入用户定义的http head，在此过程中 
          * 如果http head 有重名，那么将会用用户定义
          * 的替换http module默认的值。
          */
        if (0 != (add_http_request_head(item_info->http_session_ptr, 
            item_info->http_request->heads[i].name, 
            item_info->http_request->heads[i].value)) )
        {
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3054 , item_info->http_request->heads[i].name);
        }
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3058 , item_info);
}

/**
  * 调用vm_asyn_http_req函数返回值的定义。
  * 
  * ASYN_HTTP_REQ_ACCEPT_SUCCESS
  * 接受HTTP 请求成功，MRE将会 异步发送HTTP请求。
  *
  * ASYN_HTTP_REQ_NOT_SUPPORT_METHOD
  * 不支持当前的HTTP method。
  *
  * ASYN_HTTP_REQ_NOT_SUPPORT_HTTP_COMM
  * 不支持HTTP协议栈的通信。
  *
  * ASYN_HTTP_REQ_ONLY_SUPPORT_PROXY
  * 仅仅支持代理模式-即CMWAP。
  *
  * ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE
  * HTTP协议栈没有足够的资源，无法接受此次HTTP请求。
  * 如果HTTP只支持一个HTTP连接，在HTTP协议栈还没有
  * 把HTTP response通过客户程序注册到协议栈的回调函数
  * 之前又调用vm_asyn_http_req函数，那么该该结果将回被
  * 返回。
  */

static VMINT vm_http_add_head_int(session_item_info* item_info, VMCHAR * p1, VMCHAR * p2)
{
    /* 在请求头中写入 Content-Length信息 */
    if (add_http_request_head(item_info->http_session_ptr, p1, p2) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3334 , item_info->http_session_ptr->nreqbuf, item_info->req_body_length);
        return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
    }
    
    if (item_info->http_session_ptr->nreqbuf + CRLF_LEN <= HTTP_REQUEST_BUFSIZE)
    {
        /* 在请求缓冲区中加入CRLF 标志，表示entity body的开始位置。*/
        memcpy(item_info->http_session_ptr->reqbuf + item_info->http_session_ptr->nreqbuf, 
            CRLF, CRLF_LEN);
        item_info->http_session_ptr->nreqbuf += CRLF_LEN;
        return 0;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3348 , item_info->http_session_ptr->nreqbuf, item_info->req_body_length);
        return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
    }

}
/*****************************************************************************
 * FUNCTION
 *  vm_http_request_sent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  asyn_request                    [?]         
 *  http_hook                       [IN]        
 *  http_state_notify               [?]         
 *  session_ptr                     [?]         
 *  sessionInStateNotifyFunc        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_http_request_sent(
                asyn_http_req_t *asyn_request,
                void (*http_hook) (VMINT, void*),
                void *http_state_notify,
                http_session_t *session_ptr,
    VMINT sessionInStateNotifyFunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * 1. prcessing request-line & headers
     * item_info->http_session_ptr->reqbuf = request-line + headers (vm_http_fetch_handle -> vm_asyn_http_req -> vm_http_request_sent )
     * reset URL and Host in Headers in reqbuf if necessary
     * 
     * item_info->http_session_ptr->reqbuf = blank (vm_asyn_http_req -> vm_http_request_sent )
     * add Reuest-Line, Headers into reqbuf
     * 2. add body
     * 3. connect tcp
*/
#ifndef WIN32
    extern VMINT vm_tcp_apn_exists(VMINT);
    VMINT cmwap_exists = vm_tcp_apn_exists(VM_TCP_APN_CMWAP);
    VMINT cmnet_exists = vm_tcp_apn_exists(VM_TCP_APN_CMNET);
#else
    VMINT cmwap_exists = TRUE, cmnet_exists = TRUE;
#endif

    VMINT current_use_proxy = TRUE;
    session_item_info* item_info = NULL;
    char scheme[10] = {0}, /*res[1024+128] = {0},  */param[10] = {0}/*, temp[1024+128+128] = {0}*/;
    char * res = NULL;
    char * temp = NULL;
    int i = 0;
    vm_apn_info_ext apn_info;
    VMINT ret = 0;
    VMCHAR * tmp_url = 0;
    http_session_t* ssi_tmp = NULL;

// 	if (!http_module_started)
// 		return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;

    res = (char*)_vm_kernel_calloc(1024+128);
    if (!res)
    {
        return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
    }
    temp = (char*)_vm_kernel_calloc(1024+128+128);
    if (!temp)
    {
        return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
    }
    

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3141 , current_handle);
    
    if ((item_info =  vm_allot_ssesion_item(session_ptr)) == NULL)
    {
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3145 );
        _vm_kernel_free(res);
        _vm_kernel_free(temp);
        return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
    }
    ssi_tmp = item_info->http_session_ptr;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3149 , item_info, item_info+sizeof(session_item_info), current_handle);

    /*TODO:
http_session_ptr->url is used in vm_get_asyn_http_req_handle
    */
    strncpy(ssi_tmp->url, asyn_request->http_request->url, sizeof(ssi_tmp->url));
    item_info->use_proxy = asyn_request->use_proxy;
    item_info->method = asyn_request->req_method;
    item_info->http_state_notify = http_state_notify;
    item_info->tcp_connected = FALSE;
    ssi_tmp->hook = http_hook;
    item_info->sessionInStateNotifyFunc = sessionInStateNotifyFunc;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3162 , cmwap_exists, cmnet_exists, item_info->use_proxy);
    
    /* 解析URL, 从中获取host, port, res,  */
    if (item_info->req_url != NULL)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3167 );
        //vm_log_debug_long(item_info->req_url, strlen(item_info->req_url));
        tmp_url = item_info->req_url;

    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3180 );
        //vm_log_debug_long(asyn_request->http_request->url, strlen(asyn_request->http_request->url));
        tmp_url = asyn_request->http_request->url;
    }
    
    if (unpack_url(tmp_url, scheme, ssi_tmp->host, 
    &(ssi_tmp->port), res, param) != 0)
    {
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3173 );
        vm_ret_session_item(item_info);
        _vm_kernel_free(res);
        _vm_kernel_free(temp);
        return ASYN_HTTP_REQ_URL_FORMAT_ERROR;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3192 , scheme, ssi_tmp->host, ssi_tmp->port, res, param);
    //vm_log_debug_long(res, strlen(res));

    /* 
      * 得到以CMNET联网还是CMWAP联网。 
      */
    switch (item_info->use_proxy)
    {
    case HTTP_USE_CMWAP:
        current_use_proxy = TRUE;
        break;
    case HTTP_USE_CMNET_PRIORITY:
        if (cmnet_exists || (!cmwap_exists))
            current_use_proxy = FALSE;
        else
            current_use_proxy = TRUE;
        break;
    case HTTP_USE_CMWAP_PRIORITY:
        if (cmwap_exists || (!cmnet_exists))
            current_use_proxy = TRUE;
        else
            current_use_proxy = FALSE;
        break;
    case HTTP_USE_CMNET:
    case HTTP_USE_WIFI:
    default:
        current_use_proxy = FALSE;
        break;
    }

    /* 组合请求行 			*/
    switch(item_info->method)
    {
    case POST:
        sprintf(temp, "POST ");
        break;
    case GET:
        sprintf(temp, "GET ");
        break;
    default:
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3232 , item_info->method);
        vm_ret_session_item(item_info);
        _vm_kernel_free(res);
        _vm_kernel_free(temp);
        return ASYN_HTTP_REQ_NOT_SUPPORT_METHOD;
    }

    if (current_use_proxy)
    {
        /* 检查是否应用设置了自定义长度的req_url */
        if (item_info->req_url != NULL)
            strcat(temp, item_info->req_url);
        else
            strcat(temp, asyn_request->http_request->url);
    }
    else
    {
        strcat(temp, res);
    }
    strcat(temp, " HTTP/1.1\r\n");
    /* 请求行准备完毕 */
    
    if (ssi_tmp->nreqbuf > 0)	
    {/* 请求缓存中已有数据: Request-Line, Headers */
    
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3255 , ssi_tmp->nreqbuf);

        /* 重设请求行: GET/POST $url$ HTTP/1.1\r\n */
        if (reset_http_request_line(ssi_tmp, temp) < 0)
        {
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3260 , strlen(temp));
            //vm_log_debug_long(temp, strlen(temp));
            vm_ret_session_item(item_info);
            _vm_kernel_free(res);
            _vm_kernel_free(temp);
            return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
        }

        /* 替换请求头中的Host 信息 */
        memset(temp, 0, sizeof(temp));
        sprintf(temp, "%s:%d", ssi_tmp->host, ssi_tmp->port);

        add_http_request_head(ssi_tmp, "Host", temp);
    }
    else
    {/* 请求缓存尚为空，未执行过vm_http_fetch_handle */

        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3275 , ssi_tmp->nreqbuf);

        /* 保存请求行至请求缓存 */
        memcpy(ssi_tmp->reqbuf+ssi_tmp->nreqbuf, temp, strlen(temp));
        ssi_tmp->nreqbuf = strlen(temp);

        memset(temp, 0, sizeof(temp));
        sprintf(temp, "%s:%d", ssi_tmp->host, ssi_tmp->port);

        /* 添加默认请求头信息*/
        add_http_request_head(ssi_tmp, "Host", temp);
        add_http_request_head(ssi_tmp, "User-Agent", (VMCHAR*)applib_inet_get_user_agent_string());
        add_http_request_head(ssi_tmp, "Accept", "*/*");
        add_http_request_head(ssi_tmp, "Accept-Language", "zh_CN,zh");
        add_http_request_head(ssi_tmp, "Accept-Charset", "UTF-8,ISO-8859-1,US-ASCII,ISO-10646-UCS-2;q=0.6");
        add_http_request_head(ssi_tmp, "Accept-Encoding", "identity");
        add_http_request_head(ssi_tmp, "Connection", "close");
        
        for (i = 0; i < asyn_request->http_request->nhead; i++)
        {
            if ( !strcmp(asyn_request->http_request->heads[i].name, "MRE-AM-BlockSize") )
            {
                item_info->range_size = atoi(asyn_request->http_request->heads[i].value);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3298 , item_info->range_size);
                continue;
            }
            
            /* 
              * 开始加入用户定义的http head，在此过程中 
              * 如果http head 有重名，那么将会用用户定义
              * 的替换http module默认的值。
              */
            if ((add_http_request_head(ssi_tmp, 
                asyn_request->http_request->heads[i].name, 
                asyn_request->http_request->heads[i].value))  != 0)
            {
                MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3311 , asyn_request->http_request->heads[i].name);
                vm_ret_session_item(item_info);
                _vm_kernel_free(res);
                _vm_kernel_free(temp);
                return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
            }
        }
    }
    /* 至此请求行与请求头已完成，下面处理请求体 */

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3319 , ssi_tmp->nreqbuf);
    //vm_log_debug_long(item_info->http_session_ptr->reqbuf, item_info->http_session_ptr->nreqbuf);

    if (item_info->req_body_length > 0)
    {/* 发送定长请求报文体 */
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3325 , 
            item_info->req_body_length);
        
        memset(temp, 0, sizeof(temp));
        sprintf(temp, "%d", item_info->req_body_length);
        
        /* 在请求头中写入 Content-Length信息 */
        if (ASYN_HTTP_REQ_ACCEPT_SUCCESS != (ret = vm_http_add_head_int(item_info, "Content-Length", temp)))
        {
            vm_ret_session_item(item_info);
            _vm_kernel_free(res);
            _vm_kernel_free(temp);
            return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
        }
    }
    else if (item_info->sender !=NULL)	//item_info->req_body_length <= 0
    {/* 请求报文长度未指定，且注册了上传回调函数 */
    
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3356 , item_info->req_body_length);

        /* 在请求头中写入Content-Encoding信息，按chunk 编码发送数据 */
        if (ASYN_HTTP_REQ_ACCEPT_SUCCESS != (ret = vm_http_add_head_int(item_info, "Transfer-Encoding", "chunked")))
        {
            vm_ret_session_item(item_info);
            _vm_kernel_free(res);
            _vm_kernel_free(temp);
            return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
        }

        /* 为chunk_buffer_ptr分配内存 */
        if (NULL == (item_info->chunk_buffer_ptr = (VMUINT8*)vm_malloc(HTTP_REQUEST_BUFSIZE) )  )
        {
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3383 );
            vm_ret_session_item(item_info);
            _vm_kernel_free(res);
            _vm_kernel_free(temp);
            return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
        }
        memset(item_info->chunk_buffer_ptr, 0, HTTP_REQUEST_BUFSIZE);

    }
    else		//item_info->req_body_length <= 0 && item_info->sender ==NULL
    {/* 原HTTP 流程 */
    
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3393 );
        
        if (!(item_info->method == GET && asyn_request->http_request->nbody <= 0))
        {
            /* 加入用户指定的内容到请求的entity body。 */
            if (set_http_request_body(ssi_tmp, 
                asyn_request->http_request->nbody, asyn_request->http_request->body) != 0)
            {
                MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3401 );
                vm_ret_session_item(item_info);
                _vm_kernel_free(res);
                _vm_kernel_free(temp);
                return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
            }
        }
        else
        {/* 是GET 请求但是没有entity body */
        
            if (ssi_tmp->nreqbuf + CRLF_LEN <= HTTP_REQUEST_BUFSIZE)
            {
            /* 在请求缓冲区中加入CRLF 标志，表示没有entity body。*/
                memcpy(ssi_tmp->reqbuf + ssi_tmp->nreqbuf, 
                    CRLF, CRLF_LEN);
                ssi_tmp->nreqbuf += CRLF_LEN;
            }
            else
            {
                //kal_wap_trace("{HTTP MODULE} Failed to add \r\n http session, because http request body is NULL.");
                vm_ret_session_item(item_info);
                _vm_kernel_free(res);
                _vm_kernel_free(temp);
                return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
            }
        }
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3425 , ssi_tmp->nreqbuf);
    //vm_log_debug_long(item_info->http_session_ptr->reqbuf, item_info->http_session_ptr->nreqbuf);
    if (current_use_proxy)
    {
        VMUINT dtacct_id;

        vm_get_encoded_dtacct_id(VM_TCP_APN_CMWAP, &dtacct_id);
        vm_get_apn_info(&apn_info);
        // lf modified
        if (0 != strstr(apn_info.proxy_ip, "0.0.0.0") ||0 == apn_info.proxy_port)
        {
            current_use_proxy = 0;
        }
    }

    if (current_use_proxy)
        MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMHTTP_3436 , apn_info.proxy_ip, apn_info.proxy_port);
    else
        MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMHTTP_3438 , ssi_tmp->host, ssi_tmp->port);
   
    if ((item_info->socket_handle = vm_tcp_connect(
        (current_use_proxy ? apn_info.proxy_ip : ssi_tmp->host), 
        (current_use_proxy ? apn_info.proxy_port : ssi_tmp->port), 
        (item_info->use_proxy == HTTP_USE_WIFI ? 
            VM_TCP_APN_WIFI : (current_use_proxy ? VM_TCP_APN_CMWAP : VM_TCP_APN_CMNET)),
        vm_tcp_module_hook)) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_3447 , item_info->socket_handle);
        vm_ret_session_item(item_info);
        _vm_kernel_free(res);
        _vm_kernel_free(temp);
        return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
    }

    /* 将socket句柄保存至会话信息，使应用端可以获取 */
    //item_info->http_session_ptr->s = item_info->socket_handle;
    ssi_tmp->s = item_info->http_handle; // modified as res id 

	//abm hold
    {
        extern VMUINT32 vm_get_tcp_acctid_by_resid(VMINT res_id);
        VMUINT32 account_id = vm_get_tcp_acctid_by_resid(item_info->socket_handle);
        item_info->account_id = account_id;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3455 , item_info->socket_handle, current_handle);

    /*FLOW:
    bind sock handle to http handle
    reset current_handle
    */

    /* 绑定HTTP 句柄至SOCKET 句柄 
    vm_res_set_mtk_reshandle(VM_RES_TYPE_HTTP_HANDLE, current_handle, item_info->socket_handle);*/
    
    /* 清除当前HTTP 句柄 */
    current_handle = -1;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3468 , current_handle);
    //vm_print_res_table();
    _vm_kernel_free(res);
    _vm_kernel_free(temp);
    return ASYN_HTTP_REQ_ACCEPT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  request     [?]     
 *  session     [?]     
 * RETURNS
 *  
 *****************************************************************************/
int vm_http_request(http_request_t *request, http_session_t *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = ASYN_HTTP_REQ_ACCEPT_SUCCESS;
    asyn_http_req_t* ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!request || !session)
        return -1;

    if ((ptr = vm_calloc(sizeof(asyn_http_req_t))) == NULL)
        return ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE;
    //else
    //	memset(ptr, 0, sizeof(asyn_http_req_t));

    ptr->http_request = request;
    ptr->req_method = POST;
#ifdef WIN32
    ptr->use_proxy = HTTP_USE_CMNET;
#else
    ptr->use_proxy = use_proxy;
#endif
    
    ret = vm_http_request_sent(ptr, session->hook, (void*)notify_state_callback, session, FALSE);
    
    vm_free(ptr);
    
    return ret;	
}


/*****************************************************************************
 * FUNCTION
 *  vm_asyn_http_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  request                 [?]         
 *  http_hook               [IN]        
 *  http_state_notify       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_asyn_http_req(
        asyn_http_req_t *request,
        void (*http_hook) (VMINT, void*),
    void (*http_state_notify)(VMINT state, VMINT param, void* session))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3544 , current_handle);
    
    if (request && request->http_request)
    {
#ifdef WIN32
        request->use_proxy = HTTP_USE_CMNET;
#endif
        return vm_http_request_sent(request, http_hook, (void*)http_state_notify, NULL, TRUE);
    }

    return ASYN_HTTP_REQ_ACCEPT_SUCCESS;
}

/*TODO:
how to get sock handle from asyn_http_req_t
*/


/*****************************************************************************
 * FUNCTION
 *  vm_get_asyn_http_req_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  request     [?]     
 *  handle      [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_asyn_http_req_handle(asyn_http_req_t* request, VMINT* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT p_handle = -1;
    VMINT res_handle = -1;
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    http_session_t* ssi_tmp = NULL;
    http_request_t* 	req_tmp = NULL;	/* Old http request */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	if (!http_module_started)
// 		return VM_GET_AHH_NO_COMM;

    /* 检查参数 */
    if (!request || !request->http_request || !handle)
        return VM_GET_AHH_ERROR_PARAM;
    req_tmp = request->http_request;
    /* 取当前进程句柄 */
    p_handle = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3596 , handle, p_handle, current_handle);
    //vm_print_res_table();
    //_vm_dump_http_res();	
    
    /* 
     * 遍历进程的HTTP 资源，取出具有对应SOCKET 句柄的资源 
     */
    if (VM_RES_NOT_FIND == 
        (res_handle = vm_res_findfirst(p_handle, VM_RES_TYPE_HTTP_HANDLE)) )
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_3606 , handle, current_handle, p_handle);
        vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
        return VM_GET_AHH_NO_COMM;
    }
    do {
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3611 , res_handle, p_handle);
    
        if (VM_RES_OK != 
            vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, res_handle, (void **)&sii, &res_size) )
        {
            MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3616 , res_handle);
            continue;
        }
        ssi_tmp = sii->http_session_ptr;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3619 , res_handle, p_handle, ssi_tmp, sii->user_terminate_flag);
        if (ssi_tmp && !sii->user_terminate_flag)
        {/* session item info有效，且用户没有取消HTTP请求 */

            //MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3624 );
            //vm_log_debug_long(sii->http_session_ptr->url, strlen(sii->http_session_ptr->url));
            //_vm_http_log("{HTTP MODULE} vm_get_asyn_http_req_handle - to compare url - sii vs. req, req: ");
            //_vm_http_log_long(request->http_request->url, strlen(request->http_request->url));
            
            if (0 == strncmp(ssi_tmp->url, req_tmp->url, sizeof(req_tmp->url)))
            {/* 相同的请求URL */
                
                int i = 0, heads_same_flag = TRUE;
                char *p_head_name=NULL, *p_head_value=NULL, *p_head_end=NULL;

                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3635 , req_tmp->nhead);
                /* to compare the heads of request */
                for (i=0; i<req_tmp->nhead; i++)
                {
                    if ( !strcmp(req_tmp->heads[i].name, "MRE-AM-BlockSize") )
                    {
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3641 , req_tmp->heads[i].name);
                        continue;
                    }
                    
                    p_head_name = strstr(ssi_tmp->reqbuf, req_tmp->heads[i].name);
                    //MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3646 );
                    //vm_log_debug_long(request->http_request->heads[i].name, 20);
                    //_vm_http_log("p_head_name. ");
                    //_vm_http_log_long(p_head_name, 20);
                    if (NULL == p_head_name)	/* head not found in reqbuf */
                    {
                        heads_same_flag = FALSE;
                        break;
                    }
                    
                    p_head_value = strstr(p_head_name, ": ") + 2;
                    if (NULL == p_head_value)	/* head value not found in reqbuf */
                    {
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_3659 );
                        vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
                        return VM_GET_AHH_NO_COMM;
                    }

                    p_head_end = strstr(p_head_value, CRLF);
                    if (NULL == p_head_end)	/* head value not found in reqbuf */
                    {
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_3667 );
                        vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
                        return VM_GET_AHH_NO_COMM;
                    }

                    //MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3672 );
                    //vm_log_debug_long(request->http_request->heads[i].value, 100);
                    //_vm_http_log("p_head_value. ");
                    //_vm_http_log_long(p_head_value, 100);
                    if (0 != strncmp(req_tmp->heads[i].value, p_head_value, p_head_end-p_head_value ) )
                    {/* different head value */

                        heads_same_flag = FALSE;
                        break;
                    }
                }

                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3684 , req_tmp->nhead, heads_same_flag);
                if (!heads_same_flag)	/* heads are different */
                    continue;
                
                /* if come here, mean heads are same */
            
                //MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3690 );
                if (sii->method == POST)
                {
                //_vm_http_log("{HTTP MODULE} vm_get_asyn_http_req_handle - POST, to campare req body - sii vs. req.");
                    
                    /* 都包含请求体 */
                    if (((unsigned int)(ssi_tmp->nreqbuf) > (unsigned int)(req_tmp->nbody + CRLF_LEN))
                        && (req_tmp->nbody > 0))
                    {
                        //_vm_http_log("{HTTP MODULE} vm_get_asyn_http_req_handle - have body - sii vs. req, sii: "
                        //	"nreqbuf:%d, nbody:%d .", sii->http_session_ptr->nreqbuf, request->http_request->nbody);
                        //_vm_http_log_long(sii->http_session_ptr->reqbuf, sii->http_session_ptr->nreqbuf);
                        //_vm_http_log("{HTTP MODULE} vm_get_asyn_http_req_handle - have body - sii vs. req, req: "
                        //	"nreqbuf:%d, nbody:%d .", sii->http_session_ptr->nreqbuf, request->http_request->nbody);
                        //_vm_http_log_long(request->http_request->body, request->http_request->nbody);
                        if (0 == memcmp(
                            ssi_tmp->reqbuf + ssi_tmp->nreqbuf - req_tmp->nbody, 
                            req_tmp->body, req_tmp->nbody) )
                        {/* 相同的请求体 */
                        
                            //*handle = sii->socket_handle;
                            *handle = sii->http_handle; // modified as res id
                            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3712 , sii->socket_handle, *handle);
                            //vm_print_res_table();
                            vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
                            return VM_GET_AHH_SUCCESS;
                        }
                    }
                    else		
                    {
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3720 , ssi_tmp->nreqbuf, req_tmp->nbody);
                        //vm_log_debug_long(sii->http_session_ptr->reqbuf, sii->http_session_ptr->nreqbuf);
                        /* 没有请求体 	*/
                        if (req_tmp->nbody <= 0)
                        {
                            //*handle = sii->socket_handle;
                            *handle = sii->http_handle; // modified as res id
                            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3727 , sii->socket_handle, *handle);
                            //vm_print_res_table();
                            vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
                            return VM_GET_AHH_SUCCESS;
                        }
                    }
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3733 );
                }
                else		/* GET请求，只判定url是否一致 */
                {
                    
                    //*handle = sii->socket_handle;
                    *handle = sii->http_handle; // modified as res id
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3740 , sii->socket_handle, *handle);
                    //vm_print_res_table();
                    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
                    return VM_GET_AHH_SUCCESS;
                }
            }
        }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3747 , res_handle, p_handle);
    }
    while (VM_RES_NOT_FIND != 
        (res_handle = vm_res_findnext(p_handle, VM_RES_TYPE_HTTP_HANDLE)) );
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3751 , res_handle, p_handle);
        
    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3755 , handle, current_handle, p_handle);
    return VM_GET_AHH_NO_COMM;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cancel_asyn_http_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_cancel_asyn_http_req(VMINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * TODO:
     * 1. close tcp connection
     * 2. set user terminate flag
     * 3. release http resource 
*/
    VMINT p_handle = -1;
    VMINT res_handle = -1;
    VMINT res_size = 0;
    session_item_info* sii = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// 	if (!http_module_started)
// 		return VM_CAH_REQ_NO_COMM;

    /* 检查参数 */
    if (handle < 0)
        return VM_GET_AHH_ERROR_PARAM;

    /* 取当前进程句柄 */
    p_handle = vm_pmng_get_current_handle();

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3799 , handle, p_handle, current_handle);
    //vm_print_res_table();
    //_vm_dump_http_res();	

    //vm_tcp_close(handle);
    
    /* 
     * 遍历进程的HTTP 资源，释放SOCKET 句柄对应的资源。
     */
    if (VM_RES_NOT_FIND == 
        (res_handle = vm_res_findfirst(p_handle, VM_RES_TYPE_HTTP_HANDLE)) )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3811 , handle, current_handle, p_handle);
        vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
        return VM_GET_AHH_NO_COMM;
    }
    do {
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3816 , res_handle, p_handle);
        if (VM_RES_OK != 
            vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, res_handle, (void **)&sii, &res_size) )
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3820 , res_handle);
            continue;
        }
        
        if (sii->http_session_ptr && /*sii->socket_handle == handle*/
                                                res_handle == handle)
        {/* session item info有效 *//* socket句柄匹配 */
            
            if (sii->callback_lock == 0)
            {
                //vm_tcp_close(handle);
                vm_tcp_close(sii->socket_handle);
                vm_http_free_handle(res_handle);
                
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3834 , res_handle, handle);
            }
            else
            {
                sii->user_terminate_flag = TRUE;
                sii->sessionInStateNotifyFunc = 0;
                sii->http_state_notify = NULL;

                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3842 , res_handle, handle);
            }
            
            vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
            return VM_CAH_REQ_SUCCESS;
        }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3848 , res_handle, p_handle);
    } 
    while (VM_RES_NOT_FIND != 
        (res_handle = vm_res_findnext(p_handle, VM_RES_TYPE_HTTP_HANDLE)) );
    
    vm_res_findclose(VM_RES_TYPE_HTTP_HANDLE);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3855 , handle, current_handle);
    return VM_CAH_REQ_NO_COMM;
}


/*********************************************************************
 * HTTP模块新增的接口实现 2009-11-11
 *********************************************************************/
/*HTTP request example:
------------------------------------------------------------
Request-Line	|GET/POST http://localhost HTTP/1.1\r\n
------------------------------------------------------------
Header Fields	|Host=localhost
            |User-Agent=$USER_AGENT$
            |Accept=* / *
            |Accept-Language=zh_CN,zh
            |Accept-Charset=UTF-8,ISO-8859-1,US-ASCII,ISO-10646-UCS-2;q=0.6
            |Accept-Encoding=identity
            |Connection=close
            |...... (user customized headers)
------------------------------------------------------------
*/


/*****************************************************************************
 * FUNCTION
 *  vm_http_fetch_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [IN]        
 *  p       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_fetch_handle(VMINT req, void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_handle = -1;
    //VMINT res_size = 0;
    session_item_info* sii = NULL;
    //asyn_http_req_t* asyn_request = NULL;
    http_request_t * req_p = NULL;
    VMINT ret = 0;
    //char temp[255];
    char *temp;
    int temp_size = 300;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* unsigned int i = 0; */

    if (req < 0 || req > HTTP_REQUEST || p == NULL)
        return -1;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3912 , req);
    current_handle = -1;

    /* 申请HTTP 资源，保存session info  */
    if ((sii =  vm_allot_ssesion_item(NULL)) == NULL)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_3918 , current_handle);
        return -1;
    }

    /* sii->http_handle 应与current_handle 相同 */
    if (sii->http_handle == current_handle)
    {
        res_handle = sii->http_handle;
    }
    else		/* 发生异常错误 */
    {
        vm_http_free_handle(sii->http_handle);
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_3930 , sii->http_handle, current_handle);
        return -1;
    }
    
    switch (req)
    {
    case ASYN_HTTP_REQ:
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3937 , req);
/*TODO:
how prepared is ASYN_HTTP_REQ?
==================================================
req.req_method = HTTP_USE_CMNET_PRIORITY;
req.use_proxy = GET;
//req.http_request = (http_request_t*)vm_calloc(sizeof(http_request_t)); 
//? strcat(req.http_request->url, "http://xxxx/xxx"); 
*/
        req_p = ((asyn_http_req_t*)p)->http_request;
        sii->method = ((asyn_http_req_t*)p)->req_method;

        if (NULL == req_p)
        {/* 应用中没有设置http_request */
        
            sii->http_request = (http_request_t*)vm_malloc(sizeof(http_request_t)); 
            if (NULL == sii->http_request)
            {
                MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3955 , sizeof(http_request_t));
                return -1;
            }
            memset(sii->http_request, 0, sizeof(sizeof(http_request_t)));
            
            //memset(sii->http_request, 0, sizeof(http_request_t));
            sprintf(sii->http_request->url, "http://localhost/");
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3965 );
            ret = vm_http_data_prepare_int(sii, req_p);
            if (0 > ret)
            {
                return ret;
            }
        }
        

        break;
    case HTTP_REQUEST:
        {
            http_request_t * req_p = (http_request_t*)p;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_3972 , req);

            //sii->http_request = (http_request_t*)p;
            sii->method = POST;

            //_vm_http_log("{HTTP MODULE} vm_http_fetch_handle by HTTP_REQUEST. req:%d .", req);
            
            ret = vm_http_data_prepare_int(sii, req_p);
            if (0 > ret)
            {
                return ret;
            }
        }
        break;
    default:
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3979 , req);
        vm_http_free_handle(sii->http_handle);
        return -1;
        //break;
    }

    temp = (char*)vm_malloc(temp_size);
    memset(temp, 0, sizeof(temp_size));
    /* 组合请求行 */
    switch(sii->method)
    {
    case POST:
        sprintf(temp, "POST ");
        break;
    case GET:
        sprintf(temp, "GET ");
        break;
    default:
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_3997 , sii->method);
        vm_http_free_handle(sii->http_handle);
        vm_free(temp);
        return -2;
    }
    strcat(temp, "http://localhost HTTP/1.1\r\n");
    memcpy(sii->http_session_ptr->reqbuf+sii->http_session_ptr->nreqbuf, temp, strlen(temp));
    sii->http_session_ptr->nreqbuf = strlen(temp);
    vm_free(temp); 
    /* 请求行组合完毕 	*/

    /* 添加默认请求头 */
    vm_add_default_headers(sii);
    //add_http_request_head(sii->http_session_ptr, "Host", "localhost");
    //add_http_request_head(sii->http_session_ptr, "User-Agent", (VMCHAR*)applib_inet_get_user_agent_string());
    //add_http_request_head(sii->http_session_ptr, "Accept", "*/*");
    //add_http_request_head(sii->http_session_ptr, "Accept-Language", "zh_CN,zh");
    //add_http_request_head(sii->http_session_ptr, "Accept-Charset", "UTF-8,ISO-8859-1,US-ASCII,ISO-10646-UCS-2;q=0.6");
    //add_http_request_head(sii->http_session_ptr, "Accept-Encoding", "identity");
    //add_http_request_head(sii->http_session_ptr, "Connection", "close");

    /* 添加request 中的用户自定义请求头 
    for (i = 0; i < sii->http_request->nhead; i++)
    {*/
        /* 
          * 开始加入用户定义的http head，在此过程中 
          * 如果http head 有重名，那么将会用用户定义
          * 的替换http module默认的值。
        if (0 != (add_http_request_head(sii->http_session_ptr, 
            sii->http_request->heads[i].name, 
            sii->http_request->heads[i].value)) )
        {
            vm_log_warn("{HTTP MODULE} vm_http_fetch_handle - Failed to add http request head. head name: %s", 
                sii->http_request->heads[i].name);
            vm_ret_session_item(sii);
            return -1;
        }
    }
          */

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4036 );
    //vm_log_debug_long(sii->http_session_ptr->reqbuf, sii->http_session_ptr->nreqbuf);

    /* 保存资源 
    if (VM_RES_OK != vm_res_set_data(VM_RES_TYPE_HTTP_HANDLE, res_handle, (void *)sii, res_size) )
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4042 , res_handle);
        vm_ret_session_item(sii);
        res_handle = -1;
    }*/

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4047 , current_handle);

    return res_handle;
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_get_current_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_get_current_handle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4072 , current_handle);
    return current_handle;
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_set_current_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_set_current_handle(VMINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
        current_handle = handle;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4099 , current_handle);
    return current_handle;
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_free_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_http_free_handle(VMINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * 1. callback ing
     * sii->user_terminate_flag = TRUE;
     * sii->sessionInStateNotifyFunc = 0;
     * sii->http_state_notify = NULL;
     * 2. no callback ing
     * vm_tcp_close
     * vm_ret_session_item
*/
    VMINT ret = -1;
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle < 0)
        return;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4139 , handle);

    /* 释放资源数据 */
    ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&sii, &res_size);
    if (VM_RES_OK != ret)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4145 , ret, handle, current_handle);
        return;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4148 , ret, handle, current_handle);

    if (sii && sii->http_session_ptr)	/* session_item_info有效 */
    {
        if (sii->callback_lock == 0)	/* 进程不处于回调状态 */
        {
            vm_tcp_close(sii->socket_handle); 
            vm_ret_session_item(sii);
            
            /* 
             * vm_ret_session_item中释放资源的操作可能执行不到，
             * 再释放一次保证资源被释放 。
             */
            if (VM_RES_OK != 
                vm_res_release_data(VM_RES_TYPE_HTTP_HANDLE, handle) )
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4164 , handle, current_handle);
            }
            
            current_handle = -1;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4168 , handle);
        }
        else		/* 进程处于回调状态 */
        {
            /* 
             * 正在运行应用回调函数, 设置用户终止标识, 
             * 回调结束后由系统关闭连接并释放资源 
             */
            sii->user_terminate_flag = TRUE;
            sii->sessionInStateNotifyFunc = 0;
            sii->http_state_notify = NULL;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4179 , handle);
        }
        //return 0;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4184 , current_handle);
    
    //return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_set_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  url         [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_set_url(VMINT handle, VMCHAR * url, VMINT len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * 1. vm_res_get_data
     * 2. sii->req_url = url
     * 3. vm_res_set_data
*/
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle < 0 || url == NULL || len <= 0)
        return -1;
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4222 , handle, len);
    
    if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&sii, &res_size) ) 
    {
        sii->req_url = url;
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4228 , handle);
        //vm_log_debug_long(sii->req_url, strlen(sii->req_url));

/*
        if (VM_RES_OK == vm_res_set_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void *)sii, res_size) )
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4234 , handle);
            return 0;
        }
*/
        return 0;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4240 , handle, len);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_add_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  name        [?]         
 *  value       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_add_header(VMINT handle, VMCHAR* name, VMCHAR* value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * FLOW:
     * operation reqbuf directly
     * ------------------------------------------------------------
     * Header Fields  |Host=localhost
     * |User-Agent=$USER_AGENT$
     * |Accept=* / *
     * |Accept-Language=zh_CN,zh
     * |Accept-Charset=UTF-8,ISO-8859-1,US-ASCII,ISO-10646-UCS-2;q=0.6
     * |Accept-Encoding=identity
     * |Connection=close
     * |...... (user customized headers)
     * ------------------------------------------------------------
     * 1. add new header
     * 2. replace existing header
*/
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle < 0 || name == NULL || value == NULL)
        return -1;
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4287 , handle);
    
    if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&sii, &res_size) )
    {
        if (add_http_request_head(sii->http_session_ptr, name, value) == 0 )
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4293 , name, value);
            //vm_log_debug_long(sii->http_session_ptr->reqbuf, sii->http_session_ptr->nreqbuf);
            return 0;
        }
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4299 , handle);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_http_set_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  data        [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_set_body(VMINT handle, VMUINT8 * data, VMINT len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*TODO:
     * ---------------------------------------------
     * Content-Length: $len$\r\n
     * ---------------------------------------------
     * CRLF
     * ---------------------------------------------
     * $body$
     * ---------------------------------------------
*/
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle < 0 || len <= 0)
        return -1;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4339 , len);

    if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&sii, &res_size) )
    {
        sii->req_body = data;
        sii->req_body_length = len;
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4346 , len);
        //if (data != NULL)
            //vm_log_debug_long((char*)sii->req_body, sii->req_body_length);
        return 0;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4352 , len);
    return -1;
}

/*FLOW:
call receiver after head
*/

static VMINT vm_http_reg_int_cb(VMINT type, VMINT handle, void * cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle < 0 || cb == NULL)
        return -1;
    
    
    if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&sii, &res_size) )
    {
        if (0 == type)
            sii->receiver = (void*)cb;
        else if (1 == type)
            sii->sender = (void*)cb;
        return 0;
    }
    
    return -1;
}
/*****************************************************************************
 * FUNCTION
 *  vm_http_reg_receiver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  reciever        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_reg_receiver(VMINT handle, http_data_receiver reciever)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    return vm_http_reg_int_cb(0, handle, (void *)reciever);
    
}

/*FLOW:
call sender after head
*/


/*****************************************************************************
 * FUNCTION
 *  vm_http_reg_sender
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  sender      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_reg_sender(VMINT handle, http_data_sender sender)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_http_reg_int_cb(1, handle, (void *)sender);
}

/*TODO:
how to stop sending?
1. the app know before sending, nodify mre by content-length
2. the app know after sending start
3. the app know at the end of sending, nodify mre by 
    call vm_http_send_data with len=0
    return value of sender, >0 means finished
*/


/*****************************************************************************
 * FUNCTION
 *  vm_http_send_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  data        [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_send_data(VMINT handle, VMUINT8* data, VMINT len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_size = 0;
    VMINT ret = -1;
    session_item_info* sii = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*NOTE:
-------------------------------------------------------------------
       Chunked-Body   = *chunk
                        last-chunk
                        trailer
                        CRLF
       chunk          = chunk-size [ chunk-extension ] CRLF
                        chunk-data CRLF
       chunk-size     = 1*HEX
       last-chunk     = 1*("0") [ chunk-extension ] CRLF
       chunk-extension= *( ";" chunk-ext-name [ "=" chunk-ext-val ] )
       chunk-ext-name = token
       chunk-ext-val  = token | quoted-string
       chunk-data     = chunk-size(OCTET)
       trailer        = *(entity-header CRLF)
-------------------------------------------------------------------

FLOW:
check message encode (req_body_encode : fixbody, chunk)
    stream
        vm_tcp_write
    chunk
        make chunk_buffer
        vm_tcp_write
        check buffer
            empty
                return
            not empty
                vm_tcp_write -^

*/
    /* 检查参数 */
    if (handle <0 || data == NULL || len <= 0)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4508 , handle, data, len);
        return OP_ERROR;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4512 , handle, len);

    /* 取得资源中的session_item_info */
    if (vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&sii, &res_size) == VM_RES_OK )
    {
        if (sii->req_body_length > 0)	/* 直接发送数据块 */
        {
             MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4519 , sii->socket_handle);
            //vm_log_debug_long((char*)data, len);

            if ((unsigned int)(sii->sent) < (unsigned int)(sii->http_session_ptr->nreqbuf+sii->req_body_length))
            {/* 请求体尚未发送完成 */
            
                ret = vm_tcp_write(sii->socket_handle, data, len);
                
                sii->sent += ret;
                
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4529 , ret, sii->socket_handle);
            }
            else		/* 请求体已发送完成 */
            {
                return 1;
            }
        }
        else		/* 以chunk编码方式发送数据块 */
        {
            /* 数据块大小超过缓冲区的大小 */
            if (len > HTTP_REQUEST_BUFSIZE)
                return -1;
            
            /*NOTE: 在调用sender前执行此逻辑
             * 前一个数据块尚未发送成功，继续发送直至完成。
            while(sii->chunk_buffer_sent < sii->chunk_buffer_length)
            {
                ret = vm_tcp_write(sii->socket_handle,
                    sii->chunk_buffer_ptr+sii->chunk_buffer_sent, 
                    sii->chunk_buffer_length-sii->chunk_buffer_sent)
                if (ret > 0)
                {
                    sii->chunk_buffer_sent += ret;
                }
                else		//blocked, or error
                {
                    return ret;
                }
            }
             */

/*NOTE:
Chunked-Body
-------------------------------------
chunk-size 		|0f 0a 1b 67 CRLF	(octet 8位元组，不需考虑网络字节序)
chunk-data 		|$data$ CRLF
-------------------------------------
......
last-chunk----------------------------
chunk-size 		|00000000 CRLF
-------------------------------------
            |CRFL
-------------------------------------
*/
            /* 
             * 根据当前data数据构造新的chunk数据块 
             */
            memset(sii->chunk_buffer_ptr, 0, HTTP_REQUEST_BUFSIZE);
            sprintf((char*)sii->chunk_buffer_ptr, "%x\r\n", len);
            sii->chunk_buffer_length = strlen((char*)sii->chunk_buffer_ptr);
            
            memcpy(sii->chunk_buffer_ptr+sii->chunk_buffer_length, data, len);
            sii->chunk_buffer_length += len;

            memcpy(sii->chunk_buffer_ptr+sii->chunk_buffer_length, CRLF, CRLF_LEN);
            sii->chunk_buffer_length += CRLF_LEN;
            
            sii->chunk_buffer_sent = 0;

            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4588 , len, sii->chunk_buffer_length);
            //vm_log_debug_long((char*)sii->chunk_buffer_ptr, (int)sii->chunk_buffer_length);

            /* 
             * 发送新的chunk数据块 ，对应用来说发送已经完成。
             */
            while(sii->chunk_buffer_sent < sii->chunk_buffer_length)
            {
                ret = vm_tcp_write(sii->socket_handle, 
                    sii->chunk_buffer_ptr+sii->chunk_buffer_sent, 
                    sii->chunk_buffer_length-sii->chunk_buffer_sent);
                if (ret > 0)
                {
                    sii->chunk_buffer_sent += ret;
                }
                else if (ret == 0)	//block
                {
                /*
                 * 若阻塞，数据块保留在chunk_buffer_ptr中，
                 * 将在系统收到can write消息后继续发送 。
                 */
                    MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMHTTP_4609 , handle, data, len);
                    break;
                }
                else		//error
                {
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4614 , handle, data, len);
                    return ret;
                }
            }

            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4619 , 
                sii->chunk_buffer_length, sii->chunk_buffer_sent);

            ret = sii->chunk_buffer_sent;
        }
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4626 , handle, len);
    return ret;
}

/*NOTE:
how to stop recving?
1. App does not know, the mre know by chunk, mre should nodify app
    nodify by return value of vm_http_recv_data, ==0 means block, >0 means data read, 
    nodify by return value & data, when data is CRLF, chunk end.
    nodify by a new interface, vm_http_response_eof(handle), TRUE when chunk end.
2. App knows, by the content-length, and app nodify mre, by returning a >0 int
*/


/*****************************************************************************
 * FUNCTION
 *  vm_http_recv_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  data        [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_http_recv_data(VMINT handle, VMUINT8* data, VMINT len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*TODO:
REQUEST:
http://61.236.127.192/ucenter/data/avatar/000/00/00/01_avatar_middle.jpg
Host:61.236.127.192

RESPONSE
------------------------------------------------------
HTTP/1.1 200 OK
Date: Tue, 17 Nov 2009 06:51:10 GMT
Server: Apache/2.2.4 (Win32)
Last-Modified: Thu, 10 Jul 2008 06:18:27 GMT
ETag: "1911-cb5-64b4359d"
Accept-Ranges: bytes
Content-Length: 3253
Content-Type: image/jpeg
------------------------------------------------------
*/
    VMINT ret = -1;
    VMINT buffer_size = 0;	/* 对应sii->buffer->buffer */
    //VMINT data_read = 0;		/* data中已经填充的数据大小 */
    VMINT res_size = 0;
    session_item_info* sii = NULL;
    VMUINT8* ptr = NULL;
    VMUINT i = 0;
    http_response_buffer_t* buf_tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4685 , handle, len);

    /* 检查参数 */
    if (handle <0 || data == NULL || len <= 0)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4690 , handle, data, len);
        return OP_ERROR;
    }
    
    /* 取得资源中的session_item_info */
    if (vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&sii, &res_size) == VM_RES_OK )
    {
        /*
         * 计算buffer缓存中存放数据或每次从TCP管道中读取数据的最大值:
         * 应大于HTTP_MIN_CHUNK_SIZE (16)，并小于RESPONSE_BUFFER_SIZE (1024*2)。
         */
        buffer_size = MAX(HTTP_MIN_CHUNK_SIZE, len);
        buffer_size = MIN(buffer_size, RESPONSE_BUFFER_SIZE);
        buf_tmp = sii->buffer;
        while(1)
        {
            /*
              * 若响应体以chunk方式编码，则填充buffer。
              * 使buffer中始终有buffer_size大小的数据。
              */
            if ((buf_tmp->receive_type != fixed_body) && 
                ((unsigned int)(buf_tmp->receive_num) < (unsigned int)(buffer_size)) )
            { 
                MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4713 , buffer_size);
                //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
                
                if ((ret = vm_tcp_read(sii->socket_handle, 
                    buf_tmp->buffer+buf_tmp->receive_num, 
                    buffer_size-buf_tmp->receive_num ) ) > 0)
                {
                    buf_tmp->receive_num += ret;
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4722 , ret);
                    //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
                }
                else if (0 == ret)
                {
                    return OP_BLOCK;
                }
                else
                {
                    /* 判断TCP管道数据是否读完 */
                    if (VM_TCP_READ_EOF != ret)
                        return OP_ERROR;
                }
            }
                
            switch (buf_tmp->receive_type)
            {
            case fixed_body:	
            case read_eof:	
            /* 定长编码方式接收响应体数据，不改变buffer中的数据 */
                
                /*
                 * 在vm_http_read_data中，buffer已经读取了一段数据，
                 * 其中包括响应头与可能的部分响应体。
                 * 调用下载回调函数时，已经完成响应头的解析
                 * 并把响应头移出buffer，此时buffer中剩下的数据
                 * 就是响应体了。
                 */
                
                if (sii->read < buf_tmp->receive_num)
                {/* buffer 中仍有数据未读完 */
                
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4754 , (int)buf_tmp->receive_num);
                    //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
/*FLOW: 
copy data from buffer to "data"
    compare receive_num to len
    if receive_num >= len
        copy len
    if receive_num < len
        copy receive_num

receive_num -= len;

move buffer data;
*/
                    /* 根据buffer中数据长度与len大小决定接收的数据块大小 */
                    ret = MIN((unsigned int)(buf_tmp->receive_num-sii->read), (unsigned int)(len));

                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4771 , ret, sii->read, buf_tmp->receive_num);

                    /* 保存数据至应用的数据块缓冲 */
                    memset(data, 0, len);
                    memcpy(data, buf_tmp->buffer+sii->read, ret);
                    sii->read += ret;
                    //sii->buffer->receive_num -= ret;
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4779 , ret, sii->read, buf_tmp->receive_num);
                }
                else  /* buffer 中的数据已经读完 */
                {
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4783 , len, sii->socket_handle);

                    ret = vm_tcp_read(sii->socket_handle, data, len);

                    /* 判断TCP管道数据是否读完 
                    if (VM_TCP_READ_EOF == ret)
                        return OP_COMPLETE;*/
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4791 , ret, sii->socket_handle);
                }

                break;
            case chunk_size:
            /* chunk编码方式接收响应体数据，以buffer作为chunk缓存 */
/*NOTE:
buffer sketch:
-------------------------------------------
|chunk size CRLF chunk data CRLF  	  		    | 
-------------------------------------------
|chunk size ; chunk extension CRLF  			    | 
-------------------------------------------
|chunk size ; chunk extension 1; chunk extension 2| 
-------------------------------------------
|						  		  		    | 
-------------------------------------------
chunk size example: 01 0f a0 0a (8 bytes)

get chunk_size from buffer
    make sure the buffer is start from shunk size
check if chunk extension exist
goto chunk_data

*/
                
                if (sii->buffer->receive_num > 0)
                {/* buffer 中有数据 */
                
                    VMUINT8 *p1 = NULL, *p2 = NULL;
                    //VMUINT len = 0;

                    /*TODO:
                    check if chunk-extension exist ?
                     *   如果有chunk-extension则从buffer里移除。
                     */
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4828 , buf_tmp->receive_num, sii->read);
                    //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
                    
                    /* 在buffer 中找第一个CRLF符，之前的内容为chunk size */
                    if ( (p1 = (VMUINT8*)strstr((char*)buf_tmp->buffer, CRLF)) != NULL)
                    {
                        VMUINT8 size_str[9];
                        VMINT chunk_data_size = 0;

                        memset(size_str, 0, sizeof(size_str));
                        
                        /* chunk size 长度应该不超过8个字节 */
                        if ((p1 - buf_tmp->buffer) > (sizeof(size_str) - 1))
                        {
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4842 );
                            return OP_ERROR;
                        }

                        /* 获取表示chunk size 的数据段 */
                        for (p2 = buf_tmp->buffer; p2 < p1; p2++)
                            *(size_str + (p2 -  buf_tmp->buffer)) = *p2;
                        
                        /* 计算chunk size  */
                        if (hex_cstring_to_oct(size_str, &chunk_data_size) != 0)
                        {
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4853, size_str);
							
                            return OP_ERROR;
                        }
                        else		/* 有效的chunk size */
                        {
                            MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4859 , size_str, chunk_data_size);
                            //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
                                
                            if (chunk_data_size >= 0)
                            {
                                /*
                                 * 从buffer中移出chunk size和CRLF。
                                 */
                                p2 = p1 + CRLF_LEN;
                                p1 = buf_tmp->buffer;
                                while (p2 < buf_tmp->buffer + RESPONSE_BUFFER_SIZE)
                                    *p1++ = *p2++;
                                if (p1 < buf_tmp->buffer + RESPONSE_BUFFER_SIZE)
                                    memset(p1, 0, (buf_tmp->buffer + RESPONSE_BUFFER_SIZE) - p1);
                                buf_tmp->receive_num -= (p2 -p1);
/*
                                sii->buffer->receive_num -= 
                                    _vm_move_buffer_data(p1, p2, sii->buffer->receive_num);
*/

                            
                                buf_tmp->chunk_size = chunk_data_size;

                                if (buf_tmp->chunk_size == 0)
                                {/* chunk size 为0, 说明为最后一个chunk */

                                    /* 
                                     * 读到结束chunk，将CRLF返回给应用，
                                     * 表示响应体数据接收完成。
                                     */
                                    memcpy(data, CRLF, CRLF_LEN);
                                    ret = CRLF_LEN;
                                    return ret;

                                    /*TODO:
                                    how to deal with the chunk-trailer?
                                    */
                                    //sii->buffer->receive_type = chunk_trailer;
                                    //goto CHUNK_TRAILER;
                                }
                                else  /* chunk size > 0，继续读chunk data */
                                {
                                    /* 响应体长度增加chunk size大小 */
                                    sii->http_session_ptr->nresbody += chunk_data_size;
                                    buf_tmp->receive_type = chunk_data;

                                    /* 
                                     * 下面将直接进入case chunk_data的代码段。
                                     */
                                    
                                    //continue;
                                    //goto CHUNK_DATA;
                                }
                            }
                            else		/* chunk size < 0，返回错误 */
                            {
                                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_4915 , size_str);
                                return OP_ERROR;
                            }
                        }
                    }
                }
                
                //break;
            case chunk_data:
/*TODO:
-------------------------------------------
|chunk data 1 CRLF chunk size 2 CRLF chunk data 2| start to read chunk data 1
-------------------------------------------
|CRLF chunk size 2, chunk data 2 CR                    | finish read chunk data 1, femove CRLF from buffer, goto chunk size next time
-------------------------------------------
|chunk data 2 CR                                                | start to read chunk data 2
-------------------------------------------
|CR                                                                    | finish read chunk data 1, data in buffer not enough, read from tcp imediately
---------------------------------------------------
|chunk data 3            	                                       | chunk data 3 longer than buffer size
-------------------------------------------
|			           	                                       | buffer empty, read from tcp imediately
-------------------------------------------

1. if (sii->buffer->chunk_size >0)
    check receive_num
        receive_num == 0
            read data from tcp to buffer
        receive_num > 0
            read from buffer

2. if (sii->buffer->chunk_size == 0),
    if (sii->buffer->receive_num < CRLF_LEN )
        read from tcp imediately
    if no CRLF in buffer
        error
    if CRLF in buffer head, remove CRLF from buffer

*/
                /* 
                 * 从chunk缓存中读取chunk size大小的数据 。
                 */
                if (buf_tmp->chunk_size > 0)
                {
                    /*
                      * buffer 中有数据，拷贝chunk data 至data。
                      */
                    if (buf_tmp->receive_num > 0)
                    {
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4964 , ret, buf_tmp->chunk_size, buf_tmp->receive_num, sii->read);
                        //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
                        
                        /* 
                         * 确定要复制的数据段大小，
                         * 为len, sii->buffer->chunk_size, sii->buffer->receive_num中的最小值。
                         */
                        ret = MIN(buf_tmp->chunk_size, buf_tmp->receive_num);
                        ret = MIN(ret, len);

                        /* 保存数据至应用的数据块缓存 */ 
                        memcpy(data, buf_tmp->buffer, ret);

                        sii->read += ret;				/* 已接收响应体大小增加。*/
                        buf_tmp->chunk_size -= ret;	/* 待接收的chunk size 的减小。*/

                        /* 
                         * 从buffer中移出已保存给应用的数据 
                         */
                        for (i = 0; i < (buf_tmp->receive_num - ret); i++)
                            *(buf_tmp->buffer  + i) = *(buf_tmp->buffer  + i + ret);
                        memset(buf_tmp->buffer + i, 0, ret);
                        buf_tmp->receive_num -= ret;
/* 
                        sii->buffer->receive_num -= _vm_move_buffer_data(sii->buffer->buffer, 
                            sii->buffer->buffer + ret, sii->buffer->receive_num);
*/


                        MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_4993 , ret, buf_tmp->chunk_size, buf_tmp->receive_num, sii->read);
                        //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
                    }
                }
/*TODO:
1. app get len data, chunk size > 0, buffer not blank
2. chunk size in data, continue reading, chunk size =0, to read next chunk
3. data not full, continue reading, chunk size >0, to refill buffer

any time when buffer is blank, read buffer first
*/

                if (buf_tmp->chunk_size == 0)
                {/* 读完了一段chunk */
                
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_5008 , buf_tmp->chunk_size, buf_tmp->receive_num, sii->read);
                    //vm_log_debug_long((char*)sii->buffer->buffer, (int)sii->buffer->receive_num);
                    
                    /* 
                     * buffer 头部有应该有CRLF 符，表示chunk块结束。
                     */
                    if ((ptr = (VMUINT8*)strstr((char*)buf_tmp->buffer, CRLF)) != NULL)
                    {
                        /*
                         * CRLF应在buffer里的首地址位置上，从buffer里移出。
                         */
                        if (buf_tmp->buffer == ptr)	
                        {
                            unsigned int i = 0;

                            /*
                             * 从buffer中移除CRLF。
                             */
                            for (i = 0; i < (buf_tmp->receive_num - CRLF_LEN); i++)
                                *(buf_tmp->buffer + i) = *(buf_tmp->buffer + i + CRLF_LEN);
                            buf_tmp->receive_num -= CRLF_LEN;
                            memset(buf_tmp->buffer + buf_tmp->receive_num, 
                                0, RESPONSE_BUFFER_SIZE - buf_tmp->receive_num);
/*
                            sii->buffer->receive_num -= _vm_move_buffer_data(sii->buffer->buffer, 
                                sii->buffer->buffer + CRLF_LEN, sii->buffer->receive_num);
*/


                            /* 下次调用时继续读下一个chunk */
                            buf_tmp->receive_type = chunk_size;
                            //continue;
                            //goto CHUNK_SIZE;
                        }
                        else		
                        {
                        /* 
                         * 若一个chunk结束后没有CRLF，编码出现错误 
                         */
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_5047 );
                            return OP_ERROR;
                        }
                    }
                    else
                    {
                    /*
                     * 此时buffer中没有CRLF，可能有2中可能:
                     * 1. buffer中数据不足
                     * 2. chunk编码错误
                     */
                        if (buf_tmp->receive_num >= CRLF_LEN)
                        {/* chunk编码错误*/
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMHTTP_5060 );
                            return OP_ERROR;
                        }
                        else
                        {/* buffer中剩余数据长度< CRLF的长度*/

                            /* 继续读数据至buffer */
                            continue;
                        }
                    }
                }
                break;
            case chunk_trailer:
                /*TODO:
                not implemented
                */
                break;
            default:
                return OP_ERROR;
                //break;
            }

            break;	/* 默认只循环1 次 */
        }
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMHTTP, TRC_MRE_VMHTTP_5086 , handle, len);
    return ret;
}

	//abm hold
VMUINT32 vm_get_http_acctid_by_resid(VMINT res_id)
{
    session_item_info * info = NULL;
    info = vm_get_item_info(res_id, 1);
    if (NULL == info)
        return 0;
    return info->account_id;
}


//#endif

#endif /* __MRE_LIB_HTTP__ */

