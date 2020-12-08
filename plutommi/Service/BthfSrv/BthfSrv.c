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
 * BthfSrv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM external API and internal API declaration
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_HFP_SUPPORT__
#include "UcmSrvGProt.h"
#include "bt_dm_struct.h"
#include "bt_hfg_struct.h"
//#include "bt_hsg_struct.h"
#include "BthfSrv.h"

/* RHR ADD */
#include "MMIDataType.h"
#include "string.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "BthfSrvGprot.h"
#include "BtcmSrvGprot.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_conn_app_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "stack_config.h"

/***************************************************************************** 
* Globle definition
*****************************************************************************/
static bthf_cntx_struct g_bthf_cntx;
static bthf_cntx_struct *cntx = &g_bthf_cntx;
static bthf_helper_cntx_struct g_bthf_helper;
static bthf_helper_cntx_struct *helper_cntx = &g_bthf_helper;

static const srv_bt_cm_profile_struct g_bthf_prof = 
{
    SRV_BT_CM_HFG_PROFILE_UUID,
    bthf_enable,
    bthf_disable,
    bthf_disconnect
};
static const srv_bt_cm_profile_struct g_bths_prof = 
{
    SRV_BT_CM_HEADSET_AG_SERVICE_UUID,
    NULL,
    NULL,
    NULL
};

#define MakeHandle(inst)    (((U32)inst >> 8) | ((U32)((U32)inst & 0xFF) << 24))
#define MakeDevID(dev)      (((U32)dev) & 0xFFFF)
#define MakeParam(hi, low)  (((U32)(hi)<< 16) & 0xFFFF0000) | (low & 0x0000FFFF)
#define MakeWord(hi, low)   (((U16)(hi)<< 8) & 0xFF00) | (low & 0x00FF)

#define ValidDevice(addr) \
            ((addr != NULL) && \
            ((addr)->lap != 0 || (addr)->nap != 0 || (addr)->uap != 0))

#define SameDevice(addr1, addr2) \
            ((addr1 != NULL && addr2 != NULL) && \
            ((addr1)->lap == (addr2)->lap) && \
            ((addr1)->uap == (addr2)->uap) && \
            ((addr1)->nap == (addr2)->nap))

#define IsServReq(id)       ((id) & 0x10000000)
#define RawID(id)           ((id) & 0xEFFFFFFF)

#define g_service       (cntx->service)
#define g_insts         (cntx->insts)
#define g_inst_list     (&cntx->inst_list)
#define g_devs          (cntx->devs)
#define g_dev_list      (&cntx->dev_list)
#define g_setting       (cntx->setting)
#define g_dev_count     (cntx->dev_count)
#define g_init_done     (cntx->init_done)

const static BTHFFSM g_serv_fsm[STATE_SERV_END] = {
    (BTHFFSM)state_serv_idle,
    (BTHFFSM)state_activate,
    (BTHFFSM)state_activate_ed,
    (BTHFFSM)state_deactivate
};

const static BTHFFSM g_dev_fsm[STATE_DEV_END] = {
    (BTHFFSM)state_dev_idle,
    (BTHFFSM)state_wait_rsp,        
    (BTHFFSM)state_slc_conn,
    (BTHFFSM)state_slc_conn_ed,
    (BTHFFSM)state_sco_conn,
    (BTHFFSM)state_sco_conn_ed,
    (BTHFFSM)state_sco_disc,
    (BTHFFSM)state_slc_disc
};

extern U8 *BTBMGetLocalStoredName(U8 *bdAddr);
extern void CONVERT_BDADDR2ARRAY(U8 *dest, U32 lap, U8 uap, U16 nap);

/***************************************************************************** 
* BTHF External API
*****************************************************************************/
void srv_bthf_init(void)
{
    U32 i;
    
    if (g_init_done)
        return;

    memset(cntx, 0, sizeof(*cntx));

    ListInit(&g_service.req_list);

    ListInit(g_inst_list);
    
    ListInit(g_dev_list);

    for (i = MSG_ID_BT_HFG_ACTIVATE_CNF; i <= MSG_ID_BT_HFG_MIC_GAIN_CNF; i++)
        mmi_frm_set_protocol_event_handler(
            (U16)i, (PsIntFuncPtr)bthf_msg_hdlr, MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_HFG_SPEAKER_GAIN_REQ,
        (PsIntFuncPtr)bthf_msg_hdlr, MMI_FALSE);

    srv_bt_cm_profile_register(&g_bthf_prof);
    srv_bt_cm_profile_register(&g_bths_prof);

    bthf_init_setting(&g_setting);

    g_init_done = MMI_TRUE;
}

void srv_bthf_deinit(void)
{
    bthf_list_struct *m, *b1, *b2;
    
    ForEachOfListEx(g_dev_list, m, b1)
    {
        bthf_device_struct *dev = (bthf_device_struct *)m;
        bthf_list_struct *n;

        ForEachOfListEx(&dev->req_list, n, b2)
        {
            bthf_del_req((bthf_request_struct *)n);
        }
        bthf_del_dev(dev->owner, dev);
    }

    ForEachOfListEx(&g_service.req_list, m, b1)
    {
        bthf_del_req((bthf_request_struct *)m);
    }

    ForEachOfListEx(g_inst_list, m, b1)
    {
        bthf_delete((bthf_inst_struct *)m);
    }

    g_init_done = MMI_FALSE;
}

BTHFHandle srv_bthf_open(void)
{
    bthf_inst_struct *inst = bthf_new();

    if (!inst)
        return 0;

    return inst->handle;
}

void srv_bthf_close(BTHFHandle srv_hd)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);

    if (!inst)
        return;

    /* After close is invoked, no futher event should be received */
    inst->notify = NULL;

    if (inst->dev_count > 0)
    {
        bthf_list_struct *m;
        ForEachOfList(g_dev_list, m)
        {
            bthf_device_struct *dev = (bthf_device_struct *)m;
            if (dev->owner == inst)
                bthf_insert_req(inst, dev, REQ_DETACH, 0);
        }
    }

    if (inst->dev_count > 0)
        inst->flags |= FLAG_DELETE;
    else
        bthf_delete(inst);
}

BTHFResult srv_bthf_set_notify(BTHFHandle srv_hd, BTHFSrvNotify notify, U32 mask, U8 op)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);

    if (!inst)
        return RESULT_FAIL;

    switch (op) {
    case BTHF_MOP_NEW:
        inst->event_mask = mask;
        inst->notify = notify;
        break;

    case BTHF_MOP_ADD:
        inst->event_mask |= mask;
        break;

    case BTHF_MOP_DEL:
        inst->event_mask &= ~mask;
        break;
    }

    return RESULT_SUCC;
}

BTHFResult srv_bthf_config(BTHFHandle srv_hd, U32 item, void *value)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);

    if (!inst || !value)
        return RESULT_FAIL;

    switch (item) {
    case CFG_AUDIO_PATH:
        inst->setting.mode = *((U32 *)value);
        break;

    case CFG_DEF_DEVICE:
        inst->setting.def_dev = *((BTHFAddr *)value);
        break;

    case CFG_PROFILE:
        inst->prof = *((U32 *)value);
        break;

    default:
        break;
    }

    return RESULT_SUCC;
}

U32 srv_bthf_attach(BTHFHandle srv_hd, BTHFAddr *addr)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);
    bthf_device_struct *dev = NULL;
    BTHFAddr *dev_addr;
    U32 req_id = REQ_ATTACH;

    if (!inst)
        return 0;

    if (!addr)
        dev_addr = (BTHFAddr *)bthf_read_setting(CFG_DEF_DEVICE);
    else
        dev_addr = addr;
    
    if (!ValidDevice(dev_addr))
        return 0;

    if (!bthf_serv_avail())
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_ALLOW, req_id));
        return 0;
    }

    dev = bthf_find_dev(FIND_BY_ADDR, dev_addr);
    if (dev)
    {
        if (dev->owner != inst)
        {
            bthf_notify(inst, NULL, EV_REQ_RESULT, 
                MakeParam(E_NOT_AUTHORIZE, req_id));
            return 0;
        }
    }
    else
    {
        if (inst->prof == PROF_AUTO)
            dev = bthf_new_dev(inst, dev_addr, PROF_HF, MMI_FALSE);
        else
            dev = bthf_new_dev(inst, dev_addr, inst->prof, MMI_FALSE);
        if (dev)
        {
            inst->dev_count++;
        }
        else
        {
            bthf_notify(inst, NULL, EV_REQ_RESULT, 
                MakeParam(E_BUSY, req_id));
            return 0;
        }
    }

    bthf_add_req(dev->owner, dev, REQ_ATTACH, 0);

    return dev->id;
}

