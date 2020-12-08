/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *   certManAgentSrv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Wrapper over certman task to provide SDK APIs.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#include "mmi_include.h"
#include "certManAgentSrvGprot.h"
#include "certman_api.h"


#define SRV_CERTMAN_MAX_NUM_JOBS    4


typedef struct
{
    kal_uint8   job_id;
    kal_uint8   in_use;
    kal_uint32  trans_id;
    void*       fp_callback;
    kal_uint32  certman_job_id;
	union {
		srv_certman_pwd_cb pwd_cb;
		kal_uint32 ocsp_trans_id;
		kal_uint32 cert_ref_id;
	}u;
} srv_certman_job_struct;


static srv_certman_job_struct g_srv_certman_jobs[SRV_CERTMAN_MAX_NUM_JOBS] = {0};
static kal_uint32 g_srv_certman_trans_id = 0;

static srv_certman_job_struct* srv_certman_get_free_job()
{
    kal_int32 i;

    for(i = 0; i < SRV_CERTMAN_MAX_NUM_JOBS; i++)
    {
        if(g_srv_certman_jobs[i].in_use == 0)
        {
            g_srv_certman_jobs[i].job_id = i;
            return &g_srv_certman_jobs[i];
        }
    }
    return NULL;
}

static srv_certman_job_struct* srv_certman_find_job_by_trans_id(kal_uint32 trans_id)
{
    kal_int32 i;

    for(i = 0; i < SRV_CERTMAN_MAX_NUM_JOBS; i++)
    {
        if(g_srv_certman_jobs[i].trans_id == trans_id)
            return &g_srv_certman_jobs[i];
    }
    return NULL;
}

static srv_certman_job_struct* srv_certman_find_job_by_ocsp_trans_id(kal_uint32 ocsp_trans_id)
{
    kal_int32 i;

    for(i = 0; i < SRV_CERTMAN_MAX_NUM_JOBS; i++)
    {
        if(g_srv_certman_jobs[i].trans_id == 0 && g_srv_certman_jobs[i].u.ocsp_trans_id == ocsp_trans_id)
            return &g_srv_certman_jobs[i];
    }
    return NULL;
}

static srv_certman_job_struct* srv_certman_find_job_by_job_id(kal_int32 job_id)
{
    if(job_id < 0 || job_id >= SRV_CERTMAN_MAX_NUM_JOBS)
        return NULL;
    else
        return &g_srv_certman_jobs[job_id];
}

static kal_int32 srv_certman_get_job_id(srv_certman_job_struct* job)
{
    if(!job)
        return -1;
    return job->job_id;
}

static void srv_certman_job_new(srv_certman_job_struct* job, kal_uint32 trans_id, void* cb)
{
    job->in_use = 1;
    job->trans_id = trans_id;
    job->fp_callback = cb;
}

static void srv_certman_job_modify_trans_id(srv_certman_job_struct* job, kal_uint32 trans_id)
{
	job->trans_id = trans_id;
}

static void srv_certman_job_modify_cb(srv_certman_job_struct* job, void* cb)
{
	job->fp_callback = cb;
}

static void srv_certman_job_modify_certman_job_id(srv_certman_job_struct* job, kal_uint32 certman_job_id)
{
	job->certman_job_id = certman_job_id;
}

static void srv_certman_job_modify_pwd_cb(srv_certman_job_struct* job, srv_certman_pwd_cb pwd_cb)
{
	job->u.pwd_cb = pwd_cb;
}

#ifdef __OCSP_SUPPORT__
static void srv_certman_job_modify_ocsp_trans_id(srv_certman_job_struct* job, kal_uint32 ocsp_trans_id)
{
	job->u.ocsp_trans_id = ocsp_trans_id;
}
#endif

