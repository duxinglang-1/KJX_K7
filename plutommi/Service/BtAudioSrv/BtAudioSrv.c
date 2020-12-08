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
 * BtAudioSrv.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"

#include "MmiDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_conn_app_trc.h"
#include "app_buff_alloc.h"
#include "mmi_include.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_mdi_def.h"
#include "UCMSrvGprot.h"
#include "BtcmSrvGprot.h"
#include "BthfSrvGprot.h"
#include "A2dpSrvGprot.h"
#include "BthScoPathSrvGprot.h"
#include "BtAudioSrvGprot.h"
#include "BtAudioSrv.h"

#ifdef __MMI_BT_SUPPORT__

#define ValidInstance(inst)		\
        ((inst != NULL) && \
        (((U8 *)inst-(U8 *)cntx->insts)/sizeof(*inst) < MAX_INSTANCE_NUM) && \
        (((U8 *)inst-(U8 *)cntx->insts)%sizeof(*inst) == 0))

#define SameDevice(d1, d2)       \
        ((d1)->lap == (d2)->lap && \
         (d1)->uap == (d2)->uap && \
         (d1)->nap == (d2)->nap)

#define ValidDevice(d) \
        ((d)->lap || (d)->uap || (d)->nap)

static btaud_cntx_struct g_btaud_cntx;
static btaud_cntx_struct *cntx = &g_btaud_cntx;
#define BT_AUDIO_REJECT   0
#define BT_AUDIO_ACCEPT  1
static ChnlStateHdlr state_hdlr[STATE_NUM] = {
    chnl_state_idle,
    chnl_state_discovery,
    chnl_state_conn,
    chnl_state_conn_ed,
    chnl_state_switch_on,
    chnl_state_audio_on,
    chnl_state_switch_off,
    chnl_state_authorize
};


void srv_btaud_init(void)
{
    U32 i;
    
    U32 cm_evt = SRV_BT_CM_EVENT_CONNECT_RES |
                 SRV_BT_CM_EVENT_DISCONNECT_IND |
                 SRV_BT_CM_EVENT_SCO_IND;

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    U32 hf_evt = BTHF_EV_ATTACH |
                 BTHF_EV_DETACH |
                 BTHF_EV_REQ_ATTACH |
                 BTHF_EV_REQ_ABORT |
                 BTHF_EV_REQ_RESULT |
                 BTHF_EV_VOL_CHANGE;

    srv_bthf_init();
#endif

#if (AUD_CHNL_SUPPORT == DUAL_CHNL)
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND, 
        (PsIntFuncPtr)btaud_service_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BM_SERVICE_SEARCH_CNF,
        (PsIntFuncPtr)btaud_service_hdlr, MMI_TRUE);
#endif

    srv_bt_cm_set_notify(btaud_cm_notify_hdlr, cm_evt, NULL);

    for (i = 0; i < MAX_CHANNEL_NUM; i++)
        cntx->chnls[i].state = STATE_IDLE;

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    cntx->chnls[CHNL_HFP].type = AUD_CHNL_MONO;
    cntx->chnls[CHNL_HFP].chnl_hd = srv_bthf_open();
    srv_bthf_set_notify(cntx->chnls[CHNL_HFP].chnl_hd, btaud_hf_notify_hdlr, hf_evt, BTHF_MOP_NEW);
#endif

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)    
    cntx->chnls[CHNL_A2DP].type = AUD_CHNL_STEREO;
#endif
}

void srv_btaud_deinit()
{
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    srv_bthf_deinit();
#endif
    btaud_delete_device();
}

U32 srv_btaud_open(BtAudAccessLevel level, BtAudChannel chnl)
{
    btaud_instance *inst = btaud_new(level);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_OPEN, inst, level, chnl);

    if (inst)
    {
        if (level == BTAUD_LEVEL_ADMIN || chnl == BTAUD_CHNL_ALL)
            inst->sel_chnl = AUD_CHNL_ANY;
        else
            inst->sel_chnl = chnl;
    }

    return (U32)inst;
}

void srv_btaud_set_notify(U32 srv_hd, U32 events, BtAudNotify notify, void *user_data)
{
    btaud_instance *inst = btaud_find(srv_hd);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_SET_NOTIFY, inst, events, notify);
    
    if (!inst)
        return;

    inst->events = events;
    inst->notify = notify;
    inst->user_data = user_data;
}

void srv_btaud_close(U32 srv_hd)
{
    btaud_instance *inst = btaud_find(srv_hd);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_CLOSE, inst);

    if (!inst)
        return;

    btaud_delete(inst);
}

void srv_btaud_set_option(U32 srv_hd, BtAudOption item, U32 value)
{
    btaud_instance *inst = btaud_find(srv_hd);
    U32 i;

    if (!inst) return;

    for (i = 0; i < MAX_OPTION_NUM; i++)
    {
        if (item == inst->options[i].item)
        {
            inst->options[i].value = value;
            break;
        }
    }
}

U32 srv_btaud_get_option(U32 srv_hd, BtAudOption option)
{
    btaud_instance *inst = btaud_find(srv_hd);
    U32 i, value = 0;

    if (!inst) return 0;

    for (i = 0; i < MAX_OPTION_NUM; i++)
    {
        if (option == inst->options[i].item)
        {
            value = inst->options[i].value;
            break;
        }
    }

    return value;
}

MMI_BOOL srv_btaud_attach(U32 srv_hd, const BtAudDevAddr *addr)
{
    btaud_channel *chnl;
    btaud_instance *inst = btaud_find(srv_hd);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_ATTACH, inst, cntx->device.status);
    
    if (!inst || inst->level != BTAUD_LEVEL_ADMIN)
        return MMI_FALSE;

    if (inst->sel_chnl == AUD_CHNL_ANY)
        chnl = btaud_new_chnl(inst, addr, AUD_CHNL_MONO);
    else
        chnl = btaud_new_chnl(inst, addr, inst->sel_chnl);

    if (!chnl)
        return MMI_FALSE;

