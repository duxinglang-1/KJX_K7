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
 *  Vapp_email_composer.h
 *
 * Project:
 * --------
 *  COSMOS Email Composer
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

#ifndef _VAPP_EMAIL_COMPOSER_H_
#define _VAPP_EMAIL_COMPOSER_H_

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_uc_gprot.h"

#include "vapp_email_gprot.h"
#include "vapp_email_prot.h"

extern "C" {
#include "EmailSrvGprot.h"
#include "EmailAppGprot.h"
#include "Vapp_email_core.h"
}

typedef struct
{
    VfxBool copyed;
    VfxBool needDeleteAfterSave;
    VfxBool isDrmFile;
    VfxU32 size;
    WCHAR name[EMAIL_ATTCH_FILE_NAME_LEN + 1];
    WCHAR path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1]; 
    S32 mimeType;
    S32 mimeSubType;
    S32 drmType;
    S32 drmSubType;
} VappEmailCompAttchStruct;

typedef struct
{
    srv_email_addr_type_enum type;  // to/cc/bcc
    WCHAR dispName[SRV_EMAIL_MAX_DISP_NAME_LEN + 1];
    WCHAR emailAddr[SRV_EMAIL_MAX_ADDR_LEN + 1]; 
} VappEmailCompAddrStruct;


class VappEmailComp : public VfxObject
{
public:
    VappEmailComp();
    virtual ~VappEmailComp();

    enum ResultEnum
    {
        SUCC = 0,
        FAIL = -1,
        FILE_IS_EMPTY = -2,
        FILE_NOT_FOUND = -3,
        FILE_TOO_LARGE = -4,
        MAIL_TOO_LARGE = -5,
        DRM_PROHIBITED = -6,
        EXCEED_MAX_ATTCH_NUM = -7,
        FS_ERROR = -8,
        WOULD_BLOCK             = -9,
    };

    typedef void (*vapp_email_comp_proc)(VappEmailComp::ResultEnum result,
                                     void* user_data);

    // for Email
    enum VappEmailEditModeEnum
    {
        EMAIL_MODE_NEW = 0,
        EMAIL_MODE_REPLY,
        EMAIL_MODE_REPLY_ALL,
        EMAIL_MODE_FWD,
        EMAIL_MODE_EDIT,
    };

    // for UC
    enum VappEmailSaveSendEnum
    {
        EMAIL_MODE_SAVE_ONLY = 0,
        EMAIL_MODE_SAVE_SEND,
    };

    // ************ for [Email] interface -- START
    void newEmail(EMAIL_ACCT_ID, VfxMainScr*, VfxBool backgroudSend = VFX_FALSE);
    void newEmailSetSubj(WCHAR *subj);              // optional
    void newEmailSetCont(WCHAR *cont);              // optional
    void newEmailAddAddr(WCHAR *addr, WCHAR* name, srv_email_addr_type_enum type = SRV_EMAIL_ADDR_TYPE_TO); // optional
    void newEmailAddAttch(WCHAR *filePath, VfxBool deleteFile);         // optional

    void editEmail(EMAIL_MSG_ID, VfxMainScr*, VappEmailEditModeEnum mode = EMAIL_MODE_EDIT);
    // ************ for [Email] interface -- END

    // ************ for [UC] interface    -- START
    static VfxBool save(void*, VappUcEntryStruct*, void *);
    static VfxBool send(void*, VappUcEntryStruct*, void *);
    static srv_uc_addr_struct* queryAddr(VfxU16 index, void* compInstdata);
    static void *queryAttch(VfxU16 index, vapp_uc_media_info *mediaInfo, void* compInstdata);
    static void queryTitle(VfxWString &titleStr1, VfxWString &titleStr2, void* compInstdata);
    static VfxBool queryShowCcBcc(void* compInstdata);

    static VfxU32 queryRecentContactCount(const WCHAR* fiterStr = NULL);
    static void queryRecentContact(VfxU32 index, WCHAR *address, const WCHAR* fiterStr = NULL);
    static void addRecentContact(const WCHAR *address);

    static VappEmailComp::ResultEnum addAttch(const vapp_uc_media_info *mediaInfo, VfxU32 mailSize, void* compInstdata);
    static VappEmailComp::ResultEnum addAttchAsync(
                                        const vapp_uc_media_info *mediaInfo,
                                        VfxU32 mailSize,
                                        void* compInstdata,
                                        vapp_email_comp_proc user_proc,
                                        void *user_data);
    static mmi_ret copyAttchCallback(mmi_event_struct *param);
    static VappEmailComp::ResultEnum removeAttch(const vapp_uc_media_info *mediaInfo, void* compInstdata);
    static VfxResId getFsErrorStrId(void* compInstdata);
    static VfxBool isSendButtonAvailable();
    
