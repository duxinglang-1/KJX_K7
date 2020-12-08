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
 *  Vapp_email_composer.cpp
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

#include "vapp_email_composer.h"
#include "vapp_email_acct.h"
#include "vapp_email_util.h"
#include "vapp_email_mgr.h"
extern "C"
{
#include "app_mine.h"
#include "conversions.h"
#include "FileMgrSrvGprot.h"
}

#define VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM  20
static const CHAR *VAPP_EMAIL_COMP_FLDR_NAME = "VappComp";

typedef struct
{
    VfxU32 version;
    VfxU32 totalNum;
    WCHAR domains[VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM][MMI_EMAIL_MAX_ADDR_LEN + 1];
} VappEmailRecentDomainStruct;

class VappEmailRecentDomain : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappEmailRecentDomain);

public:
    static void sysInit(void)
    {
        VappEmailRecentDomain *p = VappEmailRecentDomain::getInstance();
        memset(&p->data, 0, sizeof(VappEmailRecentDomainStruct));
        if (p->readFile() < FS_NO_ERROR)
        {
            memset(&p->data, 0, sizeof(VappEmailRecentDomainStruct));
            p->writeFile();
        }

        if (p->data.totalNum > VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM)
        {
            p->data.totalNum = VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM;
        }
    };
    
    static VfxU32 getCount(const WCHAR* filterStr)
    {
        VappEmailRecentDomain *p = VappEmailRecentDomain::getInstance();

        if (filterStr == NULL || filterStr[0] == 0)
        {
            return p->data.totalNum;
        }

        VfxU32 cnt = 0;
        for (VfxU32 i = 0; i < p->data.totalNum; ++i)
        {
            if (mmi_wcsnicmp(
                    p->data.domains[i],
                    filterStr,
                    mmi_wcslen(filterStr)) == 0)
            {
                ++cnt;
            }
        }
        return cnt;
    };
    
    static void getDomain(VfxU32 index, WCHAR *domain, const WCHAR* filterStr)
    {
        VappEmailRecentDomain *p = VappEmailRecentDomain::getInstance();
        if (index >= p->data.totalNum)
        {
            return;
        }

        if (filterStr == NULL || filterStr[0] == 0)
        {
            mmi_wcscpy(domain, p->data.domains[p->data.totalNum - 1 - index]);
            return;
        }

        VfxU32 cnt = 0;
        for (VfxU32 i = p->data.totalNum - 1; ; --i)
        {
            if (mmi_wcsnicmp(
                    p->data.domains[i],
                    filterStr,
                    mmi_wcslen(filterStr)) == 0)
            {
                if (cnt == index)
                {
                    mmi_wcscpy(domain, p->data.domains[i]);
                    return;
                }
                ++cnt;
            }
            if (i == 0)
            {
                break;
            }
        }
    };

    static void insertDomain(WCHAR *address)
    {
        VappEmailRecentDomain *p = VappEmailRecentDomain::getInstance();
        p->addAddr(address);
    };

    static void commit(void)
    {
        VappEmailRecentDomain *p = VappEmailRecentDomain::getInstance();
        p->writeFile();
    };

private:
    void addAddr(WCHAR* addr)
    {
        if (!vapp_email_util_chk_addr((const VfxWChar*)addr))
        {
            return;
        }

        VfxU32 len = mmi_wcslen(addr);
        VfxU32 i;
        for (i = 0; i < len; ++i)
        {
            if (*(addr + i) == '@')
            {
                break;
            }
        }
        if (i >= len - 1)
        {
            return;
        }

        addDomain(addr + i + 1);
    }
    
    void addDomain(WCHAR *domain)
    {
        VfxU32 i;
        for (i = 0; i < data.totalNum; ++i)
        {
            if (mmi_wcsicmp(domain, data.domains[i]) == 0)
            {
                for (VfxU32 j = i; j < data.totalNum - 1; ++j)
                {
                    mmi_wcscpy(data.domains[j], data.domains[j + 1]);
                }
                mmi_wcsncpy(
                    data.domains[data.totalNum - 1],
                    mmi_wcslwr(domain),
                    MMI_EMAIL_MAX_ADDR_LEN);
                return;
            }
        }

        if (data.totalNum < VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM)
        {
            i = data.totalNum;
        }
        else // if (totalNum == MAX_NUM)
        {
            for (VfxU32 j = 0; j < VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM - 1; ++j)
            {
                mmi_wcscpy(data.domains[j], data.domains[j + 1]);
            }
            i = VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM - 1;
        }

        mmi_wcsncpy(
            data.domains[i], mmi_wcslwr(domain), MMI_EMAIL_MAX_ADDR_LEN);

        if (data.totalNum < VAPP_EMAIL_RECENT_DOMAIN_MAX_NUM)
        {
            ++data.totalNum;
        }
    }

    void makePath(WCHAR *path)
    {
        kal_wsprintf(
            path,
            "%c:\\@email_sys\\%s",
            (CHAR) FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM),
            "domain");
    }
    
    VfxS32 readFile(void)
    {
        S32 ret;
        U32 readWrite;
        WCHAR path[32];
        FS_HANDLE hd;
        makePath(path);
        hd = FS_Open(path, FS_READ_ONLY);
        if (hd < FS_NO_ERROR)
        {
            VEMAIL_TRC_COMP_RECENT_DOMAIN_READ(hd);
            return hd;
        }
        ret = FS_Read(
                hd, &data, sizeof(VappEmailRecentDomainStruct), &readWrite);
        FS_Close(hd);
        return ret;
    }

    void writeFile(void)
    {
        S32 ret;
        U32 readWrite;
        WCHAR path[32];
        FS_HANDLE hd;
        makePath(path);
        hd = FS_Open(path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (hd < FS_NO_ERROR)
        {
            VEMAIL_TRC_COMP_RECENT_DOMAIN_WRITE(hd);
            return;
        }
        
        ret = FS_Write(
                hd, &data, sizeof(VappEmailRecentDomainStruct), &readWrite);
        if (ret < FS_NO_ERROR ||
            readWrite != sizeof(VappEmailRecentDomainStruct))
        {
            VEMAIL_TRC_COMP_RECENT_DOMAIN_WRITE(ret);
        }
        FS_Close(hd);
    }

private:
    VappEmailRecentDomainStruct data;
};

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappEmailRecentDomain);

////////////////////////////////////////////////////
//              Composer Class                    //
////////////////////////////////////////////////////
VappEmailComp::VappEmailComp()
    :
    acctId(EMAIL_ACCT_INVALID_ID),
    fldrId(EMAIL_FLDR_INVALID_ID),
    msgId(EMAIL_MSG_INVALID_ID),
    reqId(EMAIL_REQ_INVALID_ID),
    msgHandle(EMAIL_MSG_INVALID_HANDLE), 
    origHandle(EMAIL_MSG_INVALID_HANDLE),

    editMode(EMAIL_MODE_NEW),
    saveSendMode(EMAIL_MODE_SAVE_ONLY),

    backgroudSend(VFX_FALSE),

    currScr(NULL), 
    indicatorPopup(NULL),
    ucCuiId(0),

    priority(EMAIL_MSG_PRIO_MED),
    
    addrNum(0),
    attchNum(0),
    origAttchNum(0),

    addHtmlContAsAttch(VFX_FALSE),

    sigStatus(VFX_FALSE),
    sigHasImg(VFX_FALSE),
    sigTextLost(VFX_FALSE),
    sigImageLost(VFX_FALSE),

    ucUserdata(NULL),
    userChoosed(VFX_FALSE),
    fsErrorCode(0),
    asyncCopyJobId(0)
{
    senderAddr[0] = 0;
    subject[0] = 0;
    content[0] = 0;
    addrSubNum[0] = 0;
    addrSubNum[1] = 0;
    addrSubNum[2] = 0;

    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ATTACH_NUMBER; ++i)
    {
        attachments[i] = NULL;
    }
    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ADDR_NUM; ++i)
    {
        addresses[i] = NULL;
    }
}

VappEmailComp::~VappEmailComp()
{
    if (msgHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(msgHandle);
    }
    if (origHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(origHandle);
    }
    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ATTACH_NUMBER; ++i)
    {
        if (attachments[i] != NULL)
        {
            if (attachments[i]->needDeleteAfterSave)
            {
                FS_Delete(attachments[i]->path);
            }
            if (attachments[i]->copyed)
            {
                makeInternalAttchPath(i, attachments[i]->path);
                FS_Delete(attachments[i]->path);
            }
            VFX_FREE_MEM(attachments[i]);
        }
    }
    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ADDR_NUM; ++i)
    {
        if (addresses[i] != NULL)
        {
            VFX_FREE_MEM(addresses[i]);
        }
    }

    // call UC to exit
    if (ucCuiId != 0)
    {
        vcui_unifiedcomposer_close(ucCuiId);
    }

    if (asyncCopyJobId != 0)
    {
        srv_fmgr_async_abort(asyncCopyJobId, MMI_TRUE);
        asyncCopyJobId = 0;
    }
}

void VappEmailComp::onAcctListChoose(VfxObject *sender, VfxId id)
{
    if (!userChoosed)
    {
        userChoosed = (id != VCP_POPUP_BUTTON_NO_PRESSED);
    }
}

void VappEmailComp::onAcctListClick(
        VfxBasePopup* popup,
        VfxBasePopupStateEnum state)
{
    if (state != VFX_BASE_POPUP_AFTER_END_ANIMATION || !userChoosed)
    {
        return;
    }

    VcpSelectPopup *acctSelectPop = (VcpSelectPopup *)popup;
    VfxId id = acctSelectPop->getFirstSeletedId();

    VEMAIL_TRC_COMP_ACCT_LIST_ID(id);
    
    if (id > EMAIL_ACCT_INVALID_ID &&
        id <= EMAIL_ACCT_INVALID_ID + MMI_EMAIL_MAX_ACCTS)
    {
        newEmail(id, currScr);
    }
}

