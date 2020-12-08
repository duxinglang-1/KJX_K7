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
*  vapp_certman_invalid_cert_ui.cpp
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
#include "vapp_certman_invalid_cert_ui.h"
#include "vapp_certman_util.h"
#include "vapp_certman_gprot.h"
#include "mmi_rp_vapp_certman_def.h"
#include "vcp_global_popup.h"
#include "GlobalResDef.h"
#include "certManAgentSrvGprot.h"
#include "notificationgprot.h"
//#include "CertManMMIGprots.h"


VFX_IMPLEMENT_CLASS("VappCertmanInvalidCert", VappCertmanInvalidCert, VfxApp) ;


extern "C" srv_certman_error_enum srv_certman_import_file (S32 *job_id, const U16 *filename,
						srv_certman_import_cert_cb import_cert_cb);

typedef void (*srv_certman_import_cert_cb)(S32 job_id, srv_certman_error_enum status, U8* label, srv_certman_dcs_enum dcs_label, U32 cert_id);

VfxBool VappCertmanInvalidCert::is_popup_exist = VFX_FALSE;

VappCertmanInvalidCert::~VappCertmanInvalidCert(void)
{
    U8* post_data1;
    VfxBool *post_data2;
    VFX_SYS_ALLOC_MEM(post_data1, sizeof (vapp_certman_invalid_cert_ind_struct));
    VFX_SYS_ALLOC_MEM(post_data2, sizeof(VfxBool));
    memcpy(post_data1, &invalid_cert_ind, sizeof(vapp_certman_invalid_cert_ind_struct));
    *post_data2 = is_close_by_back;
    postInvoke(ClosePostfunc, post_data1, post_data2);
    VappCertmanIfMapList *interface_map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
    interface_map->remove_by_apphandler(getGroupId());

}


void VappCertmanInvalidCert::ClosePostfunc(void *arg1, void *arg2, void *arg3)
{
    if ((arg2)&&((*(VfxBool*)arg2) == VFX_TRUE))
    {
        VappCertmanInvalidCert::ShowPopUp(arg1);
    }
    else
    {
        /* details screen being closed without back press
           so send response */
        vapp_certman_invalid_cert_ind_struct *temp = (vapp_certman_invalid_cert_ind_struct*)arg1;
        VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_DENY, temp->trans_id, temp->src_mod);
        VFX_SYS_FREE_MEM(arg1);
    }
    /* no need to free arg1. used and freed inside ShowPopUp */
    VFX_SYS_FREE_MEM(arg2);
}

void VappCertmanInvalidCert::PostInvokePopup2(void *arg1, void *arg2, void *arg3)
{
	mmi_frm_nmgr_notify_by_app(
          MMI_SCENARIO_ID_CERTMAN_INVALID_CERT,
          MMI_EVENT_DEFAULT,
          (mmi_noti_scrn_func_ptr)&VappCertmanInvalidCert::ShowPopUp2,
          arg1);
           
}


VfxBool VappCertmanInvalidCert::ShowPopUp2(mmi_scenario_id scen_id, void* msg)
{
    vapp_certman_invalid_cert_ind_struct* temp = (vapp_certman_invalid_cert_ind_struct*)msg;
    VappCertmanIfMapList *interface_map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
    interface_map->remove_by_transid(temp->trans_id);

    mmi_id grp_id = vcp_global_popup_show_confirm_two_button_id(
                        GRP_ID_ROOT,
                        VCP_POPUP_TYPE_QUESTION,
                        STR_ID_VAPP_CERTMAN_WARN_ACCEPT_ALWAYS,
                        STR_ID_VAPP_CERTMAN_CONTINUE,
                        STR_GLOBAL_CANCEL,
                        VCP_POPUP_BUTTON_TYPE_NORMAL,
                        VCP_POPUP_BUTTON_TYPE_CANCEL,
                        VappCertmanInvalidCert::PopUpCallBack,
                        msg
                        );
    if(!(interface_map->add(temp->trans_id, grp_id)))
	{
		VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_DENY, temp->trans_id, temp->src_mod);
	}
	return VFX_TRUE;
}

