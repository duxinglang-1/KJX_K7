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
 * DtcntSrvIprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   These are the internal services provided by data account service module.
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
#ifndef _DTCNT_SRV_IPROT_H
#define _DTCNT_SRV_IPROT_H

/* include gprot.h */
#include "DtcntSrvGprot.h"
#include "cbm_consts.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wndrv_cnst.h"

#define SRV_DTCNT_INT_DEFS
/****************************************************************************/
/* Definitions                                                              */
/****************************************************************************/
#ifdef __WIFI_SLIM__
#define SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM  (10)
#else
#define SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM  (30)		/* MAX WLAN profile number */
#endif
#ifdef __WAPI_SUPPORT__
#define SRV_DTCNT_WAPI_PSK_STR_LEN  (32+1)			/* WAPI PSK string length */
#endif /* __WAPI_SUPPORT__ */

/* Maximum length of MAC ADDR length */
#define SRV_DTCNT_MAX_MAC_ADDR_LEN  (6)

/******************************************************************************/
/*                                                                            */
/* Data Account SRV database GSM_GPRS profile record attributes configuration */
/*                                                                            */
/******************************************************************************/
/* SRV profile database attributes config values : Default settings */
#define SRV_DTCNT_PROF_CONFIG_DEFAULT_ENABLE    (0x00000001)
/* SRV profile database attributes config values : APP Type */
#define SRV_DTCNT_PROF_CONFIG_APP_TYPE_ENABLE   (0x00000002)
/* SRV profile database attributes config values : INET IP/NETMASK/DNS */
#define SRV_DTCNT_PROF_CONFIG_INET_ENABLE       (0x00000004)
/* SRV profile database attributes config values : PROXY */
#define SRV_DTCNT_PROF_CONFIG_PROXY_ENABLE      (0x00000008)
/* SRV profile database attributes config values : HOMEPAGE */
#define SRV_DTCNT_PROF_CONFIG_HOME_ENABLE       (0x00000010)
/* SRV profile database attributes config values : ALL settings */
#define SRV_DTCNT_PROF_CONFIG_ALL_ENABLE        (SRV_DTCNT_PROF_CONFIG_DEFAULT_ENABLE|SRV_DTCNT_PROF_CONFIG_APP_TYPE_ENABLE| SRV_DTCNT_PROF_CONFIG_INET_ENABLE|SRV_DTCNT_PROF_CONFIG_PROXY_ENABLE|SRV_DTCNT_PROF_CONFIG_HOME_ENABLE)

/**********************************************************************************/
/*                                                                                */
/* Data Account SRV database GSM_GPRS profile query/update/add fields definitions */
/*                                                                                */
/**********************************************************************************/
/* Set NAME field in account profile */
#define SRV_DTCNT_PROF_FIELD_NAME           (0x00000001)
/* Set APN/DialNumber field in account profile depends on GPRS or CSD profile */
#define SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM   (0x00000002)
/* Set AuthType field in account profile */
#define SRV_DTCNT_PROF_FIELD_AUTH_TYPE      (0x00000004)
/* Set Auth.user field in account profile */
#define SRV_DTCNT_PROF_FIELD_AUTH_USER_ID   (0x00000008)
/* Set Auth.pass field in account profile */
#define SRV_DTCNT_PROF_FIELD_AUTH_USER_PW   (0x00000010)
/* Set Auth user info field in account profile */
#define SRV_DTCNT_PROF_FIELD_AUTH_USER_INFO (SRV_DTCNT_PROF_FIELD_AUTH_USER_ID | SRV_DTCNT_PROF_FIELD_AUTH_USER_PW)
/* Set AccountType field in account profile */
#define SRV_DTCNT_PROF_FIELD_ACC_TYPE       (0x00000020)
/* Set SIMType field in account profile */
#define SRV_DTCNT_PROF_FIELD_SIM_TYPE       (0x00000040)
/* Set AppType field in account profile */
#define SRV_DTCNT_PROF_FIELD_APP_TYPE       (0x00000080)
/* Set UserData field in account profile */
#define SRV_DTCNT_PROF_FIELD_USER_DATA      (0x00000100)
/* Set CSD dial type field in account profile */
#define SRV_DTCNT_PROF_FIELD_DIAL_TYPE      (0x00000200)
/* Set CSD data rate field in account profile */
#define SRV_DTCNT_PROF_FIELD_DATA_RATE      (0x00000400)
/* Set INET static IP field in account profile */
#define SRV_DTCNT_PROF_FIELD_INET_IP        (0x00000800)
/* Set INET Netmask field in account profile */
#define SRV_DTCNT_PROF_FIELD_INET_MASK      (0x00001000)
/* Set INET Primary DNS field in account profile */
#define SRV_DTCNT_PROF_FIELD_INET_PRI_DNS   (0x00002000)
/* Set INET Secondary DNS field in account profile */
#define SRV_DTCNT_PROF_FIELD_INET_SEC_DNS   (0x00004000)
/* Set Homepage field in account profile */
#define SRV_DTCNT_PROF_FIELD_HOME           (0x00008000)
/* Set Proxy addr/port field in account profile */
#define SRV_DTCNT_PROF_FIELD_PX_ADDR        (0x00010000)
/* Set Proxy port field in account profile */
#define SRV_DTCNT_PROF_FIELD_PX_PORT        (0x00020000)
/* Set Proxy field in account profile */

//#define SRV_DTCNT_PROF_FIELD_PROXY          (SRV_DTCNT_PROF_FIELD_PX_ADDR | SRV_DTCNT_PROF_FIELD_PX_PORT)

/* Set Proxy auth.user field in account profile */
#define SRV_DTCNT_PROF_FIELD_PX_AUTH_ID     (0x00040000)
/* Set Proxy auth.pass field in account profile */
#define SRV_DTCNT_PROF_FIELD_PX_AUTH_PW     (0x00080000)
/* Set Proxy auth info field in account profile */
#define SRV_DTCNT_PROF_FIELD_PX_AUTH        (SRV_DTCNT_PROF_FIELD_PX_AUTH_ID | SRV_DTCNT_PROF_FIELD_PX_AUTH_PW)
/* Set Proxy service type field in account profile */
#define SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE    (0x00100000)

/* Set Proxy ID in account profile (used in sms bootstrap) */
//#define SRV_DTCNT_PROF_FIELD_PX_ID          (0x00200000)
/* Set Proxy Name in account profile (used in otap) */
//#define SRV_DTCNT_PROF_FIELD_PX_NAME        (0x00400000)

/* Set OMACP hash value fields in account profile (used in ota) */
#define SRV_DTCNT_PROF_FIELD_HASH_VAL       (0x00800000)
/* Set profile read only fields in account profile (used in OMA bootstrap) */
#define SRV_DTCNT_PROF_FIELD_READONLY       (0x01000000)
/* Set Proxy use flag field in account profile */
#define SRV_DTCNT_PROF_FIELD_USE_PX         (0x02000000)

/* Set All fields */
#define SRV_DTCNT_PROF_FIELD_ALL            (0xFFFFFFFF)

/******************************************************************************/
/*                                                                            */
/* Data Account SRV database WLAN profile query/update/add fields definitions */
/*                                                                            */
/******************************************************************************/
/* Set NAME field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_NAME                  (0x00000001)
/* Set SSID and ssid_len fields in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_SSID                  (0x00000002)

/* Set channel field in wlan account profile */
//#define SRV_DTCNT_WLAN_PROF_FIELD_CHANNEL               (0x00000004)

