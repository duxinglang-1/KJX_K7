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
 * w32_socket.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Socket APIs on WIN32 environment.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/* KAL - RTOS Abstraction Layer */
/* KAL - RTOS Abstraction Layer */
#include <ctype.h>
#include <stdio.h>
#include <winsock2.h>

#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"         /* local/peer struct */
#include "stack_ltlcom.h"

/* Timer Management  */
#include "stacklib.h"
#include "event_shed.h"         /* event schedulet */
#include "stack_timer.h"

/* Task Management */
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"

#include "app_buff_alloc.h"     /* buffer management API */
#include "lcd_cqueue.h"
#include "bitop_funcs.h"

#include "l3_inc_enums.h"
#include "soc_feature.h"        /* soc configurations */
#include "soc_api.h"
#include "soc2abm_struct.h"     /* interface with ABM */
#include "abm2soc_struct.h"     /* interface with ABM */
#include "soc2tcpip_struct.h"   /* interface with TCP/IP */

#include "soc_defs.h"
#include "soc_enum.h"
#include "soc_dns.h"
#include "soc_struct.h"
#include "soc_abm.h"
#include "soc_app.h"

#include "app2soc_struct.h"   /* interface with Applications */
#include "abm2soc_struct.h"
#include "abm_soc_enums.h"
#include "cbm_api.h"


#ifndef __NWK_APP_UT__

#define _W32_SOCKET_C_

/* if you want to print dbg info in console, pls turn on SOC_DBG_ENABLE */
//#define SOC_DBG_ENABLE
#define SOC_MAX_APP_NWK_NUM  50
#define SOC_SMS_ID -2
#define SOC_DNS_SOC_ID  -3

void soc_hostname_ind(kal_bool result,
                 module_type mod_id,
                 kal_int32 request_id,
                 kal_uint8 access_id,
                 kal_uint8 *ip_addr,
                 kal_uint8 addr_len,
                 kal_int8 error_cause,
                 kal_int32 detail_cause);

void soc_hostaddr_ind(kal_bool result,
                 module_type mod_id,
                 kal_int32 request_id,
                 kal_uint8 access_id,
                 kal_uint8 *name,
                 kal_int8 error_cause,
                 kal_int32 detail_cause);

kal_int8 socgethostbyname(kal_bool is_blocking,
                          module_type mod_id,
                          kal_int32 request_id,
                          const kal_char *domain_name,
                          kal_uint8 *addr,
                          kal_uint8 addr_len,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id,
                          kal_uint8 *out_entry_num);

kal_int8 socgethostbyaddr(kal_char *domain_name,
                               kal_uint32 *domain_name_len,
                               kal_uint8 *addr,
                               kal_uint8 addr_len);

void soc_start_timer(kal_uint8 timer_id,
                         kal_int8 invoke_id,
                         kal_uint8 sub_id,
                         kal_uint32 time_out);

kal_int8 sooconnect(kal_int8 s, sockaddr_struct *addr);
void soc_notify_thread(void);
static void soc_notify_app(int socketid,
                    soc_event_enum event,
                    kal_bool result,
                    kal_int8 cause);
static
int soc_find_soc_app_slot(int mod_id, 
                          int app_id,
                          int nwk_account_id, 
                          int *idx);

static
int soc_find_free_soc_app_slot(int *idx);

typedef enum
{
    W32_BEARER_CLOSED         = 0,
    W32_BEARER_OPENED         = 1,
    W32_BEARER_OPENING        = 2,
    W32_BEARER_CLOSING        = 4
} bearer_state_enum;

typedef struct
{
    int mod_id;
    int app_id;
    int nwk_account_id;
    int force_to_release;
    bearer_state_enum state;
} soc_app_nwk_state_struct;

typedef struct
{
    kal_bool is_blocking;
    module_type mod_id;
    kal_int32 request_id;
    kal_char *domain_name;
    kal_uint8 addr[16];
    kal_uint8 addr_len;
    kal_uint8 access_id;
    kal_uint32 nwk_account_id;
} soc_app_hostname_struct;

static kal_semid soc_lock;
#define SOC_LOCK          kal_take_sem(soc_lock, KAL_INFINITE_WAIT)
#define SOC_UNLOCK        kal_give_sem(soc_lock)

static fd_set read_fd, write_fd, except_fd;
static struct timeval soc_timeout_win32;

int last_socket_id = -1;
int soc_free[MAX_IP_SOCKET_NUM];    /* storing socket id */
int soc_state[MAX_IP_SOCKET_NUM];   /* state of each socket */
int soc_type[MAX_IP_SOCKET_NUM];

static int soc_modid[MAX_IP_SOCKET_NUM];   /* storing module id */
static int notify_soc_modid[MAX_IP_SOCKET_NUM];   /* storing module id to notify */
static int soc_appid[MAX_IP_SOCKET_NUM];

sockaddr_struct soc_peer_addr[MAX_IP_SOCKET_NUM];
static int soc_account_id[MAX_IP_SOCKET_NUM]; /* storing network account id */

static int soc_options[MAX_IP_SOCKET_NUM];
static int soc_events[MAX_IP_SOCKET_NUM];
static int soc_want_events[MAX_IP_SOCKET_NUM];
static soc_app_nwk_state_struct soc_app_nwk[SOC_MAX_APP_NWK_NUM];
static soc_app_hostname_struct soc_host_name[MAX_IP_SOCKET_NUM];
static int created_socket_num = 0;      /* total created sockets */
static int soc_polling_timer_running = 0;
static int csd_timer_val = 0;

typedef enum
{
    W32_SOC_S_NOUSE             = 0,
    W32_SOC_S_INUSE             = 0x0001,
    W32_SOC_S_CONNECTING        = 0x0200,   /* in process of connecting to peer */
    W32_SOC_S_CONNECTED         = 0x0400,   /* socket connected to a peer */
    W32_SOC_S_SENDING           = 0x0800,
    W32_SOC_S_RECVING           = 0x1000,
    W32_SOC_S_FINED             = 0x00200000,     /* received TCP FIN from peer */
    W32_SOC_S_DNS_RESOLVING     = 0x00400000,     /* resolving DNS address */
    W32_SOC_S_CANTRCVMORE       = 0x00800000	/* cannot receive data */
} soc_state_enum;


static unsigned char state_str[][16] = {
    "ACTIVATING",
    "ACTIVATED",
    "DEACTIVATED",
    "DEACTIVATING",
    "UNKNOWN"
};

static unsigned char event_str[][16] = {
    "1 READ",
    "2 WRITE",
    "4 ACCEPT",
    "8 CONNECT",
    "16 CLOSE",
    "UNKNOWN"
};

static unsigned char winsock_errstr[][32] = {
    "0 WSABASEERR",            /* No Error */
    "10004 WSAEINTR",          /* Interrupted system call */
    "10009 WSAEBADF",          /* Bad file number */
    "10013 WSAEACCES",         /* Permission denied */
    "10014 WSAEFAULT",         /* Bad address */
    "10022 WSAEINVAL",         /* Invalid argument */
    "10024 WSAEMFILE",         /* Too many open files */
    "10035 WSAEWOULDBLOCK",    /* Operation would block */
    "10036 WSAEINPROGRESS",    /* Operation now in progress */
    "10037 WSAEALREADY",       /* Operation already in progress */
    "10038 WSAENOTSOCK",       /* Socket operation on non-socket */
    "10039 WSAEDESTADDRREQ",   /* Destination address required */
    "10040 WSAEMSGSIZE",       /* Message too long */
    "10041 WSAEPROTOTYPE",     /* Protocol wrong type for socket */
    "10042 WSAENOPROTOOPT",    /* Bad protocol option */
    "10043 WSAEPROTONOSUPPORT",/* Protocol not supported */
    "10044 WSAESOCKTNOSUPPORT",/* Socket type not supported */
    "10045 WSAEOPNOTSUPP",     /* Operation not supported on socket */
    "10046 WSAEPFNOSUPPORT",   /* Protocol family not supported */
    "10047 WSAEAFNOSUPPORT",   /* Address family not supported by protocol family */
    "10048 WSAEADDRINUSE",     /* Address already in use */
    "10049 WSAEADDRNOTAVAIL",  /* Can't assign requested address */
    "10050 WSAENETDOWN",       /* Network is down */
    "10051 WSAENETUNREACH",    /* Network is unreachable */
    "10052 WSAENETRESET",      /* Net dropped connection or reset */
    "10053 WSAECONNABORTED",   /* Software caused connection abort */
    "10054 WSAECONNRESET",     /* Connection reset by peer */
    "10055 WSAENOBUFS",        /* No buffer space available */
    "10056 WSAEISCONN",        /* Socket is already connected */
    "10057 WSAENOTCONN",       /* Socket is not connected */
    "10058 WSAESHUTDOWN",      /* Can't send after socket shutdown */
    "10059 WSAETOOMANYREFS",   /*  Too many references, can't splice */
    "10060 WSAETIMEDOUT",      /*  Connection timed out */
    "10061 WSAECONNREFUSED",   /*  Connection refused */
    "10062 WSAELOOP",          /*  Too many levels of symbolic links */
    "10063 WSAENAMETOOLONG",   /*  File name too long */
    "10064 WSAEHOSTDOWN",      /*  Host is down */
    "10065 WSAEHOSTUNREACH",   /*  No Route to Host */
    "10066 WSAENOTEMPTY",      /*  Directory not empty */
    "10067 WSAEPROCLIM",       /*  Too many processes */
    "10068 WSAEUSERS",         /*  Too many users */
    "10069 WSAEDQUOT",         /*  Disc Quota Exceeded */
    "10070 WSAESTALE",         /*  Stale NFS file handle */
    "10091 WSASYSNOTREADY",    /*  Network SubSystem is unavailable */
    "10092 WSAVERNOTSUPPORTED",/*  WINSOCK DLL Version out of range */
    "10093 WSANOTINITIALISED", /*  Successful WSASTARTUP not yet performed */
    "10071 WSAEREMOTE",        /*  Too many levels of remote in path */
    "11001 WSAHOST_NOT_FOUND", /*  Host not found  */
    "11002 WSATRY_AGAIN",      /*  Non-Authoritative Host not found */
    "11003 WSANO_RECOVERY",    /*  Non-Recoverable errors: FORMERR, REFUSED, NOTIMP */
    "11004 WSANO_DATA",        /* Valid name, no data record of requested type */
    "11004 WSANO_ADDRESS"      /* No address, look for MX record */
};


static kal_int8 socgetlocalip(kal_uint8 *local_ip);
static unsigned char *err_str(int error);



static
void soc_dump_hex(unsigned char *buf, int len)
{
    int i, pos;

    for (pos = 0; pos < len; pos += 16)
    {
        kal_printf("%06d  ", pos);
        for (i = 0; i < 16; i++)
            if (pos + i < len)
                kal_printf("%02x%s", buf[pos+i], (i+1)%8 ? " " : "  ");
            else
                kal_printf("  %s", (i+1)%8 ? " " : "  ");

        kal_printf("  ");

        for (i = 0; i < 16 && pos+i < len; i++)
            kal_printf("%c%s", isprint(buf[pos+i]) ? buf[pos+i] : '.',
                               (i+1)%8 ? "" : " ");
        kal_printf("\n");
    }
}

