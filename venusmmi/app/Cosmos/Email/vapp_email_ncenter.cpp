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
 *  Vapp_email_ncenter.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Notification Center
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "Vapp_email_main.h"
#include "Vapp_email_ncenter.h"
#include "vcp_global_popup.h"
#include "mmi_rp_srv_status_icons_def.h"

extern "C"
{
#include "GlobalResDef.h"
#include "Wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "NotificationGprot.h"

#include "mmi_rp_vapp_email_def.h"
#include "MMI_inet_app_trc.h"
#include "app_datetime.h"

void vapp_email_set_first_page_type(email_app_set_first_struct *pageInfo);
}

#define VAPP_EMAIL_NC_MAX_STR_LEN       (128)

/* 
 * refresh fail and push refresh fail use same status icon
 * so if there is no any refresh fail, we need hide refresh fail icon
 */
static VfxBool g_vappEmailRefreshFailIconIsShown = VFX_FALSE;
static VfxBool g_vappEmailPushRefreshFailIconIsShown = VFX_FALSE;

static const CHAR * VAPP_EMAIL_NCENTER_CELL_CONTEXT_FILE_NAME = "NCenterCellState";
static VappEmailNCenterCellContext g_vappEmailNCenterCellCntx = {};


static const VfxU32 g_vappEmailNCenterCtrlMemPollSize = 2 * 1024;
static VfxU32 g_vappEmailNCenterCtrlMemPoll[g_vappEmailNCenterCtrlMemPollSize / sizeof(VfxU32)];

//static const VfxS32 VAPP_EMAIL_FS_FULL_NOTIFICATION_TIMEOUT = (1000 * 30);
static const VfxU32 VAPP_EMAIL_PREVIEW_SUBJECT_MAX_LENGTH = 200;

static void vapp_email_show_alert_icon(S32 icon_id, VfxBool isAnimate)
{
    mmi_frm_nmgr_alert_struct alertInfo = {0};
    alertInfo.app_id = VAPP_EMAIL;
    alertInfo.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
    alertInfo.behavior_mask = FORCE_ICON_ONLY;
    alertInfo.status_bar_icon_para.icon_id = icon_id;
    if(isAnimate)
    {
        alertInfo.alert_option |= MMI_FRM_NMGR_ICON_ANIMATION;
    }
    mmi_frm_nmgr_alert(&alertInfo);
}

static void vapp_email_hide_alert_icon(S32 icon_id)
{
    NMGR_HANDLE nmgrHandle = mmi_frm_nmgr_compose_alert_handle(VAPP_EMAIL, MMI_EVENT_DEFAULT, icon_id);
    mmi_frm_nmgr_alert_cancel(nmgrHandle);
}


static void vapp_email_alert_cancel()
{
    NMGR_HANDLE nmgrHandle = mmi_frm_nmgr_compose_alert_handle(VAPP_EMAIL, MMI_EVENT_EMAIL_NEW_EMAIL, STATUS_ICON_INVALID_ID);
    mmi_frm_nmgr_alert_cancel(nmgrHandle);
}


static void vapp_email_show_refresh_fail_icon(VappEmailNCenterCellTypeEnum cellType)
{
    switch (cellType)
    {
        case VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL:
            g_vappEmailRefreshFailIconIsShown = VFX_TRUE;
			break;
            
        case VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL:
            g_vappEmailPushRefreshFailIconIsShown = VFX_TRUE;
			break;
            
        default:
            return;
    }

    vapp_email_show_alert_icon(STATUS_ICON_EMAIL_FAIL, VFX_FALSE);
}


static void vapp_email_hide_refresh_fail_icon(VappEmailNCenterCellTypeEnum cellType)
{
    switch (cellType)
    {
        case VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL:
            g_vappEmailRefreshFailIconIsShown = VFX_FALSE;
			break;
            
        case VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL:
            g_vappEmailPushRefreshFailIconIsShown = VFX_FALSE;
			break;
            
        default:
            return;
    }

    if (!g_vappEmailRefreshFailIconIsShown &&
        !g_vappEmailPushRefreshFailIconIsShown)
    {
        vapp_email_hide_alert_icon(STATUS_ICON_EMAIL_FAIL);
    }
}


/*****************************************************************************
 * Class VappEmailNotificationCtrl
 *****************************************************************************/

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappEmailNotificationCtrl);

VappEmailNCenterCellContext* VappEmailNotificationCtrl::g_cellContext = &g_vappEmailNCenterCellCntx;


void VappEmailNotificationCtrl::onInit()
{
    VfxObject::onInit();
    
    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool((VfxU8*)g_vappEmailNCenterCtrlMemPoll, g_vappEmailNCenterCtrlMemPollSize);

    VFX_OBJ_CREATE_EX(m_sendFailNotify, VappEmailNcFailNoti, this, (VAPP_EMAIL_NCENTER_CELL_SEND_FAIL));
    VFX_OBJ_CREATE_EX(m_refreshFailNotify, VappEmailNcFailNoti, this, (VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL));
#ifdef __MMI_EMAIL_IMAP_PUSH__     
    VFX_OBJ_CREATE_EX(m_pushRefreshFailNotify, VappEmailNcFailNoti, this, (VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL));
#endif
    VFX_OBJ_CREATE_EX(m_sendingNotify, VappEmailNcOngoingNoti, this, (VAPP_EMAIL_NCENTER_CELL_SENDING));
    VFX_OBJ_CREATE_EX(m_refreshingNotify, VappEmailNcOngoingNoti, this, (VAPP_EMAIL_NCENTER_CELL_REFRESHING));
    VFX_OBJ_CREATE(m_fsFullNotify, VappEmailNcFsFullNoti, this);

    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalNcStateChange.connect(this, &VappEmailNotificationCtrl::onNcStateChange);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalNcShowHide.connect(this, &VappEmailNotificationCtrl::onNcShowHide);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalAcctNwkDone.connect(this, &VappEmailNotificationCtrl::onAcctNwkDone);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalNewMsg.connect(this, &VappEmailNotificationCtrl::onShowMsgNoti);
}


void VappEmailNotificationCtrl::SysInit(void)
{
    readCellContext();

    VappEmailNcUnreadNoti::sysInit();
    m_sendFailNotify->sysInit();
    m_refreshFailNotify->sysInit();
#ifdef __MMI_EMAIL_IMAP_PUSH__    
    m_pushRefreshFailNotify->sysInit();
#endif
    m_sendingNotify->sysInit();
    m_refreshingNotify->sysInit();
    m_fsFullNotify->sysInit();

    VsrvNGroupSingleTitle *group = getNGroup();
}


