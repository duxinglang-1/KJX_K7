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
 *  vapp_email_mgr.h
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
#ifndef VAPP_EMAIL_MGR_H
#define VAPP_EMAIL_MGR_H

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

extern "C" {
#include "EmailSrvGprot.h"
}

#define VAPP_EMAIL_MAX_FLDR_NUM    (SRV_EMAIL_FLDR_TYPE_BASICS_CNT + MMI_EMAIL_MAX_REMOTE_FOLDER_NUM)
#define VAPP_EMAIL_MGR_GLOBAL_POP_NUM   (10)

#define __MMI_EMAIL_VIDEO_PREVIEW__

#if (defined(__LOW_COST_SUPPORT_COMMON__))
#undef __MMI_EMAIL_VIDEO_PREVIEW__     
#define __MMI_EMAIL_STOR_CANNOT_SWITCH__ 
#endif

/* The result value enum */
typedef enum
{
    VAPP_EMAIL_RES_SUCC,
    VAPP_EMAIL_RES_FAIL,
    VAPP_EMAIL_RES_WOULDBLOCK,
    VAPP_EMAIL_RES_ACCT_IN_USE,
    VAPP_EMAIL_RES_ACCT_EDIT_MODE,
    VAPP_EMAIL_RES_FLDR_MULTI_SELECT,
    VAPP_EMAIL_RES_IN_PARTIAL_FETCH,
    VAPP_EMAIL_RES_NETWORK_RUNNING,
    VAPP_EMAIL_RES_SERVICE_ERROR,
    VAPP_EMAIL_RES_ACCT_NOT_EDIT_MODE,
    VAPP_EMAIL_RES_TOTAL
} VappEmailResEnum;

typedef struct
{
    VappEmailResEnum result;
    VfxS32 major;
    VfxS32 minor;
} VappEmailResStruct;

typedef struct
{
    VfxU32 totalNum;
    VfxU32 unreadNum;
} VappEmailFldrMsgNumStruct;

/* The account state enum */
typedef enum
{
    VAPP_EMAIL_ACCT_STATE_NORMAL,
    VAPP_EMAIL_ACCT_STATE_EDITING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_TEST_WAITING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_WAITING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_WAITING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_RETRIEVE_WAITING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_TESTING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_SENDING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESHING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_RETRIEVING,
    VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL,
    VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL,
    VAPP_EMAIL_ACCT_STATE_IN_USE,
    VAPP_EMAIL_ACCT_STATE_TOTAL
} VappEmailAcctStateEnum;

/* The folder state enum */
typedef enum
{
    VAPP_EMAIL_FLDR_STATE_NORMAL,
    VAPP_EMAIL_FLDR_STATE_EDITING,
    VAPP_EMAIL_FLDR_STATE_NETWORK_SEND_WAITING,
    VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVE_WAITING,
    VAPP_EMAIL_FLDR_STATE_NETWORK_RETRIEVE_WAITING,
    VAPP_EMAIL_FLDR_STATE_NETWORK_SENDING,
    VAPP_EMAIL_FLDR_STATE_NETWORK_RECEIVING,
    VAPP_EMAIL_FLDR_STATE_NETWORK_RETRIEVING,
    VAPP_EMAIL_FLDR_STATE_TOTAL
} VappEmailFldrStateEnum;

/* The message state enum */
typedef enum
{
    VAPP_EMAIL_MSG_STATE_NORMAL,
    VAPP_EMAIL_MSG_STATE_NETWORK_WAITING,
    VAPP_EMAIL_MSG_STATE_NETWORK_SENDING,
    VAPP_EMAIL_MSG_STATE_NETWORK_RETRIEVING,
    VAPP_EMAIL_MSG_STATE_NETWORK_SEND_FAIL,
    VAPP_EMAIL_MSG_STATE_TOTAL
} VappEmailMsgStateEnum;

