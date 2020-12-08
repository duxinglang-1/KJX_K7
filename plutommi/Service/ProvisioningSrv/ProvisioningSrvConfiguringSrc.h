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
 * ProvisioningSrvConfiguringSrc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   header file for ProvisioningSrvConfiguringSrc.c file
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
#ifndef _PROVISIONINGSRVCONFIGURINGSRC_H
#define _PROVISIONINGSRVCONFIGURINGSRC_H

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

#include "MMIDataType.h"
//------------------------------ suggest Add ------------------------------
#include "ProvisioningSrvMain.h"
//------------------------------ usage ------------------------------

typedef S8 SRV_PROV_RETCODE;

#define SRV_PROV_ATTRIBUTE_VALUE_NUMBER             2
#define SRV_PROV_MAX_TONAPID_SUPPORT                10
#define SRV_PROV_MAX_CCA_NODE_LEVEL                 10
#define SRV_PROV_MAX_CCA_NODEID_ITTR                100

#define SRV_PROV_ROOT_NODE_VAL                      0x01
#define SRV_PROV_PXPHYSICAL_NODE_VAL                0x02
#define SRV_PROV_PXLOGICAL_NODE_VAL                 0x04
#define SRV_PROV_PORT_NODE_VAL                      0x08
#define SRV_PROV_PXAUTHINFO_NODE_VAL                0x10
#define SRV_PROV_APPLICATION_NODE_VAL               0x20
#define SRV_PROV_RESOURCE_NODE_VAL                  0x40
#define SRV_PROV_APPADDR_NODE_VAL                   0x80
#define SRV_PROV_APPAUTH_NODE_VAL                   0x100
#define SRV_PROV_BOOTSTRAP_NODE_VAL                 0x200
#define SRV_PROV_NAPDEF_NODE_VAL                    0x400
#define SRV_PROV_NAPAUTHINFO_NODE_VAL               0x800
#define SRV_PROV_VALIDITY_NODE_VAL                  0x1000
#define SRV_PROV_ACCESS_NODE_VAL                    0x2000

#define SRV_PROV_PXPHYSICAL_TXT                     "PXPHYSICAL"
#define SRV_PROV_PXLOGICAL_TXT                      "PXLOGICAL"
#define SRV_PROV_PXAUTHINFO_TXT                     "PXAUTHINFO"
#define SRV_PROV_NAPAUTHINFO_TXT                    "NAPAUTHINFO"
#define SRV_PROV_PORT_TXT                           "PORT"
#define SRV_PROV_RESOURCE_TXT                       "RESOURCE"
#define SRV_PROV_BOOTSTRAP_TXT                      "BOOTSTRAP"
#define SRV_PROV_APPADDR_TXT                        "APPADDR"
#define SRV_PROV_APPAUTH_TXT                        "APPAUTH"
#define SRV_PROV_NAPDEF_TXT                         "NAPDEF"
#define SRV_PROV_APPLICATION_TXT                    "APPLICATION"
#define SRV_PROV_PX_SIP_TXT                         "PX-SIP"
#define SRV_PROV_WIFI_TXT                           "wifi"
#define SRV_PROV_ACCESS_POINT_TXT                   "access-point"
#define SRV_PROV_AD_HOC_TXT                         "ad-hoc"
#define SRV_PROV_VALIDITY_TXT                       "VALIDITY"
#define SRV_PROV_ACCESS_TXT                         "ACCESS"

#define SRV_PROV_AACCEPT_TXT                        "AACCEPT"
#define SRV_PROV_AAUTHDATA_TXT                      "AAUTHDATA"
#define SRV_PROV_AAUTHLEVEL_TXT                     "AAUTHLEVEL"
#define SRV_PROV_AAUTHNAME_TXT                      "AAUTHNAME"
#define SRV_PROV_AAUTHSECRET_TXT                    "AAUTHSECRET"
#define SRV_PROV_AAUTHTYPE_TXT                      "AAUTHTYPE"
#define SRV_PROV_ADDR_TXT                           "ADDR"
#define SRV_PROV_ADDRTYPE_TXT                       "ADDRTYPE"
#define SRV_PROV_APPID_TXT                          "APPID"
#define SRV_PROV_APROTOCOL_TXT                      "APROTOCOL"
#define SRV_PROV_CIDPREFIX_TXT                      "CIDPREFIX"

