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
 *   jsec_pki.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Java security APIs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include files
*************************************************************************/
/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"
/* CHE */
#include "app_base64.h"
#include "che_api.h"
#include "App_str.h"

/* PKI */
#ifdef __SSL_SUPPORT__
#include "app_datetime.h"
#include "certman_api.h"
#include "pki_api.h"
#endif /* __SSL_SUPPORT__ */

/* APP Lib */
#include "app_base64.h"
#include "app_mine.h"

#include "j2me_custom.h"
#include "jal.h"
#include "jvm_internal.h"
#include "jvm_interface.h"
#include "jam_internal.h"
#include "jam_msg_handler.h"
#include "jsec_interface.h"
#include "jsec_internal.h"

#include "custpack_java_certs.h"
 
extern unsigned short *WCHAR_Dup(unsigned short *src);
 
#ifdef __SSL_SUPPORT__
certman_validate_cnf_struct *verify_cnf;
#endif /* __SSL_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  jsec_pem_decode
 * DESCRIPTION
 *  decode the certificate from PEM format to DER format
 *  
 * PARAMETERS
 *  encCert               [IN]        
 *  encCert_len           [IN]       
 *  derCert               [OUT]
 *  derCert_len           [OUT]
 * RETURNS
 *  JSEC_OK: decode base64 to DER format successfully
 *  JSEC_ERROR: fail to decode
 *****************************************************************************/
kal_int8 jsec_pem_decode(kal_uint8 *encCert, kal_uint32 encCert_len,
                         kal_uint8 **derCert, kal_uint32 *derCert_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *decoded_cert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (encCert == NULL)
    {
        return JSEC_ERROR;
    }

    /* Der size < PEM size */
    decoded_cert = jvm_malloc(encCert_len);
    memset(decoded_cert, 0, encCert_len);
    
    *derCert_len = applib_base64_decode((char*)encCert, encCert_len, (char*)decoded_cert, encCert_len);
    if (*derCert_len <= 0)
    {
        jvm_free(decoded_cert);
        return JSEC_ERROR;
    }

    *derCert = jvm_malloc(*derCert_len);
    memset(*derCert, 0, *derCert_len);
    memcpy(*derCert, decoded_cert, *derCert_len);
    jvm_free(decoded_cert);
    return JSEC_OK;
}

#ifdef __SSL_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  jsec_verify_cert_chain
 * DESCRIPTION
 *  verify the certificate chain and get the verified Java domain. 
 *  User must put the certificate chain in verify_cert by the following order:
 *  end entity cert -> intermediate cert --> ... --> root cert. That is to say,
 *  the verify_cert[0].data = end_entity_cert.
 *  
 * PARAMETERS
 *  verify_cert           [IN]  verified certificate chain. The order of
 *                              certificate chain is 
 *                              "end entity"-> intermediate cert ... --> root cert                              
 *  verify_cert_num       [IN]  verified certificate chain number               
 *  tck_mode              [IN]  is TCK mode or not
 *  trusted_cert          [OUT] Trusted CA, remember to use jvm_free to release it
 *
 * RETURNS
 *  JSEC_OK: verify certificate chain successfully
 *  JSEC_ERROR: verify certificate fail
 *****************************************************************************/
