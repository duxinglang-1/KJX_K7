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
 * WAPProvisioningSrvType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This declares types for UPP provisioning module.
 *
 * Author: Ramneek Kalra
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 #ifdef PROV_SUPPORT
#ifndef _WAPPROVISIONINGSRVTYPE_H
#define _WAPPROVISIONINGSRVTYPE_H

#include "MMI_features.h"
#include "MMIDataType.h"
//#include "custom_nvram_editor_data_item.h"
#include "common_nvram_editor_data_item.h"
#ifdef WAP_SUPPORT
#include "WAPProfileSrvType.h"
#include "CcaSrvGProt.h"

#ifdef WAP2
#define SRV_DM_PROF_DEFAULT_PORTNBR          80
#define SRV_DM_PROF_DEFAULT_CONN_TYPE        SRV_WAP_PROF_CONN_TYPE_HTTP
#else /* WAP2 */ 
#define SRV_DM_PROF_DEFAULT_PORTNBR          9201
#define SRV_DM_PROF_DEFAULT_CONN_TYPE        SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED
#endif /* WAP2*/ 

#define SRV_DM_PROF_DEFAULT_PRIMARY_ID       10
#define SRV_DM_PROF_DEFAULT_SECONDARY_ID     SRV_WAP_PROF_DEFAULT_SECONDARY_DATA_ACCOUNT_ID

#define SRV_WAP_PROF_PROV_MAX_DISPLAY_CHARS     64  /* MAUI_040452086 */


typedef enum
{
    SRV_WAP_PROF_PROV_RESULT_INVALID =1,
    SRV_WAP_PROF_PROV_RESULT_SKIPPED,
	SRV_WAP_PROF_PROV_RESULT_SUCCESS,
    SRV_WAP_PROF_PROV_RESULT_UPDATED,

    SRV_WAP_PROF_PROV_RESULT_END
} srv_wap_prof_prov_result_enum;

typedef enum
{
    SRV_WAP_PROV_TYPE_OTA,
    SRV_WAP_PROV_TYPE_USIM,
    SRV_WAP_PROV_TYPE_DM,

    /* Add above this. */
    SRV_WAP_PROV_TYPE_END
} srv_wap_prov_type_enum;

typedef enum
{
    SRV_WAP_PROV_OP_ADD_NEW,
    SRV_WAP_PROV_OP_UPDATE_SELECT,
    SRV_WAP_PROV_OP_UPDATE_BOOTSTRAP,

    /* Add above this. */
    SRV_WAP_PROV_OP_END
} srv_wap_prov_op_enum;


typedef enum
{
	SRV_WAP_PROV_SET_SCRN_DELETED = 0,
	SRV_WAP_PROV_UNSET_SCRN_DELETED,
	SRV_WAP_PROV_SCRN_DELETED_END
}srv_wap_prov_scrn_delete_status_enum;
typedef enum
{
    SRV_WAP_PROV_NODE_BRW_PROXY = 0,
    SRV_WAP_PROV_NODE_BRW_PORT,
    SRV_WAP_PROV_NODE_BRW_AUTHINFO,
    SRV_WAP_PROV_NODE_BRW_APP,
    SRV_WAP_PROV_NODE_BRW_RESOURCE,
    SRV_WAP_PROV_NODE_BRW_BOOTSTRAP,

    SRV_WAP_PROV_NODE_BRW_END
} srv_wap_prov_node_symbol_brw_enum;

typedef enum
{
    SRV_WAP_PROV_NODE_MMS_PROXY = 0,
    SRV_WAP_PROV_NODE_MMS_PORT,
    SRV_WAP_PROV_NODE_MMS_AUTHINFO,
    SRV_WAP_PROV_NODE_MMS_APP,
    SRV_WAP_PROV_NODE_MMS_BOOTSTRAP,

    SRV_WAP_PROV_NODE_MMS_END
} srv_wap_prov_node_symbol_mms_enum;

#define SRV_WAP_PROV_PROXY_ID_LEN              (32)


#ifdef WAP2

#define SRV_WAP_PROF_PROV_DEFAULT_CONN_TYPE     SRV_WAP_PROF_CONN_TYPE_HTTP
#else /* WAP2 */ 
#define SRV_WAP_PROF_PROV_DEFAULT_CONN_TYPE     SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED

#endif /* WAP2 */ 

#define SRV_WAP_PROV_MAX_PROFILE_COUNT 5
#define SRV_WAP_PROV_MAX_BOOKMARK_COUNT 5
#define SRV_WAP_PROV_MAX_TO_PROXY SRV_WAP_PROV_MAX_PROFILE_COUNT


#define SRV_WAP_PROV_NEW_LINE_SIZE          5