    // ************ for [UC] interface    -- END

public:
    static VappEmailComp::ResultEnum sysInit(void);
    static VappEmailComp::ResultEnum chkAttch(
                                        const WCHAR* path,
                                        const WCHAR* fileName,
                                        VfxU32 existAttchSize,
                                        VfxU32 *size,
                                        VfxS32 *errCode);

public:
    VfxSignal3 <VfxBool, VfxS32, VfxS32> m_signalSaveSendResult;

private:
    // UC related
    void getSubjFromUC(void);
    void getContFromUC(void);
    void getAddrFromUC(void);
    void getAttchFromUC(void);
    VfxBool realSave(void);
    void setUcUserdata(VappUcEntryStruct *, void*);
    void setSaveSendMode(VappEmailSaveSendEnum);

    // init Email data
    void initSignature(void);
    srv_email_result_enum initHandle(void);
    void initSender(void);
    void initAddrAttchNum(void);
    void initSubj(void);
    void initCont(void);
    void initAddr(void);
    void initAttch(void);

    // wirte data to Email Srv
    srv_email_result_enum writeSubj(void);
    srv_email_result_enum writeCont(void);
    srv_email_result_enum writeAddr(void);
    srv_email_result_enum writeAttch(void);

    void onAcctListChoose(VfxObject *sender, VfxId id);
    void onAcctListClick(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void realEdit();

    void showLoadingBeforeEnterUc(
        EMAIL_ACCT_ID inAcctId, 
        EMAIL_FLDR_ID inFldrId,
        EMAIL_MSG_ID inMsgId,
        VfxMainScr* scr,
        VappEmailEditModeEnum mode);

    // uitlity
    void makeInternalAttchPath(VfxU32 index, WCHAR* path);
    ResultEnum internalAddAttch(const srv_email_attach_struct*, VfxBool, VfxBool);
    ResultEnum internalAddAttchAsync(const srv_email_attach_struct* attch,
                                     VfxBool needCopy,
                                     VfxBool needDelete,
                                     mmi_proc_func userProc,
                                     void *userData);
    ResultEnum internalRemoveAttch(const WCHAR* path);
    VfxU32 getAttchTotalSize(void);
    VfxBool isAddrExist(const WCHAR* addr);
    void addReFwdPrefix(VappEmailEditModeEnum mode, WCHAR* subject, U32 buffLen);
    void copyFileName(const WCHAR *origName, WCHAR* newName);

    void editAsync(VfxTimer *source);

    static void saveProc(srv_email_result_struct*, EMAIL_REQ_ID, void*);
    static void saveStateProc(srv_email_nwk_proc_struct*);
    static void ucProc(void *);

private:
    EMAIL_ACCT_ID acctId;
    EMAIL_FLDR_ID fldrId;
    EMAIL_MSG_ID  msgId;
    EMAIL_REQ_ID  reqId;
    EMAIL_MSG_HANDLE msgHandle;
    EMAIL_MSG_HANDLE origHandle;    // for Reply/FWD

    VappEmailEditModeEnum editMode;
    VappEmailSaveSendEnum saveSendMode;

    VfxBool backgroudSend;

    VfxMainScr *currScr;
    VfxWeakPtr<VcpIndicatorPopup> indicatorPopup;
    mmi_id ucCuiId;
 
    EMAIL_MSG_PRIO priority;
    WCHAR senderAddr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    WCHAR subject[VAPP_EMAIL_MAX_SUBJ_LEN + 1];
    WCHAR content[VAPP_EMAIL_MAX_CONT_LEN + 1];
    VappEmailCompAddrStruct *addresses[MMI_EMAIL_MAX_ADDR_NUM];
    VappEmailCompAttchStruct *attachments[MMI_EMAIL_MAX_ATTACH_NUMBER];
    VfxU32 addrNum;
    VfxU32 attchNum;
    VfxU32 addrSubNum[SRV_EMAIL_ADDR_TYPE_BCC - SRV_EMAIL_ADDR_TYPE_TO + 1];
    VfxU32 origAttchNum;

    VfxBool addHtmlContAsAttch;

    VfxBool sigStatus;
    VfxBool sigHasImg;
    VfxBool sigTextLost;
    VfxBool sigImageLost;    
    WCHAR   sigText[MMI_EMAIL_SIG_MAX_TEXT_LEN + 1];
    WCHAR   sigImgName[EMAIL_ATTCH_FILE_NAME_LEN + 1];

    VappUcEntryStruct *ucSaveData;
    void *ucUserdata;
    srv_uc_addr_struct ucAddrTmp;
    srv_email_attach_struct attchInfo;

    VfxBool userChoosed;    // for Account List 

    VfxS32 fsErrorCode;

    // for attach async copy
    vapp_email_comp_proc copyAttchUserProc;
    void*                copyAttchUserData;

    VfxTimer *timer;

    WCHAR *asyncCopyPath;
    S32 asyncCopyJobId;
};

#endif /* _VAPP_EMAIL_COMPOSER_H_ */
