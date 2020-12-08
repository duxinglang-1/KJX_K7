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
 *   PnSrvMain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Push notification service.
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
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "mmi_features.h"

#ifdef __MMI_PNS__

#include "app_str.h"
#include "MMIDataType.h"
#include "app_datetime.h"
#include "DateTimeGprot.h"
#include "PnSrvGprot.h"
#include "PnSrvProt.h"
#include "ModeSwitchSrvGProt.h"
#include "mmi_rp_srv_pns_def.h"
#include "CbmSrvGprot.h"
#include "CbmSrvIprot.h"
#include "SimCtrlSrvGprot.h"

#include "hpnsappengine.h"
#include "hpnsplatform.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "pns_trc.h"

#include "jansson.h"

/****************************************************************************
* Global Variable
*****************************************************************************/
extern void srv_pnsi_nms_rsp(SNmsQueueMsgStruct *pHpnsMsg);
extern void srv_pns_send_reg_req(SHpnsRegInfo *reg);;
extern S32 srv_pns_send_query(U32 appId, char* buffer, U32 buffer_size);
extern kal_uint8 cbm_get_app_id(kal_uint32 acct_id);
extern kal_int8  cbm_get_bearer_type(kal_uint32 account_id, cbm_bearer_enum *bearer_type);
extern kal_int32 cbm_get_bearer_status(kal_uint32 account_id);

/****************************************************************************
* Static Variable
*****************************************************************************/

static srv_pns_request_element_struct* g_pns_request_ptr;
static srv_pns_request_element_struct* g_pns_request_tail;
static srv_pns_msg_cb_struct* g_pns_msg_head;
static srv_pns_msg_cb_struct* g_pns_msg_tail;
static mmi_ret srv_pns_cbm_info_callback(mmi_event_struct *param);

static MMI_BOOL g_pns_change_sim;
static mmi_proc_func g_force_close_cb;
static void* g_force_close_user_data;

//static srv_pns_statistic_duration_struct* g_pns_app_duration_head;
//static srv_pns_statistic_duration_struct* g_pns_app_duration_tail;
//static srv_pns_statistic_struct g_pns_statistics[SRV_PNS_MAX_BUNDLE_APP];

static srv_pns_result srv_pnsi_transfer_hpns_err(S32 hpnsErrCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_result err = SRV_PNS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hpnsErrCode)
    {
        case 0:
            break;
        case HPNS_SERVICE_NOT_AVAILABLE:
            err = SRV_PNS_SERVICE_NOT_AVAILABLE;
            break;
        case HPNS_TOO_MANY_REGISTRATIONS:
            err = SRV_PNS_TOO_MANY_REGISTRATIONS;
            break;
        case HPNS_INVALID_DATA_CONNECTION:
            err = SRV_PNS_INVALID_DATA_CONNECTION;
            break;
        case HPNS_LAST_MSG_ON_PROCESSING:
            err = SRV_PNS_LAST_MSG_ON_PROCESSING;
            break;
        case HPNS_INVALID_SENDER:
            err = SRV_PNS_INVALID_SENDER;
            break;
        case HPNS_INVALID_APPID:
            err = SRV_PNS_INVALID_APPID;
            break;
        case HPNS_SYSTEM_ERROR:
        default:
            err = SRV_PNS_SYSTEM_ERROR;
            break;
    }

    return err;
}

#define PNS_INTERNAL_REQ_QUEUE_API

static srv_pns_request_element_struct* srv_pnsi_find_req(U32 appId, MMI_BOOL reg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_request_element_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = g_pns_request_ptr;
    
    while (req)
    {
        if (req->reg == reg)
        {
            if (req->reg && req->request.reg.appId == appId)
            {
                /* register request */
                break;
            }
            else if (!req->reg && req->request.dereg.appId == appId)
            {
                /* deregister request */
                break;
            }
        }
        else if (reg)
        {
            if (!req->reg && req->request.dereg.appId == appId)
            {
                /* The register request of this appid was removed by itself because we found it's deregister request first. */
                req = NULL;
                break;
            }
        }
            

        req = req->next;
    }

    SRV_PNS_TRACE2(TRC_SRV_PNS_166be444de2146db8c5fa64f942a5de4, reg, (req != NULL)? 1 : 0);
    return req;
}