static void srv_certman_job_delete(srv_certman_job_struct* job)
{
	memset(job, 0, sizeof(srv_certman_job_struct));
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void* srv_certman_job_get_cb(srv_certman_job_struct* job)
{
	return job->fp_callback;
}

static kal_uint32 srv_certman_job_get_certman_job_id(srv_certman_job_struct* job)
{
	return job->certman_job_id;
}

static srv_certman_pwd_cb srv_certman_job_get_pwd_cb(srv_certman_job_struct* job)
{
	return job->u.pwd_cb;
}

static kal_uint32 srv_certman_new_trans_id()
{
    g_srv_certman_trans_id++;

	if(g_srv_certman_trans_id == 0)
		g_srv_certman_trans_id++;

	return g_srv_certman_trans_id;
}

static srv_certman_error_enum srv_certman_convert_certman_error(certman_error_enum error)
{
    return (srv_certman_error_enum)error;
}

static void srv_certman_job_modify_cert_ref_id(srv_certman_job_struct* job, kal_uint32 cert_ref_id)
{
	job->u.cert_ref_id = cert_ref_id;
}

static kal_uint32 srv_certman_job_get_cert_ref_id(srv_certman_job_struct* job)
{
	return job->u.cert_ref_id;
}

static U8* srv_certman_suggest_label(certman_disp_name_struct* subject, certman_dcs_enum *dcs)
{
    //certman_disp_name_struct* subject = &(parsed_data_p->cert.subject);
    U8** names = ((certman_disp_name_struct*)subject)->names;
    certman_dcs_enum* dcs_type = ((certman_disp_name_struct*)subject)->dcs;

    if (names[CERTMAN_NAMETYPE_COMMON_NAME])
    {
        *dcs = dcs_type[CERTMAN_NAMETYPE_COMMON_NAME];
        return (U8*)names[CERTMAN_NAMETYPE_COMMON_NAME];
    }
    else if (names[CERTMAN_NAMETYPE_ORGANISATION])
    {
        *dcs = dcs_type[CERTMAN_NAMETYPE_ORGANISATION];
        return (U8*)names[CERTMAN_NAMETYPE_ORGANISATION];
    }
    else if (names[CERTMAN_NAMETYPE_ORGANISATION_UNIT])
    {
        *dcs = dcs_type[CERTMAN_NAMETYPE_ORGANISATION_UNIT];
        return (U8*)names[CERTMAN_NAMETYPE_ORGANISATION_UNIT];
    }
    else if (names[CERTMAN_NAMETYPE_TITLE])
    {
        *dcs = dcs_type[CERTMAN_NAMETYPE_TITLE];
        return (U8*)names[CERTMAN_NAMETYPE_TITLE];
    }
    else if (names[CERTMAN_NAMETYPE_GIVEN_NAME])
    {
        *dcs = dcs_type[CERTMAN_NAMETYPE_GIVEN_NAME];
        return (U8*)names[CERTMAN_NAMETYPE_GIVEN_NAME];
    }
    else
	{
        *dcs = CERTMAN_DCS_ASCII;
		return "Certificate";
	}
}


/********************Handlers*************************/
void  srv_certman_parse_begin_cnf_handler(void *msg) //MSG_ID_CERTMAN_PARSE_BEGIN_CNF/*(S32 job_id, srv_certman_error_enum status, U16 num_private_key, srv_certman_parsed_info_struct *parsed_info)*/
{
	certman_parse_begin_cnf_struct *parse_begin = (certman_parse_begin_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_error_enum status;
	srv_certman_parsed_info_struct *parsed_info;
	srv_certman_parsed_info_cb parsed_info_cb = NULL;

	job = srv_certman_find_job_by_trans_id(parse_begin->trans_id);

	if(job == NULL)
		return;

	parsed_info_cb = (srv_certman_parsed_info_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(parse_begin->status);

	if(parse_begin->status != CERTMAN_ERR_NONE)
	{
		parsed_info_cb(srv_certman_get_job_id(job), status, 0, NULL);
		srv_certman_job_delete(job);
		return;
	}

	srv_certman_job_modify_certman_job_id(job, parse_begin->job_id);

	parsed_info = (srv_certman_parsed_info_struct*)parse_begin->parsed_info;

	parsed_info_cb(srv_certman_get_job_id(job), status, parse_begin->num_private_key, parsed_info);
}


void srv_certman_parse_detail_cnf_handler(void *msg) //MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF //srv_certman_parsed_data_cb (S32 job_id, srv_certman_error_enum status, srv_certman_parsed_data_struct *parsed_data)
{
	certman_parse_cert_detail_cnf_struct *parse_detail = (certman_parse_cert_detail_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_error_enum status;
	srv_certman_parsed_data_struct *parsed_data;
	srv_certman_parsed_data_cb parsed_data_cb = NULL;

	job = srv_certman_find_job_by_trans_id(parse_detail->trans_id);

	if(job == NULL)
		return;

	parsed_data_cb = (srv_certman_parsed_data_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(parse_detail->status);

	if(parse_detail->status != CERTMAN_ERR_NONE)
	{
		parsed_data_cb(srv_certman_get_job_id(job), status, NULL);
		return;
	}

	parsed_data = (srv_certman_parsed_data_struct*)parse_detail->parsed_data;
	
	parsed_data_cb(srv_certman_get_job_id(job), status, parsed_data);

	certman_parsed_data_free(parse_detail->parsed_data);
}

void srv_certman_parse_end_cnf_handler(void *msg)//MSG_ID_CERTMAN_PARSE_END_CNF //srv_certman_parse_end_cb (S32 job_id, srv_certman_error_enum status)
{
	certman_parse_end_cnf_struct *parse_end = (certman_parse_end_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_parse_end_cb parse_end_cb = NULL;

	job = srv_certman_find_job_by_trans_id(parse_end->trans_id);

	if(job == NULL)
		return;

	parse_end_cb = (srv_certman_parse_end_cb)srv_certman_job_get_cb(job);

	parse_end_cb(srv_certman_get_job_id(job), srv_certman_convert_certman_error(parse_end->status));

	srv_certman_job_delete(job);
}

void srv_certman_import_cnf_handler(void *msg)
{
	certman_import_cnf_struct *import_cnf = (certman_import_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_import_cert_cb import_cert_cb = NULL;

	job = srv_certman_find_job_by_trans_id(import_cnf->trans_id);

	if(job == NULL)
		return;

	import_cert_cb = (srv_certman_import_cert_cb)srv_certman_job_get_cb(job);

	if(import_cnf->status != CERTMAN_ERR_NONE)
	{
		import_cert_cb(srv_certman_get_job_id(job), srv_certman_convert_certman_error(import_cnf->status), NULL, (srv_certman_dcs_enum)0, 0);
	}
        else{
	import_cert_cb(srv_certman_get_job_id(job), SRV_CERTMAN_ERR_NONE, import_cnf->label, (srv_certman_dcs_enum)import_cnf->dcs, import_cnf->cert_id);
}
}


void srv_certman_update_key_purpose_cnf_handler(void *msg)//srv_certman_update_key_purpose_cb(S32 job_id, srv_certman_error_enum status, U32 cert_id, srv_certman_keypurpose_enum key_purpose)
{
	certman_update_key_purpose_cnf_struct *kp_cnf = (certman_update_key_purpose_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_update_key_purpose_cb kp_cnf_cb = NULL;

	job = srv_certman_find_job_by_trans_id(kp_cnf->trans_id);

	if(job == NULL)
		return;

	kp_cnf_cb = (srv_certman_update_key_purpose_cb)srv_certman_job_get_cb(job);

	kp_cnf_cb(srv_certman_get_job_id(job), srv_certman_convert_certman_error(kp_cnf->status), kp_cnf->cert_id, (srv_certman_keypurpose_enum)kp_cnf->key_purpose);

	srv_certman_job_delete(job);
}

void srv_certman_cert_list_by_group_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF //srv_certman_list_by_grp_cb(S32 job_id, srv_certman_error_enum status, srv_certman_cert_list_by_group_struct *cert_list)
{
	certman_get_cert_list_by_group_cnf_struct *cert_list_bg = (certman_get_cert_list_by_group_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_error_enum status;
	srv_certman_cert_list_by_group_struct cert_list;
	srv_certman_list_by_grp_cb list_by_grp_cb = NULL;

	job = srv_certman_find_job_by_trans_id(cert_list_bg->trans_id);

	if(job == NULL)
		return;

	list_by_grp_cb = (srv_certman_list_by_grp_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(cert_list_bg->status);

	if(cert_list_bg->status != CERTMAN_ERR_NONE)
	{
		list_by_grp_cb(srv_certman_get_job_id(job), status, NULL);
		return;
	}

	cert_list.cert_group	= (srv_certman_cert_group_enum)cert_list_bg->cert_group;
	cert_list.key_purpose	= (srv_certman_keypurpose_enum)cert_list_bg->key_purpose;
	cert_list.pubkey_type	= (srv_certman_pubkey_type_enum)cert_list_bg->pubkey_type;
	memcpy(cert_list.cert_list, cert_list_bg->cert_list, sizeof(cert_list.cert_list));
	cert_list.size	= cert_list_bg->size;
	cert_list.more	= cert_list_bg->more;
	
	list_by_grp_cb(srv_certman_get_job_id(job), status, &cert_list);

	srv_certman_job_delete(job);
}

void srv_certman_cert_list_by_dmn_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF //srv_certman_list_by_dmn_cb(S32 job_id, srv_certman_error_enum status, srv_certman_cert_list_by_domain_struct *cert_list)
{
	certman_get_cert_list_by_domain_cnf_struct *cert_list_bd = (certman_get_cert_list_by_domain_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_error_enum status;
	srv_certman_cert_list_by_domain_struct cert_list;
	srv_certman_list_by_dmn_cb list_by_dmn_cb = NULL;

	job = srv_certman_find_job_by_trans_id(cert_list_bd->trans_id);

	if(job == NULL)
		return;

	list_by_dmn_cb = (srv_certman_list_by_dmn_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(cert_list_bd->status);

	if(cert_list_bd->status != CERTMAN_ERR_NONE)
	{
		list_by_dmn_cb(srv_certman_get_job_id(job), status, NULL);
		return;
	}

	cert_list.domain		= (srv_certman_domain_enum)cert_list_bd->domain;
	cert_list.key_purpose	= (srv_certman_keypurpose_enum)cert_list_bd->key_purpose;
	memcpy(cert_list.cert_list, cert_list_bd->cert_list, cert_list_bd->size*sizeof(certman_cert_list_elem_struct));
	cert_list.size	= cert_list_bd->size;
	cert_list.more	= cert_list_bd->more;
	
	list_by_dmn_cb(srv_certman_get_job_id(job), status, &cert_list);

	srv_certman_job_delete(job);
}

void srv_certman_cert_list_by_issuer_file_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF //srv_certman_list_by_issuer_data_cb(S32 job_id, srv_certman_error_enum status, U16 num_certs, srv_certman_cert_list_elem_struct *cert_lest, U32 cert_list_size, U8 last)
{
	certman_get_cert_list_by_issuers_file_cnf_struct *cert_list_by_issuers = (certman_get_cert_list_by_issuers_file_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_list_by_issuer_data_cb list_by_issuer_data_cb = NULL;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(cert_list_by_issuers->trans_id);

	if(job == NULL)
		return;

	list_by_issuer_data_cb = (srv_certman_list_by_issuer_data_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(cert_list_by_issuers->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		list_by_issuer_data_cb(srv_certman_get_job_id(job), status, 0, NULL, 0, 1);
		srv_certman_job_delete(job);
		return;
	}

	list_by_issuer_data_cb(srv_certman_get_job_id(job), status, cert_list_by_issuers->num_certs, NULL, 0, 0);
}

void srv_certman_cert_list_by_issuer_data_ind_handler(void *msg)//MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND
{
	certman_get_cert_list_by_issuers_data_ind_struct *cert_list_data = (certman_get_cert_list_by_issuers_data_ind_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_list_by_issuer_data_cb list_data_cb = NULL;

	job = srv_certman_find_job_by_trans_id(cert_list_data->trans_id);

	if(job == NULL)
		return;

	list_data_cb = (srv_certman_list_by_issuer_data_cb)srv_certman_job_get_cb(job);

	list_data_cb(srv_certman_get_job_id(job), SRV_CERTMAN_ERR_NONE, 0, (srv_certman_cert_list_elem_struct*)(cert_list_data->cert_list), cert_list_data->size, cert_list_data->last);

	if(cert_list_data->last)
		srv_certman_job_delete(job);
}

void srv_certman_cert_disp_by_id_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF //srv_certman_cert_disp_by_id_cb(S32 job_id, srv_certman_error_enum status, srv_certman_cert_disp_by_id_struct *cert_list)
{
	certman_get_cert_disp_by_id_cnf_struct *cert_disp_by_id = (certman_get_cert_disp_by_id_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_cert_disp_by_id_cb cert_disp_by_id_cb = NULL;
	srv_certman_cert_disp_by_id_struct cert_list;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(cert_disp_by_id->trans_id);

	if(job == NULL)
		return;

	cert_disp_by_id_cb = (srv_certman_cert_disp_by_id_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(cert_disp_by_id->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		cert_disp_by_id_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	cert_list.cert_id		=	cert_disp_by_id->cert_id;
	cert_list.key_purpose	=	(srv_certman_keypurpose_enum)cert_disp_by_id->key_purpose;
	memcpy(&cert_list.cert_info, &cert_disp_by_id->cert_info, sizeof(cert_list.cert_info));
	memcpy(&cert_list.cert, &cert_disp_by_id->cert, sizeof(cert_list.cert));
	cert_list.has_pubkey	=	cert_disp_by_id->has_pubkey;
	cert_list.pubkey_type	=	(srv_certman_pubkey_type_enum)cert_disp_by_id->pubkey_type;
	cert_list.pubkey.key	=	(srv_certman_pubkey_struct *)cert_disp_by_id->pubkey.key;

	cert_disp_by_id_cb(srv_certman_get_job_id(job), status, &cert_list);

	certman_cert_display_content_free(&(cert_disp_by_id->cert));
	srv_certman_job_delete(job);
}

void srv_certman_chain_disp_by_id_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_CERT_CHAIN_DISP_BY_ID_CNF //srv_certman_chain_disp_by_id_cb(S32 job_id, srv_certman_error_enum status, srv_certman_cert_chain_disp_by_id_struct *cert_list)
{
	certman_get_cert_chain_disp_by_id_cnf_struct *chain_disp_by_id = (certman_get_cert_chain_disp_by_id_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_chain_disp_by_id_cb chain_disp_by_id_cb = NULL;
	srv_certman_cert_chain_disp_by_id_struct cert_chain;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(chain_disp_by_id->trans_id);

	if(job == NULL)
		return;

	chain_disp_by_id_cb = (srv_certman_chain_disp_by_id_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(chain_disp_by_id->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		chain_disp_by_id_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	memcpy(cert_chain.labels, chain_disp_by_id->labels, sizeof(cert_chain.labels));
	memcpy(cert_chain.dcs, chain_disp_by_id->dcs, sizeof(cert_chain.dcs));
	cert_chain.size = chain_disp_by_id->size;

	chain_disp_by_id_cb(srv_certman_get_job_id(job), status, &cert_chain);

	srv_certman_job_delete(job);
}

void srv_certman_certid_by_group_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_CERTID_BY_GROUP_CNF srv_certman_ids_by_grp_cb(S32 job_id, srv_certman_error_enum status, srv_certman_certid_by_group_struct *cert_ids)
{
	certman_get_certid_by_group_cnf_struct *certid_by_group = (certman_get_certid_by_group_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_ids_by_grp_cb ids_by_grp_cb = NULL;
	srv_certman_certid_by_group_struct certid;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(certid_by_group->trans_id);

	if(job == NULL)
		return;

	ids_by_grp_cb = (srv_certman_ids_by_grp_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(certid_by_group->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		ids_by_grp_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	certid.cert_group	=	(srv_certman_cert_group_enum)certid_by_group->cert_group;
	certid.key_purpose	=	(srv_certman_keypurpose_enum)certid_by_group->key_purpose;
	memcpy(&certid.certids, &certid_by_group->certids, sizeof(certid.certids));
	certid.size			=	certid_by_group->size;
	certid.more			=	certid_by_group->more;

	ids_by_grp_cb(srv_certman_get_job_id(job), status, &certid);

	srv_certman_job_delete(job);
}

void srv_certman_certid_by_domain_cnf_handler(void *msg) //MSG_ID_CERTMAN_GET_CERTID_BY_DOMAIN_CNF srv_certman_ids_by_dmn_cb(S32 job_id, srv_certman_error_enum status, srv_certman_certid_by_domain_struct *cert_ids)
{
	certman_get_certid_by_domain_cnf_struct *certid_by_domain = (certman_get_certid_by_domain_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_ids_by_dmn_cb ids_by_gmn_cb = NULL;
	srv_certman_certid_by_domain_struct certids;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(certid_by_domain->trans_id);

	if(job == NULL)
		return;

	ids_by_gmn_cb = (srv_certman_ids_by_dmn_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(certid_by_domain->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		ids_by_gmn_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	certids.domain			=	(srv_certman_domain_enum)certid_by_domain->domain;
	certids.key_purpose		=	(srv_certman_keypurpose_enum)certid_by_domain->key_purpose;
	memcpy(&certids.certids, &certid_by_domain->certids, sizeof(certids.certids));
	certids.size			=	certid_by_domain->size;
	certids.more			=	certid_by_domain->more;

	ids_by_gmn_cb(srv_certman_get_job_id(job), status, &certids);

	srv_certman_job_delete(job);
}

void srv_certman_cert_by_id_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_CERT_BY_ID_CNF srv_certman_cert_by_id_cb(S32 job_id, srv_certman_error_enum status, srv_certman_cert_by_id_struct *cert)
{
	certman_get_cert_by_id_cnf_struct *cert_by_id = (certman_get_cert_by_id_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_cert_by_id_cb cert_by_id_cb = NULL;
	srv_certman_cert_by_id_struct cert;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(cert_by_id->trans_id);

	if(job == NULL)
		return;

	cert_by_id_cb = (srv_certman_cert_by_id_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(cert_by_id->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		cert_by_id_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	cert.cert_id = cert_by_id->cert_id;
	memcpy(cert.filename, cert_by_id->filename, sizeof(cert.filename));

	cert_by_id_cb(srv_certman_get_job_id(job), status, &cert);

	srv_certman_job_delete(job);
}

void srv_certman_trusted_cert_by_id_cnf_handler(void *msg) //MSG_ID_CERTMAN_GET_TRUSTED_CERT_BY_ID_CNF srv_certman_trstd_cert_by_id_cb(S32 job_id, srv_certman_error_enum status, srv_certman_trusted_cert_by_id_struct *cert)
{
	certman_get_trusted_cert_by_id_cnf_struct *trusted_cert_by_id = (certman_get_trusted_cert_by_id_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_trstd_cert_by_id_cb trstd_cert_by_id_cb = NULL;
	srv_certman_trusted_cert_by_id_struct trusted_cert;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(trusted_cert_by_id->trans_id);

	if(job == NULL)
		return;

	trstd_cert_by_id_cb = (srv_certman_trstd_cert_by_id_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(trusted_cert_by_id->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		trstd_cert_by_id_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	trusted_cert.cert_id = trusted_cert_by_id->cert_id;
	memcpy(trusted_cert.filename, trusted_cert_by_id->filename, sizeof(trusted_cert.filename));

	trstd_cert_by_id_cb(srv_certman_get_job_id(job), status, &trusted_cert);

	srv_certman_job_delete(job);
}


void srv_certman_cert_chain_cnf_handler(void *msg) //MSG_ID_CERTMAN_GET_CERT_CHAIN_CNF srv_certman_cert_chain_cb(S32 job_id, srv_certman_error_enum status, srv_certman_cert_chain_struct *cert_chain)
{
	certman_get_cert_chain_cnf_struct *cert_chain_cnf = (certman_get_cert_chain_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_cert_chain_cb cert_chain_cb = NULL;
	srv_certman_cert_chain_struct cert_chain;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(cert_chain_cnf->trans_id);

	if(job == NULL)
		return;

	cert_chain_cb = (srv_certman_cert_chain_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(cert_chain_cnf->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		cert_chain_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	cert_chain.num_certs = cert_chain_cnf->num_certs;
	cert_chain.cert_id = cert_chain_cnf->cert_id;
	memcpy(cert_chain.filename, cert_chain_cnf->filename, sizeof(cert_chain.filename));

	cert_chain_cb(srv_certman_get_job_id(job), status, &cert_chain);

	srv_certman_job_delete(job);
}

void srv_certman_pwd_cb_handler(kal_uint32 trans_id, kal_uint32 cert_id, const kal_uint8 *pwd, kal_uint32 size)// srv_certman_pwd_cb(S32 job_id, const U8 *pwd, U32 size)
{
	srv_certman_job_struct* job = NULL;
	srv_certman_pwd_cb pwd_cb = NULL;

	job = srv_certman_find_job_by_trans_id(trans_id);

	if(job == NULL)
		return;

	pwd_cb = srv_certman_job_get_pwd_cb(job);

	if(pwd_cb == NULL)
		return;

	pwd_cb(srv_certman_get_job_id(job), pwd, size);
}

void srv_certman_privkey_cnf_handler(void *msg)//MSG_ID_CERTMAN_GET_PRIVKEY_CNF srv_certman_priv_key_cb(S32 job_id, srv_certman_error_enum status, srv_certman_privkey_struct *priv_key)
{
	certman_get_privkey_cnf_struct *privkey_cnf = (certman_get_privkey_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_priv_key_cb priv_key_cb = NULL;
	srv_certman_privkey_struct privkey;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(privkey_cnf->trans_id);

	if(job == NULL)
		return;

	priv_key_cb = (srv_certman_priv_key_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(privkey_cnf->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		priv_key_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	privkey.cert_id = privkey_cnf->cert_id;
	memcpy(privkey.filename, privkey_cnf->filename, sizeof(privkey.filename));

	priv_key_cb(srv_certman_get_job_id(job), status, &privkey);

	srv_certman_job_delete(job);
}

void srv_certman_validate_cert_cnf_handler(void *msg) //MSG_ID_CERTMAN_VALIDATE_CNF srv_certman_val_result_cb(S32 job_id, srv_certman_error_enum status, srv_certman_validate_struct *val_result)
{
	certman_validate_cnf_struct *validate_cnf = (certman_validate_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_val_result_cb val_result_cb = NULL;
	srv_certman_validate_struct validate_result;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(validate_cnf->trans_id);

	if(job == NULL)
		return;

	val_result_cb = (srv_certman_val_result_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(validate_cnf->status);

	if(status != SRV_CERTMAN_ERR_NONE)
	{
		val_result_cb(srv_certman_get_job_id(job), status, NULL);
		srv_certman_job_delete(job);
		return;
	}

	memcpy(validate_result.trusted_cert.filename, validate_cnf->trusted_cert.filename, sizeof(validate_result.trusted_cert.filename));
	validate_result.trusted_cert.size = validate_cnf->trusted_cert.size;
	validate_result.trusted_cert.cert_id = validate_cnf->trusted_cert.cert_id;
	validate_result.has_trusted_cert = validate_cnf->has_trusted_cert;

	val_result_cb(srv_certman_get_job_id(job), status, &validate_result);

	srv_certman_job_delete(job);
}

void srv_certman_delete_cert_cnf_handler(void *msg) //MSG_ID_CERTMAN_DELETE_CERT_CNF srv_certman_status_cb(S32 job_id, srv_certman_error_enum status)
{
	certman_delete_cert_cnf_struct *delete_cert_cnf = (certman_delete_cert_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_status_cb status_cb = NULL;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(delete_cert_cnf->trans_id);

	if(job == NULL)
		return;

	status_cb = (srv_certman_status_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(delete_cert_cnf->status);

	status_cb(srv_certman_get_job_id(job), status);

	srv_certman_job_delete(job);
}

void srv_certman_delete_all_cert_cnf_handler(void *msg)//MSG_ID_CERTMAN_DELETE_ALL_CERT_CNF srv_certman_delete_status_cb(S32 job_id, srv_certman_error_enum status, srv_certman_cert_group_enum cert_group)
{
	certman_delete_all_cert_cnf_struct *delete_all_cert_cnf = (certman_delete_all_cert_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_delete_status_cb delete_status_cb = NULL;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_trans_id(delete_all_cert_cnf->trans_id);

	if(job == NULL)
		return;

	delete_status_cb = (srv_certman_delete_status_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(delete_all_cert_cnf->status);

	delete_status_cb(srv_certman_get_job_id(job), status, (srv_certman_cert_group_enum)delete_all_cert_cnf->cert_group);

	srv_certman_job_delete(job);
}

void srv_certman_ocsp_verify_cert_cnf_handler(void *msg)//MSG_ID_CERTMAN_OCSP_VERIFY_CERT_CNF srv_certman_status_cb(S32 job_id, srv_certman_error_enum status)
{
	certman_ocsp_verify_cert_cnf_struct *ocsp_verify_cert_cnf = (certman_ocsp_verify_cert_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_status_cb status_cb = NULL;
	srv_certman_error_enum status;

	job = srv_certman_find_job_by_ocsp_trans_id(ocsp_verify_cert_cnf->trans_id);

	if(job == NULL)
		return;

	status_cb = (srv_certman_status_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(ocsp_verify_cert_cnf->status);

	status_cb(srv_certman_get_job_id(job), status);

	srv_certman_job_delete(job);
}


void srv_certman_import_file_cnf_handler(void *msg)
{
	certman_import_cnf_struct *import_cnf = (certman_import_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_import_cert_cb import_cert_cb = NULL;

	job = srv_certman_find_job_by_trans_id(import_cnf->trans_id);

	if(job == NULL)
		return;

	import_cert_cb = (srv_certman_import_cert_cb)srv_certman_job_get_cb(job);

	if(import_cnf->status != CERTMAN_ERR_NONE)
	{
		import_cert_cb(srv_certman_get_job_id(job), srv_certman_convert_certman_error(import_cnf->status), NULL, (srv_certman_dcs_enum)0, 0);
	}
	else{
	import_cert_cb(srv_certman_get_job_id(job), SRV_CERTMAN_ERR_NONE, import_cnf->label, (srv_certman_dcs_enum)import_cnf->dcs, import_cnf->cert_id);
	}

	certman_send_parse_end_req(MOD_MMI, 0, srv_certman_job_get_certman_job_id(job));
	srv_certman_job_delete(job);
}

void srv_certman_parse_file_detail_cnf_handler(void *msg) //MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF //srv_certman_parsed_data_cb (S32 job_id, srv_certman_error_enum status, srv_certman_parsed_data_struct *parsed_data)
{
	certman_parse_cert_detail_cnf_struct *parse_detail = (certman_parse_cert_detail_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_error_enum status;
	srv_certman_parsed_data_struct *parsed_data;
	srv_certman_import_cert_cb import_cert_cb = NULL;
	U8 *label = NULL;
	certman_dcs_enum label_dcs;
	certman_ctx_import_struct *ctx_import = NULL;
	U32 cert_ref_id, certman_trans_id;
	S32 err;

	job = srv_certman_find_job_by_trans_id(parse_detail->trans_id);

	if(job == NULL)
		return;

	import_cert_cb = (srv_certman_import_cert_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(parse_detail->status);

	parsed_data = (srv_certman_parsed_data_struct*)parse_detail->parsed_data;

	if(parse_detail->status != CERTMAN_ERR_NONE)
	{
		import_cert_cb(srv_certman_get_job_id(job), status, NULL, (srv_certman_dcs_enum)0, 0);
		certman_send_parse_end_req(MOD_MMI, 0, srv_certman_job_get_certman_job_id(job));
		srv_certman_job_delete(job);
		return;
	}

	if(parsed_data->cert_exists)
	{
		import_cert_cb(srv_certman_get_job_id(job), SRV_CERTMAN_ERR_NONE, parsed_data->cert.label, parsed_data->cert.dcs_label, 0);
		certman_send_parse_end_req(MOD_MMI, 0, srv_certman_job_get_certman_job_id(job));
		srv_certman_job_delete(job);
		return;
	}

	label = srv_certman_suggest_label(&(parse_detail->parsed_data->cert.subject), &label_dcs);

	cert_ref_id = srv_certman_job_get_cert_ref_id(job);

	err = certman_ctx_import_new(srv_certman_job_get_certman_job_id(job), cert_ref_id, &ctx_import);

	if(err != CERTMAN_ERR_NONE)
        goto error;

	err = certman_import_set_label(ctx_import, label, (certman_dcs_enum)label_dcs);
		
	if(err != CERTMAN_ERR_NONE)
		goto error;
	
	certman_trans_id = srv_certman_new_trans_id();
	srv_certman_job_modify_trans_id(job, certman_trans_id);

	SetProtocolEventHandler(srv_certman_import_file_cnf_handler, MSG_ID_CERTMAN_IMPORT_CNF);

	certman_send_import_req(MOD_MMI, certman_trans_id, ctx_import);
	certman_parsed_data_free(parse_detail->parsed_data);

error:
	if(ctx_import)
		certman_ctx_import_free(ctx_import);

	if(err != CERTMAN_ERR_NONE)
	{
		import_cert_cb(srv_certman_get_job_id(job), srv_certman_convert_certman_error(parse_detail->status), NULL, (srv_certman_dcs_enum)0, 0);
		certman_send_parse_end_req(MOD_MMI, 0, srv_certman_job_get_certman_job_id(job));
		srv_certman_job_delete(job);
	}
}


void  srv_certman_parse_begin_file_cnf_handler(void *msg) //MSG_ID_CERTMAN_PARSE_BEGIN_CNF/*(S32 job_id, srv_certman_error_enum status, U16 num_private_key, srv_certman_parsed_info_struct *parsed_info)*/
{
	certman_parse_begin_cnf_struct *parse_begin = (certman_parse_begin_cnf_struct*)msg;
	srv_certman_job_struct* job = NULL;
	srv_certman_error_enum status;
	srv_certman_import_cert_cb import_cert_cb = NULL;
	U32 cert_ref_id, certman_trans_id;

	job = srv_certman_find_job_by_trans_id(parse_begin->trans_id);

	if(job == NULL)
		return;

	import_cert_cb = (srv_certman_import_cert_cb)srv_certman_job_get_cb(job);

	status = srv_certman_convert_certman_error(parse_begin->status);

	if(parse_begin->status != CERTMAN_ERR_NONE)
	{
		import_cert_cb(srv_certman_get_job_id(job), status, NULL, (srv_certman_dcs_enum)0, 0);
		srv_certman_job_delete(job);
		return;
	}

	srv_certman_job_modify_certman_job_id(job, parse_begin->job_id);



	if(parse_begin->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_count != 1)
	{
		import_cert_cb(srv_certman_get_job_id(job), SRV_CERTMAN_ERR_TOO_MANY_CERTS, NULL, (srv_certman_dcs_enum)0, 0);
		certman_send_parse_end_req(MOD_MMI, 0, srv_certman_job_get_certman_job_id(job));
		srv_certman_job_delete(job);
		return;
	}

	cert_ref_id = parse_begin->parsed_info[CERTMAN_PARSED_CERTGRP_ALL].cert_ref_ids[0];

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_modify_trans_id(job, certman_trans_id);
	srv_certman_job_modify_cert_ref_id(job, cert_ref_id);

	SetProtocolEventHandler(srv_certman_parse_file_detail_cnf_handler, MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF);

	certman_send_parse_cert_detail_req(MOD_MMI, certman_trans_id, srv_certman_job_get_certman_job_id(job), cert_ref_id);
}


/* Parsing*/
srv_certman_error_enum srv_certman_parse_start(S32 *job_id,
							const kal_wchar *filename,
                            const U8 *password,
                            srv_certman_parsed_info_cb parsed_info_cb)
{
    certman_encoding_enum file_encoding;
    certman_error_enum err;
    certman_ctx_parse_struct *parse_ctx = NULL;
    srv_certman_job_struct* job = NULL;
    kal_uint32 certman_trans_id;
	*job_id = -1;
    
    if(filename == NULL || parsed_info_cb == NULL)
        return SRV_CERTMAN_ERR_INVALID_INPUT;

    job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

    err = certman_parse_get_encoding_type_by_file(filename, &file_encoding);

    if(err != CERTMAN_ERR_NONE)
        return srv_certman_convert_certman_error(err);
    
    err = certman_ctx_parse_new_by_file(filename, file_encoding, &parse_ctx);

    if(err != CERTMAN_ERR_NONE)
        return srv_certman_convert_certman_error(err);

    if(password)
    {
        err = certman_parse_set_decrypt_password(parse_ctx, password);
        if(err != CERTMAN_ERR_NONE)
        {
            certman_ctx_parse_free(parse_ctx);
            return srv_certman_convert_certman_error(err);
        }
    }
    
    certman_trans_id = srv_certman_new_trans_id();

    srv_certman_job_new(job, certman_trans_id, (void*)parsed_info_cb);

	SetProtocolEventHandler(srv_certman_parse_begin_cnf_handler, MSG_ID_CERTMAN_PARSE_BEGIN_CNF);

    certman_send_parse_begin_req(MOD_MMI, certman_trans_id, parse_ctx);

    certman_ctx_parse_free(parse_ctx);

	*job_id = srv_certman_get_job_id(job);

    return SRV_CERTMAN_ERR_NONE;
}

srv_certman_error_enum srv_certman_parse_detail(U32 job_id,
                             U32 cert_ref_id,
                             srv_certman_parsed_data_cb parsed_data_cb)
{
    srv_certman_job_struct *job = NULL;
	kal_uint32 certman_trans_id;
	
	job = srv_certman_find_job_by_job_id(job_id);

	if(job == NULL || parsed_data_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_modify_trans_id(job, certman_trans_id);
	srv_certman_job_modify_cb(job, (void*)parsed_data_cb);

	SetProtocolEventHandler(srv_certman_parse_detail_cnf_handler, MSG_ID_CERTMAN_PARSE_CERT_DETAIL_CNF);

	certman_send_parse_cert_detail_req(MOD_MMI, certman_trans_id, srv_certman_job_get_certman_job_id(job), cert_ref_id);
	
	return SRV_CERTMAN_ERR_NONE;
}

srv_certman_error_enum srv_certman_parse_end(U32 job_id,
                          srv_certman_parse_end_cb parse_end_cb)
{
    srv_certman_job_struct *job = NULL;
	kal_uint32 certman_trans_id;
	
	job = srv_certman_find_job_by_job_id(job_id);

	if(job == NULL || parse_end_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_modify_trans_id(job, certman_trans_id);
	srv_certman_job_modify_cb(job, (void*)parse_end_cb);

	SetProtocolEventHandler(srv_certman_parse_end_cnf_handler, MSG_ID_CERTMAN_PARSE_END_CNF);

	certman_send_parse_end_req(MOD_MMI, certman_trans_id, srv_certman_job_get_certman_job_id(job));
	
	return SRV_CERTMAN_ERR_NONE;
}


/* Import */
srv_certman_error_enum srv_certman_import (U32 job_id,
                        U32 cert_ref_id,
                        const U8 *label,
                        srv_certman_dcs_enum label_dcs,
                        srv_certman_privkey_protection_enum privkey_protect_method,
                        const U8 *privkey_protect_password,
                        U8 privkey_is_exportable,
                        srv_certman_import_cert_cb import_cert_cb)
{
    srv_certman_job_struct *job = NULL;
	kal_uint32 certman_trans_id;
	certman_ctx_import_struct *ctx_import = NULL;
	certman_error_enum err = CERTMAN_ERR_NONE;
	
	job = srv_certman_find_job_by_job_id(job_id);

	if(job == NULL || import_cert_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;
	
	if(label)
	{
		err = certman_import_check_label_exists(label, (certman_dcs_enum)label_dcs);
		
		if(err != CERTMAN_ERR_NONE)
			goto error;
	}

	err = certman_ctx_import_new(srv_certman_job_get_certman_job_id(job), cert_ref_id, &ctx_import);

	if(err != CERTMAN_ERR_NONE)
        goto error;

	if(label)
	{
		err = certman_import_set_label(ctx_import, label, (certman_dcs_enum)label_dcs);
		
		if(err != CERTMAN_ERR_NONE)
			goto error;
	}

	err = certman_import_set_privkey_protection(ctx_import, (certman_privkey_protection_enum)privkey_protect_method, privkey_protect_password);

	if(err != CERTMAN_ERR_NONE)
		goto error;

	err = certman_import_set_privkey_exportable(ctx_import, privkey_is_exportable);

	if(err != CERTMAN_ERR_NONE)
		goto error;

	certman_trans_id = srv_certman_new_trans_id();
	srv_certman_job_modify_trans_id(job, certman_trans_id);
	srv_certman_job_modify_cb(job, (void*)import_cert_cb);

	SetProtocolEventHandler(srv_certman_import_cnf_handler, MSG_ID_CERTMAN_IMPORT_CNF);

	certman_send_import_req(MOD_MMI, certman_trans_id, ctx_import);

error:
	if(ctx_import)
		certman_ctx_import_free(ctx_import);

	return srv_certman_convert_certman_error(err);
}



srv_certman_error_enum srv_certman_import_file (S32 *job_id,
												const U16 *filename,
												srv_certman_import_cert_cb import_cert_cb)
{
    certman_encoding_enum file_encoding;
    certman_error_enum err;
    certman_ctx_parse_struct *parse_ctx = NULL;
    srv_certman_job_struct* job = NULL;
    kal_uint32 certman_trans_id;
	*job_id = -1;
    
    if(filename == NULL || import_cert_cb == NULL)
        return SRV_CERTMAN_ERR_INVALID_INPUT;

    job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

    err = certman_parse_get_encoding_type_by_file(filename, &file_encoding);

    if(err != CERTMAN_ERR_NONE)
        return srv_certman_convert_certman_error(err);
    
    err = certman_ctx_parse_new_by_file(filename, file_encoding, &parse_ctx);

    if(err != CERTMAN_ERR_NONE)
        return srv_certman_convert_certman_error(err);

    certman_trans_id = srv_certman_new_trans_id();

    srv_certman_job_new(job, certman_trans_id, (void*)import_cert_cb);

	SetProtocolEventHandler(srv_certman_parse_begin_file_cnf_handler, MSG_ID_CERTMAN_PARSE_BEGIN_CNF);

    certman_send_parse_begin_req(MOD_MMI, certman_trans_id, parse_ctx);

    certman_ctx_parse_free(parse_ctx);

	*job_id = srv_certman_get_job_id(job);

    return SRV_CERTMAN_ERR_NONE;
}


/* Retrieve */
srv_certman_error_enum srv_certman_get_cert_ids_by_type(srv_certman_certtype_enum type,
                                     srv_certman_cert_ids_result_struct *ids_qry)
{
    certman_cert_ids_result_struct cert_ids_qry;

	if(ids_qry == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	certman_get_cert_ids_by_type((certman_certtype_enum)type, &cert_ids_qry);

	ids_qry->num_ids = cert_ids_qry.num_ids;
	ids_qry->cert_ids = (U32*)cert_ids_qry.cert_ids;
	
	return SRV_CERTMAN_ERR_NONE;
}


U32 srv_certman_get_cert_count (srv_certman_cert_group_enum cert_group,
                                srv_certman_keypurpose_enum key_purpose)
{
    return (U32) certman_get_cert_count(cert_group, key_purpose);
}


srv_certman_error_enum srv_certman_get_cert_label(U32 cert_id,
	                                              U8 *label_buffer,
	                                              U32 bufsize,
	                                              srv_certman_dcs_enum *dcs_out)
{
    return srv_certman_convert_certman_error(certman_get_cert_label(cert_id, label_buffer, bufsize, (certman_dcs_enum*)dcs_out));
}

srv_certman_error_enum srv_certman_get_cert_list_by_group (S32 *job_id, srv_certman_cert_group_enum cert_group, 
                                        srv_certman_keypurpose_enum key_purpose, 
                                        srv_certman_pubkey_type_enum pubkey_type, 
                                        U32 more,
                                        srv_certman_list_by_grp_cb list_by_grp_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;
	
	*job_id = -1;
	
	if(list_by_grp_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)list_by_grp_cb);

	SetProtocolEventHandler(srv_certman_cert_list_by_group_cnf_handler, MSG_ID_CERTMAN_GET_CERT_LIST_BY_GROUP_CNF);

	certman_send_get_cert_list_by_group_req(MOD_MMI, certman_trans_id, cert_group, key_purpose, pubkey_type, more);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}


srv_certman_error_enum srv_certman_get_cert_list_by_domain (S32 *job_id, srv_certman_domain_enum domain, 
                                         srv_certman_keypurpose_enum key_purpose, 
                                         U32 more,
                                         srv_certman_list_by_dmn_cb list_by_dmn_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;
	
	*job_id = -1;
	
	if(list_by_dmn_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)list_by_dmn_cb);

	SetProtocolEventHandler(srv_certman_cert_list_by_dmn_cnf_handler, MSG_ID_CERTMAN_GET_CERT_LIST_BY_DOMAIN_CNF);

	certman_send_get_cert_list_by_domain_req(MOD_MMI, certman_trans_id, domain, key_purpose, more);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}



srv_certman_error_enum srv_certman_get_cert_list_by_issuers_file (S32 *job_id, srv_certman_cert_group_enum cert_group, 
                                               srv_certman_keypurpose_enum key_purpose,
                                               srv_certman_pubkey_type_enum *pubkey_types,
                                               U8 num_types,
                                               const kal_wchar *issuers_filename,
                                               srv_certman_list_by_issuer_data_cb list_by_issuer_data_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;

	*job_id = -1;
	
	if(list_by_issuer_data_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)list_by_issuer_data_cb);

	SetProtocolEventHandler(srv_certman_cert_list_by_issuer_file_cnf_handler, MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_FILE_CNF);
	SetProtocolEventHandler(srv_certman_cert_list_by_issuer_data_ind_handler, MSG_ID_CERTMAN_GET_CERT_LIST_BY_ISSUERS_DATA_IND);

	certman_send_get_cert_list_by_issuers_file_req(MOD_MMI,
												   certman_trans_id,
												   cert_group, key_purpose,
												   (kal_uint8*) pubkey_types,
												   num_types,
												   issuers_filename);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}

srv_certman_error_enum srv_certman_get_cert_disp_by_id (S32 *job_id, U32 cert_id,
                                     srv_certman_cert_disp_by_id_cb cert_disp_by_id_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;
	
	*job_id = -1;
	
	if(cert_disp_by_id_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)cert_disp_by_id_cb);

	SetProtocolEventHandler(srv_certman_cert_disp_by_id_cnf_handler, MSG_ID_CERTMAN_GET_CERT_DISP_BY_ID_CNF);

	certman_send_get_cert_disp_by_id_req(MOD_MMI, certman_trans_id, cert_id);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}


srv_certman_error_enum srv_certman_get_cert_chain_disp_by_id (S32 *job_id, U32 cert_id,
                                           srv_certman_chain_disp_by_id_cb chain_disp_by_id_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;
	
	*job_id = -1;
	
	if(chain_disp_by_id_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)chain_disp_by_id_cb);

	SetProtocolEventHandler(srv_certman_chain_disp_by_id_cnf_handler, MSG_ID_CERTMAN_GET_CERT_CHAIN_DISP_BY_ID_CNF);

	certman_send_get_cert_chain_disp_by_id_req(MOD_MMI, certman_trans_id, cert_id);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}


srv_certman_error_enum srv_certman_get_certid_by_group (S32 *job_id, srv_certman_cert_group_enum cert_group,
                                     srv_certman_keypurpose_enum key_purpose,
                                     U32 more,
                                     srv_certman_ids_by_grp_cb ids_by_grp_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;

	*job_id = -1;
	
	if(ids_by_grp_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)ids_by_grp_cb);

	SetProtocolEventHandler(srv_certman_certid_by_group_cnf_handler, MSG_ID_CERTMAN_GET_CERTID_BY_GROUP_CNF);

	certman_send_get_certid_by_group_req(MOD_MMI, certman_trans_id, cert_group, key_purpose, more);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}


srv_certman_error_enum srv_certman_get_certid_by_domain (S32 *job_id, srv_certman_domain_enum domain,
                                      srv_certman_keypurpose_enum key_purpose,
                                      U32 more,
                                      srv_certman_ids_by_dmn_cb ids_by_dmn_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;
	
	*job_id = -1;
	
	if(ids_by_dmn_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)ids_by_dmn_cb);

	SetProtocolEventHandler(srv_certman_certid_by_domain_cnf_handler, MSG_ID_CERTMAN_GET_CERTID_BY_DOMAIN_CNF);

	certman_send_get_certid_by_group_req(MOD_MMI, certman_trans_id, domain, key_purpose, more);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}


srv_certman_error_enum srv_certman_get_cert_by_id (S32 *job_id, U32 cert_id,
                                srv_certman_encoding_enum encoding,
                                srv_certman_keypurpose_enum key_purpose,
                                srv_certman_cert_by_id_cb cert_by_id_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;

	*job_id = -1;
	
	if(cert_by_id_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)cert_by_id_cb);

	SetProtocolEventHandler(srv_certman_cert_by_id_cnf_handler, MSG_ID_CERTMAN_GET_CERT_BY_ID_CNF);

	certman_send_get_cert_by_id_req(MOD_MMI, certman_trans_id, cert_id, (certman_encoding_enum)encoding, key_purpose, NULL);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}


srv_certman_error_enum srv_certman_get_trusted_cert_by_id (S32 *job_id, U32 cert_id,
                                        srv_certman_keypurpose_enum key_purpose,
                                        srv_certman_trstd_cert_by_id_cb trstd_cert_by_id_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;
	
	*job_id = -1;
	
	if(trstd_cert_by_id_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)trstd_cert_by_id_cb);

	SetProtocolEventHandler(srv_certman_trusted_cert_by_id_cnf_handler, MSG_ID_CERTMAN_GET_TRUSTED_CERT_BY_ID_CNF);

	certman_send_get_trusted_cert_by_id_req(MOD_MMI, certman_trans_id, cert_id, key_purpose, NULL);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}



srv_certman_error_enum srv_certman_get_cert_chain (S32 *job_id, U32 cert_id,
                                srv_certman_keypurpose_enum key_purpose,
                                srv_certman_cert_chain_cb cert_chain_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;
	
	*job_id = -1;
	
	if(cert_chain_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)cert_chain_cb);

	SetProtocolEventHandler(srv_certman_cert_chain_cnf_handler, MSG_ID_CERTMAN_GET_CERT_CHAIN_CNF);

	certman_send_get_cert_chain_req(MOD_MMI, certman_trans_id, cert_id, key_purpose, NULL);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}


srv_certman_error_enum srv_certman_get_privkey (S32 *job_id, U32 cert_id, 
                             srv_certman_encoding_enum encoding,
                             srv_certman_pwd_cb pwd_cb,
                             srv_certman_priv_key_cb priv_key_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;

	*job_id = -1;
	
	if(pwd_cb == NULL || priv_key_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)priv_key_cb);
	srv_certman_job_modify_pwd_cb(job, pwd_cb);

	SetProtocolEventHandler(srv_certman_privkey_cnf_handler, MSG_ID_CERTMAN_GET_PRIVKEY_CNF);

	certman_send_get_privkey_req(MOD_MMI, certman_trans_id, cert_id, srv_certman_pwd_cb_handler, (certman_encoding_enum)encoding, NULL);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}

/***************** Util ***************/

srv_certman_error_enum srv_certman_util_decrypt_privkey_file(const kal_wchar *filename,
            	                                         const U8 *password,
            	                                         U32 size,
            	                                         srv_certman_encoding_enum output_encoding,
            	                                         srv_certman_privkey_decrypt_out_cb privkey_decrypt_out_cb)
{
    kal_wchar *output_filename = NULL;
	certman_error_enum err;

	err = certman_util_decrypt_privkey_file_out_file(filename, password, size, (certman_encoding_enum)output_encoding, &output_filename);

	if(err == CERTMAN_ERR_NONE)
	{
		privkey_decrypt_out_cb(SRV_CERTMAN_ERR_NONE, filename, output_filename);
	}
	else
	{
		privkey_decrypt_out_cb(srv_certman_convert_certman_error(err), filename, NULL);
	}

	if(output_filename)
		free_ctrl_buffer(output_filename);

	return srv_certman_convert_certman_error(err);
}


srv_certman_error_enum srv_certman_util_check_id_as_cert(   U32 id,
            	                                            srv_certman_cert_group_enum cert_group,
            	                                            srv_certman_domain_enum domain,
            	                                            srv_certman_keypurpose_enum key_purpose)
{
    return srv_certman_convert_certman_error(certman_util_check_id_as_cert(id, cert_group, domain, key_purpose));
}


srv_certman_error_enum srv_certman_util_check_id_as_privkey(U32 id)
{
    return srv_certman_convert_certman_error(certman_util_check_id_as_privkey(id));
}


srv_certman_error_enum srv_certman_util_signature_verify_by_id(U32 id, 
                                                       srv_certman_signature_vfy_params_struct *sig_vfy,
                                                       U8 *verified)
{
    return srv_certman_convert_certman_error(certman_util_signature_verify_by_id(id, (certman_signature_vfy_params_struct*)sig_vfy, (kal_int8*)verified));
}


srv_certman_error_enum srv_certman_update_key_purpose (S32 *job_id, U32 cert_id,
                                    srv_certman_keypurpose_enum key_purpose,
                                    srv_certman_update_key_purpose_cb update_kp_cb)
{
    srv_certman_job_struct* job = NULL;
    kal_uint32 certman_trans_id;

	*job_id = -1;
    
    if(update_kp_cb == NULL)
        return SRV_CERTMAN_ERR_INVALID_INPUT;

    job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)update_kp_cb);

	SetProtocolEventHandler(srv_certman_update_key_purpose_cnf_handler, MSG_ID_CERTMAN_UPDATE_KEY_PURPOSE_CNF);

	certman_send_update_key_purpose_req(MOD_MMI, certman_trans_id, cert_id, key_purpose);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}
/***************** Validate ***************/

srv_certman_error_enum srv_certman_validate_cert_list (S32 *job_id, srv_certman_cert_data_struct *cert_list,
                                    U8 num_cert,
                                    srv_certman_ocsp_opt_enum ocsp_options,
                                    U8 *ocsp_responser_url,
                                    U32 ocsp_retry_time,
									srv_certman_ocsp_network_profile_struct *ocsp_profile,
                                    srv_certman_val_result_cb val_result_cb)
{
    certman_error_enum err = CERTMAN_ERR_NONE;
    srv_certman_job_struct* job = NULL;
    kal_uint32 certman_trans_id;
	certman_ctx_validate_struct *ctx_validate;
	int i;

	*job_id = -1;
    
    if(cert_list == NULL || val_result_cb == NULL)
        return SRV_CERTMAN_ERR_INVALID_INPUT;

	if(CERTMAN_NUM_CERT_IN_VALIDATE < num_cert)
		return SRV_CERTMAN_ERR_TOO_MANY_CERTS;

    job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

    err = certman_ctx_validate_new(CERTMAN_VALSOURCE_ARRAY, CERTMAN_VALTYPE_TRUSTED_ISSUER, &ctx_validate);

    if(err != CERTMAN_ERR_NONE)
        return srv_certman_convert_certman_error(err);

    for(i=0; i<num_cert; i++)
	{
		err = certman_validate_add_cert(ctx_validate, (certman_certtype_enum)cert_list[i].type, cert_list[i].data, cert_list[i].size);

		if(err != CERTMAN_ERR_NONE)
			goto error;
	}

	if(ocsp_options & SRV_CERTMAN_OCSP_OPT_USE_OCSP)
	{
		kal_bool kb = (kal_bool)1;
		err = certman_validate_set_ocsp_opt(ctx_validate, CERTMAN_OCSP_OPT_USE_OCSP, &kb);
		if(err != CERTMAN_ERR_NONE)
			goto error;
	}

	if(ocsp_options & SRV_CERTMAN_OCSP_OPT_MUST_PASS)
	{
		kal_bool kb = (kal_bool)1;
		err = certman_validate_set_ocsp_opt(ctx_validate, CERTMAN_OCSP_OPT_MUST_PASS, &kb);
		if(err != CERTMAN_ERR_NONE)
			goto error;
	}

	if(ocsp_responser_url)
	{
		err = certman_validate_set_ocsp_opt(ctx_validate, CERTMAN_OCSP_OPT_RESPONDER, ocsp_responser_url);
		if(err != CERTMAN_ERR_NONE)
			goto error;
	}

	if(ocsp_retry_time)
	{
		err = certman_validate_set_ocsp_opt(ctx_validate, CERTMAN_OCSP_OPT_RETRY_TIMER, &ocsp_retry_time);
		if(err != CERTMAN_ERR_NONE)
			goto error;
	}

	if(ocsp_profile)
	{
		err = certman_validate_set_ocsp_opt(ctx_validate, CERTMAN_OCSP_OPT_NETWORK, ocsp_profile);
		if(err != CERTMAN_ERR_NONE)
			goto error;
	}
    
    certman_trans_id = srv_certman_new_trans_id();

    srv_certman_job_new(job, certman_trans_id, (void*)val_result_cb);

	SetProtocolEventHandler(srv_certman_validate_cert_cnf_handler, MSG_ID_CERTMAN_VALIDATE_CNF);

    certman_send_validate_req(MOD_MMI, certman_trans_id, NULL, ctx_validate);

	*job_id = srv_certman_get_job_id(job);

error:
	if(ctx_validate)
		certman_ctx_validate_free(ctx_validate);

	return srv_certman_convert_certman_error(err);
}


/*******************Delete******************/
srv_certman_error_enum srv_certman_delete_cert(S32 *job_id, U32 cert_id,
                            srv_certman_status_cb status_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;

	*job_id = -1;
	
	if(status_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)status_cb);

	SetProtocolEventHandler(srv_certman_delete_cert_cnf_handler, MSG_ID_CERTMAN_DELETE_CERT_CNF);

	certman_send_delete_cert_req(MOD_MMI, certman_trans_id, cert_id);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}

srv_certman_error_enum srv_certman_delete_cert_group(S32 *job_id, srv_certman_cert_group_enum cert_group,
                                  srv_certman_delete_status_cb delete_status_cb)
{
    srv_certman_job_struct* job = NULL;
	kal_uint32 certman_trans_id;

	*job_id = -1;
	
	if(delete_status_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	certman_trans_id = srv_certman_new_trans_id();

	srv_certman_job_new(job, certman_trans_id, (void*)delete_status_cb);

	SetProtocolEventHandler(srv_certman_delete_all_cert_cnf_handler, MSG_ID_CERTMAN_DELETE_ALL_CERT_CNF);

	certman_send_delete_all_cert_req(MOD_MMI, certman_trans_id, cert_group);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
}

/******** OCSP *********************/
srv_certman_error_enum srv_certman_ocsp_verify_cert(S32 *job_id, const void* cert, U32 cert_len,
                                const void* issuer, U32 issuer_len,
								srv_certman_encoding_enum encoding,
                                srv_certman_ocsp_opt_enum ocsp_options,
                                U8 *ocsp_responser_url,
                                U32 ocsp_retry_time,
								srv_certman_ocsp_network_profile_struct *ocsp_profile,
                                srv_certman_status_cb status_cb)
{
#ifdef __OCSP_SUPPORT__
    srv_certman_job_struct* job = NULL;
	kal_uint8 certman_trans_id;
	certman_ocsp_customize_param_struct customize_params;
	kal_uint32 customize_options = 0;
	certman_error_enum err = CERTMAN_ERR_NONE;

	*job_id = -1;
	
	if(status_cb == NULL)
		return SRV_CERTMAN_ERR_INVALID_INPUT;

	job = srv_certman_get_free_job();

    if(!job)
        return SRV_CERTMAN_ERR_MEMFULL;

	memset(&customize_params, 0, sizeof(customize_params));

	if(ocsp_options & SRV_CERTMAN_OCSP_OPT_USE_OCSP)
	{
		customize_options |= CERTMAN_OCSP_OPT_USE_OCSP;
		customize_params.use_ocsp = (kal_bool)1;
	}

	if(ocsp_options & SRV_CERTMAN_OCSP_OPT_MUST_PASS)
	{
		customize_options |= CERTMAN_OCSP_OPT_MUST_PASS;
		customize_params.must_pass = (kal_bool)1;
	}

	if(ocsp_responser_url)
	{
		if(strlen((const char *)ocsp_responser_url) > 255)
			return SRV_CERTMAN_ERR_INVALID_INPUT;

		customize_options |= CERTMAN_OCSP_OPT_RESPONDER;
		strcpy(customize_params.responder, (const char *)ocsp_responser_url);
	}

	if(ocsp_retry_time)
	{
		customize_options |= CERTMAN_OCSP_OPT_RETRY_TIMER;
		customize_params.retry_timer = ocsp_retry_time;
	}
 
	if(ocsp_profile)
	{
		customize_options |= CERTMAN_OCSP_OPT_NETWORK;
		customize_params.network = *(certman_ocsp_network_profile_struct*)ocsp_profile;
	}

	SetProtocolEventHandler(srv_certman_ocsp_verify_cert_cnf_handler, MSG_ID_CERTMAN_OCSP_VERIFY_CERT_CNF);

	err = certman_ocsp_verify_cert(MOD_MMI, cert, cert_len, issuer, issuer_len, NULL, (certman_encoding_enum)encoding, &certman_trans_id, customize_options, &customize_params);

	if(err != CERTMAN_ERR_NONE && err != CERTMAN_ERR_WOULDBLOCK)
		return srv_certman_convert_certman_error(err);

	srv_certman_job_new(job, 0, (void*)status_cb);

	srv_certman_job_modify_ocsp_trans_id(job, certman_trans_id);

	*job_id = srv_certman_get_job_id(job);

	return SRV_CERTMAN_ERR_NONE;
#else
	return SRV_CERTMAN_ERR_FAIL;
#endif /*__OCSP_SUPPORT__*/
}
#endif /*__CERTMAN_SUPPORT__*/
