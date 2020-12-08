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
*  vapp_certman_if.cpp
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "stack_common.h"
#include "stack_msgs.h"
#include "vapp_certman_list_ui.h"
#include "vapp_certman_invalid_cert_ui.h"
#include "vapp_certman_util.h"
#include "vapp_certman_gprot.h"
#include "vapp_certman_privkey.h"
#include "GlobalResDef.h"
#include "vapp_certman_types.h"

#define theMaxNumofQuene 4

static MMI_BOOL vapp_certman_nmgr_notify_hdlr(mmi_scenario_id scen_id, void *arg);

VFX_IMPLEMENT_CLASS("VappCertmanSelectList", VappCertmanSelectList, VfxApp);

VfxU8 VappCertmanInterfaces::numOfQuene = 0;


/*---------------------invalid------------------------------------*/

void VappCertmanInterfaces::vapp_certman_invalid_certificates_ind(
    module_type src_mod,
    kal_bool action,
    kal_bool disable_install,
    VfxU32 error,
    VfxU16 mod_name,
    VfxWChar *cert_filename,
    VfxU32 trans_id)
{
    vapp_certman_invalid_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (vapp_certman_invalid_cert_ind_struct*) OslConstructDataPtr(sizeof(vapp_certman_invalid_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    data->disable_install_option = disable_install;
    data->error = error;
    data->mod_name = mod_name;
    mmi_ucs2cpy((CHAR*) data->cert_filename,(CHAR*)cert_filename);
    data->src_mod = src_mod;
    /* Send the response message. */
    VappCertmanUtilities::vapp_certman_send_msg_on_queue(
        src_mod,
        MOD_MMI,
        (void*)data,
        (msg_type)MSG_ID_MMI_CERTMAN_INVALID_CERT_IND);
}


VfxBool VappCertmanInterfaces::vapp_certman_invalid_cert_popup_isexist()
{
  return VappCertmanInvalidCert::is_popup_exist;
}



void VappCertmanInterfaces::vapp_certman_invalid_cert_hndlr(void *msg)
{
    vapp_certman_invalid_cert_ind_struct *invalid_certificate_ind = (vapp_certman_invalid_cert_ind_struct*) msg;

    if (invalid_certificate_ind->action == VAPP_CERTMAN_ACTION_OPEN)
    {

        U8* ctx;
        VFX_SYS_ALLOC_MEM(ctx, sizeof (vapp_certman_invalid_cert_ind_struct));
        memcpy(ctx, msg, sizeof(vapp_certman_invalid_cert_ind_struct));
        /* nmgr may delay, so need to copy */

        /* nmgr starts */
        VfxBool isShow =  mmi_frm_nmgr_notify_by_app(
          MMI_SCENARIO_ID_CERTMAN_INVALID_CERT,
          MMI_EVENT_DEFAULT,
          vapp_certman_nmgr_notify_hdlr,
          ctx);

		if(!isShow)
		{
          ++numOfQuene;
		}
		if(isQueneFull())
		{
		 VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_DENY, invalid_certificate_ind->trans_id, invalid_certificate_ind->src_mod);
		}

    }
    else if (invalid_certificate_ind->action == VAPP_CERTMAN_ACTION_CANCEL)
    {
        VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
        const VappCertmanIfMapItem item = map->get_by_trans_id(invalid_certificate_ind->trans_id);
        if (item.isvalid)
        {
            mmi_frm_group_close(item.app_handler);
        }
    }
    else
    {
        /* assert */
    }
}

/* nmgr */

MMI_BOOL vapp_certman_nmgr_notify_hdlr(mmi_scenario_id scen_id, void *msg)
{
    if(VappCertmanInterfaces::numOfQuene > 0)
    {
     --VappCertmanInterfaces::numOfQuene;
    }
    VappCertmanInvalidCert::ShowPopUp(msg);
    /* no need to free. Context used and released inside */
    return MMI_TRUE;
}


/*---------------------select user------------------------------------*/
void VappCertmanInterfaces::vapp_certman_select_user_certificates_ind(
    module_type src_mod,
    kal_bool action,
    kal_uint32 key_purpose,
    kal_uint8 pubkey_type_num,
    kal_uint8 *pubkey_types,
    kal_uint16 mod_name,
    kal_wchar *issuers_filename,
    kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_certman_select_user_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data =
        (vapp_certman_select_user_cert_ind_struct*)
        OslConstructDataPtr(sizeof(vapp_certman_select_user_cert_ind_struct));

    data->action = action;
    data->trans_id = trans_id;
    data->key_purpose = key_purpose;
    data->pubkey_type_num = pubkey_type_num;
    memcpy((CHAR*) data->pubkey_types, (CHAR*) pubkey_types, data->pubkey_type_num);
    data->mod_name = mod_name;
    mmi_ucs2cpy((CHAR*) data->issuer_filename, (CHAR*)issuers_filename);
    data->src_module = src_mod;
    VappCertmanUtilities::vapp_certman_send_msg_on_queue(
        src_mod,
        MOD_MMI,
        (void*)data,
        (msg_type)MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND);

}



void VappCertmanInterfaces::vapp_certman_select_user_certificates_ind_hndlr(void *msg)
{
    vapp_certman_select_user_cert_ind_struct *select_cert_ind_p = (vapp_certman_select_user_cert_ind_struct*)msg;
    if (select_cert_ind_p->action == VAPP_CERTMAN_ACTION_OPEN)
    {
        mmi_id temp = VfxAppLauncher::launch(
            VAPP_CERTMAN,                            // todo: use own app base
            VFX_OBJ_CLASS_INFO(VappCertmanSelectUserCertListApp),
            GRP_ID_ROOT,
            msg,
            sizeof(vapp_certman_select_user_cert_ind_struct)
            );

        VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
        map->add(select_cert_ind_p->trans_id, temp);
    }
    else if (select_cert_ind_p->action == VAPP_CERTMAN_ACTION_CANCEL)
    {
        VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
        VappCertmanIfMapItem item = map->get_by_trans_id(select_cert_ind_p->trans_id);
        if (item.isvalid)
        {
            VfxAppLauncher::terminate(item.app_handler);
        }
        /* ifmap cleaned up inside destructor. so no need to free here */
    }
    else
    {

    }
}


/*--------------------------------------------select------------------------------------------------*/
void VappCertmanInterfaces::vapp_certman_select_certificates_ind(module_type src_mod,
                                                                 vapp_certman_action_enum action,
                                                                 kal_bool multiple_selection_flag,
                                                                 VfxU32 trans_id,
                                                                 VfxResId title,
                                                                 vapp_certman_cert_group_enum cert_group,
                                                                 kal_uint32 key_type)
{
    vapp_certman_select_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /*            Code Body                                           */
    /*----------------------------------------------------------------*/
    data = (vapp_certman_select_cert_ind_struct*) OslConstructDataPtr(sizeof(vapp_certman_select_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    data->multiple_selection_flag = multiple_selection_flag;
    data->cert_group = cert_group;
    data->key_type = key_type;
    data->title = title;
    data->source_mod = src_mod;
    VappCertmanUtilities::vapp_certman_send_msg_on_queue(
        src_mod,
        MOD_MMI,
        (void*)data,
        (msg_type)MSG_ID_MMI_CERTMAN_SELECT_CERT_IND);
}





void VappCertmanInterfaces::vapp_certman_select_certificates_ind_hndlr(void *msg)
{
    vapp_certman_select_cert_ind_struct *select_cert_ind_p = (vapp_certman_select_cert_ind_struct*)msg;
    if (select_cert_ind_p->action == VAPP_CERTMAN_ACTION_OPEN)
    {


		 mmi_id temp = VfxAppLauncher::launch(
            VAPP_CERTMAN,                            // todo: use own app base
            VFX_OBJ_CLASS_INFO(VappCertmanSelectList),
            GRP_ID_ROOT,
            msg,
            sizeof(vapp_certman_select_cert_ind_struct)
            );

	 

    }
    else if (select_cert_ind_p->action == VAPP_CERTMAN_ACTION_CANCEL)
    {
        VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
        VappCertmanIfMapItem item = map->get_by_trans_id(select_cert_ind_p->trans_id);
        if (item.isvalid)
        {
            VfxAppLauncher::terminate(item.app_handler);
        }
    }
    else
    {

    }
}


void VappCertmanInterfaces::vapp_certman_privkey_passwd_ind_hndlr(void* msg)
{
    certman_privkey_usage_password_ind_struct *privkey_usage_password
        = (certman_privkey_usage_password_ind_struct*) msg;
    if (privkey_usage_password->state == CERTMAN_PWDAUTH_FIRST)
    {
        mmi_id temp = VfxAppLauncher::launch(
            VAPP_CERTMAN,                            // todo: use own app base
            VFX_OBJ_CLASS_INFO(VappCertmanPrivKeyPasswd),
            GRP_ID_ROOT,
            msg,
            sizeof(certman_privkey_usage_password_ind_struct)
            );
        VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
        map->add(privkey_usage_password->trans_id, temp);
    }
    else
    {
        VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
        VappCertmanIfMapItem item = map->get_by_trans_id(privkey_usage_password->trans_id);
        VfxApp* app = VfxApp::getObject(item.app_handler);
        ((VappCertmanPrivKeyPasswd*)app)->retry(msg);
    }
}


void VappCertmanInterfaces::vapp_certman_privkey_cnf_ind_hndlr(void* msg)
{
    VappCertmanPrivKeyCnf *app;
    VFX_SYS_NEW_EX(app, VappCertmanPrivKeyCnf, (msg));
    app->show_priv_key_dialog();
    /* don't need to remember context */
}


VfxBool VappCertmanInterfaces::isQueneFull()
{
  if(numOfQuene > theMaxNumofQuene)
  	{
      return VFX_TRUE;
  }
  return VFX_FALSE;

}

#ifdef __OCSP_SUPPORT__
void vapp_certman_send_ocsp_settings(VfxU8* url)
{
    certman_ocsp_set_config(KAL_TRUE, KAL_FALSE, (S8*)url);
}
#endif /*__OCSP_SUPPORT__*/


extern "C" void mmi_certman_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VappCertmanUtilities::vapp_certman_set_protocol_events();
#ifdef __OCSP_SUPPORT__
    vapp_certman_send_ocsp_settings(NULL);
    certman_ocsp_set_default_id((U16)STR_GLOBAL_0, (U16)IMG_GLOBAL_OPTIONS);
#endif /*__OCSP_SUPPORT__*/
}




#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