VsrvNGroupSingleTitle* VappEmailNotificationCtrl::getNGroup(void)
{
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VsrvNGroupSingleTitle *group = (VsrvNGroupSingleTitle*)nm->queryNGroup(VAPP_EMAIL);

    if (group == NULL)
    {
        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_EMAIL));
        group->setTitle(VFX_WSTR_RES(STR_EMAIL_FTO_EMAIL));
    }

    return group;
}


void VappEmailNotificationCtrl::readCellContext(void)
{
    VfxWString path;
    VfxS32 ret;
    U32 readWrite;

    if (g_cellContext == NULL)
    {
        return;
    }
    
    memset(g_cellContext, 0, sizeof(VappEmailNCenterCellContext));
    
    path.format(
        "%s%s",
        srv_email_get_root_path(),
        VAPP_EMAIL_NCENTER_CELL_CONTEXT_FILE_NAME);

    FS_HANDLE hd = FS_Open((WCHAR*)path.getBuf(), FS_READ_ONLY);
    if (hd < FS_NO_ERROR)
    {
        VEMAIL_TRC_GLB_SET_OPEN(hd);
        writeCellContext();
        return;
    }
    ret = FS_Read(hd, g_cellContext, sizeof(VappEmailNCenterCellContext), &readWrite);
    if (ret < FS_NO_ERROR || readWrite != sizeof(VappEmailNCenterCellContext))
    {
        VEMAIL_TRC_GLB_SET_READ(
            ret,
            readWrite,
            sizeof(VappEmailNCenterCellContext));
    }
    FS_Close(hd);

}


void VappEmailNotificationCtrl::writeCellContext(void)
{
    VfxWString path;
    S32 ret;
    U32 readWrite;

    if (g_cellContext == NULL)
    {
        return;
    }

    path.format(
        "%s%s",
        srv_email_get_root_path(),
        VAPP_EMAIL_NCENTER_CELL_CONTEXT_FILE_NAME);

    FS_HANDLE hd = FS_Open(
                    (WCHAR*)path.getBuf(),
                    (FS_READ_WRITE | FS_CREATE_ALWAYS));
    if (hd < FS_NO_ERROR)
    {
        VEMAIL_TRC_GLB_SET_OPEN(hd);
        return;
    }
    ret = FS_Write(hd, g_cellContext, sizeof(VappEmailNCenterCellContext), &readWrite);
    if (ret < FS_NO_ERROR || sizeof(VappEmailNCenterCellContext) != readWrite)
    {
        VEMAIL_TRC_GLB_SET_WRITE(
            ret,
            readWrite,
            sizeof(VappEmailNCenterCellContext));
    }
    FS_Close(hd);

}
    

void VappEmailNotificationCtrl::getCellState(VappEmailNCenterCellTypeEnum cellType, VappEmailNCenterCellState *cellState)
{
    memcpy(cellState, &g_cellContext->cellState[cellType], sizeof(VappEmailNCenterCellState));
}


void VappEmailNotificationCtrl::updateCellState(VappEmailNCenterCellTypeEnum cellType, VappEmailNCenterCellState *cellState)
{
    if (g_cellContext->cellState[cellType].isHandled != cellState->isHandled ||
        g_cellContext->cellState[cellType].timeStamp != cellState->timeStamp ||
        g_cellContext->cellState[cellType].num != cellState->num ||
        g_cellContext->cellState[cellType].acctId != cellState->acctId)
    {
        memcpy(&g_cellContext->cellState[cellType], cellState, sizeof(VappEmailNCenterCellState));
        writeCellContext();
    }
}


void VappEmailNotificationCtrl::setCellHandled(VappEmailNCenterCellTypeEnum cellType, VfxBool isHandled)
{
    if (g_cellContext->cellState[cellType].isHandled != isHandled)
    {
        g_cellContext->cellState[cellType].isHandled = isHandled;
        writeCellContext();
    }
}

mmi_ret VappEmailNotificationCtrl::newMsgProc(mmi_event_struct *param)
{
    VappEmailNewMsgStruct *newMsg = (VappEmailNewMsgStruct *)param->user_data;

    if(param->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH || 
       param->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
        launchApp(newMsg->acctId, newMsg->fldrId, newMsg->msgId);
    }
    return MMI_TRUE;
}

void VappEmailNotificationCtrl::launchApp(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId, EMAIL_MSG_ID msgId)
{
    S32 acctNum = MMI_EMAIL_MAX_ACCTS;
    VfxApp *app = NULL;
    email_app_set_first_struct *firstPage = NULL;
    srv_email_result_enum retval;
    EMAIL_ACCT_ID acctIdtemp;
    
    retval = srv_email_acct_get_acct_id(0, &acctNum, &acctIdtemp);
    if (retval != SRV_EMAIL_RESULT_SUCC || acctNum == 0)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_EMAIL_FTO_NO_EMAIL_ACCT));
        return;
    }
    if(fldrId != srv_email_fldr_type_to_fldr_id(acctId, SRV_EMAIL_FLDR_TYPE_INBOX))
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_EMAIL_ERROR_CODE_MSG_NOT_EXISTING_ID));
        return;
    }
    MMI_BOOL isValid;
    retval = srv_email_msg_check_valid(msgId, &isValid);
    if(retval != SRV_EMAIL_RESULT_SUCC || isValid == MMI_FALSE)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_EMAIL_ERROR_CODE_MSG_NOT_EXISTING_ID));
        return;
    }
    firstPage = (email_app_set_first_struct*)OslMalloc(sizeof(email_app_set_first_struct));
    memset(firstPage, 0, sizeof(email_app_set_first_struct));
    firstPage->entry_point = EMAIL_ENTRY_FROM_NCENTER;
    firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_MSG_VIEW;
    firstPage->acct_id = acctId;
    firstPage->fldr_id = fldrId;
    firstPage->msg_id = msgId;
    firstPage->fldr_type = SRV_EMAIL_FLDR_TYPE_INBOX;

    app = VfxAppLauncher::findApp(VAPP_EMAIL, VFX_OBJ_CLASS_INFO(VappEmailApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }

    vapp_email_set_first_page_type(firstPage);
    OslMfree(firstPage);

    VfxAppLauncher::launch(
        VAPP_EMAIL,
        VFX_OBJ_CLASS_INFO(VappEmailApp),
        GRP_ID_ROOT);
}


