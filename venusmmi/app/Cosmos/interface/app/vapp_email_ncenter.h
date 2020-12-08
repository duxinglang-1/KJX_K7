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
 *  Vapp_email_ncenter.h
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
#ifndef VAPP_EMAIL_NCENTER_H
#define VAPP_EMAIL_NCENTER_H


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "Vapp_ncenter_base_cell.h"
#include "vsrv_ncenter.h"


/*****************************************************************************
 * Class VappEmailUnread
 *****************************************************************************/
 
typedef enum
{
    VAPP_EMAIL_NCENTER_CELL_UNREAD,
    VAPP_EMAIL_NCENTER_CELL_SEND_FAIL,
    VAPP_EMAIL_NCENTER_CELL_REFRESH_FAIL,
    VAPP_EMAIL_NCENTER_CELL_PUSH_REFRESH_FAIL,
    VAPP_EMAIL_NCENTER_CELL_SENDING,
    VAPP_EMAIL_NCENTER_CELL_REFRESHING, 
    VAPP_EMAIL_NCENTER_CELL_FS_FULL,     
    VAPP_EMAIL_NCENTER_CELL_TOTAL
} VappEmailNCenterCellTypeEnum;


/* Ncenter cell state structer */
typedef struct
{
    VfxBool isHandled;  //cell had been handled(tapped or cleared) or not.
    VfxU32 timeStamp;   //the timestamp when cell show
    VfxU32 num;         //account number or unread mesasge nember
    VfxU32 acctId;
} VappEmailNCenterCellState;


/* Ncenter cells state context structer*/
typedef struct
{
    VappEmailNCenterCellState cellState[VAPP_EMAIL_NCENTER_CELL_TOTAL];   
} VappEmailNCenterCellContext;

typedef struct
{
    EMAIL_ACCT_ID acctId;
    EMAIL_FLDR_ID fldrId;
    EMAIL_MSG_ID msgId;
}VappEmailNewMsgStruct;

class VappEmailNcFailNoti;
class VappEmailNcOngoingNoti;
class VappEmailNcFsFullNoti;

class VappEmailNotificationCtrl : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappEmailNotificationCtrl);

protected:
    virtual void onInit();
    
public:
    virtual vrt_allocator_handle getAllocator()
    {
        return m_context->getAllocator();
    }
    void SysInit(void);
    static VsrvNGroupSingleTitle* getNGroup(void);
    static void getCellState(VappEmailNCenterCellTypeEnum cellType, VappEmailNCenterCellState *cellState);
    static void updateCellState(VappEmailNCenterCellTypeEnum cellType, VappEmailNCenterCellState *cellState);
    static void setCellHandled(VappEmailNCenterCellTypeEnum cellType, VfxBool isHandled);    
    static VfxU32 getCellTimeStamp(VappEmailNCenterCellTypeEnum cell);
    static void setCellTimeStamp(VappEmailNCenterCellTypeEnum cell, VfxU32 timeStamp);    
    static mmi_ret newMsgProc(mmi_event_struct *param);
    static void launchApp(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId, EMAIL_MSG_ID msgId);

private:
    static void readCellContext(void);
    static void writeCellContext(void);
    void onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 acctNum, VfxU32 acctId);
    void onNcShowHide(VappEmailNcTypeEnum ncType, VfxBool showEvent, VfxBool showBalloon);
    void onAcctNwkDone(EMAIL_ACCT_ID, VappEmailNwkDoneEnum, VappEmailResStruct);
    void onShowMsgNoti(EMAIL_ACCT_ID acctId, EMAIL_FLDR_ID fldrId, EMAIL_MSG_ID msgId, VfxU32 recvNum);

private:
    VfxContext *m_context;
    static VappEmailNCenterCellContext *g_cellContext;
    VappEmailNcFailNoti *m_sendFailNotify;
    VappEmailNcFailNoti *m_refreshFailNotify;
#ifdef __MMI_EMAIL_IMAP_PUSH__    
    VappEmailNcFailNoti *m_pushRefreshFailNotify;
#endif
    VappEmailNcOngoingNoti *m_sendingNotify;
    VappEmailNcOngoingNoti *m_refreshingNotify;

    VappEmailNcFsFullNoti *m_fsFullNotify;
};


