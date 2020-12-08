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
 *  jsec_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
*==============================================================================
*******************************************************************************/
#ifndef _JSEC_INTERFACE_H
#define _JSEC_INTERFACE_H

#ifdef __SSL_SUPPORT__

#ifndef __APP_DATETIME_H__
#include "app_datetime.h"
#endif

#ifndef PKI_API_H
#include "pki_api.h"
#endif

#endif /* __SSL_SUPPORT__ */

/*************************************************************************
* Constant values
*************************************************************************/

/*************************************************************************
* Enum values
*************************************************************************/
typedef enum {
    JSEC_HASH_NONE               = 0,
    JSEC_HASH_MD5                = 1,
    JSEC_HASH_SHA1               = 2,
    JSEC_HASH_TOTAL
} jsec_hash_alg_enum;

typedef enum {
    JSEC_OK             = 0,
    JSEC_ERROR          = -1,
    JSEC_HASH_FAIL      = -2,
    JSEC_VERIFY_FAIL    = -3,
    JSEC_ABORTED                    = -4,
    JSEC_CORRUPT_PROVIDER_CERT      = -5,
    JSEC_CERT_EXPIRED               = -6,
    JSEC_UNRECOGNIZED_CERT_ISSUER   = -7
} jsec_error_enum;

#ifdef __SSL_SUPPORT__

typedef enum
{
    JSEC_PKI_ECDSA_SHA1      = PKI_SIGNALG_ECDSA_SHA1,
    JSEC_PKI_ECDSA_SHA224    = PKI_SIGNALG_ECDSA_SHA224,
    JSEC_PKI_ECDSA_SHA256    = PKI_SIGNALG_ECDSA_SHA256,
    JSEC_PKI_ECDSA_SHA384    = PKI_SIGNALG_ECDSA_SHA384,
    JSEC_PKI_ECDSA_SHA512    = PKI_SIGNALG_ECDSA_SHA512,
    JSEC_PKI_DSA_SHA1        = PKI_SIGNALG_DSA_SHA1,
    JSEC_PKI_RSA_SHA1        = PKI_SIGNALG_RSA_SHA1,
    JSEC_PKI_RSA_MD5         = PKI_SIGNALG_RSA_MD5,
    JSEC_PKI_RSA_MD2         = PKI_SIGNALG_RSA_MD2,
    JSEC_PKI_RSA_SHA256      = PKI_SIGNALG_RSA_SHA256,
    JSEC_PKI_RSA_SHA384      = PKI_SIGNALG_RSA_SHA384,
    JSEC_PKI_RSA_SHA512      = PKI_SIGNALG_RSA_SHA512,
    JSEC_PKI_RSA_PSS_SHA1    = PKI_SIGNALG_RSA_PSS_SHA1,
    JSEC_PKI_RSA_PSS_SHA224  = PKI_SIGNALG_RSA_PSS_SHA224,
    JSEC_PKI_RSA_PSS_SHA256  = PKI_SIGNALG_RSA_PSS_SHA256,
    JSEC_PKI_RSA_PSS_SHA384  = PKI_SIGNALG_RSA_PSS_SHA384,
    JSEC_PKI_RSA_PSS_SHA512  = PKI_SIGNALG_RSA_PSS_SHA512,
    JSEC_PKI_TOTAL           = PKI_SIGNALG_TOTAL
} jsec_pki_signature_alg_enum;

typedef enum {
    JSEC_NAMETYPE_COMMON_NAME        = PKI_NAMETYPE_COMMON_NAME,
    JSEC_NAMETYPE_SERIAL_NUMBER      = PKI_NAMETYPE_SERIAL_NUMBER,
    JSEC_NAMETYPE_COUNTRY            = PKI_NAMETYPE_COUNTRY,
    JSEC_NAMETYPE_STATE              = PKI_NAMETYPE_STATE,
    JSEC_NAMETYPE_LOCALITY           = PKI_NAMETYPE_LOCALITY,
    JSEC_NAMETYPE_ORGANISATION       = PKI_NAMETYPE_ORGANISATION,
    JSEC_NAMETYPE_ORGANISATION_UNIT  = PKI_NAMETYPE_ORGANISATION_UNIT,
    JSEC_NAMETYPE_TITLE              = PKI_NAMETYPE_TITLE,
    JSEC_NAMETYPE_SURNAME            = PKI_NAMETYPE_SURNAME,
    JSEC_NAMETYPE_GIVEN_NAME         = PKI_NAMETYPE_GIVEN_NAME,
    JSEC_NAMETYPE_INITIALS           = PKI_NAMETYPE_INITIALS,
    JSEC_NAMETYPE_DOMAIN_COMPONENT   = PKI_NAMETYPE_DOMAIN_COMPONENT,
    JSEC_NAMETYPE_EMAIL_ADDRESS      = PKI_NAMETYPE_EMAIL_ADDRESS,
    JSEC_NAMETYPE_TOTAL              = PKI_NAMETYPE_TOTAL
} jsec_name_structype_enum;

#endif /* __SSL_SUPPORT__ */


/*************************************************************************
* Structures
*************************************************************************/
typedef struct
{
    const void *data;
    kal_uint32 size;
} jsec_pki_data_struct;

#ifdef __SSL_SUPPORT__

typedef struct
{
    jsec_pki_signature_alg_enum  sig_alg; /* signature algorithm */
    kal_uint32  version; /* certificate version */
    kal_uint8 *serial_num; /* serial number */
    kal_uint32 serial_num_len; /* serial number length*/
    kal_uint8 *issuer[JSEC_NAMETYPE_TOTAL]; /* issuer name: space must be free by the caller */
    kal_uint8 *subject[JSEC_NAMETYPE_TOTAL]; /* subject name: space must be free by the caller */
    applib_time_struct not_before;
    applib_time_struct not_after;
} jsec_cert_info_struct;


/*************************************************************************
* External APIs
*************************************************************************/
extern kal_int8 jsec_gen_hash(kal_int32 handle, kal_int32 file_size, 
                       jsec_hash_alg_enum hash_method, kal_uint8 *output,
                       kal_uint8 output_len);
extern kal_int8 jsec_get_cert_info(jsec_pki_data_struct *cert, 
                            jsec_cert_info_struct *cert_info);
extern kal_int8 jsec_free_cert_info(jsec_cert_info_struct *cert_info);

#endif /* __SSL_SUPPORT__ */


extern kal_int8 jsec_pem_decode(kal_uint8 *encCert, kal_uint32 encCert_len,
                         kal_uint8 **derCert, kal_uint32 *derCert_len);

extern kal_int8 jsec_verify_cert_chain(jsec_pki_data_struct *verify_cert,
                                       kal_uint8 verify_cert_num,
                                kal_bool tck_mode,
                                jsec_pki_data_struct *trusted_cert);
extern kal_int8 jsec_verify_signature(jsec_pki_data_struct *sig,
                               jsec_pki_data_struct *cert,
                               jsec_hash_alg_enum hash_method,
                               kal_int32 verify_file_id,
                               kal_uint32 file_size);
extern kal_int32 jsec_get_cert_name_len(kal_uint8 *name[]);
extern kal_int8 jsec_get_cert_name(kal_uint8 *name[], kal_uint8 *out_name_string, kal_int32 out_name_len);

#endif /* _JSEC_INTERFACE_H */