static void srv_pnsi_push_req_element(U32 appId, char* senderId, mmi_proc_func cb, void* user_data, MMI_BOOL reg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_request_element_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (srv_pns_request_element_struct*)OslMalloc(sizeof(srv_pns_request_element_struct));
    memset(req, 0, sizeof(srv_pns_request_element_struct));
    req->reg = reg;
    req->request.reg.appId = appId;
    if (senderId) app_strlcpy((kal_char*)req->request.reg.senderId, (const kal_char*)senderId, SRV_PNS_SENDERID_LEN);
    req->request.reg.cb = cb;
    req->request.reg.user_data = user_data;

    if (g_pns_request_ptr != NULL && g_pns_request_tail != NULL)
    {
        g_pns_request_tail->next = req;
        req->pre = g_pns_request_tail;
        g_pns_request_tail = req;
    }
    else
    {
        req->next = NULL;
        g_pns_request_ptr = req;
        g_pns_request_tail = req;
    }
}

static void srv_pnsi_pop_req_element(U32 appId, MMI_BOOL reg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_request_element_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = srv_pnsi_find_req(appId, reg);
    if (req != NULL)
    {
        if (req->pre) req->pre->next = req->next;
        if (req->next) req->next->pre = req->pre;

        if (g_pns_request_ptr == req) g_pns_request_ptr = req->next;
        if (g_pns_request_tail == req) g_pns_request_tail = req->pre;

        OslMfree(req);
    }
}

static void srv_pnsi_process_next_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_request_element_struct *req = NULL;
    SHpnsRegInfo pRegInfo;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pns_request_ptr)
    {
        req = g_pns_request_ptr;

        if (req->reg)
        {
            pRegInfo.appId = req->request.reg.appId;
            app_strlcpy((kal_char*)pRegInfo.senderId, (const kal_char*)req->request.reg.senderId, SRV_PNS_SENDERID_LEN);
            srv_pns_send_reg_req(&pRegInfo);
        }
        else
        {
            srv_pns_send_dereg_req(req->request.dereg.appId);
        }
    }
}

#define PNS_INTERNAL_MSG_QUEUE_API

static srv_pns_msg_cb_struct* srv_pnsi_find_msg_cb(U32 appId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_msg_cb_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = g_pns_msg_head;
    
    while (node)
    {
        if (node->appId == appId)
        {
            /* Got it */
            break;
        }

        node = node->next;
    }

    return node;
}

static void srv_pnsi_push_msg_cb_element(U32 appId, mmi_proc_func cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_msg_cb_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_pns_msg_cb_struct*)OslMalloc(sizeof(srv_pns_msg_cb_struct));
    memset(node, 0, sizeof(srv_pns_msg_cb_struct));
    node->appId = appId;
    node->cb = cb;
    node->user_data = user_data;

    if (g_pns_msg_head != NULL && g_pns_msg_tail != NULL)
    {
        g_pns_msg_tail->next = node;
        node->pre = g_pns_msg_tail;
        g_pns_msg_tail = node;
    }
    else
    {
        node->next = NULL;
        g_pns_msg_head = node;
        g_pns_msg_tail = node;
    }
}

