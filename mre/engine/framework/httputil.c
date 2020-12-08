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
 * httputil.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vmswitch.h"

#ifdef __MRE_LIB_HTTP__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vmsys.h"
#include "vmhttp.h"
#include "httputil.h"
#include "vmstdlib.h"
#include "vmlog.h"
#include "vmmod.h"



/* ------------------------------------------------------------------------
 * 模块内部变量声明。
 * ----------------------------------------------------------------------- */
/*
  * http 模块是否正在运行的标志。
  */
//static VMUINT8 http_module_running = FALSE;

/*
 * HTTP会话队列。
 */
//static struct queue_item_t* queue_items = NULL;

/*
  * HTTP模块初始化函数。
  */
//static VMINT initialize_http_module(void);

/*
  * HTTP模块的清理函数。
  */
//static VMINT finialize_http_module(void);

/* ------------------------------------------------------------------
  * 文件作用域的函数定义。
  * -----------------------------------------------------------------*/
/*
static VMINT initialize_http_module(void)
{
    if (!http_module_running)
    {
        http_module_running = TRUE;
        if ((queue_items = vm_malloc(sizeof(struct queue_item_t) * QUEUE_SIZE)) == NULL)
        {
            return -1;
        }
        memset(queue_items, 0x00, sizeof(struct queue_item_t) * QUEUE_SIZE);
    }
    return 0;
}

static VMINT finialize_http_module(void)
{
    if (http_module_running)
    {
        vm_cancel_all_http_sessions();
        http_module_running = FALSE;
        if (queue_items)
        {
            vm_free(queue_items);
            queue_items = NULL;
        }
    }
    return 0;
}
*/
/* ------------------------------------------------------------------------
 * 全局函数声明。
 * ----------------------------------------------------------------------- */
//extern _close_socket(SOCKET_T socket);

/* ------------------------------------------------------------------------
  * 全部局函数定义
  * ------------------------------------------------------------------------*/
/*
VMINT _vm_reg_http_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("HTTP MODULE", (MOD_SETUP_FUNC)initialize_http_module, 
        (MOD_CLEANUP_FUNC)finialize_http_module)) != REG_MRE_MODULE_SUCCESS)
    {
        vm_log_error("Failed to regisiter http module. Error Code : %d", res_code);
    }

    return res_code;
}

void proc_queue(int tid) 
{
    int i;

    for (i = 0; http_module_running && i < QUEUE_SIZE; i++) 
    {
        if (queue_items[i].active) 
        {
            if (proc_session(queue_items + i) == 0) 
            {
                if (queue_items[i].session->s > 0)
                    _close_socket(queue_items[i].session->s);
                queue_items[i].active = 0;
            }
        }
    }
}

void proc_queue_item(struct queue_item_t* item) 
{	
    if (http_module_running && item->active) 
    {
        if (proc_session(item) == 0) 
        {
            if (item->session->s > 0)
                _close_socket(item->session->s);
            item->active = 0;
        }
    }
}

struct queue_item_t* enqueue(http_session_t* session) 
{
    int i;

    for (i = 0; http_module_running && i < QUEUE_SIZE; i++) 
    {
        if (!queue_items[i].active) 
        {
            vm_log_debug("enqueue() session->hook: 0x%x.", session->hook);
            queue_items[i].active = 1;
            queue_items[i].session = session;
            queue_items[i].state = CONNECTING;
            queue_items[i].dns_req_id = 100 + i;
            
            return queue_items + i;
        }
    }
    
    return NULL;
}

void vm_cancel_all_http_sessions(void) 
{
    int i;
    
    for (i = 0; http_module_running && i < QUEUE_SIZE; i++) 
    {
        if (queue_items[i].active) 
        {
            if (queue_items[i].session->s > 0)
                _close_socket(queue_items[i].session->s);
            if (queue_items[i].session->nresbody > 0 && queue_items[i].session->resbody != NULL)
                vm_free(queue_items[i].session->resbody);
            queue_items[i].active = FALSE;
            queue_items[i].session->hook = NULL;
        }
    }
}

struct queue_item_t* get_item_by_dns_req_id(int dns_req_id) 
{
    int i;

    for (i = 0; http_module_running && i < QUEUE_SIZE; i++) 
    {
        if (queue_items[i].active && (queue_items[i].dns_req_id == dns_req_id))
            return queue_items + i;
    }

    return NULL;
}

struct queue_item_t* get_item_by_soc_id(SOCKET_T soc_id) 
{
    int i;

    for (i = 0; http_module_running && i < QUEUE_SIZE; i++) 
    {
        if (queue_items[i].active && (queue_items[i].session->s == soc_id))
            return queue_items + i;
    }

    return NULL;
}
*/