typedef struct
{
    U8 bm_title[SRV_WAP_PROV_MAX_BOOKMARK_TITLE_LEN *ENCODING_LENGTH];
    U8 bm_url[SRV_WAP_PROV_MAX_BOOKMARK_URL_LEN];
} srv_wap_prov_bookmark_struct;

typedef struct
{
    U8 primary_dataacc_id;
    U8 secondary_dataacc_id;

    S16 bookmark_count;
    MMI_BOOL only_bookmarks;
    MMI_BOOL only_mms_settings;
    srv_wap_prov_mms_setting_data_list_struct *mms_setting_data_p;
    srv_wap_prov_bookmark_struct *bookmark[SRV_WAP_PROV_MAX_BOOKMARK_COUNT];

    U8 url[NVRAM_WAP_PROF_URL_LEN];
} srv_wap_prov_ota_profile_struct;

typedef struct
{
    U8 px_primary_dataacc_id;
    U8 px_secondary_dataacc_id;

    U8 px_id[SRV_WAP_PROV_PROXY_ID_LEN];

    U8 px_startpage[NVRAM_WAP_PROF_URL_LEN];
} srv_wap_prov_proxy_content_struct;

typedef struct
{

    S16 bookmark_count;
    srv_wap_prov_mms_setting_data_list_struct *mms_setting_data_p;
    srv_wap_prov_bookmark_struct *bookmark[SRV_WAP_PROV_MAX_BOOKMARK_COUNT];

    U8 *app_to_proxy[SRV_WAP_PROV_MAX_PROFILE_COUNT];

    U8 app_url[NVRAM_WAP_PROF_URL_LEN];
} srv_wap_prov_application_content_struct;



/* Type definition for save OTA mms setting. */
typedef void (*srv_wap_prov_save_ota_mms_setting_funcptr_type) (srv_wap_prov_mms_setting_data_list_struct *
                                                                mms_setting_content_p,
                                                                srv_wap_prof_response_funcptr_type
                                                                save_mms_setting_rsp_callback);

/* Type definition for Add bookmark. */
typedef void (*srv_wap_prov_add_bookmark_funcptr_type)
    (U8 *bookmark_name, U8 *url, srv_wap_prof_response_funcptr_type add_bookmark_rsp_callback);


typedef struct
{
    srv_wap_prof_active_profile_chg_ind_funcptr_type active_profile_changed_callback[SRV_WAP_PROF_APPID_END];
    srv_wap_prof_is_active_profile_in_use_funcptr_type is_active_profile_in_use_callback[SRV_WAP_PROF_APPID_END];

#ifdef BROWSER_SUPPORT
    srv_wap_prof_get_active_sim_id_funcptr_type active_sim_id_callback;
#endif
    srv_wap_prov_add_bookmark_funcptr_type add_bookmark_callback;
    srv_wap_prov_save_ota_mms_setting_funcptr_type save_ota_mms_setting_callback;
    srv_wap_prof_is_target_app_ready is_application_ready[SRV_WAP_PROF_APPID_END];

} srv_wap_prof_callback_struct;

extern srv_wap_prof_callback_struct g_srv_wap_prof_callback_st ;

typedef struct
{
	srv_wap_prov_proxy_content_struct *proxy_list[SRV_WAP_PROV_MAX_PROFILE_COUNT] ;
	srv_wap_prov_application_content_struct *app_list[SRV_WAP_PROV_MAX_PROFILE_COUNT];
	srv_wap_prov_ota_profile_struct *profile_list[SRV_WAP_PROV_MAX_PROFILE_COUNT] ;
	S8 crnt_proxy_index;
	S8 crnt_app_index;
        mmi_id cui_id;
//	MMI_BOOL port_flag;
//	MMI_BOOL proxy_flag;
	MMI_BOOL startpage_flag;
	MMI_BOOL application_flag ;
	MMI_BOOL free_profile;
	S8  profile_count ;
	S8  crnt_prof_index;
	S8 crnt_profile_bookmark_idx ;
	S32 cca_hconfig;
	S32 cca_dm_prof_id;
	srv_wap_prof_sim_id_enum sim_id;
	srv_wap_prof_app_id_enum app_id;
	srv_wap_prov_type_enum provisioning_type;
//	S8  provurl[NVRAM_WAP_PROF_PROVURL_LEN] ;
	srv_wap_prov_op_enum prov_op ;
	srv_cca_app_configure_ind_struct  *cca_config_doc;
	MMI_BOOL scrn_deleted;
	MMI_BOOL status_sent ;
//	MMI_BOOL update_factory_profile_flag ;
 //	 setting_installed;
	U8 crnt_bkm_or_mms_setting_index;


}srv_wap_prov_cntx_struct; 


extern srv_wap_prov_cntx_struct g_srv_wap_prov_cntx;


#endif /* WAP_SUPPORT */ 
#endif /* _WAPPROVISIONINGTYPE_H */ 
#endif
