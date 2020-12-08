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
 * ProvisioningSrvConfiguringSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file will function as configuring source for MOD WAP.
 *
 * Author:
 * -------
 *
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
//#include "MMI_include.h"
#include "MMI_features.h"
#ifndef _PROVISIONINGSRVCONFIGURINGSRC_C
#define _PROVISIONINGSRVCONFIGURINGSRC_C

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

#include "ProvisioningSrvMain.h"

#ifdef __MMI_PROV_SERVICE_CCA_SUPPORT_ON__

#include "ProvisioningSrvProt.h"
//------------------------------ suggest Add ------------------------------
#include "ProvisioningSrvConfiguringSrc.h"
#include "ProvisioningSrvProt.h"
#include "MMIDataType.h"
#include "CcaSrvGprot.h"
#include "kal_general_types.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"

#include "stack_config.h"
#include "kal_public_api.h"
#include "stdio.h"
#include "stdlib.h"
//------------------------------ usage ------------------------------


static SRV_PROV_RETCODE srv_prov_napdef_param_callspeed_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);

static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_proxy_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_PROXY_ID_TXT, SRV_CCA_NS_OMA_PROXY_ID, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_proxy_param_proxyid_tag_hdlr */ },
    //{(U8 *) SRV_PROV_PROXY_PW_TXT, SRV_CCA_NS_OMA_PROXY_PW, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_PPGAUTH_TYPE_TXT, SRV_CCA_NS_OMA_PPGAUTH_TYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
    // srv_prov_param_authtype_tag_hdlr},
#ifdef __MMI_SYNCML_CCA_SUPPORT__
    {(U8 *) SRV_PROV_PROXY_PROVIDER_ID_TXT, SRV_CCA_NS_OMA_PROXY_PROVIDER_ID, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
    {(U8 *) SRV_PROV_NAME_TXT, SRV_CCA_NS_OMA_NAME, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_proxy_param_name_tag_hdlr */ },

    //{(U8 *) SRV_PROV_TRUST_TXT, SRV_CCA_NS_OMA_TRUST, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_MASTER_TXT, SRV_CCA_NS_OMA_MASTER, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_STARTPAGE_TXT, SRV_CCA_NS_OMA_STARTPAGE, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
   // {(U8 *) SRV_PROV_BASAUTH_ID_TXT, SRV_CCA_NS_OMA_BASAUTH_ID, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
   // {(U8 *) SRV_PROV_BASAUTH_PW_TXT, SRV_CCA_NS_OMA_BASAUTH_PW, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
   // {(U8 *) SRV_PROV_WSP_VERSION_TXT, SRV_CCA_NS_OMA_WSP_VERSION, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_PUSHENABLED_TXT, SRV_CCA_NS_OMA_PUSHENABLED, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
    // srv_prov_proxy_param_pushpullenabled_tag_hdlr},
    //{(U8 *) SRV_PROV_PULLENABLED_TXT, SRV_CCA_NS_OMA_PULLENABLED, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
    // srv_prov_proxy_param_pushpullenabled_tag_hdlr},
   // {(U8 *) SRV_PROV_PHYSICAL_PROXY_ID_TXT, SRV_CCA_NS_OMA_PHYSICAL_PROXY_ID, SRV_PROV_CCA_CONV_TYPE_STR,
    // NULL /* srv_prov_proxy_param_phyproxyid_tag_hdlr */ },
    {(U8 *) SRV_PROV_PXADDR_TXT, SRV_CCA_NS_OMA_PXADDR, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_proxy_param_pxaddr_tag_hdlr */ },
    {(U8 *) SRV_PROV_PXADDRTYPE_TXT, SRV_CCA_NS_OMA_PXADDRTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_addrtype_tag_hdlr},
    //{(U8 *) SRV_PROV_PXADDR_FQDN_TXT, SRV_CCA_NS_OMA_PXADDR_FQDN, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_TO_NAPID_TXT, SRV_CCA_NS_OMA_TO_NAPID, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_proxy_param_tonapid_tag_hdlr */ },

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};