kal_int8 jsec_verify_cert_chain(jsec_pki_data_struct *verify_cert,
                          kal_uint8 verify_cert_num,
                                kal_bool tck_mode,
                                jsec_pki_data_struct *trusted_cert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cur_cert_idx = 0;
    kal_int32 result;
    kal_bool is_abort = KAL_FALSE;
    certman_error_enum err;
    certman_ctx_validate_struct *ctx_validate;
    certman_validate_req_struct *req;
    //certman_get_cert_disp_by_id_req_struct *disp_req;
    ilm_struct ilm_ptr;
    FS_HANDLE file_handle;
    module_type mod_id;
    kal_uint8 *trust_ca_buf;
    kal_uint32 readlen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (verify_cert == NULL)
    {
        return JSEC_ERROR;
    }
    
    err = certman_ctx_validate_new(CERTMAN_VALSOURCE_ARRAY, CERTMAN_VALTYPE_TRUSTED_ISSUER, &ctx_validate);
    if (err != CERTMAN_ERR_NONE)
    {
        return JSEC_ERROR;
    }

    /*  add verified certificate chain */
    for ( ; ;) 
    {
        err = certman_validate_add_cert(
                ctx_validate,
                CERTMAN_CERTTYPE_X509,
                verify_cert[cur_cert_idx].data,
                verify_cert[cur_cert_idx].size);        
        if (err)
        {
            certman_ctx_validate_free(ctx_validate);
            return JSEC_ERROR;
        }
        cur_cert_idx++;
        if (cur_cert_idx >= verify_cert_num)
        {
            break;
        }
    }

    /* set the verify certificate path */
    if (tck_mode == KAL_FALSE)
    {
        err = certman_validate_set_verify_path(ctx_validate, CERTMAN_JAVA_CERTS_PATH,CERTMAN_ENC_DER);
    }
    else
    {
        err = certman_validate_set_verify_path(ctx_validate, CERTMAN_JAVA_TCK_VERIFY_PATH, CERTMAN_ENC_DER);
    }
    
    if (err)
    {
	    certman_ctx_validate_free(ctx_validate);
	    return JSEC_ERROR;
    }

    /* send certificate validation request */
    req = (certman_validate_req_struct*)construct_local_para((kal_uint16)sizeof(certman_validate_req_struct), TD_RESET);
    err = certman_form_validate_req(req, 0xCAFEBABE, NULL, ctx_validate);

    if (err)
    {
        certman_ctx_validate_free(ctx_validate);
	return JSEC_ERROR;
    }
    
    ilm_ptr.src_mod_id = MOD_JAM;
    ilm_ptr.dest_mod_id = MOD_CERTMAN;
    ilm_ptr.sap_id = CERTMAN_APP_SAP;
   
    ilm_ptr.msg_id = MSG_ID_CERTMAN_VALIDATE_REQ;
    ilm_ptr.local_para_ptr = (local_para_struct *)req;
    ilm_ptr.peer_buff_ptr = NULL;
   
    verify_cnf = jvm_malloc(sizeof(certman_validate_cnf_struct));
   
    mod_id = stack_get_active_module_id();

    if (mod_id != MOD_JAM)
    {
        result = jvm_send_and_get_next_event(
                    &ilm_ptr,
                    KAL_TRUE,
                    MSG_ID_CERTMAN_VALIDATE_CNF,
                    KAL_FALSE,
                    KAL_FALSE,
                    &is_abort);
    }
    else
    {
        msg_send(&ilm_ptr);
        result = get_next_event(KAL_TRUE, MSG_ID_CERTMAN_VALIDATE_CNF, KAL_FALSE, KAL_FALSE, &is_abort);
    }
        
    /* get trusted DER CA */
    if (verify_cnf->has_trusted_cert &&
        trusted_cert)
    {
        trust_ca_buf = jvm_malloc(verify_cnf->trusted_cert.size);
        file_handle = FS_Open((kal_uint16*) verify_cnf->trusted_cert.filename, FS_READ_ONLY);
        if (file_handle >= FS_NO_ERROR)
        {
            FS_Read(
                    file_handle,
                    trust_ca_buf,
                    verify_cnf->trusted_cert.size,
                    &readlen);
            FS_Close(file_handle);
        }

        trusted_cert->data = (void *)trust_ca_buf;
        trusted_cert->size = verify_cnf->trusted_cert.size;
    }
    
    if (is_abort == KAL_FALSE)
    {
        switch(verify_cnf->status)
        {
            case CERTMAN_ERR_NONE:
            result = JSEC_OK;
                break;
            case CERTMAN_ERR_CERT_EXPIRED:
                result = JSEC_CERT_EXPIRED;
                break;
            case CERTMAN_ERR_NO_TRUSTED_CERT_FOUND:
                result = JSEC_UNRECOGNIZED_CERT_ISSUER;
                break;
            default:
            result = JSEC_ERROR;
                break;
        }
    }
    else
    {
        /* send abort validation request */
        certman_ctx_validate_free(ctx_validate);
        err = certman_ctx_validate_new(CERTMAN_VALSOURCE_ARRAY, CERTMAN_VALTYPE_CANCEL, &ctx_validate);
        if (err != CERTMAN_ERR_NONE)
            return JSEC_ABORTED;

        req = (certman_validate_req_struct*)construct_local_para((kal_uint16)sizeof(certman_validate_req_struct), TD_RESET);
        err = certman_form_validate_req(req, 0xCAFEBABE, NULL, ctx_validate);
        if (!err)
        {
            ilm_ptr.src_mod_id = MOD_JAM;
            ilm_ptr.dest_mod_id = MOD_CERTMAN;
            ilm_ptr.sap_id = CERTMAN_APP_SAP;
   
            ilm_ptr.msg_id = MSG_ID_CERTMAN_VALIDATE_REQ;
            ilm_ptr.local_para_ptr = (local_para_struct *)req;
            ilm_ptr.peer_buff_ptr = NULL;

            msg_send(&ilm_ptr); /* send request to abort validation */
        }

        result = JSEC_ABORTED;
    }

    if (verify_cnf)
    {
        jvm_free(verify_cnf);
    }
    certman_ctx_validate_free(ctx_validate);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  jsec_verify_signature
 * DESCRIPTION
 *  verify the signature
 *  
 * PARAMETERS
 *  sig                      [IN]       signature needed to be verified
 *  cert                     [IN]       certificate used to verify signature
 *  hash_method              [IN]       signature hash method
 *  verify_file_id           [IN]       jar file id
 *  file_size                [IN]       jar file size
 * RETURNS
 *  JSEC_OK: verify signature successfully.
 *  JSEC_ERROR: fail to verify signature
 *****************************************************************************/
kal_int8 jsec_verify_signature(jsec_pki_data_struct *sig,
                              jsec_pki_data_struct *cert,
                              jsec_hash_alg_enum hash_method,
                              kal_int32 verify_file_id,
                              kal_uint32 file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret;
    kal_int8 verified;
    pki_context_struct *pki_ctx = NULL;
    pki_x509_struct *x509_out = NULL;
    pki_pubkey_struct *pubkey_out = NULL;
    pki_error_enum pki_err;
    kal_uint8 hash_output[20];
    kal_int8 verify_result = JSEC_VERIFY_FAIL;
    pki_hash_alg_enum hash_alg = ((hash_method == JSEC_HASH_MD5) ? PKI_HASH_ALG_MD5 : PKI_HASH_ALG_SHA1);
    kal_uint8 hash_len = ((hash_method == JSEC_HASH_MD5) ? 16 : 20);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sig)
    {
        if (sig->data == NULL)
        {
            return JSEC_ERROR;
        }
    }
    else
    {
        return JSEC_ERROR;
    }
    
    if (cert)
    {
        if (cert->data == NULL)
        {
            return JSEC_ERROR;
        }
    }
    else
    {
        return JSEC_ERROR;
    }
    
    ret = jsec_gen_hash(verify_file_id, file_size, hash_method, hash_output, sizeof(hash_output));
    if (ret == JSEC_OK)
    {
        pki_err = pki_context_new(&pki_ctx);
        if (pki_err == PKI_ERR_NONE)
        {
            /* get the public key from the certificate */
            pki_err = pki_x509_new(pki_ctx, (void *)cert->data, cert->size, &x509_out);
            if (pki_err == PKI_ERR_NONE)
            {
                pki_err = pki_pubkey_new_by_x509(x509_out, &pubkey_out);                if (pki_err == PKI_ERR_NONE)
                {
                    /* verify the signature */
                    pki_err = pki_pubkey_signature_verify(pubkey_out, hash_output, hash_len, hash_alg, (void *)sig->data, sig->size, &verified);
                    if (verified == KAL_TRUE)
                    {
                        /* verify success */
                        verify_result =  JSEC_OK;
                    }
                }
            }
        }  
    }

    if (pubkey_out)
    {
        pki_pubkey_release(&pubkey_out);
    }
    if (x509_out)
    {
        pki_x509_release(&x509_out);
    }
    if (pki_ctx)
    {
        pki_context_release(&pki_ctx);
    }
    return verify_result;   
}