class VappEmailNcFsFullNoti : public VfxObject
{
public:
    VappEmailNcFsFullNoti() {};
    
private:
    void sysInit();
    VsrvNotificationEvent* getNotify();
    void showNotify(VfxBool show);    
    void updateNotify(VfxBool isChangeTime = VFX_TRUE);
    static void intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);
    
    friend class VappEmailNotificationCtrl;
};


class VappEmailNcUnreadNoti : public VfxObject
{
private:
    static void sysInit();
    static VsrvNotificationEvent* getNotify();
    static void showNotify(VfxBool show);    
    static void updateNotify(VfxBool isChangeTime = VFX_TRUE);    
    static void clearNotify();
    static void intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);    
    static void launchApp(void);
    static void launchAppCallback(VfxAppLauncherResultEnum result, void *userData);
    static void onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 unreadNum, EMAIL_ACCT_ID acctId);
    static void onNcShowHide(VappEmailNcTypeEnum ncType, VfxBool showEvent, VfxBool showBalloon);

private:
    static VfxBool m_isShow;
    static VfxU32 m_unreadNum;
    static VfxBool m_inited;

    friend class VappEmailNotificationCtrl;
};


/*****************************************************************************
 * Class VappEmailNcFailNoti
 *****************************************************************************/

/*
 * VappEmailNcFailNoti is used to show Email send/refresh/(push refresh) fail notifications for NCener.
 */
class VappEmailNcFailNoti : public VfxObject
{
private:
    typedef struct
    {
        VappEmailNCenterCellTypeEnum notifyType;
        VfxResId imageIcon;
        VfxResId statusIcon;
        VfxResId mainText;
        mmi_event_notify_enum eventType;
    } vapp_email_fail_notify_mapping_table_struct;

public:
    VappEmailNcFailNoti(VappEmailNCenterCellTypeEnum notifyType);

private:
    void sysInit();
    VsrvNotificationEvent* getNotify();
    void showNotify(VfxBool show);
    void updateNotify(VfxBool isChangeTime = VFX_TRUE);    
    void clearNotify();
    void launchApp(void);
    static void launchAppCallback(VfxAppLauncherResultEnum result, void *userData);
    static void intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);
    void onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 acctNum, EMAIL_ACCT_ID acctId);
    void onNcShowHide(VappEmailNcTypeEnum ncType, VfxBool showEvent, VfxBool showBalloon);

private:
    VappEmailNCenterCellTypeEnum m_notifyType;
    VfxResId m_imageIcon;
    VfxResId m_statusIcon;
    VfxResId m_mainText;
    mmi_event_notify_enum m_eventType;
    VfxU32 m_acctNum;
    EMAIL_ACCT_ID m_acctId;
    VfxBool m_isShow;
    VfxBool m_inited;

    static const vapp_email_fail_notify_mapping_table_struct m_mappingTable[];

    friend class VappEmailNotificationCtrl;    
};



/*****************************************************************************
 * Class VappEmailNcOngoingNoti
 *****************************************************************************/

/*
 * VappEmailNcOngoingNoti is used to show Email sending and refreshing notifications for NCener.
 */
class VappEmailNcOngoingNoti : public VfxObject
{
private:
    typedef struct
    {
        VappEmailNCenterCellTypeEnum notifyType;
        VfxResId imageIcon;
        VfxResId statusIcon;
        VfxResId mainText;
    } vapp_email_ongoing_notify_mapping_table_struct;

public:
    VappEmailNcOngoingNoti(VappEmailNCenterCellTypeEnum notifyType);
    
private:
    void sysInit();
    void launchApp(void);   
    VsrvNotificationOngoing* getNotify();
    void showNotify(VfxBool show);
    void updateNotify(VfxBool isChangeTime = VFX_TRUE);    
    static void intentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);
    void onNcStateChange(VappEmailNcTypeEnum ncType, VfxU32 acctNum, EMAIL_ACCT_ID acctId);
    void onCloseButtonClicked(VfxObject *sender, VfxId id);
    void onCancelConfirmChoosed(VfxId id, void *userData);

private:
    VappEmailNCenterCellTypeEnum m_notifyType;    
    VfxResId m_imageIcon;
    VfxResId m_statusIcon;    
    VfxResId m_mainText;
    VfxU32 m_acctNum;
    EMAIL_ACCT_ID m_acctId;

    static const vapp_email_ongoing_notify_mapping_table_struct m_mappingTable[];

    friend class VappEmailNotificationCtrl;    
};

   
#endif /* VAPP_EMAIL_NCENTER_H */


