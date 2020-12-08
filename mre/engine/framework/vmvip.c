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

#ifdef __MRE_LIB_NETWORK_VIP__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vmio.h"
#include "vmvip.h"
#include "vmhttp.h"
#include "vmsys.h"

#include "vmchset.h"
#include "vmmod.h"
#include "vmgraph.h"

#ifdef __MRE_LIB_NETWORK_VIP_VG__

#ifndef VIP12
#include "vmcermng.h"
#include "vmrsa.h"
#include "vmdes.h"
#include "vmmd5.h"
#include "vmpkcs.h"
#endif /* VIP12 */ 

#ifdef VIP14
#include "vmnvram.h"
#include "vmsock.h"
#include "vmsim.h"
#include "vmtimer.h"
#include "vmsms.h"
#endif /* VIP14 */ 

#include "vmlog.h"

//#include "phsh.h"
//#include "phpic.h"

#define STORE_USE_ID_FILE_NAME         "user.dat"
#define MRE_SUPPORT_VIP_SESSION_MAX_NUM   (3)
#define POOL_SIZE                   MRE_SUPPORT_VIP_SESSION_MAX_NUM

static VMINT g_is_updating = FALSE;


extern VMINT vm_is_ready_dataaccount(void);


#ifdef VIP12

/************************************************************************/
/* static file range variable                               */
/************************************************************************/

#define  PARSE_CATCH_LEN            1024
#define  VIP_LINE_BUF_LEN               1024

/*
 * 机型号
 */
static int phone_id;

/*
 * 用户编号
 */
static int user_id = 0;

/*
 * VIP协议会话号
 */
static char session_id[255];

/*
 * VIP会话上下文池。
 */
static session_pool_item_t *session_pool = NULL;

/*
 * 客户程序注册上来的回调函数。
 */
static vm_vip_callback vip_callback;

/*
 * 重连的http request 。
 */
static http_request_t vm_retry_http_req;

/* 
 * 重连的http request 里的heads 结构 
 */
static http_head_t vm_retry_heads[5];

/* 
 * 重连的http request 里的body 结构 
 */
static char *vm_retry_reqbuf = NULL;

/* 
 * 是否需要重连的标志 
 */
static int retry_link = TRUE;

/************************************************************************/
/* static function prototype                                                                    */
/************************************************************************/
/*
 * 初始化VIP模块的函数。
 */
static VMINT vm_initialize_vip_module(void);

/*
 * VIP模块的清理函数。
 */
static VMINT vm_finialize_vip_module(void);

/*
 * HTTP 模块的生命周期函数。
 */
static VMINT vip_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);

/**
 *shaw
 */
#ifdef APPSTORE_SUPPORT_COFING
static int vip_get_a_line(char *pString);
static VMINT vip_get_key_value(VMCHAR *pLine, VMCHAR *key, VMCHAR *value);
#endif /* APPSTORE_SUPPORT_COFING */ 

static VMINT overflow(BYTE *cur, int len, BYTE *end);
static BYTE *packint(BYTE *p, int v, BYTE *end);
static BYTE *packbyte(BYTE *p, BYTE v, BYTE *end);
static BYTE *packasciistr(BYTE *p, char *s, BYTE *end);

/* static BYTE* unpackbyte(BYTE *p, BYTE *v, BYTE* end); */
static BYTE *unpackint(BYTE *p, int *v, BYTE *end);
static BYTE *unpackstr(BYTE *p, char *s, int size, BYTE *end);
static http_session_t *get_session(void);
static void return_session(http_session_t *session);
static void http_hook_func(int state, void *session_ptr);
static void http_proxy_hook(int state, void *session_ptr);
static void build_provision_url(char *url);
static BYTE *plus_connect_cmd(BYTE *p, BYTE *end);
static BYTE *process_price_info(BYTE *p, BYTE *end);
static BYTE *process_rescontent(BYTE *p, BYTE *end);
static BYTE *process_error(BYTE *p, BYTE *end);
static BYTE *process_wap_proxy(BYTE *p, BYTE *end);
static BYTE *process_wap_payment_complete(BYTE *p);
static BYTE *process_user_info(BYTE *p, BYTE *end);


/*****************************************************************************
 * FUNCTION
 *  _vm_reg_vip_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_vip_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res_code = REG_MRE_MODULE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res_code = _vm_reg_module("VIP MODULE", (MOD_EVT_PROCESS) vip_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_282 , res_code); */
    }

    return res_code;
}


/*****************************************************************************
 * FUNCTION
 *  register_vip_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pf      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_vip_callback(vm_vip_callback pf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vip_callback = pf;
}


/*****************************************************************************
 * FUNCTION
 *  vip_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phoneid     [IN]        
 *  userid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vip_init(int phoneid, int userid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retry_link = TRUE;
    strcpy(session_id, "");

    //      phone_id = phoneid;
    //      user_id = userid;
    //      strcpy(session_id, "");
    //      retry_link = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  retry_vip_link
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void retry_vip_link(int tid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    http_session_t *session = NULL;
    error_t error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* static error_t error; */

    vm_delete_timer((VMUSHORT) tid);
    if ((session = get_session()) == NULL)
    {
        /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_368 ); */
        error.code = -1;
        sprintf(error.message, "分配SESSION失败");
        if (vip_callback)
        {
            vip_callback(RES_ERROR_CMD, (void*)&error);
        }
    }
    else
    {
        session->hook = http_hook_func;
        if (vm_http_request(&vm_retry_http_req, session) != 0)
        {
            /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_381 ); */
            error.code = -2;
            sprintf(error.message, "发送HTTP 请求失败");
            if (vip_callback)
            {
                vip_callback(RES_ERROR_CMD, (void*)&error);
            }
        }
    }
}

extern VMINT vm_get_nvram_driver(void);


/*****************************************************************************
 * FUNCTION
 *  http_hook_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state           [IN]        
 *  session_ptr     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void http_hook_func(int state, void *session_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char s[255];
    char head_value[255];
    int i;

    /* static error_t error; */
    error_t error;
    http_session_t *session;
    BYTE *p, cmd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    session = (http_session_t*) session_ptr;
    /* 网络错误 */
    if (0 != state)
    {
        error.code = state;
        sprintf(error.message, "网络通信错误：%d", state);
        if (vip_callback)
        {
            vip_callback(RES_ERROR_CMD, (void*)&error);
        }
        return_session(session);
        return;
    }

    /* HTTP响应错误 */
    if (200 != session->res_code)
    {
        error.code = session->res_code;
        sprintf(error.message, "服务器内部错误：%d", session->res_code);
        if (vip_callback)
        {
            vip_callback(RES_ERROR_CMD, (void*)&error);
        }
        return_session(session);
        return;
    }

    /* 走重发流程 */
    if (retry_link && get_http_head(session, "Content-Type", head_value) == 0)
    {
        retry_link = FALSE; /* 无论如何这里都不需要重新连了。 */
        if (strncmp("text/vnd.wap.wml", head_value, 16) == 0)
        {
            if (vm_create_timer(200, (VM_TIMERPROC_T) retry_vip_link) < 0)
            {
                error.code = -3;    /* 表示有推送页面没有处理。 */
                sprintf(error.message, "网络通信错误：%d", state);
                if (vip_callback)
                {
                    vip_callback(RES_ERROR_CMD, (void*)&error);
                }
            }
            return_session(session);
            return;
        }
    }

    p = session->resbody;
    p = unpackstr(p, s, 255, (BYTE*) (session->resbody + session->nresbody));
    strcpy(session_id, s);
    p = unpackint(p, &i, (BYTE*) (session->resbody + session->nresbody));      /* 得到服务器的userid。 */

    if (i != user_id)
    {
        VMCHAR filename[24];
        VMWCHAR wideFilename[24];
        VMFILE fileHandle = -1;

        sprintf(filename, "%c:\\%s", vm_get_nvram_driver(), STORE_USE_ID_FILE_NAME);
        vm_ascii_to_ucs2(wideFilename, 24, filename);
        if ((fileHandle = vm_file_open(wideFilename, MODE_WRITE, TRUE)) >= 0)
        {
            VMUINT written = 0;

            if (vm_file_write(fileHandle, (void*)&i, sizeof i, &written) == sizeof i)
                vm_file_commit(fileHandle);
            vm_file_close(fileHandle);
        }

        user_id = i;
    }

    while ((p - session->resbody) < session->nresbody)
    {
        p = unpackbyte(p, &cmd, (BYTE*) (session->resbody + session->nresbody));
        switch (cmd)
        {
            case RES_PRICE_INFO_CMD:
                p = process_price_info(p, (BYTE*) (session->resbody + session->nresbody));
                break;
            case RES_ERROR_CMD:
                p = process_error(p, (BYTE*) (session->resbody + session->nresbody));
                break;
            case RES_RESCONTENT_CMD:
                p = process_rescontent(p, (BYTE*) (session->resbody + session->nresbody));
                break;
            case RES_PROCESS_WAP_PROXY:
                p = process_wap_proxy(p, (BYTE*) (session->resbody + session->nresbody));
                break;
            case RES_WAP_PAYMENT_COMPLETE:
                p = process_wap_payment_complete(p);
                break;
            case RES_USER_INFO:
                p = process_user_info(p, (BYTE*) (session->resbody + session->nresbody));
                break;
            default:
                break;
        }
    }

    return_session(session);
}


/*****************************************************************************
 * FUNCTION
 *  http_proxy_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state           [IN]        
 *  session_ptr     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void http_proxy_hook(int state, void *session_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //static error_t error;
    //static BYTE buf[8192];
    //static char value[1024];
    //static http_head_t heads[5];

    error_t error;
    BYTE *buf = NULL;
    char *value = NULL;
    http_head_t heads[5];

    http_session_t *reply_session, *session;
    BYTE *p = NULL;
    http_request_t req;
    int i, n;
    char name[255];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != state)
    {
        error.code = state;
        sprintf(error.message, "网络通信错误：%d", state);
        if (vip_callback)
        {
            vip_callback(RES_ERROR_CMD, (void*)&error);
        }
        return;
    }

    session = (http_session_t*) session_ptr;

    reply_session = get_session();
    if (NULL == reply_session)
        return;

    if ((buf = vm_malloc(8192)) == NULL)
        return;
    if ((value = vm_malloc(1024)) == NULL)
    {
        vm_free(buf);
        return;
    }

    memset(&req, 0, sizeof(req));
    build_provision_url(req.url);
    strcpy(heads[0].name, "Vip-Version");
#ifndef LINK_RICH
    strcpy(heads[0].value, "1.2");
#else 
    strcpy(heads[0].value, "2.0");
#endif 

    req.nhead = 1;
    req.heads = heads;

    p = buf;
    p = packbyte(p, REQ_WAP_PROXY_RESULT, (BYTE*) (buf + 8192));
    p = packint(p, session->res_code, (BYTE*) (buf + 8192));

    n = get_http_head_number(session);
    p = packint(p, n, (BYTE*) (buf + 8192));
    for (i = 0; i < n; i++)
    {
        if (get_http_head_by_index(session, i, name, value) == 0)
        {
            p = packasciistr(p, name, buf + 8192);
            p = packasciistr(p, value, buf + 8192);
        }
    }
    p = packint(p, session->nresbody, (BYTE*) (buf + 8192));
    memcpy(p, session->resbody, session->nresbody);
    p = (BYTE*) (p + session->nresbody);
    req.nbody = p - buf;
    req.body = (char*)buf;

    reply_session->hook = http_hook_func;
    vm_http_request(&req, reply_session);

    vm_free(buf);
    vm_free(value);

    return_session(session);
}


/*****************************************************************************
 * FUNCTION
 *  process_price_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *process_price_info(BYTE *p, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static price_t price;
    BYTE b;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&price, 0, sizeof(price));
#ifdef LINK_RICH
    p = unpackbyte(p, &b, end);
    price.usage_mode = b;
    p = unpackint(p, &i, end);
    price.param = i;
    p = unpackint(p, &i, end);
    price.price = i;

    if (price.price > 0)    /* 免费的歌曲. */
    {
        p = unpackbyte(p, &b, end);
        price.pay_method = b;
        if (price.pay_method == PAY_METHOD_BY_SMS)
        {
            p = unpackint(p, &i, end);
            price.charge_info.sms_info.sms_count = i;
            p = unpackstr(p, price.charge_info.sms_info.access_number, 20, end);
            p = unpackstr(p, price.charge_info.sms_info.order, 99, end);
        }
        else
            p = unpackstr(p, price.charge_info.wap_info.reverse_subscribe_url, 180, end);
    }

    p = unpackstr(p, price.download_song_url, 180, end);
#else /* LINK_RICH */ 
    p = unpackbyte(p, &b, end);
    price.usage_mode = b;
    p = unpackbyte(p, &b, end);
    price.param = b;
    p = unpackint(p, &i, end);
    price.price = i;
    p = unpackbyte(p, &b, end);
    price.pay_method = b;
    p = unpackint(p, &i, end);
    while (i-- > 0)
    {
        p = unpackstr(p, price.access_number, 20, end);
        p = unpackstr(p, price.order_cmd, 99, end);
        price.sms_count++;
    }
#endif /* LINK_RICH */ 
    if (vip_callback)
        vip_callback(RES_PRICE_INFO_CMD, (void*)&price);
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  process_wap_payment_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *process_wap_payment_complete(BYTE *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_callback)
    {
        vip_callback(RES_WAP_PAYMENT_COMPLETE, (void*)NULL);
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  process_rescontent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *process_rescontent(BYTE *p, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static res_content_t res_content;

    /* static error_t error; */
    error_t error;
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = unpackint(p, &len, end);
    if (len > res_content.len)
    {
        if (NULL != res_content.buf)
        {
            vm_free(res_content.buf);
            res_content.buf = NULL;
        }
        res_content.buf = vm_malloc(len);
        if (NULL != res_content.buf)
        {
            res_content.len = len;
        }
        else
        {
            strcpy(error.message, "无足够内存保存资源内容。");
            if (vip_callback)
            {
                vip_callback(RES_ERROR_CMD, (void*)&error);
            }
        }
    }

    if (NULL != res_content.buf)
    {
        res_content.len = len;
        memcpy(res_content.buf, p, len);
        if (vip_callback)
        {
            vip_callback(RES_RESCONTENT_CMD, (void*)&res_content);
        }
    }
    p = (BYTE*) (p + len);

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  process_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *process_error(BYTE *p, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* static error_t error; */
    error_t error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = unpackint(p, &error.code, end);
    p = unpackstr(p, error.message, 255, end);

    if (vip_callback)
    {
        vip_callback(RES_ERROR_CMD, (void*)&error);
    }

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  process_user_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *process_user_info(BYTE *p, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static user_info_t user_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = unpackint(p, &(user_info.userid), end);
    p = unpackstr(p, user_info.nickname, 50, end);
    p = unpackstr(p, user_info.password, 50, end);

    if (vip_callback)
    {
        vip_callback(RES_USER_INFO, (void*)&user_info);
    }

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  process_wap_proxy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *process_wap_proxy(BYTE *p, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BYTE method;
    char uri[255], name[20], value[100];
    int i, nhead, nbody;
    http_session_t *session;
    http_request_t req;
    http_head_t heads[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    session = get_session();

    p = unpackbyte(p, &method, end);
    p = unpackstr(p, uri, 255, end);
    p = unpackint(p, &nhead, end);

    for (i = 0; (i < nhead) && (i < 10); i++)
    {
        p = unpackstr(p, name, 20, end);
        p = unpackstr(p, value, 100, end);
        strcpy(heads[i].name, name);
        strcpy(heads[i].value, value);
    }

    p = unpackint(p, &nbody, end);

    if (NULL != session)
    {
        memset(&req, 0, sizeof(req));
        strcpy(req.url, uri);
        req.nhead = nhead;
        req.heads = heads;
        req.nbody = nbody;
        req.body = (char*)p;
        session->hook = http_proxy_hook;
        vm_http_request(&req, session);
    }

    p = (BYTE*) (p + nbody);
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  packint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]         
 *  v       [IN]        
 *  end     [?]         
 * RETURNS
 *  
 *****************************************************************************/
BYTE *packint(BYTE *p, int v, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (overflow(p, 4, end))
        return p;

    p[0] = (BYTE) ((v & 0xFF000000) >> 24);
    p[1] = (BYTE) ((v & 0x00FF0000) >> 16);
    p[2] = (BYTE) ((v & 0x0000FF00) >> 8);
    p[3] = (BYTE) (v & 0x000000FF);

    return (BYTE*) (p + 4);
}


/*****************************************************************************
 * FUNCTION
 *  packasciistr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  s       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *packasciistr(BYTE *p, char *s, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(s);
    if (overflow(p, 4, end))
        return p;
    p = packint(p, len, end);

    if (overflow(p, len * 2, end))
        return p;
    for (i = 0; i < len; i++)
    {
        p[i * 2] = (BYTE) '\0';
        p[i * 2 + 1] = (BYTE) s[i];
    }

    p = (BYTE*) (p + len * 2);

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  packasciistr2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  s       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *packasciistr2(BYTE *p, char *s, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(s);
    if (overflow(p, 4, end))
        return p;
    p = packint(p, len, end);

    if (overflow(p, len, end))
        return p;
    for (i = 0; i < len; i++)
    {
        p[i] = (BYTE) s[i];
    }

    p = (BYTE*) (p + len);

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  packbyte
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]         
 *  v       [IN]        
 *  end     [?]         
 * RETURNS
 *  
 *****************************************************************************/
BYTE *packbyte(BYTE *p, BYTE v, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (overflow(p, 1, end))
        return p;

    p[0] = (BYTE) (v & 0x000000FF);

    return (BYTE*) (p + 1);
}


/*****************************************************************************
 * FUNCTION
 *  unpackint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  v       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *unpackint(BYTE *p, int *v, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (overflow(p, 4, end))
        return p;

    *v = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + (p[3]);
    return (BYTE*) (p + 4);
}

/*
BYTE* unpackbyte(BYTE *p, BYTE *v, BYTE *end) {
	if (overflow(p, 1, end))
		return p;

	*v = p[0];

	return (BYTE*)(p + 1);
}
*/


/*****************************************************************************
 * FUNCTION
 *  unpackstr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p           [?]         
 *  s           [?]         
 *  size        [IN]        
 *  end         [?]         
 * RETURNS
 *  
 *****************************************************************************/
BYTE *unpackstr(BYTE *p, char *s, int size, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len, v;
    BYTE *p2;
    VMUWCHAR t[1024];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p2 = p;
    if (overflow(p, 4, end))
        return p;
    p2 = unpackint(p2, &v, end);
    len = v > size ? size : v;

    memset(t, 0, sizeof(VMUWCHAR) * 1024);
    for (i = 0; (i < len) && (i < 1024); i++)
    {
        t[i] = (VMUWCHAR) (p2[i * 2] << 8) + (p2[i * 2 + 1]);
    }
    /* vm_ucs2_to_gb2312((VMSTR)s, size, (VMWSTR)t); */
    vm_ucs2_to_ascii((VMSTR) s, size, (VMWSTR) t);

    return (BYTE*) (p2 + len * 2);
}


/*****************************************************************************
 * FUNCTION
 *  get_session
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
http_session_t *get_session(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < POOL_SIZE; i++)
    {
        if (!session_pool[i].used)
        {
            session_pool[i].used = 1;
            memset(&session_pool[i].session, 0, sizeof(http_session_t));
            return &session_pool[i].session;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  return_session
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void return_session(http_session_t *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < POOL_SIZE; i++)
    {
        if (&session_pool[i].session == session)
        {
            session_pool[i].used = 0;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vip_read_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  respath     [?]     
 * RETURNS
 *  
 *****************************************************************************/
int vip_read_resource(char *respath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    http_session_t *session;
    http_request_t req;
    BYTE buf[512];
    BYTE *p;
    http_head_t heads[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(req));
    build_provision_url(req.url);
    strcpy(heads[0].name, "Vip-Version");
    strcpy(heads[0].value, "1.2");
    req.nhead = 1;
    req.heads = heads;

    p = buf;
    p = plus_connect_cmd(p, (BYTE*) (buf + 512));
    p = packbyte(p, REQ_READRES_CMD, (BYTE*) (buf + 512));
    p = packasciistr(p, respath, (BYTE*) (buf + 512));
    req.nbody = p - buf;
    req.body = (char*)buf;

    if ((session = get_session()) == NULL)
        return -1;
    session->hook = http_hook_func;

    /* 准备重发的数据开始 */
    memset(&vm_retry_http_req, 0x00, sizeof(vm_retry_http_req));
    memset(&vm_retry_heads, 0x00, sizeof(vm_retry_heads));
    memset(vm_retry_reqbuf, 0x00, sizeof(HTTP_REQUEST_BUFSIZE));
    build_provision_url(vm_retry_http_req.url);
    strcpy(vm_retry_heads[0].name, "Vip-Version");
    strcpy(vm_retry_heads[0].value, "1.2");
    vm_retry_http_req.nhead = 1;
    vm_retry_http_req.heads = heads;
    if (req.nbody < HTTP_REQUEST_BUFSIZE)
    {
        memcpy(vm_retry_reqbuf, req.body, req.nbody);
        vm_retry_http_req.nbody = req.nbody;
        vm_retry_http_req.body = vm_retry_reqbuf;
    }
    else
        retry_link = FALSE;
    /* 准备重发的数据结束 */

    return vm_http_request(&req, session);
}


/*****************************************************************************
 * FUNCTION
 *  vip_ask_for_price
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pay_point_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int vip_ask_for_price(int pay_point_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* static http_head_t heads[5]; */

    http_head_t heads[5];
    http_session_t *session;
    http_request_t req;
    BYTE buf[255];
    BYTE *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(req));
    build_provision_url(req.url);
    strcpy(heads[0].name, "Vip-Version");
    strcpy(heads[0].value, "1.2");
    req.nhead = 1;
    req.heads = heads;

    p = buf;
    p = plus_connect_cmd(p, (BYTE*) (buf + 255));
    p = packbyte(p, REQ_ASK_FOR_PRICE_CMD, (BYTE*) (buf + 255));
    p = packint(p, pay_point_id, (BYTE*) (buf + 255));
    req.nbody = p - buf;
    req.body = (char*)buf;

    if ((session = get_session()) == NULL)
        return -1;
    session->hook = http_hook_func;

    /* 准备重发的数据开始 */
    memset(&vm_retry_http_req, 0x00, sizeof(vm_retry_http_req));
    memset(&vm_retry_heads, 0x00, sizeof(vm_retry_heads));
    memset(vm_retry_reqbuf, 0x00, sizeof(HTTP_REQUEST_BUFSIZE));
    build_provision_url(vm_retry_http_req.url);
    strcpy(vm_retry_heads[0].name, "Vip-Version");
    strcpy(vm_retry_heads[0].value, "1.2");
    vm_retry_http_req.nhead = 1;
    vm_retry_http_req.heads = heads;
    if (req.nbody < HTTP_REQUEST_BUFSIZE)
    {
        memcpy(vm_retry_reqbuf, req.body, req.nbody);
        vm_retry_http_req.nbody = req.nbody;
        vm_retry_http_req.body = vm_retry_reqbuf;
    }
    else
        retry_link = FALSE;
    /* 准备重发的数据结束 */

    return vm_http_request(&req, session);
}


/*****************************************************************************
 * FUNCTION
 *  vip_get_user_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int vip_get_user_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* static http_head_t heads[5]; */

    http_head_t heads[5];
    http_session_t *session;
    http_request_t req;
    BYTE buf[50];
    BYTE *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(req));
    build_provision_url(req.url);
    strcpy(heads[0].name, "Vip-Version");
#ifndef LINK_RICH
    strcpy(heads[0].value, "1.2");
#else 
    strcpy(heads[0].value, "2.0");
#endif 

    req.nhead = 1;
    req.heads = heads;

    p = buf;
    p = plus_connect_cmd(p, (BYTE*) (buf + 50));
    p = packbyte(p, REQ_GET_USER_INFO, (BYTE*) (buf + 50));
    req.nbody = p - buf;
    req.body = (char*)buf;

    if ((session = get_session()) == NULL)
        return -1;
    session->hook = http_hook_func;

    /* 准备重发的数据开始 */
    memset(&vm_retry_http_req, 0x00, sizeof(vm_retry_http_req));
    memset(&vm_retry_heads, 0x00, sizeof(vm_retry_heads));
    memset(vm_retry_reqbuf, 0x00, sizeof(HTTP_REQUEST_BUFSIZE));
    build_provision_url(vm_retry_http_req.url);
    strcpy(vm_retry_heads[0].name, "Vip-Version");
#ifndef LINK_RICH
    strcpy(vm_retry_heads[0].value, "1.2");
#else 
    strcpy(vm_retry_heads[0].value, "2.0");
#endif 
    vm_retry_http_req.nhead = 1;
    vm_retry_http_req.heads = heads;
    if (req.nbody < HTTP_REQUEST_BUFSIZE)
    {
        memcpy(vm_retry_reqbuf, req.body, req.nbody);
        vm_retry_http_req.nbody = req.nbody;
        vm_retry_http_req.body = vm_retry_reqbuf;
    }
    else
        retry_link = FALSE;
    /* 准备重发的数据结束 */

    return vm_http_request(&req, session);
}

#ifndef LINK_RICH


/*****************************************************************************
 * FUNCTION
 *  vip_pay_by_wap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pay_point_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int vip_pay_by_wap(int pay_point_id)
{   /* 在linkrich的vip版本中，这个指令是没有的。 */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static http_head_t heads[5];

    http_session_t *session;
    http_request_t req;
    BYTE buf[255];
    BYTE *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(req));
    build_provision_url(req.url);
    strcpy(heads[0].name, "Vip-Version");
    strcpy(heads[0].value, "1.2");
    req.nhead = 1;
    req.heads = heads;

    p = buf;
    p = plus_connect_cmd(p, (BYTE*) (buf + 255));
    p = packbyte(p, REQ_PAY_BY_WAP, (BYTE*) (buf + 255));
    p = packint(p, pay_point_id, (BYTE*) (buf + 255));
    req.nbody = p - buf;
    req.body = (char*)buf;

    if ((session = get_session()) == NULL)
        return -1;
    session->hook = http_hook_func;

    /* 准备重发的数据开始 */
    memset(&vm_retry_http_req, 0x00, sizeof(vm_retry_http_req));
    memset(&vm_retry_heads, 0x00, sizeof(vm_retry_heads));
    memset(vm_retry_reqbuf, 0x00, sizeof(HTTP_REQUEST_BUFSIZE));
    build_provision_url(vm_retry_http_req.url);
    strcpy(vm_retry_heads[0].name, "Vip-Version");
    strcpy(vm_retry_heads[0].value, "1.2");
    vm_retry_http_req.nhead = 1;
    vm_retry_http_req.heads = heads;
    if (req.nbody < HTTP_REQUEST_BUFSIZE)
    {
        memcpy(vm_retry_reqbuf, req.body, req.nbody);
        vm_retry_http_req.nbody = req.nbody;
        vm_retry_http_req.body = vm_retry_reqbuf;
    }
    else
        retry_link = FALSE;
    /* 准备重发的数据结束 */

    return vm_http_request(&req, session);
}
#endif /* LINK_RICH */ 


