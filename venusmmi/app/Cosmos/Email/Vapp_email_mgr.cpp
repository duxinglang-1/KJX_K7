/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_email_mgr.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Management
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
 *----------------------------------------------------------------------------
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vapp_email_mgr.h"
#include "vapp_email_main.h"
#include "Vapp_email_acct.h"
#include "Vapp_email_composer.h"
#include "vapp_email_emn.h"
#include "vapp_email_uri.h"
#include "vapp_email_util.h"
#include "Vapp_email_ncenter.h"
#include "Vapp_Email_Msg_List.h"
#include "vcui_cbm_gprot.h"
#include "vcp_global_popup.h"
#ifdef __MMI_EMAIL_OTAP__
#include "vapp_email_otap.h"
#endif

extern "C" {
#include "MMIDataType.h"
#include "TimerEvents.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "SimCtrlSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "app_datetime.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "AppMgrSrvGprot.h"

#include "mmi_rp_vapp_email_def.h"
#include "MMI_inet_app_trc.h"

#include "EmailAppGprot.h"
#include "Vapp_email_core.h"
}

#define VAPPEMAILMGR_ASSERT(x)                      ASSERT(x)
#define VAPPEMAILMGR_EXT_ASSERT(x, y1, y2, y3)      EXT_ASSERT(x, y1, y2, y3)

#define VAPP_EMAIL_NC_TYPE_ALL      (VAPP_EMAIL_NC_TYPE_EVENT_UNREAD | \
                                     VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL | \
                                     VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL | \
                                     VAPP_EMAIL_NC_TYPE_ONGOING_SEND | \
                                     VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH)

#define VAPP_EMAIL_NC_TYPE_ALL_FAIL_EVENT   (VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL | VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL)
#define VAPP_EMAIL_NC_TYPE_ALL_ONGOING      (VAPP_EMAIL_NC_TYPE_ONGOING_SEND | VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH)

#define VAPP_EMAIL_NC_TYPE_ALL_NETWORK      (VAPP_EMAIL_NC_TYPE_ALL_FAIL_EVENT | VAPP_EMAIL_NC_TYPE_ALL_ONGOING)

#define VAPP_EMAIL_ACCT_STATE_FILENAME      "acctState"
#define VAPP_EMAIL_ACCT_STATE_FILENAME_LEN  (32)

static const VfxU32 g_vappEmailMgrMemPollSize = 1 * 1024;
static VfxU32 g_vappEmailMgrMemPoll[g_vappEmailMgrMemPollSize / sizeof(VfxU32)];

//#define __MMI_EMAIL_IMAP_PUSH_DEBUG__
#ifdef __MMI_EMAIL_IMAP_PUSH__
static const VfxS32 VAPP_EMAIL_PUSH_RETRY_CONNECT_DELAY_1 = (1000 * 60 * 2);
static const VfxS32 VAPP_EMAIL_PUSH_RETRY_CONNECT_DELAY_2 = (1000 * 60 * 30);
static const VfxS32 VAPP_EMAIL_PUSH_RETRY_CONNECT_DELAY_3 = (1000 * 60 * 360);

#ifdef __MMI_EMAIL_IMAP_PUSH_DEBUG__
static const VfxS32 VAPP_EMAIL_PUSH_RETRY_DELAY = (1000 * 30);
#else
static const VfxS32 VAPP_EMAIL_PUSH_RETRY_DELAY = (1000 * 60 * 5);
#endif

static const VfxS32 VAPP_EMAIL_PUSH_START_SERVICE_DELAY = (1000 * 20);
static const VfxU32 VAPP_EMAIL_PUSH_RETRY_MAX_NUM = (3);
#endif

static const VfxS32 VAPP_EMAIL_START_SERVICE_DELAY = (1000 * 1);


enum VappEmailMgrNwkOprtEnum
{
    VAPP_EMAIL_MGR_NWK_OPRT_TEST_OUTGOING = 0x01,
    VAPP_EMAIL_MGR_NWK_OPRT_TEST_INCOMING = 0x02,
    VAPP_EMAIL_MGR_NWK_OPRT_TEST_NETWORK = VAPP_EMAIL_MGR_NWK_OPRT_TEST_OUTGOING | VAPP_EMAIL_MGR_NWK_OPRT_TEST_INCOMING,
    VAPP_EMAIL_MGR_NWK_OPRT_CONNECT = 0x04,
    VAPP_EMAIL_MGR_NWK_OPRT_SEND = 0x08,
    VAPP_EMAIL_MGR_NWK_OPRT_RECEIVE = 0x10,
    VAPP_EMAIL_MGR_NWK_OPRT_REFRESH = VAPP_EMAIL_MGR_NWK_OPRT_SEND | VAPP_EMAIL_MGR_NWK_OPRT_RECEIVE,
    VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE = 0x20,
    VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT = 0x40,
    VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER = 0x80,
    VAPP_EMAIL_MGR_NWK_OPRT_TOTAL
};

static VappEmailMgr *g_vappEmailMgrClass = NULL;
//static VappEmailResStruct g_vappEmailRecvResult;
static VappEmailResStruct g_vappEmailResult;
static EMAIL_ACCT_HANDLE g_vappEmailAcctHandle = EMAIL_ACCT_INVALID_HANDLE;

VappEmailMgrContextStruct VappEmailMgr::vappEmailMgrCntx = {};

static void vapp_email_unset_notify(VappEmailMgrContextStruct *emailMgrCntx);
static void vapp_email_init_cntx(VappEmailMgrContextStruct *emailMgrCntx);
static void vapp_email_set_errcode(VappEmailResEnum retval, S32 major, S32 minor);
static void vapp_email_set_acct_state(
                VappEmailAcctStateTableStruct *acctTable,
                EMAIL_ACCT_ID acctId,
                VappEmailAcctStateEnum acctState);
static void vapp_email_reset_acct_state(
                VappEmailAcctStateTableStruct *acctTable,
                EMAIL_ACCT_ID acctId);
static void vapp_email_set_fldr_state(
                VappEmailFldrStateTableStruct *fldrTable,
                EMAIL_ACCT_ID acctId,
                EMAIL_FLDR_ID fldrId,
                VappEmailFldrStateEnum fldrState);
static void vapp_email_reset_fldr_state(
                VappEmailFldrStateTableStruct *fldrTable,
                EMAIL_ACCT_ID acctId,
                VfxBool allFldr,
                EMAIL_FLDR_ID fldrId);
static VappEmailResEnum vapp_email_get_errcode_by_acct_state(VappEmailAcctStateEnum acctState);
static VappEmailResEnum vapp_email_get_errcode_by_fldr_state(VappEmailFldrStateEnum fldrState);
static void vapp_email_get_srv_errcode(srv_email_result_enum retval, S32 *major, S32 *minor);
static void vapp_email_reset_acct_conn(VappEmailAcctConnStruct *acctConn);


static void vapp_email_unset_notify(VappEmailMgrContextStruct *emailMgrCntx)
{
    if (emailMgrCntx->acctNotifyId >= 0)
    {
        srv_email_om_unset_notify(SRV_EMAIL_OM_NOTIFY_OBJ_ACCT, emailMgrCntx->acctNotifyId);
        emailMgrCntx->acctNotifyId = -1;
    }
    if (emailMgrCntx->fldrNotifyId >= 0)
    {
        srv_email_om_unset_notify(SRV_EMAIL_OM_NOTIFY_OBJ_FLDR, emailMgrCntx->fldrNotifyId);
        emailMgrCntx->fldrNotifyId = -1;
    }
    if (emailMgrCntx->msgNotifyId >= 0)
    {
        srv_email_om_unset_notify(SRV_EMAIL_OM_NOTIFY_OBJ_MSG, emailMgrCntx->msgNotifyId);
        emailMgrCntx->msgNotifyId = -1;
    }
}


static void vapp_email_init_cntx(VappEmailMgrContextStruct *emailMgrCntx)
{
    vapp_email_unset_notify(emailMgrCntx);

    memset(emailMgrCntx, 0, sizeof(VappEmailMgrContextStruct));

    emailMgrCntx->emailState = VAPP_EMAIL_STATE_DEINITED;
    emailMgrCntx->currNwkState = VAPP_EMAIL_NWK_STATE_NORMAL;

    emailMgrCntx->acctNotifyId = -1;
    emailMgrCntx->fldrNotifyId = -1;
    emailMgrCntx->msgNotifyId = -1;

    emailMgrCntx->acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    emailMgrCntx->msgHandle = EMAIL_MSG_INVALID_HANDLE;
    emailMgrCntx->reqId = EMAIL_REQ_INVALID_ID;

    emailMgrCntx->currSendMsgId = EMAIL_MSG_INVALID_ID;

    emailMgrCntx->currEnterAcctId = EMAIL_ACCT_INVALID_ID;

    for (VfxU32 i = 0; i < VAPP_EMAIL_MGR_GLOBAL_POP_NUM; ++i)
    {
        emailMgrCntx->globalPopHanle[i] = VCP_GLOBAL_POPUP_INVALID_HANDLE;
    }
}


static void vapp_email_set_errcode(VappEmailResEnum retval, S32 major, S32 minor)
{
    g_vappEmailResult.result = retval;
    g_vappEmailResult.major = major;
    g_vappEmailResult.minor = minor;
}


static void vapp_email_set_acct_state(
                VappEmailAcctStateTableStruct *acctTable,
                EMAIL_ACCT_ID acctId,
                VappEmailAcctStateEnum acctState)
{
    VfxU32 i;

    if (acctState == VAPP_EMAIL_ACCT_STATE_NORMAL)
    {
        vapp_email_reset_acct_state(acctTable, acctId);
        return;
    }

    for (i = 0; i < acctTable->count; i++)
    {
        if (acctTable->acctList[i].acctId == acctId)
        {
            acctTable->acctList[i].acctState = acctState;
            return;
        }
    }

    acctTable->acctList[i].acctId = acctId;
    acctTable->acctList[i].acctState = acctState;
    acctTable->count++;
}


static void vapp_email_reset_acct_state(
                VappEmailAcctStateTableStruct *acctTable,
                EMAIL_ACCT_ID acctId)
{
    VfxU32 i;

    for (i = 0; i < acctTable->count; i++)
    {
        if (acctTable->acctList[i].acctId == acctId)
        {
            for (; i < acctTable->count - 1; i++)
            {
                memcpy(
                    &acctTable->acctList[i],
                    &acctTable->acctList[i + 1],
                    sizeof(VappEmailAcctStateItemStruct));
            }
            acctTable->acctList[i].acctId = EMAIL_ACCT_INVALID_ID;
            acctTable->acctList[i].acctState = VAPP_EMAIL_ACCT_STATE_NORMAL;
            acctTable->count--;
        }
    }
}


static void vapp_email_set_fldr_state(
                VappEmailFldrStateTableStruct *fldrTable,
                EMAIL_ACCT_ID acctId,
                EMAIL_FLDR_ID fldrId,
                VappEmailFldrStateEnum fldrState)
{
    VfxU32 i, j;

    if (fldrState == VAPP_EMAIL_FLDR_STATE_NORMAL)
    {
        vapp_email_reset_fldr_state(fldrTable, acctId, VFX_FALSE, fldrId);
        return;
    }

    for (i = 0; i < fldrTable->count; i++)
    {
        if (fldrTable->fldrList[i].acctId == acctId)
        {
            for (j = 0; j < fldrTable->fldrList[i].fldrNum; j++)
            {
                if (fldrTable->fldrList[i].fldrItem[j].fldrId == fldrId)
                {
                    fldrTable->fldrList[i].fldrItem[j].fldrState = fldrState;
                    return;
                }
            }

            fldrTable->fldrList[i].fldrItem[j].fldrId = fldrId;
            fldrTable->fldrList[i].fldrItem[j].fldrState = fldrState;
            fldrTable->fldrList[i].fldrNum++;
            return;
        }
    }

    fldrTable->fldrList[i].acctId = acctId;
    fldrTable->fldrList[i].fldrItem[0].fldrId = fldrId;
    fldrTable->fldrList[i].fldrItem[0].fldrState = fldrState;
    fldrTable->fldrList[i].fldrNum++;
    fldrTable->count++;
}


static void vapp_email_reset_fldr_state(
                VappEmailFldrStateTableStruct *fldrTable,
                EMAIL_ACCT_ID acctId,
                VfxBool allFldr,
                EMAIL_FLDR_ID fldrId)
{
    VfxU32 i, j;

    for (i = 0; i < fldrTable->count; i++)
    {
        if (fldrTable->fldrList[i].acctId == acctId)
        {
            if (allFldr)
            {
                for (; i < fldrTable->count - 1; i++)
                {
                    memcpy(
                        &fldrTable->fldrList[i],
                        &fldrTable->fldrList[i + 1],
                        sizeof(VappEmailFldrStateListStruct));
                }

                memset(&fldrTable->fldrList[i], 0, sizeof(VappEmailFldrStateListStruct));
                fldrTable->fldrList[i].acctId = EMAIL_ACCT_INVALID_ID;
                fldrTable->count--;
                return;
            }

            for (j = 0; j < fldrTable->fldrList[i].fldrNum; j++)
            {
                if (fldrTable->fldrList[i].fldrItem[j].fldrId == fldrId)
                {
                    for (; j < fldrTable->fldrList[i].fldrNum - 1; j++)
                    {
                        memcpy(
                            &fldrTable->fldrList[i].fldrItem[j],
                            &fldrTable->fldrList[i].fldrItem[j + 1],
                            sizeof(VappEmailFldrStateItemStruct));
                    }
                    fldrTable->fldrList[i].fldrItem[j].fldrId = EMAIL_FLDR_INVALID_ID;
                    fldrTable->fldrList[i].fldrItem[j].fldrState = VAPP_EMAIL_FLDR_STATE_NORMAL;
                    fldrTable->fldrList[i].fldrNum--;

                    if (fldrTable->fldrList[i].fldrNum == 0)
                    {
                        for (; i < fldrTable->count - 1; i++)
                        {
                            memcpy(
                                &fldrTable->fldrList[i],
                                &fldrTable->fldrList[i + 1],
                                sizeof(VappEmailFldrStateListStruct));
                        }

                        memset(&fldrTable->fldrList[i], 0, sizeof(VappEmailFldrStateListStruct));
                        fldrTable->fldrList[i].acctId = EMAIL_ACCT_INVALID_ID;
                        fldrTable->count--;
                    }
                    return;
                }
            }
        }
    }
}


static VappEmailResEnum vapp_email_get_errcode_by_acct_state(VappEmailAcctStateEnum acctState)
{
    switch (acctState)
    {
        case VAPP_EMAIL_ACCT_STATE_EDITING:
            return VAPP_EMAIL_RES_ACCT_EDIT_MODE;

        case VAPP_EMAIL_ACCT_STATE_NETWORK_TEST_WAITING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_TESTING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING:
            return VAPP_EMAIL_RES_NETWORK_RUNNING;

        case VAPP_EMAIL_ACCT_STATE_NETWORK_RETRIEVE_WAITING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_RETRIEVING:
            return VAPP_EMAIL_RES_IN_PARTIAL_FETCH;

        default:
            return VAPP_EMAIL_RES_FAIL;
    }
}


static VappEmailResEnum vapp_email_get_errcode_by_fldr_state(VappEmailFldrStateEnum fldrState)
{
    switch (fldrState)
    {
        case VAPP_EMAIL_FLDR_STATE_EDITING:
            return VAPP_EMAIL_RES_ACCT_EDIT_MODE;

        case VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING:
        case VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVING:
        case VAPP_EMAIL_FLDR_STATE_NETWORK_SEND_WAITING:
        case VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVE_WAITING:
            return VAPP_EMAIL_RES_NETWORK_RUNNING;

        case VAPP_EMAIL_FLDR_STATE_NETWORK_RETRIEVING:
        case VAPP_EMAIL_FLDR_STATE_NETWORK_RETRIEVE_WAITING:
            return VAPP_EMAIL_RES_IN_PARTIAL_FETCH;

        default:
            return VAPP_EMAIL_RES_FAIL;
    }
}


static void vapp_email_get_srv_errcode(srv_email_result_enum retval, S32 *major, S32 *minor)
{
    if (retval == SRV_EMAIL_RESULT_FS_ERROR)
    {
        *major = SRV_EMAIL_FS_ERROR;
        *minor = srv_email_errno_get();
    }
    else
    {
        *major = SRV_EMAIL_MAIL_ERROR;
        *minor = retval;
    }
}


static void vapp_email_reset_acct_conn(VappEmailAcctConnStruct *acctConn)
{
    acctConn->acctId = EMAIL_ACCT_INVALID_ID;
    if (acctConn->acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctConn->acctHandle);
        acctConn->acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    }

    acctConn->msgId = EMAIL_MSG_INVALID_ID;
    if (acctConn->msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(acctConn->msgHandle);
        acctConn->msgHandle = EMAIL_MSG_INVALID_HANDLE;
    }

    acctConn->reqId = EMAIL_REQ_INVALID_ID;
    acctConn->reqOprt = 0;
    acctConn->currOprt = 0;

    acctConn->attachId = EMAIL_ATTCH_INVALID_ID;
    acctConn->retrOpt = SRV_EMAIL_RETRIEVE_ALL_PARTS;

    acctConn->acctConnected = VFX_FALSE;
}


extern "C" void vapp_email_unread_number_changed_cb(
                    srv_email_all_msg_unread_notify_type type, 
                    U32 num, 
                    void* userdata)
{
    //Notify app mgr that email unread number had updated.
    srv_appmgr_update_app_info("native.mtk.vapp_email", EVT_ID_SRV_APPMGR_UPDATE_BADGE);
}


/*****************************************************************************/

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappEmailMgr);

VappEmailMgr::VappEmailMgr()
{
    emailMgrCntx = &vappEmailMgrCntx;
    memset(emailMgrCntx, 0, sizeof(VappEmailMgrContextStruct));
    emailMgrCntx->acctNotifyId = -1;
    emailMgrCntx->fldrNotifyId = -1;
    emailMgrCntx->msgNotifyId = -1;
    switchStorageFlag = VFX_FALSE;
    m_initSrvDelayTimer = NULL;
}

void VappEmailMgr::onInit()
{
    g_vappEmailMgrClass = VFX_OBJ_GET_INSTANCE(VappEmailMgr);
    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool((VfxU8*)g_vappEmailMgrMemPoll, g_vappEmailMgrMemPollSize);
}


