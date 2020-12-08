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
 *  vapp_email_emn.cpp
 *
 * Project:
 * --------
 *  COSMOS Email EMN
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
extern "C"
{
#include "MMIDataType.h"
#include "TimerEvents.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "MMI_inet_app_trc.h"

#include "EmailSrvGprot.h"
#include "Vapp_email_core.h"
}

#include "mmi_rp_vapp_email_def.h"
#include "vapp_email_mgr.h"
#include "vapp_email_emn.h"

#define VAPP_EMAIL_EMN_STATE_FILENAME       "emnState"
#define VAPP_EMAIL_EMN_STATE_FILENAME_LEN   (32)

#define VAPP_EMAIL_EMN_TIMEOUT              (KAL_TICKS_1_SEC * 30)


static VappEmailEmn *g_vappEmnClass = NULL;

VappEmailEmnCntxStruct VappEmailEmn::vappEmnCntx = {};

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappEmailEmn);

VappEmailEmn::VappEmailEmn()
{
    emnCntx = &vappEmnCntx;
    memset(emnCntx, 0, sizeof(VappEmailEmnCntxStruct));
}

void VappEmailEmn::onInit()
{
    g_vappEmnClass = VFX_OBJ_GET_INSTANCE(VappEmailEmn);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalAcctNwkDone.connect(this, &VappEmailEmn::onAcctNwkDone);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalNwkStop.connect(this, &VappEmailEmn::onAcctNwkStop);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalAcctDelete.connect(this, &VappEmailEmn::onAcctDelete);
}


void VappEmailEmn::readRecordFile(void)
{
    VappEmailEmnRecItemStruct *acctItem;
    WCHAR fn[VAPP_EMAIL_EMN_STATE_FILENAME_LEN];
    FS_HANDLE fd = -1;
    S32 ret;
    U32 rwByte;
    VfxU32 count;
    VfxU32 i;
    srv_email_result_enum retval;
    MMI_BOOL isValid;
    VfxBool needUpdate = VFX_FALSE;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_EMN_READ_RECORD_FILE_START);

    memset(&emnCntx->recTable, 0, sizeof(VappEmailEmnRecTableStruct));

    kal_wsprintf(fn, "%s%s", srv_email_get_root_path(), VAPP_EMAIL_EMN_STATE_FILENAME);

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
        acctItem = &emnCntx->recTable.acctList[emnCntx->recTable.acctNum];
        ret = FS_Read(
                fd,
                acctItem,
                sizeof(VappEmailEmnRecItemStruct),
                &rwByte);
        if (ret < 0 || rwByte != sizeof(VappEmailEmnRecItemStruct))
        {
            emnCntx->recTable.acctNum = 0;
            FS_Close(fd);
            FS_Delete(fn);
            return;
        }

        retval = srv_email_acct_check_valid(acctItem->acctId, &isValid);
        if (retval == SRV_EMAIL_RESULT_SUCC && isValid)
        {
            emnCntx->recTable.acctNum++;
        }
        else
        {
            needUpdate = VFX_TRUE;
        }
    }

    FS_Close(fd);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_EMN_READ_RECORD_FILE_END, emnCntx->recTable.acctNum);

    if (needUpdate)
    {
        updateRecordFile();
    }
}


void VappEmailEmn::updateRecordFile(void)
{
    WCHAR fn[VAPP_EMAIL_EMN_STATE_FILENAME_LEN];
    FS_HANDLE fd;
    S32 ret;
    U32 wByte;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_EMN_UPDATE_RECORD_FILE, emnCntx->recTable.acctNum);

    kal_wsprintf(fn, "%s%s", srv_email_get_root_path(), VAPP_EMAIL_EMN_STATE_FILENAME);

    fd = FS_Open(fn, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd < 0)
    {
        return;
    }

    ret = FS_Write(fd, &emnCntx->recTable, sizeof(VappEmailEmnRecTableStruct), &wByte);
    if (ret < 0 || wByte != sizeof(VappEmailEmnRecTableStruct))
    {
        FS_Close(fd);
        FS_Delete(fn);
        return;
    }

    FS_Close(fd);
}