/*****************************************************************************
 * FUNCTION
 *  build_provision_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void build_provision_url(char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(session_id) == 0)
        strcpy(url, PROVISION_URL);
    else
        sprintf(url, "%s?session_id=%s", PROVISION_URL, session_id);

#ifdef APPSTORE_SUPPORT_COFING
    /* shaw, 09/04/15 , 读取配置文件中的信息 */
    {
        VMCHAR *pro_url = vm_malloc(255);

        if (pro_url)
        {
            memset(pro_url, 0, 255);
            if (!vip_get_shell_config_value("provision_url", pro_url))
            {
                if (strlen(session_id) == 0)
                    sprintf(url, "%s", pro_url);
                else
                    sprintf(url, "%s?session_id=%s", pro_url, session_id);
            #ifdef PHSH_DEBUG
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_1524 , url);
            #endif 
            }
            vm_free(pro_url);
        }
    }
#endif /* APPSTORE_SUPPORT_COFING */ 

}


/*****************************************************************************
 * FUNCTION
 *  plus_connect_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BYTE *plus_connect_cmd(BYTE *p, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(session_id) > 0)
        return p;

    p = packbyte(p, REQ_CONNECT_CMD, end);
    p = packint(p, user_id, end);
    p = packint(p, phone_id, end);

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  vip_get_user_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int vip_get_user_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return user_id;
}


/*****************************************************************************
 * FUNCTION
 *  overflow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur     [?]         
 *  len     [IN]        
 *  end     [?]         
 * RETURNS
 *  
 *****************************************************************************/
int overflow(BYTE *cur, int len, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (end - cur) < len;
}


/*****************************************************************************
 * FUNCTION
 *  cancel_all_vip_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cancel_all_vip_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_cancel_all_http_sessions();
    if (session_pool)
        memset(session_pool, 0, sizeof(session_pool_item_t) * POOL_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  vip_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vip_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            if (0 != vm_initialize_vip_module())
                return -1;
            break;
        case EVT_MOD_ACTIVE:
            break;
        case EVT_MOD_INACTIVE:
            break;
        case EVT_MOD_RELEASE:
            vm_finialize_vip_module();
            break;
        default:
            /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_1672 , event); */
            return -2;
    }

    return 0;
}

/* 为了支持在Link阶段能够动态链接，而不用宏MRE_SYS_EQUIPMENT_NUMBER */
extern int vm_get_equipment_number(void);


/*****************************************************************************
 * FUNCTION
 *  vm_initialize_vip_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_initialize_vip_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMCHAR filename[24];
    VMWCHAR wideFilename[24];
    VMFILE fileHandle = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phone_id = vm_get_equipment_number();
    vip_callback = NULL;
    retry_link = TRUE;
    memset(session_id, 0x00, 255);
    memset(&vm_retry_http_req, 0x00, sizeof(vm_retry_http_req));
    memset(&vm_retry_heads, 0x00, sizeof(vm_retry_heads));

    if ((session_pool = vm_malloc(POOL_SIZE * sizeof(session_pool_item_t))) == NULL)
        return -1;
    if ((vm_retry_reqbuf = vm_malloc(HTTP_REQUEST_BUFSIZE)) == NULL)
    {
        vm_free(session_pool);
        return -1;
    }
    memset(session_pool, 0x00, POOL_SIZE * sizeof(session_pool_item_t));
    memset(vm_retry_reqbuf, 0x00, HTTP_REQUEST_BUFSIZE);

    /*
     * 从NVRAM的driver读出userid。
     */
    sprintf(filename, "%c:\\%s", vm_get_nvram_driver(), STORE_USE_ID_FILE_NAME);
    /* vm_gb2312_to_ucs2(wideFilename, 24, filename); */
    vm_ascii_to_ucs2(wideFilename, 24, filename);
    if ((fileHandle = vm_file_open(wideFilename, MODE_WRITE, TRUE)) >= 0)
    {
        VMUINT nread = 0;

        if (vm_file_read(fileHandle, (void*)&user_id, sizeof user_id, &nread) != sizeof user_id)
        {
        }
        /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_1735 ); */

        vm_file_close(fileHandle);
    }
    else
    {
        user_id = 0;
        if ((fileHandle = vm_file_open(wideFilename, MODE_CREATE_ALWAYS_WRITE, TRUE)) < 0)
        {
        }   /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_1744 ); */
        else
            vm_file_close(fileHandle);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_finialize_vip_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_finialize_vip_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phone_id = 0;
    user_id = 0;
    vip_callback = NULL;
    memset(session_id, 0x00, 255);
    memset(&vm_retry_http_req, 0x00, sizeof(vm_retry_http_req));
    memset(&vm_retry_heads, 0x00, sizeof(vm_retry_heads));
    retry_link = TRUE;

    if (session_pool)
    {
        vm_free(session_pool);
        session_pool = NULL;
    }

    if (vm_retry_reqbuf)
    {
        vm_free(vm_retry_reqbuf);
        vm_retry_reqbuf = NULL;
    }

    return 0;
}
#else /* VIP12 */ 
/* rencai.xiao 2010/04/20 add imsi and input */
#define VIP13_MAX_CONNECT_COMMAND_LEN        (159 + 20 + 30 + 10)       /* modified by rencai.xiao at 2010/04/19 */
#define ENCRYPT_VIP_COMMAND_LEN              (64 + 4 + 5)
#define MD5_DIGEST_LEN                    (16)
#define DES_PADDING_LEN                   (8)

/* add by shaw, 09/11/05 */
#define VIP14_SUPPORT_CONNECT_NUM               (2)

/**
 * 协议通讯中的上下文。
 */
static vm_vip_item_t *vip_context;

/* add by shaw, 09/11/05 */
static vm_vip_item_t *vip_context_ext[VIP14_SUPPORT_CONNECT_NUM - 1];

/**
 * 错误响应的结构。
 */
static error_t error;

#ifdef _VMDEBUG
static VMPUBKey pubKey = 
{
    0,
    64,
    3,
    {
     0xBB, 0x73, 0x13, 0x98, 0xE4, 0x6F, 0x77, 0xDB,
     0xAB, 0xC8, 0x3A, 0xD1, 0x8E, 0x75, 0x84, 0x93,
     0xB5, 0xA9, 0x99, 0x4F, 0x2C, 0x8C, 0xEF, 0xD7,
     0xB7, 0x8B, 0x69, 0xDA, 0x4E, 0xBD, 0x97, 0x11,
     0x26, 0x2C, 0x50, 0x86, 0x2B, 0x6C, 0xD0, 0xEF,
     0x6A, 0x01, 0x55, 0xDE, 0xC4, 0xE0, 0x9E, 0x1E,
     0x6F, 0x6B, 0xBB, 0x2A, 0x3F, 0x01, 0xB7, 0xC9,
     0x19, 0x11, 0xC4, 0xDD, 0x2E, 0x1F, 0x8F, 0x4B

     //              0xD3,0x2D,0xC0,0x14,0xC5,0x3E,0xB5,0x42,0xE1,
     //              0xCD,0xF9,0xC1,0x64,0xAE,0x4F,0x34,0x18,0x95,
     //              0x94,0x0B,0xE5,0xCE,0x08,0x31,0x3B,0xBD,0xDD,0x99,
     //              0x95,0x72,0x6D,0x07,0x59,0xD4,0xBF,0xA5,0xEB,0xB7,
     //              0x66,0xBB,0x05,0xB4,0xFE,0xE5,0xE1,0x49,0xFD,0xBF,
     //              0x6D,0xA6,0x24,0xC8,0xCB,0x70,0x2F,0x3C,0x10,0xFE,
     //              0x4F,0xC3,0x8A,0x6C,0x0E,0x9F

     },
    {0x01, 0x00, 0x01}
};
#endif /* _VMDEBUG */ 

// static VMPRIKey priKey = {
//      0,
//      64,
//      64,
//      {
//              0xbf, 0x79, 0xcd, 0x46, 0xf4, 0x64, 0x2c, 0xb8, 
//              0x90, 0x65, 0x49, 0xd7, 0x63, 0x1f, 0xbc, 0x15, 
//              0x5a, 0x80, 0x84, 0x44, 0x70, 0x0c, 0x5e, 0x26, 
//              0x7a, 0xc6, 0x5b, 0x25, 0x08, 0xe0, 0xbf, 0xdf, 
//              0xfc, 0xc1, 0x4d, 0xd3, 0xfd, 0x9c, 0xbb, 0xc1, 
//              0xc7, 0x57, 0xa9, 0xec, 0xad, 0x4f, 0x1a, 0x8a, 
//              0xa7, 0xec, 0x8a, 0x7f, 0x60, 0xa7, 0x7b, 0x11, 
//              0xee, 0x7b, 0xf2, 0x7f, 0xa2, 0x18, 0x52, 0xaf
//      },
//      {
//              0x0a, 0x9c, 0x85, 0x73, 0xd9, 0x37, 0x74, 0x03, 
//              0x06, 0x7d, 0x96, 0x8a, 0x09, 0x44, 0x48, 0xf8, 
//              0x25, 0xfb, 0xd9, 0x58, 0xb1, 0x9c, 0xfd, 0xda, 
//              0xc4, 0x13, 0x1a, 0x1a, 0x03, 0x53, 0xf1, 0x4e, 
//              0x2f, 0xd5, 0xa0, 0xad, 0x60, 0xff, 0x3a, 0xbc, 
//              0xe3, 0xb1, 0x5a, 0x32, 0x5f, 0xdc, 0x0a, 0xb6, 
//              0xb6, 0x18, 0x8c, 0x7a, 0xb9, 0x9d, 0x69, 0xce, 
//              0xb5, 0xc0, 0xf0, 0x9c, 0xbd, 0xf8, 0x14, 0x01
//      }
// };
/************************************************************************/
/* local function prototype                                             */
/************************************************************************/
static VMINT overflow(BYTE *cur, int len, BYTE *end);
static BYTE *packint(BYTE *p, int v, BYTE *end);
static BYTE *packbyte(BYTE *p, BYTE v, BYTE *end);
static BYTE *packasciistr(BYTE *p, char *s, BYTE *end);

/* static BYTE* packtime(BYTE *p, vm_time_t* datetime, BYTE *end); */
#ifdef VIP12
static BYTE *unpackbyte(BYTE *p, BYTE *v, BYTE *end);
#endif 
static BYTE *unpackint(BYTE *p, int *v, BYTE *end);
static BYTE *unpackstr(BYTE *p, char *s, int size, BYTE *end);

/* static BYTE* unpacktime(BYTE *p, vm_time_t* datetime, BYTE *end); */
static BYTE *plus_connect_cmd(BYTE *p, BYTE *end);
static void generate_des_key(VMUINT8 des_key[8]);
static void vip_do_res(VMUINT8 *response, VMINT len);
static void repeat_vip_connect(VMINT tid);

/* add by shaw, 09/11/05 */
#ifdef VIP14
static VMINT vip_read_resource_shell(vm_vip_item_t *pContext, VMCHAR *respath,
                                     void (*http_hook_cb) (VMINT, void *),
                                     void (*http_state_cb) (VMINT state, VMINT param, void *session));
static void vip_http_hook_shell(VMINT result, void *session, vm_vip_item_t *pContext,
                                void (*repeat_vip_ct) (VMINT tid), void (*do_res) (VMUINT8 *response, VMINT len));
static void vip_http_state_hook_shell(VMINT httpState, VMINT param, void *session, vm_vip_item_t *pContext);
static void vip_do_res_shell(VMUINT8 *response, VMINT len, vm_vip_item_t *pContext);
static void repeat_vip_connect_shell(vm_vip_item_t *pContext);

static void vip_http_hook_ext(VMINT result, void *session);
static void vip_http_state_hook_ext(VMINT httpState, VMINT param, void *session);
static void vip_do_res_ext(VMUINT8 *response, VMINT len);
static void repeat_vip_connect_ext(VMINT tid);

/* added by rencai.xiao */
#define VIP_CONNECT_TIME_OUT                (1000 * 60)
VMINT g_app_handle_timer;
VMINT g_other_handle_timer;

static void vm_vip_app_handle_proc(VMINT nTimerID);
static void vm_vip_other_handle_proc(VMINT nTimerID);

#define  VIP_GPRS                   (0)
#define  VIP_WIFI                   (1)

#define LOG_VIP
static VMINT g_phoneid = 0;
static VMINT g_userid = 0;

static vm_vip_callback g_callback;  /**<客户程序注册上来的回调函数.              */
static vm_vip_callback g_app_callback;

static vm_vip_progress_callback g_progress_hook;    /**<VIP协议进度的回调函数。 */
static vm_vip_progress_callback g_app_progress_hook;

/* rencai.xiao 2010/04/29 */
#ifdef VIP_CHECK_DOWNLOAD_READY

/* check internal */
#define VIP_CHECK_ACCOUNT_INTERNAL           (100)

/* check data account */
static void vm_vip_check_account_timer_proc(VMINT nTimerID);

/* send request. */
static VMINT vm_vip_send_request(void);

typedef struct Asyn_Data_t
{
    VMINT nTimer;                       /* check timer */
    VMINT nHandle;                      /* connect handle. */
    VMINT nCount;                       /* try count. */
    http_head_t head[2];                /* head */
    asyn_http_req_t request;            /* http request */
    vm_vip_item_t *context;             /* download context */
    http_request_t internal_http_req;   /* internal http request */
    void (*http_hook) (VMINT, void *);  /* http hook callback. */
    void (*http_state_notify) (VMINT state, VMINT param, void *session);        /* http state notify callback */
} Asyn_Data_t;

static Asyn_Data_t asyn_data;
#endif /* VIP_CHECK_DOWNLOAD_READY */ 

VMINT vm_vip_pack_resource_path(BYTE *p, BYTE *pBody, VMCHAR *res_path, VMCHAR *res_type, VMINT *res_size);

/**
 * 判断用哪个连接
 *
 * @param pszPath 资源路径
 *
 * @return VIP_APP_HANDLE:下载应用的连接，VIP_OTHER_HANDLE:非下载应用连接
 */