#define SRV_PROV_INIT_TXT                           "INIT"
#define SRV_PROV_SERVICES_TXT                       "SERVICES"
#define SRV_PROV_SYNCTYPE_TXT                       "SYNCTYPE"
#define SRV_PROV_CLIURI_TXT                         "CLIURI"

#define SRV_PROV_APP_MMS_CM_TXT                     "CM"
#define SRV_PROV_APP_RM_TXT                         "RM"
#define SRV_PROV_APP_MODE_RESTRICTED_TXT            "R"
#define SRV_PROV_APP_MODE_WARNING_TXT               "W"
#define SRV_PROV_APP_MODE_FREE_TXT                  "F"
#define SRV_PROV_APP_MS_TXT                         "MS"
#define SRV_PROV_APP_MA_TXT                         "Ma"
#define SRV_PROV_APP_MA_VALUE_ENABLE_TXT            "ENABLE"
#define SRV_PROV_APP_MA_VALUE_DISABLE_TXT           "DISABLE"
#define SRV_PROV_APP_MA_VALUE_LOCKED_TXT            "LOCKED"
#define SRV_PROV_APP_PC_ADDR_TXT                    "PC-ADDR"
/* APGS support */
#define SRV_PROV_APP_MAX_BANDWIDTH_TXT              "MAX-BANDWIDTH"
#define SRV_PROV_APP_NETINFO_TXT                    "NETINFO"
#define SRV_PROV_APP_MIN_UDP_PORT                   "MIN-UDP-PORT"
#define SRV_PROV_APP_MAX_UDP_PORT                   "MAX-UDP-PORT"
/* APGS support */