BTHFResult srv_bthf_detach(BTHFHandle srv_hd, U32 dev_id)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);
    bthf_device_struct *dev = bthf_find_dev(FIND_BY_DEV_ID, &dev_id);
    U32 req_id = REQ_DETACH;

    if (!inst || !dev)
        return RESULT_FAIL;

    if (!bthf_serv_avail())
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_ALLOW, req_id));
        return RESULT_SUCC;
    }

    if (dev->owner != inst)
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_AUTHORIZE, req_id));
        return RESULT_SUCC;
    }

    return bthf_add_req(inst, dev, req_id, 0);
}

#ifdef __BT_MANUAL_AUDIO_SWITCH__
BTHFResult srv_bthf_audio_on(BTHFHandle srv_hd, U32 dev_id)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);
    bthf_device_struct *dev = bthf_find_dev(FIND_BY_DEV_ID, &dev_id);
    U32 req_id = REQ_AUDIO_ON;

    if (!inst || !dev)
        return RESULT_FAIL;

    if (!bthf_serv_avail())
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_ALLOW, req_id));
        return RESULT_SUCC;
    }

    if (dev->owner != inst)
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_AUTHORIZE, req_id));
        return RESULT_SUCC;
    }

    return bthf_add_req(inst, dev, req_id, 0);
}

BTHFResult srv_bthf_audio_off(BTHFHandle srv_hd, U32 dev_id)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);
    bthf_device_struct *dev = bthf_find_dev(FIND_BY_DEV_ID, &dev_id);
    U32 req_id = REQ_AUDIO_OFF;

    if (!inst || !dev)
        return RESULT_FAIL;

    if (!bthf_serv_avail())
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_ALLOW, req_id));
        return RESULT_SUCC;
    }

    if (dev->owner != inst)
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_AUTHORIZE, req_id));
        return RESULT_SUCC;
    }

    return bthf_add_req(inst, dev, req_id, 0);
}
#endif

static BTHFResult srv_bthf_request_hdler(BTHFHandle srv_hd, U32 dev_id, U32 req_id)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);
    bthf_device_struct *dev = bthf_find_dev(FIND_BY_DEV_ID, &dev_id);
    if (!inst || !dev)
        return RESULT_FAIL;

    if (!bthf_serv_avail())
    {
        bthf_notify(inst, NULL, EV_REQ_RESULT, 
            MakeParam(E_NOT_ALLOW, req_id));
        return RESULT_SUCC;
    }

    dev->owner = inst;
    inst->dev_count++;
    
    return bthf_add_req(inst, dev, req_id, 0);
}

BTHFResult srv_bthf_accept(BTHFHandle srv_hd, U32 dev_id)
{

	return srv_bthf_request_hdler(srv_hd,dev_id,REQ_ACCEPT);
    }

BTHFResult srv_bthf_reject(BTHFHandle srv_hd, U32 dev_id)
    {
    return srv_bthf_request_hdler(srv_hd,dev_id,REQ_REJECT);
}

void srv_bthf_abort(BTHFHandle srv_hd)
{
    bthf_inst_struct *inst = bthf_find(srv_hd);

    if (!inst)
        return;

    bthf_abort_req(inst);
}

void srv_bthf_abort_all(void)
{
    bthf_inst_struct *inst;
    bthf_list_struct *m;

    ForEachOfList(g_inst_list, m)
    {
        inst = (bthf_inst_struct *)m;
        bthf_abort_req(inst);
    }
}

BTHFResult srv_bthf_change_volume(BTHFHandle srv_hd, U32 dev_id, U8 volume)
{
    bthf_inst_struct *inst = NULL;
    U32 req_id = REQ_CHG_VOLUME;
    bthf_list_struct *m;
    
    if (MOD_MMI != stack_get_active_module_id())
    {
        bthf_send_msg(MSG_VOLUME_REQ, (void *)srv_hd, volume);
        return RESULT_SUCC;
    }

    if (srv_hd)
    {
        inst = bthf_find(srv_hd);
        if (!inst)
            return RESULT_FAIL;

        if (!bthf_serv_avail())
        {
            bthf_notify(inst, NULL, EV_REQ_RESULT, 
                MakeParam(E_NOT_ALLOW, req_id));
            return RESULT_SUCC;
        }
    }

    /* We change all attached device volume */
    ForEachOfList(g_dev_list, m)
    {
        bthf_device_struct *dev = (bthf_device_struct *)m;
        if ((dev->owner == inst || !srv_hd) && (dev->id == dev_id || !dev_id))
            bthf_add_req(dev->owner, dev, req_id, volume);
    }

    return RESULT_SUCC;
}


U32 srv_bthf_list_device(U32 *dev_list, U32 count)
{
    U32 i = 0;
    bthf_list_struct *m;

    if (!g_init_done || !dev_list)
        return g_dev_count;

    for (m = ListHead(g_dev_list); m != g_dev_list && i < count; m = ListNext(m))
    {
        bthf_device_struct *dev = (bthf_device_struct *)m;

        dev->id ? (dev_list[i++] = dev->id) : 0;
    }

    return i;
}


BTHFResult srv_bthf_get_device_info(U32 dev_id, bthf_dev_info_struct *info)
{
    bthf_device_struct *dev = bthf_find_dev(FIND_BY_DEV_ID, &dev_id);

    if (!dev)
        return RESULT_FAIL;

    info->id = dev_id;

    info->addr = dev->addr;
    info->dev_class = dev->dev_class;
    info->prof = dev->prof;
    info->conn_id = dev->cmgr_id;

    info->status = bthf_get_status(dev);

    return RESULT_SUCC;
}

BTHFStatus srv_bthf_get_status(void)
{
    bthf_list_struct *m;
    BTHFStatus status = STATUS_DETACH, s;

    if (!g_init_done)
        return STATUS_DETACH;

    ForEachOfList(g_dev_list, m)
    {
        s = bthf_get_status((bthf_device_struct *)m);
        
        if (s == STATUS_AUDIO_ON)
            return s;
        
        if (s == STATUS_ATTACH && s != status)
            status = s;
    }

    return status;
}

BTHFResult srv_bthf_save_config(U32 item, void *value)
{
    BTHFResult retval;
    
    if (!value)
        retval = bthf_reset_setting(item);
    else
        retval = bthf_save_setting(item, value);

    return retval;
}

void * srv_bthf_read_config(U32 item)
{
    return bthf_read_setting(item);
}

MMI_BOOL srv_bthf_attach_device(BTHFAddr *addr, BTHFAttachCallback notify)
{
    BTHFHandle handle;
    U32 dev_id;
    U32 evt_mask = BTHF_EV_ATTACH |
                   BTHF_EV_DETACH |
                   BTHF_EV_REQ_RESULT;

    handle = srv_bthf_open();
    if (!handle)
        return MMI_FALSE;

    srv_bthf_set_notify(handle, bthf_helper_notify, evt_mask, BTHF_MOP_NEW);

    dev_id = srv_bthf_attach(handle, addr);
    if (!dev_id)
    {
        srv_bthf_close(handle);
        return MMI_FALSE;
    }

    helper_cntx->handle = handle;
    helper_cntx->dev_id = dev_id;
    helper_cntx->busy = MMI_TRUE;
    helper_cntx->notify = notify;
    
    return MMI_TRUE;
}

static S32 bthf_helper_notify(BTHFHandle handle, U32 evt, U32 param)
{
    U32 dev_id = param & 0xFFFF;
    U32 result = (param >> 16) & 0xFFFF;

    switch (evt) {
    case BTHF_EV_ATTACH:
        
        if (dev_id != helper_cntx->dev_id)
            break;
        helper_cntx->busy = MMI_FALSE;
        if (helper_cntx->notify)
        {
            helper_cntx->notify(MMI_TRUE);
            helper_cntx->notify = NULL;
        }
        break;

    case BTHF_EV_DETACH:

        if (dev_id != helper_cntx->dev_id)
            break;
        if (helper_cntx->busy)
        {
            helper_cntx->busy = MMI_FALSE;
            helper_cntx->notify(MMI_FALSE);
            helper_cntx->notify = NULL;
        }
        srv_bthf_close(helper_cntx->handle);
        helper_cntx->handle = 0;
        helper_cntx->dev_id = 0;

        break;

    case BTHF_EV_REQ_RESULT:

        if (dev_id == BTHF_REQ_ATTACH && result != BTHF_E_NONE)
        {
            helper_cntx->busy = MMI_FALSE;
            if (helper_cntx->notify)
            {
                helper_cntx->notify(MMI_FALSE);
                helper_cntx->notify = NULL;
            }
            srv_bthf_close(helper_cntx->handle);
            helper_cntx->handle = 0;
            helper_cntx->dev_id = 0;
        }
        break;
    }

    return 0;
}

