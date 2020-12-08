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
 * BppSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for Bpp MMI service internal structure definition and 
 *      prototype declaration.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef BPP_SERVICE_H
#define BPP_SERVICE_H

#include "BppSrvGprot.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "fs_type.h"
#include "bluetooth_struct.h"
/* auto add by kw_check end */
/***************************************************************************** 
* List operation
*****************************************************************************/
typedef struct _bpp_list {
    struct _bpp_list *prev;
    struct _bpp_list *next;
} bpp_list_struct;

#define ListInit(list) \
    do { \
		(list)->prev = (list)->next = (list); \
    } while (0)

#define ListNodeInit(node)    ((node)->prev = (node)->next = 0)

#define ListHead(list)         ((list)->prev)
#define ListTail(list)         ((list)->next)
#define ListNext(node)         ((node)->prev)
#define ListPrev(node)         ((node)->next)
#define ListEmpty(list)        ((list)->prev == list)

#define ListAdd(list, node) \
    do { \
        (node)->prev = list; \
        (node)->next = (list)->next; \
        (list)->next->prev = node; \
        (list)->next = node; \
    } while (0)

#define ListInsert(list, node) \
    do { \
        (node)->next = list; \
        (node)->prev = (list)->prev; \
        (list)->prev->next = node; \
        (list)->prev = node; \
    } while (0)

#define ListDelete(node) \
    do { \
        (node)->next->prev = (node)->prev; \
        (node)->prev->next = (node)->next; \
    } while (0)

#define ListEntry(addr, type, member) \
    ((type *)((U8 *)addr - (U32)(&((type *)0)->member)))

#define ForEachOfList(list, node) \
    for (node = ListHead(list); node != list; node = ListNext(node))

#define ForEachOfListEx(list, node, backup) \
    for (node = ListHead(list), backup = ListNext(node); node != list; \
        node = backup, backup = ListNext(node))
        
#define ForEachOfListPrev(list, node, backup) \
        for (node = ListTail(list), backup = ListPrev(node); node != list; \
            node = backup, backup = ListPrev(node))

/***************************************************************************** 
* Const
*****************************************************************************/
#define MAX_INSTANCES    (3)
#define MAX_JOBS         (8)

#define MAX_PASSWORD    (16)
#define MAX_FILE_PATH   (32)

#define BPP_EVENT_ID        (0x400 + 3)

enum {
    EV_JOB_UPDATE =     BPP_EV_JOB_UPDATE,
    EV_JOB_NEW =        BPP_EV_JOB_NEW,
    EV_JOB_DELETE =     BPP_EV_JOB_DELETE,
    EV_JOB_START_REQ =  BPP_EV_JOB_START_REQ,
    EV_JOB_REQUEST =    BPP_EV_JOB_REQUEST,
    EV_JOB_STATUS =     BPP_EV_JOB_STATUS,
    EV_JOB_PROGRESS =   BPP_EV_JOB_PROGRESS,
    EV_JOB_FINISH =     BPP_EV_JOB_FINISH,
    EV_BEARER_INFO =    BPP_EV_BEARER_INFO,
    EV_UPDATE_FAIL =    BPP_EV_UPDATE_FAIL,
    EV_END
};

enum {
    PRINT_MODE_SIMPLE =     BPP_PRINT_MODE_SIMPLE,
    PRINT_MODE_ADVANCED =   BPP_PRINT_MODE_ADVANCED,
    PRINT_MODE_END
};

enum {
    RESULT_SUCC =       BPP_RESULT_SUCC,
    RESULT_FAIL =       BPP_RESULT_FAIL,
    RESULT_PENDING =    BPP_RESULT_PENDING,
    RESULT_END
};

enum {
    E_NONE =            BPP_E_NONE,
    E_GENERAL =         BPP_E_GENERAL,
    E_INVALID_PARA =    BPP_E_INVALID_PARA,
    E_INVALID_DATA =    BPP_E_INVALID_DATA,
    E_REQ_CANCELLED =   BPP_E_REQ_CANCELLED,
    E_USER_ABORT =      BPP_E_USER_ABORT,
    E_SCO_REJECT =      BPP_E_SCO_REJECT,
    E_LINK_BROKEN =     BPP_E_LINK_BROKEN,
    E_OP_BUSY =         BPP_E_OP_BUSY,
    E_END
};

enum {
    EV_OP_NEW = BPP_EV_OP_NEW,
    EV_OP_ADD = BPP_EV_OP_ADD,
    EV_OP_DEL = BPP_EV_OP_DEL,
    EV_OP_END
};