void VappEmailNotificationCtrl::onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 acctNum, VfxU32 acctId)
{
    switch (ncType)
    {
        case VAPP_EMAIL_NC_TYPE_EVENT_UNREAD:
        {
            VappEmailNcUnreadNoti::onNcStateChange(ncType, acctNum, acctId);
            break;
        }
        case VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL:
        {
            m_sendFailNotify->onNcStateChange(ncType, acctNum, acctId);
            break;
        }
        case VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL:
        {
            m_refreshFailNotify->onNcStateChange(ncType, acctNum, acctId);
            break;
        }
#ifdef __MMI_EMAIL_IMAP_PUSH__
         case VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL:
         {
            m_pushRefreshFailNotify->onNcStateChange(ncType, acctNum, acctId);
            break;
         }
#endif
        case VAPP_EMAIL_NC_TYPE_ONGOING_SEND:
        {
            m_sendingNotify->onNcStateChange(ncType, acctNum, acctId);
            break;
        }
        case VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH:
        {
            m_refreshingNotify->onNcStateChange(ncType, acctNum, acctId);
            break;
        }
        default:
        {
            break;
        }
    }    
}


void VappEmailNotificationCtrl::onNcShowHide(VappEmailNcTypeEnum ncType, VfxBool showEvent, VfxBool showBalloon)
{
    switch (ncType)
    {
        case VAPP_EMAIL_NC_TYPE_EVENT_UNREAD:
        {
            VappEmailNcUnreadNoti::onNcShowHide(ncType, showEvent, VFX_FALSE);
            break;
        }
        case VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL:
        {
            m_sendFailNotify->onNcShowHide(ncType, showEvent, showBalloon);
            break;
        }
        case VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL:
        {
            m_refreshFailNotify->onNcShowHide(ncType, showEvent, showBalloon);
            break;
        }
#ifdef __MMI_EMAIL_IMAP_PUSH__    
        case VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL:
        {
            m_pushRefreshFailNotify->onNcShowHide(ncType, showEvent, showBalloon);
            break;
        }
#endif
        default:
        {
            break;
        }
    }
}


void VappEmailNotificationCtrl::onAcctNwkDone(EMAIL_ACCT_ID acctId, VappEmailNwkDoneEnum operation, VappEmailResStruct res)
{
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, TRC_VEMAIL_MAIN_ACCT_NWK_DONE, operation, res.result);

    if (acctId == EMAIL_ACCT_INVALID_ID)
    {
        return;
    }
    
    if (operation >= VAPP_EMAIL_NWK_DONE_SEND && operation <= VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER)
    {
        if (res.result != SRV_EMAIL_RESULT_SUCC && 
            res.major == SRV_EMAIL_FS_ERROR &&
            res.minor == FS_DISK_FULL)
        {
            m_fsFullNotify->showNotify(VFX_TRUE);
        }
        else if(res.result == SRV_EMAIL_RESULT_SUCC)
        {
            m_fsFullNotify->showNotify(VFX_FALSE);
        }
    }
}

void VappEmailNotificationCtrl::onShowMsgNoti(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId, EMAIL_MSG_ID msgId, VfxU32 recvNum)
{
    VappEmailNewMsgStruct newMsg = {0};
    mmi_frm_nmgr_alert_struct alertInfo = {0};
    srv_email_result_enum retval;
    EMAIL_MSG_HANDLE msgHandle;
    srv_email_addr_struct srvAddr;
    WCHAR *subjBuf = NULL;
    S32 subjChset;
    U32 subjLen;
    U32 bufLen;

    newMsg.acctId = acctId;
    newMsg.fldrId = fldrId;
    newMsg.msgId = msgId;

    alertInfo.app_id = VAPP_EMAIL;
    alertInfo.scen_id = MMI_SCENARIO_ID_NEW_EMAIL;
    alertInfo.event_type = MMI_EVENT_EMAIL_NEW_EMAIL;
    alertInfo.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
    alertInfo.behavior_mask = PREFER_DEFAULT;
    if(recvNum > 1)
    {
        alertInfo.alert_option |= MMI_FRM_NMGR_DISABLE_TONE | MMI_FRM_NMGR_DISABLE_VIB;
    }
    
    alertInfo.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    alertInfo.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
    alertInfo.status_bar_para.image.id = IMG_SI_UNREAD_EMAIL;

    alertInfo.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    alertInfo.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
    alertInfo.popup_para.image.id = IMG_EMAIL_FTO_MAINMENU;

    retval = srv_email_msg_create(0, &msgHandle);
    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        retval = srv_email_msg_open(msgHandle, acctId, fldrId, msgId);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            retval = srv_email_msg_get_sender(msgHandle, &srvAddr);
            if (retval == SRV_EMAIL_RESULT_SUCC)
            {
                retval = srv_email_msg_get_subject_len(msgHandle, &subjLen, &subjChset);
                
                if (subjLen > VAPP_EMAIL_PREVIEW_SUBJECT_MAX_LENGTH)
                {
                    subjLen = VAPP_EMAIL_PREVIEW_SUBJECT_MAX_LENGTH;
                }      
                
                if (retval == SRV_EMAIL_RESULT_SUCC)
                {
                    if (subjLen)
                    {
                        bufLen = subjLen + 1;
                        subjBuf = (WCHAR*)OslMalloc(bufLen * ENCODING_LENGTH);
                        retval = srv_email_msg_get_subject(msgHandle, subjBuf, &bufLen);
                    }
                    else
                    {
                        subjLen = mmi_wcslen((const WCHAR*)GetString(STR_EMAIL_FTO_COMMON_NO_SUBJECT_ID));
                        subjBuf = (WCHAR*)OslMalloc((subjLen + 1) * ENCODING_LENGTH);
                        mmi_wcscpy(subjBuf, (const WCHAR*)GetString(STR_EMAIL_FTO_COMMON_NO_SUBJECT_ID));
                    }

                    if (retval == SRV_EMAIL_RESULT_SUCC)
                    {
                        S32 dispLen = mmi_wcslen(srvAddr.disp_name) * ENCODING_LENGTH;
                        S32 addrLen = mmi_wcslen(srvAddr.email_addr) * ENCODING_LENGTH;
                        S32 tempLen = (subjLen + 3) * ENCODING_LENGTH;
                        WCHAR *tempBuf = NULL;
                        WCHAR *sender = NULL;

                        if (dispLen)
                        {
                            tempLen += dispLen;
                            sender = srvAddr.disp_name;
                        }
                        else if (addrLen)
                        {
                            tempLen += addrLen;
                            sender = srvAddr.email_addr;
                        }

                        tempBuf = (WCHAR*)OslMalloc(tempLen);
                        if (dispLen || addrLen)
                        {
                            mmi_wcscpy(tempBuf, sender);
                        }
                        else
                        {
                            tempBuf[0] = 0;
                        }

                        if (subjLen)
                        {
                            tempLen = mmi_wcslen(tempBuf);
                            kal_wsprintf(tempBuf + tempLen, ": %w", subjBuf);
                        }
                        alertInfo.status_bar_para.display_string = tempBuf;
                        alertInfo.popup_para.popup_string = tempBuf;
                        alertInfo.popup_para.popup_button_string = (VfxWChar*)GetString(STR_GLOBAL_VIEW);

                        alertInfo.app_proc_para.scrn_group_proc = &VappEmailNotificationCtrl::newMsgProc;
                        alertInfo.app_proc_para.user_data = &newMsg;
                        alertInfo.app_proc_para.data_size = sizeof(VappEmailNewMsgStruct);
                        mmi_frm_nmgr_alert(&alertInfo);
                        OslMfree(tempBuf);
                    }

                    OslMfree(subjBuf);
                }
            }
        }
        srv_email_msg_destroy(msgHandle);
    }  
}
/*****************************************************************************
 * Class VappEmailNcFsFullNoti
 *****************************************************************************/
