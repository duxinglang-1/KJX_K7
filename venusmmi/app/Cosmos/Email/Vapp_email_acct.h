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
 *  Vapp_email_acct.h
 *
 * Project:
 * --------
 *  COSMOS Email Account Class (only handle Data, No UI)
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
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_EMAIL_ACCT_H_
#define _VAPP_EMAIL_ACCT_H_

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_email_prot.h"
extern "C" {
#include "EmailSrvGprot.h"
}

#define VAPP_EMAIL_CHECK_INTERVAL_DAY_BEGIN           (0)
#define VAPP_EMAIL_CHECK_INTERVAL_DAY_END             (6)

#define VAPP_EMAIL_CHECK_INTERVAL_DAY_START_TIME      (0)
#define VAPP_EMAIL_CHECK_INTERVAL_DAY_END_TIME        (24 * 60 *60 - 1)

#define VAPP_EMAIL_CHECK_INTERVAL_5_MIN_TIME          (5 * 60)
#define VAPP_EMAIL_CHECK_INTERVAL_30_MIN_TIME         (30 * 60)
#define VAPP_EMAIL_CHECK_INTERVAL_1_HOUR_TIME         (60 * 60)
#define VAPP_EMAIL_CHECK_INTERVAL_2_HOUR_TIME         (2 * 60 * 60)

typedef struct
{
    VfxBool showCcBcc;
    EMAIL_MSG_PRIO priority;
    VfxBool saveSentEmails[MMI_EMAIL_MAX_ACCTS];
} VappEmailGlobalSettingStruct;

typedef struct 
{
    U16 str_id;
    U16 icon_id;
} vapp_email_appinfo_map_struct;

class VappEmailAcct : public VfxBase
{
public:
    VappEmailAcct(){VFX_ASSERT(0);};
    explicit VappEmailAcct(EMAIL_ACCT_ID acctId);
   ~VappEmailAcct();
    srv_email_result_enum initData(void);
    
    enum VappEmailServerType
    {
        INCOMING,
        OUTGOING,
    };

    enum CheckIntervalEnum
    {
        CHECK_INTERVAL_OFF,
        CHECK_INTERVAL_5_MIN,
        CHECK_INTERVAL_30_MIN,
        CHECK_INTERVAL_1_HOUR,
        CHECK_INTERVAL_2_HOUR,
        CHECK_INTERVAL_TOTAL
    };

    static const vapp_email_appinfo_map_struct appInfoArr[MMI_EMAIL_MAX_ACCTS * 4];
    
    VfxBool getSaveSentEmails(void) const;
    const srv_email_acct_info_struct* getBasicInfo(void) const;
    CheckIntervalEnum getAutoCheckType(void) const;
    EMAIL_ACCT_HANDLE getAcctHandle(void) const;

    srv_email_result_enum saveAcctInfo(void);
    srv_email_result_enum delAcct(void);

    // set account info
    void setProtocol(srv_email_prot_type_enum protocol);
    void setDispName(const VfxWString& dispName);
    void setAddress(const VfxWString& addr);
    void setReplyTo(const VfxWString& replyTo);
    void setServerName(const VfxWString& serverName, VappEmailServerType type);
    void setPort(VfxU16 port, VappEmailServerType type);
    void setSecPort(VfxU16 secPort, VappEmailServerType type);
    void setSecMode(srv_email_sec_mode_enum secMode, VappEmailServerType type);
    void setWifiOnly(VfxBool wifiOnly);
    void setDataAcctId(VfxU32 dataAcctId, VfxU32 index, VappEmailServerType type);
    void setAuthType(srv_email_auth_type_enum authType, VappEmailServerType type);
    void setUsername(const VfxWString& userame, VappEmailServerType type);
    void setPassword(const VfxWString& password, VappEmailServerType type);
    void setDownloadOpt(srv_email_download_option_enum download_option);
    void setNotifyOpt(VfxBool notifyOn);
    void setDownloadSize(S32 downloadSize);
    void setRetrieveAmount(S32 retrieveAmount);
    void setAcctName(const VfxWString& acctName);
    void setAutoCheckType(CheckIntervalEnum);
    void setSaveSentEmails(VfxBool);

public:
    static void sysInit(void);
    static void getAppInfo(EMAIL_ACCT_ID, MMI_BOOL, VfxU32, U16*, U16*);
    static VfxBool initMiscInfo(EMAIL_ACCT_ID account_id);
    static MMI_BOOL queryAppInfoBySrv(srv_email_app_info_query_struct*, U16*, U16*);
    static EMAIL_MSG_PRIO getPriority(void);
    static VfxBool getAlwaysShowCcBcc(void);
    static VfxBool getGlobalSaveSentEmails(EMAIL_ACCT_ID);
    static void setPriority(EMAIL_MSG_PRIO);
    static void setAlwaysShowCcBcc(VfxBool);
    static void setGlobalSaveSendEmails(VfxBool, EMAIL_ACCT_ID);
    
    static void setAcctAttribute(srv_email_acct_info_struct *acctInfo);
    static VfxBool isAcctAddrExist(const VfxWChar* addr, EMAIL_ACCT_ID skipAcctId);
    static void getImap4Acct(EMAIL_ACCT_ID *imapAcct, VfxU32 &acctNum, VfxU32 maxAcctNum);
    
private:
    static void registerDataAcctDelHandler(void);
    static void checkAndReviseDataAcctId(void);
    static S32 dataAcctDelProc(mmi_event_struct* param);
    static S32 dataAcctUpdateProc(mmi_event_struct* param);

    static void readData(VappEmailGlobalSettingStruct* data);
    static void resetData(VappEmailGlobalSettingStruct* data);
    CheckIntervalEnum convertCheckInterval(U32 intervalValue);

private:
    EMAIL_ACCT_HANDLE acctHandle;
    srv_email_acct_info_struct acctInfo;
    CheckIntervalEnum autoCheckType;
    VfxBool saveSentEmails;
    VfxBool isAcctInfoChged;
    VfxBool isExtraInfoChged;
    VfxBool isAutoCheckChged;
};

#endif /* _VAPP_EMAIL_ACCT_H_ */
