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
 * ProvisioningSrvMain.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   header file for ProvisioningSrvMain.c file
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
#ifndef _PROVISIONINGSRVMAIN_H
#define _PROVISIONINGSRVMAIN_H

//#include "mmi_frm_gprot.h"

//------------------------------ suggest Add ------------------------------
#include "MMI_features.h"
#include "MMIDataType.h"
//------------------------------ usage ------------------------------

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

#ifndef __MMI_PROV_SERVICE_CCA_SUPPORT_ON__
#ifdef __MMI_CCA_SUPPORT__
#define __MMI_PROV_SERVICE_CCA_SUPPORT_ON__
#endif 
#endif /* __MMI_PROV_SERVICE_CCA_SUPPORT_ON__ */ 

#ifndef __PROV_NOKIA_OTA_SUPPORT__
#ifndef SLIM_WAP_MMS    /* SLIM_R */
#define __PROV_NOKIA_OTA_SUPPORT__
#endif 
#endif 

#ifndef __PROV_OMA_PIN_VALIDATION_SUPPORT__
#define __PROV_OMA_PIN_VALIDATION_SUPPORT__
#endif 

#ifdef __MMI_PROV_SERVICE_CCA_SUPPORT_ON__

#include "ProvisioningSrvConfiguringSrc.h"


/* Trace group 9 of inet_app */
#define SRV_PROV_TRACE_GRP9                 TRACE_GROUP_9
#define SRV_PROV_TRACE_MOD_INET_APP         MOD_MMI_INET_APP

#ifdef SLIM_WAP_MMS
#define SRV_PROV_MAX_FILE_SIZE_SUPPORT      (1*1024)
#else /* SLIM_WAP_MMS */
#define SRV_PROV_MAX_FILE_SIZE_SUPPORT      (2*1024)
#endif /* SLIM_WAP_MMS */

/* SLIM_R starts */
#ifdef SLIM_WAP_MMS
#define SRV_PROV_MAX_WBXML_PARSER_BUFFER    (0)
#else
#define SRV_PROV_MAX_WBXML_PARSER_BUFFER    (7*1024)
#endif /* SLIM_WAP_MMS */
/* SLIM_R ends */
#define SRV_PROV_MAX_DYNAMIC_MEM_REQUIRED   ((1*1024) + SRV_PROV_MAX_WBXML_PARSER_BUFFER)

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#define SRV_PROV_MAX_NBR_DOCUMENTS          (1)
#else
#ifdef SLIM_WAP_MMS
#define SRV_PROV_MAX_NBR_DOCUMENTS          (1)
#else /* SLIM_WAP_MMS */
#define SRV_PROV_MAX_NBR_DOCUMENTS          (5)
#endif /* SLIM_WAP_MMS */
#endif /* __SRV_PROV_MESSAGE_SUPPORT__ */

#define SRV_PROV_MAX_MEM_SIZE               ((SRV_PROV_MAX_FILE_SIZE_SUPPORT * SRV_PROV_MAX_NBR_DOCUMENTS) + SRV_PROV_MAX_DYNAMIC_MEM_REQUIRED)

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__

#define SRV_PROV_SEC_TEXT                   " SEC"
#define SRV_PROV_MAC_TEXT                   " MAC"
#define SRV_PROV_HEADER_SEPARATOR           ";"
#define SRV_PROV_MAX_PIN_RETRIES            3
#define SRV_PROV_MAX_MAC_CHARS              20
#define SRV_PROV_MAX_IMSI_CHARS             16
#define SRV_PROV_MAX_PIN_CHARS              SRV_CCA_MAX_PIN_CHARS
#define SRV_PROV_OMA_OTA_MIME               "application/vnd.wap.connectivity-wbxml"
#define SRV_PROV_MIME_STR_LEN               40  /* 40 len of bookmark mime */

/* Enum for SEC values in header. refer OMA spec PROVCONT. */
typedef enum
{
    SRV_PROV_SEC_VALUE_NETWPIN,
    SRV_PROV_SEC_VALUE_USERPIN,
    SRV_PROV_SEC_VALUE_USERNETWPIN,
    SRV_PROV_SEC_VALUE_USERPINMAC,
    SRV_PROV_SEC_VALUE_TOTAL
} srv_prov_sec_value_enum;

#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

typedef enum
{
    SRV_PROV_OK,
    SRV_PROV_MEM_FULL,
    SRV_PROV_ERR,
    SRV_PROV_CCA_DUP_NODE_CREATED,
    SRV_PROV_UNKNOWN_TAG,

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__

    SRV_PROV_AUTHENTICATION_FAILED,

#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

    SRV_PROV_CORRUPT_SETTING,
    SRV_PROV_GET_MSG_FAILED,

    /* Add before this */
    SRV_PROV_RETCODE_TOTAL
} srv_prov_retcode_enum;


/* Enum for setting type */
typedef enum
{
    SRV_PROV_OTA_TYPE_OMA = 1,
    SRV_PROV_OTA_TYPE_WAP,
    SRV_PROV_OTA_TYPE_TOTAL
} srv_prov_ota_type_enum;

/* Structure to store prov data in a queue */
typedef struct
{
    S8 *p_header;
    S8 *pbuffer;
    U16 i_sim_id;
    U32 plength;
    S32 trans_id;
} srv_prov_queue_data_struct;

/* PROV context structure */
typedef struct
{
    S32 node_parent_id;
    S32 parent_parent_id;
    U8 cur_node_level;
    S8 unnkown_tag_count;
    U8 prov_type;                               /* wap ota or oma ota */
/*    U8 new_doc_rsp_state; USIM */
    SRV_PROV_RETCODE err_code;
    MMI_BOOL valid_prov_tag;                    /* Handled if all the characteristic are unknown */
    U8 *tonapid[SRV_PROV_MAX_TONAPID_SUPPORT];  /* Contains to napid param of an application */
    srv_prov_cca_node_hdlr_st *sibling_node_list_p;
    S16 i_sec_value;                            /* Sec value, default -1 */
#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__
    U8 s_imsi[SRV_PROV_MAX_IMSI_CHARS + 1];
    U8 s_mac[SRV_PROV_MAX_MAC_CHARS + 1];       /* will contain transformed MAC from header */
    U16 i_mac_len;
    U16 i_imsi_len;                             /* required bcoz imsi len can be less than 8 also */
#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

#ifdef __PROV_NOKIA_OTA_SUPPORT__
    S8 first_proxy_id[2];
    U8 *setting_name;
    U8 *app_url;
    S32 napauthinfo_node;
    S32 pxauthinfo_node;
    S32 proxy_node;
    srv_prov_cca_ne_node_list_struct *cca_proxy_node_list_p;
    srv_prov_cca_ne_node_list_struct *cca_brw_app_node_list_p;
    srv_prov_cca_ne_node_list_struct *cca_mms_app_node_list_p;
    srv_prov_cca_ne_node_list_struct *cca_resorce_node_list_p;
#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 


#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    U32 msg_id;
    S32 msg_trans_id;
    U16 msg_sim_id;
    U8  msg_prov_type;
    U32 msg_prov_flag;
    U8  addr_type;
    U8 *addr;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

} srv_prov_context_struct;

extern srv_prov_context_struct g_srv_prov_ctxt;

#endif /* __MMI_PROV_SERVICE_CCA_SUPPORT_ON__ */ 
#endif /* __MMI_PROVISIONING_SERVICE_SUPPORT__ */ 
#endif /* _PROVSERVICEMAIN_H */ 

