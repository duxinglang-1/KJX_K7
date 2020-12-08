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
*  vapp_certman_data.cpp
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 
#include "vapp_certman_cfg.h"
#include "vapp_certman_data.h"
#include "vapp_certman_util.h"
#include "mmi_rp_vapp_certman_def.h"
#include "mmi_include.h"

/*----------------------------------CERT FILE DATA-------------------------------------*/

VappCertmanCertFileData::VappCertmanCertFileData(VfxWChar* filename, VappCertmanDataUser* data_user_obj)
{
    memcpy(this->filename, filename, VAPP_CERTMAN_MAX_FILE_PATH_LENGTH);
    this->data_user_obj = data_user_obj;
    msghndlr.set_user_obj(this);
    state = 0;
}

VfxU32 VappCertmanCertFileData::get_data_pre_func(void)
{
    VfxU32 error = msghndlr.verify_file_before_parse(filename, encoding_type);
    if (error != CERTMAN_ERR_NONE)
    {
        return error;
    }
    if (encoding_type == CERTMAN_ENC_PK12)
    {
        return CERTMAN_ERR_NEED_PASSWORD;
    }
    return CERTMAN_ERR_NONE;
}


VfxU32 VappCertmanCertFileData::get_data_set_passwd(const VfxWChar* password)
{
    /*  */
    VfxU8 temp[CERTMAN_PASSWORD_SIZE];
    mmi_ucs2_to_asc((CHAR*) temp, (CHAR*)password);
    return msghndlr.set_file_decrypt_password(temp);
}


void VappCertmanCertFileData::get_data_post_func(void)
{
    msghndlr.parse_begin_req();
}


void VappCertmanCertFileData::VappCertmanGenericRspHndlr(void* msg)
{
    certman_parse_begin_cnf_struct *parsed_begin_cnf_p = (certman_parse_begin_cnf_struct*) msg;

    if (parsed_begin_cnf_p->status != CERTMAN_ERR_NONE)
    {
        data_user_obj->VappCertmanDataRspHndlr(&parsed_begin_cnf_p->status);
        return ;
    }

    job_id = parsed_begin_cnf_p->job_id;

    cert_total = parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_count;

    //VFX_ASSERT(cert_total <= CERTMAN_NUM_PARSED_CERT);

    num_priv_key = parsed_begin_cnf_p->num_private_key;

    num_auth_cert = parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ROOTCA].cert_count +
        parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_OTHERCA].cert_count;

    num_user_cert = parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_OTHERUSER].cert_count +
        parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_PERSONAL].cert_count;

    for (VfxU32 temp_count = 0; temp_count < cert_total; temp_count++)
    {
        cert_ref_ids[temp_count] = parsed_begin_cnf_p->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_ref_ids[temp_count];
    }

    state |= PARSE_BEGIN_CNF_RECIEVED;

    data_user_obj->VappCertmanDataRspHndlr(&parsed_begin_cnf_p->status);
    msghndlr.setmore(0);
}


VappCertmanCertFileData::~VappCertmanCertFileData(void)
{
    if (state & PARSE_BEGIN_CNF_RECIEVED)
    {
        msghndlr.send_parse_end_req(job_id);
    }
}

/*----------------------------------CERT DETAILS DATA-------------------------------------*/

VappCertmanCertDetailsData::VappCertmanCertDetailsData(VfxU32 param1, VappCertmanDataUser *param3)
{
    cert_id = param1;
    use_job_id = 0;
    data_user_obj = param3;

    /* fingers crossed */
    msghndlr.set_user_obj(this);
    getdetails();
    state = 0;
    display_p=NULL;
    parsed_data_p=NULL;
}


VappCertmanCertDetailsData::VappCertmanCertDetailsData(VfxU32 param1, VfxU32 param2, VappCertmanDataUser *param3)
{
    job_id = param1;
    cert_id = param2;
    use_job_id = 1;
    data_user_obj = param3;

    msghndlr.set_user_obj(this);
    getdetails();
    state = 0;
    display_p=NULL;
    parsed_data_p=NULL;
}


void VappCertmanCertDetailsData::getdetails(void)
{
    if (use_job_id)
    {
        msghndlr.get_parse_details_req(cert_id, job_id);
    }
    else
    {
        msghndlr.get_cert_details_by_id(cert_id);
    }
}