void VappCertmanInvalidCert::ShowPopUp(void* msg)
{
    VfxS32 temp;
	is_popup_exist = VFX_TRUE;
    temp = vcp_global_popup_show_command_create_id(GRP_ID_ROOT, STR_ID_VAPP_CERTMAN_WARN_VALIDITY, VappCertmanInvalidCert::PopUpCallBack, msg);
    vcp_global_popup_show_command_add_id(temp, ACCEPT_THIS_TIME_BUTTON_ID, STR_ID_VAPP_CERTMAN_ACCEPT_CERT_THIS_TIME, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_id(temp, ACCEPT_PERMANENTLY_BUTTON_ID, STR_ID_VAPP_CERTMAN_ACCEPT_CERT, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_id(temp, CERT_DETAILS_BUTTON_ID, STR_ID_VAPP_CERTMAN_CERTIFICATE_DETAILS, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_id(temp, CANCEL_BUTTON_ID, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
    vcp_global_popup_show_command_show_id(temp);

    vapp_certman_invalid_cert_ind_struct* invalid_certificate_ind = (vapp_certman_invalid_cert_ind_struct*)msg;
    VappCertmanIfMapList *interface_map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
    if(!(interface_map->add(invalid_certificate_ind->trans_id, temp)))
    {
		VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_DENY, invalid_certificate_ind->trans_id, invalid_certificate_ind->src_mod);
	}

	
}

void VappCertmanInvalidCert::PopUpCallBack(VfxId id, void *userData)
{
    vapp_certman_invalid_cert_ind_struct* temp = (vapp_certman_invalid_cert_ind_struct*)userData;
    VappCertmanIfMapList *interface_map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
	is_popup_exist = VFX_FALSE;
    switch(id)
    {
    case ACCEPT_THIS_TIME_BUTTON_ID:
        {
            VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_ACCEPT, temp->trans_id, temp->src_mod);
            interface_map->remove_by_transid(temp->trans_id);
            VFX_SYS_FREE_MEM(userData);
            break;
        }
    case ACCEPT_PERMANENTLY_BUTTON_ID:
        {
            postInvoke(PostInvokePopup2, userData);
        }
        break;
    case CERT_DETAILS_BUTTON_ID:
        {
            /* now launch app to show cert details*/
			 mmi_frm_nmgr_notify_by_app(
          MMI_SCENARIO_ID_CERTMAN_INVALID_CERT,
          MMI_EVENT_DEFAULT,
          (mmi_noti_scrn_func_ptr)&VappCertmanInvalidCert::launch_invalid_certman_app,
          userData);

        }
        break;
    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VfxS32 job_id;
            srv_certman_import_file (&job_id, temp->cert_filename,
                VappCertmanInvalidCert::agent_callbak_func);
            
            VappCertmanServiceMapList* service_map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
            service_map->add(job_id, userData, NULL);

            interface_map->remove_by_transid(temp->trans_id);
        }
        break;
    case CANCEL_BUTTON_ID:
    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
    case VCP_POPUP_BUTTON_NO_PRESSED:
    case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
        {
            VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_DENY, temp->trans_id, temp->src_mod);
            interface_map->remove_by_transid(temp->trans_id);
            VFX_SYS_FREE_MEM(userData);
        }
        break;
    }
}


VfxBool VappCertmanInvalidCert::launch_invalid_certman_app(mmi_scenario_id scen_id,void *userData)
{
    vapp_certman_invalid_cert_ind_struct* temp = (vapp_certman_invalid_cert_ind_struct*)userData;
    VappCertmanIfMapList *interface_map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
	
	mmi_id grp_id = VfxAppLauncher::launch(
				   VAPP_CERTMAN,							// todo: use own app base
				   VFX_OBJ_CLASS_INFO(VappCertmanInvalidCert),
				   GRP_ID_ROOT,
				   userData,
				   sizeof(vapp_certman_invalid_cert_ind_struct)
				   );
			   
   mmi_frm_asm_property_struct p;
   mmi_frm_asm_get_property(grp_id, &p);
   p.f_hide_in_oom = 1;   
   mmi_frm_asm_set_property(grp_id, &p);
	
   /* optimize */
   interface_map->remove_by_transid(temp->trans_id);
   if(!(interface_map->add(temp->trans_id, grp_id)))
   	{     
	   VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_DENY, temp->trans_id, temp->src_mod);
   }
   VFX_SYS_FREE_MEM(userData);

   return VFX_TRUE;


}