static VMINT vip_get_connect_handle(VMCHAR *pszPath);

static VMINT vip_get_resource_path(VMCHAR *src_path, VMCHAR *des_url, VMCHAR *des_path);

/**
 * 判断是否是更多下载首页
 */
/* static VMINT vip_is_more_list_first_level(VMCHAR * pszPath); */

/**
 * 从NVRAM中读取连接类型
 */
static VMINT vip_get_connect_type(void);

#ifdef _VMDEBUG
VMINT vm_is_support_wifi(void);
#endif 
#endif /* VIP14 */ 
/************************************************************************/
/* local function definition                                */
/************************************************************************/
#ifdef VIP14
#ifdef _VMDEBUG


/*****************************************************************************
 * FUNCTION
 *  vm_is_support_wifi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_is_support_wifi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FALSE;
}
#endif /* _VMDEBUG */ 


/*****************************************************************************
 * FUNCTION
 *  vip_get_connect_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vip_get_connect_type(void)
{
#ifdef __MRE_PAYMENT_TEMP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef _VMDEBUG
    vm_nvram_appstore_config_t appstore_config;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MRE_SAL_SIM__
    if (vm_sim_card_count() == 0)
        return HTTP_USE_WIFI;
#endif /* __MRE_SAL_SIM__ */ 
    /* return HTTP_USE_WIFI; */

    if (!vm_get_appstore_config(&appstore_config))
    {
        return VIP_GPRS;
    }
    else
    {
        if (appstore_config.update_hint == VIP_WIFI)
            return HTTP_USE_WIFI;
        else
            return HTTP_USE_CMWAP_PRIORITY;
    }
#else /* _VMDEBUG */ 
    return HTTP_USE_CMWAP_PRIORITY;
#endif /* _VMDEBUG */ 

#else /* __MRE_PAYMENT_TEMP__ */ /* #ifdef __MRE_PAYMENT_TEMP__  */
    return HTTP_USE_CMWAP_PRIORITY;
#endif /* __MRE_PAYMENT_TEMP__ */ /* #ifdef __MRE_PAYMENT_TEMP__  */
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  overflow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur     [?]         
 *  len     [IN]        
 *  end     [?]         
 * RETURNS
 *  
 *****************************************************************************/
static VMINT overflow(BYTE *cur, int len, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (end - cur) < len;
}


/*****************************************************************************
 * FUNCTION
 *  packint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]         
 *  v       [IN]        
 *  end     [?]         
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *packint(BYTE *p, int v, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (overflow(p, 4, end))
        return p;

    p[0] = (BYTE) ((v & 0xFF000000) >> 24);
    p[1] = (BYTE) ((v & 0x00FF0000) >> 16);
    p[2] = (BYTE) ((v & 0x0000FF00) >> 8);
    p[3] = (BYTE) (v & 0x000000FF);

    return (BYTE*) (p + 4);
}

// static BYTE* packtime(BYTE *p, vm_time_t* datetime, BYTE *end)
// {
//      if (overflow(p, 14, end))
//              return p;
//      
//      if (datetime)
//      {
//              sprintf((char*)p, "%04d%02d%02d%02d%02d%02d",
//                      datetime->year, 
//                      datetime->mon, 
//                      datetime->day, 
//                      datetime->hour, 
//                      datetime->min, 
//                      datetime->sec);
// 
//              return (p+14);
//      }
// }


/*****************************************************************************
 * FUNCTION
 *  packasciistr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  s       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *packasciistr(BYTE *p, char *s, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(s);
    if (overflow(p, 4, end))
        return p;
    p = packint(p, len, end);

    if (overflow(p, len * 2, end))
        return p;
    for (i = 0; i < len; i++)
    {
        p[i * 2] = (BYTE) '\0';
        p[i * 2 + 1] = (BYTE) s[i];
    }

    p = (BYTE*) (p + len * 2);

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  packasciistr_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  s       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *packasciistr_ex(BYTE *p, char *s, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(s);
    if (overflow(p, 4, end))
        return p;
    p = packint(p, len * 2, end);

    if (overflow(p, len * 2, end))
        return p;
    for (i = 0; i < len; i++)
    {
        p[i * 2] = (BYTE) '\0';
        p[i * 2 + 1] = (BYTE) s[i];
    }

    p = (BYTE*) (p + len * 2);

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  packbyte
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]         
 *  v       [IN]        
 *  end     [?]         
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *packbyte(BYTE *p, BYTE v, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (overflow(p, 1, end))
        return p;

    p[0] = (BYTE) (v & 0x000000FF);

    return (BYTE*) (p + 1);
}


/*****************************************************************************
 * FUNCTION
 *  unpackint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  v       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *unpackint(BYTE *p, int *v, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (overflow(p, 4, end))
        return p;

    *v = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + (p[3]);
    return (BYTE*) (p + 4);
}

#ifdef VIP12


/*****************************************************************************
 * FUNCTION
 *  unpackbyte
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  v       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *unpackbyte(BYTE *p, BYTE *v, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (overflow(p, 1, end))
        return p;

    *v = p[0];

    return (BYTE*) (p + 1);
}
#endif /* VIP12 */ 


/*****************************************************************************
 * FUNCTION
 *  unpackstr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p           [?]         
 *  s           [?]         
 *  size        [IN]        
 *  end         [?]         
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *unpackstr(BYTE *p, char *s, int size, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len, v;
    BYTE *p2;
    static VMUWCHAR t[1024];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p2 = p;
    if (overflow(p, 4, end))
        return p;
    p2 = unpackint(p2, &v, end);
    len = v > size ? size : v;

    memset(t, 0, sizeof(VMUWCHAR) * 1024);
    for (i = 0; (i < len) && (i < 1024); i++)
    {
        t[i] = (VMUWCHAR) (p2[i * 2] << 8) + (p2[i * 2 + 1]);
    }

    /* vm_ucs2_to_gb2312((VMSTR)s, size, (VMWSTR)t); */
    vm_ucs2_to_ascii((VMSTR) s, size, (VMWSTR) t);

    return (BYTE*) (p2 + len * 2);
}

// static BYTE* unpacktime(BYTE *p, vm_time_t* datetime, BYTE *end)
// {
//      if (overflow(p, 14, end))
//              return p;
// 
//      if (datetime)
//      {
//              char str[5] = {0, 0, 0, 0, 0};
// 
//              memcpy(str, p, 4);              
//              datetime->year = atoi(str); /* 年 */
//              
//              memset(str, 0x00, sizeof(str));
//              
//              memcpy(str, p + 4, 2);
//              datetime->mon = atoi(str);  /* 月*/
// 
//              memcpy(str, p + 6, 2);
//              datetime->day = atoi(str);  /* 日 */
// 
//              memcpy(str, p + 8, 2);
//              datetime->hour = atoi(str); /* 小时 */
// 
//              memcpy(str, p + 10, 2);                 
//              datetime->min = atoi(str);  /* 分钟 */
// 
//              memcpy(str, p + 12, 2);                 
//              datetime->sec = atoi(str);  /* 秒数 */
//      }
// 
//      return (p+14);
// }

#ifdef WIN32
#define __packed
#endif 


/*****************************************************************************
 * FUNCTION
 *  generate_des_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  des_key     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void generate_des_key(VMUINT8 des_key[8])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __packed VMINT *ptr = (__packed VMINT*) des_key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr)
    {
        srand((VMUINT) vm_get_tick_count());
        *ptr = rand();
        *(ptr + 1) = rand();
    }
}


/*****************************************************************************
 * FUNCTION
 *  plus_connect_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 *  end     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static BYTE *plus_connect_cmd(BYTE *p, BYTE *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * CONNECT_CMD USER_ID MOBILE_PHONE_ID USER_AGENT MRE_VERSION MTK_VERSION 
     * SCREEN_WIDTH SCREEN_HEIGHT MEMORY_SIZE SUPPORT_KEYPAD SUPPORT_TOUCH
     */
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2452 );
#endif 
    if (p && end && p < end)
    {
        BYTE *curr_ptr = p;
        VMCHAR user_agent[26] = {0};
        VMCHAR mre_version[13] = {0};
        VMCHAR host_version[31] = {0};
        VMCHAR max_mem[7] = {0};
        VMINT mem_val = 0;

        /* 
         * 编码connect命令字，user_id，mobile_phone_id。共9个字节，命令为1
         */
        if (curr_ptr + 9 <= end)
        {
            curr_ptr = packbyte(curr_ptr, REQ_CONNECT_CMD, end);        /* Byte */
        #ifdef VIP14

            curr_ptr = packint(curr_ptr, g_userid, end);    /* word */
            curr_ptr = packint(curr_ptr, g_phoneid, end);   /* word */
        #else /* VIP14 */ 
            curr_ptr = packint(curr_ptr, vip_context->user_id, end);    /* word */
            curr_ptr = packint(curr_ptr, vip_context->mobile_phone_id, end);    /* word */
        #endif /* VIP14 */ 
        }
        else
            return p;

        /* 
         * 编码USER-AGENT。
         */
/*		if (vm_get_sys_property(MRE_SYS_EQUIPMENT_ID, user_agent, sizeof(user_agent)) > 0)
		{
			VMUINT size = 0;
			if ((size = strlen(user_agent)) > 20)
			{
				user_agent[20] = 0x00;
				size = 20;
			}
			if ((curr_ptr + size * sizeof(VMWCHAR) + 4) <= end)
				curr_ptr = packasciistr(curr_ptr, user_agent, end);
			else
				return p;
		}
		else
			return p;
         */

        /* 获取USER_AGENT */
    #ifdef APPSTORE_SUPPORT_COFING
        /* shaw, 09/04/15 , 读取配置文件中的信息 */
        {
            VMCHAR temp_user_agent[26];

            memset(temp_user_agent, 0, sizeof(temp_user_agent));
            if (!vip_get_shell_config_value("user_agent", temp_user_agent))
            {
                VMUINT size = 0;

                memset(user_agent, 0, sizeof(user_agent));
                memcpy(user_agent, temp_user_agent, sizeof(user_agent));
                if ((size = strlen(user_agent)) > 20)
                {
                    user_agent[20] = 0x00;
                    size = 20;
                }
                if ((curr_ptr + size * sizeof(VMWCHAR) + 4) <= end)
                    curr_ptr = packasciistr(curr_ptr, user_agent, end);
                else
                    return p;
            }
            else
            {

/*		
		VMINT size = 0;
		sprintf(user_agent, "Gionee-A10");
		if ((size = strlen(user_agent)) > 20)
		{
		user_agent[20] = 0x00;
		size = 20;
		}
		if ((curr_ptr + size * sizeof(VMWCHAR) + 4) <= end)
		curr_ptr = packasciistr(curr_ptr, user_agent, end);
		else
		return p;
*/
                if (vm_get_sys_property(MRE_SYS_EQUIPMENT_ID, user_agent, sizeof(user_agent)) > 0)
                {
                    VMUINT size = 0;

                    if ((size = strlen(user_agent)) > 20)
                    {
                        user_agent[20] = 0x00;
                        size = 20;
                    }

                    if ((curr_ptr + size * sizeof(VMWCHAR) + 4) <= end)
                        curr_ptr = packasciistr(curr_ptr, user_agent, end);
                    else
                        return p;
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_2555 , user_agent);
                #endif 
                }
                else
                    return p;

            }
        }
    #else /* APPSTORE_SUPPORT_COFING */ 
        {
/*	
	VMINT size = 0;
	sprintf(user_agent, "Gionee-A10");
	if ((size = strlen(user_agent)) > 20)
	{
				user_agent[20] = 0x00;
				size = 20;
	}
				if ((curr_ptr + size * sizeof(VMWCHAR) + 4) <= end)
				curr_ptr = packasciistr(curr_ptr, user_agent, end);
				else
				return p;
*/

            if (vm_get_sys_property(MRE_SYS_EQUIPMENT_ID, user_agent, sizeof(user_agent)) > 0)
            {
                VMUINT size = 0;

                if ((size = strlen(user_agent)) > 20)
                {
                    user_agent[20] = 0x00;
                    size = 20;
                }

                if ((curr_ptr + size * sizeof(VMWCHAR) + 4) <= end)
                    curr_ptr = packasciistr(curr_ptr, user_agent, end);
                else
                    return p;
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_2594 , user_agent);
            #endif 
            }
            else
                return p;

        }

    #endif /* APPSTORE_SUPPORT_COFING */ 

        /* 
         * {
         * sprintf(mre_version, "2.0.0");
         * if ((curr_ptr + (strlen(mre_version) * sizeof(VMWCHAR) + 4)) <= end)
         * curr_ptr = packasciistr(curr_ptr, mre_version, end);
         * else
         * return p;
         * }
         */

        if (vm_get_sys_property(MRE_SYS_VERSION, mre_version, sizeof(mre_version)) > 0)
        {

            if ((curr_ptr + (strlen(mre_version) * sizeof(VMWCHAR) + 4)) <= end)
                curr_ptr = packasciistr(curr_ptr, mre_version, end);
            else
                return p;
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_2622 , mre_version);
        #endif 
        }
        else
            return p;

        /* 
         * 编码宿主平台的版本号。           MTK_VERSION    
         */

        /*     
         * sprintf(host_version, "MT6225_07_VERSION");
         * if ((curr_ptr + (strlen(host_version) * sizeof(VMWCHAR) + 4)) <= end)
         * curr_ptr = packasciistr(curr_ptr, host_version, end);
         * else
         * return p;
         */
        if (vm_get_sys_property(MRE_SYS_HOST_VERSION, host_version, sizeof(host_version)) > 0)
        {
            if ((curr_ptr + (strlen(host_version) * sizeof(VMWCHAR) + 4)) <= end)
                curr_ptr = packasciistr(curr_ptr, host_version, end);
            else
                return p;
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_2646 , host_version);
        #endif 
        }
        else
            return p;

        /* 
         * 编码手机屏幕尺寸。
         */
        if (curr_ptr + 8 <= end)
        {
            curr_ptr = packint(curr_ptr, vm_graphic_get_screen_width(), end);
            curr_ptr = packint(curr_ptr, vm_graphic_get_screen_height(), end);
        }
        else
            return p;

        /* 
         * 编码MRE的内存池大小。
         */

        if (vm_get_sys_property(MRE_SYS_HOST_MAX_MEM, max_mem, sizeof(max_mem)) > 0)
        {
            if ((mem_val = atoi(max_mem)) > 0)
            {
                if ((curr_ptr + 4) <= end)
                {
                #ifdef VIP_SUPPORT_UPLOAD_IMSI
                        if (!g_is_updating)
                        {
                            curr_ptr = packint(curr_ptr, mem_val, end);
                            #ifdef LOG_VIP
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2678 , mem_val);
                            #endif
                        }
                        else
                        {
                            curr_ptr = packint(curr_ptr, mem_val * 1024, end);
                        }
                #else /* VIP_SUPPORT_UPLOAD_IMSI */ 
                    curr_ptr = packint(curr_ptr, mem_val * 1024, end);
                #endif /* VIP_SUPPORT_UPLOAD_IMSI */ 
                }
                else
                    return p;
            }
            else
            {
                //MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2694 , 
                //  mem_val);
                return p;
            }
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2698 , mem_val);
        }
        else
            return p;

/*
 		sprintf(max_mem, "800");
 		if ((mem_val = atoi(max_mem)) > 0)
 		{
 			if ((curr_ptr + 4) <= end)
 				curr_ptr = packint(curr_ptr, mem_val * 1024, end);
 			else
 				return p;
 		}
 		else
 		{
 			//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2714 , 
 			//	mem_val);
 			return p;
 		}
*/
        /*
         * 编码是否支持全键盘和笔触。
         */
#ifdef VIP_SUPPORT_UPLOAD_IMSI
        if (!g_is_updating)
        {
            if(curr_ptr + 5 <= end)
            {
                curr_ptr = packbyte(curr_ptr, 
                    (BYTE)(vm_is_support_keyborad() == TRUE ? 1 : 0), end);
                curr_ptr = packbyte(curr_ptr, 
                    (BYTE)(vm_is_support_pen_touch() == TRUE ? 1 : 0), end);
                //rencai.xiao 2010/04/20 add new input method.
                curr_ptr = packbyte(curr_ptr, //is support FTE?
                    (BYTE)(vm_is_finger_touch_version() == TRUE ? 1 : 0), end);
                curr_ptr = packbyte(curr_ptr, //is support G-sensor?
                    (BYTE)(vm_is_support_gsensor() == TRUE ? 1 : 0), end);
                curr_ptr = packbyte(curr_ptr, //is support camera sensor?
                    (BYTE)(vm_is_support_camera_sensor() == TRUE ? 1 : 0), end);
            }
            else
                return p; 
        }
        else
        {
            if (curr_ptr + 2 <= end)
            {
                curr_ptr = packbyte(curr_ptr, 
                    (BYTE)(vm_is_support_keyborad() == TRUE ? 1 : 0), end);
                curr_ptr = packbyte(curr_ptr, 
                    (BYTE)(vm_is_support_pen_touch() == TRUE ? 1 : 0), end);
            }
            else
                return p;            
        }
#else /* VIP_SUPPORT_UPLOAD_IMSI */
        if (curr_ptr + 2 <= end)
        {
            curr_ptr = packbyte(curr_ptr, 
                (BYTE)(vm_is_support_keyborad() == TRUE ? 1 : 0), end);
            curr_ptr = packbyte(curr_ptr, 
                (BYTE)(vm_is_support_pen_touch() == TRUE ? 1 : 0), end);
        }
        else
            return p;
#endif /* VIP_SUPPORT_UPLOAD_IMSI */


        //rencai.xiao 2010/03/03
        //短信中心
        {
        #if defined(__MRE_SAL_SIM__) && defined(__MRE_SAL_SMS__)

            static vm_sms_get_sc_addr_cb_t sc_addr;

            /* static VMINT8 sc_address[(VM_SMS_MAX_ADDR_LEN + 1)*2]; */
            VMINT sim_index;
    #ifdef __MRE_PAYMENT_TEMP__
            vm_nvram_appstore_config_t appstore_config;
    #endif            
            VMINT nRet;
            vm_sim_state_t sim_state;
            VMINT nSimCount;

            nSimCount = vm_sim_card_count();

            if (nSimCount == 1)
            {
                sim_state = vm_get_sim_card_status(VM_SIM_SIM1);
                if (sim_state == VM_SIM_STATE_WORKING)
                    sim_index = VM_SMS_SIM_1;
                else
                {
                    sim_state = vm_get_sim_card_status(VM_SIM_SIM2);
                    if (sim_state == VM_SIM_STATE_WORKING)
                        sim_index = VM_SMS_SIM_2;
                    else
                        sim_index = VM_SMS_SIM_1;   /* 读取错误 */
                }
            }
            else if (nSimCount == 2)
            {
    #ifdef __MRE_PAYMENT_TEMP__
                
                if (vm_get_appstore_config(&appstore_config))
                {
                    if (appstore_config.sim_index == 2)
                        sim_index = VM_SMS_SIM_2;
                    else
                        sim_index = VM_SMS_SIM_1;
                }
                else
    #endif /* __MRE_PAYMENT_TEMP__ */ /* #ifdef __MRE_PAYMENT_TEMP__    */
                    
                    sim_index = VM_SMS_SIM_1;
            }
            else
            {
                sim_index = VM_SMS_SIM_1;   /* 无SIm卡或者费心模式 */
            }

        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2821 , sim_index, VM_SMS_SIM_1);
        #endif 
            memset(sc_addr.sc_addr, 0, sizeof(sc_addr.sc_addr));

            nRet = vm_sms_get_sc_address_syn(&sc_addr, (vm_sms_sim_enum) sim_index);
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2827 , nRet);
        #endif 
            if (nRet == VM_SMS_SUPPORT_SYN_SCA)
            {
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2832 );
            #endif 
            }
            else
            {
                sprintf(sc_addr.sc_addr, "0");
            }

        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2841 , sc_addr.sc_addr);
        #endif 
            if ((curr_ptr + (strlen(sc_addr.sc_addr) * sizeof(VMWCHAR) + 4)) <= end)
                curr_ptr = packasciistr(curr_ptr, sc_addr.sc_addr, end);
            else
                return p;
        #endif /* defined(__MRE_SAL_SIM__) && defined(__MRE_SAL_SMS__) */ 
        }

        /* 运营商代码 */
    #ifdef __MRE_SAL_SIM__
        {
            static VMCHAR operator_code[20];

            memset(operator_code, 0, sizeof(operator_code));

            if (vm_query_operator_code(operator_code, sizeof(operator_code)) == 0)
            {
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2860 , operator_code);
            #endif 
            }
            else
            {
                sprintf(operator_code, "0");
                /* return p; */
            }
            if ((curr_ptr + (strlen(operator_code) * sizeof(VMWCHAR) + 4)) <= end)
                curr_ptr = packasciistr(curr_ptr, operator_code, end);
            else
                return p;
        }
    #endif /* __MRE_SAL_SIM__ */ 
        /* rencai.xiao 2010/04/19 upload imsi */
    #if defined(VIP_SUPPORT_UPLOAD_IMSI) && defined(__MRE_SAL_SIM__)
        if (!g_is_updating)
        {

            static VMCHAR szImsi[30];
            VMINT nSimCount;
            VMSTR pStr = NULL;

            nSimCount = vm_sim_card_count();
            memset(szImsi, 0, sizeof(szImsi));
            pStr = vm_get_imsi();

            if (nSimCount > 0 && nSimCount != 99 && pStr != NULL)
                sprintf(szImsi, "%s", pStr);
            else
                sprintf(szImsi, "0");

        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_2893 , szImsi);
        #endif 

            if ((curr_ptr + (strlen(szImsi) * sizeof(VMWCHAR) + 4)) <= end)
                curr_ptr = packasciistr(curr_ptr, szImsi, end);
            else
                return p;
        }
    #endif /* defined(VIP_SUPPORT_UPLOAD_IMSI) && defined(__MRE_SAL_SIM__) */ 

        return curr_ptr;
    }

    return p;
}