kal_int8 soc_create_dns_socket(kal_bool is_blocking,
                           kal_uint8 ap_id,
                           module_type mod_id,
                           kal_int32 request_id,
                           const kal_char *domain_name,
                           kal_uint8 *addr,
                           kal_uint8 addr_len,
                           kal_uint8 access_id,
                           kal_uint32 nwk_account_id)
{
    int idx, i;
  
    /* Find the first slot with soc_free[i] equals -1(unused) */
    for (i = last_socket_id + 1; i < MAX_IP_SOCKET_NUM; i++)
    {
        if (soc_free[i] == -1)
            break;
    }
    if (i == MAX_IP_SOCKET_NUM) /* find again from 0 */
    {
        for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
            if (soc_free[i] == -1)
                break;
    }

    if (i < MAX_IP_SOCKET_NUM)
    {
        /* found free slot */
        soc_free[i] = SOC_DNS_SOC_ID;
        soc_modid[i] = mod_id;
        soc_appid[i] = ap_id;
        soc_account_id[i] = nwk_account_id;
        soc_state[i] = W32_SOC_S_INUSE;
        soc_state[i] |= W32_SOC_S_DNS_RESOLVING;
        if (soc_find_soc_app_slot(mod_id,
            (int)ap_id,
            nwk_account_id, 
            &idx) == 0)
        {
            if (soc_find_free_soc_app_slot(&idx))
            {
                soc_app_nwk[idx].mod_id = mod_id;
                soc_app_nwk[idx].app_id = ap_id;
                soc_app_nwk[idx].nwk_account_id = nwk_account_id;
                soc_app_nwk[idx].state = W32_BEARER_CLOSED;
            }
        }
        
        created_socket_num++;
        ASSERT(created_socket_num <= MAX_IP_SOCKET_NUM);
        
        /* fill in DNS info */
        soc_host_name[i].access_id = access_id;
        soc_host_name[i].is_blocking = is_blocking;
        soc_host_name[i].mod_id = mod_id;
        soc_host_name[i].request_id = request_id;
        if (domain_name)
        {
        soc_host_name[i].domain_name = malloc(strlen(domain_name) + 1);
        strcpy(soc_host_name[i].domain_name, domain_name);
        }
        
        soc_host_name[i].addr_len = addr_len;
        soc_host_name[i].nwk_account_id = nwk_account_id;
        if (addr)
        {
            memcpy(soc_host_name[i].addr, addr, 4);
        }
        else
        {
            memset(soc_host_name[i].addr, 0, 4);
        }
        
    }
    else
    {
        return SOC_LIMIT_RESOURCE;
    }
    
    return i;
}

void soc_free_dns_socket(kal_int8 soc_id)
{
    soc_free[soc_id]        = -1;
    soc_modid[soc_id]       = -1;
    soc_appid[soc_id]       = -1;
    soc_state[soc_id]       = W32_SOC_S_NOUSE;
    soc_account_id[soc_id]  = -1;
    soc_events[soc_id]      = 0;
    soc_want_events[soc_id] = 0;
    soc_options[soc_id] = 0;
    ASSERT(created_socket_num > 0);
    created_socket_num--;

    soc_host_name[soc_id].access_id = 0;
    soc_host_name[soc_id].is_blocking = 0;
    soc_host_name[soc_id].mod_id = 0;
    soc_host_name[soc_id].request_id = 0;
    if (soc_host_name[soc_id].domain_name)
    {
        free(soc_host_name[soc_id].domain_name);
        soc_host_name[soc_id].domain_name = NULL;
    }
    
    soc_host_name[soc_id].addr_len = 0;
    memset(soc_host_name[soc_id].addr, 0, sizeof(soc_host_name[soc_id].addr));
    soc_host_name[soc_id].nwk_account_id = 0;

    return;
}


static
int soc_find_soc_app_slot(int mod_id, 
                          int app_id,
                          int nwk_account_id, 
                          int *idx)
{
    int i;
    ASSERT(idx);
    for (i = 0 ; i < SOC_MAX_APP_NWK_NUM ; i++)
    {
        if (((app_id != 0 && soc_app_nwk[i].app_id == app_id) ||
             (app_id == 0 && soc_app_nwk[i].mod_id == mod_id &&
              soc_app_nwk[i].app_id == app_id)) &&
             (nwk_account_id == 0xff ||
              soc_app_nwk[i].nwk_account_id == nwk_account_id))
        {
            *idx = i;
            return 1;
        }
    }
    return 0;
}


static
int soc_find_all_soc_app_slot(int mod_id, 
                              int app_id,
                              int nwk_account_id, 
                              int *idx)
{
    int i;
    ASSERT(idx);
    for (i = 0 ; i < SOC_MAX_APP_NWK_NUM ; i++)
    {
        if (((app_id != 0 && soc_app_nwk[i].app_id == app_id) ||
             (app_id == 0 && soc_app_nwk[i].mod_id == mod_id)) &&
             (nwk_account_id == 0xff ||
              soc_app_nwk[i].nwk_account_id == nwk_account_id))
        {
            *idx = i;
            return 1;
        }
    }
    return 0;
}


static
int soc_find_free_soc_app_slot(int *idx)
{
    int found;

    ASSERT(idx);
    found = soc_find_soc_app_slot(-1,
                                  -1,
                                  -1, 
                                  idx);
    ASSERT(found == 1);

    return found;
}


static
void soc_free_soc_app_slot(int idx)
{
    ASSERT(idx >= 0 && idx < SOC_MAX_APP_NWK_NUM);

    soc_app_nwk[idx].mod_id = -1;
    soc_app_nwk[idx].app_id = -1;
    soc_app_nwk[idx].force_to_release = -1;

    soc_app_nwk[idx].nwk_account_id = -1;
    soc_app_nwk[idx].state = W32_BEARER_CLOSED;
}

static
kal_int8 soc_activate_account(int s)
{
    int id;

    if (soc_find_soc_app_slot(soc_modid[s], 
                              soc_appid[s],
                              soc_account_id[s], 
                              &id) == 0)
    {
        if (soc_find_free_soc_app_slot(&id))
        {
            soc_app_nwk[id].mod_id = soc_modid[s];
            soc_app_nwk[id].app_id = soc_appid[s];
            soc_app_nwk[id].nwk_account_id = soc_account_id[s];
            soc_app_nwk[id].state = W32_BEARER_CLOSED;
        }
    }

    if (soc_app_nwk[id].state == W32_BEARER_CLOSED ||
        soc_app_nwk[id].state == W32_BEARER_CLOSING)
    {
        soc_app_nwk[id].state = W32_BEARER_OPENING;
        soc_send_activate_req_to_abm(soc_modid[s], soc_account_id[s], 0, 0);
    }
    else if (soc_app_nwk[id].state == W32_BEARER_OPENED)
    {
        return SOC_SUCCESS;
    }

    return SOC_WOULDBLOCK;
}

void soc_deactivate_bearer(module_type mod_id,
                           kal_uint32 nw_acct_id, 
                           kal_uint8 qos_profile_id,
                           kal_bool is_deact_by_soc)
{
    int i;
    kal_uint8 ap_id;
    kal_uint8 ori_acct_id = 0;

    ori_acct_id = cbm_get_original_account(nw_acct_id);
    ap_id = cbm_get_app_id(nw_acct_id);
    
    for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
    {
        if (((ap_id != 0 && soc_appid[i] == ap_id) ||
            (ap_id == 0 && soc_modid[i] == mod_id)) &&
            soc_free[i] != -1)
        {
            break;
            
        }
    }

    if (i < MAX_IP_SOCKET_NUM)
    {
        if (!is_deact_by_soc)
        {
            for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
            {
                if ((ap_id != 0 && soc_app_nwk[i].app_id == ap_id) ||
                    (ap_id == 0 && soc_app_nwk[i].mod_id == mod_id))
                {
                    soc_app_nwk[i].force_to_release = 1;
                }
            }
        }
        return;
    }

    for (i = 0 ; i < SOC_MAX_APP_NWK_NUM ; i++)
    {
        if (((ap_id != 0 && soc_app_nwk[i].app_id == ap_id) ||
             (ap_id == 0 && soc_app_nwk[i].mod_id == mod_id)) &&
             (ori_acct_id == CBM_ALL_NWK_ACCT_ID ||
              soc_app_nwk[i].nwk_account_id == (int)nw_acct_id))
        {
            if (!is_deact_by_soc ||  soc_app_nwk[i].force_to_release > 0)
                soc_send_deactivate_req_to_abm(soc_app_nwk[i].mod_id, 
                                               (kal_uint32)soc_app_nwk[i].nwk_account_id,
                                                0,
                                                0,
                                                ABM_APP_NON_AUTO_DEACT);
            else
            {
                soc_send_deactivate_req_to_abm(soc_app_nwk[i].mod_id, 
                                               (kal_uint32)soc_app_nwk[i].nwk_account_id,
                                                0,
                                                0,
                                                0);
            }
            
            soc_app_nwk[i].state = W32_BEARER_CLOSING;
            
            return;
        }
    }

    return;
}

kal_int8 soc_app_activate_req_hdlr(module_type mod_id, 
                                   kal_uint32 account_id)
{
    int app_id;
    int idx;
    
    SOC_LOCK;
    app_id = cbm_get_app_id(account_id);
    if (soc_find_soc_app_slot(mod_id,
            (int)app_id,
            account_id, 
            &idx) == 0)
    {
        if (soc_find_free_soc_app_slot(&idx))
        {
            soc_app_nwk[idx].mod_id = mod_id;
            soc_app_nwk[idx].app_id = app_id;
            soc_app_nwk[idx].nwk_account_id = account_id;
            soc_app_nwk[idx].state = W32_BEARER_CLOSED;
        }
    }

    if (soc_app_nwk[idx].state == W32_BEARER_CLOSED ||
        soc_app_nwk[idx].state == W32_BEARER_CLOSING)
    {
        soc_app_nwk[idx].state = W32_BEARER_OPENING;
        soc_send_activate_req_to_abm(mod_id, account_id, 0, 0);
    }
   
    SOC_UNLOCK;
    return SOC_WOULDBLOCK;
}

