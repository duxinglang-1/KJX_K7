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
 * BthfSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for Bluetooth hands-free MMI service internal structure 
 *     definition and prototype declaration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BTHF_SERVICE_H
#define BTHF_SERVICE_H

#include "BthfSrvGprot.h"

/* RHR ADD */
#include "MMIDataType.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "BtcmSrvGprot.h"
/* RHR ADD end */

#ifdef __MMI_BT_SLIM__
#ifndef _MMI_BT_ULTRA_SLIM_
#define _MMI_BT_ULTRA_SLIM_
#endif 
#endif

/***************************************************************************** 
* Const
*****************************************************************************/
#define BTHF_MAX_INSTANCE       (4)
#define BTHF_MAX_CONNECTION     (2)

typedef enum {
    STATE_SERV_IDLE,
    STATE_ACTIVATE,
    STATE_ACTIVATE_ED,
    STATE_DEACTIVATE,
    STATE_SERV_END
} bthf_serv_state_enum;

typedef enum {
    STATE_DEV_IDLE,
    STATE_WAIT_RSP,
    STATE_SLC_CONN,
    STATE_SLC_CONN_ED,
    STATE_SCO_CONN,
    STATE_SCO_CONN_ED,
    STATE_SCO_DISC,
    STATE_SLC_DISC,
    STATE_DEV_END
} bthf_state_enum;

typedef enum {
    REQ_INIT,
    REQ_START,
    REQ_DONE
} bthf_req_state_enum;

enum {
    EV_ENABLE =     BTHF_EV_ENABLE,
    EV_DISABLE =    BTHF_EV_DISABLE,
    EV_REQ_ATTACH = BTHF_EV_REQ_ATTACH,
    EV_REQ_ABORT =  BTHF_EV_REQ_ABORT,
    EV_ATTACH =     BTHF_EV_ATTACH,
    EV_DETACH =     BTHF_EV_DETACH,
    EV_AUDIO_ON =   BTHF_EV_AUDIO_ON,
    EV_AUDIO_OFF =  BTHF_EV_AUDIO_OFF,
    EV_VOL_CHANGE = BTHF_EV_VOL_CHANGE,
    EV_REQ_RESULT = BTHF_EV_REQ_RESULT
};

enum {
    RESULT_SUCC = BTHF_RESULT_SUCC,
    RESULT_FAIL = BTHF_RESULT_FAIL
};

enum {
    E_NONE =            BTHF_E_NONE,
    E_BUSY =            BTHF_E_BUSY,
    E_PENDING =         BTHF_E_PENDING,
    E_NOT_AUTHORIZE =   BTHF_E_NOT_AUTHORIZE,
    E_NOT_ALLOW =       BTHF_E_NOT_ALLOW,
    E_NOT_SUPPORTED =   BTHF_E_NOT_SUPPORT,
    E_BEARER_BROKEN =   BTHF_E_BEARER_BROKEN,
    E_UNKNOWN =         BTHF_E_UNKNOWN,
    E_USER_ABORT =      BTHF_E_USER_ABORT
};

enum {
    PROF_HF = BTHF_PROF_HF,
    PROF_HS = BTHF_PROF_HS,
    PROF_AUTO = BTHF_PROF_AUTO,
    PROF_END
};

enum {
    MSG_ACTIVATE,
    MSG_DEACTIVATE,
    MSG_SLC_CONN,
    MSG_AUTH_RSP,
    MSG_SLC_DISC,
    MSG_SPEAKER_GAIN,
    MSG_MIC_GAIN,
    MSG_SCO_CONN,
    MSG_SCO_DISC,
    MSG_VOLUME_REQ
};

enum {
    CFG_AUDIO_PATH = BTHF_CFG_AUDIO_PATH,
    CFG_DEF_DEVICE = BTHF_CFG_DEF_DEVICE,
    CFG_PROFILE = BTHF_CFG_PROFILE
};

