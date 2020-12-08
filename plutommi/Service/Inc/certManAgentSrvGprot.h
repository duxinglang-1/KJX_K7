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
 *   certManAgentSrvGprot.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file for certman SDK API.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *        HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __CERTMAN_AGENT_SRV_GPROT_H__ 
#define __CERTMAN_AGENT_SRV_GPROT_H__
 
#ifdef __CERTMAN_SUPPORT__
#include "MMIDatatype.h"

/*Constants*/

#define SRV_CERTMAN_NUM_PARSED_CERT         20  /* Maximum number of certificates allowed to parse in a single parse request.*/
#define SRV_CERTMAN_LABEL_LENGTH            64  /* Maximum supported certificate label name length. (ASCII characters not including zero-terminate)*/
#define SRV_CERTMAN_LABEL_SIZE              SRV_CERTMAN_LABEL_LENGTH + 2  /* Certificate label name string buffer size, including 2 bytes zero-terminate in case of UCS2 encoding. */
#define SRV_CERTMAN_SERIAL_SIZE             20  /* Maximum number of bytes in certificate's serial number. */
#define SRV_CERTMAN_NUM_ID_IN_LIST          20  /* Maximum number of IDs listed per response. */
#define SRV_CERTMAN_NUM_CERT_IN_LIST        12  /* Maximum number of certificate list elements per response. */
#define SRV_CERTMAN_NUM_CERT_IN_CHAIN_DISP  10  /* Maximum number of certificates in chain for display purpose. */
#define SRV_CERTMAN_FILENAME_LENGTH         260 /* Maximum supported length of filename.*/
#define SRV_CERTMAN_SHA1_SIZE               20  /* SHA-1 hash length (number of bytes). */
#define SRV_CERTMAN_NUM_KEYTYPE_IN_LIST     10  /* Maximum number of public key types per get certificates by issuers file request. */
#define SRV_CERTMAN_PKPWD_SIZE        60  /* max private key file password length (not NULL-terminated) */
#define SRV_CERTMAN_NUM_CERT_IN_VALIDATE    20  /* Maximum number of certificates in validate request certificate chain. */



/* This enum defines the possible error codes returned from Certman Service.*/
typedef enum
{
    SRV_CERTMAN_ERR_NONE,                         /* 0 : Success. */                                                                 
    SRV_CERTMAN_ERR_FAIL,                         /* 1 : General error. */                                                           
    SRV_CERTMAN_ERR_MEMFULL,                      /* 2 : Memory full error. */                                                       
    SRV_CERTMAN_ERR_INVALID_CONTEXT,              /* 3 : Input context error. */                                                     
    SRV_CERTMAN_ERR_OUT_OF_RANGE,                 /* 4 : Specified item out of range in decoding process. */                         
    SRV_CERTMAN_ERR_INCORRECT_PASSWORD,           /* 5 : The input password is incorrect. */                                         
    SRV_CERTMAN_ERR_FS_ERROR,                     /* 6 : File system operation failed. */                                            
    SRV_CERTMAN_ERR_NEED_PASSWORD,                /* 7 : Password required operation notification. */                                      
    SRV_CERTMAN_ERR_INVALID_INPUT,                /* 8 : Input paramaters are invalid. */                                            
    SRV_CERTMAN_ERR_EXT_NOT_FOUND,                /* 9 : Specified extension is not found. */                                        
    SRV_CERTMAN_ERR_ISSUER_UID_NOT_FOUND,         /* 10 : The issuer uid is not found in specified certificate. */                   
    SRV_CERTMAN_ERR_SUBJECT_UID_NOT_FOUND,        /* 11 : The subject uid is not found in specified certificate. */                  
    SRV_CERTMAN_ERR_UNSUPPORTED_CONTENT,          /* 12 : The specified content can't be parsed. */                                  
    SRV_CERTMAN_ERR_CERT_NOT_FOUND,               /* 13 : Can't find certificate in PEM decoding. */                                 
    SRV_CERTMAN_ERR_CORRUPTED_DATA,               /* 14 : The input data is corrupted. */                                            
    SRV_CERTMAN_ERR_EXCEED_MAX_DATA_SIZE,         /* 15 : The specified pkcs7 or pkcs12 data exceeds predefined maximum size for importing. */
    SRV_CERTMAN_ERR_NOT_SUPPORTED_OP,             /* 16 : Special return value for subject name hash utility. */
    SRV_CERTMAN_ERR_FIRST_BOOTUP,                 /* 17 : First bootup operation for preinstalled certificates. */
    SRV_CERTMAN_ERR_KEY_NOT_FOUND,                /* 18 : Key not found in Certman Service database. */
    SRV_CERTMAN_ERR_ISSUER_NOT_FOUND,             /* 19 : Issuer name can't be found in provided issuer names file. */
    SRV_CERTMAN_ERR_ID_ALREADY_EXISTS,            /* 20 : The specified certificate ID already exists. */
    SRV_CERTMAN_ERR_FILE_NOT_FOUND,               /* 21 : File not found error. */
    SRV_CERTMAN_ERR_DISK_FULL,                    /* 22 : Disk full error. */
    SRV_CERTMAN_ERR_FILE_CORRUPTED,               /* 23 : The file content is corrupted or not supported. */
    SRV_CERTMAN_ERR_INVALID_LABEL,                /* 24 : Label string is invalid. */
    SRV_CERTMAN_ERR_INVALID_CERT_GROUP,           /* 25 : Specified certificate group is invalid. */
    SRV_CERTMAN_ERR_INVALID_KEY_PURPOSE,          /* 26 : Specified key purpose is invalid. */
    SRV_CERTMAN_ERR_INVALID_KEY_TYPE,             /* 27 : Specified key type is invalid. */
    SRV_CERTMAN_ERR_INVALID_DOMAIN,               /* 28 : Specified certificate domain is invalid. */
    SRV_CERTMAN_ERR_INVALID_FILENAME,             /* 29 : Specified filename parameter is invalid. */
    SRV_CERTMAN_ERR_INVALID_DATA,                 /* 30 : Specified data or data length parameter is invalid. */
    SRV_CERTMAN_ERR_INVALID_ENCODING,             /* 31 : Specified data encoding type is invalid. */
    SRV_CERTMAN_ERR_INVALID_JOB,                  /* 32 : Specified job ID is invalid in parsing and import process. */
    SRV_CERTMAN_ERR_INVALID_CERT_ID,              /* 33 : Specified Certificate ID is invalid. */
    SRV_CERTMAN_ERR_INVALID_PASSWORD,             /* 34 : Specified password parameters is invalid. */
    SRV_CERTMAN_ERR_INVALID_PATH,                 /* 35 : Specified path parameter is invalid. */
    SRV_CERTMAN_ERR_INVALID_VALIDATION_PARAM,     /* 36 : Specified validation parameters is invalid. */
    SRV_CERTMAN_ERR_NO_PWD_CALLBACK,              /* 37 : No specified password callback function for Certman Service. */
    SRV_CERTMAN_ERR_LABEL_EXISTS,                 /* 38 : Label duplicated error. */
    SRV_CERTMAN_ERR_CERT_EXISTS,                  /* 39 : Specified certificate had been imported before. */
    SRV_CERTMAN_ERR_KEY_PURPOSE_DENIED,           /* 40 : Key purpose denied for specified operation. */
    SRV_CERTMAN_ERR_ACCESS_DENIED,                /* 41 : Key usage request denied. */
    SRV_CERTMAN_ERR_READ_ONLY,                    /* 42 : The certificate is read_only one. */
    SRV_CERTMAN_ERR_CERT_IN_USE,                  /* 43 : The certificate is inuse. */
    SRV_CERTMAN_ERR_CHAIN_NOT_ALLOWED,            /* 44 : Certificate chain validation failed. */
    SRV_CERTMAN_ERR_CHAIN_TOO_LARGE,              /* 45 : Certificate chain length exceeds the maximum permitted value (SRV_CERTMAN_NUM_CERT_IN_CHAIN_DISP). */
    SRV_CERTMAN_ERR_TOO_MANY_CERTS,               /* 46 : Too many certificates in validate request cert chain array. */
    SRV_CERTMAN_ERR_CERT_EXPIRED,                 /* 47 : Certificate was expired before. */
    SRV_CERTMAN_ERR_NO_TRUSTED_CERT_FOUND,        /* 48 : No trusted certificate found in passed certificate chain. */
    SRV_CERTMAN_ERR_CONVERT_FAIL,                 /* 49 : Database information file encode/decode error. */
    SRV_CERTMAN_ERR_FILE_TOO_LARGE,               /* 50 : The input text file is too large to parse. */
    SRV_CERTMAN_ERR_WOULDBLOCK,                   /* 51 : The operation cannot finish immediately. */
    SRV_CERTMAN_ERR_RETRY,                        /* 52 : Request timeout, retry again. */
    SRV_CERTMAN_ERR_NO_RESPONSE,                  /* 53 : No OCSP response from server. */
    SRV_CERTMAN_ERR_TOTAL                         /* 54 : Maximum possible error value. */
}srv_certman_error_enum;






/* This enum defines the Certman Service private key protection settings. 
 * Application must pass appropriate method to protect the private key.
 */
typedef enum
{
    SRV_CERTMAN_PROTECT_NONE,           /* No protection setting is specified. */
    SRV_CERTMAN_PROTECT_USAGE_CONFIRM,  /* Ask for user confirmation before using this private key. */
    SRV_CERTMAN_PROTECT_USAGE_PASSWORD  /* Ask for password before using this private key. */
}srv_certman_privkey_protection_enum;




/* This enum defines the supported certificate types by Certman Service. */
typedef enum
{
    SRV_CERTMAN_CERTTYPE_X509,          /* x509 certificate type */
    SRV_CERTMAN_CERTTYPE_JAVA_X509,     /* x509 java certificate type (Certman Service internal use for java certificates filter) */
    SRV_CERTMAN_CERTTYPE_JAVA_TCK,      /* JAVA TCK Certificate type (Certman Service internal use for java TCK certificates filter) */    
    SRV_CERTMAN_CERTTYPE_GADGET         /* Gadget Certificate. */            
} srv_certman_certtype_enum;




/* This enum defines the Certman Service certificate group filter settings.
 * Different certificates can be classified into different groups as defined.
 */
typedef enum
{
    SRV_CERTMAN_CERTGRP_NONE,           /* Certificate group is not defined. */
    SRV_CERTMAN_CERTGRP_ROOTCA,         /* Specified certificate group filter for root certificates (Issuer = Subject). */
    SRV_CERTMAN_CERTGRP_CA,             /* Specified certificate group filter for intermediately certificate (Version 3 certificate with BasicConstraint: CA=TRUE). */
    SRV_CERTMAN_CERTGRP_OTHERUSER,      /* Specified certificate group filter for other end-entity certificate (Version 3 certificate with BasicConstraint: CA=FALSE OR version 1 cert with no private key associated). */
    SRV_CERTMAN_CERTGRP_PERSONAL,       /* Specified certificate group filter for personal certificate (Associated with a private key (regardless of whether it's a CA cert)). */
    SRV_CERTMAN_CERTGRP_ANY             /* This group filter will match with all certificates. */
} srv_certman_cert_group_enum;