void VappEmailMgr::initServiceDone(srv_email_init_state_enum initState, S32 errCode, void *userData)
{
    VappEmailMgrContextStruct *emailMgrCntx = g_vappEmailMgrClass->emailMgrCntx;
    srv_email_result_enum retval;
    CHAR drive;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_INIT_SERVICE_DONE, initState, errCode);

    switch (initState)
    {
        case SRV_EMAIL_INIT_STATE_ERROR:
        {
            if(errCode == SRV_EMAIL_RESULT_FS_ERROR && srv_email_errno_get() == FS_DEVICE_BUSY)
            {
                g_vappEmailMgrClass->startSrvDelay();
            }
            drive = srv_email_get_drive();
            if (FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
            {
                emailMgrCntx->emailState = VAPP_EMAIL_STATE_TCARD_OUT;
            }
            else
            {
                emailMgrCntx->emailState = VAPP_EMAIL_STATE_DEINITED;
            }

            if (g_vappEmailMgrClass->switchStorageFlag)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_SWITCH_STORAGE, VAPP_EMAIL_RES_FAIL, __LINE__);
                g_vappEmailMgrClass->m_signalStorageFinishSwitch.postEmit(VAPP_EMAIL_RES_FAIL);
                g_vappEmailMgrClass->switchStorageFlag = VFX_FALSE;
            }
            break;
        }

        case SRV_EMAIL_INIT_STATE_READY:
        {
            emailMgrCntx->emailState = VAPP_EMAIL_STATE_READY;

            strcpy(emailMgrCntx->rootFldrPath, srv_email_get_root_path());

            vapp_email_unread_number_changed_cb(SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_NONE, 0, NULL);
            srv_email_acct_cache_notify_set(vapp_email_unread_number_changed_cb, NULL);

            retval = srv_email_om_set_notify(
                        SRV_EMAIL_OM_NOTIFY_OBJ_ACCT,
                        &VappEmailMgr::notifyAcctCbFunc,
                        &emailMgrCntx->acctNotifyId);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                //trace: error
            }
            retval = srv_email_om_set_notify(
                        SRV_EMAIL_OM_NOTIFY_OBJ_FLDR,
                        &VappEmailMgr::notifyFldrCbFunc,
                        &emailMgrCntx->fldrNotifyId);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                //trace: error
            }
            retval = srv_email_om_set_notify(
                        SRV_EMAIL_OM_NOTIFY_OBJ_MSG,
                        &VappEmailMgr::notifyMsgCbFunc,
                        &emailMgrCntx->msgNotifyId);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                //trace: error
            }

            mmi_email_app_core_init();
            VappEmailAcct::sysInit();
            VappEmailComp::sysInit();
#ifdef __MMI_EMAIL_OTAP__
            VappEmailOtap::sysInit();
#endif

#ifdef __MMI_URI_AGENT__
            vapp_email_uri_register();
#endif

            VFX_OBJ_GET_INSTANCE(VappEmailEmn)->startService();

            g_vappEmailMgrClass->readAcctState();

            if (g_vappEmailMgrClass->switchStorageFlag)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_SWITCH_STORAGE, VAPP_EMAIL_RES_SUCC, __LINE__);
                g_vappEmailMgrClass->m_signalStorageFinishSwitch.postEmit(VAPP_EMAIL_RES_SUCC);
                g_vappEmailMgrClass->switchStorageFlag = VFX_FALSE;
            }

            /* update NCenter */
            VFX_OBJ_GET_INSTANCE(VappEmailNotificationCtrl)->SysInit();

#ifdef __MMI_EMAIL_IMAP_PUSH__
            /* Check push account validation */
            EMAIL_ACCT_ID pushAcctId = VappEmailPush::getPushAcctId();
            MMI_BOOL isValid;
            srv_email_acct_check_valid(pushAcctId, &isValid);
            if (!isValid)
            {
                VappEmailPush::removePushAcctId(pushAcctId);
            }
            
            /* IMAP push email start */
            if (VappEmailPush::isEnable())
            {
                /* Delay to start service for waiting network ready */
                g_vappEmailMgrClass->pushDelayStartService();
            }
#endif
            break;
        }
        default:
            break;
    }
}


void VappEmailMgr::startSrvDelay()
{
    if(m_initSrvDelayTimer == NULL)
    {
        VFX_OBJ_CREATE(m_initSrvDelayTimer, VfxTimer, this);
    }
    else
    {
        m_initSrvDelayTimer->stop();
    }
    m_initSrvDelayTimer->setStartDelay(VAPP_EMAIL_START_SERVICE_DELAY);
    m_initSrvDelayTimer->m_signalTick.connect(this, &VappEmailMgr::restartEmailApp);
    m_initSrvDelayTimer->start();
}


void VappEmailMgr::restartEmailApp(VfxTimer *timer)
{
    VFX_OBJ_CLOSE(m_initSrvDelayTimer);
    
    resetEmailApp();
}


void VappEmailMgr::refreshAcctCbFunc(srv_email_result_struct *result, EMAIL_REQ_ID reqId, void *userData)
{
    VappEmailMgrContextStruct *emailMgrCntx = g_vappEmailMgrClass->emailMgrCntx;
    VappEmailMgrReqItemStruct *reqItem = (VappEmailMgrReqItemStruct*)userData;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_REQ_ID newReqId;
    EMAIL_FLDR_ID fldrId;
    srv_email_acct_folder_struct *fldrInfo = NULL;
    S32 msgNum = 0;
    VappEmailNwkDoneEnum nwkType = VAPP_EMAIL_NWK_DONE_NONE;
    S32 major = 0;
    S32 minor = 0;
    VappEmailAcctStateEnum acctState = VAPP_EMAIL_ACCT_STATE_NORMAL;
    EMAIL_ACCT_ID acctId;
    VfxU8 reqOprt;
    VfxBool updateTime = VFX_FALSE;

    if (emailMgrCntx->currReqItem != reqItem || emailMgrCntx->reqId != reqId)
    {
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MGR_REFRESH_ACCT_CB_FUNC,
        emailMgrCntx->currReqItem->acctId,
        emailMgrCntx->currReqItem->reqOprt,
        emailMgrCntx->currReq,
        result->result,
        result->major,
        result->minor);

    if (result->result)
    {
        vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
    }
    else
    {
        vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, result->major, result->minor);
    }

    switch (emailMgrCntx->currReq)
    {
        case VAPP_EMAIL_MGR_NWK_OPRT_TEST_OUTGOING:
            nwkType = VAPP_EMAIL_NWK_DONE_NETWORK_TEST;

            if (!result->result)
            {
                goto EXIT_HANDLE;
            }

            retval = srv_email_acct_nwk_test(emailMgrCntx->acctHandle, MMI_TRUE, &newReqId);
            if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                goto EXIT_HANDLE;
            }

            emailMgrCntx->reqId = newReqId;
            emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_TEST_INCOMING;
            return;

        case VAPP_EMAIL_MGR_NWK_OPRT_TEST_INCOMING:
            nwkType = VAPP_EMAIL_NWK_DONE_NETWORK_TEST;
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_SEND:
            if (result->major == SRV_EMAIL_MAIL_ERROR &&
                result->minor == SRV_EMAIL_RESULT_FLDR_EMPTY)
            {
                result->result = MMI_TRUE;
                vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
            }

            if (reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_REFRESH)
            {
                nwkType = VAPP_EMAIL_NWK_DONE_REFRESH;
                updateTime = VFX_TRUE;
                if (!result->result)
                {
                    acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                }
            }
            else
            {
                nwkType = VAPP_EMAIL_NWK_DONE_SEND;
                if (!result->result)
                {
                    acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL;
                }
            }
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_CONNECT:
            nwkType = VAPP_EMAIL_NWK_DONE_REFRESH;

            if (!result->result)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                goto EXIT_HANDLE;
            }

            if (reqItem->acctId == emailMgrCntx->currEnterAcctId)
            {
                g_vappEmailMgrClass->connectCurrAcct();
            }

            retval = srv_email_acct_receive(emailMgrCntx->acctHandle, SRV_EMAIL_RECEIVE_NEW_EMAIL, &newReqId);
            if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                goto EXIT_HANDLE;
            }

            emailMgrCntx->reqId = newReqId;
            emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_RECEIVE;
            return;

        case VAPP_EMAIL_MGR_NWK_OPRT_RECEIVE:
            nwkType = VAPP_EMAIL_NWK_DONE_REFRESH;
            updateTime = VFX_TRUE;

            if (!result->result)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                goto EXIT_HANDLE;
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
        #endif

            if (reqItem->acctId != emailMgrCntx->currEnterAcctId)
            {
                retval = srv_email_acct_disconnect(emailMgrCntx->acctHandle, MMI_TRUE, MMI_FALSE, &newReqId);
                if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
                {
                    acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                    goto EXIT_HANDLE;
                }

                emailMgrCntx->reqId = newReqId;
                emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT;
                return;
            }

            /* No Break */

        case VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT:
            nwkType = VAPP_EMAIL_NWK_DONE_REFRESH;
            updateTime = VFX_TRUE;

            if (!result->result)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                goto EXIT_HANDLE;
            }

            fldrId = srv_email_fldr_type_to_fldr_id(reqItem->acctId, SRV_EMAIL_FLDR_TYPE_OUTBOX);
            fldrInfo = (srv_email_acct_folder_struct*)OslMalloc(sizeof(srv_email_acct_folder_struct));
            retval = srv_email_acct_get_fldr_info(emailMgrCntx->acctHandle, fldrId, fldrInfo);
            msgNum = fldrInfo->msg_count;
            OslMfree(fldrInfo);

            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                goto EXIT_HANDLE;
            }

            if (msgNum == 0)
            {
                goto EXIT_HANDLE;
            }

            emailMgrCntx->currSendMsgId = EMAIL_MSG_INVALID_ID;
            memset(emailMgrCntx->sendFailMsgId, 0, sizeof(emailMgrCntx->sendFailMsgId));
            emailMgrCntx->sendFailMsgNum = 0;

            retval = srv_email_acct_send(
                        emailMgrCntx->acctHandle,
                        (MMI_BOOL)VappEmailAcct::getGlobalSaveSentEmails(reqItem->acctId),
                        &newReqId);
            if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                goto EXIT_HANDLE;
            }

            emailMgrCntx->reqId = newReqId;
            emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_SEND;

            vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, reqItem->acctId, VFX_TRUE, 0);
            vapp_email_set_fldr_state(
                &emailMgrCntx->fldrStateTable,
                reqItem->acctId,
                fldrId,
                VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING);
            return;

        case VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER:
            nwkType = VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER;
            acctState = VAPP_EMAIL_ACCT_STATE_EDITING;
            break;

        default:
            VAPPEMAILMGR_EXT_ASSERT(0, emailMgrCntx->currReq, 0, 0);
    }

EXIT_HANDLE:

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        vapp_email_get_srv_errcode(retval, &major, &minor);
        vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, major, minor);
    }

    g_vappEmailMgrClass->m_signalAcctNwkDone.postEmit(reqItem->acctId, nwkType, g_vappEmailResult);

    acctId = reqItem->acctId;
    reqOprt = reqItem->reqOprt;

    g_vappEmailMgrClass->removeAcctReq(reqItem->acctId, acctState);

    g_vappEmailMgrClass->updateAcctState(
        acctId,
        nwkType,
        (VfxBool)(g_vappEmailResult.result == VAPP_EMAIL_RES_SUCC),
        updateTime);

    if (nwkType != VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER)
    {
        /* no need to update Ncenter after list remote folder */
        g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);        
    }

    if (retval != SRV_EMAIL_RESULT_SUCC || !result->result)
    {
        switch (reqOprt)
        {
            case VAPP_EMAIL_MGR_NWK_OPRT_SEND:
                g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL, VFX_TRUE, VFX_TRUE);
                break;

            case VAPP_EMAIL_MGR_NWK_OPRT_REFRESH:
                g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);
                break;

            default:
                break;
        }
    }

    if (reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_REFRESH && emailMgrCntx->refreshAllFlag)
    {
        g_vappEmailMgrClass->updatefreshAllState();
    }

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);
}


void VappEmailMgr::retrMsgProcCbFunc(srv_email_nwk_proc_struct *data)
{
    VappEmailNwkStateEnum nwkState = VAPP_EMAIL_NWK_STATE_RETRIEVING;
    VfxU32 msgId;

    if (g_vappEmailMgrClass->emailMgrCntx->currAcctConn.msgHandle != (EMAIL_ACCT_HANDLE)data->user_data)
    {
        return;
    }

    msgId = g_vappEmailMgrClass->emailMgrCntx->currAcctConn.msgId;

    switch (data->status)
    {
        case SRV_EMAIL_NWK_CONNECTING:
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, msgId, VAPP_EMAIL_NWK_PROC_CONNECTING);
            break;

        case SRV_EMAIL_NWK_AUTHORIZING:
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, msgId, VAPP_EMAIL_NWK_PROC_AUTHORIZING);
            break;

        case SRV_EMAIL_NWK_UPDATING:
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, msgId, VAPP_EMAIL_NWK_PROC_UPDATING);
            break;

        case SRV_EMAIL_NWK_RECEIVING:
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, msgId, VAPP_EMAIL_NWK_PROC_RETRIEVING);
            break;

        default:
            break;
    }
}


void VappEmailMgr::refreshAcctProcCbFunc(srv_email_nwk_proc_struct *data)
{
    VappEmailMgrContextStruct *emailMgrCntx = g_vappEmailMgrClass->emailMgrCntx;
    VappEmailMgrReqItemStruct *reqItem = (VappEmailMgrReqItemStruct*)data->user_data;
    VappEmailNwkStateEnum nwkState;
    VfxU32 acctId;

    if (emailMgrCntx->currReqItem != reqItem)
    {
        return;
    }

    acctId = (VfxU32)emailMgrCntx->currReqItem->acctId;

    switch (emailMgrCntx->currReqItem->reqOprt)
    {
        case VAPP_EMAIL_MGR_NWK_OPRT_TEST_NETWORK:
            nwkState = VAPP_EMAIL_NWK_STATE_NETWORK_TESTING;
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_REFRESH:
            nwkState = VAPP_EMAIL_NWK_STATE_REFRESHING;
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_SEND:
            nwkState = VAPP_EMAIL_NWK_STATE_SENDING;
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER:
            nwkState = VAPP_EMAIL_NWK_STATE_REMOTE_FOLDER_LISTING;
            break;

        default:
            return;
    }

    switch (data->status)
    {
        case SRV_EMAIL_NWK_CONNECTING:
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, acctId, VAPP_EMAIL_NWK_PROC_CONNECTING);
            break;

        case SRV_EMAIL_NWK_AUTHORIZING:
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, acctId, VAPP_EMAIL_NWK_PROC_AUTHORIZING);
            break;

        case SRV_EMAIL_NWK_SENDING:
        {
            srv_email_sending_data_struct *sendData = (srv_email_sending_data_struct*)data->status_data;

            if (emailMgrCntx->currSendMsgId != EMAIL_MSG_INVALID_ID && !sendData->result)
            {
                VAPPEMAILMGR_EXT_ASSERT(
                    emailMgrCntx->sendFailMsgNum < SRV_EMAIL_GLOBAL_MAX_MSG_NUM,
                    SRV_EMAIL_GLOBAL_MAX_MSG_NUM,
                    emailMgrCntx->sendFailMsgNum,
                    0);

                emailMgrCntx->sendFailMsgId[emailMgrCntx->sendFailMsgNum] = emailMgrCntx->currSendMsgId;
                emailMgrCntx->sendFailMsgNum++;

                g_vappEmailMgrClass->m_signalMsgStateChange.postEmit(
                    emailMgrCntx->currSendMsgId,
                    VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL);
            }

            emailMgrCntx->currSendMsgId = sendData->msg_id;
            if (emailMgrCntx->currSendMsgId != EMAIL_MSG_INVALID_ID)
            {
                g_vappEmailMgrClass->m_signalMsgStateChange.postEmit(
                    emailMgrCntx->currSendMsgId,
                    VAPP_EMAIL_MSG_STATE_NETWORK_SENDING);
            }
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, acctId, VAPP_EMAIL_NWK_PROC_SENDING);
            break;
        }

        case SRV_EMAIL_NWK_UPDATING:
            g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, acctId, VAPP_EMAIL_NWK_PROC_UPDATING);
            break;

        case SRV_EMAIL_NWK_RECEIVING:
        {
            onMsgReceiving(acctId, nwkState, (srv_email_receiving_data_struct*)data->status_data);
            break;
        }

        default:
            break;
    }
}


void VappEmailMgr::connectAcctCbFunc(srv_email_result_struct *result, EMAIL_REQ_ID reqId, void *userData)
{
    VappEmailMgrContextStruct *emailMgrCntx = g_vappEmailMgrClass->emailMgrCntx;
    VappEmailAcctConnStruct *acctConn = &g_vappEmailMgrClass->emailMgrCntx->currAcctConn;
    EMAIL_ACCT_HANDLE acctHandle = (EMAIL_ACCT_HANDLE)userData;
    EMAIL_FLDR_ID fldrId = EMAIL_FLDR_INVALID_ID;
    EMAIL_MSG_ID msgId = EMAIL_MSG_INVALID_ID;
#ifdef __MMI_EMAIL_IMAP_PUSH__
    EMAIL_ACCT_ID acctId = EMAIL_ACCT_INVALID_ID;
#endif
    if (acctConn->acctHandle != acctHandle)
    {
        return;
    }

    switch (acctConn->currOprt)
    {
        case VAPP_EMAIL_MGR_NWK_OPRT_CONNECT:
            acctConn->currOprt = 0;

            g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_EVENT_UNREAD);

            if (result->result)
            {
                acctConn->acctConnected = VFX_TRUE;

                switch (acctConn->reqOprt)
                {
                    case VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE:
                        g_vappEmailMgrClass->retrieveCurrAcct(acctConn->msgId, acctConn->retrOpt, acctConn->attachId);
                        break;

                    case VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT:
                        g_vappEmailMgrClass->disconnectCurrAcct();
                        break;

                    default:
                        acctConn->reqOprt = 0;
                        break;
                }
            }
            else
            {
                if (acctConn->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE)
                {
                    vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, result->major, result->minor);
                    g_vappEmailMgrClass->m_signalMsgNwkDone.postEmit(
                        acctConn->msgId,
                        VAPP_EMAIL_NWK_DONE_RETRIEVE,
                        g_vappEmailResult);
                }

                g_vappEmailMgrClass->stopCurrAcct();
            }

            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE:
            acctConn->currOprt = 0;
            acctConn->reqOprt = 0;
            msgId = acctConn->msgId;
        #ifdef __MMI_EMAIL_IMAP_PUSH__
            acctId = acctConn->acctId;
        #endif
            acctConn->msgId = EMAIL_MSG_INVALID_ID;
            srv_email_msg_destroy(acctConn->msgHandle);
            acctConn->msgHandle = EMAIL_MSG_INVALID_HANDLE;

            fldrId = srv_email_msg_id_to_fldr_id(msgId);
            vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, acctConn->acctId, VFX_FALSE, fldrId);
            vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, acctConn->acctId);

            if (result->result)
            {
                vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
                g_vappEmailMgrClass->updateAcctState(acctConn->acctId, VAPP_EMAIL_NWK_DONE_RETRIEVE, VFX_TRUE, VFX_FALSE);
            }
            else
            {
                vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, result->major, result->minor);
                g_vappEmailMgrClass->updateAcctState(acctConn->acctId, VAPP_EMAIL_NWK_DONE_RETRIEVE, VFX_FALSE, VFX_FALSE);
                
                if (result->result == MMI_FALSE &&
                    result->major == SRV_EMAIL_MAIL_ERROR &&
                    (result->minor == SRV_EMAIL_RESULT_INVALID_MSG || result->minor == SRV_EMAIL_RESULT_MSG_NOT_EXIST))
                {
                    /* msg delete on server, no need to stop current account */
                }
                else
                {
                    g_vappEmailMgrClass->stopCurrAcct();
                }
            }

            g_vappEmailMgrClass->m_signalMsgNwkDone.postEmit(
                msgId,
                VAPP_EMAIL_NWK_DONE_RETRIEVE,
                g_vappEmailResult);
            g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_EVENT_UNREAD);
            