void VappEmailEmn::addRecord(EMAIL_ACCT_ID acctId)
{
    VfxU32 i;

    for (i = 0; i < emnCntx->recTable.acctNum; i++)
    {
        if (emnCntx->recTable.acctList[i].acctId == acctId)
        {
            break;
        }
    }

    if (i == emnCntx->recTable.acctNum)
    {
        emnCntx->recTable.acctList[i].acctId = acctId;
        emnCntx->recTable.acctList[i].state = VAPP_EMAIL_EMN_STATE_PENDING;
        emnCntx->recTable.acctNum++;

        updateRecordFile();
        return;
    }

    emnCntx->recTable.acctList[i].state = VAPP_EMAIL_EMN_STATE_PENDING;
}


void VappEmailEmn::removeRecord(EMAIL_ACCT_ID acctId)
{
    VfxU32 i;

    for (i = 0; i < emnCntx->recTable.acctNum; i++)
    {
        if (emnCntx->recTable.acctList[i].acctId == acctId)
        {
            for (; i < emnCntx->recTable.acctNum - 1; i++)
            {
                memcpy(
                    &emnCntx->recTable.acctList[i],
                    &emnCntx->recTable.acctList[i + 1],
                    sizeof(VappEmailEmnRecItemStruct));
            }

            memset(&emnCntx->recTable.acctList[i], 0, sizeof(VappEmailEmnRecItemStruct));
            emnCntx->recTable.acctNum--;

            updateRecordFile();
        }
    }
}


void VappEmailEmn::setRecordState(EMAIL_ACCT_ID acctId, VappEmailEmnItemStateEnum state)
{
    VfxU32 i;

    for (i = 0; i < emnCntx->recTable.acctNum; i++)
    {
        if (emnCntx->recTable.acctList[i].acctId == acctId)
        {
            emnCntx->recTable.acctList[i].state = state;
        }
    }
}


VappEmailEmnItemStateEnum VappEmailEmn::getRecordState(EMAIL_ACCT_ID acctId)
{
    VfxU32 i;

    for (i = 0; i < emnCntx->recTable.acctNum; i++)
    {
        if (emnCntx->recTable.acctList[i].acctId == acctId)
        {
            return emnCntx->recTable.acctList[i].state;
        }
    }

    return VAPP_EMAIL_EMN_STATE_NONE;
}


void VappEmailEmn::addReq(EMAIL_ACCT_ID acctId, VappEmailEmnTypeEnum type)
{
    VfxU32 i;

    for (i = 0; i < emnCntx->reqTable.reqNum; i++)
    {
        if (emnCntx->reqTable.reqList[i].acctId == acctId)
        {
            break;
        }
    }

    if (i == emnCntx->reqTable.reqNum)
    {
        emnCntx->reqTable.reqList[i].acctId = acctId;
        emnCntx->reqTable.reqList[i].type = type;
        emnCntx->reqTable.reqNum++;
        return;
    }

    emnCntx->reqTable.reqList[i].type |= type;
}


void VappEmailEmn::removeReq(EMAIL_ACCT_ID acctId)
{
    VfxU32 i;

    for (i = 0; i < emnCntx->reqTable.reqNum; i++)
    {
        if (emnCntx->reqTable.reqList[i].acctId == acctId)
        {
            for (; i < emnCntx->reqTable.reqNum - 1; i++)
            {
                memcpy(
                    &emnCntx->reqTable.reqList[i],
                    &emnCntx->reqTable.reqList[i + 1],
                    sizeof(VappEmailEmnReqItemStruct));
            }

            memset(&emnCntx->reqTable.reqList[i], 0, sizeof(VappEmailEmnReqItemStruct));
            emnCntx->reqTable.reqNum--;
        }
    }
}


void VappEmailEmn::emnSchlRun(void)
{
    StopTimer(EMAIL_MMI_EMN_NOTIFY_TIMER);
    StartNonAlignTimer(EMAIL_MMI_EMN_NOTIFY_TIMER, VAPP_EMAIL_EMN_TIMEOUT, &VappEmailEmn::emnSchlCbFunc);
}