void soc_abm_activate_cnf_hdlr(soc_abm_activate_cnf_struct *cnf)
{
    int i, id, ret;
    kal_int8 cause;
    kal_uint8 app_id = 0;
    kal_uint8 domain_name[SOC_MAX_DNS_NAME_LEN];
    kal_uint32 domain_name_len = SOC_MAX_DNS_NAME_LEN;

    SOC_LOCK;
    
    app_id = cbm_get_app_id(cnf->nw_acc_id);
    if (soc_find_soc_app_slot(cnf->mod_id, 
                              app_id,
                              cnf->nw_acc_id, 
                              &id) == 0)
    {
        SOC_UNLOCK;
        return;
    }

    if (cnf->result)
    {
        soc_app_nwk[id].state = W32_BEARER_OPENED;
        
        for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
        {                  
            if ((app_id != 0 && soc_appid[i] == app_id) ||
               (app_id == 0 && soc_modid[i] == cnf->mod_id &&
                soc_appid[i] == app_id))
            {
                if (soc_state[i] & W32_SOC_S_CONNECTING)
                {
                    soc_state[i] &= ~W32_SOC_S_CONNECTING;
                    sooconnect((kal_uint8)i, &soc_peer_addr[i]);
                }
                else if (soc_state[i] & W32_SOC_S_SENDING)
                {
                    soc_events[i] |= SOC_WRITE;
                    soc_notify_thread();
                }
                else if (soc_state[i] & W32_SOC_S_RECVING)
                {
                    soc_events[i] |= SOC_READ;
                    soc_notify_thread();
                }
                else if (soc_state[i] & W32_SOC_S_DNS_RESOLVING)
                {
                    if (IP_ALL_ZEROS(soc_host_name[i].addr))
                    {
                    ret = socgethostbyname(soc_host_name[i].is_blocking,
                           soc_host_name[i].mod_id,
                           soc_host_name[i].request_id,
                           soc_host_name[i].domain_name,
                            (kal_uint8 *)soc_host_name[i].addr,
                            soc_host_name[i].addr_len,
                           soc_host_name[i].access_id,
                            soc_host_name[i].nwk_account_id,
                            NULL);

                    if (ret == SOC_SUCCESS)
                    {
                        soc_hostname_ind(KAL_TRUE,
                            soc_host_name[i].mod_id,
                            soc_host_name[i].request_id,
                            soc_host_name[i].access_id,
                            soc_host_name[i].addr,
                            soc_host_name[i].addr_len,
                            0,
                            0);
                    }
                    else
                    {
                        
                        soc_hostname_ind(KAL_FALSE,
                            soc_host_name[i].mod_id,
                            soc_host_name[i].request_id,
                            soc_host_name[i].access_id,
                            soc_host_name[i].addr,
                            soc_host_name[i].addr_len,
                            SOC_BEARER_FAIL,
                            0);
                        soc_free_soc_app_slot(id);
                    }
                    }
                    else
                    {
                        ret = socgethostbyaddr(
                            domain_name,
                            &domain_name_len,
                            soc_host_name[i].addr,
                            soc_host_name[i].addr_len);

                        if (ret == SOC_SUCCESS)
                        {
                            soc_hostaddr_ind(KAL_TRUE,
                                soc_host_name[i].mod_id,
                                soc_host_name[i].request_id,
                                soc_host_name[i].access_id,
                                domain_name,
                                0,
                                0);
                        }
                        else
                        {
                        
                            soc_hostaddr_ind(KAL_FALSE,
                                soc_host_name[i].mod_id,
                                soc_host_name[i].request_id,
                                soc_host_name[i].access_id,
                                domain_name,
                                SOC_BEARER_FAIL,
                                0);
                            soc_free_soc_app_slot(id);
                        }
                    }
                    soc_free_dns_socket((kal_int8)i);
                }
            }
        }
    }
    else
    {
        
        for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
        {
            if ((app_id != 0 && soc_appid[i] == app_id) ||
                (app_id == 0 && soc_modid[i] == cnf->mod_id &&
                 soc_appid[i] == app_id))
            {

                    if (cnf->err_cause == ABM_E_ABORT &&
                        cnf->cause == ABM_APP_ACCT_NEED_NOTIFY)
                    {
                        cause = SOC_CANCEL_ACT_BEARER;
                    }
                    else
                    {
                        cause = SOC_BEARER_FAIL;
                    }
                    
                    if (soc_state[i] & W32_SOC_S_CONNECTING)
                    {
                        soc_notify_app(soc_free[i], SOC_CONNECT, 
                        KAL_FALSE, cause);
                    }
                    else if (soc_state[i] & W32_SOC_S_SENDING) 
                    {
                        soc_notify_app(soc_free[i], SOC_WRITE, 
                        KAL_FALSE, cause);
                    }
                    else if (soc_state[i] & W32_SOC_S_RECVING)
                    {
                        soc_notify_app(soc_free[i], SOC_READ, 
                        KAL_FALSE, cause);
                    }
                    else if (soc_state[i] & W32_SOC_S_DNS_RESOLVING)
                    {
                        if (IP_ALL_ZEROS(soc_host_name[i].addr))
                        {
                        soc_hostname_ind(KAL_FALSE,
                            soc_host_name[i].mod_id,
                            soc_host_name[i].request_id,
                            soc_host_name[i].access_id,
                            soc_host_name[i].addr,
                            soc_host_name[i].addr_len,
                            SOC_BEARER_FAIL,
                            0);
                        }
                        else
                        {
                            soc_hostaddr_ind(KAL_FALSE,
                                soc_host_name[i].mod_id,
                                soc_host_name[i].request_id,
                                soc_host_name[i].access_id,
                                domain_name,
                                SOC_BEARER_FAIL,
                                0);
                        }
                        soc_free_dns_socket((kal_int8)i);
                        soc_free_soc_app_slot(id);
                    }
                    else
                    {
                        soc_notify_app(soc_free[i], SOC_CLOSE, 
                        KAL_FALSE, cause);
                    }
                    soc_modid[i]       = -1;
                    soc_appid[i]       = -1;   
            }
        }   
        soc_free_soc_app_slot(id);
        
    }

    SOC_UNLOCK;
    return;
}

static
void soc_notify_app(int socketid,
                    soc_event_enum event,
                    kal_bool result,
                    kal_int8 cause)
{
    app_soc_notify_ind_struct *ind_ptr;
    module_type mod_id;
    kal_int8 s = -1;
    kal_uint8 i;
#ifdef SOC_DBG_ENABLE
    unsigned char *ev;
#endif

    for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
    {
        if (soc_free[i] == socketid)
        {
            s = i;
            break;
        }
    }

    if (s == -1)
        return;

    ind_ptr = (app_soc_notify_ind_struct*)
        construct_local_para(sizeof(app_soc_notify_ind_struct),
                             TD_CTRL);

    ind_ptr->socket_id   = s;
    ind_ptr->event_type  = event;
    ind_ptr->result      = result;
    ind_ptr->error_cause = cause;

    if (event == SOC_CONNECT)
    {
        soc_state[s] &= ~W32_SOC_S_CONNECTING;
        if (result == KAL_TRUE)
            soc_state[s] |= W32_SOC_S_CONNECTED;
    }

    if (event == SOC_READ)
    {
        soc_state[s] &= ~W32_SOC_S_RECVING;
    }

    if (event == SOC_WRITE)
    {
        soc_state[s] &= ~W32_SOC_S_SENDING;
    }

#ifdef SOC_DBG_ENABLE
    for (i = 0; i < sizeof(event_str) / sizeof(event_str[0]); i++)
        if (atoi(event_str[i]) == event)
        {
            ev = strchr(event_str[i], ' ') + 1;
            break;
        }
    if (i == sizeof(event_str) / sizeof(event_str[0]))
        ev = event_str[i-1];
    kal_printf("notify socket=%d event=%s\n", s, ev);
#endif /* SOC_DBG_ENABLE */

    if (notify_soc_modid[s] != -1)
        mod_id = notify_soc_modid[s];
    else
        mod_id = soc_modid[s];

#ifdef SOC_DBG_ENABLE
    kal_printf("notify socket %d ", soc_state[s]);
    switch(event)
    {
    case SOC_READ:
        kal_printf("SOC_READ");
        break;

    case SOC_WRITE:
        kal_printf("SOC_WRITE");
        break;

    case SOC_CONNECT:
        kal_printf("SOC_CONNECT");
        break;

    case SOC_CLOSE:
        kal_printf("SOC_CLOSE");
        break;

    case SOC_ACCEPT:
        kal_printf("SOC_ACCEPT");
        break;
    }
    kal_printf(" to module %d(%s)\n", mod_id, mod_id == MOD_TFTP ? "TFTP" :
                                              mod_id == MOD_TLS ? "TLS" : "?");
#endif /* SOC_DBG_ENABLE */

    soc_send_msg_to_app(mod_id,
                        MSG_ID_APP_SOC_NOTIFY_IND,
                        (local_para_struct*)ind_ptr,
                        NULL);
}


/*
 * s:           MoDIS socket layer socket id
 * socket_id:   Winsock layer socket id
 */
static
int soc_reselect(kal_uint8 s, int socket_id, int wantEventType, int *eventType)
{
    int rt;
    int ret = 0;  //reset
    int i = 0;
    int max_fd = 0;

    FD_ZERO(&read_fd);
    FD_ZERO(&write_fd);
    FD_ZERO(&except_fd);

    if ((wantEventType & SOC_READ) && (*eventType & SOC_READ))
        FD_SET((SOCKET)socket_id, &read_fd);

    if ((wantEventType & SOC_ACCEPT) && (*eventType & SOC_ACCEPT))
        FD_SET((SOCKET)socket_id, &read_fd);

    if ((wantEventType & SOC_CONNECT) && (*eventType & SOC_CONNECT))
        FD_SET((SOCKET)socket_id, &write_fd);

    if ((wantEventType & SOC_WRITE) && (*eventType & SOC_WRITE))
        FD_SET((SOCKET)socket_id, &write_fd);

    if ((wantEventType & SOC_CLOSE) && (*eventType & SOC_CLOSE))
        FD_SET((SOCKET)socket_id, &read_fd);


    for (i = 0; i < sizeof(read_fd.fd_array) / sizeof(read_fd.fd_array[0]); i++)
        max_fd = max_fd < (int)read_fd.fd_array[i] ? read_fd.fd_array[i] : max_fd;
    
    for (i = 0; i < sizeof(write_fd.fd_array) / sizeof(write_fd.fd_array[0]); i++)
        max_fd = max_fd < (int)write_fd.fd_array[i] ? write_fd.fd_array[i] : max_fd;
    
    for (i = 0; i < sizeof(except_fd.fd_array) / sizeof(except_fd.fd_array[0]); i++)
        max_fd = max_fd < (int)except_fd.fd_array[i] ? except_fd.fd_array[i] : max_fd;
        
    max_fd += 1;

    if (max_fd > 1)
        rt = select(max_fd, &read_fd, &write_fd, &except_fd, &soc_timeout_win32);
    else
        return 0;

    if (rt == SOCKET_ERROR) /* error */
    {
    #ifdef SOC_DBG_ENABLE
        int error = WSAGetLastError();
        kal_printf("select error: %s (%d)\n", err_str(error), error);
    #endif /* SOC_DBG_ENABLE */
    }
    else if (0 < rt)    /* success, rt = the number of descriptors */
    {
        if (FD_ISSET(socket_id, &read_fd))
        {
            int sockopt_ret = 0;
            int sotype = 0;
            int sotype_len = sizeof(sotype);
            int data_rcvd = 1;  /* init to 1 as there is data for receive */
            kal_int8 buf[1];
            
            sockopt_ret = getsockopt(socket_id, SOL_SOCKET, SO_TYPE, (char*)&sotype, &sotype_len);
            if (sotype == SOCK_STREAM)
                data_rcvd = recv(socket_id, buf, sizeof(buf), MSG_PEEK);
            
            if ((*eventType & SOC_READ) && data_rcvd == 1)
            {
                soc_notify_app(socket_id, SOC_READ, KAL_TRUE, 0);
                *eventType &= ~SOC_READ;
                ret++;
            }
            else if (*eventType & SOC_ACCEPT)
            {
                soc_notify_app(socket_id, SOC_ACCEPT, KAL_TRUE, 0);
                *eventType &= ~SOC_ACCEPT;
                ret++;
            }
            else if (*eventType & SOC_CLOSE && data_rcvd == 0) /* data_rcvd == 0 */
            {
            #ifdef SOC_DBG_ENABLE
                kal_printf("socket %d closed by peer\n", s);
            #endif /* SOC_DBG_ENABLE */

                if (!(soc_state[s] & W32_SOC_S_FINED))  /* notify once */
                {
                    soc_state[s] |= W32_SOC_S_FINED;
                    soc_notify_app(socket_id, SOC_CLOSE, KAL_FALSE, SOC_CONNRESET);
                }
                *eventType &= ~SOC_CLOSE;
                ret++;
            }
        }

        if (FD_ISSET(socket_id, &write_fd))
        {
            if (*eventType & SOC_CONNECT)
            {
                soc_notify_app(socket_id, SOC_CONNECT, KAL_TRUE, 0);
                *eventType &= ~SOC_CONNECT;
                ret++;
            }
            else if (*eventType & SOC_WRITE)
            {
                soc_notify_app(socket_id, SOC_WRITE, KAL_TRUE, 0);
                *eventType &= ~SOC_WRITE;
                ret++;
            }
        }

        if (FD_ISSET(socket_id, &except_fd))
        {
            if (*eventType & SOC_CONNECT)
            {
                soc_notify_app(socket_id, SOC_CONNECT, KAL_FALSE, 0);
                *eventType &= ~SOC_CONNECT;
                ret++;
            }
        }
    }

    return ret;
}