#define SRV_PROV_FROM_TXT                           "FROM"
#define SRV_PROV_NAME_TXT                           "NAME"
#define SRV_PROV_PROVIDER_ID_TXT                    "PROVIDER-ID"
#define SRV_PROV_RT_ADDR_TXT                        "RT-ADDR"
#define SRV_PROV_STARTPAGE_TXT                      "STARTPAGE"
#define SRV_PROV_TO_PROXY_TXT                       "TO-PROXY"
#define SRV_PROV_URI_TXT                            "URI"
#define SRV_PROV_AUTH_ENTITY_TXT                    "AUTH-ENTITY"
#define SRV_PROV_AUTHNAME_TXT                       "AUTHNAME"
#define SRV_PROV_AUTHSECRET_TXT                     "AUTHSECRET"
#define SRV_PROV_AUTHTYPE_TXT                       "AUTHTYPE"
#define SRV_PROV_BASAUTH_ID_TXT                     "BASAUTH-ID"
#define SRV_PROV_BASAUTH_PW_TXT                     "BASAUTH-PW"
#define SRV_PROV_BEARER_TXT                         "BEARER"
#define SRV_PROV_CALLTYPE_TXT                       "CALLTYPE"
#define SRV_PROV_COUNTRY_TXT                        "COUNTRY"
#define SRV_PROV_DELIVERY_ERR_SDU_TXT               "DELIVERY-ERR-SDU"
#define SRV_PROV_DELIVERY_ORDER_TXT                 "DELIVERY-ORDER"
#define SRV_PROV_DNLINKSPEED_TXT                    "DNLINKSPEED"
#define SRV_PROV_DNS_ADDR_TXT                       "DNS-ADDR"
#define SRV_PROV_FIRST_RETRY_TIMEOUT_TXT            "FIRST-RETRY-TIMEOUT"
#define SRV_PROV_GUARANTEED_BITRATE_DNLINK_TXT      "GUARANTEED-BITRATE-DNLINK"
#define SRV_PROV_GUARANTEED_BITRATE_UPLINK_TXT      "GUARANTEED-BITRATE-UPLINK"
#define SRV_PROV_CALLSPEED_AUTOBAUDING_TXT          "AUTOBAUDING"
#define SRV_PROV_INTERNET_TXT                       "INTERNET"
#define SRV_PROV_LINGER_TXT                         "LINGER"
#define SRV_PROV_LINKSPEED_TXT                      "LINKSPEED"
#define SRV_PROV_LOCAL_ADDR_TXT                     "LOCAL-ADDR"
#define SRV_PROV_LOCAL_ADDRTYPE_TXT                 "LOCAL-ADDRTYPE"
#define SRV_PROV_MASTER_TXT                         "MASTER"
#define SRV_PROV_MAX_BITRATE_DNLINK_TXT             "MAX-BITRATE-DNLINK"
#define SRV_PROV_MAX_BITRATE_UPLINK_TXT             "MAX-BITRATE-UPLINK"
#define SRV_PROV_MAX_NUM_RETRY_TXT                  "MAX-NUM-RETRY"
#define SRV_PROV_MAX_SDU_SIZE_TXT                   "MAX-SDU-SIZE"
#define SRV_PROV_NAP_ADDRESS_TXT                    "NAP-ADDRESS"
#define SRV_PROV_NAP_ADDRTYPE_TXT                   "NAP-ADDRTYPE"
#define SRV_PROV_NAPID_TXT                          "NAPID"
#define SRV_PROV_NETWORK_TXT                        "NETWORK"
#define SRV_PROV_PHYSICAL_PROXY_ID_TXT              "PHYSICAL-PROXY-ID"
#define SRV_PROV_PORTNBR_TXT                        "PORTNBR"
#define SRV_PROV_PPGAUTH_TYPE_TXT                   "PPGAUTH-TYPE"
#define SRV_PROV_PROXY_ID_TXT                       "PROXY-ID"
#define SRV_PROV_CONTEXT_ALLOW_TXT                  "CONTEXT-ALLOW"
#define SRV_PROV_PROVURL_TXT                        "PROVURL"
#define SRV_PROV_PROXY_PROVIDER_ID_TXT              "PROXY-PROVIDER-ID"
#define SRV_PROV_PROXY_PW_TXT                       "PROXY-PW"
#define SRV_PROV_PULLENABLED_TXT                    "PULLENABLED"
#define SRV_PROV_PUSHENABLED_TXT                    "PUSHENABLED"
#define SRV_PROV_PXADDR_TXT                         "PXADDR"
#define SRV_PROV_PXADDR_FQDN_TXT                    "PXADDR-FQDN"
#define SRV_PROV_PXADDRTYPE_TXT                     "PXADDRTYPE"
#define SRV_PROV_PXAUTH_ID_TXT                      "PXAUTH-ID"
#define SRV_PROV_PXAUTH_PW_TXT                      "PXAUTH-PW"
#define SRV_PROV_PXAUTH_TYPE_TXT                    "PXAUTH-TYPE"
#define SRV_PROV_REREG_THRESHOLD_TXT                "REREG-THRESHOLD"
#define SRV_PROV_RESIDUAL_BER_TXT                   "RESIDUAL-BER"
#define SRV_PROV_SDU_ERROR_RATIO_TXT                "SDU-ERROR-RATIO"
#define SRV_PROV_SERVICE_TXT                        "SERVICE"
#define SRV_PROV_SID_TXT                            "SID"
#define SRV_PROV_SOC_TXT                            "SOC"
#define SRV_PROV_SPI_TXT                            "SPI"
#define SRV_PROV_T_BIT_TXT                          "T-BIT"
#define SRV_PROV_TO_NAPID_TXT                       "TO-NAPID"
#define SRV_PROV_TRAFFIC_CLASS_TXT                  "TRAFFIC-CLASS"
#define SRV_PROV_TRAFFIC_HANDL_PRIO_TXT             "TRAFFIC-HANDL-PRIO"
#define SRV_PROV_TRANSFER_DELAY_TXT                 "TRANSFER-DELAY"
#define SRV_PROV_TRUST_TXT                          "TRUST"
#define SRV_PROV_VALIDUNTIL_TXT                     "VALIDUNTIL"
#define SRV_PROV_WSP_VERSION_TXT                    "WSP-VERSION"
/* ENUM VALUE START */
#define SRV_PROV_IPV4_TXT                           "IPV4"
#define SRV_PROV_IPV6_TXT                           "IPV6"
#define SRV_PROV_E164_TXT                           "E164"
#define SRV_PROV_ALPHA_TXT                          "ALPHA"
#define SRV_PROV_APN_TXT                            "APN"
#define SRV_PROV_SCODE_TXT                          "SCODE"
#define SRV_PROV_TETRA_ITSI_TXT                     "TETRA-ITSI"
#define SRV_PROV_MAN_TXT                            "MAN"

