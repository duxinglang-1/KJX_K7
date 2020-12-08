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
 * BtAudioSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to provide bluetooth audio related service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MmiDataType.h"
#include "UCMSrvGprot.h"
#include "BtAudioSrvGprot.h"

#ifdef __MMI_BT_SLIM__
#ifndef _MMI_BT_ULTRA_SLIM_
#define _MMI_BT_ULTRA_SLIM_
#endif 
#endif

#define NULL_CHNL       0
#define MONO_CHNL       1
#define STEREO_CHNL     2
#define DUAL_CHNL       3

#if defined(__MMI_HFP_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
#define AUD_CHNL_SUPPORT     DUAL_CHNL
#elif defined(__MMI_HFP_SUPPORT__)
#define AUD_CHNL_SUPPORT     MONO_CHNL
#elif defined(__MMI_A2DP_SUPPORT__)
#define AUD_CHNL_SUPPORT     STEREO_CHNL
#else
#define AUD_CHNL_SUPPORT   NULL_CHNL
#endif

enum {
    STATE_IDLE,
    STATE_DISCOVERY,
    STATE_CONNECT,
    STATE_CONNECT_ED,
    STATE_SWITCH_ON,
    STATE_AUDIO_ON,
    STATE_SWITCH_OFF,
    STATE_AUTHORIZE,
    STATE_NUM
};

enum {
    OP_DISCOVERY,
    OP_DEV_CONN,
    OP_AUDIO_ON,
    OP_AUDIO_OFF,
    OP_CONN_RSP,
    OP_NUM,
    SERVICE_IND,
    SERVICE_CNF,
    DEV_REQ_CONN,
    DEV_CONN_ED,
    DEV_CONN_FAIL,
    AUDIO_ON_ED,
    AUDIO_ON_FAIL,
    AUDIO_OFF_ED,
    AUDIO_OFF_FAIL,
    DEV_DISC_ED
};

enum {
    REQ_INIT = 0x01,
    REQ_START,
    REQ_DONE
};

enum {
    AUD_CHNL_ANY =   BTAUD_CHNL_ANY,
    AUD_CHNL_MONO =  BTAUD_CHNL_MONO,
    AUD_CHNL_STEREO = BTAUD_CHNL_STEREO,
    AUD_CHNL_ALL =   BTAUD_CHNL_ALL
};

enum {
    CHNL_HFP,
    CHNL_A2DP,
    MAX_CHANNEL_NUM
};

enum {
    FLAG_ABORT =        0x01,
    FLAG_HEADSET =      0x02,
    FLAG_HANDSFREE =    0x04,
    FLAG_DETACH =       0x08
};

enum {
    EV_ATTACH_IND =     BTAUD_EV_ATTACH_IND,
    EV_ATTACH_FAIL =    BTAUD_EV_ATTACH_FAIL,
    EV_DETACH_IND =     BTAUD_EV_DETACH_IND,
    EV_SWITCH_IND =     BTAUD_EV_SWITCH_IND,
    EV_SWITCH_FAIL =    BTAUD_EV_SWITCH_FAIL,
    EV_CHNL_UPDATE =    BTAUD_EV_CHNL_UPDATE,
    EV_ATTACH_REQ =     BTAUD_EV_ATTACH_REQ,
    EV_ATTACH_ABORT =   BTAUD_EV_ATTACH_ABORT,
    EV_VOLUME_IND =     BTAUD_EV_VOLUME_IND,
    EV_STEREO_CONFIG_IND = BTAUD_EV_STEREO_CONFIG_IND,
    EV_MAX_COUNT
};

#define MAX_INSTANCE_NUM    (6)
#define MAX_CHANNEL_NUM     (2)
#define MAX_OPTION_NUM      (2)
#define BTAUD_EVENT_ID      (1024+3)

typedef struct {
    BtAudOption item;
    U32 value;
} btaud_option;

typedef struct {
    U32 events;
    void *user_data;
    BtAudAccessLevel level;
    BtAudNotify notify;
    BtAudChannel sel_chnl;
    btaud_option options[MAX_OPTION_NUM];
    U32 alloc;
} btaud_instance;

typedef struct {
    btaud_instance *inst;
    U32 evt_id;
    U32 arg;
} btaud_notification;

typedef struct _btaud_chnl btaud_channel;
typedef struct _btaud_dev btaud_device;

