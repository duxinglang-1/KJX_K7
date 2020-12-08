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
*  vapp_certman_msg_hndlr.cpp
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "stack_common.h"
#include "stack_msgs.h"
#include "vapp_certman_msg_hndlr.h"
#include "kal_release.h"
#include "kal_trace.h"
#include "vapp_certman_util.h"


void VappCertmanMsgHndlr::GenericCnfHndlr(void* msg)
{
    vapp_certman_generic_rsp_struct *temp = (vapp_certman_generic_rsp_struct*)msg;
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    const VappCertmanServiceMapItem& item = map->get_by_trans_id(temp->trans_id);

    if (item.isvalid == VFX_TRUE)
    {
        ((VappCertmanMsgHndlr*)(item.msghndlr_obj))->get_user_obj()->VappCertmanGenericRspHndlr(msg);
    }
    else if(item.fp!=NULL) 
    {
        item.fp(msg);
    }
    else
    {
        //ignore
    }
    map->remove_by_transid(temp->trans_id);
}

void VappCertmanMsgHndlr::free_ctx_parse(void)
{
    certman_ctx_parse_free(ctx_parse_p);
}


void VappCertmanMsgHndlr::free_ctx_import(void)
{
    certman_ctx_import_free(ctx_import_p);
}


void VappCertmanMsgHndlr::get_cert_list_by_group(VfxU32 cert_group, VfxU32 key_type)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF);

    /*-------just because certman task doesn't support pointer as user data-------- */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_get_cert_list_by_group_req(
        MOD_MMI,
        new_trans_id,
        cert_group,
        CERTMAN_KP_NONE,
        key_type,
        more);
}


void VappCertmanMsgHndlr::setmore(VfxS32 arg)
{
    more = arg;
}


void VappCertmanMsgHndlr::get_cert_details_by_id(VfxU32 cert_id)
{	
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF);

    /*--------------just because certman task doesn't support pointer as user data */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_get_cert_disp_by_id_req(
        MOD_MMI,
        new_trans_id,
        cert_id);
}


void VappCertmanMsgHndlr::update_key_purpose(VfxU32 cert_id, VfxU32 key_purpose)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_CNF);

    /*--------------just because certman task doesn't support pointer as user data */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_update_key_purpose_req(MOD_MMI,
        new_trans_id,
        cert_id,
        key_purpose);

}


void VappCertmanMsgHndlr::get_cert_list_by_issuers_file(VfxU32 cert_group,
                                                        VfxU32 key_purpose,
                                                        VfxU8 pubkey_types[CERTMAN_NUM_KEYTYPE_IN_LIST],
                                                        VfxU8 num_types,
                                                        const VfxWChar *issuers_filename)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF);

    /*--------------just because certman task doesn't support pointer as user data */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_get_cert_list_by_issuers_file_req(MOD_MMI, new_trans_id,
        cert_group, key_purpose,
        pubkey_types, num_types,
        issuers_filename);
}


VfxU32 VappCertmanMsgHndlr::verify_file_before_parse(VfxWChar* filename_p, certman_encoding_enum &encoding_type)
{
    VfxU32 error;
    error = certman_parse_get_encoding_type_by_file((kal_wchar*) filename_p, &encoding_type);
    if (error!=CERTMAN_ERR_NONE)
    {
        return error;
    }

    error = certman_ctx_parse_new_by_file(filename_p, encoding_type, &ctx_parse_p);
    if (error == CERTMAN_ERR_NONE)
    {
        state |= PARSE_CTX_CREATED;
    }
    return error;
}


VfxU32 VappCertmanMsgHndlr::set_file_decrypt_password(VfxU8* password)
{
    return certman_parse_set_decrypt_password(ctx_parse_p, password);
}


void VappCertmanMsgHndlr::parse_begin_req(void)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_PARSE_BEGIN_CNF);

    /*--------------just because certman task doesn't support pointer as user data */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, VappCertmanMsgHndlr::send_parse_end_req_cleanup);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    /* use different response handler as ctx_parse_p has to be freed. ctx_parse_p is for certman task reference only
    Not for use in application. So made it a part of message handler */
    certman_send_parse_begin_req(
        MOD_MMI,
        new_trans_id,
        ctx_parse_p);
}


void VappCertmanMsgHndlr::get_parse_details_req(VfxU32 cert_id, VfxU32 job_id)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF);

    /*--------------just because certman task doesn't support pointer as user data */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this,VappCertmanMsgHndlr::parsed_data_free);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_parse_cert_detail_req(
        MOD_MMI,
        new_trans_id,
        job_id,
        cert_id);
}