typedef enum
{
    VAPP_EMAIL_NWK_STATE_NORMAL,
    VAPP_EMAIL_NWK_STATE_SENDING,
    VAPP_EMAIL_NWK_STATE_REFRESHING,
    VAPP_EMAIL_NWK_STATE_RETRIEVING,
    VAPP_EMAIL_NWK_STATE_NETWORK_TESTING,
    VAPP_EMAIL_NWK_STATE_REMOTE_FOLDER_LISTING,
    VAPP_EMAIL_NWK_STATE_TOTAL
} VappEmailNwkStateEnum;

typedef enum
{
    VAPP_EMAIL_NWK_PROC_CONNECTING,
    VAPP_EMAIL_NWK_PROC_AUTHORIZING,
    VAPP_EMAIL_NWK_PROC_UPDATING,
    VAPP_EMAIL_NWK_PROC_SENDING,
    VAPP_EMAIL_NWK_PROC_RECEIVING,
    VAPP_EMAIL_NWK_PROC_RETRIEVING,
    VAPP_EMAIL_NWK_PROC_LISTING_FOLDER,
    VAPP_EMAIL_NWK_PROC_TOTAL
} VappEmailNwkProcEnum;

typedef enum
{
    VAPP_EMAIL_NC_TYPE_EVENT_UNREAD = 0x01,
    VAPP_EMAIL_NC_TYPE_EVENT_SEND_FAIL = 0x02,
    VAPP_EMAIL_NC_TYPE_EVENT_REFRESH_FAIL = 0x04,
    VAPP_EMAIL_NC_TYPE_ONGOING_SEND = 0x08,
    VAPP_EMAIL_NC_TYPE_ONGOING_REFRESH = 0x10,
#ifdef __MMI_EMAIL_IMAP_PUSH__    
    VAPP_EMAIL_NC_TYPE_EVENT_PUSH_REFRESH_FAIL = 0x20,
#endif
    VAPP_EMAIL_NC_TYPE_TOTAL
} VappEmailNcTypeEnum;

typedef enum
{
    VAPP_EMAIL_NWK_DONE_NONE,
    VAPP_EMAIL_NWK_DONE_SEND,
    VAPP_EMAIL_NWK_DONE_REFRESH,
    VAPP_EMAIL_NWK_DONE_REFRESH_ALL,
    VAPP_EMAIL_NWK_DONE_RETRIEVE,
    VAPP_EMAIL_NWK_DONE_NETWORK_TEST,
    VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER,
    VAPP_EMAIL_NWK_DONE_CANCEL,
    VAPP_EMAIL_NWK_DONE_TOTAL
} VappEmailNwkDoneEnum;

typedef enum
{
    VAPP_EMAIL_STATE_DEINITED,
    VAPP_EMAIL_STATE_INITIALIZING,
    VAPP_EMAIL_STATE_READY,
    VAPP_EMAIL_STATE_USB_MODE,
    VAPP_EMAIL_STATE_TCARD_OUT,
    VAPP_EMAIL_STATE_FLIGHT_MODE,
    VAPP_EMAIL_STATE_NO_SIM,
    VAPP_EMAIL_STATE_TOTAL
} VappEmailStateEnum;

typedef enum
{
    VAPP_EMAIL_MGR_STOP_CAUSE_NONE,
    VAPP_EMAIL_MGR_STOP_CAUSE_SWITCH_STORAGE,
    VAPP_EMAIL_MGR_STOP_CAUSE_USB,
    VAPP_EMAIL_MGR_STOP_CAUSE_TCARD,
    VAPP_EMAIL_MGR_STOP_CAUSE_FLIGHT_MODE,
    VAPP_EMAIL_MGR_STOP_CAUSE_FORMAT_FS,
    VAPP_EMAIL_MGR_STOP_CAUSE_SHUTDOWN,
    VAPP_EMAIL_MGR_STOP_CAUSE_TOTAL,
} VappEmailMgrStopCauseEnum;

/* The request structure */
typedef struct
{
    EMAIL_ACCT_ID acctId;
    EMAIL_MSG_ID msgId;
    EMAIL_ATTCH_ID attachId;
    VfxU8 reqOprt;
    srv_email_retrieve_option_enum retrOpt;
} VappEmailMgrReqItemStruct;