static void srv_pnsi_pop_msg_cb_element(U32 appId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_msg_cb_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = srv_pnsi_find_msg_cb(appId);
    if (node != NULL)
    {
        if (node->pre) node->pre->next = node->next;
        if (node->next) node->next->pre = node->pre;

        if (g_pns_msg_head == node) g_pns_msg_head = node->next;
        if (g_pns_msg_tail == node) g_pns_msg_tail = node->pre;

        OslMfree(node);
    }
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
#endif

#define PNS_RESPONSE_HANDLER

void srv_pnsi_handle_request_rsp(SHpnsRegInfo* pRegInfo, U32 MsgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 appId;
    srv_pns_request_element_struct* req = NULL;
    
    union {
        srv_pns_reg_rsp_event_struct reg;
        srv_pns_dereg_rsp_event_struct dereg;
    } evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    appId = pRegInfo->appId;
    
    SRV_PNS_TRACE2(TRC_SRV_PNS_5fb17f944d1344d689c7687b93c17ae3, MsgType, pRegInfo->appCode);
    switch (MsgType)
    {
        case HPNS_MSG_REG_RSP:
        {
            req = srv_pnsi_find_req(appId, MMI_TRUE);
            if (req != NULL)
            {
                /* The request in the queue */
                if (req->request.reg.cb)
                {
                    MMI_FRM_INIT_EVENT(&evt.reg, EVT_ID_SRV_PNS_REGISTER_RSP);
                    evt.reg.appId = pRegInfo->appId;
                    evt.reg.result = srv_pnsi_transfer_hpns_err(pRegInfo->appCode);
                    if (pRegInfo->appCode == 0)
                    {
                        app_strlcpy((kal_char*)evt.reg.reg_id, (const kal_char*)pRegInfo->regId, SRV_PNS_REGID_LEN);
                    }
                    
                    MMI_FRM_SEND_EVENT(&evt.reg, req->request.reg.cb, req->request.reg.user_data);
                }
                srv_pnsi_pop_req_element(appId, MMI_TRUE);
            }
            /* Process next request */
            srv_pnsi_process_next_req();
            break;
        }
        case HPNS_MSG_UNREG_RSP:
        {
            req = srv_pnsi_find_req(appId, MMI_FALSE);
            if (req != NULL)
            {
                /* The request in the queue */
                if (req->request.dereg.cb)
                {
                    MMI_FRM_INIT_EVENT(&evt.dereg, EVT_ID_SRV_PNS_DEREGISTER_RSP);
                    evt.dereg.appId = pRegInfo->appId;
                    evt.dereg.result = srv_pnsi_transfer_hpns_err(pRegInfo->appCode);
                    
                    MMI_FRM_SEND_EVENT(&evt.dereg, req->request.dereg.cb, req->request.dereg.user_data);
                }
                srv_pnsi_pop_req_element(appId, MMI_FALSE);
            }
            /* Clear msg callback */
            srv_pnsi_pop_msg_cb_element(appId);
            
            /* Process next request */
            srv_pnsi_process_next_req();
            break;
        }
    }
}

void srv_pnsi_handle_unsolicited_msg(SHpnsRegInfo* pRegInfo, U32 MsgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 appId;
    U32 msgLen = 0;
    srv_pns_msg_cb_struct* node = NULL;
    
    union {
        srv_pns_msg_event_struct msg;
        srv_pns_change_reg_event_struc change_reg;
    } evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    appId = pRegInfo->appId;
    SRV_PNS_TRACE1(TRC_SRV_PNS_57fa5f4bbbe34a4ab6b21a8a7ce0fb96, MsgType);
    switch (MsgType)
    {
        case HPNS_MSG_NOTIFICATION:
        {
            node = srv_pnsi_find_msg_cb(appId);
            if (node != NULL && node->cb != NULL)
            {
                MMI_FRM_INIT_EVENT(&evt.msg, EVT_ID_SRV_PNS_MESSAGE);
                evt.msg.appId = appId;
                msgLen = strlen((CHAR *)pRegInfo->payload);
                if (msgLen >= SRV_PNS_MAX_MSGBODY_SIZE) msgLen = (SRV_PNS_MAX_MSGBODY_SIZE-1);
                evt.msg.msgLen = msgLen;
                evt.msg.msgBody = (char*)OslMalloc(evt.msg.msgLen+1);
                memset(evt.msg.msgBody, 0, (evt.msg.msgLen+1));
                app_strlcpy((kal_char*)evt.msg.msgBody, (const kal_char*)pRegInfo->payload, (evt.msg.msgLen+1));

                MMI_FRM_SEND_EVENT(&evt.msg, node->cb, node->user_data);
                OslMfree(evt.msg.msgBody);

                /* Notify PE */
                srv_pns_send_msg_rsp(appId);
            }
            break;
        }
        case HPNS_MSG_REGID_CHANGED_NOTIFICATION:
        {
            node = srv_pnsi_find_msg_cb(appId);
            if (node != NULL && node->cb != NULL)
            {
                /* find msg callback node */
                MMI_FRM_INIT_EVENT(&evt.change_reg, EVT_ID_SRV_PNS_REGISTRATION_ID_CHANGED);
                evt.change_reg.appId = appId;
                app_strlcpy((kal_char*)evt.change_reg.reg_id, (const kal_char*)pRegInfo->regId, SRV_PNS_REGID_LEN);

                MMI_FRM_SEND_EVENT(&evt.change_reg, node->cb, node->user_data);
            }
            break;
        }
        default:
            break;
    }
}

#define PNS_EXTERNAL_API

void srv_pns_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 appId = 0;
    mmi_event_struct evt;
    mmi_ret ret = MMI_RET_ERR;
    srv_pns_global_setting_enum config;
    U32 hpns_config = HPNS_PUSH_NOTIFICATION_ON;
    U32 accountId = 0;
    srv_cbm_result_error_enum cbm_ret = SRV_CBM_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(g_pns_statistics, 0, sizeof(srv_pns_statistic_struct)*SRV_PNS_MAX_BUNDLE_APP);
    //ReadMultiRecord(NVRAM_EF_SRV_PNS_APP_STATISTIC_LID, 1, g_pns_statistics, sizeof(srv_pns_statistic_struct)*SRV_PNS_MAX_BUNDLE_APP, SRV_PNS_MAX_BUNDLE_APP, &error);

    nmsCreateLocalMemoryPool();
	SetProtocolEventHandler(srv_pnsi_nms_rsp,MSG_ID_MSG_TO_MMI_FROM_NMS);		
	hpnsInitTask();

    g_pns_request_ptr = g_pns_request_tail = NULL;
    g_pns_msg_head = g_pns_msg_tail = NULL;
    g_force_close_cb = NULL;
    g_force_close_user_data = NULL;
    //g_pns_app_duration_head = g_pns_app_duration_tail = NULL;

    config = srv_pns_get_global_setting();
    if (config == SRV_PNS_SETTING_OFF)
    {
        hpns_config = HPNS_PUSH_NOTIFICATION_OFF;
    }
    if (hpns_config != hpnsApiGetPushServiceStatus())
    {
        hpnsSendMsgToEngine(HPNS_MSG_PUSH_NOTIFICATION_SWITCH,(kal_uint8*)hpns_config,0);
    }
    /* TODO: Should we check if the AppId's registration were removed by push server. Or wait for engine call reset? */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* Broadcast */
    memset(&evt, 0, sizeof(evt));
    evt.evt_id = EVT_ID_SRV_PNS_START_REGISTER;
    evt.size = sizeof(evt);

    ret = mmi_frm_cb_emit_event(&evt);
	kal_prompt_trace(MOD_MMI, "srv_pns_init mmi_frm_cb_emit_event = d%",ret);
    accountId = hpnsGetNwkNetAcctId();
    appId = cbm_get_app_id(accountId);
    ret = srv_cbm_register_bearer_info(appId, SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED, SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI, srv_pns_cbm_info_callback, NULL);
	kal_prompt_trace(MOD_MMI, "srv_pns_init srv_cbm_register_bearer_info = d%",ret);
    cbm_ret = srv_cbm_register_bearer_event(SRV_CBM_BEARER_EVENT_SWITCH|SRV_CBM_BEARER_EVENT_DISCONNECT, appId, srv_pns_cbm_event_receiver, NULL);
    SRV_PNS_TRACE1(TRC_SRV_PNS_fd44c8688a0740e8995ab4127f02a2d2, cbm_ret);
}