enum {
    REQ_ENABLE =    BTHF_REQ_ENABLE,
    REQ_DISABLE =   BTHF_REQ_DISABLE,
    REQ_ATTACH =    BTHF_REQ_ATTACH,
    REQ_DETACH =    BTHF_REQ_DETACH,
    REQ_AUDIO_ON =  BTHF_REQ_AUDIO_ON,
    REQ_AUDIO_OFF = BTHF_REQ_AUDIO_OFF,
    REQ_ACCEPT =    BTHF_REQ_ACCEPT,
    REQ_REJECT =    BTHF_REQ_REJECT,
    REQ_CHG_VOLUME = BTHF_REQ_CHG_VOLUME,
    REQ_END,
    CNF_ACTIVATE,
    CNF_DEACTIVATE,
    CNF_SLC_CONN,
    CNF_SCO_CONN,
    CNF_SPEAKER_GAIN,
    CNF_MIC_GAIN,
    CNF_END,
    IND_SLC_REQ,
    IND_SLC_CONN,
    IND_SLC_DISC,
    IND_SCO_CONN,
    IND_SCO_DISC,
    IND_SPEAKER_GAIN,
    IND_MIC_GAIN,
    IND_END,
    FSM_EVT_END
};

enum {
    STATUS_DETACH = BTHF_STATUS_DETACH,
    STATUS_ATTACH = BTHF_STATUS_ATTACH,
    STATUS_AUDIO_ON = BTHF_STATUS_AUDIO_ON
};

enum {
    FIND_BY_ADDR,
    FIND_BY_DEV_ID,
    FIND_BY_CONN_ID,
    FIND_BY_CMGR_ID,
    FIND_BY_OWNER
};

#define FLAG_DELETE    (0x01)
#define FLAG_DISABLE   (0x02)
#define FLAG_ABORT     (0x04)
#define FLAG_DETACH    (0x08)

#define BTHF_EVENT_ID  (1024 + 2)

/***************************************************************************** 
* List operation
*****************************************************************************/
typedef struct _bthf_list {
    struct _bthf_list *prev;
    struct _bthf_list *next;
} bthf_list_struct;

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

#define ListOwner(addr, type, member) \
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
* Structure
*****************************************************************************/
typedef struct _bthf_dev    bthf_device_struct;
typedef struct _bthf_inst   bthf_inst_struct;

typedef BTHFErrCode (*BTHFFSM)(void *owner, U32 in, void *para);

typedef struct {
    LOCAL_PARA_HDR
    U16 result;        
    BTHFAddr addr;
    U32 conn_id;
} bthf_slc_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    BTHFAddr addr;
    U32 conn_id;
    U32 passive;
} bthf_slc_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    U16 result;        
    U8 conn_id;
} bthf_sco_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    U8 conn_id;
} bthf_sco_ind_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    U32 evt;
    U32 para;
} bthf_event_struct;

typedef struct {
    bthf_list_struct node;
    bthf_inst_struct *owner;
    bthf_list_struct *list;
    U32 id;
    U32 para;
    U32 flags;
    U8 status;
    U16 retval;
} bthf_request_struct;

typedef struct {
    bthf_inst_struct *inst;
    bthf_device_struct *dev;
    U32 evt_id;
    U32 para;
} bthf_notify_struct;

typedef struct {
    BTHFAudioMode mode;
    BTHFAddr def_dev;
} bthf_setting_struct;

typedef struct _bthf_dev {
    bthf_list_struct node;
    bthf_inst_struct *owner;
    U32 id;
    BTHFAddr addr;
    U32 state;
    U32 conn_id;
    U32 cmgr_id;
    U32 features;
    U32 flags;
    U8 prof;
    U8 dev_class;
    U8 spk_gain;
    U8 mic_gain;
    MMI_BOOL incoming;
    bthf_list_struct req_list;
} bthf_device_struct;

typedef struct _bthf_inst{
    bthf_list_struct node;
    S32 handle;
    U32 event_mask;
    U32 flags;
    U32 dev_count;
    BTHFSrvNotify notify;
    bthf_setting_struct setting;
    U32 prof;
} bthf_inst_struct;

typedef struct {
    U8 state;
    U8 prof_count;
    U32 features;
    U32 flags;
    bthf_inst_struct *owner;
    bthf_list_struct req_list;
} bthf_serv_struct;

typedef struct {
    bthf_serv_struct service;
    bthf_inst_struct insts[BTHF_MAX_INSTANCE];
    bthf_list_struct inst_list;
    bthf_device_struct devs[BTHF_MAX_CONNECTION];
    bthf_list_struct dev_list;
    bthf_setting_struct setting;
    U32 dev_count;
    MMI_BOOL init_done;
} bthf_cntx_struct;