static void bthf_enable(void)
{
    bthf_add_req(NULL, NULL, REQ_ENABLE, 0);
}

static void bthf_disable(void)
{
    if (g_dev_count > 0)
    {
        bthf_list_struct *m;
        ForEachOfList(g_dev_list, m)
        {
            bthf_device_struct *dev = (bthf_device_struct *)m;
            if (dev->state == STATE_SLC_CONN)
            {
                srv_bthf_abort(dev->owner->handle);
            }
            else
            {
                bthf_insert_req(NULL, dev, REQ_DETACH, 0);
            }
        }
    }
    if (g_dev_count == 0)
        bthf_add_req(NULL, NULL, REQ_DISABLE, 0);        
    else
        g_service.flags |= FLAG_DISABLE;
}

static void bthf_disconnect(U32 conn_id)
{
    bthf_device_struct *dev = bthf_find_dev(FIND_BY_CMGR_ID, &conn_id);
    U32 req_id = REQ_DETACH;

    if (!dev)
        return;

    if (!bthf_serv_avail())
        return;

    bthf_add_req(dev->owner, dev, req_id, 0);
}


/***************************************************************************** 
* BTHF Internal Implementation
*****************************************************************************/
static U32 bthf_call_status_check(void)
{
    U32 status = hsg_no_call;
    
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0)
        status |= hsg_incoming_call;

    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0)
        status |= hsg_outgoing_call;

    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0)
        status |= hsg_in_call;
    
    return status;
}

static MMI_RET bthf_evt_proc(mmi_event_struct *evt)
{
    bthf_notify_struct *notify = (bthf_notify_struct *)evt->user_data;
    bthf_inst_struct *inst = notify->inst;
    bthf_device_struct *dev = notify->dev;

    MMI_ASSERT(evt->evt_id == BTHF_EVENT_ID);

    if (inst->handle && inst->notify) {
        if (inst->event_mask & notify->evt_id)
            inst->notify(inst->handle, notify->evt_id, notify->para);
    }

    /* We delay deleting device here since user might need to get 
        device info in notify callback */
    if (dev && (dev->flags & FLAG_DELETE))
        bthf_del_dev(dev->owner, dev);

    free_ctrl_buffer(notify);

    return MMI_RET_OK;
}

static U8 bthf_msg_hdlr(void *para, U32 src_mod, ilm_struct *ilm)
{
    bthf_device_struct *dev = NULL;
    U32 conn_id = 0, evt = 0;
    bthf_slc_cnf_struct *slc_cnf = (bthf_slc_cnf_struct *)para;
    bthf_slc_ind_struct *slc_ind = (bthf_slc_ind_struct *)para;
#ifdef __BT_MANUAL_AUDIO_SWITCH__
    bthf_sco_cnf_struct *sco_cnf = (bthf_sco_cnf_struct *)para;
    bthf_sco_ind_struct *sco_ind = (bthf_sco_ind_struct *)para;
#endif

    /* This is internal primitive, used to task synchornize */
    if (ilm->msg_id == MSG_ID_BT_HFG_SPEAKER_GAIN_REQ)
    {
        bt_hfg_speaker_gain_req_struct *req = 
            (bt_hfg_speaker_gain_req_struct *)ilm->local_para_ptr;
        srv_bthf_change_volume((BTHFHandle)req->connection_id, 0, (U8)req->gain);
        return 1;
    }
    
    /* Service message */
    switch (ilm->msg_id) {
    case MSG_ID_BT_HFG_ACTIVATE_CNF:
        evt = CNF_ACTIVATE;
        break;

    case MSG_ID_BT_HFG_DEACTIVATE_CNF:
        evt = CNF_DEACTIVATE;
        break;

    default:
        break;
    }

    /* Connection message */
    switch (ilm->msg_id) {
    case MSG_ID_BT_HFG_CONNECT_IND_REQ:
        {
            bt_hfg_connect_ind_req_struct *ind_req = 
                (bt_hfg_connect_ind_req_struct *)para;
			#ifdef __BT_DIALER_SUPPORT__
			if(srv_bt_cm_get_btdialor_mode() == MMI_TRUE)
			{
				bthf_device_struct device;
                device.addr = slc_ind->addr;
				bthf_send_msg(MSG_AUTH_RSP, &device, MMI_FALSE);
				return 1;
			}
			#endif //__BT_DIALER_SUPPORT__
            if (ind_req->hs_conn)
                dev = bthf_new_dev(NULL, &slc_ind->addr, PROF_HS, MMI_TRUE);
            else
                dev = bthf_new_dev(NULL, &slc_ind->addr, PROF_HF, MMI_TRUE);
            
            if (!dev)
            {
                bthf_device_struct device;
                device.addr = slc_ind->addr;
                bthf_send_msg(MSG_AUTH_RSP, &device, MMI_FALSE);
                return 1;
            }

            evt = IND_SLC_REQ;
            conn_id = slc_ind->conn_id;
        }

        break;

    case MSG_ID_BT_HFG_CONNECT_CNF:
    case MSG_ID_BT_HSG_CONNECT_CNF:

        if (slc_cnf->result == BT_HFG_RESULT_OK)
        {
            slc_ind = (bthf_slc_ind_struct *)get_ctrl_buffer(sizeof(*slc_ind));
            slc_ind->conn_id = slc_cnf->conn_id;
            slc_ind->addr = slc_cnf->addr;
            slc_ind->passive = 0;
            evt = IND_SLC_CONN;
        }
        else
            evt = CNF_SLC_CONN;

        conn_id = slc_cnf->conn_id;
        break;

    case MSG_ID_BT_HFG_CONNECT_IND:
    case MSG_ID_BT_HSG_CONNECT_IND:
        
        slc_ind = (bthf_slc_ind_struct *)get_ctrl_buffer(sizeof(*slc_ind));
        *slc_ind = *((bthf_slc_ind_struct *)para);
        slc_ind->passive = 1;
        evt = IND_SLC_CONN;
        conn_id = slc_ind->conn_id;
        
        break;

    case MSG_ID_BT_HFG_DISCONNECT_CNF:
    case MSG_ID_BT_HSG_DISCONNECT_CNF:

        slc_ind = (bthf_slc_ind_struct *)get_ctrl_buffer(sizeof(*slc_ind));
        slc_ind->conn_id = slc_cnf->conn_id;
        slc_ind->addr = slc_cnf->addr;
        slc_ind->passive = 0;
        evt = IND_SLC_DISC;
        conn_id = slc_cnf->conn_id;

        break;
    
    case MSG_ID_BT_HFG_DISCONNECT_IND:
    case MSG_ID_BT_HSG_DISCONNECT_IND:

        slc_ind = (bthf_slc_ind_struct *)get_ctrl_buffer(sizeof(*slc_ind));
        *slc_ind = *((bthf_slc_ind_struct *)para);
        slc_ind->passive = 1;
        evt = IND_SLC_DISC;
        conn_id = slc_ind->conn_id;

        break;

#ifdef __BT_MANUAL_AUDIO_SWITCH__
    case MSG_ID_BT_HFG_SCO_CONNECT_CNF:
        
        if (sco_cnf->result == BT_HFG_RESULT_OK)
        {
            sco_ind = (bthf_sco_ind_struct *)get_ctrl_buffer(sizeof(*sco_ind));
            sco_ind->conn_id = sco_cnf->conn_id;
            evt = IND_SCO_CONN;
        }
        else
            evt = CNF_SCO_CONN;
        
        conn_id = sco_cnf->conn_id;
        
        break;

    case MSG_ID_BT_HFG_SCO_CONNECT_IND:

        evt = IND_SCO_CONN;
        conn_id = sco_ind->conn_id;

        break;
        
    case MSG_ID_BT_HFG_SCO_DISCONNECT_CNF:

        sco_ind = (bthf_sco_ind_struct *)get_ctrl_buffer(sizeof(*sco_ind));
        sco_ind->conn_id = sco_cnf->conn_id;
        evt = IND_SCO_DISC;
        conn_id = sco_cnf->conn_id;

        break;
        
    case MSG_ID_BT_HFG_SCO_DISCONNECT_IND:

        evt = IND_SCO_DISC;
        conn_id = sco_ind->conn_id;

        break;
#endif
        
    case MSG_ID_BT_HFG_SPEAKER_GAIN_CNF:
    case MSG_ID_BT_HSG_SPEAKER_GAIN_CNF:
        {
            bt_hfg_speaker_gain_cnf_struct *cnf = 
                (bt_hfg_speaker_gain_cnf_struct *)para;
            evt = CNF_SPEAKER_GAIN;
            conn_id = cnf->connection_id;
        }
        break;

    case MSG_ID_BT_HFG_SPEAKER_GAIN_IND:
    case MSG_ID_BT_HSG_SPEAKER_GAIN_IND:
        {
            bt_hfg_speaker_gain_ind_struct *ind =
                (bt_hfg_speaker_gain_ind_struct *)para;
            evt = IND_SPEAKER_GAIN;
            conn_id = ind->connection_id;
        }
        break;
        
    case MSG_ID_BT_HFG_MIC_GAIN_CNF:
    case MSG_ID_BT_HSG_MIC_GAIN_CNF:
        {
            bt_hfg_mic_gain_cnf_struct *cnf = 
                (bt_hfg_mic_gain_cnf_struct *)para;
            evt = CNF_MIC_GAIN;
            conn_id = cnf->connection_id;
        }
        break;

    case MSG_ID_BT_HFG_MIC_GAIN_IND:
    case MSG_ID_BT_HSG_MIC_GAIN_IND:
        {
            bt_hfg_mic_gain_ind_struct *ind = 
                (bt_hfg_mic_gain_ind_struct *)para;
            evt = IND_MIC_GAIN;
            conn_id = ind->connection_id;
        }
        break;

    default:
        break;
    }

    if (evt == CNF_ACTIVATE ||
        evt == CNF_DEACTIVATE)
    {
        bthf_fsm(&g_service, evt, para);
        if (!ListEmpty(&g_service.req_list))
            bthf_check_req(&g_service.req_list);
    }
    else
    {
        if (!dev)
            dev = bthf_find_dev(FIND_BY_CONN_ID, &conn_id);

        if (dev)
        {
            if (slc_ind != para)
                bthf_fsm(dev, evt, slc_ind);
#ifdef __BT_MANUAL_AUDIO_SWITCH__
            else if (sco_ind != para)
                bthf_fsm(dev, evt, sco_ind);
#endif            
            else
                bthf_fsm(dev, evt, para);
            if (!ListEmpty(&dev->req_list))
                bthf_check_req(&dev->req_list);
        }
    }

    if (slc_ind != para)
        free_ctrl_buffer(slc_ind);
    
#ifdef __BT_MANUAL_AUDIO_SWITCH__
    if (sco_ind != para)
        free_ctrl_buffer(sco_ind);
#endif

    return 1;
}