#ifdef __MMI_EMAIL_IMAP_PUSH__
            if (VappEmailPush::isEnable() && acctId == VappEmailPush::getPushAcctId())
            {
                g_vappEmailMgrClass->pushDelayRefresh(acctId);
            }
#endif
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT:
            g_vappEmailMgrClass->stopCurrAcct();
            break;

        default:
            VAPPEMAILMGR_EXT_ASSERT(0, acctConn->acctId, acctConn->reqOprt, acctConn->currOprt);
            break;
    }
}


void VappEmailMgr::connectAcctProcCbFunc(srv_email_nwk_proc_struct *data)
{
    VappEmailAcctConnStruct *acctConn = &g_vappEmailMgrClass->emailMgrCntx->currAcctConn;
    EMAIL_ACCT_HANDLE acctHandle = (EMAIL_ACCT_HANDLE)data->user_data;

    if (acctConn->acctHandle != acctHandle)
    {
        return;
    }

    switch (data->status)
    {
        case SRV_EMAIL_NWK_DISCONNECTED:
            if (acctConn->acctConnected && acctConn->currOprt == 0)
            {
                g_vappEmailMgrClass->stopCurrAcct();
            }
            break;

        default:
            break;
    }
}


void VappEmailMgr::notifyAcctCbFunc(const srv_email_om_notify_struct *notifyData)
{
    switch (notifyData->notify_type)
    {
        case SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG:
        {
            srv_email_om_notify_acct_struct *acctNotify = (srv_email_om_notify_acct_struct*)notifyData->data;
            g_vappEmailMgrClass->m_signalAcctMsgNumChange.postEmit(
                acctNotify->acct_id,
                (VfxU32)acctNotify->msg_unread_num,
                (VfxU32)acctNotify->msg_total_num);

            g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_EVENT_UNREAD);
            break;
        }

        default:
            break;
    }
}


void VappEmailMgr::notifyFldrCbFunc(const srv_email_om_notify_struct *notifyData)
{
    switch (notifyData->notify_type)
    {
        case SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG:
        {
            srv_email_om_notify_fldr_struct *fldrNotify = (srv_email_om_notify_fldr_struct*)notifyData->data;
            VappEmailFldrMsgNumStruct fldrMsgNum;

            fldrMsgNum.totalNum = (VfxU32)fldrNotify->msg_total_num;
            fldrMsgNum.unreadNum = (VfxU32)fldrNotify->msg_unread_num;

            g_vappEmailMgrClass->m_signalFldrMsgNumChange.postEmit(
                fldrNotify->acct_id,
                fldrNotify->fldr_id,
                fldrMsgNum);

            /* Reset the send failed state when there is no email in Outbox */
            if (fldrNotify->msg_total_num == 0)
            {
                VappEmailAcctStateEnum acctState;
                srv_email_fldr_type_enum fldrType;

                acctState = g_vappEmailMgrClass->getAcctState(fldrNotify->acct_id);
                fldrType = srv_email_fldr_id_to_fldr_type(fldrNotify->acct_id, fldrNotify->fldr_id);

                if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
                    fldrType == SRV_EMAIL_FLDR_TYPE_OUTBOX)
                {
                    vapp_email_reset_acct_state(
                        &g_vappEmailMgrClass->emailMgrCntx->acctStateTable,
                        fldrNotify->acct_id);
                    g_vappEmailMgrClass->m_signalAcctStateChange.postEmit(
                        fldrNotify->acct_id,
                        VAPP_EMAIL_ACCT_STATE_NORMAL);

                    g_vappEmailMgrClass->updateAcctState(
                        fldrNotify->acct_id,
                        VAPP_EMAIL_NWK_DONE_SEND,
                        VFX_TRUE,
                        VFX_FALSE);
                    g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL);
                }
            }
            break;
        }

        default:
            break;
    }
}


void VappEmailMgr::notifyMsgCbFunc(const srv_email_om_notify_struct *notifyData)
{
    srv_email_om_notify_msg_struct *msgNotify = NULL;

    switch (notifyData->notify_type)
    {
        case SRV_EMAIL_OM_NOTIFY_MSG_ADD:
        {
            msgNotify = (srv_email_om_notify_msg_struct*)notifyData->data;
            g_vappEmailMgrClass->m_signalMsgAdd.postEmit(msgNotify->msg_id);
            break;
        }

        case SRV_EMAIL_OM_NOTIFY_MSG_DEL:
        {
            msgNotify = (srv_email_om_notify_msg_struct*)notifyData->data;
            g_vappEmailMgrClass->m_signalMsgDelete.emit(msgNotify->msg_id);
            break;
        }

        case SRV_EMAIL_OM_NOTIFY_MSG_UPDATE:
        {
            msgNotify = (srv_email_om_notify_msg_struct*)notifyData->data;
            g_vappEmailMgrClass->m_signalMsgChange.emit(msgNotify->msg_id, *msgNotify);
            break;
        }

        default:
            break;
    }
}


void VappEmailMgr::mgrSchlCbFunc(void)
{
    g_vappEmailMgrClass->startMgr();
}


VappEmailResEnum VappEmailMgr::startMgr(void)
{
    VappEmailMgrReqItemStruct *reqItem = NULL;
    VappEmailNwkDoneEnum nwkType = VAPP_EMAIL_NWK_DONE_NONE;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    EMAIL_MSG_HANDLE msgHandle = EMAIL_MSG_INVALID_HANDLE;
    EMAIL_REQ_ID reqId = EMAIL_REQ_INVALID_ID;
    EMAIL_ACCT_ID acctId;
    EMAIL_FLDR_ID fldrId;
    srv_email_acct_folder_struct *fldrInfo = NULL;
    S32 msgNum = 0;
    EMAIL_FLDR_ID fldrIdList[VAPP_EMAIL_MAX_FLDR_NUM];
    S32 fldrNum = VAPP_EMAIL_MAX_FLDR_NUM - 1;
    S32 i = 0;
    S32 major = 0;
    S32 minor = 0;
    VappEmailAcctStateEnum acctState = VAPP_EMAIL_ACCT_STATE_NORMAL;
    VfxU8 reqOprt;

    if (emailMgrCntx->reqNum == 0 || emailMgrCntx->currReqItem)
    {
        return VAPP_EMAIL_RES_WOULDBLOCK;
    }

    reqItem = &emailMgrCntx->reqItem[0];

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MGR_START_MGR_RUN,
        emailMgrCntx->reqNum,
        reqItem->reqOprt);

    if (reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
    {
        acctHandle = g_vappEmailAcctHandle;
    }
    else
    {
        retval = srv_email_acct_create(0, &acctHandle);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            goto EXIT_HANDLE;
        }
    }

    retval = srv_email_acct_open(acctHandle, reqItem->acctId);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    srv_email_acct_register_callback(acctHandle, &VappEmailMgr::refreshAcctCbFunc, reqItem);
    srv_email_acct_register_proc_callback(acctHandle, &VappEmailMgr::refreshAcctProcCbFunc, reqItem);

    switch (reqItem->reqOprt)
    {
        case VAPP_EMAIL_MGR_NWK_OPRT_TEST_NETWORK:
            nwkType = VAPP_EMAIL_NWK_DONE_NETWORK_TEST;

            retval = srv_email_acct_nwk_test(acctHandle, MMI_FALSE, &reqId);
            if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                goto EXIT_HANDLE;
            }

            emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_TEST_OUTGOING;
            emailMgrCntx->currNwkState = VAPP_EMAIL_NWK_STATE_NETWORK_TESTING;

            vapp_email_set_acct_state(
                &emailMgrCntx->acctStateTable,
                reqItem->acctId,
                VAPP_EMAIL_ACCT_STATE_NETWORK_TESTING);

            //m_signalAcctStateChange.postEmit(reqItem->acctId, VAPP_EMAIL_ACCT_STATE_NETWORK_TESTING);
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_SEND:
            nwkType = VAPP_EMAIL_NWK_DONE_SEND;

            fldrId = srv_email_fldr_type_to_fldr_id(reqItem->acctId, SRV_EMAIL_FLDR_TYPE_OUTBOX);

            fldrInfo = (srv_email_acct_folder_struct*)OslMalloc(sizeof(srv_email_acct_folder_struct));
            retval = srv_email_acct_get_fldr_info(acctHandle, fldrId, fldrInfo);
            msgNum = fldrInfo->msg_count;
            OslMfree(fldrInfo);

            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                goto EXIT_HANDLE;
            }

            if (msgNum == 0)
            {
                goto EXIT_HANDLE;
            }

            emailMgrCntx->currSendMsgId = EMAIL_MSG_INVALID_ID;
            memset(emailMgrCntx->sendFailMsgId, 0, sizeof(emailMgrCntx->sendFailMsgId));
            emailMgrCntx->sendFailMsgNum = 0;

            retval = srv_email_acct_send(
                        acctHandle,
                        (MMI_BOOL)VappEmailAcct::getGlobalSaveSentEmails(reqItem->acctId),
                        &reqId);
            if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                srv_email_cbm_release(reqItem->acctId, MMI_TRUE, MMI_TRUE);
                goto EXIT_HANDLE;
            }

            emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_SEND;
            emailMgrCntx->currNwkState = VAPP_EMAIL_NWK_STATE_SENDING;

            vapp_email_set_acct_state(
                &emailMgrCntx->acctStateTable,
                reqItem->acctId,
                VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING);
            vapp_email_set_fldr_state(
                &emailMgrCntx->fldrStateTable,
                reqItem->acctId,
                fldrId,
                VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING);

            m_signalAcctStateChange.postEmit(reqItem->acctId, VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING);
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_REFRESH:
            nwkType = VAPP_EMAIL_NWK_DONE_REFRESH;

            retval = srv_email_acct_get_fldr_id(acctHandle, SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL, 0, &fldrNum, &fldrIdList[1]);
            if (retval != SRV_EMAIL_RESULT_SUCC)
            {
                goto EXIT_HANDLE;
            }

            if (reqItem->acctId == emailMgrCntx->currEnterAcctId)
            {
                stopCurrAcct();
            }

            fldrIdList[0] = srv_email_fldr_type_to_fldr_id(reqItem->acctId, SRV_EMAIL_FLDR_TYPE_INBOX);
            fldrNum++;

            srv_email_cbm_hold(reqItem->acctId, MMI_TRUE, MMI_TRUE);

            retval = srv_email_acct_connect(acctHandle, MMI_TRUE, &reqId);
            if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                srv_email_cbm_release(reqItem->acctId, MMI_TRUE, MMI_TRUE);
                goto EXIT_HANDLE;
            }

            emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_CONNECT;
            emailMgrCntx->currNwkState = VAPP_EMAIL_NWK_STATE_REFRESHING;

            vapp_email_set_acct_state(
                &emailMgrCntx->acctStateTable,
                reqItem->acctId,
                VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING);

            for (i = 0; i < fldrNum; i++)
            {
                vapp_email_set_fldr_state(
                    &emailMgrCntx->fldrStateTable,
                    reqItem->acctId,
                    fldrIdList[i],
                    VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVING);
            }

            m_signalAcctStateChange.postEmit(reqItem->acctId, VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING);
            break;

        case VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER:
            nwkType = VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER;
            acctState = VAPP_EMAIL_ACCT_STATE_EDITING;

            retval = srv_email_acct_list_remote_fldr(acctHandle, MMI_EMAIL_MAX_REMOTE_FOLDER_NUM, &reqId);
            if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                goto EXIT_HANDLE;
            }

            emailMgrCntx->currReq = VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER;
            emailMgrCntx->currNwkState = VAPP_EMAIL_NWK_STATE_REMOTE_FOLDER_LISTING;
            break;

        default:
            break;
    }

    emailMgrCntx->acctHandle = acctHandle;
    emailMgrCntx->reqId = reqId;
    emailMgrCntx->currReqItem = reqItem;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MGR_START_MGR_DONE,
        __LINE__,
        VAPP_EMAIL_RES_WOULDBLOCK,
        0,
        0);

    return VAPP_EMAIL_RES_WOULDBLOCK;

EXIT_HANDLE:
    if (reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
    {
        acctHandle = EMAIL_ACCT_INVALID_HANDLE;
        g_vappEmailAcctHandle = EMAIL_ACCT_INVALID_HANDLE;
    }

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
    if (msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(msgHandle);
    }

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
    }
    else
    {
        switch (reqItem->reqOprt)
        {
            case VAPP_EMAIL_MGR_NWK_OPRT_SEND:
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL;
                break;

            case VAPP_EMAIL_MGR_NWK_OPRT_REFRESH:
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
                break;

            default:
                break;
        }

        vapp_email_get_srv_errcode(retval, &major, &minor);
        vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, major, minor);
    }

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        TRC_VEMAIL_MGR_START_MGR_DONE,
        __LINE__,
        g_vappEmailResult.result,
        g_vappEmailResult.major,
        g_vappEmailResult.minor);

    reqOprt = reqItem->reqOprt;
    acctId = reqItem->acctId;
    m_signalAcctNwkDone.postEmit(reqItem->acctId, nwkType, g_vappEmailResult);
    removeAcctReq(reqItem->acctId, acctState);
    updateAcctState(
        acctId,
        nwkType,
        (VfxBool)(g_vappEmailResult.result == VAPP_EMAIL_RES_SUCC),
        VFX_FALSE);

    updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);

    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        switch (reqOprt)
        {
            case VAPP_EMAIL_MGR_NWK_OPRT_SEND:
                g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL, VFX_TRUE, VFX_TRUE);
                break;

            case VAPP_EMAIL_MGR_NWK_OPRT_REFRESH:
                g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);
                break;

            default:
                break;
        }
    }

    if (reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_REFRESH && emailMgrCntx->refreshAllFlag)
    {
        updatefreshAllState();
    }

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);

    return VAPP_EMAIL_RES_WOULDBLOCK;
}


void VappEmailMgr::stopMgr(VappEmailMgrStopCauseEnum stopCause)
{
    VfxApp *app = NULL;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_STOP_MGR, stopCause);

    m_signalNwkStop.emit(stopCause);

    cancelAllNwkOperation();

#ifdef __MMI_EMAIL_IMAP_PUSH__
    g_vappEmailMgrClass->pushStopService(stopCause);
#endif    

    switch (stopCause)
    {
        case VAPP_EMAIL_MGR_STOP_CAUSE_SWITCH_STORAGE:
            VFX_OBJ_GET_INSTANCE(VappEmailEmn)->stopService();
            resetNcState();
            resetEmailApp();
            break;

        case VAPP_EMAIL_MGR_STOP_CAUSE_USB:
            VFX_OBJ_GET_INSTANCE(VappEmailEmn)->stopService();
            resetNcState();
            vapp_email_unset_notify(emailMgrCntx);
            emailMgrCntx->emailState = VAPP_EMAIL_STATE_USB_MODE;

            app = VfxAppLauncher::findApp(
                    VAPP_EMAIL,
                    VFX_OBJ_CLASS_INFO(VappEmailApp),
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
                    0);
            if (app)
            {
                VfxAppLauncher::terminate(app->getGroupId());
            }

            vapp_email_init_cntx(emailMgrCntx);
            emailMgrCntx->emailState = VAPP_EMAIL_STATE_USB_MODE;
            srv_appmgr_update_app_info("native.mtk.vapp_email", EVT_ID_SRV_APPMGR_UPDATE_BADGE);
            break;

        case VAPP_EMAIL_MGR_STOP_CAUSE_TCARD:
            VFX_OBJ_GET_INSTANCE(VappEmailEmn)->stopService();
            resetNcState();
            vapp_email_unset_notify(emailMgrCntx);
            emailMgrCntx->emailState = VAPP_EMAIL_STATE_TCARD_OUT;

            app = VfxAppLauncher::findApp(
                    VAPP_EMAIL,
                    VFX_OBJ_CLASS_INFO(VappEmailApp),
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
                    0);
            if (app)
            {
                VfxAppLauncher::terminate(app->getGroupId());
            }

            vapp_email_init_cntx(emailMgrCntx);
            emailMgrCntx->emailState = VAPP_EMAIL_STATE_TCARD_OUT;
            break;

        case VAPP_EMAIL_MGR_STOP_CAUSE_FLIGHT_MODE:
            /* Not change the state */
            break;

        case VAPP_EMAIL_MGR_STOP_CAUSE_FORMAT_FS:
        case VAPP_EMAIL_MGR_STOP_CAUSE_SHUTDOWN:
            VFX_OBJ_GET_INSTANCE(VappEmailEmn)->stopService();
            resetNcState();

            vapp_email_init_cntx(emailMgrCntx);
            emailMgrCntx->emailState = VAPP_EMAIL_STATE_DEINITED;
            break;

        default:
            break;
    }
}


void VappEmailMgr::onMsgReceiving(
                       EMAIL_ACCT_ID acctId, 
                       VappEmailNwkStateEnum nwkState,
                       srv_email_receiving_data_struct *recvData)
{
    EMAIL_FLDR_ID inboxId = srv_email_fldr_type_to_fldr_id(acctId, SRV_EMAIL_FLDR_TYPE_INBOX);
    if (recvData->new_msg_received && recvData->fldr_id == inboxId)
    {
        if (recvData->received_num == 1)
        {
            g_vappEmailMgrClass->updateAcctTime(acctId);
        }
        g_vappEmailMgrClass->m_signalNewMsg.postEmit(acctId, recvData->fldr_id, recvData->new_msg_id, (VfxU32)recvData->received_num);
    }
    g_vappEmailMgrClass->m_signalAcctNwkProc.emit(nwkState, acctId, VAPP_EMAIL_NWK_PROC_RECEIVING);
}


