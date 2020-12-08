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
 * DtcntSrvProv.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the internal header file of data account OTAP services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_PROV_H
#define _DTCNT_SRV_PROV_H

#include "MMI_features.h"
#include "DtcntSrvIntDef.h"
#include "DtcntSrvGprot.h"
#include "MMIDataType.h"
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
#include "CcaSrvGprot.h"
#endif /* __CCA_SUPPORT__ */


//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
/* structure for bootstrap */
typedef struct
{
#ifdef __TCPIP_OVER_CSD__
    U8 csd_num;
#endif /* __TCPIP_OVER_CSD__ */

#ifdef __MMI_GPRS_FEATURES__
    U8 gprs_num;
#endif /* __MMI_GPRS_FEATURES__ */
} srv_dtcnt_ota_sim_acc_ctx_struct;
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

typedef struct
{
    U8 napid_hash_val1[SRV_DTCNT_NAPID_HASH_LEN];        /* at most support 1 proxy using 3 accounts */
    U8 napid_hash_val2[SRV_DTCNT_NAPID_HASH_LEN];        /* at most support 1 proxy using 3 accounts */
    U8 napid_hash_val3[SRV_DTCNT_NAPID_HASH_LEN];        /* at most support 1 proxy using 3 accounts */
    U8 proxy_flag;      /* identify proxy settings done */
    U8 port_flag;       /* identify proxy-port settings done */
    srv_dtcnt_addr_type_enum    px_addrtype;    /* IPv4 or IPv6 */
    srv_dtcnt_prof_px_srv_enum  px_service;     /* proxy service type */    
    U16 px_port;                                /* proxy port */
    U8  px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];        /* proxy addr */
    U8  px_authid[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1];   /* proxy auth. ID string (ASCII) */
    U8  px_authpw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1];   /* proxy auth. PW (ASCII) */
    U8  px_startpage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1];  /* proxy homepage string (ASCII) */    
} srv_dtcnt_ota_proxy_item_struct;

typedef struct srv_dtcnt_ota_item_st
{
    struct srv_dtcnt_ota_item_st *next;
    CHAR node_id[SRV_DTCNT_MAX_NODE_ID_LEN+1];            /* UTF-8, 0-ended   */
    U8 napid_hash_val[SRV_DTCNT_NAPID_HASH_LEN];        /* hash value of napid */
    U8 bearer;                                          /* If this item is presented */
    CHAR name[(SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH];       /* Name of a Data Account */
#ifdef __MMI_GPRS_FEATURES__
    CHAR address[SRV_DTCNT_PROF_MAX_APN_LEN + 1];    /* GPRS APN */
#else /* __MMI_GPRS_FEATURES__ */
    CHAR address[SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1];        /* CSD Dial string */
#endif /* __MMI_GPRS_FEATURES__ */
    CHAR UserName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];                          /* User of a Data Account */
    CHAR Passwd[SRV_DTCNT_PROF_MAX_PW_LEN + 1];                          /* Password for a Data Account */
    U8 AuthType;                                            /* Authentication Type */
    U8 DialType;                                            /* Boolean : 0.Analoue or 1. SDN */
    U8 DataRate;                                            /* Boolean : 0.9.6 kbit/s or 1. 14.4 Kbit/s */
    U8 DnsAddress[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];                     /* DNS IP Address */
    BOOL valid;
    srv_dtcnt_addr_type_enum    px_addrtype;    /* IPv4 or IPv6 */
    srv_dtcnt_prof_px_srv_enum  px_service;     /* proxy service type */    
    U16 px_port;                                /* proxy port */
    U8  px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];        /* proxy addr */
    U8  px_authid[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1];   /* proxy auth. ID string (ASCII) */
    U8  px_authpw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1];   /* proxy auth. PW (ASCII) */
    U8  px_startpage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1];  /* proxy homepage string (ASCII) */  
} srv_dtcnt_ota_item_struct;


typedef struct dtcnt_ota_context_st
{
    U16 conf_id;                        /* Configuration ID                  */
    S32 doc_hdl;                        /* Configuration document handle     */
    U8 num_installed;                    /* Num of processed profiles         */
    U8 num_updated;                      /* Number of updated accounts */
    U8 num_profiles;                    /* Num of profiles installl          */
    
    U8 provurl_hash_val[SRV_DTCNT_PROVURL_HASH_LEN];    /* hash value of provisioning URL info */
    U8 sim_id;                          /* sim_id gotten from mmi_cca_app_configure_ind_struct, reseved only */
    U8 prov_type;                       /* newly added for bootstrap feature */
    U32 prov_flag;                      /* newly added for bootstrap feature */
    //MMI_BOOL is_updating;
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    U8 matched_index;
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    U8 index_profile;
    U8 cur_status;
    U8 replace_acct_index;
    U32 installed_acct_id;
    srv_dtcnt_ota_item_struct *active_item;
    srv_dtcnt_ota_item_struct *current_item;
    srv_dtcnt_ota_item_struct *g_dtcnt_ota_items;
    srv_dtcnt_ota_proxy_item_struct *curr_proxy_item;
} srv_dtcnt_ota_ctx_struct;

#ifdef SYNCML_DM_SUPPORT
typedef struct dtcnt_dm_context
{
    U8 selected_id;
    U16 app_id;
    U32 prof_id;
    S32 hconfig;
    //U8  data_ready_status;
    cca_status_enum  check_status;
    U8 proxy_flag;      /* identify proxy settings done */
    U8 port_flag;       /* identify proxy-port settings done */    
    srv_dtcnt_ota_item_struct  dm_item_cntx;
}srv_dtcnt_dm_ctx_struct;
#endif /* SYNCML_DM_SUPPORT */
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
extern MMI_BOOL g_srv_dtcnt_ota_ongoing;
#endif /* __CCA_SUPPORT__ */

extern void srv_dtcnt_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status);
extern void srv_dtcnt_ota_dm_update_ind(U16 appid, S32 profid, S32 hconfig);
extern void srv_dtcnt_ota_dm_retrieve_ind(U16 appid, S32 profid);
extern void srv_dtcnt_ota_proc_cca_doc(mmi_cca_app_configure_ind_struct * newConfigDoc);
extern cca_status_enum srv_dtcnt_ota_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct * data_list);

#endif /* __CCA_SUPPORT__ */
#endif /* _DTCNT_SRV_PROV_H */ 