void VappEmailComp::newEmail(
        EMAIL_ACCT_ID id,
        VfxMainScr *scr,
        VfxBool backgroudSend)
{
    this->currScr = scr;
    this->backgroudSend = backgroudSend;
    
    if (id == EMAIL_ACCT_INVALID_ID)
    {
        EMAIL_ACCT_ID dftAcctId = EMAIL_ACCT_INVALID_ID;
        srv_email_acct_get_default(&dftAcctId);
        if (dftAcctId != EMAIL_ACCT_INVALID_ID)
        {
            id = dftAcctId;
        }
        else
        {
            VfxU32 acctCount = 0;
            srv_email_acct_get_num(&acctCount);

            VEMAIL_TRC_COMP_GET_ACCT_CNT(acctCount);

            if (acctCount == 0)
            {
                return;
            }

            EMAIL_ACCT_ID acctIds[MMI_EMAIL_MAX_ACCTS];
            srv_email_acct_get_acct_id(0, (VfxS32*)&acctCount, &acctIds[0]);
            if (acctCount == 1)
            {
                id = acctIds[0];
            }
            else    // lauch acct list page
            {
                VcpSelectPopup *acctSelectPop;
                userChoosed = VFX_FALSE;
                VFX_OBJ_CREATE(acctSelectPop, VcpSelectPopup, getParent());
                acctSelectPop->setText(VFX_WSTR_RES(STR_EMAIL_FTO_SELECT_ACCT));
                acctSelectPop->m_signalButtonClicked.connect(
                    this, &VappEmailComp::onAcctListChoose);
                acctSelectPop->m_signalPopupState.connect(
                    this, &VappEmailComp::onAcctListClick);

                for (VfxU32 i = 0; i < acctCount; ++i)
                {
                    srv_email_acct_info_cache_struct acctInfo;
                    srv_email_acct_cache_get(acctIds[i], &acctInfo);
                    acctSelectPop->addItem(
                        acctIds[i],
                        VFX_WSTR_MEM(acctInfo.acct_name), i == 0);
                }
                acctSelectPop->show(VFX_TRUE);
                return;
            }
        }
    } 

    VEMAIL_TRC_COMP_SLCT_ACCT_ID(id);

    if (attachments[0] != NULL)
    {
        /* New a email with attachment, we should show loading */
        showLoadingBeforeEnterUc(id, EMAIL_FLDR_INVALID_ID, EMAIL_MSG_INVALID_ID, scr, EMAIL_MODE_NEW);
    }
    else
    {
        acctId = id;
        currScr = scr;
        editMode = EMAIL_MODE_NEW;     
        realEdit();
    }
}

void VappEmailComp::newEmailSetSubj(WCHAR *subj)
{
    if (subj == NULL)
    {
        VEMAIL_TRC_COMP_SET_SUBJ(NULL, 0);
        return;
    }
    
    VEMAIL_TRC_COMP_SET_SUBJ(subj, subj[0]);
    mmi_wcsncpy(subject, subj, VAPP_EMAIL_MAX_SUBJ_LEN);
}

void VappEmailComp::newEmailSetCont(WCHAR *cont)
{
    if (cont == NULL)
    {
        VEMAIL_TRC_COMP_SET_CONT(NULL, 0);
        return;
    }
    
    VEMAIL_TRC_COMP_SET_CONT(cont, cont[0]);
    mmi_wcsncpy(content, cont, MMI_EMAIL_MAX_CONT_LEN);
}

void VappEmailComp::newEmailAddAddr(
    WCHAR *addr, WCHAR* name, srv_email_addr_type_enum type)
{
    if (addr == NULL)
    {
        VEMAIL_TRC_COMP_SET_ADDR(NULL, 0, NULL, 0, 0);
        return;
    }

    if (!(type == SRV_EMAIL_ADDR_TYPE_TO ||
          type == SRV_EMAIL_ADDR_TYPE_CC ||
          type == SRV_EMAIL_ADDR_TYPE_BCC))
    {
        VEMAIL_TRC_COMP_SET_ADDR(addr, addr[0], NULL, 0, type);
        return;
    }
    
    VfxU32 i;
    for (i = 0; i < MMI_EMAIL_MAX_ADDR_NUM; ++i)
    {
        if (addresses[i] == NULL)
        {
            break;
        }
    }
    VEMAIL_TRC_COMP_INST_ADDR_INDEX(i);
    

    VFX_ALLOC_MEM(addresses[i], sizeof(VappEmailCompAddrStruct), this);
    memset(addresses[i], 0, sizeof(VappEmailCompAddrStruct));
    
    addresses[i]->type = type;
    mmi_wcsncpy(addresses[i]->emailAddr, addr, SRV_EMAIL_MAX_ADDR_LEN);
    if (name != NULL && name[0] != 0)
    {
        VEMAIL_TRC_COMP_SET_ADDR(addr, addr[0], name, name[0], type);
        mmi_wcsncpy(addresses[i]->dispName, name, SRV_EMAIL_MAX_DISP_NAME_LEN);
    }
    else
    {
        VEMAIL_TRC_COMP_SET_ADDR(addr, addr[0], NULL, 0, type);
    }
}

void VappEmailComp::newEmailAddAttch(WCHAR *filePath, VfxBool deleteFile)
{
    VEMAIL_TRC_COMP_SET_ATTCH(
        filePath,
        filePath == NULL ? 0 : filePath[0],
        deleteFile);

    srv_email_attach_struct *tempAttachInfo;
    VFX_ALLOC_MEM(tempAttachInfo, sizeof(srv_email_attach_struct), this);
    memset(tempAttachInfo, 0, sizeof(srv_email_attach_struct));

    tempAttachInfo->downloaded = MMI_TRUE;
    tempAttachInfo->charset = MMI_CHSET_UCS2;
    mmi_wcsncpy(tempAttachInfo->path, filePath, SRV_EMAIL_MAX_FILE_NAME_LEN);

    const WCHAR *filename = srv_fmgr_path_get_filename_const_ptr(filePath);
    if (filename != NULL)
    {
        copyFileName(filename, tempAttachInfo->name);
    }

    U32 fileSize = 0;
    VfxS32 ret = vapp_email_util_file_get_size(filePath, &fileSize);

    VEMAIL_TRC_COMP_GET_FILE_SIZE(ret, fileSize);
    
    if (ret >= 0)
    {
        tempAttachInfo->size = fileSize;
        
        VappEmailComp::ResultEnum compRes =
            internalAddAttch(tempAttachInfo, VFX_FALSE, deleteFile);
        VEMAIL_TRC_COMP_INTERNAL_ADD_ATTCH(compRes);

        if (compRes != SUCC)
        {
            VfxResId errStrId = STR_GLOBAL_ERROR;
            switch (compRes)
            {
                case FILE_IS_EMPTY:
                    errStrId = STR_EMAIL_FTO_EMPTY_FILE;
                    break;
                case FILE_NOT_FOUND:
                    errStrId = STR_GLOBAL_FILE_NOT_FOUND;
                    break;
                case FILE_TOO_LARGE:
                case MAIL_TOO_LARGE:
                case EXCEED_MAX_ATTCH_NUM:
                    errStrId = STR_EMAIL_FTO_ATTCH_TOO_LARGE;
                    break;
                case DRM_PROHIBITED:
                    errStrId = STR_EMAIL_FTO_DRM_FILE_DELETED;
                    break;
                case FS_ERROR:
                    errStrId = srv_fmgr_fs_error_get_string(fsErrorCode);
                    break;
            }
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                                 MMI_EVENT_INFO_BALLOON,
                                 MMI_NMGR_BALLOON_TYPE_INFO,
                                 (WCHAR*)(GetString(errStrId)));
        }
    }

    VFX_FREE_MEM(tempAttachInfo);
}

// prepare Signature info (only when mode == new)
void VappEmailComp::initSignature(void)
{
    MMI_BOOL status = MMI_FALSE;
    sigStatus = VFX_FALSE;
    sigHasImg = VFX_FALSE;
    sigText[0] = 0;
    sigImgName[0] = 0;
    mmi_email_app_core_result_enum res;

    res = mmi_email_sig_get_status(acctId, &status);
    VEMAIL_TRC_COMP_SIG_GET_STATUS(res, acctId, status);
    
    sigStatus = (status == MMI_TRUE);

    if (sigStatus)
    {
        mmi_email_sig_struct *signature;
        VFX_ALLOC_MEM(signature, sizeof(mmi_email_sig_struct), this);

        res = mmi_email_sig_get_signature(acctId, signature);
        VEMAIL_TRC_COMP_SIG_GET_SIG(res, acctId);

        mmi_wcsncpy(sigText, signature->text, MMI_EMAIL_SIG_MAX_TEXT_LEN);
        sigHasImg = signature->image_num > 0;

        if (sigHasImg)
        {
            mmi_wcsncpy(
                sigImgName,
                signature->image_name[0],
                EMAIL_ATTCH_FILE_NAME_LEN);
        }

        VFX_FREE_MEM(signature);
    }
}

// prepare MSG Handle
srv_email_result_enum VappEmailComp::initHandle(void)
{
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;
    
    res = srv_email_msg_create(0, &msgHandle);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        VEMAIL_TRC_COMP_MSG_CREATE(res);
        return res;
    }

    if (editMode == EMAIL_MODE_EDIT)
    {
        res = srv_email_msg_open(msgHandle, acctId, fldrId, msgId);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_OPEN(res, msgId);
            srv_email_msg_destroy(msgHandle);
            return res;
        }
    }
    if (editMode == EMAIL_MODE_REPLY || 
        editMode == EMAIL_MODE_REPLY_ALL || 
        editMode == EMAIL_MODE_FWD || 
        editMode == EMAIL_MODE_NEW)
    {
        res = srv_email_msg_set_new(this->msgHandle);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_SET_NEW(res);
            srv_email_msg_destroy(this->msgHandle);
            return res;
        }
    }
    
    if (editMode == EMAIL_MODE_REPLY || 
        editMode == EMAIL_MODE_REPLY_ALL || 
        editMode == EMAIL_MODE_FWD)
    {
        res = srv_email_msg_create(0, &origHandle);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_CREATE(res);
            return res;
        }
        
        res = srv_email_msg_open(origHandle, acctId, fldrId, msgId);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_OPEN(res, msgId);
            srv_email_msg_destroy(origHandle);
            return res;
        }
    }
    
    return res;
}

// fill Sender and Reply-To
void VappEmailComp::initSender(void)
{
    if (editMode == EMAIL_MODE_EDIT)
    {
        EMAIL_MSG_HANDLE tempHandle = msgHandle;
        srv_email_addr_struct addrTmp;
        memset(&addrTmp, 0, sizeof(addrTmp));

        srv_email_result_enum res = srv_email_msg_get_sender(
                                        tempHandle, &addrTmp);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_GET_SENDER(res);
        }
        mmi_wcsncpy(senderAddr, addrTmp.email_addr, SRV_EMAIL_MAX_ADDR_LEN);
    }
    else if (editMode == EMAIL_MODE_REPLY ||
             editMode == EMAIL_MODE_REPLY_ALL ||
             editMode == EMAIL_MODE_FWD ||
             editMode == EMAIL_MODE_NEW)
    {
        srv_email_acct_info_struct gAcctInfo;
        srv_email_acct_info_struct *acctInfo = &gAcctInfo;
        EMAIL_ACCT_HANDLE acctHandle = 0;
        srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;

        res = srv_email_acct_create(0, &acctHandle);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_ACCT_CREATE(res);
            return;
        }

        res = srv_email_acct_open(acctHandle, acctId);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_ACCT_OPEN(res, acctId);
            srv_email_acct_destroy(acctHandle);
            return;
        }

        memset(&gAcctInfo, 0, sizeof(srv_email_acct_info_struct));
        res = srv_email_acct_read(acctHandle, acctInfo);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_ACCT_READ(res);
            srv_email_acct_destroy(acctHandle);
            return;
        }

        srv_email_acct_destroy(acctHandle);

        mmi_wcsncpy(
            senderAddr,
            acctInfo->email_addr.email_addr,
            SRV_EMAIL_MAX_ADDR_LEN);
        if (mmi_wcslen(acctInfo->reply_to_addr.email_addr))
        {
            res = srv_email_msg_update_reply_to(
                    msgHandle, &(acctInfo->reply_to_addr));
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                VEMAIL_TRC_COMP_UPDATE_REPLY_TO(res);
            }
        }
        if (mmi_wcslen(acctInfo->email_addr.email_addr))
        {
            res = srv_email_msg_update_sender(
                msgHandle, &(acctInfo->email_addr));
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                VEMAIL_TRC_COMP_UPDATE_SENDER(res);
            }
        }
    }
}