void VappEmailMgr::updateNcState(VfxU8 ncTypeSet)
{
    VappEmailAcctStateItemStruct *acctItem = NULL;
    EMAIL_ACCT_ID sendFailAcctId = EMAIL_ACCT_INVALID_ID;
    EMAIL_ACCT_ID refreshFailAcctId = EMAIL_ACCT_INVALID_ID;
    EMAIL_ACCT_ID onGoingSendAcctId = EMAIL_ACCT_INVALID_ID;
    EMAIL_ACCT_ID onGoingRefreshAcctId = EMAIL_ACCT_INVALID_ID;
    VfxU32 sendFailNum = 0;
    VfxU32 refreshFailNum = 0;
    VfxU32 onGoingSendNum = 0;
    VfxU32 onGoingRefreshNum = 0;
    VfxU32 i = 0;
    U32 unreadNum = 0;

#ifdef __MMI_EMAIL_IMAP_PUSH__
    EMAIL_ACCT_ID pushAcctId = VappEmailPush::getPushAcctId();
    VfxBool pushEnable = VappEmailPush::isEnable();
#endif

    srv_email_acct_total_unread_num_get(&unreadNum);

    for (i = 0; i < emailMgrCntx->acctStateTable.count; i++)
    {
        acctItem = &emailMgrCntx->acctStateTable.acctList[i];

        switch (acctItem->acctState)
        {
            case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
                sendFailNum++;
                if (sendFailAcctId == EMAIL_ACCT_INVALID_ID)
                {
                    sendFailAcctId = acctItem->acctId;
                }
                break;

            case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
#ifdef __MMI_EMAIL_IMAP_PUSH__
                /* NCenter refreshing fail cell not include push refreshing fail */
                if (pushEnable && (pushAcctId == acctItem->acctId))
                {
                    VappEmailPushAcctStruct *pushAcct = findPushAcct(pushAcctId);
                    if (pushAcct == NULL)
                    {
                        if (emailMgrCntx->pushCntx.reStartTimer == NULL)
                        {
                            /* push fail */
                            break;                        
                        }
                    }
                    else
                    {
                        if (pushAcct->refreshFail)
                        {
                            /* push refresh fail */
                            break;
                        }
                    }
                }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */
                refreshFailNum++;
                if (refreshFailAcctId == EMAIL_ACCT_INVALID_ID)
                {
                    refreshFailAcctId = acctItem->acctId;
                }
                break;

            case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING:
            case VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING:
                onGoingSendNum++;
                if (onGoingSendAcctId == EMAIL_ACCT_INVALID_ID)
                {
                    onGoingSendAcctId = acctItem->acctId;
                }
                break;

            case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
            case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING:
                onGoingRefreshNum++;
                if (onGoingRefreshAcctId == EMAIL_ACCT_INVALID_ID)
                {
                    onGoingRefreshAcctId = acctItem->acctId;
                }
                break;

            default:
                break;
        }
    }

    if (ncTypeSet & VAPP_EMAIL_NC_TYPE_EVENT_UNREAD)
    {
        m_signalNcStateChange.emit(VAPP_EMAIL_NC_TYPE_EVENT_UNREAD, (VfxU32)unreadNum, 0);
    }
    if (ncTypeSet & VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL)
    {
        m_signalNcStateChange.emit(VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL, sendFailNum, sendFailAcctId);
    }
    if (ncTypeSet & VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL)
    {
        m_signalNcStateChange.emit(VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL, refreshFailNum, refreshFailAcctId);
    }
    if (ncTypeSet & VAPP_EMAIL_NC_TYPE_ONGOING_SEND)
    {
        m_signalNcStateChange.emit(VAPP_EMAIL_NC_TYPE_ONGOING_SEND, onGoingSendNum, onGoingSendAcctId);
    }
    if (ncTypeSet & VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH)
    {
        m_signalNcStateChange.emit(VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH, onGoingRefreshNum, onGoingRefreshAcctId);
    }
}


void VappEmailMgr::updateAcctState(EMAIL_ACCT_ID acctId, VappEmailNwkDoneEnum nwkType, VfxBool result, VfxBool updateTime)
{
    VappEmailAcctUpdateItemStruct *acctItem = NULL;
    VappEmailAcctStateEnum acctState = VAPP_EMAIL_ACCT_STATE_NORMAL;
    VfxBool needUpdate = VFX_FALSE;
    VfxU32 i;
    applib_time_struct rtcTime;
    kal_uint32 rtcSecs;
    kal_uint32 utcSecs;

    applib_dt_get_rtc_time(&rtcTime);
    rtcSecs = applib_dt_mytime_2_utc_sec(&rtcTime, KAL_FALSE);
    utcSecs = applib_dt_sec_local_to_utc(rtcSecs);

    switch (nwkType)
    {
        case VAPP_EMAIL_NWK_DONE_SEND:
            if (!result)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL;
            }
            break;

        case VAPP_EMAIL_NWK_DONE_REFRESH:
            if (!result)
            {
                acctState = VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL;
            }
            break;

        case VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER:
            return;

        case VAPP_EMAIL_NWK_DONE_CANCEL:
            if (updateTime)
            {
                break;
            }
            /* No break */

        default:
            for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
            {
                acctItem = &emailMgrCntx->acctUpdateTable.acctList[i];
                if (acctItem->acctId == acctId &&
                    acctItem->acctState != VAPP_EMAIL_ACCT_STATE_NORMAL)
                {
                    vapp_email_set_acct_state(
                        &emailMgrCntx->acctStateTable,
                        acctItem->acctId,
                        acctItem->acctState);

                    m_signalAcctStateChange.postEmit(acctItem->acctId, acctItem->acctState);
                    break;
                }
            }
            return;
    }

    for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
    {
        if (emailMgrCntx->acctUpdateTable.acctList[i].acctId == acctId)
        {
            break;
        }
    }

    acctItem = &emailMgrCntx->acctUpdateTable.acctList[i];

    if (i < emailMgrCntx->acctUpdateTable.count)
    {
        switch (nwkType)
        {
            case VAPP_EMAIL_NWK_DONE_SEND:
                if (!result || acctItem->acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL)
                {
                    acctItem->acctState = acctState;
                    needUpdate = VFX_TRUE;
                }
                break;

            case VAPP_EMAIL_NWK_DONE_REFRESH:
                acctItem->acctState = acctState;
                if (result || updateTime)
                {
                    acctItem->updatedTime = utcSecs;
                }

                needUpdate = VFX_TRUE;
                break;

            case VAPP_EMAIL_NWK_DONE_CANCEL:
                if (updateTime)
                {
                    acctItem->updatedTime = utcSecs;
                    needUpdate = VFX_TRUE;
                }
                break;

            default:
                return;
        }
    }
    else
    {
        acctItem->acctId = acctId;
        acctItem->acctState = acctState;
        if (result || updateTime)
        {
            acctItem->updatedTime = utcSecs;
        }
        emailMgrCntx->acctUpdateTable.count++;

        needUpdate = VFX_TRUE;
    }

    for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
    {
        acctItem = &emailMgrCntx->acctUpdateTable.acctList[i];
        if (acctItem->acctId == acctId &&
            acctItem->acctState != VAPP_EMAIL_ACCT_STATE_NORMAL)
        {
            vapp_email_set_acct_state(
                &emailMgrCntx->acctStateTable,
                acctItem->acctId,
                acctItem->acctState);

            m_signalAcctStateChange.postEmit(acctItem->acctId, acctItem->acctState);
            break;
        }
    }

    if (needUpdate)
    {
        updateAcctStateFile();
    }
}


void VappEmailMgr::updateAcctTime(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctUpdateItemStruct *acctItem = NULL;
    VfxU32 i;
    applib_time_struct rtcTime;
    kal_uint32 rtcSecs;
    kal_uint32 utcSecs;

    applib_dt_get_rtc_time(&rtcTime);
    rtcSecs = applib_dt_mytime_2_utc_sec(&rtcTime, KAL_FALSE);
    utcSecs = applib_dt_sec_local_to_utc(rtcSecs);

    for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
    {
        if (emailMgrCntx->acctUpdateTable.acctList[i].acctId == acctId)
        {
            break;
        }
    }

    acctItem = &emailMgrCntx->acctUpdateTable.acctList[i];

    if (i == emailMgrCntx->acctUpdateTable.count)
    {
        acctItem->acctId = acctId;
        acctItem->acctState = VAPP_EMAIL_ACCT_STATE_NORMAL;
        emailMgrCntx->acctUpdateTable.count++;
    }
    acctItem->updatedTime = utcSecs;

    updateAcctStateFile();
}


void VappEmailMgr::updateAcctStateFile(void)
{
    WCHAR fn[VAPP_EMAIL_ACCT_STATE_FILENAME_LEN];
    FS_HANDLE fd = -1;
    S32 ret;
    U32 wByte;

    kal_wsprintf(fn, "%s%s", emailMgrCntx->rootFldrPath, VAPP_EMAIL_ACCT_STATE_FILENAME);

    fd = FS_Open(fn, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd < 0)
    {
        return;
    }

    ret = FS_Write(fd, &emailMgrCntx->acctUpdateTable.count, sizeof(VfxU32), &wByte);
    if (ret < 0 || wByte != sizeof(VfxU32))
    {
        FS_Close(fd);
        FS_Delete(fn);
        return;
    }

    ret = FS_Write(
            fd,
            emailMgrCntx->acctUpdateTable.acctList,
            sizeof(VappEmailAcctUpdateItemStruct) * MMI_EMAIL_MAX_ACCTS,
            &wByte);
    if (ret < 0 || wByte != sizeof(VappEmailAcctUpdateItemStruct) * MMI_EMAIL_MAX_ACCTS)
    {
        FS_Close(fd);
        FS_Delete(fn);
        return;
    }

    FS_Close(fd);
}


void VappEmailMgr::readAcctState(void)
{
    VappEmailAcctUpdateItemStruct *acctItem;
    WCHAR fn[VAPP_EMAIL_ACCT_STATE_FILENAME_LEN];
    FS_HANDLE fd = -1;
    S32 ret;
    U32 rwByte;
    VfxU32 count;
    VfxU32 i;
    srv_email_result_enum retval;
    MMI_BOOL isValid;

    memset(&emailMgrCntx->acctUpdateTable, 0, sizeof(VappEmailAcctUpdateTableStruct));

    kal_wsprintf(fn, "%s%s", emailMgrCntx->rootFldrPath, VAPP_EMAIL_ACCT_STATE_FILENAME);

    fd = FS_Open(fn, FS_READ_ONLY);
    if (fd < 0)
    {
        return;
    }

    ret = FS_Read(fd, &count, sizeof(VfxU32), &rwByte);
    if (ret < 0 || rwByte != sizeof(VfxU32))
    {
        FS_Close(fd);
        FS_Delete(fn);
        return;
    }

    if (count > MMI_EMAIL_MAX_ACCTS)
    {
        FS_Close(fd);
        FS_Delete(fn);
        return;
    }

    for (i = 0; i < count; i++)
    {
        acctItem = &emailMgrCntx->acctUpdateTable.acctList[emailMgrCntx->acctUpdateTable.count];
        ret = FS_Read(
                fd,
                acctItem,
                sizeof(VappEmailAcctUpdateItemStruct),
                &rwByte);
        if (ret < 0 || rwByte != sizeof(VappEmailAcctUpdateItemStruct))
        {
            emailMgrCntx->acctUpdateTable.count = 0;
            FS_Close(fd);
            FS_Delete(fn);
            return;
        }

        retval = srv_email_acct_check_valid(acctItem->acctId, &isValid);
        if (retval == SRV_EMAIL_RESULT_SUCC && isValid)
        {
            emailMgrCntx->acctUpdateTable.count++;
        }
    }

    FS_Close(fd);

    for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
    {
        acctItem = &emailMgrCntx->acctUpdateTable.acctList[i];
        if (acctItem->acctState != VAPP_EMAIL_ACCT_STATE_NORMAL)
        {
            vapp_email_set_acct_state(
                &emailMgrCntx->acctStateTable,
                acctItem->acctId,
                acctItem->acctState);
        }
    }

    fd = FS_Open(fn, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd < 0)
    {
        return;
    }

    ret = FS_Write(fd, &emailMgrCntx->acctUpdateTable.count, sizeof(VfxU32), &rwByte);
    if (ret < 0 || rwByte != sizeof(VfxU32))
    {
        FS_Close(fd);
        FS_Delete(fn);
        return;
    }

    ret = FS_Write(
            fd,
            emailMgrCntx->acctUpdateTable.acctList,
            sizeof(VappEmailAcctUpdateItemStruct) * MMI_EMAIL_MAX_ACCTS,
            &rwByte);
    if (ret < 0 || rwByte != sizeof(VappEmailAcctUpdateItemStruct) * MMI_EMAIL_MAX_ACCTS)
    {
        FS_Close(fd);
        FS_Delete(fn);
        return;
    }

    FS_Close(fd);
}


void VappEmailMgr::resetEmailApp(void)
{
    vapp_email_init_cntx(emailMgrCntx);

    srv_email_app_init_set_callback(&VappEmailMgr::initServiceDone, NULL);
    srv_email_init();

    emailMgrCntx->emailState = VAPP_EMAIL_STATE_INITIALIZING;
}


void VappEmailMgr::resetNcState(void)
{
    m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_UNREAD, VFX_FALSE, VFX_FALSE);
    m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL, VFX_FALSE, VFX_FALSE);
    m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL, VFX_FALSE, VFX_FALSE);
#ifdef __MMI_EMAIL_IMAP_PUSH__    
    m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_FALSE, VFX_FALSE);
#endif
}


VappEmailResEnum VappEmailMgr::addAcctReq(EMAIL_ACCT_ID acctId, VfxU8 reqOprt)
{
    VappEmailResEnum resRet;
    VappEmailAcctStateEnum acctState;
    VappEmailFldrStateEnum fldrState;
    VappEmailMgrReqItemStruct *reqItem = NULL;
    EMAIL_FLDR_ID outbox = EMAIL_FLDR_INVALID_ID;
    EMAIL_FLDR_ID fldrId[VAPP_EMAIL_MAX_FLDR_NUM];
    S32 fldrNum = VAPP_EMAIL_MAX_FLDR_NUM - 1;
    S32 i = 0;
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    srv_email_result_enum retval;
    S32 major = 0;
    S32 minor = 0;

    acctState = getAcctState(acctId);
    if (reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
    {
        if (acctState != VAPP_EMAIL_ACCT_STATE_EDITING)
        {
            vapp_email_set_errcode(VAPP_EMAIL_RES_ACCT_NOT_EDIT_MODE, 0, 0);
            return VAPP_EMAIL_RES_ACCT_NOT_EDIT_MODE;
        }
    }
    else
    {
        if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
            acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
            acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL &&
            acctState != VAPP_EMAIL_ACCT_STATE_IN_USE)
        {
            resRet = vapp_email_get_errcode_by_acct_state(acctState);
            vapp_email_set_errcode(resRet, 0, 0);
            return resRet;
        }
        vapp_email_set_acct_state(&emailMgrCntx->acctStateTable, acctId, VAPP_EMAIL_ACCT_STATE_NORMAL);
    }

    if (reqOprt & VAPP_EMAIL_MGR_NWK_OPRT_SEND)
    {
        outbox = srv_email_fldr_type_to_fldr_id(acctId, SRV_EMAIL_FLDR_TYPE_OUTBOX);

        fldrState = getFldrState(acctId, outbox);
        if (fldrState != VAPP_EMAIL_FLDR_STATE_NORMAL)
        {
            resRet = vapp_email_get_errcode_by_fldr_state(fldrState);
            vapp_email_set_errcode(resRet, 0, 0);
            return resRet;
        }
    }
    if (reqOprt & VAPP_EMAIL_MGR_NWK_OPRT_RECEIVE)
    {
        retval = srv_email_acct_create(0, &acctHandle);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            goto ERROR_HANDLE;
        }

        retval = srv_email_acct_open(acctHandle, acctId);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            goto ERROR_HANDLE;
        }

        retval = srv_email_acct_get_fldr_id(acctHandle, SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL, 0, &fldrNum, &fldrId[1]);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            goto ERROR_HANDLE;
        }

        srv_email_acct_destroy(acctHandle);

        fldrId[0] = srv_email_fldr_type_to_fldr_id(acctId, SRV_EMAIL_FLDR_TYPE_INBOX);
        fldrNum++;

        for (i = 0; i < fldrNum; i++)
        {
            fldrState = getFldrState(acctId, fldrId[i]);
            if (fldrState != VAPP_EMAIL_FLDR_STATE_NORMAL)
            {
                resRet = vapp_email_get_errcode_by_fldr_state(fldrState);
                vapp_email_set_errcode(resRet, 0, 0);
                return resRet;
            }
        }
    }

    VAPPEMAILMGR_EXT_ASSERT(
        emailMgrCntx->reqNum < MMI_EMAIL_MAX_ACCTS,
        MMI_EMAIL_MAX_ACCTS,
        emailMgrCntx->reqNum,
        0);

    reqItem = &emailMgrCntx->reqItem[emailMgrCntx->reqNum];

    memset(reqItem, 0, sizeof(VappEmailMgrReqItemStruct));
    reqItem->acctId = acctId;
    reqItem->reqOprt = reqOprt;
    emailMgrCntx->reqNum++;

    if (reqOprt & VAPP_EMAIL_MGR_NWK_OPRT_SEND)
    {
        vapp_email_set_acct_state(
            &emailMgrCntx->acctStateTable,
            acctId,
            VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING);

        vapp_email_set_fldr_state(
            &emailMgrCntx->fldrStateTable,
            acctId,
            outbox,
            VAPP_EMAIL_FLDR_STATE_NETWORK_SEND_WAITING);
    }
    if (reqOprt & VAPP_EMAIL_MGR_NWK_OPRT_RECEIVE)
    {
        vapp_email_set_acct_state(
            &emailMgrCntx->acctStateTable,
            acctId,
            VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING);

        for (i = 0; i < fldrNum; i++)
        {
            vapp_email_set_fldr_state(
                &emailMgrCntx->fldrStateTable,
                acctId,
                fldrId[i],
                VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVE_WAITING);
        }
    }

    if (reqOprt != VAPP_EMAIL_MGR_NWK_OPRT_TEST_NETWORK &&
        reqOprt != VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
    {
        m_signalAcctStateChange.postEmit(acctId, getAcctState(acctId));
    }

    if (reqOprt & VAPP_EMAIL_MGR_NWK_OPRT_SEND)
    {
        m_signalFldrStateChange.emit(outbox, getFldrState(acctId, outbox));
    }

    return VAPP_EMAIL_RES_SUCC;

ERROR_HANDLE:
    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
    vapp_email_get_srv_errcode(retval, &major, &minor);
    vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, major, minor);

    return VAPP_EMAIL_RES_SERVICE_ERROR;
}