#define SRV_PROV_CL_WSP_TXT                        "CL-WSP"
#define SRV_PROV_CO_WSP_TXT                        "CO-WSP"
#define SRV_PROV_CL_SEC_WSP_TXT                    "CL-SEC-WSP"
#define SRV_PROV_CO_SEC_WSP_TXT                    "CO-SEC-WSP"
#define SRV_PROV_CO_SEC_WTA_TXT                    "CO-SEC-WTA"
#define SRV_PROV_CL_SEC_WTA_TXT                    "CL-SEC-WTA"
#define SRV_PROV_OTA_HTTP_TO_TXT                   "OTA-HTTP-TO"
#define SRV_PROV_OTA_HTTP_TLS_TO_TXT               "OTA-HTTP-TLS-TO"
#define SRV_PROV_OTA_HTTP_PO_TXT                   "OTA-HTTP-PO"
#define SRV_PROV_OTA_HTTP_TLS_PO_TXT               "OTA-HTTP-TLS-PO"
#define SRV_PROV_STARTTLS_TXT                      "STARTTLS"

#define SRV_PROV_GSM_CSD_TXT                       "GSM-CSD"
#define SRV_PROV_GSM_GPRS_TXT                      "GSM-GPRS"
#define SRV_PROV_GSM_USSD_TXT                      "GSM-USSD"
#define SRV_PROV_GSM_SMS_TXT                       "GSM-SMS"
#define SRV_PROV_CDMA_SMS_TXT                      "IS-95-CDMA-SMS"
#define SRV_PROV_CDMA_CSD_TXT                      "IS-95-CDMA-CSD"
#define SRV_PROV_CDMA_PACKET_TXT                   "IS-95-CDMA-PACKET"
#define SRV_PROV_ANSI_136_GUTS_TXT                 "ANSI-136-GUTS"
#define SRV_PROV_ANSI_136_CSD_TXT                  "ANSI-136-CSD"
#define SRV_PROV_ANSI_136_GPRS_TXT                 "ANSI-136_GPRS"
#define SRV_PROV_ANSI_136_GHOST_TXT                "ANSI-136_GHOST"
#define SRV_PROV_AMPS_CDPD_TXT                     "AMPS-CDPD"
#define SRV_PROV_PDC_CSD_TXT                       "PDC-CSD"
#define SRV_PROV_PDC_PACKET_TXT                    "PDC-PACKET"
#define SRV_PROV_IDEN_SMS_TXT                      "IDEN-SMS"
#define SRV_PROV_IDEN_CSD_TXT                      "IDEN-CSD"
#define SRV_PROV_IDEN_PACKET_TXT                   "IDEN-PACKET"
#define SRV_PROV_FLEX_REFLEX_TXT                   "FLEX/REFLEX"
#define SRV_PROV_PHS_SMS_TXT                       "PHS-SMS"
#define SRV_PROV_PHS_CSD_TXT                       "PHS-CSD"
#define SRV_PROV_TETRA_SDS_TXT                     "TETRA-SDS"
#define SRV_PROV_TETRA_PACKET_TXT                  "TETRA-PACKET"
#define SRV_PROV_MOBITEX_MPAK_TXT                  "MOBITEX MPAK"
#define SRV_PROV_CDMA2000_1X_SIMPLE_IP_TXT         "CDMA2000-1X-SIMPLE-IP"
#define SRV_PROV_CDMA2000_1X_MOBILE_IP_TXT         "CDMA2000-1X_MOBILE_IP"
#define SRV_PROV_ANALOG_MODEM_TXT                  "ANALOG-MODEM"
#define SRV_PROV_V120_TXT                          "V.120"
#define SRV_PROV_V110_TXT                          "V.110"
#define SRV_PROV_X31_TXT                           "X.31"
#define SRV_PROV_BIT_TRANSPARENT_TXT               "BIT-TRANSPARENT"
#define SRV_PROV_DIRECT_ASYNC_DATA_SERVICE_TXT     "DIRECT-ASYNCHRONOUS-DATA-SERVICE"