VfxU32 VappCertmanMsgHndlr::new_import_begin(VfxU32 cert_id, VfxU32 job_id)
{
    certman_error_enum error = certman_ctx_import_new(job_id, cert_id, &ctx_import_p);
    if (error == CERTMAN_ERR_NONE)
    {
        state |= IMPORT_CTX_CREATED;
    }
    return error;
}


VfxU32 VappCertmanMsgHndlr::new_import_set_label(VfxU8* label, certman_dcs_enum dcs_type)
{
    return certman_import_set_label(ctx_import_p, label, dcs_type);
}


VfxU32 VappCertmanMsgHndlr::new_import_set_priv_key_protection(certman_privkey_protection_enum protection_method, VfxU8* password)
{
    return certman_import_set_privkey_protection(ctx_import_p, protection_method, password);
}


void VappCertmanMsgHndlr::new_import_req(void)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_IMPORT_CNF);

    /*--------------just because certman task doesn't support pointer as user data */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_import_req(
        MOD_MMI,
        new_trans_id,
        ctx_import_p);
}


void VappCertmanMsgHndlr::delete_cert(VfxU32 cert_id)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_DELETE_CERT_CNF);

    /*--------------just because certman task doesn't support pointer as user data */
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_delete_cert_req(MOD_MMI, new_trans_id, cert_id);
}


void VappCertmanMsgHndlr::send_parse_end_req(VfxU32 job_id)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_DELETE_CERT_CNF);

    /*-----Just because certman task doesn't support pointer as user data------*/
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_parse_end_req(MOD_MMI, new_trans_id, job_id);
}


void VappCertmanMsgHndlr::get_cert_list_by_issuers_file_req(VfxU32 cert_group, VfxU32 key_purpose, VfxU8 *pubkey_types, VfxU8 num_types, const VfxWChar *issuers_filename)
{
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF);
    SetProtocolEventHandler(VappCertmanMsgHndlr::GenericCnfHndlr, MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND);

    /*--------Just because certman task doesn't support pointer as user data-------*/
    VfxU32 new_trans_id = VappCertmanUtil::generate_new_trans_id();
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->add(new_trans_id, this, NULL);
    this->trans_id = new_trans_id;
    /*-----------------------------------------------------------------------------*/

    certman_send_get_cert_list_by_issuers_file_req(
        MOD_MMI,
        new_trans_id,
        cert_group,
        key_purpose,
        pubkey_types,
        num_types,
        issuers_filename);
}


void VappCertmanMsgHndlr::send_parse_end_req_cleanup(void* msg)
{
    certman_parse_begin_cnf_struct *parsed_begin_cnf_p = (certman_parse_begin_cnf_struct*) msg; 
    ClearProtocolEventHandler(MSG_ID_CERTMAN_PARSE_BEGIN_CNF);
    certman_send_parse_end_req(MOD_MMI, parsed_begin_cnf_p->trans_id, parsed_begin_cnf_p->job_id);
}


void VappCertmanMsgHndlr::parsed_data_free(void* msg)
{
    certman_parse_cert_detail_cnf_struct *cert_detail_p = (certman_parse_cert_detail_cnf_struct*) msg;
    certman_parsed_data_free(cert_detail_p->parsed_data);
}


VappCertmanMsgHndlr::VappCertmanMsgHndlr(VappCertmanMsgHndlrUser * obj)
{
    user_obj = obj;
    more = 0;
    state = 0;
}


VappCertmanMsgHndlrUser *VappCertmanMsgHndlr:: get_user_obj(void)
{
    return user_obj;
}


void VappCertmanMsgHndlr:: set_user_obj(VappCertmanMsgHndlrUser * obj)
{
    user_obj = obj;
}


VappCertmanMsgHndlr::VappCertmanMsgHndlr(void)
{
    more = 0;
    state = 0;
}


VappCertmanMsgHndlr::~VappCertmanMsgHndlr(void)
{
    if (state & PARSE_CTX_CREATED)
    {
        free_ctx_parse();
    }
    if (state & IMPORT_CTX_CREATED)
    {
        free_ctx_import();
    }
    VappCertmanServiceMapList* map = VFX_OBJ_GET_INSTANCE(VappCertmanServiceMapList);
    map->remove_by_transid(trans_id);
}

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