static BTHFErrCode bthf_fsm(void *owner, U32 in, void *para)
{
    BTHFErrCode retval;
    BTHFFSM entry;
    U32 id = RawID(in);

    if ((id < REQ_END && IsServReq(in)) ||
        in == CNF_ACTIVATE || in == CNF_DEACTIVATE)
    {
        bthf_serv_struct *serv = (bthf_serv_struct *)owner;
        entry = g_serv_fsm[serv->state];
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_FSM_BEGIN, 1, in, serv->state);
    }
    else
    {
        bthf_device_struct *dev = (bthf_device_struct *)owner;
        entry = g_dev_fsm[dev->state];
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_FSM_BEGIN, 0, in, dev->state);
    }

    retval = entry(owner, id, para);

    if ((id < REQ_END && IsServReq(in)) ||
        in == CNF_ACTIVATE || in == CNF_DEACTIVATE)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_FSM_END, 1, in, ((bthf_serv_struct *)owner)->state);
    }
    else
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_FSM_END, 0, in, ((bthf_device_struct *)owner)->state);
    }
    return retval;
}

static BTHFErrCode state_serv_idle(bthf_serv_struct *serv, U32 evt, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (evt) {
    case REQ_ENABLE:
        serv->state = STATE_ACTIVATE;
        bthf_send_msg(MSG_ACTIVATE, NULL, PROF_HF);
        req->status = REQ_START;
        break;

    case REQ_DISABLE:
        req->retval = E_NONE;
        req->status = REQ_DONE;
        break;

    default:
        break;
    }

    return retval;
}

static BTHFErrCode state_activate(bthf_serv_struct *serv, U32 evt, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (evt) {
    case CNF_ACTIVATE:
        
        serv->state = STATE_ACTIVATE_ED;
        req = bthf_find_req(&serv->req_list, REQ_ENABLE);
        if (req)
        {
            req->status = REQ_DONE;
            req->retval = E_NONE;
        }
        srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_HFG_PROFILE_UUID);
        bthf_notify_all(NULL, EV_ENABLE, 0);

        break;

    default:
        break;
    }

    return retval;
}

static BTHFErrCode state_activate_ed(bthf_serv_struct *serv, U32 evt, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (evt) {
    case REQ_ENABLE:
        req->status = REQ_DONE;
        req->retval = E_NONE;
        break;

    case REQ_DISABLE:
        bthf_send_msg(MSG_DEACTIVATE, NULL, PROF_HS);
        serv->state = STATE_DEACTIVATE;
        req->status = REQ_START;
        break;

    default:
        break;
    }

    return retval;
}

static BTHFErrCode state_deactivate(bthf_serv_struct *serv, U32 evt, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;

    switch (evt) {
    case CNF_ACTIVATE:
        MMI_ASSERT(0);
        break;

    case CNF_DEACTIVATE:
        {
            bthf_list_struct *m, *n;
            
            serv->state = STATE_SERV_IDLE;
            serv->flags = 0;
            srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_HFG_PROFILE_UUID);
            bthf_notify_all(NULL, EV_DISABLE, 0);

            ForEachOfListEx(&serv->req_list, m, n)
            {
                bthf_request_struct *req = (bthf_request_struct *)m;
                if (RawID(req->id) == REQ_DISABLE)
                    bthf_req_done(req, E_NONE);
                else
                    bthf_req_done(req, E_USER_ABORT);
            }
        }
        break;

    default:
        break;
    }

    return retval;
}

static BTHFErrCode state_dev_idle(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (in) {
    case REQ_ATTACH:

        dev->state = STATE_SLC_CONN;
        bthf_send_msg(MSG_SLC_CONN, dev, 0);
        req->status = REQ_START;

        break;

    case IND_SLC_REQ:

        dev->state = STATE_WAIT_RSP;
        bthf_notify_all(dev, EV_REQ_ATTACH, MakeParam(0, dev->id));

        break;

    case REQ_DETACH:
#ifdef __BT_MANUAL_AUDIO_SWITCH__        
    case REQ_AUDIO_OFF:
#endif
        req->status = REQ_DONE;
        req->retval = E_NONE;
        
        break;

    case REQ_ACCEPT:
    case REQ_REJECT: 
#ifdef __BT_MANUAL_AUDIO_SWITCH__        
    case REQ_AUDIO_ON:
#endif        
    case REQ_CHG_VOLUME:

        req->status = REQ_DONE;
        req->retval = E_NOT_ALLOW;
        
        break;
        
    default:
        break;
    }

    return retval;
}

static BTHFErrCode state_wait_rsp(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (in) {
    case REQ_ACCEPT:

        req->status = REQ_START;
        
        dev->state = STATE_SLC_CONN;
        bthf_send_msg(MSG_AUTH_RSP, dev, 1);

        break;

    case REQ_REJECT:
        
        req->status = REQ_DONE;
        req->retval = E_NONE;

        bthf_send_msg(MSG_AUTH_RSP, dev, 0);
        bthf_notify_all(dev, EV_REQ_ABORT, dev->id);
        bthf_del_dev(dev->owner, dev);

        break;

    case REQ_ATTACH:
    case REQ_DETACH:
#ifdef __BT_MANUAL_AUDIO_SWITCH__        
    case REQ_AUDIO_ON:
    case REQ_AUDIO_OFF:
#endif        
    case REQ_CHG_VOLUME:

        req->status = REQ_DONE;
        req->retval = E_NOT_ALLOW;

        break;

    case CNF_SLC_CONN:
    case IND_SLC_DISC:

        bthf_notify_all(dev, EV_REQ_ABORT, dev->id);
        bthf_del_dev(dev->owner, dev);
        
        break;
    }

    return retval;
}

