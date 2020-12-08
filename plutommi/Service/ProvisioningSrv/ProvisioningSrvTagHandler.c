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
 * ProvisioningSrvTagHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file helps in parsing the WBXML content.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#ifndef _PROVISIONINGSRVTAGHANDLER_C
#define _PROVISIONINGSRVTAGHANDLER_C

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

#include "ProvisioningSrvMain.h"

#ifdef __MMI_PROV_SERVICE_CCA_SUPPORT_ON__

#include "ProvisioningSrvProt.h"
#include "ProvisioningSrvTagHandler.h"

//------------------------------ suggest Add ------------------------------
#include "ProvisioningSrvConfiguringSrc.h"
#include "MMIDataType.h"
#include "wbxmlp.h"
#include "kal_public_api.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "stack_config.h"
//------------------------------ usage ------------------------------

static SRV_PROV_RETCODE srv_prov_handle_characteristic_tag(const S8 **attrlist);
static SRV_PROV_RETCODE srv_prov_handle_param_tag(const S8 **attrlist);
static void srv_prov_wbxml_header_hdlr(
                void *resv,
                kal_char *publicid,
                kal_uint32 charset,
                kal_uint8 mainver,
                kal_uint8 subver);
static void *srv_prov_wbxml_malloc_buffer(kal_int32 len);
static void srv_prov_wbxml_free_buffer(void *ptr);
static void srv_prov_wbxml_start_hdlr(void *resv, const kal_char *tagname, const kal_char **attrlist);
static void srv_prov_wbxml_data_hdlr(
                void *resv,
                const kal_char *tagname,
                const kal_char *data,
                kal_uint32 len,
                kal_uint8 datatype);
static void srv_prov_wbxml_end_hdlr(void *resv, const kal_char *tagname);
static SRV_PROV_RETCODE srv_prov_convert_wbxml_parser_error_code(S32 err_code);
static kal_int32 srv_prov_wbxml_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token);
static kal_int32 srv_prov_wbxml_get_attrname_by_token(
                    kal_char *ptr,
                    kal_char *attrprefix,
                    kal_uint32 attrcp,
                    kal_uint8 token);