/* Set use_dhcp field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_DHCP                  (0x00000004)
/* Set IP field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_IP                    (0x00000008)
/* Set Netmask field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_NETMASK               (0x00000010)
/* Set Netmask field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_GATEWAY               (0x00000020)
/* Set DNS1 field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_DNS1                  (0x00000040)
/* Set DNS2 field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_DNS2                  (0x00000080)
/* Set priority field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY            (0x00000100)
/* Set network type field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_NET_TYPE              (0x00000200)
/* Set auth type field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_AUTH_TYPE             (0x00000400)
/* Set encrypt type field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_ENCRYPT_TYPE          (0x00000800)
/* Set certificate info fields in wlan account profile (root related fields) */
#define SRV_DTCNT_WLAN_PROF_FIELD_ROOT_CERT_SETTINGS    (0x00001000)
/* Set certificate info fields in wlan account profile (client/private_key related fields) */
#define SRV_DTCNT_WLAN_PROF_FIELD_USER_CERT_SETTINGS    (0x00002000)
/* Set passphrase info fields in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PASSPHRASE            (0x00004000)
/* Set PrivateKeyPass info fields in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PRIVKEY_PASS          (0x00008000)
/* Set psk info fields in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PSK                   (0x00010000)
/* Set wep key info fields in wlan account profile (wep_key/wep_key_index/wep_key_len/wep_key_format fields) */
#define SRV_DTCNT_WLAN_PROF_FIELD_WEP_KEY_SETTINGS      (0x00020000)
/* Set eap auth.info fields in wlan account profile (eap_auth/eap_peap/eap_ttls/peap_version fields) */
#define SRV_DTCNT_WLAN_PROF_FIELD_EAP_AUTH_SETTINGS     (0x00040000)
/* Set auth.user field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_USER                  (0x00080000) 
/* Set auth.password field in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PW                    (0x00100000) 
/* Set all wapi specific fields in wlan account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_WAPI_SETTINGS         (0x00200000)
/* Set Homepage field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_HOME                  (0x00400000)
/* Set Proxy addr field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PX_ADDR               (0x00800000)
/* Set Proxy port field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PX_PORT               (0x01000000)
/* Set Proxy field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PROXY          (SRV_DTCNT_WLAN_PROF_FIELD_PX_ADDR | SRV_DTCNT_WLAN_PROF_FIELD_PX_PORT)
/* Set Proxy auth.user field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_ID            (0x02000000)
/* Set Proxy auth.pass field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_PW            (0x04000000)
/* Set Proxy auth.pass field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_USE_PX                (0x08000000)
/* Set Proxy auth info field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH               (SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_ID | SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_PW)
/* Set access point type field in WLAN account profile */
#define SRV_DTCNT_WLAN_PROF_FIELD_AP_TYPE               (0x10000000)
/* Set All fields */
#define SRV_DTCNT_WLAN_PROF_FIELD_ALL                   (0xFFFFFFFF)

/* WLAN authentication enable status */

#define WLAN_EAP_TLS_SUPPORT					/* Enable EAP TLS authentication support */
#define WLAN_EAP_MD5_SUPPORT					/* Enable EAP MD5 authentication support */
#define WLAN_EAP_PEAP_SUPPORT					/* Enable EAP PEAP authentication support */
#define SRV_DTCNT_WLAN_EAP_TYPES_TOTAL        (6)//shall less or equal than (sizeof(g_srv_dtcnt_wlan_eap_types) - 1)
#define SRV_DTCNT_WLAN_EAP_PEAP_TYPES_TOTAL   (4)//shall less or equal than(sizeof(g_srv_dtcnt_wlan_eap_peap_types) - 1)
#define WLAN_EAP_TTLS_SUPPORT					/* Enable EAP TTLS authentication support */
#define SRV_DTCNT_WLAN_EAP_TTLS_TYPES_TOTAL   (10)//shall less or equal than(sizeof(g_srv_dtcnt_wlan_eap_ttls_types) - 1)
// #ifndef __MMI_DUAL_SIM__
#define WLAN_EAP_SIM_SUPPORT					/* Enable EAP SIM authentication support */
// #endif
// #define WLAN_EAP_FAST_SUPPORT
#define WLAN_EAP_AKA_SUPPORT

#define WLAN_EAP_MSCHAP2_SUPPORT			/* Enable EAP MSCHAP2 authentication support */
#define WLAN_EAP_GTC_SUPPORT					/* Enable EAP GTC authentication support */
#define WLAN_PAP_SUPPORT							/* Enable EAP PAP authentication support */
#define WLAN_CHAP_SUPPORT							/* Enable EAP CHAP authentication support */
#define WLAN_MSCHAP_SUPPORT						/* Enable EAP MSCHAP authentication support */
#define WLAN_MSCHAP2_SUPPORT					/* Enable EAP MSCHAP2 authentication support */

/* DOM-NOT_FOR_SDK-BEGIN */
#define SRV_DTCNT_WLAN_AUTH_TYPE_END  (0xFF)
/* DOM-NOT_FOR_SDK-END */

/* WPA key management */

#define SRV_DTCNT_BIT(n)                ((kal_uint32) 1 << (n))
#define WPA_KEY_MGMT_IEEE8021X          SRV_DTCNT_BIT(0)		/* WPA Key management IEEE8021x bit mask */
#define WPA_KEY_MGMT_PSK                SRV_DTCNT_BIT(1)		/* WPA Key management PSK bit mask */
#define WPA_KEY_MGMT_NONE               SRV_DTCNT_BIT(2)		/* WPA Key management NONE bit mask */
#define WPA_KEY_MGMT_IEEE8021X_NO_WPA   SRV_DTCNT_BIT(3)		/* WPA Key management IEEE8021x_NO_WPA bit mask */
#define WPA_KEY_MGMT_WPA_NONE           SRV_DTCNT_BIT(4)		/* WPA Key management WPA_NONE bit mask */
#define WAPI_KEY_MGMT_PSK               SRV_DTCNT_BIT(5)		/* WPA Key management PSK bit mask */
#define WAPI_KEY_MGMT_WAI               SRV_DTCNT_BIT(6)		/* WPA Key management WAI bit mask */

#define SRV_DTCNT_STORE_IDS_QRY_MAX_SIZE    (64)		/* maximum size of ids query id buffer */

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#define DTCNT_STRING_SIM (L"SIM")				/* data account mms sim profile predefined SIM name string */
#ifdef __TCPIP_OVER_CSD__
#define DTCNT_STRING_CSD (L"GSM data")	/* data account mms sim profile predefined csd account name string */
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
#define DTCNT_STRING_GPRS (L"GPRS")			/* data account mms sim profile predefined gprs account name string */
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

/****************************************************************************/
/* Enums                                                                    */
/****************************************************************************/

/* Data Account store query type enum */
typedef enum
{
    SRV_DTCNT_STORE_QRY_TYPE_SIM            = 0x01, /* sim info */
    SRV_DTCNT_STORE_QRY_TYPE_APP_TYPE       = 0x02, /* app type info */
    SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE    = 0x04, /* bearer type info */
    SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE       = 0x08, /* user defined/factory/OTA profiles */
    SRV_DTCNT_STORE_QRY_TYPE_TOTAL          = 0x10
}srv_dtcnt_store_qry_type_enum;

/* Data Account GRPS profile authentication type enum */
typedef enum
{
    SRV_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,       /* auth. type : normal */
    SRV_DTCNT_PROF_GPRS_AUTH_TYPE_SECURE,       /* auth. type : secure */
    SRV_DTCNT_PROF_GPRS_AUTH_TYPE_TOTAL    
} srv_dtcnt_prof_gprs_auth_type_enum;

/* Data Account profile type enum */
typedef enum
{
    SRV_DTCNT_PROF_TYPE_USER_CONF = 0,  /* user configured account */
    SRV_DTCNT_PROF_TYPE_OTA_CONF,       /* OTA configured account */
    SRV_DTCNT_PROF_TYPE_FACTORY_CONF,   /* Factory default */
    SRV_DTCNT_PROF_TYPE_SIM_PROF,       /* SIM provisioning account */
    SRV_DTCNT_PROF_TYPE_DM_CONF,        /* DM configured account */
    SRV_DTCNT_PROF_TYPE_TOTAL
} srv_dtcnt_prof_acc_type_enum;

/* Data Account CSD profile dial type enum */
typedef enum
{
    SRV_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,       /* dial type : analogue */
    SRV_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,           /* dial type : ISDN */
    SRV_DTCNT_PROF_CSD_DIAL_TYPE_TOTAL    
} srv_dtcnt_prof_csd_dial_type_enum;

/* Data Account CSD profile data rate enum */
typedef enum
{
    SRV_DTCNT_PROF_CSD_RATE_TWO_FOUR,       /* csd data rate : 2400 */
    SRV_DTCNT_PROF_CSD_RATE_FOUR_EIGHT,     /* csd data rate : 4800 */
    SRV_DTCNT_PROF_CSD_RATE_NINE_SIX,       /* csd data rate : 9600 */
    SRV_DTCNT_PROF_CSD_RATE_FOURTEEN_FOUR,  /* csd data rate : 14400 */
    SRV_DTCNT_PROF_CSD_RATE_AUTO,           /* csd data rate : auto */
    SRV_DTCNT_PROF_CSD_RATE_TOTAL
} srv_dtcnt_prof_csd_rate_enum;

/* Data Account wlan network type enum */
typedef enum
{
    SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA,  /* infrasturcture mode */
    SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC,  /* ad-hoc mode */
    SRV_DTCNT_WLAN_NETWORK_TYPE_TOTAL
} srv_dtcnt_wlan_network_type_enum;