#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  vip_http_state_hook_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  httpState       [IN]        
 *  param           [IN]        
 *  session         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_http_state_hook_ext(VMINT httpState, VMINT param, void *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vip_http_state_hook_shell(httpState, param, session, vip_context_ext[0]);
}


/*****************************************************************************
 * FUNCTION
 *  vip_http_state_hook_shell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  httpState       [IN]        
 *  param           [IN]        
 *  session         [?]         
 *  pContext        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_http_state_hook_shell(VMINT httpState, VMINT param, void *session, vm_vip_item_t *pContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_log_fatal(
        "[TEST] enter vip_http_state_hook_shell. pContext:%p, pContext->progress_hook[%p]:%p",
        pContext,
        &pContext->progress_hook,
        pContext->progress_hook);
    if (pContext && pContext->progress_hook)
    {
        VMUINT percent = 0;

        if (!(pContext->allow_repeat))
        {
            switch (httpState)
            {
                case HTTP_STATE_SENDING:
                    percent = 20;
                    break;
                case HTTP_STATE_RECV_STATUS:
                    percent = 25;
                    break;
                case HTTP_STATE_RECV_HEADS:
                    percent = 30;
                    break;
                case HTTP_STATE_RECV_BODY:
                    percent = 30 + (param > 30 ? (param * 7 / 10) : 0);
                    break;
            }
        }
        else
        {
            char head_value[50] = {0};

            switch (httpState)
            {
                case HTTP_STATE_SENDING:
                    percent = 5;
                    break;
                case HTTP_STATE_RECV_STATUS:
                    percent = 10;
                    break;
                case HTTP_STATE_RECV_HEADS:
                    percent = 15;
                    break;
                case HTTP_STATE_RECV_BODY:
                    memset(head_value, 0x00, sizeof(head_value));
                    if (session != NULL)
                    {
                        if (get_http_head((http_session_t*) session, "Content-Type", head_value) == 0)
                        {
                            if (strncmp("text/vnd.wap.wml", head_value, 16) == 0)
                            {
                                percent = 20;
                                break;
                            }
                        }
                    }

                    percent = 30 + (param > 30 ? (param * 7 / 10) : 0);

                    break;
            }
        }

        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3021 , pContext->progress_hook);
        pContext->progress_hook((percent > 100 ? 100 : percent));
    }
    vm_log_fatal(
        "[TEST] leave vip_http_state_hook_shell. pContext:%p, pContext->progress_hook:%p",
        pContext,
        pContext->progress_hook);
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  vip_http_state_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  httpState       [IN]        
 *  param           [IN]        
 *  session         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_http_state_hook(VMINT httpState, VMINT param, void *session)
{
#ifdef VIP14
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vip_http_state_hook_shell(httpState, param, session, vip_context);
    return;
#else /* VIP14 */ 
    if (vip_context && vip_context->progress_hook)
    {
        VMUINT percent = 0;

        if (!(vip_context->allow_repeat))
        {
            switch (httpState)
            {
                case HTTP_STATE_SENDING:
                    percent = 20;
                    break;
                case HTTP_STATE_RECV_STATUS:
                    percent = 25;
                    break;
                case HTTP_STATE_RECV_HEADS:
                    percent = 30;
                    break;
                case HTTP_STATE_RECV_BODY:
                    percent = 30 + (param > 30 ? (param * 7 / 10) : 0);
                    break;
            }
        }
        else
        {
            char head_value[50] = {0};

            switch (httpState)
            {
                case HTTP_STATE_SENDING:
                    percent = 5;
                    break;
                case HTTP_STATE_RECV_STATUS:
                    percent = 10;
                    break;
                case HTTP_STATE_RECV_HEADS:
                    percent = 15;
                    break;
                case HTTP_STATE_RECV_BODY:
                    memset(head_value, 0x00, sizeof(head_value));
                    if (session != NULL)
                    {
                        if (get_http_head((http_session_t*) session, "Content-Type", head_value) == 0)
                        {
                            if (strncmp("text/vnd.wap.wml", head_value, 16) == 0)
                            {
                                percent = 20;
                                break;
                            }
                        }
                    }

                    percent = 30 + (param > 30 ? (param * 7 / 10) : 0);

                    break;
            }
        }

        vip_context->progress_hook((percent > 100 ? 100 : percent));
    }
#endif /* VIP14 */ 
}

#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  vip_do_res_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  response        [?]         
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_do_res_ext(VMUINT8 *response, VMINT len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vip_do_res_shell(response, len, vip_context_ext[0]);
}


/*****************************************************************************
 * FUNCTION
 *  vip_do_res_shell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  response        [?]         
 *  len             [IN]        
 *  pContext        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_do_res_shell(VMUINT8 *response, VMINT len, vm_vip_item_t *pContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3168 , pContext, pContext->callback);
#endif 
    if (pContext && pContext->callback)
    {
        BYTE *ptr = response, *oldPtr = response;
        VMINT user_id = 0;
        VMINT mobile_phone_id = 0;
        VMINT size = 0;
        VMINT nLen = 0;
        BYTE *pTemp = NULL;

        /* 解码SESSION_ID。     */
        ptr = unpackstr(oldPtr, pContext->vip_session, 255, response + len);
        if (oldPtr >= ptr)
        {
            error.code = -2;
            sprintf(error.message, "Leak of data.");
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3186 );
        #endif 
            pContext->callback(pContext->user_id, pContext->mobile_phone_id, RES_ERROR_CMD, &error, sizeof(error_t));

            return;
        }

        /* 解码UID。         */
        oldPtr = ptr;
        ptr = unpackint(oldPtr, &user_id, response + len);
        if (oldPtr >= ptr)
        {
            error.code = -2;
            sprintf(error.message, "Leak of data. ");
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3201 );
        #endif 
            pContext->callback(pContext->user_id, pContext->mobile_phone_id, RES_ERROR_CMD, &error, sizeof(error_t));

            return;
        }

        /* 解码MOBILE_PHONE_ID。 */
        oldPtr = ptr;
        ptr = unpackint(oldPtr, &mobile_phone_id, response + len);
        if (oldPtr >= ptr)
        {
            error.code = -2;
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3215 );
        #endif 
            sprintf(error.message, "Leak of data.  ");
            pContext->callback(pContext->user_id, pContext->mobile_phone_id, RES_ERROR_CMD, &error, sizeof(error_t));

            return;
        }

        /* rencai.xiao 2010/03/02 */
        nLen = strlen(pContext->vip_session) + 8;
        pTemp = ptr;
        switch (*ptr)
        {
            case RES_RESCONTENT_CMD:
            case REQ_POST_DATA_CMD:
                ptr = unpackint(ptr + 1, &size, response + len);
        #ifdef LOG_VIP
                {
                    VMINT test_size = ((response + len) - ptr);

                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3235 , test_size);
                }
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3237 );
        #endif /* LOG_VIP */ 
                if (size >= 0 && size == ((response + len) - ptr))
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3242 );
                #endif 
                    pContext->callback(user_id, mobile_phone_id, RES_RESCONTENT_CMD, ptr, (VMUINT) size);
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3246 );
                #endif 
                }
                else
                {
                    /* rencai.xiao 2010/03/02 */
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3253 );
                #endif 
                    pContext->callback(user_id, mobile_phone_id, RES_RESCONTENT_CMD, pTemp, (VMUINT) len - nLen);
                    //                              error.code = -2;
                    //                              sprintf(error.message, "Leak of data.");
                    //                              pContext->callback(pContext->user_id, pContext->mobile_phone_id, 
                    //                                      RES_ERROR_CMD, &error, sizeof(error_t));
                }

                break;
            case RES_ERROR_CMD:
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3265 );
            #endif 
                ptr = unpackint(ptr + 1, &(error.code), response + len);
                /* rencai.xiao 2010/03/02 */
            #ifdef LOG_VIP
                {
                    VMINT error_size;

                    error_size = ((response + len) - ptr);
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3274 , error_size);
                }
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3276 , error.code, len);
            #endif /* LOG_VIP */ 
                /* if (error.code >= 0 && error.code == ((response + len) - ptr)) */
                {
                    ptr = unpackstr(ptr, error.message, 255, response + len);
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3282 , error.code);
                #endif 
                    pContext->callback(user_id, mobile_phone_id, RES_ERROR_CMD, &error, sizeof(error_t));
                }
                /*
                 * else
                 * {
                 * //rencai.xiao 2010/03/02
                 * pContext->callback(user_id, mobile_phone_id, 
                 * RES_RESCONTENT_CMD, pTemp, (VMUINT)len - nLen);
                 * }
                 */
                break;
            default:
                error.code = -1;
                sprintf(error.message, "Error vip command, command is %d.", *ptr);
                pContext->callback(
                            pContext->user_id,
                            pContext->mobile_phone_id,
                            RES_ERROR_CMD,
                            &error,
                            sizeof(error_t));
                break;
        }
    }
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  vip_do_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  response        [?]         
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_do_res(VMUINT8 *response, VMINT len)
{
#ifdef VIP14
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vip_do_res_shell(response, len, vip_context);
    return;
#else /* VIP14 */ 
    if (vip_context && vip_context->callback)
    {
        BYTE *ptr = response, *oldPtr = response;
        VMINT user_id = 0;
        VMINT mobile_phone_id = 0;
        VMINT size = 0;

        /* 解码SESSION_ID。     */
        ptr = unpackstr(oldPtr, vip_context->vip_session, 255, response + len);
        if (oldPtr >= ptr)
        {
            error.code = -2;
            sprintf(error.message, "Leak of data.");
            vip_context->callback(
                            vip_context->user_id,
                            vip_context->mobile_phone_id,
                            RES_ERROR_CMD,
                            &error,
                            sizeof(error_t));

            return;
        }

        /* 解码UID。         */
        oldPtr = ptr;
        ptr = unpackint(oldPtr, &user_id, response + len);
        if (oldPtr >= ptr)
        {
            error.code = -2;
            sprintf(error.message, "Leak of data. ");
            vip_context->callback(
                            vip_context->user_id,
                            vip_context->mobile_phone_id,
                            RES_ERROR_CMD,
                            &error,
                            sizeof(error_t));

            return;
        }

        /* 解码MOBILE_PHONE_ID。 */
        oldPtr = ptr;
        ptr = unpackint(oldPtr, &mobile_phone_id, response + len);
        if (oldPtr >= ptr)
        {
            error.code = -2;
            sprintf(error.message, "Leak of data.  ");
            vip_context->callback(
                            vip_context->user_id,
                            vip_context->mobile_phone_id,
                            RES_ERROR_CMD,
                            &error,
                            sizeof(error_t));

            return;
        }

        switch (*ptr)
        {
            case RES_RESCONTENT_CMD:
                ptr = unpackint(ptr + 1, &size, response + len);
                if (size >= 0 && size == ((response + len) - ptr))
                {
                    vip_context->callback(user_id, mobile_phone_id, RES_RESCONTENT_CMD, ptr, (VMUINT) size);
                }
                else
                {
                    error.code = -2;
                    sprintf(error.message, "Leak of data.");
                    vip_context->callback(
                                    vip_context->user_id,
                                    vip_context->mobile_phone_id,
                                    RES_ERROR_CMD,
                                    &error,
                                    sizeof(error_t));
                }

                break;
            case RES_ERROR_CMD:
                ptr = unpackint(ptr, &(error.code), response + len);
                ptr = unpackstr(ptr, error.message, 255, response + len);
                vip_context->callback(user_id, mobile_phone_id, RES_ERROR_CMD, &error, sizeof(error_t));
                break;
            default:
                error.code = -1;
                sprintf(error.message, "Error vip command, command is %d.", *ptr);
                vip_context->callback(
                                vip_context->user_id,
                                vip_context->mobile_phone_id,
                                RES_ERROR_CMD,
                                &error,
                                sizeof(error_t));
                break;
        }
    }
#endif /* VIP14 */ 
}

#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  vip_http_hook_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  session     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_http_hook_ext(VMINT result, void *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* added by rencai.xiao 10/01/26 */
    if (g_app_handle_timer > 0)
    {
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3460 );
    #endif 
        vm_delete_timer_ex(g_app_handle_timer);
        g_app_handle_timer = -1;
    }
    vip_http_hook_shell(result, session, vip_context_ext[0], repeat_vip_connect_ext, vip_do_res_ext);
}


/*****************************************************************************
 * FUNCTION
 *  vip_http_hook_shell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  session             [?]         
 *  pContext            [?]         
 *  repeat_vip_ct       [IN]        
 *  do_res              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_http_hook_shell(
                VMINT result,
                void *session,
                vm_vip_item_t *pContext,
                void (*repeat_vip_ct) (VMINT tid),
                void (*do_res) (VMUINT8 *response, VMINT len))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    http_session_t *httpSession = (http_session_t*) session;
    char head_value[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    vm_log_fatal(
        "[TEST] enter vip_http_hook_shell. httpSession:%p, httpSession->res_code:%d, httpSession->nresbody:%d",
        httpSession,
        httpSession->res_code,
        httpSession->nresbody);
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3505 , result);
#endif /* LOG_VIP */ 
    if (result == 0 && httpSession && httpSession->res_code == 200 && httpSession->nresbody > 0)
    {
        /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3509 , httpSession->nresbody); */
        if (get_http_head(session, "Content-Type", head_value) == 0)
        {
            if (strncmp("text/vnd.wap.wml", head_value, 16) == 0)
            {
                /*
                 * 主页推送的页面，需要重新发起连接。
                 */
                if (pContext->allow_repeat)
                {

                    /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3520 ); */
                    /* 
                     * 用定时器重发VIP请求。 
                     */
                    pContext->allow_repeat = FALSE;
                    if (vm_create_timer(200, (VM_TIMERPROC_T) repeat_vip_ct) < 0)
                    {
                        pContext->used = FALSE;
                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (pContext->callback)
                        {
                            pContext->callback(
                                        pContext->user_id,
                                        pContext->mobile_phone_id,
                                        RES_ERROR_CMD,
                                        (void*)&error,
                                        sizeof(error_t));
                        }
                    }
                }
                else
                {
                    /*
                     * 已经重发但还是被主页面推送拦截。
                     * 是否该策略已经被废止？
                     */
                    if (pContext->repeat_content)
                    {
                        vm_free(pContext->repeat_content);
                        pContext->repeat_content = NULL;
                    }
                    pContext->repeat_content_size = 0;
                    pContext->used = FALSE;

                    error.code = 9999;
                    sprintf(error.message, "unknow error");
                    if (pContext->callback)
                    {
                        pContext->callback(
                                    pContext->user_id,
                                    pContext->mobile_phone_id,
                                    RES_ERROR_CMD,
                                    (void*)&error,
                                    sizeof(error_t));
                    }
                }
            }
            else
            {
              NORMAL_VIP_DEALT:
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3572 );
            #endif 
                /*
                 * 正常的VIP响应体。
                 */
                if (pContext->repeat_content)
                {
                    vm_free(pContext->repeat_content);
                    pContext->repeat_content = NULL;
                }
                pContext->repeat_content_size = 0;
                pContext->allow_repeat = FALSE;
                pContext->used = FALSE;
                if (pContext->encrypt)
                {
                    VMDESHANDLE des_handle = DES_INVALID_HANDLE;
                    VMUINT8 *desPtr = NULL;
                    VMINT des_len = 0;

                    if ((des_handle = vm_des_set_key(pContext->des_key)) == DES_INVALID_HANDLE)
                    {
                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (pContext->callback)
                        {
                        #ifdef LOG_VIP
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3598 );
                        #endif 
                            pContext->callback(
                                        pContext->user_id,
                                        pContext->mobile_phone_id,
                                        RES_ERROR_CMD,
                                        (void*)&error,
                                        sizeof(error_t));
                        }
                        return;
                    }

                    if ((desPtr = vm_des_decrypt(
                                    des_handle,
                                    httpSession->resbody,
                                    httpSession->nresbody,
                                    &des_len)) == NULL)
                    {
                        //解码错误
                        //MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3617 );
                        vm_des_reset_key(des_handle);

                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (pContext->callback)
                        {
                        #ifdef LOG_VIP
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3625 );
                        #endif 
                            pContext->callback(
                                        pContext->user_id,
                                        pContext->mobile_phone_id,
                                        RES_ERROR_CMD,
                                        (void*)&error,
                                        sizeof(error_t));
                        }
                        return;
                    }

                    if (des_len <= MD5_DIGEST_LEN)
                    {
                        /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3639 ); */

                        vm_free(desPtr);
                        vm_des_reset_key(des_handle);

                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (pContext->callback)
                        {
                        #ifdef LOG_VIP
                            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3649 );
                        #endif 
                            pContext->callback(
                                        pContext->user_id,
                                        pContext->mobile_phone_id,
                                        RES_ERROR_CMD,
                                        (void*)&error,
                                        sizeof(error_t));
                        }
                        return;
                    }
                    else
                    {
                        md5_state_t md5_state;
                        md5_byte_t digest[MD5_DIGEST_LEN];

                        md5_init(&md5_state);
                        md5_append(&md5_state, (const md5_byte_t*)desPtr, des_len - MD5_DIGEST_LEN);
                        md5_finish(&md5_state, digest);

                        if (memcmp(digest, (desPtr + des_len - MD5_DIGEST_LEN), MD5_DIGEST_LEN) != 0)
                        {
                            /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3671 ); */

                            vm_free(desPtr);
                            vm_des_reset_key(des_handle);

                            error.code = 9999;
                            sprintf(error.message, "unknow error");
                            if (pContext->callback)
                            {
                            #ifdef LOG_VIP
                                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3681 );
                            #endif 
                                pContext->callback(
                                            pContext->user_id,
                                            pContext->mobile_phone_id,
                                            RES_ERROR_CMD,
                                            (void*)&error,
                                            sizeof(error_t));
                            }
                            return;
                        }
                    }
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3694 );
                #endif 
                    do_res(desPtr, des_len - MD5_DIGEST_LEN);
                    vm_free(desPtr);
                    vm_des_reset_key(des_handle);
                }
                else
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3703 );
                #endif 
                    do_res(httpSession->resbody, httpSession->nresbody);
                }
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3708 );
            #endif 
            }
        }
        else
        {
            /* 取不到Content-Type的值，被认为是正常的VIP响应。 */
            goto NORMAL_VIP_DEALT;
        }
    }
    else
    {
        //MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3720 , 
        //        httpSession->nresbody, result);

        /*
         * 错误的HTTP响应。
         */

        if (pContext->repeat_content)
        {
            vm_free(pContext->repeat_content);
            pContext->repeat_content = NULL;
        }
        pContext->repeat_content_size = 0;
        pContext->used = FALSE;
        pContext->allow_repeat = FALSE;

        error.code = 9001;
        sprintf(error.message, "Network I/O error");
        if (pContext->callback)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3741 );
        #endif 
            pContext->callback(
                        pContext->user_id,
                        pContext->mobile_phone_id,
                        RES_ERROR_CMD,
                        (void*)&error,
                        sizeof(error_t));
        }
    }
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  vm_vip_app_handle_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nTimerID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_vip_app_handle_proc(VMINT nTimerID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3775 , g_app_handle_timer);
#endif 
    if (g_app_handle_timer > 0)
    {
        vm_delete_timer_ex(g_app_handle_timer);
        g_app_handle_timer = -1;
    }
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3783 , vip_context_ext[0]->repeat_content);
#endif 
    if (vip_context_ext[0])
    {
        if (vip_context_ext[0]->repeat_content)
        {
            vm_free(vip_context_ext[0]->repeat_content);
            vip_context_ext[0]->repeat_content = NULL;
        }
        vip_context_ext[0]->repeat_content_size = 0;
        /* vip_context_ext[0]->used = FALSE; */
        vip_context_ext[0]->allow_repeat = FALSE;

        error.code = 9900;
        sprintf(error.message, "Connection timeout");
        if (vip_context_ext[0]->callback)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3801 );
        #endif 
            vip_context_ext[0]->callback(
                                    vip_context_ext[0]->user_id,
                                    vip_context_ext[0]->mobile_phone_id,
                                    RES_ERROR_CMD,
                                    (void*)&error,
                                    sizeof(error_t));
        }
    }
    vip_cancel_request_handle(VIP_APP_HANDLE);

}