#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
/* DMP Spec */

#define SRV_PROV_PXSIP_NAME_TXT                        "NAME"
#define SRV_PROV_PXSIP_USER_NAME_TXT                   "USER-NAME"
#define SRV_PROV_PXSIP_AUTH_NAME_TXT                   "AUTH-NAME"
#define SRV_PROV_PXSIP_AUTH_PASSWD_TXT                 "AUTH-PASSWD"
#define SRV_PROV_PXSIP_DOMAIN_TXT                      "DOMAIN"
#define SRV_PROV_PXSIP_LOCAL_PORT_TXT                  "LOCAL-PORT"
#define SRV_PROV_PXSIP_PREFER_CODEC_TXT                "PREFER-CODEC"
#define SRV_PROV_PXSIP_PXSRV_ADDR_TXT                  "PXSRV-ADDR"
#define SRV_PROV_PXSIP_PXSRV_ADDRTYPE_TXT              "PXSRV-ADDRTYPE"
#define SRV_PROV_PXSIP_PXSRV_PORT_TXT                  "PXSRV-PORT"
#define SRV_PROV_PXSIP_REGSRV_ADDR_TXT                 "REGSRV-ADDR"
#define SRV_PROV_PXSIP_REGSRV_ADDRTYPE_TXT             "REGSRV-ADDRTYPE"
#define SRV_PROV_PXSIP_REGSRV_PORT_TXT                 "REGSRV-PORT"
#define SRV_PROV_PXSIP_REGSRV_REGPERIOD_TXT            "REGSRV-REGPERIOD"
#define SRV_PROV_PXSIP_OUTPXSRV_ADDR_TXT               "OUTPXSRV-ADDR"
#define SRV_PROV_PXSIP_OUTPXSRV_ADDRTYPE_TXT           "OUTPXSRV-ADDRTYPE"
#define SRV_PROV_PXSIP_OUTPXSRV_PORT_TXT               "OUTPXSRV-PORT"
#define SRV_PROV_PXSIP_RTP_AUDIO_PORT_TXT              "RTP-AUDIO-PORT"
#define SRV_PROV_PXSIP_RTP_PACKET_PERIOD_TXT           "RTP-PACKET-PERIOD"
#define SRV_PROV_PXSIP_NAT_RPORT_ENABLED_TXT           "NAT-RPORT-ENABLED"
#define SRV_PROV_PXSIP_NAT_STUN_ENABLED_TXT            "NAT-STUN-ENABLED"
#define SRV_PROV_PXSIP_NAT_STUNSRV_ADDR_TXT            "NAT-STUNSRV-ADDR"
#define SRV_PROV_PXSIP_NAT_STUNSRV_ADDRTYPE_TXT        "NAT-STUNSRV-ADDRTYPE"
#define SRV_PROV_PXSIP_NAT_STUNSRV_PORT_TXT            "NAT-STUNSRV-PORT"
#define SRV_PROV_PXSIP_NAT_STUNSRV_REFRESH_PERIOD_TXT  "NAT-STUNSRV-REFRESH-PERIOD"

