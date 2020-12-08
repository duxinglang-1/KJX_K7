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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   j2me_msg_util.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements J2ME message handler utilities
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
 *
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

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "jam_msg_handler.h"
#include "jam_internal.h"
#include "jma_internal.h"
#include "j2me_trace.h"

#include "JavaAgencyDef.h"
#include "JavaAgencyGProt.h"
#include "wgui_categories.h"
#include "MMI_features.h"
#include "gdi_include.h"
#include "jvm_interface.h"
#include "jvm_internal.h"
#include "jam_internal.h"
#include "gdi_image_gif.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#include "drm_def.h"
#endif /* __DRM_SUPPORT__ */ 
#include "GlobalDefs.h"
#include "mexe_struct.h"
#ifdef WAP_SEC_SUPPORT
#include "wps_struct.h"
#endif 
#include "FileManagerDef.h"
#include "app_str.h"
/* global definition */
jam_ca_struct *g_jam_ca_list = NULL;
jam_get_cert_status g_jam_get_ca_status = JAM_GET_CA_READY;
jam_sim_ca_struct *g_jam_sim_ca_list = NULL;
jam_get_cert_status g_jam_get_sim_ca_status = JAM_GET_CA_READY;
/* certification */
#ifdef WAP_SEC_SUPPORT
typedef struct _jam_ca_list_ids_struct
{
    kal_uint8  total;
    kal_uint32 ids[256];
}jam_ca_list_ids_struct;
static jam_ca_list_ids_struct *g_jam_ca_list_ids = NULL;
#endif /* WAP_SEC_SUPPORT */ 

/*****************************************************************************
 * FUNCTION
 *  get_ca_from_wap
 * DESCRIPTION
 *  Use this function to get x509 CA from WAP.
 *  *** This function can be used by jal layer only ****
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool get_ca_from_wap(void)
{
#ifdef WAP_SEC_SUPPORT
    wps_sec_get_cert_ids_req_struct *get_cer_req;
    if (!jam_is_network_service_available()|| (wap_is_ready() == 0))
    {
        g_jam_get_ca_status = JAM_GET_CA_COMPLETED;
        return KAL_TRUE;
    }
    if (g_jam_get_ca_status == JAM_GET_CA_RUNNING)
    {
        return KAL_FALSE;
    }
    free_jam_ca_list();

    get_cer_req =
        (wps_sec_get_cert_ids_req_struct*) construct_local_para(sizeof(wps_sec_get_cert_ids_req_struct), TD_CTRL);
    get_cer_req->cert_options = WPS_SEC_GET_ROOT_CERT;
    g_jam_get_ca_status = JAM_GET_CA_RUNNING;
    java_send_msg_from_active_mod(MOD_WPS,J2ME_WAP_SAP,MSG_ID_WPS_SEC_GET_CERT_IDS_REQ,get_cer_req);
    return KAL_TRUE;
#else
    g_jam_get_ca_status = JAM_GET_CA_COMPLETED;
    return KAL_TRUE;
#endif /* WAP_SEC_SUPPORT */ 
}