void VappCertmanCertDetailsData::VappCertmanGenericRspHndlr(void* msg)
{
    if (use_job_id)
    {
        parse_cert_details_struct_func(msg);
    }
    else
    {
        parse_cert_details_by_id_struct_func(msg);
    }
}


void VappCertmanCertDetailsData::parse_cert_details_by_id_struct_func(void* msg)
{
    certman_get_cert_disp_by_id_cnf_struct*disp_cnf = (certman_get_cert_disp_by_id_cnf_struct*)msg;

    /* 20071108 Sanity Test Fail Tmp Patch */
    /* todo: copied from old certman. check */
    display_p = (certman_cert_display_struct*)get_ctrl_buffer(sizeof(certman_cert_display_struct));
    /* free this in constructor */

    state |= CERT_PARSED_DATA_RECIEVED;

    kal_mem_cpy(
        display_p,
        &(disp_cnf->cert),
        sizeof(certman_cert_display_struct));

    // notify user
    VfxU32 err = CERTMAN_ERR_NONE;
    data_user_obj->VappCertmanDataRspHndlr(&err);
    msghndlr.setmore(0);
}


void VappCertmanCertDetailsData::parse_cert_details_struct_func(void *msg)
{
    certman_parse_cert_detail_cnf_struct* cert_detail_p = (certman_parse_cert_detail_cnf_struct*)msg;
    
    VfxU32 err = cert_detail_p->status;

    if (err!= CERTMAN_ERR_NONE)
    {
        data_user_obj->VappCertmanDataRspHndlr(&err);
        return ;
    }

    state |= CERT_PARSED_DATA_RECIEVED;

    parsed_data_p = cert_detail_p->parsed_data;

    cert_group = cert_detail_p->parsed_data->cert_group;
    data_user_obj->VappCertmanDataRspHndlr(&err);
    msghndlr.setmore(0);
}


const certman_cert_display_struct *VappCertmanCertDetailsData::GetDisplayStruct(void)
{
    if (use_job_id)
    {
        return &(parsed_data_p->cert);
    }
    else
    {
        return display_p;
    }
}


VappCertmanCertDetailsData::~VappCertmanCertDetailsData(void)
{
    if (state & CERT_PARSED_DATA_RECIEVED)
    {
        if (!use_job_id)
        {
            certman_cert_display_content_free(display_p);

            /* todo: copied from old certman. check */
            free_ctrl_buffer(display_p);
        }
        else
        {
            certman_parsed_data_free(parsed_data_p);
        }
    }
}


VfxU8* VappCertmanCertDetailsData::getlabel(void)
{
    return parsed_data_p->cert.label;
}


VfxU32 VappCertmanCertDetailsData::getkeypurpose(void)
{
    return parsed_data_p->key_purposes;
}

VfxU32 VappCertmanCertDetailsData::getcertid(void)
{
    return cert_id;
}

VfxU32 VappCertmanCertDetailsData::getjobid(void)
{
    return job_id;
}

VfxBool VappCertmanCertDetailsData::IsPersonalCert(void)
{
    return (cert_group == CERTMAN_CERTGRP_PERSONAL);
}

VfxU8* VappCertmanCertDetailsData::getsubject(void)
{
    return (VfxU8*)&parsed_data_p->cert.subject;
}

VfxBool VappCertmanCertDetailsData::AlreadyExists(void)
{
    if ((use_job_id)&&(parsed_data_p !=NULL))
    {
        return (parsed_data_p->cert_exists == 1);
    }
    return VFX_FALSE;
}


/*---------------------------------------------------------------------------*/


VappCertmanCertDetailsInputData::VappCertmanCertDetailsInputData(VfxU32 key_purpose, VfxU32 key_purpose_all)
{
    this->keyusage = key_purpose;
    this->keyusage_all = key_purpose_all;
}

VfxWChar* VappCertmanCertDetailsInputData::getlabel(void)
{
    return (VfxWChar*)label;
}

void VappCertmanCertDetailsInputData::set_label(VfxU8* label)
{
    mmi_ucs2cpy(
        (CHAR*) this->label,
        (CHAR*) label);
}


VfxU32 VappCertmanCertDetailsInputData::getallkeyusage(void)
{
    return keyusage_all;
}


void VappCertmanCertDetailsInputData::set_key_protection_method(certman_privkey_protection_enum protection_method)
{
    this->keyprotection =  protection_method;
}