typedef struct
{
    EMAIL_ACCT_ID acctId;
    VappEmailAcctStateEnum acctState;
} VappEmailAcctStateItemStruct;

typedef struct
{
    VappEmailAcctStateItemStruct acctList[MMI_EMAIL_MAX_ACCTS];
    VfxU32 count;
} VappEmailAcctStateTableStruct;

typedef struct
{
    EMAIL_FLDR_ID fldrId;
    VappEmailFldrStateEnum fldrState;
} VappEmailFldrStateItemStruct;

typedef struct
{
    EMAIL_ACCT_ID acctId;
    VappEmailFldrStateItemStruct fldrItem[VAPP_EMAIL_MAX_FLDR_NUM];
    VfxU32 fldrNum;
} VappEmailFldrStateListStruct;

typedef struct
{
    VappEmailFldrStateListStruct fldrList[MMI_EMAIL_MAX_ACCTS];
    VfxU32 count;
} VappEmailFldrStateTableStruct;

typedef struct
{
    EMAIL_ACCT_ID acctId;
    VappEmailAcctStateEnum acctState;
    VfxU32 updatedTime;
} VappEmailAcctUpdateItemStruct;

typedef struct
{
    VappEmailAcctUpdateItemStruct acctList[MMI_EMAIL_MAX_ACCTS];
    VfxU32 count;
} VappEmailAcctUpdateTableStruct;

typedef struct
{
    EMAIL_ACCT_ID acctId;
    EMAIL_ACCT_HANDLE acctHandle;
    EMAIL_REQ_ID reqId;

    VfxU8 reqOprt;
    VfxU8 currOprt;

    EMAIL_MSG_HANDLE msgHandle;
    EMAIL_MSG_ID msgId;
    EMAIL_ATTCH_ID attachId;
    srv_email_retrieve_option_enum retrOpt;

    VfxBool acctConnected;
} VappEmailAcctConnStruct;

#ifdef __MMI_EMAIL_IMAP_PUSH__

/* This structure used for IMAP4 push email */
typedef struct
{
    EMAIL_ACCT_ID acctId;
    EMAIL_ACCT_HANDLE acctHandle;
    EMAIL_REQ_ID reqId;
    VfxU8 currOprt;
    VfxBool acctConnected;
    VfxBool refreshPending;  //refresh pending because multi-selection, foregroud retrieve.
    VfxU8 retryNum;
    VfxTimer *retryTimer;
    VfxBool refreshFail;
} VappEmailPushAcctStruct;

typedef struct
{
    VappEmailPushAcctStruct pushAcct[MMI_EMAIL_MAX_PUSH_ACCTS];
    VfxU32 acctNum;
    VfxTimer *reStartTimer;    
} VappEmailPushEmailStruct;

#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

/* The Email manager context structure */
typedef struct
{
    CHAR rootFldrPath[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];

    VappEmailStateEnum emailState;
    VappEmailNwkStateEnum currNwkState;

    S32 acctNotifyId;
    S32 fldrNotifyId;
    S32 msgNotifyId;

    VappEmailAcctUpdateTableStruct acctUpdateTable;

    VappEmailAcctStateTableStruct acctStateTable;

    VappEmailFldrStateTableStruct fldrStateTable;

    VappEmailMgrReqItemStruct reqItem[MMI_EMAIL_MAX_ACCTS];
    VfxU32 reqNum;

    VappEmailMgrReqItemStruct *currReqItem;

    EMAIL_ACCT_HANDLE acctHandle;
    EMAIL_MSG_HANDLE msgHandle;
    EMAIL_REQ_ID reqId;

    VfxU8 currReq;

    EMAIL_MSG_ID currSendMsgId;
    EMAIL_MSG_ID sendFailMsgId[SRV_EMAIL_GLOBAL_MAX_MSG_NUM];
    VfxU32 sendFailMsgNum;

    VfxBool refreshAllFlag;

    EMAIL_ACCT_ID currEnterAcctId;
    VappEmailAcctConnStruct currAcctConn;

#ifdef __MMI_EMAIL_IMAP_PUSH__
    VappEmailPushEmailStruct pushCntx;
#endif

    VfxS32 globalPopHanle[VAPP_EMAIL_MGR_GLOBAL_POP_NUM];
} VappEmailMgrContextStruct;


