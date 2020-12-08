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
 *  Vapp_email_acct.cpp
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

#include "vapp_email_acct.h"
#include "vapp_email_mgr.h"
#include "vapp_dtcnt_gprot.h"

extern "C" {
#include "EmailSrvGprot.h"
#include "Vapp_email_core.h"
#include "cbmsrvgprot.h"
#include "cbm_consts.h"
#include "cbm_api.h"
}

static VappEmailGlobalSettingStruct globalSettingData = {0};
static const CHAR * VAPP_EMAIL_GLOBAL_SETTING_NAME = "GlobalSetting";

const vapp_email_appinfo_map_struct
VappEmailAcct::appInfoArr[MMI_EMAIL_MAX_ACCTS * 4] =
{
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP1_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP2_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP3_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP4_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP5_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP6_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP7_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP8_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP9_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP10_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP11_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP12_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP13_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP14_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP15_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP16_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP17_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP18_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP19_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP20_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP21_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP22_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP23_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP24_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP25_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP26_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP27_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP28_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP29_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP30_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP31_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP32_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP33_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP34_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP35_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP36_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP37_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP38_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP39_ID},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_FTO_APP40_ID}
};

VappEmailAcct::VappEmailAcct(EMAIL_ACCT_ID acctId)
    :
    acctHandle(EMAIL_ACCT_INVALID_HANDLE),
    autoCheckType(CHECK_INTERVAL_OFF),
    isAcctInfoChged(VFX_FALSE),
    isExtraInfoChged(VFX_FALSE),
    isAutoCheckChged(VFX_FALSE)
{
    acctInfo.acct_id = acctId;
};

VappEmailAcct::~VappEmailAcct()
{
    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
        acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    }
}

srv_email_result_enum VappEmailAcct::initData(void)
{
    srv_email_result_enum res;
    
    res = srv_email_acct_create(0, &acctHandle);
    if (res != SRV_EMAIL_RESULT_SUCC) 
    {
        VEMAIL_TRC_ACCT_CREATE(res);
        return res;
    }
    
    res = srv_email_acct_open(acctHandle, acctInfo.acct_id);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_acct_destroy(acctHandle);
        acctHandle = EMAIL_ACCT_INVALID_HANDLE;
        
        VEMAIL_TRC_ACCT_OPEN(res);
        return res;
    }
    
    res = srv_email_acct_read(acctHandle, &acctInfo);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_acct_destroy(acctHandle);
        acctHandle = EMAIL_ACCT_INVALID_HANDLE;
        
        VEMAIL_TRC_ACCT_READ(res);
        return res;
    }
    
    saveSentEmails = VappEmailAcct::getGlobalSaveSentEmails(acctInfo.acct_id);
    
    mmi_email_app_core_result_enum appCoreRes;
    MMI_BOOL autoChkEnable = MMI_FALSE;
    
    appCoreRes = mmi_email_auto_check_get_day_enable(
                    acctInfo.acct_id, 0, &autoChkEnable);
    if (appCoreRes != MMI_EMAIL_SUCCESS)
    {
        VEMAIL_TRC_AUTO_CHK(appCoreRes);
        autoCheckType = CHECK_INTERVAL_OFF;
    }
    else if (autoChkEnable)
    {
        mmi_email_auto_check_time_segment autoCheckSegment;
        memset(&autoCheckSegment, 0, sizeof(mmi_email_auto_check_time_segment));
        
        appCoreRes = mmi_email_auto_check_get_segment(
                        acctInfo.acct_id, 0, 0, &autoCheckSegment);

        if (appCoreRes != MMI_EMAIL_SUCCESS)
        {
            VEMAIL_TRC_AUTO_CHK(appCoreRes);
            autoCheckType = CHECK_INTERVAL_OFF;
        }
        else
        {
            autoCheckType = convertCheckInterval(autoCheckSegment.interval);
        }
    }

    return SRV_EMAIL_RESULT_SUCC;
}

