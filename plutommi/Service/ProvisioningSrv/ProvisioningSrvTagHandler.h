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
 * ProvServiceTagHandler.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for ProvServiceTagHandler.c
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
#include "MMI_features.h"
#ifndef _PROVISIONINGSRVTAGHANDLER_H
#define _PROVISIONINGSRVTAGHANDLER_H

#include "MMIDataType.h"

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

//#include "wbxmlp.h"

extern const S8 *prov_tags[];
extern const S8 *prov_start_attributes[];
extern const S8 *prov_value_attributes[];
extern const S8 *nokia_prov_tags[];
extern const S8 *nokia_prov_start_attributes[];
/* extern const S8 *nokia_prov_value_attributes[]; */ /* This is currently not in use */

extern const S8 *pacOmaProvStartAttributes[];
extern const S8 *pacOmaProvValueAttributes[];

#define SRV_PROV_MAX_WBXML_STRLEN                   2048

#define PROV_OMA_PUBLIC_ID                          "-//WAPFORUM//DTD WML 1.0//EN"
#define PROV_WAP_PUBLIC_ID                          "unknown id"
#define PROV_CHARACTERISTIC                         "characteristic"

/* Tag tokens */
#define SRV_PROV_WAP_SWITCH_PAGE                    0x00
#define SRV_PROV_OMA_SWITCH_PAGE                    0x01
#define PROVT_WAP_PROVISIONING_DOC                  0x05
#define PROVT_CHARACTERISTIC                        0x06
#define PROVT_PARM                                  0x07

/* Attribute start tokens */

#define PROVS_NAME                                  0x05
#define PROVS_VALUE                                 0x06
#define PROVS_NAME_NAME                             0x07
#define PROVS_NAME_NAP_ADDRESS                      0x08
#define PROVS_NAME_NAP_ADDRTYPE                     0x09
#define PROVS_NAME_CALLTYPE                         0x0A
#define PROVS_NAME_VALIDUNTIL                       0x0B
#define PROVS_NAME_AUTHTYPE                         0x0C
#define PROVS_NAME_AUTHNAME                         0x0D
#define PROVS_NAME_AUTHSECRET                       0x0E
#define PROVS_NAME_LINGER                           0x0F
#define PROVS_NAME_BEARER                           0x10
#define PROVS_NAME_NAPID                            0x11
#define PROVS_NAME_COUNTRY                          0x12
#define PROVS_NAME_NETWORK                          0x13
#define PROVS_NAME_INTERNET                         0x14
#define PROVS_NAME_PROXY_ID                         0x15
#define PROVS_NAME_PROXY_PROVIDER_ID                0x16
#define PROVS_NAME_DOMAIN                           0x17
#define PROVS_NAME_PROVURL                          0x18
#define PROVS_NAME_PXAUTH_TYPE                      0x19
#define PROVS_NAME_PXAUTH_ID                        0x1A
#define PROVS_NAME_PXAUTH_PW                        0x1B
#define PROVS_NAME_STARTPAGE                        0x1C
#define PROVS_NAME_BASAUTH_ID                       0x1D
#define PROVS_NAME_BASAUTH_PW                       0x1E
#define PROVS_NAME_PUSHENABLED                      0x1F
#define PROVS_NAME_PXADDR                           0x20
#define PROVS_NAME_PXADDRTYPE                       0x21
#define PROVS_NAME_TO_NAPID                         0x22
#define PROVS_NAME_PORTNBR                          0x23
#define PROVS_NAME_SERVICE                          0x24
#define PROVS_NAME_LINKSPEED                        0x25
#define PROVS_NAME_DNLINKSPEED                      0x26
#define PROVS_NAME_LOCAL_ADDR                       0x27
#define PROVS_NAME_LOCAL_ADDR_TYPE                  0x28
#define PROVS_NAME_CONTEXT_ALLOW                    0x29
#define PROVS_NAME_TRUST                            0x2A
#define PROVS_NAME_MASTER                           0x2B
#define PROVS_NAME_SID                              0x2C
#define PROVS_NAME_SOC                              0x2D
#define PROVS_NAME_WSP_VERSION                      0x2E
#define PROVS_NAME_PHYSICAL_PROXY_ID                0x2F
#define PROVS_NAME_CLIENT_ID                        0x30
#define PROVS_NAME_DELIVERY_ERR_SDU                 0x31
#define PROVS_NAME_DELIVERY_ORDER                   0x32
#define PROVS_NAME_TRAFFIC_CLASS                    0x33
#define PROVS_NAME_MAX_SDU_SIZE                     0x34
#define PROVS_NAME_MAX_BITRATE_UPLINK               0x35
#define PROVS_NAME_MAX_BITRATE_DNLINK               0x36
#define PROVS_NAME_RESIDUAL_BER                     0x37
#define PROVS_NAME_SDU_ERROR_RATIO                  0x38
#define PROVS_NAME_TRAFFIC_HANDL_PRIO               0x39
#define PROVS_NAME_TRANSFER_DELAY                   0x3A
#define PROVS_NAME_GUARANTEED_BITRATE_UPLINK        0x3B
#define PROVS_NAME_GUARANTEED_BITRATE_DNLINK        0x3C
#define PROVS_NAME_PXADDR_FQDN                      0X3D
#define PROVS_NAME_PROXY_PW                         0X3E
#define PROVS_NAME_PPGAUTH_TYPE                     0x3F