void VappCertmanCertDetailsInputData::set_key_protection_password(VfxU8* password)
{
    mmi_ucs2cpy((CHAR*) this->key_protection_passwd, (CHAR*) password);
}


void VappCertmanCertDetailsInputData::set_key_protection(certman_privkey_protection_enum protection_method, VfxU8* password)
{
    this->keyprotection =  protection_method;

    /* todo: relook type casts */
    mmi_ucs2cpy((CHAR*) this->key_protection_passwd, (CHAR*) password);
}

VfxU8* VappCertmanCertDetailsInputData::getpasswd(void)
{
    return key_protection_passwd;
}

VfxU32 VappCertmanCertDetailsInputData::getkeyprotection(void)
{
    return keyprotection;
}

/* list data */
VappCertmanCertListData::VappCertmanCertListData(VfxU32 cert_group, VfxU32 key_type, VappCertmanDataUser *data_user_obj)
{
    this->cert_group = cert_group;
    this->key_type = key_type;
    certificate_count = 0;
    this->data_user_obj = data_user_obj;
    msghndlr.set_user_obj(this);
    this->get_by_issue_file = VFX_FALSE;
    getlist();
} 

VappCertmanCertListData::VappCertmanCertListData(VfxU32 key_purpose, VfxU32 cert_group, 
                                                 VfxU32 *pubkey_types, VfxU32 pubkey_type_num,
                                                 VfxWChar *issuer_filename, VappCertmanDataUser* data_user_obj)
{
    this->key_purpose = key_purpose;
    this->cert_group = cert_group;
    certificate_count = 0;
    this->data_user_obj = data_user_obj;
    msghndlr.set_user_obj(this);
    for (VfxU32 i =0;i<pubkey_type_num; i++)
    {
        this->pubkey_types[i] = pubkey_types[i];
    }
    this->pubkey_type_num = pubkey_type_num;
    mmi_ucs2cpy((VfxChar*)this->issuer_filename, (const VfxChar*)issuer_filename);
    this->get_by_issue_file = VFX_TRUE;
    this->state = REQ_STATE;
    getlistbyissuerfile();
}

void VappCertmanCertListData::getlistbyissuerfile(void)
{
    msghndlr.get_cert_list_by_issuers_file_req(cert_group,key_purpose, pubkey_types, pubkey_type_num, issuer_filename);
}

void VappCertmanCertListData::getlist(void)
{
    msghndlr.get_cert_list_by_group(cert_group, key_type);
}


VfxU32 VappCertmanCertListData::get_cert_count(void) const
{
    return certificate_count;
}

void VappCertmanCertListData::VappCertmanGenericRspHndlr(void* msg)
{
    if (get_by_issue_file)
    {
        cert_list_by_issue_file_cnf(msg);
    }
    else
    {
        cert_list_by_group_cnf_hndlr(msg);
        certman_get_cert_list_by_group_cnf_struct *group_cnf = (certman_get_cert_list_by_group_cnf_struct *)msg;
    }
}


VappCertmanCertListDataItem* VappCertmanCertListData::get_cert_list_item(VfxU32 index)const
{
    return &certificate_list_item[index];
}

void VappCertmanCertListData::updatelist(void)
{
    msghndlr.get_cert_list_by_group(cert_group, key_type);
}


void VappCertmanCertListData::finishgetlist(void)
{
    VfxU32 err = CERTMAN_ERR_NONE;
    data_user_obj->VappCertmanDataRspHndlr(&err);
}

void VappCertmanCertListData::refresh(void)
{
    certificate_count = 0;
    getlist();
}

void VappCertmanCertListData::cert_list_by_group_cnf_hndlr(void* msg)
{
    certman_get_cert_list_by_group_cnf_struct *group_cnf = (certman_get_cert_list_by_group_cnf_struct *)msg;

    for (int count = 0; count < group_cnf->size; count++)
    {
        if (certificate_count >= VAPP_CERTMAN_CERTIFICATES_MAX)
        {
            //VFX_ASSERT(0);
            break;
        }


        certificate_list_item[certificate_count].cert_id = group_cnf->cert_list[count].id;

        certificate_list_item[certificate_count].cert_group = group_cnf->cert_list[count].group;

        certificate_list_item[certificate_count].key_purpose = group_cnf->cert_list[count].key_purpose_allowed;        

        certificate_list_item[certificate_count].key_purpose_all = group_cnf->cert_list[count].key_purpose_all;

        certificate_list_item[certificate_count].cert_prop = group_cnf->cert_list[count].properties;

        certificate_list_item[certificate_count].certificate_dcs = group_cnf->cert_list[count].dcs;  

        certificate_list_item[certificate_count].not_before = group_cnf->cert_list[count].not_before;

        certificate_list_item[certificate_count].not_after = group_cnf->cert_list[count].not_after;

        memcpy(
            certificate_list_item[certificate_count].cert_label,
            group_cnf->cert_list[count].label,
            CERTMAN_LABEL_SIZE);

        certificate_count++;
    }

    msghndlr.setmore(group_cnf->more);
    
    if (group_cnf->more > 0)
    {
        updatelist();
    }
    else
    {
        finishgetlist();
    }
}