srv_email_result_enum VappEmailAcct::saveAcctInfo(void)
{
    srv_email_result_enum res;

    if (isAcctInfoChged)
    {
        res = srv_email_acct_get_permission(acctHandle);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_ACCT_PERMISSION(res);
            return res;
        }

        res = srv_email_acct_edit(acctHandle, &acctInfo);
        if (SRV_EMAIL_RESULT_SUCC != res) 
        {
            VEMAIL_TRC_ACCT_EDIT(res);
            return res;
        }
        
        res = srv_email_acct_save(acctHandle);
        if (SRV_EMAIL_RESULT_SUCC != res) 
        {
            VEMAIL_TRC_ACCT_SAVE(res);
            return res;
        }

        isAcctInfoChged = VFX_FALSE;
    }

    if (isExtraInfoChged)
    {
        VappEmailAcct::setGlobalSaveSendEmails(
            saveSentEmails,
            acctInfo.acct_id);
        isExtraInfoChged = VFX_FALSE;
    }

    if (isAutoCheckChged)
    {
        MMI_BOOL autoChkEnable;
        mmi_email_auto_check_time_segment autoChkSeg;

        autoChkEnable =
            (autoCheckType == CHECK_INTERVAL_OFF ? MMI_FALSE : MMI_TRUE);
        mmi_email_auto_check_set_day_enable(
            acctInfo.acct_id, 0, autoChkEnable);
        
        if (autoChkEnable)
        {
            autoChkSeg.start_time = VAPP_EMAIL_CHECK_INTERVAL_DAY_START_TIME;
            autoChkSeg.stop_time = VAPP_EMAIL_CHECK_INTERVAL_DAY_END_TIME;
            if (autoCheckType == CHECK_INTERVAL_5_MIN)
            {
                autoChkSeg.interval = VAPP_EMAIL_CHECK_INTERVAL_5_MIN_TIME;
            }
            else if (autoCheckType == CHECK_INTERVAL_30_MIN)
            {
                autoChkSeg.interval = VAPP_EMAIL_CHECK_INTERVAL_30_MIN_TIME;
            }
            else if (autoCheckType == CHECK_INTERVAL_1_HOUR)
            {
                autoChkSeg.interval = VAPP_EMAIL_CHECK_INTERVAL_1_HOUR_TIME;
            }
            else
            {
                autoChkSeg.interval = VAPP_EMAIL_CHECK_INTERVAL_2_HOUR_TIME;
            }
        }

        U16 dayIndex;
        for (dayIndex = VAPP_EMAIL_CHECK_INTERVAL_DAY_BEGIN; 
             dayIndex <= VAPP_EMAIL_CHECK_INTERVAL_DAY_END; ++dayIndex)
        {
            mmi_email_auto_check_set_day_enable(
                acctInfo.acct_id, dayIndex, autoChkEnable);
            if (autoChkEnable)
            {
                mmi_email_auto_check_edit_segment(
                    acctInfo.acct_id, dayIndex, 0, &autoChkSeg);
            }
        }

        if (autoChkEnable)
        {
            mmi_email_auto_check_start(acctInfo.acct_id);
        }
        else
        {
            mmi_email_auto_check_stop(acctInfo.acct_id);
        }
        
        isAutoCheckChged = VFX_FALSE;
    }

    return SRV_EMAIL_RESULT_SUCC;
}

srv_email_result_enum VappEmailAcct::delAcct(void)
{
    EMAIL_ACCT_ID acctId;
    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
        acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    }

    acctId = getBasicInfo()->acct_id;

    srv_email_result_enum res = srv_email_acct_delete(acctId);
    if (SRV_EMAIL_RESULT_SUCC != res)
    {
        return res;
    }

    VappEmailMgr::getInstance()->notifyAcctDelete(acctId);
    mmi_email_auto_check_delete_acct(acctId, MMI_TRUE);
    mmi_email_sig_delete_acct(acctId, MMI_TRUE);
    
    return SRV_EMAIL_RESULT_SUCC;
}

const srv_email_acct_info_struct * VappEmailAcct::getBasicInfo(void) const
{
    return &acctInfo;
}

EMAIL_ACCT_HANDLE VappEmailAcct::getAcctHandle(void) const
{
    return acctHandle;
};

void VappEmailAcct::setProtocol(srv_email_prot_type_enum protocol)
{
    isAcctInfoChged = VFX_TRUE;
    
    acctInfo.protocol = protocol;
}

void VappEmailAcct::setDispName(const VfxWString& dispName)
{    
    isAcctInfoChged = VFX_TRUE;

    mmi_wcsncpy(
        acctInfo.email_addr.disp_name,
        dispName.getBuf(),
        SRV_EMAIL_MAX_DISP_NAME_LEN);
}

void VappEmailAcct::setAddress(const VfxWString& addr)
{
    isAcctInfoChged = VFX_TRUE;
    
    mmi_wcsncpy(
        acctInfo.email_addr.email_addr,
        addr.getBuf(),
        SRV_EMAIL_MAX_ADDR_LEN);
}