void VappEmailNcFsFullNoti::sysInit()
{
    showNotify(VFX_FALSE);
}

VsrvNotificationEvent* VappEmailNcFsFullNoti::getNotify()
{
    VsrvNGroupSingleTitle *group = VappEmailNotificationCtrl::getNGroup();
    VsrvNotificationEvent *noti = (VsrvNotificationEvent*)group->queryNotification(VAPP_EMAIL_NCENTER_CELL_FS_FULL);

    if (noti == NULL)
    {
        VfxObjHandle objHandle = getObjHandle();
        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*)group, VAPP_EMAIL_NCENTER_CELL_FS_FULL));
        noti->setIcon(VfxImageSrc(IMG_EMAIL_FTO_NC_UNREAD));        
        noti->setIntentCallback(intentCallback, &objHandle, sizeof(VfxObjHandle));
        noti->setAutoClose(VFX_FALSE);
    }

    return noti;
}


void VappEmailNcFsFullNoti::showNotify(VfxBool show)
{
    if (show)
    {
        updateNotify();
    }
    else
    {
        VSRV_NOTIFICATION_CLOSE_EX(VAPP_EMAIL, VAPP_EMAIL_NCENTER_CELL_FS_FULL);
    }
}


void VappEmailNcFsFullNoti::updateNotify(VfxBool isChangeTime)
{
    VsrvNotificationEvent *noti = getNotify();
    VfxResId mainText;

    if (SRV_FMGR_DRV_PHONE_TYPE == srv_fmgr_drv_get_type(srv_email_get_drive()))
    {
        mainText = STR_EMAIL_FTO_PHONE_FULL;
    }
    else
    {
        mainText = STR_EMAIL_FTO_MEMORY_FULL;        
    }

    noti->setMainText(VFX_WSTR_RES(mainText));    
    noti->notify();
}


void VappEmailNcFsFullNoti::intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    VfxResId strId;
    
    if (noti == NULL || userData == NULL)
    {
       return; 
    }

    VappEmailNcFsFullNoti *fsFullNotify = (VappEmailNcFsFullNoti *)handleToObject(*(VfxObjHandle*)userData);

    if (fsFullNotify == NULL)
    {
        return;
    }

    if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
    {

    }  
    else if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        if (SRV_FMGR_DRV_PHONE_TYPE == srv_fmgr_drv_get_type(srv_email_get_drive()))
        {
            strId = STR_EMAIL_FTO_REMOVE_PHONE_FILE;
        }
        else
        {
            strId = STR_EMAIL_FTO_REMOVE_MEMORY_FILE;        
        }
        vcp_global_popup_show_confirm_one_button_id(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_INFO,
            strId,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);
        fsFullNotify->showNotify(VFX_FALSE);
    }
    else if (intent.type == VSRV_NINTENT_TYPE_CLEAR)
    {
        fsFullNotify->showNotify(VFX_FALSE);
    }
    else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
    {
        fsFullNotify->updateNotify(VFX_FALSE);
    }
}


/*****************************************************************************
 * Class VappEmailNcUnreadNoti
 *****************************************************************************/

VfxBool VappEmailNcUnreadNoti::m_isShow;
VfxU32 VappEmailNcUnreadNoti::m_unreadNum;
VfxBool VappEmailNcUnreadNoti::m_inited;


void VappEmailNcUnreadNoti::sysInit()
{
    m_isShow = VFX_FALSE;
    m_inited = VFX_FALSE;

    VappEmailNCenterCellState cellState;
    VappEmailNotificationCtrl::getCellState(VAPP_EMAIL_NCENTER_CELL_UNREAD, &cellState);
    m_unreadNum = cellState.num;

    if (!cellState.isHandled && cellState.num != 0)
    {
        showNotify(VFX_TRUE);
        vapp_email_show_alert_icon(STATUS_ICON_UNREAD_EMAIL, VFX_FALSE);
    }

    m_inited = VFX_TRUE;
}


VsrvNotificationEvent* VappEmailNcUnreadNoti::getNotify()
{
    VsrvNGroupSingleTitle *group = VappEmailNotificationCtrl::getNGroup();
    VsrvNotificationEvent *noti = (VsrvNotificationEvent*)group->queryNotification(VAPP_EMAIL_NCENTER_CELL_UNREAD);

    if (noti == NULL)
    {
        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*)group, VAPP_EMAIL_NCENTER_CELL_UNREAD));
        noti->setIcon(VfxImageSrc(IMG_EMAIL_FTO_NC_UNREAD));
        noti->setMainText(VFX_WSTR_RES(STR_EMAIL_FTO_NC_UNREAD_ID));        
        noti->setIntentCallback(intentCallback, NULL, 0);
        noti->setAutoClose(VFX_FALSE);
    }

    return noti;
}


void VappEmailNcUnreadNoti::showNotify(VfxBool show)
{
    if (show)
    {
        updateNotify();
        m_isShow = VFX_TRUE;
    }
    else
    {
        VSRV_NOTIFICATION_CLOSE_EX(VAPP_EMAIL, VAPP_EMAIL_NCENTER_CELL_UNREAD);
        m_isShow = VFX_FALSE;
    }
}