typedef struct {
    BTHFHandle handle;
    BTHFAttachCallback notify;
    U32 dev_id;
    MMI_BOOL busy;
} bthf_helper_cntx_struct;

/***************************************************************************** 
* Internal function declaration
*****************************************************************************/
static void bthf_enable(void);
static void bthf_disable(void);
static void bthf_connect(U32 conn_id, MMI_BOOL result);
static void bthf_disconnect(U32 conn_id);

static MMI_RET bthf_evt_proc(mmi_event_struct *event);
static U8 bthf_msg_hdlr(void *para, U32 src_mod, ilm_struct *ilm);

static BTHFErrCode bthf_fsm(void *owner, U32 in, void *para);
static BTHFErrCode state_serv_idle(bthf_serv_struct *serv, U32 evt, void *para);
static BTHFErrCode state_activate(bthf_serv_struct *serv, U32 evt, void *para);
static BTHFErrCode state_activate_ed(bthf_serv_struct *serv, U32 evt, void *para);
static BTHFErrCode state_deactivate(bthf_serv_struct *serv, U32 evt, void *para);
static BTHFErrCode state_dev_idle(bthf_device_struct *dev, U32 in, void *para);
static BTHFErrCode state_wait_rsp(bthf_device_struct *dev, U32 in, void *para);
static BTHFErrCode state_slc_conn(bthf_device_struct *dev, U32 in, void *para);
static BTHFErrCode state_slc_conn_ed(bthf_device_struct *dev, U32 in, void *para);
static BTHFErrCode state_sco_conn(bthf_device_struct *dev, U32 in, void *para);
static BTHFErrCode state_sco_conn_ed(bthf_device_struct *dev, U32 in, void *para);
static BTHFErrCode state_sco_disc(bthf_device_struct *dev, U32 in, void *para);
static BTHFErrCode state_slc_disc(bthf_device_struct *dev, U32 in, void *para);

static void bthf_init_setting(bthf_setting_struct *setting);
static void * bthf_read_setting(U32 item);
static BTHFResult bthf_save_setting(U32 item, void *value);
static BTHFResult bthf_reset_setting(U32 item);

static BTHFStatus bthf_get_status(bthf_device_struct *dev);

static BTHFResult bthf_add_req(bthf_inst_struct *inst, bthf_device_struct *dev, U32 req_id, U32 para);
static BTHFResult bthf_insert_req(bthf_inst_struct *inst, bthf_device_struct *dev, U32 req_id, U32 para);
static void bthf_check_req(bthf_list_struct *req_list);
static void bthf_req_done(bthf_request_struct *req, U32 retval);
static void bthf_abort_req(bthf_inst_struct *inst);

static void bthf_notify(bthf_inst_struct *inst, bthf_device_struct *dev, U32 evt, U32 param);
static void bthf_notify_all(bthf_device_struct *dev, U32 evt, U32 param);
static void bthf_send_msg(U32 msg, void *para1, U32 para2);

static bthf_inst_struct *bthf_new(void);
static void bthf_delete(bthf_inst_struct *inst);
static bthf_inst_struct *bthf_find(S32 handle);
static bthf_device_struct *bthf_new_dev(bthf_inst_struct *inst, BTHFAddr *addr, U32 prof, MMI_BOOL incoming);
static void bthf_del_dev(bthf_inst_struct *inst, bthf_device_struct *dev);
static bthf_device_struct *bthf_find_dev(U32 key, void *value);
static bthf_request_struct * bthf_new_req(bthf_inst_struct *inst, bthf_device_struct *dev, U32 req_id, U32 para);
static void bthf_del_req(bthf_request_struct *req);
static bthf_request_struct *bthf_find_req(bthf_list_struct *list, U32 req_id);
static MMI_BOOL bthf_serv_avail(void);
static MMI_BOOL in_list(bthf_list_struct *list, bthf_list_struct *node);
static U32 bthf_call_status_check(void);
static S32 bthf_helper_notify(BTHFHandle handle, U32 evt, U32 param);

#endif /* BTHF_SERVICE_H */