void VappEmailAcct::setReplyTo(const VfxWString& replyTo)
{
    isAcctInfoChged = VFX_TRUE;
    
    mmi_wcsncpy(
        acctInfo.reply_to_addr.email_addr,
        replyTo.getBuf(),
        SRV_EMAIL_MAX_ADDR_LEN);
}


void VappEmailAcct::setServerName(
    const VfxWString& serverName, VappEmailServerType type)
{
    srv_email_server_struct *server =
        (type == INCOMING ? &acctInfo.in_server : &acctInfo.out_server);

    isAcctInfoChged = VFX_TRUE;

    mmi_wcsncpy(
        server->server_name,
        serverName.getBuf(),
        SRV_EMAIL_MAX_SERVER_NAME_LEN);
}

void VappEmailAcct::setPort(VfxU16 port, VappEmailServerType type)
{
    srv_email_server_struct *server =
        (type == INCOMING ? &acctInfo.in_server : &acctInfo.out_server);

    isAcctInfoChged = VFX_TRUE;

    server->port_num = port;
}

void VappEmailAcct::setSecPort(VfxU16 secPort, VappEmailServerType type)
{
    srv_email_server_struct *server =
        (type == INCOMING ? &acctInfo.in_server : &acctInfo.out_server);

    isAcctInfoChged = VFX_TRUE;

    server->sec_port_num = secPort;
}

void VappEmailAcct::setSecMode(
    srv_email_sec_mode_enum secMode,
    VappEmailServerType type)
{
    srv_email_server_struct *server =
        (type == INCOMING ? &acctInfo.in_server : &acctInfo.out_server);

    isAcctInfoChged = VFX_TRUE;

    server->sec_mode = secMode;
}

void VappEmailAcct::setWifiOnly(VfxBool wifiOnly)
{
    isAcctInfoChged = VFX_TRUE;
    
    acctInfo.in_server.wifi_only = wifiOnly ? MMI_TRUE : MMI_FALSE;
    acctInfo.out_server.wifi_only = wifiOnly ? MMI_TRUE : MMI_FALSE;
}

void VappEmailAcct::setDataAcctId(
    VfxU32 dataAcctId,
    VfxU32 index,
    VappEmailServerType type)
{
    srv_email_server_struct *server =
        (type == INCOMING ? &acctInfo.in_server : &acctInfo.out_server);

    VFX_ASSERT(index <= (MMI_MAX_SIM_NUM - 1));

    server->data_acct[index] = dataAcctId;
    isAcctInfoChged = VFX_TRUE;
}

void VappEmailAcct::setAuthType(
    srv_email_auth_type_enum authType,
    VappEmailServerType type)
{
    srv_email_auth_struct *auth =
        (type == INCOMING ? &acctInfo.in_auth : &acctInfo.out_auth);

    auth->auth_type = authType;

    isAcctInfoChged = VFX_TRUE;
}

void VappEmailAcct::setUsername(
    const VfxWString& userame,
    VappEmailServerType type)
{    
    srv_email_auth_struct *auth =
        (type == INCOMING ? &acctInfo.in_auth : &acctInfo.out_auth);

    isAcctInfoChged = VFX_TRUE;

    mmi_wcsncpy(auth->username, userame.getBuf(), SRV_EMAIL_MAX_USERNAME_LEN);
}

void VappEmailAcct::setPassword(
    const VfxWString& password,
    VappEmailServerType type)
{
    srv_email_auth_struct *auth =
        (type == INCOMING ? &acctInfo.in_auth : &acctInfo.out_auth);

    isAcctInfoChged = VFX_TRUE;

    mmi_wcsncpy(auth->password, password.getBuf(), SRV_EMAIL_MAX_PASSWORD_LEN);
}

void VappEmailAcct::setDownloadOpt(srv_email_download_option_enum downloadOpt)
{
    isAcctInfoChged = VFX_TRUE;
    
    acctInfo.download_option = downloadOpt;
}

void VappEmailAcct::setNotifyOpt(VfxBool notifyOn)
{
    isAcctInfoChged = VFX_TRUE;
    
    acctInfo.notify_option =
        (notifyOn ? SRV_EMAIL_NOTIFY_ON : SRV_EMAIL_NOTIFY_OFF);
}

void VappEmailAcct::setDownloadSize(S32 downloadSize)
{
    isAcctInfoChged = VFX_TRUE;
    
    acctInfo.download_size = downloadSize;
}

void VappEmailAcct::setRetrieveAmount(S32 retrieveAmount)
{
    isAcctInfoChged = VFX_TRUE;
    
    acctInfo.retrieve_amount = retrieveAmount;
}