void VappEmailNcUnreadNoti::updateNotify(VfxBool isChangeTime)
{
    VsrvNotificationEvent *noti = getNotify();
    
    VfxWString subText, subNextText;
    if (m_unreadNum > 1)
    {
        subText.format("%d", m_unreadNum);
        subNextText.loadFromRes(STR_EMAIL_FTO_NC_UNREAD_MAILS_ID);
        subText += subNextText;
    }
    else
    {
        subText.format("%d", m_unreadNum);
        subNextText.loadFromRes(STR_EMAIL_FTO_NC_UNREAD_MAIL_ID);
        subText += subNextText;
    }
    if(isChangeTime)
    {
        VappEmailNCenterCellState cellState;
        VappEmailNotificationCtrl::getCellState(VAPP_EMAIL_NCENTER_CELL_UNREAD, &cellState);
  
        VfxDateTime dateTime;
        applib_time_struct applib_time = {0};

        if (!m_inited)
        {
            m_inited = VFX_TRUE;
            VfxU32 local_sec = applib_dt_sec_utc_to_local(cellState.timeStamp);        
            applib_dt_utc_sec_2_mytime(local_sec, &applib_time, KAL_FALSE);
            dateTime.setDateTime(&applib_time);
        }
        else
        {
            cellState.num = m_unreadNum;
            dateTime.setCurrentTime();
            applib_time = dateTime.getDateTime();
            cellState.timeStamp = applib_dt_mytime_2_utc_sec(&applib_time, KAL_FALSE);
            VappEmailNotificationCtrl::updateCellState(VAPP_EMAIL_NCENTER_CELL_UNREAD, &cellState);        
        }
        noti->setTimeStamp(dateTime);
    }
    noti->setSubText(subText);
    noti->notify();
}


void VappEmailNcUnreadNoti::clearNotify()
{
    showNotify(VFX_FALSE);
    vapp_email_hide_alert_icon(STATUS_ICON_UNREAD_EMAIL);
    VappEmailNotificationCtrl::setCellHandled(VAPP_EMAIL_NCENTER_CELL_UNREAD, VFX_TRUE);
}


void VappEmailNcUnreadNoti::intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
    {

    }  
    else if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        launchApp();
    }
    else if (intent.type == VSRV_NINTENT_TYPE_CLEAR)
    {
        clearNotify();
    }
    else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
    {
        updateNotify(VFX_FALSE);
    }
}


void VappEmailNcUnreadNoti::launchApp(void)
{
    VfxApp *app = NULL;
    email_app_set_first_struct *firstPage = NULL;
    srv_email_acct_info_cache_struct acctInfo;
    srv_email_result_enum retval;
    S32 acctNum = MMI_EMAIL_MAX_ACCTS;
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    S32 i;
    VfxU32 acctCnt = 0;
    VfxU32 msgCnt = 0;
    EMAIL_ACCT_ID matchedAcctId = EMAIL_ACCT_INVALID_ID;
    EMAIL_MSG_ID matchedMsgId = EMAIL_MSG_INVALID_ID;

    firstPage = (email_app_set_first_struct*)OslMalloc(sizeof(email_app_set_first_struct));
    memset(firstPage, 0, sizeof(email_app_set_first_struct));
    firstPage->entry_point = EMAIL_ENTRY_FROM_NCENTER;

    retval = srv_email_acct_get_acct_id(0, &acctNum, acctId);
    if (retval != SRV_EMAIL_RESULT_SUCC || acctNum == 0)
    {
        return;
    }

    for (i = 0; i < acctNum; i++)
    {
        srv_email_acct_cache_get(acctId[i], &acctInfo);
        if (acctInfo.unread_num)
        {
            matchedAcctId = acctId[i];
            acctCnt++;
            msgCnt += acctInfo.unread_num;
        }
    }

    if (acctCnt == 0)
    {
        if (acctNum > 1)
        {
            acctCnt = MMI_EMAIL_MAX_ACCTS;
        }
        else
        {
            acctCnt = 1;
            msgCnt = SRV_EMAIL_GLOBAL_MAX_MSG_NUM;
            matchedAcctId = acctId[0];
        }
    }

    if (acctCnt > 1)
    {
        firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_ACCT_LIST;
    }
    else if (msgCnt > 1)
    {
        firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_MSG_LIST;
        firstPage->acct_id = matchedAcctId;
        firstPage->fldr_id = srv_email_fldr_type_to_fldr_id(matchedAcctId, SRV_EMAIL_FLDR_TYPE_INBOX);
        firstPage->fldr_type = SRV_EMAIL_FLDR_TYPE_INBOX;
    }
    else
    {
        firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_MSG_VIEW;
        firstPage->acct_id = matchedAcctId;
        firstPage->fldr_id = srv_email_fldr_type_to_fldr_id(matchedAcctId, SRV_EMAIL_FLDR_TYPE_INBOX);

        srv_email_fldr_get_all_msg_id(
            matchedAcctId,
            firstPage->fldr_id,
            EMAIL_MSG_FLAG_SEEN,
            0,
            &msgCnt,
            &matchedMsgId);

        firstPage->msg_id = matchedMsgId;
        firstPage->fldr_type = SRV_EMAIL_FLDR_TYPE_INBOX;
    }

    app = VfxAppLauncher::findApp(
                            VAPP_EMAIL, 
                            VFX_OBJ_CLASS_INFO(VappEmailApp), 
                            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 
                            0);
    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }

    vapp_email_set_first_page_type(firstPage);
    OslMfree(firstPage);

    VfxAppLauncherParam launchParam(VAPP_EMAIL, VFX_OBJ_CLASS_INFO(VappEmailApp), GRP_ID_ROOT);
    launchParam.setLauncherResultCb(launchAppCallback, NULL);
    VfxAppLauncher::launchEx(launchParam);
}


void VappEmailNcUnreadNoti::launchAppCallback(VfxAppLauncherResultEnum result, void *userData)
{
    if (result == VFX_APP_LAUNCHER_RESULT_OK)
    {
        clearNotify();
    }
}


void VappEmailNcUnreadNoti::onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 unreadNum, VfxU32 type)
{
    if (m_unreadNum != unreadNum)
    {
        VfxU32 oldUnreadNum = m_unreadNum;        
        m_unreadNum = unreadNum;
    
        if (unreadNum)
        {
            if (m_isShow)
            {
                updateNotify();
            }

            if (oldUnreadNum < unreadNum)
            {
                showNotify(VFX_TRUE);
                vapp_email_show_alert_icon(STATUS_ICON_UNREAD_EMAIL, VFX_FALSE);
                VappEmailNotificationCtrl::setCellHandled(VAPP_EMAIL_NCENTER_CELL_UNREAD, VFX_FALSE);
            }
        }
        else
        {
            showNotify(VFX_FALSE);
            VappEmailNCenterCellState cellState = {0};
            VappEmailNotificationCtrl::updateCellState(VAPP_EMAIL_NCENTER_CELL_UNREAD, &cellState);
            vapp_email_hide_alert_icon(STATUS_ICON_UNREAD_EMAIL);
        }
    } 
}