static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_port_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_PORTNBR_TXT, SRV_CCA_NS_OMA_PORTNBR, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_port_param_port_tag_hdlr */ },
    {(U8 *) SRV_PROV_SERVICE_TXT, SRV_CCA_NS_OMA_SERVICE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_port_param_service_tag_hdlr},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_pxauthinfo_param_tag_hdlr_mapping_table[] = 
{
#ifdef __MMI_SYNCML_CCA_SUPPORT__	
    {(U8 *) SRV_PROV_PXAUTH_TYPE_TXT, SRV_CCA_NS_OMA_PXAUTH_TYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_authtype_tag_hdlr},
#endif
    {(U8 *) SRV_PROV_PXAUTH_ID_TXT, SRV_CCA_NS_OMA_PXAUTH_ID, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXAUTH_PW_TXT, SRV_CCA_NS_OMA_PXAUTH_PW, SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_application_param_tag_hdlr_mapping_table[] = 
{
   
    {(U8 *) SRV_PROV_APPID_TXT, SRV_CCA_NS_OMA_APPID, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_application_param_appid_tag_hdlr */ },
    {(U8 *) SRV_PROV_PROVIDER_ID_TXT, SRV_CCA_NS_OMA_PROVIDER_ID, SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) SRV_PROV_NAME_TXT, SRV_CCA_NS_OMA_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#ifdef __MMI_SYNCML_CCA_SUPPORT__
    {(U8 *) SRV_PROV_AACCEPT_TXT, SRV_CCA_NS_OMA_AACCEPT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
    //{(U8 *) SRV_PROV_APROTOCOL_TXT, SRV_CCA_NS_OMA_APROTOCOL, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#if defined (__MMI_EMAIL__) || defined (__MMI_IMPS__) || defined (__AGPS_SUPPORT__) || defined (__MMI_SYNCML_CCA_SUPPORT__) || defined (SYNCML_DM_SUPPORT) || defined (WAP_SUPPORT)
    {(U8 *) SRV_PROV_TO_PROXY_TXT, SRV_CCA_NS_OMA_TO_PROXY, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_application_param_toproxy_tag_hdlr */ },
    {(U8 *) SRV_PROV_ADDR_TXT, SRV_CCA_NS_OMA_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
    {(U8 *) SRV_PROV_TO_NAPID_TXT, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, srv_prov_application_param_tonapid_tag_hdlr},

#ifdef __MMI_EMAIL__
    {(U8 *) SRV_PROV_FROM_TXT, SRV_CCA_NS_OMA_FROM, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_RT_ADDR_TXT, SRV_CCA_NS_OMA_RT_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
   // {(U8 *) SRV_PROV_CIDPREFIX_TXT, SRV_CCA_NS_OMA_CIDPREFIX, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_SERVICES_TXT, SRV_CCA_NS_OMA_SERVICES, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_INIT_TXT, SRV_CCA_NS_OMA_INIT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#ifdef WAP_SUPPORT
    {(U8 *) SRV_PROV_APP_MMS_CM_TXT, SRV_CCA_NS_OMA_CM, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR, srv_prov_app_param_cm_and_rm_tag_hdlr},
    {(U8 *) SRV_PROV_APP_RM_TXT, SRV_CCA_NS_OMA_RM, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR, srv_prov_app_param_cm_and_rm_tag_hdlr},
    {(U8 *) SRV_PROV_APP_MS_TXT, SRV_CCA_NS_OMA_MS, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_APP_MA_TXT, SRV_CCA_NS_OMA_MA, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR, NULL},
    {(U8 *) SRV_PROV_APP_PC_ADDR_TXT, SRV_CCA_NS_OMA_PC_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
/* AGPS support starts */
    //{(U8 *) SRV_PROV_APP_MAX_BANDWIDTH_TXT, SRV_CCA_NS_OMA_MAX_BANDWIDTH, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_APP_NETINFO_TXT, SRV_CCA_NS_OMA_NETINFO, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#ifdef __MMI_STREAMING_OTAP__
    {(U8 *) SRV_PROV_APP_MIN_UDP_PORT, SRV_CCA_NS_OMA_MIN_UDP_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_APP_MAX_UDP_PORT, SRV_CCA_NS_OMA_MAX_UDP_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
/* AGPS support ends */

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_resource_param_tag_hdlr_mapping_table[] = 
{
  
    {(U8 *) SRV_PROV_URI_TXT, SRV_CCA_NS_OMA_URI, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_pxauthinfo_param_uri_tag_hdlr */ },

    {(U8 *) SRV_PROV_NAME_TXT, SRV_CCA_NS_OMA_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#ifdef __MMI_SYNCML_CCA_SUPPORT__
    {(U8 *) SRV_PROV_AACCEPT_TXT, SRV_CCA_NS_OMA_AACCEPT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif 
#if defined (SYNCML_DM_SUPPORT) || defined (__MMI_SYNCML_CCA_SUPPORT__)
    {(U8 *) SRV_PROV_AAUTHTYPE_TXT, SRV_CCA_NS_OMA_AAUTHTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_authtype_tag_hdlr},
#endif
#if defined (__MMI_IMPS__) || defined (__MMI_SYNCML_CCA_SUPPORT__) || defined (SYNCML_DM_SUPPORT)
    {(U8 *) SRV_PROV_AAUTHNAME_TXT, SRV_CCA_NS_OMA_AAUTHNAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_AAUTHSECRET_TXT, SRV_CCA_NS_OMA_AAUTHSECRET, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
#ifdef SYNCML_DM_SUPPORT
    {(U8 *) SRV_PROV_AAUTHDATA_TXT, SRV_CCA_NS_OMA_AAUTHDATA, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
    {(U8 *) SRV_PROV_STARTPAGE_TXT, SRV_CCA_NS_OMA_STARTPAGE, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_CLIURI_TXT, SRV_CCA_NS_OMA_CLIURI, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_SYNCTYPE_TXT, SRV_CCA_NS_OMA_SYNCTYPE, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
 #ifdef __PROV_NOKIA_OTA_SUPPORT__
    {(U8 *) SRV_PROV_NE_URL_TXT, SRV_CCA_NS_OMA_URI, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
 #endif 
    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_appaddr_param_tag_hdlr_mapping_table[] = 
{
#if defined (__MMI_EMAIL__) || defined (__MMI_IMPS__) || defined (__AGPS_SUPPORT__) || defined (__MMI_SYNCML_CCA_SUPPORT__) || defined (SYNCML_DM_SUPPORT) || defined (WAP_SUPPORT)
    {(U8 *) SRV_PROV_ADDR_TXT, SRV_CCA_NS_OMA_ADDR, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_appaddr_param_addr_tag_hdlr */ },
    {(U8 *) SRV_PROV_ADDRTYPE_TXT, SRV_CCA_NS_OMA_ADDRTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_addrtype_tag_hdlr},
#endif
    {(U8 *) SRV_PROV_PORTNBR_TXT, SRV_CCA_NS_OMA_PORTNBR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_SERVICE_TXT, SRV_CCA_NS_OMA_SERVICE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_port_param_service_tag_hdlr},


    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_appauth_param_tag_hdlr_mapping_table[] = 
{
#if defined (__MMI_SYNCML_CCA_SUPPORT__) || defined (SYNCML_DM_SUPPORT) 
    {(U8 *) SRV_PROV_AAUTHLEVEL_TXT, SRV_CCA_NS_OMA_AAUTHLEVEL, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_appauth_param_authlevel_tag_hdlr},
#endif
#if defined (__MMI_EMAIL__) || defined (__MMI_IMPS__) || defined (__MMI_SYNCML_CCA_SUPPORT__) || defined (SYNCML_DM_SUPPORT)
    {(U8 *) SRV_PROV_AAUTHTYPE_TXT, SRV_CCA_NS_OMA_AAUTHTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_authtype_tag_hdlr},
    {(U8 *) SRV_PROV_AAUTHNAME_TXT, SRV_CCA_NS_OMA_AAUTHNAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_AAUTHSECRET_TXT, SRV_CCA_NS_OMA_AAUTHSECRET, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif
#ifdef SYNCML_DM_SUPPORT
    {(U8 *) SRV_PROV_AAUTHDATA_TXT, SRV_CCA_NS_OMA_AAUTHDATA, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
#endif

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};

static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_bootstrap_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_NAME_TXT, SRV_CCA_NS_OMA_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_NETWORK_TXT, SRV_CCA_NS_OMA_NETWORK, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_COUNTRY_TXT, SRV_CCA_NS_OMA_COUNTRY, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PROXY_ID_TXT, SRV_CCA_NS_OMA_PROXY_ID, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PROVURL_TXT, SRV_CCA_NS_OMA_PROVURL, SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}
};

static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_napdef_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_NAPID_TXT, SRV_CCA_NS_OMA_NAPID, SRV_PROV_CCA_CONV_TYPE_STR,
     NULL /* srv_prov_napdef_param_napid_tag_hdlr */ },
    {(U8 *) SRV_PROV_BEARER_TXT, SRV_CCA_NS_OMA_BEARER, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_napdef_param_bearer_tag_hdlr},
    {(U8 *) SRV_PROV_NAME_TXT, SRV_CCA_NS_OMA_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_INTERNET_TXT, SRV_CCA_NS_OMA_INTERNET, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_NAP_ADDRESS_TXT, SRV_CCA_NS_OMA_NAP_ADDRESS, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_NAP_ADDRTYPE_TXT, SRV_CCA_NS_OMA_NAP_ADDRTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
    // srv_prov_param_addrtype_tag_hdlr},
    {(U8 *) SRV_PROV_DNS_ADDR_TXT, SRV_CCA_NS_OMA_DNS_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_CALLTYPE_TXT, SRV_CCA_NS_OMA_CALLTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_napdef_param_calltype_tag_hdlr},
    //{(U8 *) SRV_PROV_LOCAL_ADDR_TXT, SRV_CCA_NS_OMA_LOCAL_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    //{(U8 *) SRV_PROV_LOCAL_ADDRTYPE_TXT, SRV_CCA_NS_OMA_LOCAL_ADDRTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
    // srv_prov_param_addrtype_tag_hdlr},
    {(U8 *) SRV_PROV_LINKSPEED_TXT, SRV_CCA_NS_OMA_LINKSPEED, SRV_PROV_CCA_CONV_TYPE_INT, srv_prov_napdef_param_callspeed_tag_hdlr},        /* take care for auto-bauding */
   // {(U8 *) SRV_PROV_DNLINKSPEED_TXT, SRV_CCA_NS_OMA_DNLINKSPEED, SRV_PROV_CCA_CONV_TYPE_INT,
    // srv_prov_napdef_param_callspeed_tag_hdlr},
   /* {(U8 *) SRV_PROV_LINGER_TXT, SRV_CCA_NS_OMA_LINGER, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_DELIVERY_ERR_SDU_TXT, SRV_CCA_NS_OMA_DELIVERY_ERR_SDU, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_DELIVERY_ORDER_TXT, SRV_CCA_NS_OMA_DELIVERY_ORDER, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_TRAFFIC_CLASS_TXT, SRV_CCA_NS_OMA_TRAFFIC_CLASS, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_MAX_SDU_SIZE_TXT, SRV_CCA_NS_OMA_MAX_SDU_SIZE, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_MAX_BITRATE_UPLINK_TXT, SRV_CCA_NS_OMA_MAX_BITRATE_UPLINK, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_MAX_BITRATE_DNLINK_TXT, SRV_CCA_NS_OMA_MAX_BITRATE_DNLINK, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_RESIDUAL_BER_TXT, SRV_CCA_NS_OMA_RESIDUAL_BER, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_SDU_ERROR_RATIO_TXT, SRV_CCA_NS_OMA_SDU_ERROR_RATIO, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_TRAFFIC_HANDL_PRIO_TXT, SRV_CCA_NS_OMA_TRAFFIC_HANDL_PRIO, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_TRANSFER_DELAY_TXT, SRV_CCA_NS_OMA_TRANSFER_DELAY, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_GUARANTEED_BITRATE_UPLINK_TXT, SRV_CCA_NS_OMA_GUARANTEED_BITRATE_UPLINK, SRV_PROV_CCA_CONV_TYPE_INT,
     NULL},
    {(U8 *) SRV_PROV_GUARANTEED_BITRATE_DNLINK_TXT, SRV_CCA_NS_OMA_GUARANTEED_BITRATE_DNLINK, SRV_PROV_CCA_CONV_TYPE_INT,
     NULL},
    {(U8 *) SRV_PROV_MAX_NUM_RETRY_TXT, SRV_CCA_NS_OMA_MAX_NUM_RETRY, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_FIRST_RETRY_TIMEOUT_TXT, SRV_CCA_NS_OMA_FIRST_RETRY_TIMEOUT, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_REREG_THRESHOLD_TXT, SRV_CCA_NS_OMA_REREG_THRESHOLD, SRV_PROV_CCA_CONV_TYPE_INT, NULL},
    {(U8 *) SRV_PROV_T_BIT_TXT, SRV_CCA_NS_OMA_T_BIT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},*/

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_napauthinfo_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_AUTHTYPE_TXT, SRV_CCA_NS_OMA_AUTHTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_authtype_tag_hdlr},
    {(U8 *) SRV_PROV_AUTHNAME_TXT, SRV_CCA_NS_OMA_AUTHNAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_AUTHSECRET_TXT, SRV_CCA_NS_OMA_AUTHSECRET, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
   // {(U8 *) SRV_PROV_AUTH_ENTITY_TXT, SRV_CCA_NS_OMA_AUTH_ENTITY, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
    // srv_prov_napauthinfo_param_authentity_tag_hdlr},
    //{(U8 *) SRV_PROV_SPI_TXT, SRV_CCA_NS_OMA_SPI, SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
/*static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_validity_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_COUNTRY_TXT, SRV_CCA_NS_OMA_COUNTRY, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_NETWORK_TXT, SRV_CCA_NS_OMA_NETWORK, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_SID_TXT, SRV_CCA_NS_OMA_SID, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_SOC_TXT, SRV_CCA_NS_OMA_SOC, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_VALIDUNTIL_TXT, SRV_CCA_NS_OMA_VALIDUNTIL, SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};*/

static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_access_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_root_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};

#ifdef __PROV_NOKIA_OTA_SUPPORT__

static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_ne_address_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_BEARER_TXT, SRV_CCA_NS_OMA_BEARER, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_napdef_param_bearer_tag_hdlr},
    {(U8 *) SRV_PROV_NE_ISP_NAME_TXT, SRV_CCA_NS_OMA_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) SRV_PROV_NE_SMS_SMSC_ADDRESS_TXT, SRV_CCA_NS_OMA_NAP_ADDRESS, SRV_PROV_CCA_CONV_TYPE_STR,
     srv_prov_ne_address_param_sms_smsc_tag_hdlr},
    {(U8 *) SRV_PROV_NE_USSD_SERVICE_CODE_TXT, SRV_CCA_NS_OMA_NAP_ADDRESS, SRV_PROV_CCA_CONV_TYPE_STR,
     srv_prov_ne_address_param_ussd_sevice_tag_hdlr},
    {(U8 *) SRV_PROV_NE_GPRS_ACCESSPOINTNAME_TXT, SRV_CCA_NS_OMA_NAP_ADDRESS, SRV_PROV_CCA_CONV_TYPE_STR,
     srv_prov_ne_address_param_gprs_accesspoint_tag_hdlr},
    {(U8 *) SRV_PROV_NE_CSD_DIALSTRING_TXT, SRV_CCA_NS_OMA_NAP_ADDRESS, SRV_PROV_CCA_CONV_TYPE_STR,
     srv_prov_ne_address_param_sms_smsc_tag_hdlr},

    {(U8 *) SRV_PROV_NE_CSD_CALLTYPE_TXT, SRV_CCA_NS_OMA_CALLTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_napdef_param_calltype_tag_hdlr},

    {(U8 *) SRV_PROV_NE_CSD_CALLSPEED_TXT, SRV_CCA_NS_OMA_LINKSPEED, SRV_PROV_CCA_CONV_TYPE_INT, srv_prov_napdef_param_callspeed_tag_hdlr}, /* take care for auto-bauding */

    {(U8 *) SRV_PROV_NE_PPP_AUTHTYPE_TXT, SRV_CCA_NS_OMA_AUTHTYPE, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_ppp_authtype_tag_hdlr},
    {(U8 *) SRV_PROV_NE_PPP_AUTHNAME_TXT, SRV_CCA_NS_OMA_AUTHNAME, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_ppp_authname_tag_hdlr},
    {(U8 *) SRV_PROV_NE_PPP_AUTHSECRET_TXT, SRV_CCA_NS_OMA_AUTHSECRET, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_ppp_authsecret_tag_hdlr},

    {(U8 *) SRV_PROV_NE_PPP_LOGINTYPE_TXT, SRV_CCA_NS_OMA_LOGINTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_ne_address_param_ppp_logintype_tag_hdlr},
    {(U8 *) SRV_PROV_NE_PROXY_LOGINTYPE_TXT, SRV_CCA_NS_OMA_LOGINTYPE, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_proxy_logintype_tag_hdlr},

    {(U8 *) SRV_PROV_NE_PROXY_TXT, SRV_CCA_NS_OMA_PXADDR, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_proxy_tag_hdlr},
    {(U8 *) SRV_PROV_NE_PROXY_TYPE_TXT, SRV_CCA_NS_OMA_PXADDRTYPE, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_proxy_type_tag_hdlr},

    {(U8 *) SRV_PROV_NE_PROXY_AUTHNAME_TXT, SRV_CCA_NS_OMA_PXAUTH_ID, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_proxy_authname_tag_hdlr},
    {(U8 *) SRV_PROV_NE_PROXY_AUTHSECRET_TXT, SRV_CCA_NS_OMA_PXAUTH_PW, SRV_PROV_CCA_CONV_TYPE_TOTAL,
     srv_prov_ne_address_param_proxy_authsecret_tag_hdlr},

    {(U8 *) SRV_PROV_NE_PORT_TXT, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, srv_prov_ne_address_param_port_tag_hdlr},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};

static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_ne_name_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_NAME_TXT, SRV_CCA_NS_OMA_NAME, SRV_PROV_CCA_CONV_TYPE_TOTAL, srv_prov_ne_name_param_name_tag_hdlr},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};

#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
/* DMP Spec */
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_pxsip_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_PXSIP_NAME_TXT, CCA_NS_OMADMP_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_USER_NAME_TXT, SRV_CCA_NS_OMADMP_USER_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_AUTH_NAME_TXT, SRV_CCA_NS_OMADMP_AUTH_NAME, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_AUTH_PASSWD_TXT, SRV_CCA_NS_OMADMP_AUTH_PASSWD, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_DOMAIN_TXT, SRV_CCA_NS_OMADMP_DOMAIN, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_LOCAL_PORT_TXT, SRV_CCA_NS_OMADMP_LOCAL_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_PREFER_CODEC_TXT, SRV_CCA_NS_OMADMP_PREFER_CODEC, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_pxsip_codec_tag_hdlr},
    {(U8 *) SRV_PROV_PXSIP_PXSRV_ADDR_TXT, SRV_CCA_NS_OMADMP_PXSRV_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_PXSRV_ADDRTYPE_TXT, SRV_CCA_NS_OMADMP_PXSRV_ADDRTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_addrtype_tag_hdlr},
    {(U8 *) SRV_PROV_PXSIP_PXSRV_PORT_TXT, SRV_CCA_NS_OMADMP_PXSRV_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_REGSRV_ADDR_TXT, SRV_CCA_NS_OMADMP_REGSRV_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_REGSRV_ADDRTYPE_TXT, SRV_CCA_NS_OMADMP_REGSRV_ADDRTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_addrtype_tag_hdlr},
    {(U8 *) SRV_PROV_PXSIP_REGSRV_PORT_TXT, SRV_CCA_NS_OMADMP_REGSRV_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_REGSRV_REGPERIOD_TXT, SRV_CCA_NS_OMADMP_REGSRV_REGPERIOD, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_OUTPXSRV_ADDR_TXT, SRV_CCA_NS_OMADMP_OUTPXSRV_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_OUTPXSRV_ADDRTYPE_TXT, SRV_CCA_NS_OMADMP_OUTPXSRV_ADDRTYPE, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_addrtype_tag_hdlr},
    {(U8 *) SRV_PROV_PXSIP_OUTPXSRV_PORT_TXT, SRV_CCA_NS_OMADMP_OUTPXSRV_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_RTP_AUDIO_PORT_TXT, SRV_CCA_NS_OMADMP_RTP_AUDIO_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_RTP_PACKET_PERIOD_TXT, SRV_CCA_NS_OMADMP_RTP_PACKET_PERIOD, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_NAT_RPORT_ENABLED_TXT, SRV_CCA_NS_OMADMP_NAT_RPORT_ENABLED, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_proxy_param_pushpullenabled_tag_hdlr},
    {(U8 *) SRV_PROV_PXSIP_NAT_STUN_ENABLED_TXT, SRV_CCA_NS_OMADMP_NAT_STUN_ENABLED, SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_proxy_param_pushpullenabled_tag_hdlr},
    {(U8 *) SRV_PROV_PXSIP_NAT_STUNSRV_ADDR_TXT, SRV_CCA_NS_OMADMP_NAT_STUNSRV_ADDR, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_NAT_STUNSRV_ADDRTYPE_TXT, SRV_CCA_NS_OMADMP_NAT_STUNSRV_ADDRTYPE,
     SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR,
     srv_prov_param_addrtype_tag_hdlr},
    {(U8 *) SRV_PROV_PXSIP_NAT_STUNSRV_PORT_TXT, SRV_CCA_NS_OMADMP_NAT_STUNSRV_PORT, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_PXSIP_NAT_STUNSRV_REFRESH_PERIOD_TXT, SRV_CCA_NS_OMADMP_NAT_STUNSRV_REFRESH_PERIOD,
     SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_wifi_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_access_point_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_adhoc_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}

};
static const srv_prov_characteristic_parm_tag_hdlr_struct srv_prov_wifi_profile_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_WIFI_ADHOC_TXT, SRV_CCA_NS_OMADMP_ADHOC, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_WIFI_AUTHENTICATION_TXT, SRV_CCA_NS_OMADMP_AUTHENTICATION, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_WIFI_ENCRYPTION_TXT, SRV_CCA_NS_OMADMP_ENCRYPTION, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_WIFI_KEYPROVIDED_TXT, SRV_CCA_NS_OMADMP_KEYPROVIDED, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_WIFI_NETWORKKEY_TXT, SRV_CCA_NS_OMADMP_NETWORKKEY, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_WIFI_KEYINDEX_TXT, SRV_CCA_NS_OMADMP_KEYINDEX, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_WIFI_USE8021X_TXT, SRV_CCA_NS_OMADMP_USE8021X, SRV_PROV_CCA_CONV_TYPE_STR, NULL},
    {(U8 *) SRV_PROV_WIFI_EAPTYPE_TXT, SRV_CCA_NS_OMADMP_EAPTYPE, SRV_PROV_CCA_CONV_TYPE_STR, NULL},

    {(U8 *) NULL, 0xFFFF, SRV_PROV_CCA_CONV_TYPE_TOTAL, NULL}
};
static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_pxsip_codec_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_PXSIP_CODEC_G711A_TXT, SRV_CCA_NS_VAL_G711A},
    {(U8 *) SRV_PROV_PXSIP_CODEC_G711U_TXT, SRV_CCA_NS_VAL_G711U},
    {(U8 *) SRV_PROV_PXSIP_CODEC_G726_16_TXT, SRV_CCA_NS_VAL_G726_16},
    {(U8 *) SRV_PROV_PXSIP_CODEC_G726_24_TXT, SRV_CCA_NS_VAL_G726_24},
    {(U8 *) SRV_PROV_PXSIP_CODEC_G726_32_TXT, SRV_CCA_NS_VAL_G726_32},
    {(U8 *) SRV_PROV_PXSIP_CODEC_G726_40_TXT, SRV_CCA_NS_VAL_G726_40},
    {(U8 *) NULL, 0xffff},
};

#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */

static const srv_prov_characteristic_tag_hdlr_struct srv_prov_oma_characteristic_tag_hdlr_mapping_table[] = 
{
    {(U8 *) SRV_PROV_PXPHYSICAL_TXT, SRV_CCA_NS_OMA_PROXY, SRV_PROV_PXLOGICAL_NODE_VAL, SRV_PROV_PXPHYSICAL_NODE_VAL,
     srv_prov_characteristic_pxphysical_tag_hdlr,
     srv_prov_proxy_param_tag_hdlr_mapping_table}, //all
    {(U8 *) SRV_PROV_PXLOGICAL_TXT, SRV_CCA_NS_OMA_PROXY, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_PXLOGICAL_NODE_VAL,
     srv_prov_characteristic_pxlogical_tag_hdlr,
     srv_prov_proxy_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_PORT_TXT, SRV_CCA_NS_OMA_PORT,
     SRV_PROV_PXLOGICAL_NODE_VAL | SRV_PROV_PXPHYSICAL_NODE_VAL | SRV_PROV_APPADDR_NODE_VAL,
     SRV_PROV_PORT_NODE_VAL, srv_prov_characteristic_port_tag_hdlr,
     srv_prov_port_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_PXAUTHINFO_TXT, SRV_CCA_NS_OMA_PXAUTHINFO, SRV_PROV_PXLOGICAL_NODE_VAL, SRV_PROV_PXAUTHINFO_NODE_VAL,
     srv_prov_characteristic_pxauthinfo_tag_hdlr,
     srv_prov_pxauthinfo_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_APPLICATION_TXT, SRV_CCA_NS_OMA_APPLICATION, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_APPLICATION_NODE_VAL,
     srv_prov_characteristic_application_tag_hdlr,
     srv_prov_application_param_tag_hdlr_mapping_table},
    {(U8 *) SRV_PROV_RESOURCE_TXT, SRV_CCA_NS_OMA_RESOURCE, SRV_PROV_APPLICATION_NODE_VAL, SRV_PROV_RESOURCE_NODE_VAL,
     srv_prov_characteristic_resource_tag_hdlr,
     srv_prov_resource_param_tag_hdlr_mapping_table},
#if defined (__MMI_EMAIL__) || defined (__MMI_IMPS__) || defined (__AGPS_SUPPORT__) || defined (__MMI_SYNCML_CCA_SUPPORT__) || defined (SYNCML_DM_SUPPORT)
    {(U8 *) SRV_PROV_APPADDR_TXT, SRV_CCA_NS_OMA_APPADDR, SRV_PROV_APPLICATION_NODE_VAL, SRV_PROV_APPADDR_NODE_VAL,
     srv_prov_characteristic_appaddr_tag_hdlr,
     srv_prov_appaddr_param_tag_hdlr_mapping_table},
#endif

    {(U8 *) SRV_PROV_APPAUTH_TXT, SRV_CCA_NS_OMA_APPAUTH, SRV_PROV_APPLICATION_NODE_VAL, SRV_PROV_APPAUTH_NODE_VAL,
     srv_prov_characteristic_appauth_tag_hdlr,
     srv_prov_appauth_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_BOOTSTRAP_TXT, SRV_CCA_NS_OMA_BOOTSTRAP, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_BOOTSTRAP_NODE_VAL,
     srv_prov_characteristic_bootstrap_tag_hdlr,
     srv_prov_bootstrap_param_tag_hdlr_mapping_table}, //all
    {(U8 *) SRV_PROV_NAPDEF_TXT, SRV_CCA_NS_OMA_NAPDEF, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_NAPDEF_NODE_VAL,
     srv_prov_characteristic_napdef_tag_hdlr,
     srv_prov_napdef_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_NAPAUTHINFO_TXT, SRV_CCA_NS_OMA_NAPAUTHINFO, SRV_PROV_NAPDEF_NODE_VAL, SRV_PROV_NAPAUTHINFO_NODE_VAL,
     srv_prov_characteristic_napauthinfo_tag_hdlr,
     srv_prov_napauthinfo_param_tag_hdlr_mapping_table},

   /* {(U8 *) SRV_PROV_VALIDITY_TXT, SRV_CCA_NS_OMA_VALIDITY, SRV_PROV_NAPDEF_NODE_VAL, SRV_PROV_VALIDITY_NODE_VAL,
     srv_prov_characteristic_validity_tag_hdlr,
     srv_prov_validity_param_tag_hdlr_mapping_table},*/

   /* {(U8 *) SRV_PROV_ACCESS_TXT, SRV_CCA_NS_OMA_ACCESS, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_ACCESS_NODE_VAL,
     srv_prov_characteristic_access_tag_hdlr,
     srv_prov_access_param_tag_hdlr_mapping_table},*/

 #if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
    /* DMP Spec */
    {(U8 *) SRV_PROV_PX_SIP_TXT, SRV_CCA_NS_OMADMP_PX_SIP, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_PXSIP_NODE_VAL,
     srv_prov_characteristic_pxsip_tag_hdlr,
     srv_prov_pxsip_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_WIFI_TXT, SRV_CCA_NS_OMADMP_WIFI, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_WIFI_NODE_VAL,
     srv_prov_characteristic_wifi_tag_hdlr,
     srv_prov_wifi_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_ACCESS_POINT_TXT, SRV_CCA_NS_OMADMP_ACCESS_POINT, SRV_PROV_WIFI_NODE_VAL,
     SRV_PROV_ACCESS_POINT_NODE_VAL,
     srv_prov_characteristic_access_point_tag_hdlr,
     srv_prov_access_point_param_tag_hdlr_mapping_table},

    {(U8 *) SRV_PROV_AD_HOC_TXT, SRV_CCA_NS_OMADMP_AD_HOC, SRV_PROV_WIFI_NODE_VAL, SRV_PROV_AD_HOC_NODE_VAL,
     srv_prov_characteristic_adhoc_tag_hdlr,
     srv_prov_adhoc_param_tag_hdlr_mapping_table},

 #endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */

    {NULL, 0xFFFF}
};

static const srv_prov_characteristic_tag_hdlr_struct srv_prov_non_oma_characteristic_tag_hdlr_mapping_table[] = 
{
#ifdef __PROV_NOKIA_OTA_SUPPORT__

    {(U8 *) SRV_PROV_NE_ADDRESS_TXT, SRV_CCA_NS_OMA_NAPDEF, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_NE_ADRESS_NODE_VAL,
     srv_prov_characteristic_ne_address_tag_hdlr,
     srv_prov_ne_address_param_tag_hdlr_mapping_table},

    /* {(U8 *)SRV_PROV_NE_URL_TXT, SRV_CCA_NS_OMA_RESOURCE, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_NE_URL_NODE_VAL,
       srv_prov_characteristic_ne_url_tag_hdlr,
       NULL}, */

    {(U8 *) SRV_PROV_NE_MMSURL_TXT, SRV_CCA_NS_OMA_APPLICATION, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_NE_MMSURL_NODE_VAL,
     srv_prov_characteristic_ne_mmsurl_tag_hdlr,
     NULL},

    {(U8 *) SRV_PROV_NE_BOOKMARK_TXT, SRV_CCA_NS_OMA_RESOURCE, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_NE_BOOKMARK_NODE_VAL,
     srv_prov_characteristic_ne_bookmark_tag_hdlr,
     srv_prov_resource_param_tag_hdlr_mapping_table},

    /* {(U8 *)SRV_PROV_NE_ID_TXT, CCA_NS_OMA_CLIENTIDENTITY, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_NE_ID_NODE_VAL,
       srv_prov_characteristic_ne_id_tag_hdlr,
       prov_ne_id_param_tag_hdlr_mapping_table}, */

    /* dummy resource node is created for handling its param values and then deleted the node */
    {(U8 *) SRV_PROV_NAME_TXT, SRV_CCA_NS_OMA_RESOURCE, SRV_PROV_ROOT_NODE_VAL, SRV_PROV_NE_NAME_NODE_VAL,
     srv_prov_characteristic_ne_name_tag_hdlr,
     srv_prov_ne_name_param_tag_hdlr_mapping_table},

#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

    {NULL, 0xFFFF}
};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_authtype_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_AUTHTYPE_HTTP_BASIC_TXT, SRV_CCA_NS_VAL_HTTP_BASIC},
    {(U8 *) SRV_PROV_AUTHTYPE_HTTP_DIGEST_TXT, SRV_CCA_NS_VAL_HTTP_DIGEST},
    {(U8 *) SRV_PROV_AUTHTYPE_BASIC_TXT, SRV_CCA_NS_VAL_BASIC},
    {(U8 *) SRV_PROV_AUTHTYPE_DIGEST_TXT, SRV_CCA_NS_VAL_DIGEST},
    {(U8 *) SRV_PROV_AUTHTYPE_WTLS_SS_TXT, SRV_CCA_NS_VAL_WTLS_SS},
    {(U8 *) SRV_PROV_AUTHTYPE_CRAM_MD5_TXT, SRV_CCA_NS_VAL_CRAM_MD5},
    {(U8 *) SRV_PROV_AUTHTYPE_DIGEST_MD5_TXT, SRV_CCA_NS_VAL_DIGEST_MD5},
    {(U8 *) SRV_PROV_AUTHTYPE_LOGIN_TXT, SRV_CCA_NS_VAL_LOGIN},
    {(U8 *) SRV_PROV_AUTHTYPE_PLAIN_TXT, SRV_CCA_NS_VAL_PLAIN},
    {(U8 *) SRV_PROV_AUTHTYPE_APOP_TXT, SRV_CCA_NS_VAL_APOP},
    {(U8 *) SRV_PROV_AUTHTYPE_GSSAPI_TXT, SRV_CCA_NS_VAL_GSSAPI},
    {(U8 *) SRV_PROV_AUTHTYPE_KERBEROS_V4_TXT, SRV_CCA_NS_VAL_KERBEROS_V4},
    {(U8 *) SRV_PROV_AUTHTYPE_SKEY_TXT, SRV_CCA_NS_VAL_SKEY},
    {(U8 *) SRV_PROV_AUTHTYPE_PAP_TXT, SRV_CCA_NS_VAL_PAP},
    {(U8 *) SRV_PROV_AUTHTYPE_CHAP_TXT, SRV_CCA_NS_VAL_CHAP},
    {(U8 *) SRV_PROV_AUTHTYPE_MS_CHAP_TXT, SRV_CCA_NS_VAL_CHAP},
    {(U8 *) SRV_PROV_AUTHTYPE_MD5_TXT, SRV_CCA_NS_VAL_MD5},
    {(U8 *) SRV_PROV_AUTHTYPE_X509_TXT, SRV_CCA_NS_VAL_X509},
    {(U8 *) SRV_PROV_AUTHTYPE_SECURID_TXT, SRV_CCA_NS_VAL_SECURID},
    {(U8 *) SRV_PROV_AUTHTYPE_SAFEWORD_TXT, SRV_CCA_NS_VAL_SAFEWORD},
    {(U8 *) SRV_PROV_AUTHTYPE_DIGIPASS_TXT, SRV_CCA_NS_VAL_DIGIPASS},
    {(U8 *) SRV_PROV_AUTHTYPE_HMAC_TXT, SRV_CCA_NS_VAL_HMAC},

    {(U8 *) NULL, 0xffff},
};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_authlevel_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_AUTHLEVEL_APPSRV_TXT, SRV_CCA_NS_VAL_APPSRV},
    {(U8 *) SRV_PROV_AUTHLEVEL_OBEX_TXT, SRV_CCA_NS_VAL_OBEX},
    {(U8 *) SRV_PROV_AUTHLEVEL_CLIENT_TXT, SRV_CCA_NS_VAL_CLIENT},
    {(U8 *) NULL, 0xffff},
};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_authentity_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_AUTHENTITY_AAA_TXT, SRV_CCA_NS_VAL_AAA},
    {(U8 *) SRV_PROV_AUTHENTITY_HA_TXT, SRV_CCA_NS_VAL_HA},
    {(U8 *) NULL, 0xffff},
};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_pushpullenabled_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_PUSHPULL_DISABLED_TXT, SRV_CCA_NS_VAL_DISABLED},
    {(U8 *) SRV_PROV_PUSHPULL_ENABLED_TXT, SRV_CCA_NS_VAL_ENABLED},
    {(U8 *) NULL, 0xffff},
};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_addrtype_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_IPV4_TXT, SRV_CCA_NS_VAL_IPV4},
    {(U8 *) SRV_PROV_IPV6_TXT, SRV_CCA_NS_VAL_IPV6},
    {(U8 *) SRV_PROV_E164_TXT, SRV_CCA_NS_VAL_E164},
    {(U8 *) SRV_PROV_ALPHA_TXT, SRV_CCA_NS_VAL_ALPHA},
    {(U8 *) SRV_PROV_APN_TXT, SRV_CCA_NS_VAL_APN},
    {(U8 *) SRV_PROV_SCODE_TXT, SRV_CCA_NS_VAL_SCODE},
    {(U8 *) SRV_PROV_TETRA_ITSI_TXT, SRV_CCA_NS_VAL_TETRA_ITSI},
    {(U8 *) SRV_PROV_MAN_TXT, SRV_CCA_NS_VAL_MAN},
    {(U8 *) NULL, 0xffff},

};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_port_param_service_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_CL_WSP_TXT, SRV_CCA_NS_VAL_CL_WSP},
    {(U8 *) SRV_PROV_CO_WSP_TXT, SRV_CCA_NS_VAL_CO_WSP},
    {(U8 *) SRV_PROV_CL_SEC_WSP_TXT, SRV_CCA_NS_VAL_CL_SEC_WSP},
    {(U8 *) SRV_PROV_CO_SEC_WSP_TXT, SRV_CCA_NS_VAL_CO_SEC_WSP},
    {(U8 *) SRV_PROV_CO_SEC_WTA_TXT, SRV_CCA_NS_VAL_CO_SEC_WTA},
    {(U8 *) SRV_PROV_CL_SEC_WTA_TXT, SRV_CCA_NS_VAL_CL_SEC_WTA},
    {(U8 *) SRV_PROV_OTA_HTTP_TO_TXT, SRV_CCA_NS_VAL_OTA_HTTP_TO},
    {(U8 *) SRV_PROV_OTA_HTTP_TLS_TO_TXT, SRV_CCA_NS_VAL_OTA_HTTP_TLS_TO},
    {(U8 *) SRV_PROV_OTA_HTTP_PO_TXT, SRV_CCA_NS_VAL_OTA_HTTP_PO},
    {(U8 *) SRV_PROV_OTA_HTTP_TLS_PO_TXT, SRV_CCA_NS_VAL_OTA_HTTP_TLS_PO},
    {(U8 *) SRV_PROV_STARTTLS_TXT, SRV_CCA_NS_VAL_STARTTLS},
    {(U8 *) NULL, 0xffff},

};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_napdef_param_bearer_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_GSM_CSD_TXT, SRV_CCA_NS_VAL_GSM_CSD},
    {(U8 *) SRV_PROV_GSM_GPRS_TXT, SRV_CCA_NS_VAL_GSM_GPRS},
    {(U8 *) SRV_PROV_GSM_USSD_TXT, SRV_CCA_NS_VAL_GSM_USSD},
    {(U8 *) SRV_PROV_GSM_SMS_TXT, SRV_CCA_NS_VAL_GSM_SMS},
    {(U8 *) SRV_PROV_CDMA_SMS_TXT, SRV_CCA_NS_VAL_CDMA_SMS},
    {(U8 *) SRV_PROV_CDMA_CSD_TXT, SRV_CCA_NS_VAL_CDMA_CSD},
    {(U8 *) SRV_PROV_CDMA_PACKET_TXT, SRV_CCA_NS_VAL_CDMA_PACKET},
    {(U8 *) SRV_PROV_ANSI_136_GUTS_TXT, SRV_CCA_NS_VAL_ANSI_136_GUTS},
    {(U8 *) SRV_PROV_ANSI_136_CSD_TXT, SRV_CCA_NS_VAL_ANSI_136_CSD},
    {(U8 *) SRV_PROV_ANSI_136_GPRS_TXT, SRV_CCA_NS_VAL_ANSI_136_GPRS},
    {(U8 *) SRV_PROV_ANSI_136_GHOST_TXT, SRV_CCA_NS_VAL_ANSI_136_GHOST},
    {(U8 *) SRV_PROV_AMPS_CDPD_TXT, SRV_CCA_NS_VAL_AMPS_CDPD},
    {(U8 *) SRV_PROV_PDC_CSD_TXT, SRV_CCA_NS_VAL_PDC_CSD},
    {(U8 *) SRV_PROV_PDC_PACKET_TXT, SRV_CCA_NS_VAL_PDC_PACKET},
    {(U8 *) SRV_PROV_IDEN_SMS_TXT, SRV_CCA_NS_VAL_IDEN_SMS},
    {(U8 *) SRV_PROV_IDEN_CSD_TXT, SRV_CCA_NS_VAL_IDEN_CSD},
    {(U8 *) SRV_PROV_IDEN_PACKET_TXT, SRV_CCA_NS_VAL_IDEN_PACKET},
    {(U8 *) SRV_PROV_FLEX_REFLEX_TXT, SRV_CCA_NS_VAL_FLEX_REFLEX},
    {(U8 *) SRV_PROV_PHS_SMS_TXT, SRV_CCA_NS_VAL_PHS_SMS},
    {(U8 *) SRV_PROV_PHS_CSD_TXT, SRV_CCA_NS_VAL_PHS_CSD},
    {(U8 *) SRV_PROV_TETRA_SDS_TXT, SRV_CCA_NS_VAL_TETRA_SDS},
    {(U8 *) SRV_PROV_TETRA_PACKET_TXT, SRV_CCA_NS_VAL_TETRA_PACKET},
    {(U8 *) SRV_PROV_MOBITEX_MPAK_TXT, SRV_CCA_NS_VAL_MOBITEX_MPAK},
    {(U8 *) SRV_PROV_CDMA2000_1X_SIMPLE_IP_TXT, SRV_CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP},
    {(U8 *) SRV_PROV_CDMA2000_1X_MOBILE_IP_TXT, SRV_CCA_NS_VAL_CDMA2000_1X_MOBILE_IP},