void soc_notify_thread(void)
{
    kal_uint8 i;

    int batch   = 0;
    int wait_wb = 0;

    if (created_socket_num <= 0 || soc_polling_timer_running == 1)
        return;

    for (i = 0 ; i < MAX_IP_SOCKET_NUM ; i++)
    {
        if (soc_free[i] >= 0 && soc_want_events[i] && soc_events[i] > 0)
        {
            batch += soc_reselect(i,
                                  soc_free[i],
                                  soc_want_events[i],
                                  &soc_events[i]);

            if (batch == 10)
            {
                /* do not send too many IND to application at the same time,
                 * otherwise, application's queue may be full */
                kal_sleep_task(KAL_TICKS_100_MSEC);
                batch = 0;
            }
            wait_wb++;
        }
    }

    /* start a polling timer */
    if (wait_wb > 0)
    {
        soc_start_timer(0 /* dummy timer_id */,
                        0 /* dummy invoke_id */,
                        0 /* dummy sub_id */,
                        KAL_TICKS_100_MSEC * 2);
        soc_polling_timer_running = 1;
    }
}

/*
 * Called by soc_expiry_hanlder() at the condition of
 * !defined(__MTK_TARGET__) || defined(WIN_SOC)
 */
void soc_polling_timer_expiry(void)
{
    SOC_LOCK;

    ASSERT(soc_polling_timer_running == 1);
    soc_polling_timer_running = 0;
    soc_notify_thread();

    SOC_UNLOCK;
}


void soc_init_win32(void)
{
    int i;
    WSADATA info;

    soc_lock = kal_create_sem("soc lock", 1);

    for (i = 0 ; i < MAX_IP_SOCKET_NUM ; i++)
    {
        soc_free[i]        = -1;
        soc_modid[i]       = -1;
        notify_soc_modid[i] = -1;
        soc_appid[i]       = -1;
  
        soc_account_id[i]  = -1;
        soc_events[i]      = 0;
        soc_type[i] = 0;
        soc_want_events[i] = 0;
        soc_options[i] = 0;
        
        soc_host_name[i].access_id = 0;
        soc_host_name[i].is_blocking = 0;
        soc_host_name[i].mod_id = 0;
        soc_host_name[i].request_id = 0;
        soc_host_name[i].domain_name = NULL;
    
        soc_host_name[i].addr_len = 0;
        memset(soc_host_name[i].addr, 0, sizeof(soc_host_name[i].addr));
        soc_host_name[i].nwk_account_id = 0;
    }

    for (i = 0 ; i < SOC_MAX_APP_NWK_NUM ; i++)
    {
        soc_app_nwk[i].mod_id         = -1;
        soc_app_nwk[i].app_id         = -1;
        soc_app_nwk[i].force_to_release = -1;
    
        soc_app_nwk[i].nwk_account_id = -1;
        soc_app_nwk[i].state          = W32_BEARER_CLOSED;
    }

    if (WSAStartup(MAKEWORD(1,1), &info) != 0)
    {
        MessageBox(NULL, "Cannot initialize WinSock!", "WSAStartup", MB_OK);
    }
    else /* initiate WinSock successfully, start periodic timer */
    {
        soc_timeout_win32.tv_sec = 0;
        soc_timeout_win32.tv_usec = 50; /* wait for 50 usec */

        #ifdef SOC_DBG_ENABLE
        kal_printf("socket simulation activated\n");
        #endif		
    }
}

void soc_hostname_ind(kal_bool result,
                 module_type mod_id,
                 kal_int32 request_id,
                 kal_uint8 access_id,
                 kal_uint8 *ip_addr,
                 kal_uint8 addr_len,
                 kal_int8 error_cause,
                 kal_int32 detail_cause)
{
    app_soc_get_host_by_name_ind_struct *ind_ptr;
  
    ind_ptr = (app_soc_get_host_by_name_ind_struct*)
               construct_local_para(sizeof(app_soc_get_host_by_name_ind_struct),
               TD_CTRL | TD_RESET);
    ind_ptr->result = result;

    if (result == KAL_TRUE)
    {
        ind_ptr->num_entry = addr_len/4;
        if (ind_ptr->num_entry > SOC_MAX_A_ENTRY)
        {
            ind_ptr->num_entry = SOC_MAX_A_ENTRY;
            addr_len = SOC_MAX_A_ENTRY * 4;
        }
        kal_mem_cpy(ind_ptr->entry, ip_addr, addr_len);
    }
    else    /* fail */
    {
        ind_ptr->num_entry = 0;
        kal_mem_set(ind_ptr->entry, 0, sizeof(ind_ptr->entry));
    }
    
    kal_mem_cpy(ind_ptr->addr, ip_addr, addr_len);
    ind_ptr->addr_len = addr_len;

    ind_ptr->request_id = request_id;
    ind_ptr->access_id = access_id;
    ind_ptr->error_cause = error_cause;
    ind_ptr->detail_cause = detail_cause;

    soc_send_msg_to_app(mod_id,
                        MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND,
                        (local_para_struct*)ind_ptr,
                        NULL);
 
}

void soc_hostaddr_ind(kal_bool result,
                 module_type mod_id,
                 kal_int32 request_id,
                 kal_uint8 access_id,
                 kal_uint8 *name,
                 kal_int8 error_cause,
                 kal_int32 detail_cause)
{
    app_soc_get_host_by_addr_ind_struct *ind_ptr;
  
    ind_ptr = (app_soc_get_host_by_addr_ind_struct*)
               construct_local_para(sizeof(app_soc_get_host_by_addr_ind_struct),
               TD_CTRL | TD_RESET);
    ind_ptr->result = result;

    if (result == KAL_TRUE)
    {
        strcpy(ind_ptr->name, name);
        ind_ptr->num_entry = 1;
        strcpy((kal_uint8 *)ind_ptr->entry, name);
    }
    else    /* fail */
    {
        strcpy(ind_ptr->name, "");
        ind_ptr->num_entry = 0;
        kal_mem_set(ind_ptr->entry, 0, sizeof(ind_ptr->entry));
    }
    
    ind_ptr->request_id = request_id;
    ind_ptr->access_id = access_id;
    ind_ptr->error_cause = error_cause;
    ind_ptr->detail_cause = detail_cause;

    soc_send_msg_to_app(mod_id,
                        MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND,
                        (local_para_struct*)ind_ptr,
                        NULL);
 
}

void soc_convert_addr(struct sockaddr_in *win32_addr,
                      sockaddr_struct *addr)
{
    addr->port = ntohs(win32_addr->sin_port);
    addr->addr_len = 4;

    memset(addr->addr, 0, sizeof(addr->addr));
    memcpy(addr->addr, &win32_addr->sin_addr, 4);
}


kal_int8 soc_create(kal_uint8  domain,
                    socket_type_enum  type,
                    kal_uint8  protocol,
                    module_type mod_id,
                    kal_uint32 nwk_account_id)
{

    int ap_id;
    kal_bool always_ask = KAL_FALSE;
    int idx;
    int i;
    
    /* with initial values */
    kal_int8 s = SOC_ERROR;
    kal_int8 error = SOC_SUCCESS;
    SOCKET id = INVALID_SOCKET;

    SOC_LOCK;
    
    ap_id = cbm_get_app_id(nwk_account_id);
    
    switch (type)
    {
    case SOC_SOCK_DGRAM:
        id = socket(AF_INET, SOCK_DGRAM, 0);
        break;

    case SOC_SOCK_STREAM:
        id = socket(AF_INET, SOCK_STREAM, 0);
        break;

    case SOC_SOCK_SMS:
        id = SOC_SMS_ID;
        break;

    default:
        id = socket(AF_INET, SOCK_STREAM, 0);
        break;
    }

    if (id == INVALID_SOCKET)
    {
    #ifdef SOC_DBG_ENABLE
        int err = WSAGetLastError();
        kal_printf("socket create error: %s (%d)\n", err_str(err), err);
    #endif /* SOC_DBG_ENABLE */
        SOC_UNLOCK;
        return -1;
    }

    /* Find the first slot with soc_free[i] equals -1(unused) */
    for (i = last_socket_id + 1; i < MAX_IP_SOCKET_NUM; i++)
    {
        if (soc_free[i] == -1)
            break;
    }
    if (i == MAX_IP_SOCKET_NUM) /* find again from 0 */
    {
        for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
            if (soc_free[i] == -1)
                break;
    }

    if (i < MAX_IP_SOCKET_NUM)
    {
        /* found free slot */
       

        soc_free[i] = id;
        soc_modid[i] = mod_id;
        soc_appid[i] = ap_id;
        soc_account_id[i] = nwk_account_id;
        soc_type[i] = type;
        soc_state[i] = W32_SOC_S_INUSE;
        soc_events[i] |= SOC_READ;
        soc_events[i] |= SOC_CLOSE;

        if (soc_find_soc_app_slot(mod_id,
            (int)ap_id,
            nwk_account_id, 
            &idx) == 0)
        {
            if (soc_find_free_soc_app_slot(&idx))
            {
                soc_app_nwk[idx].mod_id = mod_id;
                soc_app_nwk[idx].app_id = ap_id;
                soc_app_nwk[idx].nwk_account_id = nwk_account_id;
                soc_app_nwk[idx].state = W32_BEARER_CLOSED;
            }
        }
        
        created_socket_num++;
    }
    else
    {
        /* All MAX_IP_SOCKET_NUM socket slots are occupied */
        i = SOC_LIMIT_RESOURCE;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("return socket id = %d, (win32 socket id = %d)\n", i, id);
#endif /* SOC_DBG_ENABLE */

    last_socket_id = i;
    SOC_UNLOCK;

    return i;
}


kal_int8 soc_close(kal_int8 s)
{
    int account_id;
    module_type mod_id;

    if (s < 0 || MAX_IP_SOCKET_NUM <= s)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] < 0 && soc_free[s] != SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_free[s] != SOC_SMS_ID)
        closesocket(soc_free[s]);
      
    notify_soc_modid[s]  = -1;
    soc_free[s] = -1;
    soc_state[s] = W32_SOC_S_NOUSE;
    soc_type[s] = 0;

    ASSERT(created_socket_num > 0);

    created_socket_num--;
    account_id = soc_account_id[s];
    mod_id = soc_modid[s];

    soc_deactivate_bearer(mod_id, account_id, 0, KAL_TRUE);
    
    SOC_UNLOCK;
    return SOC_SUCCESS;
}