// prepare addrNum & attchNum
void VappEmailComp::initAddrAttchNum(void)
{
    if (editMode == EMAIL_MODE_EDIT || 
         editMode == EMAIL_MODE_REPLY || 
         editMode == EMAIL_MODE_REPLY_ALL || 
         editMode == EMAIL_MODE_FWD)
    {
        srv_email_msg_get_basic_info_struct *msgBasicInfo;
        VFX_ALLOC_MEM(
            msgBasicInfo,
            sizeof(srv_email_msg_get_basic_info_struct),
            this);
        memset(msgBasicInfo, 0, sizeof(srv_email_msg_get_basic_info_struct));
        EMAIL_MSG_HANDLE tempHandle =
                        (editMode == EMAIL_MODE_EDIT) ? msgHandle : origHandle;

        srv_email_result_enum res;
        res = srv_email_msg_get_basic_info(tempHandle, msgBasicInfo);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_GET_BASIC(res);
        }
        VEMAIL_TRC_COMP_MSG_BASIC_ADDR_ATTCH(
            msgBasicInfo->to_addr_num, 
            msgBasicInfo->cc_addr_num,
            msgBasicInfo->bcc_addr_num,
            msgBasicInfo->attach_num);

        if (editMode == EMAIL_MODE_EDIT)
        {
            addrSubNum[0] = msgBasicInfo->to_addr_num;
            addrSubNum[1] = msgBasicInfo->cc_addr_num;
            addrSubNum[2] = msgBasicInfo->bcc_addr_num;
            origAttchNum = msgBasicInfo->attach_num;
        }
        else    // for reply, reply-all, FWD
        {
            srv_email_result_enum result;
            S8 text_state = 0, html_state = 0;

            result = srv_email_msg_cont_status(
                        tempHandle, &text_state, &html_state);
            if ((result == SRV_EMAIL_RESULT_SUCC) &&
               !(text_state & SRV_EMAIL_MSG_CONT_PART_EXIST) &&
                (html_state & SRV_EMAIL_MSG_CONT_PART_EXIST) && 
                (html_state & SRV_EMAIL_MSG_CONT_DOWNLOADED))
            {
                // add html content as attachment
                addHtmlContAsAttch = VFX_TRUE;
                ++origAttchNum;
            }
        }
        
        if (editMode == EMAIL_MODE_FWD)
        {
            origAttchNum += msgBasicInfo->attach_num;
        }
        else if (editMode == EMAIL_MODE_REPLY)
        {
        }
        else if (editMode == EMAIL_MODE_REPLY_ALL)
        {
            addrSubNum[0] = msgBasicInfo->to_addr_num;
            addrSubNum[1] = msgBasicInfo->cc_addr_num;
        }
        VFX_FREE_MEM(msgBasicInfo);
    }
}


void VappEmailComp::initSubj(void)
{
    srv_email_result_enum res;
    VfxU32 subjLen = VAPP_EMAIL_MAX_SUBJ_LEN + 1;

    if (editMode == EMAIL_MODE_EDIT)
    {
        res = srv_email_msg_get_subject(msgHandle, subject, &subjLen);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_GET_SUBJ(res);
        }
    }
    else if (editMode == EMAIL_MODE_REPLY || 
             editMode == EMAIL_MODE_REPLY_ALL || 
             editMode == EMAIL_MODE_FWD)
    {
        res = srv_email_msg_get_subject(origHandle, subject, &subjLen);
        addReFwdPrefix(editMode, subject, (VAPP_EMAIL_MAX_SUBJ_LEN + 1) * 2);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_GET_SUBJ(res);
        }
    }
}

void VappEmailComp::initCont(void)
{
    srv_email_result_enum res;
    VfxU32 contLen = VAPP_EMAIL_MAX_CONT_LEN + 1;

    if (editMode == EMAIL_MODE_EDIT)
    {
        res = srv_email_msg_get_content(msgHandle, MMI_TRUE, content, &contLen);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_GET_CONT(res);
        }
    }
    else if (editMode == EMAIL_MODE_REPLY ||
             editMode == EMAIL_MODE_REPLY_ALL || 
             editMode == EMAIL_MODE_FWD)
    {
        res = srv_email_msg_get_content(origHandle, MMI_TRUE, content, &contLen);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_GET_CONT(res);
        }
    }

    if (editMode != EMAIL_MODE_EDIT && sigStatus)
    {
        if (mmi_wcslen(sigText) != 0)
        {
            if (VAPP_EMAIL_MAX_CONT_LEN - mmi_wcslen(content) > mmi_wcslen(sigText))
            {
                mmi_wcscat(content, (WCHAR*)L"\n");
                mmi_wcscat(content, sigText);
            }
            else
            {
                sigTextLost = VFX_TRUE;
            }
        }
    }
}

void VappEmailComp::initAddr(void)
{
    EMAIL_MSG_HANDLE tempHandle;
    srv_email_msg_get_recipient_struct addrCntx;
    srv_email_addr_struct *addrTmp;
    srv_email_result_enum res;

    tempHandle = (editMode == EMAIL_MODE_EDIT) ? msgHandle : origHandle;

    VFX_ALLOC_MEM(addrTmp, sizeof(srv_email_addr_struct), this);
    memset(addrTmp, 0, sizeof(srv_email_addr_struct));

    if (editMode == EMAIL_MODE_REPLY || editMode == EMAIL_MODE_REPLY_ALL)
    {
        // when reply, add Reply-To to TO
        // if no Reply-To, add the FROM to TO
        res = srv_email_msg_get_reply_to(tempHandle, addrTmp);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_MSG_GET_SENDER(res);
        }
        if (mmi_wcslen(addrTmp->email_addr) == 0 ||
            !(vapp_email_util_chk_addr((const VfxWChar*)addrTmp->email_addr)))
        {
            res = srv_email_msg_get_sender(tempHandle, addrTmp);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                VEMAIL_TRC_COMP_MSG_GET_SENDER(res);
            }
        }

        VfxU32 i;
        for (i = 0; i < MMI_EMAIL_MAX_ADDR_NUM; ++i)
        {
            if (addresses[i] == NULL)
            {
                break;
            }
        }
        VEMAIL_TRC_COMP_INST_ADDR_INDEX(i);

        VFX_ALLOC_MEM(addresses[i], sizeof(VappEmailCompAddrStruct), this);
        addresses[i]->type = SRV_EMAIL_ADDR_TYPE_TO;
        
        mmi_wcsncpy(
            addresses[i]->dispName,
            addrTmp->disp_name,
            SRV_EMAIL_MAX_DISP_NAME_LEN);
        mmi_wcsncpy(
            addresses[i]->emailAddr,
            addrTmp->email_addr,
            SRV_EMAIL_MAX_ADDR_LEN);
    }

        VFX_FREE_MEM(addrTmp);

    memset(&addrCntx, 0, sizeof(addrCntx));

    for (addrCntx.type = SRV_EMAIL_ADDR_TYPE_TO; 
         addrCntx.type <= SRV_EMAIL_ADDR_TYPE_BCC;
         addrCntx.type = (srv_email_addr_type_enum)(addrCntx.type + 1))
    {
        VfxU32 addrTypeIndex = (VfxU32)(addrCntx.type - SRV_EMAIL_ADDR_TYPE_TO);
        if ((addrCntx.number = addrSubNum[addrTypeIndex]) == 0)
        {
            continue;
        }

        VFX_ALLOC_MEM(
            addrTmp,
            addrCntx.number * sizeof(srv_email_addr_struct),
            this);
        memset(addrTmp, 0, addrCntx.number * sizeof(srv_email_addr_struct));
        addrCntx.addr_list = addrTmp;
        res = srv_email_msg_get_recipient(tempHandle, &addrCntx);
        VEMAIL_TRC_COMP_MSG_GET_RECIPIENT(res, addrCntx.number);

        VfxU32 i;
        for (i = 0; i < MMI_EMAIL_MAX_ADDR_NUM; ++i)
        {
            if (addresses[i] == NULL)
            {
                break;
            }
        }

        if (i >= MMI_EMAIL_MAX_ADDR_NUM)
        {
            VFX_FREE_MEM(addrTmp);
            break;
        }

        for (VfxU32 j = 0; j < addrCntx.number; ++j)
        {
            if (i >= MMI_EMAIL_MAX_ADDR_NUM)
            {
                // NO VFX_FREE_MEM !!!
                break;
            }

            // when it's reply all, if this address is already exist, ignore it
            if (editMode == EMAIL_MODE_REPLY_ALL &&
                isAddrExist((addrTmp + j)->email_addr))
            {
                continue;
        }
            
            VEMAIL_TRC_COMP_INST_ADDR_INDEX(i);

            VFX_ALLOC_MEM(addresses[i], sizeof(VappEmailCompAddrStruct), this);
            addresses[i]->type = addrCntx.type;
            mmi_wcsncpy(
                addresses[i]->dispName,
                (addrTmp + j)->disp_name,
                SRV_EMAIL_MAX_DISP_NAME_LEN);
            mmi_wcsncpy(
                addresses[i]->emailAddr,
                (addrTmp + j)->email_addr,
                SRV_EMAIL_MAX_ADDR_LEN);
            ++i;
        }
        
        VFX_FREE_MEM(addrTmp);
    }

    addrNum = 0;
    for (VfxU32 k = 0; k < MMI_EMAIL_MAX_ADDR_NUM; ++k)
    {
        if (addresses[k] != NULL)
        {
            ++addrNum;
        }
    }
    VEMAIL_TRC_COMP_ADDR_TOTAL(addrNum);
}