#ifdef __PROV_NOKIA_OTA_SUPPORT__

    {(U8 *) SRV_PROV_NE_GSM_CSD_TXT, SRV_CCA_NS_VAL_GSM_CSD},
    {(U8 *) SRV_PROV_NE_GPRS_TXT, SRV_CCA_NS_VAL_GSM_GPRS},
    {(U8 *) SRV_PROV_NE_GSM_USSD_TXT, SRV_CCA_NS_VAL_GSM_USSD},
    {(U8 *) SRV_PROV_NE_GSM_SMS_TXT, SRV_CCA_NS_VAL_GSM_SMS},
    {(U8 *) SRV_PROV_NE_IS_136_CSD_TXT, SRV_CCA_NS_VAL_ANSI_136_CSD},

#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

    {(U8 *) NULL, 0xffff},

};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_napdef_param_calltype_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_ANALOG_MODEM_TXT, SRV_CCA_NS_VAL_ANALOG_MODEM},
    {(U8 *) SRV_PROV_V120_TXT, SRV_CCA_NS_VAL_V120},
    {(U8 *) SRV_PROV_V110_TXT, SRV_CCA_NS_VAL_V110},
    {(U8 *) SRV_PROV_X31_TXT, SRV_CCA_NS_VAL_X31},
    {(U8 *) SRV_PROV_BIT_TRANSPARENT_TXT, SRV_CCA_NS_VAL_BIT_TRANSPARENT},
    {(U8 *) SRV_PROV_DIRECT_ASYNC_DATA_SERVICE_TXT, SRV_CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE},