/* This enum defines the Certman Service key usage extension settings as defined in X509 spec. */
typedef enum
{
    SRV_CERTMAN_KP_NONE,                        /* No specified extension key usage */
    SRV_CERTMAN_KP_SERVER_AUTH,                 /* Extension key usage : server authentication assert. */
    SRV_CERTMAN_KP_CLIENT_AUTH,                 /* Extension key usage : client authentication assert. */
    SRV_CERTMAN_KP_CODE_SIGNING,                /* Extension key usage : code signing assert. */
    SRV_CERTMAN_KP_EMAIL_PROTECTION,            /* Extension key usage : email protection assert. */
    SRV_CERTMAN_KP_IPSEC_ENDSYSTEM,             /* Extension key usage : IPSec end system assert. */
    SRV_CERTMAN_KP_IPSEC_TUNNEL,                /* Extension key usage : IPSec tunneling assert. */
    SRV_CERTMAN_KP_IPSEC_USER,                  /* Extension key usage : IPSec user assert. */
    SRV_CERTMAN_KP_TIME_STAMPING,               /* Extension key usage : Time stamp assert. */
    SRV_CERTMAN_KP_OCSP_SIGNING,                /* Extension key usage : OCSP signing assert. */
    SRV_CERTMAN_KP_ALL                          /* All key usage. */
} srv_certman_keypurpose_enum;





/* This enum defines string encoding. */
typedef enum
{
    SRV_CERTMAN_DCS_ASCII,      /* ASCII encoding string. */
    SRV_CERTMAN_DCS_UCS2        /* UCS2 encoding string. */
} srv_certman_dcs_enum;





/* This enum defines the public key types supported by Certman service. */
typedef enum
{
    SRV_CERTMAN_PUBKEY_RSA,             /* Public key type is RSA.*/
    SRV_CERTMAN_PUBKEY_DSA,             /* Public key type is DSA.*/
    SRV_CERTMAN_PUBKEY_DH_ANSI,         /* Public key type is DH (ANSI)*/
    SRV_CERTMAN_PUBKEY_DH_PKCS3,        /* Public key type is DH (PKCS3)*/
    SRV_CERTMAN_PUBKEY_EC,              /* Public key type is EC*/
    SRV_CERTMAN_PUBKEY_TOTAL            /* Total number of public key types supported.*/
} srv_certman_pubkey_type_enum;






/* This enum defines the Certman Service domain filter settings. */
typedef enum
{
    SRV_CERTMAN_DOMAIN_NONE,                    /* Domain filter is not specified. */
    SRV_CERTMAN_DOMAIN_UNTRUSTED,               /* Filter for certificates from untrusted domain. */
    SRV_CERTMAN_DOMAIN_OPERATOR,                /* Filter for certificates from operator domain.*/
    SRV_CERTMAN_DOMAIN_MANUFACTURER,            /* Filter for certificates installed by manufacturer. */
    SRV_CERTMAN_DOMAIN_THIRD_PARTY,             /* Filter for certificates installed by Third party. */
    SRV_CERTMAN_DOMAIN_ANY                      /* Filter for all domain certificates. */
} srv_certman_domain_enum;



  
/* This enum defines the certificate encoding types supported by Certman Service.*/
typedef enum
{
    SRV_CERTMAN_ENC_UNSUPPORTED = 0x00,         /* Content format is not supported. */
    SRV_CERTMAN_ENC_DER = 0x01,                 /* Single DER encoded X.509 certificate. */
    SRV_CERTMAN_ENC_PEM = 0x02,                 /* Base64 encoded list of X.509 certificates wrapped within multiple PEM begin/end header. */
    SRV_CERTMAN_ENC_PK7 = 0x04,                 /* DER/PEM encoded PKCS #7 file (list of certificates). */
    SRV_CERTMAN_ENC_PK12 = 0x08,                /* DER/PEM encoded PKCS #12 file (1 private key + 1 or more certificates OR 1 or more certificates). */
    SRV_CERTMAN_ENC_PEM_USER_CERT = 0x10        /* PEM encoded client cert file (1 private key + multiple certificates). */
} srv_certman_encoding_enum;




/*This enum defines options from OCSP verification.*/
typedef enum {
    SRV_CERTMAN_OCSP_OPT_USE_OCSP    = 0x01 << 0, /* Enable OCSP validation */
    SRV_CERTMAN_OCSP_OPT_MUST_PASS   = 0x01 << 1, /* Must pass OCSP validation */
} srv_certman_ocsp_opt_enum;




/* This enum defines parsed certificate groups defined by Certman Service. */
typedef enum
{
    SRV_CERTMAN_PARSED_CERTGRP_ALL,         /* Total numbers of certificates in certificate file being parsed. */
    SRV_CERTMAN_PARSED_CERTGRP_ROOTCA,      /* Total numbers of root ca certificates in certificate file being parsed. */
    SRV_CERTMAN_PARSED_CERTGRP_OTHERCA,     /* Total numbers of intermediately ca certificates incertificate file being parsed. */
    SRV_CERTMAN_PARSED_CERTGRP_OTHERUSER,   /* Total numbers of other user certificates in certificate file being parsed. */
    SRV_CERTMAN_PARSED_CERTGRP_PERSONAL,    /* Total numbers of personal certificates in certificate file being parsed. */
    SRV_CERTMAN_PARSED_CERTGRP_SIZE
} srv_certman_parsed_cert_group_enum;




/* This enum defines the Certman Service defined name types identifier for different fields in a certificate.*/
typedef enum {
    SRV_CERTMAN_NAMETYPE_COMMON_NAME,                   /* Common name. */
    SRV_CERTMAN_NAMETYPE_SERIAL_NUMBER,                 /* Serial. */        
    SRV_CERTMAN_NAMETYPE_COUNTRY,                       /* Country name. */                    
    SRV_CERTMAN_NAMETYPE_STATE,                         /* State name. */
    SRV_CERTMAN_NAMETYPE_LOCALITY,                      /* Locality. */
    SRV_CERTMAN_NAMETYPE_ORGANISATION,                  /* Organization name. */
    SRV_CERTMAN_NAMETYPE_ORGANISATION_UNIT,             /* Organization unit name. */
    SRV_CERTMAN_NAMETYPE_TITLE,                         /* Title. */
    SRV_CERTMAN_NAMETYPE_SURNAME,                       /* Surname. */
    SRV_CERTMAN_NAMETYPE_GIVEN_NAME,                    /* Given name. */
    SRV_CERTMAN_NAMETYPE_INITIALS,                      /* Initials. */
    SRV_CERTMAN_NAMETYPE_DOMAIN_COMPONENT,              /* Domain component name. */
    SRV_CERTMAN_NAMETYPE_EMAIL_ADDRESS,                 /* E-mail address. */
    SRV_CERTMAN_NAMETYPE_SIZE
} srv_certman_name_type_enum;





/* This enum defines siganture algorithms supported by the Certman Service.*/
typedef enum
{
    SRV_CERTMAN_SIGNALG_ECDSA_SHA1,                 /* ECDSA + SHA1 */
    SRV_CERTMAN_SIGNALG_ECDSA_SHA224,               /* ECDSA + SHA1-224 bits digest */
    SRV_CERTMAN_SIGNALG_ECDSA_SHA256,               /* ECDSA + SHA1-256 bits digest */
    SRV_CERTMAN_SIGNALG_ECDSA_SHA384,               /* ECDSA + SHA1-384 bits digest */
    SRV_CERTMAN_SIGNALG_ECDSA_SHA512,               /* ECDSA + SHA1-512 bits digest */
    SRV_CERTMAN_SIGNALG_DSA_SHA1,                   /* DSA + SHA1 */
    SRV_CERTMAN_SIGNALG_RSA_SHA1,                   /* RSA + SHA1 */
    SRV_CERTMAN_SIGNALG_RSA_MD4,                    /* RSA + MD4 */
    SRV_CERTMAN_SIGNALG_RSA_MD5,                    /* RSA + MD5 */
    SRV_CERTMAN_SIGNALG_RSA_MD2,                    /* RSA + MD2 */
    SRV_CERTMAN_SIGNALG_RSA_SHA256,                 /* RSA + SHA1-256 bits digest */
    SRV_CERTMAN_SIGNALG_RSA_SHA384,                 /* RSA + SHA1-384 bits digest */
    SRV_CERTMAN_SIGNALG_RSA_SHA512,                 /* RSA + SHA1-512 bits digest */
    SRV_CERTMAN_SIGNALG_RSA_PSS_SHA1,               /* RSA-PSS + SHA1 */
    SRV_CERTMAN_SIGNALG_RSA_PSS_SHA224,             /* RSA-PSS + SHA1-224 bits digest */
    SRV_CERTMAN_SIGNALG_RSA_PSS_SHA256,             /* RSA-PSS + SHA1-256 bits digest */
    SRV_CERTMAN_SIGNALG_RSA_PSS_SHA384,             /* RSA-PSS + SHA1-384 bits digest */
    SRV_CERTMAN_SIGNALG_RSA_PSS_SHA512,             /* RSA-PSS + SHA1-512 bits digest */
    SRV_CERTMAN_SIGNALG_TOTAL
} srv_certman_signature_alg_enum;





/* This enum defines the Certman Service certificate storage location. */
typedef enum
{
    SRV_CERTMAN_STORAGE_PHONE,          /* Certman Service certificate storage location setting is phone. */
    SRV_CERTMAN_STORAGE_SIM             /* Certman Service certificate storage location setting is SIM card. (not support yet) */
} srv_certman_storage_enum;








/* 
 * This structure is used for store time stamp.
 */
typedef struct
{
    U16 nYear;          /* Year.*/
    U8  nMonth;         /* Month. */
    U8  nDay;           /* Day. */
    U8  nHour;          /*Hour. */
    U8  nMin;           /* Minute. */
    U8  nSec;           /* Second. */
    U8  DayIndex;       /* Day index. (0=Sunday) */
} srv_certman_time_struct;





/* This structure defines the structure for get certificate list by type request to Certman Service. */
typedef struct
{
    U16     num_ids;            /* Number of certificates in list array. */
    U32     *cert_ids;          /* Certificate list array. */
}srv_certman_cert_ids_result_struct;