#define PROVS_VERSION                               0x45
#define PROVS_VERSION_1_0                           0x46
#define PROVS_PULLENABLED_VAL                       0x47
#define PROVS_DNS_ADDR_VAL                          0x48
#define PROVS_MAX_NUM_RETRY_VAL                     0x49
#define PROVS_FIRST_RETRY_TIMEOUT_VAL               0x4A
#define PROVS_REREG_THRESHOLD_VAL                   0x4B
#define PROVS_T_BIT_VAL                             0x4C
#define PROVS_AUTH_ENTITY_VAL                       0x4E
#define PROVS_NAME_SPI_VAL                          0x4F

#define PROVS_TYPE                                  0x50
#define PROVS_TYPE_PXLOGICAL                        0x51
#define PROVS_TYPE_PXPHYSICAL                       0x52
#define PROVS_TYPE_PORT                             0x53
#define PROVS_TYPE_VALIDITY                         0x54
#define PROVS_TYPE_NAPDEF                           0x55
#define PROVS_TYPE_BOOTSTRAP                        0x56
#define PROVS_TYPE_VENDORCONFIG                     0x57
#define PROVS_TYPE_CLIENTIDENTITY                   0x58
#define PROVS_TYPE_PXAUTHINFO                       0x59
#define PROVS_TYPE_NAPAUTHINFO                      0x5A
#define PROVS_TYPE_ACCESS                           0x5B

/******* Provisiong Parameter Token Values **************/

#define PROVA_IPV4                                  0x85
#define PROVA_IPV6                                  0x86
#define PROVA_E164                                  0x87
#define PROVA_ALPHA                                 0x88
#define PROVA_APN                                   0x89
#define PROVA_SCODE                                 0x8A
#define PROVA_TETRA_ITSI                            0x8B
#define PROVA_MAN                                   0x8C

#define PROVA_ANALOG_MODEM                          0x90
#define PROVA_V_120                                 0x91
#define PROVA_V_110                                 0x92
#define PROVA_X_31                                  0x93
#define PROVA_BIT_TRANSPARENT                       0x94
#define PROVA_DIRECT_ASYNCHRONOUS_DATA_SERVICE      0x95

#define PROVA_PAP                                   0x9A
#define PROVA_CHAP                                  0x9B
#define PROVA_HTTP_BASIC                            0x9C
#define PROVA_HTTP_DIGEST                           0x9D
#define PROVA_WTLS_SS                               0x9E
#define PROVA_MD5_VAL                               0x9F

#define PROVA_GSM_USSD                              0xA2
#define PROVA_GSM_SMS                               0xA3
#define PROVA_ANSI_136_GUTS                         0xA4
#define PROVA_IS_95_CDMA_SMS                        0xA5
#define PROVA_IS_95_CDMA_CSD                        0xA6
#define PROVA_IS_95_CDMA_PACKET                     0xA7
#define PROVA_ANSI_136_CSD                          0xA8
#define PROVA_ANSI_136_GPRS                         0xA9
#define PROVA_GSM_CSD                               0xAA
#define PROVA_GSM_GPRS                              0xAB
#define PROVA_AMPS_CDPD                             0xAC
#define PROVA_PDC_CSD                               0xAD
#define PROVA_PDC_PACKET                            0xAE
#define PROVA_IDEN_SMS                              0xAF
#define PROVA_IDEN_CSD                              0xB0
#define PROVA_IDEN_PACKET                           0xB1
#define PROVA_FLEX_REFLEX                           0xB2
#define PROVA_PHS_SMS                               0xB3
#define PROVA_PHS_CSD                               0xB4
#define PROVA_TETRA_SDS                             0xB5
#define PROVA_TETRA_PACKET                          0xB6
#define PROVA_ANSI_136_GHOST                        0xB7
#define PROVA_MOBITEX_MPAK                          0xB8