#define SRV_PROV_WIFI_ADHOC_TXT                        "AdHoc"
#define SRV_PROV_WIFI_AUTHENTICATION_TXT               "Authentication"
#define SRV_PROV_WIFI_ENCRYPTION_TXT                   "Encryption"
#define SRV_PROV_WIFI_KEYPROVIDED_TXT                  "KeyProvided"
#define SRV_PROV_WIFI_NETWORKKEY_TXT                   "NetworkKey"
#define SRV_PROV_WIFI_KEYINDEX_TXT                     "KeyIndex"
#define SRV_PROV_WIFI_USE8021X_TXT                     "Use8021x"
#define SRV_PROV_WIFI_EAPTYPE_TXT                      "EAPType"

#define SRV_PROV_PXSIP_CODEC_G711A_TXT                  "G.711A"
#define SRV_PROV_PXSIP_CODEC_G711U_TXT                  "G.711U"
#define SRV_PROV_PXSIP_CODEC_G726_16_TXT                "G.726-16"
#define SRV_PROV_PXSIP_CODEC_G726_24_TXT                "G.726-24"
#define SRV_PROV_PXSIP_CODEC_G726_32_TXT                "G.726-32"
#define SRV_PROV_PXSIP_CODEC_G726_40_TXT                "G.726-40"

#define SRV_PROV_PXSIP_NODE_VAL                         0x4000
#define SRV_PROV_WIFI_NODE_VAL                          0x10000
#define SRV_PROV_ACCESS_POINT_NODE_VAL                  0x20000
#define SRV_PROV_AD_HOC_NODE_VAL                        0x40000
#define SRV_PROV_WIFI_PROFILE_NODE_VAL                  0x80000

#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */

#define SRV_PROV_AUTHTYPE_HTTP_BASIC_TXT                "HTTP-BASIC"
#define SRV_PROV_AUTHTYPE_HTTP_DIGEST_TXT               "HTTP-DIGEST"
#define SRV_PROV_AUTHTYPE_BASIC_TXT                     "BASIC"
#define SRV_PROV_AUTHTYPE_DIGEST_TXT                    "DIGEST"
#define SRV_PROV_AUTHTYPE_WTLS_SS_TXT                   "WTLS-SS"
#define SRV_PROV_AUTHTYPE_CRAM_MD5_TXT                  "CRAM-MD5"
#define SRV_PROV_AUTHTYPE_DIGEST_MD5_TXT                "DIGEST-MD5"
#define SRV_PROV_AUTHTYPE_LOGIN_TXT                     "LOGIN"
#define SRV_PROV_AUTHTYPE_PLAIN_TXT                     "PLAIN"
#define SRV_PROV_AUTHTYPE_APOP_TXT                      "APOP"
#define SRV_PROV_AUTHTYPE_GSSAPI_TXT                    "GSSAPI"
#define SRV_PROV_AUTHTYPE_KERBEROS_V4_TXT               "KERBEROS_V4"
#define SRV_PROV_AUTHTYPE_SKEY_TXT                      "SKEY"
#define SRV_PROV_AUTHTYPE_PAP_TXT                       "PAP"
#define SRV_PROV_AUTHTYPE_CHAP_TXT                      "CHAP"
#define SRV_PROV_AUTHTYPE_MS_CHAP_TXT                   "MS_CHAP"
#define SRV_PROV_AUTHTYPE_MD5_TXT                       "MD5"
#define SRV_PROV_AUTHTYPE_X509_TXT                      "X509"
#define SRV_PROV_AUTHTYPE_SECURID_TXT                   "SECURID"
#define SRV_PROV_AUTHTYPE_SAFEWORD_TXT                  "SAFEWORD"
#define SRV_PROV_AUTHTYPE_DIGIPASS_TXT                  "DIGIPASS"
#define SRV_PROV_AUTHTYPE_HMAC_TXT                      "HMAC"
#define SRV_PROV_AUTHLEVEL_APPSRV_TXT                   "APPSRV"
#define SRV_PROV_AUTHLEVEL_OBEX_TXT                     "OBEX"
#define SRV_PROV_AUTHLEVEL_CLIENT_TXT                   "CLIENT"
#define SRV_PROV_AUTHENTITY_AAA_TXT                     "AAA"
#define SRV_PROV_AUTHENTITY_HA_TXT                      "HA"
#define SRV_PROV_PUSHPULL_ENABLED_TXT                   "1"
#define SRV_PROV_PUSHPULL_DISABLED_TXT                  "0"
#define SRV_PROV_OMA_APPID_BRW                          "w2"
#define SRV_PROV_OMA_APPID_MMS                          "w4"