static BTHFErrCode state_slc_conn(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_slc_ind_struct *ind = (bthf_slc_ind_struct *)para;
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (in) {
    case IND_SLC_CONN:

        dev->conn_id = ind->conn_id;

        dev->state = STATE_SLC_CONN_ED;

        req = bthf_find_req(&dev->req_list, REQ_ATTACH);
        if (!req) req = bthf_find_req(&dev->req_list, REQ_ACCEPT);
        if (req)
        {
            if (req->flags & FLAG_ABORT)
            {
                req->id = REQ_DETACH;
                bthf_send_msg(MSG_SLC_DISC, dev, 0);
                dev->state = STATE_SLC_DISC;
            }
            else
            {
                req->status = REQ_DONE;
                req->retval = E_NONE;
                bthf_notify_all(dev, EV_ATTACH, dev->id);
                srv_bt_cm_connect_ind(dev->cmgr_id);
            }
        }
        else
        {
            bthf_notify_all(dev, EV_ATTACH, dev->id);
            srv_bt_cm_connect_ind(dev->cmgr_id);
        }
        
        break;
        
    case CNF_SLC_CONN:
    case IND_SLC_DISC:
        req = bthf_find_req(&dev->req_list, REQ_ATTACH);
        /* Always try to connect HSP once more in HFP connect fail case,
            since we can't guarentee that device SDP record is correct */
        if (dev->owner && dev->owner->prof == PROF_AUTO &&
            dev->prof == PROF_HF && 
            req &&
            !(req->flags & FLAG_ABORT))
        {
            dev->prof = PROF_HS;
            bthf_send_msg(MSG_SLC_CONN, dev, 0);
            break;
        }
        
        dev->state = STATE_DEV_IDLE;

        req = bthf_find_req(&dev->req_list, REQ_ATTACH);
        if (!req) req = bthf_find_req(&dev->req_list, REQ_ACCEPT);
        if (req) 
        {
            req->status = REQ_DONE;
            if (req->flags & FLAG_ABORT)
                req->retval = E_USER_ABORT;
            else
                req->retval = E_UNKNOWN;
        }

        bthf_del_dev(dev->owner, dev);

        break;
    }

    return retval;
}


static BTHFErrCode state_slc_conn_ed(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (in) {
    case IND_SLC_DISC:

        dev->state = STATE_DEV_IDLE;
        bthf_notify_all(dev, EV_DETACH, MakeParam(((bthf_slc_ind_struct *)para)->passive, dev->id));
        bthf_del_dev(dev->owner, dev);

        break;
        
#ifdef __BT_MANUAL_AUDIO_SWITCH__
    case IND_SCO_CONN:
        
        dev->state = STATE_SCO_CONN_ED;
        bthf_notify(dev->owner, dev, EV_AUDIO_ON, dev->id);
        
        break;
#endif        

    case IND_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_ind_struct *ind = 
                (bt_hfg_speaker_gain_ind_struct *)para;
            dev->spk_gain = ind->gain;
            bthf_notify_all(dev, EV_VOL_CHANGE, MakeParam(ind->gain, dev->id));
        }
        break;

    case CNF_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_cnf_struct *cnf = 
                (bt_hfg_speaker_gain_cnf_struct *)para;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
            
            req = bthf_find_req(&dev->req_list, REQ_CHG_VOLUME);
            if (req)
            {
                req->status = REQ_DONE;
                req->retval = (cnf->result == BT_HFG_RESULT_OK) ? E_NONE:E_UNKNOWN;
            }
        }
        break;

#ifdef __BT_MANUAL_AUDIO_SWITCH__
    case REQ_AUDIO_ON:
        
        bthf_send_msg(MSG_SCO_CONN, dev, 0);
        dev->state = STATE_SCO_CONN;
        req->status = REQ_START;

        break;
#endif        

    case REQ_DETACH:
        
        bthf_send_msg(MSG_SLC_DISC, dev, 0);
        dev->state = STATE_SLC_DISC;
        req->status = REQ_START;

        break;

    case REQ_CHG_VOLUME:
        
        bthf_send_msg(MSG_SPEAKER_GAIN, dev, req->para);
        req->status = REQ_START;
        
        break;

#ifdef __BT_MANUAL_AUDIO_SWITCH__
    case REQ_AUDIO_OFF:
        
        req->status = REQ_DONE;
        req->retval = E_NONE;
        
        break;
#endif        

    case REQ_ATTACH:

        req->status = REQ_DONE;
        req->retval = E_BUSY;
        
        break;

    case REQ_ACCEPT:
    case REQ_REJECT:        

        req->status = REQ_DONE;
        req->retval = E_NOT_ALLOW;
        
        break;

    default:
        break;
    }

    return retval;
}

static BTHFErrCode state_sco_conn(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
#ifdef __BT_MANUAL_AUDIO_SWITCH__
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (in) {
    case IND_SCO_CONN:

        dev->state = STATE_SCO_CONN_ED;

        req = bthf_find_req(&dev->req_list, REQ_AUDIO_ON);
        if (req)
        {
            if (req->flags & FLAG_ABORT)
            {
                req->id = REQ_AUDIO_OFF;
                bthf_send_msg(MSG_SCO_DISC, dev, 0);
                dev->state = STATE_SCO_DISC;
            }
            else
            {
                req->status = REQ_DONE;
                req->retval = E_NONE;
                bthf_notify(dev->owner, dev, EV_AUDIO_ON, dev->id);
            }
        }
        else
            bthf_notify(dev->owner, dev, EV_AUDIO_ON, dev->id);

        break;

    case IND_SCO_DISC:
    case CNF_SCO_CONN:
        
        dev->state = STATE_SLC_CONN_ED;

        req = bthf_find_req(&dev->req_list, REQ_AUDIO_ON);
        if (req)
        {
            req->status = REQ_DONE;
            if (req->flags & FLAG_ABORT)
                req->retval = E_USER_ABORT;
            else
                req->retval = E_UNKNOWN;
        }

        break;

    case IND_SLC_DISC:

        dev->state = STATE_DEV_IDLE;

        bthf_notify_all(dev, EV_DETACH, MakeParam(((bthf_slc_ind_struct *)para)->passive, dev->id));

        req = bthf_find_req(&dev->req_list, REQ_AUDIO_ON);
        if (req)
        {
            req->status = REQ_DONE;
            if (req->flags & FLAG_ABORT)
                req->retval = E_USER_ABORT;
            else
                req->retval = E_UNKNOWN;
        }
        bthf_del_dev(dev->owner, dev);

        break;

    case IND_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_ind_struct *ind = 
                (bt_hfg_speaker_gain_ind_struct *)para;
            dev->spk_gain = ind->gain;
            bthf_notify_all(dev, EV_VOL_CHANGE, MakeParam(ind->gain, dev->id));
        }
        break;
    }

#endif
    return retval;
}

static BTHFErrCode state_sco_conn_ed(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
#ifdef __BT_MANUAL_AUDIO_SWITCH__
    bthf_request_struct *req = (bthf_request_struct *)para;
    
    switch (in) {
    case REQ_ATTACH:

        req->status = REQ_DONE;
        req->retval = E_BUSY;

        break;
        
    case REQ_DETACH:

#ifdef HFG_CONTROL_SCO
        bthf_send_msg(MSG_SCO_DISC, dev, 0);
        dev->state = STATE_SCO_DISC;
        dev->flags |= FLAG_DETACH;
#else
        bthf_send_msg(MSG_SLC_DISC, dev, 0);
        dev->state = STATE_SLC_DISC;
#endif
        req->status = REQ_START;

        break;

    case REQ_AUDIO_ON:

        req->status = REQ_DONE;
        req->retval = E_NONE;

        break;

    case REQ_AUDIO_OFF:

        bthf_send_msg(MSG_SCO_DISC, dev, 0);
        dev->state = STATE_SCO_DISC;
        req->status = REQ_START;

        break;

    case REQ_ACCEPT:
    case REQ_REJECT:

        req->status = REQ_DONE;
        req->retval = E_NOT_ALLOW;

        break;
        
    case REQ_CHG_VOLUME:

        bthf_send_msg(MSG_SPEAKER_GAIN, dev, req->para);
        req->status = REQ_START;

        break;
        
    case CNF_SLC_CONN:
    case CNF_SCO_CONN:
        /* Ignore */
        break;

    case IND_SLC_DISC:

        dev->state = STATE_DEV_IDLE;
        bthf_notify(dev->owner, dev, EV_AUDIO_OFF, dev->id);
        bthf_notify_all(dev, EV_DETACH, MakeParam(((bthf_slc_ind_struct *)para)->passive, dev->id));
        bthf_del_dev(dev->owner, dev);

        break;

    case IND_SCO_DISC:

        dev->state = STATE_SLC_CONN_ED;
        bthf_notify(dev->owner, dev, EV_AUDIO_OFF, dev->id);

        break;

    case CNF_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_cnf_struct *cnf = 
                (bt_hfg_speaker_gain_cnf_struct *)para;
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
            req = bthf_find_req(&dev->req_list, REQ_CHG_VOLUME);
            if (req)
            {
                req->status = REQ_DONE;
                req->retval = (cnf->result == BT_HFG_RESULT_OK) ? E_NONE:E_UNKNOWN;
            }
        }
        break;

    case IND_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_ind_struct *ind = 
                (bt_hfg_speaker_gain_ind_struct *)para;
            dev->spk_gain = ind->gain;
            bthf_notify_all(dev, EV_VOL_CHANGE, MakeParam(ind->gain, dev->id));
        }
        break;
        
    default:
        break;
    }