void jam_get_certs_handler(ilm_struct *ilm_ptr)
{
    switch(ilm_ptr->msg_id)
    {
        #ifdef WAP_SEC_SUPPORT
        case MSG_ID_WPS_SEC_GET_CERT_IDS_RSP:
        {
            wps_sec_get_cert_ids_rsp_struct *sec_cert_rsp = (wps_sec_get_cert_ids_rsp_struct*) ilm_ptr->local_para_ptr;
            if (sec_cert_rsp->total > 0)
            {
                ilm_struct *send_ilm;
                wps_sec_get_cert_req_struct *get_cer_req;
                g_jam_ca_list_ids = get_ctrl_buffer(sizeof(jam_ca_list_ids_struct));
                g_jam_ca_list_ids->total = sec_cert_rsp->total;
                memcpy(&(g_jam_ca_list_ids->ids), sec_cert_rsp->cert_ids, g_jam_ca_list_ids->total << 2);
                g_jam_ca_list_ids->total--;
                get_cer_req =
                    (wps_sec_get_cert_req_struct*) construct_local_para(sizeof(wps_sec_get_cert_req_struct), TD_CTRL);
                get_cer_req->cert_id = g_jam_ca_list_ids->ids[g_jam_ca_list_ids->total];
                java_send_msg_from_active_mod(MOD_WPS,J2ME_WAP_SAP,MSG_ID_WPS_SEC_GET_CERT_REQ,get_cer_req);
            }           
            else
            {
                g_jam_get_ca_status = JAM_GET_CA_COMPLETED;
            }
        }
        break;

        case MSG_ID_WPS_SEC_GET_CERT_RSP:
        {
            wps_sec_get_cert_rsp_struct *get_cert_rsp = (wps_sec_get_cert_rsp_struct*) ilm_ptr->local_para_ptr;

            if (get_cert_rsp->result == WPS_SEC_OK && get_cert_rsp->cert.type == WPS_SEC_CERT_FORMAT_X509 &&
                get_cert_rsp->rsa_public_key.rsa_modulus != NULL && get_cert_rsp->rsa_public_key.rsa_exponent != NULL)
            {
                jam_ca_struct *temp_ca = g_jam_ca_list;
                jam_ca_struct *wap_ca = jvm_malloc(sizeof(jam_ca_struct));
                if(wap_ca)
                {
                    wap_ca->next_ca = NULL;
                    memcpy(&wap_ca->cert_content, &get_cert_rsp->cert, sizeof(wps_sec_cert_content_struct));
                    memcpy(&wap_ca->cert_pkey, &get_cert_rsp->rsa_public_key, sizeof(wps_sec_rsa_public_key_struct));
                    wap_ca->cert_pkey.rsa_exponent = jvm_malloc(get_cert_rsp->rsa_public_key.exp_len + 1);

                    if(wap_ca->cert_pkey.rsa_exponent)
                    {
                        memcpy(
                            wap_ca->cert_pkey.rsa_exponent,
                            get_cert_rsp->rsa_public_key.rsa_exponent,
                            get_cert_rsp->rsa_public_key.exp_len);
                        wap_ca->cert_pkey.rsa_modulus = jvm_malloc(get_cert_rsp->rsa_public_key.mod_len + 1);
                        if(wap_ca->cert_pkey.rsa_modulus)
                        {
                            memcpy(
                                wap_ca->cert_pkey.rsa_modulus,
                                get_cert_rsp->rsa_public_key.rsa_modulus,
                                get_cert_rsp->rsa_public_key.mod_len);
                        }                
                        else
                        {
                            g_jam_get_ca_status = JAM_GET_CA_OUT_OF_MEM;
                        }
                    }                    
                    else
                    {
                        g_jam_get_ca_status = JAM_GET_CA_OUT_OF_MEM;
                    }
                    if(g_jam_get_ca_status != JAM_GET_CA_OUT_OF_MEM)
                    {
                        if (temp_ca != NULL)
                        {
                            while (temp_ca->next_ca != NULL)
                            {
                                temp_ca = temp_ca->next_ca;
                            }
                            temp_ca->next_ca = wap_ca;
                        }
                        else
                        {
                            g_jam_ca_list = wap_ca;
                        }
                    }
                    else
                    {
                        if(wap_ca->cert_pkey.rsa_exponent)
                        {
                            jvm_free(wap_ca->cert_pkey.rsa_exponent);
                        }
                        if(wap_ca->cert_pkey.rsa_modulus)
                        {
                            jvm_free(wap_ca->cert_pkey.rsa_modulus);
                        }
                        jvm_free(wap_ca);
                    }

                }
                else
                {
                    g_jam_get_ca_status = JAM_GET_CA_OUT_OF_MEM;
                }

                free_ctrl_buffer(get_cert_rsp->rsa_public_key.rsa_exponent);
                free_ctrl_buffer(get_cert_rsp->rsa_public_key.rsa_modulus);

            }
            if(g_jam_get_ca_status == JAM_GET_CA_RUNNING)
            {
                if (g_jam_ca_list_ids->total > 0)
                {
                    ilm_struct *send_ilm;
                    wps_sec_get_cert_req_struct *get_cer_req;
                    g_jam_ca_list_ids->total--;
                    get_cer_req =
                        (wps_sec_get_cert_req_struct*) construct_local_para(sizeof(wps_sec_get_cert_req_struct), TD_CTRL);
                    get_cer_req->cert_id = g_jam_ca_list_ids->ids[g_jam_ca_list_ids->total];
                    java_send_msg_from_active_mod(MOD_WPS,J2ME_WAP_SAP,MSG_ID_WPS_SEC_GET_CERT_REQ,get_cer_req);
                }
                else
                {
                    g_jam_get_ca_status = JAM_GET_CA_COMPLETED;
                }
            }
        }
        break;
        #endif /* WAP_SEC_SUPPORT */ 

        #ifdef __MMI_MExE_SUPPORT__
        case MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_IND:
        {
            mmi_send_sim_certificate_record_ind_struct *sim_cert_ind = NULL;
            mmi_send_sim_certificate_record_res_struct *get_sim_req = NULL;
            jam_sim_ca_struct *temp_ca_list = NULL;
            kal_int32 i = 0;
            kal_int32 j = 0;

            sim_cert_ind = (mmi_send_sim_certificate_record_ind_struct*) ilm_ptr->local_para_ptr;
            temp_ca_list = g_jam_sim_ca_list;
            if (temp_ca_list != NULL)
            {
                while (temp_ca_list->next_ca != NULL)
                {
                    temp_ca_list = temp_ca_list->next_ca;
                }
                temp_ca_list->next_ca = (jam_sim_ca_struct*) jam_listmem_malloc(sizeof(jam_sim_ca_struct));
                temp_ca_list = temp_ca_list->next_ca;
                temp_ca_list->next_ca = NULL;
            }
            else
            {
                temp_ca_list = (jam_sim_ca_struct*) jam_listmem_malloc(sizeof(jam_sim_ca_struct));
                g_jam_sim_ca_list = temp_ca_list;
                temp_ca_list->next_ca = NULL;
            }

            temp_ca_list->certificate_domain = sim_cert_ind->idx;
            temp_ca_list->certificate_type = sim_cert_ind->certificate_type;
            temp_ca_list->certificate_length = sim_cert_ind->data_length;
            temp_ca_list->certificate_data = jam_listmem_malloc(sim_cert_ind->data_length);
            memcpy(temp_ca_list->certificate_data, sim_cert_ind->data, sim_cert_ind->data_length);
            for (i = 0; i < sim_cert_ind->data_length; i++)
            {
                if (temp_ca_list->certificate_data[i] != 0xd && temp_ca_list->certificate_data[i] != 0xa)
                {
                    if (i != j)
                    {
                        temp_ca_list->certificate_data[j] = temp_ca_list->certificate_data[i];
                    }
                    j++;
                }
            }
            temp_ca_list->certificate_length = j;
            get_sim_req =
                (mmi_send_sim_certificate_record_res_struct*)
                construct_local_para(sizeof(mmi_send_sim_certificate_record_res_struct), TD_CTRL);
            get_sim_req->next = KAL_TRUE;
            java_send_msg(MOD_JASYN,MOD_MMI,J2ME_WAP_SAP,MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_RES,get_sim_req);

        }
        break;
        case MSG_ID_MMI_GET_SIM_CERTIFICATE_RSP:
        {
            g_jam_get_sim_ca_status = JAM_GET_CA_COMPLETED;
        }
        break;
        #endif /* __MMI_MExE_SUPPORT__ */
        
        default:
            break;
   }

}