#if (AUD_CHNL_SUPPORT == DUAL_CHNL)
    if (inst->sel_chnl == AUD_CHNL_ANY)
        return btaud_add_req(inst, chnl, OP_DISCOVERY, 0);
    else
#endif
        return btaud_add_req(inst, chnl, OP_DEV_CONN, 0);
}

void srv_btaud_detach(U32 srv_hd)
{
    btaud_device *device;
    btaud_channel *chnl;
    btaud_instance *inst = btaud_find(srv_hd);
	device = btaud_get_device();
    if (!device)
        return;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_DETACH, inst, device->active_chnl);

    if (!inst || inst->level != BTAUD_LEVEL_ADMIN)
        return;

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    chnl = btaud_get_chnl(AUD_CHNL_MONO);
    if (chnl)
    {
        srv_bthf_detach(chnl->chnl_hd, chnl->dev_id);
    }
#endif
#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
	chnl = btaud_get_chnl(AUD_CHNL_STEREO);
    if (chnl)
    {
        srv_bt_cm_release_profile(&device->addr, SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID);
        srv_bt_cm_release_profile(&device->addr, SRV_BT_CM_AV_REMOTE_CONTROL_UUID);
    }
#endif

    device->flags |= FLAG_DETACH;
}

MMI_BOOL srv_btaud_switch(U32 srv_hd, MMI_BOOL on)
{
    btaud_instance *inst = btaud_find(srv_hd);
    btaud_device *device = btaud_get_device();
    btaud_channel *chnl;
    MMI_BOOL result = MMI_FALSE;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_SWITCH, inst, on, device->active_chnl);

    if (!inst)
        return MMI_FALSE;

    /* Currently not support A2DP streaming switching */
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    chnl = btaud_get_chnl(AUD_CHNL_MONO);
    if (!chnl)
        return MMI_FALSE;

    if (on)
    {
        result = btaud_add_req(inst, chnl, OP_AUDIO_ON, 0);
    }
    else
    {
        result = btaud_add_req(inst, chnl, OP_AUDIO_OFF, 0);
    }
#endif

    return result;
}

static void srv_btaud_req_hdler(U32 srv_hd,U32 arg)
{
    btaud_instance *inst = btaud_find(srv_hd);
    btaud_device *device = btaud_get_device();
    btaud_channel *chnl;
	chnl = btaud_get_chnl(AUD_CHNL_MONO);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_ACCEPT, inst, device->link_chnl);
    
    if (!inst)
        return;

    if (!chnl)
        return;
    
    btaud_add_req(inst, chnl, OP_CONN_RSP, arg);

}
void srv_btaud_accept(U32 srv_hd)
{

	srv_btaud_req_hdler(srv_hd,BT_AUDIO_ACCEPT);
}

void srv_btaud_reject(U32 srv_hd)
{
	srv_btaud_req_hdler(srv_hd,BT_AUDIO_REJECT);

}

void srv_btaud_set_volume(U32 volume)
{
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    btaud_device *device = btaud_get_device();

    if (!device) return;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_SET_VOLUME, volume, device->active_chnl);

    if (device->active_chnl & BTAUD_CHNL_MONO)
    {
        btaud_channel *chnl = btaud_get_chnl(BTAUD_CHNL_MONO);

        srv_bthf_change_volume(chnl->chnl_hd, chnl->dev_id, (U8)volume);
    }
#endif
}

void srv_btaud_abort(U32 srv_hd)
{
    btaud_instance *inst = btaud_find(srv_hd);
    btaud_device *device = btaud_get_device();
    btaud_channel *chnl;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_ABORT, inst, device->link_chnl);
    
    if (!inst)
        return;

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
     chnl = btaud_get_chnl(AUD_CHNL_MONO);
    if (chnl)
        btaud_abort_req(inst, chnl);
#endif

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
	chnl = btaud_get_chnl(AUD_CHNL_STEREO);
    if (chnl)
        btaud_abort_req(inst, chnl);
#endif
}

MMI_BOOL srv_btaud_get_device_info(BtAudChannel chnl, btaud_device_info *info)
{
    btaud_device *device = btaud_get_device();

    if (!device)
        return MMI_FALSE;

    if (chnl != AUD_CHNL_ANY &&
        !(device->link_chnl & chnl))
        return MMI_FALSE;

    if (info)
    {
        info->addr = device->addr;
        info->chnls = device->link_chnl;
    }

    return MMI_TRUE;
}