#endif
    return retval;
}

static BTHFErrCode state_sco_disc(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    
#ifdef __BT_MANUAL_AUDIO_SWITCH__
    bthf_request_struct *req = (bthf_request_struct *)para;

    switch (in) {
    case IND_SCO_CONN:

        bthf_send_msg(MSG_SCO_DISC, dev, 0);

        break;
        
    case IND_SCO_DISC:
    
        dev->state = STATE_SLC_CONN_ED;
        if (dev->flags & FLAG_DETACH)
        {
            bthf_notify(dev->owner, dev, EV_AUDIO_OFF, dev->id);
            bthf_send_msg(MSG_SLC_DISC, dev, 0);
            dev->state = STATE_SLC_DISC;
        }
        else
        {
            req = bthf_find_req(&dev->req_list, REQ_AUDIO_OFF);
            if (req)
            {
                req->status = REQ_DONE;
                if (req->flags & FLAG_ABORT)
                {
                    req->id = REQ_AUDIO_ON;
                    req->retval = E_USER_ABORT;
                }
                else
                {
                    req->retval = E_NONE;
                    bthf_notify(dev->owner, dev, EV_AUDIO_OFF, dev->id);
                }
            }
            else
                bthf_notify(dev->owner, dev, EV_AUDIO_OFF, dev->id);
        }
    
        break;

    case IND_SLC_DISC:

        dev->state = STATE_DEV_IDLE;
        if (dev->flags & FLAG_DETACH)
            req = bthf_find_req(&dev->req_list, REQ_DETACH);
        else
            req = bthf_find_req(&dev->req_list, REQ_AUDIO_OFF);
        if (req)
        {
            req->status = REQ_DONE;
            req->retval = E_NONE;
        }
        bthf_notify(dev->owner, dev, EV_AUDIO_OFF, dev->id);
        bthf_notify_all(dev, EV_DETACH, MakeParam(((bthf_slc_ind_struct *)para)->passive, dev->id));
        bthf_del_dev(dev->owner, dev);

        break;
        

    case CNF_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_cnf_struct *cnf = 
                (bt_hfg_speaker_gain_cnf_struct *)para;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
            req = bthf_find_req(&dev->req_list, REQ_CHG_VOLUME);
            if (req)
            {
                req->status = REQ_DONE;
                req->retval = (cnf->result == BT_HFG_RESULT_OK) ? E_NONE:E_UNKNOWN;
            }
        }
        break;
        
    case IND_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_ind_struct *ind = 
                (bt_hfg_speaker_gain_ind_struct *)para;
            dev->spk_gain = ind->gain;
            bthf_notify_all(dev, EV_VOL_CHANGE, MakeParam(ind->gain, dev->id));
        }
        break;
        
    default:
        break;
    }
#endif
    return retval;
}

static BTHFErrCode state_slc_disc(bthf_device_struct *dev, U32 in, void *para)
{
    BTHFErrCode retval = E_UNKNOWN;
    bthf_request_struct *req = (bthf_request_struct *)para;
    
    switch (in) {
    case IND_SLC_CONN:

        bthf_send_msg(MSG_SLC_DISC, dev, 0);

        break;
        
    case IND_SLC_DISC:
        
        dev->state = STATE_DEV_IDLE;
        req = bthf_find_req(&dev->req_list, REQ_DETACH);
        if (req)
        {
            req->status = REQ_DONE;
            if (req->flags & FLAG_ABORT)
            {
                req->retval = E_USER_ABORT;
                req->id = REQ_ATTACH;
            }
            else
            {
                req->retval = E_NONE;
                bthf_notify_all(dev, EV_DETACH, MakeParam(((bthf_slc_ind_struct *)para)->passive, dev->id));
            }
        }
        else
        {
            bthf_notify_all(dev, EV_DETACH, MakeParam(((bthf_slc_ind_struct *)para)->passive, dev->id));
        }
        
        bthf_del_dev(dev->owner, dev);

        break;

    case CNF_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_cnf_struct *cnf = 
                (bt_hfg_speaker_gain_cnf_struct *)para;
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
            req = bthf_find_req(&dev->req_list, REQ_CHG_VOLUME);
            if (req)
            {
                req->status = REQ_DONE;
                req->retval = (cnf->result == BT_HFG_RESULT_OK) ? E_NONE:E_UNKNOWN;
            }
        }
        break;
        
    case IND_SLC_REQ:
        
        bthf_send_msg(MSG_AUTH_RSP, dev, 0);
        
        break;
        
    case IND_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_ind_struct *ind = 
                (bt_hfg_speaker_gain_ind_struct *)para;
            dev->spk_gain = ind->gain;
            bthf_notify_all(dev, EV_VOL_CHANGE, MakeParam(ind->gain, dev->id));
        }
        break;
        
    default:
        break;
    }

    return retval;
}

static BTHFResult bthf_add_req(
                    bthf_inst_struct *inst,
                    bthf_device_struct *dev,
                    U32 req_id, U32 para)
{
    bthf_request_struct *req;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_ADD_REQ, req_id, para);
    req = bthf_new_req(inst, dev, req_id, para);

    if (ListEmpty(req->list))
    {
        ListAdd(req->list, &req->node);
        
        if (IsServReq(req->id))
            bthf_fsm(&g_service, req->id, req);
        else
            bthf_fsm(ListOwner(req->list, bthf_device_struct, req_list), req->id, req);
        
        if (req->status == REQ_DONE)
            bthf_check_req(req->list);
    }
    else
        ListAdd(req->list, &req->node);

    return RESULT_SUCC;
}

static BTHFResult bthf_insert_req(
                    bthf_inst_struct *inst,
                    bthf_device_struct *dev,
                    U32 req_id, U32 para)
{
    bthf_request_struct *req;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_INSERT_REQ, req_id, para);
    
    req = bthf_new_req(inst, dev, req_id, para);

    if (ListEmpty(req->list))
        ListAdd(req->list, &req->node);
    else 
    {
        bthf_request_struct *head_req = (bthf_request_struct *)ListHead(req->list);
        if (head_req->status == REQ_INIT)
            ListInsert(req->list, &req->node);
        else
        {
            ListInsert(&head_req->node, &req->node);
            return RESULT_SUCC;
        }
    }

    if (IsServReq(req->id))
        bthf_fsm(&g_service, req->id, req);
    else
        bthf_fsm(ListOwner(req->list, bthf_device_struct, req_list), req->id, req);
    if (req->status == REQ_DONE)
        bthf_check_req(req->list);

    return RESULT_SUCC;
}

static void bthf_check_req(bthf_list_struct *req_list)
{
    bthf_list_struct *m, *n;

    ForEachOfListEx(req_list, m, n)
    {
        bthf_request_struct *req = (bthf_request_struct *)m;

        if (req->status == REQ_DONE)
            bthf_req_done(req, req->retval);
    }
    if (!ListEmpty(req_list))
    {
        bthf_request_struct *req = (bthf_request_struct *)ListHead(req_list);
        if (req->status == REQ_INIT)
        {
            if (IsServReq(req->id))
                bthf_fsm(&g_service, req->id, req);
            else
                bthf_fsm(ListOwner(req->list, bthf_device_struct, req_list), req->id, req);
            if (req->status == REQ_DONE)
                bthf_check_req(req_list);
        }
    }
}

static void bthf_req_done(bthf_request_struct *req, U32 retval)
{
    bthf_device_struct *dev;
    
    if (req->id < REQ_END)
        dev = ListOwner(req->list, bthf_device_struct, req_list);
    else
        dev = NULL;

    if (req->owner)
        bthf_notify(req->owner, dev, EV_REQ_RESULT, 
            MakeParam(req->retval, req->id));

    bthf_del_req(req);
}

