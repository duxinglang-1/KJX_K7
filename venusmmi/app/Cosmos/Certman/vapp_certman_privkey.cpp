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
*  vapp_certman_privkey.cpp
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
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
 * removed!
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vapp_certman_privkey.h"
#include "mmi_rp_vapp_certman_def.h"
#include "GlobalResDef.h"
#include "vcp_global_popup.h"
#include "vapp_certman_util.h"


VFX_IMPLEMENT_CLASS("VappCertmanPrivKeyPasswd", VappCertmanPrivKeyPasswd, VfxApp);

/*---------------------------------------------------------------------------*/

VappCertmanPrivKeyCnf::VappCertmanPrivKeyCnf(void* msg)
{
    memcpy(&ind, msg, sizeof(certman_privkey_usage_confirm_ind_struct));
}

void VappCertmanPrivKeyCnf::show_priv_key_dialog(void)
{
        mmi_frm_nmgr_notify_by_app(
          MMI_SCENARIO_ID_DEFAULT,
          MMI_EVENT_DEFAULT,
          VappCertmanPrivKeyCnf::nmgr_notify_hdlr,
          this);
}


MMI_BOOL VappCertmanPrivKeyCnf::nmgr_notify_hdlr(mmi_scenario_id scen_id, void *userData)
{
    VappCertmanPrivKeyCnf* temp = (VappCertmanPrivKeyCnf*)userData;
    VfxWString text;

    text += VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_PRIV_KEY_CONFIRMATION);

    vcp_global_popup_show_confirm_two_button_str(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_QUESTION, 
        text, 
        VfxWString(STR_GLOBAL_YES),
        VfxWString(STR_GLOBAL_NO),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VappCertmanPrivKeyCnf::popup_callback,
        userData
        );

    return MMI_TRUE;
}


void VappCertmanPrivKeyCnf::popup_callback(VfxId id, void *userData)
{
    VappCertmanPrivKeyCnf* temp = (VappCertmanPrivKeyCnf*)userData;
    switch(id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
            temp->send_rsp(MMI_TRUE);
            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        case VCP_POPUP_BUTTON_NO_PRESSED:
            temp->send_rsp(MMI_FALSE);
            break;
        default:
            break;
    }
    VFX_SYS_DELETE(temp);
}

void VappCertmanPrivKeyCnf::send_rsp(VfxU32 result)
{
    certman_send_privkey_usage_confirm_rsp(MOD_MMI, ind.trans_id, result);
}

/*---------------------------------------------------------------------------*/

void VappCertmanPrivKeyPasswd::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    certman_privkey_usage_password_ind_struct* temp_privkey_pass_ind = (certman_privkey_usage_password_ind_struct*)args;
    memcpy(&privkey_usage_password_ind, temp_privkey_pass_ind, sizeof(certman_privkey_usage_password_ind_struct));
    VFX_OBJ_CREATE_EX(scr, VappCertmanPrivKeyPasswdScr, this, (&privkey_usage_password_ind));
    scr->show();
}

void VappCertmanPrivKeyPasswd::retry(void* args)
{
    certman_privkey_usage_password_ind_struct* temp_privkey_pass_ind = (certman_privkey_usage_password_ind_struct*)args;
    memcpy(&privkey_usage_password_ind, temp_privkey_pass_ind, sizeof(certman_privkey_usage_password_ind_struct));
    scr->retry(args);
}

VappCertmanPrivKeyPasswd::~VappCertmanPrivKeyPasswd(void)
{
    VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
    map->remove_by_apphandler(getGroupId());
}


VappCertmanPrivKeyPasswdScr::VappCertmanPrivKeyPasswdScr(void* p)
{
    privkey_usage_password_ind_p = (certman_privkey_usage_password_ind_struct*)p;
    result = VFX_FALSE;
}


VappCertmanPrivKeyPasswdScr::~VappCertmanPrivKeyPasswdScr(void)
{
    certman_send_privkey_usage_password_rsp(MOD_MMI, privkey_usage_password_ind_p->trans_id, result);
}


void VappCertmanPrivKeyPasswdScr::on1stReady(void)
{
    VfxMainScr::on1stReady();

    VfxWString title;
    
    if (privkey_usage_password_ind_p->dcs == CERTMAN_DCS_ASCII)
    {
        title.format("%s", privkey_usage_password_ind_p->label);
    }
    else
    {
        //title.format("%ls", privkey_usage_password_ind_p->label);
		title.loadFromMem((VfxWChar*)privkey_usage_password_ind_p->label);
    }

    VFX_OBJ_CREATE(m_inputPopup, VcpInputPopup, this);
    
    m_inputPopup->setTitle(VfxWString(title));
    m_inputPopup->setHintText(VfxWString(STR_ID_VAPP_CERTMAN_INPUT_PASSWORD));
    m_inputPopup->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    m_inputPopup->m_signalButtonClicked.connect(this, &VappCertmanPrivKeyPasswdScr::ipOnButtonClicked);
    m_inputPopup->show(VFX_TRUE);
}


void VappCertmanPrivKeyPasswdScr::ipOnButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    VfxWString inputText;
    switch (id)
    {
    case VCP_INPUT_POPUP_BTN_OK:
        {
            VfxU8 temp_string[CERTMAN_PASSWORD_SIZE];
            VfxU16 pwd_length;
            inputText = m_inputPopup->getText();
            const VfxWChar* passwd= inputText.getBuf();
            mmi_ucs2_to_asc((CHAR*) temp_string, (CHAR*) passwd);
            pwd_length = strlen((CHAR*) temp_string);
            privkey_usage_password_ind_p->pcb(
                privkey_usage_password_ind_p->trans_id,
                privkey_usage_password_ind_p->cert_id,
                temp_string,
                pwd_length);
            certman_send_privkey_usage_password_rsp(MOD_MMI, privkey_usage_password_ind_p->trans_id, MMI_TRUE);
        }
        break;
    case VCP_INPUT_POPUP_BTN_CANCEL:
        {
           VfxAppLauncher::terminate(getApp()->getGroupId());
        }
        break;
    }
}


void VappCertmanPrivKeyPasswdScr::retry(void* arg)
{
    privkey_usage_password_ind_p = (certman_privkey_usage_password_ind_struct*)arg;
    switch(privkey_usage_password_ind_p->state)
    {
    case CERTMAN_PWDAUTH_FAILED_RETRY_AGAIN:
        {
            m_inputPopup->setErrorText(VfxWString(STR_ID_VAPP_CERTMAN_INPUT_PASS_AGAIN));
        }
        break;
    case CERTMAN_PWDAUTH_FAILED_ABORT:
        {
            /* remove input popup and fail */
            VFX_OBJ_CLOSE(m_inputPopup);
            result = VFX_FALSE;
            VfxAppLauncher::terminate(getApp()->getGroupId());
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_SUCCESS, (WCHAR*)vfxSysResGetStr(STR_GLOBAL_FAILED));
        }
        break;
    case CERTMAN_PWDAUTH_SUCCEEDED:
        {
            /* remove input popup and done*/
            VFX_OBJ_CLOSE(m_inputPopup);
            result = VFX_TRUE;
            VfxAppLauncher::terminate(getApp()->getGroupId());
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_SUCCESS, (WCHAR*)vfxSysResGetStr(STR_GLOBAL_OK));
        }
        break;
    }
}

#endif /* __COSMOS_MMI_PACKAGE__   */
#endif /* __CERTMAN_SUPPORT__ */