#ifdef __PROV_NOKIA_OTA_SUPPORT__

    {(U8 *) SRV_PROV_NE_ANALOGUE_TXT, SRV_CCA_NS_VAL_ANALOG_MODEM},
    {(U8 *) SRV_PROV_NE_ISDN_TXT, SRV_CCA_NS_VAL_V120},

#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

    {(U8 *) NULL, 0xffff},

};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_app_param_cm_and_rm_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_APP_MODE_RESTRICTED_TXT, SRV_CCA_NS_VAL_RESTRICTED},
    {(U8 *) SRV_PROV_APP_MODE_WARNING_TXT, SRV_CCA_NS_VAL_WARNING},
    {(U8 *) SRV_PROV_APP_MODE_FREE_TXT, SRV_CCA_NS_VAL_FREE},

    {(U8 *) NULL, 0xffff},
};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_app_param_ma_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_APP_MA_VALUE_ENABLE_TXT, SRV_CCA_NS_VAL_ENABLE},
    {(U8 *) SRV_PROV_APP_MA_VALUE_DISABLE_TXT, SRV_CCA_NS_VAL_DISABLE},
    {(U8 *) SRV_PROV_APP_MA_VALUE_LOCKED_TXT, SRV_CCA_NS_VAL_LOCKED},

    {(U8 *) NULL, 0xffff},
};

#ifdef __PROV_NOKIA_OTA_SUPPORT__

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_ne_addrtype_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_NE_IPV4_TXT, SRV_CCA_NS_VAL_IPV4},
    {(U8 *) SRV_PROV_NE_MSISDN_NO_TXT, SRV_CCA_NS_VAL_E164},
    {(U8 *) NULL, 0xffff},

};

static const srv_prov_convert_str_to_cca_enum_struct srv_prov_param_ne_logintype_str_enum_table[] = 
{
    {(U8 *) SRV_PROV_NE_LOGINTYPE_AUTOMATIC_TXT, SRV_CCA_NS_VAL_AUTOMATIC},
    {(U8 *) SRV_PROV_NE_LOGINTYPE_MANUAL_TXT, SRV_CCA_NS_VAL_MANUAL},
    {(U8 *) NULL, 0xffff},
};

#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

static srv_prov_curr_ccanode_characteristic_tag_hdlr_st
    g_srv_prov_cur_cca_node_char_taghdlr[SRV_PROV_MAX_CCA_NODE_LEVEL];


/*****************************************************************************
 * FUNCTION
 *  srv_prov_context_initialize
 * DESCRIPTION
 *  Initializes prov context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_context_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_prov_ctxt.err_code = SRV_PROV_OK;
    g_srv_prov_ctxt.cur_node_level = 0;
    g_srv_prov_ctxt.unnkown_tag_count = 0;
    g_srv_prov_ctxt.valid_prov_tag = MMI_FALSE;
    g_srv_prov_ctxt.parent_parent_id = 0x00;
    g_srv_prov_ctxt.node_parent_id = SRV_PROV_ROOT_NODE_VAL;
    memset(g_srv_prov_cur_cca_node_char_taghdlr, 0, sizeof(g_srv_prov_cur_cca_node_char_taghdlr));
    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].par_cca_node_h = 0;
    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h = 0;
    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].characteristic_tag_hdlr =
        srv_prov_characteristic_root_tag_hdlr;
    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr =
        srv_prov_root_param_tag_hdlr_mapping_table;

    /* MAUI_01175262 starts */
#ifdef __PROV_NOKIA_OTA_SUPPORT__
    g_srv_prov_ctxt.napauthinfo_node = 0;
    g_srv_prov_ctxt.pxauthinfo_node = 0;
    g_srv_prov_ctxt.proxy_node = 0;
#endif
    /* MAUI_01175262 ends */

    g_srv_prov_ctxt.i_sec_value = -1;   /* Default NIL value for sec */

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__

    memset(g_srv_prov_ctxt.s_mac, 0, sizeof(g_srv_prov_ctxt.s_mac));
    g_srv_prov_ctxt.i_mac_len = SRV_PROV_MAX_MAC_CHARS; /* Default is max as it will change only in case of USERPINMAC dynamically */
    memset(g_srv_prov_ctxt.s_imsi, 0, sizeof(g_srv_prov_ctxt.s_imsi));

#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

#ifdef __PROV_NOKIA_OTA_SUPPORT__
    memset(g_srv_prov_ctxt.first_proxy_id, 0, sizeof(g_srv_prov_ctxt.first_proxy_id));
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_free_memory
 * DESCRIPTION
 *  This function freed the allocated memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_prov_ctxt.sibling_node_list_p)
    {

        temp_node = (srv_prov_cca_node_hdlr_st*) g_srv_prov_ctxt.sibling_node_list_p;
        g_srv_prov_ctxt.sibling_node_list_p =
            (srv_prov_cca_node_hdlr_st*) g_srv_prov_ctxt.sibling_node_list_p->node_hdlr_next;
        srv_prov_mem_free(temp_node);
        temp_node = NULL;
    }
    srv_prov_free_application_param_tonapid_value();