void VappEmailComp::initAttch(void)
{
    EMAIL_MSG_HANDLE tempHandle;
    srv_email_result_enum res;
    tempHandle = (editMode == EMAIL_MODE_EDIT) ? msgHandle : origHandle;

    if (editMode == EMAIL_MODE_NEW)
    {
        // to handle "in the account select screen, plug-out memory out"
        for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ATTACH_NUMBER; ++i)
        {
            if (attachments[i] != NULL)
            {
                VfxBool exist = VFX_FALSE;
                vapp_email_util_file_exist(attachments[i]->path, &exist);
                if (!exist)
                {
                    internalRemoveAttch(attachments[i]->path);
                    attachments[i] = NULL;
                }
                else if (!attachments[i]->copyed)
                {
                    attachments[i]->copyed = VFX_TRUE;

                    WCHAR *tempInternalPath = NULL;
                    VFX_ALLOC_MEM(
                        tempInternalPath,
                        (SRV_EMAIL_MAX_FILE_NAME_LEN * sizeof(WCHAR)),
                        this);
                    makeInternalAttchPath(i, tempInternalPath);
                    S32 ret = FS_Move(
                                attachments[i]->path,
                                tempInternalPath,
                                FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
                    VFX_FREE_MEM(tempInternalPath);
                    if (ret != FS_NO_ERROR)
                    {
                        fsErrorCode = ret;
                        const WCHAR *removePath = &(attachments[i]->path[0]);
                        internalRemoveAttch(removePath);
                        VEMAIL_TRC_COMP_ATTCH_COPY(ret);
                        mmi_frm_nmgr_balloon(
                            MMI_SCENARIO_ID_DEFAULT,
                            MMI_EVENT_INFO_BALLOON,
                            MMI_NMGR_BALLOON_TYPE_INFO,
                            (WCHAR*)(GetString(srv_fmgr_fs_error_get_string(fsErrorCode))));
                    }
                }
            }
        }
    }

    if (editMode != EMAIL_MODE_NEW)
    {
        if (origAttchNum > 0)
        {
            srv_email_attach_struct *tempAttachInfo;
            VFX_ALLOC_MEM(
                tempAttachInfo,
                sizeof(srv_email_attach_struct) * origAttchNum,
                this);
            memset(
                tempAttachInfo,
                0, sizeof(srv_email_attach_struct) * origAttchNum);

            VfxU32 i = 0;
            if (addHtmlContAsAttch)
            {
                CHAR *charsetString;
                U32 path_len = SRV_EMAIL_MAX_FILE_NAME_LEN + 1;
                VFX_ALLOC_MEM(charsetString, 50+1, this);
                
                res = srv_email_msg_get_html_file(
                        tempHandle,
                        (tempAttachInfo+i)->path,
                        &path_len,
                        charsetString,
                        MMI_TRUE);
                VFX_FREE_MEM(charsetString);
                
                (tempAttachInfo+i)->downloaded = MMI_TRUE;

                mmi_wcscpy((tempAttachInfo+i)->name, (WCHAR*)L"content.html");
                
                ++i;
            }

            if (origAttchNum - i > 0)
            {
                origAttchNum -= i;
                res = srv_email_msg_get_attachment_info(
                        tempHandle,
                        0,
                        (S32*)&origAttchNum,
                        tempAttachInfo + i);
            VEMAIL_TRC_COMP_MSG_GET_ATTCH(res, origAttchNum);
                origAttchNum += i;
            }

            for (i = 0; i < origAttchNum; ++i)
            {
                if (!(tempAttachInfo + i)->downloaded)
                {
                    continue;
                }

                VfxU32 realSize = 0;
                VfxS32 errCode = 0;
                VappEmailComp::ResultEnum compRes;
                compRes = VappEmailComp::chkAttch(
                            (tempAttachInfo+i)->path,
                            (tempAttachInfo+i)->name,
                            getAttchTotalSize(),
                            &realSize, 
                            &errCode);
                if (compRes != VappEmailComp::SUCC)
                {
                    VfxResId errId = STR_GLOBAL_ERROR;
                    switch (compRes)
                    {
                        case FILE_IS_EMPTY:
                            errId = STR_EMAIL_FTO_EMPTY_FILE;
                            break;
                        case FILE_NOT_FOUND:
                            errId = STR_GLOBAL_FILE_NOT_FOUND;
                            break;
                        case FILE_TOO_LARGE:
                        case MAIL_TOO_LARGE:
                        case EXCEED_MAX_ATTCH_NUM:
                            errId = STR_EMAIL_FTO_ATTCH_TOO_LARGE;
                            break;
                        case DRM_PROHIBITED:
                            errId = STR_EMAIL_FTO_DRM_FILE_DELETED;
                            break;
                        case FS_ERROR:
                            errId = srv_fmgr_fs_error_get_string(errCode);
                            break;
                    }
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)(GetString(errId)));
                    VEMAIL_TRC_COMP_CHK_ATTCH(compRes);
                    continue;
                }
                
                (tempAttachInfo + i)->size = realSize;
                compRes = internalAddAttch(
                            (tempAttachInfo + i),
                            editMode != EMAIL_MODE_EDIT ? VFX_TRUE : VFX_FALSE,
                            VFX_FALSE);
                if (compRes != VappEmailComp::SUCC)
                {
                    U16 errStr;
                    switch (compRes)
                    {
                        case VappEmailComp::FS_ERROR:
                            errStr = srv_fmgr_fs_error_get_string(fsErrorCode);
                            break;
                        case VappEmailComp::EXCEED_MAX_ATTCH_NUM:
                            errStr = STR_EMAIL_FTO_MAX_NUM_REACHED;
                            break;
                        default:
                            errStr = STR_GLOBAL_ERROR;
                            break;
                    }
                    VEMAIL_TRC_COMP_INTERNAL_ADD_ATTCH(compRes);
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_WARNING,
                        (WCHAR*)(GetString(errStr)));
                }
            }
            VFX_FREE_MEM(tempAttachInfo);
        }
    }

    // copy signature image
    if (editMode != EMAIL_MODE_EDIT && sigStatus && sigHasImg)
    {
        srv_email_attach_struct *tempAttachInfo;
        mmi_email_app_core_result_enum res;
        
        VFX_ALLOC_MEM(tempAttachInfo, sizeof(srv_email_attach_struct),this);
        memset(tempAttachInfo, 0, sizeof(srv_email_attach_struct));

        res = mmi_email_sig_get_image_path(
            acctId, 
            0, 
            tempAttachInfo->path, 
            SRV_FMGR_PATH_MAX_LEN + 1);
        if (res != MMI_EMAIL_SUCCESS)
        {
            VEMAIL_TRC_COMP_SIG_GET_PATH(res);
            VFX_FREE_MEM(tempAttachInfo);
            goto SIG_ERROR_EXIT;
        }

        VfxU32 realSize = 0;
        VappEmailComp::ResultEnum compRes;
        compRes = VappEmailComp::chkAttch(
                    tempAttachInfo->path,
                    tempAttachInfo->name,
                    getAttchTotalSize(),
                    &realSize, 
                    NULL);
        if (compRes != VappEmailComp::SUCC)
        {
            if (compRes == MAIL_TOO_LARGE)
            {
                sigImageLost = VFX_TRUE;
            }
            VEMAIL_TRC_COMP_CHK_ATTCH(compRes);
            VFX_FREE_MEM(tempAttachInfo);
            goto SIG_ERROR_EXIT;
        }

        mmi_wcsncpy(
            tempAttachInfo->name,
            sigImgName,
            EMAIL_ATTCH_FILE_NAME_LEN);
        tempAttachInfo->size = realSize;
        compRes = internalAddAttch(tempAttachInfo, VFX_TRUE, VFX_FALSE);
        if (compRes != VappEmailComp::SUCC)
        {
            sigImageLost = VFX_TRUE;
            VEMAIL_TRC_COMP_INTERNAL_ADD_ATTCH(compRes);
        }

        VFX_FREE_MEM(tempAttachInfo);
    }

SIG_ERROR_EXIT:

    attchNum = 0;
    for (VfxU32 k = 0; k < MMI_EMAIL_MAX_ATTACH_NUMBER; ++k)
    {
        if (attachments[k])
        {
            ++attchNum;
        }
    }
    VEMAIL_TRC_COMP_ATTCH_TOTAL(attchNum);
}

void VappEmailComp::editEmail(
        EMAIL_MSG_ID id, VfxMainScr* scr, VappEmailEditModeEnum mode)
{
    acctId = srv_email_msg_id_to_acct_id(id);
    fldrId = srv_email_msg_id_to_fldr_id(id);
    msgId = id;
    currScr = scr;
    editMode = mode;
    
    if (editMode == EMAIL_MODE_FWD)
    {
        /* When forword a email, need loading popup to wait copy attachment finished */
        showLoadingBeforeEnterUc(acctId, fldrId, msgId, scr, editMode);
    }
    else
    {
        realEdit();
    }
}

void VappEmailComp::editAsync(VfxTimer *source)
{
    VFX_OBJ_CLOSE(timer);
    timer = NULL;

    if (!indicatorPopup.isValid())
    {
        /* Timeout during terminate email app */
        return;
    }

    realEdit();
}


void VappEmailComp::showLoadingBeforeEnterUc(
        EMAIL_ACCT_ID inAcctId, 
        EMAIL_FLDR_ID inFldrId,
        EMAIL_MSG_ID inMsgId,
        VfxMainScr* scr,
        VappEmailEditModeEnum mode)
{
    acctId = inAcctId;
    fldrId = inFldrId;
    msgId = inMsgId;
    currScr = scr;
    editMode = mode;
    VcpIndicatorPopup *tempIndicator;

    vapp_email_indicator_pop(&tempIndicator, 
                             STR_GLOBAL_LOADING,
                             currScr->getPage(currScr->getTopPageId()));
    indicatorPopup = tempIndicator;

    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(500);
    timer->setDuration(500);
    timer->m_signalTick.connect(this, &VappEmailComp::editAsync);
    timer->start();
}


void VappEmailComp::realEdit()
{
    initSignature();

    srv_email_result_enum result = initHandle();
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        vapp_email_alert_cfm(vapp_email_util_get_err_code(
                                result, srv_email_errno_get()));
        goto EXIT;
    }

    initAddrAttchNum();
    initSubj();
    initCont();
    initSender();
    initAddr();
    initAttch();

    if ((sigTextLost && sigImageLost) || 
        (sigImageLost && (mmi_wcslen(sigText) == 0)) ||
        (sigTextLost && !sigHasImg))
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)(GetString(STR_EMAIL_FTO_SIG_DISCARDED)));
    }
    else if (sigTextLost || sigImageLost)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)(GetString(STR_EMAIL_FTO_SIG_PART_DISCARDED)));
    }

    if (origHandle != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(origHandle);
    }

    if (backgroudSend)
    {
        goto EXIT;
    }
    
    // prepare data for UC
    VappUcEntryStruct data;
    memset(&data, 0, sizeof(VappUcEntryStruct));
    
    data.subject = (U8*)subject;
    data.text_buffer = (U8*)content;
    data.text_num = mmi_wcslen(content);
    data.addr_num = addrNum;
    data.media_num = attchNum;
    data.info_type  = SRV_UC_INFO_TYPE_EMAIL;
    data.operation  = UC_OPERATION_EDIT_EXISTED_MSG;
    data.type       = SRV_UC_STATE_WRITE_NEW_MSG;
    data.msg_type   = SRV_UC_MSG_TYPE_MMS_ONLY;
    data.edit_mode  = SRV_UC_MMS_EDIT_MODE_EMAIL;
    data.callback   = &VappEmailComp::ucProc;
    data.callback_para = (void*)this;
    data.get_address_callback = &VappEmailComp::queryAddr;
    data.get_media_callback = &VappEmailComp::queryAttch;

    VEMAIL_TRC_COMP_UC_LAUNCH(addrNum, attchNum, subject[0], content[0]);

    //vappUcAppLauncher(&data);
    ucCuiId = vcui_unifiedcomposer_create(
                currScr->getApp()->getGroupId(), &data);
    if(ucCuiId != GRP_ID_INVALID)
    {
        vfxSetCuiCallerScr(ucCuiId, currScr);
        vcui_unifiedcomposer_run(ucCuiId);
    }