/*****************************************************************************
 * FUNCTION
 *  unpack_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url         [?]     
 *  scheme      [?]     
 *  host        [?]     
 *  port        [?]     
 *  res         [?]     
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int unpack_url(char *url, char *scheme, char *host, int *port, char *res, char *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * TODO:
     * param is unimplemented
     * FLOW:
     * url      http://61.236.127.192/ucenter/data/avatar/000/00/00/01_avatar_middle.jpg?name=value
     * scheme   http
     * host     61.236.127.192
     * port     80
     * res      ucenter/data/avatar/000/00/00/01_avatar_middle.jpg
     * param name=value
     */
    char *p, *src;
    char t[255];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url == NULL)
        return -1;
    src = url;

    /* scheme */
    p = strstr(src, "://");
    if (NULL == p)
        return -2;
    strncpy(scheme, src, p - src);
    scheme[p - src] = '\0';
    src = p + 3;

    /* host */
    p = strstr(src, "/");
    if (NULL == p) 
    {
        unpack_host(src, host, port);
        src = "/";
    }
    else 
    {
        strncpy(t, src, p - src);
        t[p - src] = '\0';
        unpack_host(t, host, port);
        src = p;
    }
    
    /* resource */
    strcpy(res, src);
    strcpy(param, "\0");

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  add_http_request_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session     [?]     
 *  name        [?]     
 *  value       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int add_http_request_head(http_session_t *session, VMCHAR* name, VMCHAR* value) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int length = 0, offset = 0;
    //char s[255] = {0};	/*linminqi - 2009-11-18*/
    char s[511] = {0};
    char *p1 = NULL, *p2 = NULL, *p = NULL;
    int len;
    char * buf;
    int nbuf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!session || !name || !value)
        return -1;
    len = strlen(name);
    if (len == 0 || len + strlen(value) >= (511 - 5))
        return -1;
    buf = session->reqbuf;
    nbuf = session->nreqbuf;
    sprintf(s, "%s: ", name);
    p1 = strstr(buf, name);
    
    sprintf(s, "%s: %s\r\n", name, value);
    length = strlen(s);
    if (!p1)    /* No same name HTTP HEAD */
    {
        if (nbuf + length >= HTTP_REQUEST_BUFSIZE)
            return -1;

        memcpy((char*)(buf + nbuf), s, length);
        session->nreqbuf += length;
    }
    else
    {
        p2 = strstr(p1, "\r\n");
        if (p2)
        {
            p2 += 2;
            offset = length - (p2 - p1);
            
            if (offset + nbuf >= HTTP_REQUEST_BUFSIZE)
                return -1;
            
            if (offset > 0)
            {   /* move backward */
                p = buf + nbuf - 1;
                while (p >= p2 && p > buf)
                {
                    *(p + offset) = *p;
                    p--;
                }
            }
            else if (offset < 0)
            {   /* move forward */
                p = p2;
                while (p <= (buf + nbuf - 1))
                {
                    *(p + offset) = *p;
                    p++;
                }
            }

            memcpy(p1, s, length);
            session->nreqbuf += offset;
        }
        else
            return -1;
    }	

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  reset_http_request_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session     [?]     
 *  line        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int reset_http_request_line(http_session_t *session, VMCHAR* line) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * TODO:
     * ------------------------------------------------------------
     * Request-Line   |GET/POST $url$ HTTP/1.1\r\n
     * ------------------------------------------------------------
     * p1           p2  