#define PROVA_AUTOBAUDING                           0xC5

#define PROVA_CL_WSP                                0xCA
#define PROVA_CO_WSP                                0xCB
#define PROVA_CL_SEC_WSP                            0xCC
#define PROVA_CO_SEC_WSP                            0xCD
#define PROVA_CL_SEC_WTA                            0xCE
#define PROVA_CO_SEC_WTA                            0xCF

#define PROVA_OTA_HTTP_TO                           0xD0
#define PROVA_OTA_HTTP_TLS_TO                       0xD1
#define PROVA_OTA_HTTP_PO                           0xD2
#define PROVA_OTA_HTTP_TLS_PO                       0xD3
#define SRV_PROV_CODE_PAGE_ZERO_ATTR_VAL_AAA_TOKEN  0xE0
#define SRV_PROV_CODE_PAGE_ZERO_ATTR_VAL_HA_TOKEN   0xE1

#define SRV_PROV_TAGS_MIN                           PROVT_WAP_PROVISIONING_DOC
#define SRV_PROV_TAGS_MAX                           PROVT_PARM

#define SRV_PROV_SATTR_MIN                          PROVS_NAME
#define SRV_PROV_SATTR_MAX                          PROVS_TYPE_ACCESS

#define SRV_PROV_VATTR_MIN                          PROVA_IPV4
#define SRV_PROV_VATTR_MAX                          PROVA_OTA_HTTP_TLS_PO

/******* OMA Provisioning Parameter Token Values **************/

/* Tag tokens */

#define OMA_PROVT_CHARACTERISTIC                    0x06
#define OMA_PROVT_PARM                              0x07

/* Attribute start tokens */

#define OMA_PROVS_NAME                              0x05
#define OMA_PROVS_VALUE                             0x06
#define OMA_PROVS_NAME_VALUE                        0x07

#define OMA_PROVS_NAME_INTERNET                     0x14
#define OMA_PROVS_NAME_STARTPAGE                    0x1C
#define OMA_PROVS_NAME_TO_NAPID                     0x22
#define OMA_PROVS_NAME_PORTNBR                      0x23
#define OMA_PROVS_NAME_SERVICE                      0x24
#define OMA_PROVS_NAME_AACCEPT                      0x2E
#define OMA_PROVS_NAME_AAUTHDATA                    0x2F
#define OMA_PROVS_NAME_AAUTHLEVEL                   0x30
#define OMA_PROVS_NAME_AAUTHNAME                    0x31
#define OMA_PROVS_NAME_AAUTHSECRET                  0x32
#define OMA_PROVS_NAME_AAUTHTYPE                    0x33
#define OMA_PROVS_NAME_ADDR                         0x34
#define OMA_PROVS_NAME_ADDRTYPE                     0x35
#define OMA_PROVS_NAME_APPID                        0x36
#define OMA_PROVS_NAME_APROTOCOL                    0x37
#define OMA_PROVS_NAME_PROVIDER_ID                  0x38
#define OMA_PROVS_NAME_TO_PROXY                     0x39
#define OMA_PROVS_NAME_URI                          0x3A
#define OMA_PROVS_NAME_RULE                         0x3B

#define OMA_PROVS_TYPE                              0x50
#define OMA_PROVS_TYPE_PORT                         0x53
#define OMA_PROVS_TYPE_APPLICATION                  0x55
#define OMA_PROVS_TYPE_APPADDR                      0x56
#define OMA_PROVS_TYPE_APPAUTH                      0x57
#define OMA_PROVS_TYPE_CLIENTIDENTITY               0x58
#define OMA_PROVS_TYPE_RESOURCE                     0x59

/* OMA Provisioning Parameter Token Values  */

#define OMA_PROVS_COMMA                             0x80
#define OMA_PROVS_HTTP_                             0x81
#define OMA_PROVS_BASIC                             0x82
#define OMA_PROVS_DIGEST                            0x83
#define OMA_PROVS_IPV6                              0x86
#define OMA_PROVS_E164                              0x87
#define OMA_PROVS_ALPHA                             0x88