EXIT:
    if (indicatorPopup.isValid())
    {
        VcpIndicatorPopup *indicator = indicatorPopup.get(); 	
        VFX_OBJ_CLOSE (indicator);
    }
}

// for UC to query addresses
srv_uc_addr_struct* VappEmailComp::queryAddr(VfxU16 index, void* compInstdata)
{
    VappEmailComp *comp = VFX_STATIC_CAST(compInstdata, VappEmailComp*);

    if (comp == NULL)
    {
        VEMAIL_TRC_COMP_UC_QUERY_ADDR(-1, -1, -1);
        return NULL;
    }

    VFX_ASSERT(index < comp->addrNum && comp->addresses[index] != NULL);
    
    memset(&comp->ucAddrTmp, 0, sizeof(comp->ucAddrTmp));
    
    comp->ucAddrTmp.group = (srv_uc_address_group_type_enum)
                                (SRV_UC_ADDRESS_GROUP_TYPE_TO +
                                 comp->addresses[index]->type -
                                 SRV_EMAIL_ADDR_TYPE_TO);
    comp->ucAddrTmp.addr = (U8*)&comp->addresses[index]->emailAddr;
    comp->ucAddrTmp.next = comp->ucAddrTmp.previous = NULL;
    comp->ucAddrTmp.type = SRV_UC_ADDRESS_TYPE_EMAIL;

    VEMAIL_TRC_COMP_UC_QUERY_ADDR(
        index,
        comp->ucAddrTmp.group,
        comp->ucAddrTmp.addr);
    return &comp->ucAddrTmp;
}

// for UC to query attachments
void * VappEmailComp::queryAttch(
                        VfxU16 index,
                        vapp_uc_media_info *mediaInfo,
                        void* compInstdata)
{
    VappEmailComp *comp = VFX_STATIC_CAST(compInstdata, VappEmailComp*);

    if (comp == NULL)
    {
        VEMAIL_TRC_COMP_UC_QUERY_ATTCH(-1, -1, -1);
        return NULL;
    }

    VFX_ASSERT(index < comp->attchNum);

    mediaInfo->file_name = comp->attachments[index]->name;
    mediaInfo->file_path = comp->attachments[index]->path;
    mediaInfo->is_virtual_file = TRUE;
    mediaInfo->offset = 0;
    mediaInfo->size = comp->attachments[index]->size;

    VEMAIL_TRC_COMP_UC_QUERY_ATTCH(
        mediaInfo->file_name,
        mediaInfo->file_path,
        mediaInfo->size);
    return NULL;
}

// for UC to get the title string, it's sender's email address
void VappEmailComp::queryTitle(
                        VfxWString &titleStr1,
                        VfxWString &titleStr2,
                        void* compInstdata)
{
    VappEmailComp *comp = VFX_STATIC_CAST(compInstdata, VappEmailComp*);

    if (comp == NULL)
    {
        VEMAIL_TRC_COMP_UC_QUERY_TITLE(-1, -1);
        return;
    }

    if (comp->editMode == VappEmailComp::EMAIL_MODE_NEW)
    {
        titleStr1 = VFX_WSTR_RES(STR_EMAIL_FTO_NEW_EMAIL);
    }
    else
    {
        titleStr1 = VFX_WSTR_RES(STR_EMAIL_FTO_EDIT_EMAIL);
    }
    titleStr2.loadFromMem((VfxWChar*)comp->senderAddr);

    VEMAIL_TRC_COMP_UC_QUERY_TITLE(comp->editMode, comp->senderAddr[0]);
}

VfxBool VappEmailComp::queryShowCcBcc(void* compInstdata)
{
    VfxBool show = VappEmailAcct::getAlwaysShowCcBcc();

    VEMAIL_TRC_COMP_UC_QUERY_SHOW_CC(show);
    return show;
}

VfxU32 VappEmailComp::queryRecentContactCount(const WCHAR* filterStr)
{
    VfxU32 cnt = VappEmailRecentDomain::getCount(filterStr);

    VEMAIL_TRC_COMP_UC_QUERY_DOMAIN_CNT(cnt);
    return cnt;
}

void VappEmailComp::queryRecentContact(
        VfxU32 index, WCHAR *domain, const WCHAR* filterStr)
{
    VappEmailRecentDomain::getDomain(index, domain, filterStr);
    
    VEMAIL_TRC_COMP_UC_QUERY_DOMAIN(index, domain[0]);
}

void VappEmailComp::addRecentContact(const WCHAR *address)
{
    VappEmailRecentDomain::insertDomain((WCHAR*)address);
    VappEmailRecentDomain::commit();
}

VappEmailComp::ResultEnum VappEmailComp::chkAttch(
    const WCHAR* path,
    const WCHAR* fileName,    
    VfxU32 existAttchSize,
    VfxU32 *size,
    VfxS32 *errCode)
{
    VfxU32 realSize = 0;
    
    VfxS32 ret = vapp_email_util_file_get_size(path, &realSize);

    VEMAIL_TRC_COMP_GET_FILE_SIZE(ret, realSize);

    if (ret < 0)
    {
        if (ret == FS_PATH_NOT_FOUND || 
            ret == FS_FILE_NOT_FOUND ||
            ret == FS_INVALID_FILENAME)
        {
            return FILE_NOT_FOUND;
        }

        if (errCode != NULL)
        {
            *errCode = ret;
        }
        return FS_ERROR;
    }

    if (realSize == 0)
    {
        return FILE_IS_EMPTY;
    }

    if (realSize + existAttchSize > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
    {
        return MAIL_TOO_LARGE;
    }

#ifdef __DRM_SUPPORT__
    S32 mime_type = 0;
    S32 mime_subtype = 0;

    if (fileName != NULL)
    {
        vapp_email_util_get_mine_type(fileName, &mime_type, &mime_subtype);
    }
    else
    {
        vapp_email_util_get_mine_type(path, &mime_type, &mime_subtype);
    }
    
    if (mime_subtype == MIME_SUBTYPE_DRM_MESSAGE)
    {
        VEMAIL_TRC_COMP_DRM();
        return DRM_PROHIBITED;
    }
    
    S32 fwd_flag = mmi_rmgr_check_forward((U16*)path);
    if (fwd_flag < 0 || !(fwd_flag & MMI_RMGR_USAGE_SEND))
    {
        VEMAIL_TRC_COMP_DRM_FWD(fwd_flag);
        return DRM_PROHIBITED;
    }
#endif /* __DRM_SUPPORT__ */

    if (size != NULL)
    {
        *size = realSize;
    }
    return SUCC;
}

VfxU32 VappEmailComp::getAttchTotalSize(void)
{
    VfxU32 totalSize = 0;
    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ATTACH_NUMBER; ++i)
    {
        if (attachments[i] != NULL)
        {
            totalSize += attachments[i]->size;
        }
    }
    VEMAIL_TRC_COMP_TOTAL_SIZE(totalSize);
    return totalSize;
}

VappEmailComp::ResultEnum VappEmailComp::addAttch(
    const vapp_uc_media_info *mediaInfo, VfxU32 mailSize, void* compInstdata)
{
    VappEmailComp *comp = VFX_STATIC_CAST(compInstdata, VappEmailComp*);

    if (comp == NULL)
    {
        return VappEmailComp::FAIL;
    }
    
    WCHAR *path = (WCHAR*)mediaInfo->file_path;

    VfxU32 realSize = 0;

    VappEmailComp::ResultEnum res;
    VfxS32 errCode = 0;
    res = VappEmailComp::chkAttch(path, NULL, comp->getAttchTotalSize(), &realSize, &errCode);
    if (res != VappEmailComp::SUCC)
    {
        VEMAIL_TRC_COMP_CHK_ATTCH(res);
        if (res == VappEmailComp::FS_ERROR)
        {
            comp->fsErrorCode = errCode;
        }
        return res;
    }

    VfxBool isDrmFile = VFX_FALSE;

    S32 mime_type = 0;
    S32 mime_subtype = 0;
    S32 drm_type = 0;
    S32 drm_subtype = 0;

#ifdef __DRM_SUPPORT__
    vapp_email_util_get_mine_type(path, &mime_type, &mime_subtype);
    vapp_email_drm_is_file_lock(path, &isDrmFile);
    if (isDrmFile)
    {
        drm_type = mime_type;
        drm_subtype = mime_subtype;
        mime_type = MIME_TYPE_APPLICATION;
        mime_subtype = MIME_SUBTYPE_DRM_CONTENT;
    }
    else
#endif /* __DRM_SUPPORT__ */
    {
        vapp_email_util_get_mine_type(path, &mime_type, &mime_subtype);
#ifdef __DRM_SUPPORT__
        if (mime_subtype == MIME_SUBTYPE_DRM_CONTENT || 
            mime_subtype == MIME_SUBTYPE_DRM_MESSAGE)
        {
            mime_type = MIME_TYPE_UNKNOWN;
            mime_subtype = MIME_SUBTYPE_UNRECOGNIZED;
        }
#endif /* __DRM_SUPPORT__ */
    }

    srv_email_attach_struct *attch;
    VFX_ALLOC_MEM(attch, sizeof(srv_email_attach_struct), comp);
    memset(attch, 0, sizeof(srv_email_attach_struct));

    comp->copyFileName(mediaInfo->file_name, attch->name);
    mmi_wcsncpy(attch->path, path, SRV_EMAIL_MAX_FILE_NAME_LEN);
    attch->size = realSize;
    attch->mime_type = mime_type;
    attch->mime_subtype = mime_subtype;
    attch->drm_object = isDrmFile ? MMI_TRUE : MMI_FALSE;
    attch->drm_type = drm_type;
    attch->drm_subtype = drm_subtype;
    
    if ((res = comp->internalAddAttch(
                        attch, VFX_TRUE, VFX_FALSE)) == VappEmailComp::SUCC)
    {
        ++(comp->attchNum);
    }
    VEMAIL_TRC_COMP_INTERNAL_ADD_ATTCH(res);

    VFX_FREE_MEM(attch);

    return res;
}