/*****************************************************************************
 * FUNCTION
 *  vm_vip_other_handle_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nTimerID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_vip_other_handle_proc(VMINT nTimerID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3836 , g_other_handle_timer);
#endif 
    if (g_other_handle_timer > 0)
    {
        vm_delete_timer_ex(g_other_handle_timer);
        g_other_handle_timer = -1;
    }

    if (vip_context)
    {
        if (vip_context->repeat_content)
        {
            vm_free(vip_context->repeat_content);
            vip_context->repeat_content = NULL;
        }
        vip_context->repeat_content_size = 0;
        /* vip_context->used = FALSE; */
        vip_context->allow_repeat = FALSE;

        error.code = 9900;
        sprintf(error.message, "Connection timeout");
        if (vip_context->callback)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3860 );
        #endif 
            vip_context->callback(
                            vip_context->user_id,
                            vip_context->mobile_phone_id,
                            RES_ERROR_CMD,
                            (void*)&error,
                            sizeof(error_t));
        }
    }
    vip_cancel_request_handle(VIP_OTHER_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  vip_http_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  session     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void vip_http_hook(VMINT result, void *session)
{
#ifndef VIP14
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    http_session_t *httpSession = (http_session_t*) session;
    char head_value[64] = {0};
#endif /* VIP14 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef VIP14
    /* added by rencai.xiao 10/01/26 */
    if (g_other_handle_timer > 0)
    {
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_3903 );
    #endif 
        vm_delete_timer_ex(g_other_handle_timer);
        g_other_handle_timer = -1;
    }
    vip_http_hook_shell(result, session, vip_context, repeat_vip_connect, vip_do_res);
    return;
#else /* VIP14 */ 
    if (result == 0 && httpSession && httpSession->res_code == 200 && httpSession->nresbody > 0)
    {
        /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3913 , httpSession->nresbody); */
        if (get_http_head(session, "Content-Type", head_value) == 0)
        {
            if (strncmp("text/vnd.wap.wml", head_value, 16) == 0)
            {
                /*
                 * 主页推送的页面，需要重新发起连接。
                 */
                if (vip_context->allow_repeat)
                {

                    /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_3924 ); */
                    /* 
                     * 用定时器重发VIP请求。 
                     */
                    vip_context->allow_repeat = FALSE;
                    if (vm_create_timer(200, (VM_TIMERPROC_T) repeat_vip_connect) < 0)
                    {
                        vip_context->used = FALSE;
                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (vip_context->callback)
                        {
                            vip_context->callback(
                                            vip_context->user_id,
                                            vip_context->mobile_phone_id,
                                            RES_ERROR_CMD,
                                            (void*)&error,
                                            sizeof(error_t));
                        }
                    }
                }
                else
                {
                    /*
                     * 已经重发但还是被主页面推送拦截。
                     * 是否该策略已经被废止？
                     */
                    if (vip_context->repeat_content)
                    {
                        vm_free(vip_context->repeat_content);
                        vip_context->repeat_content = NULL;
                    }
                    vip_context->repeat_content_size = 0;
                    vip_context->used = FALSE;

                    error.code = 9999;
                    sprintf(error.message, "unknow error");
                    if (vip_context->callback)
                    {
                        vip_context->callback(
                                        vip_context->user_id,
                                        vip_context->mobile_phone_id,
                                        RES_ERROR_CMD,
                                        (void*)&error,
                                        sizeof(error_t));
                    }
                }
            }
            else
            {
              NORMAL_VIP_DEALT:
                /*
                 * 正常的VIP响应体。
                 */
                if (vip_context->repeat_content)
                {
                    vm_free(vip_context->repeat_content);
                    vip_context->repeat_content = NULL;
                }
                vip_context->repeat_content_size = 0;
                vip_context->allow_repeat = FALSE;
                vip_context->used = FALSE;
                if (vip_context->encrypt)
                {
                    VMDESHANDLE des_handle = DES_INVALID_HANDLE;
                    VMUINT8 *desPtr = NULL;
                    VMINT des_len = 0;

                    if ((des_handle = vm_des_set_key(vip_context->des_key)) == DES_INVALID_HANDLE)
                    {
                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (vip_context->callback)
                        {
                            vip_context->callback(
                                            vip_context->user_id,
                                            vip_context->mobile_phone_id,
                                            RES_ERROR_CMD,
                                            (void*)&error,
                                            sizeof(error_t));
                        }
                        return;
                    }

                    if ((desPtr = vm_des_decrypt(
                                    des_handle,
                                    httpSession->resbody,
                                    httpSession->nresbody,
                                    &des_len)) == NULL)
                    {
                        //解码错误
                        //MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_4015 );
                        vm_des_reset_key(des_handle);

                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (vip_context->callback)
                        {
                            vip_context->callback(
                                            vip_context->user_id,
                                            vip_context->mobile_phone_id,
                                            RES_ERROR_CMD,
                                            (void*)&error,
                                            sizeof(error_t));
                        }
                        return;
                    }

                    if (des_len <= MD5_DIGEST_LEN)
                    {
                        /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_4034 ); */

                        vm_free(desPtr);
                        vm_des_reset_key(des_handle);

                        error.code = 9999;
                        sprintf(error.message, "unknow error");
                        if (vip_context->callback)
                        {
                            vip_context->callback(
                                            vip_context->user_id,
                                            vip_context->mobile_phone_id,
                                            RES_ERROR_CMD,
                                            (void*)&error,
                                            sizeof(error_t));
                        }
                        return;
                    }
                    else
                    {
                        md5_state_t md5_state;
                        md5_byte_t digest[MD5_DIGEST_LEN];

                        md5_init(&md5_state);
                        md5_append(&md5_state, (const md5_byte_t*)desPtr, des_len - MD5_DIGEST_LEN);
                        md5_finish(&md5_state, digest);

                        if (memcmp(digest, (desPtr + des_len - MD5_DIGEST_LEN), MD5_DIGEST_LEN) != 0)
                        {
                            /* MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_4063 ); */

                            vm_free(desPtr);
                            vm_des_reset_key(des_handle);

                            error.code = 9999;
                            sprintf(error.message, "unknow error");
                            if (vip_context->callback)
                            {
                                vip_context->callback(
                                                vip_context->user_id,
                                                vip_context->mobile_phone_id,
                                                RES_ERROR_CMD,
                                                (void*)&error,
                                                sizeof(error_t));
                            }
                            return;
                        }
                    }

                    vip_do_res(desPtr, des_len - MD5_DIGEST_LEN);
                    vm_free(desPtr);
                    vm_des_reset_key(des_handle);
                }
                else
                {
                    vip_do_res(httpSession->resbody, httpSession->nresbody);
                }
            }
        }
        else
        {
            /* 取不到Content-Type的值，被认为是正常的VIP响应。 */
            goto NORMAL_VIP_DEALT;
        }
    }
    else
    {
        //MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_4101 , 
        //        httpSession->nresbody, result);

        /*
         * 错误的HTTP响应。
         */

        if (vip_context->repeat_content)
        {
            vm_free(vip_context->repeat_content);
            vip_context->repeat_content = NULL;
        }
        vip_context->repeat_content_size = 0;
        vip_context->used = FALSE;
        vip_context->allow_repeat = FALSE;

        error.code = 9001;
        sprintf(error.message, "Network I/O error");
        if (vip_context->callback)
        {
            vip_context->callback(
                            vip_context->user_id,
                            vip_context->mobile_phone_id,
                            RES_ERROR_CMD,
                            (void*)&error,
                            sizeof(error_t));
        }
    }
#endif /* VIP14 */ 
}

#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  repeat_vip_connect_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void repeat_vip_connect_ext(VMINT tid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    repeat_vip_connect_shell(vip_context_ext[0]);
}


/*****************************************************************************
 * FUNCTION
 *  repeat_vip_connect_shell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pContext        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void repeat_vip_connect_shell(vm_vip_item_t *pContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pContext)
    {
        if (pContext->repeat_content && pContext->repeat_content_size > 0)
        {
            http_request_t httpReq;
            asyn_http_req_t req;
            http_head_t head;

            sprintf(head.name, "Vip-Version");
            //modified by rencai.xiao 2010/04/20 
            //version 1.4.1 : upload imsi
        #ifdef VIP14
        #ifdef VIP_SUPPORT_UPLOAD_IMSI
            if (!g_is_updating)
            {
                sprintf(head.value, "1.4.1");
            }
            else
            {
                sprintf(head.value, "1.4");
            }
        #else 
            sprintf(head.value, "1.4");
        #endif 
        #else /* VIP14 */ 
            sprintf(head.value, "1.3");
        #endif /* VIP14 */ 
            httpReq.body = (char*)pContext->repeat_content;
            httpReq.nbody = pContext->repeat_content_size;
            httpReq.heads = &head;
            httpReq.nhead = 1;
            strncpy(httpReq.url, PROVISION_URL, 255);

        #ifdef APPSTORE_SUPPORT_COFING
            /* shaw, 09/04/15 , 读取配置文件中的信息 */
            {
                VMCHAR *pro_url = vm_malloc(255);

                if (pro_url)
                {
                    memset(pro_url, 0, 255);
                    if (!vip_get_shell_config_value("provision_url", pro_url))
                    {
                        sprintf(httpReq.url, "%s", pro_url);
                    #ifdef PHSH_DEBUG
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4222 , httpReq.url);
                    #endif 
                    }
                    vm_free(pro_url);
                }
            }
        #endif /* APPSTORE_SUPPORT_COFING */ 

            req.req_method = POST;
            req.http_request = &httpReq;
        #ifdef VIP14
            if (vm_is_support_wifi())
                req.use_proxy = vip_get_connect_type();
            else
                req.use_proxy = HTTP_USE_CMWAP_PRIORITY;
        #else /* VIP14 */ 
        #ifdef WIFI_VERSION
            req.use_proxy = GetProxy(); // /*TRUE*/HTTP_USE_CMWAP_PRIORITY;
        #else 
            req.use_proxy = /* TRUE */ HTTP_USE_CMWAP_PRIORITY;
        #endif 
        #endif /* VIP14 */ 
            if (vm_asyn_http_req(&req, vip_http_hook, vip_http_state_hook) == ASYN_HTTP_REQ_ACCEPT_SUCCESS)
            {
                pContext->used = TRUE;
                vm_get_asyn_http_req_handle(&req, &(pContext->http_handle));
                return;
            }
        }

        pContext->repeat_content_size = 0;
        if (pContext->repeat_content)
        {
            vm_free(pContext->repeat_content);
            pContext->repeat_content = NULL;
        }

        if (pContext->callback)
        {
            pContext->callback(pContext->user_id, pContext->mobile_phone_id, RES_ERROR_CMD, &error, sizeof(error_t));
        }
    }
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  repeat_vip_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void repeat_vip_connect(VMINT tid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_delete_timer(tid);
#ifdef VIP14
    repeat_vip_connect_shell(vip_context);
    return;
#else /* VIP14 */ 
    if (vip_context)
    {
        if (vip_context->repeat_content && vip_context->repeat_content_size > 0)
        {
            http_request_t httpReq;
            asyn_http_req_t req;
            http_head_t head;

            sprintf(head.name, "Vip-Version");
            //modified by rencai.xiao 2010/04/20 
            //version 1.4.1 : upload imsi
        #ifdef VIP14
        #ifdef VIP_SUPPORT_UPLOAD_IMSI
            sprintf(head.value, "1.4.1");
        #else 
            sprintf(head.value, "1.4");
        #endif 
        #else /* VIP14 */ 
            sprintf(head.value, "1.3");
        #endif /* VIP14 */ 
            httpReq.body = (char*)vip_context->repeat_content;
            httpReq.nbody = vip_context->repeat_content_size;
            httpReq.heads = &head;
            httpReq.nhead = 1;
            strncpy(httpReq.url, PROVISION_URL, 255);

        #ifdef APPSTORE_SUPPORT_COFING
            /* shaw, 09/04/15 , 读取配置文件中的信息 */
            {
                VMCHAR *pro_url = vm_malloc(255);

                if (pro_url)
                {
                    memset(pro_url, 0, 255);
                    if (!vip_get_shell_config_value("provision_url", pro_url))
                    {
                        sprintf(httpReq.url, "%s", pro_url);
                    #ifdef PHSH_DEBUG
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4330 , httpReq.url);
                    #endif 
                    }
                    vm_free(pro_url);
                }
            }
        #endif /* APPSTORE_SUPPORT_COFING */ 

            req.req_method = POST;
            req.http_request = &httpReq;
        #ifdef VIP14
            if (vm_is_support_wifi())
                req.use_proxy = vip_get_connect_type();
            else
                req.use_proxy = HTTP_USE_CMWAP_PRIORITY;
        #else /* VIP14 */ 
        #ifdef WIFI_VERSION
            req.use_proxy = GetProxy(); // /*TRUE*/HTTP_USE_CMWAP_PRIORITY;
        #else 
            req.use_proxy = /* TRUE */ HTTP_USE_CMWAP_PRIORITY;
        #endif 
        #endif /* VIP14 */ 
            if (vm_asyn_http_req(&req, vip_http_hook, vip_http_state_hook) == ASYN_HTTP_REQ_ACCEPT_SUCCESS)
            {
                vip_context->used = TRUE;
                vm_get_asyn_http_req_handle(&req, &(vip_context->http_handle));
                return;
            }
        }

        vip_context->repeat_content_size = 0;
        if (vip_context->repeat_content)
        {
            vm_free(vip_context->repeat_content);
            vip_context->repeat_content = NULL;
        }

        if (vip_context->callback)
        {
            vip_context->callback(
                            vip_context->user_id,
                            vip_context->mobile_phone_id,
                            RES_ERROR_CMD,
                            &error,
                            sizeof(error_t));
        }
    }
#endif /* VIP14 */ 
}

/************************************************************************/
/* global function definition                               */
/************************************************************************/
#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  vip_init_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phoneid     [IN]        
 *  userid      [IN]        
 *  nHandle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_init_ext(VMINT phoneid, VMINT userid, VMINT nHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4408 );
#endif 
    if (nHandle == VIP_OTHER_HANDLE)
    {
        /* 初始化下载其它应用的连接 */
        if (vip_context)
        {
            if (vip_context->used)
                return -1;
            else
            {
                memset(vip_context, 0x00, sizeof(vm_vip_item_t));
                vip_context->allow_repeat = TRUE;
            }
        }
        else
        {
            if ((vip_context = vm_malloc(sizeof(vm_vip_item_t))) == NULL)
                return -2;

            memset(vip_context, 0x00, sizeof(vm_vip_item_t));
            vip_context->allow_repeat = TRUE;
        }

        vip_context->user_id = userid;
        vip_context->mobile_phone_id = phoneid;
    }
    else if (nHandle == VIP_APP_HANDLE)
    {
        VMINT i;

        /* 初始化下载应用的连接 */
        for (i = 0; i < VIP14_SUPPORT_CONNECT_NUM - 1; i++)
        {
            vm_log_fatal(
                "[TEST] vip_context_ext[%d, %p ~ %p]",
                i,
                vip_context_ext[i],
                vip_context_ext[i] + sizeof(vm_vip_item_t));
            if (vip_context_ext[i])
            {
                vm_log_fatal(
                    "[TEST] vip_context_ext[%d]->used[%d, %p ~ %p]:%d",
                    i,
                    &vip_context_ext[i]->used,
                    &vip_context_ext[i]->used + sizeof(vm_vip_item_t),
                    vip_context_ext[i]->used);
                if (vip_context_ext[i]->used)
                    return -1;
                else
                {
                    memset(vip_context_ext[i], 0x00, sizeof(vm_vip_item_t));
                    vip_context_ext[i]->allow_repeat = TRUE;

                    vm_log_fatal(
                        "[TEST] vip_context_ext[%d, %p ~ %p] after memset",
                        i,
                        vip_context_ext[i],
                        vip_context_ext[i] + sizeof(vm_vip_item_t));
                }
            }
            else
            {
                if ((vip_context_ext[i] = vm_malloc(sizeof(vm_vip_item_t))) == NULL)
                    return -2;

                memset(vip_context_ext[i], 0x00, sizeof(vm_vip_item_t));
                vip_context_ext[i]->allow_repeat = TRUE;

                vm_log_fatal(
                    "[TEST] vip_context_ext[%d, %p ~ %p] after vm_malloc",
                    i,
                    vip_context_ext[i],
                    vip_context_ext[i] + sizeof(vm_vip_item_t));
            }

            vip_context_ext[i]->user_id = userid;
            vip_context_ext[i]->mobile_phone_id = phoneid;
        }
    }
    else
        return -1;

#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4492 );
#endif 

    return 0;
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  vip_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phoneid     [IN]        
 *  userid      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_init(VMINT phoneid, VMINT userid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef VIP14
    g_phoneid = phoneid;
    g_userid = userid;
#endif /* VIP14 */ 
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4526 );
#endif 
    if (vip_context)
    {
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4531 , vip_context->used);
    #endif 
        if (vip_context->used)
            return -1;
        else
        {
            memset(vip_context, 0x00, sizeof(vm_vip_item_t));
            vip_context->allow_repeat = TRUE;
        }
    }
    else
    {
        if ((vip_context = vm_malloc(sizeof(vm_vip_item_t))) == NULL)
            return -2;
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4546 , vip_context);
    #endif 
        memset(vip_context, 0x00, sizeof(vm_vip_item_t));
        vip_context->allow_repeat = TRUE;
    }

    vip_context->user_id = userid;
    vip_context->mobile_phone_id = phoneid;

#ifdef VIP14
    for (i = 0; i < VIP14_SUPPORT_CONNECT_NUM - 1; i++)
    {
        if (vip_context_ext[i])
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4561 , vip_context_ext[i]->used);
        #endif 
            if (vip_context_ext[i]->used)
                return -1;
            else
            {
                memset(vip_context_ext[i], 0x00, sizeof(vm_vip_item_t));
                vip_context_ext[i]->allow_repeat = TRUE;
            }
        }
        else
        {
            if ((vip_context_ext[i] = vm_malloc(sizeof(vm_vip_item_t))) == NULL)
                return -2;
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4576 , vip_context_ext[i]);
        #endif 
            memset(vip_context_ext[i], 0x00, sizeof(vm_vip_item_t));
            vip_context_ext[i]->allow_repeat = TRUE;
        }

        vip_context_ext[i]->user_id = userid;
        vip_context_ext[i]->mobile_phone_id = phoneid;
    }
#endif /* VIP14 */ 

    return 0;
}