MMI_BOOL srv_btaud_is_audio_device(const BtAudDevAddr *dev_addr)
{
    U32 cod = srv_bt_cm_get_dev_cod((BtAudDevAddr *)dev_addr);

    if (cod & SRV_BT_AUDIO_MAJOR_SERVICE_MASK)
        return MMI_TRUE;

    return MMI_FALSE;
}

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)    
MMI_BOOL srv_btaud_stereo_notify(const BtAudDevAddr *addr)
{
    btaud_device *device = &cntx->device;

    if (device->link_chnl & AUD_CHNL_STEREO)
    {
        if (btaud_send_notify())
            return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif

#if (AUD_CHNL_SUPPORT == DUAL_CHNL)
static U8 btaud_service_hdlr(void *para, U32 src_mod, ilm_struct *ilm)
{
    MMI_BOOL result = MMI_FALSE;
    btaud_channel *chnl = btaud_get_chnl(AUD_CHNL_MONO);

    if (!chnl)
        return 0;
    
    switch (ilm->msg_id) {
    case MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND:
        
        result = btaud_chnl_run(chnl, SERVICE_IND, para);

        break;

    case MSG_ID_BT_BM_SERVICE_SEARCH_CNF:
        
        result = btaud_chnl_run(chnl, SERVICE_CNF, para);
        
        break;

    default:
        break;
    }

    return result ? 1:0;
}
#endif

static void btaud_cm_notify_hdlr(U32 event, void *args)
{
    btaud_device *device = btaud_get_device();
    btaud_channel *chnl = NULL;
    U32 in = 0;
    
    switch (event) {
#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    case SRV_BT_CM_EVENT_CONNECT_RES:
        {
            srv_bt_cm_conn_res_struct *ind = 
                (srv_bt_cm_conn_res_struct *)args;
	    
            if (ind->profile_id != SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
                break;
            chnl = btaud_new_chnl(NULL, ind->dev_addr, AUD_CHNL_STEREO);
            if ((device && (device->flags & FLAG_DETACH)) || (!chnl) ) 
            {
                srv_bt_cm_release_profile(ind->dev_addr, ind->profile_id);
                break;
            }

            in = DEV_CONN_ED;
        }
        break;

    case SRV_BT_CM_EVENT_DISCONNECT_IND:
        {
            srv_bt_cm_disconnect_ind_struct *ind = 
                (srv_bt_cm_disconnect_ind_struct *)args;

            if (ind->profile_id != SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
                break;

            chnl = btaud_get_chnl(AUD_CHNL_STEREO);
            in = DEV_DISC_ED;
        }
        break;
#endif
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    case SRV_BT_CM_EVENT_SCO_IND:
        {
            srv_bt_cm_sco_ind_struct *ind = 
                (srv_bt_cm_sco_ind_struct *)args;

            chnl = btaud_get_chnl(AUD_CHNL_MONO);
            in = ind->result ? AUDIO_ON_ED : AUDIO_OFF_ED;
        }

        break;
#endif

    default:
        return;
    }

    btaud_chnl_run(chnl, in, args);
}


static S32 btaud_hf_notify_hdlr(U32 handle, U32 event, U32 args)
{
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    btaud_device *device = btaud_get_device();
    btaud_channel *chnl = btaud_get_chnl(AUD_CHNL_MONO);
    bthf_dev_info_struct info;
    U32 in = 0;

    switch (event) {
    case BTHF_EV_ATTACH:
        
        in = DEV_CONN_ED;

        break;
        
    case BTHF_EV_DETACH:

        in = DEV_DISC_ED;

        break;
        
    case BTHF_EV_REQ_ATTACH:
        
        srv_bthf_get_device_info(args, &info);
		chnl = btaud_new_chnl(NULL, &info.addr, AUD_CHNL_MONO);
        if ((device && (device->flags & FLAG_DETACH)) ||(!chnl))
        {
            srv_bthf_reject(handle, args);
            return 0;
        }

        chnl->dev_id = args;
        in = DEV_REQ_CONN;

        break;

    case BTHF_EV_REQ_ABORT:

        in = DEV_DISC_ED;

        break;

    case BTHF_EV_REQ_RESULT:

        switch (args & 0xFFFF) {
        case BTHF_REQ_ATTACH:
        case BTHF_REQ_ACCEPT:
            if ((args >> 16 & 0xFFFF) != BTHF_E_NONE)
                in = DEV_CONN_FAIL;
            break;
        
        case BTHF_REQ_DETACH:
            if ((args >> 16 & 0xFFFF) != BTHF_E_NONE)
                in = DEV_DISC_ED;
            break;

        default:
            break;
        }

        break;

    case BTHF_EV_VOL_CHANGE:

        btaud_notify_all(EV_VOLUME_IND, ((args >> 16) & 0xffff));

        return 0;

    default:
        return 0;
    }

    if (in)
        btaud_chnl_run(chnl, in, (void *)args);
#endif

    return 0;
}


MMI_RET btaud_ucm_notify_hdlr(srv_ucm_ind_evt_struct *ind)
{
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    btaud_channel *chnl = btaud_get_chnl(BTAUD_CHNL_MONO);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_UCM_IND, ind->ind_type, chnl);

    switch (ind->ind_type) {
    case SRV_UCM_INCOMING_CALL_IND:

        #ifdef __MMI_BT_AUDIO_VIA_SCO__
        if (!srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
            btaud_call_begin();
        #endif

        break;

    case SRV_UCM_OUTGOING_CALL_IND:

        btaud_call_begin();
        
        break;

    case SRV_UCM_RELEASE_IND:

        if (!srv_ucm_is_any_call())
            btaud_call_end();

        break;
    }
#endif

    return MMI_RET_OK;
}

MMI_RET btaud_speech_notify_hdlr(mmi_evt_mdi_audio_speech_ind_struct *ind)
{
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    btaud_channel *chnl = btaud_get_chnl(BTAUD_CHNL_MONO);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_SPEECH_IND, ind->status, chnl);

    if (ind->status == MDI_AUDIO_SPH_POST_SPEECH_ON && srv_ucm_is_any_call())
    {
        #ifdef __MMI_BT_AUDIO_VIA_SCO__
        if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
        #endif
            btaud_call_begin();
    }
#endif

    return MMI_RET_OK;
}

static MMI_BOOL btaud_chnl_run(btaud_channel *chnl, U32 op_code, void* args)
{
    btaud_request *req = chnl->req_list;
    MMI_BOOL result = MMI_FALSE;

    while (chnl)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_FSM_BEGIN, chnl->type, chnl->state, op_code);

        if (op_code < OP_NUM)
            req->status = REQ_START;

        result = state_hdlr[chnl->state](chnl, op_code, args);

        if (!result && op_code < OP_NUM)
            req->status = REQ_DONE;

        MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_FSM_END, chnl->type, chnl->state);

        if (!btaud_check_req(chnl))
            break;
        
        op_code = chnl->req_list->op_code;
        req = chnl->req_list;
    }

    return result;
}