/* This structure is designed for input in validation request to Certman Service. */
typedef struct
{
    srv_certman_certtype_enum   type;     /*Certificate typ. e*/
    void                        *data;                      /*Certificate Data. */
    U32                         size;                       /*Certificate Data Size. */
}srv_certman_cert_data_struct;





/* This sturcture is designed for parsed info response. */
typedef struct
{
    U32  cert_ref_ids[SRV_CERTMAN_NUM_PARSED_CERT];     /* Reference IDs of certificates in this parse context. */
    U16  cert_count;                                    /* The total numbers of certificates in this parse context. */
} srv_certman_parsed_info_struct;




/* This structure defines the display name string array. It contains all strings to displayed an indexed by srv_certman_name_type_enum. */
typedef struct
{
    U8                      *names[SRV_CERTMAN_NAMETYPE_SIZE];      /* Array indexed by srv_certman_name_type_enum, each element is a zero-terminated string. */
    srv_certman_dcs_enum    dcs[SRV_CERTMAN_NAMETYPE_SIZE];         /* Encoding type of the corresponding name string in "names" array. */
} srv_certman_disp_name_struct;





/* This sturct defines the display attributes of one certificate. */
typedef struct
{
    srv_certman_certtype_enum       cert_type;                              /* Certificate type (certman_certtype_enum). */
    U8                              label[SRV_CERTMAN_LABEL_SIZE];          /* Certificate label. */
    srv_certman_dcs_enum            dcs_label;                              /* The dcs of label. */
    U32                             version;                                /* Certificate version, 3 means version 3.. etc.  */
    U32                             serial_size;                            /* Number of valid bytes in "serial" array. */
    U8                              serial[SRV_CERTMAN_SERIAL_SIZE];        /* This is not a string. This array must be treated as an array of octets forming the serial number long integer. */
    srv_certman_disp_name_struct    issuer;                                 /* Issuer name string. */
    srv_certman_disp_name_struct    subject;                                /* Subject name string. */
    srv_certman_time_struct         valid_from;                             /* Valid not before information. */
    srv_certman_time_struct         valid_until;                            /* Valid not after information. */
    U8                              fngrprt_sha1[SRV_CERTMAN_SHA1_SIZE];    /* This is not a string. This array contains SRV_CERTMAN_SHA1_SIZE octets for the certificate's finger print. */
    srv_certman_signature_alg_enum  sigalg;                                 /* Associated signature algorithm. */
} srv_certman_cert_display_struct;




/* This struct defines the returned detailed certificate attributes. */
typedef struct
{
    srv_certman_cert_display_struct     cert;           /* The certificate display data. */
    U8                                  not_validated;  /* Valid information, 1 means validated. */
    U8                                  cert_exists;    /* Certificate already exists in Certman Service's database, must not allow user to import this certificate again. */
    srv_certman_cert_group_enum         cert_group;     /* Certificate group. */
    U8                                  cert_expired;   /* Set to 1 when this certificate has expired. Application should warn user before importing. */
    srv_certman_keypurpose_enum         key_purposes;   /* Certificate key purpose. */
} srv_certman_parsed_data_struct;




/* This structure defines the information about a certificate that is useful on our device. */
typedef struct
{
    U32                             id;                                 /* Unique certificate ID assigned by Certman Service. */
    U8                              label[SRV_CERTMAN_LABEL_SIZE];      /* Unique certificate label specified by user. */
    srv_certman_dcs_enum            dcs;                                /* Label string decoding. */
    U32                             properties;                         /* An OR'd result of values from srv_certman_property_enum. */
    srv_certman_cert_group_enum     group;                              /* Group from the certificate belongs. */
    srv_certman_domain_enum         domain;                             /* Domain from the certificate belongs. */
    srv_certman_storage_enum        storage;                            /* Storage of the certificate. */
    srv_certman_keypurpose_enum     key_purpose_all;                    /* All key purposes of certificate. This is an OR'd result of values from srv_certman_keypurpose_enum. */
    srv_certman_keypurpose_enum     key_purpose_allowed;                /* Allowed key purposes of certificate. These are used to check against key usage purposes provided by certificate retriever. */
} srv_certman_cert_list_elem_struct;




/* This structure defines response for request get certificate list by group from the Certman Service. */
typedef struct
{
    srv_certman_cert_group_enum         cert_group;                                 /* Group from the certificate belongs. */
    srv_certman_keypurpose_enum         key_purpose;                                /* All key purposes of certificate. */
    srv_certman_pubkey_type_enum        pubkey_type;                                /* Public key type filter OR'd by srv_certman_pubkey_type_enum. */
    srv_certman_cert_list_elem_struct   cert_list[SRV_CERTMAN_NUM_CERT_IN_LIST];    /* Filtered out certificate list. */
    U16                                 size;                                       /* The number of certificates in list array. */
    U16                                 more;                                       /* The progress index value returned to caller for continuous querying. */
} srv_certman_cert_list_by_group_struct;




/* This structure defines the Certman Service get certificate list by domain result. */
typedef struct
{
    srv_certman_domain_enum                 domain;                                     /* Domain(s) from the certificate belongs. */
    srv_certman_keypurpose_enum             key_purpose;                                /* All key purposes of certificate. */
    srv_certman_cert_list_elem_struct       cert_list[SRV_CERTMAN_NUM_CERT_IN_LIST];    /* Filtered out certificate list. */
    U16                                     size;                                       /* The number of certificates in list array. */
    U16                                     more;                                       /* The progress index value returned to caller for continuous querying. */
} srv_certman_cert_list_by_domain_struct;





/* This structure defines the Certman Service public key object. */
typedef struct
{
    void *data;     /* public key data */
    U32  size;      /* public key data length */
} srv_certman_pubkey_struct;




/* This structure defines the Certman Service get certificate display information by specified ID.*/
typedef struct
{
    U32                                 cert_id;        /* Specified certificate ID. */
    srv_certman_keypurpose_enum         key_purpose;    /* All key purposes of certificate. */
    srv_certman_cert_list_elem_struct   cert_info;      /* Associate certificate information in Certman Service database. */
    srv_certman_cert_display_struct     cert;           /* Certificate display content. */
    U8                                  has_pubkey;     /* If this certificate has public key.. */
    srv_certman_pubkey_type_enum        pubkey_type;    /* Type of public key. */
    union
    {
        srv_certman_pubkey_struct       *key;           /* Public key of the certificate. */
    } pubkey;                                           /* Public key of the certificate. */
} srv_certman_cert_disp_by_id_struct;




/* This structure defines the Certman Service get certificate chain display information by specified ID response. */
typedef struct
{
    U8                          labels[SRV_CERTMAN_NUM_CERT_IN_CHAIN_DISP][SRV_CERTMAN_LABEL_SIZE]; /* 2 dimension array for certicates' label string of certificates in chain. */
    srv_certman_dcs_enum        dcs[SRV_CERTMAN_NUM_CERT_IN_CHAIN_DISP];                            /* Each label string dcs in label string array. */
    U32                         size;                                                               /* The number of certificates in chain. */
} srv_certman_cert_chain_disp_by_id_struct;




/* This structure defines the Certman Service get certificate IDs by group response. */
typedef struct
{
    srv_certman_cert_group_enum             cert_group;                             /* Certificate group filter OR'd by srv_certman_cert_group_enum. */
    srv_certman_keypurpose_enum             key_purpose;                            /* All key purposes of certificate. */
    U32                                     certids[SRV_CERTMAN_NUM_ID_IN_LIST];    /* The filtered certificate IDs array. */
    U16                                     size;                                   /* The number of IDs in certids array. */
    U16                                     more;                                   /* The progress index value returned to caller for continuous querying. */
} srv_certman_certid_by_group_struct;




/* This structure defines the Certman Service get certificate IDs by domain response. */
typedef struct
{
    srv_certman_domain_enum                 domain;                                 /* Domain(s) from the certificate belongs. */
    srv_certman_keypurpose_enum             key_purpose;                            /* All key purposes of certificate. */
    U32                                     certids[SRV_CERTMAN_NUM_ID_IN_LIST];    /* The filtered certificate IDs array. */
    U16                                     size;                                   /* The number of IDs in certids array. */
    U16                                     more;                                   /* The progress index value returned to caller for continuous querying. */
} srv_certman_certid_by_domain_struct;




/* This structure defines the Certman Service get certificate data by specified ID response. */
typedef struct
{
    U32                     cert_id;                                    /* Specified certificate ID. */
    U16                     filename[SRV_CERTMAN_FILENAME_LENGTH+1];    /* DER/PEM encoded single X.509 certificate. */
} srv_certman_cert_by_id_struct;



/* This structure defines the Certman Service get certificate chain by specified ID response. */
typedef struct
{
    U32                     num_certs;
    U32                     cert_id;                                    /* Specified certificate ID. */
    U16                     filename[SRV_CERTMAN_FILENAME_LENGTH+1];    /* DER/PEM encoded single X.509 certificate. */
} srv_certman_cert_chain_struct;




/* This structure defines the Certman Service signature verify utility parameters. */
typedef struct
{
    srv_certman_signature_alg_enum      hash_alg;       /*Hash algorithn id.*/
    void                                *hash_data;     /*Hash data buffer.*/
    U32                                 hash_len;       /*Length of hash data buffer.*/
    void                                *signature;     /*Buffer for signature.*/
    U32                                 sig_len;        /*Signature length.*/
} srv_certman_signature_vfy_params_struct;




/* This structure defines the trusted certificate data object in Certman Service validation response message. */
typedef struct
{
    U16         filename[SRV_CERTMAN_FILENAME_LENGTH+1];    /* DER encoded X509 cert. */
    U32         size;                                       /* Size of certificate data stored in file. */
    U32         cert_id;                                    /* Specified certificate ID. */
} srv_certman_trusted_cert_struct;




/* This structure defines the Certman Service validate response message. */
typedef struct
{
    srv_certman_trusted_cert_struct     trusted_cert;       /* The trusted certificate data information. */
    U8                                  has_trusted_cert;   /* If the chain has trusted certificate, it will be set to TRUE. */
} srv_certman_validate_struct;




/* This structure defines the user-specific customizable network parameters for OCSP verification. */
typedef struct {
    U32  data_account;          /* User specific data account to access network. */
    U8   proxy_addr[4];         /* User specific proxy address */
    U16  proxy_port;            /* User specific proxy port */
} srv_certman_ocsp_network_profile_struct;



typedef srv_certman_cert_by_id_struct srv_certman_trusted_cert_by_id_struct;
typedef srv_certman_cert_by_id_struct srv_certman_privkey_struct;




/*********************Result Callback Types **********************************/






/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This callback type is used for response of request srv_certman_parse_start. For more information refer srv_certman_parse_start.
 * 
 *  NOTE : Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 * 
 * PARAMETERS
 *    job_id            : job_id of the corresponding job.
 *    status            : status of the operation. SRV_CERTMAN_ERR_NONE in case of success.
 *    num_private_key   : Number of private keys in the parsed file.
 *    parsed_info       : Structure containing the parsed information of the file.
 *
 *****************************************************************************/