#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  vip_get_resource_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_path        [?]     
 *  des_url         [?]     
 *  des_path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vip_get_resource_path(VMCHAR *src_path, VMCHAR *des_url, VMCHAR *des_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMCHAR *search_ptr = NULL;
    VMCHAR *search_ptr_next = NULL;
    VMINT nFlag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 不同资源之间用";"分割 */
    if (!src_path || !des_url)
        return FALSE;

    search_ptr = strstr(src_path, des_url);
    if (!search_ptr)
        return FALSE;

    if (strcmp(des_url, VIP_SYNC_FEEINFO_URL) == 0 || strcmp(des_url, VIP_SYNC_SMSINFO_URL) == 0)
    {
        /* sprintf(des_path, "%s", des_url); */
        nFlag = TRUE;
    }
    search_ptr_next = strstr(search_ptr, ";");
    if (search_ptr_next)
    {
        if (nFlag)
        {
            VMINT nLen;//, nPos;

            //nPos = strlen(des_url);
            nLen = search_ptr_next - search_ptr - strlen(des_url);
            memcpy(des_path, search_ptr + strlen(des_url), nLen);
            /* memcpy(des_path + nPos, &nLen, 4); */
        }
        else
            memcpy(des_path, search_ptr, search_ptr_next - search_ptr);
    }
    else
    {
        if (nFlag)
        {
            VMINT nLen;//, nPos;

            //nPos = strlen(des_url);
            nLen = strlen(search_ptr) - strlen(des_url);
            memcpy(des_path, search_ptr + strlen(des_url), nLen);
            /* memcpy(des_path + nPos, &nLen, 4); */
        }
        else
            memcpy(des_path, search_ptr, strlen(search_ptr));
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_vip_pack_resource_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p               [?]     
 *  pBody           [?]     
 *  res_path        [?]     
 *  res_type        [?]     
 *  res_size        [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_vip_pack_resource_path(BYTE *p, BYTE *pBody, VMCHAR *res_path, VMCHAR *res_type, VMINT *res_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMCHAR *syspath = NULL;
    VMCHAR *pSearch = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    syspath = vm_malloc(1024 * 3);
    if (!syspath)
    {
        /* vm_free(internal_http_req.body); */
        return FALSE;
    }
    memset(syspath, 0, 1024 * 3);
    memset(syspath, 0, sizeof(syspath));
    pSearch = strstr(res_path, res_type);
    if (!pSearch)
        return FALSE;

    if (!vip_get_resource_path(res_path, res_type, syspath))
        return FALSE;

    if (strcmp(res_type, VIP_UPDATE_MRE_SYS_CONFIG_URL) == 0 || strcmp(res_type, VIP_PROMOTION_UPDATE_URL) == 0)
    {
        //              if(strcmp(res_type, VIP_PROMOTION_UPDATE_URL) == 0)
        //                 (*res_size) += (strlen(syspath) * sizeof(VMWCHAR));
        p = packbyte(p, REQ_READRES_CMD, (BYTE*) pBody + (*res_size));
        p = packasciistr(p, syspath, (BYTE*) pBody + (*res_size));
    }
    else
    {
        /* (*res_size) += (strlen(syspath) * sizeof(VMWCHAR)); */
        p = packbyte(p, REQ_POST_DATA_CMD, (BYTE*) pBody + (*res_size));
        p = packasciistr(p, res_type, (BYTE*) pBody + (*res_size));
        p = packasciistr(p, syspath, (BYTE*) pBody + (*res_size));
    }

    vm_free(syspath);
    syspath = NULL;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_vip_parse_block_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  range       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static int _vm_vip_parse_block_size(char *range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int r1 = 0, r2 = 0, i = 0;
    char int_buf[10];

    char *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range && (p = strchr(range, '=')) != NULL)
    {
        p++;
        while (*p != '&')
        {
            if (*p == '-')
            {
                int_buf[i] = '\0';
                r1 = atoi(int_buf);

                p++;
                i = 0;
                continue;
            }

            int_buf[i++] = *p++;
        }
        int_buf[i] = '\0';
        r2 = atoi(int_buf);

        MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_4769 , range, r1, r2);
        return r2 - r1;
    }
    return 0;
}

/* rencai.xiao 2010/04/29 */
#ifdef VIP_CHECK_DOWNLOAD_READY


/*****************************************************************************
 * FUNCTION
 *  vm_vip_check_account_timer_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nTimerID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_vip_check_account_timer_proc(VMINT nTimerID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4799 );
#endif 

    asyn_data.nCount++;

    if (vm_is_ready_dataaccount())
    {
        VMINT nHttpRet;

        vm_delete_timer_ex(asyn_data.nTimer);
        asyn_data.nTimer = -1;
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4811 );
    #endif 
        nHttpRet = vm_vip_send_request();
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4815 , nHttpRet);
    #endif 
        if (nHttpRet != ASYN_HTTP_REQ_ACCEPT_SUCCESS)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4820 , nHttpRet);
        #endif 
            vm_free(asyn_data.internal_http_req.body);
            asyn_data.internal_http_req.body = NULL;
            if (asyn_data.context)
            {
                asyn_data.context->used = FALSE;
                error.code = 9999;
                sprintf(error.message, "Connection Failed");
                if (asyn_data.context->callback)
                {
                    asyn_data.context->callback(
                                        asyn_data.context->user_id,
                                        asyn_data.context->mobile_phone_id,
                                        RES_ERROR_CMD,
                                        (void*)&error,
                                        sizeof(error_t));
                }
            }
        }
    }
    else
    {
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4844 , asyn_data.nCount);
    #endif 
        if (asyn_data.nCount > 3)
        {
            vm_delete_timer_ex(asyn_data.nTimer);
            asyn_data.nTimer = -1;
            asyn_data.nCount = 0;

            vm_free(asyn_data.internal_http_req.body);
            asyn_data.internal_http_req.body = NULL;
            if (asyn_data.context)
            {
                asyn_data.context->used = FALSE;
                error.code = 9999;
                sprintf(error.message, "Connection Failed");
                if (asyn_data.context->callback)
                {
                    asyn_data.context->callback(
                                        asyn_data.context->user_id,
                                        asyn_data.context->mobile_phone_id,
                                        RES_ERROR_CMD,
                                        (void*)&error,
                                        sizeof(error_t));
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_vip_send_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_vip_send_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT http_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4895 );
#endif 
#ifdef LOG_VIP
    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4898 , asyn_data.internal_http_req.url; */
#endif 
    if ((http_ret = vm_asyn_http_req(&asyn_data.request, asyn_data.http_hook, asyn_data.http_state_notify))
        == ASYN_HTTP_REQ_ACCEPT_SUCCESS)
    {
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4904 );
    #endif 
        vm_get_asyn_http_req_handle(&asyn_data.request, &(asyn_data.context->http_handle));
        asyn_data.context->used = TRUE;
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4909 );
    #endif 
        if (asyn_data.context->allow_repeat)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4914 );
        #endif 
            if ((asyn_data.context->repeat_content = vm_malloc(asyn_data.internal_http_req.nbody)) != NULL)
            {
                memcpy(
                    asyn_data.context->repeat_content,
                    asyn_data.internal_http_req.body,
                    asyn_data.internal_http_req.nbody);
                asyn_data.context->repeat_content_size = asyn_data.internal_http_req.nbody;
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4924 , asyn_data.context->repeat_content);
            #endif 
            }
        }

        vm_free(asyn_data.internal_http_req.body);
        asyn_data.internal_http_req.body = NULL;
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4932 );
    #endif 

    }
    else
    {
        vm_free(asyn_data.internal_http_req.body);
        asyn_data.internal_http_req.body = NULL;
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4941 , http_ret);
    #endif 
        return -3;
    }

    /* added by rencai.xiao 10/01/26 */
    if (asyn_data.nHandle == VIP_APP_HANDLE)
    {
        g_app_handle_timer = vm_create_timer_ex(VIP_CONNECT_TIME_OUT, vm_vip_app_handle_proc);
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4951 , g_app_handle_timer);
    #endif 
    }
    else
    {
        g_other_handle_timer = vm_create_timer_ex(VIP_CONNECT_TIME_OUT, vm_vip_other_handle_proc);
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4958 , g_other_handle_timer);
    #endif 
    }

    return 0;
}
#endif /* VIP_CHECK_DOWNLOAD_READY */ 


/*****************************************************************************
 * FUNCTION
 *  vip_read_resource_shell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pContext            [?]         
 *  respath             [?]         
 *  http_hook_cb        [IN]        
 *  http_state_cb       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vip_read_resource_shell(
                vm_vip_item_t *pContext,
                VMCHAR *respath,
                void (*http_hook_cb) (VMINT, void*),
                void (*http_state_cb) (VMINT state, VMINT param, void *session))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_4994 );
#endif 
    if (pContext && !pContext->used && respath)
    {
        asyn_http_req_t http_req;
        http_request_t internal_http_req;
        http_head_t head[2];
        BYTE *p = NULL;

        /* rencai.xiao 2010/05/04 */
    #ifndef VIP_CHECK_DOWNLOAD_READY
        VMINT http_ret = ASYN_HTTP_REQ_ACCEPT_SUCCESS;
    #endif 
        char *search_ptr = NULL;
        VMCHAR *syspath = NULL;
        int block_size = 0;

        /* 更新配置请求需要加码，其它的资源请求则不加密。 */
        if (((search_ptr = strstr(respath, VIP_UPDATE_MRE_SYS_CONFIG_URL)) != NULL && respath == search_ptr) ||
            ((search_ptr = strstr(respath, VIP_FEE_CHANNEL_RUL)) != NULL && respath == search_ptr) ||
            ((search_ptr = strstr(respath, VIP_SYNC_FEEINFO_URL)) != NULL) ||
            ((search_ptr = strstr(respath, VIP_SYNC_SMSINFO_URL)) != NULL) ||
            ((search_ptr = strstr(respath, VIP_PROMOTION_UPDATE_URL)) != NULL))
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5019 );
        #endif 
            generate_des_key(pContext->des_key);
            pContext->encrypt = TRUE;
        }
        else
        {
            /* 不需要加密 */
            memset(pContext->des_key, 0x00, sizeof(pContext->des_key));
            pContext->encrypt = FALSE;
        }

        /* 附加请求头增加Vip-Version, 新版本中值需修改为1.4 */
        strcpy(head[0].name, "Vip-Version");
        //modified by rencai.xiao 2010/04/20 
        //version 1.4.1 : upload imsi
    #ifdef VIP14
    #ifdef VIP_SUPPORT_UPLOAD_IMSI
        if (!g_is_updating)
        {
            strcpy(head[0].value, "1.4.1");
        }
        else
        {
            strcpy(head[0].value, "1.4");
        }
    #else 
        strcpy(head[0].value, "1.4");
    #endif 
    #else /* VIP14 */ 
        strcpy(head[0].value, "1.3");
    #endif /* VIP14 */ 

        block_size = _vm_vip_parse_block_size(strstr(respath, "range=")) + 200;
        strcpy(head[1].name, "MRE-AM-BlockSize");
        sprintf(head[1].value, "%d", block_size);

        internal_http_req.nhead = 2;    /* 附加请求头个数 */
        internal_http_req.heads = head; /* 附加请求头数组指针 */
        internal_http_req.body = NULL;  /* 附加请求体指针 */
        internal_http_req.nbody = 0;    /* 附加请求体的长度，字节单位 */

        http_req.req_method = POST; /* <HTTP_METHOD类型,客户端发起请求的方法必须用POST */

    #ifdef VIP14
        if (vm_is_support_wifi())
            http_req.use_proxy = vip_get_connect_type();
        else
            http_req.use_proxy = HTTP_USE_CMWAP_PRIORITY;
    #else /* VIP14 */ 
    #ifdef WIFI_VERSION     /* 新版本中需要从NVRAM中获取 */
        http_req.use_proxy = GetProxy();        // /*TRUE*/HTTP_USE_CMWAP_PRIORITY;
    #else 
        http_req.use_proxy = /* TRUE */ HTTP_USE_CMWAP_PRIORITY;
    #endif 
    #endif /* VIP14 */ 

    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5077 , http_req.use_proxy);
    #endif 
        http_req.http_request = &internal_http_req; /* <HTTP请求。 */

    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5082 );
    #endif 
        if (strlen(pContext->vip_session) == 0) /* 第一次会话 */
        {
            strncpy(internal_http_req.url, PROVISION_URL, 255); /* 联网地址 */

        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5089 );
        #endif 
        #ifdef APPSTORE_SUPPORT_COFING
            /* shaw, 09/04/15 , 读取配置文件中的信息 */
            {
                VMCHAR *pro_url = vm_malloc(255);

                if (pro_url)
                {
                    memset(pro_url, 0, 255);
                    if (!vip_get_shell_config_value("provision_url", pro_url))
                    {
                        sprintf(internal_http_req.url, "%s", pro_url);
                    #ifdef LOG_VIP
                        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMVIP_5103 , internal_http_req.url);
                    #endif 
                    }
                    vm_free(pro_url);
                }
            }
        #endif /* APPSTORE_SUPPORT_COFING */ 

            if (pContext->encrypt)
            {
                /* 需要加密请求 */
                VMINT req_group_size = 0;
                VMINT rsa_len = 64, des_handle = 0, des_len = 0;
                md5_state_t md5_state;
                VMUINT8 *encrypt = NULL;

            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5120 );
            #endif 
                /* 计算Body长度 */
                req_group_size += VIP13_MAX_CONNECT_COMMAND_LEN;        /* 连接指令长度 */
                req_group_size += ENCRYPT_VIP_COMMAND_LEN;  /* 加密指令长度 */
                req_group_size += (strlen(respath) * sizeof(VMWCHAR) + MD5_DIGEST_LEN + DES_PADDING_LEN);       /* path以及MD5,DES长度 */
                req_group_size += 100;

                if ((internal_http_req.body = vm_malloc(req_group_size)) == NULL)
                    return -1;

                /* 编码连接指令。 */
                /*
                 * CONNECT_CMD USER_ID MOBILE_PHONE_ID USER_AGENT MRE_VERSION MTK_VERSION 
                 * SCREEN_WIDTH SCREEN_HEIGHT MEMORY_SIZE SUPPORT_KEYPAD SUPPORT_TOUCH
                 */
                /* 连接指令的最大长度为：VIP13_MAX_CONNECT_COMMAND_LEN */
                if ((p = plus_connect_cmd(
                            (BYTE*) internal_http_req.body,
                            (BYTE*) internal_http_req.body + VIP13_MAX_CONNECT_COMMAND_LEN))
                    <= (BYTE*) internal_http_req.body)
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5143 );
                #endif 
                    vm_free(internal_http_req.body);
                    return -2;
                }
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;

                /* 编码加密指令. *//* SECURE_CMD CERT_ID PUBK_ENCRYPT_DES_KEY */
                p = packbyte(p, REQ_ENCRYPT_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packint(p, 0, (BYTE*) internal_http_req.body + req_group_size);    /* 0号证书 */
                p = packint(p, 64, (BYTE*) internal_http_req.body + req_group_size);   /* DES密钥长度 */
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5155 );
            #endif 
            #ifndef PHSH_VIP_DEBUG  /* 用指定的密钥对给定的内容签名 */
                if (vm_ce_init() == 0 && 0 == vm_rsa_sign_by_id(
                                                pContext->des_key,
                                                8,  /* for test */
                                                0,
                                                p,
                                                &rsa_len,
                                                PUB_PADDING))   /* 用公钥签名 */
            #else /* PHSH_VIP_DEBUG */ 
                if (0 == vm_rsa_sign(pContext->des_key, 8, &pubKey, p, &rsa_len, PUB_PADDING))
            #endif /* PHSH_VIP_DEBUG */ 
                    //                              if (0 == vm_ce_init() && 0 == vm_rsa_sign_by_id(vip_context->des_key, 8, 
                    //                                      0, p, &rsa_len, PUB_PADDING))
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                    if (rsa_len != 64)
                    {
                    #ifdef LOG_VIP
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5177 );
                    #endif 
                        vm_free(internal_http_req.body);
                        return -3;
                    }
                }
                else
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5189 );
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5192 ); */
                    return -4;
                }
                p += 64;
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;

                /* 编码资源指令,需要做MD5摘要和DES加密 *//* READ_RES_CMD RES_PATH */

            #ifdef VIP_SUPPORT_NEW_BILLING
                if ((search_ptr = strstr(respath, VIP_UPDATE_MRE_SYS_CONFIG_URL)) != NULL)
                {
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);

                    p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_UPDATE_MRE_SYS_CONFIG_URL, syspath))
                        return -9;
                    p = packasciistr(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    vm_free(syspath);
                    syspath = NULL;
                }

            #else /* VIP_SUPPORT_NEW_BILLING */ 
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packasciistr(p, respath, (BYTE*) internal_http_req.body + req_group_size);
            #endif /* VIP_SUPPORT_NEW_BILLING */ 
            #ifdef VIP_SUPPORT_NEW_BILLING
                /* 计费信息同步 */
                if ((search_ptr = strstr(respath, VIP_SYNC_FEEINFO_URL)) != NULL)
                {
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);
                    p = packbyte(p, REQ_POST_DATA_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_SYNC_FEEINFO_URL, syspath))
                        return -9;
                    p = packasciistr(p, VIP_SYNC_FEEINFO_URL, (BYTE*) internal_http_req.body + req_group_size);
                    p = packasciistr_ex(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    vm_free(syspath);
                    syspath = NULL;
                }

                /* 短信信息同步 */
                if ((search_ptr = strstr(respath, VIP_SYNC_SMSINFO_URL)) != NULL)
                {
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);
                    p = packbyte(p, REQ_POST_DATA_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_SYNC_SMSINFO_URL, syspath))
                        return -9;
                    p = packasciistr(p, VIP_SYNC_SMSINFO_URL, (BYTE*) internal_http_req.body + req_group_size);
                    p = packasciistr_ex(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    vm_free(syspath);
                    syspath = NULL;
                }

                /* 促销金额更新 */
                if ((search_ptr = strstr(respath, VIP_PROMOTION_UPDATE_URL)) != NULL)
                {
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);
                    p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_PROMOTION_UPDATE_URL, syspath))
                        return -9;
                    p = packasciistr(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    vm_free(syspath);
                    syspath = NULL;
                }
            #endif /* VIP_SUPPORT_NEW_BILLING */ 
                md5_init(&md5_state);
                md5_append(
                    &md5_state,
                    (const md5_byte_t*)internal_http_req.body + internal_http_req.nbody,
                    p - (BYTE*) (internal_http_req.body + internal_http_req.nbody));
                md5_finish(&md5_state, (md5_byte_t*) p);
                p += 16;
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5292 );
            #endif 
                if ((des_handle = vm_des_set_key(pContext->des_key)) == DES_INVALID_HANDLE)
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5297 );
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5300 ); */
                    return -5;
                }
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5304 );
            #endif 
                if ((encrypt = vm_des_encrypt(
                                des_handle,
                                (VMUINT8*) (internal_http_req.body + internal_http_req.nbody),
                                p - (BYTE*) (internal_http_req.body + internal_http_req.nbody),
                                &des_len)) == NULL)
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5313 );
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5316 ); */
                    return -6;
                }

                memcpy(internal_http_req.body + internal_http_req.nbody, encrypt, des_len);
                internal_http_req.nbody += des_len;

                vm_des_reset_key(des_handle);
                vm_free(encrypt);
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5326 );
            #endif 
            }
            else
            {
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5332 );
            #endif 
                /* 无须加密请求 */
                if ((internal_http_req.body = vm_malloc(VIP13_MAX_CONNECT_COMMAND_LEN +
                                                        5 + strlen(respath) * sizeof(VMWCHAR))) == NULL)
                    return -1;

                /* 编码连接指令。 */
                if ((p = plus_connect_cmd(
                            (BYTE*) internal_http_req.body,
                            (BYTE*) internal_http_req.body + VIP13_MAX_CONNECT_COMMAND_LEN))
                    <= (BYTE*) internal_http_req.body)
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5346 );
                #endif 
                    vm_free(internal_http_req.body);
                    return -2;
                }
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;

                /* 编码资源指令。 */
                internal_http_req.nbody += (5 + strlen(respath) * sizeof(VMWCHAR));
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + internal_http_req.nbody);
                p = packasciistr(p, respath, (BYTE*) internal_http_req.body + internal_http_req.nbody);
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5358 );
            #endif 
            }
        }
        else
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5365 );
        #endif 
            /* 不是第一次会话 */
            if (pContext->encrypt)
            {
                /* 需要加密VIP请求组 */
                VMINT req_group_size = 0;
                VMINT rsa_len = 64, des_handle = 0, des_len = 0;
                md5_state_t md5_state;
                VMUINT8 *encrypt = NULL;

                req_group_size += ENCRYPT_VIP_COMMAND_LEN;
                req_group_size += (strlen(respath) * sizeof(VMWCHAR) + MD5_DIGEST_LEN + DES_PADDING_LEN);

                if ((internal_http_req.body = vm_malloc(req_group_size)) == NULL)
                    return -1;

                /* 编码加密指令. */
                p = (BYTE*) internal_http_req.body;
                p = packbyte(p, REQ_ENCRYPT_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packint(p, 0, (BYTE*) internal_http_req.body + req_group_size);
                p = packint(p, 64, (BYTE*) internal_http_req.body + req_group_size);
            #ifndef PHSH_VIP_DEBUG

                if (vm_ce_init() == 0 && 0 == vm_rsa_sign_by_id(pContext->des_key, 8, 0, p, &rsa_len, PUB_PADDING))
            #else /* PHSH_VIP_DEBUG */ 
                if (0 == vm_rsa_sign(pContext->des_key, 8, &pubKey, p, &rsa_len, PUB_PADDING))

            #endif /* PHSH_VIP_DEBUG */ 
                    //                              if (0 == vm_ce_init() && 0 == vm_rsa_sign_by_id(vip_context->des_key, 8, 
                    //                                      0, p, &rsa_len, PUB_PADDING))
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                    if (rsa_len != 64)
                    {
                    #ifdef LOG_VIP
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5403 );
                    #endif 
                        vm_free(internal_http_req.body);
                        return -3;
                    }
                }
                else
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5415 );
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5418 ); */
                    return -4;
                }
                p += 64;
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;
            #ifdef VIP_SUPPORT_NEW_BILLING
                if ((search_ptr = strstr(respath, VIP_UPDATE_MRE_SYS_CONFIG_URL)) != NULL)
                {
                    /* 编码资源指令,需要做MD5摘要和DES加密 */
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);
                    p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_UPDATE_MRE_SYS_CONFIG_URL, syspath))
                        return -9;

                    p = packasciistr(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    vm_free(syspath);
                    syspath = NULL;
                }

            #else /* VIP_SUPPORT_NEW_BILLING */ 
                /* 编码资源指令,需要做MD5摘要和DES加密 */
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packasciistr(p, respath, (BYTE*) internal_http_req.body + req_group_size);
            #endif /* VIP_SUPPORT_NEW_BILLING */ 

            #ifdef VIP_SUPPORT_NEW_BILLING
                /* 计费信息同步 */
                if ((search_ptr = strstr(respath, VIP_SYNC_FEEINFO_URL)) != NULL)
                {
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);
                    p = packbyte(p, REQ_POST_DATA_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_SYNC_FEEINFO_URL, syspath))
                        return -9;
                    p = packasciistr(p, VIP_SYNC_FEEINFO_URL, (BYTE*) internal_http_req.body + req_group_size);
                    p = packasciistr_ex(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    vm_free(syspath);
                    syspath = NULL;
                }

                /* 短信信息同步 */
                if ((search_ptr = strstr(respath, VIP_SYNC_SMSINFO_URL)) != NULL)
                {
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);
                    p = packbyte(p, REQ_POST_DATA_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_SYNC_SMSINFO_URL, syspath))
                        return -9;
                    req_group_size += (strlen(syspath) * sizeof(VMWCHAR));
                    p = packasciistr(p, VIP_SYNC_SMSINFO_URL, (BYTE*) internal_http_req.body + req_group_size);
                    p = packasciistr_ex(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    vm_free(syspath);
                    syspath = NULL;
                }

                /* 促销金额更新 */
                if ((search_ptr = strstr(respath, VIP_PROMOTION_UPDATE_URL)) != NULL)
                {
                    /* 余额 */
                    syspath = vm_malloc(1024 * 3);
                    if (!syspath)
                    {
                        vm_free(internal_http_req.body);
                        return -9;
                    }
                    memset(syspath, 0, 1024 * 3);
                    p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                    memset(syspath, 0, sizeof(syspath));
                    if (!vip_get_resource_path(respath, VIP_PROMOTION_UPDATE_URL, syspath))
                        return -9;

                    p = packasciistr(p, syspath, (BYTE*) internal_http_req.body + req_group_size);
                    syspath = NULL;
                }
            #endif /* VIP_SUPPORT_NEW_BILLING */ 
                md5_init(&md5_state);
                md5_append(
                    &md5_state,
                    (const md5_byte_t*)internal_http_req.body + internal_http_req.nbody,
                    p - (BYTE*) (internal_http_req.body + internal_http_req.nbody));
                md5_finish(&md5_state, (md5_byte_t*) p);
                p += 16;

                if ((des_handle = vm_des_set_key(pContext->des_key)) == DES_INVALID_HANDLE)
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5523 );
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5526 ); */
                    return -5;
                }
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5530 );
            #endif 
                if ((encrypt = vm_des_encrypt(
                                des_handle,
                                (VMUINT8*) (internal_http_req.body + internal_http_req.nbody),
                                p - (BYTE*) (internal_http_req.body + internal_http_req.nbody),
                                &des_len)) == NULL)
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5539 );
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5542 ); */
                    return -6;
                }

                memcpy(internal_http_req.body + internal_http_req.nbody, encrypt, des_len);
                internal_http_req.nbody += des_len;

                vm_des_reset_key(des_handle);
                vm_free(encrypt);
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5552 );
            #endif 
            }
            else
            {
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5558 );
            #endif 
                /* MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMVIP_5560 ); */
                /* 无需加密VIP请求组 */
                internal_http_req.nbody = 5 + strlen(respath) * sizeof(VMWCHAR);

                if ((internal_http_req.body = vm_malloc(internal_http_req.nbody)) == NULL)
                {
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5567 );
                #endif 
                    //MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5569 , 
                    //       internal_http_req.nbody);
                    return -1;
                }

                /*
                 * 编码资源请求指令。
                 */
                p = (BYTE*) internal_http_req.body;
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) (internal_http_req.body + internal_http_req.nbody));
                p = packasciistr(p, respath, (BYTE*) (internal_http_req.body + internal_http_req.nbody));
            }

            /*
             * 包含session_id参数的URL。
             */
            strncpy(internal_http_req.url, PROVISION_URL, 255);

        #ifdef APPSTORE_SUPPORT_COFING
            /* shaw, 09/04/15 , 读取配置文件中的信息 */
            {
                VMCHAR *pro_url = vm_malloc(255);

                if (pro_url)
                {
                    memset(pro_url, 0, 255);
                    if (!vip_get_shell_config_value("provision_url", pro_url))
                    {
                        sprintf(internal_http_req.url, "%s", pro_url);
                    #ifdef PHSH_DEBUG
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5599 , internal_http_req.url);
                    #endif 
                    }
                    vm_free(pro_url);
                }
            }
        #endif /* APPSTORE_SUPPORT_COFING */ 
            /* 追加session id */
            strncat(
                internal_http_req.url,
                "?session_id=",
                sizeof(internal_http_req.url) - strlen(internal_http_req.url));
            strncat(
                internal_http_req.url,
                pContext->vip_session,
                sizeof(internal_http_req.url) - strlen(internal_http_req.url));
        }

    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5618 );
    #endif 

        /* rencai.xiao 2010/04/29 */
    #ifdef VIP_CHECK_DOWNLOAD_READY
        //check data account firstly.
        //http_req.http_request = &internal_http_req;
    #ifdef LOG_VIP
        // MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5626 , /*http_req.http_request.url*/internal_http_req.url);
    #endif 
        /* init asyn data */
        memcpy(&asyn_data.request, &http_req, sizeof(struct asyn_http_req_t));
        memcpy(&asyn_data.internal_http_req, &internal_http_req, sizeof(struct http_request_t));

        // strcpy(head[0].name, "Vip-Version");           
        //  strcpy(head[0].value, "1.4.1");

        //strcpy(head[1].name, "MRE-AM-BlockSize");
        //sprintf(head[1].value, "%d", block_size);

    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5639 , head[0].name);
    #endif 
        strcpy(asyn_data.head[0].name, head[0].name);
        strcpy(asyn_data.head[0].value, head[0].value);
        strcpy(asyn_data.head[1].name, head[1].name);
        strcpy(asyn_data.head[1].value, head[1].value);
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5646 , asyn_data.head[0].name);
    #endif 
        asyn_data.internal_http_req.heads = asyn_data.head;
        asyn_data.request.http_request = &asyn_data.internal_http_req;
        asyn_data.context = pContext;
        asyn_data.http_hook = http_hook_cb;
        asyn_data.http_state_notify = http_state_cb;
        asyn_data.nHandle = vip_get_connect_handle(respath);
        asyn_data.nCount = 0;

    #ifdef LOG_VIP
        /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5657 , asyn_data.internal_http_req.url); */
    #endif 
        if (vm_is_ready_dataaccount())
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5662 );
        #endif 
            return vm_vip_send_request();
        }
        else
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5669 );
        #endif 
            /* create timer check data account. */
            asyn_data.nTimer = vm_create_timer_ex(VIP_CHECK_ACCOUNT_INTERNAL, vm_vip_check_account_timer_proc);

            if (asyn_data.nTimer < 0)
            {
                vm_free(asyn_data.internal_http_req.body);
                return -1;
            }
            else
                return 0;
        }
    #else /* VIP_CHECK_DOWNLOAD_READY */ 
        /* no need check data account. */
        if ((http_ret = vm_asyn_http_req(&http_req, http_hook_cb, http_state_cb)) == ASYN_HTTP_REQ_ACCEPT_SUCCESS)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5687 );
        #endif 
            vm_get_asyn_http_req_handle(&http_req, &(pContext->http_handle));
            pContext->used = TRUE;
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5692 );
        #endif 
            if (pContext->allow_repeat)
            {
            #ifdef LOG_VIP
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5697 );
            #endif 
                if ((pContext->repeat_content = vm_malloc(internal_http_req.nbody)) != NULL)
                {
                    memcpy(pContext->repeat_content, internal_http_req.body, internal_http_req.nbody);
                    pContext->repeat_content_size = internal_http_req.nbody;
                #ifdef LOG_VIP
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5704 , pContext->repeat_content);
                #endif 
                }
            }

            vm_free(internal_http_req.body);
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5711 );
        #endif 

        }
        else
        {
            vm_free(internal_http_req.body);
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5719 , http_ret);
        #endif 
            return -3;
        }

        /* added by rencai.xiao 10/01/26 */
        if (vip_get_connect_handle(respath) == VIP_APP_HANDLE)
        {
            g_app_handle_timer = vm_create_timer_ex(VIP_CONNECT_TIME_OUT, vm_vip_app_handle_proc);
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5729 , g_app_handle_timer);
        #endif 
        }
        else
        {
            g_other_handle_timer = vm_create_timer_ex(VIP_CONNECT_TIME_OUT, vm_vip_other_handle_proc);
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5736 , g_other_handle_timer);
        #endif 
        }

    #endif /* VIP_CHECK_DOWNLOAD_READY */ /* end VIP_CHECK_DOWNLOAD_READY */
        //return 0;
    }
    else
    {
        /* context未被初始化或已被使用或传递的path为空 */
        return -1;
    }
}
#endif /* VIP14 */ 