static MMI_BOOL chnl_state_idle(btaud_channel *chnl, U32 op_code, void *arg)
{
    btaud_request *req = (btaud_request *)arg;
    MMI_BOOL result = MMI_TRUE;

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    if (chnl->type == AUD_CHNL_STEREO)
    {
        switch (op_code) {
        case OP_DEV_CONN:

            srv_bt_a2dp_connect_req(chnl->device->addr);
            chnl->state = STATE_CONNECT;

            break;
            
        case DEV_CONN_ED:

            btaud_enable_chnl(chnl->type);

            break;

        default:
            result = MMI_FALSE;
            break;
        }
    }
#endif

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    if (chnl->type == AUD_CHNL_MONO)
    {
        switch (op_code) {
        case OP_DISCOVERY:
            {
                bt_bm_service_search_req_struct *req = construct_local_para(sizeof(*req), TD_CTRL);
                req->bd_addr = *((btbm_bd_addr_t *)&(chnl->device->addr));

                /* Only search for audio related service */
                req->sdap_uuid[0] = SRV_BT_CM_HF_PROFILE_UUID;
                req->sdap_uuid[1] = SRV_BT_CM_HS_PROFILE_UUID;
                req->sdap_uuid[2] = SRV_BT_CM_AUDIO_SINK_UUID;
                req->sdap_len = 3;

                msg_send5(MOD_MMI, MOD_BT, BT_APP_SAP, 
                    MSG_ID_BT_BM_SERVICE_SEARCH_REQ, (local_para_struct *)req);

                chnl->state = STATE_DISCOVERY;
            }
            break;

        case OP_DEV_CONN:

            chnl->dev_id = srv_bthf_attach(chnl->chnl_hd, &chnl->device->addr);
            if (!chnl->dev_id)
                return MMI_FALSE;

            chnl->state = STATE_CONNECT;

            break;

        case OP_AUDIO_ON:
            
            result = MMI_FALSE;

            break;

        case OP_AUDIO_OFF:
            
            req->status = REQ_DONE;
            btaud_notify(req->caller, EV_SWITCH_IND, 0);

            break;

        case DEV_REQ_CONN:

            chnl->state = STATE_AUTHORIZE;
            if (chnl->device->link_chnl & AUD_CHNL_STEREO)
            {
                srv_bthf_accept(chnl->chnl_hd, chnl->dev_id);
            }
            else
            {
                btaud_notify_all(EV_ATTACH_REQ, 0);
            }

            break;

        case OP_CONN_RSP:
            result = MMI_FALSE;
            break;
        }
    }
#endif

    return result;
}

static MMI_BOOL chnl_state_discovery(btaud_channel *chnl, U32 op_code, void *arg)
{
    MMI_BOOL result = MMI_TRUE;
    
#if (AUD_CHNL_SUPPORT == DUAL_CHNL)
    bt_bm_service_search_result_ind_struct *ind = (bt_bm_service_search_result_ind_struct *)arg;
    btaud_device *device = chnl->device;

    if (chnl->type == AUD_CHNL_STEREO)
        return MMI_FALSE;

    switch (op_code) {
    case SERVICE_IND:

        if (ind->uuid == SRV_BT_CM_HF_PROFILE_UUID)
        {
            device->service |= AUD_CHNL_MONO;
            device->flags |= FLAG_HANDSFREE;
        }
        else if (ind->uuid == SRV_BT_CM_HS_PROFILE_UUID)
        {
            device->service |= AUD_CHNL_MONO;
            device->flags |= FLAG_HEADSET;
        }
        else if (ind->uuid == SRV_BT_CM_AUDIO_SINK_UUID)
        {
            device->service |= AUD_CHNL_STEREO;
        }

        break;

    case SERVICE_CNF:

        if (chnl->req_list && chnl->req_list->op_code == OP_DISCOVERY)
        {
            btaud_request *req = chnl->req_list;
            if ((req->flags & FLAG_ABORT) || !device->service)
            {
                req->status = REQ_DONE;
                btaud_notify(chnl->req_list->caller, EV_ATTACH_FAIL, 0);
                btaud_disable_chnl(chnl->type, MMI_TRUE);
            }
            else
            {
                U32 prof;
                if (device->service & AUD_CHNL_MONO)
                {
                    req->op_code = OP_DEV_CONN;

                    if (device->flags & FLAG_HANDSFREE)
                        prof = BTHF_PROF_HF;
                    else
                        prof = BTHF_PROF_HS;
                    
                    srv_bthf_config(chnl->chnl_hd, BTHF_CFG_PROFILE, &prof);
                    chnl->dev_id = srv_bthf_attach(chnl->chnl_hd, &device->addr);
                    chnl->state = STATE_CONNECT;
                }
                else
                {
                    btaud_channel *ch = btaud_new_chnl(chnl->inst, &device->addr, AUD_CHNL_STEREO);
                    if (ch)
                    {
                        btaud_add_req(ch->inst, ch, OP_DEV_CONN, 0);
                    }
                    btaud_disable_chnl(chnl->type, MMI_TRUE);
                }
            }
        }

        break;

    default:

        result = MMI_FALSE;

        break;
    }
#endif

    return result;
}


static MMI_BOOL chnl_state_conn(btaud_channel *chnl, U32 op_code, void *arg)
{
    MMI_BOOL result = MMI_FALSE;
#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    btaud_device *device = chnl->device;
#endif

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    if (chnl->type == AUD_CHNL_STEREO)
    {
        switch (op_code) {
        case DEV_CONN_ED:
        
            if (chnl->req_list && chnl->req_list->op_code == OP_DEV_CONN)
            {
                if (chnl->req_list->flags & FLAG_ABORT)
                {
                    srv_bt_cm_release_profile(&device->addr, SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID);
                    break;
                }
                    
                chnl->req_list->status = REQ_DONE;
            }

            btaud_enable_chnl(chnl->type);
        
            break;

        /* Actually currently no CONN_FAIL event can be generated, just for future extention */
        case DEV_CONN_FAIL:
        case DEV_DISC_ED:

            if (chnl->req_list && chnl->req_list->op_code == OP_DEV_CONN)
            {
                btaud_notify(chnl->req_list->caller, EV_ATTACH_FAIL, 0);
                chnl->req_list->status = REQ_DONE;
            }

            btaud_disable_chnl(chnl->type, MMI_TRUE);

            break;
        }

        return result;
    }
#endif

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    switch (op_code) {
    case DEV_CONN_ED:

        if (chnl->req_list && chnl->req_list->op_code == OP_DEV_CONN)
        {
            chnl->req_list->status = REQ_DONE;
        }
#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
        if (device->link_chnl & AUD_CHNL_STEREO)
        {
            U32 dev_id = (U32)arg;
            bthf_dev_info_struct info;
            srv_bthf_get_device_info(dev_id, &info);
            
            if (!SameDevice(&device->addr, &info.addr))
            {
                btaud_channel *s_chnl = btaud_get_chnl(AUD_CHNL_STEREO);
                srv_bt_cm_release_profile(
                    &device->addr, SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID);
                device->addr = info.addr;
            }
        }
#endif

        btaud_enable_chnl(chnl->type);

        break;

    case DEV_CONN_FAIL:
    case DEV_DISC_ED:        
        {
            if (chnl->req_list && chnl->req_list->op_code == OP_DEV_CONN)
            {
                btaud_notify(chnl->req_list->caller, EV_ATTACH_FAIL, 0);
                chnl->req_list->status = REQ_DONE;
            }

            btaud_disable_chnl(chnl->type, MMI_TRUE);
        }
        break;
    }
#endif

    return result;
}