class VappEmailMgr : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappEmailMgr);

private:
    VfxContext *m_context;
    static VappEmailMgrContextStruct vappEmailMgrCntx;
    VappEmailMgrContextStruct *emailMgrCntx;
    VfxBool switchStorageFlag;
    VfxTimer *m_initSrvDelayTimer;

public:
    /* INBOX's MSG unread & total num change of an account */
    VfxSignal3 <EMAIL_ACCT_ID, VfxU32, VfxU32> m_signalAcctMsgNumChange;
    VfxSignal3 <EMAIL_ACCT_ID, EMAIL_FLDR_ID, VappEmailFldrMsgNumStruct> m_signalFldrMsgNumChange;
    VfxSignal2 <EMAIL_FLDR_ID, VappEmailFldrStateEnum> m_signalFldrStateChange;
    /* MSG added signal */
    VfxSignal1 <EMAIL_MSG_ID> m_signalMsgAdd;
    /* MSG deleted signal */
    VfxSignal1 <EMAIL_MSG_ID> m_signalMsgDelete;
    /* MSG changed signal. */
    VfxSignal2 <EMAIL_MSG_ID, srv_email_om_notify_msg_struct> m_signalMsgChange;

    /* MSG state changed signal */
    VfxSignal2 <EMAIL_MSG_ID, VappEmailMsgStateEnum> m_signalMsgStateChange;

    /* Account state changed signal */
    VfxSignal2 <EMAIL_ACCT_ID, VappEmailAcctStateEnum> m_signalAcctStateChange;
    VfxSignal1 <EMAIL_ACCT_ID> m_signalAcctDelete;

    /* Network state changed signal */
    VfxSignal3 <VfxU32, EMAIL_ACCT_ID, VappEmailNwkStateEnum> m_signalNwkStateChange;
    VfxSignal3 <VappEmailNcTypeEnum, VfxU32, VfxU32> m_signalNcStateChange;
    VfxSignal3 <VappEmailNcTypeEnum, VfxBool, VfxBool> m_signalNcShowHide;
    VfxSignal4 <EMAIL_ACCT_ID, EMAIL_FLDR_ID, EMAIL_MSG_ID, VfxU32> m_signalNewMsg;

    /* Network operation done signal */
    VfxSignal3 <EMAIL_ACCT_ID, VappEmailNwkDoneEnum, VappEmailResStruct> m_signalAcctNwkDone;
    VfxSignal3 <EMAIL_MSG_ID, VappEmailNwkDoneEnum, VappEmailResStruct> m_signalMsgNwkDone;

    VfxSignal1 <VappEmailMgrStopCauseEnum> m_signalNwkStop;

    VfxSignal3 <VappEmailNwkStateEnum, VfxU32, VappEmailNwkProcEnum> m_signalAcctNwkProc;

    /* Email App state changed signal */
    VfxSignal1 <VappEmailStateEnum> m_signalEmailStateChange;
    VfxSignal0 m_signalStoragePreSwitch;
    VfxSignal1 <VappEmailResEnum> m_signalStorageFinishSwitch;
    VfxSignal0 m_signalUsbPlugin;
    VfxSignal1 <VfxBool> m_signalTcardPlug;
    VfxSignal0 m_signalFlightMode;
 
    VfxSignal1 < VfxBool > m_signalSimAvailableChanged;