void VappEmailNcUnreadNoti::onNcShowHide(VappEmailNcTypeEnum ncType, VfxBool showEvent, VfxBool showBalloon)
{
    if(!showEvent)
    {
        showNotify(VFX_FALSE);
        vapp_email_hide_alert_icon(STATUS_ICON_UNREAD_EMAIL);
        vapp_email_alert_cancel();
    }
}


/*****************************************************************************
 * Class VappEmailNcFailNoti
 *****************************************************************************/
const VappEmailNcFailNoti::vapp_email_fail_notify_mapping_table_struct 
        VappEmailNcFailNoti::m_mappingTable[] = 
{
    //NCenter send fail
    {VAPP_EMAIL_NCENTER_CELL_SEND_FAIL, 
     IMG_EMAIL_FTO_NC_SEND_FAIL, 
     STATUS_ICON_EMAIL_SEND_ERROR, 
     STR_EMAIL_FTO_NC_SEND_FAIL_ID, 
     MMI_EVENT_EMAIL_SEND_FAIL},
     
    //NCenter refresh fail
    {VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL, 
     IMG_EMAIL_FTO_NC_REFRESH_FAIL, 
     STATUS_ICON_EMAIL_FAIL, 
     STR_EMAIL_FTO_NC_REFRESH_FAIL_ID, 
     MMI_EVENT_EMAIL_REFRESH_FAIL},
     
#ifdef __MMI_EMAIL_IMAP_PUSH__
    //NCenter push refresh fail     
    {VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL, 
     IMG_EMAIL_FTO_NC_REFRESH_FAIL, 
     STATUS_ICON_EMAIL_FAIL, 
     STR_EMAIL_FTO_NC_PUSH_REFRESH_FAIL_ID, 
     MMI_EVENT_EMAIL_REFRESH_FAIL}
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */
};

VappEmailNcFailNoti::VappEmailNcFailNoti(VappEmailNCenterCellTypeEnum notifyType)
    : m_notifyType(notifyType),
      m_acctNum(0),
      m_acctId(EMAIL_ACCT_INVALID_ID),
      m_isShow(VFX_FALSE),
      m_inited(VFX_FALSE)
{
    VfxU32 i;
    VfxU32 entry = sizeof(m_mappingTable) / sizeof(vapp_email_fail_notify_mapping_table_struct);
    
    for (i = 0; i < entry; i++)
    {
        if (m_mappingTable[i].notifyType == m_notifyType)
        {
            m_imageIcon = m_mappingTable[i].imageIcon;
            m_statusIcon = m_mappingTable[i].statusIcon;
            m_mainText = m_mappingTable[i].mainText;
            m_eventType = m_mappingTable[i].eventType;
            break;
        }
    }

    MMI_ASSERT(i < entry);
};


void VappEmailNcFailNoti::sysInit()
{
    m_isShow = VFX_FALSE;
    m_inited = VFX_FALSE;

    VappEmailNCenterCellState cellState;
    VappEmailNotificationCtrl::getCellState(m_notifyType, &cellState);
    m_acctNum = cellState.num;
    m_acctId = cellState.acctId;

    if (!cellState.isHandled && cellState.num != 0)
    {
        showNotify(VFX_TRUE);
        vapp_email_show_refresh_fail_icon(m_notifyType);
    }

    m_inited = VFX_TRUE;    
}


VsrvNotificationEvent* VappEmailNcFailNoti::getNotify()
{
    VsrvNGroupSingleTitle *group = VappEmailNotificationCtrl::getNGroup();
    VsrvNotificationEvent *noti = (VsrvNotificationEvent*)group->queryNotification(m_notifyType);

    if (noti == NULL)
    {
        VfxObjHandle objHandle = getObjHandle();
        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*)group, m_notifyType));
        noti->setIcon(VfxImageSrc(m_imageIcon));
        noti->setMainText(VFX_WSTR_RES(m_mainText));        
        noti->setIntentCallback(intentCallback, &objHandle, sizeof(VfxObjHandle));
        noti->setAutoClose(VFX_FALSE);
    }

    return noti;
}


void VappEmailNcFailNoti::showNotify(VfxBool show)
{
    if (show)
    {
        updateNotify();
        m_isShow = VFX_TRUE;
    }
    else
    {
        VSRV_NOTIFICATION_CLOSE_EX(VAPP_EMAIL, m_notifyType);
        m_isShow = VFX_FALSE;
    }
}


void VappEmailNcFailNoti::updateNotify(VfxBool isChangeTime)
{
    VsrvNotificationEvent *noti = getNotify();
    
    VfxWString subText, subNextText;
    if (m_acctNum > 1)
    {
        subText.format("%d", m_acctNum);
        subNextText.loadFromRes(STR_EMAIL_FTO_NC_ACCOUNTS_ID);
        subText += subNextText;
    }
    else
    {
        srv_email_acct_info_cache_struct acctInfo;

        srv_email_acct_cache_get(m_acctId, &acctInfo);
        subText = VFX_WSTR_MEM(acctInfo.acct_name);
    }
    if(isChangeTime)
    {
        VappEmailNCenterCellState cellState;
        VappEmailNotificationCtrl::getCellState(m_notifyType, &cellState);
 
        VfxDateTime dateTime;
        applib_time_struct applib_time = {0};
    
        if (!m_inited)
        {
            m_inited = VFX_TRUE;
            VfxU32 local_sec = applib_dt_sec_utc_to_local(cellState.timeStamp);        
            applib_dt_utc_sec_2_mytime(local_sec, &applib_time, KAL_FALSE);
            dateTime.setDateTime(&applib_time);
        }
        else
        {
            cellState.acctId = m_acctId;
            cellState.num = m_acctNum;
            dateTime.setCurrentTime();
            applib_time = dateTime.getDateTime();
            cellState.timeStamp = applib_dt_mytime_2_utc_sec(&applib_time, KAL_FALSE);
            VappEmailNotificationCtrl::updateCellState(m_notifyType, &cellState);        
        }
        noti->setTimeStamp(dateTime);
    }
    noti->setSubText(subText);
    noti->notify();
}


void VappEmailNcFailNoti::clearNotify()
{
    showNotify(VFX_FALSE);
    m_acctNum = 0;
    m_acctId = EMAIL_ACCT_INVALID_ID;

    if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SEND_FAIL)
    {
        vapp_email_hide_alert_icon(m_statusIcon);
    }
    else if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL ||
             m_notifyType == VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL)
    {
        vapp_email_hide_refresh_fail_icon(m_notifyType);
    }

    VappEmailNotificationCtrl::setCellHandled(m_notifyType, VFX_TRUE);
}