VappEmailResEnum VappEmailMgr::removeAcctReq(EMAIL_ACCT_ID acctId, VappEmailAcctStateEnum acctState)
{
    VappEmailMgrReqItemStruct *reqItem = NULL;
    VfxU32 i;

    for (i = 0; i < emailMgrCntx->reqNum; i++)
    {
        if (emailMgrCntx->reqItem[i].acctId == acctId)
        {
            break;
        }
    }

    if (i == emailMgrCntx->reqNum)
    {
        return VAPP_EMAIL_RES_FAIL;
    }

    reqItem = &emailMgrCntx->reqItem[i];

    if (emailMgrCntx->currReqItem == reqItem)
    {
        srv_email_cbm_release(reqItem->acctId, MMI_TRUE, MMI_TRUE);
        if (reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
        {
            g_vappEmailAcctHandle = EMAIL_ACCT_INVALID_HANDLE;
        }
        else
        {
            srv_email_acct_destroy(emailMgrCntx->acctHandle);
        }
        emailMgrCntx->acctHandle = EMAIL_ACCT_INVALID_HANDLE;
        emailMgrCntx->reqId = EMAIL_REQ_INVALID_ID;
        emailMgrCntx->currReq = 0;

        if (reqItem->reqOprt & VAPP_EMAIL_MGR_NWK_OPRT_SEND)
        {
            emailMgrCntx->currSendMsgId = EMAIL_MSG_INVALID_ID;
            emailMgrCntx->sendFailMsgNum = 0;
        }

        emailMgrCntx->currReqItem = NULL;
        emailMgrCntx->currNwkState = VAPP_EMAIL_NWK_STATE_NORMAL;
    }

    vapp_email_set_acct_state(&emailMgrCntx->acctStateTable, acctId, acctState);
    vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, acctId, VFX_TRUE, 0);

    if (reqItem->reqOprt != VAPP_EMAIL_MGR_NWK_OPRT_TEST_NETWORK &&
        reqItem->reqOprt != VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
    {
        m_signalAcctStateChange.postEmit(acctId, acctState);
    }

    for (; i < emailMgrCntx->reqNum - 1; i++)
    {
        memcpy(
            &emailMgrCntx->reqItem[i],
            &emailMgrCntx->reqItem[i + 1],
            sizeof(VappEmailMgrReqItemStruct));
    }

    memset(&emailMgrCntx->reqItem[i], 0, sizeof(VappEmailMgrReqItemStruct));
    emailMgrCntx->reqNum--;

    return VAPP_EMAIL_RES_SUCC;
}


void VappEmailMgr::connectCurrAcct()
{
    emailMgrCntx->currAcctConn.reqOprt = VAPP_EMAIL_MGR_NWK_OPRT_CONNECT;
    startCurrAcct();
}


void VappEmailMgr::disconnectCurrAcct()
{
    emailMgrCntx->currAcctConn.reqOprt = VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT;
    startCurrAcct();
}


void VappEmailMgr::retrieveCurrAcct(EMAIL_MSG_ID msgId, srv_email_retrieve_option_enum retrOpt, EMAIL_ATTCH_ID attachId)
{
    VappEmailAcctConnStruct *acctConn = &emailMgrCntx->currAcctConn;

    acctConn->reqOprt = VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE;
    acctConn->msgId = msgId;
    acctConn->retrOpt = retrOpt;
    acctConn->attachId = attachId;

    startCurrAcct();
}


void VappEmailMgr::startCurrAcct()
{
    VappEmailAcctConnStruct *acctConn = &emailMgrCntx->currAcctConn;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    EMAIL_ACCT_ID acctId = emailMgrCntx->currEnterAcctId;
    EMAIL_FLDR_ID fldrId = EMAIL_FLDR_INVALID_ID;
    EMAIL_REQ_ID reqId = EMAIL_REQ_INVALID_ID;
    S32 major = 0;
    S32 minor = 0;
    EMAIL_MSG_HANDLE msgHandle = EMAIL_MSG_INVALID_HANDLE;

    if (!acctConn->acctConnected &&
        acctConn->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT)
    {
        stopCurrAcct();
        return;
    }

    if (acctConn->currOprt != 0)
    {
        return;
    }

    if (acctConn->acctConnected)
    {
        switch (acctConn->reqOprt)
        {
            case VAPP_EMAIL_MGR_NWK_OPRT_CONNECT:
                break;

            case VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE:
                retval = srv_email_msg_create(0, &msgHandle);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    goto EXIT_HANDLE;
                }

                fldrId = srv_email_msg_id_to_fldr_id(acctConn->msgId);

                retval = srv_email_msg_open(msgHandle, acctId, fldrId, acctConn->msgId);
                if (retval != SRV_EMAIL_RESULT_SUCC)
                {
                    goto EXIT_HANDLE;
                }

                srv_email_msg_regist_callback(msgHandle, &VappEmailMgr::connectAcctCbFunc, (void*)acctConn->acctHandle);
                srv_email_msg_regist_proc_callback(msgHandle, &VappEmailMgr::retrMsgProcCbFunc, (void*)msgHandle);

                retval = srv_email_msg_retrieve(msgHandle, acctConn->retrOpt, acctConn->attachId, &reqId);
                if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
                {
                    goto EXIT_HANDLE;
                }

                vapp_email_set_acct_state(
                    &emailMgrCntx->acctStateTable,
                    acctId,
                    VAPP_EMAIL_ACCT_STATE_NETWORK_RETRIEVING);
                vapp_email_set_fldr_state(
                    &emailMgrCntx->fldrStateTable,
                    acctId,
                    fldrId,
                    VAPP_EMAIL_FLDR_STATE_NETWORK_RETRIEVING);

                acctConn->msgHandle = msgHandle;
                acctConn->reqId = reqId;
                acctConn->currOprt = VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE;
                break;

            case VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT:
                retval = srv_email_acct_disconnect(
                            acctConn->acctHandle,
                            MMI_TRUE,
                            MMI_FALSE,
                            &acctConn->reqId);

                if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
                {
                    acctConn->currOprt = VAPP_EMAIL_MGR_NWK_OPRT_DISCONNECT;
                    acctConn->acctConnected = VFX_FALSE;
                }
                else
                {
                    stopCurrAcct();
                }
                break;

            default:
                VAPPEMAILMGR_EXT_ASSERT(0, acctConn->acctId, acctConn->reqOprt, 0);
                break;
        }
        
        return;
    }

    retval = srv_email_acct_create(0, &acctHandle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    retval = srv_email_acct_open(acctHandle, acctId);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    srv_email_acct_register_callback(acctHandle, &VappEmailMgr::connectAcctCbFunc, (void*)acctHandle);
    srv_email_acct_register_proc_callback(acctHandle, &VappEmailMgr::connectAcctProcCbFunc, (void*)acctHandle);

    retval = srv_email_acct_connect(acctHandle, MMI_TRUE, &reqId);
    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        goto EXIT_HANDLE;
    }

    if (acctConn->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE)
    {
        vapp_email_set_acct_state(
            &emailMgrCntx->acctStateTable,
            acctId,
            VAPP_EMAIL_ACCT_STATE_NETWORK_RETRIEVING);
    }

    acctConn->acctId = acctId;
    acctConn->acctHandle = acctHandle;
    acctConn->reqId = reqId;
    acctConn->currOprt = VAPP_EMAIL_MGR_NWK_OPRT_CONNECT;
    return;

EXIT_HANDLE:
    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
    if (msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(msgHandle);
    }

    if (acctConn->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE)
    {
        vapp_email_get_srv_errcode(retval, &major, &minor);
        vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, major, minor);

        vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, acctConn->acctId);
        updateAcctState(acctConn->acctId, VAPP_EMAIL_NWK_DONE_RETRIEVE, VFX_FALSE, VFX_FALSE);

        g_vappEmailMgrClass->m_signalMsgNwkDone.postEmit(
            acctConn->msgId,
            VAPP_EMAIL_NWK_DONE_RETRIEVE,
            g_vappEmailResult);

        if (retval != SRV_EMAIL_RESULT_MSG_EXCEED_DOWNLOAD_SIZE)
        {
            g_vappEmailMgrClass->stopCurrAcct();
        }
    }
    acctConn->reqOprt = 0;
    
#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && acctId == VappEmailPush::getPushAcctId())
    {
        g_vappEmailMgrClass->pushDelayRefresh(acctId);
    }
#endif    
}


void VappEmailMgr::stopCurrAcct()
{
    VappEmailAcctConnStruct *acctConn = &emailMgrCntx->currAcctConn;
    EMAIL_FLDR_ID fldrId = EMAIL_FLDR_INVALID_ID;

    if (acctConn->acctId == EMAIL_ACCT_INVALID_HANDLE)
    {
        return;
    }

    if (acctConn->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE)
    {
        vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, acctConn->acctId);
        updateAcctState(acctConn->acctId, VAPP_EMAIL_NWK_DONE_CANCEL, VFX_TRUE, VFX_FALSE);

        fldrId = srv_email_msg_id_to_fldr_id(acctConn->msgId);
        vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, acctConn->acctId, VFX_FALSE, fldrId);

        vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
        m_signalMsgNwkDone.postEmit(acctConn->msgId, VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);
    }
#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && (acctConn->acctId == VappEmailPush::getPushAcctId()))
    {
        pushCheckPending(acctConn->acctId);
    }
#endif
    vapp_email_reset_acct_conn(acctConn);
}


void VappEmailMgr::updatefreshAllState()
{
    S32 acctNum = MMI_EMAIL_MAX_ACCTS;
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    VappEmailAcctStateEnum acctState;
    VfxU32 addNum = 0;
    S32 i = 0;

    if (emailMgrCntx->refreshAllFlag == VFX_FALSE)
    {
        return;
    }

    srv_email_acct_get_acct_id(0, &acctNum, acctId);

    for (i = 0; i < acctNum; i++)
    {
        acctState = getAcctState(acctId[i]);
        
        if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING ||
            acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING)
        {
            addNum++;
        }
    }

    if (addNum == 0)
    {
        /* No refreshing accounts */
        emailMgrCntx->refreshAllFlag = VFX_FALSE;
        
        vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
        g_vappEmailMgrClass->m_signalAcctNwkDone.postEmit(
            EMAIL_ACCT_INVALID_ID,
            VAPP_EMAIL_NWK_DONE_REFRESH_ALL,
            g_vappEmailResult);
    }

}


#ifdef __MMI_EMAIL_IMAP_PUSH__

void VappEmailMgr::pushDelayStartService(void)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_DELAY_START_SERVICE);

    if (pushCntx->reStartTimer)
    {
        VFX_OBJ_CLOSE(pushCntx->reStartTimer);
    }
    
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(VAPP_EMAIL_PUSH_START_SERVICE_DELAY);
    timer->m_signalTick.connect(this, &VappEmailMgr::pushDelayStartServiceTimeout);
    timer->start();
    pushCntx->reStartTimer = timer;
}


void VappEmailMgr::pushDelayStartServiceTimeout(VfxTimer *timer)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_DELAY_START_SERVICE_TIMEOUT, timer);

    VFX_OBJ_CLOSE(pushCntx->reStartTimer);

    if (VappEmailPush::isEnable())
    {
        g_vappEmailMgrClass->pushStartService();
    }   
}


void VappEmailMgr::pushStartService()
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_START_SERVICE);

    if (pushCntx->reStartTimer)
    {
        VFX_OBJ_CLOSE(pushCntx->reStartTimer);
    }

    EMAIL_ACCT_ID acctId = VappEmailPush::getPushAcctId();

    if (acctId != EMAIL_ACCT_INVALID_ID)
    {
        pushStart(acctId);
    }
}


void VappEmailMgr::pushStopService(VappEmailMgrStopCauseEnum stopCause)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VfxU32 i;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_STOP_SERVICE);    
    
    for (i = 0; i < pushCntx->acctNum; i++)
    {
        pushStop(pushCntx->pushAcct[i].acctId);
    }

    if (pushCntx->reStartTimer)
    {
        VFX_OBJ_CLOSE(pushCntx->reStartTimer);
    }

    /* update Ncenter */
    g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);
    if (!VappEmailPush::isEnable())
    {
        g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_FALSE, VFX_FALSE);
    }
    else
    {
        if (stopCause == VAPP_EMAIL_MGR_STOP_CAUSE_FLIGHT_MODE)
        {
            g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);
        } 
    }
}


VfxBool VappEmailMgr::pushAllowStart(EMAIL_ACCT_ID acctId)
{
    EMAIL_FLDR_ID fldrId;
    VappEmailFldrStateEnum fldrState;
    VappEmailAcctStateEnum acctState;

    if (acctId == EMAIL_ACCT_INVALID_ID)
    {
        return VFX_FALSE;
    }

    fldrId = srv_email_fldr_type_to_fldr_id(acctId, SRV_EMAIL_FLDR_TYPE_INBOX);
    fldrState = getFldrState(acctId, fldrId);

    if (fldrState == VAPP_EMAIL_FLDR_STATE_EDITING)
    {
        /* multi-selection */
        return VFX_FALSE;
    }

    acctState = getAcctState(acctId);

    if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING &&
        acctState != VAPP_EMAIL_ACCT_STATE_IN_USE)
    {
        /* current account has network operation */
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VappEmailResEnum VappEmailMgr::pushStart(EMAIL_ACCT_ID acctId)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VappEmailPushAcctStruct *pushAcct = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_ACCT_HANDLE acctHandle = EMAIL_ACCT_INVALID_HANDLE;
	MMI_BOOL isValid;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_START, acctId);

    VappEmailStateEnum appState = getEmailAppState();

    if (appState == VAPP_EMAIL_STATE_FLIGHT_MODE ||
        appState == VAPP_EMAIL_STATE_USB_MODE)
    {
        return VAPP_EMAIL_RES_FAIL;
    }

    if (pushCntx->acctNum >= MMI_EMAIL_MAX_PUSH_ACCTS)
    {
        return VAPP_EMAIL_RES_FAIL;
    }

    if (acctId != VappEmailPush::getPushAcctId())
    {
        return VAPP_EMAIL_RES_FAIL;        
    }

    retval = srv_email_acct_check_valid(acctId, &isValid);

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        if (!isValid)
        {
            /* remove invalid push account */
            VappEmailPush::removePushAcctId(acctId);
            return VAPP_EMAIL_RES_FAIL;
        }
    }

    if (!pushAllowStart(acctId))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_CURRENT_NOT_ALLOW_START, acctId);
        pushDelayStart(acctId);
        return VAPP_EMAIL_RES_FAIL;
    }

    pushAcct = findPushAcct(EMAIL_ACCT_INVALID_ID);

    if (pushAcct == NULL)
    {
        return VAPP_EMAIL_RES_FAIL;
    }
    
    retval = srv_email_acct_create(0, &acctHandle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto ERROR_HANDLE;
    }

    retval = srv_email_acct_open(acctHandle, acctId);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto ERROR_HANDLE;
    }

    srv_email_acct_register_callback(acctHandle, &VappEmailMgr::pushAcctCbFunc, (void*)acctHandle);
    srv_email_acct_register_proc_callback(acctHandle, &VappEmailMgr::pushAcctProcCbFunc, (void*)acctHandle);

    pushAcct->acctId = acctId;
    pushAcct->acctHandle = acctHandle;
    pushAcct->refreshFail = VFX_FALSE;
    pushCntx->acctNum++;

    m_signalNcStateChange.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, 1, VappEmailPush::getPushAcctId());

    /* remove accout from request queue for network waiting case */
    removeAcctReq(pushAcct->acctId, VAPP_EMAIL_ACCT_STATE_NORMAL);

    pushAcctConnect(pushAcct);

    return VAPP_EMAIL_RES_SUCC;

ERROR_HANDLE:
    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
    
    return VAPP_EMAIL_RES_FAIL;
}


void VappEmailMgr::pushStop(EMAIL_ACCT_ID acctId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_STOP, acctId);

    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VappEmailPushAcctStruct *pushAcct = findPushAcct(acctId);

    if (pushAcct == NULL)
    {
        return;
    }
    
    if (pushAcct->acctHandle == EMAIL_ACCT_INVALID_HANDLE)
    {
        return;
    }

    if (pushAcct->currOprt != 0)
    {
        pushAcct->refreshFail = VFX_FALSE;
        vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, pushAcct->acctId);

        EMAIL_FLDR_ID fldrId = srv_email_fldr_type_to_fldr_id(pushAcct->acctId, SRV_EMAIL_FLDR_TYPE_INBOX);            
        vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, pushAcct->acctId, VFX_FALSE, fldrId);
        
        updateAcctState(pushAcct->acctId, VAPP_EMAIL_NWK_DONE_CANCEL, VFX_TRUE, VFX_FALSE);
        updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);
    
        if (emailMgrCntx->refreshAllFlag)
        {
            updatefreshAllState();                
        }
    }

    if (pushAcct->acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(pushAcct->acctHandle);
    }

    if (pushAcct->retryTimer != NULL)
    {
        VFX_OBJ_CLOSE(pushAcct->retryTimer);
    }

    if (pushCntx->reStartTimer)
    {
        VFX_OBJ_CLOSE(pushCntx->reStartTimer);
    }

    memset(pushAcct, 0, sizeof(VappEmailPushAcctStruct));
    emailMgrCntx->pushCntx.acctNum--;
}


void VappEmailMgr::pushDelayStart(EMAIL_ACCT_ID acctId)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VappEmailPushAcctStruct *pushAcct = findPushAcct(acctId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_RESTART, acctId);
    
    if (pushAcct != NULL && pushAcct->acctConnected)
    {
        return;
    }

    if (pushCntx->reStartTimer)
    {
        VFX_OBJ_CLOSE(pushCntx->reStartTimer);
    }
    
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(VAPP_EMAIL_PUSH_RETRY_DELAY);
    timer->m_signalTick.connect(this, &VappEmailMgr::pushDelayStartTimeout);
    timer->start();
    pushCntx->reStartTimer = timer;
}


void VappEmailMgr::pushDelayStartTimeout(VfxTimer *timer)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    EMAIL_ACCT_ID acctId = VappEmailPush::getPushAcctId();
    VappEmailPushAcctStruct *pushAcct = findPushAcct(acctId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_RESTART_TIMEOUT, timer);

    VFX_OBJ_CLOSE(pushCntx->reStartTimer);

    if (pushAcct == NULL)
    {
        pushStart(acctId);
    }    
}


void VappEmailMgr::pushAcctCbFunc(srv_email_result_struct *result, EMAIL_REQ_ID reqId, void *userData)
{
    VappEmailMgrContextStruct *emailMgrCntx = g_vappEmailMgrClass->emailMgrCntx;
    EMAIL_ACCT_HANDLE acctHandle = (EMAIL_ACCT_HANDLE)userData;
    VappEmailPushAcctStruct *pushAcct = g_vappEmailMgrClass->findPushAcctByHandle(acctHandle);
    EMAIL_FLDR_ID fldrId;

    if (pushAcct == NULL)
    {
        return;
    }

    switch (pushAcct->currOprt)
    {
        case VAPP_EMAIL_MGR_NWK_OPRT_CONNECT:
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_CONNECTED, pushAcct->acctId, result->result);
            
            pushAcct->currOprt = 0;
            
            if (result->result)
            {
				pushAcct->acctConnected = VFX_TRUE;
                pushAcct->retryNum = 0;
                g_vappEmailMgrClass->pushAcctRefresh(pushAcct);
            }
            else
            {
                pushAcct->refreshFail = VFX_TRUE;
                /* reset account and folder state */
                vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, pushAcct->acctId);
                fldrId = srv_email_fldr_type_to_fldr_id(pushAcct->acctId, SRV_EMAIL_FLDR_TYPE_INBOX);            
                vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, pushAcct->acctId, VFX_FALSE, fldrId);

                g_vappEmailMgrClass->updateAcctState(
                                        pushAcct->acctId, 
                                        VAPP_EMAIL_NWK_DONE_REFRESH, 
                                        VFX_FALSE, 
                                        VFX_FALSE);
				g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);
                g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);

                if (emailMgrCntx->refreshAllFlag)
                {
                    g_vappEmailMgrClass->updatefreshAllState();
                }
                
                g_vappEmailMgrClass->pushRetryConnect(pushAcct);
            }

            break;
        }
        
        case VAPP_EMAIL_MGR_NWK_OPRT_REFRESH:
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_REFRESHED, pushAcct->acctId, result->result);
            VfxBool ret = result->result ? VFX_TRUE : VFX_FALSE;
            
			pushAcct->currOprt = 0;
            vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, pushAcct->acctId);

            fldrId = srv_email_fldr_type_to_fldr_id(pushAcct->acctId, SRV_EMAIL_FLDR_TYPE_INBOX);            
            vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, pushAcct->acctId, VFX_FALSE, fldrId);

            if (result->result)
            {
                vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
                pushAcct->refreshFail = VFX_FALSE;
            }
            else
            {
                vapp_email_set_errcode(VAPP_EMAIL_RES_SERVICE_ERROR, result->major, result->minor);
                pushAcct->refreshFail = VFX_TRUE;
            }

            g_vappEmailMgrClass->updateAcctState(
                                    pushAcct->acctId, 
                                    VAPP_EMAIL_NWK_DONE_REFRESH, 
                                    ret, 
                                    VFX_FALSE);
              
            g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);

            g_vappEmailMgrClass->m_signalAcctNwkDone.postEmit(
                pushAcct->acctId, 
                VAPP_EMAIL_NWK_DONE_REFRESH, 
                g_vappEmailResult);
            
            if (!result->result)
            {
                g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);
                pushAcct->refreshPending = VFX_TRUE;
                g_vappEmailMgrClass->pushDelayRefresh(pushAcct->acctId);
            }

            if (emailMgrCntx->refreshAllFlag)
            {
                g_vappEmailMgrClass->updatefreshAllState();
            }
            
            break;
        }
        
        default:
            VAPPEMAILMGR_ASSERT(0);
            break;
    }
}