srv_pns_result srv_pns_register(U32 appId, char* senderId, mmi_proc_func cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_result result = SRV_PNS_NO_ERROR;
    SHpnsRegInfo pRegInfo;
    srv_pns_request_element_struct *req = NULL;
    srv_pns_reg_rsp_event_struct reg;
    char regId[SRV_PNS_REGID_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        if (srv_pns_get_global_setting() == SRV_PNS_SETTING_OFF)
        {
            result = SRV_PNS_NOTIFICATION_OFF;
            break;
        }

	    if (g_pns_request_ptr == NULL)
        {
            /* Request queue is empty */
            srv_pnsi_push_req_element(appId, senderId, cb, user_data, MMI_TRUE);

    	    pRegInfo.appId = appId;
            app_strlcpy((kal_char*)pRegInfo.senderId, (const kal_char*)senderId, SRV_PNS_SENDERID_LEN);
            srv_pns_send_reg_req(&pRegInfo);
        }
        else
        {
            /* Check if the deregister request already exists or not */
            req = srv_pnsi_find_req(appId, MMI_FALSE);
            if (req != NULL)
            {
                /* There is a register request of this appId in the queue */
                if (req == g_pns_request_ptr)
                {
                    /* The request is waitting response so the register request should be pushed into queue */
                    srv_pnsi_push_req_element(appId, senderId, cb, user_data, MMI_TRUE);
                }
                else
                {
                    /* The reg requst is in queue and not waitting for response */
                    if (srv_pns_query_regid(appId, regId, SRV_PNS_REGID_LEN) < SRV_PNS_NO_ERROR)
                    {
                        srv_pnsi_push_req_element(appId, senderId, cb, user_data, MMI_TRUE);
                    }
                    else
                    {
                        if (cb)
                        {
                            MMI_FRM_INIT_EVENT(&reg, EVT_ID_SRV_PNS_REGISTER_RSP);
                            reg.appId = appId;
                            reg.result = SRV_PNS_NO_ERROR;
                            app_strlcpy((kal_char*)reg.reg_id, (const kal_char*)regId, SRV_PNS_REGID_LEN);
                            
                            MMI_FRM_POST_EVENT(&reg, cb, user_data);
                        }
                    }
                }
                /* Popup deregister request */
                srv_pnsi_pop_req_element(appId, MMI_FALSE);
                break;
            }
            else
            {
                /* Check if the request already exists or not */
                req = srv_pnsi_find_req(appId, MMI_TRUE);
                if (req != NULL)
                {
                    /* Already exists */
                    result = SRV_PNS_ALREADY_IN_QUEUE;
                    break;
                }
            }

            /* Push the request into queue */
            srv_pnsi_push_req_element(appId, senderId, cb, user_data, MMI_TRUE);
        }
    } while(0);

    SRV_PNS_TRACE1(TRC_SRV_PNS_b389d98874e94a3397f7a803beb9c26a, result);
    return result;
}