void VappEmailNcFailNoti::intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    if (noti == NULL || userData == NULL)
    {
       return; 
    }

    VappEmailNcFailNoti *failNotify = (VappEmailNcFailNoti *)handleToObject(*(VfxObjHandle*)userData);

    if (failNotify == NULL)
    {
        return;
    }

    if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        failNotify->launchApp();
    }
    else if (intent.type == VSRV_NINTENT_TYPE_CLEAR)
    {
        failNotify->clearNotify();
    }
    else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
    {
        failNotify->updateNotify(VFX_FALSE);
    }
}


void VappEmailNcFailNoti::launchApp(void)
{
    VfxApp *app = NULL;
    email_app_set_first_struct *firstPage = NULL;

    firstPage = (email_app_set_first_struct*)OslMalloc(sizeof(email_app_set_first_struct));
    memset(firstPage, 0, sizeof(email_app_set_first_struct));
    firstPage->entry_point = EMAIL_ENTRY_FROM_NCENTER;

    if (m_acctNum > 1)
    {
        firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_ACCT_LIST;
    }
    else
    {
        srv_email_fldr_type_enum folderType;
        
        if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SEND_FAIL)
        {
            folderType = SRV_EMAIL_FLDR_TYPE_OUTBOX;
        }
        else if(m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL ||
                m_notifyType == VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL)
        {
            folderType = SRV_EMAIL_FLDR_TYPE_INBOX;
        }
        else
        {
            return;
        }
        
        firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_MSG_LIST;
        firstPage->acct_id = m_acctId;
        firstPage->fldr_id = srv_email_fldr_type_to_fldr_id(m_acctId, folderType);
        firstPage->fldr_type = folderType;
    }

    app = VfxAppLauncher::findApp(VAPP_EMAIL, VFX_OBJ_CLASS_INFO(VappEmailApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }

    vapp_email_set_first_page_type(firstPage);
    OslMfree(firstPage);

    VfxAppLauncherParam launchParam(VAPP_EMAIL, VFX_OBJ_CLASS_INFO(VappEmailApp), GRP_ID_ROOT);
    launchParam.setLauncherResultCb(launchAppCallback, getObjHandle());
    VfxAppLauncher::launchEx(launchParam);
}


void VappEmailNcFailNoti::launchAppCallback(VfxAppLauncherResultEnum result, void *userData)
{
    if (userData == NULL)
    {
       return; 
    }

    VappEmailNcFailNoti *failNotify = (VappEmailNcFailNoti *)handleToObject(userData);

    if (failNotify == NULL)
    {
        return;
    }

    if (result == VFX_APP_LAUNCHER_RESULT_OK)
    {
        failNotify->clearNotify();
    }
}


void VappEmailNcFailNoti::onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 acctNum, VfxU32 acctId)
{
    if (m_acctNum != acctNum || (m_acctNum == 1 && m_acctId != acctId))
    {
        m_acctNum = acctNum;
        m_acctId = acctId;

        if (m_acctNum == 0)
        {
            showNotify(VFX_FALSE);
            VappEmailNCenterCellState cellState = {0};
            VappEmailNotificationCtrl::updateCellState(m_notifyType, &cellState);

            if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SEND_FAIL)
            {
                vapp_email_hide_alert_icon(m_statusIcon);
            }
            else if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL ||
                     m_notifyType == VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL)
            {
                vapp_email_hide_refresh_fail_icon(m_notifyType);
            }
            else
            {
                return;
            }
        }
        else if (m_isShow)
        {
            updateNotify();
            VappEmailNotificationCtrl::setCellHandled(m_notifyType, VFX_FALSE);
        }
    }
}


void VappEmailNcFailNoti::onNcShowHide(VappEmailNcTypeEnum ncType, VfxBool showEvent, VfxBool showBalloon)
{
    if (m_acctNum && showEvent)
    {
        showNotify(VFX_TRUE);

        if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SEND_FAIL)
        {
            vapp_email_show_alert_icon(m_statusIcon, VFX_FALSE);
        }
        else if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL ||
                 m_notifyType == VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL)
        {
            vapp_email_show_refresh_fail_icon(m_notifyType);
        }
        else
        {
            return;
        }
        
        VappEmailNotificationCtrl::setCellHandled(m_notifyType, VFX_FALSE);

        if (showBalloon)
        {
            mmi_frm_nmgr_alert_struct alertInfo = {0};
            alertInfo.app_id = VAPP_EMAIL;
            alertInfo.scen_id = MMI_SCENARIO_ID_DEFAULT;
            alertInfo.event_type = m_eventType;
            alertInfo.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
            alertInfo.behavior_mask = FORCE_STATUS_BAR;
            alertInfo.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_BALLOON_TYPE;
            alertInfo.status_bar_icon_para.icon_id = m_statusIcon;
            alertInfo.status_bar_para.display_string = (WCHAR*)GetString(m_mainText);
            mmi_frm_nmgr_alert(&alertInfo);
        }
    }
    else
    {
        showNotify(VFX_FALSE);
        if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SEND_FAIL)
        {
            vapp_email_hide_alert_icon(m_statusIcon);
        }
        else if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL ||
                 m_notifyType == VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL)
        {
            vapp_email_hide_refresh_fail_icon(m_notifyType);
        }
        else
        {
            return;
        }
    }
}


/*****************************************************************************
 * Class VappEmailNcOngoingNoti
 *****************************************************************************/

const VappEmailNcOngoingNoti::vapp_email_ongoing_notify_mapping_table_struct 
        VappEmailNcOngoingNoti::m_mappingTable[] = 
{
    //NCenter sending
    {VAPP_EMAIL_NCENTER_CELL_SENDING, 
     IMG_EMAIL_FTO_NC_SENDING, 
     STATUS_ICON_EMAIL_SEND, 
     STR_EMAIL_FTO_NC_SENDING_ID},
    
    //NCenter refreshing
    {VAPP_EMAIL_NCENTER_CELL_REFRESHING, 
     IMG_EMAIL_FTO_NC_REFRESHING, 
     STATUS_ICON_EMAIL_REF, 
     STR_EMAIL_FTO_NC_REFRESHING_ID}
};


VappEmailNcOngoingNoti::VappEmailNcOngoingNoti(VappEmailNCenterCellTypeEnum notifyType)
    : m_notifyType(notifyType),
      m_acctNum(0),
      m_acctId(EMAIL_ACCT_INVALID_ID)
{
    VfxU32 i;
    VfxU32 entry = sizeof(m_mappingTable) / sizeof(vapp_email_ongoing_notify_mapping_table_struct);
    
    for (i = 0; i < entry; i++)
    {
        if (m_mappingTable[i].notifyType == m_notifyType)
        {
            m_imageIcon = m_mappingTable[i].imageIcon;
            m_statusIcon = m_mappingTable[i].statusIcon;
            m_mainText = m_mappingTable[i].mainText;
            break;
        }
    }

    MMI_ASSERT(i < entry);
};