/*****************************************************************************
 * FUNCTION
 *  jsec_gen_hash
 * DESCRIPTION
 *  generate hash value
 *  
 * PARAMETERS
 *  handle               [IN]   file handler
 *  file_size            [IN]   file size
 *  hash_method          [IN]   hash method (JSEC_HASH_SHA1 or JSEC_HASH_MD5)
 *  output               [OUT]  hash output
 *  output_len           [OUT]  hash output length (MD5: 16, SHA1: 20)
 *
 * RETURNS
 *  JSEC_OK: generate hash value successfully.
 *  JSEC_ERROR: fail to generate the hash value.
 *****************************************************************************/
kal_int8 jsec_gen_hash(kal_int32 handle, kal_int32 file_size, 
                       jsec_hash_alg_enum hash_method, kal_uint8 *output,
                       kal_uint8 output_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STCHE che_context;
    kal_bool ret = KAL_TRUE;
    kal_uint8 *temp = NULL;
    kal_uint32 index = 0;
    kal_uint32 count = 0;
    kal_bool mod_complete = KAL_FALSE;
    kal_uint32 i = 1;
    kal_int8 result = JSEC_OK;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hash_method != JSEC_HASH_MD5 && hash_method != JSEC_HASH_SHA1)
    {
        return JSEC_ERROR;
    }

    /* MD5: length 16 + che space 8*/
    if (hash_method == JSEC_HASH_MD5 && output_len < 16)
    {
        /* invalid buffer length */
        return JSEC_ERROR;
    }

    /* SHA1: length 20 + che space 8*/
    if (hash_method == JSEC_HASH_SHA1 && output_len < 20)
    {
        /* invalid buffer length */
        return JSEC_ERROR;
    }
    
    temp = jvm_malloc(1025);
    if (temp == NULL)
    {
        return JSEC_ERROR;
    }
    memset(temp,0,1025);
    
    count = file_size/1024; 
    if (file_size % 1024 == 0)
    {
        mod_complete = KAL_TRUE;
    }
    
    if (hash_method == JSEC_HASH_SHA1)
    {
        che_init(&che_context, CHE_SHA1);
    }
    else
    {
        che_init(&che_context, CHE_MD5);
    }
    
    for (; ;) 
    { 
        if ((index >= (kal_uint32)file_size)) 
        {
            break;
        }
                
        if(count == 0)
        {
            if (jvm_file_read(handle, temp, file_size) < 0)
            {
            	result = JSEC_ERROR;
            	goto done;
            }
            
            /* compute the hash value */
            if (hash_method == JSEC_HASH_SHA1)
            {
                ret = che_process(
                        &che_context,
                        CHE_SHA1,
                        CHE_MODE_NULL,
                        CHE_HASH,
                        (kal_uint8*)temp,
                        output,
                        file_size, 
                        KAL_TRUE);
            }
            else
            {
                ret = che_process(
                        &che_context,
                        CHE_SHA1,
                        CHE_MODE_NULL,
                        CHE_HASH,
                        (kal_uint8*)temp,
                        output,
                        file_size, 
                        KAL_TRUE);
            }
            if (!ret)
            {
                result = JSEC_HASH_FAIL;
                goto done;
            }
            
            break;
                    
        }
        else
        {
            if(i <= count)
            {
                if (jvm_file_read(handle, temp, 1024) < 0)
                {
                    result = JSEC_ERROR;
                    goto done;
                }
                
                /* compute the hash value */
                if (hash_method == JSEC_HASH_SHA1)
                {
                    if (i == count && mod_complete)
                    {
                        ret = che_process(
                                &che_context,
                                CHE_SHA1,
                                CHE_MODE_NULL,
                                CHE_HASH,
                                (kal_uint8*)temp,
                                output,
                                1024, 
                                KAL_TRUE);
                    }
                    else
                    {
                        ret = che_process(
                                &che_context,
                                CHE_SHA1,
                                CHE_MODE_NULL,
                                CHE_HASH,
                                (kal_uint8*)temp,
                                output,
                                1024, 
                                KAL_FALSE);
                    }
                }
                else
                {
                    if (i == count && mod_complete)
                    {
                        ret = che_process(
                                &che_context,
                                CHE_MD5,
                                CHE_MODE_NULL,
                                CHE_HASH,
                                (kal_uint8*)temp,
                                output,
                                1024, 
                                KAL_TRUE);
                    }
                    else
                    {
                        ret = che_process(
                                &che_context,
                                CHE_MD5,
                                CHE_MODE_NULL,
                                CHE_HASH,
                                (kal_uint8*)temp,
                                output,
                                1024, 
                                KAL_FALSE);
                    }
                }
                if (!ret)
                {
                    result = JSEC_HASH_FAIL;
                    goto done;
                }
                   
                index = index + 1024;
                i++;
            }
            else
            {
                memset(temp,0,1025);
                if (jvm_file_read(handle, temp, (file_size - (count*1024))) < 0)
                {
                    result = JSEC_ERROR;
                    goto done;
                }
       
                /* compute the hash value */
                if (hash_method == JSEC_HASH_SHA1)
                {
                    ret = che_process(
                        &che_context,
                        CHE_SHA1,
                        CHE_MODE_NULL,
                        CHE_HASH,
                        (kal_uint8*)temp,
                        output,
                        (file_size-(count*1024)), 
                        KAL_TRUE);
                }
                else
                {
                    ret = che_process(
                        &che_context,
                        CHE_MD5,
                        CHE_MODE_NULL,
                        CHE_HASH,
                        (kal_uint8*)temp,
                        output,
                        (file_size-(count*1024)), 
                        KAL_TRUE);
                }
                if (!ret)
                {
                    result = JSEC_HASH_FAIL;
                    goto done;
                }
                
                index= index + (file_size-(count*1024));
            }
        }
    }