#ifdef __PROV_NOKIA_OTA_SUPPORT__

#define SRV_PROV_NE_ADRESS_NODE_VAL                     0x100000
#define SRV_PROV_NE_URL_NODE_VAL                        0x200000
#define SRV_PROV_NE_MMSURL_NODE_VAL                     0x400000
#define SRV_PROV_NE_NAME_NODE_VAL                       0x800000
#define SRV_PROV_NE_BOOKMARK_NODE_VAL                   0x1000000
#define SRV_PROV_NE_ID_NODE_VAL                         0x2000000

#define SRV_PROV_NE_ADDRESS_TXT                         "ADDRESS"
#define SRV_PROV_NE_URL_TXT                             "URL"
#define SRV_PROV_NE_MMSURL_TXT                          "MMSURL"
#define SRV_PROV_NE_BOOKMARK_TXT                        "BOOKMARK"
#define SRV_PROV_NE_ID_TXT                              "ID"
#define SRV_PROV_NE_BEARER_TXT                          "BEARER"
#define SRV_PROV_NE_PPP_AUTHTYPE_TXT                    "PPP_AUTHTYPE"
#define SRV_PROV_NE_PPP_AUTHNAME_TXT                    "PPP_AUTHNAME"
#define SRV_PROV_NE_PPP_AUTHSECRET_TXT                  "PPP_AUTHSECRET"
#define SRV_PROV_NE_PPP_LOGINTYPE_TXT                   "PPP_LOGINTYPE"
#define SRV_PROV_NE_PROXY_TXT                           "PROXY"
#define SRV_PROV_NE_PROXY_TYPE_TXT                      "PROXY_TYPE"
#define SRV_PROV_NE_PROXY_AUTHNAME_TXT                  "PROXY_AUTHNAME"
#define SRV_PROV_NE_PROXY_AUTHSECRET_TXT                "PROXY_AUTHSECRET"
#define SRV_PROV_NE_PROXY_LOGINTYPE_TXT                 "PROXY_LOGINTYPE"
#define SRV_PROV_NE_PORT_TXT                            "PORT"
#define SRV_PROV_NE_CSD_DIALSTRING_TXT                  "CSD_DIALSTRING"
#define SRV_PROV_NE_CSD_CALLTYPE_TXT                    "CSD_CALLTYPE"
#define SRV_PROV_NE_CSD_CALLSPEED_TXT                   "CSD_CALLSPEED"
#define SRV_PROV_NE_CALLSPEED_AUTO_TXT                  "AUTO"
#define SRV_PROV_NE_ISP_NAME_TXT                        "ISP_NAME"
#define SRV_PROV_NE_SMS_SMSC_ADDRESS_TXT                "SMS_SMSC_ADDRESS"
#define SRV_PROV_NE_USSD_SERVICE_CODE_TXT               "USSD_SERVICE_CODE"
#define SRV_PROV_NE_GPRS_ACCESSPOINTNAME_TXT            "GPRS_ACCESSPOINTNAME"
#define SRV_PROV_NE_GSM_CSD_TXT                         "GSM/CSD"
#define SRV_PROV_NE_GSM_SMS_TXT                         "GSM/SMS"
#define SRV_PROV_NE_GSM_USSD_TXT                        "GSM/USSD"
#define SRV_PROV_NE_IS_136_CSD_TXT                      "IS-136/CSD"
#define SRV_PROV_NE_GPRS_TXT                            "GPRS"
#define SRV_PROV_NE_ANALOGUE_TXT                        "ANALOGUE"
#define SRV_PROV_NE_ISDN_TXT                            "ISDN"
#define SRV_PROV_NE_MSISDN_NO_TXT                       "MSISDN_NO"
#define SRV_PROV_NE_IPV4_TXT                            "IPV4"
#define SRV_PROV_NE_LOGINTYPE_AUTOMATIC_TXT             "AUTOMATIC"
#define SRV_PROV_NE_LOGINTYPE_MANUAL_TXT                "MANUAL"
#define SRV_PROV_NE_PORT_9200                           9200
#define SRV_PROV_NE_PORT_9201                           9201
#define SRV_PROV_NE_PORT_9202                           9202
#define SRV_PROV_NE_PORT_9203                           9203
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