void VappCertmanInvalidCert::agent_callbak_func(S32 job_id, srv_certman_error_enum status, U8* label, srv_certman_dcs_enum dcs_label, U32 cert_id)
{
    VappCertmanServiceMapList* service_map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    const VappCertmanServiceMapItem &service_map_item = service_map->get_by_trans_id(job_id);
    vapp_certman_invalid_cert_ind_struct *temp = (vapp_certman_invalid_cert_ind_struct*)(service_map_item.msghndlr_obj);

    VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VAPP_CERTMAN_INVALID_CERT_INSTALL, temp->trans_id, temp->src_mod);
    service_map->remove_by_transid(job_id);
    VFX_SYS_FREE_MEM(temp);
}


void VappCertmanInvalidCert::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    vapp_certman_invalid_cert_ind_struct *temp_invalid_certificate_ind = (vapp_certman_invalid_cert_ind_struct*) args;
    memcpy(&invalid_cert_ind, temp_invalid_certificate_ind, sizeof(vapp_certman_invalid_cert_ind_struct));

    is_close_by_back = VFX_FALSE;
    VappCertmanCertInvalidCertScr *scr;
    VFX_OBJ_CREATE_EX (scr, VappCertmanCertInvalidCertScr, this, (args));
    scr->show();
}


VfxBool VappCertmanInvalidCert::onScrBack(VfxAppScr *scr)
{
    is_close_by_back = VFX_TRUE;
    return VFX_TRUE;
}

VappCertmanCertInvalidCertScr::VappCertmanCertInvalidCertScr(void* msg):
file_data(((vapp_certman_invalid_cert_ind_struct*) msg)->cert_filename, this)
{
    VfxU32 error = file_data.get_data_pre_func();
    if (error == CERTMAN_ERR_NONE)
    {
        file_data.get_data_post_func();
    }
    else
    {
        VfxAppLauncher::terminate(getApp()->getGroupId());
    }
}


void VappCertmanCertInvalidCertScr::VappCertmanDataRspHndlr(void* msg)
{
    VappCertmanInvalidDetailsPage *details_page;
    VFX_OBJ_CREATE_EX(details_page, VappCertmanInvalidDetailsPage, this, (file_data.cert_ref_ids[0], file_data.job_id));
    pushPage(CERT_DETAILS_PAGE, details_page);
}


VappCertmanInvalidDetailsPage::VappCertmanInvalidDetailsPage(VfxU32 cert_id, VfxU32 job_id):
VappCertmanDetailsPage(job_id, cert_id)
{

}


void VappCertmanInvalidCert::vapp_certman_invalid_certificates_rsp(VfxU16 invalid_cert_action, VfxU32 trans_id, module_type src_mod)
{
    vapp_certman_invalid_cert_rsp_struct *data;

    data = (vapp_certman_invalid_cert_rsp_struct*) OslConstructDataPtr(sizeof(vapp_certman_invalid_cert_rsp_struct));
    data->invalid_cert_action = invalid_cert_action;
    if (invalid_cert_action == VAPP_CERTMAN_INVALID_CERT_DENY)
    {
        data->result = VFX_FALSE;
    }
    else
    {
        data->result = VFX_TRUE;
    }
    data->trans_id = trans_id;
    /* Send the response message. */
    VappCertmanUtilities::vapp_certman_send_msg_on_queue(
        MOD_MMI,
        src_mod,
        (void*)data,
        (msg_type)MSG_ID_MMI_CERTMAN_INVALID_CERT_RSP);  /* todo: check type cast */
}


/*--------------------------------------rotation----------------------------------*/
void VappCertmanCertInvalidCertScr::onQueryRotateEx(
     VfxScreenRotateParam &param
    )
{
}


void VappCertmanInvalidDetailsPage::onQueryRotateEx(
     VfxScreenRotateParam &param
    )
{
}


#endif /* __COSMOS_MMI__ */
#endif /* __CERTMAN_SUPPORT__ */