done:
    if(temp!=NULL) 
    {
        jvm_free(temp);
    }
    che_deinit(&che_context);
    temp=NULL; 
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  jsec_get_cert_info
 * DESCRIPTION
 *  get the certificate info
 *  
 * PARAMETERS
 *  cert                 [IN]   input certificate
 *  cert_info            [OUT]   certificate info
 *
 * RETURNS
 *  JSEC_OK: get the certificate info successfully.
 *  JSEC_ERROR: fail to get the certificate info.
 *****************************************************************************/
kal_int8 jsec_get_cert_info(jsec_pki_data_struct *cert, 
                            jsec_cert_info_struct *cert_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pki_context_struct *pki_ctx;
    pki_x509_struct *x509_ctx;
    pki_error_enum pki_err;
    pki_name_struct *issuer;
    pki_name_struct *subject;
    const void *serial;
    kal_uint8 i;
    kal_uint32 serial_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cert == NULL || cert_info == NULL)
    {
        return JSEC_ERROR;
    }
    
    pki_err = pki_context_new(&pki_ctx);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_CREATE_CTX_FAIL, pki_err);
        return JSEC_ERROR;
    }
    
    pki_err = pki_x509_new(pki_ctx, (void *)cert->data, (kal_uint32)cert->size, &x509_ctx);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_CREATE_CTX_FAIL, pki_err);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }

    /* get the issuer info */
    pki_err = pki_x509_get_issuer(x509_ctx, &issuer);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_ISSUER_NAME_FAIL, pki_err);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }
    
    pki_err = pki_name_parse(issuer);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_PARSE_NAME_FAIL, pki_err);
        pki_name_release(&issuer);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }

    for (i = 0; i < JSEC_NAMETYPE_TOTAL; i++)
    {
        if (issuer->names[i])
        {
            /* count the name length */
            cert_info->issuer[i] = (kal_uint8 *)jvm_malloc(strlen(issuer->names[i]) + 1);
            strcpy((char *)cert_info->issuer[i], issuer->names[i]);
        }
    }

    pki_name_release(&issuer);
    /* get the subject info */
    pki_err = pki_x509_get_subject(x509_ctx, (pki_name_struct **)&subject);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_SUBJECT_NAME_FAIL, pki_err);
        jsec_free_cert_info(cert_info);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }
    
    pki_err = pki_name_parse(subject);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_PARSE_NAME_FAIL, pki_err);
        jsec_free_cert_info(cert_info);
        pki_name_release(&subject);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }

    for (i = 0; i < JSEC_NAMETYPE_TOTAL; i++)
    {
        if (subject->names[i])
        {
            /* count the name length */
            cert_info->subject[i] = (kal_uint8 *)jvm_malloc(strlen(subject->names[i]) + 1);
            strcpy((char *)cert_info->subject[i], subject->names[i]);
        }
    }

    pki_name_release(&subject);

    /* get serial number info */
    pki_err = pki_x509_get_serial(x509_ctx, (void **)&serial, &serial_len);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_SERIAL_NUM_FAIL, IO_ERROR);
        jsec_free_cert_info(cert_info);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }
    if (serial)
    {
        cert_info->serial_num = (kal_uint8 *)jvm_malloc(serial_len);
        memcpy(cert_info->serial_num, serial, serial_len);
        cert_info->serial_num_len = serial_len;
        pki_x509_data_release((void *)serial);
    }

    /* get signature algorithm */
    pki_err = pki_x509_get_signature_algorithm(x509_ctx, (pki_signature_alg *)&cert_info->sig_alg);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_SIG_FAIL, pki_err);
        jsec_free_cert_info(cert_info);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }

    /* get certificate version */
    pki_err = pki_x509_get_version(x509_ctx, &cert_info->version);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_VER_FAIL, pki_err);
        jsec_free_cert_info(cert_info);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }

    /* get valid date */
    pki_err = pki_x509_get_validity(x509_ctx, &cert_info->not_before, &cert_info->not_after);
    if (pki_err != PKI_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_VALID_DATE_FAIL, pki_err);
        jsec_free_cert_info(cert_info);
        pki_x509_release(&x509_ctx);
        pki_context_release(&pki_ctx);
        return JSEC_ERROR;
    }

    applib_dt_utc_sec_2_mytime(
            applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&cert_info->not_before, KAL_TRUE)),
            &cert_info->not_before,
            KAL_TRUE);
    applib_dt_utc_sec_2_mytime(
            applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&cert_info->not_after, KAL_TRUE)),
            &cert_info->not_after,
            KAL_TRUE);

    pki_x509_release(&x509_ctx);
    pki_context_release(&pki_ctx);
    return JSEC_OK;
}