/* Data Account provisioning profile type enum */
typedef enum
{
    SRV_DTCNT_PROV_TYPE_UPDATE = 0, /* update csd/gprs provisioning profiles */ 
    SRV_DTCNT_PROV_TYPE_ADD,        /* add a new profile */
    SRV_DTCNT_PROV_TYPE_REPLACE,    /* profiles full, select one to replace */
    SRV_DTCNT_PROV_TYPE_TOTAL
} srv_dtcnt_prov_type_enum;

/* Data Account provisioning indication type enum */
typedef enum
{
    SRV_DTCNT_PROV_IND_CSD = 0,     /* csd profile provisioning */
    SRV_DTCNT_PROV_IND_GPRS,        /* gprs profile provisioning */
    SRV_DTCNT_PROV_IND_WLAN,        /* wlan profile provisioning */
    SRV_DTCNT_PROV_IND_TOTAL
} srv_dtcnt_prov_ind_enum;

/* Data Account provisioning confirm type enum */
typedef enum
{
    SRV_DTCNT_PROV_CNF_INSTALL = 0, /* install current provisioning profile */
    SRV_DTCNT_PROV_CNF_REPLACE,     /* replace a specified profile or account */
    SRV_DTCNT_PROV_CNF_SKIP,        /* ignore current provisioning profile */
    SRV_DTCNT_PROV_CNF_ABORT,       /* abort provisioning operation */
    SRV_DTCNT_PROV_CNF_TOTAL
} srv_dtcnt_prov_cnf_enum;

/* Data Account profile connection type enum */
typedef enum
{
    SRV_DTCNT_CONN_TYPE_WAP,    /* WAP */
    SRV_DTCNT_CONN_TYPE_HTTP,   /* HTTP */
    SRV_DTCNT_CONN_TYPE_TOTAL
}srv_dtcnt_connection_type_enum;

/* Data Account wlan auth.mode enum */
typedef enum
{
    SRV_DTCNT_WLAN_AUTH_MODE_OPEN,                     /* Open Network */
    SRV_DTCNT_WLAN_AUTH_MODE_WEP,                      /* WEP */
    SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X,                /* IEEE802.1x */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY,                 /* WPA Enterprise */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK,             /* WPA Only PSK */
    SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT,                 /* WAPICERT */
    SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK,                  /* WAPIPSK */
    
    SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY,                /* WPA2 Enterprise */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX,             /* WPA WPA2 Mix Enterprise */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK,           /* WPA2 Only PSK */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK,         /* WPA WPA2 Mix PSK */
    SRV_DTCNT_WLAN_AUTH_MODE_TOTAL
} srv_dtcnt_wlan_auth_mode_enum;


/* Data Account wlan encrypt mode */
typedef enum
{
    SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE,   /* unencrypt mode */
    SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP,    /* WEP mode */
    SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP,   /* TKIP mode */
    SRV_DTCNT_WLAN_ENCRYPT_MODE_AES,    /* AES mode */
    SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI,    /* WPI mode */
    SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP_AES, /*TKIP_CCMP */
    SRV_DTCNT_WLAN_ENCRYPT_MODE_TOTAL
} srv_dtcnt_wlan_encrypt_mode_enum;

/* Data Account wlan wep key encrypt mode */
typedef enum
{
    SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64,  /* 64 */
    SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128, /* 128 */
    SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_TOTAL
} srv_dtcnt_wlan_wep_key_encrypt_enum;

/* Data Account wlan wep key format */
typedef enum
{
    SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX,  /* HEX encoded */
    SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII,/* ASCII encoded */
    SRV_DTCNT_WLAN_WEP_KEY_FORMAT_TOTAL
} srv_dtcnt_wlan_wep_key_format_enum;

typedef enum
{
    SRV_DTCNT_WLAN_AP_USER_DEFINE,
    SRV_DTCNT_WLAN_AP_DEFAULT,
    SRV_DTCNT_WLAN_AP_UNKNOW,
    SRV_DTCNT_WLAN_AP_BLACK_LIST,
    SRV_DTCNT_WLAN_AP_END
}srv_dtcnt_wlan_ap_type_enum;

/* Data Account wlan authentication support type enum */
typedef enum
{
#ifdef WLAN_EAP_TLS_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_TLS,   /* EAP_TLS */
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_MD5,   /* EAP_MD5 */
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_PEAP,  /* EAP_PEAP */
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_TTLS,  /* EAP_TTLS */
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_SIM,   /* EAP_SIM */
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_FAST,  /* EAP_FAST */
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_MSCHAP2,/* EAP_MSCHAP2 */
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_GTC,   /* EAP_GTC */
#endif 
#ifdef WLAN_PAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_PAP,       /* EAP_PAP */
#endif 
#ifdef WLAN_CHAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_CHAP,      /* EAP_CHAP */
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_MSCHAP,    /* EAP_MSCHAP */
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_MSCHAP2,   /* EAP_MSCHAP2 */
#endif 
#ifdef WLAN_EAP_AKA_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_AKA,
#endif
    SRV_DTCNT_WLAN_AUTH_TYPE_TOTAL
} srv_dtcnt_wlan_auth_type_enum;

/* Data Account wlan power saving mode */
typedef enum
{
    SRV_DTCNT_WLAN_WLAN_POWER_MODE_CAM,     /* WNDRV_POWER_MODE_CAM */
    SRV_DTCNT_WLAN_WLAN_POWER_MODE_FAST_PS, /* WNDRV_POWER_MODE_FAST_PS */
    SRV_DTCNT_WLAN_WLAN_POWER_MODE_MAX_PS,  /* WNDRV_POWER_MODE_MAX_PS */
    SRV_DTCNT_WLAN_WLAN_POWER_MODE_CTIA,    /* WNDRV_POWER_MODE_CTIA */
    SRV_DTCNT_WLAN_WLAN_POWER_MODE_TOTAL
} srv_dtcnt_wlan_power_mode_enum;

/* Data account WLAN search AP list opening response */
typedef enum
{
    SRV_DTCNT_WLAN_SEARCH_AP_OPEN_CONNECT,      /* User select one of AP to connect */
    SRV_DTCNT_WLAN_SEARCH_AP_OPEN_CANCEL,       /* User cancel while searching or press end key to exit AP list */
    SRV_DTCNT_WLAN_SEARCH_AP_OPEN_CLOSE_IND,    /* Close AP list since application doesn't need WLAN connection */
    SRV_DTCNT_WLAN_SEARCH_AP_OPEN_TOTAL
} srv_dtcnt_wlan_search_ap_open_rsp_enum;

/* Data account CMCC WLAN logout response*/
typedef enum
{
    SRV_DTCNT_WLAN_LOGOUT_SUCC,
    SRV_DTCNT_WLAN_LOGOUT_FAIL,
    SRV_DTCNT_WLAN_LOGOUT_TOTAL
}srv_dtcnt_wlan_logout_rsp_enum;

typedef enum
{
    SRV_DTCNT_WLAN_STATE_NULL = 0,
    SRV_DTCNT_WLAN_STATE_DEINIT_WAIT,
    SRV_DTCNT_WLAN_STATE_INIT_WAIT,
    SRV_DTCNT_WLAN_STATE_INIT,
    SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT,
    SRV_DTCNT_WLAN_STATE_CONNECT_WAIT,
    SRV_DTCNT_WLAN_STATE_CONNECTED,
    SRV_DTCNT_WLAN_STATE_TOTAL
} srv_dtcnt_wlan_state_enum;