void VappCertmanCertListData::cert_list_by_issue_file_cnf(void* msg)
{
    switch(state)
    {
    case REQ_STATE:
        {
            certman_get_cert_list_by_issuers_file_cnf_struct *cert_list =
                (certman_get_cert_list_by_issuers_file_cnf_struct*) msg;
            if (cert_list->status != CERTMAN_ERR_NONE)
            {
                /* error handling */
            }
            else
            {
                if (cert_list->num_certs == 0)
                {
                    certificate_count = 0;
                    finishgetlist();
                }
                else
                {
                    state = DATA_STATE;
                }
            }
        }
        break;
    case DATA_STATE:
        {
            certman_get_cert_list_by_issuers_data_ind_struct *issuer_data_ind = (certman_get_cert_list_by_issuers_data_ind_struct *)msg;

            for (int count = 0; count < VAPP_CERTMAN_NUM_CERT_IN_LIST; count++)
            {
                if (certificate_count >= VAPP_CERTMAN_CERTIFICATES_MAX)
                {
                    //VFX_ASSERT(0);
                    break;
                }


                certificate_list_item[certificate_count].cert_id = issuer_data_ind->cert_list[count].id;

                certificate_list_item[certificate_count].cert_group = issuer_data_ind->cert_list[count].group;

                certificate_list_item[certificate_count].key_purpose = issuer_data_ind->cert_list[count].key_purpose_allowed;        

                certificate_list_item[certificate_count].key_purpose_all = issuer_data_ind->cert_list[count].key_purpose_all;

                certificate_list_item[certificate_count].cert_prop = issuer_data_ind->cert_list[count].properties;

                certificate_list_item[certificate_count].certificate_dcs = issuer_data_ind->cert_list[count].dcs;  

                memcpy(
                    certificate_list_item[certificate_count].cert_label,
                    issuer_data_ind->cert_list[count].label,
                    CERTMAN_LABEL_SIZE);

                certificate_count++;
            }

            if (issuer_data_ind->last == 1)
            {
                finishgetlist();
            }
        }
    }
}

VappCertmanCertListDataItem::VappCertmanCertListDataItem(void) : selected(VFX_FALSE)
{}

VfxU8* VappCertmanCertListDataItem:: getcertlabel(void)
{
    return cert_label;
}


VfxU32 VappCertmanCertListDataItem:: getcertid(void)
{
    return cert_id;
}


VfxU32 VappCertmanCertListDataItem::getcertprop(void)
{
    return cert_prop;
}

VfxU32 VappCertmanCertListDataItem::getcertgroup(void)
{
    return cert_group;
}

VfxU32 VappCertmanCertListDataItem::getdcs(void)
{
    return certificate_dcs;
}

VfxU32 VappCertmanCertListDataItem::getkeypurpose(void)
{
    return key_purpose;
}


void VappCertmanCertListDataItem::toggle_select(void)
{
    selected = selected?VFX_FALSE:VFX_TRUE;
}


VfxBool VappCertmanCertListDataItem::is_selected(void) const
{
    return selected;
}


applib_time_struct VappCertmanCertListDataItem::getnotbefore(void)
{
    return not_before;
}


applib_time_struct VappCertmanCertListDataItem::getnotafter(void)
{
    return not_after;
}