#define OMA_PROVS_APPSRV                            0x8D
#define OMA_PROVS_OBEX                              0x8E

#define OMA_PROVS_CL_WSP                            0xCA
#define OMA_PROVS_CO_WSP                            0xCB
#define OMA_PROVS_CL_SEC_WSP                        0xCC
#define OMA_PROVS_CO_SEC_WSP                        0xCD
#define OMA_PROVS_CL_SEC_WTA                        0xCE
#define OMA_PROVS_CO_SEC_WTA                        0xCF

#define OMA_PROV_TAGS_MIN                           OMA_PROVT_CHARACTERISTIC
#define OMA_PROV_TAGS_MAX                           OMA_PROVT_PARM
#define SRV_PROV_OMA_SATTR_MIN                      OMA_PROVS_NAME
#define SRV_PROV_OMA_SATTR_MAX                      OMA_PROVS_TYPE_RESOURCE
#define OMA_PROV_VATTR_MIN                          OMA_PROVS_COMMA
#define OMA_PROV_VATTR_MAX                          OMA_PROVS_CO_SEC_WTA

/* Charset */
#define UTF_8                                       0x6A

// #ifdef PROPRIETARY_PROVISIONING_WBXML_EXT

#define NOKIA_UNKNOWN_IDENTIFIER                    0x01
#define NOKIA_PROVT_CHARACTERISTICLIST              0x05

/* NOKIA Tag tokens */
#define NOKIA_PROVT_CHARACTERISTIC                  0x06
#define NOKIA_PROVT_PARM                            0x07

/* NOKIA Attribute start tokens */

#define NOKIA_PROVS_TYPE_ADDRESS                    0x06
#define NOKIA_PROVS_TYPE_URL                        0x07
#define NOKIA_PROVS_TYPE_NAME                       0x08
#define NOKIA_PROVS_TYPE_MMSURL                     0x7C
#define NOKIA_PROVS_TYPE_ID                         0x7D
#define NOKIA_PROVS_TYPE_BOOKMARK                   0x7F

#define NOKIA_PROVS_NAME                            0x10
#define NOKIA_PROVS_NAME_VALUE                      0x11
#define NOKIA_PROVS_NAME_BEARER                     0x12
#define NOKIA_PROVS_NAME_PROXY                      0x13
#define NOKIA_PROVS_NAME_PORT                       0x14
#define NOKIA_PROVS_NAME_NAME                       0x15
#define NOKIA_PROVS_NAME_PROXY_TYPE                 0x16
#define NOKIA_PROVS_NAME_URL                        0x17
#define NOKIA_PROVS_NAME_PROXY_AUTHNAME             0x18
#define NOKIA_PROVS_NAME_PROXY_AUTHSECRET           0x19
#define NOKIA_PROVS_NAME_SMS_SMSC_ADDRESS           0x1A
#define NOKIA_PROVS_NAME_USSD_SERVICE_CODE          0x1B
#define NOKIA_PROVS_NAME_GPRS_ACCESSPOINTNAME       0x1C
#define NOKIA_PROVS_NAME_PPP_LOGINTYPE              0x1D
#define NOKIA_PROVS_NAME_PROXY_LOGINTYPE            0x1E
#define NOKIA_PROVS_NAME_CSD_DIALSTRING             0x21
#define NOKIA_PROVS_NAME_CSD_CALLTYPE               0x28
#define NOKIA_PROVS_NAME_CSD_CALLSPEED              0x29
#define NOKIA_PROVS_NAME_PPP_AUTHTYPE               0x22
#define NOKIA_PROVS_NAME_PPP_AUTHNAME               0x23
#define NOKIA_PROVS_NAME_PPP_AUTHSECRET             0x24
#define NOKIA_PROVS_NAME_ISP_NAME                   0x7E

