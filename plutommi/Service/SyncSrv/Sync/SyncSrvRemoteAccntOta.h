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
 *  SyncSrvRemoteAccntOTA.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of syncml service about remote account.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_REMOTE_ACCNT_OTA_H__
#define __SYNC_SRV_REMOTE_ACCNT_OTA_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "common_nvram_editor_data_item.h"
#include "custom_mmi_default_value.h"

#include "CcaSrvGprot.h"
#include "SyncSrv.h"
/*****************************************************************************
 * Define
 *****************************************************************************/
	/* invalid dest id for buffered profile*/
#define DEFAULT_CCA_PROFILE_NAME    (L"New account")
#define SYNCML_INVALID_IDX 			MAX_SYNCML_SV_PROFILES 
#define MAX_SYNCML_MIME_LEN 		64
#define MMI_MAX_SYNCML_ACCOUNTS   MAX_SYNCML_SV_PROFILES

	/* OTA operation flag */
#define SYNCML_OTA_OPR_UPDATE_MASK		0x01
#define SYNCML_OTA_OPR_REPLACE_MASK		0x02	
#define SYNCML_OTA_OPR_SKIP_MASK		0x04
#define SYNCML_OTA_OPR_ACTIVATE_MASK	0x08
#define SYNCML_OTA_OPR_INSTALL_MASK     0x10
#define SYNCML_OTA_OPR_DM_UPDATE_MASK	0x20
#define SYNCML_OTA_OPR_PROV_MASK		0x40
#define SYNCML_OTA_OPR_KEY_END_MASK		0x80

#define MMI_SYNCML_TRANS_TYPE_INTERNET SRV_SYNC_ACCNT_TRANS_TYPE_INTERNET
#define MMI_SYNCML_TRANS_TYPE_BT SRV_SYNC_ACCNT_TRANS_TYPE_BT

/*****************************************************************************
 * Typedef 
 *****************************************************************************/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
typedef enum
{
	MMI_SYNCML_ACCOUNT_TYPE_FACTORY,		   /* factory pre-configured */
	MMI_SYNCML_ACCOUNT_TYPE_OTA,			   /* provioning profile */
	MMI_SYNCML_ACCOUNT_TYPE_USR_DEFINED,	   /* usr defined profile */
	MMI_SYNCML_ACCOUNT_TYPE_TOTAL
}srv_sync_ota_accnt_type_enum;
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

typedef enum
{
	MMI_CCA_NS_SYNCML_PROXY,
	MMI_CCA_NS_SYNCML_BOOTSTRAP,
	MMI_CCA_NS_SYNCML_APPLICATION,
	MMI_CCA_NS_SYNCML_PORT,
	MMI_CCA_NS_SYNCML_PXAUTHINFO,
	MMI_CCA_NS_SYNCML_APPADDR,
	MMI_CCA_NS_SYNCML_APPAUTH,
	MMI_CCA_NS_SYNCML_RESOURCE,
	MMI_CCA_NS_SYNCML_NAPDEF,
	MMI_CCA_NS_SYNCML_TOTAL
} srv_sync_ota_cca_symbol_enum;

typedef struct{
	U16  id;
	U8 *mime;
	U32 db_mask;
	U32 valid_mask;
}srv_sync_ota_db_info_struct;

typedef struct
{
	MMI_BOOL valid;
	U8 unused[3];
	U32 dataaccountid;								 /*DataAccount id */
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	U8 proxy_id_hash[MAX_SYNCML_HASH_BUF_LEN];
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
	U8	proxy_id[MAX_SYNCML_PROXY_ID_LEN];			 /*For mapping profile number use. */ 
} srv_sync_ota_proxy_cntx_struct;

typedef struct
{
	U8 num_profiles;						 /* Num of processed profiles */
	U8 num_proxy;							 /*Num of processed proxy*/  
	U8 iter;								 /* Used to traverse profiles */
	U8 opr_flag;							/* operation flag */
	U8 total_valid; 						/* total valid profile */
	U8 unused;
	S8 dst_idx[MAX_SYNCML_SV_PROFILES];	 /*The index of slot where place the new profile.*/
	MMI_BOOL isvalidprof[MAX_SYNCML_SV_PROFILES];
	
	U16 conf_id;							 /* Configuration ID				  */
	U16 sim_id;								 /* CBM SIM ID */
	S32 doc_hdl;							 /* Configuration document handle	  */

	srv_sync_ota_db_info_struct *db_info;
	/* store the settings of the new profile */    
	nvram_ef_syncml_account_struct *profile[MAX_SYNCML_SV_PROFILES];

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	U8 prov_url_hash[MAX_SYNCML_HASH_BUF_LEN];
	U32 prov_flag;							/* prov flag from CCA */
#endif

	/* store the data of the new proxy */
	srv_sync_ota_proxy_cntx_struct proxy[MAX_SYNCML_SV_PROFILES];
	/* currentProfNameList for select screen display */
	U8 currentprofnamelist[MAX_SYNCML_SV_PROFILES][MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH];
	U8 app_to_proxy[MAX_SYNCML_SV_PROFILES][MAX_SYNCML_PROXY_ID_LEN]; /*For mapping profile number use.*/

} srv_sync_ota_cntx_struct;

typedef nvram_ef_syncml_account_struct mmi_syncml_account_struct;
typedef srv_sync_ota_cntx_struct mmi_syncml_ota_cntx_struct;
typedef srv_sync_ota_proxy_cntx_struct mmi_syncml_ota_proxy_cntx_struct;

/*****************************************************************************
 * Global function 
 *****************************************************************************/
extern cca_status_enum srv_sync_ota_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data);
#endif /* __SYNC_SRV_REMOTE_ACCNT_OTA_H__ */