void VappEmailMgr::pushAcctProcCbFunc(srv_email_nwk_proc_struct *data)
{
    EMAIL_ACCT_HANDLE acctHandle = (EMAIL_ACCT_HANDLE)data->user_data;
    VappEmailPushAcctStruct *pushAcct = g_vappEmailMgrClass->findPushAcctByHandle(acctHandle);

    if (pushAcct == NULL)
    {
        return;
    }

    switch (data->status)
    {
        case SRV_EMAIL_NWK_DISCONNECTED:
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_DISCONNECTED, pushAcct->acctId);

            EMAIL_ACCT_ID acctId = pushAcct->acctId;
            g_vappEmailMgrClass->pushStop(acctId);
            g_vappEmailMgrClass->pushDelayStart(acctId);

            g_vappEmailMgrClass->m_signalNcShowHide.emit
                (VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);            
            break;
        }
        
        case SRV_EMAIL_NWK_NEED_REFRESH:
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_NEED_REFRESH, pushAcct->acctId);

            g_vappEmailMgrClass->pushAcctRefresh(pushAcct);            
            break;
        }
        
        case SRV_EMAIL_NWK_RECEIVING:
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_RECEIVING, pushAcct->acctId);
            
            onMsgReceiving(
                pushAcct->acctId, 
                VAPP_EMAIL_NWK_STATE_REFRESHING,
                (srv_email_receiving_data_struct*)data->status_data);
            
            break;
        }
        
        default:
            break;
    }
}

VappEmailResEnum VappEmailMgr::pushAcctConnect(VappEmailPushAcctStruct *pushAcct)
{
    EMAIL_REQ_ID reqId = EMAIL_REQ_INVALID_ID;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_ACCT_ID acctId = pushAcct->acctId;
    EMAIL_ACCT_HANDLE acctHandle = pushAcct->acctHandle; 

    retval = srv_email_acct_connect(acctHandle, MMI_TRUE, &reqId);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_CONNECTING, pushAcct->acctId, retval);

    if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        pushAcct->refreshFail = VFX_TRUE;
        updateAcctState(
            acctId, 
            VAPP_EMAIL_NWK_DONE_REFRESH, 
            VFX_FALSE, 
            VFX_FALSE);
        updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);
        m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);

        pushRetryConnect(pushAcct);
        return VAPP_EMAIL_RES_FAIL;
    }

    /* Case: set A as push account when it's refresh waiting */
    if (emailMgrCntx->refreshAllFlag)
    {
        removeAcctReq(pushAcct->acctId, VAPP_EMAIL_ACCT_STATE_NORMAL);
    }    

    /* update account and folder state */
    EMAIL_FLDR_ID fldrId = srv_email_fldr_type_to_fldr_id(acctId, SRV_EMAIL_FLDR_TYPE_INBOX);

    vapp_email_set_acct_state(
        &emailMgrCntx->acctStateTable,
        acctId,
        VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING);
    
    vapp_email_set_fldr_state(
        &emailMgrCntx->fldrStateTable,
        acctId,
        fldrId,
        VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVING);
    
    m_signalAcctStateChange.postEmit(acctId, VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING);
    updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);
    m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_FALSE, VFX_FALSE);

    pushAcct->reqId = reqId;
    pushAcct->currOprt = VAPP_EMAIL_MGR_NWK_OPRT_CONNECT;

    return VAPP_EMAIL_RES_SUCC;
}


void VappEmailMgr::pushAcctRefresh(VappEmailPushAcctStruct *pushAcct)
{
    EMAIL_REQ_ID reqId = EMAIL_REQ_INVALID_ID;    
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_FLDR_ID fldrId;
    VappEmailFldrStateEnum fldrState;
    
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        TRC_VEMAIL_PUSH_ACCT_REFRESHING, 
        pushAcct->acctId, 
        pushAcct->currOprt, 
        pushAcct->acctConnected);

    if (pushAcct->acctConnected && pushAcct->currOprt == 0)
    {
        fldrId = srv_email_fldr_type_to_fldr_id(pushAcct->acctId, SRV_EMAIL_FLDR_TYPE_INBOX);
        fldrState = getFldrState(pushAcct->acctId, fldrId);
        
        VappEmailAcctStateEnum acctState = getAcctState(pushAcct->acctId);

        if (fldrState == VAPP_EMAIL_FLDR_STATE_EDITING ||
            acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING ||
            acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING)
        {
            /* push fresh pending by multi-selection or sending */
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_REFRESH_PENDING, pushAcct->acctId);
            pushAcct->refreshPending = VFX_TRUE;
            pushDelayRefresh(pushAcct->acctId);
            return;
        }

        if (pushAcct->retryTimer != NULL)
        {
            VFX_OBJ_CLOSE(pushAcct->retryTimer);
        }
        
        retval = srv_email_acct_refresh(pushAcct->acctHandle, SRV_EMAIL_RECEIVE_NEW_EMAIL, &reqId);
        if (retval != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_REFRESH_FAIL, pushAcct->acctId, retval);
            return;
        }
        pushAcct->refreshPending = VFX_FALSE;

        /* 
         * For case receive push ind when refresh all accounts,
         * We should merge push account's two refresh together.
         */
        if (emailMgrCntx->refreshAllFlag)
        {
            removeAcctReq(pushAcct->acctId, VAPP_EMAIL_ACCT_STATE_NORMAL);
        }

        vapp_email_set_acct_state(
            &emailMgrCntx->acctStateTable,
            pushAcct->acctId,
            VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING);

        vapp_email_set_fldr_state(
            &emailMgrCntx->fldrStateTable,
            pushAcct->acctId,
            fldrId,
            VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVING);

        m_signalAcctStateChange.postEmit(pushAcct->acctId, VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING);
        updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);
        m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_FALSE, VFX_FALSE);        

        pushAcct->reqId = reqId;
        pushAcct->currOprt = VAPP_EMAIL_MGR_NWK_OPRT_REFRESH;
    }
}


VfxBool VappEmailMgr::pushStopRefresh(EMAIL_ACCT_ID acctId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_STOP_REFRESH, acctId);

    if (acctId == EMAIL_ACCT_INVALID_ID)
    {
        return VFX_FALSE;
    }
    
    VappEmailPushAcctStruct *pushAcct = findPushAcct(acctId); 

    if (pushAcct == NULL)
    {
        return VFX_FALSE;
    }

    if (pushAcct->currOprt == 0 || pushAcct->reqId == EMAIL_REQ_INVALID_ID)
    {
        return VFX_FALSE;
    }

    srv_email_acct_abort(pushAcct->acctHandle, pushAcct->reqId);
    
    pushAcct->refreshPending = VFX_TRUE;
    pushAcct->refreshFail = VFX_TRUE;

    vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, pushAcct->acctId);

    EMAIL_FLDR_ID fldrId = srv_email_fldr_type_to_fldr_id(pushAcct->acctId, SRV_EMAIL_FLDR_TYPE_INBOX);            
    vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, pushAcct->acctId, VFX_FALSE, fldrId);

    g_vappEmailMgrClass->updateAcctState(
                            pushAcct->acctId, 
                            VAPP_EMAIL_NWK_DONE_CANCEL, 
                            VFX_TRUE, 
                            VFX_FALSE);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
    m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);
        
    g_vappEmailMgrClass->updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);

    if (pushAcct->currOprt != 0 && !pushAcct->acctConnected)
    {
        // cancel push refresh during push connecting
        g_vappEmailMgrClass->m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);
    }
        
    pushAcct->currOprt = 0;
        
    if (emailMgrCntx->refreshAllFlag)
    {
        updatefreshAllState();
    }

    if (pushAcct->retryTimer != NULL)
    {
        VFX_OBJ_CLOSE(pushAcct->retryTimer);
    }
    
    return VFX_TRUE;
}


void VappEmailMgr::pushDelayRefresh(EMAIL_ACCT_ID acctId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_ACCT_DELAY_REFRESH, acctId);

    if (acctId == EMAIL_ACCT_INVALID_ID)
    {
        return;
    }
    
    VappEmailPushAcctStruct *pushAcct = findPushAcct(acctId); 

    if (pushAcct == NULL)
    {
        if (VappEmailPush::isEnable() && (acctId == VappEmailPush::getPushAcctId()))
        {
			/* Push account has been stoped during the timeout */
            pushDelayStart(acctId);
        }
        return;
    }
    else if (!pushAcct->refreshPending)
    {
        return;
    }

    /* delay 5 minutes to refresh */
    if (pushAcct->retryTimer != NULL)
    {
        VFX_OBJ_CLOSE(pushAcct->retryTimer);
    }
    
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(VAPP_EMAIL_PUSH_RETRY_DELAY);
    timer->m_signalTick.connect(this, &VappEmailMgr::pushDelayRefreshTimeout);
    timer->start();
    pushAcct->retryTimer = timer;
	return;
}


void VappEmailMgr::pushDelayRefreshTimeout(VfxTimer *timer)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VappEmailPushAcctStruct *pushAcct;
    VfxU32 i;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_DELAY_REFRESH_TIMEOUT, timer);     

    for (i = 0; i < MMI_EMAIL_MAX_PUSH_ACCTS; i++)
    {
        pushAcct = &pushCntx->pushAcct[i];
        if (timer == pushAcct->retryTimer)
        {
            break;
        }
    }
    VAPPEMAILMGR_ASSERT(i < MMI_EMAIL_MAX_PUSH_ACCTS);
    VFX_OBJ_CLOSE(pushAcct->retryTimer);

    if (pushAcct->acctHandle == EMAIL_ACCT_INVALID_HANDLE)
    {
        return;
    }

    if (!pushAllowStart(pushAcct->acctId))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_CURRENT_NOT_ALLOW_START, pushAcct->acctId);
        pushDelayRefresh(pushAcct->acctId);
        return;
    }

    if (!pushAcct->acctConnected)
    {
        pushAcctConnect(pushAcct);
    }else if(pushAcct->refreshPending)
    {
        pushAcctRefresh(pushAcct);
    }
}


void VappEmailMgr::pushRetryConnect(VappEmailPushAcctStruct *pushAcct)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VfxU32 delay;
    VfxU32 i;
    
    pushAcct->retryNum++;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_RETRY_CONNECT, pushAcct->acctId, pushAcct->retryNum);    
    
    if (pushAcct->retryNum > VAPP_EMAIL_PUSH_RETRY_MAX_NUM)
    {
        EMAIL_ACCT_ID acctId = pushAcct->acctId;
        
        pushStop(acctId);

        updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);
        m_signalNcShowHide.emit(VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL, VFX_TRUE, VFX_TRUE);
        return;
    }

    switch (pushAcct->retryNum)
    {
        case 1:
            delay = VAPP_EMAIL_PUSH_RETRY_CONNECT_DELAY_1;
            break;
            
        case 2:
            delay = VAPP_EMAIL_PUSH_RETRY_CONNECT_DELAY_2;
            break;

        case 3:
            delay = VAPP_EMAIL_PUSH_RETRY_CONNECT_DELAY_3;
            break;
            
        default:
            VAPPEMAILMGR_ASSERT(0);
            return;
    }

    for (i = 0; i < MMI_EMAIL_MAX_PUSH_ACCTS; i++)
    {
        if (pushAcct == &pushCntx->pushAcct[i])
        {
            break;
        }
    }

    VAPPEMAILMGR_ASSERT(i < MMI_EMAIL_MAX_PUSH_ACCTS);

    if (pushAcct->retryTimer)
    {
        VFX_OBJ_CLOSE(pushAcct->retryTimer);
    }

    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(delay);
    timer->m_signalTick.connect(this, &VappEmailMgr::pushRetryConnectTimeout);
    timer->start();
    pushAcct->retryTimer = timer;
}


void VappEmailMgr::pushRetryConnectTimeout(VfxTimer *timer)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VappEmailPushAcctStruct *pushAcct;
    VfxU32 i;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_RETRY_CONNECT_TIMEOUT, timer);

    for (i = 0; i < MMI_EMAIL_MAX_PUSH_ACCTS; i++)
    {
        pushAcct = &pushCntx->pushAcct[i];
        if (timer == pushAcct->retryTimer)
        {
            break;
        }
    }
    VAPPEMAILMGR_ASSERT(i < MMI_EMAIL_MAX_PUSH_ACCTS);
    VFX_OBJ_CLOSE(pushAcct->retryTimer);

    if (pushAcct->acctHandle == EMAIL_ACCT_INVALID_HANDLE)
    {
        return;
    }

    pushAcctConnect(pushAcct);
}


void VappEmailMgr::pushCheckPending(EMAIL_ACCT_ID acctId)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_CHECK_PENDING, acctId);

    VappEmailPushAcctStruct *pushAcct = findPushAcct(acctId);

    if (pushAcct == NULL)
    {
        if (VappEmailPush::isEnable() && (acctId == VappEmailPush::getPushAcctId()))
        {
			/* Push account has been stoped */
            VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
            
            if (pushCntx->reStartTimer)
            {
                /* check start timer is runing */
                return;
            }
            
            pushDelayStart(acctId);
        }
        return;
     }

    if (pushAcct->refreshPending)
    {
        if (!pushAllowStart(pushAcct->acctId))
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_PUSH_CURRENT_NOT_ALLOW_START, pushAcct->acctId);
            pushDelayRefresh(pushAcct->acctId);
        }
        else
        {
            pushAcctRefresh(pushAcct);
        }
    }
}


VappEmailPushAcctStruct *VappEmailMgr::findPushAcct(EMAIL_ACCT_ID acctId)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VfxU32 i;
    
    for (i = 0; i < MMI_EMAIL_MAX_PUSH_ACCTS; i++)
    {
        if (pushCntx->pushAcct[i].acctId == acctId)
        {
            return &pushCntx->pushAcct[i];
        }
    }
    return NULL;
}


VappEmailPushAcctStruct *VappEmailMgr::findPushAcctByHandle(EMAIL_ACCT_HANDLE acctHandle)
{
    VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;
    VfxU32 i;
    
    for (i = 0; i < MMI_EMAIL_MAX_PUSH_ACCTS; i++)
    {
        if (pushCntx->pushAcct[i].acctHandle == acctHandle)
        {
            return &pushCntx->pushAcct[i];
        }
    }
    return NULL;
}

VfxBool VappEmailMgr::isPushRefreshing(EMAIL_ACCT_ID acctId)
{
    VappEmailPushAcctStruct *pushAcct = findPushAcct(acctId);

    if (pushAcct == NULL)
    {
        return VFX_FALSE;
    }

    if (pushAcct->acctHandle != EMAIL_ACCT_INVALID_HANDLE && pushAcct->currOprt != 0)
    {
        return VFX_TRUE;
    }
    
    return VFX_FALSE;    
}

VfxBool VappEmailMgr::pushRetryByRefresh(EMAIL_ACCT_ID pushAcctId)
{
    VappEmailPushAcctStruct *pushAcct = findPushAcct(pushAcctId);
    if (pushAcct != NULL)
    {
        if (pushAcct->currOprt == 0 && !pushAcct->acctConnected)
        {
            /* push connect failed */
            if (pushAcct->retryTimer != NULL)
            {
                VFX_OBJ_CLOSE(pushAcct->retryTimer);
            }
            pushAcct->retryNum = 0;
            pushAcctConnect(pushAcct);
            return VFX_TRUE;
        }
        else
        {
            if (pushAcct->refreshFail == VFX_TRUE)
            {
                /* push refresh failed */
                pushAcctRefresh(pushAcct);
                return VFX_TRUE;
            }
        }
    }
    else
    {
        VappEmailPushEmailStruct *pushCntx = &emailMgrCntx->pushCntx;

        if (pushCntx->reStartTimer)
        {
            /* press refresh button before start push service timeout */
            VFX_OBJ_CLOSE(pushCntx->reStartTimer);

            if (VappEmailPush::isEnable())
            {
                g_vappEmailMgrClass->pushStartService();
            } 
        }
        else
        {
            /* push connect failed after retry 3 times*/
            pushStart(pushAcctId);
        }
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */


VappEmailStateEnum VappEmailMgr::getEmailAppState()
{
    if (emailMgrCntx->emailState != VAPP_EMAIL_STATE_READY)
    {
        return emailMgrCntx->emailState;
    }
#ifndef __MMI_WLAN_FEATURES__
    else if (!srv_sim_ctrl_any_sim_is_available())
    {
        return VAPP_EMAIL_STATE_NO_SIM;
    }
#endif /* __MMI_WLAN_FEATURES__ */
    else if (!srv_mode_switch_is_network_service_available() && 
             srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_INACTIVE) //WiFi can turn on in flight mode
    {
        return VAPP_EMAIL_STATE_FLIGHT_MODE;
    }
    else
    {
        return emailMgrCntx->emailState;
    }
}


/* State query */
VappEmailAcctStateEnum VappEmailMgr::getAcctState(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateTableStruct *acctTable = &emailMgrCntx->acctStateTable;
    VfxU32 i;

    for (i = 0; i < acctTable->count; i++)
    {
        if (acctTable->acctList[i].acctId == acctId)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_GET_ACCT_STATE, acctId, acctTable->acctList[i].acctState);
            return acctTable->acctList[i].acctState;
        }
    }

    if (acctId == emailMgrCntx->currEnterAcctId)
    {
        return VAPP_EMAIL_ACCT_STATE_IN_USE;
    }

    return VAPP_EMAIL_ACCT_STATE_NORMAL;
}


VappEmailFldrStateEnum VappEmailMgr::getFldrState(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId)
{
    VappEmailFldrStateTableStruct *fldrTable = &emailMgrCntx->fldrStateTable;
    VfxU32 i, j;

    for (i = 0; i < fldrTable->count; i++)
    {
        if (fldrTable->fldrList[i].acctId == acctId)
        {
            for (j = 0; j < fldrTable->fldrList[i].fldrNum; j++)
            {
                if (fldrTable->fldrList[i].fldrItem[j].fldrId == fldrId)
                {
                    MMI_TRACE(
                        MMI_INET_TRC_G9_EMAIL,
                        TRC_VEMAIL_MGR_GET_FLDR_STATE,
                        acctId,
                        fldrId,
                        fldrTable->fldrList[i].fldrItem[j].fldrState);
                    return fldrTable->fldrList[i].fldrItem[j].fldrState;
                }
            }
        }
    }

    return VAPP_EMAIL_FLDR_STATE_NORMAL;
}