/******* NOKIA Provisiong Parameter Token Values **************/
#define NOKIA_PROVA_GSM_CSD                         0x45
#define NOKIA_PROVA_GSM_SMS                         0x46
#define NOKIA_PROVA_GSM_USSD                        0x47
#define NOKIA_PROVA_IS_136_USSD                     0x48
#define NOKIA_PROVA_GPRS                            0x49
#define NOKIA_PROVA_9200                            0x60
#define NOKIA_PROVA_9201                            0x61
#define NOKIA_PROVA_9202                            0x62
#define NOKIA_PROVA_9203                            0x63
#define NOKIA_PROVA_AUTOMATIC                       0x64
#define NOKIA_PROVA_MANUAL                          0x65
#define NOKIA_PROVA_AUTO                            0x6A
#define NOKIA_PROVA_9600                            0x6B
#define NOKIA_PROVA_14400                           0x6C
#define NOKIA_PROVA_19200                           0x6D
#define NOKIA_PROVA_28800                           0x6E
#define NOKIA_PROVA_38400                           0x6F
#define NOKIA_PROVA_PAP                             0x70
#define NOKIA_PROVA_CHAP                            0x71
#define NOKIA_PROVA_ANALOGUE                        0x72
#define NOKIA_PROVA_ISDN                            0x73
#define NOKIA_PROVA_43200                           0x74
#define NOKIA_PROVA_57600                           0x75
#define NOKIA_PROVA_MSISDN_NO                       0x76
#define NOKIA_PROVA_IPV4                            0x77
#define NOKIA_PROVA_MS_CHAP                         0x78

#define SRV_PROV_NOKIA_TAGS_MIN                     NOKIA_PROVT_CHARACTERISTICLIST
#define SRV_PROV_NOKIA_TAGS_MAX                     NOKIA_PROVT_PARM

#define SRV_PROV_NOKIA_SATTR_MIN                    NOKIA_PROVS_TYPE_ADDRESS
#define SRV_PROV_NOKIA_SATTR_MAX                    NOKIA_PROVS_TYPE_BOOKMARK

#define SRV_PROV_NOKIA_VATTR_MIN                    NOKIA_PROVA_GSM_CSD
#define SRV_PROV_NOKIA_VATTR_MAX                    NOKIA_PROVA_MS_CHAP

#define SRV_PROV_SATTR_DESC(a)                      (((a>=SRV_PROV_SATTR_MIN)&&(a<=SRV_PROV_SATTR_MAX))?prov_start_attributes[(a-SRV_PROV_SATTR_MIN)]:NULL)
#define SRV_PROV_VATTR_DESC(a)                      (((a>=SRV_PROV_VATTR_MIN)&&(a<=SRV_PROV_VATTR_MAX))?prov_value_attributes[(a-SRV_PROV_VATTR_MIN)]:NULL)

#define SRV_PROV_OMA_SATTR_DESC(a)                  (((a>=SRV_PROV_OMA_SATTR_MIN)&&(a<=SRV_PROV_OMA_SATTR_MAX))?pacOmaProvStartAttributes[(a-SRV_PROV_OMA_SATTR_MIN)]:NULL)
#define SRV_PROV_OMA_VATTR_DESC(a)                  (((a>=OMA_PROV_VATTR_MIN)&&(a<=OMA_PROV_VATTR_MAX))?pacOmaProvValueAttributes[(a-OMA_PROV_VATTR_MIN)]:NULL)

#define SRV_PROV_TAG_DESC(a)                        (((a>=SRV_PROV_TAGS_MIN)&&(a<=SRV_PROV_TAGS_MAX))?prov_tags[(a-SRV_PROV_TAGS_MIN)]:NULL)

/* SLIM_R */
#ifdef __PROV_NOKIA_OTA_SUPPORT__
#define SRV_PROV_NOKIA_TAG_DESC(a)                  (((a>=SRV_PROV_NOKIA_TAGS_MIN)&&(a<=SRV_PROV_NOKIA_TAGS_MAX))?nokia_prov_tags[(a-SRV_PROV_NOKIA_TAGS_MIN)]:NULL)

#define SRV_PROV_NOKIA_SATTR_DESC(a)                (((a>=SRV_PROV_NOKIA_SATTR_MIN)&&(a<=SRV_PROV_NOKIA_SATTR_MAX))?nokia_prov_start_attributes[(a-SRV_PROV_NOKIA_SATTR_MIN)]:NULL)
#endif
/* #define SRV_PROV_NOKIA_VATTR_DESC(a)                (((a>=SRV_PROV_NOKIA_VATTR_MIN)&&(a<=SRV_PROV_NOKIA_VATTR_MAX))?nokia_prov_value_attributes[(a-SRV_PROV_NOKIA_VATTR_MIN)]:NULL) */

#endif /* __PROVISIONING_SERVICE_SUPPORT__ */ 
#endif /* _PROVSERVICETAGHANDLER_H */ 