void VappEmailEmn::autoCheckNotifyCbFunc(EMAIL_ACCT_ID acctId)
{
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    VappEmailStateEnum state;
    VappEmailAcctStateEnum acctState;

#ifdef __MMI_EMAIL_IMAP_PUSH__
    if (VappEmailPush::isEnable() && (acctId == VappEmailPush::getPushAcctId()))
    {
        /* disable push account's auto check */
        mmi_email_auto_check_start(acctId);
        return;
    }
#endif

    state = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_EMN_AUTOCHK_NOTIFY_CB_FUNC, acctId, state);

    switch (state)
    {
        case VAPP_EMAIL_STATE_READY:
            acctState = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getAcctState(acctId);
            switch (acctState)
            {
                case VAPP_EMAIL_ACCT_STATE_NORMAL:
                case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
                case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
                case VAPP_EMAIL_ACCT_STATE_IN_USE:
                    g_vappEmnClass->addReq(acctId, VAPP_EMAIL_EMN_TYPE_AUTO_CHECK);
                    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->refreshAcct(acctId);
                    break;

                case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
                case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING:
                    g_vappEmnClass->addReq(acctId, VAPP_EMAIL_EMN_TYPE_AUTO_CHECK);
                    break;

                default:
                    mmi_email_auto_check_start(acctId);
                    break;
            }
            break;

        case VAPP_EMAIL_STATE_FLIGHT_MODE:
        case VAPP_EMAIL_STATE_NO_SIM:
            mmi_email_auto_check_start(acctId);
            break;

        default:
            return;
    }
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
}


void VappEmailEmn::emnNotifyCbFunc(EMAIL_ACCT_ID acctId)
{
    VappEmailStateEnum state;
    VappEmailAcctStateEnum acctState;

    g_vappEmnClass->addRecord(acctId);

    state = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_EMN_EMN_NOTIFY_CB_FUNC, acctId, state);

    switch (state)
    {
        case VAPP_EMAIL_STATE_READY:
            acctState = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getAcctState(acctId);
            switch (acctState)
            {
                case VAPP_EMAIL_ACCT_STATE_NORMAL:
                case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
                case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
                case VAPP_EMAIL_ACCT_STATE_IN_USE:
                    g_vappEmnClass->setRecordState(acctId, VAPP_EMAIL_EMN_STATE_RUNNING);
                    g_vappEmnClass->addReq(acctId, VAPP_EMAIL_EMN_TYPE_EMN);
                    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->refreshAcct(acctId);
                    break;

                case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
                    g_vappEmnClass->setRecordState(acctId, VAPP_EMAIL_EMN_STATE_RUNNING);
                    g_vappEmnClass->addReq(acctId, VAPP_EMAIL_EMN_TYPE_EMN);
                    break;

                default:
                    g_vappEmnClass->emnSchlRun();
                    break;
            }
            break;

        case VAPP_EMAIL_STATE_FLIGHT_MODE:
        case VAPP_EMAIL_STATE_NO_SIM:
            g_vappEmnClass->emnSchlRun();
            break;

        default:
            return;
    }
}

void VappEmailEmn::emnSchlCbFunc(void)
{
    VappEmailEmnCntxStruct *emnCntx = g_vappEmnClass->emnCntx;
    VappEmailStateEnum state;
    EMAIL_ACCT_ID acctId;
    VappEmailAcctStateEnum acctState;
    VfxU32 i;
    VfxBool restartTimer = VFX_FALSE;

    state = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_EMN_SCHEDULE_CB_FUNC, emnCntx->recTable.acctNum, state);

    switch (state)
    {
        case VAPP_EMAIL_STATE_READY:
            for (i = 0; i < emnCntx->recTable.acctNum; i++)
            {
                if (emnCntx->recTable.acctList[i].state == VAPP_EMAIL_EMN_STATE_PENDING)
                {
                    acctId = emnCntx->recTable.acctList[i].acctId;

                    acctState = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getAcctState(acctId);
                    switch (acctState)
                    {
                        case VAPP_EMAIL_ACCT_STATE_NORMAL:
                        case VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL:
                        case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL:
                        case VAPP_EMAIL_ACCT_STATE_IN_USE:
                            g_vappEmnClass->setRecordState(acctId, VAPP_EMAIL_EMN_STATE_RUNNING);
                            g_vappEmnClass->addReq(acctId, VAPP_EMAIL_EMN_TYPE_EMN);
                            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->refreshAcct(acctId);
                            break;

                        case VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING:
                            g_vappEmnClass->setRecordState(acctId, VAPP_EMAIL_EMN_STATE_RUNNING);
                            g_vappEmnClass->addReq(acctId, VAPP_EMAIL_EMN_TYPE_EMN);
                            break;

                        default:
                            restartTimer = VFX_TRUE;
                            break;
                    }
                }
            }

            if (restartTimer)
            {
                g_vappEmnClass->emnSchlRun();
            }
            break;

        case VAPP_EMAIL_STATE_FLIGHT_MODE:
        case VAPP_EMAIL_STATE_NO_SIM:
            g_vappEmnClass->emnSchlRun();
            break;

        default:
            return;
    }
}