typedef void (*srv_certman_parsed_info_cb)(S32 job_id, srv_certman_error_enum status, U16 num_private_key, srv_certman_parsed_info_struct* parsed_info);






/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This call back type is used for response of srv_certman_parse_detail. For more information refer srv_certman_parse_detail.
 *
 *  NOTE : Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 * 
 * PARAMETERS
 *    job_id        : job_id of the corresponding job.
 *    status        : status of the operation. SRV_CERTMAN_ERR_NONE in case of success.
 *    parsed_data   : Detailed parsed data of the required certificate.
 * 
 *****************************************************************************/
typedef void (*srv_certman_parsed_data_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_parsed_data_struct* parsed_data);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This callback provides the result of srv_certman_parse_end operation. For more information, please refer srv_certman_parse_end.
 *
 * PARAMETERS
 *    job_id    : job_id of the corresponding job.
 *    status    : status of the operation. SRV_CERTMAN_ERR_NONE in case of success.
 *
 *****************************************************************************/
typedef void (*srv_certman_parse_end_cb)(S32 job_id, srv_certman_error_enum status);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This call back type is used to implement callback function for response of srv_certman_import request. For more information, please refer srv_certman_import.
 *
 *  NOTE : Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 *  
 * PARAMETERS
 *    job_id    : job_id of the corresponding job.
 *    status    : status of the operation. SRV_CERTMAN_ERR_NONE in case of success.
 *    label     : Certificate Label.
 *    dcs_label : Label encoding.
 *    cert_id   : Certificate id.
 *
 *****************************************************************************/
typedef void (*srv_certman_import_cert_cb)(S32 job_id, srv_certman_error_enum status, U8* label, srv_certman_dcs_enum dcs_label, U32 cert_id);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This callback provides the result of srv_certman_update_key_purpose operation.
 * PARAMETERS
 *    job_id      : Job id of the associated job.
 *    status      : Status of the request.
 *    cert_id     : Associated certificate ID in the request.
 *    key_purpose   : Final set of key purposes applied.
 *****************************************************************************/
typedef void (*srv_certman_update_key_purpose_cb)(S32 job_id, srv_certman_error_enum status, U32 cert_id, srv_certman_keypurpose_enum key_purpose);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * 
 *  NOTE : Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 *  
 * PARAMETERS
 *    job_id      : job_id of the associated job request.
 *    status      : Status of the request.
 *    cert_list   : Result data.
 *
 *****************************************************************************/
typedef void (*srv_certman_list_by_grp_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_cert_list_by_group_struct* cert_list);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  NOTE : Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 *  
 * PARAMETERS
 *    job_id      : job_id of the associated job request.
 *    status      : Status of the request.
 *    cert_list   : Result data.
 * 
 *****************************************************************************/
typedef void (*srv_certman_list_by_dmn_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_cert_list_by_domain_struct* cert_list);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  NOTE : 
 *    1. This callback will be called multiple times.
 *    2. First call will provide the information about the status, and result. If there is an error, there will be no further callback.
 *    3. In case of success, multiple callbacks will provide the complete data.
 *    4. In the last callback, "last" parameter will be true.
 *    5. Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 * 
 * PARAMETERS
 *    job_id      : job_id of the associated job request.
 *    status      : Status of the request.
 *    num_certs   : Total number of certificates matching the criteria.
 *    cert_list   : Array of the certificates.
 *    cert_list_size  : Number of certificates in the array.
 *    last      : True if last callback. [See Note]
 *
 *****************************************************************************/
typedef void (*srv_certman_list_by_issuer_data_cb)(S32 job_id, srv_certman_error_enum status, U16 num_certs, srv_certman_cert_list_elem_struct* cert_list, U32 cert_list_size, U8 last);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned. 
 *
 * PARAMETERS
 *    job_id    : job_id of the associated job request.
 *    status    : Status of the request.
 *    cert    : Certificate data returned by Certman Service.
 *****************************************************************************/
typedef void (*srv_certman_cert_disp_by_id_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_cert_disp_by_id_struct* cert);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.  
 *
 * PARAMETERS
 *    job_id    : job_id of the associated job request.
 *    status    : Status of the request.
 *    cert    : Certificate chain data returned by Certman Service.
 *
 *****************************************************************************/
typedef void (*srv_certman_chain_disp_by_id_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_cert_chain_disp_by_id_struct *cert_list);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned. 
 * 
 * PARAMETERS
 *    job_id    : job_id of the associated job request.
 *    status    : Status of the request.
 *    cert_ids  : Certificate data returned by Certman Service.
 *
 *****************************************************************************/
typedef void (*srv_certman_ids_by_grp_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_certid_by_group_struct *cert_ids);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 *
 * PARAMETERS
 *    job_id    : job_id of the associated job request.
 *    status    : Status of the request.
 *    cert_ids  : Certificate data returned by Certman Service.
 *
 *****************************************************************************/
typedef void (*srv_certman_ids_by_dmn_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_certid_by_domain_struct *cert_ids);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 *
 * PARAMETERS
 *    job_id    : job_id of the associated job request.
 *    status    : Status of the request.
 *    cert    : Certificate data returned by Certman Service.
 *
 *****************************************************************************/
typedef void (*srv_certman_cert_by_id_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_cert_by_id_struct *cert);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned. 
 * PARAMETERS
 *    job_id    : job_id of the associated job request.
 *    status    : Status of the request.
 *    cert    : Certificate data returned by Certman Service.
 *
 *****************************************************************************/
typedef void (*srv_certman_trstd_cert_by_id_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_trusted_cert_by_id_struct *cert);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by certman service after the callback returned.
 * PARAMETERS
 *    job_id    : job_id of the associated job request.
 *    status    : Status of the request.
 *    cert_chain  : Certificate chain data returned by certman service.
 *
 *****************************************************************************/
typedef void (*srv_certman_cert_chain_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_cert_chain_struct *cert_chain);





/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by certman service after the callback returned.
 * PARAMETERS
 *      job_id    : job_id of the associated job request.
 *      pwd     : Buffer pointer containing password.
 *      size    : Size of password.
 *
 *****************************************************************************/
typedef void (*srv_certman_pwd_cb)(S32 job_id, const U8 *pwd, U32 size);






/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  Note: Application should copy the required data to its internal buffer because the data will be freed by certman service after the callback returned.
 * PARAMETERS
 *      job_id    : job_id of the associated job request.
 *      status    : Status of the request
 *      priv_key  : Private key file information.
 *
 *****************************************************************************/
typedef void (*srv_certman_priv_key_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_privkey_struct *priv_key);






/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 * Note: Application should copy the required data to its internal buffer because the data will be freed by certman service after the callback returned.
 * PARAMETERS
 *    job_id      : Job id of the associated job.
 *    status      : Status of the request.
 *    val_result    : Validation result
 *
  *****************************************************************************/
typedef void (*srv_certman_val_result_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_validate_struct *val_result);






/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This callback provides the reasult of 2 operations.
 *  1. srv_certman_delete_cert
 *  2. srv_certman_ocsp_verify_cert
 * PARAMETERS
 *    job_id      : Job id of the associated job.
 *    status      : Status of the request.
 *
 *****************************************************************************/
typedef void (*srv_certman_status_cb)(S32 job_id, srv_certman_error_enum status);






/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This callback function provides the result of srv_certman_delete_cert_group operation.
 * PARAMETERS
 *    job_id      : Job id of the associated job.
 *    status      : Status of the request.
 *    cert_group    : Certificate group deleted.
 *****************************************************************************/
typedef void (*srv_certman_delete_status_cb)(S32 job_id, srv_certman_error_enum status, srv_certman_cert_group_enum cert_group);






/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 *
 *  NOTE: 1. This callback will be trigerred before the request function is rerurned (srv_certman_util_decrypt_privkey_file) so there is no job_id to associate with.
 *      2. Application should copy the output_file name in its internal buffer because it will be freed after callback returns. 
 * PARAMETERS
 *    status      : status of the operation
 *    input_file    : Input filename for reference.
 *    output_file   : Output file (NULL in case of error)
 *
 *****************************************************************************/
typedef void (*srv_certman_privkey_decrypt_out_cb)(srv_certman_error_enum status, const U16 *input_file, const U16* output_file);








/* Parsing*/






/*****************************************************************************
 * FUNCTION
 *  srv_certman_parse_start
 * DESCRIPTION
 *  This API initializes a parse context in certman service based on the specified file and returns the parsed information of the file.
 *  Returned certificate ids can be further used to get detailed information about the certificate.
 *  NOTE : 
 *      1. When a PKCS #12 is to be parsed, application must ensure the password protecting the file is obtained from the user. 
 *         The password must be set into parse context by srv_certman_parse_set_decrypt_password APIbefore 
 *         a "certman_send_parse_begin_req" request can be sent to Certman Service.
 *      2. Since the certman service creates a context to provide detailed information later, application should call srv_certman_parse_end
 *         when parsing info is no more needed.
 *      3. On success, the API will return SRV_CERTMAN_ERR_NONE and job_id will contain job_id assigned by certman service.
 *         This job id must be retained by application and should be provided to service for further reference ion future.
 *         In case of error job_id will have invalid value.
 *
 * PARAMETERS
 *  job_id          :   [OUT]       job_id returned from certman service to further reference the job in future.
 *  filename        :   [IN]        Specified file to be parsed (certman_send_parse_begin_req).
 *  password        :   [IN]        Password to the input file.
 *  parsed_info_cb  :   [IN]        Callback function to return the result.
 
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                 :   Success. job_id will contain a valid value.
 *  SRV_CERTMAN_ERR_INVALID_INPUT        :   Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL              :   Memory full error
 *  SRV_CERTMAN_ERR_FILE_NOT_FOUND       :   file not found or filename is NULL pointer
 *  SRV_CERTMAN_ERR_FS_ERROR             :   other file system errors
 *  SRV_CERTMAN_ERR_INVALID_ENCODING     :   unable to parse file with the specified encoding type
 *  SRV_CERTMAN_ERR_UNSUPPORTED_CONTENT  :   file is parse-able but the content cannot be supported. (eg, private key exists in PEM file, PKCS#12 file with public-key integrity/privacy mode)
 *
 * SEE ALSO
 *  srv_certman_parse_detail, srv_certman_parse_end, srv_certman_import
 *****************************************************************************/