enum {
    REQUEST_DATA = BPP_REQUEST_DATA,
    REQUEST_AUTH = BPP_REQUEST_AUTH,
    REQUEST_END
};

enum {
    MODE_RDONLY = BPP_MODE_RDONLY,
    MODE_RDWRITE = BPP_MODE_RDWRITE,
    MODE_END
};

enum {
    INFO_PRINTER_ADDR = BPP_INFO_PRINTER_ADDR,
    INFO_PRINTER_ATTR = BPP_INFO_PRINTER_ATTR,
    INFO_PRINTER_VALID =BPP_INFO_PRINTER_VALID,
    INFO_PRINTER =      BPP_INFO_PRINTER,
    INFO_PRINT_OPTION = BPP_INFO_PRINT_OPTION,
    INFO_JOB_OPTION =   BPP_INFO_JOB_OPTION,
    INFO_JOB =          BPP_INFO_JOB,
    INFO_END
};

enum {
    JOB_MODE_RDONLY,
    JOB_MODE_RDWR,
    JOB_MODE_END
};

enum {
    OP_UPDATE = BPP_OP_UPDATE,
    OP_PRINT = BPP_OP_PRINT,
    OP_NONE,
    OP_END
};

enum {
    PRINTER_IDLE =          BPP_PRINTER_IDLE,
    PRINTER_PROGRESSING =   BPP_PRINTER_PROCESSING,
    PRINTER_STOPPED =       BPP_PRINTER_STOPPED,
    PRINTER_UNKNOWN =       BPP_PRINTER_UNKNOWN,
    PRINTER_STATE_END
};

enum {
    JOB_PRINTING =  BPP_JOB_PRINTING,
    JOB_WAITING =   BPP_JOB_WAITING,
    JOB_STOPPED =   BPP_JOB_STOPPED,
    JOB_COMPLETED = BPP_JOB_COMPLETED,
    JOB_ABORTED =   BPP_JOB_ABORTED,
    JOB_CANCELLED = BPP_JOB_CANCELLED,
    JOB_UNKNOWN =   BPP_JOB_UNKNOWN,
    JOB_STATE_END
};

enum {
    BEARER_UP = BPP_BEARER_UP,
    BEARER_FAIL = BPP_BEARER_FAIL,
    BEARER_DOWN = BPP_BEARER_DOWN,
    BEARER_END
};

enum {
    START_MODE_CONFLICT,
    START_MODE_NORMAL,
    START_MODE_END
};

enum {
    MSG_OPEN,
    MSG_CLOSE,
    MSG_GET_ATTR,
    MSG_PRINT_DOC,
    MSG_VALIDATE,
    MSG_PROGRESS,
    MSG_END
};

enum {
    STATE_CLOSE_ED,
    STATE_OPEN,
    STATE_OPEN_ED,
    STATE_CLOSE,
    STATE_DISC,
    STATE_WAIT_START,
    STATE_WAIT_DATA,
    STATE_WAIT_AUTH,
    STATE_END
};

enum {
    REQ_UPDATE,
    REQ_PRINT,
    REQ_ACCEPT,
    REQ_ABORT,
    REQ_END,
    CNF_OPEN,
    CNF_UPDATE,
    CNF_PRINT,
    CNF_CLOSE,
    CNF_END,
    IND_STATUS,
    IND_PROGRESS,
    IND_AUTHENTICATE,
    IND_DISCONNECT,
    IND_END
};

enum {
    FLAG_DESTROY = 0x01,
    FLAG_DELETE = 0x02,
    FLAG_CLOSE = 0x04,
    FLAG_ABORT = 0x08,
    FLAG_END
};

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct {
    MMI_EVT_PARAM_HEADER
    U32 notify;
    U32 para;
} bpp_event_struct;

typedef struct {
    U32 id;
    U32 pos;
} bpp_job_search_struct;

typedef struct {
    U32 job_count;
    U32 del_count;
    bpp_job_search_struct table[MAX_JOBS];
} bpp_job_summary_struct;

typedef struct {
    U32 del_flag;
    U32 id;
} bpp_job_head_struct;

typedef PrinterInfo     bpp_dev_info_struct;
typedef PrintOptionInfo bpp_job_info_struct;

typedef struct {
    bpp_job_head_struct head;
    bpp_dev_info_struct device;
    bpp_job_info_struct info;
} bpp_job_save_struct;

typedef struct {
    U16 job;
    U16 dev;
} bpp_progress_struct;

typedef struct {
    U32 type;
    union {
        U8 *buff;
        WCHAR file[MAX_FILE_PATH];
    } u;
    U32 size;
    U32 more;
} bpp_data_struct;