/*****************************************************************************
 * FUNCTION
 *  free_jam_ca_list
 * DESCRIPTION
 *  Use this function to free memory used by Java ca list.
 *  *** This function can be used by jal layer only ****
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void free_jam_ca_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_ca_struct *temp_ca = g_jam_ca_list;
    jam_ca_struct *ca_to_free;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp_ca != NULL)
    {
        ca_to_free = temp_ca;
        if (ca_to_free->cert_pkey.rsa_exponent && ca_to_free->cert_pkey.rsa_modulus)
        {
            jvm_free(ca_to_free->cert_pkey.rsa_exponent);
            jvm_free(ca_to_free->cert_pkey.rsa_modulus);
        }
        jvm_free(ca_to_free);
        temp_ca = temp_ca->next_ca;
    }
    g_jam_ca_list = NULL;
    #ifdef WAP_SEC_SUPPORT
    if(g_jam_ca_list_ids)
    {
        free_ctrl_buffer(g_jam_ca_list_ids);
        g_jam_ca_list_ids = NULL;
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  get_jam_ca_list
 * DESCRIPTION
 *  Use this function to get ca list retrieved from WAP.
 * PARAMETERS
 *  void
 * RETURNS
 *  jam_ca_struct*
 *****************************************************************************/
jam_ca_struct *get_jam_ca_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jam_ca_list;
}