private:
    VappEmailMgr();
    virtual void onInit();

    static void initServiceDone(srv_email_init_state_enum initState, S32 errCode, void *userData);

    static void retrMsgProcCbFunc(srv_email_nwk_proc_struct *data);
    static void refreshAcctCbFunc(srv_email_result_struct *result, EMAIL_REQ_ID reqId, void *userData);
    static void refreshAcctProcCbFunc(srv_email_nwk_proc_struct *data);
    static void connectAcctCbFunc(srv_email_result_struct *result, EMAIL_REQ_ID reqId, void *userData);
    static void connectAcctProcCbFunc(srv_email_nwk_proc_struct *data);

    static void notifyAcctCbFunc(const srv_email_om_notify_struct *notifyData);
    static void notifyFldrCbFunc(const srv_email_om_notify_struct *notifyData);
    static void notifyMsgCbFunc(const srv_email_om_notify_struct *notifyData);

    static void mgrSchlCbFunc();

    VappEmailResEnum startMgr();
    void stopMgr(VappEmailMgrStopCauseEnum stopCause);

    static void onMsgReceiving(EMAIL_ACCT_ID acctId, VappEmailNwkStateEnum nwkState, srv_email_receiving_data_struct *recvData);

    void updateNcState(VfxU8 ncTypeSet);

    void updateAcctState(EMAIL_ACCT_ID acctId, VappEmailNwkDoneEnum nwkType, VfxBool result, VfxBool updateTime);
    void updateAcctTime(EMAIL_ACCT_ID acctId);
    void updateAcctStateFile();

    void readAcctState();
    void resetEmailApp();
    void resetNcState();

    VappEmailResEnum addAcctReq(EMAIL_ACCT_ID acctId, VfxU8 reqOprt);
    VappEmailResEnum removeAcctReq(EMAIL_ACCT_ID acctId, VappEmailAcctStateEnum acctState);
    void closeGlobalPop();

    void connectCurrAcct();
    void disconnectCurrAcct();
    void retrieveCurrAcct(EMAIL_MSG_ID msgId, srv_email_retrieve_option_enum retrOpt, EMAIL_ATTCH_ID attachId);
    void startCurrAcct();
    void stopCurrAcct();
    void updatefreshAllState();    
    void startSrvDelay();
    void restartEmailApp(VfxTimer *timer);
#ifdef __MMI_EMAIL_IMAP_PUSH__
    /* IMAP push email */
    void pushDelayStartService(void);
    void pushDelayStartServiceTimeout(VfxTimer *timer);
    VfxBool pushAllowStart(EMAIL_ACCT_ID acctId);
    void pushDelayStart(EMAIL_ACCT_ID acctId);
    void pushDelayStartTimeout(VfxTimer *timer);     
    static void pushAcctCbFunc(srv_email_result_struct *result, EMAIL_REQ_ID reqId, void *userData);
    static void pushAcctProcCbFunc(srv_email_nwk_proc_struct *data);
    VappEmailResEnum pushAcctConnect(VappEmailPushAcctStruct *pushAcct);
    void pushAcctRefresh(VappEmailPushAcctStruct *pushAcct);
    VfxBool pushStopRefresh(EMAIL_ACCT_ID acctId);
    void pushDelayRefresh(EMAIL_ACCT_ID acctId);    
    void pushDelayRefreshTimeout(VfxTimer *timer);    
    void pushRetryConnect(VappEmailPushAcctStruct *pushAcct);
    void pushRetryConnectTimeout(VfxTimer *timer);    
    void pushCheckPending(EMAIL_ACCT_ID acctId);    
    VappEmailPushAcctStruct *findPushAcct(EMAIL_ACCT_ID acctId);
    VappEmailPushAcctStruct *findPushAcctByHandle(EMAIL_ACCT_HANDLE acctHandle);
    VfxBool pushRetryByRefresh(EMAIL_ACCT_ID pushAcctId);
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