static void bthf_abort_req(bthf_inst_struct *inst)
{
    bthf_list_struct *m, *n, *b1, *b2;

    /* We only search latest request in device request list.
        since service request could not aborted at all */
    ForEachOfListEx(g_dev_list, m, b1)
    {
        bthf_device_struct *dev = (bthf_device_struct *)m;

        ForEachOfListEx(&dev->req_list, n, b2)
        {
            bthf_request_struct *req = (bthf_request_struct *)n;
            if (req->owner == inst)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_ABORT_REQ, req->id, req->status);
                if (req->status == REQ_INIT)
                    bthf_req_done(req, E_USER_ABORT);
                else if (req->id == REQ_ATTACH || req->id == REQ_AUDIO_ON)
                    req->flags |= FLAG_ABORT;
                break;
            }
        }
    }
}

static BTHFStatus bthf_get_status(bthf_device_struct *dev)
{
    BTHFStatus status;
    
    switch (dev->state) {
    case STATE_SLC_CONN_ED:
    case STATE_SCO_CONN:
    case STATE_SLC_DISC:
        status = STATUS_ATTACH;
        break;

    case STATE_SCO_CONN_ED:
    case STATE_SCO_DISC:
        status = STATUS_AUDIO_ON;
        break;

    default:
        status = STATUS_DETACH;
        break;
    }

    return status;
}

static void bthf_init_setting(bthf_setting_struct *setting)
{
#ifndef __COSMOS_MMI_PACKAGE__
    bthf_setting_struct set;
    S16 err;
    
    ReadRecord(NVRAM_EF_BTHF_CONFIG_LID, 1, &set, sizeof(set), &err);
    if (err == NVRAM_READ_SUCCESS)
    {
        *setting = set;
        if (!setting->mode)
            setting->mode = BTHF_AUD_REMOTE;
    }
    else
#endif
    {
        setting->mode = BTHF_AUD_REMOTE;
        memset(&setting->def_dev, 0, sizeof(setting->def_dev));
        setting->def_dev.lap = 0;
        setting->def_dev.uap = 0;
        setting->def_dev.nap = 0;
#ifndef __COSMOS_MMI_PACKAGE__       
        WriteRecord(NVRAM_EF_BTHF_CONFIG_LID, 1, setting, sizeof(*setting), NULL);
#endif
    }
}

static BTHFResult bthf_save_setting(U32 item, void *value)
{
#ifdef __COSMOS_MMI_PACKAGE__

    return RESULT_SUCC;

#else

    S16 err;
    
    switch (item) {
    case CFG_AUDIO_PATH:
        g_setting.mode = *((U32 *)value);
        break;

    case CFG_DEF_DEVICE:
        g_setting.def_dev = *((BTHFAddr *)value);
        break;

    default:
        return RESULT_FAIL;
    }

    WriteRecord(NVRAM_EF_BTHF_CONFIG_LID, 1, &g_setting, sizeof(g_setting), &err);

    return (err == NVRAM_WRITE_SUCCESS) ? RESULT_SUCC : RESULT_FAIL;
#endif
}

static BTHFResult bthf_reset_setting(U32 item)
{
#ifdef __COSMOS_MMI_PACKAGE__

    return RESULT_SUCC;

#else

    S16 err;
    
    switch (item) {
    case CFG_AUDIO_PATH:
        g_setting.mode = BTHF_AUD_REMOTE;
        break;

    case CFG_DEF_DEVICE:
        memset(&g_setting.def_dev, 0, sizeof(g_setting.def_dev));
        break;

    default:
        return RESULT_FAIL;
    }

    WriteRecord(NVRAM_EF_BTHF_CONFIG_LID, 1, &g_setting, sizeof(g_setting), &err);

    return (err == NVRAM_WRITE_SUCCESS) ? RESULT_SUCC : RESULT_FAIL;
#endif
}


static void * bthf_read_setting(U32 item)
{
    switch (item) {
    case CFG_AUDIO_PATH:
        return &g_setting.mode;

    case CFG_DEF_DEVICE:
        if (!ValidDevice(&g_setting.def_dev))
            return NULL;
        return &g_setting.def_dev;

    default:
        return NULL;
    }
}

/***************************************************************************** 
* BTHF Utilities
*****************************************************************************/
static void bthf_notify(bthf_inst_struct *inst, bthf_device_struct *dev, U32 evt, U32 para)
{
    bthf_notify_struct *notify;
    mmi_event_struct evnt;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_HF_SRV_NOTIFY, evt, para);

    notify = get_ctrl_buffer(sizeof(*notify));
    notify->inst = inst;
    notify->dev = dev;
    notify->evt_id = evt;
    notify->para = para;

    MMI_FRM_INIT_EVENT(&evnt, BTHF_EVENT_ID);

    mmi_frm_post_event((mmi_event_struct *)&evnt, bthf_evt_proc, notify);
}

static void bthf_notify_all(bthf_device_struct *dev, U32 evt, U32 param)
{
    bthf_list_struct *m;

    ForEachOfList(g_inst_list, m)
    {
        bthf_inst_struct *inst = (bthf_inst_struct *)m;
        bthf_notify(inst, dev, evt, param);
    }
}

static void bthf_send_msg(U32 msg, void *para1, U32 para2)
{
    msg_type msg_id;
    module_type dst_mod = MOD_BT;
    local_para_struct *local_para = NULL;
    bthf_device_struct *dev = (bthf_device_struct *)para1;    

    switch (msg) {
    case MSG_ACTIVATE:
        {
            bt_hfg_activate_req_struct *req =
                construct_local_para(sizeof(*req), TD_DL);
            
            req->check_call = bthf_call_status_check;
            local_para = (local_para_struct *)req;
            
            msg_id = MSG_ID_BT_HFG_ACTIVATE_REQ;
        }
        
        break;

    case MSG_DEACTIVATE:
        
        msg_id = MSG_ID_BT_HFG_DEACTIVATE_REQ;
        
        break;

    case MSG_SLC_CONN:
        {
            bt_hfg_connect_req_struct *req = 
                construct_local_para(sizeof(*req), TD_DL);
            
            req->bt_addr = *((bt_dm_addr_struct *)&dev->addr);

            local_para = (local_para_struct *)req;

            if (dev->prof == PROF_HF)
                req->hs_conn = KAL_FALSE;
            else
                req->hs_conn = KAL_TRUE;
#if MMI_MAX_SIM_NUM > 1
            req->sim = srv_bt_cm_get_binding_sim(&dev->addr);
#else
            req->sim = hfg_sim_1;
#endif
            msg_id = MSG_ID_BT_HFG_CONNECT_REQ;
        }
        break;

    case MSG_AUTH_RSP:
        {
            bt_hfg_connect_ind_res_struct *rsp = 
                construct_local_para(sizeof(*rsp), TD_DL);
            
            rsp->result = para2 ? 
                hfg_connect_accept_cnf_result_accepted:
                hfg_connect_accept_cnf_result_rejected;
            rsp->bt_addr = *((bt_dm_addr_struct *)&dev->addr);
            rsp->connection_id = dev->conn_id;
#if MMI_MAX_SIM_NUM > 1
            rsp->sim = srv_bt_cm_get_binding_sim(&dev->addr);
#else
            rsp->sim = hfg_sim_1;
#endif
            local_para = (local_para_struct *)rsp;
            
            msg_id = MSG_ID_BT_HFG_CONNECT_IND_RES;
        }
        break;

    case MSG_SLC_DISC:
        {
            bt_hfg_disconnect_req_struct *req = 
                construct_local_para(sizeof(*req), TD_DL);
            
            req->bt_addr = *((bt_dm_addr_struct *)&dev->addr);
            req->connection_id = dev->conn_id;

            local_para = (local_para_struct *)req;
            msg_id = MSG_ID_BT_HFG_DISCONNECT_REQ;
        }
        break;

    case MSG_SPEAKER_GAIN:
        {
            bt_hfg_speaker_gain_req_struct *req = 
                construct_local_para(sizeof(*req), TD_DL);

            req->gain = (U8)para2;
            req->connection_id = dev->conn_id;

            local_para = (local_para_struct *)req;
            msg_id = MSG_ID_BT_HFG_SPEAKER_GAIN_REQ;
        }
        break;

    case MSG_MIC_GAIN:
        {
            bt_hfg_mic_gain_req_struct *req = 
                construct_local_para(sizeof(*req), TD_DL);

            req->gain = (U8)para2;
            req->connection_id = dev->conn_id;

            local_para = (local_para_struct *)req;
            msg_id = MSG_ID_BT_HFG_MIC_GAIN_REQ;
        }
        break;

    case MSG_SCO_CONN:
        {
            bt_hfg_sco_connect_req_struct *req = 
                construct_local_para(sizeof(*req), TD_DL);

            req->connection_id = dev->conn_id;

            local_para = (local_para_struct *)req;
            msg_id = MSG_ID_BT_HFG_SCO_CONNECT_REQ;
        }
        break;

    case MSG_SCO_DISC:
        {
            bt_hfg_sco_disconnect_req_struct *req = 
                construct_local_para(sizeof(*req), TD_DL);

            req->connection_id = dev->conn_id;

            local_para = (local_para_struct *)req;
            msg_id = MSG_ID_BT_HFG_SCO_DISCONNECT_REQ;
        }
        break;

    case MSG_VOLUME_REQ:
        {
            bt_hfg_speaker_gain_req_struct *req = 
                construct_local_para(sizeof(*req), TD_CTRL);

            req->gain = (U8)para2;
            req->connection_id = (U32)para1;

            local_para = (local_para_struct *)req;
            msg_id = MSG_ID_BT_HFG_SPEAKER_GAIN_REQ;
            dst_mod = MOD_MMI;
        }
        break;

    default:
        return;
    }

    msg_send5(stack_get_active_module_id(),
        dst_mod, BT_APP_SAP, msg_id, local_para);
}