kal_int8 soc_bind(kal_int8 s, sockaddr_struct *addr)
{
    struct sockaddr_in A;
    int socketid;
    char buf[128];
    int last_error;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return 0;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (addr->addr_len == 0)
    {
        memset(addr->addr, 0, MAX_SOCK_ADDR_LEN);
    }

    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf,"%d.%d.%d.%d",
            addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf);

#ifdef SOC_DBG_ENABLE
    kal_printf("Socket %d bind %s:%d\n", s, buf, addr->port);
#endif /* SOC_DBG_ENABLE */

    if (bind(socketid, (const struct sockaddr*)&A, sizeof(A)) == SOCKET_ERROR)
    {
        last_error = WSAGetLastError();
        SOC_UNLOCK;
        if (last_error == WSAEADDRINUSE)
            return SOC_ADDRINUSE;
        else
            return -1;
    }

    SOC_UNLOCK;

    return SOC_SUCCESS;
}


kal_int8 soc_listen(kal_int8 s, kal_uint8 backlog)
{
    int socketid;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid < 0)
    {
        SOC_UNLOCK;
       
        if(socketid == SOC_SMS_ID)
            return SOC_OPNOTSUPP;
        else
            return SOC_INVALID_SOCKET;
    }
    
    if (listen(socketid, backlog))
    {
        SOC_UNLOCK;
        return -1;
    }

    soc_events[s] |= SOC_ACCEPT;

    if ((soc_free[s] != SOC_SMS_ID) && 
        ((soc_options[s] & SOC_SILENT_LISTEN) != SOC_SILENT_LISTEN))
    {
        soc_activate_account(s);
        
    }
  
    SOC_UNLOCK;
    return 0;
}


kal_int8 soc_accept(kal_int8 s, sockaddr_struct *addr)
{
    int socketid, i;
    SOCKET newid;

    struct sockaddr_in their_addr; /* connector's address information */
    int addr_len;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    addr_len = sizeof(struct sockaddr);

    newid = accept(socketid, (struct sockaddr *)&their_addr, &addr_len);
    if (newid == INVALID_SOCKET)
    {
        int last_error = WSAGetLastError();

        soc_events[s] |= SOC_ACCEPT;

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("accept(%d) error: %s (%d)\n",
                       s, err_str(last_error), last_error);
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return -1;
        }

        soc_notify_thread();

        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }

    soc_events[s] |= SOC_ACCEPT;

    soc_convert_addr(&their_addr, addr);


    for (i = last_socket_id + 1; i < MAX_IP_SOCKET_NUM; i++)
    {
        if (soc_free[i] == -1)
            break;
    }
    if (i == MAX_IP_SOCKET_NUM) /* find again from 0 */
    {
        for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
            if (soc_free[i] == -1)
                break;
    }

    if (i < MAX_IP_SOCKET_NUM)
    {
        soc_free[i] = newid;
        
        soc_state[i] = W32_SOC_S_INUSE;
        soc_events[i] |= SOC_READ;
        soc_events[i] |= SOC_CLOSE;

        soc_modid[i] = soc_modid[s];
        soc_appid[i] = soc_appid[s];
        soc_account_id[i] = soc_account_id[s];
    
        created_socket_num++;
    }
    else
    {
        closesocket(newid);
        SOC_UNLOCK;
        return SOC_LIMIT_RESOURCE;
    }

    last_socket_id = i;
    SOC_UNLOCK;
    return (kal_int8)i;
}


kal_int8 sooconnect(kal_int8 s, sockaddr_struct *addr)
{
    char buf[128];
    struct sockaddr_in A;
    int socketid;
    kal_int8 ret;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    if (soc_state[s] & (W32_SOC_S_CONNECTING | W32_SOC_S_CONNECTED))
        return SOC_ALREADY;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        return SOC_OPNOTSUPP;
    }

    if (socketid < 0)
    {
        return SOC_INVALID_SOCKET;
    }

    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf,"%d.%d.%d.%d",
            addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf);

#ifdef SOC_DBG_ENABLE
    kal_printf("Socket %d connect to %s:%d\n", s, buf, addr->port);
#endif /* SOC_DBG_ENABLE */   

    
    soc_state[s] |= W32_SOC_S_CONNECTING;
    memcpy(&soc_peer_addr[s], addr, sizeof(sockaddr_struct));

    if ((soc_free[s] != SOC_SMS_ID) && 
        ((soc_options[s] & SOC_SILENT_LISTEN) != SOC_SILENT_LISTEN) &&
        soc_type[s] != SOC_SOCK_DGRAM)
    {
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            return SOC_WOULDBLOCK;
        }
    }
    if (connect(socketid, (const struct sockaddr*)&A, sizeof(A)) == SOCKET_ERROR)
    {
        int last_error = WSAGetLastError();

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("connect(%d) error: %s (%d)\n",
                       s, err_str(last_error), last_error);
        #endif /* SOC_DBG_ENABLE */
            soc_state[s] &= ~W32_SOC_S_CONNECTING;
            return -1;
        }

        soc_events[s] |= SOC_CONNECT;

        soc_notify_thread();
        
        return SOC_WOULDBLOCK;
    }

    soc_state[s] &= ~W32_SOC_S_CONNECTING;
    soc_state[s] |= W32_SOC_S_CONNECTED;

    return 0;
}


kal_int8 soc_connect(kal_int8 s, sockaddr_struct *addr)
{
    kal_int8 ret;
    
    SOC_LOCK;

    ret = sooconnect(s, addr);
        
    SOC_UNLOCK;

    return ret;
}


kal_int8 soc_shutdown(kal_int8 s, kal_uint8 how)
{
    int sd;
	kal_int8 ret;

    if (s < 0 || MAX_IP_SOCKET_NUM <= s)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return 0;
    }

    if (soc_free[s] < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

	switch (how)
	{
    case SHUT_RD:
		sd = SD_RECEIVE;
                soc_state[s] |= W32_SOC_S_CANTRCVMORE;
		break;

	case SHUT_WR:
		sd = SD_SEND;
		break;

	case SHUT_RDWR:
		sd = SD_BOTH;
		break;

	default:
		return SOC_INVAL;
	}

    if (shutdown(soc_free[s], sd)) /* error */
        ret = SOC_ERROR;
    else
        ret = SOC_SUCCESS;
    SOC_UNLOCK;

    return ret;
}


kal_int32 soc_sendto(kal_int8 s,
                     void *buf,
                     kal_int32 len,
                     kal_uint8 flags,
                     sockaddr_struct *addr)
{
    int send_size;
    int socketid;
    struct sockaddr_in A;
    char buf_tmp[128];
    kal_int8 ret;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_OPNOTSUPP;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }
    
    soc_state[s] |= W32_SOC_S_SENDING;
    
     if ((soc_free[s] != SOC_SMS_ID) && 
        ((soc_options[s] & SOC_SILENT_LISTEN) != SOC_SILENT_LISTEN))
    {
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }
        
    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf_tmp, "%d.%d.%d.%d",
            addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf_tmp);

    send_size = sendto(socketid, (void*)buf, len, 0,
                       (const struct sockaddr*)&A, sizeof(A));
    if (send_size < 0)
    {
        int last_error = WSAGetLastError();

        if (last_error == WSAEWOULDBLOCK)
        {
            soc_events[s] |= SOC_WRITE;
            soc_notify_thread();
        #ifdef SOC_DBG_ENABLE
            kal_printf("sendto(%d) wouldblock, event: %x\n", s, soc_events[s]);
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;        
        }

    #ifdef SOC_DBG_ENABLE
        kal_printf("send error %d\n", last_error);
    #endif /* SOC_DBG_ENABLE */

        soc_state[s] &= ~W32_SOC_S_SENDING;
        SOC_UNLOCK;
        return -1;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("Send to: %d.%d.%d.%d port=%d %d bytes\n", 
               addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3],
               addr->port, send_size);
    soc_dump_hex(buf, send_size);
#endif /* SOC_DBG_ENABLE */

    soc_state[s] &= ~W32_SOC_S_SENDING;
    SOC_UNLOCK;

    return send_size;
}

kal_int32 soc_sendmsg(kal_int8      s,
                    soc_msghdr_struct *buf,
                    kal_uint32       flags)
{
    return SOC_ERROR;
}