#ifdef __PROV_NOKIA_OTA_SUPPORT__

    while (g_srv_prov_ctxt.cca_proxy_node_list_p)
    {

        temp_node = (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_proxy_node_list_p;
        g_srv_prov_ctxt.cca_proxy_node_list_p =
            (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_proxy_node_list_p->node_next;
        srv_prov_mem_free(temp_node);
        temp_node = NULL;
    }
    while (g_srv_prov_ctxt.cca_resorce_node_list_p)
    {

        temp_node = (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_resorce_node_list_p;
        g_srv_prov_ctxt.cca_resorce_node_list_p =
            (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_resorce_node_list_p->node_next;
        srv_prov_mem_free(temp_node);
        temp_node = NULL;
    }
    while (g_srv_prov_ctxt.cca_brw_app_node_list_p)
    {

        temp_node = (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_brw_app_node_list_p;
        g_srv_prov_ctxt.cca_brw_app_node_list_p =
            (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_brw_app_node_list_p->node_next;
        srv_prov_mem_free(temp_node);
        temp_node = NULL;
    }
    while (g_srv_prov_ctxt.cca_mms_app_node_list_p)
    {

        temp_node = (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_mms_app_node_list_p;
        g_srv_prov_ctxt.cca_mms_app_node_list_p =
            (srv_prov_cca_ne_node_list_struct*) g_srv_prov_ctxt.cca_mms_app_node_list_p->node_next;
        srv_prov_mem_free(temp_node);
        temp_node = NULL;
    }
    if (g_srv_prov_ctxt.setting_name)
    {
        srv_prov_mem_free(g_srv_prov_ctxt.setting_name);
        g_srv_prov_ctxt.setting_name = NULL;
    }
    if (g_srv_prov_ctxt.app_url)
    {
        srv_prov_mem_free(g_srv_prov_ctxt.app_url);
        g_srv_prov_ctxt.app_url = NULL;
    }

#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_handle_provisioning_setting
 * DESCRIPTION
 *  handle provisioning setting
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_handle_provisioning_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 root;
    S32 hdoc_config;
    SRV_PROV_RETCODE ret_code;
    SRV_PROV_RETCODE par_ret = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_HANDLE_PROVISIONING_SETTING_ENTER);

    root = srv_cca_doc_node_new(SRV_CCA_NS_DOCROOT);
    if (!root)
    {
        return SRV_PROV_ERR;
    }
    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h = root;

    par_ret = srv_prov_wbxml_parser_handler();

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_WBXML_PARSER_RETURNED, par_ret);

    if (g_srv_prov_ctxt.valid_prov_tag && (g_srv_prov_ctxt.err_code == SRV_PROV_UNKNOWN_TAG))
    {
        g_srv_prov_ctxt.err_code = SRV_PROV_OK;
    }

    if (g_srv_prov_ctxt.err_code == SRV_PROV_OK && par_ret != SRV_PROV_OK)
    {
        g_srv_prov_ctxt.err_code = par_ret;
    }

    ret_code = srv_prov_root_end_tag_hdlr(g_srv_prov_ctxt.err_code);
#ifdef __PROV_NOKIA_OTA_SUPPORT__
    if (ret_code == SRV_PROV_OK && g_srv_prov_ctxt.prov_type == SRV_PROV_OTA_TYPE_WAP)
    {
        ret_code = srv_prov_ne_post_parsing_operation(root);
    }
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 
    ret_code = srv_prov_fix_cca_doc(root, ret_code);
    if (ret_code != SRV_PROV_OK)
    {
        srv_cca_doc_node_free(root);
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_FIX_CCA_DOC_ERROR, ret_code);
        goto error;
    }

    ret_code = srv_prov_create_dependency_relationship(root, ret_code);
    if (ret_code != SRV_PROV_OK)
    {
        srv_cca_doc_node_free(root);
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CREATE_DEPENDENCY_ERROR, ret_code);
        goto error;
    }

    srv_cca_oma_sort_new_doc(root);
    hdoc_config = srv_cca_doc_new(root);
    if (!hdoc_config)
    {
        ret_code = SRV_PROV_MEM_FULL;
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CONFIG_DOC_CREATE_ERROR, ret_code);
        srv_cca_doc_node_free(root);
        goto error;
    }
    srv_prov_cca_new_doc_ind_req(hdoc_config);

  error:
    srv_prov_free_memory();

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_HANDLE_PROVISIONING_SETTING_EXIT);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_root_end_tag_hdlr
 * DESCRIPTION
 *  Handles the end tag of the root.
 * PARAMETERS
 *  retcode     [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_root_end_tag_hdlr(SRV_PROV_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_ROOT_END_TAG_HDLR_ENTER);

    if (retcode != SRV_PROV_OK)
    {
        return retcode;
    }
    while (g_srv_prov_ctxt.cur_node_level > 0)
    {
        retcode = srv_prov_characteristic_end_tag_hdlr(g_srv_prov_ctxt.cur_node_level);
        g_srv_prov_ctxt.cur_node_level--;
    }

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_ROOT_END_TAG_HDLR_EXIT);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_end_tag_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur_node_level      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_end_tag_hdlr(U8 cur_node_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CHARACTERISTIC_END_TAG_HDLR_ENTER);

    retcode =
        g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level].
        characteristic_tag_hdlr(
            &g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h,
            SRV_PROV_CHARACTERISTIC_END);
    /* retcode return error if any must present field is absent from the node */
    srv_prov_release_sibling_node_from_node_list(
        &g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h,
        retcode);

    if (retcode == SRV_PROV_OK)
    {
        retcode = srv_prov_attach_node_to_sibling_node_list(
                    g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h,
                    g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level].par_cca_node_h);
    }
    else
    {
        /* Release the node and its child node from cca node tree if it is not released */
        if (g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h)
        {
            srv_cca_doc_node_free(g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h);
        }
    }
    memset(
        &g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level],
        0,
        sizeof(g_srv_prov_cur_cca_node_char_taghdlr[cur_node_level]));

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_oma_get_cca_nodeid
 * DESCRIPTION
 *  Creates the unique node id for CCA node.
 * PARAMETERS
 *  nodeid      [IN]        IN\OUT
 * RETURNS
 *  S8*
 *****************************************************************************/
S8 *srv_prov_oma_get_cca_nodeid(S8 *nodeid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 cca_nodeid = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nodeid[0] = cca_nodeid;
    nodeid[1] = 0;

    cca_nodeid++;
    if (cca_nodeid > SRV_PROV_MAX_CCA_NODEID_ITTR)
    {
        cca_nodeid = 1;
    }
    return nodeid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_cca_nodeid
 * DESCRIPTION
 *  Add nodeid to CCA nodes.
 * PARAMETERS
 *  crtnode_h           [IN]        
 *  chartagname         [?]         
 *  charTagName(?)      [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_cca_nodeid(S32 crtnode_h, U16 *chartagname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    S8 nodeid[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((strcmp((S8*) SRV_PROV_PXPHYSICAL_TXT, (S8*) chartagname) == 0) ||
        (strcmp((S8*) SRV_PROV_APPLICATION_TXT, (S8*) chartagname) == 0) ||
        (strcmp((S8*) SRV_PROV_NAPDEF_TXT, (S8*) chartagname) == 0)
#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
        || (strcmp((S8*) SRV_PROV_PX_SIP_TXT, (S8*) chartagname) == 0)
#endif /* #if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */
#ifdef __PROV_NOKIA_OTA_SUPPORT__
        || (strcmp((S8*) SRV_PROV_NE_ADDRESS_TXT, (S8*) chartagname) == 0)
        || (strcmp((S8*) SRV_PROV_NE_MMSURL_TXT, (S8*) chartagname) == 0)
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 
        )
    {
        if (srv_cca_doc_nodedata_add_str(crtnode_h, SRV_CCA_NS_NODEID, srv_prov_oma_get_cca_nodeid(nodeid)) ==
            SRV_CCA_STATUS_MEMFULL)
        {
            retcode = SRV_PROV_MEM_FULL;
        }
    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_handle_characteristic_end_tag_value
 * DESCRIPTION
 *  handle unknown characteristic tag
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 *  node_h          [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_handle_characteristic_end_tag_value(const S8 *tag_str, const S8 *tag_str_val, S32 node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PROV_NOKIA_OTA_SUPPORT__
    if (strcmp((S8*) SRV_PROV_NE_MMSURL_TXT, tag_str) == 0)
    {
        retcode = srv_prov_add_nodedata_str_to_cca_node(node_h, SRV_CCA_NS_OMA_ADDR, (U16*) tag_str_val);
    }
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_handle_unknown_characteristic_tag
 * DESCRIPTION
 *  handle unknown characteristic tag
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 *  node_id         [IN]        
 *  retcode         [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_handle_unknown_characteristic_tag(
                    const S8 *tag_str,
                    const S8 *tag_str_val,
                    S32 node_id,
                    SRV_PROV_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] Unknown Tag = %s", (S8*) tag_str);

    if (retcode != SRV_PROV_OK)
    {
        return retcode;
    }
    else
    {
        ASSERT(tag_str);
        retcode = SRV_PROV_UNKNOWN_TAG;

    #if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
        if (g_srv_prov_ctxt.node_parent_id & (SRV_PROV_ACCESS_POINT_NODE_VAL | SRV_PROV_AD_HOC_NODE_VAL))
        {
            S32 crtnode_h;
            S8 nodeid[2];

            crtnode_h = srv_cca_doc_node_new_and_attach(
                            SRV_CCA_NS_OMADMP_PROFILE,
                            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h);
            if (!crtnode_h)
            {
                return SRV_PROV_MEM_FULL;
            }

            g_srv_prov_ctxt.cur_node_level++;
            if (g_srv_prov_ctxt.cur_node_level >= SRV_PROV_MAX_CCA_NODE_LEVEL)
            {
                return SRV_PROV_MEM_FULL;
                /* ASSERT(0); */
            }
            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].par_cca_node_h =
                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level - 1].crt_cca_node_h;
            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h = crtnode_h;

            g_srv_prov_ctxt.parent_parent_id = g_srv_prov_ctxt.node_parent_id;
            g_srv_prov_ctxt.node_parent_id |= SRV_PROV_WIFI_PROFILE_NODE_VAL;

            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].characteristic_tag_hdlr =
                srv_prov_characteristic_wifi_profile_tag_hdlr;
            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr =
                srv_prov_wifi_profile_param_tag_hdlr_mapping_table;
            if (srv_cca_doc_nodedata_add_str(crtnode_h, SRV_CCA_NS_NODEID, srv_prov_oma_get_cca_nodeid(nodeid)) ==
                SRV_CCA_STATUS_MEMFULL)
            {
                retcode = SRV_PROV_MEM_FULL;
                return retcode;
            }
            retcode = srv_prov_add_nodedata_str_to_cca_node(crtnode_h, SRV_CCA_NS_OMADMP_SSID, (U16*) tag_str);
        }
    #endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */ 
    #ifdef __PROV_NOKIA_OTA_SUPPORT__
        /* Only first url to be considered */
        if ((SRV_PROV_OTA_TYPE_WAP == g_srv_prov_ctxt.prov_type) &&
            (strcmp((S8*) SRV_PROV_NE_URL_TXT, tag_str) == 0) && (!g_srv_prov_ctxt.app_url))
        {
            if (srv_prov_copy_utf8_str((U8 **) & g_srv_prov_ctxt.app_url, (U8*) tag_str_val) == SRV_PROV_MEM_FULL)
            {
                return SRV_PROV_MEM_FULL;
            }
        }
    #endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 
    }

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_HANDLE_UNKNOWN_CHARACTERISTIC_TAG_EXIT);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_cca_characteristic_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 *  node_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_cca_characteristic_node(const S8 *tag_str, const S8 *tag_str_val, S32 node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 crtnode_h;
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    U8 count = 0;
    MMI_BOOL unknowntag = MMI_TRUE;
    const srv_prov_characteristic_tag_hdlr_struct * prov_characteristic_tag_hdlr_mapping_table = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_ADD_CCA_CHARACTERISTIC_NODE_ENTER);

    if (tag_str == NULL)
    {
        return SRV_PROV_UNKNOWN_TAG;
    }
    if (g_srv_prov_ctxt.prov_type == SRV_PROV_OTA_TYPE_OMA)
    {
        prov_characteristic_tag_hdlr_mapping_table = srv_prov_oma_characteristic_tag_hdlr_mapping_table;
    }
    else if (g_srv_prov_ctxt.prov_type == SRV_PROV_OTA_TYPE_WAP)
    {
        prov_characteristic_tag_hdlr_mapping_table = srv_prov_non_oma_characteristic_tag_hdlr_mapping_table;
    }
    ASSERT(prov_characteristic_tag_hdlr_mapping_table);
    while (prov_characteristic_tag_hdlr_mapping_table[count].characterestic != NULL)
    {
        if (strcmp((S8*) prov_characteristic_tag_hdlr_mapping_table[count].characterestic, tag_str) == 0)
        {
            if ((g_srv_prov_ctxt.node_parent_id & (~g_srv_prov_ctxt.parent_parent_id))
                & prov_characteristic_tag_hdlr_mapping_table[count].src_parent_node_id)
            {
                retcode = prov_characteristic_tag_hdlr_mapping_table[count].
                    characteristic_tag_hdlr(
                        &g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h,
                        SRV_PROV_CHARACTERISTIC_START);
                if (retcode == SRV_PROV_MEM_FULL)
                {
                    return retcode;
                }
                else if (retcode != SRV_PROV_CCA_DUP_NODE_CREATED)
                {
                    crtnode_h = srv_cca_doc_node_new_and_attach(
                                    prov_characteristic_tag_hdlr_mapping_table[count].cca_node_id,
                                    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h);
                    if (!crtnode_h)
                    {
                        return SRV_PROV_MEM_FULL;
                    }

                    g_srv_prov_ctxt.cur_node_level++;
                    if (g_srv_prov_ctxt.cur_node_level >= SRV_PROV_MAX_CCA_NODE_LEVEL)
                    {
                        ASSERT(0);
                    }
                    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].par_cca_node_h =
                        g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level - 1].crt_cca_node_h;
                    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h = crtnode_h;
                }
                g_srv_prov_ctxt.parent_parent_id = g_srv_prov_ctxt.node_parent_id;
                g_srv_prov_ctxt.node_parent_id |= prov_characteristic_tag_hdlr_mapping_table[count].src_node_id;

                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].characteristic_tag_hdlr =
                    prov_characteristic_tag_hdlr_mapping_table[count].characteristic_tag_hdlr;
                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr =
                    prov_characteristic_tag_hdlr_mapping_table[count].char_param_tag_map_hdlr;
                retcode = srv_prov_add_cca_nodeid(
                            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h,
                            (U16*) tag_str);
                unknowntag = MMI_FALSE;
                g_srv_prov_ctxt.valid_prov_tag = MMI_TRUE;
                if ((g_srv_prov_ctxt.prov_type == SRV_PROV_OTA_TYPE_WAP) && (retcode == SRV_PROV_OK))
                {
                    retcode = srv_prov_handle_characteristic_end_tag_value(
                                tag_str,
                                tag_str_val,
                                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h);
                }
                break;
            }
        }
        count++;
    }
    if (unknowntag)
    {
        retcode = srv_prov_handle_unknown_characteristic_tag(tag_str, tag_str_val, node_id, retcode);
    }

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_ADD_CCA_CHARACTERISTIC_NODE_EXIT);

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_cca_param_value
 * DESCRIPTION
 *  Adds the provising parameter value to CCA nodes.
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_cca_param_value(const S8 *tag_str, const S8 *tag_str_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    U8 count = 0;
    U16 ret_value = 0;  /* it stores the enum value return by the function */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tag_str == NULL)
    {
        return retcode;
    }
    while ((g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr) && (g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].param !=
           NULL))
    {
        if (strcmp
            ((S8*) g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].
             param, tag_str) == 0)
        {

            if (g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].
                param_tag_hdlr)
            {
                retcode =
                    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].
                    param_tag_hdlr(
                        (U16*) tag_str_val,
                        &g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h,
                        (U16*) & ret_value);
                if (retcode != SRV_PROV_OK)
                {
                    return retcode;
                }
            }

            switch (g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].
                    convtype)
            {
                case SRV_PROV_CCA_CONV_TYPE_STR:
                {
                    retcode = srv_prov_add_nodedata_str_to_cca_node(
                                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h,
                                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].cca_symbol,
                                (U16*) tag_str_val);
                    break;
                }
                case SRV_PROV_CCA_CONV_TYPE_ENUM_FROM_STR:
                {
                    retcode = srv_prov_add_nodedata_enum_to_cca_node(
                                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h,
                                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].cca_symbol,
                                ret_value);
                    break;
                }
                case SRV_PROV_CCA_CONV_TYPE_INT:
                {
                    retcode = srv_prov_add_nodedata_int_to_cca_node(
                                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h,
                                g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].char_param_tag_map_hdlr[count].cca_symbol,
                                (U16*) tag_str_val);

                    break;
                }
                default:

                    break;
            }
            break;
        }
        count++;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_appauth_param_authlevel_tag_hdlr
 * DESCRIPTION
 *  Handles authlevele param of appauth characteristic.
 * PARAMETERS
 *  attr_value      [IN]        
 *  root            [IN]        
 *  ret_value       [?]         [IN\OUT]
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_appauth_param_authlevel_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_authlevel_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_application_param_tonapid_tag_hdlr
 * DESCRIPTION
 *  Handles tonapid param of application characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_application_param_tonapid_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    S8 nodeid[2];
    U8 *out_buffer = NULL;
    S8 *out_new_pxy_id = NULL;
    S32 vir_pxy_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_buffer = (U8*) attr_value;
    if (!(attr_value))
    {
        /* NULL value recieved, setting to blank as NULL crashes in cca. */
        out_buffer = (U8*) "" ;
    }
    /* If value already exist then don't add virtual proxy */
    retcode = srv_prov_check_dup_application_param_tonapid_value(out_buffer);
    if (retcode == SRV_PROV_OK)
    {
        vir_pxy_node = srv_cca_oma_generate_virtual_proxy_node(
                        (const S8*)(out_buffer),
                        srv_prov_oma_get_cca_nodeid(nodeid),
                        &out_new_pxy_id);
        if (!vir_pxy_node)
        {
            retcode = SRV_PROV_MEM_FULL;
        }
        else
        {
            /* Free CCA doc root never be zeo */
            ASSERT(g_srv_prov_cur_cca_node_char_taghdlr[0].crt_cca_node_h);
            if (srv_cca_doc_node_attach(vir_pxy_node, g_srv_prov_cur_cca_node_char_taghdlr[0].crt_cca_node_h)
                != SRV_CCA_STATUS_OK)
            {
                ASSERT(0);
            }

            if (srv_cca_doc_nodedata_add_str(*root, SRV_CCA_NS_OMA_TO_PROXY, out_new_pxy_id) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }

            /* OTA Whitelist */
            if (srv_cca_doc_nodedata_add_str(*root, SRV_CCA_NS_OMA_TO_NAPID, (S8*) attr_value) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }
        }
    }
    else if (retcode == SRV_PROV_ERR)
    {
        retcode = SRV_PROV_OK;
    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_napauthinfo_param_authentity_tag_hdlr
 * DESCRIPTION
 *  Handles authentity param of napauthinfo characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_napauthinfo_param_authentity_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_authentity_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_napdef_param_bearer_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_napdef_param_bearer_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_napdef_param_bearer_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_napdef_param_calltype_tag_hdlr
 * DESCRIPTION
 *  Handles calltype param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_napdef_param_calltype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_napdef_param_calltype_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_napdef_param_callspeed_tag_hdlr
 * DESCRIPTION
 *  Handles callspeed param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
static SRV_PROV_RETCODE srv_prov_napdef_param_callspeed_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(attr_value))
    {
        return retcode ;
    }
    if ((strcmp((S8*) attr_value, (S8*) SRV_PROV_CALLSPEED_AUTOBAUDING_TXT) == 0)
#ifdef __PROV_NOKIA_OTA_SUPPORT__
        || (strcmp((S8*) attr_value, (S8*) SRV_PROV_NE_CALLSPEED_AUTO_TXT) == 0)
#endif 
        )
    {
        /* Changing attr_value as later API does atoi, which will fail. */
        sprintf((S8*) attr_value, "%d", (U16) SRV_CCA_NS_VAL_AUTOBAUDING);
    }
    /* As integer value, Nothing to be done */

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_port_param_service_tag_hdlr
 * DESCRIPTION
 *  Handles service param of port characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_port_param_service_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_port_param_service_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_param_authtype_tag_hdlr
 * DESCRIPTION
 *  Handles authtype param of characteristics.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_param_authtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_authtype_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_proxy_param_pushpullenabled_tag_hdlr
 * DESCRIPTION
 *  Handles pushpullenabled param of proxy characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_proxy_param_pushpullenabled_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_pushpullenabled_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_param_addrtype_tag_hdlr
 * DESCRIPTION
 *  Handles addrtype param of characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_param_addrtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_addrtype_str_enum_table);
    return retcode;
}