VappEmailMsgStateEnum VappEmailMgr::getMsgState(EMAIL_MSG_ID msgId)
{
    EMAIL_ACCT_ID acctId = srv_email_msg_id_to_acct_id(msgId);
    EMAIL_FLDR_ID fldrId = srv_email_msg_id_to_fldr_id(msgId);
    srv_email_fldr_type_enum fldrType = srv_email_fldr_id_to_fldr_type(acctId, fldrId);
    VfxU32 i;

    if (fldrType == SRV_EMAIL_FLDR_TYPE_OUTBOX)
    {
        VappEmailFldrStateEnum fldrState = getFldrState(acctId, fldrId);

        switch (fldrState)
        {
            case VAPP_EMAIL_FLDR_STATE_NETWORK_SEND_WAITING:
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_GET_MSG_STATE, msgId, VAPP_EMAIL_MSG_STATE_NETWORK_WAITING);
                return VAPP_EMAIL_MSG_STATE_NETWORK_WAITING;

            case VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING:
                if (msgId == emailMgrCntx->currSendMsgId)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_GET_MSG_STATE, msgId, VAPP_EMAIL_MSG_STATE_NETWORK_SENDING);
                    return VAPP_EMAIL_MSG_STATE_NETWORK_SENDING;
                }
                else
                {
                    for (i = 0; i < emailMgrCntx->sendFailMsgNum; i++)
                    {
                        if (msgId == emailMgrCntx->sendFailMsgId[i])
                        {
                            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_GET_MSG_STATE, msgId, VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL);
                            return VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL;
                        }
                    }
                }
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_GET_MSG_STATE, msgId, VAPP_EMAIL_MSG_STATE_NETWORK_WAITING);
                return VAPP_EMAIL_MSG_STATE_NETWORK_WAITING;

            default:
                break;
        }
    }

    return VAPP_EMAIL_MSG_STATE_NORMAL;
}


VfxU32 VappEmailMgr::getAcctUpdatedTime(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctUpdateItemStruct *acctItem;
    VfxU32 i;

    for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
    {
        acctItem = &emailMgrCntx->acctUpdateTable.acctList[i];
        if (acctItem->acctId == acctId)
        {
            return acctItem->updatedTime;
        }
    }

    return 0;
}


void VappEmailMgr::enterAcct(EMAIL_ACCT_ID acctId)
{
    if (emailMgrCntx->currEnterAcctId != EMAIL_ACCT_INVALID_ID)
    {
        //Trace:
    }

    stopCurrAcct();

    emailMgrCntx->currEnterAcctId = acctId;

    //connectCurrAcct();
}


void VappEmailMgr::exitAcct(EMAIL_ACCT_ID acctId)
{
    if (emailMgrCntx->currEnterAcctId == EMAIL_ACCT_INVALID_ID)
    {
        return;
    }

    if (emailMgrCntx->currEnterAcctId != acctId)
    {
        //Trace:
    }

    disconnectCurrAcct();

    emailMgrCntx->currEnterAcctId = EMAIL_ACCT_INVALID_ID;
}


VfxBool VappEmailMgr::isAcctEntered(EMAIL_ACCT_ID acctId)
{
    if (acctId == emailMgrCntx->currEnterAcctId)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


/* Enter editable mode */
VappEmailResEnum VappEmailMgr::editAcctStart(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateEnum acctState = getAcctState(acctId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_EDIT_ACCT_START, acctId, acctState);

    if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL &&
        acctState != VAPP_EMAIL_ACCT_STATE_IN_USE)
    {
        return VAPP_EMAIL_RES_NETWORK_RUNNING;
    }

    if (acctState == VAPP_EMAIL_ACCT_STATE_IN_USE)
    {
        return VAPP_EMAIL_RES_ACCT_IN_USE;
    }

    if (acctId == emailMgrCntx->currAcctConn.acctId)
    {
        stopCurrAcct();
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && 
        (acctId == VappEmailPush::getPushAcctId()))
    {
        pushStop(acctId);
    }
#endif

    vapp_email_set_acct_state(
        &emailMgrCntx->acctStateTable,
        acctId,
        VAPP_EMAIL_ACCT_STATE_EDITING);

    return VAPP_EMAIL_RES_SUCC;
}


VappEmailResEnum VappEmailMgr::editAcctStop(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateEnum acctState = getAcctState(acctId);
    srv_email_result_enum retval;
    MMI_BOOL isValid;
    VfxU32 i;
    VappEmailAcctUpdateItemStruct *acctItem = NULL;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_EDIT_ACCT_STOP, acctId, acctState);

    if (acctState != VAPP_EMAIL_ACCT_STATE_EDITING)
    {
        return VAPP_EMAIL_RES_FAIL;
    }

    vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, acctId);

    retval = srv_email_acct_check_valid(acctId, &isValid);
    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        if (isValid)
        {
            for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
            {
                acctItem = &emailMgrCntx->acctUpdateTable.acctList[i];
                if (acctItem->acctId == acctId &&
                    acctItem->acctState != VAPP_EMAIL_ACCT_STATE_NORMAL)
                {
                    vapp_email_set_acct_state(
                        &emailMgrCntx->acctStateTable,
                        acctItem->acctId,
                        acctItem->acctState);
                    break;
                }
            }
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_EDIT_ACCT_DELETE, acctId);
            notifyAcctDelete(acctId);
        }
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && (acctId == VappEmailPush::getPushAcctId()))
    {
        pushStart(acctId);
    }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

    return VAPP_EMAIL_RES_SUCC;
}


VappEmailResEnum VappEmailMgr::editFldrStart(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId)
{
    VappEmailFldrStateEnum fldrState;

    fldrState = getFldrState(acctId, fldrId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_EDIT_FLDR_START, acctId, fldrId, fldrState);

    if (fldrState != VAPP_EMAIL_FLDR_STATE_NORMAL)
    {
        return VAPP_EMAIL_RES_NETWORK_RUNNING;
    }

    vapp_email_set_fldr_state(
        &emailMgrCntx->fldrStateTable,
        acctId,
        fldrId,
        VAPP_EMAIL_FLDR_STATE_EDITING);

    return VAPP_EMAIL_RES_SUCC;
}


VappEmailResEnum VappEmailMgr::editFldrStop(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId)
{
    VappEmailFldrStateEnum fldrState;

    fldrState = getFldrState(acctId, fldrId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_EDIT_FLDR_STOP, acctId, fldrId, fldrState);

    if (fldrState != VAPP_EMAIL_FLDR_STATE_EDITING)
    {
        return VAPP_EMAIL_RES_FAIL;
    }

    vapp_email_reset_fldr_state(&emailMgrCntx->fldrStateTable, acctId, VFX_FALSE, fldrId);

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && (acctId == VappEmailPush::getPushAcctId()))
    {
        pushCheckPending(acctId);
    }
#endif

    return VAPP_EMAIL_RES_SUCC;
}


/* Notify */
void VappEmailMgr::notifyAcctDelete(EMAIL_ACCT_ID acctId)
{
    VfxU32 i;
    VfxU8 ncType = VAPP_EMAIL_NC_TYPE_EVENT_UNREAD;
    srv_email_result_enum retval;
    U32 acctNum = MMI_EMAIL_MAX_ACCTS;

    vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, acctId);
    vapp_email_reset_fldr_info(acctId);
    
    for (i = 0; i < emailMgrCntx->acctUpdateTable.count; i++)
    {
        if (emailMgrCntx->acctUpdateTable.acctList[i].acctId == acctId)
        {
            switch (emailMgrCntx->acctUpdateTable.acctList[i].acctState)
            {
                case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
                    ncType |= VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL;
                    break;

                case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
                    ncType |= VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL;
                    break;

                default:
                    break;
            }

            for (; i < emailMgrCntx->acctUpdateTable.count - 1; i++)
            {
                memcpy(
                    &emailMgrCntx->acctUpdateTable.acctList[i],
                    &emailMgrCntx->acctUpdateTable.acctList[i + 1],
                    sizeof(VappEmailAcctUpdateItemStruct));
            }
            emailMgrCntx->acctUpdateTable.acctList[i].acctId = EMAIL_ACCT_INVALID_ID;
            emailMgrCntx->acctUpdateTable.acctList[i].acctState = VAPP_EMAIL_ACCT_STATE_NORMAL;
            emailMgrCntx->acctUpdateTable.acctList[i].updatedTime = 0;
            emailMgrCntx->acctUpdateTable.count--;
        }
    }

    retval = srv_email_acct_get_num(&acctNum);
    if (retval == SRV_EMAIL_RESULT_SUCC && acctNum == 0)
    {
        mmi_frm_nmgr_cancel(MMI_EVENT_EMAIL_NEW_EMAIL);
    }

    updateNcState(ncType);
    m_signalAcctDelete.emit(acctId);
#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (acctId == VappEmailPush::getPushAcctId())
    {
        VappEmailPush::removePushAcctId(acctId);
    }
#endif    
}


/* Send & Receive */
VappEmailResEnum VappEmailMgr::refreshAllAcct(void)
{
    VappEmailAcctStateEnum acctState;
    VappEmailResEnum result = VAPP_EMAIL_RES_SUCC;
    srv_email_result_enum retval;
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    S32 acctNum = MMI_EMAIL_MAX_ACCTS;
    S32 i = 0;
    VfxU32 addNum = 0;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_REFRESH_ALL_ACCT_CHECK, emailMgrCntx->refreshAllFlag);

    if (emailMgrCntx->refreshAllFlag)
    {
        return VAPP_EMAIL_RES_WOULDBLOCK;
    }

    retval = srv_email_acct_get_acct_id(0, &acctNum, acctId);
    if (retval != SRV_EMAIL_RESULT_SUCC || acctNum == 0)
    {
        return VAPP_EMAIL_RES_FAIL;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_REFRESH_ALL_ACCT_START, acctNum);

#ifdef __MMI_EMAIL_IMAP_PUSH__
    EMAIL_ACCT_ID pushAcctId = VappEmailPush::getPushAcctId();
    VfxBool pushEnable = VappEmailPush::isEnable();
#endif    

    for (i = 0; i < acctNum; i++)
    {
        resetAcctFailState(acctId[i]);

#ifdef __MMI_EMAIL_IMAP_PUSH__
        if (pushEnable && acctId[i] == pushAcctId)
        {
            if (pushRetryByRefresh(pushAcctId))
            {
                acctState = getAcctState(acctId[i]);
                if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING ||
                    acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING)
                {
                    addNum++;
                }
                continue;
            }
        }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

        addAcctReq(acctId[i], VAPP_EMAIL_MGR_NWK_OPRT_REFRESH);

        acctState = getAcctState(acctId[i]);
        if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING ||
            acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING)
        {
            addNum++;
        }
        else if (result == VAPP_EMAIL_RES_SUCC)
        {
            result = vapp_email_get_errcode_by_acct_state(acctState);
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_REFRESH_ALL_ACCT_END, addNum);

    if (addNum == 0)
    {
        vapp_email_set_errcode(result, 0, 0);
        m_signalAcctNwkDone.postEmit(EMAIL_ACCT_INVALID_ID, VAPP_EMAIL_NWK_DONE_REFRESH_ALL, g_vappEmailResult);
        return VAPP_EMAIL_RES_FAIL;
    }

    emailMgrCntx->refreshAllFlag = VFX_TRUE;

    updateNcState(VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH);

    return startMgr();
}


VappEmailResEnum VappEmailMgr::refreshAcct(EMAIL_ACCT_ID acctId)
{
#ifdef __MMI_EMAIL_IMAP_PUSH__
    EMAIL_ACCT_ID pushAcctId = VappEmailPush::getPushAcctId();
    VfxBool pushEnable = VappEmailPush::isEnable();

    if (pushEnable && acctId == pushAcctId)
    {
        if (pushRetryByRefresh(pushAcctId))
        {
            return VAPP_EMAIL_RES_SUCC;
        }
    }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

    resetAcctFailState(acctId);
    VappEmailResEnum addRet = addAcctReq(acctId, VAPP_EMAIL_MGR_NWK_OPRT_REFRESH);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_REFRESH_ACCT, acctId, addRet);

    if (addRet != VAPP_EMAIL_RES_SUCC)
    {
        m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_REFRESH, g_vappEmailResult);
        return VAPP_EMAIL_RES_FAIL;
    }

    updateNcState(VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH);

    return startMgr();
}


VappEmailResEnum VappEmailMgr::sendOutbox(EMAIL_ACCT_ID acctId)
{
#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && 
        (acctId == VappEmailPush::getPushAcctId()))
    {
        pushStopRefresh(acctId);
    }
#endif

    VappEmailResEnum addRet;

    resetAcctFailState(acctId);

    addRet = addAcctReq(acctId, VAPP_EMAIL_MGR_NWK_OPRT_SEND);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_SEND_OUTBOX, acctId, addRet);

    if (addRet != VAPP_EMAIL_RES_SUCC)
    {
        m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_SEND, g_vappEmailResult);
        return VAPP_EMAIL_RES_FAIL;
    }

    updateNcState(VAPP_EMAIL_NC_TYPE_ONGOING_SEND);

    return startMgr();
}


VappEmailResEnum VappEmailMgr::retrieveMsg(EMAIL_MSG_ID msgId, srv_email_retrieve_option_enum retrOpt)
{
    retrieveCurrAcct(msgId, retrOpt, EMAIL_ATTCH_INVALID_ID);
    return VAPP_EMAIL_RES_WOULDBLOCK;
}


VappEmailResEnum VappEmailMgr::retrieveMsgAttach(EMAIL_ATTCH_ID attachId)
{
    EMAIL_MSG_ID msgId = srv_email_attch_id_to_msg_id(attachId);

    retrieveCurrAcct(msgId, SRV_EMAIL_RETRIEVE_SINGLE_ATTACHMENT, attachId);
    return VAPP_EMAIL_RES_WOULDBLOCK;
}


VappEmailResEnum VappEmailMgr::testAcctNetwork(EMAIL_ACCT_ID acctId)
{
    VappEmailResEnum addRet;

    if (emailMgrCntx->reqNum > 0)
    {
        vapp_email_set_errcode(VAPP_EMAIL_RES_NETWORK_RUNNING, 0, 0);
        m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_NETWORK_TEST, g_vappEmailResult);
        return VAPP_EMAIL_RES_NETWORK_RUNNING;
    }

    //resetAcctFailState(acctId);

    addRet = addAcctReq(acctId, VAPP_EMAIL_MGR_NWK_OPRT_TEST_NETWORK);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_TEST_ACCT_NETWORK, acctId, addRet);

    if (addRet != VAPP_EMAIL_RES_SUCC)
    {
        m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_NETWORK_TEST, g_vappEmailResult);
        return addRet;
    }

    return startMgr();
}


VappEmailResEnum VappEmailMgr::listRemoteFolder(EMAIL_ACCT_ID acctId, EMAIL_ACCT_HANDLE acctHandle)
{
    VappEmailResEnum addRet;

    if (emailMgrCntx->reqNum > 0)
    {
        vapp_email_set_errcode(VAPP_EMAIL_RES_NETWORK_RUNNING, 0, 0);
        m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER, g_vappEmailResult);
        return VAPP_EMAIL_RES_NETWORK_RUNNING;
    }

    addRet = addAcctReq(acctId, VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER);

    //MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_TEST_ACCT_NETWORK, acctId, addRet);

    if (addRet != VAPP_EMAIL_RES_SUCC)
    {
        m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER, g_vappEmailResult);
        return addRet;
    }

    g_vappEmailAcctHandle = acctHandle;

    return startMgr();
}


VappEmailResEnum VappEmailMgr::getCurrNwkState(EMAIL_ACCT_ID &acctId, VappEmailNwkStateEnum &nwkState)
{
    if (!emailMgrCntx->currReqItem)
    {
        acctId = 0;
        nwkState = VAPP_EMAIL_NWK_STATE_NORMAL;
    }
    else
    {
        acctId = emailMgrCntx->currReqItem->acctId;
        nwkState = emailMgrCntx->currNwkState;
    }

    return VAPP_EMAIL_RES_SUCC;
}


VfxBool VappEmailMgr::isRefreshAllAcct(void)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_IS_REFRESH_ALL_ACCT, emailMgrCntx->refreshAllFlag);
    return emailMgrCntx->refreshAllFlag;
}