srv_pns_result srv_pns_deregister(U32 appId, mmi_proc_func cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_result result = SRV_PNS_NO_ERROR;
    srv_pns_request_element_struct *req = NULL;
    srv_pns_dereg_rsp_event_struct dereg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
	    if (g_pns_request_ptr == NULL)
        {
            /* Request queue is empty */
            srv_pnsi_push_req_element(appId, NULL, cb, user_data, MMI_FALSE);
            srv_pns_send_dereg_req(appId);
        }
        else
        {
            /* Check if the register request already exists or not */
            req = srv_pnsi_find_req(appId, MMI_TRUE);
            if (req != NULL)
            {
                /* There is a register request of this appId in the queue */
                if (req == g_pns_request_ptr)
                {
                    /* The request is waitting response so the deregister request should be pushed into queue */
                    srv_pnsi_push_req_element(appId, NULL, cb, user_data, MMI_FALSE);
                }
                else
                {
                    /* The reg requst is in queue and not waitting for response */
                    if (cb)
                    {
                        MMI_FRM_INIT_EVENT(&dereg, EVT_ID_SRV_PNS_DEREGISTER_RSP);
                        dereg.evt_id = EVT_ID_SRV_PNS_DEREGISTER_RSP;
                        dereg.appId = appId;
                        dereg.result = SRV_PNS_NO_ERROR;
                        
                        MMI_FRM_POST_EVENT(&dereg, cb, user_data);
                    }
                }
                /* Popup register request */
                srv_pnsi_pop_req_element(appId, MMI_TRUE);
                break;
            }
            else
            {
                /* There is no register request of this appId in the queue */
                /* Check if the request already exists or not */
                req = srv_pnsi_find_req(appId, MMI_FALSE);
                if (req != NULL)
                {
                    /* Already exists */
                    result = SRV_PNS_ALREADY_IN_QUEUE;
                    break;
                }
            }

            /* Push the request into queue */
            srv_pnsi_push_req_element(appId, NULL, cb, user_data, MMI_FALSE);
        }
    } while(0);
    SRV_PNS_TRACE1(TRC_SRV_PNS_c284149e950c436f95a993fe69b2c20a, result);
    return result;
}

srv_pns_result srv_pns_setup_receive_cb(U32 appId, mmi_proc_func cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_result result = SRV_PNS_NO_ERROR;
    srv_pns_msg_cb_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        if (g_pns_msg_head == NULL)
        {
            /* Message callback queue is empty */
            srv_pnsi_push_msg_cb_element(appId, cb, user_data);
            break;
        }
        else
        {
            node = srv_pnsi_find_msg_cb(appId);
            if (node != NULL)
            {
                //result = SRV_PNS_ALREADY_IN_QUEUE;
                /* Replace the old one */
                node->cb = cb;
                node->user_data = user_data;
                break;
            }
            srv_pnsi_push_msg_cb_element(appId, cb, user_data);
        }
    } while(0);
    SRV_PNS_TRACE1(TRC_SRV_PNS_113f6e4db9bb4bf1976b664e527c1cb1, result);
    return result;
}