#if 0   /* currently not in use */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_root_tag_hdlr
 * DESCRIPTION
 *  Handles root characteristic tag.
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_root_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:

            g_srv_prov_ctxt.parent_parent_id &= ~0x00;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_pxphysical_tag_hdlr
 * DESCRIPTION
 *  Handles pxphysical characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_pxphysical_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    S32 crtnode_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If status is SRV_PROV_CHARACTERISTIC_START then the input node is parent node otherwise current node */
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:

            crtnode_h = mmi_doc_duplicate_node(g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].
                                               crt_cca_node_h);
            if (crtnode_h)
            {
                if (srv_cca_doc_node_attach
                    (crtnode_h,
                     g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level - 1].crt_cca_node_h) ==
                    SRV_CCA_STATUS_OK)
                {
                    g_srv_prov_ctxt.cur_node_level++;
                    if (g_srv_prov_ctxt.cur_node_level >= SRV_PROV_MAX_CCA_NODE_LEVEL)
                    {
                        ASSERT(0);
                    }
                    /* the parent node will be the same as that of the sibling node */
                    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].par_cca_node_h =
                        g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level - 1].par_cca_node_h;
                    g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h = crtnode_h;
                    retcode = srv_prov_add_sibling_node_to_node_list(crtnode_h, *root);
                    if (retcode == SRV_PROV_OK)
                    {
                        retcode = SRV_PROV_CCA_DUP_NODE_CREATED;
                    }
                }
                else
                {
                    ASSERT(0);
                }
            }
            else
            {
                retcode = SRV_PROV_MEM_FULL;
            }
            break;

        case SRV_PROV_CHARACTERISTIC_END:

            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_PXLOGICAL_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_PXPHYSICAL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_pxlogical_tag_hdlr
 * DESCRIPTION
 *  Handles pxlogical characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_pxlogical_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /* S8 loop_count; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_PXLOGICAL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_port_tag_hdlr
 * DESCRIPTION
 *  Handles port characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_port_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    S32 crtnode_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:

            if (g_srv_prov_ctxt.node_parent_id & SRV_PROV_APPADDR_NODE_VAL)
            {
                crtnode_h = mmi_doc_duplicate_node(g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].
                                                   crt_cca_node_h);
                if (crtnode_h)
                {
                    if (srv_cca_doc_node_attach(
                            crtnode_h,
                            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level - 1].crt_cca_node_h) ==
                        SRV_CCA_STATUS_OK)
                    {
                        g_srv_prov_ctxt.cur_node_level++;
                        if (g_srv_prov_ctxt.cur_node_level >= SRV_PROV_MAX_CCA_NODE_LEVEL)
                        {
                            ASSERT(0);
                        }
                        /* the parent node will be the same as that of the sibling node */
                        g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].par_cca_node_h =
                            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level - 1].par_cca_node_h;
                        g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h = crtnode_h;
                        retcode = srv_prov_add_sibling_node_to_node_list(crtnode_h, *root);
                        if (retcode == SRV_PROV_OK)
                        {
                            retcode = SRV_PROV_CCA_DUP_NODE_CREATED;
                        }

                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                else
                {
                    retcode = SRV_PROV_MEM_FULL;
                }
            }
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &=
                ~(SRV_PROV_PXLOGICAL_NODE_VAL | SRV_PROV_PXPHYSICAL_NODE_VAL | SRV_PROV_APPADDR_NODE_VAL);
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_PORT_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_pxauthinfo_tag_hdlr
 * DESCRIPTION
 *  Handles pxauthinfo characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_pxauthinfo_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_PXLOGICAL_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_PXAUTHINFO_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_application_tag_hdlr
 * DESCRIPTION
 *  Handles application characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_application_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:

            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_APPLICATION_NODE_VAL;
            /* srv_prov_check_dup_application_param_tonapid_value(NULL); */
            srv_prov_free_application_param_tonapid_value();
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_resource_tag_hdlr
 * DESCRIPTION
 *  Handles resource characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_resource_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_APPLICATION_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_RESOURCE_NODE_VAL;

            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_appaddr_tag_hdlr
 * DESCRIPTION
 *  Handles appaddr characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_appaddr_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_APPLICATION_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_APPADDR_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_appauth_tag_hdlr
 * DESCRIPTION
 *  Handles appauth characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_appauth_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_APPLICATION_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_APPAUTH_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_bootstrap_tag_hdlr
 * DESCRIPTION
 *  Handles bootstrap characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_bootstrap_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_BOOTSTRAP_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_napdef_tag_hdlr
 * DESCRIPTION
 *  Handles napdef characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_napdef_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NAPDEF_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_napauthinfo_tag_hdlr
 * DESCRIPTION
 *  Handles napauthinfo characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_napauthinfo_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_NAPDEF_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NAPAUTHINFO_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_validity_tag_hdlr
 * DESCRIPTION
 *  Handles validity characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_validity_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_NAPDEF_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_VALIDITY_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_access_tag_hdlr
 * DESCRIPTION
 *  Handles access characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_access_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_ACCESS_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_app_param_cm_and_rm_tag_hdlr
 * DESCRIPTION
 *  Handles CM and RM params of MMS application tag.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_app_param_cm_and_rm_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_app_param_cm_and_rm_str_enum_table);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_app_param_ma_tag_hdlr
 * DESCRIPTION
 *  Handles MA param of MMS application tag.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_app_param_ma_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_app_param_ma_str_enum_table);

    return retcode;
}