VfxBool VappEmailMgr::getCurrSendingMsg(EMAIL_MSG_ID &msgId)
{
    EMAIL_FLDR_ID fldrId;
    
    if (!emailMgrCntx->currReqItem ||
        (emailMgrCntx->currReqItem->reqOprt != VAPP_EMAIL_MGR_NWK_OPRT_SEND &&
         emailMgrCntx->currReqItem->reqOprt != VAPP_EMAIL_MGR_NWK_OPRT_REFRESH))
    {
        return VFX_FALSE;
    }

    fldrId = srv_email_fldr_type_to_fldr_id(emailMgrCntx->currReqItem->acctId, SRV_EMAIL_FLDR_TYPE_OUTBOX);

    VappEmailFldrStateEnum fldrState = getFldrState(emailMgrCntx->currReqItem->acctId, fldrId);

    if (fldrState == VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING)
    {
        if (emailMgrCntx->currSendMsgId != EMAIL_MSG_INVALID_ID)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_GET_CURR_SENDING_MSG, emailMgrCntx->currSendMsgId);
            msgId = emailMgrCntx->currSendMsgId;
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


void VappEmailMgr::cancelAllNwkOperation(void)
{
    VappEmailMgrReqItemStruct *reqItem = NULL;
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    VfxU32 acctNum = 0;
    VfxU32 msgNum = 0;
    VfxU8 reqOprt[MMI_EMAIL_MAX_ACCTS];
    EMAIL_ACCT_ID updateAcctId = EMAIL_ACCT_INVALID_ID;

    for (VfxU32 i = 0; i < emailMgrCntx->reqNum; i++)
    {
        reqItem = &emailMgrCntx->reqItem[i];

        if (emailMgrCntx->currReqItem == reqItem &&
            reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_REFRESH &&
            emailMgrCntx->currReq != VAPP_EMAIL_MGR_NWK_OPRT_CONNECT)
        {
            updateAcctId = reqItem->acctId;
        }
        reqOprt[acctNum] = reqItem->reqOprt;
        acctId[acctNum++] = reqItem->acctId;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_ALL_NWK_OPERATION, emailMgrCntx->reqNum, acctNum, msgNum);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);

    if (acctNum)
    {
        for (VfxS32 i = acctNum - 1; i >= 0; i--)
        {
            if (reqOprt[i] == VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
            {
                removeAcctReq(acctId[i], VAPP_EMAIL_ACCT_STATE_EDITING);
                updateAcctState(acctId[i], VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER, VFX_TRUE, VFX_FALSE);
            }
            else
            {
                removeAcctReq(acctId[i], VAPP_EMAIL_ACCT_STATE_NORMAL);
                updateAcctState(
                    acctId[i],
                    VAPP_EMAIL_NWK_DONE_CANCEL,
                    VFX_TRUE,
                    (acctId[i] == updateAcctId ? VFX_TRUE : VFX_FALSE));
            }
            m_signalAcctNwkDone.postEmit(acctId[i], VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);
        }
    }

    stopCurrAcct();

    updateNcState(VAPP_EMAIL_NC_TYPE_ALL_ONGOING);

    if (emailMgrCntx->refreshAllFlag)
    {
        updatefreshAllState();
    }
}


void VappEmailMgr::cancelCurrNwkOperation(void)
{
    VappEmailMgrReqItemStruct *reqItem = NULL;
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    VfxU32 acctNum = 0;
    VfxU32 msgNum = 0;
    VfxU8 reqOprt[MMI_EMAIL_MAX_ACCTS];
    EMAIL_ACCT_ID updateAcctId = EMAIL_ACCT_INVALID_ID;

    for (VfxU32 i = 0; i < emailMgrCntx->reqNum; i++)
    {
        reqItem = &emailMgrCntx->reqItem[i];

        if (reqItem->acctId == emailMgrCntx->currEnterAcctId)
        {
            if (emailMgrCntx->currReqItem == reqItem &&
                reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_REFRESH &&
                emailMgrCntx->currReq != VAPP_EMAIL_MGR_NWK_OPRT_CONNECT)
            {
                updateAcctId = reqItem->acctId;
            }
            reqOprt[acctNum] = reqItem->reqOprt;
            acctId[acctNum++] = reqItem->acctId;
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_ALL_NWK_OPERATION, emailMgrCntx->reqNum, acctNum, msgNum);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);

    if (acctNum)
    {
        for (VfxS32 i = acctNum - 1; i >= 0; i--)
        {
            if (reqOprt[i] == VAPP_EMAIL_MGR_NWK_OPRT_LIST_REMOTE_FOLDER)
            {
                removeAcctReq(acctId[i], VAPP_EMAIL_ACCT_STATE_EDITING);
                updateAcctState(acctId[i], VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER, VFX_TRUE, VFX_FALSE);
            }
            else
            {
                removeAcctReq(acctId[i], VAPP_EMAIL_ACCT_STATE_NORMAL);
                updateAcctState(
                    acctId[i],
                    VAPP_EMAIL_NWK_DONE_CANCEL,
                    VFX_TRUE,
                    (acctId[i] == updateAcctId ? VFX_TRUE : VFX_FALSE));
            }
            m_signalAcctNwkDone.postEmit(acctId[i], VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);
        }
    }

    stopCurrAcct();

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && 
        (emailMgrCntx->currEnterAcctId == VappEmailPush::getPushAcctId()))
    {
        pushStopRefresh(emailMgrCntx->currEnterAcctId);
    }
#endif

    updateNcState(VAPP_EMAIL_NC_TYPE_ALL);

    if (emailMgrCntx->refreshAllFlag)
    {
        updatefreshAllState();
}

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);    
}


void VappEmailMgr::cancelAcctRefresh(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateEnum acctState;
    VappEmailMgrReqItemStruct *reqItem = emailMgrCntx->currReqItem;
    VfxBool updateTime = VFX_FALSE;

    acctState = getAcctState(acctId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_ACCT_REFRESH, acctId, acctState);

    switch (acctState)
    {
        case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING:
            break;

        default:
            return;
    }

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && (acctId == VappEmailPush::getPushAcctId()))
    {
        VfxBool result = pushStopRefresh(acctId);
        if (result)
        {
            pushDelayRefresh(acctId);
            return; 
        }
    }
#endif

    if (reqItem &&
        reqItem->acctId == acctId &&
        reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_REFRESH &&
        emailMgrCntx->currReq != VAPP_EMAIL_MGR_NWK_OPRT_CONNECT)
    {
        updateTime = VFX_TRUE;
    }

    removeAcctReq(acctId, VAPP_EMAIL_ACCT_STATE_NORMAL);
    updateAcctState(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, VFX_TRUE, updateTime);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
    m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);

    updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);

    if (emailMgrCntx->refreshAllFlag)
    {
        updatefreshAllState();
    }

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);
}


void VappEmailMgr::cancelSendOutbox(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateEnum acctState;

    acctState = getAcctState(acctId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_SEND_OUTBOX, acctId, acctState);

    switch (acctState)
    {
        case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING:
            break;

        default:
            return;
    }

    removeAcctReq(acctId, VAPP_EMAIL_ACCT_STATE_NORMAL);
    updateAcctState(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, VFX_TRUE, VFX_FALSE);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
    m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);

    updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && (acctId == VappEmailPush::getPushAcctId()))
    {
        pushCheckPending(acctId);
    }
#endif

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);
}


void VappEmailMgr::cancelMsgRetrieve(EMAIL_MSG_ID msgId)
{
    VappEmailAcctConnStruct *acctConn = &emailMgrCntx->currAcctConn;

    if (acctConn->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_RETRIEVE)
    {
        stopCurrAcct();
    }
}


void VappEmailMgr::cancelTestAcctNetwork(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateEnum acctState;

    acctState = getAcctState(acctId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_TEST_ACCT_NETWORK, acctId, acctState);

    switch (acctState)
    {
        case VAPP_EMAIL_ACCT_STATE_NETWORK_TEST_WAITING:
        case VAPP_EMAIL_ACCT_STATE_NETWORK_TESTING:
            break;

        default:
            return;
    }

    removeAcctReq(acctId, VAPP_EMAIL_ACCT_STATE_NORMAL);
    updateAcctState(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, VFX_TRUE, VFX_FALSE);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
    m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);
}


void VappEmailMgr::cancelListRemoteFolder(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateEnum acctState;

    acctState = getAcctState(acctId);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_TEST_ACCT_NETWORK, acctId, acctState);

    switch (acctState)
    {
        case VAPP_EMAIL_ACCT_STATE_EDITING:
            break;

        default:
            return;
    }

    removeAcctReq(acctId, VAPP_EMAIL_ACCT_STATE_EDITING);
    updateAcctState(acctId, VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER, VFX_TRUE, VFX_FALSE);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);
    m_signalAcctNwkDone.postEmit(acctId, VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);
}


void VappEmailMgr::cancelAllAcctRefresh(void)
{
    VappEmailMgrReqItemStruct *reqItem = NULL;
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    VfxU32 acctNum = 0;
    EMAIL_ACCT_ID updateAcctId = EMAIL_ACCT_INVALID_ID;

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable())
    {
        EMAIL_ACCT_ID pushAcctId = VappEmailPush::getPushAcctId();
        if (pushAcctId != EMAIL_ACCT_INVALID_ID)
        {
            pushStopRefresh(pushAcctId);
            pushDelayRefresh(pushAcctId);
        }
    }
#endif

    for (VfxU32 i = 0; i < emailMgrCntx->reqNum; i++)
    {
        reqItem = &emailMgrCntx->reqItem[i];
        if (reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_REFRESH)
        {
            if (emailMgrCntx->currReqItem == reqItem &&
                emailMgrCntx->currReq != VAPP_EMAIL_MGR_NWK_OPRT_CONNECT)
            {
                updateAcctId = reqItem->acctId;
            }
            acctId[acctNum++] = reqItem->acctId;
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_ALL_ACCT_REFRESH, emailMgrCntx->reqNum, acctNum);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);

    if (acctNum)
    {
        for (VfxS32 i = acctNum - 1; i >= 0; i--)
        {
            removeAcctReq(acctId[i], VAPP_EMAIL_ACCT_STATE_NORMAL);
            updateAcctState(
                acctId[i],
                VAPP_EMAIL_NWK_DONE_CANCEL,
                VFX_TRUE,
                (acctId[i] == updateAcctId ? VFX_TRUE : VFX_FALSE));
            m_signalAcctNwkDone.postEmit(acctId[i], VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);
        }
    }

    updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);

    if (emailMgrCntx->refreshAllFlag)
    {
        updatefreshAllState();
    }

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);
}


void VappEmailMgr::cancelAllSendOutbox(void)
{
    VappEmailMgrReqItemStruct *reqItem = NULL;
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    VfxU32 acctNum = 0;

    for (VfxU32 i = 0; i < emailMgrCntx->reqNum; i++)
    {
        reqItem = &emailMgrCntx->reqItem[i];
        if (reqItem->reqOprt == VAPP_EMAIL_MGR_NWK_OPRT_SEND)
        {
            acctId[acctNum++] = reqItem->acctId;
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_CANCEL_ALL_SEND_OUTBOX, emailMgrCntx->reqNum, acctNum);

    vapp_email_set_errcode(VAPP_EMAIL_RES_SUCC, 0, 0);

    if (acctNum)
    {
        for (VfxS32 i = acctNum - 1; i >= 0; i--)
        {
            removeAcctReq(acctId[i], VAPP_EMAIL_ACCT_STATE_NORMAL);
            updateAcctState(acctId[i], VAPP_EMAIL_NWK_DONE_CANCEL, VFX_TRUE, VFX_FALSE);
            m_signalAcctNwkDone.postEmit(acctId[i], VAPP_EMAIL_NWK_DONE_CANCEL, g_vappEmailResult);
        }
    }

    updateNcState(VAPP_EMAIL_NC_TYPE_ALL_NETWORK);

    StartNonAlignTimer(VAPP_EMAIL_MGR_JOB_SCHEDULER, 0, &VappEmailMgr::mgrSchlCbFunc);
}


void VappEmailMgr::resetAcctFailState(EMAIL_ACCT_ID acctId)
{
    VappEmailAcctStateEnum acctState;

    acctState = getAcctState(acctId);
    switch (acctState)
    {
        case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
            vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, acctId);
            updateNcState(VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL);
            break;

        case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
            vapp_email_reset_acct_state(&emailMgrCntx->acctStateTable, acctId);
            updateNcState(VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL);
            break;

        default:
            break;
    }
}


VfxBool VappEmailMgr::isNetworkReady(VappEmailStateEnum &emailState)
{
    emailState = getEmailAppState();

    if (emailState == VAPP_EMAIL_STATE_READY ||
        emailState == VAPP_EMAIL_STATE_FLIGHT_MODE)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappEmailMgr::initEmailApp(void)
{
    vapp_email_init_cntx(emailMgrCntx);

    srv_email_init_state_enum initState = srv_email_get_srv_init_state();

    switch (initState)
    {
        case SRV_EMAIL_INIT_STATE_NOT_STARTED:
        case SRV_EMAIL_INIT_STATE_ERROR:
            srv_email_app_init_set_callback(&VappEmailMgr::initServiceDone, NULL);
            srv_email_init();
            /* No break */

        case SRV_EMAIL_INIT_STATE_INITING:
            srv_email_app_init_set_callback(&VappEmailMgr::initServiceDone, NULL);
            emailMgrCntx->emailState = VAPP_EMAIL_STATE_INITIALIZING;
            break;

        case SRV_EMAIL_INIT_STATE_READY:
            initServiceDone(SRV_EMAIL_INIT_STATE_READY, 0, NULL);
            break;

        default:
            break;
    }
}


#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
void VappEmailMgr::switchStorage(CHAR newDrive)
{
    CHAR oldDrive = srv_email_get_drive();
    srv_email_result_enum retval;

    if (newDrive == oldDrive)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_SWITCH_STORAGE, VAPP_EMAIL_RES_SUCC, __LINE__);
        m_signalStorageFinishSwitch.postEmit(VAPP_EMAIL_RES_SUCC);
        return;
    }

    retval = srv_email_set_drive(newDrive);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_SWITCH_STORAGE, VAPP_EMAIL_RES_FAIL, __LINE__);
        m_signalStorageFinishSwitch.postEmit(VAPP_EMAIL_RES_FAIL);
        return;
    }

    m_signalStoragePreSwitch.emit();
    switchStorageFlag = VFX_TRUE;
    stopMgr(VAPP_EMAIL_MGR_STOP_CAUSE_SWITCH_STORAGE);

    /* reset current folder info */
    vapp_email_reset_curr_fldr_info();
}
#endif

void VappEmailMgr::plugUsb(VfxBool plugIn)
{
    VappEmailStateEnum state = getEmailAppState();

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_PLUG_USB, plugIn, state);

    if (plugIn)
    {
        closeGlobalPop();
        m_signalUsbPlugin.emit();
        stopMgr(VAPP_EMAIL_MGR_STOP_CAUSE_USB);
    }
    else
    {
        resetEmailApp();
    }
}


void VappEmailMgr::plugTcard(VfxBool plugIn, U8 *drvTable, U8 drvNum)
{
    VappEmailStateEnum state = getEmailAppState();

    if (state == VAPP_EMAIL_STATE_USB_MODE)
    {
        //No need to update app state in USB mass storage mode
        return;
    }

    U8 drive = (U8)srv_email_get_drive();
    VfxBool needUpdate = VFX_FALSE;
    U8 i;
    VfxApp *app = NULL;

    for (i = 0; i < drvNum; i++)
    {
        if (drive == drvTable[i])
        {
            needUpdate = VFX_TRUE;
            break;
        }
    }

    if (!plugIn)
    {
        closeGlobalPop();
    }

    m_signalTcardPlug.emit(plugIn);

    if (!needUpdate)
    {
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_PLUG_TCARD, plugIn, state);

    if (!plugIn)
    {
        stopMgr(VAPP_EMAIL_MGR_STOP_CAUSE_TCARD);
    }
    else
    {
        app = VfxAppLauncher::findApp(
                VAPP_EMAIL,
                VFX_OBJ_CLASS_INFO(VappEmailApp),
                VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
                0);

        if (app)
        {
            VfxAppLauncher::terminate(app->getGroupId());
        }

        resetEmailApp();
    }
}


void VappEmailMgr::switchFlightMode(VfxBool enterMode)
{
    VappEmailStateEnum state = getEmailAppState();

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MGR_SWITCH_FLIGHT_MODE, enterMode, state);

    if (enterMode)
    {
        switch (state)
        {
            case VAPP_EMAIL_STATE_READY:
            case VAPP_EMAIL_STATE_NO_SIM:
            case VAPP_EMAIL_STATE_FLIGHT_MODE:
            {
                m_signalFlightMode.emit();
                stopMgr(VAPP_EMAIL_MGR_STOP_CAUSE_FLIGHT_MODE);
                break;
            }

            default:
                break;
        }
    }
    else
    {
        switch (state)
        {
            case VAPP_EMAIL_STATE_READY:
            case VAPP_EMAIL_STATE_NO_SIM:
            case VAPP_EMAIL_STATE_FLIGHT_MODE:
            {
#ifdef __MMI_EMAIL_IMAP_PUSH__
                /* IMAP push email start */
                if (VappEmailPush::isEnable())
                {
                    g_vappEmailMgrClass->pushStartService();
                }
#endif
                break;
            }

            default:
                break;
        }
    }
}


void VappEmailMgr::formatFileSystem(VfxBool beforeAfter, U8 drvLetter)
{
    //VappEmailStateEnum state = getEmailAppState();
    U8 drive = (U8)srv_email_get_drive();

    if (drive != drvLetter)
    {
        return;
    }

    if (beforeAfter)
    {
        stopMgr(VAPP_EMAIL_MGR_STOP_CAUSE_FORMAT_FS);
    }
    else
    {
        resetEmailApp();
    }
}


void VappEmailMgr::fmgrAdvAction()
{
    if (emailMgrCntx->emailState == VAPP_EMAIL_STATE_DEINITED)
    {
        resetEmailApp();
    }
}


void VappEmailMgr::shutdown(void)
{
    stopMgr(VAPP_EMAIL_MGR_STOP_CAUSE_SHUTDOWN);
}


void VappEmailMgr::addGlobalPopHandle(VfxS32 handle)
{
    VAPPEMAILMGR_ASSERT(handle != VCP_GLOBAL_POPUP_INVALID_HANDLE);

    for (VfxU32 i = 0; i < VAPP_EMAIL_MGR_GLOBAL_POP_NUM; ++i)
    {
        if (emailMgrCntx->globalPopHanle[i] == VCP_GLOBAL_POPUP_INVALID_HANDLE)
        {
            emailMgrCntx->globalPopHanle[i] = handle;
            return;
        }
    }

    //VAPPEMAILMGR_ASSERT(0);
}


void VappEmailMgr::removeGlobalPopHandle(VfxS32 handle)
{
    VAPPEMAILMGR_ASSERT(handle != VCP_GLOBAL_POPUP_INVALID_HANDLE);

    for (VfxU32 i = 0; i < VAPP_EMAIL_MGR_GLOBAL_POP_NUM; ++i)
    {
        if (emailMgrCntx->globalPopHanle[i] == handle)
        {
            emailMgrCntx->globalPopHanle[i] = VCP_GLOBAL_POPUP_INVALID_HANDLE;
            return;
        }
    }

    //VAPPEMAILMGR_ASSERT(0);
}


void VappEmailMgr::closeGlobalPop(void)
{
    for (VfxU32 i = 0; i < VAPP_EMAIL_MGR_GLOBAL_POP_NUM; ++i)
    {
        if (emailMgrCntx->globalPopHanle[i] != VCP_GLOBAL_POPUP_INVALID_HANDLE)
        {
            vcp_global_popup_cancel(emailMgrCntx->globalPopHanle[i]);
            emailMgrCntx->globalPopHanle[i] = VCP_GLOBAL_POPUP_INVALID_HANDLE;
        }
    }
}


#ifdef __MMI_EMAIL_IMAP_PUSH__

void VappEmailPush::setEnable(VfxBool enable)
{
	MMI_BOOL status = (enable ? MMI_TRUE : MMI_FALSE);
    mmi_email_imap_push_set_status(status);
}


VfxBool VappEmailPush::isEnable(void)
{
    MMI_BOOL enable;
     
    mmi_email_imap_push_get_status(&enable);
    return (enable ? VFX_TRUE : VFX_FALSE);
}


void VappEmailPush::addPushAcctId(EMAIL_ACCT_ID acctId)
{
    mmi_email_imap_push_acct_add(acctId);

    if (VappEmailPush::isEnable())
    {
        VappEmailStateEnum emailState = 
            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();
        if (emailState == VAPP_EMAIL_STATE_FLIGHT_MODE)
        {
            vapp_email_util_nmgr_balloon(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE);
            return;
        }
        
        g_vappEmailMgrClass->pushStart(acctId);
    }
}


void VappEmailPush::removePushAcctId(EMAIL_ACCT_ID acctId)
{
    mmi_email_imap_push_acct_remove(acctId);
    
    if (VappEmailPush::isEnable())
    {
        g_vappEmailMgrClass->pushStop(acctId);
        g_vappEmailMgrClass->m_signalNcStateChange.emit(
            VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL,
            0,
            acctId);
    }
}


EMAIL_ACCT_ID VappEmailPush::getPushAcctId(void)
{
    EMAIL_ACCT_ID acctId = EMAIL_ACCT_INVALID_ID;
    VfxU32 count = 1;

    mmi_email_imap_push_acct_get(&acctId, &count);
    return acctId;
}

#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