MMI_BOOL srv_pns_has_custom_payload(char* msgBody)
{
    /*----------------------------------------------------------------*/
    U16 i = 0;
    MMI_BOOL result = MMI_FALSE;
    S32 payloadArrayNum = 0;
    json_t *root = NULL;
    json_error_t error;
    json_t* item = NULL;
    json_t* mpsObj = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgBody == NULL)
    {
        SRV_PNS_TRACE2(TRC_SRV_PNS_37cc3d31c15e46ef8dee105cee153ab2, 1, result);
        return result;
    }

    do {
        root = json_loads(msgBody, 0, &error);
        if (root == NULL || !json_is_array(root))
        {
            SRV_PNS_TRACE2(TRC_SRV_PNS_37cc3d31c15e46ef8dee105cee153ab2, 2, result);
            break;
        }

        payloadArrayNum = json_array_size(root);
        if (payloadArrayNum > 1)
        {
            /* There are more than one objects in the payload */
            for (i = 0; i < payloadArrayNum; i++)
            {
                /* Check all objects */
                item = json_array_get(root, i);
                if (!json_is_object(item))
                {
                    /* Wrong format */
                    break;
                }
            }
            if (i == payloadArrayNum)
            {
                result = MMI_TRUE;
            }
            SRV_PNS_TRACE2(TRC_SRV_PNS_37cc3d31c15e46ef8dee105cee153ab2, 3, result);
        }
        else if (payloadArrayNum == 1)
        {
            item = json_array_get(root, payloadArrayNum);
            if (!json_is_object(item))
            {
                break;
            }
            mpsObj = json_object_get(item, "mps");
            if (mpsObj == NULL)
            {
                /* There is only one object and it's not mps. So it must be custom payload */
                result = MMI_TRUE;
                break;
            }
        }
    } while(0);

    if (root)
    {
        json_decref(root);
    }
    SRV_PNS_TRACE2(TRC_SRV_PNS_37cc3d31c15e46ef8dee105cee153ab2, 4, result);
    return result;
}

void srv_pns_switch_global_setting(srv_pns_global_setting_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (flag)
    {
        case SRV_PNS_SETTING_ON:
            hpnsSendMsgToEngine(HPNS_MSG_PUSH_NOTIFICATION_SWITCH,(kal_uint8*)HPNS_PUSH_NOTIFICATION_ON,0);
            temp = 1;
            break;
        case SRV_PNS_SETTING_OFF:
            hpnsSendMsgToEngine(HPNS_MSG_PUSH_NOTIFICATION_SWITCH,(kal_uint8*)HPNS_PUSH_NOTIFICATION_OFF,0);
            temp = 0;
            break;
        default:
            return;
            //break;
    }

    WriteValue(NVRAM_PNS_SWITCH, &temp, DS_BYTE, &error);
}

srv_pns_global_setting_enum srv_pns_get_global_setting()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 temp;
    srv_pns_global_setting_enum result = SRV_PNS_SETTING_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_PNS_SWITCH, &temp, DS_BYTE, &error);
    if(error == NVRAM_READ_SUCCESS)
    {
        result = (temp == 1)? SRV_PNS_SETTING_ON : SRV_PNS_SETTING_OFF;
    }
    return result;
}
#if 0  // these two api will not used current 
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
#endif
srv_pns_result srv_pns_query_regid(U32 appId, char* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pns_result result = SRV_PNS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        if (buffer == NULL || buffer_size < SRV_PNS_REGID_LEN)
        {
            result = SRV_PNS_PARAM_ERR;
            break;
        }

        memset(buffer, 0, buffer_size);
        
        if (srv_pns_send_query(appId, buffer, buffer_size) < 0)
        {
            result = SRV_PNS_QUERY_FAIL;
        }
    } while(0);

    SRV_PNS_TRACE1(TRC_SRV_PNS_14da7cb659d84555ac66f20dca38267c, result);
    return result;
}