typedef struct _btaud_input {
    U32 op_code;
    U32 arg;
    U32 status;
    U32 flags;
    btaud_instance *caller;
    btaud_channel *owner;
    struct _btaud_input *next;
} btaud_request;

typedef struct _btaud_chnl{
    U32 state;
    U32 type;
    U32 chnl_hd;
    U32 dev_id;
    U32 status;
    btaud_instance *inst;
    btaud_device *device;
    btaud_request *req_list;
} btaud_channel;

typedef struct _btaud_dev {
    BtAudDevAddr addr;
    BtAudStatus status;
    U32 active_chnl;
    U32 link_chnl;
    U32 flags;
    U32 service;
    btaud_channel *chnls[MAX_CHANNEL_NUM];
} btaud_device;

typedef S32 (*BtAudNotifyEx)(BtAudEvent event, U32 arg, void *user_data);
typedef MMI_BOOL (*ChnlStateHdlr)(btaud_channel *chnl, U32 op_code, void *args);

typedef struct {
    btaud_instance insts[MAX_INSTANCE_NUM];
    btaud_device device;
    btaud_channel chnls[MAX_CHANNEL_NUM];
    MMI_BOOL ongoing_call;
} btaud_cntx_struct;

static U8 btaud_service_hdlr(void *para, U32 src_mod, ilm_struct *ilm);
static void btaud_cm_notify_hdlr(U32 event, void *args);
static S32 btaud_hf_notify_hdlr(U32 handle, U32 event, U32 args);
MMI_RET btaud_ucm_notify_hdlr(srv_ucm_ind_evt_struct *ind);
MMI_RET btaud_speech_notify_hdlr(mmi_evt_mdi_audio_speech_ind_struct *ind);
static MMI_BOOL btaud_chnl_run(btaud_channel *chnl, U32 op_code, void* args);
static MMI_BOOL chnl_state_idle(btaud_channel *chnl, U32 op_code, void *arg);
static MMI_BOOL chnl_state_discovery(btaud_channel *chnl, U32 op_code, void *arg);
static MMI_BOOL chnl_state_conn(btaud_channel *chnl, U32 op_code, void *arg);
static MMI_BOOL chnl_state_conn_ed(btaud_channel *chnl, U32 op_code, void *arg);
static MMI_BOOL chnl_state_switch_on(btaud_channel *chnl, U32 op_code, void *arg);
static MMI_BOOL chnl_state_audio_on(btaud_channel *chnl, U32 op_code, void *arg);
static MMI_BOOL chnl_state_switch_off(btaud_channel *chnl, U32 op_code, void *arg);
static MMI_BOOL chnl_state_authorize(btaud_channel *chnl, U32 op_code, void *arg);
static btaud_instance *btaud_new(BtAudAccessLevel level);
static void btaud_delete(btaud_instance *inst);
static btaud_instance *btaud_find(U32 srv_hd);
static btaud_device *btaud_new_device(const BtAudDevAddr *addr);
static void btaud_delete_device(void);
static btaud_device *btaud_get_device(void);
static btaud_channel *btaud_new_chnl(btaud_instance *inst, const BtAudDevAddr *addr, U32 type);
static void btaud_delete_chnl(btaud_channel *chnl);
static void btaud_enable_chnl(U32 type);
static void btaud_disable_chnl(U32 type, MMI_BOOL passive);
static void btaud_call_begin(void);
static void btaud_call_end(void);
static btaud_channel *btaud_get_chnl(U32 type);
static void btaud_link_chnl(btaud_device *device, btaud_channel *chnl);
static void btaud_unlink_chnl(btaud_channel *chnl);
static btaud_request *btaud_new_req(
                        btaud_instance *inst,
                        btaud_channel *chnl,
                        U32 op_code, U32 arg);
static void btaud_delete_req(btaud_request **req_list, btaud_request *req);
static MMI_BOOL btaud_add_req(
                    btaud_instance *inst,
                    btaud_channel *chnl,
                    U32 op_code, U32 arg);
static MMI_BOOL btaud_check_req(btaud_channel *chnl);
static void btaud_abort_req(btaud_instance *inst, btaud_channel *chnl);
static void btaud_notify(btaud_instance *inst, U32 event, U32 arg);
static void btaud_notify_all(U32 event, U32 arg);
static mmi_ret btaud_event_proc(mmi_event_struct *evt);
static S32 btaud_send_notify(void);


