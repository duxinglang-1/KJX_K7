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
 

/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */









/*******************************************************************************
 *
 * Filename:
 * ---------
 * phs_main.h
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
 * -------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _phs_main_h
#define _phs_main_h

#include <clib.h>

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _msf_mem_h
#include "msf_mem.h"
#endif

#ifndef _msf_lib_h
#include "msf_lib.h"
#endif

#ifndef _phs_cfg_h
#include "phs_cfg.h"
#endif

#ifndef _phs_msg_h
#include "phs_msg.h"
#endif

#include "msf_log.h"

#ifndef _phs_dlg_h
#include "phs_dlg.h"
#endif

#ifdef PHS_CONFIG_MULTIPART
#ifndef _phs_mprt_h
#include "phs_mprt.h"
#endif
#endif





#define PHS_MEM_ALLOC(x)      MSF_MEM_ALLOC (MSF_MODID_PHS, (x))
#define PHS_MEM_ALLOCTYPE(x)  MSF_MEM_ALLOCTYPE (MSF_MODID_PHS, x)
#define PHS_MEM_FREE(x)       MSF_MEM_FREE (MSF_MODID_PHS, (x))





#define PHS_MAIN_SIG_OPEN_PUSH_CONNECTION            PHS_MODULE_MAIN + 1
#define PHS_MAIN_SIG_CLOSE_PUSH_CONNECTION           PHS_MODULE_MAIN + 2
#define PHS_MAIN_SIG_STK_CONNECTION_CREATED          PHS_MODULE_MAIN + 3
#define PHS_MAIN_SIG_STK_CONNECTION_CLOSED           PHS_MODULE_MAIN + 4
#define PHS_MAIN_SIG_RECV_REQUEST                    PHS_MODULE_MAIN + 5
#define PHS_MAIN_SIG_HTTP_REPLY                      PHS_MODULE_MAIN + 6
#define PHS_MAIN_SIG_RESPONSE_FROM_CONTENT_ROUTING   PHS_MODULE_MAIN + 7
#define PHS_MAIN_SIG_WIDGET_ACTION                   PHS_MODULE_MAIN + 8
#define PHS_MAIN_SIG_HOST_BY_NAME                    PHS_MODULE_MAIN + 10

#define PHS_SIG_NOTIFY                               PHS_MODULE_MAIN + 11


#define PHS_SIG_DIALOG_RESPONSE                      PHS_MODULE_MAIN + 14
 
#define PHS_MAIN_SIG_SET_DATA_TO_SETTING			 PHS_MODULE_MAIN + 15

#define PHS_MAIN_SIG_SET_DEF_CONN					 PHS_MODULE_MAIN + 16

#define PHS_MAIN_SIG_SET_LIST_DATA					 PHS_MODULE_MAIN + 17

    
#ifdef MTK_TMP_PATCH /* TR35727 */
#define PHS_MAIN_SIG_HTTP_REQUEST_ABORTED            (PHS_MODULE_MAIN + 18)
#endif

#define TEMP										 PHS_MODULE_MAIN + 19









  

  
#define PHS_REG_PATH_CPI_INFO               0
#define PHS_REG_PATH_DEFAULT_CONN           1
#define PHS_REG_PATH_SIR                    2
#define PHS_REG_PATH_WHITELIST              3
#define PHS_REG_PATH_ROOT                   4


 
#define PHS_REG_KEY_SMS                     0
#define PHS_REG_KEY_UDP                     1
#define PHS_REG_KEY_HTTP                    2   
#define PHS_REG_KEY_WTLS                    3
  
#define PHS_REG_KEY_SECURITY_LEVEL          4
#define PHS_REG_KEY_SUPPORT_SL              5
#define PHS_REG_KEY_SUPPORT_SIR             20

#define PHS_REG_KEY_SIR_CONNTYPE            6
#define PHS_REG_KEY_SIR_NET_ID              7

#define PHS_REG_KEY_ACCEPT                  8
#define PHS_REG_KEY_ACCEPT_CHARSET          9
#define PHS_REG_KEY_ACCEPT_LANGUAGE         10
#define PHS_REG_KEY_ACCEPT_APP_ID           11

#define PHS_REG_KEY_WHITELIST_IP            12
#define PHS_REG_KEY_WHITELIST_SMSC          13
#define PHS_REG_KEY_BLACKLIST_IP            14
#define PHS_REG_KEY_BLACKLIST_SMSC          15
#define PHS_REG_KEY_WHITELIST_DOMAIN        16
#define PHS_REG_KEY_WHITELIST_BEHAVIOR      17

#define PHS_REG_KEY_TERMINAL_ID             18
#define PHS_REG_KEY_PROVISND_TERMINAL_ID    19

#define PHS_STREAM_PIPE_READ                1
#define PHS_STREAM_FILE_READ                2
#define PHS_STREAM_MEM_READ                 3

#define PHS_STREAM_EVENT_CLOSED             1        
#define PHS_STREAM_EVENT_READ_READY         2


#define PHS_STREAM_ERROR_DELAYED                  -1
#define PHS_STREAM_ERROR_EOF                      -2
#define PHS_STREAM_ERROR                          -3


#define PHS_WHITELIST_NO_MATCH                        1
#define PHS_WHITELIST_MATCH                           2
#define PHS_WHITELIST_DNS_LOOKUP                      3 
#define PHS_BLACKLIST_MATCH                           4 




typedef struct phs_msg_list_st           phs_msg_list_t;
#ifdef PHS_CONFIG_MULTIPART
typedef struct phs_mprt_st               phs_mprt_t;
#endif