kal_int32 soc_send(kal_int8 s,
                   void *buf,
                   kal_int32 len,
                   kal_uint8 flags)
{
    int send_size;
    int socketid;
    kal_int8 ret;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_OPNOTSUPP;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    soc_state[s] |= W32_SOC_S_SENDING;

     if ((soc_free[s] != SOC_SMS_ID) && 
        ((soc_options[s] & SOC_SILENT_LISTEN) != SOC_SILENT_LISTEN))
    {
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }

    send_size = send(socketid, (void*)buf, len, 0);
    if (send_size <0)
    {
        int last_error = WSAGetLastError();

        if (last_error == WSAEWOULDBLOCK)
        {
            soc_events[s] |= SOC_WRITE;
            soc_notify_thread();
        #ifdef SOC_DBG_ENABLE
            kal_printf("send(%d) wouldblock, event: %x\n", s, soc_events[s]);
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;        
        }

    #ifdef SOC_DBG_ENABLE
        kal_printf("send error %d\n", last_error);
    #endif /* SOC_DBG_ENABLE */

        soc_state[s] &= ~W32_SOC_S_SENDING;
        SOC_UNLOCK;
        return -1;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("Send: %d bytes\n", send_size);
    soc_dump_hex(buf, send_size);
#endif /* SOC_DBG_ENABLE */

    soc_state[s] &= ~W32_SOC_S_SENDING;
    SOC_UNLOCK;

    return send_size;
}


kal_int32 soc_recvfrom(kal_int8 s,
                       void *buf,
                       kal_int32 len,
                       kal_uint8 flags,
                       sockaddr_struct *fromaddr)
{
    int recv_size;
    int socketid;
    struct sockaddr_in their_addr; /* connector's address information */
    int addr_len;
    int error;
    int opt_val;
    int opt_len = sizeof(int);
    int flag = 0;
    kal_int8 ret;
    kal_uint8 peek_buf[1];

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_state[s] & W32_SOC_S_CANTRCVMORE)
    {
        /* receive side of the connection is closed */
        SOC_UNLOCK;
        return 0;
    }

     if (getsockopt(socketid, 
           SOL_SOCKET, 
           SO_TYPE, 
           (char*)&opt_val, 
           &opt_len) == SOCKET_ERROR)        
    {
        SOC_UNLOCK;
        return SOC_ERROR;
           
    }

    
    soc_state[s] |= W32_SOC_S_RECVING;

     if ((soc_free[s] != SOC_SMS_ID) && 
        ((soc_options[s] & SOC_SILENT_LISTEN) != SOC_SILENT_LISTEN))
    {
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }
    
    addr_len = sizeof(struct sockaddr);

    flag |= flags & SOC_MSG_PEEK ? MSG_PEEK : 0;
    recv_size = recvfrom(socketid, (void*)buf, len, flag,
                         (struct sockaddr *)&their_addr, &addr_len);
    if (recv_size < 0)
    {
        error = WSAGetLastError();
        switch (error)
        {
        case WSAEWOULDBLOCK:
            soc_events[s] |= SOC_READ;
            soc_notify_thread();
        #ifdef SOC_DBG_ENABLE
            kal_printf("recvfrom(%d) wouldblock, evnent %x\n", s, soc_events[s]);
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;

        case WSAEMSGSIZE:
            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_MSGSIZE;

        case WSAECONNABORTED:
        #ifdef SOC_DBG_ENABLE
            kal_printf("WSAECONNABORTED\r\n");
        #endif /* SOC_DBG_ENABLE */
            /* fall through */

        default:
        #ifdef SOC_DBG_ENABLE
            kal_printf("recvfrom(%d) returns error %d\n", s, recv_size);
            kal_printf("recvfrom(%d) error %s (%d)\n", s, err_str(error), error);
        #endif /* SOC_DBG_ENABLE */

            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_ERROR;
        }
    }
    else if (recv_size == 0)
    {
        /* found if there is available function to obtain the socket type (TCP or UDP)*/
        /* Only TCP need the len == 0 */
        if(opt_val == SOCK_STREAM)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("socket %d closed by peer\n", s);
        #endif /* SOC_DBG_ENABLE */
            if (!(soc_state[s] & W32_SOC_S_FINED))  /* notify once */
            {
                soc_state[s] |= W32_SOC_S_FINED;
                soc_notify_app(socketid, SOC_CLOSE, KAL_FALSE, SOC_CONNRESET);
            }
        }
       
        soc_state[s] &= ~W32_SOC_S_RECVING;

        /*  Windows recvfrom API didn't return address for TCP. Find another API to get the address*/
        if(fromaddr)
        {
            memset(fromaddr, 0, sizeof(sockaddr_struct));
            if(opt_val == SOCK_STREAM)
            {
                addr_len = sizeof(struct sockaddr);
                error = getpeername(socketid,(struct sockaddr *)&their_addr, &addr_len);
                if(error < 0)
                {
                    SOC_UNLOCK;
                    return SOC_ERROR;
                }

                fromaddr->sock_type = SOC_SOCK_STREAM;      
            }
            else
            {
                fromaddr->sock_type = SOC_SOCK_DGRAM;
            }
        
            soc_convert_addr(&their_addr, fromaddr);
        }

        SOC_UNLOCK;
        return 0;
    }

    /* For UDP sockets, recvfrom() returns 0 indicating that
     * the received datagram contains data of length 0.
     */
#ifdef SOC_DBG_ENABLE
    kal_printf("Recv: %d bytes\n", recv_size);
    soc_dump_hex(buf, recv_size);
#endif /* SOC_DBG_ENABLE */

    /*  Windows recvfrom API didn't return address for TCP. Find another API to get the address*/
   if(fromaddr)
    {
        memset(fromaddr, 0, sizeof(sockaddr_struct));
        if(opt_val == SOCK_STREAM)
        {
            addr_len = sizeof(struct sockaddr);
            error = getpeername(socketid,(struct sockaddr *)&their_addr, &addr_len);
            if(error < 0)
            {
                SOC_UNLOCK;
                return SOC_ERROR;
            }

            fromaddr->sock_type = SOC_SOCK_STREAM;      
        }
        else
        {
            fromaddr->sock_type = SOC_SOCK_DGRAM;
        }
        
        soc_convert_addr(&their_addr, fromaddr);
        
    }

    if (recvfrom(socketid, peek_buf, sizeof(peek_buf), MSG_PEEK, NULL, 0) == 1)
        soc_events[s] &= ~SOC_READ;
	else
    soc_events[s] |= SOC_READ;

    soc_state[s] &= ~W32_SOC_S_RECVING;
    SOC_UNLOCK;

    return recv_size;
}

kal_int32 soc_recvmsg(kal_int8 s, soc_msghdr_struct *buf, kal_uint32 flags)
{
   // not support in modis
    return SOC_ERROR;
}

kal_int32 soc_recv(kal_int8 s,
                   void *buf,
                   kal_int32 len,
                   kal_uint8 flags)
{
    int recv_size;
    int socketid;
    int error;
    kal_int8 ret;
    kal_uint8 peek_buf[1];
    int flag = 0;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_state[s] & W32_SOC_S_CANTRCVMORE)
    {
        /* receive side of the connection is closed */
        SOC_UNLOCK;
        return 0;
    }

    soc_state[s] |= W32_SOC_S_RECVING;

    if ((soc_free[s] != SOC_SMS_ID) && 
        ((soc_options[s] & SOC_SILENT_LISTEN) != SOC_SILENT_LISTEN))
    {
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }
    
    flag |= flags & SOC_MSG_PEEK ? MSG_PEEK : 0;
    recv_size = recv(socketid, (void*)buf, len, flag);
    
    if (recv_size < 0)
    {
        error = WSAGetLastError();
        switch (error)
        {
        case WSAEWOULDBLOCK:
            soc_events[s] |= SOC_READ;
            soc_notify_thread();
        #ifdef SOC_DBG_ENABLE
            kal_printf("recv(%d) wouldblock\n", s);
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;

        case WSAEMSGSIZE:
            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_MSGSIZE;

        case WSAECONNABORTED:
        #ifdef SOC_DBG_ENABLE
            kal_printf("WSAECONNABORTED\r\n");
        #endif /* SOC_DBG_ENABLE */
            /* fall through */

        default:
        #ifdef SOC_DBG_ENABLE
            kal_printf("recv(%d) returns error %d\n", s, recv_size);
            kal_printf("recv(%d) error %s (%d)\n", s, err_str(error), error);
        #endif /* SOC_DBG_ENABLE */
            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_ERROR;
        }
    }
    else if (recv_size == 0)
    {
    #ifdef SOC_DBG_ENABLE
        kal_printf("socket %d closed by peer\n", s);
    #endif /* SOC_DBG_ENABLE */
        if (!(soc_state[s] & W32_SOC_S_FINED))  /* notify once */
        {
            soc_state[s] |= W32_SOC_S_FINED;
            soc_notify_app(socketid, SOC_CLOSE, KAL_FALSE, SOC_CONNRESET);
        }

        soc_state[s] &= ~W32_SOC_S_RECVING;
        SOC_UNLOCK;
        return 0;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("Recv: %d bytes\n", recv_size);
    soc_dump_hex(buf, recv_size);
#endif /* SOC_DBG_ENABLE */

    if (soc_options[s] & SOC_NBIO)
    {
        if (recv(socketid, peek_buf, sizeof(peek_buf), MSG_PEEK) == 1)
            soc_events[s] &= ~SOC_READ;
        else
            soc_events[s] |= SOC_READ;
    }

    soc_state[s] &= ~W32_SOC_S_RECVING;
    SOC_UNLOCK;
    return recv_size;
}


kal_int8 soc_select(kal_uint8 ndesc,
                    soc_fd_set *in,
                    soc_fd_set *out,
                    soc_fd_set *ex,
                    soc_timeval_struct *tv)
{
    int rt;
    int max_ndesc = -1;
    int i;
    int s;
    soc_fd_set *fd[3];
    fd_set win_fd[3];

    struct timeval to_val, *to_val_ptr = NULL;

    SOC_LOCK;

    FD_ZERO(&win_fd[0]);
    FD_ZERO(&win_fd[1]);
    FD_ZERO(&win_fd[2]);
    
    fd[0] = in;
    fd[1] = out;
    fd[2] = ex;

    #define FD_WANT(sock, fdset)    ((fdset)->fds_bits[sock] & 0x01)
    for (s = 0; s < MAX_IP_SOCKET_NUM; s++)
    {
        for (i = 0; i < 3; i++)
        {
            if (fd[i] && FD_WANT(s, fd[i]))   /* SOC_FD_SET */
            {
                FD_SET(soc_free[s], &win_fd[i]);
            }
        }
    }
    #undef FD_WANT

    if (tv)
    {
        to_val.tv_sec = tv->tv_sec;
        to_val.tv_usec = tv->tv_usec;
        to_val_ptr = &to_val;
    }

    /* ndesc is the largest socket id in the SET plus one,
     *               i =   0,  1,  2,  3,  4,  5,  6
     * say, soc_free[] = {34, 27, -1, 14, 21, -1, -1};
     * the app wants to select the socket 1, 3, and 4, it will call
     * FD_SET(1, &readfds);
     * FD_SET(3, &readfds);
     * FD_SET(4, &readfds);
     * select(4+1, &readfds, NULL, NULL, &tv);
     *
     * To this adaptation layer, we have to
     * 1. translate FD_SET(1, &readfds); to
     *              FD_SET(soc_free[1], &readfds);
     *    translate FD_SET(3, &readfds); to
     *              FD_SET(soc_free[3], &readfds);
     *    translate FD_SET(4, &readfds); to
     *              FD_SET(soc_free[4], &readfds);
     * 2. try to get the real ndesc, which is given as (4+1) = 5.
     *    loop over the soc_free[], from 0 to (5-1) to find the max socket id.
     *    e.g., max(37, 27, -1, 24, 21) = 37, the real ndesc is (37+1) = 38.
     */

    for (i = 0; i < ndesc; i++)
        max_ndesc = soc_free[i] > max_ndesc ? soc_free[i] : max_ndesc;
    max_ndesc += 1;
    
    rt = select((int)max_ndesc,
                (in ? &win_fd[0] : NULL),
                (out ? &win_fd[1] : NULL),
                (ex ? &win_fd[2] : NULL), to_val_ptr);

    if (rt < 0)
    {
    #ifdef SOC_DBG_ENABLE
        int error = WSAGetLastError();
        kal_printf("select() error %s (%d)\n", err_str(error), error);
    #endif /* SOC_DBG_ENABLE */
        SOC_UNLOCK;
        return -1;
    }

    #define FD_SET_READY(sock, fdset)   ((fdset)->fds_bits[sock] |= 0x02)
    for (s = 0; s < MAX_IP_SOCKET_NUM; s++)
    {
        for (i = 0; i < 3; i++)
        {
            if (fd[i] && FD_ISSET(soc_free[s], &win_fd[i]))
            {
                FD_SET_READY(s, fd[i]);
            }
        }
    }
    #undef FD_SET_READY

#ifdef SOC_DBG_ENABLE
    kal_printf("select return: %d\n", rt);
#endif /* SOC_DBG_ENABLE */
            
    SOC_UNLOCK;
    return (kal_int8)rt;
}