typedef enum
{
    SRV_DTCNT_WLAN_SWITCH_STATE_OPEN,
    SRV_DTCNT_WLAN_SWITCH_STATE_OPENING,
    SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE,
    SRV_DTCNT_WLAN_SWITCH_STATE_CLOSING,
    SRV_DTCNT_WLAN_SWITCH_STATE_TOTAL
} srv_dtcnt_wlan_switch_state_enum;


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_wlan_scan_res_cb_func_ptr
 * DESCRIPTION
 *  WLAN scan result callback function
 *  APPs need to copy the bss info byself.
 * PARAMETERS
 *  job_id      :   [IN]    APP's job ID from return value by calling WLAN scan operation
 *  user_data   :   [IN]    APP's piggyback user_data
 *  scan_res    :   [IN]    Scan results from DA SRV
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_wlan_scan_res_cb_func_ptr) (
            U32 job_id,
            void *user_data,
            srv_dtcnt_wlan_scan_result_struct *scan_res);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_wlan_conn_res_cb_func_ptr
 * DESCRIPTION
 *  WLAN connect result callback function
 * PARAMETERS
 *  user_data   :   [IN]    APP's piggyback user_data
 *  conn_res    :   [IN]    connect results from DA SRV
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_wlan_conn_res_cb_func_ptr) (
            void *user_data,
            srv_dtcnt_wlan_conn_res_struct *conn_res);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_prov_ind_cb_func_ptr
 * DESCRIPTION
 *  Data account provisioning profile installation indication callback for UI confirmation.
 * PARAMETERS
 *  cnf         :   [IN]    confirmation from APP
 *  replace_idx :   [IN]    profile/account idx of indication prof_name_list to be replaced (WLAN)
 *                          account id to be replaced (csd/gprs)
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_prov_ind_cb_func_ptr) (srv_dtcnt_prov_cnf_enum cnf, U8 replace_idx);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_ipaddr_change_qry_cb_func_ptr
 * DESCRIPTION
 *  Data account WLAN not-saved connected AP IP setting info query.
 * PARAMETERS
 *  use_dhcp    :   [IN]    identify the use dhcp flag, if TRUE, the ipaddr_info will be ignored
 *  ipaddr_info :   [IN]    IP address settings of active AP, MUST exist if use_dhcp = FALSE
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_ipaddr_change_qry_cb_func_ptr) (MMI_BOOL use_dhcp, srv_dtcnt_wlan_ipaddr_update_struct *ipaddr_info);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Used for CMCC TD WLAN spec. */
/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_wlan_search_ap_open_ind_cb_func_ptr
 * DESCRIPTION
 *  Data account WLAN search AP list opening indication callback for UI selection.
 * PARAMETERS
 *  rsp     :   [IN]    Selection response from DA APP
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_wlan_search_ap_open_ind_cb_func_ptr) (srv_dtcnt_wlan_search_ap_open_rsp_enum rsp);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_wlan_logout_cb_func_ptr
 * DESCRIPTION
 *  Data account WLAN logout indication callback for WLAN APP selection.
 * PARAMETERS
 *  rsp     :   [IN]    Selection response from WLAN APP
 * RETURNS
 *  void
 *****************************************************************************/

typedef void (*srv_dtcnt_wlan_logout_cb_func_ptr)(srv_dtcnt_wlan_logout_rsp_enum rsp);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_bearer_init_wlan_ap_query_ind_cb_func_ptr
 * DESCRIPTION
 *  Data account bearer initial WLAN AP query.
 * PARAMETERS
 *  bearer_type :   [IN]    Bearer initial type
 *  acct_id: [IN]  account id
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_bearer_init_wlan_ap_query_ind_cb_func_ptr) (U32 bearer_type, U32 acct_id);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_wlan_ap_list_query_ind_cb_func_ptr
 * DESCRIPTION
 *  Data account WLAN AP list query.
 * PARAMETERS
 *  ap_num :   [IN]    AP list number
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_wlan_ap_list_query_ind_cb_func_ptr) (U32 ap_num);
/* DOM-NOT_FOR_SDK-END */

/**********************************************************************************************/
/*  SRV Indication Events                                                                     */
/**********************************************************************************************/

/* event structure for EVT_ID_SRV_DTCNT_PROV_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_prov_ind_enum  prov_ind;  /* CSD/GPRS/WLAN profiles */
    srv_dtcnt_prov_type_enum prov_type; /* operation type expected for APP */
    U8 num_profs;                       /* number of provisioning profiles */
    U8 cur_prof_idx;                    /* profile index in this provisioning documents, from 1 to num_profs */
    void *prof_data;                    /* profile information for UI display, typecasting by prov_ind info
                                           csd/gprs : srv_dtcnt_prov_csd_gprs_ind_struct, wlan : srv_dtcnt_prov_wlan_ind_struct */
    U8 *prof_name_list[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM]; /* provide profile names buffer pointer array (UCS2 encoding) for replacement (WLAN) */
    srv_dtcnt_prov_ind_cb_func_ptr cnf_callback;   /* after getting user confirmation, APP need to call this cb to notify SRV. */
    srv_dtcnt_sim_type_enum sim_info;
} srv_dtcnt_prov_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_prof_acc_type_enum prof_type; /* prof_type : SRV_DTCNT_PROF_TYPE_OTA_CONF or SRV_DTCNT_PROF_TYPE_SIM_CONF */
    srv_dtcnt_prov_ind_enum  prov_ind;  /* CSD/GPRS profiles */
    U8 name[(SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN + 1) * ENCODING_LENGTH]; /* install profile name */
    U8 install_result;                  /* 1 : success, 0 : failed */
    U8 num_profs;                       /* number of provisioning profiles */
    U8 prof_idx;                        /* profile index in this provisioning documents, from 1 to num_profs */
    U8 acct_id;                         /* installed account id */
    srv_dtcnt_sim_type_enum sim_info;
} srv_dtcnt_prov_install_res_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_PROV_DONE_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_prov_ind_enum  prov_ind;  /* CSD/GPRS/WLAN profiles */
    void *prof_data;                    /* profile information for UI display, typecasting by prov_ind info
                                           csd/gprs : srv_dtcnt_prov_csd_gprs_ind_struct, wlan : srv_dtcnt_prov_wlan_done_ind_struct */
} srv_dtcnt_prov_done_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_DISC_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_disc_ind_evt_struct;

/**********************************************************************************************/
/*  APP Request Response Indication Events                                                    */
/**********************************************************************************************/

/* event structure for EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_req_res_enum  res;   /* request result */
    U8 mac_addr[WNDRV_MAC_ADDRESS_LEN]; /* mac address from wifi chip */
} srv_dtcnt_wlan_init_res_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_req_res_enum  res;   /* request result */
} srv_dtcnt_wlan_deinit_res_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_conn_res_struct conn_result; /* connect result for data account APP */
} srv_dtcnt_wlan_conn_res_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_req_res_enum  res;   /* request result */
} srv_dtcnt_wlan_disc_res_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_scan_result_struct scan_res;    /* scan result for APP */
} srv_dtcnt_wlan_scan_res_ind_evt_struct;

/**********************************************************************************************/
/*  App/Srv Interaction Events                                                                */
/**********************************************************************************************/

/* event structure for EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_QRY */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_ipaddr_change_qry_cb_func_ptr  ipaddr_change_cb;   /* APP need to call this cb to notify SRV the IPaddr to send to ABM. */
} srv_dtcnt_wlan_ipaddr_change_qry_evt_struct;
    
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_ipaddr_change_cnf_evt_struct;

typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_switch_same_ssid_evt_struct;

    
/* event structure for EVT_ID_SRV_DTCNT_WIFI_CHIP_INVALID */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wifi_chip_invalid_evt_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
/* Used for CMCC TD WLAN spec. */
/* event structure for EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_OPEN_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_search_ap_open_ind_cb_func_ptr rsp_callback;   /* After getting user selection, APP need to call this cb to notify SRV. */
} srv_dtcnt_wlan_search_ap_open_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_CLOSE_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_search_ap_close_ind_evt_struct;

typedef struct
{
#ifdef __BUILD_DOM__
        U16 evt_id;             /* MMI_EVENT_ID */
        U16 size;               /* EVENT SIZE */
        void *user_data;        /* Piggyback user data */
#endif
        /* DOM-NOT_FOR_SDK-BEGIN */
        MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
        /* DOM-NOT_FOR_SDK-END */
        srv_dtcnt_wlan_logout_cb_func_ptr rsp_callback; 

}srv_dtcnt_wlan_logout_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_BEARER_INIT_WLAN_AP_QUERY_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_bearer_init_wlan_ap_query_ind_cb_func_ptr rsp_callback;   /* After getting AP list, APP need to call this cb to notify SRV. */
} srv_dtcnt_bearer_init_wlan_ap_query_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_BEARER_DEINIT_WLAN_AP_QUERY_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_bearer_deinit_wlan_ap_query_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_AP_LIST_QUERY_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_ap_list_query_ind_cb_func_ptr rsp_callback;   /* After getting AP list, APP need to call this cb to notify SRV. */
} srv_dtcnt_wlan_ap_list_query_ind_evt_struct;


typedef struct
{
    U32 prof_id[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
    U8  prof_num;
    U8  conn_type; 
}srv_dtcnt_wlan_conn_prof_ind_struct;
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;             /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;        /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_conn_prof_ind_struct res;
}srv_dtcnt_wlan_conn_prof_evt_struct;
/* DOM-NOT_FOR_SDK-END */

/****************************************************************************/
/* Structs                                                                  */
/****************************************************************************/