mmi_ret srv_pns_cbm_event_receiver(mmi_event_struct *param)
{
    srv_cbm_bearer_event_struct *event = (srv_cbm_bearer_event_struct*)param;
    switch(event->type)
    {
        case SRV_CBM_BEARER_EVENT_DISCONNECT:
        {
            SRV_PNS_TRACE0(TRC_SRV_PNS_cc5b0ae0b7314ded9b178ec16ce64a64);
            hpnsApiChangeNetworkStatusOff();
            break;
        }
        case SRV_CBM_BEARER_EVENT_SWITCH:
        {
            kal_uint32 switch_to = 0;
            if (event->user_result)
            {
                switch (event->switch_type)
                {
                    case SRV_CBM_BEARER_SWITCH_WIFI_TO_PS:
                        switch_to = HPNS_APN_GPRS;
                        break;
                    default:
                        switch_to = HPNS_APN_WIFI;
                        break;
                }
                if (srv_pns_get_global_setting() == SRV_PNS_SETTING_ON)
                {
                    hpnsApiChangeNetworkStatusOn(switch_to);
                }
            }
            SRV_PNS_TRACE2(TRC_SRV_PNS_cbe721a3d3484328bbe7598d22725712, event->user_result, switch_to);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

static mmi_ret srv_pnsi_nmgr_proc(mmi_event_struct *evt)
{
    if(evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
        /* Press "Ok" */
        mmi_event_struct evt;
        //mmi_ret ret = 0;
        
        SRV_PNS_TRACE0(TRC_SRV_PNS_8ce568f74b8a44b49c089d7f797172be);
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PNS_ENTER_NS);
        mmi_frm_cb_emit_event(&evt);
    }   
    else if(evt->evt_id == EVT_ID_NMGR_ALERT_END)
    {
        /* Press "Cancel" */
        SRV_PNS_TRACE0(TRC_SRV_PNS_68bda4ef7ba545f9abd0adb383dc811c);
    }
    return MMI_TRUE;
}


void srv_pns_show_confrim_with_user()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_alert_struct *alert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alert = (mmi_frm_nmgr_alert_struct*)OslMalloc(sizeof(mmi_frm_nmgr_alert_struct));
    memset(alert, 0, sizeof(mmi_frm_nmgr_alert_struct));

    alert->app_id = 0;
    alert->scen_id = MMI_SCENARIO_ID_MRE_PUSH;
    alert->event_type = MMI_EVENT_MRE_PUSH;
    /*fill in the notification information, if your app¡¦s notification can be controlled by NSS, your UI mask must include icon, status bar and popup*/
    alert->ui_mask = MMI_FRM_NMGR_UI_POPUP_MASK;
    /*Once the NSS is not support , NMGR will take the behavior mask as its behavior guildline*/
    alert->behavior_mask = FORCE_POPUP;

    alert->popup_para.image_type = MMI_NMGR_IMG_RES_ID;
    alert->popup_para.image.id = IMG_GLOBAL_QUESTION;
    alert->popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    alert->popup_para.popup_string = (WCHAR*)GetString(STR_ID_PNS_BACKGROUND_DATA_ON);
    alert->popup_para.popup_button_string = (WCHAR*)GetString(STR_ID_PNS_OPEN_NS);

    alert->app_proc_para.scrn_group_proc= &srv_pnsi_nmgr_proc;
    mmi_frm_nmgr_alert(alert);

    if (alert) OslMfree(alert);
    SRV_PNS_TRACE0(TRC_SRV_PNS_e3cbf98f0e3746a5b356604fe7dc7cfd);
}

void srv_pns_show_warning()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_alert_struct *alert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alert = (mmi_frm_nmgr_alert_struct*)OslMalloc(sizeof(mmi_frm_nmgr_alert_struct));
    memset(alert, 0, sizeof(mmi_frm_nmgr_alert_struct));

    alert->app_id = 0;
    alert->scen_id = MMI_SCENARIO_ID_MRE_PUSH;
    alert->event_type = MMI_EVENT_MRE_PUSH;
    /*fill in the notification information, if your app¡¦s notification can be controlled by NSS, your UI mask must include icon, status bar and popup*/
    alert->ui_mask = MMI_FRM_NMGR_UI_POPUP_MASK;
    /*Once the NSS is not support , NMGR will take the behavior mask as its behavior guildline*/
    alert->behavior_mask = FORCE_POPUP;

    alert->popup_para.image_type = MMI_NMGR_IMG_RES_ID;
    alert->popup_para.image.id = IMG_GLOBAL_WARNING;
    alert->popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE;
    alert->popup_para.popup_string = (WCHAR*)GetString(STR_ID_PNS_BACKGROUND_DATA_ON);
    alert->popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_OK);

    mmi_frm_nmgr_alert(alert);

    if (alert) OslMfree(alert);
    SRV_PNS_TRACE0(TRC_SRV_PNS_65a49cdf234b4fa9b0c573f80b0c651a);
}

mmi_ret srv_pns_broadcast_receiver(mmi_event_struct *param)
{
    switch (param->evt_id)
	{
	    case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            srv_mode_switch_notify_struct *flightMode = (srv_mode_switch_notify_struct*)param;
            if ((flightMode->curr_flight_mode == SRV_MODE_SWITCH_ON &&
                 flightMode->select_flight_mode == SRV_MODE_SWITCH_OFF))
            {
                SRV_PNS_TRACE1(TRC_SRV_PNS_360d0e29bf1542ceae1719af363518f0, 0);
                if (srv_pns_get_global_setting() == SRV_PNS_SETTING_ON)
                {
                    hpnsApiChangeNetworkStatusOn(0);
                }
            }
            else if ((flightMode->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
                      flightMode->select_flight_mode == SRV_MODE_SWITCH_ON))
            {
                SRV_PNS_TRACE1(TRC_SRV_PNS_360d0e29bf1542ceae1719af363518f0, 1);
                hpnsApiChangeNetworkStatusOff();
            }
            break;
        }
        case EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED:
        {
            /* Receive SIM changed event */
            srv_sim_ctrl_event_detected_evt_struct *evt = (srv_sim_ctrl_event_detected_evt_struct*)param;
            switch(evt->type)
            {
                case SRV_SIM_CTRL_EVENT_DET_INSERTED:
                case SRV_SIM_CTRL_EVENT_DET_RECOVERY_END:
                case SRV_SIM_CTRL_EVENT_DET_BOOTUP_WITH_SIM:
                {
                    if (evt->change_check == SRV_SIM_CTRL_CHANGE_CHECK_CHANGED)
                    {
                        U8 item = 1;
                        S16 error;

                        g_pns_change_sim = MMI_TRUE;
                        /* Set the flag */
                        WriteValue(NVRAM_PNS_CHANGE_SIM, &item, DS_BYTE, &error);
                    }
                    else
                    {
                        g_pns_change_sim = MMI_FALSE;
                    }
                    break;
                }
            }
            SRV_PNS_TRACE3(TRC_SRV_PNS_f259e52cedb140c886b281182df3e682, evt->type, evt->change_check, g_pns_change_sim);
        }
        case EVT_ID_SRV_CBM_BEARER_INFO:
        {
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
        #endif
            break;
        }
    }
    return MMI_RET_OK;
}