static MMI_BOOL chnl_state_conn_ed(btaud_channel *chnl, U32 op_code, void *arg)
{
    btaud_request *req = (btaud_request *)arg;
    btaud_device *device = chnl->device;
    MMI_BOOL result = MMI_TRUE;
    
#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    if (chnl->type == AUD_CHNL_STEREO)
    {
        switch (op_code) {
        case DEV_DISC_ED:
        {
            srv_bt_cm_disconnect_ind_struct *ind = (srv_bt_cm_disconnect_ind_struct *)arg;
            if (ind->passive)
                btaud_disable_chnl(chnl->type, MMI_TRUE);
            else
                btaud_disable_chnl(chnl->type, MMI_FALSE);
        }

            break;

        default:
            result = MMI_FALSE;
            break;
        }
    }
#endif

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    if (chnl->type == AUD_CHNL_MONO)
    {
        switch (op_code) {
        case OP_DEV_CONN:

            req->status = REQ_DONE;
            btaud_notify(req->caller, EV_ATTACH_IND, 0);

            break;
            
        case OP_AUDIO_ON:

            if (!srv_btsco_open_stream_req())
            {
                result = MMI_FALSE;
                break;
            }
            
            chnl->state = STATE_SWITCH_ON;

            break;

        case OP_AUDIO_OFF:
            
            req->status = REQ_DONE;
            btaud_notify(req->caller, EV_SWITCH_IND, 0);

            break;

        case AUDIO_ON_ED:

            chnl->state = STATE_AUDIO_ON;
            chnl->status = BTAUD_SWITCH_ON;
            device->status = BTAUD_SWITCH_ON;

            btaud_notify_all(EV_SWITCH_IND, 1);

            break;
            
        case DEV_DISC_ED:

            if (((U32)arg) == chnl->dev_id)
                btaud_disable_chnl(chnl->type, MMI_FALSE);
            else
                btaud_disable_chnl(chnl->type, MMI_TRUE);

            break;

        default:
            result = MMI_FALSE;
            break;
        }
    }
#endif

    return result;
}

static MMI_BOOL chnl_state_switch_on(btaud_channel *chnl, U32 op_code, void *arg)
{
    btaud_device *device = chnl->device;
    MMI_BOOL result = MMI_TRUE;
    
#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    if (chnl->type == AUD_CHNL_STEREO)
        return MMI_FALSE;
#endif

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    switch (op_code) {
    case AUDIO_ON_ED:

        if (chnl->req_list && chnl->req_list->op_code == OP_AUDIO_ON)
        {
            chnl->req_list->status = REQ_DONE;
        }

        chnl->state = STATE_AUDIO_ON;
        chnl->status = BTAUD_SWITCH_ON;
        device->status = BTAUD_SWITCH_ON;

        btaud_notify_all(EV_SWITCH_IND, 1);

        break;
        
    case AUDIO_ON_FAIL:
    case AUDIO_OFF_ED:

        if (chnl->req_list && chnl->req_list->op_code == OP_AUDIO_ON)
        {
            chnl->req_list->status = REQ_DONE;
            btaud_notify(chnl->req_list->caller, EV_SWITCH_FAIL, 0);
        }
        chnl->state = STATE_CONNECT_ED;

        break;
        
    case DEV_DISC_ED:

        if (chnl->req_list && chnl->req_list->op_code == OP_AUDIO_ON)
        {
            chnl->req_list->status = REQ_DONE;
            btaud_notify(chnl->req_list->caller, EV_SWITCH_FAIL, 0);
        }

        if (((U32)arg) == chnl->dev_id)
            btaud_disable_chnl(chnl->type, MMI_FALSE);
        else
            btaud_disable_chnl(chnl->type, MMI_TRUE);
        
        break;

    default:
        result = MMI_FALSE;
        break;
    }
#endif

    return result;
}

static MMI_BOOL chnl_state_audio_on(btaud_channel *chnl, U32 op_code, void *arg)
{
    btaud_request *req = (btaud_request *)arg;
    btaud_device *device = chnl->device;
    MMI_BOOL result = MMI_TRUE;

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    if (chnl->type == AUD_CHNL_STEREO)
    {
        return MMI_FALSE;
    }
#endif

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    switch (op_code) {
    case OP_DEV_CONN:

        req->status = REQ_DONE;
        btaud_notify(req->caller, EV_ATTACH_IND, 0);

        break;
        
    case OP_AUDIO_ON:

        req->status = REQ_DONE;
        btaud_notify(req->caller, EV_SWITCH_IND, 1);

        break;

    case OP_AUDIO_OFF:

        srv_btsco_close_stream_req();
        chnl->state = STATE_SWITCH_OFF;

        break;
    
    case AUDIO_OFF_ED:

        chnl->state = STATE_CONNECT_ED;
        chnl->status = BTAUD_ACTIVE;
        device->status = BTAUD_ACTIVE;

        btaud_notify_all(EV_SWITCH_IND, 0);

        break;

    case DEV_DISC_ED:
    
        btaud_notify_all(EV_SWITCH_IND, 0);
        if (((U32)arg) == chnl->dev_id)
            btaud_disable_chnl(chnl->type, MMI_FALSE);
        else
            btaud_disable_chnl(chnl->type, MMI_TRUE);
       
        break;

    default:
        result = MMI_FALSE;
        break;
    }
#endif

    return result;
}

