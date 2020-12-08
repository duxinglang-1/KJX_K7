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
 *  Vapp_email_sso.cpp
 *
 * Project:
 * --------
 *  COSMOS Email SSO(Single Sign-on)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__

#ifdef __MMI_SSO__

extern "C" {
#include "Unicodexdcl.h"
#include "SsoSrvGprot.h"
}

#include "vcui_sso_gprot.h"
#include "Vapp_email_sso.h"
#include "Vapp_email_main.h"
#include "Vapp_email_acct.h"
#include "Vapp_email_util.h"

static EMAIL_ACCT_ID vapp_email_sso_acct_compare(WCHAR* cloudAcct);


static EMAIL_ACCT_ID vapp_email_get_cloud_acct(void)
{
    VfxU32 acctCnt = 0;
    EMAIL_ACCT_ID acctId;
    srv_email_acct_info_cache_struct acctInfo;
    EMAIL_ACCT_ID acctIdArray[MMI_EMAIL_MAX_ACCTS] = {0};

    srv_email_acct_get_num(&acctCnt);
    srv_email_acct_get_acct_id(0, (S32*)&acctCnt, acctIdArray);


    for (VfxU32 i = 0;i < acctCnt; i++)
    {
        acctId = acctIdArray[i];
        srv_email_acct_cache_get(acctId, &acctInfo);
        if (acctInfo.is_cloud_acct)
        {
            return acctId;
        }
    }

    return EMAIL_ACCT_INVALID_ID;
}


VfxBool vapp_email_is_cloud_acct(EMAIL_ACCT_ID acctId)
{
    srv_email_acct_info_cache_struct acctInfo;
    srv_email_acct_cache_get(acctId, &acctInfo);
    return (acctInfo.is_cloud_acct ? VFX_TRUE : VFX_FALSE);
}


WCHAR *vapp_email_sso_get_acct(void)
{
    srv_sso_provider_struct ssoProvider;
    srv_sso_account_struct ssoAcct;
    static WCHAR ssoAcctName[SRV_SSO_NAME_SIZE + 1];

    srv_sso_get_providers(&ssoProvider, 1);
    
    if (srv_sso_get_account_count(ssoProvider.provider, SRV_SSO_LOGIN_DONT_CARE) > 0)
    {
        srv_sso_get_accounts(ssoProvider.provider, SRV_SSO_LOGIN_DONT_CARE, &ssoAcct, 1);
        srv_sso_get_account_name(ssoProvider.provider, ssoAcct.account, ssoAcctName);

        //if (strchr(name, "@yahoo") != NULL)
        {
            return ssoAcctName;
        }
    }
    return NULL;
}


VfxBool vapp_email_sso_check_cloud_acct()
{
    WCHAR *ssoAcct;
    EMAIL_ACCT_ID emailCloudAcct = EMAIL_ACCT_INVALID_ID;

    ssoAcct = vapp_email_sso_get_acct();
    if (!vapp_email_util_chk_addr(ssoAcct))
    {
        return VFX_FALSE;
    }

    emailCloudAcct = vapp_email_get_cloud_acct();
    
    if (emailCloudAcct == EMAIL_ACCT_INVALID_ID)
    {
        if (ssoAcct == NULL)
        {
            return VFX_FALSE;
        }
        else
        {
            emailCloudAcct = vapp_email_sso_acct_compare(ssoAcct);
            if (emailCloudAcct == EMAIL_ACCT_INVALID_ID)
            {
                return MMI_TRUE;
            }
            else
            {
                // just set it as cloud 
                srv_email_acct_set_cloud_acct(emailCloudAcct, MMI_TRUE);
                return VFX_FALSE;
            }
        }
    }
    else //exist email cloud account
    {
        if (ssoAcct == NULL)
        {
            //set it as common email account
            srv_email_acct_set_cloud_acct(emailCloudAcct, MMI_FALSE);
            return VFX_FALSE;
        }
        else
        {
            if (emailCloudAcct == vapp_email_sso_acct_compare(ssoAcct))
            {
                return MMI_FALSE;
            }
            else //cloud account changed
            {
                srv_email_acct_set_cloud_acct(emailCloudAcct, MMI_FALSE);
                emailCloudAcct = vapp_email_sso_acct_compare(ssoAcct);
                if (emailCloudAcct == EMAIL_ACCT_INVALID_ID)
                {
                    return MMI_TRUE;
                }
                else
                {
                    srv_email_acct_set_cloud_acct(emailCloudAcct, MMI_TRUE);
                    return MMI_FALSE;
                }
            }            
        }
    }
}