typedef enum
{
    SRV_PROV_CHARACTERISTIC_START,
    SRV_PROV_CHARACTERISTIC_END,
    /* Add before this */
    SRV_PROV_CHARACTERISTIC_TOTAL
} srv_prov_characteristic_status_enum;

typedef enum
{
    SRV_PROV_CCA_CONV_TYPE_STR = 1,
    SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
    SRV_PROV_CCA_CONV_TYPE_INT,
    SRV_PROV_CCA_CONV_TYPE_TOTAL    /* Add element before it */
} srv_prov_cca_conv_type_enum;

/* Structure to store tag handler info for parameters of a particular characteristic */
typedef struct
{
    U8 *param;
    U16 cca_symbol;
    srv_prov_cca_conv_type_enum convtype;

      SRV_PROV_RETCODE(*param_tag_hdlr) (U16 *attr_value, S32 *root, U16 *ret_value);
} srv_prov_characteristic_parm_tag_hdlr_struct;

/* Structure to convert string to CCA ENUM */
typedef struct
{
    U8 *src_str;
    U16 cca_enum_value;
} srv_prov_convert_str_to_cca_enum_struct;

/* Structure to store tag handler info for characteristics. */
typedef struct
{
    U8 *characterestic;
    U16 cca_node_id;
    S32 src_parent_node_id;
    S32 src_node_id;

      SRV_PROV_RETCODE(*characteristic_tag_hdlr) (S32 *root, srv_prov_characteristic_status_enum charac_status);

    const srv_prov_characteristic_parm_tag_hdlr_struct *char_param_tag_map_hdlr;
} srv_prov_characteristic_tag_hdlr_struct;

/* Structure to store CCA node handles' addresses for current setting being parsed */
typedef struct
{
    S32 par_cca_node_h;
    S32 crt_cca_node_h;

      SRV_PROV_RETCODE(*characteristic_tag_hdlr) (S32 *root, srv_prov_characteristic_status_enum charac_status);

    const srv_prov_characteristic_parm_tag_hdlr_struct *char_param_tag_map_hdlr;
} srv_prov_curr_ccanode_characteristic_tag_hdlr_st;

/* Structure to create CCA node handles list */
typedef struct srv_prov_cca_node_hdlr_st srv_prov_cca_node_hdlr_st;
typedef struct srv_prov_cca_node_hdlr_st
{
    S32 node_h; /* Contains parent node handler or sibling node handler */
    S32 cur_node_h;
    srv_prov_cca_node_hdlr_st *node_hdlr_next;
} srv_prov_cca_node_hdlr_st;

#ifdef __PROV_NOKIA_OTA_SUPPORT__

/* CCA Node list structure for NE setting. */
typedef struct srv_prov_cca_ne_node_list_struct srv_prov_cca_ne_node_list_struct;
typedef struct srv_prov_cca_ne_node_list_struct
{
    S32 node_h;
    srv_prov_cca_ne_node_list_struct *node_next;
} srv_prov_cca_ne_node_list_struct;
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

#endif /* __PROVISIONING_SERVICE_SUPPORT__ */ 
#endif /* _PROVSERVICECONFIGURINGSRC_H */ 