srv_certman_error_enum srv_certman_parse_start( S32 *job_id,
                                                const U16 *filename,
                                                const U8 *password,
                                                srv_certman_parsed_info_cb parsed_info_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_parse_detail
 * DESCRIPTION
 *  This function enables caller to get detailed parsed information of a perticular certificate using 
 *  certificate id which returned by certman service in response callback of srv_certman_parse_start API.
 *  NOTE : 
 *          1. The purpose of this service is to get the parsed certificate data of the associated 
 *             parse job ("job_id") and the certificate reference ID.
 *          2. Certificate Management Application may display the information contained in 
 *             returned parsed_data to user, and acquire user's confirmation 
 *             before import this certificate to system. 
 * PARAMETERS
 *  job_id              :   [IN]        Job id of parsing job earlier provided by Certman Service via srv_certman_parse_start.
 *  cert_ref_id         :   [IN]        Associated certificate reference id (from response of srv_certman_parse_start)
 *  parsed_data_cb      :   [IN]        Callback function to get the response.
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                 :   Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT        :   Invalid input parameters.
 *
 * SEE ALSO
 *  srv_certman_parse_start, srv_certman_parse_end, srv_certman_import
 *****************************************************************************/
srv_certman_error_enum srv_certman_parse_detail( U32 job_id,
                                                 U32 cert_ref_id,
                                                 srv_certman_parsed_data_cb parsed_data_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_parse_end
 * DESCRIPTION
 *  This interface function enables the caller to free the parse context maintained at certman service.
 *  NOTE : 
 *          This service will release the parse states of the associated "job_id" in Certman service,
 *          once this request is made, caller must not make any further parse/import requests with this "job_id".
 * PARAMETERS
 *  job_id     :   [IN]     Associated Certman Service job id (from srv_certman_parse_start). 
 * RETURNS
 *  SRV_CERTMAN_ERR_NONE                 :   Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT        :   Invalid input parameters.
 * SEE ALSO
 *  srv_certman_parse_start, srv_certman_parse_end, srv_certman_import
 *****************************************************************************/
srv_certman_error_enum srv_certman_parse_end(U32 job_id,
                                             srv_certman_parse_end_cb parse_end_cb);


/* Import */






/*****************************************************************************
 * FUNCTION
 *  srv_certman_import
 * DESCRIPTION
 *  This API enables caller to import the specified certificate to Certman Service database. 
 *  NOTE : 
 *         1. This API takes the parse job ID as generated by Certman Service, it also takes in a certificate reference ID,
 *            The combination of these 2 IDs allows Certman Service to identify which certificate of which parse context (ie, the data source, or file) that the certificate should be imported.
 *         2. Caller must ensure all necessary information is obtained from user before an import request is made:
 *            (1)Unique label must be set for ALL certificates.
 *            (2)Additional information for personal certificates: private key protection method, password
 *            (3)and private key exportability : srv_certman_import_set_privkey_exportable.
 *         3. The label must be zero-terminated string, with encoding type specified by "dcs" parameter (ie, ASCII or UCS2). 
 *            Caller must ensure the number of ASCII character does not exceed SRV_CERTMAN_LABEL_LENGTH (64) characters, and half of the size (32) for UCS2 characters.
 *         4. Currently 3 types of private key protection methods are supported:
 *            (1)SRV_CERTMAN_PROTECT_NONE :
 *                  key stored in Certman Service password protected storage, and usage of key is transparent to user
 *            (2)SRV_CERTMAN_PROTECT_USAGE_CONFIRM :
 *                  key stored in Certman Service password protected storage, and confirmation from user is required when this key is to be used
 *            (3)SRV_CERTMAN_PROTECT_USAGE_PASSWORD :
 *                  key storage protected by user specified password, and the password is required from user when this key is to be used.
 *         5. Caller must ensure the user specifies a password when the protection method is SRV_CERTMAN_PROTECT_USAGE_PASSWORD. 
 *            As for the other two types of protection methods (SRV_CERTMAN_PROTECT_NONE and SRV_CERTMAN_PROTECT_USAGE_CONFIRM), 
 *            no password is needed and application must not prompt user for such information.
 *         6. When the password is required, caller must ensure that the password is 
 *            a zero-terminated ASCII string and cannot be NULL or empty value. 
 *            The maximum number of characters of a password is defined by SRV_CERTMAN_PASSWORD_LENGTH (32).
 *         7. Private key exportability is used to specify whether the private key of the associated personal certificate can be exported later on.
 *         8. Once all inputs are gathered, caller may send this request to Certman Service.
 * PARAMETERS
 *  job_id                      :   [IN]     Associated Certman Service parse job id.
 *  cert_ref_id                 :   [IN]     Specified certificate reference id in associated parse job.
 *  label                       :   [IN]     Unique label for the certificate.
 *  label_dcs                   :   [IN]     Encoding type of the lable specified.
 *  privkey_protect_method      :   [IN]     Private key protection method.
 *  privkey_protect_password    :   [IN]     Password to protect the private key.
 *  privkey_is_exportable       :   [IN]     Is private exportable?
 *  import_cert_cb              :   [IN]     Callback function to provide the operation result.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *  SRV_CERTMAN_ERR_LABEL_EXISTS        : label already exists.
 *  SRV_CERTMAN_ERR_INVALID_LABEL       : the label parameter is a NULL pointer or empty value or exceeds the limited size.
 *  SRV_CERTMAN_ERR_INVALID_PASSWORD    : password does not match the requirement
 *  SRV_CERTMAN_ERR_OUT_OF_RANGE        : privkey_is_exportable is not 0 or 1
 * SEE ALSO
 *  srv_certman_parse_detail, srv_certman_parse_end, srv_certman_parse_start
 *****************************************************************************/
srv_certman_error_enum srv_certman_import ( U32 job_id,
                                            U32 cert_ref_id,
                                            const U8 *label,
                                            srv_certman_dcs_enum label_dcs,
                                            srv_certman_privkey_protection_enum privkey_protect_method,
                                            const U8 *privkey_protect_password,
                                            U8 privkey_is_exportable,
                                            srv_certman_import_cert_cb import_cert_cb);










/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_ids_by_type
 * DESCRIPTION
 *  This interface function assists caller to query the certificate ID list by specified type
 *  Currently only support quering maximum SRV_CERTMAN_NUM_ID_IN_LIST number of certificate ID list.
 * PARAMETERS
 *  type    :   [IN]    specified certificate type (srv_certman_certtype_enum).
 *  ids_qry :   [IN/OUT]    query result output location.
 * RETURNS
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_ids_by_type(srv_certman_certtype_enum type,
                                                        srv_certman_cert_ids_result_struct *ids_qry);

/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_count
 * DESCRIPTION
 *  This API allows caller to retrieve the number of certificates in system satisfying the requirements.
 *  NOTE : 
 *         1. The "cert_group" and "key_purpose" parameters must be a value concatenated from 
 *            "certman_cert_group_enum" and "certman_keypurpose_enum" respectively. 
 *         2. Caller may use "SRV_CERTMAN_CERTGRP_NONE" and "SRV_CERTMAN_KP_NONE" if the parameters are not required.
 * PARAMETERS
 *  cert_group  :   [IN]     specified certificate groups (srv_certman_cert_group_enum).
 *  key_purpose :   [IN]     specified key purposes (srv_certman_keypurpose_enum).
 * RETURNS
 *  number of certificates satisfying requirements
 *****************************************************************************/
U32 srv_certman_get_cert_count (srv_certman_cert_group_enum cert_group,
                                srv_certman_keypurpose_enum key_purpose);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_label
 * DESCRIPTION
 *  retrieves certificate label given the specified certificate ID
 * PARAMETERS
 *  cert_id         :   [IN]        ID of the certificate label to retrieve
 *  label_buffer    :   [IN\OUT]    buffer provided by caller in which label will be filled into
 *  bufsize         :   [IN]        buffer size (the number of usable bytes in buffer, include zero-terminate)
 *  dcs_out         :   [IN\OUT]    identifies label's DCS param (ie, whether string in label_buffer is ASCII or UCS2)
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE            :   Success
 *  SRV_CERTMAN_ERR_CERT_NOT_FOUND  :   can't find out the certificate in database by specified id
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_label(  U32 cert_id,
                                                    U8 *label_buffer,
                                                    U32 bufsize,
                                                    srv_certman_dcs_enum *dcs_out);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_list_by_group
 * DESCRIPTION
 *  This interface function assists caller to request certman service to get a list of certificates who belong to the specified group. 
 *  Caller should expect the data to be returned through the callback function provided.
 *  NOTE : 
 *         1. The "cert_group" parameter defines the group(s) of certificates that are in caller's interests.
 *            Multiple groups can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Root CA and Intermediate CA are required, 
 *            cert_group may be set to a value of SRV_CERTMAN_CERTGRP_ROOTCA | SRV_CERTMAN_CERTGRP_CA.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for 
 *            a hit to occur. Application wishing to specifying more than 1 purposes may concatenate the 
 *            values together with OR operation. Application is allowed to specify SRV_CERTMAN_KP_NONE in this 
 *            retrieval request as no public key will be made available in its response callback.
 *         3. One result callback can provide maximum of SRV_CERTMAN_NUM_CERT_IN_LIST (12) certificates.
 *            If the number of certificates of matching criteria are more than the this value, 
 *            then this API should be called again using the "more" parameter provided via the result callback.
 *            "more" must be zero in initial request
 * PARAMETERS
 *  job_id          :   [OUT]   Job id generated by certman service.
 *  cert_group      :   [IN]    specified certificate groups (certman_cert_group_enum).
 *  key_purpose     :   [IN]    specified key purposes (certman_keypurpose_enum).
 *  pubkey_type     :   [IN]    Specified Public key type for the criteria.
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from last result callback to fetch more certs until all certs retrieved.
 *  list_by_grp_cb  :   [IN]  Result callback function.
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 * SEE ALSO
 *  srv_certman_get_cert_list_by_domain, srv_certman_get_certid_by_group
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_list_by_group ( S32 *job_id,
                                                            srv_certman_cert_group_enum cert_group, 
                                                            srv_certman_keypurpose_enum key_purpose, 
                                                            srv_certman_pubkey_type_enum pubkey_type, 
                                                            U32 more,
                                                            srv_certman_list_by_grp_cb list_by_grp_cb);


/*****************************************************************************
 FUNCTION
 *  srv_certman_get_cert_list_by_domain
 * DESCRIPTION
 *  This interface function assists caller to request certman service to get a list of certificates who belong to the specified domain. 
 *  Caller should expect the data to be returned through the callback function provided.
 *  NOTE : 
 *         1. The "domain" parameter defines the domain(s) of certificate that are in caller's interests.
 *            Multiple domains can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Operator and Manufacturer domains are required, 
 *            domain may be set to a value of SRV_CERTMAN_DOMAIN_OPERATOR | SRV_CERTMAN_DOMAIN_MANUFACTURER.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is allowed to specify SRV_CERTMAN_KP_NONE in this retrieval request as no public key will be made available in its response callback.
 *         3. One result callback can provide maximum of SRV_CERTMAN_NUM_CERT_IN_LIST (12) certificates.
 *            If the number of certificates of matching criteria are more than the this value, 
 *            then this API should be called again using the "more" parameter provided via the result callback.
 *            "more" must be zero in initial request
 * PARAMETERS
 *  job_id          :   [OUT]   Job id generated by certman service.
 *  domain          :   [IN]    specified certificate domains (SRV_certman_domain_enum).
 *  key_purpose     :   [IN]    specified key purposes (SRV_certman_keypurpose_enum).
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from last result callback to fetch more certs until all certs retrieved.
 *  list_by_dmn_cb  :   [IN]    Result callback function.
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 * SEE ALSO
 *  srv_certman_get_cert_list_by_group 
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_list_by_domain (S32 *job_id, 
                                                            srv_certman_domain_enum domain, 
                                                            srv_certman_keypurpose_enum key_purpose, 
                                                            U32 more,
                                                            srv_certman_list_by_dmn_cb list_by_dmn_cb);



/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_list_by_issuers_file
 * DESCRIPTION
 *  This interface function assists caller to request certman service to get a list of certificates who belong to the specified issuer file.
 *  Caller should expect the data to be returned through the callback function provided.
 *  NOTE : 
 *         1. This request will return certificate information matching the specified certificate group and key purpose. 
 *            In addition, the issuer names of the certificate validation chain by matched certificate 
 *            must be one of the issuer name described within the issuers name file provided.
 *         2. In fact, this is a special API for supporting client certficiate authentication. 
 *         3. The "cert_group" parameter defines the group(s) of certificates that are in caller's interests.
 *            Multiple groups can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Root CA and Intermediate CA are required, 
 *            cert_group may be set to a value of SRV_CERTMAN_CERTGRP_ROOTCA | SRV_CERTMAN_CERTGRP_CA.
 *         4. The "key_purpose" parameter defines the certificate usage purpose where it must match for 
 *            a hit to occur. Application wishing to specifying more than 1 purposes may concatenate the 
 *            values together with OR operation. Application is allowed to specify SRV_CERTMAN_KP_NONE in this 
 *            retrieval request as no public key will be made available in its response callback. 
 *         5. The "issuers_filename" parameter defines the filename where the issuers name could be located. 
 *            This parameter must not be set to NULL or an empty string and Certman Service will not be deleting this file 
 *            when its operation has completed, caller has full ownership of the file itself. 
 *            Caller may delete the file should it chooses to as soon as result callback is triggered.
 *         6. The format of the issuers' name file is defined as follows:
 *            |<---- 2 --->|<--- sizenum of bytes -->| ...
 *            |Entry size 1|DER encoded issuer name 1|Entry size 2|DER encoded issuer name 2|
 *            |Entry size 3|DER encoded issuer name 3|Entry size 4|DER encoded issuer name 4|
 *            | .....
 *            Basically, it's a multiple entries of issuers' name where each entry is a concatenation of a "size" (2 bytes) 
 *            followed by a DER encoded name data and no header such as "number of entries" or footer such as "the end of record" is required.
 *         7. As the number of issuers in file and the number of matching certificates cannot be predetermined, 
 *            the returning of certificate list information back to the application may need to be done through 
 *            a series of callbacks depending on the number of certificates found.
 *            where each callback will provide SRV_CERTMAN_NUM_CERT_IN_LIST number of certificates information.
 *            The total number of matched certificates is returned in the first callback for application to prepare sufficient memory 
 *            for the data to come, and the end of data will be identified by the "last" parameter in the result callback.
 *         8. The "pubkey_types" parameter defines the public key types filters,
 *            Applications may use OR operation for srv_certman_pubkey_type_enum to set public key requirements.
 *            And the "num_types" defines the total number of pubkey requirements being set by applications.
 * PARAMETERS
 *  job_id                  :   [OUT]   Job id provided by Certman Service.
 *  cert_group              :   [IN]    specified certificate groups (srv_certman_cert_group_enum).
 *  key_purpose             :   [IN]    specified key purposes (srv_certman_keypurpose_enum). array containing maximum SRV_CERTMAN_NUM_KEYTYPE_IN_LIST parameters.
 *  pubkey_types            :   [IN]    specified public key types (srv_certman_pubkey_type_enum).
 *  num_types               :   [IN]    the number of specified public key types in pubkey_types array.
 *  issuers_filename        :   [IN]    specified issuer names file.
 *  list_by_issuer_data_cb  :   [IN]    Callback function for result.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_list_by_issuers_file ( S32 *job_id, 
                                                                   srv_certman_cert_group_enum cert_group, 
                                                                   srv_certman_keypurpose_enum key_purpose,
                                                                   srv_certman_pubkey_type_enum *pubkey_types, 
                                                                   U8 num_types,
                                                                   const U16 *issuers_filename,
                                                                   srv_certman_list_by_issuer_data_cb list_by_issuer_data_cb);

/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_disp_by_id
 * DESCRIPTION
 *  This interface function assists caller to get display data of a certificate by certificate id.
 *  Caller should expect the data to be returned via result callback. 
 *  NOTE : The returned data of this request will primarily be used for certificate display, and so the included parameters are limited. 
 *
 * PARAMETERS
 *  job_id                  :   [OUT]    Job id provided by Certman Service.
 *  cert_id                 :   [IN]     specified certificate id.
 *  cert_disp_by_id_cb      :   [IN]     Result callback.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_disp_by_id (S32 *job_id, 
                                                        U32 cert_id,
                                                        srv_certman_cert_disp_by_id_cb cert_disp_by_id_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_chain_disp_by_id
 * DESCRIPTION
 *  This interface function assists caller to get display certificate chain by certificate id.
 *  Caller should expect the data to be returned via result callback.
 *  NOTE : The returned data of this request will primarily be used for certificate chain display, and so the included parameters are limited. 
 *
 * PARAMETERS
 *  job_id                  :   [OUT]    Job id provided by Certman Service.
 *  cert_id                 :   [IN]     specified certificate id.
 *  chain_disp_by_id_cb     :   [IN]     Result callback.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_chain_disp_by_id (S32 *job_id, 
                                                              U32 cert_id,
                                                              srv_certman_chain_disp_by_id_cb chain_disp_by_id_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_certid_by_group
 * DESCRIPTION
 *  This interface function assists caller to get the certificate ids related to group(s). 
 *  Caller should expect the data to be returned through the result callback. 
 *  NOTE : 
 *         1. The "cert_group" parameter defines the group(s) of certificates that are in caller's interests.
 *            Multiple groups can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Root CA and Intermediate CA are required, 
 *            cert_group may be set to a value of SRV_CERTMAN_CERTGRP_ROOTCA | SRV_CERTMAN_CERTGRP_CA.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for 
 *            a hit to occur. Application wishing to specifying more than 1 purposes may concatenate the 
 *            values together with OR operation. Application is allowed to specify SRV_CERTMAN_KP_NONE in this 
 *            retrieval request as no public key will be made available in its response callback.
 *         3. The "more" parameter must match the value of "more" from the last result callback,
 *            and caller should pass in 0 on initial request for Certman Service to return list of certificate info from the beginning. 
 *            The returned data will be sorted in alphabetical order of labels.
 * PARAMETERS
 *  job_id          :   [OUT]   Job id provided by Certman Service.
 *  cert_group      :   [IN]    specified certificate groups (srv_certman_cert_group_enum).
 *  key_purpose     :   [IN]    specified key purposes (srv_certman_keypurpose_enum).
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from last result callback to fetch other certs until all certs being retrieved.
 *  ids_by_grp_cb   :   [IN]    Result callback function.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_certid_by_group ( S32 *job_id, 
                                                         srv_certman_cert_group_enum cert_group,
                                                         srv_certman_keypurpose_enum key_purpose,
                                                         U32 more,
                                                         srv_certman_ids_by_grp_cb ids_by_grp_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_certid_by_domain
 * DESCRIPTION
 *  This interface function assists caller to get the certificate ids related to domain(s). 
 *  Caller should expect the data to be returned through the result callback. 
 *  NOTE : 
 *         1. The "domain" parameter defines the domain(s) of certificate that are in caller's interests.
 *            Multiple domains can be concatenated together by the OR operation, 
 *            ie, if the certificate info of all Operator and Manufacturer domains are required, 
 *            domain may be set to a value of SRV_CERTMAN_DOMAIN_OPERATOR | SRV_CERTMAN_DOMAIN_MANUFACTURER.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is allowed to specify SRV_CERTMAN_KP_NONE in this retrieval request as no public key will be made available in its response callback.
 *         3. The "more" parameter must match the value of "more" from the last result callback, 
 *            and caller should pass in 0 on initial request for Certman Service to return list of info from the beginning. The returned data will be sorted in alphabetical order of labels.
 * PARAMETERS
 *  job_id          :   [OUT]   Job id to be returned by Certman Service.
 *  domain          :   [IN]    specified certificate domains (srv_certman_domain_enum).
 *  key_purpose     :   [IN]    specified key purposes (srv_certman_keypurpose_enum).
 *  more            :   [IN]    index flag for cert list query, first time query is 0, then use the value from result callback to fetch other certs until all certs being retrieved
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_certid_by_domain (   S32 *job_id, 
                                                            srv_certman_domain_enum domain,
                                                            srv_certman_keypurpose_enum key_purpose,
                                                            U32 more,
                                                            srv_certman_ids_by_dmn_cb ids_by_dmn_cb);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_by_id
 * DESCRIPTION
 *  This interface function assists caller to get certificate data by certificate id. 
 *  Caller should expect the data to be returned through result callback.
 *  NOTE : 
 *         1. Certman Service will generate a new file for each request and have the requested certificate placed in this file. 
 *         2. The file path will be returned to caller through the response callback, 
 *            and caller is expected to delete the file when it is no longer needed. 
 *         3. The file will be located within Certman Service's temp folder under system drive, and this folder will be cleaned by Certman Service during each bootup.
 *         4. In the case when a personal certificate is to be retrieved, the callback will return the certificate data only, 
 *            caller must use srv_certman_get_privkey function with the same certificate ID to request for its private key.
 *         5. Currently for this service, Certman Service only allows an encoding type of either 
 *            SRV_CERTMAN_ENC_DER or SRV_CERTMAN_ENC_PEM as these are found to be the only formats required in either protocol usage, or internally within applications' scopes.
 *         6. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is strictly disallowed to specify SRV_CERTMAN_KP_NONE in this retrieval request as using this service means application intends to operate on certificate's public key.
 *
 * PARAMETERS
 *  job_id          :   [OUT]   Job id to be returned by Certman Service.
 *  cert_id         :   [IN]    Specified certificate id.
 *  encoding        :   [IN]    Specified certificate output encoding type (certman_encoding_enum).
 *  key_purpose     :   [IN]    Specified key purposes (certman_keypurpose_enum).
 *  cert_by_id_cb   :   [IN]    Function for result callback.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_by_id ( S32 *job_id, 
                                                    U32 cert_id,
                                                    srv_certman_encoding_enum encoding,
                                                    srv_certman_keypurpose_enum key_purpose,
                                                    srv_certman_cert_by_id_cb cert_by_id_cb);




/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_trusted_cert_by_id
 * DESCRIPTION
 *  NOTE : 
 *         1. This API is used to load the link files of trusted certificates.
 *         2. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is strictly disallowed to specify SRV_CERTMAN_KP_NONE in this retrieval request as using this service means application intends to operate on certificate's public key.
 *
 * PARAMETERS
 *  job_id                  :   [OUT]   Job id to be returned by Certman Service.
 *  cert_id                 :   [IN]    Specified certificate id.
 *  key_purpose             :   [IN]    Specified key purposes (certman_keypurpose_enum).
 *  trstd_cert_by_id_cb     :   [IN]    Function for result callback.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_trusted_cert_by_id ( S32 *job_id, 
                                                            U32 cert_id,
                                                            srv_certman_keypurpose_enum key_purpose,
                                                            srv_certman_trstd_cert_by_id_cb trstd_cert_by_id_cb);



/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_cert_chain
 * DESCRIPTION
 *  This function provides interface to request certificate chain related to the specified certificate id.
 *  NOTE : 
 *         1. Certman Service will generate a new file for each request and have the requested certificate(s) placed in this file. 
 *         2. The file path will be returned to caller through the response callback, 
 *            and caller is expected to delete the file when it is no longer needed. 
 *            The file will be located within Certman Service's temp folder under system drive, and this folder will be cleaned by Certman Service during each bootup.
 *         3. There is no encoding type associated with this request as a chain of certificates can only be encoded in either PEM or PKCS family formats.
 *            Chain of certificates will always be encoded in PEM with multiple BEGIN/END separating each certificates.
 *         4. The "key_purpose" parameter defines the certificate usage purpose where it must match for a hit to occur. 
 *            Application wishing to specifying more than 1 purposes may concatenate the values together with OR operation. 
 *            Application is strictly disallowed to specify SRV_CERTMAN_KP_NONE in this retrieval request as using this service means application intends to operate on certificate's public key.
 *         5. Please be reminded that this request will only include the relevant certificates 
 *            (ie, issuer's certificate on the requested certificate, and its issuer, and issuers),
 *            in the order of {requested certificate, issuer of requested certificate, issuer of the issuer, root CA certificate}. 
 *            No private key will be included in this request.
 *
 * PARAMETERS
 *  job_id          :   [OUT]   Job id to be returned by Certman Service.
 *  cert_id         :   [IN]    Specified certificate id.
 *  key_purpose     :   [IN]    Specified key purposes (certman_keypurpose_enum).
 *  cert_chain_cb   :   [IN]    Function for result callback.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_cert_chain ( S32 *job_id, 
                                                    U32 cert_id,
                                                    srv_certman_keypurpose_enum key_purpose,
                                                    srv_certman_cert_chain_cb cert_chain_cb);



/*****************************************************************************
 * FUNCTION
 *  srv_certman_get_privkey
 * DESCRIPTION
 *  This interface function assist caller to retrieve private key related to a personal certificate.
 *  NOTE : 
 *         1. Certman Service will generate a new file for each request and have the requested private key placed in this file. 
 *            The file path will be returned to caller through the response callback, 
 *            and caller is expected to delete the file when it is no longer needed.
 *            The file will be located within Certman Service's temp folder under system drive, and this folder will be cleaned by Certman Service during each bootup.
 *         2. The encoding type is used to specify whether the generated file should be in DER or PEM (base 64) encoding.
 *         3. The private key file will be protected by password for security purpose. 
 *            The password will be different for each of the file generated (ie, different for each request), 
 *            and hence this will not be the same password to what the user had specified during private key import operation. 
 *            The password will be randomly produced on each request, and will be passed to caller through the "password callback function", which must be provided by caller as Certman Service does not keep the password information within itself. 
 *         4. Caller must prepare at least a SRV_CERTMAN_PKPWD_SIZE(60) sized buffer for storing password. 
 *            The password must not assume to be a string value or zero-terminated, 
 *            the additional "size" parameter has included indicating the number of bytes the password occupies. 
 *            Caller must be responsible for copying the password across to its own buffer when the callback is triggered, 
 *            as Certman Service does not keep track of generated password, the private key file will be unable to decrypt 
 *            if this information is not stored at this point in time.
 *         5. The format of the file produced will thus be PKCS#8 Encrypted Private Key format, 
 *            and caller is expected to have enough knowledge on decrypting the file or 
 *            may simply pass the password and private key information further up/down the stack for the true private key manipulator to use. In case when caller is unable to decrypt the file, 
 *            Certman Service provides the srv_certman_util_decrypt_privkey_file utility API where it may decrypt on caller's behalf.
 *         6. The requirements on private key protection are based on the following three fundamental rules, 
 *            which all applications should follow in order to gain maximum security:
 *            (1)private key file must be encrypted in case of system failure and an attack directly on file system
 *            (2)password must not be hard-coded
 *            (3)password must not appear on log
 *         7. In addition to the password protection on the generated private key file, 
 *            applications are reminded that the private key itself is protected by one of the protection method selected by user during import:
 *            (1)SRV_CERTMAN_PROTECT_NONE
 *            (2)SRV_CERTMAN_PROTECT_USAGE_CONFIRM
 *            (3)SRV_CERTMAN_PROTECT_USAGE_PASSWORD
 *         8. In the case of protection by USAGE_CONFIRM or USAGE_PASSWORD, 
 *            Certman Service will trigger Certificate Management Application in displaying appropriate confirmation 
 *            or pin input dialog before proceeding.
 *            Private key retriever must be aware that user input can be a slow process and 
 *            hence the caller must be able to handle scenario such as processing Certman Service's private key retrieval response after its own request timer times out. 
 *            In the case when Certman Service is unable to proceed (eg, user fails to confirm key usage, or consecutively incorrect PIN inputs, or user presses END-key), 
 *            Certman Service will return an error status in the callback, no file will be generated and hence password callback will not be triggered. 
 *            Caller must then perform necessary termination procedure as user has denied the request. 
 *
 * PARAMETERS
 *  job_id              :   [OUT]   Job id to be returned by Certman Service.
 *  cert_id             :   [IN]    Specified certificate id.
 *  encoding            :   [IN]    identify DER or PEM encoding
 *  pwd_cb              :   [IN]    caller specified password callback function
 *  priv_key_cb         :   [IN]    Callback Function to return generated privatekey file.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_get_privkey (S32 *job_id, 
                                                U32 cert_id, 
                                                srv_certman_encoding_enum encoding,
                                                srv_certman_pwd_cb pwd_cb,
                                                srv_certman_priv_key_cb priv_key_cb);


/***************** Util ***************/







/*****************************************************************************
 * FUNCTION
 *  srv_certman_util_decrypt_privkey_file
 * DESCRIPTION
 *  This utility function has been provided to assist application in decrypting.
 *  the password protected private key file that was generated by Certman Service. 
 *  NOTE : 
 *         1. The use of this API is not mandatory, as the file uses the standard PKCS #8 encrypted private key format,
 *            and can be decoded by others provided they support for this as well.
 *         2. Caller needs to specify the desired output encoding type, 
 *            this API currently allows output encoding type of DER and PEM, 
 *            and the decrypted private key will be stored into a file specified in "output_filename". 
 *         3. Caller is reminded that storing of unencrypted private key data on file is subject to security risk, 
 *            and caller must ensure this file is deleted when it is no longer needed. 
 *         4. The output private key format will be in PKCS #8 private key format 
 *            (ie, the unencrypted version), and it is expected caller to have sufficient knowledge in performing further operations. 
 * PARAMETERS
 *  filename                    :   [IN]        zero-terminated filename.
 *  password                    :   [IN]        Transaction id from the caller applications.
 *  size                        :   [IN]        size of password (number of bytes).
 *  output_encoding             :   [IN]        SRV_CERTMAN_ENC_DER or SRV_CERTMAN_ENC_PEM (srv_certman_encoding_enum)
 *  privkey_decrypt_out_cb      :   [IN]        Callback function to provide result to the application.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                :   Success
 *  SRV_CERTMAN_ERR_MEMFULL             :   Memory full error
 *  SRV_CERTMAN_ERR_FILE_NOT_FOUND      :   Can't find the specified file error
 *  SRV_CERTMAN_ERR_FS_ERROR            :   Other file system error
 *  SRV_CERTMAN_ERR_INCORRECT_PASSWORD  :   Password error
 *  SRV_CERTMAN_ERR_INVALID_ENCODING    :   File content encoding error
 *
 * SEE ALSO
 *  srv_certman_send_get_privkey_req, srv_certman_send_get_privkey_req_auto_accept 
 *****************************************************************************/
srv_certman_error_enum srv_certman_util_decrypt_privkey_file(const U16 *filename,
                                                             const U8 *password,
                                                             U32 size,
                                                             srv_certman_encoding_enum output_encoding,
                                                             srv_certman_privkey_decrypt_out_cb privkey_decrypt_out_cb);


/*****************************************************************************
 *  srv_certman_util_check_id_as_cert
 * DESCRIPTION
 *  This utility function has been provided to assist application in checking 
 *  whether the certificate of the specified ID does exist on system, in addition, 
 *  caller may specify the additional check condition such as certificate group, domain and/or key purposes.
 *  NOTE : 
 *         1. Caller wishing to perform a simple check on whether the certificate exists, 
 *            it then may set:
 *            cert_group to SRV_CERTMAN_CERTGRP_NONE
 *            domain to SRV_CERTMAN_DOMAIN_NONE
 *            key_purpose to SRV_CERTMAN_KP_NONE
 *            or otherwise, it may specify more than one certificate group by concatenating the values in srv_certman_cert_group_enum enumeration,
 *            or one or more domain by values in srv_certman_domain_enum or one or more key purpose by values in srv_certman_keypurpose_enum.
 *         2. This utility will simply checks the certificate information stored on Certman Service's database in memory
 *            and will actually not go into file system to check on existence of the certificate raw data itself.
 * PARAMETERS
 *  id              :   [IN]    The specified ID to check.
 *  cert_group      :   [IN]    specified certificate groups (certman_cert_group_enum).
 *  domain          :   [IN]    specified certificate domains (certman_domain_enum).
 *  key_purpose     :   [IN]    Specified key purposes (certman_keypurpose_enum).
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                :   Success
 *  SRV_CERTMAN_ERR_INVALID_CERT_GROUP  :   cert_group setting invalid
 *  SRV_CERTMAN_ERR_INVALID_DOMAIN      :   domain setting invalid
 *  SRV_CERTMAN_ERR_INVALID_KEY_PURPOSE :   key_purpose setting invalid
 *  SRV_CERTMAN_ERR_CERT_NOT_FOUND      :   can't find certificate with specified ID
 *
 * Note: Application should copy the required data to its internal buffer because the data will be freed by Certman Service after the callback returned.
 *****************************************************************************/
srv_certman_error_enum srv_certman_util_check_id_as_cert(   U32 id,
                                                            srv_certman_cert_group_enum cert_group,
                                                            srv_certman_domain_enum domain,
                                                            srv_certman_keypurpose_enum key_purpose);


/*****************************************************************************
 * FUNCTION
 *  srv_certman_util_check_id_as_privkey
 * DESCRIPTION
 *  This utility function has been provided to assist application in checking 
 *  whether the private key of the specified ID does exist on system.
 *  NOTE : This utility will simply checks the private key information stored in Certman Service's database in memory and 
 *         will actually not go into file system to check on existence of the private key raw data itself, 
 *         no UI confirmation will be required from user (eg, password input or user confirmation dialog).
 * PARAMETERS
 *  id      :   [IN]    The specified ID to check.
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE            :   Success
 *  SRV_CERTMAN_ERR_KEY_NOT_FOUND   :   can't find private key with specified ID
 *****************************************************************************/
srv_certman_error_enum srv_certman_util_check_id_as_privkey(U32 id);



/*****************************************************************************
 * FUNCTION
 *  srv_certman_util_signature_verify_by_id
 * DESCRIPTION
 *  This utility function to verify the signature by specified certificate public key. 
 * PARAMETERS
 *  id          :   [IN]        The specified certificate ID to check.
 *  sig_vfy     :   [IN]        Certman Service signataure verify param setting struct
 *  verified    :   [IN\OUT]    verify outcome
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE            :   Success
 *  SRV_CERTMAN_ERR_INVALID_INPUT   :   input invalid
 *  SRV_CERTMAN_ERR_CERT_NOT_FOUND  :   can't find private key with specified ID
 *  SRV_CERTMAN_ERR_FS_ERROR        :   FS error
 *  SRV_CERTMAN_ERR_FAIL            :   verified failed
 *****************************************************************************/
srv_certman_error_enum srv_certman_util_signature_verify_by_id( U32 id, 
                                                                srv_certman_signature_vfy_params_struct *sig_vfy,
                                                                U8 *verified);



/*****************************************************************************
 * FUNCTION
 *  srv_certman_update_key_purpose
 * DESCRIPTION
 *  This interface function assists caller in updating key purposes of a perticular certificate, specified by cert_id.
 *  Caller should expect the data to be returned through response callback. 
 *  NOTE : 
 *         1. The "key_purpose" parameter should define a set of key purposes that are enabled by user (ie, replaces "key_purpose_allowed" parameter). 
 *         2. Application should ensure that the set of allowed purposes does not exceed the restriction from "key_purpose_all" of the associated certificate. 
 *            Should this event occurred, Certman Service would simply discard any "out of range" or "additional" key purposes that are incorrectly set, 
 *            and have the final set of key purposes returned in response callback.
 * PARAMETERS
 *  job_id          :   [OUT]   Job id to be returned by Certman Service.
 *  cert_id         :   [IN]    Specified certificate id.
 *  key_purpose     :   [IN]    Specified key purposes (OR'd value from srv_certman_keypurpose_enum, must not go beyond "key_purpose_all").
 *  update_kp_cb    :   [IN]    Callback function for response.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 ******************************************************************************/
srv_certman_error_enum srv_certman_update_key_purpose ( S32 *job_id,
                                                        U32 cert_id,
                                                        srv_certman_keypurpose_enum key_purpose,
                                                        srv_certman_update_key_purpose_cb update_kp_cb);

/***************** Validate ***************/







/*****************************************************************************
 * FUNCTION
 *  srv_certman_validate_cert_list
 * DESCRIPTION
 *  This API is used to validate a certificate chain by specified trusted certificates.
 *  NOTE : 
 *         1. The source of the validate certificate chain is certificate array like material 
 *            and the application need pay more attention for the sequence of the insertion. 
 *            The certificate in array index 0 is the end-entity to be validated and 
 *            the other certificates are used to build the certificate chain.
 *         2. If the sequence should be the end-entity add first for index 0, 
 *            and the root certificate of the chain shall be the last one certificate to add.
 *         3. If application needs OCSP verification of the certificate, it should set SRV_CERTMAN_OCSP_OPT_USE_OCSP in ocsp_option parameters.
 *            Application should also set corresponding parameters when using OCSP.
 *         4. The last trusted certificate in the chain will be saved in Certman Service temp folder and the path will be returned in response callback.
 * 
 * PARAMETERS
 *  job_id              : [OUT] Job id to be returned by Certman Service.
 *  cert_list           : [IN]  Certificate array to be validated.
 *  num_cert            : [IN]  Number of certificate in the array.
 *  ocsp_options        : [IN]  Option to use ocsp in the validation.
 *  ocsp_responser_url  : [IN]  URL to use in ocsp validation. Ignore if ocsp is not required.
 *  ocsp_retry_time     : [IN]  Retry timout to handle network delays. Ignore if ocsp is not required.
 *  ocsp_profile        : [IN]  Profile to be used when connecting to server of ocsp verification.  Ignore if ocsp is not required.
 *  val_result_cb       : [IN]  Callback function to ptovide result.
 *
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *  SRV_CERTMAN_ERR_TOO_MANY_CERTS      : More than supported certificates in the validation array (SRV_CERTMAN_NUM_CERT_IN_VALIDATE).
 *  CERTMAN_ERR_INVALID_DATA            : Data in the validation array is invalid.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_validate_cert_list ( S32 *job_id, 
                                                        srv_certman_cert_data_struct *cert_list,
                                                        U8 num_cert,
                                                        srv_certman_ocsp_opt_enum ocsp_options,
                                                        U8 *ocsp_responser_url,
                                                        U32 ocsp_retry_time,
                                                        srv_certman_ocsp_network_profile_struct *ocsp_profile,
                                                        srv_certman_val_result_cb val_result_cb);


/*******************Delete******************/






/*****************************************************************************
 * FUNCTION
 *  srv_certman_delete_cert
 * DESCRIPTION
 *  This interface function assists caller in deleting a perticular certficate in Certman Service database. 
 *  Caller should expect the data to be returned through response callback.
 *  NOTE : 
 *         1. Caller must be aware that some certificates may be set with read-only, and cannot be deleted manually. 
 *            Deleting this type of certificate will always cause Certman Service to return failed error status.
 *         2. Application must be aware that deleting a personal certificate will result in 
 *            deletion of the associated private key automatically as well. 
 *            Please be noted that no user's confirmation or password is required for this operation.
 * PARAMETERS
 *  job_id      :   [IN]    Job id to be returned by Certman Service.
 *  cert_id     :   [IN]    Specified certificate id.
 *  status_cb   :   [IN]  Callback function to provide result.
 *  
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE                : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT       : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL             : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_delete_cert(S32 *job_id, 
                                               U32 cert_id,
                                               srv_certman_status_cb status_cb);



/*****************************************************************************
 * FUNCTION
 *  srv_certman_delete_cert_group
 * DESCRIPTION
 *  This interface function assists caller in deleting all the certificates corresponding to a perticular group. 
 *  Caller should expect the data to be returned through response callback.
 *  NOTE : Caller must be aware that although the purpose of this function is to delete all certificates (and keys) on system, 
 *            however the read-only certificates will still be remained unchanged, ie, after this operation has completed successfully, 
 *            all read-only certificate will still remain and visible when queried later on.
 * PARAMETERS
 *  job_id              :   [OUT]   Job id to be returned by Certman Service.
 *  cert_group          :   [IN]    specified certificate groups (certman_cert_group_enum).
 *  delete_status_cb    :   [IN]  Callback function to provide result.
 *  
 * RETURN VALUES
 *  SRV_CERTMAN_ERR_NONE            : Success.
 *  SRV_CERTMAN_ERR_INVALID_INPUT   : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL         : Memory full error.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_delete_cert_group(S32 *job_id, 
                                                     srv_certman_cert_group_enum cert_group,
                                                     srv_certman_delete_status_cb delete_status_cb);





/*****************************************************************************
 * FUNCTION
 *  srv_certman_ocsp_verify_cert
 * DESCRIPTION:
 *  This function used to perform ocsp verification on a perticular certificate.
 * PARAMETERS
 *  job_id              :   [OUT] Job id to be returned by Certman Service.
 *  cert                :   [IN]  certificate content of end-entity in DER format
 *  cert_len            :   [IN]  size of cert in bytes
 *  issuer              :   [IN]  end-entity's issuer certificate in DER format
 *  issuer_len          :   [IN]  size of issuer in bytes
 *  encoding            :   [IN]  encoding type of trusted certificates in trusted_path.
 *  ocsp_options        :   [IN]  Option to use ocsp in the validation.
 *  ocsp_responser_url  :   [IN]  URL to use in ocsp validation.
 *  ocsp_retry_time     :   [IN]  Retry timout to handle network delays.
 *  ocsp_profile        :   [IN]  Profile to be used when connecting to server of ocsp verification.
 *  status_cb           :   [IN]  Callback function to provide result.
 * RETURNS
 *  SRV_CERTMAN_ERR_NONE            : Success. Must wait for callback for final validation result.
 *  SRV_CERTMAN_ERR_INVALID_INPUT   : Invalid input parameters.
 *  SRV_CERTMAN_ERR_MEMFULL         : Memory full error.
 *  SRV_CERTMAN_ERR_WOULDBLOCK      : waiting for validation response
 *  SRV_CERTMAN_ERR_MEMFULL         : out-of-memory to accomplish the operation
 *  SRV_CERTMAN_EXT_NOT_FOUND       : ocsp_responser_url is not set and OCSP url is not specified in the certificate
 *  SRV_CERTMAN_ERR_FAIL            : other errors.
 *
 *****************************************************************************/
srv_certman_error_enum srv_certman_ocsp_verify_cert(S32 *job_id, 
                                                    const void* cert, U32 cert_len,
                                                    const void* issuer, U32 issuer_len,
                                                    srv_certman_encoding_enum encoding,
                                                    srv_certman_ocsp_opt_enum ocsp_options,
                                                    U8 *ocsp_responser_url,
                                                    U32 ocsp_retry_time,
                                                    srv_certman_ocsp_network_profile_struct *ocsp_profile,
                                                    srv_certman_status_cb status_cb);
#endif /*__CERTMAN_SUPPORT__*/
#endif /*__CERTMAN_AGENT_SRV_GPROT_H__*/