kal_int8 soc_setsockopt(kal_int8 s,
                        kal_uint32 option,
                        void *val,
                        kal_uint8 val_size)
{
    u_long non_blocking;
    int socketid;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return 0;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (option == SOC_NBIO)
    {
        if (val == NULL ||
            (val_size != sizeof(kal_bool) && val_size != sizeof(kal_uint8)))
        {
            SOC_UNLOCK;
            return SOC_INVAL;
        }
       
        if (val_size  == sizeof(kal_uint8))
        non_blocking = *(kal_uint8*)val ? 1 : 0;
        else /* val_size  == sizeof(kal_bool) */
            non_blocking = *(kal_bool*)val ? 1 : 0;
        ioctlsocket(socketid, FIONBIO, &non_blocking);
        if (non_blocking)
            soc_options[s] |= SOC_NBIO;
        else
            soc_options[s] &= ~SOC_NBIO;
    }
    else if (option == SOC_SILENT_LISTEN)
    {
        if (val == NULL || val_size != sizeof(kal_uint8) || 
            ((*(kal_uint8 *)val != KAL_TRUE) && (*(kal_uint8 *)val != KAL_FALSE)))
        {
            SOC_UNLOCK;
            return SOC_INVAL;
        }
        
        soc_options[s] |= SOC_SILENT_LISTEN;
    }
    else if (option == SOC_ASYNC)
    {
        if (val == NULL || val_size != sizeof(kal_uint8))
        {
           SOC_UNLOCK;
           return SOC_INVAL;
        }
        soc_want_events[s] = (int)(*(kal_uint8 *)val);
        if (soc_events[s] & soc_want_events[s])
            soc_notify_thread();
    }
    else
    {
        /* do nothing */
    }

    SOC_UNLOCK;

    return 0;
}


kal_int8 soc_getsockopt(kal_int8 s,
                        kal_uint32 option,
                        void *val,
                        kal_uint8 val_size)
{
    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return 0;
    }

    if (soc_free[s] < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (option == SOC_NBIO)
    {
        if (val == NULL || val_size != sizeof(kal_bool))
        {
            SOC_UNLOCK;
            return SOC_INVAL;
        }

        if (soc_options[s] & SOC_NBIO)
            *(kal_bool*)val = KAL_TRUE;
        else
            *(kal_bool*)val = KAL_FALSE;
    }
    else if (option == SOC_ASYNC)
    {
        *(kal_uint8*)val = (kal_uint8)soc_want_events[s];
    }
    else
    {
        /* do nothing */
    }

    SOC_UNLOCK;

    return 0;
}


kal_int8 socgethostbyname(kal_bool is_blocking,
                          module_type mod_id,
                          kal_int32 request_id,
                          const kal_char *domain_name,
                          kal_uint8 *addr,
                          kal_uint8 addr_len,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id,
                          kal_uint8 *out_entry_num)
{
    unsigned char *p;
    struct hostent *HOST;
    kal_uint8 i;
    kal_uint8 out_entry = 0;

    HOST = gethostbyname(domain_name);

    if (HOST == NULL)
        return SOC_ERROR;
    else
    {
        if (HOST->h_aliases[0])
            kal_printf("%s is an alias for %s.\n", HOST->h_aliases[0], HOST->h_name);
        for (i = 0, p = HOST->h_addr_list[0]; HOST->h_addr_list[i++]; p+=HOST->h_length)
            kal_printf("%s has address %u.%u.%u.%u\n", HOST->h_name, p[0], p[1], p[2], p[3]);

        memset(addr, 0, addr_len);
        for (i = 0; i < (addr_len/4); i++)
        {
            if (HOST->h_addr_list[i])
            {
                memcpy((addr+(i*4)), HOST->h_addr_list[i], 4);
                out_entry++;
            }
            else
            {
                break;
            }
        }

        if (out_entry_num)
        {
            *out_entry_num = out_entry;
        }
        return SOC_SUCCESS;
    }
}

kal_int8 soc_gethostbyname(kal_bool is_blocking,
                           module_type mod_id,
                           kal_int32 request_id,
                           const kal_char *domain_name,
                           kal_uint8 *addr,
                           kal_uint8 *addr_len,
                           kal_uint8 access_id,
                           kal_uint32 nwk_account_id)
{
    kal_int8 ret, soc_id;
    kal_uint8 ap_id;
    kal_bool always_ask = KAL_FALSE;

    SOC_LOCK;

    ap_id = cbm_get_app_id(nwk_account_id);
    *addr_len = 4;

    soc_id = soc_create_dns_socket(is_blocking,
                                ap_id,
                                mod_id,
                                request_id,
                                domain_name,
                                NULL,
                                *addr_len,
                                access_id,
                                nwk_account_id);
    if (soc_id == SOC_LIMIT_RESOURCE)
    {
        SOC_UNLOCK;
        return SOC_LIMIT_RESOURCE;
    }
    
    ret = soc_activate_account((int)soc_id);
    if (ret == SOC_WOULDBLOCK)
    {
        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }
    soc_free_dns_socket(soc_id);
    
    ret = socgethostbyname(is_blocking,
                           mod_id,
                           request_id,
                           domain_name,
                           addr,
                           *addr_len,
                           access_id,
                           nwk_account_id,
                           NULL);
        
    SOC_UNLOCK;
    return ret;

}


kal_int8 soc_gethostbyname2(kal_bool is_blocking,
                           module_type mod_id,
                           kal_int32 request_id,
                           const kal_char *domain_name,
                           kal_uint8 *addr,
                           kal_uint8 *addr_len,
                           kal_uint8 access_id,
                           kal_uint32 nwk_account_id,
                           kal_uint8 in_entry_num,
                           kal_uint8 *out_entry_num)
{
    kal_int8 ret, soc_id;
    kal_uint8 ap_id;
    kal_bool always_ask = KAL_FALSE;

    SOC_LOCK;

    ap_id = cbm_get_app_id(nwk_account_id);

    if (addr_len)
    {
        *addr_len = in_entry_num * 4;
    }
    soc_id = soc_create_dns_socket(is_blocking,
                                ap_id,
                                mod_id,
                                request_id,
                                domain_name,
                                NULL,
                                *addr_len,
                                access_id,
                                nwk_account_id);
    if (soc_id == SOC_LIMIT_RESOURCE)
    {
        SOC_UNLOCK;
        return SOC_LIMIT_RESOURCE;
}

    ret = soc_activate_account((int)soc_id);
    if (ret == SOC_WOULDBLOCK)
    {
        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }
    soc_free_dns_socket(soc_id);
    
    ret = socgethostbyname(is_blocking,
                           mod_id,
                           request_id,
                           domain_name,
                           addr,
                           *addr_len,
                           access_id,
                           nwk_account_id,
                           out_entry_num);
        
    SOC_UNLOCK;
    return ret;
}

kal_int8 socgethostbyaddr(kal_char *domain_name,
                               kal_uint32 *domain_name_len,
                               kal_uint8 *addr,
                               kal_uint8 addr_len)
{
    kal_uint32 *ip_addr;
	struct in_addr in_addr;
	struct hostent *remoteHost;

    
    ip_addr = (kal_uint32 *)addr;
    in_addr.s_addr = (kal_uint32)(*ip_addr);
    remoteHost = gethostbyaddr((char *) &in_addr, 4, AF_INET);
    if (remoteHost == NULL)
        return SOC_ERROR;
    else
    {
        if (strlen(remoteHost->h_name) > *domain_name_len)
        {
            memcpy(domain_name, remoteHost->h_name, *domain_name_len - 1);
            domain_name[*domain_name_len] = '\0';
            *domain_name_len = strlen(remoteHost->h_name);
            return SOC_NAMETOOLONG;
        }
        else
        {
            strcpy(domain_name, remoteHost->h_name);
        }  
    }
    return SOC_SUCCESS;
}

kal_int8 soc_gethostbyaddr(kal_bool is_blocking,
                           module_type mod_id,
                           kal_int32 request_id,
                           kal_char *domain_name,
                           kal_uint32 *domain_name_len,
                           const kal_uint8 *addr,
                           kal_uint8 addr_len,
                           kal_uint8 access_id,
                           kal_uint32 nwk_account_id)
{
    kal_uint8 ap_id;
    kal_int8 ret, soc_id;

    if (domain_name == NULL || domain_name_len == NULL)
    {
        return SOC_ERROR;
    }
    
	SOC_LOCK;
    
    ap_id = cbm_get_app_id(nwk_account_id);

    soc_id = soc_create_dns_socket(is_blocking,
                                ap_id,
                                mod_id,
                                request_id,
                                NULL,
                                (kal_uint8 *)addr,
                                addr_len,
                                access_id,
                                nwk_account_id);
    if (soc_id == SOC_LIMIT_RESOURCE)
    {
        SOC_UNLOCK;
        return SOC_LIMIT_RESOURCE;
    }
    
    ret = soc_activate_account((int)soc_id);
    if (ret == SOC_WOULDBLOCK)
    {
        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }
    soc_free_dns_socket(soc_id);
    ret = socgethostbyaddr(domain_name,
                           domain_name_len,
                           (kal_uint8 *)addr,
                           addr_len);
    
    SOC_UNLOCK;
    return ret;
}


kal_int8 soc_getsockaddr(kal_int8 s,
                         kal_bool is_local,
                         sockaddr_struct *addr)
{
    struct sockaddr_in saddr;  /* connector's address information */
    int addr_len = sizeof(saddr);
    int socketid;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (is_local)
    {
        if (getsockname(socketid, (struct sockaddr *)&saddr, &addr_len))
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("getsockname error %d\n", WSAGetLastError());
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return -1;
        }
    }
    else
    {
        if (getpeername(socketid, (struct sockaddr *)&saddr, &addr_len))
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("getpeername error %d\n", WSAGetLastError());
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return -1;
        }
    }

    soc_convert_addr(&saddr, addr);
    SOC_UNLOCK;
    return 0;
}

kal_bool soc_ip_check(kal_char *asci_addr,
                      kal_uint8 *ip_addr,
                      kal_bool *ip_validity)
{
    kal_uint8 len;
    kal_uint8 i,octet_cnt;
    kal_int32 ip_digit;

    len = strlen(asci_addr);

    for (i = 0 ; i < len ; i++)
    {
        if (!isdigit((int)*(asci_addr+i)) && *(asci_addr+i) != '.' )
            return KAL_FALSE;
    }

    *ip_validity = KAL_TRUE;

    /* Extract the IP adress from character array */
    for (octet_cnt = 0 ; octet_cnt < 4 ; octet_cnt++)
    {
        if (*asci_addr == '\0') /* in case of "1.2.3." */
        {
            *ip_validity = KAL_FALSE;
            return KAL_FALSE;
        }

        ip_digit = atoi(asci_addr);

        if (ip_digit < 0 || ip_digit > 255)
        {
            *ip_validity = KAL_FALSE;
            return KAL_FALSE;
        }

        ip_addr[octet_cnt] = (kal_uint8)ip_digit;

        if (octet_cnt == 3)
            continue;

        asci_addr = strstr(asci_addr,".");
        if (asci_addr)
            asci_addr++;
        else
            break;
    }

    if (octet_cnt != 4)
    {
        return KAL_FALSE;
    }

    if (ip_addr[0] == 0 && ip_addr[1] == 0 && ip_addr[2] == 0 && ip_addr[3] == 0)
    {
        *ip_validity = KAL_FALSE;
    }

    return KAL_TRUE;
}