*/	
    int length = 0, offset = 0;
    char s[511 + 512] = {0};
    char *p1 = NULL, *p2 = NULL, *p = NULL;
    int len;
    char * buf;
    int nbuf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(line);
    if (!session || !line || len == 0 || len >= (511 + 512 - 9))
        return -1;
    buf = session->reqbuf;
    nbuf = session->nreqbuf;
    p1 = buf;   /* strchr(session->reqbuf, ' ')+1; */

    sprintf(s, "%s", line);
    length = strlen(s);
    if (!p1)							/* No space in request line */
    {
        return -1;
    }
    else
    {
        p2 = strstr(p1, "\r\n");
        if (p2)
        {
            p2 += 2;
            offset = length - (p2 - p1);
            
            if (offset + nbuf >= HTTP_REQUEST_BUFSIZE)
                return -1;
            
            if (offset > 0)
            {	
                /* move backward */										
                p = buf + nbuf - 1;
                while (p >= p2 && p > buf)
                {
                    *(p + offset) = *p;
                    p--;
                }
            }
            else if (offset < 0)
            {	
                /* move forward */ 
                p = p2;
                while (p <= (buf + nbuf - 1))
                {
                    *(p + offset) = *p;
                    p++;
                }
            }

            memcpy(p1, s, length);
            session->nreqbuf += offset;
        }
        else
            return -1;
    }	

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  set_http_request_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session     [?]         
 *  len         [IN]        
 *  buf         [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT set_http_request_body(http_session_t *session, VMINT len, void* buf) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*TODO:
     * ---------------------------------------------
     * Content-Length: $len$\r\n
     * ---------------------------------------------
     * \r\n
     * ---------------------------------------------
     * $body$
     * ---------------------------------------------
*/
    char s[255];
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
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(s, "Content-Length: %d\r\n", len);
    if (session->nreqbuf + strlen(s) >= HTTP_REQUEST_BUFSIZE)
        return -1;
    memcpy((char*)(session->reqbuf + session->nreqbuf), s, strlen(s));
    session->nreqbuf += strlen(s);

    if (session->nreqbuf + len + 2 >= HTTP_REQUEST_BUFSIZE)
        return -1;
    
    memcpy((char*)(session->reqbuf + session->nreqbuf), "\r\n", 2);
    session->nreqbuf += 2;
    
    if (len > 0) 
    {
        memcpy((char*)(session->reqbuf + session->nreqbuf), buf, len);
        session->nreqbuf += len;
    }

#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  get_http_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session     [?]         
 *  name        [IN]        
 *  value       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT get_http_head(http_session_t *session, const VMCHAR *name, VMCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *s, *e;
    int count;
    char n[255], v[512], t[512];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!session || !name || !value)
        return -1;

    s = e = (char*)session->resbuf;
    count = 0;
    while (count < session->nresbuf) 
    {
        if (e[count++] == '\r') 
        {
            if (count > 510)
                count = 510;
            strncpy(t, s, count - 1);
            t[count - 1] = '\0';
            s = e + 1;
            e = s;
            count = 0;

            if (unpack_head(t, n, v) == 0) 
            {
                if (vm_string_equals_ignore_case(n, name) == 0) 
                {
                    strcpy(value, v);
                    return 0;
                }
            }
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  get_http_head_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT get_http_head_number(http_session_t *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = count = 0;
    
    if (!session)
        return 0;
    
    while (i < session->nresbuf) 
    {
        if (session->resbuf[i++] == '\n')
            ++count;
    }
    
    if (count > 0)
        --count;

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  get_http_head_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session     [?]         
 *  index       [IN]        
 *  name        [?]         
 *  value       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT get_http_head_by_index(http_session_t* session, int index, char* name, char* value) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char t[1024];
    int i, j, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!session || !name || !value)
        return -1;

    i = j = count = 0;
    while (i < session->nresbuf) 
    {
        if ('\r' == session->resbuf[i]) 
        {
            if (count == index) 
            {
                t[j] = '\0';
                unpack_head(t, name, value);
                return 0;
            }
            ++count; 
            ++i;
            j = 0;
        }
        else 
        {
            if (j < 1024)
                t[j++] = session->resbuf[i];
        }
        ++i;
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  unpack_host
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url         [?]     
 *  host        [?]     
 *  port        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void unpack_host(char *url, char *host, int *port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char* p;
    char t[50];
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = strstr(url, ":");
    if (NULL == p)
    {
        *port = 80;
        strcpy(host, url);
    }
    else
    {
        len = p - url;
        strcpy(t, p + 1);
        *port = atoi(t);
        strncpy(host, url, len);
        host[len] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  unpack_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [?]     
 *  name        [?]     
 *  value       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int unpack_head(char *s, char *name, char *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p;
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((p = strstr(s, ":")) == NULL)
        return -1;

    len = p - s;
    if (len > 254)
        len = 254;
    strncpy(name, s, len);
    name[len] = '\0';

    if (' ' == p[1])
        p += 2;
    len = strlen(s) - (p - s);
    if (len > 511)
        len = 511;
    strncpy(value, p, len);
    value[len] = '\0';

    return 0;
}

#endif /* __MRE_LIB_HTTP__ */