static mmi_ret srv_pns_cbm_info_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp;
    S16 error;
    srv_cbm_bearer_info_struct *bearer_info_p = (srv_cbm_bearer_info_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PNS_TRACE4(TRC_SRV_PNS_fa7a628ab560498cba42ed306a874269, (g_force_close_cb != NULL)? 1 : 0, bearer_info_p->state, bearer_info_p->error_cause, bearer_info_p->error);
    if (bearer_info_p->state == SRV_CBM_DEACTIVATED && g_force_close_cb)
    {
        srv_pns_force_close_rsp_event_struct evt;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PNS_FORCE_CLOSED_COMPLETE);
        evt.error = bearer_info_p->error;
        evt.error_cause = bearer_info_p->error_cause;
        MMI_FRM_SEND_EVENT(&evt, g_force_close_cb, g_force_close_user_data);
        g_force_close_cb = NULL;
        g_force_close_user_data = NULL;
    }
    else
    {
        ReadValue(NVRAM_PNS_CHANGE_SIM, &temp, DS_BYTE, &error);
        SRV_PNS_TRACE3(TRC_SRV_PNS_1cdc3f7cdfaa4adabc4d8bdab55293fa, temp, g_pns_change_sim, bearer_info_p->state);
        if ((temp == 1 || g_pns_change_sim) && bearer_info_p->state == SRV_CBM_ACTIVATED)
        {
            //srv_pns_show_confrim_with_user();
            srv_pns_show_warning();
            hpnsStaticDataSendBack(MMI_TRUE);
            g_pns_change_sim = MMI_FALSE;
            temp = 0;
            WriteValue(NVRAM_PNS_CHANGE_SIM, &temp, DS_BYTE, &error);
        }
    }
    return MMI_RET_OK;
}

MMI_BOOL srv_pns_force_close_connection(mmi_proc_func callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    cbm_bearer_enum bearer_type;
    kal_int8 cbm_ret = cbm_get_bearer_type(hpnsGetAccountId(), &bearer_type);
    kal_int32 cbm_status = cbm_get_bearer_status(hpnsGetAccountId());
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If bearer type is WIFI, don't care */
    SRV_PNS_TRACE4(TRC_SRV_PNS_c7aff01de57d4be8ae684d51b48c29f8, cbm_status, cbm_ret, bearer_type, (g_force_close_cb != NULL)? 1 : 0);
    if ((cbm_status == CBM_ACTIVATING || cbm_ret == CBM_OK) && g_force_close_cb == NULL)
    {
        if (cbm_status == CBM_ACTIVATING || bearer_type != CBM_BEARER_WIFI)
        {
            /* Close connection */
            hpnsApiChangeNetworkStatusOff();
            /* Register to receive the event of SIM preference changed */
            result = MMI_TRUE;
            g_force_close_cb = callback;
            g_force_close_user_data = user_data;
        }
    }
    SRV_PNS_TRACE3(TRC_SRV_PNS_c6d8090c29b14b95bc6ec239225f6837, cbm_ret, bearer_type, (g_force_close_cb != NULL)? 1 : 0);
    return result;
}

void srv_pns_resume_connection()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PNS_TRACE0(TRC_SRV_PNS_02a81689ac0947e59608e59555ea6e0a);
    if (srv_pns_get_global_setting() == SRV_PNS_SETTING_ON)
    {
        hpnsApiChangeNetworkStatusOn(0);
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
#endif
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
/* under construction !*/
#endif

#endif /* __MMI_PNS__ */