#ifdef VIP14
/*
 * static VMINT vip_is_more_list_first_level(VMCHAR * pszPath)
 * {
 * VMCHAR * pSearch = NULL;
 * 
 * if ((pSearch = strstr(pszPath, VIP_DSM_URL)) != NULL && pszPath == pSearch)
 * {
 * if((pSearch = strstr(pszPath, "folderid")) != NULL)
 * {
 * VMCHAR szFolderValue[2];
 * memset(szFolderValue, 0, sizeof(szFolderValue));
 * if(strlen(pSearch) > 10)
 * memcpy(szFolderValue, pSearch + 9, 1);
 * else
 * return FALSE;
 * if(strcmp(szFolderValue, "0") == 0)
 * return TRUE;
 * else
 * return FALSE;
 * }
 * else
 * return FALSE;
 * }
 * else
 * return FALSE;
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  vip_get_connect_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pszPath     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vip_get_connect_handle(VMCHAR *pszPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMCHAR *pSearch = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pSearch = strstr(pszPath, VIP_UPDATE_MRE_SYS_CONFIG_URL)) != NULL && pszPath == pSearch)
        return VIP_OTHER_HANDLE;
    else if ((pSearch = strstr(pszPath, VIP_MRE_EXECUTABLE_FILE_URL)) != NULL && pszPath == pSearch)
        return VIP_APP_HANDLE;
    else if ((pSearch = strstr(pszPath, VIP_FEE_CHANNEL_RUL)) != NULL && pszPath == pSearch)
        return VIP_OTHER_HANDLE;
    else
        return VIP_OTHER_HANDLE;
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  vip_read_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  respath     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_read_resource(VMCHAR *respath)
{
#ifdef VIP14
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef LOG_VIP
    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5831 , respath); */
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_get_connect_handle(respath) == VIP_APP_HANDLE)
    {
        /* 应用 */
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5841 );
    #endif 

        return vip_read_resource_shell(vip_context_ext[0], respath, vip_http_hook_ext, vip_http_state_hook_ext);
    }
    else
    {
        /* 其它 */
    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5850 , vip_context->callback);
    #endif 
        return vip_read_resource_shell(vip_context, respath, vip_http_hook, vip_http_state_hook);
    }
#else /* VIP14 */ 
    /* MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMVIP_5855 , respath); */
    if (vip_context && !vip_context->used && respath)
    {
        asyn_http_req_t http_req;
        http_request_t internal_http_req;
        http_head_t head;
        BYTE *p = NULL;
        VMINT http_ret = ASYN_HTTP_REQ_ACCEPT_SUCCESS;
        char *search_ptr = NULL;

        /* 更新配置请求需要加码，其它的资源请求则不加密。 */
        if ((search_ptr = strstr(respath, VIP_UPDATE_MRE_SYS_CONFIG_URL)) != NULL && respath == search_ptr)
        {
            generate_des_key(vip_context->des_key);
            vip_context->encrypt = TRUE;
        }
        else
        {
            /* 不需要加密 */
            memset(vip_context->des_key, 0x00, sizeof(vip_context->des_key));
            vip_context->encrypt = FALSE;
        }

        /* 附加请求头增加Vip-Version, 新版本中值需修改为1.4 */
        strcpy(head.name, "Vip-Version");
        //modified by rencai.xiao 2010/04/20 
        //version 1.4.1 : upload imsi
    #ifdef VIP14
    #ifdef VIP_SUPPORT_UPLOAD_IMSI
        strcpy(head.value, "1.4.1");
    #else 
        strcpy(head.value, "1.4");
    #endif 
    #else /* VIP14 */ 
        strcpy(head.value, "1.3")
    #endif /* VIP14 */ 
            internal_http_req.nhead = 1;    /* 附加请求头个数 */
        internal_http_req.heads = &head;    /* 附加请求头数组指针 */
        internal_http_req.body = NULL;      /* 附加请求体指针 */
        internal_http_req.nbody = 0;        /* 附加请求体的长度，字节单位 */

        http_req.req_method = POST; /* <HTTP_METHOD类型,客户端发起请求的方法必须用POST */

    #ifdef VIP14
        if (vm_is_support_wifi())
            http_req.use_proxy = vip_get_connect_type();
        else
            http_req.use_proxy = HTTP_USE_CMWAP_PRIORITY;
    #else /* VIP14 */ 
    #ifdef WIFI_VERSION     /* 新版本中需要从NVRAM中获取 */
        http_req.use_proxy = GetProxy();        // /*TRUE*/HTTP_USE_CMWAP_PRIORITY;
    #else 
        http_req.use_proxy = /* TRUE */ HTTP_USE_CMWAP_PRIORITY;
    #endif 
    #endif /* VIP14 */ 
        http_req.http_request = &internal_http_req; /* <HTTP请求。 */

    #ifdef PHSH_DEBUG
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5913 );
    #endif 
        if (strlen(vip_context->vip_session) == 0)  /* 第一次会话 */
        {
            strncpy(internal_http_req.url, PROVISION_URL, 255); /* 联网地址 */

        #ifdef PHSH_DEBUG
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_5920 );
        #endif 
        #ifdef APPSTORE_SUPPORT_COFING
            /* shaw, 09/04/15 , 读取配置文件中的信息 */
            {
                VMCHAR *pro_url = vm_malloc(255);

                if (pro_url)
                {
                    memset(pro_url, 0, 255);
                    if (!vip_get_shell_config_value("provision_url", pro_url))
                    {
                        sprintf(internal_http_req.url, "%s", pro_url);
                    #ifdef PHSH_DEBUG
                        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMVIP_5934 , internal_http_req.url);
                    #endif 
                    }
                    vm_free(pro_url);
                }
            }
        #endif /* APPSTORE_SUPPORT_COFING */ 

            if (vip_context->encrypt)
            {
                /* 需要加密请求 */
                VMINT req_group_size = 0;
                VMINT rsa_len = 64, des_handle = 0, des_len = 0;
                md5_state_t md5_state;
                VMUINT8 *encrypt = NULL;

                /* 计算Body长度 */
                req_group_size += VIP13_MAX_CONNECT_COMMAND_LEN;        /* 连接指令长度 */
                req_group_size += ENCRYPT_VIP_COMMAND_LEN;  /* 加密指令长度 */
                req_group_size += (strlen(respath) * sizeof(VMWCHAR) + MD5_DIGEST_LEN + DES_PADDING_LEN);       /* path以及MD5,DES长度 */

                if ((internal_http_req.body = vm_malloc(req_group_size)) == NULL)
                    return -1;

                /* 编码连接指令。 */
                /*
                 * CONNECT_CMD USER_ID MOBILE_PHONE_ID USER_AGENT MRE_VERSION MTK_VERSION 
                 * SCREEN_WIDTH SCREEN_HEIGHT MEMORY_SIZE SUPPORT_KEYPAD SUPPORT_TOUCH
                 */
                /* 连接指令的最大长度为：VIP13_MAX_CONNECT_COMMAND_LEN */
                if ((p = plus_connect_cmd(
                            (BYTE*) internal_http_req.body,
                            (BYTE*) internal_http_req.body + VIP13_MAX_CONNECT_COMMAND_LEN))
                    <= (BYTE*) internal_http_req.body)
                {
                    vm_free(internal_http_req.body);
                    return -2;
                }
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;

                /* 编码加密指令. *//* SECURE_CMD CERT_ID PUBK_ENCRYPT_DES_KEY */
                p = packbyte(p, REQ_ENCRYPT_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packint(p, 0, (BYTE*) internal_http_req.body + req_group_size);    /* 0号证书 */
                p = packint(p, 64, (BYTE*) internal_http_req.body + req_group_size);   /* DES密钥长度 */

            #ifndef PHSH_VIP_DEBUG  /* 用指定的密钥对给定的内容签名 */
                if (vm_ce_init() == 0 && 0 == vm_rsa_sign_by_id(
                                                vip_context->des_key,
                                                8,  /* for test */
                                                0,
                                                p,
                                                &rsa_len,
                                                PUB_PADDING))   /* 用公钥签名 */
            #else /* PHSH_VIP_DEBUG */ 
                if (0 == vm_rsa_sign(vip_context->des_key, 8, &pubKey, p, &rsa_len, PUB_PADDING))
            #endif /* PHSH_VIP_DEBUG */ 
                    //                              if (0 == vm_ce_init() && 0 == vm_rsa_sign_by_id(vip_context->des_key, 8, 
                    //                                      0, p, &rsa_len, PUB_PADDING))
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                    if (rsa_len != 64)
                    {
                        vm_free(internal_http_req.body);
                        return -3;
                    }
                }
                else
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6008 ); */
                    return -4;
                }
                p += 64;
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;

                /* 编码资源指令,需要做MD5摘要和DES加密 *//* READ_RES_CMD RES_PATH */
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packasciistr(p, respath, (BYTE*) internal_http_req.body + req_group_size);
                md5_init(&md5_state);
                md5_append(
                    &md5_state,
                    (const md5_byte_t*)internal_http_req.body + internal_http_req.nbody,
                    p - (BYTE*) (internal_http_req.body + internal_http_req.nbody));
                md5_finish(&md5_state, (md5_byte_t*) p);
                p += 16;

                if ((des_handle = vm_des_set_key(vip_context->des_key)) == DES_INVALID_HANDLE)
                {
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6028 ); */
                    return -5;
                }

                if ((encrypt = vm_des_encrypt(
                                des_handle,
                                (VMUINT8*) (internal_http_req.body + internal_http_req.nbody),
                                p - (BYTE*) (internal_http_req.body + internal_http_req.nbody),
                                &des_len)) == NULL)
                {
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6039 ); */
                    return -6;
                }

                memcpy(internal_http_req.body + internal_http_req.nbody, encrypt, des_len);
                internal_http_req.nbody += des_len;

                vm_des_reset_key(des_handle);
                vm_free(encrypt);
            }
            else
            {
                /* 无须加密请求 */
                if ((internal_http_req.body = vm_malloc(VIP13_MAX_CONNECT_COMMAND_LEN +
                                                        5 + strlen(respath) * sizeof(VMWCHAR))) == NULL)
                    return -1;

                /* 编码连接指令。 */
                if ((p = plus_connect_cmd(
                            (BYTE*) internal_http_req.body,
                            (BYTE*) internal_http_req.body + VIP13_MAX_CONNECT_COMMAND_LEN))
                    <= (BYTE*) internal_http_req.body)
                {
                    vm_free(internal_http_req.body);
                    return -2;
                }
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;

                /* 编码资源指令。 */
                internal_http_req.nbody += (5 + strlen(respath) * sizeof(VMWCHAR));
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + internal_http_req.nbody);
                p = packasciistr(p, respath, (BYTE*) internal_http_req.body + internal_http_req.nbody);
            }
        }
        else
        {
            /* 不是第一次会话 */
            if (vip_context->encrypt)
            {
                /* 需要加密VIP请求组 */
                VMINT req_group_size = 0;
                VMINT rsa_len = 64, des_handle = 0, des_len = 0;
                md5_state_t md5_state;
                VMUINT8 *encrypt = NULL;

                req_group_size += ENCRYPT_VIP_COMMAND_LEN;
                req_group_size += (strlen(respath) * sizeof(VMWCHAR) + MD5_DIGEST_LEN + DES_PADDING_LEN);

                if ((internal_http_req.body = vm_malloc(req_group_size)) == NULL)
                    return -1;

                /* 编码加密指令. */
                p = (BYTE*) internal_http_req.body;
                p = packbyte(p, REQ_ENCRYPT_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packint(p, 0, (BYTE*) internal_http_req.body + req_group_size);
                p = packint(p, 64, (BYTE*) internal_http_req.body + req_group_size);
            #ifndef PHSH_VIP_DEBUG

                if (vm_ce_init() == 0 && 0 == vm_rsa_sign_by_id(vip_context->des_key, 8, 0, p, &rsa_len, PUB_PADDING))
            #else /* PHSH_VIP_DEBUG */ 
                if (0 == vm_rsa_sign(vip_context->des_key, 8, &pubKey, p, &rsa_len, PUB_PADDING))

            #endif /* PHSH_VIP_DEBUG */ 
                    //                              if (0 == vm_ce_init() && 0 == vm_rsa_sign_by_id(vip_context->des_key, 8, 
                    //                                      0, p, &rsa_len, PUB_PADDING))
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                    if (rsa_len != 64)
                    {
                        vm_free(internal_http_req.body);
                        return -3;
                    }
                }
                else
                {
                #ifndef PHSH_VIP_DEBUG
                    vm_ce_finialize();
                #endif 
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6120 ); */
                    return -4;
                }
                p += 64;
                internal_http_req.nbody = p - (BYTE*) internal_http_req.body;

                /* 编码资源指令,需要做MD5摘要和DES加密 */
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) internal_http_req.body + req_group_size);
                p = packasciistr(p, respath, (BYTE*) internal_http_req.body + req_group_size);
                md5_init(&md5_state);
                md5_append(
                    &md5_state,
                    (const md5_byte_t*)internal_http_req.body + internal_http_req.nbody,
                    p - (BYTE*) (internal_http_req.body + internal_http_req.nbody));
                md5_finish(&md5_state, (md5_byte_t*) p);
                p += 16;

                if ((des_handle = vm_des_set_key(vip_context->des_key)) == DES_INVALID_HANDLE)
                {
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6140 ); */
                    return -5;
                }

                if ((encrypt = vm_des_encrypt(
                                des_handle,
                                (VMUINT8*) (internal_http_req.body + internal_http_req.nbody),
                                p - (BYTE*) (internal_http_req.body + internal_http_req.nbody),
                                &des_len)) == NULL)
                {
                    vm_free(internal_http_req.body);
                    /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6151 ); */
                    return -6;
                }

                memcpy(internal_http_req.body + internal_http_req.nbody, encrypt, des_len);
                internal_http_req.nbody += des_len;

                vm_des_reset_key(des_handle);
                vm_free(encrypt);
            }
            else
            {
                /* MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMVIP_6163 ); */
                /* 无需加密VIP请求组 */
                internal_http_req.nbody = 5 + strlen(respath) * sizeof(VMWCHAR);

                if ((internal_http_req.body = vm_malloc(internal_http_req.nbody)) == NULL)
                {
                    //MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6169 , 
                    //       internal_http_req.nbody);
                    return -1;
                }

                /*
                 * 编码资源请求指令。
                 */
                p = (BYTE*) internal_http_req.body;
                p = packbyte(p, REQ_READRES_CMD, (BYTE*) (internal_http_req.body + internal_http_req.nbody));
                p = packasciistr(p, respath, (BYTE*) (internal_http_req.body + internal_http_req.nbody));
            }

            /*
             * 包含session_id参数的URL。
             */
            strncpy(internal_http_req.url, PROVISION_URL, 255);

        #ifdef APPSTORE_SUPPORT_COFING
            /* shaw, 09/04/15 , 读取配置文件中的信息 */
            {
                VMCHAR *pro_url = vm_malloc(255);

                if (pro_url)
                {
                    memset(pro_url, 0, 255);
                    if (!vip_get_shell_config_value("provision_url", pro_url))
                    {
                        sprintf(internal_http_req.url, "%s", pro_url);
                    #ifdef PHSH_DEBUG
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6199 , internal_http_req.url);
                    #endif 
                    }
                    vm_free(pro_url);
                }
            }
        #endif /* APPSTORE_SUPPORT_COFING */ 
            /* 追加session id */
            strncat(
                internal_http_req.url,
                "?session_id=",
                sizeof(internal_http_req.url) - strlen(internal_http_req.url));
            strncat(
                internal_http_req.url,
                vip_context->vip_session,
                sizeof(internal_http_req.url) - strlen(internal_http_req.url));
        }

        /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6217 ); */
        if ((http_ret = vm_asyn_http_req(&http_req, vip_http_hook, vip_http_state_hook))
            == ASYN_HTTP_REQ_ACCEPT_SUCCESS)
        {
            vm_get_asyn_http_req_handle(&http_req, &(vip_context->http_handle));
            vip_context->used = TRUE;

            if (vip_context->allow_repeat)
            {
                if ((vip_context->repeat_content = vm_malloc(internal_http_req.nbody)) != NULL)
                {
                    memcpy(vip_context->repeat_content, internal_http_req.body, internal_http_req.nbody);
                    vip_context->repeat_content_size = internal_http_req.nbody;
                }
            }

            vm_free(internal_http_req.body);

        }
        else
        {
            vm_free(internal_http_req.body);
            /* MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6239 , http_ret); */
            return -3;
        }

        return 0;
    }
    else
    {
        /* context未被初始化或已被使用或传递的path为空 */
        return -1;
    }