static bthf_inst_struct *bthf_new(void)
{
    bthf_inst_struct *inst = NULL;
    U32 i;

    for (i = 0; i < BTHF_MAX_INSTANCE; i++)
    {
        if (g_insts[i].handle == 0)
        {
            inst = &g_insts[i];
            break;
        }
    }

    if (inst != NULL)
    {
        inst->handle = MakeHandle(inst);
        inst->setting = g_setting;
        inst->prof = BTHF_PROF_AUTO;

        ListAdd(g_inst_list, &inst->node);
    }

    return inst;
}


static void bthf_delete(bthf_inst_struct *inst)
{
    if (!in_list(g_inst_list, &inst->node))
        return;

    inst->handle = 0;

    ListDelete(&inst->node);
}

static bthf_inst_struct *bthf_find(S32 handle)
{
    bthf_inst_struct *inst;
    bthf_list_struct *m;

    ForEachOfList(g_inst_list, m)
    {
        inst = (bthf_inst_struct *)m;
        if (inst->handle == handle)
            return inst;
    }

    return NULL;
}

static bthf_device_struct *bthf_new_dev(
                            bthf_inst_struct *inst, 
                            BTHFAddr *addr,
                            U32 prof,
                            MMI_BOOL incoming)
{
    /* SRV_BT_AV_MAJOR_DEVICE_MASK|SRV_BT_CAR_AUDIO_AV_MINOR_DEVICE_CLASS */
    U32 carkit = 0x000420;
    U32 i, cod;
    bthf_device_struct *dev = NULL;
    S32 conn_id;

    for (i = 0; i < BTHF_MAX_CONNECTION; i++)
    {
        dev = &g_devs[i];
        if (!dev->id)
            break;
    }

    if (i == BTHF_MAX_CONNECTION)
        return NULL;

    if (g_service.state != STATE_ACTIVATE_ED)
        return NULL;

    if (incoming)
    {
        U8 bd_addr[6], *dev_name;
        CONVERT_BDADDR2ARRAY(bd_addr, addr->lap, addr->uap, addr->nap);
        dev_name = BTBMGetLocalStoredName(bd_addr);
        conn_id = srv_bt_cm_start_conn(incoming, SRV_BT_CM_HFG_PROFILE_UUID, addr, (CHAR *)dev_name);
    }
    else
    {
        conn_id = srv_bt_cm_start_conn(incoming, SRV_BT_CM_HFG_PROFILE_UUID, addr, NULL);
    }

    if (conn_id < 0)
        return NULL;

    dev->id = MakeDevID(dev);
    dev->incoming = incoming;
    dev->conn_id = 0xFFFFFFFF;
    dev->cmgr_id = conn_id;
    
    dev->addr = *addr;
    dev->owner = inst;

    dev->state = STATE_DEV_IDLE;

    ListInit(&dev->req_list);

    dev->prof = prof;

    cod = srv_bt_cm_get_dev_cod(addr);
    if ((cod & 0x1FFF) == carkit)
        dev->dev_class = BTHF_DEV_CARKIT;
    else
        dev->dev_class = BTHF_DEV_HEADSET;

    dev->mic_gain = dev->spk_gain = 0;

    ListAdd(g_dev_list, &dev->node);

    g_dev_count++;

    return dev;
}


static void bthf_del_dev(bthf_inst_struct *inst, bthf_device_struct *dev)
{
    bthf_list_struct *m, *n;
    U32 cmgr_id;
    
    if (!dev || dev->owner != inst)
        return;
    
    if (!in_list(g_dev_list, &dev->node))
        return;

    if (!ListEmpty(&dev->req_list) && !(dev->flags & FLAG_DELETE))
    {
        ForEachOfListEx(&dev->req_list, m, n)
        {
            bthf_request_struct *req = (bthf_request_struct *)m;
            if (req->status == REQ_DONE)
                bthf_req_done(req, req->retval);
            else
                bthf_req_done(req, E_USER_ABORT);
        }
        dev->flags |= FLAG_DELETE;

        return;
    }

    cmgr_id = dev->cmgr_id;

    dev->id = 0;
    dev->flags = 0;
    dev->cmgr_id = 0;

    ListDelete(&dev->node);

    srv_bt_cm_stop_conn(cmgr_id);

    /* We check previously set flag to see whether 
        any following job need to be done */
    if (dev->owner)
    {
        dev->owner->dev_count--;
        
        if (dev->owner->dev_count == 0)
        {
            if (dev->owner->flags & FLAG_DELETE)
                bthf_delete(dev->owner);
        }
    }
    
    g_dev_count--;

    if (g_dev_count == 0 && g_service.flags & FLAG_DISABLE)
    {
        g_service.flags &= ~FLAG_DISABLE;
        bthf_add_req(g_service.owner, NULL, REQ_DISABLE, 0);
    }
}

static bthf_device_struct *bthf_find_dev(U32 key, void *value)
{
    bthf_list_struct *m;
    bthf_device_struct *dev;

    ForEachOfList(g_dev_list, m)
    {
        dev = (bthf_device_struct *)m;
        if (dev->id == 0)
            continue;

        switch (key) {
        case FIND_BY_ADDR:
            {
                BTHFAddr *addr = (BTHFAddr *)value;
                if (SameDevice(addr, &dev->addr))
                    return dev;
            }
            break;

        case FIND_BY_DEV_ID:
            {
                U32 id = *((U32 *)value);
                if (id == dev->id)
                    return dev;
            }
            break;

        case FIND_BY_CMGR_ID:
            {
                U32 id = *((U32 *)value);
                if (id == dev->cmgr_id)
                    return dev;
            }
            break;
            
        case FIND_BY_CONN_ID:
            {
                U32 conn_id = *((U32 *)value);
                if (dev->conn_id == 0xFFFFFFFF ||
                    conn_id == dev->conn_id)
                    return dev;
            }
            break;

        default:
            break;
        }
    }

    return NULL;
}

static bthf_request_struct * bthf_new_req(
                                bthf_inst_struct *inst,
                                bthf_device_struct *dev,
                                U32 req_id, U32 para)
{
    bthf_request_struct *req;

    req = get_ctrl_buffer(sizeof(*req));
    req->owner = inst;
    req->para = para;

    req->status = REQ_INIT;
    req->retval = 0;
    req->flags = 0;

    if (req_id == REQ_ENABLE || 
        req_id == REQ_DISABLE)
    {
        req->id = req_id | 0x10000000;
        req->list = &g_service.req_list;
    }
    else
    {
        req->id = req_id;
        req->list = &dev->req_list;
    }

    return req;
}

static void bthf_del_req(bthf_request_struct *req)
{
    if (!req) return;
    
    if (in_list(req->list, &req->node))
        ListDelete(&req->node);

    free_ctrl_buffer(req);
}

static bthf_request_struct *bthf_find_req(bthf_list_struct *list, U32 req_id)
{
    bthf_list_struct *m;

    ForEachOfList(list, m)
    {
        bthf_request_struct *req = (bthf_request_struct *)m;
        if (RawID(req->id) == req_id && req->status == REQ_START)
            return req;
    }

    return NULL;
}

static MMI_BOOL bthf_serv_avail(void)
{
	return ( (g_service.state == STATE_ACTIVATE_ED)?MMI_TRUE:MMI_FALSE );
}


static MMI_BOOL in_list(bthf_list_struct *list, bthf_list_struct *node)
{
    bthf_list_struct *m;

    ForEachOfList(list, m)
    {
        if (m == node)
            return MMI_TRUE;
    }

    return MMI_FALSE;
}

#endif /* __MMI_HFP_SUPPORT__ */