typedef struct phs_connection_st {
  int                        connection_id;
  int                        nbr_of_users;
  int                        state;
  int                        bearer;
  MSF_UINT16                 portNumber;
  MSF_INT16                  connectionType;
  MSF_INT32                  networkAccountId;
} phs_connection_t;

typedef struct phs_user_conn_info_st {
  int                        external_handle;
  phs_connection_t          *conn;
} phs_user_conn_info_t;

typedef struct phs_user_st {
  struct phs_user_st        *next;
  MSF_UINT8                  module_id;
  int                        num_open_connections;
  phs_user_conn_info_t      *user_conn[PHS_CFG_MAX_CONNECTIONS_PER_USER];
} phs_user_t;


typedef struct phs_client_conn_st {
  struct phs_client_conn_st *next;

  int                        conn_id;
  MSF_INT16                  connectionType;
  unsigned char             *assumed_cpi_tag;
  int                        network_account_id;
} phs_client_conn_t;

typedef struct phs_cpi_hdrs_value_st {
  char             *accept;
  char             *accept_charset;
  char             *accept_language;
  char             *accept_app_id;
} phs_cpi_hdrs_value_t;

typedef struct phs_data_st {
  struct phs_data_st         *next;
  unsigned char              *buf;
  int                         buf_len;
} phs_data_t;

/*
struct phs_msg_list_st {   
  struct phs_msg_list_st    *next_msg;
  
  msf_sockaddr_t             fromAddr;
  int                        method;
  char                      *headers;
  stk_content_t             *content;
  int                        connection_type;
  
  char                      *url;
  int                        whitelist_result;
  int                        dialog_id;
  int                        state;
  MSF_INT16                  id;
  int                        routing_type;
  char                      *routing_identifier;
  int                        req_id;
  int                        conn_id;
  int                        parent_id;
  int                        content_type_int;
  char                      *initiator_uri;
  char                      *content_uri;
  char                      *content_location;
  phs_prs_info_t             parsed_info;
  
  phs_data_t                *buf_list;    
  MSF_INT32                  msg_len;
  unsigned char             *msg_data;
#ifdef PHS_CONFIG_MULTIPART 
  phs_mprt_t                *mp;
#endif
#ifdef __WAP_DUAL_SIM__
  MSF_UINT32                 network_account_id;
#endif /* __WAP_DUAL_SIM__ 
MSF_UINT32 sim_id;
}; */

struct phs_msg_list_st {   
  struct phs_msg_list_st    *next_msg;
  
  msf_sockaddr_t             fromAddr;
    MSF_INT16                  id;
  int                        method;
  char                      *headers;
  stk_content_t             *content;
  int                        connection_type;
  
  char                      *url;
  int                        whitelist_result;
  int                        dialog_id;
  int                        state;

  int                        routing_type;
  char                      *routing_identifier;
  int                        req_id;
  int                        conn_id;
  int                        parent_id;
  int                        content_type_int;
  char                      *initiator_uri;
  char                      *content_uri;
  char                      *content_location;
  phs_prs_info_t             parsed_info;  
  phs_data_t                *buf_list;    
  MSF_INT32                  msg_len;
  unsigned char             *msg_data;
#ifdef PHS_CONFIG_MULTIPART 
  phs_mprt_t                *mp;
#endif
#if(MMI_MAX_SIM_NUM >= 2)
  MSF_UINT32                 network_account_id;
#endif /* MMI_MAX_SIM_NUM */
MSF_UINT32 sim_id;
};




extern mtk_jmpbuf phs_jmp_buf;
extern int     phs_inside_run;










extern phs_user_t            *phs_user_list;
extern phs_connection_t      *phs_connection_table[PHS_CFG_MAX_CONNECTIONS];
extern phs_client_conn_t     *phs_client_conn_list; 
extern int                    phs_handle;
extern char                  *phs_clients_cpi_tag;
extern phs_msg_list_t        *phs_msg_list;


extern int                    phs_security_level;
extern int                    phs_support_SIR;
extern int                    phs_support_SL;
extern int                    phs_sia_default_net_id;
extern int                    phs_sia_default_conn_type;
extern int                    phs_whitelist_behavior;
extern char                  *phs_terminal_id;
extern char                  *phs_prov_termid_list;
extern char                  *phs_whitelist_ip;
extern char                  *phs_whitelist_smsc;
extern char                  *phs_blacklist_smsc;
extern char                  *phs_blacklist_ip;

extern int                    sir_lockout_timer;

#ifdef PHS_CONFIG_HTTP_PUSH  
extern phs_cpi_hdrs_value_t   phs_cpi_hdr_values;
#endif


void
phs_init (void);

void
phs_terminate (void);

void
phs_stk_status (msf_module_status_t *p);

int
phs_new_handle (void);

void
phs_handle_file_notification (int handle, int event_type);

void
phs_handle_pipe_notification (int handle, int event_type);

int
phs_stream_init (int module, int id, int type,
                 void *data, long datalen,
                 const char *pathname);

long
phs_stream_read (int stream_handle, void *buf, long buflen);

int
phs_stream_register_handle (int id, int type, int handle, int owner, char* path_name );

void
phs_stream_close (int stream_handle);

void
phs_connectionOpened (MSF_UINT8 dst, int external_handle, int errorCode);

void
phs_connectionClosed (MSF_UINT8 dst, int external_handle, int errorCode);

void
phs_main_set_channel (MSF_UINT32 sim_id);

int 
phs_main_get_channel_id (void);

void * phs_mem_alloc (MSF_UINT32 size);

#endif