#ifdef __PROV_NOKIA_OTA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_ne_address_tag_hdlr
 * DESCRIPTION
 *  Handles NE Address characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_ne_address_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    S32 crtnode_h;
    S8 nodeid[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
        {
            g_srv_prov_ctxt.proxy_node = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PROXY, *root);
            if (!g_srv_prov_ctxt.proxy_node)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_cca_doc_nodedata_add_str
                (g_srv_prov_ctxt.proxy_node, SRV_CCA_NS_NODEID, srv_prov_oma_get_cca_nodeid(nodeid)) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }

            crtnode_h = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_APPLICATION, *root);
            if (!crtnode_h)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_cca_doc_nodedata_add_str(crtnode_h, SRV_CCA_NS_NODEID, srv_prov_oma_get_cca_nodeid(nodeid)) ==
                SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_cca_doc_nodedata_add_str(crtnode_h, SRV_CCA_NS_OMA_APPID, SRV_PROV_OMA_APPID_BRW) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_cca_doc_nodedata_add_str
                (g_srv_prov_ctxt.proxy_node, SRV_CCA_NS_OMA_PROXY_ID,
                 srv_prov_oma_get_cca_nodeid(nodeid)) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }
            if (!strlen((S8*) g_srv_prov_ctxt.first_proxy_id))
            {
                strcpy((S8*) g_srv_prov_ctxt.first_proxy_id, nodeid);
            }
            if (srv_cca_doc_nodedata_add_str(crtnode_h, SRV_CCA_NS_OMA_TO_PROXY, nodeid) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_prov_create_node_list(&g_srv_prov_ctxt.cca_brw_app_node_list_p, crtnode_h) == SRV_PROV_MEM_FULL)
            {
                return SRV_PROV_MEM_FULL;
            }
            if (srv_prov_create_node_list
                (&g_srv_prov_ctxt.cca_proxy_node_list_p, g_srv_prov_ctxt.proxy_node) == SRV_PROV_MEM_FULL)
            {
                return SRV_PROV_MEM_FULL;
            }
        }
            break;

        case SRV_PROV_CHARACTERISTIC_END:
        {

            if (srv_cca_doc_nodedata_add_str(*root, SRV_CCA_NS_OMA_NAPID, srv_prov_oma_get_cca_nodeid(nodeid)) ==
                SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_cca_doc_nodedata_add_str(g_srv_prov_ctxt.proxy_node, SRV_CCA_NS_OMA_TO_NAPID, nodeid) ==
                SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }
            g_srv_prov_ctxt.napauthinfo_node = 0;
            g_srv_prov_ctxt.pxauthinfo_node = 0;
            g_srv_prov_ctxt.proxy_node = 0;
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NE_ADRESS_NODE_VAL;
        }
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_ne_url_tag_hdlr
 * DESCRIPTION
 *  Handles NE URL characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_ne_url_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NE_URL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_ne_mmsurl_tag_hdlr
 * DESCRIPTION
 *  Handles NE MMSURL characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_ne_mmsurl_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            if (srv_cca_doc_nodedata_add_str(*root, SRV_CCA_NS_OMA_APPID, SRV_PROV_OMA_APPID_MMS) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }
            if (srv_prov_create_node_list(&g_srv_prov_ctxt.cca_mms_app_node_list_p, *root) == SRV_PROV_MEM_FULL)
            {
                return SRV_PROV_MEM_FULL;
            }
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NE_MMSURL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_ne_bookmark_tag_hdlr
 * DESCRIPTION
 *  Handles NE bookmark characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_ne_bookmark_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    S32 crtnode_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
        {
            crtnode_h = srv_cca_doc_node_new(SRV_CCA_NS_OMA_RESOURCE);

            if (!crtnode_h)
            {
                return SRV_PROV_MEM_FULL;
            }

            g_srv_prov_ctxt.cur_node_level++;
            if (g_srv_prov_ctxt.cur_node_level >= SRV_PROV_MAX_CCA_NODE_LEVEL)
            {
                ASSERT(0);
            }
            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].par_cca_node_h = 0;
            g_srv_prov_cur_cca_node_char_taghdlr[g_srv_prov_ctxt.cur_node_level].crt_cca_node_h = crtnode_h;

            if (srv_prov_create_node_list(&g_srv_prov_ctxt.cca_resorce_node_list_p, crtnode_h) == SRV_PROV_MEM_FULL)
            {
                return SRV_PROV_MEM_FULL;
            }
            if (retcode == SRV_PROV_OK)
            {
                retcode = SRV_PROV_CCA_DUP_NODE_CREATED;
            }

        }
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NE_BOOKMARK_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_ne_id_tag_hdlr
 * DESCRIPTION
 *  Handles NE ID characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_ne_id_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NE_ID_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_ne_name_tag_hdlr
 * DESCRIPTION
 *  Handles NE name characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_ne_name_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_NE_NAME_NODE_VAL;
            srv_cca_doc_node_free(*root);
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_sms_smsc_tag_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_sms_smsc_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = srv_prov_add_nodedata_enum_to_cca_node(*root, SRV_CCA_NS_OMA_NAP_ADDRTYPE, SRV_CCA_NS_VAL_E164);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_ussd_sevice_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_ussd_sevice_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = srv_prov_add_nodedata_enum_to_cca_node(*root, SRV_CCA_NS_OMA_NAP_ADDRTYPE, SRV_CCA_NS_VAL_SCODE);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_gprs_accesspoint_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_gprs_accesspoint_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = srv_prov_add_nodedata_enum_to_cca_node(*root, SRV_CCA_NS_OMA_NAP_ADDRTYPE, SRV_CCA_NS_VAL_APN);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_ppp_authtype_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_authtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_prov_ctxt.napauthinfo_node)
    {
        g_srv_prov_ctxt.napauthinfo_node = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_NAPAUTHINFO, *root);
        if (!g_srv_prov_ctxt.napauthinfo_node)
        {
            return SRV_PROV_MEM_FULL;
        }

    }
    retcode = srv_prov_add_nodedata_enum_to_cca_node(
                g_srv_prov_ctxt.napauthinfo_node,
                SRV_CCA_NS_OMA_AUTHTYPE,
                srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_authtype_str_enum_table));
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_ppp_logintype_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_logintype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_ne_logintype_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_proxy_logintype_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_logintype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prov_ne_address_param_ppp_logintype_tag_hdlr(attr_value, root, ret_value);
    retcode = srv_prov_add_nodedata_enum_to_cca_node(g_srv_prov_ctxt.proxy_node, SRV_CCA_NS_OMA_LOGINTYPE, *ret_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_ppp_authname_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_authname_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_prov_ctxt.napauthinfo_node)
    {
        g_srv_prov_ctxt.napauthinfo_node = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_NAPAUTHINFO, *root);
        if (!g_srv_prov_ctxt.napauthinfo_node)
        {
            return SRV_PROV_MEM_FULL;
        }

    }
    retcode = srv_prov_add_nodedata_str_to_cca_node(
                g_srv_prov_ctxt.napauthinfo_node,
                SRV_CCA_NS_OMA_AUTHNAME,
                (U16*) attr_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_ppp_authsecret_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_authsecret_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_prov_ctxt.napauthinfo_node)
    {
        g_srv_prov_ctxt.napauthinfo_node = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_NAPAUTHINFO, *root);
        if (!g_srv_prov_ctxt.napauthinfo_node)
        {
            return SRV_PROV_MEM_FULL;
        }

    }
    retcode = srv_prov_add_nodedata_str_to_cca_node(
                g_srv_prov_ctxt.napauthinfo_node,
                SRV_CCA_NS_OMA_AUTHSECRET,
                (U16*) attr_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_proxy_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = srv_prov_add_nodedata_str_to_cca_node(g_srv_prov_ctxt.proxy_node, SRV_CCA_NS_OMA_PXADDR, (U16*) attr_value);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_proxy_type_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_type_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_ne_addrtype_str_enum_table);
    retcode = srv_prov_add_nodedata_enum_to_cca_node(g_srv_prov_ctxt.proxy_node, SRV_CCA_NS_OMA_PXADDRTYPE, *ret_value);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_proxy_authname_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_authname_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_srv_prov_ctxt.proxy_node);
    if (!g_srv_prov_ctxt.pxauthinfo_node)
    {
        g_srv_prov_ctxt.pxauthinfo_node = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PXAUTHINFO, g_srv_prov_ctxt.proxy_node);
        if (!g_srv_prov_ctxt.pxauthinfo_node)
        {
            return SRV_PROV_MEM_FULL;
        }

    }

    retcode = srv_prov_add_nodedata_str_to_cca_node(
                g_srv_prov_ctxt.pxauthinfo_node,
                SRV_CCA_NS_OMA_PXAUTH_ID,
                (U16*) attr_value);

    if (retcode != SRV_PROV_MEM_FULL)
    {
        retcode = srv_prov_add_nodedata_enum_to_cca_node(
                    g_srv_prov_ctxt.pxauthinfo_node,
                    SRV_CCA_NS_OMA_PXAUTH_TYPE,
                    SRV_CCA_NS_VAL_HTTP_BASIC);
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_proxy_authsecret_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_authsecret_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_srv_prov_ctxt.proxy_node);
    if (!g_srv_prov_ctxt.pxauthinfo_node)
    {
        g_srv_prov_ctxt.pxauthinfo_node = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PXAUTHINFO, g_srv_prov_ctxt.proxy_node);
        if (!g_srv_prov_ctxt.pxauthinfo_node)
        {
            return SRV_PROV_MEM_FULL;
        }
    }

    retcode = srv_prov_add_nodedata_str_to_cca_node(
                g_srv_prov_ctxt.pxauthinfo_node,
                SRV_CCA_NS_OMA_PXAUTH_PW,
                (U16*) attr_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_address_param_port_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_address_param_port_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    U16 cca_enum_value;
    S32 value = 0;
    S32 node_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_srv_prov_ctxt.proxy_node);
    node_h = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_PORT, g_srv_prov_ctxt.proxy_node);
    if (!node_h)
    {
        return SRV_PROV_MEM_FULL;
    }
    if (attr_value)
    {
        value = atoi((S8*) attr_value);
    }

    if (srv_prov_add_nodedata_str_to_cca_node(node_h, SRV_CCA_NS_OMA_PORTNBR, attr_value) == SRV_CCA_STATUS_MEMFULL)
    {
        return SRV_PROV_MEM_FULL;
    }
    switch (value)
    {
        case SRV_PROV_NE_PORT_9200:
            cca_enum_value = SRV_CCA_NS_VAL_CL_WSP;
            break;
        case SRV_PROV_NE_PORT_9201:
            cca_enum_value = SRV_CCA_NS_VAL_CO_WSP;
            break;
        case SRV_PROV_NE_PORT_9202:
            cca_enum_value = SRV_CCA_NS_VAL_CL_SEC_WSP;
            break;
        case SRV_PROV_NE_PORT_9203:
            cca_enum_value = SRV_CCA_NS_VAL_CO_SEC_WSP;
            break;
        default:
            cca_enum_value = SRV_CCA_NS_VAL_OTA_HTTP_TO;
    }

    if (srv_cca_doc_nodedata_add_int(node_h, SRV_CCA_NS_OMA_SERVICE, cca_enum_value) == SRV_CCA_STATUS_MEMFULL)
    {
        return SRV_PROV_MEM_FULL;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_name_param_name_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_name_param_name_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_prov_ctxt.setting_name)
    {
    if (srv_prov_copy_utf8_str((U8 **) & g_srv_prov_ctxt.setting_name, (U8*) attr_value) == SRV_PROV_MEM_FULL)
    {
        return SRV_PROV_MEM_FULL;
    }
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_create_node_list
 * DESCRIPTION
 *  Creare link list.
 * PARAMETERS
 *  head        [IN]        
 *  node_h      [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_create_node_list(srv_prov_cca_ne_node_list_struct **head, S32 node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    srv_prov_cca_ne_node_list_struct *temp_node = NULL;
    srv_prov_cca_ne_node_list_struct *new_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node = srv_prov_mem_alloc(sizeof(srv_prov_cca_ne_node_list_struct));
    if (NULL == new_node)
    {
        retcode = SRV_PROV_MEM_FULL;
        return retcode;
    }
    new_node->node_h = node_h;
    new_node->node_next = NULL;

    if (*head)
    {
        temp_node = *head;
        while (temp_node->node_next != NULL)
        {
            temp_node = (srv_prov_cca_ne_node_list_struct*) temp_node->node_next;
        }

        temp_node->node_next = new_node;
    }
    else    /* In case of first node */
    {
        *head = new_node;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_ne_post_parsing_operation
 * DESCRIPTION
 *  Perform post parsing operation.
 * PARAMETERS
 *  root_h      [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_ne_post_parsing_operation(S32 root_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 res_node_h = 0;
    S32 crtnode_h = 0;
    S8 nodeid[2];
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    srv_prov_cca_ne_node_list_struct *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Fill TO_PROXY and NAME param for mms applications */
    if (g_srv_prov_ctxt.cca_mms_app_node_list_p)
    {
        temp_node = g_srv_prov_ctxt.cca_mms_app_node_list_p;
        while (temp_node != NULL)
        {
            if (strlen((S8*) g_srv_prov_ctxt.first_proxy_id))
            {
                if (srv_cca_doc_nodedata_add_str
                    (temp_node->node_h, SRV_CCA_NS_OMA_TO_PROXY,
                     (const S8*)g_srv_prov_ctxt.first_proxy_id) == SRV_CCA_STATUS_MEMFULL)
                {
                    return SRV_PROV_MEM_FULL;
                }
            }
            if (g_srv_prov_ctxt.setting_name)
            {
                if (srv_cca_doc_nodedata_add_str
                    (temp_node->node_h, SRV_CCA_NS_OMA_NAME,
                     (const S8*)g_srv_prov_ctxt.setting_name) == SRV_CCA_STATUS_MEMFULL)
                {
                    return SRV_PROV_MEM_FULL;
                }
            }
            temp_node = (srv_prov_cca_ne_node_list_struct*) temp_node->node_next;
        }
    }
    /* Attach all the resource nodes to first application noew */
    if (g_srv_prov_ctxt.cca_resorce_node_list_p)
    {
        temp_node = g_srv_prov_ctxt.cca_resorce_node_list_p;
        if (g_srv_prov_ctxt.cca_brw_app_node_list_p)
        {
            crtnode_h = g_srv_prov_ctxt.cca_brw_app_node_list_p->node_h;
        }
        else    /* In case of no application node */
        {
            crtnode_h = srv_cca_doc_node_new_and_attach(SRV_CCA_NS_OMA_APPLICATION, root_h);
            if (!crtnode_h)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_cca_doc_nodedata_add_str(crtnode_h, SRV_CCA_NS_NODEID, srv_prov_oma_get_cca_nodeid(nodeid)) ==
                SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }

            if (srv_cca_doc_nodedata_add_str(crtnode_h, SRV_CCA_NS_OMA_APPID, SRV_PROV_OMA_APPID_BRW) == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }
        }
        while (temp_node != NULL)
        {
            if (srv_cca_doc_node_attach(temp_node->node_h, crtnode_h) != SRV_CCA_STATUS_OK)
            {
                ASSERT(0);
            }
            temp_node = (srv_prov_cca_ne_node_list_struct*) temp_node->node_next;
        }
    }

    if (g_srv_prov_ctxt.cca_brw_app_node_list_p)
    {
        /* Create a resource node for a homepage */
        if (g_srv_prov_ctxt.app_url)
        {
            res_node_h = srv_cca_doc_node_new(SRV_CCA_NS_OMA_RESOURCE);
            if (!res_node_h)
            {
                return SRV_PROV_MEM_FULL;
            }
            if (srv_cca_doc_nodedata_add_str(res_node_h, SRV_CCA_NS_OMA_URI, (const S8*)g_srv_prov_ctxt.app_url) ==
                SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }
            if (srv_cca_doc_nodedata_add_str(res_node_h, SRV_CCA_NS_OMA_STARTPAGE, (const S8*)"") == SRV_CCA_STATUS_MEMFULL)
            {
                return SRV_PROV_MEM_FULL;
            }
        }

        temp_node = g_srv_prov_ctxt.cca_brw_app_node_list_p;
        while (temp_node != NULL)
        {
            /* Add setting name to all App nodes */
            if (g_srv_prov_ctxt.setting_name)
            {
                if (srv_cca_doc_nodedata_add_str
                    (temp_node->node_h, SRV_CCA_NS_OMA_NAME,
                     (const S8*)g_srv_prov_ctxt.setting_name) == SRV_CCA_STATUS_MEMFULL)
                {
                    return SRV_PROV_MEM_FULL;
                }
            }
            if (res_node_h)
            {
                crtnode_h = mmi_doc_duplicate_node(res_node_h);
                if (crtnode_h)
                {
                    if (srv_cca_doc_node_attach(crtnode_h, temp_node->node_h) != SRV_CCA_STATUS_OK)
                    {
                        ASSERT(0);
                    }
                }
                else
                {
                    return SRV_PROV_MEM_FULL;
                }
            }
            temp_node = (srv_prov_cca_ne_node_list_struct*) temp_node->node_next;
        }
        if (res_node_h)
        {
            srv_cca_doc_node_free(res_node_h);
        }

    }
    /* Add setting name to all proxy nodes */
    if (g_srv_prov_ctxt.cca_proxy_node_list_p)
    {
        if (g_srv_prov_ctxt.setting_name)
        {
            temp_node = g_srv_prov_ctxt.cca_proxy_node_list_p;
            while (temp_node != NULL)
            {
                if (srv_cca_doc_nodedata_add_str
                    (temp_node->node_h, SRV_CCA_NS_OMA_NAME,
                     (const S8*)g_srv_prov_ctxt.setting_name) == SRV_CCA_STATUS_MEMFULL)
                {
                    return SRV_PROV_MEM_FULL;
                }
                temp_node = (srv_prov_cca_ne_node_list_struct*) temp_node->node_next;
            }
        }
    }

    return retcode;
}
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_sibling_node_to_node_list
 * DESCRIPTION
 *  Adds parameter values to all sibling node of the given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  node_h          [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_sibling_node_to_node_list(S32 cur_node_h, S32 node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    srv_prov_cca_node_hdlr_st *temp_node = NULL;
    srv_prov_cca_node_hdlr_st *new_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node = srv_prov_mem_alloc(sizeof(srv_prov_cca_node_hdlr_st));
    if (NULL == new_node)
    {
        retcode = SRV_PROV_MEM_FULL;
        return retcode;
    }
    new_node->node_h = node_h;
    new_node->cur_node_h = cur_node_h;
    new_node->node_hdlr_next = NULL;

    if (g_srv_prov_ctxt.sibling_node_list_p)
    {
        temp_node = g_srv_prov_ctxt.sibling_node_list_p;
        while (temp_node->node_hdlr_next != NULL)
        {
            temp_node = (srv_prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
        }

        temp_node->node_hdlr_next = new_node;
    }
    else    /* In case of first node */
    {
        g_srv_prov_ctxt.sibling_node_list_p = new_node;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_release_sibling_node_from_node_list
 * DESCRIPTION
 *  Release all sibling node from node list of the given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  retcode         [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_release_sibling_node_from_node_list(S32 *cur_node_h, SRV_PROV_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 releaseFlag = 0;
    srv_prov_cca_node_hdlr_st *cur_node_ptr = NULL;
    srv_prov_cca_node_hdlr_st *prev_node_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_node_ptr = cur_node_ptr = g_srv_prov_ctxt.sibling_node_list_p;
    while (cur_node_ptr != NULL)
    {
        if (*cur_node_h == cur_node_ptr->node_h)
        {
            releaseFlag = 1;
            if (retcode != SRV_PROV_OK)
            {
                /* Release the node and its child node from cca node tree 
                   the node from which it is duplicated has an error */
                srv_cca_doc_node_free(cur_node_ptr->cur_node_h);
            }
            if (cur_node_ptr == g_srv_prov_ctxt.sibling_node_list_p)    /* in case of first node */
            {
                g_srv_prov_ctxt.sibling_node_list_p = (srv_prov_cca_node_hdlr_st*) cur_node_ptr->node_hdlr_next;
                prev_node_ptr = (srv_prov_cca_node_hdlr_st*) cur_node_ptr->node_hdlr_next;
                srv_prov_mem_free(cur_node_ptr);
                cur_node_ptr = NULL;
                cur_node_ptr = g_srv_prov_ctxt.sibling_node_list_p;
            }
            else
            {
                prev_node_ptr->node_hdlr_next = cur_node_ptr->node_hdlr_next;
                srv_prov_mem_free(cur_node_ptr);
                cur_node_ptr = NULL;
                cur_node_ptr = (srv_prov_cca_node_hdlr_st*) prev_node_ptr->node_hdlr_next;
            }

        }
        else
        {
            prev_node_ptr = cur_node_ptr;
            cur_node_ptr = (srv_prov_cca_node_hdlr_st*) cur_node_ptr->node_hdlr_next;
        }
    }
    if (releaseFlag)
    {
        /* Release the node and its child node froom cca node tree */
        srv_cca_doc_node_free(*cur_node_h);
        *cur_node_h = 0;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_nodedata_int_to_sibling_node_list
 * DESCRIPTION
 *  Add ineger param data to all sibling nodes of given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  cca_symbol      [IN]        
 *  value           [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_nodedata_int_to_sibling_node_list(S32 cur_node_h, U16 cca_symbol, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    srv_prov_cca_node_hdlr_st *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node = g_srv_prov_ctxt.sibling_node_list_p;
    while (temp_node != NULL)
    {
        if (cur_node_h == temp_node->node_h)
        {
            if (srv_cca_doc_nodedata_add_int(cur_node_h, cca_symbol, value) == SRV_CCA_STATUS_MEMFULL)
            {
                retcode = SRV_PROV_MEM_FULL;
                break;
            }
        }
        temp_node = (srv_prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_nodedata_str_to_sibling_node_list
 * DESCRIPTION
 *  Add string param data to all sibling nodes of given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  cca_symbol      [IN]        
 *  valuPtr         [?]         [IN\OUT]
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_nodedata_str_to_sibling_node_list(S32 cur_node_h, U16 cca_symbol, S8 *valuPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    srv_prov_cca_node_hdlr_st *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node = g_srv_prov_ctxt.sibling_node_list_p;
    while (temp_node != NULL)
    {
        if (cur_node_h == temp_node->node_h)
        {
            if (srv_cca_doc_nodedata_add_str(cur_node_h, cca_symbol, (const S8*)valuPtr) == SRV_CCA_STATUS_MEMFULL)
            {
                retcode = SRV_PROV_MEM_FULL;
                break;
            }
        }
        temp_node = (srv_prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_attach_node_to_sibling_node_list
 * DESCRIPTION
 *  Attach sibling node  to given node's parrent node.
 * PARAMETERS
 *  cur_node_h          [IN]        
 *  par_cca_node_h      [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_attach_node_to_sibling_node_list(S32 cur_node_h, S32 par_cca_node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    srv_prov_cca_node_hdlr_st *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!par_cca_node_h)
    {
        return retcode;
    }
    temp_node = g_srv_prov_ctxt.sibling_node_list_p;
    while (temp_node != NULL)
    {
        if (par_cca_node_h == temp_node->node_h)
        {
            if (srv_cca_doc_add_node_to_parent(cur_node_h, temp_node->cur_node_h) == SRV_CCA_STATUS_MEMFULL)
            {
                retcode = SRV_PROV_MEM_FULL;
                break;
            }
        }
        temp_node = (srv_prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_remove_deprel_nodes
 * DESCRIPTION
 *  Deattach dependency relation ship nodes from its parent nodes.
 * PARAMETERS
 *  cur_node_h      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_remove_deprel_nodes(S32 cur_node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Currently not in used */
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_fix_cca_doc
 * DESCRIPTION
 *  Wraper for srv_cca_oma_fix_doc.
 * PARAMETERS
 *  hroot       [IN]        
 *  retcode     [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_fix_cca_doc(S32 hroot, SRV_PROV_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (retcode != SRV_PROV_OK)
    {
        return retcode;
    }
    srv_cca_oma_fix_doc(hroot);

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_create_dependency_relationship
 * DESCRIPTION
 *  Create dependency relationship nodes between proxy and napdef and
 *  proxy and application.
 * PARAMETERS
 *  hroot       [IN]        
 *  retcode     [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_create_dependency_relationship(S32 hroot, SRV_PROV_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 deprel_node_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (retcode != SRV_PROV_OK)
    {
        return retcode;
    }
    deprel_node_h = srv_cca_oma_generate_deprel_node(hroot);

    if (!deprel_node_h)
    {
        retcode = SRV_PROV_MEM_FULL;
    }
    else
    {
        if (srv_cca_doc_node_attach(deprel_node_h, hroot) != SRV_CCA_STATUS_OK)
        {
            ASSERT(0);
        }
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_get_enum_from_str_enum_table
 * DESCRIPTION
 *  Converts given string values to corresponding enumerated value.
 * PARAMETERS
 *  attrValue                   [IN]        
 *  str_to_enum_map_table       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_prov_get_enum_from_str_enum_table(
        U16 *attrValue,
        const srv_prov_convert_str_to_cca_enum_struct str_to_enum_map_table[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == attrValue)
    {
        return SRV_CCA_NS_VAL__EMPTY;
    }

    if (!strlen((S8*) attrValue))
    {
        return SRV_CCA_NS_VAL__EMPTY;
    }

    while (str_to_enum_map_table[loop_count].src_str != NULL)
    {
        if (strcmp((S8*) str_to_enum_map_table[loop_count].src_str, (S8*) attrValue) == 0)
        {
            return str_to_enum_map_table[loop_count].cca_enum_value;
        }
        loop_count++;
    }
    return SRV_CCA_NS_VAL__INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_nodedata_str_to_cca_node
 * DESCRIPTION
 *  Adds string param value to CCA node.
 * PARAMETERS
 *  curccanode_h        [IN]        
 *  cca_symbol          [IN]        
 *  valuPtr             [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_nodedata_str_to_cca_node(S32 curccanode_h, U16 cca_symbol, U16 *valuPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    U8 *out_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_buffer = (U8*) valuPtr;
    if (srv_cca_doc_nodedata_add_str(curccanode_h, cca_symbol, (const S8*)(out_buffer)) != SRV_CCA_STATUS_MEMFULL)
    {
        retcode = srv_prov_add_nodedata_str_to_sibling_node_list(curccanode_h, cca_symbol, (S8*) out_buffer);
    }
    else
    {
        retcode = SRV_PROV_MEM_FULL;
    }
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_nodedata_int_to_cca_node
 * DESCRIPTION
 *  Adds integer param value to CCA node.
 * PARAMETERS
 *  curccanode_h        [IN]        
 *  cca_symbol          [IN]        
 *  value_ptr           [?]         
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_nodedata_int_to_cca_node(S32 curccanode_h, U16 cca_symbol, U16 *value_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    S32 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value_ptr)
    {
        value = atoi((S8*) value_ptr);
    }

    if (srv_cca_doc_nodedata_add_int(curccanode_h, cca_symbol, value) != SRV_CCA_STATUS_MEMFULL)
    {
        retcode = srv_prov_add_nodedata_int_to_sibling_node_list(curccanode_h, cca_symbol, value);

    }
    else
    {
        retcode = SRV_PROV_MEM_FULL;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_add_nodedata_enum_to_cca_node
 * DESCRIPTION
 *  Adds enumerated param value to CCA node.
 * PARAMETERS
 *  curccanode_h        [IN]        
 *  cca_symbol          [IN]        
 *  value               [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_add_nodedata_enum_to_cca_node(S32 curccanode_h, U16 cca_symbol, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value == 0xffff)
    {
        ASSERT(0);  /* to be removed later */
        /* return retcode; */
    }

    if (srv_cca_doc_nodedata_add_int(curccanode_h, cca_symbol, value) != SRV_CCA_STATUS_MEMFULL)
    {
        retcode = srv_prov_add_nodedata_int_to_sibling_node_list(curccanode_h, cca_symbol, value);
    }
    else
    {
        retcode = SRV_PROV_MEM_FULL;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_check_dup_application_param_tonapid_value
 * DESCRIPTION
 *  check the duplicate tonapid value in an application tag.
 * PARAMETERS
 *  out_buffer      [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_check_dup_application_param_tonapid_value(U8 *out_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;
    U8 loop_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (out_buffer)
    {
        for (loop_count = 0; loop_count < SRV_PROV_MAX_TONAPID_SUPPORT; loop_count++)
        {
            if (g_srv_prov_ctxt.tonapid[loop_count] &&
                (!strcmp((S8*) g_srv_prov_ctxt.tonapid[loop_count], (S8*) out_buffer)))
            {
                return SRV_PROV_ERR;
            }
            else if (g_srv_prov_ctxt.tonapid[loop_count] == NULL)
            {
                g_srv_prov_ctxt.tonapid[loop_count] = srv_prov_mem_alloc(strlen((S8*) out_buffer) + 1);

                if (NULL == g_srv_prov_ctxt.tonapid[loop_count])
                {
                    return SRV_PROV_MEM_FULL;
                }
                strcpy((S8*) g_srv_prov_ctxt.tonapid[loop_count], (S8*) out_buffer);
                break;
            }
        }
    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_free_application_param_tonapid_value
 * DESCRIPTION
 *  free tonapid value in an application tag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_free_application_param_tonapid_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (loop_count < SRV_PROV_MAX_TONAPID_SUPPORT && g_srv_prov_ctxt.tonapid[loop_count])
    {
        srv_prov_mem_free(g_srv_prov_ctxt.tonapid[loop_count]);
        g_srv_prov_ctxt.tonapid[loop_count] = NULL;
        loop_count++;
    }
}

#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)


/*****************************************************************************
 * FUNCTION
 *  srv_prov_param_pxsip_codec_tag_hdlr
 * DESCRIPTION
 *  Handles pxsip codec param of pxsip characteristic.
 * PARAMETERS
 *  attr_value      [IN]        
 *  root            [IN]        
 *  ret_value       [?]         [IN\OUT]
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_param_pxsip_codec_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = srv_prov_get_enum_from_str_enum_table(attr_value, srv_prov_param_pxsip_codec_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_pxsip_tag_hdlr
 * DESCRIPTION
 *  Handles px-sip characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_pxsip_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_PXSIP_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_wifi_tag_hdlr
 * DESCRIPTION
 *  Handles wi-fi characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_wifi_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_ROOT_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_WIFI_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_access_point_tag_hdlr
 * DESCRIPTION
 *  Handles access point characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_access_point_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_WIFI_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_ACCESS_POINT_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_adhoc_tag_hdlr
 * DESCRIPTION
 *  Handles adhoc characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_adhoc_tag_hdlr(S32 *root, srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~SRV_PROV_WIFI_NODE_VAL;
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_AD_HOC_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_characteristic_wifi_profile_tag_hdlr
 * DESCRIPTION
 *  Handles wi-fi profile characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_characteristic_wifi_profile_tag_hdlr(
                    S32 *root,
                    srv_prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case SRV_PROV_CHARACTERISTIC_START:
            break;

        case SRV_PROV_CHARACTERISTIC_END:
            g_srv_prov_ctxt.parent_parent_id &= ~(SRV_PROV_ACCESS_POINT_NODE_VAL | SRV_PROV_AD_HOC_NODE_VAL);
            g_srv_prov_ctxt.node_parent_id &= ~SRV_PROV_WIFI_PROFILE_NODE_VAL;
            break;

    }
    return retcode;
}
#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */ 

#endif /* __MMI_PROV_SERVICE_CCA_SUPPORT_ON__ */ 
#endif /* __PROVISIONING_SERVICE_SUPPORT__ */ 
#endif /* _PROVSERVICECONFIGURINGSRC_C */ 