mmi_ret VappEmailComp::copyAttchCallback(mmi_event_struct *param)
{
    srv_fmgr_async_done_event_struct *asyncEvt;
    VappEmailComp::ResultEnum result;
    VappEmailComp *comp = VFX_STATIC_CAST(param->user_data, VappEmailComp*);

    if (comp == NULL || !comp->isValid())
    {
        return MMI_RET_OK;
    }

    comp->asyncCopyJobId = 0;

    switch (param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            asyncEvt = (srv_fmgr_async_done_event_struct*)param;
            if (asyncEvt->result == 0)
            {
                result = VappEmailComp::SUCC;
                ++(comp->attchNum);
            }
            else
            {
                result = VappEmailComp::FS_ERROR;
                comp->fsErrorCode = asyncEvt->result;
                // for failure, free the note
                comp->internalRemoveAttch(comp->asyncCopyPath);
            }
            VEMAIL_TRC_COMP_INTERNAL_ADD_ATTCH(asyncEvt->result);
            VFX_ASSERT(comp->copyAttchUserProc != NULL);
            comp->copyAttchUserProc(result, comp->copyAttchUserData);
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


VappEmailComp::ResultEnum VappEmailComp::addAttchAsync(
    const vapp_uc_media_info *mediaInfo,
    VfxU32 mailSize,
    void* compInstdata,
    vapp_email_comp_proc user_proc,
    void *user_data)
{
    VappEmailComp *comp = VFX_STATIC_CAST(compInstdata, VappEmailComp*);

    if (comp == NULL)
    {
        return VappEmailComp::FAIL;
    }
    
    WCHAR *path = (WCHAR*)mediaInfo->file_path;

    VfxU32 realSize = 0;

    VappEmailComp::ResultEnum res;
    VfxS32 errCode = 0;
    res = VappEmailComp::chkAttch(path, NULL, comp->getAttchTotalSize(), &realSize, &errCode);
    if (res != VappEmailComp::SUCC)
    {
        VEMAIL_TRC_COMP_CHK_ATTCH(res);
        if (res == VappEmailComp::FS_ERROR)
        {
            comp->fsErrorCode = errCode;
        }
        return res;
    }

    VfxBool isDrmFile = VFX_FALSE;

    S32 mime_type = 0;
    S32 mime_subtype = 0;
    S32 drm_type = 0;
    S32 drm_subtype = 0;

#ifdef __DRM_SUPPORT__
    vapp_email_util_get_mine_type(path, &mime_type, &mime_subtype);
    vapp_email_drm_is_file_lock(path, &isDrmFile);
    if (isDrmFile)
    {
        drm_type = mime_type;
        drm_subtype = mime_subtype;
        mime_type = MIME_TYPE_APPLICATION;
        mime_subtype = MIME_SUBTYPE_DRM_CONTENT;
    }
    else
#endif /* __DRM_SUPPORT__ */
    {
        vapp_email_util_get_mine_type(path, &mime_type, &mime_subtype);
#ifdef __DRM_SUPPORT__
        if (mime_subtype == MIME_SUBTYPE_DRM_CONTENT || 
            mime_subtype == MIME_SUBTYPE_DRM_MESSAGE)
        {
            mime_type = MIME_TYPE_UNKNOWN;
            mime_subtype = MIME_SUBTYPE_UNRECOGNIZED;
        }
#endif /* __DRM_SUPPORT__ */
    }

    srv_email_attach_struct *attch;
    VFX_ALLOC_MEM(attch, sizeof(srv_email_attach_struct), comp);
    memset(attch, 0, sizeof(srv_email_attach_struct));

    comp->copyFileName(mediaInfo->file_name, attch->name);
    mmi_wcsncpy(attch->path, path, SRV_EMAIL_MAX_FILE_NAME_LEN);
    attch->size = realSize;
    attch->mime_type = mime_type;
    attch->mime_subtype = mime_subtype;
    attch->drm_object = isDrmFile ? MMI_TRUE : MMI_FALSE;
    attch->drm_type = drm_type;
    attch->drm_subtype = drm_subtype;

    comp->copyAttchUserProc = user_proc;
    comp->copyAttchUserData = user_data;

    res = comp->internalAddAttchAsync(attch, VFX_TRUE, VFX_FALSE,
                    &VappEmailComp::copyAttchCallback, (void*)comp);
    if (res == VappEmailComp::SUCC)
    {
        ++(comp->attchNum);
    }
    VEMAIL_TRC_COMP_INTERNAL_ADD_ATTCH(res);

    VFX_FREE_MEM(attch);

    return res;
}


VappEmailComp::ResultEnum VappEmailComp::removeAttch(
                const vapp_uc_media_info *mediaInfo, void* compInstdata)
{
    VappEmailComp *comp = VFX_STATIC_CAST(compInstdata, VappEmailComp*);

    if (comp == NULL)
    {
        return VappEmailComp::FAIL;
    }

    VappEmailComp::ResultEnum res =
        comp->internalRemoveAttch((const WCHAR*)mediaInfo->file_path);

    if (res == VappEmailComp::SUCC)
    {
        --(comp->attchNum);
    }
    VEMAIL_TRC_COMP_INTERNAL_DEL_ATTCH(res);
    return res;
}

VfxResId VappEmailComp::getFsErrorStrId(void* compInstdata)
{
    VappEmailComp *comp = VFX_STATIC_CAST(compInstdata, VappEmailComp*);

    if (comp == NULL)
    {
        return STR_GLOBAL_ERROR;
    }
    return (VfxResId)vapp_email_util_get_err_code(SRV_EMAIL_RESULT_FS_ERROR,
                                                  comp->fsErrorCode);
}

VfxBool VappEmailComp::isSendButtonAvailable()
{
    // In flight mode, the button should NOT be disabled
    // But SHOULD show a ballon
    /*mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE)); */

    VappEmailStateEnum emailState;
    return VappEmailMgr::getInstance()->isNetworkReady(emailState);
}

void VappEmailComp::setSaveSendMode(VappEmailSaveSendEnum mode)
{
    this->saveSendMode = mode;
    VEMAIL_TRC_COMP_SAVE_SEND_MODE(mode);
}

VfxBool VappEmailComp::save(
        void *compInstdata, VappUcEntryStruct *ucSaveData, void *ucUserdata)
{
    VappEmailComp *comp = (VappEmailComp*)compInstdata;

    VEMAIL_TRC_COMP_UC_CALL_EMAIL_SAVE();

    comp->setUcUserdata(ucSaveData, ucUserdata);
    comp->setSaveSendMode(EMAIL_MODE_SAVE_ONLY);
    return comp->realSave();
}

VfxBool VappEmailComp::send(
        void *compInstdata, VappUcEntryStruct *ucSaveData, void *ucUserdata)
{
    VappEmailComp *comp = (VappEmailComp*)compInstdata;

    VEMAIL_TRC_COMP_UC_CALL_EMAIL_SEND();

    comp->setUcUserdata(ucSaveData, ucUserdata);
    comp->saveSendMode = EMAIL_MODE_SAVE_SEND;
    return comp->realSave();
}

// to get Subject from UC
void VappEmailComp::getSubjFromUC(void)
{
    if (ucSaveData == NULL)
        return;
    mmi_wcsncpy(subject, (WCHAR*)ucSaveData->subject, VAPP_EMAIL_MAX_SUBJ_LEN);
}

// to get Content from UC
void VappEmailComp::getContFromUC(void)
{
    if (ucSaveData == NULL)
        return;
    mmi_wcsncpy(
        content,
        (WCHAR*)ucSaveData->text_buffer,
        VAPP_EMAIL_MAX_CONT_LEN);
}

// to get Addresses from UC
void VappEmailComp::getAddrFromUC(void)
{
    if (ucSaveData == NULL)
        return;
    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ADDR_NUM; ++i)
    {
        if (addresses[i] != NULL)
        {
            VFX_FREE_MEM(addresses[i]);
            addresses[i] = NULL;
        }
    }
    addrNum = 0;

    if (ucSaveData->addr_num != 0 && ucSaveData->get_address_callback != NULL)
    {
        srv_uc_addr_struct* addr;
        for (VfxS32 i = 0; i < ucSaveData->addr_num; ++i)
        {
            VFX_ALLOC_MEM(addresses[i], sizeof(VappEmailCompAddrStruct), this);
            memset(addresses[i], 0, sizeof(VappEmailCompAddrStruct));
            
            addr = (srv_uc_addr_struct*)ucSaveData->get_address_callback(
                                                        i, this->ucUserdata);
            addresses[i]->type = (srv_email_addr_type_enum)
                                    (SRV_EMAIL_ADDR_TYPE_TO +
                                    addr->group -
                                    SRV_UC_ADDRESS_GROUP_TYPE_TO);
            mmi_wcsncpy(
                addresses[i]->emailAddr,
                (WCHAR*)addr->addr,
                SRV_EMAIL_MAX_ADDR_LEN);

            ++addrNum;
        }
    }
}

// to get Attachments from UC
void VappEmailComp::getAttchFromUC(void)
{
    if (ucSaveData == NULL)
        return;
    //VFX_ASSERT(ucSaveData->media_num == attchNum);
}

srv_email_result_enum VappEmailComp::writeSubj(void)
{
    srv_email_result_enum res;

    res = srv_email_msg_update_subject(
            msgHandle, subject, MMI_CHSET_UCS2, mmi_wcslen(subject) + 1);

    VEMAIL_TRC_COMP_MSG_UPDATE_SUBJ(res);
    return res;
}

srv_email_result_enum VappEmailComp::writeCont(void)
{
    srv_email_result_enum res;
    srv_email_msg_update_content_struct contInfo;

    contInfo.buff_type = MMI_TRUE;
    contInfo.buff = content;
    contInfo.buff_len = mmi_wcslen(content) + 1;
    contInfo.charset = MMI_CHSET_UCS2;
    
    res = srv_email_msg_update_content(this->msgHandle, &contInfo);
    VEMAIL_TRC_COMP_MSG_UPDATE_CONT(res);
    return res;
}

// to get Addresses from UC
srv_email_result_enum VappEmailComp::writeAddr(void)
{
    static const VfxU32 toCcBccTypes = 3;
    VfxU32 nums[toCcBccTypes] = {0, 0, 0};

    for (VfxU16 i = 0; i < addrNum; ++i)
    {
        ++nums[addresses[i]->type - SRV_EMAIL_ADDR_TYPE_TO];
    }

    VEMAIL_TRC_COMP_FROM_UC_ADDR(nums[0], nums[1], nums[2]);

    srv_email_addr_struct *addrToWrite[toCcBccTypes] = {NULL, NULL, NULL};
    for (VfxU32 i = 0; i < toCcBccTypes; ++i)
    {
        if (nums[i] > 0)
        {
            VFX_ALLOC_MEM(
                addrToWrite[i],
                nums[i] * sizeof(srv_email_addr_struct),
                this);
            memset(addrToWrite[i], 0, nums[i] * sizeof(srv_email_addr_struct));
        }
    }

    U32 types[toCcBccTypes] = {0, 0, 0};
    for (VfxU32 i = 0; i < addrNum; ++i)
    {
        VfxU32 addrType = addresses[i]->type - SRV_EMAIL_ADDR_TYPE_TO;
        (addrToWrite[addrType] + types[addrType])->disp_charset =MMI_CHSET_UCS2;
        mmi_wcsncpy(
            (addrToWrite[addrType] + types[addrType])->email_addr,
            (WCHAR*)addresses[i]->emailAddr, SRV_EMAIL_MAX_ADDR_LEN);
        mmi_wcsncpy(
            (addrToWrite[addrType] + types[addrType])->disp_name,
            (WCHAR*)addresses[i]->dispName, SRV_EMAIL_MAX_DISP_NAME_LEN);
        ++types[addrType];
    }

    for (VfxU32 i = 0; i < toCcBccTypes; ++i)
    {
        srv_email_result_enum res;
        srv_email_addr_type_enum addrType =
            (srv_email_addr_type_enum)(i + SRV_EMAIL_ADDR_TYPE_TO);
            
        if (nums[i] > 0)
        {
            res = srv_email_msg_update_recipient(
                    this->msgHandle,
                    addrType,
                    nums[i],
                    addrToWrite[i]);
            VEMAIL_TRC_COMP_MSG_UPDATE_RECIPIENT(res, addrType, nums[i]);

            VFX_FREE_MEM(addrToWrite[i]);
        }
        else
        {
            res = srv_email_msg_update_recipient(
                    this->msgHandle,
                    addrType ,
                    nums[i],
                    (srv_email_addr_struct*)&nums[i]);
            VEMAIL_TRC_COMP_MSG_UPDATE_RECIPIENT(res, addrType, nums[i]);
        }

        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            return res;
        }
    }

    return SRV_EMAIL_RESULT_SUCC;
}