void VappEmailNcOngoingNoti::sysInit()
{
    m_acctNum = 0;
    m_acctId = EMAIL_ACCT_INVALID_ID;
}


VsrvNotificationOngoing* VappEmailNcOngoingNoti::getNotify()
{
    VsrvNGroupSingleTitle *group = VappEmailNotificationCtrl::getNGroup();
    VsrvNotificationOngoing *noti = (VsrvNotificationOngoing*)group->queryNotification(m_notifyType);

    if (noti == NULL)
    {
        VfxObjHandle objHandle = getObjHandle();

        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationOngoing, ((VsrvNGroup*)group, m_notifyType));
        noti->setIcon(VfxImageSrc(m_imageIcon));
        noti->setMainText(VFX_WSTR_RES(m_mainText));
        noti->setIntentCallback(intentCallback, &objHandle, sizeof(VfxObjHandle));
        noti->setAutoClose(VFX_FALSE);
        noti->setAutoLaunch(VFX_TRUE);
    }

    return noti;
}


void VappEmailNcOngoingNoti::showNotify(VfxBool show)
{
    if (show)
    {
        updateNotify();
    }
    else
    {
        VSRV_NOTIFICATION_CLOSE_EX(VAPP_EMAIL, m_notifyType);
    }
}


void VappEmailNcOngoingNoti::updateNotify(VfxBool isChangeTime)
{
    VsrvNotificationOngoing *noti = getNotify();
    
    VfxWString subText, subNextText;
    VfxWString questionText, questionPreText, questionNumText, questionNextText;
    if (m_acctNum > 1)
    {
        subText.format("%d", m_acctNum);
        subNextText.loadFromRes(STR_EMAIL_FTO_NC_ACCOUNTS_ID);
        subText += subNextText;
        if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SENDING)
        {
            questionPreText.loadFromRes(STR_EMAIL_FTO_NC_STOP_N_SEND_PRE_ID);
            questionNumText.format("%d", m_acctNum);
            questionNextText.loadFromRes(STR_EMAIL_FTO_NC_STOP_N_SEND_POST_ID);
            questionText += questionPreText;
            questionText += questionNumText;
            questionText += questionNextText;
        }
        else if(m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESHING)
        {
            questionPreText.loadFromRes(STR_EMAIL_FTO_NC_STOP_N_REFRESH_PRE_ID);
            questionNumText.format("%d", m_acctNum);
            questionNextText.loadFromRes(STR_EMAIL_FTO_NC_STOP_N_REFRESH_POST_ID);
            questionText += questionPreText;
            questionText += questionNumText;
            questionText += questionNextText;
        }
    
    }
    else
    {
        srv_email_acct_info_cache_struct acctInfo;

        srv_email_acct_cache_get(m_acctId, &acctInfo);
        subText = VFX_WSTR_MEM(acctInfo.acct_name);

        if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SENDING)
        {
            questionText = VFX_WSTR_RES(STR_EMAIL_FTO_NC_STOP_1_SEND_ID);
        }
        else if(m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESHING)
        {
            questionText = VFX_WSTR_RES(STR_EMAIL_FTO_NC_STOP_1_REFRESH_ID);
        }
    }

    noti->setQuestionText(questionText);    
    noti->setSubText(subText);
    noti->notify();
}


void VappEmailNcOngoingNoti::intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    if (noti == NULL || userData == NULL)
    {
       return; 
    }

    VappEmailNcOngoingNoti *ongoingNotify = (VappEmailNcOngoingNoti *)handleToObject(*(VfxObjHandle*)userData);

    if (ongoingNotify == NULL)
    {
        return;
    }

    if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
    {
        if (ongoingNotify->m_notifyType == VAPP_EMAIL_NCENTER_CELL_SENDING)
        {
            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->cancelAllSendOutbox();
        }
        else if(ongoingNotify->m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESHING)
        {
            VFX_OBJ_GET_INSTANCE(VappEmailMgr)->cancelAllAcctRefresh();
        }

    }  
    else if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        ongoingNotify->launchApp();
    }
    else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
    {
        ongoingNotify->updateNotify(VFX_FALSE);
    }
}


void VappEmailNcOngoingNoti::launchApp(void)
{
    VfxApp *app = NULL;
    email_app_set_first_struct *firstPage = NULL;

    firstPage = (email_app_set_first_struct*)OslMalloc(sizeof(email_app_set_first_struct));
    memset(firstPage, 0, sizeof(email_app_set_first_struct));
    firstPage->entry_point = EMAIL_ENTRY_FROM_NCENTER;

    if (m_acctNum > 1)
    {
        firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_ACCT_LIST;
    }
    else
    {
        srv_email_fldr_type_enum folderType;
        
        if (m_notifyType == VAPP_EMAIL_NCENTER_CELL_SENDING)
        {
            folderType = SRV_EMAIL_FLDR_TYPE_OUTBOX;
        }
        else if(m_notifyType == VAPP_EMAIL_NCENTER_CELL_REFRESHING)
        {
            folderType = SRV_EMAIL_FLDR_TYPE_INBOX;
        }
        else
        {
            return;
        }
        
        firstPage->first_page_type = EMAIL_MAIN_FIRST_PAGE_MSG_LIST;
        firstPage->acct_id = m_acctId;
        firstPage->fldr_id = srv_email_fldr_type_to_fldr_id(m_acctId, folderType);
        firstPage->fldr_type = folderType;
    }

    app = VfxAppLauncher::findApp(
                            VAPP_EMAIL, 
                            VFX_OBJ_CLASS_INFO(VappEmailApp), 
                            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 
                            0);
    if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }

    vapp_email_set_first_page_type(firstPage);
    OslMfree(firstPage);

    VfxAppLauncher::launch(
        VAPP_EMAIL,
        VFX_OBJ_CLASS_INFO(VappEmailApp),
        GRP_ID_ROOT);
}


void VappEmailNcOngoingNoti::onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 acctNum, VfxU32 acctId)
{
    if (m_acctNum != acctNum || (m_acctNum == 1 && m_acctId != acctId))
    {
        m_acctNum = acctNum;
        m_acctId = acctId;

        if (m_acctNum)
        {
            updateNotify();
            vapp_email_show_alert_icon(m_statusIcon, VFX_TRUE); 
        }
        else
        {
            showNotify(VFX_FALSE);
            vapp_email_hide_alert_icon(m_statusIcon);
        }
    }
}

