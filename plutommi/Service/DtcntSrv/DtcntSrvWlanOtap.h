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
 * DtcntSrvWlanOtap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the internal header file of data account Wlan OTAP services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_WLAN_OTAP_H
#define _DTCNT_SRV_WLAN_OTAP_H

#include "MMI_features.h"
#include "DtcntSrvIntDef.h"
#include "MMIDataType.h"
#include "DtcntSrvGprot.h"
#include "kal_general_types.h"
#include "DtcntSrvIprot.h"
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
#include "CcaSrvGprot.h"
#endif /* __CCA_SUPPORT__ */

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

/*
 * Slim WLAN profile used during OTA provisioning to save memory space. It will
 * be allocated from 512-bytes control buffer pool.
 */
typedef struct
{
    U8 node_id[SRV_DTCNT_MAX_NODE_ID_LEN+1];                        /* UTF-8, 0-ended   */
    U8 name[(SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1) * ENCODING_LENGTH];  /* UCS2, 0-ended    */
    U8 ssid[SRV_DTCNT_PROF_MAX_SSID_LEN+1];                              /* ASCII, 0-ended   */
    U8 ssid_len;
    U8 network_type;
    U8 encrypt_mode;
    U8 auth_mode;
    U32 eap_auth_type;
    U8 username[SRV_DTCNT_PROF_MAX_USER_LEN+1];
    U8 password[SRV_DTCNT_PROF_MAX_PW_LEN+1];
    U8 wep_key_index;
    U8 wep_key_len;
    U8 wep_key_format;
    U8 wep_key[SRV_DTCNT_PROF_MAX_WEP_KEY_LEN+1];
    U8 passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1];
    U8 psk[32 + 1];                         /* Last byte: whether PSK is set */
} srv_dtcnt_wlan_slim_profile_struct;

/*
 * Control block for WLAN OTA provisioning. It will be allocated from 256-
 * bytes control buffer pool. 
 */
typedef struct
{
    U8 cur_status;  /* process status of this ota profile, save for CCA */
    MMI_BOOL is_active; /* Enable to process node/param                     */
    U8 num_profiles;    /* Num of processed profiles                        */
    U8 iter;            /* Used to traverse profiles                        */

    /* node_id stores the id of a NAPDEF node. It is used to inform CCA that 
       this NAPDEF node has been installed. name is the profile name of a 
       NAPDEF node. It is possible there are multiple WLAN nodes in a NAPDEF 
       node such that we need to remember the name that will become the prefix
       of all such WLAN profiles. */
    U8 node_id[SRV_DTCNT_MAX_NODE_ID_LEN+1];                        /* UTF-8, 0-ended   */
    U8 name[(SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN+1) * ENCODING_LENGTH];  /* UCS2, 0-ended    */

    /* conf_id and doc_hdl are indicated by CCA. And we need to pass these two
       variable back to CCA when we send the response message. */
    U16 conf_id;        /* Configuration ID                                 */

    /* The variables 'src_idx' and 'dst_idx' provide linkage between 
       this->profile[] and g_wlan_prof_list[]. */
    S16 src_idx[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
    S16 dst_idx[SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM];
    S16 sel_dst_idx[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];

    S32 doc_hdl;        /* Configuration document handle                    */
    /* Storage for incoming profiles. */
    srv_dtcnt_wlan_slim_profile_struct *profile[SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM];
    /* profile replace name string pointer buffer */
    U8 *prof_name_list[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
} srv_dtcnt_wlan_otap_struct;

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */


extern void srv_dtcnt_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl);
extern void srv_dtcnt_wlan_prov_ind_callback(srv_dtcnt_prov_cnf_enum cnf, U8 replace_idx);
extern mmi_ret srv_dtcnt_wlan_event_callback(mmi_post_result_event_struct *result_evt);

//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
extern cca_status_enum srv_dtcnt_wlan_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct *data_list);
#endif /* __CCA_SUPPORT__*/

#endif /* _DTCNT_SRV_WLAN_OTAP_H */ 