const S8 *prov_tags[(SRV_PROV_TAGS_MAX - SRV_PROV_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "wap-provisioningdoc",
    /* 0x06 */ "characteristic",
    /* 0x07 */ "parm"
};

const S8 *prov_start_attributes[(SRV_PROV_SATTR_MAX - SRV_PROV_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "name",
    /* 0x06 */ "value",
    /* 0x07 */ "name=\"NAME\"",
    /* 0x08 */ "name=\"NAP-ADDRESS\"",
    /* 0x09 */ "name=\"NAP-ADDRTYPE\"",
    /* 0x0A */ "name=\"CALLTYPE\"",
    /* 0x0B */ "name=\"VALIDUNTIL\"",
    /* 0x0C */ "name=\"AUTHTYPE\"",
    /* 0x0D */ "name=\"AUTHNAME\"",
    /* 0x0E */ "name=\"AUTHSECRET\"",
    /* 0x0F */ "name=\"LINGER\"",
    /* 0x10 */ "name=\"BEARER\"",
    /* 0x11 */ "name=\"NAPID\"",
    /* 0x12 */ "name=\"COUNTRY\"",
    /* 0x13 */ "name=\"NETWORK\"",
    /* 0x14 */ "name=\"INTERNET\"",
    /* 0x15 */ "name=\"PROXY-ID\"",
    /* 0x16 */ "name=\"PROXY-PROVIDER-ID\"",
    /* 0x17 */ "name=\"DOMAIN\"",
    /* 0x18 */ "name=\"PROVURL\"",
    /* 0x19 */ "name=\"PXAUTH-TYPE\"",
    /* 0x1A */ "name=\"PXAUTH-ID\"",
    /* 0x1B */ "name=\"PXAUTH-PW\"",
    /* 0x1C */ "name=\"STARTPAGE\"",
    /* 0x1D */ "name=\"BASAUTH-ID\"",
    /* 0x1E */ "name=\"BASAUTH-PW\"",
    /* 0x1F */ "name=\"PUSHENABLED\"",
    /* 0x20 */ "name=\"PXADDR\"",
    /* 0x21 */ "name=\"PXADDRTYPE\"",
    /* 0x22 */ "name=\"TO-NAPID\"",
    /* 0x23 */ "name=\"PORTNBR\"",
    /* 0x24 */ "name=\"SERVICE\"",
    /* 0x25 */ "name=\"LINKSPEED\"",
    /* 0x26 */ "name=\"DNLINKSPEED\"",
    /* 0x27 */ "name=\"LOCAL-ADDR\"",
    /* 0x28 */ "name=\"LOCAL-ADDRTYPE\"",
    /* 0x29 */ "name=\"CONTEXT-ALLOW\"",
    /* 0x2A */ "name=\"TRUST\"",
    /* 0x2B */ "name=\"MASTER\"",
    /* 0x2C */ "name=\"SID\"",
    /* 0x2D */ "name=\"SOC\"",
    /* 0x2E */ "name=\"WSP-VERSION\"",
    /* 0x2F */ "name=\"PHYSICAL-PROXY-ID\"",
    /* 0x30 */ "name=\"CLIENT-ID\"",
    /* 0x31 */ "name=\"DELIVERY-ERR-SDU\"",
    /* 0x32 */ "name=\"DELIVERY-ORDER\"",
    /* 0x33 */ "name=\"TRAFFIC-CLASS\"",
    /* 0x34 */ "name=\"MAX-SDU-SIZE\"",
    /* 0x35 */ "name=\"MAX-BITRATE-UPLINK\"",
    /* 0x36 */ "name=\"MAX-BITRATE-DNLINK\"",
    /* 0x37 */ "name=\"RESIDUAL-BER\"",
    /* 0x38 */ "name=\"SDU-ERROR-RATIO\"",
    /* 0x39 */ "name=\"TRAFFIC-HANDL-PRIO\"",
    /* 0x3A */ "name=\"TRANSFER-DELAY\"",
    /* 0x3B */ "name=\"GUARANTEED-BITRATE-UPLINK\"",
    /* 0x3C */ "name=\"GUARANTEED-BITRATE-DNLINK\"",
    /* 0x3D */ "name=\"PXADDR-FQDN\"",
    /* 0x3E */ "name=\"PROXY-PW\"",
    /* 0x3F */ "name=\"PPGAUTH-TYPE\"",
    /* 0x40 */ NULL,
    /* 0x41 */ NULL,
    /* 0x42 */ NULL,
    /* 0x43 */ NULL,
    /* 0x44 */ NULL,
    /* 0x45 */ "version",
    /* 0x46 */ "version=\"1.0\"",
    /* 0x47 */ "name=\"PULLENABLED\"",
    /* 0x48 */ "name=\"DNS-ADDR\"",
    /* 0x49 */ "name=\"MAX-NUM-RETRY\"",
    /* 0x4A */ "name=\"FIRST-RETRY-TIMEOUT\"",
    /* 0x4B */ "name=\"REREG-THRESHOLD\"",
    /* 0x4C */ "name=\"T-BIT\"",
    /* 0x4D */ NULL,
    /* 0x4E */ "name=\"AUTH-ENTITY\"",
    /* 0x4F */ "name=\"SPI\"",
    /* 0x50 */ "type",
    /* 0x51 */ "type=\"PXLOGICAL\"",
    /* 0x52 */ "type=\"PXPHYSICAL\"",
    /* 0x53 */ "type=\"PORT\"",
    /* 0x54 */ "type=\"VALIDITY\"",
    /* 0x55 */ "type=\"NAPDEF\"",
    /* 0x56 */ "type=\"BOOTSTRAP\"",
    /* 0x57 */ "type=\"VENDORCONFIG\"",
    /* 0x58 */ "type=\"CLIENTIDENTITY\"",
    /* 0x59 */ "type=\"PXAUTHINFO\"",
    /* 0x5A */ "type=\"NAPAUTHINFO\"",
    /* 0x5B */ "type=\"ACCESS\"",
};

const S8 *prov_value_attributes[(SRV_PROV_VATTR_MAX - SRV_PROV_VATTR_MIN) + 1] = 
{
    /* 0x85 */ "IPV4",
    /* 0x86 */ "IPV6",
    /* 0x87 */ "E164",
    /* 0x88 */ "ALPHA",
    /* 0x89 */ "APN",
    /* 0x8A */ "SCODE",
    /* 0x8B */ "TETRA-ITSI",
    /* 0x8C */ "MAN",
    /* 0x8D */ NULL,
    /* 0x8E */ NULL,
    /* 0x8F */ NULL,
    /* 0x90 */ "ANALOG-MODEM",
    /* 0x91 */ "V.120",
    /* 0x92 */ "V.110",
    /* 0x93 */ "X.31",
    /* 0x94 */ "BIT-TRANSPARENT",
    /* 0x95 */ "DIRECT-ASYNCHRONOUS-DATA-SERVICE",
    /* 0x96 */ NULL,
    /* 0x97 */ NULL,
    /* 0x98 */ NULL,
    /* 0x99 */ NULL,
    /* 0x9A */ "PAP",
    /* 0x9B */ "CHAP",
    /* 0x9C */ "HTTP-BASIC",
    /* 0x9D */ "HTTP-DIGEST",
    /* 0x9E */ "WTLS-SS",
    /* 0x9F */ "MD5",
    /* 0xA0 */ NULL,
    /* 0xA1 */ NULL,
    /* 0xA2 */ "GSM-USSD",
    /* 0xA3 */ "GSM-SMS",
    /* 0xA4 */ "ANSI-136-GUTS",
    /* 0xA5 */ "IS-95-CDMA-SMS",
    /* 0xA6 */ "IS-95-CDMA-CSD",
    /* 0xA7 */ "IS-95-CDMA-PACKET",
    /* 0xA8 */ "ANSI-136-CSD",
    /* 0xA9 */ "ANSI-136-GPRS",
    /* 0xAA */ "GSM-CSD",
    /* 0xAB */ "GSM-GPRS",
    /* 0xAC */ "AMPS-CDPD",
    /* 0xAD */ "PDC-CSD",
    /* 0xAE */ "PDC-PACKET",
    /* 0xAF */ "IDEN-SMS",
    /* 0xB0 */ "IDEN-CSD",
    /* 0xB1 */ "IDEN-PACKET",
    /* 0xB2 */ "FLEX/REFLEX",
    /* 0xB3 */ "PHS-SMS",
    /* 0xB4 */ "PHS-CSD",
    /* 0xB5 */ "TETRA-SDS",
    /* 0xB6 */ "TETRA-PACKET",
    /* 0xB7 */ "ANSI-136-GHOST",
    /* 0xB8 */ "MOBITEX-MPAK",
    /* 0xB9 */ NULL,
    /* 0xBA */ NULL,
    /* 0xBB */ NULL,
    /* 0xBC */ NULL,
    /* 0xBD */ NULL,
    /* 0xBE */ NULL,
    /* 0xBF */ NULL,
    /* 0xC0 */ NULL,
    /* 0xC1 */ NULL,
    /* 0xC2 */ NULL,
    /* 0xC3 */ NULL,
    /* 0xC4 */ NULL,
    /* 0xC5 */ "AUTOBAUDING",
    /* 0xC6 */ NULL,
    /* 0xC7 */ NULL,
    /* 0xC8 */ NULL,
    /* 0xC9 */ NULL,
    /* 0xCA */ "CL-WSP",
    /* 0xCB */ "CO-WSP",
    /* 0xCC */ "CL-SEC-WSP",
    /* 0xCD */ "CO-SEC-WSP",
    /* 0xCE */ "CL-SEC-WTA",
    /* 0xCF */ "CO-SEC-WTA",
    /* 0xD0 */ "OTA-HTTP-TO",
    /* 0xD1 */ "OTA-HTTP-TLS-TO",
    /* 0xD2 */ "OTA-HTTP-PO",
    /* 0xD3 */ "OTA-HTTP-TLS-PO",
};

#ifdef __PROV_NOKIA_OTA_SUPPORT__

const S8 *nokia_prov_tags[(SRV_PROV_NOKIA_TAGS_MAX - SRV_PROV_NOKIA_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "characteristic-list",
    /* 0x06 */ "characteristic",
    /* 0x07 */ "parm"
};

const S8 *nokia_prov_start_attributes[(SRV_PROV_NOKIA_SATTR_MAX - SRV_PROV_NOKIA_SATTR_MIN) + 1] = 
{
    /* 0x06 */ "type=\"ADDRESS\"",
    /* 0x07 */ "type=\"URL\"",
    /* 0x08 */ "type=\"NAME\"",
    /* 0x09 */ NULL,
    /* 0x0A */ NULL,
    /* 0x0B */ NULL,
    /* 0x0C */ NULL,
    /* 0x0D */ NULL,
    /* 0x0E */ NULL,
    /* 0x0F */ NULL,
    /* 0x10 */ "name",
    /* 0x11 */ "value",
    /* 0x12 */ "name=\"BEARER\"",
    /* 0x13 */ "name=\"PROXY\"",
    /* 0x14 */ "name=\"PORT\"",
    /* 0x15 */ "name=\"NAME\"",
    /* 0x16 */ "name=\"PROXY_TYPE\"",
    /* 0x17 */ "name=\"URL\"",
    /* 0x18 */ "name=\"PROXY_AUTHNAME\"",
    /* 0x19 */ "name=\"PROXY_AUTHSECRET\"",
    /* 0x1A */ "name=\"SMS_SMSC_ADDRESS\"",
    /* 0x1B */ "name=\"USSD_SERVICECODE\"",
    /* 0x1C */ "name=\"GPRS_ACCESSPOINTNAME\"",
    /* 0x1D */ "name=\"PPP_LOGINTYPE\"",
    /* 0x1E */ "name=\"PROXY_LOGINTYPE\"",
    /* 0x1F */ NULL,
    /* 0x20 */ NULL,
    /* 0x21 */ "name=\"CSD_DIALSTRING\"",
    /* 0x22 */ "name=\"PPP_AUTHTYPE\"",
    /* 0x23 */ "name=\"PPP_AUTHNAME\"",
    /* 0x24 */ "name=\"PPP_AUTHSECRET\"",
    /* 0x25 */ NULL,
    /* 0x26 */ NULL,
    /* 0x27 */ NULL,
    /* 0x28 */ "name=\"CSD_CALLTYPE\"",
    /* 0x29 */ "name=\"CSD_CALLSPEED\"",
    /* 0x2A */ NULL,
    /* 0x2B */ NULL,
    /* 0x2C */ NULL,
    /* 0x2D */ NULL,
    /* 0x2E */ NULL,
    /* 0x2F */ NULL,
    /* 0x30 */ NULL,
    /* 0x31 */ NULL,
    /* 0x32 */ NULL,
    /* 0x33 */ NULL,
    /* 0x34 */ NULL,
    /* 0x35 */ NULL,
    /* 0x36 */ NULL,
    /* 0x37 */ NULL,
    /* 0x38 */ NULL,
    /* 0x39 */ NULL,
    /* 0x3A */ NULL,
    /* 0x3B */ NULL,
    /* 0x3C */ NULL,
    /* 0x3D */ NULL,
    /* 0x3E */ NULL,
    /* 0x3F */ NULL,
    /* 0x40 */ NULL,
    /* 0x41 */ NULL,
    /* 0x42 */ NULL,
    /* 0x43 */ NULL,
    /* 0x44 */ NULL,
    /* 0x45 */ "value=\"GSM/CSD\"",
    /* 0x46 */ "value=\"GSM/SMS\"",
    /* 0x47 */ "value=\"GSM/USSD\"",
    /* 0x48 */ "value=\"IS-136/USSD\"",
    /* 0x49 */ "value=\"GPRS\"",
    /* 0x4A */ NULL,
    /* 0x4B */ NULL,
    /* 0x4C */ NULL,
    /* 0x4D */ NULL,
    /* 0x4E */ NULL,
    /* 0x4F */ NULL,
    /* 0x50 */ NULL,
    /* 0x51 */ NULL,
    /* 0x52 */ NULL,
    /* 0x53 */ NULL,
    /* 0x54 */ NULL,
    /* 0x55 */ NULL,
    /* 0x56 */ NULL,
    /* 0x57 */ NULL,
    /* 0x58 */ NULL,
    /* 0x59 */ NULL,
    /* 0x5A */ NULL,
    /* 0x5B */ NULL,
    /* 0x5C */ NULL,
    /* 0x5D */ NULL,
    /* 0x5E */ NULL,
    /* 0x5F */ NULL,
    /* 0x60 */ "value=\"9200\"",
    /* 0x61 */ "value=\"9201\"",
    /* 0x62 */ "value=\"9202\"",
    /* 0x63 */ "value=\"9203\"",
    /* 0x64 */ "value=\"AUTOMATIC\"",
    /* 0x65 */ "value=\"MANUAL\"",
    /* 0x66 */ NULL,
    /* 0x67 */ NULL,
    /* 0x68 */ NULL,
    /* 0x69 */ NULL,
    /* 0x6A */ "value=\"AUTO\"",
    /* 0x6B */ "value=\"9600\"",
    /* 0x6C */ "value=\"14400\"",
    /* 0x6D */ "value=\"19200\"",
    /* 0x6E */ "value=\"28800\"",
    /* 0x6F */ "value=\"38400\"",
    /* 0x70 */ "value=\"PAP\"",
    /* 0x71 */ "value=\"CHAP\"",
    /* 0x72 */ "value=\"ANALOGUE\"",
    /* 0x73 */ "value=\"ISDN\"",
    /* 0x74 */ "value=\"43200\"",
    /* 0x75 */ "value=\"57600\"",
    /* 0x76 */ "value=\"MSISDN_NO\"",
    /* 0x77 */ "value=\"IPV4\"",
    /* 0x78 */ "value=\"MS_CHAP\"",
    /* 0x79 */ NULL,
    /* 0x7A */ NULL,
    /* 0x7B */ NULL,
    /* 0x7C */ "type=\"MMSURL\"",
    /* 0x7D */ "type=\"ID\"",
    /* 0x7E */ "type=\"ISP_NAME\"",
    /* 0x7F */ "type=\"BOOKMARK\""
};
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

#if 0   /* 2 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ /* 2 */               /* Not in use currently */

const S8 *pacOmaProvStartAttributes[(SRV_PROV_OMA_SATTR_MAX - SRV_PROV_OMA_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "name",
    /* 0x06 */ "value",
    /* 0x07 */ "name=\"NAME\"",
    /* 0x08 */ NULL,
    /* 0x09 */ NULL,
    /* 0x0A */ NULL,
    /* 0x0B */ NULL,
    /* 0x0C */ NULL,
    /* 0x0D */ NULL,
    /* 0x0E */ NULL,
    /* 0x0F */ NULL,
    /* 0x10 */ NULL,
    /* 0x11 */ NULL,
    /* 0x12 */ NULL,
    /* 0x13 */ NULL,
    /* 0x14 */ "name=\"INTERNET\"",
    /* 0x15 */ NULL,
    /* 0x16 */ NULL,
    /* 0x17 */ NULL,
    /* 0x18 */ NULL,
    /* 0x19 */ NULL,
    /* 0x1A */ NULL,
    /* 0x1B */ NULL,
    /* 0x1C */ "name=\"STARTPAGE\"",
    /* 0x1D */ NULL,
    /* 0x1E */ NULL,
    /* 0x1F */ NULL,
    /* 0x20 */ NULL,
    /* 0x21 */ NULL,
    /* 0x22 */ "name=\"TO-NAPID\"",
    /* 0x23 */ "name=\"PORTNBR\"",
    /* 0x24 */ "name=\"SERVICE\"",
    /* 0x25 */ NULL,
    /* 0x26 */ NULL,
    /* 0x27 */ NULL,
    /* 0x28 */ NULL,
    /* 0x29 */ NULL,
    /* 0x2A */ NULL,
    /* 0x2B */ NULL,
    /* 0x2C */ NULL,
    /* 0x2D */ NULL,
    /* 0x2E */ "name=\"AACCEPT\"",
    /* 0x2F */ "name=\"AAUTHDATA\"",
    /* 0x30 */ "name=\"AAUTHLEVEL\"",
    /* 0x31 */ "name=\"AAUTHNAME\"",
    /* 0x32 */ "name=\"AAUTHSECRET\"",
    /* 0x33 */ "name=\"AAUTHTYPE\"",
    /* 0x34 */ "name=\"ADDR\"",
    /* 0x35 */ "name=\"ADDRTYPE\"",
    /* 0x36 */ "name=\"APPID\"",
    /* 0x37 */ "name=\"APROTOCOL\"",
    /* 0x38 */ "name=\"PROVIDER-ID\"",
    /* 0x39 */ "name=\"TO-PROXY\"",
    /* 0x3A */ "name=\"URI\"",
    /* 0x3B */ "name=\"RULE\"",
    /* 0x3C */ NULL,
    /* 0x3D */ NULL,
    /* 0x3E */ NULL,
    /* 0x3F */ NULL,
    /* 0x40 */ NULL,
    /* 0x41 */ NULL,
    /* 0x42 */ NULL,
    /* 0x43 */ NULL,
    /* 0x44 */ NULL,
    /* 0x45 */ NULL,
    /* 0x46 */ NULL,
    /* 0x47 */ NULL,
    /* 0x48 */ NULL,
    /* 0x49 */ NULL,
    /* 0x4A */ NULL,
    /* 0x4B */ NULL,
    /* 0x4C */ NULL,
    /* 0x4D */ NULL,
    /* 0x4E */ NULL,
    /* 0x4F */ NULL,
    /* 0x50 */ "type",
    /* 0x51 */ NULL,
    /* 0x52 */ NULL,
    /* 0x53 */ "type=\"PORT\"",
    /* 0x54 */ NULL,
    /* 0x55 */ "type=\"APPLICATION\"",
    /* 0x56 */ "type=\"APPADDR\"",
    /* 0x57 */ "type=\"APPAUTH\"",
    /* 0x58 */ "type=\"CLIENTIDENTITY\"",
    /* 0x59 */ "type=\"RESOURCE\""
};

const S8 *pacOmaProvValueAttributes[(OMA_PROV_VATTR_MAX - OMA_PROV_VATTR_MIN) + 1] = 
{
    /* 0x80 */ NULL,
    /* 0x81 */ NULL,
    /* 0x82 */ NULL,
    /* 0x83 */ NULL,
    /* 0x84 */ NULL,
    /* 0x85 */ NULL,
    /* 0x86 */ "IPV6",
    /* 0x87 */ "E164",
    /* 0x88 */ "ALPHA",
    /* 0x89 */ NULL,
    /* 0x8A */ NULL,
    /* 0x8B */ NULL,
    /* 0x8C */ NULL,
    /* 0x8D */ "APPSRV",
    /* 0x8E */ "OBEX",
    /* 0x8F */ NULL,
    /* 0x90 */ ",",
    /* 0x91 */ "HTTP-",
    /* 0x92 */ "BASIC",
    /* 0x93 */ "DIGEST",
    /* 0x94 */ NULL,
    /* 0x95 */ NULL,
    /* 0x96 */ NULL,
    /* 0x97 */ NULL,
    /* 0x98 */ NULL,
    /* 0x99 */ NULL,
    /* 0x9A */ NULL,
    /* 0x9B */ NULL,
    /* 0x9C */ NULL,
    /* 0x9D */ NULL,
    /* 0x9E */ NULL,
    /* 0x9F */ NULL,
    /* 0xA0 */ NULL,
    /* 0xA1 */ NULL,
    /* 0xA2 */ NULL,
    /* 0xA3 */ NULL,
    /* 0xA4 */ NULL,
    /* 0xA5 */ NULL,
    /* 0xA6 */ NULL,
    /* 0xA7 */ NULL,
    /* 0xA8 */ NULL,
    /* 0xA9 */ NULL,
    /* 0xAA */ NULL,
    /* 0xAB */ NULL,
    /* 0xAC */ NULL,
    /* 0xAD */ NULL,
    /* 0xAE */ NULL,
    /* 0xAF */ NULL,
    /* 0xB0 */ NULL,
    /* 0xB1 */ NULL,
    /* 0xB2 */ NULL,
    /* 0xB3 */ NULL,
    /* 0xB4 */ NULL,
    /* 0xB5 */ NULL,
    /* 0xB6 */ NULL,
    /* 0xB7 */ NULL,
    /* 0xB8 */ NULL,
    /* 0xB9 */ NULL,
    /* 0xBA */ NULL,
    /* 0xBC */ NULL,
    /* 0xBD */ NULL,
    /* 0xBE */ NULL,
    /* 0xBF */ NULL,
    /* 0xC0 */ NULL,
    /* 0xC1 */ NULL,
    /* 0xC2 */ NULL,
    /* 0xC3 */ NULL,
    /* 0xC4 */ NULL,
    /* 0xC5 */ NULL,
    /* 0xC6 */ NULL,
    /* 0xC7 */ NULL,
    /* 0xC8 */ NULL,
    /* 0xC9 */ NULL,
    /* 0xCA */ "CL-WSP",
    /* 0xCB */ "CO-WSP",
    /* 0xCC */ "CL-SEC-WSP",
    /* 0xCD */ "CO-SEC-WSP",
    /* 0xCE */ "CL-SEC-WTA",
    /* 0xCF */ "CO-SEC-WTA"
};

/* Static global variables */
static WP_HANDLE g_srv_prov_wbxml_handle;


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_parser_handler
 * DESCRIPTION
 *  wbxml parser handler
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_wbxml_parser_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_prov_queue_data_struct *prov_data_p;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prov_data_p = *(srv_prov_get_current_queue_data());

    g_srv_prov_wbxml_handle = wbxml_new_parser();
    if ((WP_HANDLE) -1 == g_srv_prov_wbxml_handle)
    {
        return SRV_PROV_MEM_FULL;
    }

#ifndef SLIM_WAP_MMS    /* SLIM_R */
    wbxml_configure_memory(g_srv_prov_wbxml_handle, srv_prov_wbxml_malloc_buffer, srv_prov_wbxml_free_buffer);
#endif

    wbxml_register_header_handler(g_srv_prov_wbxml_handle, srv_prov_wbxml_header_hdlr);
    wbxml_register_data_handler(g_srv_prov_wbxml_handle, srv_prov_wbxml_data_hdlr);
    wbxml_register_element_handler(g_srv_prov_wbxml_handle, srv_prov_wbxml_start_hdlr, srv_prov_wbxml_end_hdlr);
    wbxml_register_get_name_handler(
        g_srv_prov_wbxml_handle,
        srv_prov_wbxml_get_tagname_by_token,
        srv_prov_wbxml_get_attrname_by_token);

    ret = wbxml_parse(g_srv_prov_wbxml_handle, prov_data_p->pbuffer, prov_data_p->plength);
    wbxml_close_parser(g_srv_prov_wbxml_handle);

    g_srv_prov_wbxml_handle = (WP_HANDLE) -1;
    return srv_prov_convert_wbxml_parser_error_code(ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_get_attrname_by_token
 * DESCRIPTION
 *  get attrname by oken
 * PARAMETERS
 *  ptr             [OUT]       
 *  attrprefix      [OUT]       
 *  attrcp          [IN]        
 *  token           [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 srv_prov_wbxml_get_attrname_by_token(
                    kal_char *ptr,
                    kal_char *attrprefix,
                    kal_uint32 attrcp,
                    kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *temp = NULL;
    kal_int32 len = 0;
    S32 more_attribute_value = 0;
    S32 quote_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_prov_ctxt.prov_type)
    {
        case SRV_PROV_OTA_TYPE_OMA:
        {
            if (SRV_PROV_WAP_SWITCH_PAGE == attrcp)
            {
                if (token >= SRV_PROV_SATTR_MIN && token <= SRV_PROV_SATTR_MAX)
                {
                    temp = (kal_char*) SRV_PROV_SATTR_DESC(token);
                }
                else if (token >= SRV_PROV_VATTR_MIN && token <= SRV_PROV_VATTR_MAX)
                {
                    temp = (kal_char*) SRV_PROV_VATTR_DESC(token);
                }
                else
                {
                    return 0;   /* No string found for the corresponding token */
                }
            }
            else if (SRV_PROV_OMA_SWITCH_PAGE == attrcp)
            {
                if (token >= SRV_PROV_OMA_SATTR_MIN && token <= SRV_PROV_OMA_SATTR_MAX)
                {
                    temp = (kal_char*) SRV_PROV_OMA_SATTR_DESC(token);
                }
                else if (token >= SRV_PROV_VATTR_MIN && token <= SRV_PROV_VATTR_MAX)
                {
                    temp = (kal_char*) SRV_PROV_OMA_VATTR_DESC(token);
                }
                else
                {
                    return 0;   /* No string found for the corresponding token */
                    /* ASSERT(0); */
                }
            }
            else
            {
                ASSERT(0);
            }
            break;
        }

/* SLIM_R */
#ifdef __PROV_NOKIA_OTA_SUPPORT__
        case SRV_PROV_OTA_TYPE_WAP:
        {
            if (token >= SRV_PROV_NOKIA_SATTR_MIN && token <= SRV_PROV_NOKIA_SATTR_MAX)
            {
                temp = (kal_char*) SRV_PROV_NOKIA_SATTR_DESC(token);
            }
            /*
             * else if (token >= SRV_PROV_NOKIA_VATTR_MIN && token <= SRV_PROV_NOKIA_VATTR_MAX)
             * {
             * temp = (kal_char*) SRV_PROV_NOKIA_VATTR_DESC(token);
             * ASSERT(0);
             * }
             * Not in use but can be adjusted.
             */
            else
            {
                return 0;   /* No string found for the corresponding token */
                /* ASSERT(0); */
            }
        }
            break;
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */
        default:
            ASSERT(0);

    }
    if (temp)
    {
        len = strlen(temp);
        if (len < SRV_PROV_MAX_WBXML_STRLEN)
        {
            more_attribute_value = srv_prov_get_char_occurence(temp, '\"', 0);
            if (more_attribute_value == SRV_PROV_ATTRIBUTE_VALUE_NUMBER)
            {
                quote_index = srv_prov_index_of_char('\"', temp, 0);
                memset(ptr, 0, quote_index);
                strncpy(ptr, temp, quote_index - 1);
                temp += quote_index + 1;
                memset(attrprefix, 0, strlen(temp));
                strncpy(attrprefix, temp, strlen(temp) - 1);
            }
            else if (more_attribute_value == 0)
            {
                memset(ptr, 0, strlen(temp) + 1);
                strcpy(ptr, temp);
            }
        }
        else
        {
            len = -1;
        }
    }
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_get_tagname_by_token
 * DESCRIPTION
 *  get tagname by token
 * PARAMETERS
 *  ptr         [OUT]       
 *  tagcp       [IN]        
 *  token       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 srv_prov_wbxml_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *temp = NULL;
    kal_int32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_prov_ctxt.prov_type)
    {
        case SRV_PROV_OTA_TYPE_OMA:
            if (token >= SRV_PROV_TAGS_MIN && token <= SRV_PROV_TAGS_MAX)
            {
                temp = (kal_char*) SRV_PROV_TAG_DESC(token);
            }
            else
            {
                return 0;   /* No string found for the corresponding token */
                /* ASSERT(0); */
            }
            break;

/* SLIM_R */
#ifdef __PROV_NOKIA_OTA_SUPPORT__
        case SRV_PROV_OTA_TYPE_WAP:
            if (token >= SRV_PROV_NOKIA_TAGS_MIN && token <= SRV_PROV_NOKIA_TAGS_MAX)
            {
                temp = (kal_char*) SRV_PROV_NOKIA_TAG_DESC(token);
            }
            else
            {
                return 0;   /* No string found for the corresponding token */
                /* ASSERT(0); */
            }
            break;
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */
        default:
            ASSERT(0);
    }
    if (temp)
    {
        len = strlen(temp);
        if (len < SRV_PROV_MAX_WBXML_STRLEN)
        {
            strcpy(ptr, temp);
        }
        else
        {
            len = -1;
        }
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_header_hdlr
 * DESCRIPTION
 *  wbxml header hdlr
 * PARAMETERS
 *  resv            [IN]        
 *  publicid        [IN]        
 *  charset         [IN]        
 *  mainver         [IN]        
 *  subver          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prov_wbxml_header_hdlr(
                void *resv,
                kal_char *publicid,
                kal_uint32 charset,
                kal_uint8 mainver,
                kal_uint8 subver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(publicid);
    if (srv_prov_check_if_substring(publicid, PROV_OMA_PUBLIC_ID) == 0)
    {
        g_srv_prov_ctxt.prov_type = SRV_PROV_OTA_TYPE_OMA;
    }
    else if (srv_prov_check_if_substring(publicid, PROV_WAP_PUBLIC_ID) == 0)
    {
        g_srv_prov_ctxt.prov_type = SRV_PROV_OTA_TYPE_WAP;
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_data_hdlr
 * DESCRIPTION
 *  wbxml start tag hdlr
 * PARAMETERS
 *  resv            [IN]        
 *  tagname         [IN]        
 *  data            [IN]        
 *  len             [IN]        
 *  datatype        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prov_wbxml_data_hdlr(
                void *resv,
                const kal_char *tagname,
                const kal_char *data,
                kal_uint32 len,
                kal_uint8 datatype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Currently Data not required */
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_start_hdlr
 * DESCRIPTION
 *  wbxml start tag hdlr
 * PARAMETERS
 *  resv            [IN]        
 *  tagname         [IN]        
 *  attrlist        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prov_wbxml_start_hdlr(void *resv, const kal_char *tagname, const kal_char **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(tagname);
    if (strcmp(tagname, PROV_CHARACTERISTIC) == 0)
    {
        if (!g_srv_prov_ctxt.unnkown_tag_count)
        {
            g_srv_prov_ctxt.err_code = srv_prov_handle_characteristic_tag(attrlist);
        }
        if (g_srv_prov_ctxt.err_code == SRV_PROV_UNKNOWN_TAG)
        {
            g_srv_prov_ctxt.unnkown_tag_count++;
        }
    }
    /* In case of unknown tag don't add its parametere */
    else if ((strcmp(tagname, "parm") == 0) && (g_srv_prov_ctxt.err_code != SRV_PROV_UNKNOWN_TAG))
    {
        g_srv_prov_ctxt.err_code = srv_prov_handle_param_tag(attrlist);

    }

    if ((g_srv_prov_ctxt.err_code != SRV_PROV_OK) && (g_srv_prov_ctxt.err_code != SRV_PROV_UNKNOWN_TAG))
    {
        wbxml_stop_parser(g_srv_prov_wbxml_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_end_hdlr
 * DESCRIPTION
 *  wbxml end tag hdlr
 * PARAMETERS
 *  resv        [IN]        
 *  tagname     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prov_wbxml_end_hdlr(void *resv, const kal_char *tagname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(tagname);
    if (strcmp(tagname, PROV_CHARACTERISTIC) == 0)
    {
        if (!g_srv_prov_ctxt.unnkown_tag_count)
        {
            g_srv_prov_ctxt.err_code = srv_prov_characteristic_end_tag_hdlr(g_srv_prov_ctxt.cur_node_level);
            g_srv_prov_ctxt.cur_node_level--;
        }
        else if (g_srv_prov_ctxt.err_code == SRV_PROV_UNKNOWN_TAG)
        {
            ASSERT((g_srv_prov_ctxt.unnkown_tag_count != 0));
            g_srv_prov_ctxt.unnkown_tag_count--;
        }
    }
    if ((g_srv_prov_ctxt.err_code != SRV_PROV_OK) && (g_srv_prov_ctxt.err_code != SRV_PROV_UNKNOWN_TAG))
    {
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_WBXML_END_HDLR_ERROR, g_srv_prov_ctxt.err_code);
        wbxml_stop_parser(g_srv_prov_wbxml_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_handle_characteristic_tag
 * DESCRIPTION
 *  handle characteristic tag
 * PARAMETERS
 *  attrlist        [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
static SRV_PROV_RETCODE srv_prov_handle_characteristic_tag(const S8 **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    SRV_PROV_RETCODE ret_code = SRV_PROV_OK;
    S8 *tag_str = NULL;
    S8 *tag_str_val = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attrlist[0])
    {
        tag_str = (S8*) attrlist[1];
        MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] Characteristic Tag = %s", (S8*) tag_str);
    }
    if (attrlist[2])
    {
        tag_str_val = (S8*) attrlist[3];
        MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] Characteristic value = %s", (S8*) tag_str_val);
    }
    ret_code = srv_prov_add_cca_characteristic_node(tag_str, tag_str_val, 0);

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_HANDLE_CHARACTERISTIC_TAG_EXIT);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_handle_param_tag
 * DESCRIPTION
 *  handle param ag
 * PARAMETERS
 *  attrlist        [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
static SRV_PROV_RETCODE srv_prov_handle_param_tag(const S8 **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    SRV_PROV_RETCODE ret_code = SRV_PROV_OK;
    S8 *tag_str = NULL;
    S8 *tag_str_val = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attrlist[0])
    {
        tag_str = (S8*) attrlist[1];
        MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] Param Tag = %s", (S8*) tag_str);
    }
    if (attrlist[2])
    {
        tag_str_val = (S8*) attrlist[3];
        MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] Param value = %s", (S8*) tag_str_val);
    }
    ret_code = srv_prov_add_cca_param_value(tag_str, tag_str_val);
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_HANDLE_PARAM_TAG_EXIT);

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_convert_wbxml_parser_error_code
 * DESCRIPTION
 *  convert wbxml parser error code
 * PARAMETERS
 *  err_code        [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
static SRV_PROV_RETCODE srv_prov_convert_wbxml_parser_error_code(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    SRV_PROV_RETCODE ret_code = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CONVERT_WBXML_PARSER_ERROR_CODE_ENTER, err_code);
    switch (err_code)
    {
        case WBXML_RESULT_OK:
            ret_code = SRV_PROV_OK;
            break;
        case WBXML_E_NO_MEMORY:
            ret_code = SRV_PROV_MEM_FULL;
            break;
        case WBXML_RESULT_FAIL:
        case WBXML_E_UNKNOWN_CHARSET:
        case WBXML_E_UNKNOWN_TAG:
        case WBXML_E_MISMATCH_TAG:
            ret_code = SRV_PROV_ERR;
            break;
        default:
            ASSERT(0);
    }

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_malloc_buffer
 * DESCRIPTION
 *  Allocate memory for wbxml parser
 * PARAMETERS
 *  len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *srv_prov_wbxml_malloc_buffer(kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_prov_mem_alloc(len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_wbxml_free_buffer
 * DESCRIPTION
 *  Free memory for wbxml parser
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prov_wbxml_free_buffer(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ptr);
    srv_prov_mem_free(ptr);
    ptr = NULL;
}

#endif /* __MMI_PROV_SERVICE_CCA_SUPPORT_ON__ */ 
#endif /* __PROVISIONING_SERVICE_SUPPORT__ */ 
#endif /* _PROVSERVICETAGHANDLER_C */ 