static MMI_BOOL chnl_state_switch_off(btaud_channel *chnl, U32 op_code, void *arg)
{
    btaud_device *device = chnl->device;
    MMI_BOOL result = MMI_TRUE;

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)
    if (chnl->type == AUD_CHNL_STEREO)
        return MMI_FALSE;
#endif

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    switch (op_code) {
    case AUDIO_OFF_ED:

        if (chnl->req_list && chnl->req_list->op_code == OP_AUDIO_OFF)
        {
            chnl->req_list->status = REQ_DONE;
        }

        chnl->state = STATE_CONNECT_ED;
        chnl->status = BTAUD_ACTIVE;
        device->status = BTAUD_ACTIVE;

        btaud_notify_all(EV_SWITCH_IND, 0);

        break;

    case AUDIO_OFF_FAIL:

        if (chnl->req_list && chnl->req_list->op_code == OP_AUDIO_OFF)
        {
            chnl->req_list->status = REQ_DONE;
            btaud_notify(chnl->req_list->caller, EV_SWITCH_FAIL, 1);
        }
        chnl->state = STATE_AUDIO_ON;

        break;
        
    case DEV_DISC_ED:

        if (chnl->req_list && chnl->req_list->op_code == OP_AUDIO_OFF)
        {
            chnl->req_list->status = REQ_DONE;
        }

        btaud_notify_all(EV_SWITCH_IND, 0);
        if (((U32)arg) == chnl->dev_id)
            btaud_disable_chnl(chnl->type, MMI_FALSE);
        else
            btaud_disable_chnl(chnl->type, MMI_TRUE);
        
        break;

    default:
        result = MMI_FALSE;
        break;
    }
#endif

    return result;
}

static MMI_BOOL chnl_state_authorize(btaud_channel *chnl, U32 op_code, void *arg)
{
    btaud_request *req = (btaud_request *)arg;
    MMI_BOOL result = MMI_TRUE;

#if (AUD_CHNL_SUPPORT & STEREO_CHNL)    
    if (chnl->type == AUD_CHNL_STEREO)
        return MMI_FALSE;
#endif

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
    switch (op_code) {
    case OP_CONN_RSP:
        {
            U32 accept = req->arg;

            if (accept)
                srv_bthf_accept(chnl->chnl_hd, chnl->dev_id);
            else
                srv_bthf_reject(chnl->chnl_hd, chnl->dev_id);

            req->status = REQ_DONE;
        }
        break;

    case DEV_CONN_ED:

        btaud_enable_chnl(chnl->type);

        break;
        
    case DEV_CONN_FAIL:
    case DEV_DISC_ED:

        btaud_notify_all(EV_ATTACH_ABORT, 0);
        btaud_disable_chnl(chnl->type, MMI_TRUE);
        
        break;

    default:

        result = MMI_FALSE;

        break;
    }
#endif

    return result;
}


static btaud_instance *btaud_new(BtAudAccessLevel level)
{
    U32 i;
    btaud_instance *inst = NULL;

    for (i = 0; i < MAX_INSTANCE_NUM; i++)
    {
        if (level == BTAUD_LEVEL_ADMIN && 
            level == cntx->insts[i].level &&
            cntx->insts[i].alloc)
        {
            inst = NULL;
            break;
        }
        
        if (!cntx->insts[i].alloc && !inst)
            inst = &cntx->insts[i];
    }

    if (inst) 
    {
        inst->level = level;
        inst->alloc = MMI_TRUE;
    }

    return inst;
}

static void btaud_delete(btaud_instance *inst)
{
    btaud_channel *chnl;
    btaud_request *req;
	
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
	chnl = btaud_get_chnl(AUD_CHNL_MONO);
    if (chnl)
    {
        btaud_abort_req(inst, chnl);
        for (req = chnl->req_list; req; req = req->next)
        {
            if (req->caller == inst)
                req->caller = NULL;
        }
    }
#endif
#if (AUD_CHNL_SUPPORT & STEREO_CHNL) 
	chnl = btaud_get_chnl(AUD_CHNL_STEREO);
    if (chnl)
    {
        btaud_abort_req(inst, chnl);
        for (req = chnl->req_list; req; req = req->next)
        {
            if (req->caller == inst)
                req->caller = NULL;
        }
    }
#endif
    inst->alloc = MMI_FALSE;
	memset(inst,0,sizeof(inst));
}

static btaud_instance *btaud_find(U32 srv_hd)
{
    btaud_instance *inst = (btaud_instance *)srv_hd;
    
    if (!ValidInstance(inst))
        return NULL;

    return inst;
}

static btaud_device *btaud_new_device(const BtAudDevAddr *addr)
{
    btaud_device *device = &cntx->device;

    if (ValidDevice(&device->addr))
        return device;

    memset(device, 0, sizeof(*device));
    
    device->addr = *addr;

    return device;
}

static void btaud_delete_device(void)
{
    btaud_device * device = btaud_get_device();
    
    if (!device) return;

    memset(&device->addr, 0, sizeof(device->addr));
    device->status = BTAUD_IDLE;
}

static btaud_device *btaud_get_device(void)
{
    if (!ValidDevice(&(cntx->device.addr)))
        return NULL;

    return &cntx->device;
}

static btaud_channel *btaud_new_chnl(btaud_instance *inst, const BtAudDevAddr *addr, U32 type)
{
    btaud_channel *chnl, *t_chnl;
    btaud_device * device = btaud_get_device();

    if (device && !SameDevice(&device->addr, addr))
    {
        return NULL;
    }
    t_chnl = btaud_get_chnl(type);
    if (type == AUD_CHNL_MONO)
        chnl = &cntx->chnls[CHNL_HFP];
    else
        chnl = &cntx->chnls[CHNL_A2DP];

    if (!device)
        device = btaud_new_device(addr);

    /* For incoming connection we share existing channel of same device */
    if (t_chnl)
        return inst ? NULL : t_chnl;

    chnl->type = type;
    chnl->inst = inst;
    btaud_link_chnl(device, chnl);

    return chnl;
}