void VappEmailAcct::setAcctName(const VfxWString& acctName)
{
    isAcctInfoChged = VFX_TRUE;

    mmi_wcsncpy(
        acctInfo.acct_name,
        acctName.getBuf(),
        SRV_EMAIL_MAX_ACCT_NAME_LEN);
}

VfxBool VappEmailAcct::getSaveSentEmails(void) const
{
    return saveSentEmails;
}

void VappEmailAcct::setSaveSentEmails(VfxBool saveSent)
{
    isExtraInfoChged = VFX_TRUE;
    
    saveSentEmails = saveSent;
}

VappEmailAcct::CheckIntervalEnum VappEmailAcct::getAutoCheckType(void) const
{
    return autoCheckType;
}

void VappEmailAcct::setAutoCheckType(CheckIntervalEnum autoCheckEnum)
{
    isAutoCheckChged = VFX_TRUE;
    
    autoCheckType = autoCheckEnum;
}

VappEmailAcct::CheckIntervalEnum VappEmailAcct::convertCheckInterval(
    U32 intervalValue)
{
    if (intervalValue <= (5 * 60))
    {
        return CHECK_INTERVAL_5_MIN;
    }
    else if (intervalValue <= (30 * 60))
    {
        return CHECK_INTERVAL_30_MIN;
    }
    else if (intervalValue <= (60 * 60))
    {
        return CHECK_INTERVAL_1_HOUR;
    }
    
    return CHECK_INTERVAL_2_HOUR;
}