static kal_int8 socgetlocalip(kal_uint8 *local_ip)
{
    kal_uint8       ip_addr[4];
    kal_uint8       addr_len;

    if (local_ip == NULL)
        return SOC_INVAL;

    addr_len = 4;
    if (socgethostbyname(KAL_FALSE,
                        0,
                        0,
                        "",
                        ip_addr,
                        addr_len,
                        0,
                        0,
                        NULL) != SOC_SUCCESS)
    {
        int last_error = WSAGetLastError();

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("soc_getlocalip error: %d\n", last_error);
        #endif /* SOC_DBG_ENABLE */
        }
        return SOC_ERROR;
    }

    kal_mem_cpy(local_ip, ip_addr, 4);

    return SOC_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  soc_getlocalip
* DESCRIPTION
*   This function returns the local IP address.
*
* PARAMETERS
*  a  IN/OUT      *local_ip, copy the IP address, used as return
* RETURNS
*  SOC_SUCCESS: success
*  negative: bearer is not activated, no IP address info
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int8 soc_getlocalip(kal_uint8 *local_ip)
{
    kal_uint8       ip_addr[4];
    kal_uint8       addr_len;

    if (local_ip == NULL)
        return SOC_INVAL;

    SOC_LOCK;

    addr_len = 4;
    if (socgethostbyname(KAL_FALSE,
                        0,
                        0,
                        "",
                        ip_addr,
                        addr_len,
                        0,
                        0,
                        NULL) != SOC_SUCCESS)
    {
        int last_error = WSAGetLastError();

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("soc_getlocalip error: %d\n", last_error);
        #endif /* SOC_DBG_ENABLE */
        }

        SOC_UNLOCK;

        return SOC_ERROR;
    }

    kal_mem_cpy(local_ip, ip_addr, 4);

    SOC_UNLOCK;

    return SOC_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  soc_get_account_localip
* DESCRIPTION
*   This function returns the local IP address per account.
*
* PARAMETERS
*  s  IN          socket id
*  a  IN/OUT      *local_ip, copy the IP address, used as return
* RETURNS
*  SOC_SUCCESS: success
*  negative: bearer is not activated, no IP address info
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int8 soc_get_account_localip(kal_int8 s, kal_uint8 *local_ip)
{
    if (s < 0 || MAX_IP_SOCKET_NUM <= s)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    SOC_UNLOCK;

    return soc_getlocalip(local_ip);
}

/*****************************************************************************
 * FUNCTION
 *  soc_get_localip_by_account
 *
 * DESCRIPTION
 *  This function returns the local IP address by account id.
 * PARAMETERS
 *  account_id      [IN]            profile id
 *  local_ip        [IN/OUT]        copy the IP address, used as return
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: bearer is not activated, no IP address info
 *****************************************************************************/
kal_int8 soc_get_localip_by_account(kal_uint32 account_id, kal_uint8 *local_ip)
{
    if (local_ip == NULL)
        return SOC_ERROR;

    return soc_getlocalip(local_ip);
}

kal_int8 soc_set_dns_srv_addr(kal_uint32 account_id, kal_uint8 srv_type, kal_uint8 *dns_addr)
{
    return SOC_SUCCESS;
}

void soc_app_deactivate_req_hdlr(module_type mod_id,
                                 kal_uint32 nw_acct_id, 
                                 kal_uint8 qos_profile_id)
{
    


    SOC_LOCK;

    soc_deactivate_bearer(mod_id, nw_acct_id, qos_profile_id, KAL_FALSE);
    
    SOC_UNLOCK;
    return;
}

void soc_abm_deactivate_cnf_hdlr(soc_abm_deactivate_cnf_struct *cnf)
{
    int i, id;
    kal_uint8 app_id = 0;

    SOC_LOCK;
    
    app_id = cbm_get_app_id(cnf->nw_acc_id);
    if (soc_find_soc_app_slot(cnf->mod_id, 
                              app_id,
                              cnf->nw_acc_id, 
                              &id) == 0)
    {
        SOC_UNLOCK;
        return;
    }

    if (cnf->result == KAL_FALSE && 
        cnf->err_cause == ABM_E_NON_AUTO_DEACT)
    {
        soc_app_nwk[id].state = W32_BEARER_OPENED;
        SOC_UNLOCK;
        return;
    }
    else
    {
        for (i = 0; i < MAX_IP_SOCKET_NUM; i++)
        {                  
            if (((app_id != 0 && soc_appid[i] == app_id) ||
                (app_id == 0 && soc_modid[i] == cnf->mod_id &&
                 soc_appid[i] == app_id)))
            {
                if (soc_free[i] != -1)
                {
                    if (soc_state[i] & W32_SOC_S_CONNECTING)
                    {
                        soc_notify_app(soc_free[i], SOC_CONNECT, 
                        KAL_FALSE, SOC_BEARER_FAIL);
                    }
                    else if (soc_state[i] & W32_SOC_S_SENDING) 
                    {
                        soc_notify_app(soc_free[i], SOC_WRITE, 
                        KAL_FALSE, SOC_BEARER_FAIL);
                    }
                    else if (soc_state[i] & W32_SOC_S_RECVING)
                    {
                        soc_notify_app(soc_free[i], SOC_READ, 
                        KAL_FALSE, SOC_BEARER_FAIL);
                    }
                    else
                    {
                        soc_notify_app(soc_free[i], SOC_CLOSE, 
                        KAL_FALSE, SOC_BEARER_FAIL);
                    }
                }
                soc_modid[i]       = -1;
                soc_appid[i]       = -1;
            }
        }
        
        soc_free_soc_app_slot(id);
    }

    SOC_UNLOCK;
    return;
}


kal_int8 soc_abort_dns_query(kal_bool   by_mod_id,
                             module_type mod_id,
                             kal_bool   by_request_id,
                             kal_uint32 request_id,
                             kal_bool   by_access_id,
                             kal_uint8  access_id,
                             kal_bool   by_nwk_account_id,
                             kal_uint32 nwk_account_id)
{
    return 0;
}


kal_int8 soc_get_last_error(kal_int8 s,
                            kal_int8 *error,
                            kal_int32 *detail_cause)
{
    if (error)
        *error = 0;

    if (detail_cause)
        *detail_cause = 0;

    return 0;
}


kal_int8 soc_set_last_error(kal_int8 s,
                            kal_int8 error,
                            kal_int32 detail_cause)
{
    return 0;
}


kal_int8 soc_gethostbysrv(module_type mod_id,
                          kal_int32 request_id,
                          const kal_char *domain_name,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id,
                          soc_dns_srv_struct *entry,
                          kal_uint8 in_entry_num,
                          kal_uint8 *out_entry_num)
{
    return 0;
}


kal_int8 soc_gethostbynaptr(module_type mod_id,
                          kal_int32 request_id,
                          const kal_char *domain_name,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id,
                          soc_dns_naptr_struct *entry,
                          kal_uint8 in_entry_num,
                          kal_uint8 *out_entry_num)
{
    return 0;
}


/*
 * Return KAL_TRUE if there is data in the socket's receive queue indicating
 * the socket is ready for read.
 * Otherwise, return KAL_FALSE.
 */
kal_bool soc_ready_for_read(kal_int8 s)
{
    int sock = soc_free[s];
    fd_set readfds;
    struct timeval tv;
    int ret;
    kal_int8 buf[1];
    int sotype = 0;
    int sotype_len = sizeof(sotype);

    if (sock == SOC_SMS_ID)
        return KAL_FALSE;
        
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    if (!IS_VALID_SOCKET_NUM(s) || soc_state[s] & W32_SOC_S_FINED)
        return KAL_FALSE;

    ret = select(sock + 1, &readfds, NULL, NULL, &tv);
    if (ret > 0)
    {
        ret = getsockopt(sock, SOL_SOCKET, SO_TYPE, (char*)&sotype, &sotype_len);
        if (sotype != SOCK_STREAM ||
            sotype == SOCK_STREAM &&
            recv(sock, buf, sizeof(buf), MSG_PEEK) == 1) /* received some read */
        {
            return KAL_TRUE;
        }
        else
        {
            if (!(soc_state[s] & W32_SOC_S_FINED))  /* notify once */
            {
            #ifdef SOC_DBG_ENABLE
                kal_printf("socket is closed by peer, send close notify\n");
            #endif /* SOC_DBG_ENABLE */
                soc_state[s] |= W32_SOC_S_FINED;
                soc_notify_app(sock, SOC_CLOSE, KAL_FALSE, SOC_CONNRESET);
            }
            return KAL_FALSE;
        }
    }
    else /* XXX, error return value -1 is not handled */
        return KAL_FALSE;
}



void soc_read_notify(kal_int8 s, kal_bool set)
{
    int socketid;

    if (s < 0 || s >= MAX_IP_SOCKET_NUM)
        return;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return;
    }

    if (set)
        soc_want_events[s] |= SOC_READ;
    else
        soc_want_events[s] &= ~SOC_READ;

    SOC_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  soc_set_module
 *
 * DESCRIPTION
 *  This function sets the module id associate to the socket id.
 *  The notification from SOC to application will be sent to the new module.
 * 
 *  Note that this function should not be called inside a socket protection
 *  segment, which causes a dead-lock.
 *
 * PARAMETERS
 *  s       [IN]        socket id
 *  mod     [IN]        new module id
 * RETURNS
 *  >0                     the id of original module id associated to the socket
 *  SOC_INVALID_SOCKET     given an invalid socket id.
 *  0                      error occurs.
 *****************************************************************************/
kal_int32 soc_set_module(kal_uint8 s, module_type mod)
{
#ifdef __SSL_SUPPORT__
    int idx;

    SOC_LOCK;

    if (s < 0 || MAX_IP_SOCKET_NUM <= s || soc_state[s] == W32_SOC_S_NOUSE)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_find_soc_app_slot(soc_modid[s], 
                              soc_appid[s],
                              soc_account_id[s], 
                              &idx) == 0)
    {
        SOC_UNLOCK;
        return 0;
    }

    notify_soc_modid[s] = mod;

    SOC_UNLOCK;
    return soc_modid[s];
#else /* !__SSL_SUPPORT__ */
    return SOC_OPNOTSUPP;
#endif /* !__SSL_SUPPORT__ */
}



unsigned char *err_str(int error)
{
    int i;
    unsigned char *str;
    
    for (i = 0; i < sizeof(winsock_errstr) / sizeof(winsock_errstr[0]); i++)
        if (atoi(winsock_errstr[i]) == error)
        {
            str = strchr(winsock_errstr[i], ' ') + 1;
            break;
        }
    return str;
}

kal_bool soc_set_csd_auto_disconnect_timer(kal_uint16 sec)
{
    csd_timer_val = (int)sec;
    return KAL_TRUE;
}

kal_bool soc_get_csd_auto_disconnect_timer(kal_uint16 *sec)
{
    if (sec)
        *sec = csd_timer_val;
    
    return KAL_TRUE;
}

kal_bool soc_set_gprs_auto_disconnect_timer(kal_uint16 sec, kal_uint32 account_id)
{
    return KAL_TRUE;
}

kal_bool soc_get_gprs_auto_disconnect_timer(kal_uint16 *sec, kal_uint32 account_id)
{
    return KAL_TRUE;
}

#endif /* !__NWK_APP_UT__ */