/* this struct is designed for Data account store query operation */
typedef struct
{
    srv_dtcnt_sim_type_enum         sim_qry_info;       /* sim query data for filter settings (used if OR'd set in filters) */
    srv_dtcnt_bearer_enum           bearer_qry_info;    /* bearer query data for filter settings (used if OR'd set in filters) */
    srv_dtcnt_prof_acc_type_enum    acc_type_info;      /* account type query data for filter settings (used if OR'd set in filters) */
    U16 filters;        /* query settings (OR'd operation by srv_dtcnt_store_qry_type_enum) */
    U64                             app_type;           /* app_type query data for filter settings (used if OR'd set in filters) */
} srv_dtcnt_store_prof_qry_filter_struct;

/* this struct is designed for Data account store query operation */
typedef struct
{
    srv_dtcnt_store_prof_qry_filter_struct  qry_info;   /* query information from DA APP */
    U32 ids[SRV_DTCNT_STORE_IDS_QRY_MAX_SIZE];    /* account id list query result */
    U8  num_ids;                                /* the number of queried id list */
} srv_dtcnt_store_prof_qry_struct;

/* this struct is designed for Data account store profile content operations */
typedef struct
{
    void *prof_data;                    /* profile data pointer */
    U32 prof_fields;                    /* profile enabled attributes */
    srv_dtcnt_bearer_enum prof_type;    /* profile bearer type */
} srv_dtcnt_store_prof_data_struct;

/* this struct is designed for profile authentication info struct settings for GSM/GPRS profiles */
typedef struct
{    
    srv_dtcnt_prof_gprs_auth_type_enum  AuthType;   /* GPRS Authentication Type */
    U8 UserName[SRV_DTCNT_PROF_MAX_USER_LEN+1];     /* User string of a Data Account (ASCII) (MAX: SRV_DTCNT_PROF_MAX_USER_LEN) */
    U8 Passwd[SRV_DTCNT_PROF_MAX_PW_LEN+1];         /* Password for a Data Account (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */
}srv_dtcnt_prof_auth_struct;

/* this struct is designed for common profile struct settings for GSM/GPRS profiles */
typedef struct
{
    U8 acc_id;              /* The account ID */                                           
    U8 read_only;           /* read only property */
    srv_dtcnt_prof_acc_type_enum acct_type;                /* Account type */
    srv_dtcnt_sim_type_enum sim_info;                      /* SIM info */

    const U8 *AccountName;    /* UCS2 Name of a Data Account (MAX string length = SRV_DTCNT_PROF_MAX_ACC_NAME_LEN * ENCODING_LENGTH) */
    U8 HomePage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];       /* Homepage string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN) */
    srv_dtcnt_prof_auth_struct Auth_info;       /* authentication info */

    U8 use_proxy;   /* use proxy flag */
    srv_dtcnt_prof_px_srv_enum  px_service;         /* proxy service type */
    U16 px_port;        /* proxy port */
    U8 px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];       /* proxy addr string IP format */
    U8 px_authid[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1];  /* proxy auth. ID string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN) */
    U8 px_authpw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1];  /* proxy auth. PW (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN) */

    U8 StaicIPAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];     /* Static IP Address (MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 NetMask[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];         /* Subnet Mask (MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 PrimaryAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];     /* Primary DNS IP Address (MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 SecondaryAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];   /* Secondary DNS IP Address (MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */

    U8 napid_hash_val[SRV_DTCNT_NAPID_HASH_LEN];        /* hash value of napid */
    U8 provurl_hash_val[SRV_DTCNT_PROVURL_HASH_LEN];    /* hash value of PROVURL */
    
    U64  AppType;           /* Application Type bit mask */
    const void *user_data;        /* assoicated user_data */
}srv_dtcnt_prof_common_header_struct;

/* this struct is designed for Data accont CSD profile settings for DA APP */
typedef struct
{
    srv_dtcnt_prof_common_header_struct prof_common_header;/* common profile attributes struct */    
    const U8 *DialNumber;   /* CSD profile dial number(ASCII) (MAX: SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN) */
    srv_dtcnt_prof_csd_dial_type_enum   DialType;   /* CSD dial type */
    srv_dtcnt_prof_csd_rate_enum        DataRate;   /* CSD data rate */
}srv_dtcnt_prof_csd_struct;

/* this struct is designed for Data accont CSD profile settings for DA APP */
typedef struct
{
    srv_dtcnt_prof_common_header_struct prof_common_header;/* common profile attributes struct */    
    const U8 *APN;               /* GPRS APN string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_APN_LEN) */
} srv_dtcnt_prof_gprs_struct;