/*****************************************************************************
 * FUNCTION
 *  jsec_free_cert_info
 * DESCRIPTION
 *  get the certificate info
 *  
 * PARAMETERS
 *  cert                 [IN]   input certificate
 *  cert_info            [OUT]   certificate info
 *
 * RETURNS
 *  JSEC_OK: release the certificate info space successfully.
 *  JSEC_ERROR: fail to release the certificate info.
 *****************************************************************************/
kal_int8 jsec_free_cert_info(jsec_cert_info_struct *cert_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cert_info == NULL)
    {
        return JSEC_ERROR;
    }
    /* release the issuer space */
    for (i = 0; i < JSEC_NAMETYPE_TOTAL; i++)
    {
        if (cert_info->issuer[i])
        {
            jvm_free(cert_info->issuer[i]);
        }
    }
    /* release the subject space */
    for (i = 0; i < JSEC_NAMETYPE_TOTAL; i++)
    {
        if (cert_info->subject[i])
        {
            jvm_free(cert_info->subject[i]);
        }
    }
    if (cert_info->serial_num)
    {
        jvm_free(cert_info->serial_num);
    }

    return JSEC_OK;
    
}

/*****************************************************************************
 * FUNCTION
 *  jsec_get_cert_name_len
 * DESCRIPTION
 *  get issuer or subject name length
 *  
 * PARAMETERS
 *  name      [IN]    issuer name or subject name (obtained from jsec_cert_info_struct)
 *
 * RETURNS
 *  JSEC_OK: get the certificate info successfully.
 *  JSEC_ERROR: fail to get the certificate info.
 *****************************************************************************/