public:
    virtual vrt_allocator_handle getAllocator()
    {
        return m_context->getAllocator();
    }
    /* State query */
    VappEmailStateEnum getEmailAppState();
    VappEmailAcctStateEnum getAcctState(EMAIL_ACCT_ID acctId);
    VappEmailFldrStateEnum getFldrState(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId);
    VappEmailMsgStateEnum getMsgState(EMAIL_MSG_ID msgId);

    VfxU32 getAcctUpdatedTime(EMAIL_ACCT_ID acctId);

    /* Enter/Exit account */
    void enterAcct(EMAIL_ACCT_ID acctId);
    void exitAcct(EMAIL_ACCT_ID acctId);

    /* Enter editable mode */
    VappEmailResEnum editAcctStart(EMAIL_ACCT_ID acctId);
    VappEmailResEnum editAcctStop(EMAIL_ACCT_ID acctId);
    VfxBool isAcctEntered(EMAIL_ACCT_ID acctId);  // Entered this account or not

    VappEmailResEnum editFldrStart(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId);
    VappEmailResEnum editFldrStop(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId);

    /* Notify */
    void notifyAcctDelete(EMAIL_ACCT_ID acctId);

    /* Send & Receive */
    VappEmailResEnum refreshAllAcct(void);
    VappEmailResEnum refreshAcct(EMAIL_ACCT_ID acctId);
    VappEmailResEnum sendOutbox(EMAIL_ACCT_ID acctId);
    VappEmailResEnum retrieveMsg(EMAIL_MSG_ID msgId, srv_email_retrieve_option_enum retrOpt);
    VappEmailResEnum retrieveMsgAttach(EMAIL_ATTCH_ID attachId);
    VappEmailResEnum testAcctNetwork(EMAIL_ACCT_ID acctId);
    VappEmailResEnum listRemoteFolder(EMAIL_ACCT_ID acctId, EMAIL_ACCT_HANDLE acctHandle);

    VappEmailResEnum getCurrNwkState(EMAIL_ACCT_ID &acctId, VappEmailNwkStateEnum &nwkState);
    VfxBool isRefreshAllAcct(void);
    VfxBool getCurrSendingMsg(EMAIL_MSG_ID &msgId);

    void cancelAllNwkOperation(void);
    void cancelCurrNwkOperation(void);
    void cancelAcctRefresh(EMAIL_ACCT_ID acctId);
    void cancelSendOutbox(EMAIL_ACCT_ID acctId);
    void cancelMsgRetrieve(EMAIL_MSG_ID msgId);
    void cancelTestAcctNetwork(EMAIL_ACCT_ID acctId);
    void cancelListRemoteFolder(EMAIL_ACCT_ID acctID);
    void cancelAllAcctRefresh(void);
    void cancelAllSendOutbox(void);

#ifdef __MMI_EMAIL_IMAP_PUSH__
    /* IMAP push email */
    void pushStartService();
    void pushStopService(VappEmailMgrStopCauseEnum stopCause);
    VappEmailResEnum pushStart(EMAIL_ACCT_ID acctId);
    void pushStop(EMAIL_ACCT_ID acctId);
    VfxBool isPushRefreshing(EMAIL_ACCT_ID acctId);    
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

    void resetAcctFailState(EMAIL_ACCT_ID acctId);

    VfxBool isNetworkReady(VappEmailStateEnum &emailState);

    void initEmailApp();
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
    void switchStorage(CHAR newDrive);
#endif
    void plugUsb(VfxBool plugIn);
    void plugTcard(VfxBool plugIn, U8 *drvTable, U8 drvNum);
    void switchFlightMode(VfxBool enterMode);
    void formatFileSystem(VfxBool beforeAfter, U8 drvLetter);
    void fmgrAdvAction();
    void shutdown();
    void simAvailableChanged(VfxBool simAvailable)
    {
        m_signalSimAvailableChanged.emit(simAvailable);
    };

    void addGlobalPopHandle(VfxS32 handle);
    void removeGlobalPopHandle(VfxS32 handle);
};

// VFX_OBJ_GET_INSTANCE(VappEmailMgr)


#ifdef __MMI_EMAIL_IMAP_PUSH__

class VappEmailPush
{
public:
    static void setEnable(VfxBool enable);
    static VfxBool isEnable(void);
    static void addPushAcctId(EMAIL_ACCT_ID acctId);
    static void removePushAcctId(EMAIL_ACCT_ID acctId);
    static EMAIL_ACCT_ID getPushAcctId(void);
};

#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */


#endif /* VAPP_EMAIL_MGR_H */