static void btaud_delete_chnl(btaud_channel *chnl)
{
    btaud_device *device = chnl->device;

    btaud_delete_req(&chnl->req_list, NULL);
    
    chnl->state = STATE_IDLE;
    chnl->status = BTAUD_IDLE;
    chnl->inst = NULL;

    btaud_unlink_chnl(chnl);

    if (!device->link_chnl)
        btaud_delete_device();
}

static void btaud_enable_chnl(U32 type)
{
    btaud_device *device = btaud_get_device();
    btaud_channel *chnl;
    U32 active_chnl = device->active_chnl;

    if (!device || !(device->link_chnl & type))
        return;

    chnl = btaud_get_chnl(type);

    chnl->state = STATE_CONNECT_ED;
    chnl->status = BTAUD_ACTIVE;

    if (!device->active_chnl)
    {
        device->status = BTAUD_ACTIVE;
        btaud_notify_all(EV_ATTACH_IND, type);
    }
    else
    {
        btaud_notify_all(EV_CHNL_UPDATE, device->active_chnl | type);
    }

    device->active_chnl |= type;

#ifdef __MMI_BT_AUDIO_SUPPORT__
    if (type == BTAUD_CHNL_MONO && !(active_chnl & type))
    {
        if (!(device->link_chnl & BTAUD_CHNL_STEREO))
        {
            if (btaud_send_notify())
                return;
        }
        srv_prof_bt_connected_hdlr(SRV_PROF_BT_HFP_ACL, SRV_PROF_BT_IND);
    }
#endif
}

static void btaud_disable_chnl(U32 type, MMI_BOOL passive)
{
    btaud_device *device = btaud_get_device();
    U32 active_chnl;

    if (!device || !(device->link_chnl & type))
        return;

    active_chnl = device->active_chnl;
    
    device->active_chnl &= ~type;

    btaud_delete_chnl(btaud_get_chnl(type));

    if (device->active_chnl)
        btaud_notify_all(EV_CHNL_UPDATE, device->active_chnl);
    else if (active_chnl)
    {
        if (passive)
            btaud_notify_all(EV_DETACH_IND, 1);
        else
            btaud_notify_all(EV_DETACH_IND, 0);
    }
    
#ifdef __MMI_BT_AUDIO_SUPPORT__
    if (type == BTAUD_CHNL_MONO && (active_chnl & type))
        srv_prof_bt_disconnected_hdlr(SRV_PROF_BT_HFP_ACL, SRV_PROF_BT_IND);
#endif
}

#if (AUD_CHNL_SUPPORT & MONO_CHNL)
static void btaud_call_begin(void)
{
    if (!g_btaud_cntx.ongoing_call)
    {
        srv_btsco_call_start_callback();
        g_btaud_cntx.ongoing_call = MMI_TRUE;
    }
}

static void btaud_call_end(void)
{
    if (g_btaud_cntx.ongoing_call)
    {
        srv_btsco_call_end_callback();
        g_btaud_cntx.ongoing_call = MMI_FALSE;
    }
}
#endif

static btaud_channel *btaud_get_chnl(U32 type)
{
    btaud_device *device = btaud_get_device();
    btaud_channel *chnl = NULL;

    if (!device) return NULL;
    
    if (type == BTAUD_CHNL_MONO)
        chnl = device->chnls[CHNL_HFP];
    else
        chnl = device->chnls[CHNL_A2DP];

    return chnl;
}

static void btaud_link_chnl(btaud_device *device, btaud_channel *chnl)
{
    if (!device || !chnl)
        return;

    chnl->device = device;

    if (chnl->type == BTAUD_CHNL_MONO)
        device->chnls[CHNL_HFP] = chnl;
    else
        device->chnls[CHNL_A2DP] = chnl;
    
    device->link_chnl |= chnl->type;
}

static void btaud_unlink_chnl(btaud_channel *chnl)
{
    if (!chnl) return;

    if (chnl->type == AUD_CHNL_MONO)
        chnl->device->chnls[CHNL_HFP] = NULL;
    else
        chnl->device->chnls[CHNL_A2DP] = NULL;

    chnl->device->link_chnl &= ~(chnl->type);

    chnl->device = NULL;
}

static btaud_request *btaud_new_req(
                        btaud_instance *inst,
                        btaud_channel *chnl,
                        U32 op_code, U32 arg)
{
    btaud_request *req = get_ctrl_buffer(sizeof(*req));

    req->caller = inst;
    req->owner = chnl;
    req->op_code = op_code;
    req->arg = arg;
    req->status = REQ_INIT;
    req->flags = 0;
    req->next = NULL;
    
    return req;
}

static void btaud_delete_req(btaud_request **req_list, btaud_request *req)
{
    btaud_request *t;
    
    if (!*req_list)
        return;
    
    if (req)
    {
        if (req == *req_list)
            *req_list = req->next;
        else
        {
            for (t = *req_list; t->next; t = t->next)
            {
                if (t->next == req)
                {
                    t->next = req->next;
                    break;
                }
            }
        }

        free_ctrl_buffer(req);
    }
    else /* delete entier request list */
    {
        for (req = *req_list, t = req->next; req; req = t, t = t->next)
        {
            free_ctrl_buffer(req);
        }
        *req_list = NULL;
    }
}

static MMI_BOOL btaud_add_req(
                    btaud_instance *inst,
                    btaud_channel *chnl,
                    U32 op_code, U32 arg)
{
    btaud_request *req;
    MMI_BOOL result = MMI_TRUE;

    req = btaud_new_req(inst, chnl, op_code, arg);

    if (chnl->req_list)
    {
        btaud_request *t;

        /* Optimize for Close instance then Open instance and perform same operation case */
        if (chnl->req_list->op_code == op_code &&
            chnl->req_list->caller == NULL)
        {
            chnl->req_list->caller = inst;
        }
        else
        {
            for (t = chnl->req_list; t->next; t = t->next);
            t->next = req;
        }
    }
    else
    {
        chnl->req_list = req;
        result = btaud_chnl_run(chnl, op_code, req);
    }

    return result;
}