// to get Attachments from UC
srv_email_result_enum VappEmailComp::writeAttch(void)
{
    srv_email_result_enum res;

    if (attchNum != 0)
    {
        U16 i, j;
        srv_email_attach_struct *attch;
        VFX_ALLOC_MEM(attch, attchNum * sizeof(srv_email_attach_struct), this);
        memset(attch, 0, attchNum * sizeof(srv_email_attach_struct));       
        for (i = 0, j = 0; i < attchNum; ++i, ++j)
        {
            for (; j < MMI_EMAIL_MAX_ATTACH_NUMBER;)
            {
                if (attachments[j] != NULL)
                    break;
                ++j;
            }
            
            (attch + i)->size = attachments[j]->size;
            (attch + i)->downloaded = MMI_TRUE;
            (attch + i)->charset = MMI_CHSET_UCS2;
            mmi_wcsncpy(
                (attch + i)->name,
                attachments[j]->name,
                EMAIL_ATTCH_FILE_NAME_LEN);
            (attch + i)->name_len = mmi_wcslen((attch + i)->name);
            if (attachments[j]->copyed)
            {
                makeInternalAttchPath(j, (attch + i)->path);
            }

            else
            {
                mmi_wcsncpy(
                    (attch + i)->path,
                    attachments[j]->path,
                    SRV_EMAIL_MAX_FILE_NAME_LEN);
            }
            vapp_email_util_get_mine_type(
                (attch + i)->name,
                &(attch + i)->mime_type,
                &(attch + i)->mime_subtype);
        }

        res = srv_email_msg_update_attach(this->msgHandle, attchNum, attch);
        
        VFX_FREE_MEM(attch);
    }
    else
    {
        // the 3rd arg !!! NULL not allowed
        res = srv_email_msg_update_attach(msgHandle, 0, (srv_email_attach_struct*)1);
    }

    VEMAIL_TRC_COMP_MSG_UPDATE_ATTCH(res, attchNum);
    return res;    
}

// to save UC's userdata
void VappEmailComp::setUcUserdata(
                        VappUcEntryStruct *ucSaveData,
                        void *ucUserdata)
{
    this->ucSaveData = ucSaveData;
    this->ucUserdata = ucUserdata;
}

// save the mail
VfxBool VappEmailComp::realSave(void)
{
    srv_email_result_enum res;

    res = srv_email_msg_get_permission(msgHandle);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        VEMAIL_TRC_COMP_MSG_GET_PERMISSION(res);
        srv_email_msg_destroy(msgHandle);
        return VFX_FALSE;
    }

    if (!backgroudSend)
    {
        getSubjFromUC();
        getContFromUC();
        getAddrFromUC();
        getAttchFromUC();
    }

    //write Email content
    do
    {
        res = writeSubj();
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            break;            
        }
        res = writeCont();
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            break;            
        }        
        res = writeAddr();
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            break;            
        }        
        res = writeAttch();
    } while(0);

    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        if (!backgroudSend)
        {
            vapp_email_alert_cfm(
                vapp_email_util_get_err_code(res, srv_email_errno_get()));
        }
        return VFX_FALSE;
    }

    S32 fldrTypeArr[1] = {SRV_EMAIL_FLDR_TYPE_DRAFT};
    if (saveSendMode == EMAIL_MODE_SAVE_SEND)
    {
        fldrTypeArr[0] = SRV_EMAIL_FLDR_TYPE_OUTBOX;
    }

    EMAIL_FLDR_ID fldrIdArr[1] = {0};
    vapp_email_util_get_fldr_id_by_acct(acctId, 1, fldrTypeArr, fldrIdArr);
    fldrId = fldrIdArr[0];

    // update basic info to MSG handle
    srv_email_msg_update_basic_info_struct basicInfo;
    basicInfo.acct_id = acctId;
    basicInfo.fldr_id = fldrId;
    basicInfo.priority = VappEmailAcct::getPriority();
    basicInfo.flag = EMAIL_MSG_FLAG_SEEN;
    res = srv_email_msg_update_basic_info(msgHandle, &basicInfo);
    VEMAIL_TRC_COMP_MSG_UPDATE_BASIC_INFO(res);

    // register callback (two)
    srv_email_msg_regist_callback(msgHandle, &VappEmailComp::saveProc, this);
    srv_email_msg_regist_proc_callback(
        msgHandle, &VappEmailComp::saveStateProc, this);

    // go
    if (editMode == EMAIL_MODE_EDIT)
    {
        res = srv_email_msg_save(msgHandle, SRV_EMAIL_MSG_SAVE_ALL, &reqId);
        VEMAIL_TRC_COMP_MSG_SAVE(res);
    }
    else
    {
        res = srv_email_msg_save_new(msgHandle, acctId, fldrId, &msgId, &reqId);
        VEMAIL_TRC_COMP_MSG_SAVE_NEW(res);
    }

    if (res != SRV_EMAIL_RESULT_SUCC && 
        res != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        if (!backgroudSend)
        {
            vapp_email_alert_cfm(
                vapp_email_util_get_err_code(SRV_EMAIL_MAIL_ERROR, res));
        }
        return VFX_FALSE;;
    }

    if (!backgroudSend && currScr != NULL)
    {
        VcpIndicatorPopup *tempIndicator;
        vapp_email_indicator_pop(
            &tempIndicator, 
            (saveSendMode == EMAIL_MODE_SAVE_SEND) ? STR_EMAIL_FTO_PREPARE_TO_SEND : STR_GLOBAL_SAVING,
            currScr->getPage(currScr->getTopPageId()));
        indicatorPopup = tempIndicator;
    }

    return VFX_TRUE;
}

// save proc, handle the result
void VappEmailComp::saveProc(
                        srv_email_result_struct *result,
                        EMAIL_REQ_ID req_id,
                        void *user_data)
{
    VfxS32 majorErr = 0;
    VfxS32 minorErr = 0;
    VappEmailComp *comp = (VappEmailComp*)user_data;

    if (comp == NULL || !comp->isValid())
    {
        return;
    }

    // destroy the msgHandle
    srv_email_msg_destroy(comp->msgHandle);
    comp->msgHandle = EMAIL_MSG_INVALID_HANDLE;

    // close loading
    if (!comp->backgroudSend)
    {
        if (comp->indicatorPopup.isValid())
        {
            VcpIndicatorPopup *indicator = comp->indicatorPopup.get();
            VFX_OBJ_CLOSE(indicator);
        }
    }
    
    VEMAIL_TRC_COMP_MSG_SAVE_PROC(
        result->result,
        result->sub_result,
        result->major,
        result->minor);

    if (!result->result)
    {
        majorErr = result->major;
        minorErr = result->minor;
        goto MISSION_FAILED;
    }

    // only saving
    if (comp->saveSendMode != EMAIL_MODE_SAVE_SEND)
    {
        if (comp->backgroudSend)
        {
            comp->m_signalSaveSendResult.emit(VFX_TRUE, 0, 0);
        }
        else
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR*)(GetString(STR_EMAIL_FTO_SAVED_TO_DRAFT)));
        }
        return;
    }

    // start sending
    if (comp->editMode == EMAIL_MODE_EDIT)
    {
        // move draft to outbox
        EMAIL_MSG_ID msgId;
        EMAIL_MSG_HANDLE msgHd;

        S32 fldrTypeArr[1] = {SRV_EMAIL_FLDR_TYPE_OUTBOX};
        EMAIL_FLDR_ID fldrIdArr[1] = {0};

        vapp_email_util_get_fldr_id_by_acct(
            comp->acctId, 1, fldrTypeArr, fldrIdArr);

        srv_email_result_enum res;
        res = srv_email_msg_create(0, &msgHd);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            majorErr = res;
            minorErr = srv_email_errno_get();
            VEMAIL_TRC_COMP_MSG_CREATE(res);
            goto MISSION_FAILED;
        }

        res = srv_email_msg_open(
                msgHd, comp->acctId, comp->fldrId, comp->msgId);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            majorErr = res;
            minorErr = srv_email_errno_get();
            srv_email_msg_destroy(msgHd);
            VEMAIL_TRC_COMP_MSG_OPEN(comp->msgId, res);
            goto MISSION_FAILED;
        }

        res = srv_email_msg_move(msgHd, comp->acctId, fldrIdArr[0], &msgId);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            majorErr = SRV_EMAIL_MAIL_ERROR;
            minorErr = res;
            srv_email_msg_destroy(msgHd);
            VEMAIL_TRC_COMP_MSG_MOVE(res);
            goto MISSION_FAILED;
        }
        srv_email_msg_destroy(msgHd);
    }
        
    VappEmailMgr::getInstance()->sendOutbox(comp->acctId);
    VEMAIL_TRC_COMP_MSG_SEND();

    comp->m_signalSaveSendResult.emit(VFX_TRUE, 0, 0);
    return;

MISSION_FAILED:
    if (comp->backgroudSend)
    {
        comp->m_signalSaveSendResult.emit(VFX_FALSE, majorErr, minorErr);
    }
    else if (comp->currScr != NULL)
    {
       vapp_email_alert_cfm(vapp_email_util_get_err_code(majorErr, minorErr));
    }
}

void VappEmailComp::saveStateProc(srv_email_nwk_proc_struct *data)
{
    VFX_UNUSED(data);
}

void VappEmailComp::ucProc(void *userdata)
{
    VFX_UNUSED(userdata);
}

void VappEmailComp::makeInternalAttchPath(VfxU32 index, WCHAR* path)
{
    kal_wsprintf(
        path,
        "%s%s\\%0X_%d",
        srv_email_get_root_path(),
        VAPP_EMAIL_COMP_FLDR_NAME,
        (VfxU32)(this),
        index);
}