S32 VappEmailAcct::dataAcctDelProc(mmi_event_struct* param)
{
    srv_dtcnt_acct_delete_ind_evt_struct *dt_acct =
        (srv_dtcnt_acct_delete_ind_evt_struct*)param;

    if (srv_email_get_srv_init_state() != SRV_EMAIL_INIT_STATE_READY)
    {
        return MMI_RET_OK;
    }

    VfxU32 acctCnt = 0;
    srv_email_acct_get_num(&acctCnt);
    EMAIL_ACCT_ID acctIdArray[MMI_EMAIL_MAX_ACCTS] = {0};
    srv_email_acct_get_acct_id(0, (S32*)&acctCnt, acctIdArray);

    srv_email_acct_info_struct *acct_info;
    acct_info = (srv_email_acct_info_struct*)
                    mmi_frm_temp_alloc(sizeof(srv_email_acct_info_struct));
    for (VfxU32 i = 0; i < acctCnt; ++i) 
    {
        srv_email_result_enum result;
        EMAIL_ACCT_HANDLE acct_handle;
        MMI_BOOL acct_info_changed = MMI_FALSE;
        acct_handle = EMAIL_ACCT_INVALID_HANDLE;
        result = srv_email_acct_create(0, &acct_handle);
        VfxU32 simIndex;
        
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            continue;
        }
        result = srv_email_acct_open(acct_handle, acctIdArray[i]);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_read(acct_handle, acct_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_get_permission(acct_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        
        for (simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
        {
            cbm_account_info_struct acctInfo;
            cbm_app_info_struct app_info;
            app_info.app_type = DTCNT_APPTYPE_EMAIL;
            
            VappEmailAcct::getAppInfo(
                acctIdArray[i],
                MMI_TRUE,
                simIndex,
                &app_info.app_str_id,
                &app_info.app_icon_id);
        
            cbm_decode_data_account_id_ext(
                acct_info->in_server.data_acct[simIndex],
                &acctInfo);

            if (acctInfo.account[0].account_id == dt_acct->acc_id[0])
            {
                acct_info_changed = MMI_TRUE;
                acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
                
                cbm_encode_data_account_id_ext(
                    acct_info->in_server.data_acct[simIndex],
                    &(acct_info->in_server.data_acct[simIndex]),
                    &acctInfo);
            }
        }

        if (acct_info_changed)
        {
            for (simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
            {
                acct_info->out_server.data_acct[simIndex] =
                    acct_info->in_server.data_acct[simIndex];
            }
            
            srv_email_acct_edit(acct_handle, acct_info);
            srv_email_acct_save(acct_handle);
        }
        srv_email_acct_destroy(acct_handle);
    }
    mmi_frm_temp_free(acct_info);

    return MMI_RET_OK;
}

S32 VappEmailAcct::dataAcctUpdateProc(mmi_event_struct* param)
{
    srv_dtcnt_acct_update_ind_evt_struct *dt_acct =
        (srv_dtcnt_acct_update_ind_evt_struct*)param;

    if (srv_email_get_srv_init_state() != SRV_EMAIL_INIT_STATE_READY ||
        dt_acct->cause != 1)  // only handle provisioning case
    {
        return MMI_RET_OK;
    }

    VfxU32 acctCnt = 0;
    srv_email_acct_get_num(&acctCnt);
    EMAIL_ACCT_ID acctIdArray[MMI_EMAIL_MAX_ACCTS] = {0};
    srv_email_acct_get_acct_id(0, (S32*)&acctCnt, acctIdArray);

    srv_email_acct_info_struct *acct_info;
    acct_info = (srv_email_acct_info_struct*)
                    mmi_frm_temp_alloc(sizeof(srv_email_acct_info_struct));
    for (VfxU32 i = 0; i < acctCnt; ++i) 
    {
        srv_email_result_enum result;
        EMAIL_ACCT_HANDLE acct_handle;
        MMI_BOOL acct_info_changed = MMI_FALSE;
        acct_handle = EMAIL_ACCT_INVALID_HANDLE;
        result = srv_email_acct_create(0, &acct_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            continue;
        }
        result = srv_email_acct_open(acct_handle, acctIdArray[i]);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_read(acct_handle, acct_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_get_permission(acct_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        
        VfxU32 simIndex;
        for (simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
        {
            cbm_account_info_struct acctInfo;
            cbm_app_info_struct app_info;
            app_info.app_type = DTCNT_APPTYPE_EMAIL;
            
            VappEmailAcct::getAppInfo(
                        acctIdArray[i],
                        MMI_TRUE, 
                        simIndex,
                        &app_info.app_str_id,
                        &app_info.app_icon_id);
            
            cbm_decode_data_account_id_ext(
                acct_info->in_server.data_acct[simIndex],
                &acctInfo);

            if (acctInfo.account[0].account_id == dt_acct->acc_id)
            {
                acct_info_changed = MMI_TRUE;
                acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
                
                cbm_encode_data_account_id_ext(
                    acct_info->in_server.data_acct[simIndex],
                    &(acct_info->in_server.data_acct[simIndex]),
                    &acctInfo);
            }
        }

        if (acct_info_changed)
        {
            for (simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
            {
                acct_info->out_server.data_acct[simIndex] =
                    acct_info->in_server.data_acct[simIndex];
            }
            
            srv_email_acct_edit(acct_handle, acct_info);
            srv_email_acct_save(acct_handle);
        }
        
        srv_email_acct_destroy(acct_handle);
    }
    mmi_frm_temp_free(acct_info);

    return MMI_RET_OK;
}

static VfxBool vapp_email_has_registered_data_acct_handler = VFX_FALSE;

void VappEmailAcct::registerDataAcctDelHandler(void)
{
    if (!vapp_email_has_registered_data_acct_handler)
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND,
            VappEmailAcct::dataAcctDelProc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND,
            VappEmailAcct::dataAcctUpdateProc, NULL);
    }
}

void VappEmailAcct::checkAndReviseDataAcctId(void)
{
    EMAIL_ACCT_HANDLE acctHandle;
    srv_email_acct_info_struct *acctInfoP;

    VfxU32 acctCnt = 0;
    srv_email_acct_get_num(&acctCnt);

    if (acctCnt == 0)
    {
        return;
    }
    
    acctInfoP = (srv_email_acct_info_struct*)
        mmi_frm_temp_alloc(sizeof(srv_email_acct_info_struct));

    EMAIL_ACCT_ID acctIdArray[MMI_EMAIL_MAX_ACCTS];
    srv_email_acct_get_acct_id(0, (S32*)&acctCnt, acctIdArray);

    for (VfxU32 i = 0; i < acctCnt; ++i) 
    {
        srv_email_result_enum result;

        acctHandle = EMAIL_ACCT_INVALID_HANDLE;
        result = srv_email_acct_create(0, &acctHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            continue;
        }
        result = srv_email_acct_open(acctHandle, acctIdArray[i]);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acctHandle);
            continue;
        }
        result = srv_email_acct_read(acctHandle, acctInfoP);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acctHandle);
            continue;
        }
        result = srv_email_acct_get_permission(acctHandle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acctHandle);
            continue;
        }

        cbm_app_info_struct app_info;
        U32 encodeedDataAcctId;
        MMI_BOOL acct_info_changed = MMI_FALSE;
        U8 app_id = 0;
        
        app_info.app_type = DTCNT_APPTYPE_EMAIL;

        VfxU32 simIndex;
        
        for (simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
        {
            VappEmailAcct::getAppInfo(
                acctIdArray[i],
                MMI_TRUE,
                simIndex,
                &app_info.app_str_id,
                &app_info.app_icon_id);
            app_info.app_type = DTCNT_APPTYPE_EMAIL;
            cbm_register_app_id_with_app_info(&app_info, &app_id);
            encodeedDataAcctId =
                cbm_set_app_id(acctInfoP->in_server.data_acct[simIndex], app_id);

            if (vapp_dtcnt_acct_is_valid(encodeedDataAcctId, MMI_FALSE) ==
                DTCNT_ACCT_VALID_NONE)
            {
                cbm_sim_id_enum cbm_sim_id;

                switch (simIndex)
                {
                    case 0:
                        cbm_sim_id = CBM_SIM_ID_SIM1;
                        break;
                    case 1:
                        cbm_sim_id = CBM_SIM_ID_SIM2;
                        break;
                    case 2:
                        cbm_sim_id = CBM_SIM_ID_SIM3;
                        break;
                    case 3:
                        cbm_sim_id = CBM_SIM_ID_SIM4;
                        break;
                    default:
                        cbm_sim_id = CBM_SIM_ID_SIM1;
                        break;                        
                }
                acctInfoP->in_server.data_acct[simIndex] =
                    cbm_encode_data_account_id(
                        CBM_DEFAULT_ACCT_ID, cbm_sim_id, app_id, KAL_FALSE);
                acctInfoP->out_server.data_acct[simIndex] =
                    acctInfoP->in_server.data_acct[simIndex];
                acct_info_changed = MMI_TRUE;
            }
            cbm_deregister_app_id(app_id);
        }

        if (acct_info_changed)
        {
            srv_email_acct_edit(acctHandle, acctInfoP);
            srv_email_acct_save(acctHandle);
        }
        srv_email_acct_destroy(acctHandle);
    }
    mmi_frm_temp_free(acctInfoP);
}

void VappEmailAcct::sysInit(void)
{
    srv_email_register_app_id_query_callback(
        0,
        &VappEmailAcct::queryAppInfoBySrv);

    readData(&globalSettingData);

    checkAndReviseDataAcctId();

    registerDataAcctDelHandler();
}

void VappEmailAcct::getAppInfo(EMAIL_ACCT_ID acct_id,
                               MMI_BOOL isIncoming,
                               VfxU32 da_index,
                               U16 *strId,
                               U16 *iconId)
{
    VfxU32 index;
    const vapp_email_appinfo_map_struct *appInfoP;

    index = (acct_id - VAPP_EMAIL_MIN_VLIAD_ACCT_ID) * 4 +
            da_index + (isIncoming ? 2 : 0);

    appInfoP = &(VappEmailAcct::appInfoArr[index]);
    *strId = appInfoP->str_id;
    *iconId = appInfoP->icon_id;
}

VfxBool VappEmailAcct::initMiscInfo(EMAIL_ACCT_ID account_id)
{
    mmi_email_app_core_result_enum appCoreRes = MMI_EMAIL_SUCCESS;

    /* save signature info */
    appCoreRes = mmi_email_sig_create(account_id);
    if (appCoreRes == MMI_EMAIL_ACCOUNT_ALREADY_EXIST)
    {
        // if exist, delete it, try again
        appCoreRes = mmi_email_sig_delete_acct(account_id, MMI_TRUE);
        VEMAIL_TRC_SIG_DELETE(appCoreRes);
        
        appCoreRes = mmi_email_sig_create(account_id);
    }
    if (appCoreRes != MMI_EMAIL_SUCCESS)
    {
        VEMAIL_TRC_SIG_CREATE(appCoreRes);
        return VFX_FALSE;
    }

    /* save auto check info */
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    appCoreRes = mmi_email_auto_check_create(account_id);
    if (appCoreRes == MMI_EMAIL_ACCOUNT_ALREADY_EXIST)
    {
        // if exist, delete it, try again
        appCoreRes = mmi_email_auto_check_delete_acct(account_id, MMI_TRUE);
        VEMAIL_TRC_AUTO_CHK_DELETE(appCoreRes);
        
        appCoreRes = mmi_email_auto_check_create(account_id);
    }
    if (MMI_EMAIL_SUCCESS != appCoreRes)
    {
        VEMAIL_TRC_AUTO_CHK_CREATE(appCoreRes);
        appCoreRes = mmi_email_sig_delete_acct(account_id, MMI_TRUE);
        return VFX_FALSE;
    }

    mmi_email_auto_check_time_segment time_segment;

    time_segment.start_time = VAPP_EMAIL_CHECK_INTERVAL_DAY_START_TIME;
    time_segment.stop_time = VAPP_EMAIL_CHECK_INTERVAL_DAY_END_TIME;
    time_segment.interval = 0;

    S32 count;
    for (count = VAPP_EMAIL_CHECK_INTERVAL_DAY_BEGIN; 
         count <= VAPP_EMAIL_CHECK_INTERVAL_DAY_END; 
         count++)
    {
        appCoreRes = mmi_email_auto_check_add_segment(
                        account_id, 
                        (U16)count, 
                        &time_segment);        
        if (appCoreRes != MMI_EMAIL_SUCCESS)
        {
            VEMAIL_TRC_AUTO_CHK_ADD(appCoreRes);
            return VFX_FALSE;
        }

        appCoreRes = mmi_email_auto_check_set_day_enable(
                        account_id, 
                        (U16)count, 
                        MMI_FALSE);
        if (appCoreRes != MMI_EMAIL_SUCCESS)
        {
            VEMAIL_TRC_AUTO_CHK_SET(appCoreRes);
            return VFX_FALSE;
        }
    }
    
    appCoreRes = mmi_email_auto_check_stop(account_id);
    if (appCoreRes != MMI_EMAIL_SUCCESS)
    {
        VEMAIL_TRC_AUTO_CHK_STOP(appCoreRes);
        return VFX_FALSE;  
    }
#endif

    return VFX_TRUE;
}


MMI_BOOL VappEmailAcct::queryAppInfoBySrv(
    srv_email_app_info_query_struct *appInfoP,
    U16 *str_id,
    U16 *icon_id)
{
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_1;
    srv_dtcnt_get_sim_preference(&sim_type);

    cbm_app_info_struct app_info;
    VfxU32 da_index = (sim_type == SRV_DTCNT_SIM_TYPE_1 ? 0 : 1);
    VappEmailAcct::getAppInfo(appInfoP->acct_id,
        appInfoP->is_incoming,
        da_index,
        &app_info.app_str_id, 
        &app_info.app_icon_id);

	 if(appInfoP->app_id == 0)
	 {
        U8 app_id = CBM_INVALID_APP_ID;
        app_info.app_type = DTCNT_APPTYPE_EMAIL;
        VfxS32 ret = cbm_register_app_id_with_app_info(&app_info, &app_id);
		if (ret != CBM_OK)
		{
                    VEMAIL_TRC_ACCT_CBM_REGISTER_FAIL(ret);
	            return MMI_FALSE;
		}

		U32 nwk_acct_id = cbm_set_app_id(appInfoP->dataacct_id, app_id);
		VappDtcntAcctValidTypeEnum valid_type = vapp_dtcnt_acct_is_valid(
                                                    nwk_acct_id, MMI_FALSE);
		cbm_deregister_app_id(app_id);

		if (valid_type == DTCNT_ACCT_VALID_NONE)
		{
                    VEMAIL_TRC_DTCNT_IS_VALID(valid_type);
		    return MMI_FALSE;
		}
	 }

    *str_id = app_info.app_str_id;
    *icon_id = app_info.app_icon_id;

    return MMI_TRUE;
}

EMAIL_MSG_PRIO VappEmailAcct::getPriority(void)
{
    return globalSettingData.priority;
}

VfxBool VappEmailAcct::getAlwaysShowCcBcc(void)
{
    return globalSettingData.showCcBcc;
}

VfxBool VappEmailAcct::getGlobalSaveSentEmails(EMAIL_ACCT_ID id)
{
    return globalSettingData.saveSentEmails[id - VAPP_EMAIL_MIN_VLIAD_ACCT_ID];
}

void VappEmailAcct::setPriority(EMAIL_MSG_PRIO prio)
{
    globalSettingData.priority = prio;
    resetData(&globalSettingData);
}

void VappEmailAcct::setAlwaysShowCcBcc(VfxBool show)
{
    globalSettingData.showCcBcc = show;
    resetData(&globalSettingData);
}

void VappEmailAcct::setGlobalSaveSendEmails(VfxBool save, EMAIL_ACCT_ID id)
{
    globalSettingData.saveSentEmails[id - VAPP_EMAIL_MIN_VLIAD_ACCT_ID] = save;
    resetData(&globalSettingData);
}

void VappEmailAcct::readData(VappEmailGlobalSettingStruct* data)
{
    VfxWString path;
    VfxS32 ret;
    U32 readWrite;

    memset(data, 0, sizeof(VappEmailGlobalSettingStruct));
    
    path.format(
        "%s%s",
        srv_email_get_root_path(),
        VAPP_EMAIL_GLOBAL_SETTING_NAME);

    FS_HANDLE hd = FS_Open((WCHAR*)path.getBuf(), FS_READ_ONLY);
    if (hd < FS_NO_ERROR)
    {
        VEMAIL_TRC_GLB_SET_OPEN(hd);
        resetData(data);
        return;
    }
    ret = FS_Read(hd, data, sizeof(VappEmailGlobalSettingStruct), &readWrite);
    if (ret < FS_NO_ERROR || readWrite != sizeof(VappEmailGlobalSettingStruct))
    {
        VEMAIL_TRC_GLB_SET_READ(
            ret,
            readWrite,
            sizeof(VappEmailGlobalSettingStruct));
    }
    FS_Close(hd);
}

void VappEmailAcct::resetData(VappEmailGlobalSettingStruct* data)
{
    VfxWString path;
    S32 ret;
    U32 readWrite;

    path.format(
        "%s%s",
        srv_email_get_root_path(),
        VAPP_EMAIL_GLOBAL_SETTING_NAME);

    FS_HANDLE hd = FS_Open(
                    (WCHAR*)path.getBuf(),
                    (FS_READ_WRITE | FS_CREATE_ALWAYS));
    if (hd < FS_NO_ERROR)
    {
        VEMAIL_TRC_GLB_SET_OPEN(hd);
        return;
    }
    ret = FS_Write(hd, data, sizeof(VappEmailGlobalSettingStruct), &readWrite);
    if (ret < FS_NO_ERROR || sizeof(VappEmailGlobalSettingStruct) != readWrite)
    {
        VEMAIL_TRC_GLB_SET_WRITE(
            ret,
            readWrite,
            sizeof(VappEmailGlobalSettingStruct));
    }
    FS_Close(hd);
}

void VappEmailAcct::setAcctAttribute(srv_email_acct_info_struct *acctInfo)
{
    acctInfo->acct_attr = (0 | SRV_EMAIL_ACCT_ATTR_SMTP);

    acctInfo->acct_attr |= ((SRV_EMAIL_PROT_POP3 == acctInfo->protocol) ? 
            SRV_EMAIL_ACCT_ATTR_POP3 :SRV_EMAIL_ACCT_ATTR_IMAP4);
}

VfxBool VappEmailAcct::isAcctAddrExist(
           const VfxWChar* addr,
           EMAIL_ACCT_ID skipAcctId)
{
    EMAIL_ACCT_ID acctIds[MMI_EMAIL_MAX_ACCTS] = {0};
    srv_email_acct_info_cache_struct acctCache;
    U32 acctCnt = 0;

    VFX_ASSERT(addr != NULL);

    srv_email_acct_get_num(&acctCnt);

    if (acctCnt == 0)
    {
        return VFX_FALSE;
    }

    srv_email_acct_get_acct_id(0, (S32*)&acctCnt, &acctIds[0]);

    for (VfxU32 i = 0; i < acctCnt; ++i)
    {
        if (acctIds[i] == skipAcctId)
        {
            continue;
        }

        acctCache.acct_name[0] = 0;
        srv_email_acct_cache_get(acctIds[i], &acctCache);

        if (mmi_wcsicmp(acctCache.acct_addr, addr) == 0)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


void VappEmailAcct::getImap4Acct(EMAIL_ACCT_ID *imapAcct, VfxU32 &acctNum, VfxU32 maxAcctNum)
{
    EMAIL_ACCT_ID acctId[MMI_EMAIL_MAX_ACCTS];
    VfxU32 acctTotalCount;

    acctNum = 0;
    for (VfxU32 i = 0; i < maxAcctNum; ++i)
    {
        imapAcct[i] = EMAIL_ACCT_INVALID_ID;
    }

    srv_email_acct_get_num(&acctTotalCount);
    if (acctTotalCount == 0)
    {
        return;
    }

    if (acctTotalCount > maxAcctNum)
    {
       acctTotalCount =  maxAcctNum;
    }
    
    srv_email_acct_get_acct_id(
        0,
        (VfxS32*)&acctTotalCount,
        (EMAIL_ACCT_ID*)&acctId[0]);
    
    for (VfxU32 i = 0; i < acctTotalCount; ++i)
    {
        srv_email_acct_info_cache_struct acctCache;
        srv_email_acct_cache_get(acctId[i], &acctCache);
        
        if (acctCache.protocol == SRV_EMAIL_PROT_IMAP4)
        {
            imapAcct[acctNum++] = acctId[i];
        }
    }
}