/*****************************************************************************
 * FUNCTION
 *  ca_list_ready
 * DESCRIPTION
 *  Use this function to get ca list retrieved from WAP.
 * PARAMETERS
 *  void
 *  kal_bool(?)
 * RETURNS
 *  void
 *****************************************************************************/
jam_get_cert_status ca_list_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jam_get_ca_status;;
}


/*****************************************************************************
 * FUNCTION
 *  get_ca_domain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_char *get_ca_domain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return J2ME_CA_DOMAIN;
}

/*****************************************************************************
 * FUNCTION
 *  jam_get_ca_from_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_get_ca_from_sim(void)
{
#ifdef __MMI_MExE_SUPPORT__
    if (mmi_java_is_no_sim())
    {
        g_jam_get_sim_ca_status = JAM_GET_CA_COMPLETED;
        g_jam_sim_ca_list = NULL;
    }
    else
    {
        mmi_get_sim_certificate_req_struct *get_sim_req;
        g_jam_get_sim_ca_status = JAM_GET_CA_RUNNING;
        get_sim_req =
            (mmi_get_sim_certificate_req_struct*) construct_local_para(
                                                    sizeof(mmi_get_sim_certificate_req_struct),
                                                    TD_CTRL);
        get_sim_req->mod_id = MOD_JASYN;
        get_sim_req->type = MExE_CERTIFICATE_X509;
        java_send_msg(MOD_JASYN,MOD_MMI,J2ME_WAP_SAP,MSG_ID_MMI_GET_SIM_CERTIFICATE_REQ,get_sim_req);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  sim_ca_list_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
jam_get_cert_status sim_ca_list_ready(void)
{
#ifdef __MMI_MExE_SUPPORT__
    return g_jam_get_sim_ca_status;
#else
    return JAM_GET_CA_COMPLETED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  get_sim_ca_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
jam_sim_ca_struct *get_sim_ca_list(void)
{
#ifdef __MMI_MExE_SUPPORT__
    return g_jam_sim_ca_list;
#else
    return NULL;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  get_sim_ca_domain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  domain      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_char *get_sim_ca_domain(ROOT_PUBLIC_KEY_ENUM domain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (domain == ROOT_PUBLIC_KEY_OPERATOR)
    {
        return J2ME_CA_OPERATOR_DOMAIN;
    }
    else if (domain == ROOT_PUBLIC_KEY_ADMINISTRATOR)
    {
        return J2ME_CA_MANUFACTURER_DOMAIN;
    }
    else if (domain == ROOT_PUBLIC_KEY_PARTY)
    {
        return J2ME_CA_DOMAIN;
    }

    return "INVALID";
}