#endif /* VIP14 */ 
}


/*****************************************************************************
 * FUNCTION
 *  vip_ask_for_price
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pay_point_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_ask_for_price(VMINT pay_point_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vip_get_user_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_get_user_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vip_pay_by_wap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pay_point_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_pay_by_wap(int pay_point_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vip_get_user_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_get_user_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return -1;
}

#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  vip_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vip_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_context)
    {
        if (vip_context->repeat_content)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_6373 , vip_context->repeat_content);
        #endif 
            vm_free(vip_context->repeat_content);
            vip_context->repeat_content = NULL;
        }

        vm_free(vip_context);
        vip_context = NULL;
    }

    for (i = 0; i < VIP14_SUPPORT_CONNECT_NUM - 1; i++)
    {

        if (vip_context_ext[i])
        {
        #ifdef LOG_VIP
            vm_log_debug(
                "vip_context_ext[%d] = %p, callback = %p",
                i,
                vip_context_ext[i],
                vip_context_ext[i]->callback);
        #endif /* LOG_VIP */ 

            if (vip_context_ext[i]->repeat_content)
            {
            #ifdef LOG_VIP
                vm_log_debug(
                    "[VIP] vm_free vip_context_ext[i]->repeat_content = %p",
                    vip_context_ext[i]->repeat_content);
            #endif /* LOG_VIP */ 
                vm_free(vip_context_ext[i]->repeat_content);
                vip_context_ext[i]->repeat_content = NULL;
            }
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_6407 , vip_context_ext[i]);
        #endif 
            vm_free(vip_context_ext[i]);
            vip_context_ext[i] = NULL;
        }
    }

    g_callback = NULL;
    g_app_callback = NULL;
    g_app_progress_hook = NULL;
    g_progress_hook = NULL;

#ifdef LOG_VIP
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6420 );
#endif 
    /* added by rencai.xiao 10/01/26 */
    if (g_other_handle_timer > 0)
    {
        vm_delete_timer_ex(g_other_handle_timer);
        g_other_handle_timer = -1;
    }
    if (g_app_handle_timer > 0)
    {
        vm_delete_timer_ex(g_app_handle_timer);
        g_app_handle_timer = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vip_cancel_request_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nHandle     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vip_cancel_request_handle(VMINT nHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rencai.xiao 2010/04/29 */
#ifdef VIP_CHECK_DOWNLOAD_READY
    if (asyn_data.nTimer >= 0)
    {
        vm_delete_timer_ex(asyn_data.nTimer);
        asyn_data.nTimer = -1;
    }
    if (asyn_data.internal_http_req.body)
    {
        vm_free(asyn_data.internal_http_req.body);
        asyn_data.internal_http_req.body = NULL;
    }
#endif /* VIP_CHECK_DOWNLOAD_READY */ 
    if (nHandle == VIP_OTHER_HANDLE)
    {
        /* added by rencai.xiao 10/01/26 */
        if (g_other_handle_timer > 0)
        {
        #ifdef LOG_VIP
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6474 );
        #endif 
            vm_delete_timer_ex(g_other_handle_timer);
            g_other_handle_timer = -1;
        }
        g_callback = NULL;
        g_progress_hook = NULL;
        if (vip_context)
        {
            if (vip_context->used)
                vm_cancel_asyn_http_req(vip_context->http_handle);
            if (vip_context->repeat_content)
            {
                vm_free(vip_context->repeat_content);
                vip_context->repeat_content = NULL;
            }
            vm_free(vip_context);
            vip_context = NULL;
        }
    }
    else if (nHandle == VIP_APP_HANDLE)
    {
        VMINT i;

    #ifdef LOG_VIP
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6499 );
    #endif 
        /* added by rencai.xiao 10/01/26 */
        if (g_app_handle_timer > 0)
        {
            vm_delete_timer_ex(g_app_handle_timer);
            g_app_handle_timer = -1;
        }
        g_app_callback = NULL;
        g_app_progress_hook = NULL;
        for (i = 0; i < VIP14_SUPPORT_CONNECT_NUM - 1; i++)
        {
            if (vip_context_ext[i])
            {
                if (vip_context_ext[i]->used)
                    vm_cancel_asyn_http_req(vip_context_ext[i]->http_handle);
                if (vip_context_ext[i]->repeat_content)
                {
                    vm_free(vip_context_ext[i]->repeat_content);
                    vip_context_ext[i]->repeat_content = NULL;
                }
                vm_free(vip_context_ext[i]);
                vip_context_ext[i] = NULL;
            }
        }
    }
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  vip_cancel_request_and_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vip_cancel_request_and_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef VIP14
    VMINT i;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_context)
    {
        if (vip_context->used)
            vm_cancel_asyn_http_req(vip_context->http_handle);
        if (vip_context->repeat_content)
        {
            vm_free(vip_context->repeat_content);
            vip_context->repeat_content = NULL;
        }
        vm_free(vip_context);
        vip_context = NULL;
    }
    /* added by rencai.xiao 10/01/26 */
    if (g_other_handle_timer > 0)
    {
        vm_delete_timer_ex(g_other_handle_timer);
        g_other_handle_timer = -1;
    }

#ifdef VIP14
    for (i = 0; i < VIP14_SUPPORT_CONNECT_NUM - 1; i++)
    {
        /* added by rencai.xiao 10/01/26 */
        if (g_app_handle_timer > 0)
        {
            vm_delete_timer_ex(g_app_handle_timer);
            g_app_handle_timer = -1;
        }
        vm_log_debug(
            "[TEST] vip_context_ext[%d, %p ~ %p]",
            i,
            vip_context_ext[i],
            vip_context_ext[i] + sizeof(vm_vip_item_t));
        if (vip_context_ext[i])
        {
            if (vip_context_ext[i]->used)
                vm_cancel_asyn_http_req(vip_context_ext[i]->http_handle);
            if (vip_context_ext[i]->repeat_content)
            {
                vm_free(vip_context_ext[i]->repeat_content);
                vip_context_ext[i]->repeat_content = NULL;
            }
            vm_free(vip_context_ext[i]);
            vip_context_ext[i] = NULL;
        }
    }

    g_callback = NULL;
    g_app_callback = NULL;
    g_progress_hook = NULL;
    g_app_progress_hook = NULL;
#endif /* VIP14 */ 

    /* rencai.xiao 2010/04/29 */
#ifdef VIP_CHECK_DOWNLOAD_READY
    if (asyn_data.nTimer >= 0)
    {
        vm_delete_timer_ex(asyn_data.nTimer);
        asyn_data.nTimer = -1;
    }
    if (asyn_data.internal_http_req.body)
    {
        vm_free(asyn_data.internal_http_req.body);
        asyn_data.internal_http_req.body = NULL;
    }
#endif /* VIP_CHECK_DOWNLOAD_READY */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_vip_progress_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hook        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT register_vip_progress_callback(vm_vip_progress_callback hook)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_context)
    {
        vip_context->progress_hook = hook;
        g_progress_hook = hook;
        return 0;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_6647 );
        if (vip_init_ext(g_phoneid, g_userid, VIP_OTHER_HANDLE) != 0)
            return -1;
        vip_context->callback = g_callback;
        vip_context->progress_hook = hook;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  register_vip_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pf      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT register_vip_callback(vm_vip_callback pf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_context)
    {
        vip_context->callback = pf;
        g_callback = pf;
        return 0;
    }
    else
    {

        MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_6686 );
        if (vip_init_ext(g_phoneid, g_userid, VIP_OTHER_HANDLE) != 0)
            return -1;
        vip_context->callback = pf;
        vip_context->progress_hook = g_progress_hook;
    }

    return 0;
}

#ifdef VIP14


/*****************************************************************************
 * FUNCTION
 *  register_vip_progress_callback_for_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hook        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT register_vip_progress_callback_for_app(vm_vip_progress_callback hook)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_context_ext[0])
    {
        vip_context_ext[0]->progress_hook = hook;
        g_app_progress_hook = hook;
        return 0;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_6726 );
        if (vip_init_ext(g_phoneid, g_userid, VIP_APP_HANDLE) != 0)
            return -1;
        vip_context_ext[0]->callback = g_app_callback;
        vip_context_ext[0]->progress_hook = hook;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  register_vip_callback_for_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pf      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT register_vip_callback_for_app(vm_vip_callback pf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vip_context_ext[0])
    {
        vip_context_ext[0]->callback = pf;
        g_app_callback = pf;
        return 0;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMVIP, TRC_MRE_VMVIP_6764 );
        if (vip_init_ext(g_phoneid, g_userid, VIP_APP_HANDLE) != 0)
            return -1;
        vip_context_ext[0]->callback = pf;
        vip_context_ext[0]->progress_hook = g_app_progress_hook;
    }

    return 0;
}
#endif /* VIP14 */ 


/*****************************************************************************
 * FUNCTION
 *  cancel_all_vip_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cancel_all_vip_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vip_cancel_request_and_finalize();
}

/*
 * Add VIP as a system module
 */


/*****************************************************************************
 * FUNCTION
 *  vm_initialize_vip_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_initialize_vip_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6822 );
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_finialize_vip_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_finialize_vip_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6846 );
    vip_cancel_request_and_finalize();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vip_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vip_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            if (0 != vm_initialize_vip_module())
                return -1;
            break;
        case EVT_MOD_ACTIVE:
            break;
        case EVT_MOD_INACTIVE:
            break;
        case EVT_MOD_RELEASE:
            vm_finialize_vip_module();
            break;
        default:
            MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6885 , event);
            return -2;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_reg_vip_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_vip_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res_code = REG_MRE_MODULE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res_code = _vm_reg_module("VIP MODULE", (MOD_EVT_PROCESS) vip_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_6915 , res_code);
    }

    return res_code;
}

#ifdef APPSTORE_SUPPORT_COFING
/* shaw */


/*****************************************************************************
 * FUNCTION
 *  vip_get_a_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pString     [?]     
 * RETURNS
 *  
 *****************************************************************************/
int vip_get_a_line(char *pString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *pTemp = pString;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*(pTemp) != 0x0d) && (*(pTemp++) != 0x00));

    return pTemp - pString;
}


/*****************************************************************************
 * FUNCTION
 *  vip_get_key_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pLine       [?]     
 *  key         [?]     
 *  value       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vip_get_key_value(VMCHAR *pLine, VMCHAR *key, VMCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMCHAR *pos = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = strstr(pLine, key);
    if (pos)
    {
        pos = strstr(pLine, "=");
        if (pos)
        {
            pos++;
            memcpy(value, pos, strlen(pos));
        }
        else
            return -1;
    }
    else
        return -1;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vip_get_shell_config_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_value       [?]     
 *  pro_url         [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vip_get_shell_config_value(VMCHAR *key_value, VMCHAR *pro_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static VMCHAR filename[64];
    WCHAR wcfilename[64];
    VMINT filedrv;
    VMINT filehandle;
    static struct vm_fileinfo_t fileinfo;
    VMCHAR *pCatch = NULL, *pLine = NULL, *pStr = NULL;
    VMUINT filesize;
    VMUINT nread;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef PHSH_DEBUG
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_7021 , key_value);
#endif 
    filedrv = vm_get_removable_driver();
    if (filedrv < 0)
        filedrv = vm_get_system_driver();
    if (filedrv > 0)
    {
        memset(filename, 0, sizeof(filename));
        sprintf(filename, "%c:\\%s", filedrv, SHELL_CONFIG_FILENAME);
        mmi_asc_to_wcs(wcfilename, filename);

        filehandle = vm_find_first(wcfilename, &fileinfo);
        if (filehandle >= 0)
        {
            vm_find_close(filehandle);
            filehandle = vm_file_open(wcfilename, MODE_READ, TRUE);
            if (filehandle >= 0)
            {
                vm_file_getfilesize(filehandle, &filesize);
                pCatch = vm_malloc(filesize + 2);

                if (pCatch)
                {
                    memset(pCatch, 0, filesize + 2);
                    if (vm_file_read(filehandle, pCatch, filesize, &nread) != (VMINT) filesize)
                    {
                        vm_file_close(filehandle);
                        vm_free(pCatch);
                        return 0;
                    }
                    vm_file_close(filehandle);

                    /* get a line and parse */
                    pStr = pCatch;

                    pLine = vm_malloc(1024);
                    if (pLine)
                    {
                        VMINT line_len;

                        memset(pLine, 0, 1024);

                        line_len = vip_get_a_line(pStr);

                        memcpy(pLine, pStr, line_len);

                        if (strcmp(pLine, "[Options]") == 0)
                            pStr += line_len + 2;

                        memset(pLine, 0, 1024);
                        line_len = vip_get_a_line(pStr);
                        memcpy(pLine, pStr, line_len);

                        if (vip_get_key_value(pLine, key_value, pro_url))
                        {
                            pStr += line_len + 2;
                            memset(pLine, 0, 1024);
                            line_len = vip_get_a_line(pStr);
                            memcpy(pLine, pStr, line_len);
                            if (vip_get_key_value(pLine, key_value, pro_url))
                            {
                                vm_free(pLine);
                                vm_free(pCatch);
                                return -1;
                            }
                        }

                        vm_free(pLine);
                    }

                    vm_free(pCatch);
                    return 0;
                }
                else
                {
                    vm_file_close(filehandle);
                    return -1;
                }
            }

            return 0;
        }
    }

#ifdef PHSH_DEBUG
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMVIP_7106 );
#endif 

    return -1;
}
#endif /* APPSTORE_SUPPORT_COFING */ 
#endif /* VIP12 */ 

void vip_vg_set_update(VMINT is_updating)
{
    g_is_updating = is_updating;
}

#else /* __MRE_LIB_NETWORK_VIP_VG__ */ 


VMINT register_vip_callback(vm_vip_callback pf)
{return 0;}

VMINT register_vip_callback_for_app(vm_vip_callback pf)
{return 0;}

VMINT vip_init(VMINT phoneid, VMINT userid)
{return 0;}

VMINT vip_init_ext(VMINT phoneid, VMINT userid, VMINT nHandle)
{return 0;}

VMINT register_vip_progress_callback(vm_vip_progress_callback hook)
{return 0;}

VMINT register_vip_progress_callback_for_app(vm_vip_progress_callback progress_hook)
{return 0;}

VMINT vip_read_resource(VMCHAR* respath)
{return 0;}

void cancel_all_vip_request(void)
{}

void vip_cancel_request_and_finalize(void)
{}

void vip_cancel_request_handle(VMINT nHandle)
{}


#endif /* __MRE_LIB_NETWORK_VIP_VG__ */ 
#endif /* __MRE_LIB_NETWORK_VIP__ */ 