kal_int32 jsec_get_cert_name_len(kal_uint8 *name[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_int32 name_len = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return JSEC_ERROR;
    }

    for (i = 0; i < JSEC_NAMETYPE_TOTAL; i++)
    {
        switch (i)
        {
            case JSEC_NAMETYPE_COMMON_NAME:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("CN=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;
                
            case JSEC_NAMETYPE_SERIAL_NUMBER:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("S=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_COUNTRY:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("C=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_STATE:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("ST=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_LOCALITY:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("L=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_ORGANISATION:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("O=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_ORGANISATION_UNIT:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("OU=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_SURNAME:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("SN=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_GIVEN_NAME:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("GN=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_INITIALS:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("I=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_DOMAIN_COMPONENT:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("DC=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            case JSEC_NAMETYPE_EMAIL_ADDRESS:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = strlen("E=") + name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;

            default:
                {
                    if (name[i])
                    {
                        /* count the name length */
                        name_len = name_len + 
                        strlen((const char *)name[i]) + strlen("; ");
                    }
                }
                break;
                
        }
    }

    name_len++;
    
    return name_len;
}

/*****************************************************************************
 * FUNCTION
 *  jsec_get_cert_name
 * DESCRIPTION
 *  get issuer or subject name. For example: "C=TW; CN=MTK; ST=TW; L=TW"
 *  
 * PARAMETERS
 *  name            [IN]    issuer or subject name (obtained from jsec_cert_info_struct)
 *  out_name_string [OUT]   combined issuer or subject name
 *
 * RETURNS
 *  JSEC_OK: get the certificate info successfully.
 *  JSEC_ERROR: fail to get the certificate info.
 *****************************************************************************/
kal_int8 jsec_get_cert_name(kal_uint8 *name[], kal_uint8 *out_name_string, kal_int32 out_name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    kal_int32 name_len = 0;
    kal_uint8 display_name[4];
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL || out_name_string == NULL)
    {
        return JSEC_ERROR;
    }

    for (i = 0; i < JSEC_NAMETYPE_TOTAL; i++)
    {
        memset(display_name, 0, 4);
        
        switch (i)
        {
            case JSEC_NAMETYPE_COMMON_NAME:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "CN=");
                    }
                }
                break;
                
            case JSEC_NAMETYPE_SERIAL_NUMBER:
                {
                     if (name[i])
                    {
                        strcpy((char *)display_name, "S=");
                    }
                }
                break;

            case JSEC_NAMETYPE_COUNTRY:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "C=");
                    }
                }
                break;

            case JSEC_NAMETYPE_STATE:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "ST=");
                    }
                }
                break;

            case JSEC_NAMETYPE_LOCALITY:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "L=");
                    }
                }
                break;

            case JSEC_NAMETYPE_ORGANISATION:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "O=");
                    }
                }
                break;

            case JSEC_NAMETYPE_ORGANISATION_UNIT:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "OU=");
                    }
                }
                break;

            case JSEC_NAMETYPE_SURNAME:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "SN=");
                    }
                }
                break;

            case JSEC_NAMETYPE_GIVEN_NAME:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "GN=");
                    }
                }
                break;

            case JSEC_NAMETYPE_INITIALS:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "I=");
                    }
                }
                break;

            case JSEC_NAMETYPE_DOMAIN_COMPONENT:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "DC=");
                    }
                }
                break;

            case JSEC_NAMETYPE_EMAIL_ADDRESS:
                {
                    if (name[i])
                    {
                        strcpy((char *)display_name, "E=");
                    }
                }
                break;

            default:
                break;
                
        }

        if (name[i])
        {
            if (strlen((char *)out_name_string) != 0)
            {
                name_len = name_len + strlen((char *)name[i]) + 
                    strlen("; ") + strlen((char *)display_name);
                if (name_len >= out_name_len)
                {
                    /* name is truncated */
                    kal_trace(TRACE_ERROR, JNW_TLS_NAME_IS_TRUNCATED);
                    return JSEC_OK;
                }
                if (strlen((char *)display_name) != 0)
                {
                    strcat((char *)out_name_string, "; ");
                    strcat((char *)out_name_string, (char *)display_name);
                    strcat((char *)out_name_string, (char *)name[i]);
                }
                else
                {
                    strcat((char *)out_name_string, "; ");
                    strcat((char *)out_name_string, (char *)name[i]);
                }
            }
            else
            {
                name_len = name_len + strlen((char *)name[i]) + strlen((char *)display_name);
                if (name_len >= out_name_len)
                {
                    /* name is truncated */
                    kal_trace(TRACE_ERROR, JNW_TLS_NAME_IS_TRUNCATED);
                    return JSEC_OK;
                }
                if (strlen((char *)display_name) != 0)
                {
                    strcpy((char *)out_name_string, (char *)display_name);
                    strcat((char *)out_name_string, (char *)name[i]);
                }
                else
                {
                    strcpy((char *)out_name_string, (char *)name[i]);
                }
            }
        }
    }
    return JSEC_OK;
}


#endif /* __SSL_SUPPORT__ */