VappEmailComp::ResultEnum VappEmailComp::internalAddAttch(
    const srv_email_attach_struct* attch, VfxBool needCopy, VfxBool needDelete)
{
    VfxU32 i;
    for (i = 0; i < MMI_EMAIL_MAX_ATTACH_NUMBER; ++i)
    {
        if (attachments[i] == NULL)
        {
            VFX_ALLOC_MEM(
                attachments[i],
                sizeof(VappEmailCompAttchStruct),
                this);
            break;
        }
    }

    VEMAIL_TRC_COMP_INST_ATTCH_INDEX(i);
    
    if (i >= MMI_EMAIL_MAX_ATTACH_NUMBER)
    {
        return EXCEED_MAX_ATTCH_NUM;
    }
    
    mmi_wcsncpy(attachments[i]->path, attch->path, SRV_EMAIL_MAX_FILE_NAME_LEN);
    mmi_wcsncpy(attachments[i]->name, attch->name, EMAIL_ATTCH_FILE_NAME_LEN);
    attachments[i]->needDeleteAfterSave = needDelete;
    attachments[i]->size = attch->size;
    attachments[i]->copyed = needCopy;
    attachments[i]->isDrmFile = VFX_FALSE;

#ifdef __DRM_SUPPORT__
    vapp_email_util_get_mine_type(
            attachments[i]->name,
            &(attachments[i]->mimeType), 
            &(attachments[i]->mimeSubType));
    vapp_email_drm_is_file_lock(
        attachments[i]->path,
        &(attachments[i]->isDrmFile));
    if (attachments[i]->isDrmFile)
    {
        attachments[i]->drmType = attachments[i]->mimeType;
        attachments[i]->drmSubType = attachments[i]->mimeSubType;
        attachments[i]->mimeType = MIME_TYPE_APPLICATION;
        attachments[i]->mimeSubType = MIME_SUBTYPE_DRM_CONTENT;
    }
    else
#endif /* __DRM_SUPPORT__ */
    {
        vapp_email_util_get_mine_type(
            attachments[i]->name,
            &(attachments[i]->mimeType), 
            &(attachments[i]->mimeSubType));
    }

    if (needCopy)
    {
        WCHAR *tempInternalPath = NULL;
        VFX_ALLOC_MEM(
            tempInternalPath,
            (SRV_EMAIL_MAX_FILE_NAME_LEN * sizeof(WCHAR)),
            this);
        makeInternalAttchPath(i, tempInternalPath);
        S32 ret = FS_Move(
                    attachments[i]->path,
                    tempInternalPath,
                    FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
        VFX_FREE_MEM(tempInternalPath);
        if (ret != FS_NO_ERROR)
        {
            fsErrorCode = ret;
            const WCHAR *removePath = &(attachments[i]->path[0]);
            internalRemoveAttch(removePath);
            VEMAIL_TRC_COMP_ATTCH_COPY(ret);
            return VappEmailComp::FS_ERROR;
        }
    }

    return VappEmailComp::SUCC;
}

VappEmailComp::ResultEnum VappEmailComp::internalAddAttchAsync(
    const srv_email_attach_struct* attch,
    VfxBool needCopy,
    VfxBool needDelete,
    mmi_proc_func user_proc,
    void *user_data)
{
    VfxU32 i;
    for (i = 0; i < MMI_EMAIL_MAX_ATTACH_NUMBER; ++i)
    {
        if (attachments[i] == NULL)
        {
            VFX_ALLOC_MEM(
                attachments[i],
                sizeof(VappEmailCompAttchStruct),
                this);
            break;
        }
    }

    VEMAIL_TRC_COMP_INST_ATTCH_INDEX(i);
    
    if (i >= MMI_EMAIL_MAX_ATTACH_NUMBER)
    {
        return EXCEED_MAX_ATTCH_NUM;
    }
    
    mmi_wcsncpy(attachments[i]->path, attch->path, SRV_EMAIL_MAX_FILE_NAME_LEN);
    mmi_wcsncpy(attachments[i]->name, attch->name, EMAIL_ATTCH_FILE_NAME_LEN);
    attachments[i]->needDeleteAfterSave = needDelete;
    attachments[i]->size = attch->size;
    attachments[i]->copyed = needCopy;
    attachments[i]->isDrmFile = VFX_FALSE;

#ifdef __DRM_SUPPORT__
    vapp_email_util_get_mine_type(
            attachments[i]->name,
            &(attachments[i]->mimeType), 
            &(attachments[i]->mimeSubType));
    vapp_email_drm_is_file_lock(
        attachments[i]->path,
        &(attachments[i]->isDrmFile));
    if (attachments[i]->isDrmFile)
    {
        attachments[i]->drmType = attachments[i]->mimeType;
        attachments[i]->drmSubType = attachments[i]->mimeSubType;
        attachments[i]->mimeType = MIME_TYPE_APPLICATION;
        attachments[i]->mimeSubType = MIME_SUBTYPE_DRM_CONTENT;
    }
    else
#endif /* __DRM_SUPPORT__ */
    {
        vapp_email_util_get_mine_type(
            attachments[i]->name,
            &(attachments[i]->mimeType), 
            &(attachments[i]->mimeSubType));
    }

    if (needCopy)
    {
        WCHAR *tempInternalPath = NULL;
        VFX_ALLOC_MEM(
            tempInternalPath,
            (SRV_EMAIL_MAX_FILE_NAME_LEN * sizeof(WCHAR)),
            this);
        makeInternalAttchPath(i, tempInternalPath);

        asyncCopyPath = attachments[i]->path;
        S32 jobId = srv_fmgr_async_copy(
                        asyncCopyPath,
                        tempInternalPath,
                        FS_MOVE_COPY | FS_MOVE_OVERWRITE,
                        user_proc, user_data);
        VFX_FREE_MEM(tempInternalPath);
        if (jobId < 0)
        {
            fsErrorCode = jobId;
            internalRemoveAttch(asyncCopyPath);
            VEMAIL_TRC_COMP_ATTCH_COPY(jobId);
            return VappEmailComp::FS_ERROR;
        }
        else
        {
            asyncCopyJobId = jobId;
        }
        return VappEmailComp::WOULD_BLOCK;
    }

    return VappEmailComp::SUCC;
}

VappEmailComp::ResultEnum VappEmailComp::internalRemoveAttch(const WCHAR* path)
{
    VfxU32 i;
    for (i = 0; i < MMI_EMAIL_MAX_ATTACH_NUMBER; ++i)
    {
        if (attachments[i] != NULL)
        {
            if (mmi_wcscmp(attachments[i]->path, path) == 0)
            {
                break;
            }
        }
    }

    // return, safely
    if (i >= MMI_EMAIL_MAX_ATTACH_NUMBER)
    {
        return VappEmailComp::FAIL;
    }

    if (attachments[i]->copyed)
    {
        WCHAR *tempInternalPath = NULL;
        VFX_ALLOC_MEM(
            tempInternalPath,
            (SRV_EMAIL_MAX_FILE_NAME_LEN * sizeof(WCHAR)),
            this);
        makeInternalAttchPath(i, tempInternalPath);
        S32 ret = FS_Delete(tempInternalPath);
        VEMAIL_TRC_COMP_ATTCH_DEL(ret);

        VFX_FREE_MEM(tempInternalPath);
    }
    
    VFX_FREE_MEM(attachments[i]);

    return VappEmailComp::SUCC;
}

VfxBool VappEmailComp::isAddrExist(const WCHAR* addr)
{
    for (VfxU32 k = 0; k < MMI_EMAIL_MAX_ADDR_NUM; ++k)
    {
        if (addresses[k] != NULL)
        {
            if (mmi_wcsicmp(addresses[k]->emailAddr, addr) == 0)
            {
                return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}

void VappEmailComp::copyFileName(const WCHAR *origName, WCHAR* newName)
{
    const WCHAR *extension = srv_fmgr_path_get_extension_const_ptr(origName);
    if (mmi_wcslen(origName) <= EMAIL_ATTCH_FILE_NAME_LEN || 
        extension == NULL ||
        mmi_wcslen(extension) >= EMAIL_ATTCH_FILE_NAME_LEN - 1)
    {
        mmi_wcsncpy(newName, origName, EMAIL_ATTCH_FILE_NAME_LEN);
        return;
    }

    mmi_wcsncpy(
        newName,
        origName,
        EMAIL_ATTCH_FILE_NAME_LEN - mmi_wcslen(extension) - 1);
    mmi_wcscat(newName, (const WCHAR *)L".");
    mmi_wcscat(newName, extension);
}

void VappEmailComp::addReFwdPrefix(
    VappEmailEditModeEnum mode, WCHAR* subject, U32 buffLen)
{
    const WCHAR *englStrRe = (const WCHAR *)L"Re: ";
    const WCHAR *englStrFw = (const WCHAR *)L"Fw: ";
    const WCHAR *currStrRe = (const WCHAR*)GetString(STR_EMAIL_FTO_REPLY_IND);
    const WCHAR *currStrFw = (const WCHAR*)GetString(STR_EMAIL_FTO_FWD_IND);
    const WCHAR *addStr = (mode == EMAIL_MODE_FWD) ? currStrFw : currStrRe;
    U32 englStrReLen = mmi_wcslen(englStrRe);
    U32 englStrFwLen = mmi_wcslen(englStrFw);
    U32 currStrReLen = mmi_wcslen(currStrRe);
    U32 currStrFwLen = mmi_wcslen(currStrFw);
    U32 addStrLen = (mode == EMAIL_MODE_FWD) ? currStrFwLen : currStrReLen;
    WCHAR *posAfterIgnore = subject;

    while (1)
    {
        VfxBool found = VFX_FALSE;
        if (mmi_wcsnicmp(posAfterIgnore, englStrRe, englStrReLen) == 0)
        {
            found = VFX_TRUE;
            posAfterIgnore += englStrReLen;
        }
        if (mmi_wcsnicmp(posAfterIgnore, englStrFw, englStrFwLen) == 0)
        {
            found = VFX_TRUE;
            posAfterIgnore += englStrFwLen;
        }
        if (mmi_wcsnicmp(posAfterIgnore, currStrRe, currStrReLen) == 0)
        {
            found = VFX_TRUE;
            posAfterIgnore += currStrReLen;
        }
        if (mmi_wcsnicmp(posAfterIgnore, currStrFw, currStrFwLen) == 0)
        {
            found = VFX_TRUE;
            posAfterIgnore += currStrFwLen;
        }
        if (!found)
        {
            break;
        }
    }

    
    U32 moveBuffLen = buffLen - addStrLen * 2;
    if (moveBuffLen > (buffLen - (posAfterIgnore - subject) * 2))
    {
        moveBuffLen = (buffLen - (posAfterIgnore - subject) * 2);
    }
    memmove(subject + addStrLen, posAfterIgnore, moveBuffLen);
    memcpy(subject, addStr, addStrLen * 2);
    subject[buffLen/2 - 1] = 0;
}

VappEmailComp::ResultEnum VappEmailComp::sysInit(void)
{
    VappEmailRecentDomain::sysInit();

    {
        WCHAR path[100];
        kal_wsprintf(path,
                     "%s%s",
                     srv_email_get_root_path(),
                     VAPP_EMAIL_COMP_FLDR_NAME);

        FS_XDelete(
            path,
            FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
            NULL,
            0);

        S32 ret = FS_CreateDir(path);

        VEMAIL_TRC_COMP_SYS_INIT(ret);
        
        if (ret != FS_NO_ERROR)
        {
            return VappEmailComp::FAIL;
        }
        return VappEmailComp::SUCC;
    }
}