typedef struct {
    bpp_list_struct entry;
    S32 handle;
    U32 event_mask;
    U32 mode;
    U32 flags;
    bpp_list_struct job_list;
    BppSrvNotify notify;
} bpp_srv_inst_struct;

typedef struct {
    bpp_list_struct glb_entry;
    bpp_list_struct inst_entry;
    U32 id;
    U32 flags;
    U32 conn_id;
    S32 cm_conn_id;
    S32 conn_hd;
    U8 state;
    U8 mode;
    U16 op_code;
    U16 op_result;
    U32 print_mode;
    CHAR passwd[MAX_PASSWORD];
    bpp_dev_info_struct device;
    bpp_job_info_struct info;
    bpp_data_struct     data;
    bpp_progress_struct status;
    bpp_srv_inst_struct *owner;
} bpp_srv_job_struct;

typedef BppSrvConfig bpp_srv_config_struct;

typedef struct {
    MMI_BOOL init_done;
    bpp_srv_inst_struct insts[MAX_INSTANCES];
    bpp_list_struct inst_list;
    bpp_srv_config_struct config;
    bpp_list_struct job_list;
    bpp_job_summary_struct job_sum;
    U32 id_seed;
} bpp_srv_cntx_struct;

extern const S8 *bpp_media_size_self_desc_name[];

/***************************************************************************** 
* Prototype
*****************************************************************************/
static MMI_RET bpp_event_proc(bpp_event_struct *evt);
static void bpp_msg_hdlr(void *para, S32 mod_src, ilm_struct *ilm);
static void bpp_send_msg(U32 msg_id, bpp_srv_job_struct *job);
    
static bpp_srv_inst_struct *bpp_new(U32 mode);
static bpp_srv_inst_struct *bpp_find(S32 srv_hd);
static void bpp_delete(bpp_srv_inst_struct *inst);
static void bpp_disconnect(U32 conn_id);
    
static bpp_srv_job_struct *bpp_new_job(U32 job_id);
static bpp_srv_job_struct *bpp_create_job(bpp_srv_inst_struct *inst);
static bpp_srv_job_struct *bpp_read_job(U32 job_id);
static bpp_srv_job_struct *bpp_load_job(bpp_srv_inst_struct *inst, U32 job_id, U32 mode);
static bpp_srv_job_struct *bpp_get_job(bpp_list_struct *list, U32 job_id);
static bpp_srv_job_struct *bpp_find_job(S32 conn_hd);
static S32 bpp_destroy_job(bpp_srv_job_struct *job);

static U32 bpp_add_job(bpp_srv_job_struct *job);
static U32 bpp_save_job(bpp_srv_job_struct *job);
static S32 bpp_delete_job(U32 job_id);

static FS_HANDLE bpp_open_file(U32 flag);
static void bpp_defrag(void);

static S32 bpp_state_hdlr(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_close_ed(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_open(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_open_ed(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_close(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_disc(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_wait_start(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_wait_data(U32 in, bpp_srv_job_struct *job, void *para);
static S32 bpp_state_wait_auth(U32 in, bpp_srv_job_struct *job, void *para);

static S32 bpp_update_req_hdlr(bpp_srv_job_struct *job);
static S32 bpp_print_req_hdlr(bpp_srv_job_struct *job);
static S32 bpp_open_succ_hdlr(bpp_srv_job_struct *job, U32 conn_id);
static S32 bpp_open_fail_hdlr(bpp_srv_job_struct *job, U16 cause);
static S32 bpp_update_hdlr(bpp_srv_job_struct *job, bt_bpp_prt_capability *capb);

static S32 bpp_notify(U32 action, bpp_srv_inst_struct *inst, U32 event, U32 param);
static S32 bpp_notify_all(U32 action, U32 event, U32 param);

static U32 bpp_get_compatible_options(PrintOption *opt, PrinterAttribute *attr);
static U32 bpp_job_conflict(U32 mode, bpp_dev_info_struct *dev, bpp_job_info_struct *opt);
static U16 conv_cause(S32 ret);

static void bpp_init_msg_hdlr(void);
static void bpp_init_job_sum(void);
static void bpp_create_storage(void);
static void bpp_init_job_stat(void);
static U32 alloc_new_job_id(void);
static U32 alloc_job_id(void);
static S32 in_list(bpp_list_struct *list, bpp_list_struct *entry);
static U8 bit_offset(U64 value);

extern PRT_HANDLE bt_bpp_alloc_prt_handle(const goep_bd_addr_struct *bt_addr);

#endif /* BPP_SERVICE_H */