void VappEmailEmn::onAcctNwkDone(EMAIL_ACCT_ID acctId, VappEmailNwkDoneEnum nwkType, VappEmailResStruct result)
{
    VappEmailEmnCntxStruct *emnCntx = g_vappEmnClass->emnCntx;
    VappEmailEmnItemStateEnum state;
    VfxU32 i;

    if (nwkType != VAPP_EMAIL_NWK_DONE_REFRESH &&
        nwkType != VAPP_EMAIL_NWK_DONE_CANCEL)
    {
        return;
    }

    for (i = 0; i < emnCntx->reqTable.reqNum; i++)
    {
        if (emnCntx->reqTable.reqList[i].acctId == acctId)
        {
            if (emnCntx->reqTable.reqList[i].type & VAPP_EMAIL_EMN_TYPE_AUTO_CHECK)
            {
                mmi_email_auto_check_start(acctId);
            }
            if (emnCntx->reqTable.reqList[i].type & VAPP_EMAIL_EMN_TYPE_EMN)
            {
                state = g_vappEmnClass->getRecordState(acctId);
                if (state == VAPP_EMAIL_EMN_STATE_RUNNING)
                {
                    g_vappEmnClass->removeRecord(acctId);
                }
            }
            g_vappEmnClass->removeReq(acctId);
            return;
        }
    }
}


void VappEmailEmn::onAcctNwkStop(VappEmailMgrStopCauseEnum stopCause)
{
    VappEmailEmnCntxStruct *emnCntx = g_vappEmnClass->emnCntx;
    VfxU32 i;

    for (i = 0; i < emnCntx->reqTable.reqNum; i++)
    {
        if (emnCntx->reqTable.reqList[i].type & VAPP_EMAIL_EMN_TYPE_AUTO_CHECK)
        {
            mmi_email_auto_check_start(emnCntx->reqTable.reqList[i].acctId);
        }
        if (emnCntx->reqTable.reqList[i].type & VAPP_EMAIL_EMN_TYPE_EMN)
        {
            g_vappEmnClass->setRecordState(emnCntx->reqTable.reqList[i].acctId, VAPP_EMAIL_EMN_STATE_PENDING);
        }
    }

    memset(&emnCntx->reqTable, 0, sizeof(VappEmailEmnReqTableStruct));

    g_vappEmnClass->emnSchlRun();
}


void VappEmailEmn::onAcctDelete(EMAIL_ACCT_ID acctId)
{
    g_vappEmnClass->removeReq(acctId);
    g_vappEmnClass->removeRecord(acctId);
}


void VappEmailEmn::startService(void)
{
    VappEmailStateEnum state = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();

    if (state == VAPP_EMAIL_STATE_READY ||
        state == VAPP_EMAIL_STATE_NO_SIM ||
        state == VAPP_EMAIL_STATE_FLIGHT_MODE)
    {
    #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
        mmi_email_auto_check_start_service(&VappEmailEmn::autoCheckNotifyCbFunc);
    #endif

        srv_email_register_emn_notify(0, &VappEmailEmn::emnNotifyCbFunc, NULL);
        readRecordFile();
        if (emnCntx->recTable.acctNum)
        {
            emnSchlRun();
        }
    }
}


void VappEmailEmn::stopService(void)
{
    VappEmailStateEnum state = VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();

    if (state == VAPP_EMAIL_STATE_READY ||
        state == VAPP_EMAIL_STATE_NO_SIM ||
        state == VAPP_EMAIL_STATE_FLIGHT_MODE)
    {
    #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
        mmi_email_auto_check_stop_service();
    #endif

        StopTimer(EMAIL_MMI_EMN_NOTIFY_TIMER);
        srv_email_clear_emn_notify(0);
    }
}