VappCertmanKeyUsageListData::VappCertmanKeyUsageListData(VfxU32 key_purpose_all, VfxU32 key_purpose) : msghndlr(this)
{
    this->key_purpose_all = key_purpose_all;
    this->key_purpose = key_purpose;
    count_key_usages = 0;

    VfxU32 temp = 0x01;
    for (VfxU32 count = 0; count < VAPP_CERTMAN_TOTAL_KEY_USAGE; count++, temp <<= 1)
    {
        if ((key_purpose_all & temp) == temp)
        {
            all_key_usage_list[count_key_usages].loadFromRes(STR_ID_VAPP_CERTMAN_KP_ALL + 1 + count);
            if ((key_purpose & temp) == temp)
            {
                list_of_state[count_key_usages] = VFX_TRUE;
            }
            else
            {
                list_of_state[count_key_usages] = VFX_FALSE;
            }
            count_key_usages++;
        }
    }
}

void VappCertmanKeyUsageListData::VappCertmanCommitKeyUsageData(VfxU32 cert_id)
{
    msghndlr.update_key_purpose(cert_id, key_purpose_changed);
}


void VappCertmanKeyUsageListData::VappCertmanGenericRspHndlr(void* msg)
{

}

VfxU32 VappCertmanKeyUsageListData::get_key_usage_count(void) const
{
    return count_key_usages;
}


VfxWString& VappCertmanKeyUsageListData::get_all_key_usage_list_item(VfxU32 index)
{
    return all_key_usage_list[index];
}

/* req data objects */

VappCertmanReqDataBase::VappCertmanReqDataBase(VappCertmanDataUser *data_user_obj) : msghndlr(this)
{
    this->data_user_obj = data_user_obj;
}

VappCertmanDeleteReqData::VappCertmanDeleteReqData(VfxU32 cert_id, VappCertmanDataUser* data_user_obj) : VappCertmanReqDataBase(data_user_obj)
{
    msghndlr.delete_cert(cert_id);
    status = CERTMAN_ERR_NONE;
}


void VappCertmanDeleteReqData::VappCertmanGenericRspHndlr(void* msg)
{
    certman_delete_cert_cnf_struct *delete_cnf =  (certman_delete_cert_cnf_struct *)msg;
    status = delete_cnf->status;
    data_user_obj->VappCertmanDataRspHndlr(&status);
}

VappCertmanKeyUsageUpdateReqData::VappCertmanKeyUsageUpdateReqData(VfxU32 cert_id, VfxU32 key_purpose, VappCertmanDataUser* data_user_obj) : VappCertmanReqDataBase(data_user_obj)
{
    this->cert_id = cert_id;
    msghndlr.update_key_purpose(cert_id, key_purpose);
    status = CERTMAN_ERR_NONE;
}



VappCertmanKeyUsageUpdateReqData::VappCertmanKeyUsageUpdateReqData(VappCertmanDataUser *data_user_obj) : VappCertmanReqDataBase(data_user_obj)
{
}


void VappCertmanKeyUsageUpdateReqData::VappCertmanGenericRspHndlr(void* msg)
{
    certman_update_key_purpose_cnf_struct *purpose_cnf_p = (certman_update_key_purpose_cnf_struct *)msg;
    data_user_obj->VappCertmanDataRspHndlr(&(purpose_cnf_p->status));
}

void VappCertmanKeyUsageUpdateReqData::UpdateKeyUsage(VfxU32 cert_id, VfxU32 key_purpose)
{
    msghndlr.update_key_purpose(cert_id, key_purpose);
    status = CERTMAN_ERR_NONE;
}


VappCertmanImportReqData::VappCertmanImportReqData(VappCertmanDataUser *data_user_obj) : VappCertmanReqDataBase(data_user_obj)
{

}


U32 VappCertmanImportReqData::new_import_begin(VfxU32 cert_id, VfxU32 job_id)
{
    return msghndlr.new_import_begin(cert_id, job_id);
}


U32 VappCertmanImportReqData::new_import_set_label(VfxU8* label, certman_dcs_enum dcs_type)
{
    return msghndlr.new_import_set_label(label, dcs_type);
}


U32 VappCertmanImportReqData::new_import_set_priv_key_protection(certman_privkey_protection_enum protection_method, VfxU8* password)
{
    return msghndlr.new_import_set_priv_key_protection(protection_method, password);
}


void VappCertmanImportReqData::new_import_req(void)
{
    msghndlr.new_import_req();
}


void VappCertmanImportReqData::VappCertmanGenericRspHndlr(void* msg)
{
    //certman_import_cnf_struct *import_cnf_p = (certman_import_cnf_struct *)msg;
    data_user_obj->VappCertmanDataRspHndlr(msg);
}
#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