static EMAIL_ACCT_ID vapp_email_sso_acct_compare(WCHAR* cloudAcct)
{
    VfxU32 acctCnt = 0;
    EMAIL_ACCT_ID acctId;
    srv_email_acct_info_cache_struct acctInfo;
    EMAIL_ACCT_ID acctIdArray[MMI_EMAIL_MAX_ACCTS] = {0};

    srv_email_acct_get_num(&acctCnt);
    srv_email_acct_get_acct_id(0, (S32*)&acctCnt, acctIdArray);

    for (VfxU32 i = 0;i < acctCnt; i++)
    {
        acctId = acctIdArray[i];
        srv_email_acct_cache_get(acctId, &acctInfo);
        if (mmi_wcsicmp(cloudAcct, acctInfo.acct_addr) == 0
            && acctInfo.protocol == SRV_EMAIL_PROT_IMAP4)
        {
            return acctId;
        }
    }
    
    return EMAIL_ACCT_INVALID_ID;
}



VfxBool vapp_email_sso_add_acct(WCHAR *cloudAcct)
{
    EMAIL_ACCT_HANDLE acctHandle = 0;
    srv_email_result_enum ret;
    EMAIL_ACCT_ID acctId;
    srv_email_acct_info_struct info;
    VfxResId errResId = STR_GLOBAL_ERROR;

    //init SSO account
    srv_email_acct_init_acct_info(&info);
    info.is_cloud_acct = MMI_TRUE;
    mmi_wcsncpy(info.email_addr.email_addr, cloudAcct, MMI_EMAIL_MAX_ADDR_LEN);
    mmi_wcsncpy(info.acct_name, cloudAcct, SRV_EMAIL_MAX_ACCT_NAME_LEN);
    info.protocol = SRV_EMAIL_PROT_IMAP4;

    do
    {
        ret = srv_email_acct_create(0, &acctHandle);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }

        ret = srv_email_acct_new(acctHandle, &acctId);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            errResId = vapp_email_util_get_err_code(ret, srv_email_errno_get());
            break;
        }
        info.acct_id = acctId;
        info.protocol = SRV_EMAIL_PROT_IMAP4;

        ret = srv_email_acct_edit(acctHandle, &info);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            errResId = vapp_email_util_get_err_code(ret, srv_email_errno_get());
            break;
        }

        ret = srv_email_acct_save(acctHandle);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            errResId = vapp_email_util_get_err_code(ret, srv_email_errno_get());
            break;
        }
        VappEmailAcct::initMiscInfo(acctId);        
    }while(0);

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
        acctHandle = 0;
    }

    if (ret == SRV_EMAIL_RESULT_SUCC)
    {
        return VFX_TRUE;
    }
    else
    {
        vapp_email_alert_cfm(errResId);
        srv_email_acct_destroy(acctHandle);
        return VFX_FALSE;
    }
}


static MMI_ID g_sso_cui = 0;
static srv_email_cloud_funcptr_type g_sso_cb = NULL;
static void* g_sso_user_data = NULL;

extern "C" {

static void send_result(MMI_BOOL result)
{
    if (g_sso_cui != 0)
    {
        vcui_sso_login_close(g_sso_cui);
        g_sso_cui = 0;
    }

    if (g_sso_cb != NULL)
    {
        g_sso_cb(result, g_sso_user_data);
        g_sso_cb = NULL;
        g_sso_user_data = NULL;
    }
}


mmi_ret vapp_email_sso_ind_hdlr(mmi_event_struct* para)
{
    srv_email_evt_cloud_ind_struct *evt = (srv_email_evt_cloud_ind_struct*)para;

    VfxApp *app = VfxAppLauncher::findApp(
        VAPP_EMAIL, 
        VFX_OBJ_CLASS_INFO(VappEmailApp), 
        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 
        0);
    
    if (app == NULL)
    {
        evt->callback(MMI_FALSE, evt->user_data);
        return MMI_RET_OK;
    }

    g_sso_cb = evt->callback;
    g_sso_user_data = evt->user_data;
    g_sso_cui = vcui_sso_login_create(app->getGroupId(), evt->provider_id, evt->cloud_acct_id);
    
    if (g_sso_cui == 0)
    {
        send_result(MMI_FALSE);
        return MMI_RET_OK;
    }

    vcui_sso_login_run(g_sso_cui);
    return MMI_RET_OK;
}


mmi_ret vapp_email_sso_login_done_hdlr(mmi_event_struct* para)
{
    vcui_sso_login_result_event_struct *e = (vcui_sso_login_result_event_struct*)para;

    if (e->result == VCUI_SSO_LOGIN_SUCCESS)
    {
        send_result(MMI_TRUE);
    }
    else
    {
        send_result(MMI_FALSE);
    }
    
    return MMI_RET_OK;
}

} /* extern "C" */

#endif /* __MMI_SSO__ */

#endif /* __MMI_EMAIL__ */