static MMI_BOOL btaud_check_req(btaud_channel *chnl)
{
    if (chnl->req_list && chnl->req_list->status == REQ_DONE)
    {
        btaud_delete_req(&chnl->req_list, chnl->req_list);

        return ( (chnl->req_list != NULL) ? MMI_TRUE : MMI_FALSE );
    }

    return MMI_FALSE;
}

static void btaud_abort_req(btaud_instance *inst, btaud_channel *chnl)
{
    if (chnl->req_list)
    {
        btaud_request *req;
        
        for (req = chnl->req_list; req; req = req->next)
        {
            if (req->caller != inst)
                continue;

            if (req->status == REQ_INIT)
                btaud_delete_req(&chnl->req_list, req);
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
            else if (chnl->type == AUD_CHNL_MONO && req->op_code == OP_DEV_CONN)
                srv_bthf_abort(chnl->chnl_hd);
#endif
            else
                req->flags |= FLAG_ABORT;
        }
    }
}

static void btaud_notify(btaud_instance *inst, U32 event, U32 arg)
{
    btaud_notification *notify;
    mmi_event_struct evt;

    if (!inst || !inst->alloc || !(inst->events & event) || !inst->notify)
        return;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_NOTIFY, inst, event, arg);

    notify = get_ctrl_buffer(sizeof(*notify));
    notify->inst = inst;
    notify->evt_id = event;
    notify->arg = arg;

    MMI_FRM_INIT_EVENT(&evt, BTAUD_EVENT_ID);

    mmi_frm_post_event(&evt, btaud_event_proc, notify);
}

static void btaud_notify_all(U32 event, U32 arg)
{
    U32 i;
    
    for (i = 0; i < MAX_INSTANCE_NUM; i++)
    {
        if (cntx->insts[i].alloc)
            btaud_notify(&cntx->insts[i], event, arg);
    }
}

static mmi_ret btaud_event_proc(mmi_event_struct *evt)
{
    btaud_notification *data;
    
    if (evt->evt_id != BTAUD_EVENT_ID)
        return MMI_RET_ERR;

    data = (btaud_notification *)evt->user_data;

    data->inst->notify(data->evt_id, data->arg, data->inst->user_data);

    free_ctrl_buffer(data);

    return MMI_RET_OK;
}

static S32 btaud_send_notify(void)
{
    S32 i;

    for (i = 0; i < MAX_INSTANCE_NUM; i++)
    {
        btaud_instance *inst = &cntx->insts[i];
        if (inst->alloc && inst->notify && (inst->events & EV_STEREO_CONFIG_IND))
        {
            S32 retval = ((BtAudNotifyEx)inst->notify)(EV_STEREO_CONFIG_IND, 0, inst->user_data);
            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_AUD_SRV_NOTIFY, inst, EV_STEREO_CONFIG_IND, retval);
            if (retval) return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}
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
#endif /*- btaud_dump_req_list -*/

#endif /* __MMI_BT_SUPPORT__ */

BtAudStatus srv_btaud_get_status(BtAudChannel chnl)
{
#ifdef __MMI_BT_SUPPORT__    
    btaud_device *device = btaud_get_device();
    BtAudStatus status = BTAUD_IDLE;

    if (!device)
        return status;

    if (chnl == AUD_CHNL_ANY)
        status = device->status;
    else if (chnl != AUD_CHNL_ALL && (device->active_chnl & chnl))
    {
        btaud_channel *aud_chnl = btaud_get_chnl(chnl);
        status = aud_chnl->status;
    }

    return status;
#else
    return BTAUD_IDLE;
#endif
}

MMI_BOOL srv_btaud_get_active_device(BtAudChannel chnl, btaud_device_info *info)
{
#ifdef __MMI_BT_SUPPORT__
    btaud_device *device = btaud_get_device();

    if (!device || !device->active_chnl)
        return MMI_FALSE;

    if (chnl != AUD_CHNL_ANY && !(device->active_chnl & chnl))
        return MMI_FALSE;

    if (info)
    {
        info->addr = device->addr;
        info->chnls = device->active_chnl;
    }

    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}

BtAudDevClass srv_btaud_get_device_class(void)
{
#ifdef __MMI_BT_SUPPORT__
    btaud_device *device = btaud_get_device();

    if (device)
    {
        /* SRV_BT_AV_MAJOR_DEVICE_MASK|SRV_BT_CAR_AUDIO_AV_MINOR_DEVICE_CLASS */
        U32 carkit = 0x000420;
        U32 cod = srv_bt_cm_get_dev_cod(&device->addr);

        if ((cod & 0x1FFF) == carkit)
            return BTAUD_CARKIT;

        return BTAUD_HEADSET;
    }
#endif

    return BTAUD_UNKNOWN_DEVICE;
}


MMI_BOOL srv_btaud_switchable(BtAudChannel chnl)
{
#if (AUD_CHNL_SUPPORT & MONO_CHNL)
#ifdef __COSMOS_MMI_PACKAGE__
    btaud_device *device = btaud_get_device();
    btaud_channel *aud_chnl = NULL;

    if (!device || device->status < BTAUD_ACTIVE)
        return MMI_FALSE;

    if (chnl != AUD_CHNL_MONO ||
        !(device->active_chnl & chnl))
        return MMI_FALSE;

    aud_chnl = btaud_get_chnl(chnl);
    if (aud_chnl->state == STATE_SWITCH_ON ||
        aud_chnl->state == STATE_SWITCH_OFF)
        return MMI_FALSE;

    return MMI_TRUE;
#else
    return ( (srv_bthf_get_status() >= BTHF_STATUS_ATTACH)? MMI_TRUE:MMI_FALSE ) ;
#endif
#else
    return MMI_FALSE;
#endif

}