/* this struct is designed for Data accont WLAN profile settings for DA APP */
typedef struct
{
    U8 ssid[SRV_DTCNT_PROF_MAX_SSID_LEN+1];       /* SSID ASCII string (MAX: SRV_DTCNT_PROF_MAX_SSID_LEN) */
    U8 ip_addr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* IP address (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 netmask[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* Netmask (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 gateway[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* Gateway (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 dns1[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];       /* Primary DNS (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 dns2[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];       /* Secondary DNS (ASCII, MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8 px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];       /* proxy addr string IP format */
    U8 px_authid[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1];  /* proxy auth. ID string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN) */
    U8 px_authpw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1];  /* proxy auth. PW (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN) */
    U8 HomePage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];       /* Homepage string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN) */   
    U8 priority;    /* profile priority */
    U8 ssid_len;    /* SSID string length */
    MMI_BOOL use_dhcp;  /* enable/disable DHCP */
    MMI_BOOL always_ask_connect_flag;           /* always ask trigger wlan activation (DA APP should set this attribute in Always Ask connect case) */
    MMI_BOOL always_ask_before_connect_flag;    /* always ask triggered after a DA triggered wlan connection established (DA SRV will help to set this field) */
    srv_dtcnt_wlan_network_type_enum network_type;  /* profile network type */
    srv_dtcnt_wlan_auth_mode_enum auth_mode;        /* profile auth.mode */    
    srv_dtcnt_wlan_encrypt_mode_enum encrypt_mode;  /* profile encrypt mode */
    U16 px_port;        /* proxy port */
    U8 ProfName[(SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1) * ENCODING_LENGTH];   /* wlan profile name UCS2 string (MAX: SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN) */
    U8 use_proxy;
    U32 profile_id; /* associated profile ID */
    U32 channel;    /* channel info */
    U32 root_ca_id;     /* root ca id */
    U32 client_ca_id;   /* user cert id */

#ifdef __WAPI_SUPPORT__
    U8 wapi_psk_str[SRV_DTCNT_WAPI_PSK_STR_LEN];       /* wapi pre-shared key string */
    U8 wapi_private_key_passwd_str[SRV_DTCNT_PROF_MAX_PW_LEN+2]; /* wapi private key passwd string (ASCII, MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */
    U32 wapi_ase_id;        /* wapi ase ca id */
    U32 wapi_client_id;     /* wapi client cert id */
    S32 wapi_psk_format;    /* wapi pre-shared key format */   
#endif
    srv_dtcnt_wlan_ap_type_enum   ap_type;
    U8 peap_version;        /* peap version */
    U8 wep_key_index;       /* wep key index info */
    U8 wep_key_len;         /* wep key length (srv_dtcnt_wlan_wep_key_encrypt_enum) */
    U8 username[SRV_DTCNT_PROF_MAX_USER_LEN+1];   /* user name string (ASCII, MAX: SRV_DTCNT_PROF_MAX_USER_LEN) */
    U8 passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN+1]; /* passphrase string (MAX: SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN) */
    U8 psk[SRV_DTCNT_PROF_MAX_PSK_LEN];        /* pre-shared key for passphrase (MAX: SRV_DTCNT_PROF_MAX_PSK_LEN) */
    U8 wep_key[SRV_DTCNT_PROF_MAX_WEP_KEY_LEN+1];    /* wep key string (MAX: SRV_DTCNT_PROF_MAX_WEP_KEY_LEN) */
    U8 password[SRV_DTCNT_PROF_MAX_PW_LEN+1];   /* password string (ASCII, MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */
    U8 private_key_passwd[SRV_DTCNT_PROF_MAX_PW_LEN+1]; /* private key passwd string (ASCII, MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */      
    srv_dtcnt_wlan_wep_key_format_enum wep_key_format;  /* wep key format */    
    U32 eap_auth_type;      /* eap firt level auth.type */
    U32 eap_peap_auth_type; /* peap auth.type */
    U32 eap_ttls_auth_type; /* ttls auth.type */
} srv_dtcnt_prof_wlan_struct;

/* this struct is designed for DA APP to caculate the required data buffer 
   in preparing prof_data in srv_dtcnt_store_prof_data_struct.
   APP may use sizeof(srv_dtcnt_store_prof_union) to get the buffer size */
typedef union
{
    srv_dtcnt_prof_csd_struct   csd_prof;
    srv_dtcnt_prof_gprs_struct  gprs_prof;
    srv_dtcnt_prof_wlan_struct  wlan_prof;
} srv_dtcnt_store_prof_union;

/* this struct is designed for Data account APP to carry the AP profiles to SRV for connecting */
typedef struct
{
    U8 num_prof;    /* the number of profiles in prof_data pointer list */
    U8 connect_type;	/* connection type, should be one of ONE_PROFILE_SELECT/START_WPS_PIN/START_WPS_PBC */
    srv_dtcnt_prof_wlan_struct    **prof_data;  /* profile list array */
} srv_dtcnt_wlan_conn_prof_struct;

/* this struct is designed for Data accont provisioning WLAN profile information for DA APP */
typedef struct
{
    srv_dtcnt_wlan_network_type_enum network_type;  /* network type */
    srv_dtcnt_wlan_auth_mode_enum    auth_mode;     /* authentication mode */
    srv_dtcnt_wlan_encrypt_mode_enum encrypt_mode;  /* encryption mode */
    const U8 *AccountName;                          /* account name string (UCS2) */
    const U8 *SSID;                                 /* SSID string (ASCII) */
} srv_dtcnt_prov_wlan_ind_struct;

/* this struct is designed for Data accont provisioning WLAN profile done information for DA APP */
typedef struct
{
    U8  num_infra_profs;                /* # of infra wlan profiles */
    U8  num_adhoc_profs;                /* # of adhoc wlan profiles */
    MMI_BOOL active_prof_id_valid;      /* active profile id existence flag */
    U32 active_prof_id;                 /* active profile id */
} srv_dtcnt_prov_wlan_done_ind_struct;

/* this struct is designed for Data accont provisioning CSD/GPRS profile information for DA APP */
typedef struct
{
    const U8 *AccountName;  /* account name string (UCS2) */
    const U8 *Address;      /* GPRS: APN string (ASCII), CSD: DialNumber string (ASCII) */
} srv_dtcnt_prov_csd_gprs_ind_struct;

/* this struct is designed for application information sync to ABM for account validation check */
typedef struct{
    U8  acct_1;  /* invalid account 1, if use CBM_INVALID_NWK_ACCT_ID this information will be ignored */
    U8  acct_2;  /* invalid account 2, if use CBM_INVALID_NWK_ACCT_ID this information will be ignored */
    U16 str_id; /* application registered string id */
    U16 icon_id;/* application registered icon id */              
} srv_dtcnt_app_info_struct;

/* this struct is designed for Data accont app to sync application account invalid table */
typedef struct
{
    srv_dtcnt_app_info_struct app_info[ABM_MAX_APP_NUM]; /* ap info list  */
} srv_dtcnt_prof_app_info_struct;


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_store_delete_cb_func_ptr
 * DESCRIPTION
 *  store account deleting callback function
 * PARAMETERS
 *  user_data       :   [IN]    APP's piggyback user_data
 *  deleting_acc_id :   [IN]    the account id to be deleted
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_store_delete_cb_func_ptr) (U32 deleting_acc_id, void *user_data);

/****************************************************************************/
/* Internal Interfaces (User : DataAccount MMI/CUIs)                        */
/****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_connection_type
 * DESCRIPTION
 *  To get connection type information by specified account id
 * PARAMETERS
 *  acc_id      :   [IN]        specified account ID.
 *  conn_type   :   [IN/OUT]    connection type output location
 * RETURNS
 *  MMI_TRUE    :   Get connection type successfully
 *  MMI_FALSE   :   Get connection type failed
 *****************************************************************************/
MMI_BOOL srv_dtcnt_get_connection_type(U32 acc_id, srv_dtcnt_connection_type_enum *conn_type);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_sim_info
 * DESCRIPTION
 *  To get sim information by specified account id
 * PARAMETERS
 *  acc_id      :   [IN]        specified account ID.
 *  sim_info    :   [IN/OUT]    SIM info output location
 * RETURNS
 *  MMI_TRUE    :   Get SIM info successfully
 *  MMI_FALSE   :   Get SIM info failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_sim_info(U32 acc_id, srv_dtcnt_sim_type_enum *sim_info);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_acct_is_read_only
 * DESCRIPTION
 *  To check the specified account is read only or not.
 * PARAMETERS
 *  acc_id      :   [IN]        specified account ID (no SIM id encoded).
 * RETURNS
 *  MMI_TRUE    :   the specified account is read only account
 *  MMI_FALSE   :   acc_id not found or account isn't read only
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_acct_is_read_only(U32 acc_id);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_set_sim_preference
 * DESCRIPTION
 *  To set the SIM preference
 *  Note: DA APP should set correct SIM when SIM card plug in/out. If there is not any
 *  SIM plug in, set SRV_DTCNT_SIM_TYPE_NONE.
 * PARAMETERS
 *  sim_type    :   [IN]        SIM preference type
 * RETURN VALUES
 *  MMI_TRUE    :   Set SIM preference successfully
 *  MMI_FALSE   :   Set SIM preference failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_set_sim_preference(srv_dtcnt_sim_type_enum sim_type);
/* DOM-NOT_FOR_SDK-END */

#define SRV_DTCNT_STORE_INTERNAL

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_create
 * DESCRIPTION
 *  The function is used to create a data account store.
 *  Currently we only support one store(database) which implies only DA APP can create.
 *  1. Once the store is created, the store handle should be kept by APP even the mobile is turn off.
 *  2. DA APP can use srv_dtcnt_store_open to start to use the database services as long as APP called srv_dtcnt_store_commit.
 *  3. When DA APP want to stop using the store, APP could use srv_dtcnt_store_close.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : create a new store successfully.
 *  SRV_DTCNT_RESULT_FS_ERROR           : FS error.
 *  SRV_DTCNT_RESULT_ONE_STORE_EXISTS   : store had been created already.
 * SEE ALSO
 *  srv_dtcnt_store_config, srv_dtcnt_store_commit
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_create(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_config
 * DESCRIPTION
 *  The function is used to config the created data account store.
 *  After configuration, APP need to call srv_dtcnt_store_commit,
 *  Otherwise srv_dtcnt_store_open will return error.
 *  1. DA APP can use SRV_DTCNT_PROF_CONFIG_XXX to enable attributes for GSM/GPRS profile
 *  2. Currently prof_type = WLAN can't support config attributes, all attributes are mandatory.
 *  3. DA APP can call this API multiple times before commit for CSD/GPRS.
 * PARAMETERS
 *  prof_config :   [IN]        please refer the SRV_DTCNT_PROF_CONFIG_XXX to decide the profile scope
 *  prof_type   :   [IN]        CSD/GPRS
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : config store successfully.
 *  SRV_DTCNT_RESULT_INVALID_INPUT      : the input parameter is invalid.
 *  SRV_DTCNT_RESULT_INVALID_STORE      : didn't create a store before.
 *  SRV_DTCNT_RESULT_FAILED             : configuration failed
 * SEE ALSO
 *  srv_dtcnt_store_open, srv_dtcnt_store_commit
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_config(
                        U32 prof_config,
                        srv_dtcnt_bearer_enum prof_type);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_commit
 * DESCRIPTION
 *  The function is used to commit the configuration of a data account store.
 *  After commit, srv_dtcnt_store_config can't be called and will return SRV_DTCNT_RESULT_FAILED,
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : commit successfully.
 *  SRV_DTCNT_RESULT_INVALID_STORE      : didn't create a store before.
 *  SRV_DTCNT_RESULT_FAILED             : commit failed
 * SEE ALSO
 *  srv_dtcnt_store_open, srv_dtcnt_store_config
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_commit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_open
 * DESCRIPTION
 *  The function is used to activate store services.
 *  Every reboot, DA APP need to call this API to enable the store services.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : open store successfully.
 *  SRV_DTCNT_RESULT_FS_ERROR           : file system error
 *  SRV_DTCNT_RESULT_STORE_NOT_COMMIT   : DA App didn't commit the store configuration
 *  SRV_DTCNT_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_DTCNT_RESULT_FIRST_BOOTUP,      : first bootup 
 *  SRV_DTCNT_RESULT_RESET_FACTORY,     : the data base sim profiles folder is deleted
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_open(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_qry_ids
 * DESCRIPTION
 *  The function is to query CSD/GPRS accounts by specified qry_type.
 *  DA SRV will return the filtered IDs in ids array with number in num_ids.
 *  Currently only support query by srv_dtcnt_store_qry_type_enum.
 *  Then DA APP can use srv_dtcnt_store_qry_prof_by_id to query the profile by queried ID list.
 * PARAMETERS
 *  qry   :   [IN]        query info from application
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : query successfully.
 *  SRV_DTCNT_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_DTCNT_RESULT_INVALID_INPUT      : the input parameter is invalid.
 * SEE ALSO
 *  srv_dtcnt_store_qry_prof_by_id
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_qry_ids(srv_dtcnt_store_prof_qry_struct *qry);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_qry_prof
 * DESCRIPTION
 *  The function is to query CSD/GPRS/WLAN profile content by specified account id.
 *  For qry parameter:
 *  1. DA APP need to prepare the buffer prof_data by sizeof (srv_dtcnt_store_prof_union).
 *  2. prof_fields will be updated by SRV to notify which fields are used in this profile.
 *  3. prof_type can help APP to know how to typecasting the prof_data
 *     ex: prof_type = CSD, (srv_dtcnt_prof_csd_struct *)prof_data;, otherwise, (srv_dtcnt_prof_gprs_struct *)prof_data;
 * PARAMETERS
 *  acc_prof_id :   [IN]    query account or wlan profile id
 *  qry         :   [IN]    query info from application
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : query profile successfully.
 *  SRV_DTCNT_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_DTCNT_RESULT_INVALID_INPUT      : the input parameter is invalid.
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_qry_prof(
                        U32 acc_prof_id,
                        srv_dtcnt_store_prof_data_struct *qry);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_add_prof
 * DESCRIPTION
 *  The function is to add a new profile by specified profile data.
 *  For prof parameter:
 *  1. DA APP need to prepare the buffer prof_data depends on CSD/GPRS/WLAN profile.
 *  2. prof_fields SHOULD also be provided for SRV to know which fields are used.
 *  3. prof_type need to be set for SRV to know how to typecasting the prof_data.
 * PARAMETERS
 *  prof        :   [IN]        profile data buffer to be added
 *  acc_prof_id :   [IN\OUT]    return acc_id or prof_id for gsm_gprs or wlan profile
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS        : add profile successfully.
 *  SRV_DTCNT_RESULT_FAILED         : add profile failed.
 *  SRV_DTCNT_RESULT_INVALID_STORE  : store handle invalid.
 *  SRV_DTCNT_RESULT_INVALID_INPUT  : the input parameter is invalid.
 *  SRV_DTCNT_RESULT_STORE_FULL     : storage full
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_add_prof(
                        srv_dtcnt_store_prof_data_struct *prof,
                        U32 *acc_prof_id);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_update_prof
 * DESCRIPTION
 *  The function is to update CSD/GPRS/WLAN profile content by specified account id.
 *  For prof parameter:
 *  1. DA APP need to prepare the buffer prof_data by sizeof (srv_dtcnt_store_prof_union) 
 *     or sizeof (srv_dtcnt_prof_wlan_struct) for WLAN profiles.
 *  2. only specified prof_fields will be updated to the profile.
 *  3. prof_type need to be set by APP for SRV to know how to typecasting the prof_data
 *     ex: prof_type = CSD, (srv_dtcnt_prof_csd_struct *)prof_data;, or (srv_dtcnt_prof_gprs_struct *)prof_data;
 * PARAMETERS
 *  acc_prof_id :   [IN]    query account or wlan profile id
 *  prof        :   [IN]    profile info from application
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : update profile successfully.
 *  SRV_DTCNT_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_DTCNT_RESULT_INVALID_INPUT      : the input parameter is invalid.
 *  SRV_DTCNT_RESULT_READ_ONLY          : this profile can't be deleted or update 
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_update_prof(
                        U32 acc_prof_id, 
                        srv_dtcnt_store_prof_data_struct *prof);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_delete_prof
 * DESCRIPTION
 *  The function is to delete a CSD/GPRS/WLAN profile by specified account id.
 * PARAMETERS
 *  acc_prof_id :   [IN]    query account or wlan profile id
 *  force_exec  :   [IN]    force delete even if deleting a read only account
 *  callback    :   [IN]    callbacks while deleting for AP info check
 *  user_data   :   [IN]    specified user data will be piggybacked in callback function
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : delete profile successfully.
 *  SRV_DTCNT_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_DTCNT_RESULT_INVALID_INPUT      : the input parameter is invalid.
 *  SRV_DTCNT_RESULT_READ_ONLY          : this profile can't be deleted or update
 * SEE ALSO
 *  srv_dtcnt_store_delete_prof_by_qry
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_delete_prof(
                        U32 acc_prof_id,
                        MMI_BOOL force_exec,
                        void *user_data,
                        srv_dtcnt_store_delete_cb_func_ptr callback);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_delete_prof_by_qry
 * DESCRIPTION
 *  The function is to delete CSD/GPRS/WLAN profile by query info.
 * PARAMETERS
 *  qry         :   [IN]    query settings from applications
 *  force_exec  :   [IN]    force delete even if deleting a read only account
 *  callback    :   [IN]    callbacks while deleting for AP info check
 *  user_data   :   [IN]    specified user data will be piggybacked in callback function
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS            : delete profile successfully.
 *  SRV_DTCNT_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_DTCNT_RESULT_INVALID_INPUT      : the input parameter is invalid.
 * SEE ALSO
 *  srv_dtcnt_store_delete_prof
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_store_delete_prof_by_qry(
                        srv_dtcnt_store_prof_qry_filter_struct *qry,
                        MMI_BOOL force_exec,
                        void *user_data,
                        srv_dtcnt_store_delete_cb_func_ptr callback);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_store_update_acc_apinfo
 * DESCRIPTION
 *  The function is to update account info to ABM.
 * PARAMETERS
 *  ap_info     :   [IN]    AP info
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_dtcnt_store_update_acc_apinfo(
                            srv_dtcnt_prof_app_info_struct *ap_info);
/* DOM-NOT_FOR_SDK-END */


#define SRV_DTCNT_WLAN_INTERNAL

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_init
 * DESCRIPTION
 *  The function is used to init the WLAN services.
 *  1. If the WLAN service is ACTIVE already, return SRV_DTCNT_RESULT_SUCCESS.
 *  2. After WLAN init process is done, SRV will callback APP with user_data.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the init operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    : wlan service is active
 *  SRV_DTCNT_RESULT_PROCESSING : the wlan service is activating, wait for callback notify.
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_init(
                        srv_dtcnt_wlan_cb_func_ptr callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_deinit
 * DESCRIPTION
 *  The function is used to deinit the WLAN services.
 *  1. If the WLAN service is INACTIVE already, return SRV_DTCNT_RESULT_SUCCESS.
 *  2. After WLAN deinit process is done, SRV will callback APP with user_data.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the deinit operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    : wlan service is inactive
 *  SRV_DTCNT_RESULT_PROCESSING : the wlan service is deactivating, wait for callback notify.
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_deinit(
                        srv_dtcnt_wlan_cb_func_ptr callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_scan
 * DESCRIPTION
 *  The function is used to scan the AP list for applications.
 * PARAMETERS
 *  callback    :   [IN]    scan result callback notify function for APP
 *  user_data   :   [IN]    application piggyback data
 * RETURN VALUES
 *  Job ID > 0 : New scan job created successfully.
 *  Job ID = 0 : Can't create a new scan job.
 *****************************************************************************/
extern U32 srv_dtcnt_wlan_scan(
        srv_dtcnt_wlan_scan_res_cb_func_ptr callback,
        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_scan_abort
 * DESCRIPTION
 *  The function is used to abort the scanning AP list process for applications.
 * PARAMETERS
 *  job_id  :   [IN]    created job ID from calling srv_dtcnt_wlan_scan
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_dtcnt_wlan_scan_abort(U32 job_id);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_connect_by_db_prof
 * DESCRIPTION
 *  The function is used to connect the AP list stored in data account service database.
 *  1. DA WLAN servive can only support one connection at the same time due to chip constraint.
 *  2. If the new connect request is arrived, current connecting process will be aborted. 
 *     (notify APP by callback)
 *  3. If there is one connection already, the connection will be disconnected 
 *     then connect a new one.
 * PARAMETERS
 *  callback    :   [IN]    connect result callback notify function for APP
 *  user_data   :   [IN]    application associated piggyback data
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_STATE_ERROR    : the wlan status can't perform the connect process
 *  SRV_DTCNT_RESULT_PROCESSING     : accept the connect quest, wait for event notify.
 * SEE ALSO
 *  srv_dtcnt_wlan_connect_by_app_prof
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_connect_by_db_prof(
                        srv_dtcnt_wlan_conn_res_cb_func_ptr callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_connect_by_app_prof
 * DESCRIPTION
 *  The function is used to connect the applications specified AP List for applications.
 *  1. DA WLAN servive can only support one connection at the same time due to chip constraint.
 *  2. If the new connect request is arrived, current connecting process will be aborted.
 *  3. If there is one connection already, the connection will be disconnected 
 *     then connect a new one.
 * PARAMETERS
 *  app_profs   :   [IN]    specified AP profiles by applications
 *  callback    :   [IN]    connect result callback notify function for APP
 *  user_data   :   [IN]    application associated piggyback data
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_INVALID_INPUT  : profile_num <= 0 or profile pointer invalid
 *  SRV_DTCNT_RESULT_STATE_ERROR    : the wlan status can't perform the scan process
 *  SRV_DTCNT_RESULT_PROCESSING     : accept the connect quest, wait for event notify.
 * SEE ALSO
 *  srv_dtcnt_wlan_connect_by_db_prof
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_connect_by_app_prof(
                        srv_dtcnt_wlan_conn_prof_struct *app_profs,
                        srv_dtcnt_wlan_conn_res_cb_func_ptr callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_disconnect
 * DESCRIPTION
 *  The function is used to disconnect current WLAN connection.
 *  EVT_ID_SRV_DTCNT_WLAN_ACTIVE will be sent to applications for result.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_STATE_ERROR    :   the wlan status can't perform the disconnect process
 *  SRV_DTCNT_RESULT_SUCCESS        :   the WLAN status is active.
 *  SRV_DTCNT_RESULT_PROCESSING     :   accept the disconnect quest, wait for event notify.
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_disconnect(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_init_profile
 * DESCRIPTION
 *  The function is used to init the wlan profile structure.
 * PARAMETERS
 *  profile :   [IN]    specified profile to be set
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_dtcnt_wlan_init_profile(srv_dtcnt_prof_wlan_struct *profile);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_set_power_mode
 * DESCRIPTION
 *  The function is used to set power saving mode. DA APP should not set power mode again before
 *  last set power mode process is not finished.
 * PARAMETERS
 *  pwr_mode    :   [IN]    power saving mode you want to set
 *  callback    :   [IN]    callback function to notify applications the init operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    : Power saving mode is set
 *  SRV_DTCNT_RESULT_PROCESSING : Power saving mode setting is under processing, wait for callback notify.
 *  SRV_DTCNT_RESULT_FAILED     : Failed to set power saving mode
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_set_power_mode(
                        srv_dtcnt_wlan_power_mode_enum pwr_mode,
                        srv_dtcnt_wlan_cb_func_ptr callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_get_power_mode
 * DESCRIPTION
 *  The function is used to get power saving mode.
 * PARAMETERS
 *  out_pwr_mode    :   [OUT]    power saving mode
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    : Successful to get power saving mode
 *  SRV_DTCNT_RESULT_FAILED     : Failed to get power saving mode
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_get_power_mode(
                        srv_dtcnt_wlan_power_mode_enum *out_pwr_mode);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Used for CMCC TD WLAN spec. */
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_auth_cancel
 * DESCRIPTION
 *  The function is used to cancel cmcc auth.
 * PARAMETERS
 * RETURN VALUES
 *****************************************************************************/
extern void srv_dtcnt_wlan_auth_cancel(void);
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_add_proxy_exclusive_ip_addr
 * DESCRIPTION
 *  The function is used to add IP address in the list which indicate that application need exclude using proxy.
 * PARAMETERS
 *  exclusive_ip_addr   :   [IN]    IP address
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    :   Add successfully
 *  SRV_DTCNT_RESULT_FAILED     :   Add failed
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_add_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *exclusive_ip_addr);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_delete_proxy_exclusive_ip_addr
 * DESCRIPTION
 *  The function is used to delete IP address in the list which indicate that application need exclude using proxy.
 * PARAMETERS
 *  exclusive_ip_addr   :   [IN]    IP address
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    :   Delete successfully
 *  SRV_DTCNT_RESULT_FAILED     :   Delete failed
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_delete_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *exclusive_ip_addr);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_change_bearer_to_wlan
 * DESCRIPTION
 *  The function is used to notify CBM that change bearer to WLAN.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    :   Post change bearer event successfully
 *  SRV_DTCNT_RESULT_FAILED     :   Post change bearer event failed
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_change_bearer_to_wlan(void);
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_send_portal_login_start_req
 * DESCRIPTION
 *  The function is used to send MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_STRAT_REQ to ABM.
 * PARAMETERS
 *  app_id : [IN]
 * RETURN VALUES
 *****************************************************************************/

extern void srv_dtcnt_wlan_send_portal_login_start_req(U8 app_id);
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_send_portal_logout_req
 * DESCRIPTION
 *  The function is used to send MSG_ID_MMI_ABM_WIFI_PORTAL_LOGOUT_REQ to ABM.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *****************************************************************************/

extern void srv_dtcnt_wlan_send_portal_logout_req(void);
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_send_portal_login_stop_req
 * DESCRIPTION
 *  The function is used to send MSG_ID_MMI_ABM_WIFI_PORTAL_LOGIN_STOP_REQ to ABM.
 * PARAMETERS
 *  result:    [IN]
 * RETURN VALUES
 *****************************************************************************/

extern void srv_dtcnt_wlan_send_portal_login_stop_req(MMI_BOOL result);
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_set_portal_switch
 * DESCRIPTION
 *  The function is used to set portal switch for DA Srv.
 * PARAMETERS
 *  switch_state:    [IN]
 * RETURN VALUES
 *****************************************************************************/

//extern void srv_dtcnt_wlan_set_portal_switch(MMI_BOOL switch_state);
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_wlan_prefer_setting
 * DESCRIPTION
 *  The function is used to get CMCC WLAN prefer setting from DA Srv.
 * PARAMETERS
 *  wlan_prefer_ctx:    [OUT]
 * RETURN VALUES
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_wlan_prefer_setting(srv_dtcnt_wlan_prefer_struct * wlan_prefer_ctx);
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_set_wlan_prefer_setting
 * DESCRIPTION
 *  The function is used to set CMCC WLAN prefer setting to DA Srv.
 * PARAMETERS
 *  wlan_prefer_ctx:    [IN]
 * RETURN VALUES
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_set_wlan_prefer_setting(srv_dtcnt_wlan_prefer_struct *wlan_prefer_ctx);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_default_account
 * DESCRIPTION
 *  The function is used to get default account for certain sim card.
 * PARAMETERS
 *  sim_id:    [IN]    sim id
 *  account_id:     [OUT] default account id
 * RETURN VALUES
 *****************************************************************************/

extern MMI_BOOL srv_dtcnt_get_default_account(srv_dtcnt_sim_type_enum sim_id, U32 * account_id);


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_state
 * DESCRIPTION
 *  The function is used to get wlan state.
 * PARAMETERS
 *  NULL
 * RETURN VALUES
 *  Return wlan state
 *****************************************************************************/

extern srv_dtcnt_wlan_state_enum srv_dtcnt_wlan_state(void);

extern srv_dtcnt_wlan_switch_state_enum srv_dtcnt_wlan_switch_state(void);


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_get_connected_ap_bssid
 * DESCRIPTION
 *  The function is used to get connected WiFi access point's bssid.
 * PARAMETERS
 *  bssid [IN]: array used to store bssid. The length is WNDRV_MAC_ADDRESS_LEN(6).
 * RETURN VALUES
 * MMI_TRUE: get bssid succ
 * MMI_FALSE: get bssid fail
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_wlan_get_connected_ap_bssid(U8 * bssid);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_in_blacklist
 * DESCRIPTION
 *  The function is check if the scan ap is in black list.
 * PARAMETERS
 *  scan_ap [IN]: scan ap info.
 * RETURN VALUES
 * MMI_TRUE: in black list
 * MMI_FALSE: not in black list
 *****************************************************************************/

extern MMI_BOOL srv_dtcnt_wlan_in_blacklist(supc_abm_bss_info_struct * scan_ap);

extern srv_dtcnt_prof_wlan_struct * srv_dtcnt_wlan_get_connecting_prof(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_auto_pw_on
 * DESCRIPTION
 *  Used to auto init WiFi when boot up.
 * PARAMETERS
 *  NULL
 * RETURN VALUES
 *  NULL
 *****************************************************************************/
extern void srv_dtcnt_wlan_auto_pw_on(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_need_init_check
 * DESCRIPTION
 *  The function is check if the WiFi need init when flight mode off.
 * PARAMETERS
 *  NULL.
 * RETURN VALUES
 * MMI_TRUE:  need init
 * MMI_FALSE: no need init
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_wlan_need_init_check(void);

/* DOM-NOT_FOR_SDK-END */

#endif /* _DTCNT_SRV_IPROT_H */ 
